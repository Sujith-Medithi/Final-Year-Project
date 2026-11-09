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
struct FilterState_R001150_5013_0
{
  unsigned char damping;
  unsigned char cutoff;
  unsigned char gain_db;
  int prev_in;
  int buffer[3];
};
struct AudioFrame_R001150_5013_1
{
  unsigned char channels;
  short rms;
  int sample_rate;
  short peak;
  int buffer[3];
};
union ColorPixel_R001150_5013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001150_5013_1
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
void fn_R001150_5013_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st_1 = {0};
  struct AudioFrame_R001150_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int threshold_90_1 = 0;
  int threshold_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_90_1 = ((threshold_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_90_2 = ((threshold_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_90_1) & 127;
    acc_2 = (acc_2 + threshold_90_2) & 127;
  }

  int window_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_96_1) & 63;
  aux_2 = (aux_2 + window_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_90_1 == threshold_90_2);
  assert(window_96_1 == window_96_2);
}

int fn_R001150_5013_0(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int threshold_90 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_90 = ((threshold_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_90) & 127;
  }

  int window_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001150_5013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st_1 = {0};
  struct FilterState_R001150_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int metric_67_1 = 0;
  int metric_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_67_1 = ((metric_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_67_2 = ((metric_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_67_1) & 127;
    acc_2 = (acc_2 + metric_67_2) & 127;
  }

  int metric_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_97_1)
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

  switch (metric_97_2)
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

  int phase_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_10_1 > 22)
  {
    acc_1 = ((acc_1 + (phase_10_1 * 2)) + 5) & 127;
    aux_1 ^= phase_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_10_2 > 22)
  {
    acc_2 = ((acc_2 + (phase_10_2 * 2)) + 5) & 127;
    aux_2 ^= phase_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_67_1 == metric_67_2);
  assert(metric_97_1 == metric_97_2);
  assert(phase_10_1 == phase_10_2);
}

int fn_R001150_5013_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int metric_67 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_67 = ((metric_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_67) & 127;
  }

  int metric_97 = (aux + st.buffer[1]) & 3;
  switch (metric_97)
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

  int phase_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_10 > 22)
  {
    acc = ((acc + (phase_10 * 2)) + 5) & 127;
    aux ^= phase_10 & 15;
  }
  else
  {
    acc = ((acc - phase_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001150_5013_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st_1 = {0};
  struct AudioFrame_R001150_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_94_1 = local_arr_1[aux_1 % 3];
  int segment_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_94_2 * 2)) & 127;
  int index_reg_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_77_1) & 63;
  aux_2 = (aux_2 + index_reg_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_94_1 == segment_94_2);
  assert(index_reg_77_1 == index_reg_77_2);
}

int fn_R001150_5013_2(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int segment_94 = local_arr[aux % 3];
  acc = (acc + (segment_94 * 2)) & 127;
  int index_reg_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_77) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001150_5013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st_1 = {0};
  struct FilterState_R001150_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int delta_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_73_1 > 32)
  {
    acc_1 = ((acc_1 + (delta_73_1 * 2)) + 5) & 127;
    aux_1 ^= delta_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_73_2 > 32)
  {
    acc_2 = ((acc_2 + (delta_73_2 * 2)) + 5) & 127;
    aux_2 ^= delta_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_72_1)
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

  switch (coefficient_72_2)
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
  int stride_12_1 = local_arr_1[aux_1 % 3];
  int stride_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_12_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_73_1 == delta_73_2);
  assert(coefficient_72_1 == coefficient_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_12_1 == stride_12_2);
}

int fn_R001150_5013_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int delta_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_73 > 32)
  {
    acc = ((acc + (delta_73 * 2)) + 5) & 127;
    aux ^= delta_73 & 15;
  }
  else
  {
    acc = ((acc - delta_73) + 11) & 127;
    aux += 3;
  }
  int coefficient_72 = (aux + st.buffer[1]) & 3;
  switch (coefficient_72)
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
  int stride_12 = local_arr[aux % 3];
  acc = (acc + (stride_12 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001150_5013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st_1 = {0};
  struct FilterState_R001150_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int accumulator_64_1 = 0;
  int accumulator_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_64_1 = ((accumulator_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_64_2 = ((accumulator_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_64_1) & 127;
    acc_2 = (acc_2 + accumulator_64_2) & 127;
  }

  int vector_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_10_1 > 18)
  {
    acc_1 = ((acc_1 + (vector_10_1 * 2)) + 5) & 127;
    aux_1 ^= vector_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_10_2 > 18)
  {
    acc_2 = ((acc_2 + (vector_10_2 * 2)) + 5) & 127;
    aux_2 ^= vector_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_10_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_44_1)
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

  switch (window_44_2)
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
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_64_1 == accumulator_64_2);
  assert(vector_10_1 == vector_10_2);
  assert(window_44_1 == window_44_2);
}

int fn_R001150_5013_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int accumulator_64 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_64 = ((accumulator_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_64) & 127;
  }

  int vector_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_10 > 18)
  {
    acc = ((acc + (vector_10 * 2)) + 5) & 127;
    aux ^= vector_10 & 15;
  }
  else
  {
    acc = ((acc - vector_10) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_44 = (aux + st.buffer[1]) & 3;
  switch (window_44)
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

void fn_R001150_5013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st_1 = {0};
  struct FilterState_R001150_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_55_1)
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

  switch (bound_55_2)
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
  int delta_55_1 = local_arr_1[aux_1 % 3];
  int delta_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_55_1 == bound_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_55_1 == delta_55_2);
}

int fn_R001150_5013_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_55 = (aux + st.buffer[1]) & 3;
  switch (bound_55)
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
  int delta_55 = local_arr[aux % 3];
  acc = (acc + (delta_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001150_5013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st_1 = {0};
  struct FilterState_R001150_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_50_1 = 0;
  int mask_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_50_1 = ((mask_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_50_2 = ((mask_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_50_1) & 127;
    acc_2 = (acc_2 + mask_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_50_1 == mask_50_2);
}

int fn_R001150_5013_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_50 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_50 = ((mask_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_50) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001150_5013_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st_1 = {0};
  struct AudioFrame_R001150_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_38_1) & 63;
  aux_2 = (aux_2 + vector_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_38_1 == vector_38_2);
}

int fn_R001150_5013_7(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001150_5013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st_1 = {0};
  struct AudioFrame_R001150_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_54_1 = local_arr_1[aux_1 % 3];
  int stride_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_54_2 * 2)) & 127;
  int scale_49_1 = 0;
  int scale_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_49_1 = ((scale_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_49_2 = ((scale_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_49_1) & 127;
    acc_2 = (acc_2 + scale_49_2) & 127;
  }

  int parity_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_14_1) & 63;
  aux_2 = (aux_2 + parity_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_54_1 == stride_54_2);
  assert(scale_49_1 == scale_49_2);
  assert(parity_14_1 == parity_14_2);
}

int fn_R001150_5013_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int stride_54 = local_arr[aux % 3];
  acc = (acc + (stride_54 * 2)) & 127;
  int scale_49 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_49 = ((scale_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_49) & 127;
  }

  int parity_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_14) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001150_5013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st_1 = {0};
  struct AudioFrame_R001150_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tally_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_28_1) & 63;
  aux_2 = (aux_2 + tally_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_85_1)
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

  switch (quantum_85_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_14_1 = local_arr_1[aux_1 % 3];
  int anchor_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_14_2 * 2)) & 127;
  int offset_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_85_1 > 12)
  {
    acc_1 = ((acc_1 + (offset_85_1 * 2)) + 5) & 127;
    aux_1 ^= offset_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_85_2 > 12)
  {
    acc_2 = ((acc_2 + (offset_85_2 * 2)) + 5) & 127;
    aux_2 ^= offset_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_28_1 == tally_28_2);
  assert(quantum_85_1 == quantum_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_14_1 == anchor_14_2);
  assert(offset_85_1 == offset_85_2);
}

int fn_R001150_5013_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tally_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_28) & 63;
  acc ^= aux;
  int quantum_85 = (aux + st.buffer[1]) & 3;
  switch (quantum_85)
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

  int local_arr[3] = {4, 9, 15};
  int anchor_14 = local_arr[aux % 3];
  acc = (acc + (anchor_14 * 2)) & 127;
  int offset_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_85 > 12)
  {
    acc = ((acc + (offset_85 * 2)) + 5) & 127;
    aux ^= offset_85 & 15;
  }
  else
  {
    acc = ((acc - offset_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001150_5013_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st_1 = {0};
  struct AudioFrame_R001150_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int weight_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_36_1)
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

  switch (weight_36_2)
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

  int tally_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_35_1) & 63;
  aux_2 = (aux_2 + tally_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_36_1 == weight_36_2);
  assert(tally_35_1 == tally_35_2);
}

int fn_R001150_5013_10(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int weight_36 = (aux + st.buffer[1]) & 3;
  switch (weight_36)
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

  int tally_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001150_5013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st_1 = {0};
  struct AudioFrame_R001150_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_65_1 > 31)
  {
    acc_1 = ((acc_1 + (segment_65_1 * 2)) + 5) & 127;
    aux_1 ^= segment_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_65_2 > 31)
  {
    acc_2 = ((acc_2 + (segment_65_2 * 2)) + 5) & 127;
    aux_2 ^= segment_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_65_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_65_1 == segment_65_2);
}

int fn_R001150_5013_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_65 > 31)
  {
    acc = ((acc + (segment_65 * 2)) + 5) & 127;
    aux ^= segment_65 & 15;
  }
  else
  {
    acc = ((acc - segment_65) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001150_5013_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st_1 = {0};
  struct FilterState_R001150_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int tracker_17_1 = 0;
  int tracker_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_17_1 = ((tracker_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_17_2 = ((tracker_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_17_1) & 127;
    acc_2 = (acc_2 + tracker_17_2) & 127;
  }

  int window_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_34_1) & 63;
  aux_2 = (aux_2 + window_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_17_1 == tracker_17_2);
  assert(window_34_1 == window_34_2);
}

int fn_R001150_5013_12(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int tracker_17 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_17 = ((tracker_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_17) & 127;
  }

  int window_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_34) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001150_5013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st_1 = {0};
  struct FilterState_R001150_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int residue_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_73_1)
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

  switch (residue_73_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_35_1 = local_arr_1[aux_1 % 3];
  int pivot_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_35_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_73_1 == residue_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_35_1 == pivot_35_2);
}

int fn_R001150_5013_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int residue_73 = (aux + st.buffer[1]) & 3;
  switch (residue_73)
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

  int local_arr[3] = {4, 9, 15};
  int pivot_35 = local_arr[aux % 3];
  acc = (acc + (pivot_35 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001150_5013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st_1 = {0};
  struct FilterState_R001150_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int factor_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_38_1) & 63;
  aux_2 = (aux_2 + factor_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_80_1 = local_arr_1[aux_1 % 3];
  int mask_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_38_1 == factor_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_80_1 == mask_80_2);
}

int fn_R001150_5013_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int factor_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_38) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_80 = local_arr[aux % 3];
  acc = (acc + (mask_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001150_5013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st_1 = {0};
  struct FilterState_R001150_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tracker_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_85_1) & 63;
  aux_2 = (aux_2 + tracker_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_11_1)
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

  switch (damping_11_2)
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
  int cursor_48_1 = local_arr_1[aux_1 % 3];
  int cursor_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_48_2 * 2)) & 127;
  int margin_46_1 = 0;
  int margin_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_46_1 = ((margin_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_46_2 = ((margin_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_46_1) & 127;
    acc_2 = (acc_2 + margin_46_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_85_1 == tracker_85_2);
  assert(damping_11_1 == damping_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_48_1 == cursor_48_2);
  assert(margin_46_1 == margin_46_2);
}

int fn_R001150_5013_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tracker_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_85) & 63;
  acc ^= aux;
  int damping_11 = (aux + st.buffer[1]) & 3;
  switch (damping_11)
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
  int cursor_48 = local_arr[aux % 3];
  acc = (acc + (cursor_48 * 2)) & 127;
  int margin_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_46 = ((margin_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_46) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001150_5013_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st_1 = {0};
  struct AudioFrame_R001150_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_35_1 = 0;
  int residue_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_35_1 = ((residue_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_35_2 = ((residue_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_35_1) & 127;
    acc_2 = (acc_2 + residue_35_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_35_1 == residue_35_2);
}

int fn_R001150_5013_16(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_35 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_35 = ((residue_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_35) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001150_5013_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st_1 = {0};
  struct AudioFrame_R001150_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int damping_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_89_1)
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

  switch (damping_89_2)
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
  int stride_16_1 = local_arr_1[aux_1 % 3];
  int stride_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_16_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_89_1 == damping_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_16_1 == stride_16_2);
}

int fn_R001150_5013_17(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int damping_89 = (aux + st.buffer[1]) & 3;
  switch (damping_89)
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
  int stride_16 = local_arr[aux % 3];
  acc = (acc + (stride_16 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001150_5013_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st_1 = {0};
  struct AudioFrame_R001150_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int residue_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_53_1)
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

  switch (residue_53_2)
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

  int damping_22_1 = 0;
  int damping_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_22_1 = ((damping_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_22_2 = ((damping_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_22_1) & 127;
    acc_2 = (acc_2 + damping_22_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_53_1 == residue_53_2);
  assert(damping_22_1 == damping_22_2);
}

int fn_R001150_5013_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int residue_53 = (aux + st.buffer[1]) & 3;
  switch (residue_53)
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

  int damping_22 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_22 = ((damping_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_22) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001150_5013_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st_1 = {0};
  struct FilterState_R001150_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int margin_75_1 = 0;
  int margin_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_75_1 = ((margin_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_75_2 = ((margin_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_75_1) & 127;
    acc_2 = (acc_2 + margin_75_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_31_1 = local_arr_1[aux_1 % 3];
  int phase_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_75_1 == margin_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_31_1 == phase_31_2);
}

int fn_R001150_5013_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int margin_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_75 = ((margin_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_75) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_31 = local_arr[aux % 3];
  acc = (acc + (phase_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001150_5013_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st_1 = {0};
  struct AudioFrame_R001150_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int tally_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_23_1) & 63;
  aux_2 = (aux_2 + tally_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_80_1 = local_arr_1[aux_1 % 3];
  int cursor_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_80_2 * 2)) & 127;
  int parity_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_87_1)
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

  switch (parity_87_2)
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

  int vector_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_40_1 > 42)
  {
    acc_1 = ((acc_1 + (vector_40_1 * 2)) + 5) & 127;
    aux_1 ^= vector_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_40_2 > 42)
  {
    acc_2 = ((acc_2 + (vector_40_2 * 2)) + 5) & 127;
    aux_2 ^= vector_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_23_1 == tally_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_80_1 == cursor_80_2);
  assert(parity_87_1 == parity_87_2);
  assert(vector_40_1 == vector_40_2);
}

int fn_R001150_5013_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int tally_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_23) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_80 = local_arr[aux % 3];
  acc = (acc + (cursor_80 * 2)) & 127;
  int parity_87 = (aux + st.buffer[1]) & 3;
  switch (parity_87)
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

  int vector_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_40 > 42)
  {
    acc = ((acc + (vector_40 * 2)) + 5) & 127;
    aux ^= vector_40 & 15;
  }
  else
  {
    acc = ((acc - vector_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001150_5013_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st_1 = {0};
  struct FilterState_R001150_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int vector_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_50_1) & 63;
  aux_2 = (aux_2 + vector_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_21_1)
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

  switch (metric_21_2)
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
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_50_1 == vector_50_2);
  assert(metric_21_1 == metric_21_2);
}

int fn_R001150_5013_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int vector_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_50) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_21 = (aux + st.buffer[1]) & 3;
  switch (metric_21)
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

void fn_R001150_5013_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st_1 = {0};
  struct FilterState_R001150_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_61_1)
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

  switch (metric_61_2)
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

  int index_reg_66_1 = 0;
  int index_reg_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_66_1 = ((index_reg_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_66_2 = ((index_reg_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_66_1) & 127;
    acc_2 = (acc_2 + index_reg_66_2) & 127;
  }

  int sample_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_13_1) & 63;
  aux_2 = (aux_2 + sample_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_61_1 == metric_61_2);
  assert(index_reg_66_1 == index_reg_66_2);
  assert(sample_13_1 == sample_13_2);
}

int fn_R001150_5013_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001150_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_61 = (aux + st.buffer[1]) & 3;
  switch (metric_61)
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

  int index_reg_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_66 = ((index_reg_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_66) & 127;
  }

  int sample_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001150_5013_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st_1 = {0};
  struct AudioFrame_R001150_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int anchor_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_45_1)
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

  switch (anchor_45_2)
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

  int tracker_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_44_1) & 63;
  aux_2 = (aux_2 + tracker_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_24_1 = local_arr_1[aux_1 % 3];
  int factor_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_24_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_45_1 == anchor_45_2);
  assert(tracker_44_1 == tracker_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_24_1 == factor_24_2);
}

int fn_R001150_5013_23(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001150_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int anchor_45 = (aux + st.buffer[1]) & 3;
  switch (anchor_45)
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

  int tracker_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_44) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_24 = local_arr[aux % 3];
  acc = (acc + (factor_24 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001150_0_1;
  int sec_r001150_0_2;
  int sec_r001150_1_1;
  int sec_r001150_1_2;
  int sec_r001150_2_1;
  int sec_r001150_2_2;
  int sec_r001150_3_1;
  int sec_r001150_3_2;
  int sec_r001150_4_1;
  int sec_r001150_4_2;
  int sec_r001150_5_1;
  int sec_r001150_5_2;
  int sec_r001150_6_1;
  int sec_r001150_6_2;
  int sec_r001150_7_1;
  int sec_r001150_7_2;
  int sec_r001150_8_1;
  int sec_r001150_8_2;
  int sec_r001150_9_1;
  int sec_r001150_9_2;
  int sec_r001150_10_1;
  int sec_r001150_10_2;
  int sec_r001150_11_1;
  int sec_r001150_11_2;
  int sec_r001150_12_1;
  int sec_r001150_12_2;
  int sec_r001150_13_1;
  int sec_r001150_13_2;
  int sec_r001150_14_1;
  int sec_r001150_14_2;
  int sec_r001150_15_1;
  int sec_r001150_15_2;
  int sec_r001150_16_1;
  int sec_r001150_16_2;
  int sec_r001150_17_1;
  int sec_r001150_17_2;
  int sec_r001150_18_1;
  int sec_r001150_18_2;
  int sec_r001150_19_1;
  int sec_r001150_19_2;
  int sec_r001150_20_1;
  int sec_r001150_20_2;
  int sec_r001150_21_1;
  int sec_r001150_21_2;
  int sec_r001150_22_1;
  int sec_r001150_22_2;
  int pub_r001150_0_1;
  int pub_r001150_0_2;
  int pub_r001150_1_1;
  int pub_r001150_1_2;
  int pub_r001150_2_1;
  int pub_r001150_2_2;
  int pub_r001150_3_1;
  int pub_r001150_3_2;
  int pub_r001150_4_1;
  int pub_r001150_4_2;
  int pub_r001150_5_1;
  int pub_r001150_5_2;
  int pub_r001150_6_1;
  int pub_r001150_6_2;
  int pub_r001150_7_1;
  int pub_r001150_7_2;
  int pub_r001150_8_1;
  int pub_r001150_8_2;
  int pub_r001150_9_1;
  int pub_r001150_9_2;
  int pub_r001150_10_1;
  int pub_r001150_10_2;
  int pub_r001150_11_1;
  int pub_r001150_11_2;
  int pub_r001150_12_1;
  int pub_r001150_12_2;
  int pub_r001150_13_1;
  int pub_r001150_13_2;
  int pub_r001150_14_1;
  int pub_r001150_14_2;
  int pub_r001150_15_1;
  int pub_r001150_15_2;
  int pub_r001150_16_1;
  int pub_r001150_16_2;
  int pub_r001150_17_1;
  int pub_r001150_17_2;
  int pub_r001150_18_1;
  int pub_r001150_18_2;
  int pub_r001150_19_1;
  int pub_r001150_19_2;
  int pub_r001150_20_1;
  int pub_r001150_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001150_0_1 >= (-100)) && (pub_r001150_0_1 <= 100));
  __CPROVER_assume((pub_r001150_0_2 >= (-100)) && (pub_r001150_0_2 <= 100));
  __CPROVER_assume((pub_r001150_1_1 >= (-100)) && (pub_r001150_1_1 <= 100));
  __CPROVER_assume((pub_r001150_1_2 >= (-100)) && (pub_r001150_1_2 <= 100));
  __CPROVER_assume((pub_r001150_2_1 >= (-100)) && (pub_r001150_2_1 <= 100));
  __CPROVER_assume((pub_r001150_2_2 >= (-100)) && (pub_r001150_2_2 <= 100));
  __CPROVER_assume((pub_r001150_3_1 >= (-100)) && (pub_r001150_3_1 <= 100));
  __CPROVER_assume((pub_r001150_3_2 >= (-100)) && (pub_r001150_3_2 <= 100));
  __CPROVER_assume((pub_r001150_4_1 >= (-100)) && (pub_r001150_4_1 <= 100));
  __CPROVER_assume((pub_r001150_4_2 >= (-100)) && (pub_r001150_4_2 <= 100));
  __CPROVER_assume((pub_r001150_5_1 >= (-100)) && (pub_r001150_5_1 <= 100));
  __CPROVER_assume((pub_r001150_5_2 >= (-100)) && (pub_r001150_5_2 <= 100));
  __CPROVER_assume((pub_r001150_6_1 >= (-100)) && (pub_r001150_6_1 <= 100));
  __CPROVER_assume((pub_r001150_6_2 >= (-100)) && (pub_r001150_6_2 <= 100));
  __CPROVER_assume((pub_r001150_7_1 >= (-100)) && (pub_r001150_7_1 <= 100));
  __CPROVER_assume((pub_r001150_7_2 >= (-100)) && (pub_r001150_7_2 <= 100));
  __CPROVER_assume((pub_r001150_8_1 >= (-100)) && (pub_r001150_8_1 <= 100));
  __CPROVER_assume((pub_r001150_8_2 >= (-100)) && (pub_r001150_8_2 <= 100));
  __CPROVER_assume((pub_r001150_9_1 >= (-100)) && (pub_r001150_9_1 <= 100));
  __CPROVER_assume((pub_r001150_9_2 >= (-100)) && (pub_r001150_9_2 <= 100));
  __CPROVER_assume((pub_r001150_10_1 >= (-100)) && (pub_r001150_10_1 <= 100));
  __CPROVER_assume((pub_r001150_10_2 >= (-100)) && (pub_r001150_10_2 <= 100));
  __CPROVER_assume((pub_r001150_11_1 >= (-100)) && (pub_r001150_11_1 <= 100));
  __CPROVER_assume((pub_r001150_11_2 >= (-100)) && (pub_r001150_11_2 <= 100));
  __CPROVER_assume((pub_r001150_12_1 >= (-100)) && (pub_r001150_12_1 <= 100));
  __CPROVER_assume((pub_r001150_12_2 >= (-100)) && (pub_r001150_12_2 <= 100));
  __CPROVER_assume((pub_r001150_13_1 >= (-100)) && (pub_r001150_13_1 <= 100));
  __CPROVER_assume((pub_r001150_13_2 >= (-100)) && (pub_r001150_13_2 <= 100));
  __CPROVER_assume((pub_r001150_14_1 >= (-100)) && (pub_r001150_14_1 <= 100));
  __CPROVER_assume((pub_r001150_14_2 >= (-100)) && (pub_r001150_14_2 <= 100));
  __CPROVER_assume((pub_r001150_15_1 >= (-100)) && (pub_r001150_15_1 <= 100));
  __CPROVER_assume((pub_r001150_15_2 >= (-100)) && (pub_r001150_15_2 <= 100));
  __CPROVER_assume((pub_r001150_16_1 >= (-100)) && (pub_r001150_16_1 <= 100));
  __CPROVER_assume((pub_r001150_16_2 >= (-100)) && (pub_r001150_16_2 <= 100));
  __CPROVER_assume((pub_r001150_17_1 >= (-100)) && (pub_r001150_17_1 <= 100));
  __CPROVER_assume((pub_r001150_17_2 >= (-100)) && (pub_r001150_17_2 <= 100));
  __CPROVER_assume((pub_r001150_18_1 >= (-100)) && (pub_r001150_18_1 <= 100));
  __CPROVER_assume((pub_r001150_18_2 >= (-100)) && (pub_r001150_18_2 <= 100));
  __CPROVER_assume((pub_r001150_19_1 >= (-100)) && (pub_r001150_19_1 <= 100));
  __CPROVER_assume((pub_r001150_19_2 >= (-100)) && (pub_r001150_19_2 <= 100));
  __CPROVER_assume((pub_r001150_20_1 >= (-100)) && (pub_r001150_20_1 <= 100));
  __CPROVER_assume((pub_r001150_20_2 >= (-100)) && (pub_r001150_20_2 <= 100));
  __CPROVER_assume((sec_r001150_0_1 >= 0) && (sec_r001150_0_1 <= 255));
  __CPROVER_assume((sec_r001150_0_2 >= 0) && (sec_r001150_0_2 <= 255));
  __CPROVER_assume((sec_r001150_1_1 >= 0) && (sec_r001150_1_1 <= 255));
  __CPROVER_assume((sec_r001150_1_2 >= 0) && (sec_r001150_1_2 <= 255));
  __CPROVER_assume((sec_r001150_2_1 >= 0) && (sec_r001150_2_1 <= 255));
  __CPROVER_assume((sec_r001150_2_2 >= 0) && (sec_r001150_2_2 <= 255));
  __CPROVER_assume((sec_r001150_3_1 >= 0) && (sec_r001150_3_1 <= 255));
  __CPROVER_assume((sec_r001150_3_2 >= 0) && (sec_r001150_3_2 <= 255));
  __CPROVER_assume((sec_r001150_4_1 >= 0) && (sec_r001150_4_1 <= 255));
  __CPROVER_assume((sec_r001150_4_2 >= 0) && (sec_r001150_4_2 <= 255));
  __CPROVER_assume((sec_r001150_5_1 >= 0) && (sec_r001150_5_1 <= 255));
  __CPROVER_assume((sec_r001150_5_2 >= 0) && (sec_r001150_5_2 <= 255));
  __CPROVER_assume((sec_r001150_6_1 >= 0) && (sec_r001150_6_1 <= 255));
  __CPROVER_assume((sec_r001150_6_2 >= 0) && (sec_r001150_6_2 <= 255));
  __CPROVER_assume((sec_r001150_7_1 >= 0) && (sec_r001150_7_1 <= 255));
  __CPROVER_assume((sec_r001150_7_2 >= 0) && (sec_r001150_7_2 <= 255));
  __CPROVER_assume((sec_r001150_8_1 >= 0) && (sec_r001150_8_1 <= 255));
  __CPROVER_assume((sec_r001150_8_2 >= 0) && (sec_r001150_8_2 <= 255));
  __CPROVER_assume((sec_r001150_9_1 >= 0) && (sec_r001150_9_1 <= 255));
  __CPROVER_assume((sec_r001150_9_2 >= 0) && (sec_r001150_9_2 <= 255));
  __CPROVER_assume((sec_r001150_10_1 >= 0) && (sec_r001150_10_1 <= 255));
  __CPROVER_assume((sec_r001150_10_2 >= 0) && (sec_r001150_10_2 <= 255));
  __CPROVER_assume((sec_r001150_11_1 >= 0) && (sec_r001150_11_1 <= 255));
  __CPROVER_assume((sec_r001150_11_2 >= 0) && (sec_r001150_11_2 <= 255));
  __CPROVER_assume((sec_r001150_12_1 >= 0) && (sec_r001150_12_1 <= 255));
  __CPROVER_assume((sec_r001150_12_2 >= 0) && (sec_r001150_12_2 <= 255));
  __CPROVER_assume((sec_r001150_13_1 >= 0) && (sec_r001150_13_1 <= 255));
  __CPROVER_assume((sec_r001150_13_2 >= 0) && (sec_r001150_13_2 <= 255));
  __CPROVER_assume((sec_r001150_14_1 >= 0) && (sec_r001150_14_1 <= 255));
  __CPROVER_assume((sec_r001150_14_2 >= 0) && (sec_r001150_14_2 <= 255));
  __CPROVER_assume((sec_r001150_15_1 >= 0) && (sec_r001150_15_1 <= 255));
  __CPROVER_assume((sec_r001150_15_2 >= 0) && (sec_r001150_15_2 <= 255));
  __CPROVER_assume((sec_r001150_16_1 >= 0) && (sec_r001150_16_1 <= 255));
  __CPROVER_assume((sec_r001150_16_2 >= 0) && (sec_r001150_16_2 <= 255));
  __CPROVER_assume((sec_r001150_17_1 >= 0) && (sec_r001150_17_1 <= 255));
  __CPROVER_assume((sec_r001150_17_2 >= 0) && (sec_r001150_17_2 <= 255));
  __CPROVER_assume((sec_r001150_18_1 >= 0) && (sec_r001150_18_1 <= 255));
  __CPROVER_assume((sec_r001150_18_2 >= 0) && (sec_r001150_18_2 <= 255));
  __CPROVER_assume((sec_r001150_19_1 >= 0) && (sec_r001150_19_1 <= 255));
  __CPROVER_assume((sec_r001150_19_2 >= 0) && (sec_r001150_19_2 <= 255));
  __CPROVER_assume((sec_r001150_20_1 >= 0) && (sec_r001150_20_1 <= 255));
  __CPROVER_assume((sec_r001150_20_2 >= 0) && (sec_r001150_20_2 <= 255));
  __CPROVER_assume((sec_r001150_21_1 >= 0) && (sec_r001150_21_1 <= 255));
  __CPROVER_assume((sec_r001150_21_2 >= 0) && (sec_r001150_21_2 <= 255));
  __CPROVER_assume((sec_r001150_22_1 >= 0) && (sec_r001150_22_1 <= 255));
  __CPROVER_assume((sec_r001150_22_2 >= 0) && (sec_r001150_22_2 <= 255));
  struct FilterState_R001150_5013_0 st_var_0_1 = {0};
  struct FilterState_R001150_5013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001150_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001150_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001150_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001150_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001150_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001150_0_2 + 7) & 15;
  struct AudioFrame_R001150_5013_1 st_var_1_1 = {0};
  struct AudioFrame_R001150_5013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001150_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001150_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001150_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001150_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001150_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001150_0_2 + 9) & 15;
  union ColorPixel_R001150_5013_0 u_var_1;
  union ColorPixel_R001150_5013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001150_5013_0(sec_r001150_0_1, pub_r001150_1_1);
  int helper_flow_0_2 = fn_R001150_5013_0(sec_r001150_0_2, pub_r001150_1_2);
  fn_R001150_5013_0_2(sec_r001150_0_1, pub_r001150_1_1, sec_r001150_0_2, pub_r001150_1_2);
  int helper_flow_1_1 = fn_R001150_5013_1(sec_r001150_1_1, sec_r001150_2_1, pub_r001150_3_1, pub_r001150_4_1);
  int helper_flow_1_2 = fn_R001150_5013_1(sec_r001150_1_2, sec_r001150_2_2, pub_r001150_3_2, pub_r001150_4_2);
  fn_R001150_5013_1_2(sec_r001150_1_1, sec_r001150_2_1, pub_r001150_3_1, pub_r001150_4_1, sec_r001150_1_2, sec_r001150_2_2, pub_r001150_3_2, pub_r001150_4_2);
  int helper_flow_2_1 = fn_R001150_5013_2(sec_r001150_2_1, pub_r001150_3_1, pub_r001150_4_1);
  int helper_flow_2_2 = fn_R001150_5013_2(sec_r001150_2_2, pub_r001150_3_2, pub_r001150_4_2);
  fn_R001150_5013_2_2(sec_r001150_2_1, pub_r001150_3_1, pub_r001150_4_1, sec_r001150_2_2, pub_r001150_3_2, pub_r001150_4_2);
  int helper_flow_3_1 = fn_R001150_5013_3(sec_r001150_3_1, pub_r001150_4_1, pub_r001150_5_1, pub_r001150_6_1, pub_r001150_7_1);
  int helper_flow_3_2 = fn_R001150_5013_3(sec_r001150_3_2, pub_r001150_4_2, pub_r001150_5_2, pub_r001150_6_2, pub_r001150_7_2);
  fn_R001150_5013_3_2(sec_r001150_3_1, pub_r001150_4_1, pub_r001150_5_1, pub_r001150_6_1, pub_r001150_7_1, sec_r001150_3_2, pub_r001150_4_2, pub_r001150_5_2, pub_r001150_6_2, pub_r001150_7_2);
  int helper_flow_4_1 = fn_R001150_5013_4(sec_r001150_4_1, sec_r001150_5_1, pub_r001150_6_1, pub_r001150_7_1, pub_r001150_8_1);
  int helper_flow_4_2 = fn_R001150_5013_4(sec_r001150_4_2, sec_r001150_5_2, pub_r001150_6_2, pub_r001150_7_2, pub_r001150_8_2);
  fn_R001150_5013_4_2(sec_r001150_4_1, sec_r001150_5_1, pub_r001150_6_1, pub_r001150_7_1, pub_r001150_8_1, sec_r001150_4_2, sec_r001150_5_2, pub_r001150_6_2, pub_r001150_7_2, pub_r001150_8_2);
  int helper_flow_5_1 = fn_R001150_5013_5(sec_r001150_5_1, sec_r001150_6_1, pub_r001150_7_1, pub_r001150_8_1, pub_r001150_9_1);
  int helper_flow_5_2 = fn_R001150_5013_5(sec_r001150_5_2, sec_r001150_6_2, pub_r001150_7_2, pub_r001150_8_2, pub_r001150_9_2);
  fn_R001150_5013_5_2(sec_r001150_5_1, sec_r001150_6_1, pub_r001150_7_1, pub_r001150_8_1, pub_r001150_9_1, sec_r001150_5_2, sec_r001150_6_2, pub_r001150_7_2, pub_r001150_8_2, pub_r001150_9_2);
  int helper_flow_6_1 = fn_R001150_5013_6(sec_r001150_6_1, pub_r001150_7_1, pub_r001150_8_1, pub_r001150_9_1);
  int helper_flow_6_2 = fn_R001150_5013_6(sec_r001150_6_2, pub_r001150_7_2, pub_r001150_8_2, pub_r001150_9_2);
  fn_R001150_5013_6_2(sec_r001150_6_1, pub_r001150_7_1, pub_r001150_8_1, pub_r001150_9_1, sec_r001150_6_2, pub_r001150_7_2, pub_r001150_8_2, pub_r001150_9_2);
  int helper_flow_7_1 = fn_R001150_5013_7(sec_r001150_7_1, pub_r001150_8_1);
  int helper_flow_7_2 = fn_R001150_5013_7(sec_r001150_7_2, pub_r001150_8_2);
  fn_R001150_5013_7_2(sec_r001150_7_1, pub_r001150_8_1, sec_r001150_7_2, pub_r001150_8_2);
  int helper_flow_8_1 = fn_R001150_5013_8(sec_r001150_8_1, pub_r001150_9_1, pub_r001150_10_1, pub_r001150_11_1);
  int helper_flow_8_2 = fn_R001150_5013_8(sec_r001150_8_2, pub_r001150_9_2, pub_r001150_10_2, pub_r001150_11_2);
  fn_R001150_5013_8_2(sec_r001150_8_1, pub_r001150_9_1, pub_r001150_10_1, pub_r001150_11_1, sec_r001150_8_2, pub_r001150_9_2, pub_r001150_10_2, pub_r001150_11_2);
  int helper_flow_9_1 = fn_R001150_5013_9(sec_r001150_9_1, pub_r001150_10_1, pub_r001150_11_1, pub_r001150_12_1);
  int helper_flow_9_2 = fn_R001150_5013_9(sec_r001150_9_2, pub_r001150_10_2, pub_r001150_11_2, pub_r001150_12_2);
  fn_R001150_5013_9_2(sec_r001150_9_1, pub_r001150_10_1, pub_r001150_11_1, pub_r001150_12_1, sec_r001150_9_2, pub_r001150_10_2, pub_r001150_11_2, pub_r001150_12_2);
  int helper_flow_10_1 = fn_R001150_5013_10(sec_r001150_10_1, sec_r001150_11_1, pub_r001150_12_1);
  int helper_flow_10_2 = fn_R001150_5013_10(sec_r001150_10_2, sec_r001150_11_2, pub_r001150_12_2);
  fn_R001150_5013_10_2(sec_r001150_10_1, sec_r001150_11_1, pub_r001150_12_1, sec_r001150_10_2, sec_r001150_11_2, pub_r001150_12_2);
  int helper_flow_11_1 = fn_R001150_5013_11(sec_r001150_11_1, pub_r001150_12_1, pub_r001150_13_1, pub_r001150_14_1, pub_r001150_15_1);
  int helper_flow_11_2 = fn_R001150_5013_11(sec_r001150_11_2, pub_r001150_12_2, pub_r001150_13_2, pub_r001150_14_2, pub_r001150_15_2);
  fn_R001150_5013_11_2(sec_r001150_11_1, pub_r001150_12_1, pub_r001150_13_1, pub_r001150_14_1, pub_r001150_15_1, sec_r001150_11_2, pub_r001150_12_2, pub_r001150_13_2, pub_r001150_14_2, pub_r001150_15_2);
  int helper_flow_12_1 = fn_R001150_5013_12(sec_r001150_12_1, pub_r001150_13_1);
  int helper_flow_12_2 = fn_R001150_5013_12(sec_r001150_12_2, pub_r001150_13_2);
  fn_R001150_5013_12_2(sec_r001150_12_1, pub_r001150_13_1, sec_r001150_12_2, pub_r001150_13_2);
  int stage_v_0_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001150_6_1) & 127;
  int stage_v_0_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001150_6_2) & 127;
  if (stage_v_0_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((sec_r001150_0_1 ^ 0x2A) * 2) + pub_r001150_1_1) & 127;
  int stage_v_1_2 = (((sec_r001150_0_2 ^ 0x2A) * 2) + pub_r001150_1_2) & 127;
  if (stage_v_1_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((sec_r001150_10_1 ^ 0x2A) * 2) + pub_r001150_19_1) & 127;
  int stage_v_2_2 = (((sec_r001150_10_2 ^ 0x2A) * 2) + pub_r001150_19_2) & 127;
  if (stage_v_2_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((sec_r001150_22_1 ^ 0x2A) * 2) + pub_r001150_19_1) & 127;
  int stage_v_3_2 = (((sec_r001150_22_2 ^ 0x2A) * 2) + pub_r001150_19_2) & 127;
  if (stage_v_3_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001150_3_1) & 127;
  int stage_v_4_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001150_3_2) & 127;
  if (stage_v_4_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001150_20_1) & 127;
  int stage_v_5_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001150_20_2) & 127;
  if (stage_v_5_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = ((pub_r001150_9_1 * 2) + 43) & 63;
  int stage_v_6_2 = ((pub_r001150_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((sec_r001150_1_1 ^ 0x2A) * 2) + pub_r001150_5_1) & 127;
  int stage_v_7_2 = (((sec_r001150_1_2 ^ 0x2A) * 2) + pub_r001150_5_2) & 127;
  if (stage_v_7_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001150_9_1) & 127;
  int stage_v_8_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001150_9_2) & 127;
  if (stage_v_8_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = ((pub_r001150_15_1 * 2) + 13) & 63;
  int stage_v_9_2 = ((pub_r001150_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001150_7_1) & 127;
  int stage_v_10_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001150_7_2) & 127;
  if (stage_v_10_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001150_7_1) & 127;
  int stage_v_11_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001150_7_2) & 127;
  if (stage_v_11_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001150_0_1) & 127;
  int stage_v_12_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001150_0_2) & 127;
  if (stage_v_12_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((pub_r001150_0_1 * 2) + 50) & 63;
  int stage_v_13_2 = ((pub_r001150_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001150_18_1 * 2) + 35) & 63;
  int stage_v_14_2 = ((pub_r001150_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001150_17_1) & 127;
  int stage_v_15_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001150_17_2) & 127;
  if (stage_v_15_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((sec_r001150_9_1 ^ 0x2A) * 2) + pub_r001150_20_1) & 127;
  int stage_v_16_2 = (((sec_r001150_9_2 ^ 0x2A) * 2) + pub_r001150_20_2) & 127;
  if (stage_v_16_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((sec_r001150_8_1 ^ 0x2A) * 2) + pub_r001150_11_1) & 127;
  int stage_v_17_2 = (((sec_r001150_8_2 ^ 0x2A) * 2) + pub_r001150_11_2) & 127;
  if (stage_v_17_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((sec_r001150_4_1 ^ 0x2A) * 2) + pub_r001150_1_1) & 127;
  int stage_v_18_2 = (((sec_r001150_4_2 ^ 0x2A) * 2) + pub_r001150_1_2) & 127;
  if (stage_v_18_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001150_10_1) & 127;
  int stage_v_19_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001150_10_2) & 127;
  if (stage_v_19_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((sec_r001150_3_1 ^ 0x2A) * 2) + pub_r001150_20_1) & 127;
  int stage_v_20_2 = (((sec_r001150_3_2 ^ 0x2A) * 2) + pub_r001150_20_2) & 127;
  if (stage_v_20_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001150_3_1) & 127;
  int stage_v_21_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001150_3_2) & 127;
  if (stage_v_21_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001150_4_1) & 127;
  int stage_v_22_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001150_4_2) & 127;
  if (stage_v_22_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((sec_r001150_20_1 ^ 0x2A) * 2) + pub_r001150_14_1) & 127;
  int stage_v_23_2 = (((sec_r001150_20_2 ^ 0x2A) * 2) + pub_r001150_14_2) & 127;
  if (stage_v_23_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((pub_r001150_20_1 * 2) + 31) & 63;
  int stage_v_24_2 = ((pub_r001150_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (((sec_r001150_3_1 ^ 0x2A) * 2) + pub_r001150_6_1) & 127;
  int stage_v_25_2 = (((sec_r001150_3_2 ^ 0x2A) * 2) + pub_r001150_6_2) & 127;
  if (stage_v_25_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((sec_r001150_2_1 ^ 0x2A) * 2) + pub_r001150_15_1) & 127;
  int stage_v_26_2 = (((sec_r001150_2_2 ^ 0x2A) * 2) + pub_r001150_15_2) & 127;
  if (stage_v_26_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((pub_r001150_0_1 * 2) + 44) & 63;
  int stage_v_27_2 = ((pub_r001150_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001150_1_1) & 127;
  int stage_v_28_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001150_1_2) & 127;
  if (stage_v_28_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001150_18_1) & 127;
  int stage_v_29_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001150_18_2) & 127;
  if (stage_v_29_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001150_0_1) & 127;
  int stage_v_30_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001150_0_2) & 127;
  if (stage_v_30_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001150_14_1) & 127;
  int stage_v_31_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001150_14_2) & 127;
  if (stage_v_31_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((pub_r001150_10_1 * 2) + 7) & 63;
  int stage_v_32_2 = ((pub_r001150_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001150_3_1 * 2) + 34) & 63;
  int stage_v_33_2 = ((pub_r001150_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001150_8_1 * 2) + 5) & 63;
  int stage_v_34_2 = ((pub_r001150_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001150_7_1) & 127;
  int stage_v_35_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001150_7_2) & 127;
  if (stage_v_35_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001150_16_1) & 127;
  int stage_v_36_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001150_16_2) & 127;
  if (stage_v_36_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001150_19_1) & 127;
  int stage_v_37_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001150_19_2) & 127;
  if (stage_v_37_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((sec_r001150_10_1 ^ 0x2A) * 2) + pub_r001150_20_1) & 127;
  int stage_v_38_2 = (((sec_r001150_10_2 ^ 0x2A) * 2) + pub_r001150_20_2) & 127;
  if (stage_v_38_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((sec_r001150_13_1 ^ 0x2A) * 2) + pub_r001150_12_1) & 127;
  int stage_v_39_2 = (((sec_r001150_13_2 ^ 0x2A) * 2) + pub_r001150_12_2) & 127;
  if (stage_v_39_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((pub_r001150_7_1 * 2) + 13) & 63;
  int stage_v_40_2 = ((pub_r001150_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001150_5_1) & 127;
  int stage_v_41_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001150_5_2) & 127;
  if (stage_v_41_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001150_6_1) & 127;
  int stage_v_42_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001150_6_2) & 127;
  if (stage_v_42_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001150_16_1) & 127;
  int stage_v_43_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001150_16_2) & 127;
  if (stage_v_43_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((pub_r001150_15_1 * 2) + 24) & 63;
  int stage_v_44_2 = ((pub_r001150_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((sec_r001150_22_1 ^ 0x2A) * 2) + pub_r001150_15_1) & 127;
  int stage_v_45_2 = (((sec_r001150_22_2 ^ 0x2A) * 2) + pub_r001150_15_2) & 127;
  if (stage_v_45_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((sec_r001150_17_1 ^ 0x2A) * 2) + pub_r001150_12_1) & 127;
  int stage_v_46_2 = (((sec_r001150_17_2 ^ 0x2A) * 2) + pub_r001150_12_2) & 127;
  if (stage_v_46_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((pub_r001150_5_1 * 2) + 43) & 63;
  int stage_v_47_2 = ((pub_r001150_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001150_19_1) & 127;
  int stage_v_48_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001150_19_2) & 127;
  if (stage_v_48_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001150_7_1) & 127;
  int stage_v_49_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001150_7_2) & 127;
  if (stage_v_49_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001150_1_1) & 127;
  int stage_v_50_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001150_1_2) & 127;
  if (stage_v_50_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((sec_r001150_14_1 ^ 0x2A) * 2) + pub_r001150_0_1) & 127;
  int stage_v_51_2 = (((sec_r001150_14_2 ^ 0x2A) * 2) + pub_r001150_0_2) & 127;
  if (stage_v_51_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((sec_r001150_7_1 ^ 0x2A) * 2) + pub_r001150_19_1) & 127;
  int stage_v_52_2 = (((sec_r001150_7_2 ^ 0x2A) * 2) + pub_r001150_19_2) & 127;
  if (stage_v_52_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((sec_r001150_2_1 ^ 0x2A) * 2) + pub_r001150_1_1) & 127;
  int stage_v_53_2 = (((sec_r001150_2_2 ^ 0x2A) * 2) + pub_r001150_1_2) & 127;
  if (stage_v_53_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001150_1_1) & 127;
  int stage_v_54_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001150_1_2) & 127;
  if (stage_v_54_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((sec_r001150_19_1 ^ 0x2A) * 2) + pub_r001150_3_1) & 127;
  int stage_v_55_2 = (((sec_r001150_19_2 ^ 0x2A) * 2) + pub_r001150_3_2) & 127;
  if (stage_v_55_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001150_10_1) & 127;
  int stage_v_56_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001150_10_2) & 127;
  if (stage_v_56_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((sec_r001150_8_1 ^ 0x2A) * 2) + pub_r001150_8_1) & 127;
  int stage_v_57_2 = (((sec_r001150_8_2 ^ 0x2A) * 2) + pub_r001150_8_2) & 127;
  if (stage_v_57_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((sec_r001150_4_1 ^ 0x2A) * 2) + pub_r001150_16_1) & 127;
  int stage_v_58_2 = (((sec_r001150_4_2 ^ 0x2A) * 2) + pub_r001150_16_2) & 127;
  if (stage_v_58_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001150_10_1) & 127;
  int stage_v_59_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001150_10_2) & 127;
  if (stage_v_59_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((sec_r001150_6_1 ^ 0x2A) * 2) + pub_r001150_19_1) & 127;
  int stage_v_60_2 = (((sec_r001150_6_2 ^ 0x2A) * 2) + pub_r001150_19_2) & 127;
  if (stage_v_60_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((pub_r001150_6_1 * 2) + 6) & 63;
  int stage_v_61_2 = ((pub_r001150_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001150_15_1) & 127;
  int stage_v_62_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001150_15_2) & 127;
  if (stage_v_62_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001150_18_1) & 127;
  int stage_v_63_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001150_18_2) & 127;
  if (stage_v_63_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001150_3_1) & 127;
  int stage_v_64_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001150_3_2) & 127;
  if (stage_v_64_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((sec_r001150_20_1 ^ 0x2A) * 2) + pub_r001150_8_1) & 127;
  int stage_v_65_2 = (((sec_r001150_20_2 ^ 0x2A) * 2) + pub_r001150_8_2) & 127;
  if (stage_v_65_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001150_0_1) & 127;
  int stage_v_66_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001150_0_2) & 127;
  if (stage_v_66_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001150_4_1) & 127;
  int stage_v_67_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001150_4_2) & 127;
  if (stage_v_67_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((pub_r001150_17_1 * 2) + 16) & 63;
  int stage_v_68_2 = ((pub_r001150_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (((sec_r001150_6_1 ^ 0x2A) * 2) + pub_r001150_19_1) & 127;
  int stage_v_69_2 = (((sec_r001150_6_2 ^ 0x2A) * 2) + pub_r001150_19_2) & 127;
  if (stage_v_69_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001150_18_1) & 127;
  int stage_v_70_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001150_18_2) & 127;
  if (stage_v_70_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((pub_r001150_16_1 * 2) + 34) & 63;
  int stage_v_71_2 = ((pub_r001150_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001150_3_1) & 127;
  int stage_v_72_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001150_3_2) & 127;
  if (stage_v_72_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001150_19_1) & 127;
  int stage_v_73_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001150_19_2) & 127;
  if (stage_v_73_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((pub_r001150_13_1 * 2) + 14) & 63;
  int stage_v_74_2 = ((pub_r001150_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001150_18_1) & 127;
  int stage_v_75_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001150_18_2) & 127;
  if (stage_v_75_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((sec_r001150_6_1 ^ 0x2A) * 2) + pub_r001150_19_1) & 127;
  int stage_v_76_2 = (((sec_r001150_6_2 ^ 0x2A) * 2) + pub_r001150_19_2) & 127;
  if (stage_v_76_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001150_3_1) & 127;
  int stage_v_77_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001150_3_2) & 127;
  if (stage_v_77_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001150_11_1) & 127;
  int stage_v_78_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001150_11_2) & 127;
  if (stage_v_78_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((sec_r001150_16_1 ^ 0x2A) * 2) + pub_r001150_4_1) & 127;
  int stage_v_79_2 = (((sec_r001150_16_2 ^ 0x2A) * 2) + pub_r001150_4_2) & 127;
  if (stage_v_79_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001150_6_1) & 127;
  int stage_v_80_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001150_6_2) & 127;
  if (stage_v_80_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001150_8_1) & 127;
  int stage_v_81_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001150_8_2) & 127;
  if (stage_v_81_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001150_5_1) & 127;
  int stage_v_82_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001150_5_2) & 127;
  if (stage_v_82_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((sec_r001150_16_1 ^ 0x2A) * 2) + pub_r001150_16_1) & 127;
  int stage_v_83_2 = (((sec_r001150_16_2 ^ 0x2A) * 2) + pub_r001150_16_2) & 127;
  if (stage_v_83_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001150_8_1) & 127;
  int stage_v_84_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001150_8_2) & 127;
  if (stage_v_84_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((pub_r001150_14_1 * 2) + 10) & 63;
  int stage_v_85_2 = ((pub_r001150_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001150_16_1) & 127;
  int stage_v_86_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001150_16_2) & 127;
  if (stage_v_86_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((sec_r001150_9_1 ^ 0x2A) * 2) + pub_r001150_20_1) & 127;
  int stage_v_87_2 = (((sec_r001150_9_2 ^ 0x2A) * 2) + pub_r001150_20_2) & 127;
  if (stage_v_87_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((pub_r001150_17_1 * 2) + 12) & 63;
  int stage_v_88_2 = ((pub_r001150_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001150_6_1) & 127;
  int stage_v_89_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001150_6_2) & 127;
  if (stage_v_89_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((sec_r001150_19_1 ^ 0x2A) * 2) + pub_r001150_3_1) & 127;
  int stage_v_90_2 = (((sec_r001150_19_2 ^ 0x2A) * 2) + pub_r001150_3_2) & 127;
  if (stage_v_90_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((pub_r001150_1_1 * 2) + 41) & 63;
  int stage_v_91_2 = ((pub_r001150_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001150_15_1) & 127;
  int stage_v_92_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001150_15_2) & 127;
  if (stage_v_92_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001150_8_1) & 127;
  int stage_v_93_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001150_8_2) & 127;
  if (stage_v_93_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((pub_r001150_13_1 * 2) + 11) & 63;
  int stage_v_94_2 = ((pub_r001150_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001150_14_1) & 127;
  int stage_v_95_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001150_14_2) & 127;
  if (stage_v_95_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001150_1_1) & 127;
  int stage_v_96_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001150_1_2) & 127;
  if (stage_v_96_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001150_7_1) & 127;
  int stage_v_97_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001150_7_2) & 127;
  if (stage_v_97_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((pub_r001150_8_1 * 2) + 29) & 63;
  int stage_v_98_2 = ((pub_r001150_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001150_6_1) & 127;
  int stage_v_99_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001150_6_2) & 127;
  if (stage_v_99_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001150_12_1) & 127;
  int stage_v_100_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001150_12_2) & 127;
  if (stage_v_100_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((pub_r001150_8_1 * 2) + 35) & 63;
  int stage_v_101_2 = ((pub_r001150_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001150_4_1) & 127;
  int stage_v_102_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001150_4_2) & 127;
  if (stage_v_102_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((pub_r001150_3_1 * 2) + 20) & 63;
  int stage_v_103_2 = ((pub_r001150_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001150_7_1 * 2) + 48) & 63;
  int stage_v_104_2 = ((pub_r001150_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001150_10_1) & 127;
  int stage_v_105_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001150_10_2) & 127;
  if (stage_v_105_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((sec_r001150_10_1 ^ 0x2A) * 2) + pub_r001150_5_1) & 127;
  int stage_v_106_2 = (((sec_r001150_10_2 ^ 0x2A) * 2) + pub_r001150_5_2) & 127;
  if (stage_v_106_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001150_19_1) & 127;
  int stage_v_107_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001150_19_2) & 127;
  if (stage_v_107_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((sec_r001150_1_1 ^ 0x2A) * 2) + pub_r001150_10_1) & 127;
  int stage_v_108_2 = (((sec_r001150_1_2 ^ 0x2A) * 2) + pub_r001150_10_2) & 127;
  if (stage_v_108_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((pub_r001150_18_1 * 2) + 8) & 63;
  int stage_v_109_2 = ((pub_r001150_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001150_1_1) & 127;
  int stage_v_110_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001150_1_2) & 127;
  if (stage_v_110_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((sec_r001150_21_1 ^ 0x2A) * 2) + pub_r001150_11_1) & 127;
  int stage_v_111_2 = (((sec_r001150_21_2 ^ 0x2A) * 2) + pub_r001150_11_2) & 127;
  if (stage_v_111_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((stage_v_81_1 ^ 0x2A) * 2) + pub_r001150_13_1) & 127;
  int stage_v_112_2 = (((stage_v_81_2 ^ 0x2A) * 2) + pub_r001150_13_2) & 127;
  if (stage_v_112_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((sec_r001150_5_1 ^ 0x2A) * 2) + pub_r001150_20_1) & 127;
  int stage_v_113_2 = (((sec_r001150_5_2 ^ 0x2A) * 2) + pub_r001150_20_2) & 127;
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
  int stage_v_114_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001150_13_1) & 127;
  int stage_v_114_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001150_13_2) & 127;
  if (stage_v_114_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001150_5_1) & 127;
  int stage_v_115_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001150_5_2) & 127;
  if (stage_v_115_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001150_7_1) & 127;
  int stage_v_116_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001150_7_2) & 127;
  if (stage_v_116_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001150_9_1) & 127;
  int stage_v_117_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001150_9_2) & 127;
  if (stage_v_117_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001150_3_1) & 127;
  int stage_v_118_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001150_3_2) & 127;
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
  int stage_v_119_1 = ((pub_r001150_10_1 * 2) + 44) & 63;
  int stage_v_119_2 = ((pub_r001150_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001150_19_1) & 127;
  int stage_v_120_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001150_19_2) & 127;
  if (stage_v_120_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001150_6_1) & 127;
  int stage_v_121_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001150_6_2) & 127;
  if (stage_v_121_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((pub_r001150_1_1 * 2) + 6) & 63;
  int stage_v_122_2 = ((pub_r001150_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((stage_v_67_1 ^ 0x2A) * 2) + pub_r001150_20_1) & 127;
  int stage_v_123_2 = (((stage_v_67_2 ^ 0x2A) * 2) + pub_r001150_20_2) & 127;
  if (stage_v_123_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001150_17_1) & 127;
  int stage_v_124_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001150_17_2) & 127;
  if (stage_v_124_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001150_5_1) & 127;
  int stage_v_125_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001150_5_2) & 127;
  if (stage_v_125_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((pub_r001150_11_1 * 2) + 37) & 63;
  int stage_v_126_2 = ((pub_r001150_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001150_6_1 * 2) + 20) & 63;
  int stage_v_127_2 = ((pub_r001150_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001150_8_1 * 2) + 38) & 63;
  int stage_v_128_2 = ((pub_r001150_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001150_18_1) & 127;
  int stage_v_129_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001150_18_2) & 127;
  if (stage_v_129_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001150_0_1) & 127;
  int stage_v_130_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001150_0_2) & 127;
  if (stage_v_130_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001150_8_1) & 127;
  int stage_v_131_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001150_8_2) & 127;
  if (stage_v_131_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((sec_r001150_17_1 ^ 0x2A) * 2) + pub_r001150_11_1) & 127;
  int stage_v_132_2 = (((sec_r001150_17_2 ^ 0x2A) * 2) + pub_r001150_11_2) & 127;
  if (stage_v_132_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((sec_r001150_2_1 ^ 0x2A) * 2) + pub_r001150_0_1) & 127;
  int stage_v_133_2 = (((sec_r001150_2_2 ^ 0x2A) * 2) + pub_r001150_0_2) & 127;
  if (stage_v_133_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((pub_r001150_20_1 * 2) + 27) & 63;
  int stage_v_134_2 = ((pub_r001150_20_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001150_16_1 * 2) + 30) & 63;
  int stage_v_135_2 = ((pub_r001150_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001150_9_1) & 127;
  int stage_v_136_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001150_9_2) & 127;
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
  int stage_v_137_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001150_1_1) & 127;
  int stage_v_137_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001150_1_2) & 127;
  if (stage_v_137_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001150_12_1) & 127;
  int stage_v_138_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001150_12_2) & 127;
  if (stage_v_138_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001150_13_1) & 127;
  int stage_v_139_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001150_13_2) & 127;
  if (stage_v_139_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001150_18_1) & 127;
  int stage_v_140_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001150_18_2) & 127;
  if (stage_v_140_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001150_18_1) & 127;
  int stage_v_141_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001150_18_2) & 127;
  if (stage_v_141_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001150_1_1) & 127;
  int stage_v_142_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001150_1_2) & 127;
  if (stage_v_142_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001150_18_1) & 127;
  int stage_v_143_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001150_18_2) & 127;
  if (stage_v_143_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((pub_r001150_10_1 * 2) + 42) & 63;
  int stage_v_144_2 = ((pub_r001150_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001150_18_1) & 127;
  int stage_v_145_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001150_18_2) & 127;
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
  int stage_v_146_1 = ((pub_r001150_14_1 * 2) + 47) & 63;
  int stage_v_146_2 = ((pub_r001150_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001150_10_1) & 127;
  int stage_v_147_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001150_10_2) & 127;
  if (stage_v_147_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((pub_r001150_5_1 * 2) + 16) & 63;
  int stage_v_148_2 = ((pub_r001150_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001150_10_1) & 127;
  int stage_v_149_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001150_10_2) & 127;
  if (stage_v_149_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((pub_r001150_5_1 * 2) + 35) & 63;
  int stage_v_150_2 = ((pub_r001150_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001150_10_1) & 127;
  int stage_v_151_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001150_10_2) & 127;
  if (stage_v_151_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001150_9_1) & 127;
  int stage_v_152_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001150_9_2) & 127;
  if (stage_v_152_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001150_6_1) & 127;
  int stage_v_153_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001150_6_2) & 127;
  if (stage_v_153_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((pub_r001150_3_1 * 2) + 22) & 63;
  int stage_v_154_2 = ((pub_r001150_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001150_10_1) & 127;
  int stage_v_155_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001150_10_2) & 127;
  if (stage_v_155_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001150_2_1) & 127;
  int stage_v_156_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001150_2_2) & 127;
  if (stage_v_156_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001150_14_1) & 127;
  int stage_v_157_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001150_14_2) & 127;
  if (stage_v_157_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((sec_r001150_22_1 ^ 0x2A) * 2) + pub_r001150_4_1) & 127;
  int stage_v_158_2 = (((sec_r001150_22_2 ^ 0x2A) * 2) + pub_r001150_4_2) & 127;
  if (stage_v_158_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_115_1 ^ 0x2A) * 2) + pub_r001150_16_1) & 127;
  int stage_v_159_2 = (((stage_v_115_2 ^ 0x2A) * 2) + pub_r001150_16_2) & 127;
  if (stage_v_159_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((pub_r001150_6_1 * 2) + 32) & 63;
  int stage_v_160_2 = ((pub_r001150_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_159_1 ^ 0x2A) * 2) + pub_r001150_19_1) & 127;
  int stage_v_161_2 = (((stage_v_159_2 ^ 0x2A) * 2) + pub_r001150_19_2) & 127;
  if (stage_v_161_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001150_8_1) & 127;
  int stage_v_162_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001150_8_2) & 127;
  if (stage_v_162_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((pub_r001150_3_1 * 2) + 34) & 63;
  int stage_v_163_2 = ((pub_r001150_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001150_4_1) & 127;
  int stage_v_164_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001150_4_2) & 127;
  if (stage_v_164_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((sec_r001150_7_1 ^ 0x2A) * 2) + pub_r001150_18_1) & 127;
  int stage_v_165_2 = (((sec_r001150_7_2 ^ 0x2A) * 2) + pub_r001150_18_2) & 127;
  if (stage_v_165_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001150_1_1) & 127;
  int stage_v_166_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001150_1_2) & 127;
  if (stage_v_166_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001150_10_1) & 127;
  int stage_v_167_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001150_10_2) & 127;
  if (stage_v_167_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_80_1 ^ 0x2A) * 2) + pub_r001150_9_1) & 127;
  int stage_v_168_2 = (((stage_v_80_2 ^ 0x2A) * 2) + pub_r001150_9_2) & 127;
  if (stage_v_168_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((stage_v_138_1 ^ 0x2A) * 2) + pub_r001150_15_1) & 127;
  int stage_v_169_2 = (((stage_v_138_2 ^ 0x2A) * 2) + pub_r001150_15_2) & 127;
  if (stage_v_169_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001150_9_1) & 127;
  int stage_v_170_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001150_9_2) & 127;
  if (stage_v_170_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((pub_r001150_4_1 * 2) + 41) & 63;
  int stage_v_171_2 = ((pub_r001150_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001150_10_1) & 127;
  int stage_v_172_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001150_10_2) & 127;
  if (stage_v_172_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001150_17_1) & 127;
  int stage_v_173_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001150_17_2) & 127;
  if (stage_v_173_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001150_10_1) & 127;
  int stage_v_174_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001150_10_2) & 127;
  if (stage_v_174_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((pub_r001150_15_1 * 2) + 30) & 63;
  int stage_v_175_2 = ((pub_r001150_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_174_1 ^ 0x2A) * 2) + pub_r001150_1_1) & 127;
  int stage_v_176_2 = (((stage_v_174_2 ^ 0x2A) * 2) + pub_r001150_1_2) & 127;
  if (stage_v_176_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001150_17_1) & 127;
  int stage_v_177_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001150_17_2) & 127;
  if (stage_v_177_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((pub_r001150_9_1 * 2) + 27) & 63;
  int stage_v_178_2 = ((pub_r001150_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (((sec_r001150_15_1 ^ 0x2A) * 2) + pub_r001150_5_1) & 127;
  int stage_v_179_2 = (((sec_r001150_15_2 ^ 0x2A) * 2) + pub_r001150_5_2) & 127;
  if (stage_v_179_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001150_7_1) & 127;
  int stage_v_180_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001150_7_2) & 127;
  if (stage_v_180_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_139_1 ^ 0x2A) * 2) + pub_r001150_18_1) & 127;
  int stage_v_181_2 = (((stage_v_139_2 ^ 0x2A) * 2) + pub_r001150_18_2) & 127;
  if (stage_v_181_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((pub_r001150_4_1 * 2) + 48) & 63;
  int stage_v_182_2 = ((pub_r001150_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001150_6_1) & 127;
  int stage_v_183_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001150_6_2) & 127;
  if (stage_v_183_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = (((stage_v_147_1 ^ 0x2A) * 2) + pub_r001150_6_1) & 127;
  int stage_v_184_2 = (((stage_v_147_2 ^ 0x2A) * 2) + pub_r001150_6_2) & 127;
  if (stage_v_184_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001150_3_1) & 127;
  int stage_v_185_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001150_3_2) & 127;
  if (stage_v_185_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((sec_r001150_2_1 ^ 0x2A) * 2) + pub_r001150_5_1) & 127;
  int stage_v_186_2 = (((sec_r001150_2_2 ^ 0x2A) * 2) + pub_r001150_5_2) & 127;
  if (stage_v_186_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((stage_v_112_1 ^ 0x2A) * 2) + pub_r001150_5_1) & 127;
  int stage_v_187_2 = (((stage_v_112_2 ^ 0x2A) * 2) + pub_r001150_5_2) & 127;
  if (stage_v_187_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((pub_r001150_13_1 * 2) + 31) & 63;
  int stage_v_188_2 = ((pub_r001150_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001150_16_1) & 127;
  int stage_v_189_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001150_16_2) & 127;
  if (stage_v_189_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((pub_r001150_6_1 * 2) + 35) & 63;
  int stage_v_190_2 = ((pub_r001150_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_147_1 ^ 0x2A) * 2) + pub_r001150_8_1) & 127;
  int stage_v_191_2 = (((stage_v_147_2 ^ 0x2A) * 2) + pub_r001150_8_2) & 127;
  if (stage_v_191_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((sec_r001150_0_1 ^ 0x2A) * 2) + pub_r001150_14_1) & 127;
  int stage_v_192_2 = (((sec_r001150_0_2 ^ 0x2A) * 2) + pub_r001150_14_2) & 127;
  if (stage_v_192_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001150_2_1) & 127;
  int stage_v_193_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001150_2_2) & 127;
  if (stage_v_193_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_174_1 ^ 0x2A) * 2) + pub_r001150_6_1) & 127;
  int stage_v_194_2 = (((stage_v_174_2 ^ 0x2A) * 2) + pub_r001150_6_2) & 127;
  if (stage_v_194_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((pub_r001150_20_1 * 2) + 31) & 63;
  int stage_v_195_2 = ((pub_r001150_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001150_3_1) & 127;
  int stage_v_196_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001150_3_2) & 127;
  if (stage_v_196_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((pub_r001150_7_1 * 2) + 38) & 63;
  int stage_v_197_2 = ((pub_r001150_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((sec_r001150_10_1 ^ 0x2A) * 2) + pub_r001150_10_1) & 127;
  int stage_v_198_2 = (((sec_r001150_10_2 ^ 0x2A) * 2) + pub_r001150_10_2) & 127;
  if (stage_v_198_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001150_17_1) & 127;
  int stage_v_199_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001150_17_2) & 127;
  if (stage_v_199_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001150_20_1) & 127;
  int stage_v_200_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001150_20_2) & 127;
  if (stage_v_200_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((pub_r001150_18_1 * 2) + 15) & 63;
  int stage_v_201_2 = ((pub_r001150_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001150_6_1 * 2) + 32) & 63;
  int stage_v_202_2 = ((pub_r001150_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001150_19_1 * 2) + 37) & 63;
  int stage_v_203_2 = ((pub_r001150_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((sec_r001150_7_1 ^ 0x2A) * 2) + pub_r001150_14_1) & 127;
  int stage_v_204_2 = (((sec_r001150_7_2 ^ 0x2A) * 2) + pub_r001150_14_2) & 127;
  if (stage_v_204_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001150_0_1 == pub_r001150_0_2);
  __CPROVER_assume(sec_r001150_12_1 != sec_r001150_12_2);
  __CPROVER_assume(pub_r001150_12_1 == pub_r001150_12_2);
  __CPROVER_assume(sec_r001150_16_1 != sec_r001150_16_2);
  __CPROVER_assume(pub_r001150_10_1 == pub_r001150_10_2);
  __CPROVER_assume(sec_r001150_13_1 != sec_r001150_13_2);
  __CPROVER_assume(pub_r001150_11_1 == pub_r001150_11_2);
  __CPROVER_assume(sec_r001150_9_1 != sec_r001150_9_2);
  __CPROVER_assume(pub_r001150_15_1 == pub_r001150_15_2);
  __CPROVER_assume(sec_r001150_5_1 != sec_r001150_5_2);
  __CPROVER_assume(pub_r001150_2_1 == pub_r001150_2_2);
  __CPROVER_assume(pub_r001150_13_1 == pub_r001150_13_2);
  __CPROVER_assume(pub_r001150_17_1 == pub_r001150_17_2);
  __CPROVER_assume(sec_r001150_14_1 != sec_r001150_14_2);
  __CPROVER_assume(pub_r001150_14_1 == pub_r001150_14_2);
  __CPROVER_assume(pub_r001150_19_1 == pub_r001150_19_2);
  __CPROVER_assume(pub_r001150_3_1 == pub_r001150_3_2);
  __CPROVER_assume(sec_r001150_21_1 != sec_r001150_21_2);
  __CPROVER_assume(sec_r001150_18_1 != sec_r001150_18_2);
  __CPROVER_assume(pub_r001150_18_1 == pub_r001150_18_2);
  __CPROVER_assume(pub_r001150_4_1 == pub_r001150_4_2);
  __CPROVER_assume(pub_r001150_9_1 == pub_r001150_9_2);
  __CPROVER_assume(sec_r001150_8_1 != sec_r001150_8_2);
  __CPROVER_assume(sec_r001150_0_1 != sec_r001150_0_2);
  __CPROVER_assume(pub_r001150_16_1 == pub_r001150_16_2);
  __CPROVER_assume(sec_r001150_2_1 != sec_r001150_2_2);
  __CPROVER_assume(pub_r001150_5_1 == pub_r001150_5_2);
  __CPROVER_assume(sec_r001150_17_1 != sec_r001150_17_2);
  __CPROVER_assume(sec_r001150_11_1 != sec_r001150_11_2);
  __CPROVER_assume(pub_r001150_7_1 == pub_r001150_7_2);
  __CPROVER_assume(sec_r001150_1_1 != sec_r001150_1_2);
  __CPROVER_assume(pub_r001150_6_1 == pub_r001150_6_2);
  __CPROVER_assume(sec_r001150_22_1 != sec_r001150_22_2);
  __CPROVER_assume(sec_r001150_7_1 != sec_r001150_7_2);
  __CPROVER_assume(sec_r001150_15_1 != sec_r001150_15_2);
  __CPROVER_assume(pub_r001150_8_1 == pub_r001150_8_2);
  __CPROVER_assume(sec_r001150_3_1 != sec_r001150_3_2);
  __CPROVER_assume(sec_r001150_19_1 != sec_r001150_19_2);
  __CPROVER_assume(sec_r001150_10_1 != sec_r001150_10_2);
  __CPROVER_assume(sec_r001150_4_1 != sec_r001150_4_2);
  __CPROVER_assume(pub_r001150_20_1 == pub_r001150_20_2);
  __CPROVER_assume(pub_r001150_1_1 == pub_r001150_1_2);
  __CPROVER_assume(sec_r001150_6_1 != sec_r001150_6_2);
  __CPROVER_assume(sec_r001150_20_1 != sec_r001150_20_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.peak == st_var_1_2.peak);
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
}


