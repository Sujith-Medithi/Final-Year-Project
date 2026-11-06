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
struct DeviceConfig_R000457_5713_0
{
  unsigned char id;
  int port;
  int baud_rate;
  int buffer[3];
};
struct MatrixBlock_R000457_5713_1
{
  int scale;
  int dim;
  short determinant;
  short trace;
  int density;
  int buffer[3];
};
union ColorPixel_R000457_5713_0
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
void fn_R000457_5713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st_1 = {0};
  struct MatrixBlock_R000457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int damping_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_65_1)
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

  switch (damping_65_2)
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
  int sample_51_1 = local_arr_1[aux_1 % 3];
  int sample_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_51_2 * 2)) & 127;
  int factor_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_91_1 > 36)
  {
    acc_1 = ((acc_1 + (factor_91_1 * 2)) + 5) & 127;
    aux_1 ^= factor_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_91_2 > 36)
  {
    acc_2 = ((acc_2 + (factor_91_2 * 2)) + 5) & 127;
    aux_2 ^= factor_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_86_1) & 63;
  aux_2 = (aux_2 + tracker_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_65_1 == damping_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_51_1 == sample_51_2);
  assert(factor_91_1 == factor_91_2);
  assert(tracker_86_1 == tracker_86_2);
}

int fn_R000457_5713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int damping_65 = (aux + st.buffer[1]) & 3;
  switch (damping_65)
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
  int sample_51 = local_arr[aux % 3];
  acc = (acc + (sample_51 * 2)) & 127;
  int factor_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_91 > 36)
  {
    acc = ((acc + (factor_91 * 2)) + 5) & 127;
    aux ^= factor_91 & 15;
  }
  else
  {
    acc = ((acc - factor_91) + 11) & 127;
    aux += 3;
  }
  int tracker_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000457_5713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st_1 = {0};
  struct MatrixBlock_R000457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_82_1 = local_arr_1[aux_1 % 3];
  int margin_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_82_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_82_1 == margin_82_2);
}

int fn_R000457_5713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int margin_82 = local_arr[aux % 3];
  acc = (acc + (margin_82 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000457_5713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st_1 = {0};
  struct MatrixBlock_R000457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int offset_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_42_1)
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

  switch (offset_42_2)
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
  int bound_84_1 = local_arr_1[aux_1 % 3];
  int bound_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_84_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_62_1) & 63;
  aux_2 = (aux_2 + scale_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_42_1 == offset_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_84_1 == bound_84_2);
  assert(scale_62_1 == scale_62_2);
}

int fn_R000457_5713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int offset_42 = (aux + st.buffer[1]) & 3;
  switch (offset_42)
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
  int bound_84 = local_arr[aux % 3];
  acc = (acc + (bound_84 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000457_5713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int threshold_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_78_1) & 63;
  aux_2 = (aux_2 + threshold_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_90_1)
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

  switch (coefficient_90_2)
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
  int scale_17_1 = local_arr_1[aux_1 % 3];
  int scale_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_17_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_78_1 == threshold_78_2);
  assert(coefficient_90_1 == coefficient_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_17_1 == scale_17_2);
}

int fn_R000457_5713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int threshold_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_78) & 63;
  acc ^= aux;
  int coefficient_90 = (aux + st.buffer[1]) & 3;
  switch (coefficient_90)
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
  int scale_17 = local_arr[aux % 3];
  acc = (acc + (scale_17 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000457_5713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_28_1 = local_arr_1[aux_1 % 3];
  int weight_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_28_2 * 2)) & 127;
  int tracker_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_10_1) & 63;
  aux_2 = (aux_2 + tracker_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_40_1 > 41)
  {
    acc_1 = ((acc_1 + (phase_40_1 * 2)) + 5) & 127;
    aux_1 ^= phase_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_40_2 > 41)
  {
    acc_2 = ((acc_2 + (phase_40_2 * 2)) + 5) & 127;
    aux_2 ^= phase_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_28_1 == weight_28_2);
  assert(tracker_10_1 == tracker_10_2);
  assert(phase_40_1 == phase_40_2);
}

int fn_R000457_5713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int weight_28 = local_arr[aux % 3];
  acc = (acc + (weight_28 * 2)) & 127;
  int tracker_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_10) & 63;
  acc ^= aux;
  int phase_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_40 > 41)
  {
    acc = ((acc + (phase_40 * 2)) + 5) & 127;
    aux ^= phase_40 & 15;
  }
  else
  {
    acc = ((acc - phase_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000457_5713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st_1 = {0};
  struct MatrixBlock_R000457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_50_1 = local_arr_1[aux_1 % 3];
  int metric_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_50_2 * 2)) & 127;
  int offset_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_33_1 > 33)
  {
    acc_1 = ((acc_1 + (offset_33_1 * 2)) + 5) & 127;
    aux_1 ^= offset_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_33_2 > 33)
  {
    acc_2 = ((acc_2 + (offset_33_2 * 2)) + 5) & 127;
    aux_2 ^= offset_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_50_1 == metric_50_2);
  assert(offset_33_1 == offset_33_2);
}

int fn_R000457_5713_5(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int metric_50 = local_arr[aux % 3];
  acc = (acc + (metric_50 * 2)) & 127;
  int offset_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_33 > 33)
  {
    acc = ((acc + (offset_33 * 2)) + 5) & 127;
    aux ^= offset_33 & 15;
  }
  else
  {
    acc = ((acc - offset_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000457_5713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int index_reg_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_34_1)
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

  switch (index_reg_34_2)
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

  int quotient_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_32_1) & 63;
  aux_2 = (aux_2 + quotient_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_34_1 == index_reg_34_2);
  assert(quotient_32_1 == quotient_32_2);
}

int fn_R000457_5713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int index_reg_34 = (aux + st.buffer[1]) & 3;
  switch (index_reg_34)
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

  int quotient_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_32) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000457_5713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_65_1 = local_arr_1[aux_1 % 3];
  int parity_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_65_2 * 2)) & 127;
  int parity_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_58_1) & 63;
  aux_2 = (aux_2 + parity_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_65_1 == parity_65_2);
  assert(parity_58_1 == parity_58_2);
}

int fn_R000457_5713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_65 = local_arr[aux % 3];
  acc = (acc + (parity_65 * 2)) & 127;
  int parity_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000457_5713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int quotient_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_55_1 > 15)
  {
    acc_1 = ((acc_1 + (quotient_55_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_55_2 > 15)
  {
    acc_2 = ((acc_2 + (quotient_55_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_84_1)
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

  switch (stride_84_2)
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
  int tracker_96_1 = local_arr_1[aux_1 % 3];
  int tracker_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_96_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_55_1 == quotient_55_2);
  assert(stride_84_1 == stride_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_96_1 == tracker_96_2);
}

int fn_R000457_5713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int quotient_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_55 > 15)
  {
    acc = ((acc + (quotient_55 * 2)) + 5) & 127;
    aux ^= quotient_55 & 15;
  }
  else
  {
    acc = ((acc - quotient_55) + 11) & 127;
    aux += 3;
  }
  int stride_84 = (aux + st.buffer[1]) & 3;
  switch (stride_84)
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
  int tracker_96 = local_arr[aux % 3];
  acc = (acc + (tracker_96 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000457_5713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_40_1 = local_arr_1[aux_1 % 3];
  int parity_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_40_2 * 2)) & 127;
  int checksum_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_41_1 > 13)
  {
    acc_1 = ((acc_1 + (checksum_41_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_41_2 > 13)
  {
    acc_2 = ((acc_2 + (checksum_41_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_41_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_40_1 == parity_40_2);
  assert(checksum_41_1 == checksum_41_2);
}

int fn_R000457_5713_9(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int parity_40 = local_arr[aux % 3];
  acc = (acc + (parity_40 * 2)) & 127;
  int checksum_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_41 > 13)
  {
    acc = ((acc + (checksum_41 * 2)) + 5) & 127;
    aux ^= checksum_41 & 15;
  }
  else
  {
    acc = ((acc - checksum_41) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000457_5713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int cursor_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_42_1 > 38)
  {
    acc_1 = ((acc_1 + (cursor_42_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_42_2 > 38)
  {
    acc_2 = ((acc_2 + (cursor_42_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_54_1)
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

  switch (segment_54_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_42_1 == cursor_42_2);
  assert(segment_54_1 == segment_54_2);
}

int fn_R000457_5713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int cursor_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_42 > 38)
  {
    acc = ((acc + (cursor_42 * 2)) + 5) & 127;
    aux ^= cursor_42 & 15;
  }
  else
  {
    acc = ((acc - cursor_42) + 11) & 127;
    aux += 3;
  }
  int segment_54 = (aux + st.buffer[1]) & 3;
  switch (segment_54)
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

void fn_R000457_5713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st_1 = {0};
  struct MatrixBlock_R000457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_76_1 = local_arr_1[aux_1 % 3];
  int quotient_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_76_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_76_1 == quotient_76_2);
}

int fn_R000457_5713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int quotient_76 = local_arr[aux % 3];
  acc = (acc + (quotient_76 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000457_5713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st_1 = {0};
  struct MatrixBlock_R000457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int pivot_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_45_1) & 63;
  aux_2 = (aux_2 + pivot_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_45_1 == pivot_45_2);
}

int fn_R000457_5713_12(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int pivot_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_45) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000457_5713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st_1 = {0};
  struct MatrixBlock_R000457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_77_1 = local_arr_1[aux_1 % 3];
  int tally_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_77_2 * 2)) & 127;
  int delta_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_53_1) & 63;
  aux_2 = (aux_2 + delta_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_77_1 == tally_77_2);
  assert(delta_53_1 == delta_53_2);
}

int fn_R000457_5713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int tally_77 = local_arr[aux % 3];
  acc = (acc + (tally_77 * 2)) & 127;
  int delta_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_53) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000457_5713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st_1 = {0};
  struct MatrixBlock_R000457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_57_1 = local_arr_1[aux_1 % 3];
  int phase_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_57_2 * 2)) & 127;
  int accumulator_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_93_1) & 63;
  aux_2 = (aux_2 + accumulator_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_58_1)
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

  switch (parity_58_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_57_1 == phase_57_2);
  assert(accumulator_93_1 == accumulator_93_2);
  assert(parity_58_1 == parity_58_2);
}

int fn_R000457_5713_14(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int phase_57 = local_arr[aux % 3];
  acc = (acc + (phase_57 * 2)) & 127;
  int accumulator_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_93) & 63;
  acc ^= aux;
  int parity_58 = (aux + st.buffer[1]) & 3;
  switch (parity_58)
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

void fn_R000457_5713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_33_1 = local_arr_1[aux_1 % 3];
  int vector_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_33_2 * 2)) & 127;
  int parity_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_13_1 > 41)
  {
    acc_1 = ((acc_1 + (parity_13_1 * 2)) + 5) & 127;
    aux_1 ^= parity_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_13_2 > 41)
  {
    acc_2 = ((acc_2 + (parity_13_2 * 2)) + 5) & 127;
    aux_2 ^= parity_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_13_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_33_1 == vector_33_2);
  assert(parity_13_1 == parity_13_2);
}

int fn_R000457_5713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int vector_33 = local_arr[aux % 3];
  acc = (acc + (vector_33 * 2)) & 127;
  int parity_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_13 > 41)
  {
    acc = ((acc + (parity_13 * 2)) + 5) & 127;
    aux ^= parity_13 & 15;
  }
  else
  {
    acc = ((acc - parity_13) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000457_5713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_54_1 > 26)
  {
    acc_1 = ((acc_1 + (offset_54_1 * 2)) + 5) & 127;
    aux_1 ^= offset_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_54_2 > 26)
  {
    acc_2 = ((acc_2 + (offset_54_2 * 2)) + 5) & 127;
    aux_2 ^= offset_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_32_1 = local_arr_1[aux_1 % 3];
  int checksum_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_32_2 * 2)) & 127;
  int segment_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_62_1)
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

  switch (segment_62_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_54_1 == offset_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_32_1 == checksum_32_2);
  assert(segment_62_1 == segment_62_2);
}

int fn_R000457_5713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_54 > 26)
  {
    acc = ((acc + (offset_54 * 2)) + 5) & 127;
    aux ^= offset_54 & 15;
  }
  else
  {
    acc = ((acc - offset_54) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_32 = local_arr[aux % 3];
  acc = (acc + (checksum_32 * 2)) & 127;
  int segment_62 = (aux + st.buffer[1]) & 3;
  switch (segment_62)
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

void fn_R000457_5713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int checksum_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_40_1)
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

  switch (checksum_40_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_78_1 = local_arr_1[aux_1 % 3];
  int scale_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_78_2 * 2)) & 127;
  int stride_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_23_1) & 63;
  aux_2 = (aux_2 + stride_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_40_1 == checksum_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_78_1 == scale_78_2);
  assert(stride_23_1 == stride_23_2);
}

int fn_R000457_5713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int checksum_40 = (aux + st.buffer[1]) & 3;
  switch (checksum_40)
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
  int local_arr[3] = {4, 9, 15};
  int scale_78 = local_arr[aux % 3];
  acc = (acc + (scale_78 * 2)) & 127;
  int stride_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_23) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000457_5713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st_1 = {0};
  struct MatrixBlock_R000457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int anchor_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_57_1 > 30)
  {
    acc_1 = ((acc_1 + (anchor_57_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_57_2 > 30)
  {
    acc_2 = ((acc_2 + (anchor_57_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_57_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_92_1 = local_arr_1[aux_1 % 3];
  int mask_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_92_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_57_1 == anchor_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_92_1 == mask_92_2);
}

int fn_R000457_5713_18(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int anchor_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_57 > 30)
  {
    acc = ((acc + (anchor_57 * 2)) + 5) & 127;
    aux ^= anchor_57 & 15;
  }
  else
  {
    acc = ((acc - anchor_57) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_92 = local_arr[aux % 3];
  acc = (acc + (mask_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000457_5713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st_1 = {0};
  struct MatrixBlock_R000457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_48_1 = local_arr_1[aux_1 % 3];
  int offset_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_48_2 * 2)) & 127;
  int phase_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_84_1 > 41)
  {
    acc_1 = ((acc_1 + (phase_84_1 * 2)) + 5) & 127;
    aux_1 ^= phase_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_84_2 > 41)
  {
    acc_2 = ((acc_2 + (phase_84_2 * 2)) + 5) & 127;
    aux_2 ^= phase_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_30_1) & 63;
  aux_2 = (aux_2 + cursor_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_48_1 == offset_48_2);
  assert(phase_84_1 == phase_84_2);
  assert(cursor_30_1 == cursor_30_2);
}

int fn_R000457_5713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_48 = local_arr[aux % 3];
  acc = (acc + (offset_48 * 2)) & 127;
  int phase_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_84 > 41)
  {
    acc = ((acc + (phase_84 * 2)) + 5) & 127;
    aux ^= phase_84 & 15;
  }
  else
  {
    acc = ((acc - phase_84) + 11) & 127;
    aux += 3;
  }
  int cursor_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000457_5713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_81_1) & 63;
  aux_2 = (aux_2 + tally_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_81_1 == tally_81_2);
}

int fn_R000457_5713_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000457_5713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_58_1 = local_arr_1[aux_1 % 3];
  int scale_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_58_2 * 2)) & 127;
  int scale_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_26_1 > 22)
  {
    acc_1 = ((acc_1 + (scale_26_1 * 2)) + 5) & 127;
    aux_1 ^= scale_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_26_2 > 22)
  {
    acc_2 = ((acc_2 + (scale_26_2 * 2)) + 5) & 127;
    aux_2 ^= scale_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_26_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_58_1 == scale_58_2);
  assert(scale_26_1 == scale_26_2);
}

int fn_R000457_5713_21(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int scale_58 = local_arr[aux % 3];
  acc = (acc + (scale_58 * 2)) & 127;
  int scale_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_26 > 22)
  {
    acc = ((acc + (scale_26 * 2)) + 5) & 127;
    aux ^= scale_26 & 15;
  }
  else
  {
    acc = ((acc - scale_26) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000457_5713_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_46_1 = local_arr_1[aux_1 % 3];
  int phase_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_46_2 * 2)) & 127;
  int cursor_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_76_1 > 44)
  {
    acc_1 = ((acc_1 + (cursor_76_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_76_2 > 44)
  {
    acc_2 = ((acc_2 + (cursor_76_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_76_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_46_1 == phase_46_2);
  assert(cursor_76_1 == cursor_76_2);
}

int fn_R000457_5713_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int phase_46 = local_arr[aux % 3];
  acc = (acc + (phase_46 * 2)) & 127;
  int cursor_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_76 > 44)
  {
    acc = ((acc + (cursor_76 * 2)) + 5) & 127;
    aux ^= cursor_76 & 15;
  }
  else
  {
    acc = ((acc - cursor_76) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000457_0_1;
  int sec_r000457_0_2;
  int sec_r000457_1_1;
  int sec_r000457_1_2;
  int sec_r000457_2_1;
  int sec_r000457_2_2;
  int sec_r000457_3_1;
  int sec_r000457_3_2;
  int sec_r000457_4_1;
  int sec_r000457_4_2;
  int sec_r000457_5_1;
  int sec_r000457_5_2;
  int sec_r000457_6_1;
  int sec_r000457_6_2;
  int sec_r000457_7_1;
  int sec_r000457_7_2;
  int sec_r000457_8_1;
  int sec_r000457_8_2;
  int sec_r000457_9_1;
  int sec_r000457_9_2;
  int sec_r000457_10_1;
  int sec_r000457_10_2;
  int sec_r000457_11_1;
  int sec_r000457_11_2;
  int sec_r000457_12_1;
  int sec_r000457_12_2;
  int sec_r000457_13_1;
  int sec_r000457_13_2;
  int sec_r000457_14_1;
  int sec_r000457_14_2;
  int sec_r000457_15_1;
  int sec_r000457_15_2;
  int sec_r000457_16_1;
  int sec_r000457_16_2;
  int sec_r000457_17_1;
  int sec_r000457_17_2;
  int sec_r000457_18_1;
  int sec_r000457_18_2;
  int pub_r000457_0_1;
  int pub_r000457_0_2;
  int pub_r000457_1_1;
  int pub_r000457_1_2;
  int pub_r000457_2_1;
  int pub_r000457_2_2;
  int pub_r000457_3_1;
  int pub_r000457_3_2;
  int pub_r000457_4_1;
  int pub_r000457_4_2;
  int pub_r000457_5_1;
  int pub_r000457_5_2;
  int pub_r000457_6_1;
  int pub_r000457_6_2;
  int pub_r000457_7_1;
  int pub_r000457_7_2;
  int pub_r000457_8_1;
  int pub_r000457_8_2;
  int pub_r000457_9_1;
  int pub_r000457_9_2;
  int pub_r000457_10_1;
  int pub_r000457_10_2;
  int pub_r000457_11_1;
  int pub_r000457_11_2;
  int pub_r000457_12_1;
  int pub_r000457_12_2;
  int pub_r000457_13_1;
  int pub_r000457_13_2;
  int pub_r000457_14_1;
  int pub_r000457_14_2;
  int pub_r000457_15_1;
  int pub_r000457_15_2;
  int pub_r000457_16_1;
  int pub_r000457_16_2;
  int pub_r000457_17_1;
  int pub_r000457_17_2;
  int pub_r000457_18_1;
  int pub_r000457_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000457_0_1 >= (-100)) && (pub_r000457_0_1 <= 100));
  __CPROVER_assume((pub_r000457_0_2 >= (-100)) && (pub_r000457_0_2 <= 100));
  __CPROVER_assume((pub_r000457_1_1 >= (-100)) && (pub_r000457_1_1 <= 100));
  __CPROVER_assume((pub_r000457_1_2 >= (-100)) && (pub_r000457_1_2 <= 100));
  __CPROVER_assume((pub_r000457_2_1 >= (-100)) && (pub_r000457_2_1 <= 100));
  __CPROVER_assume((pub_r000457_2_2 >= (-100)) && (pub_r000457_2_2 <= 100));
  __CPROVER_assume((pub_r000457_3_1 >= (-100)) && (pub_r000457_3_1 <= 100));
  __CPROVER_assume((pub_r000457_3_2 >= (-100)) && (pub_r000457_3_2 <= 100));
  __CPROVER_assume((pub_r000457_4_1 >= (-100)) && (pub_r000457_4_1 <= 100));
  __CPROVER_assume((pub_r000457_4_2 >= (-100)) && (pub_r000457_4_2 <= 100));
  __CPROVER_assume((pub_r000457_5_1 >= (-100)) && (pub_r000457_5_1 <= 100));
  __CPROVER_assume((pub_r000457_5_2 >= (-100)) && (pub_r000457_5_2 <= 100));
  __CPROVER_assume((pub_r000457_6_1 >= (-100)) && (pub_r000457_6_1 <= 100));
  __CPROVER_assume((pub_r000457_6_2 >= (-100)) && (pub_r000457_6_2 <= 100));
  __CPROVER_assume((pub_r000457_7_1 >= (-100)) && (pub_r000457_7_1 <= 100));
  __CPROVER_assume((pub_r000457_7_2 >= (-100)) && (pub_r000457_7_2 <= 100));
  __CPROVER_assume((pub_r000457_8_1 >= (-100)) && (pub_r000457_8_1 <= 100));
  __CPROVER_assume((pub_r000457_8_2 >= (-100)) && (pub_r000457_8_2 <= 100));
  __CPROVER_assume((pub_r000457_9_1 >= (-100)) && (pub_r000457_9_1 <= 100));
  __CPROVER_assume((pub_r000457_9_2 >= (-100)) && (pub_r000457_9_2 <= 100));
  __CPROVER_assume((pub_r000457_10_1 >= (-100)) && (pub_r000457_10_1 <= 100));
  __CPROVER_assume((pub_r000457_10_2 >= (-100)) && (pub_r000457_10_2 <= 100));
  __CPROVER_assume((pub_r000457_11_1 >= (-100)) && (pub_r000457_11_1 <= 100));
  __CPROVER_assume((pub_r000457_11_2 >= (-100)) && (pub_r000457_11_2 <= 100));
  __CPROVER_assume((pub_r000457_12_1 >= (-100)) && (pub_r000457_12_1 <= 100));
  __CPROVER_assume((pub_r000457_12_2 >= (-100)) && (pub_r000457_12_2 <= 100));
  __CPROVER_assume((pub_r000457_13_1 >= (-100)) && (pub_r000457_13_1 <= 100));
  __CPROVER_assume((pub_r000457_13_2 >= (-100)) && (pub_r000457_13_2 <= 100));
  __CPROVER_assume((pub_r000457_14_1 >= (-100)) && (pub_r000457_14_1 <= 100));
  __CPROVER_assume((pub_r000457_14_2 >= (-100)) && (pub_r000457_14_2 <= 100));
  __CPROVER_assume((pub_r000457_15_1 >= (-100)) && (pub_r000457_15_1 <= 100));
  __CPROVER_assume((pub_r000457_15_2 >= (-100)) && (pub_r000457_15_2 <= 100));
  __CPROVER_assume((pub_r000457_16_1 >= (-100)) && (pub_r000457_16_1 <= 100));
  __CPROVER_assume((pub_r000457_16_2 >= (-100)) && (pub_r000457_16_2 <= 100));
  __CPROVER_assume((pub_r000457_17_1 >= (-100)) && (pub_r000457_17_1 <= 100));
  __CPROVER_assume((pub_r000457_17_2 >= (-100)) && (pub_r000457_17_2 <= 100));
  __CPROVER_assume((pub_r000457_18_1 >= (-100)) && (pub_r000457_18_1 <= 100));
  __CPROVER_assume((pub_r000457_18_2 >= (-100)) && (pub_r000457_18_2 <= 100));
  __CPROVER_assume((sec_r000457_0_1 >= 0) && (sec_r000457_0_1 <= 255));
  __CPROVER_assume((sec_r000457_0_2 >= 0) && (sec_r000457_0_2 <= 255));
  __CPROVER_assume((sec_r000457_1_1 >= 0) && (sec_r000457_1_1 <= 255));
  __CPROVER_assume((sec_r000457_1_2 >= 0) && (sec_r000457_1_2 <= 255));
  __CPROVER_assume((sec_r000457_2_1 >= 0) && (sec_r000457_2_1 <= 255));
  __CPROVER_assume((sec_r000457_2_2 >= 0) && (sec_r000457_2_2 <= 255));
  __CPROVER_assume((sec_r000457_3_1 >= 0) && (sec_r000457_3_1 <= 255));
  __CPROVER_assume((sec_r000457_3_2 >= 0) && (sec_r000457_3_2 <= 255));
  __CPROVER_assume((sec_r000457_4_1 >= 0) && (sec_r000457_4_1 <= 255));
  __CPROVER_assume((sec_r000457_4_2 >= 0) && (sec_r000457_4_2 <= 255));
  __CPROVER_assume((sec_r000457_5_1 >= 0) && (sec_r000457_5_1 <= 255));
  __CPROVER_assume((sec_r000457_5_2 >= 0) && (sec_r000457_5_2 <= 255));
  __CPROVER_assume((sec_r000457_6_1 >= 0) && (sec_r000457_6_1 <= 255));
  __CPROVER_assume((sec_r000457_6_2 >= 0) && (sec_r000457_6_2 <= 255));
  __CPROVER_assume((sec_r000457_7_1 >= 0) && (sec_r000457_7_1 <= 255));
  __CPROVER_assume((sec_r000457_7_2 >= 0) && (sec_r000457_7_2 <= 255));
  __CPROVER_assume((sec_r000457_8_1 >= 0) && (sec_r000457_8_1 <= 255));
  __CPROVER_assume((sec_r000457_8_2 >= 0) && (sec_r000457_8_2 <= 255));
  __CPROVER_assume((sec_r000457_9_1 >= 0) && (sec_r000457_9_1 <= 255));
  __CPROVER_assume((sec_r000457_9_2 >= 0) && (sec_r000457_9_2 <= 255));
  __CPROVER_assume((sec_r000457_10_1 >= 0) && (sec_r000457_10_1 <= 255));
  __CPROVER_assume((sec_r000457_10_2 >= 0) && (sec_r000457_10_2 <= 255));
  __CPROVER_assume((sec_r000457_11_1 >= 0) && (sec_r000457_11_1 <= 255));
  __CPROVER_assume((sec_r000457_11_2 >= 0) && (sec_r000457_11_2 <= 255));
  __CPROVER_assume((sec_r000457_12_1 >= 0) && (sec_r000457_12_1 <= 255));
  __CPROVER_assume((sec_r000457_12_2 >= 0) && (sec_r000457_12_2 <= 255));
  __CPROVER_assume((sec_r000457_13_1 >= 0) && (sec_r000457_13_1 <= 255));
  __CPROVER_assume((sec_r000457_13_2 >= 0) && (sec_r000457_13_2 <= 255));
  __CPROVER_assume((sec_r000457_14_1 >= 0) && (sec_r000457_14_1 <= 255));
  __CPROVER_assume((sec_r000457_14_2 >= 0) && (sec_r000457_14_2 <= 255));
  __CPROVER_assume((sec_r000457_15_1 >= 0) && (sec_r000457_15_1 <= 255));
  __CPROVER_assume((sec_r000457_15_2 >= 0) && (sec_r000457_15_2 <= 255));
  __CPROVER_assume((sec_r000457_16_1 >= 0) && (sec_r000457_16_1 <= 255));
  __CPROVER_assume((sec_r000457_16_2 >= 0) && (sec_r000457_16_2 <= 255));
  __CPROVER_assume((sec_r000457_17_1 >= 0) && (sec_r000457_17_1 <= 255));
  __CPROVER_assume((sec_r000457_17_2 >= 0) && (sec_r000457_17_2 <= 255));
  __CPROVER_assume((sec_r000457_18_1 >= 0) && (sec_r000457_18_1 <= 255));
  __CPROVER_assume((sec_r000457_18_2 >= 0) && (sec_r000457_18_2 <= 255));
  struct DeviceConfig_R000457_5713_0 st_var_0_1 = {0};
  struct DeviceConfig_R000457_5713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000457_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000457_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000457_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000457_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000457_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000457_0_2 + 7) & 15;
  struct MatrixBlock_R000457_5713_1 st_var_1_1 = {0};
  struct MatrixBlock_R000457_5713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000457_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000457_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000457_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000457_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000457_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000457_0_2 + 9) & 15;
  union ColorPixel_R000457_5713_0 u_var_1;
  union ColorPixel_R000457_5713_0 u_var_2;
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
  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 51)
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
  if (stage_v_4_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 51)
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
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = (st_var_0_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_0_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 52)
    {
      chk_sum_1 ^= stage_v_8_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_8_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 52)
    {
      chk_sum_2 ^= stage_v_8_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 11) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_0_2.buffer[1] * 3) & 63;
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
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 15) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  int stage_v_15_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (20 & 31);
  int stage_v_15_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (20 & 31);
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= (stage_v_15_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_15_2 << 1) & 127;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = (st_var_1_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_1_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  int stage_v_30_1 = (st_var_0_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_0_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((st_var_0_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_0_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 49)
    {
      chk_sum_1 ^= stage_v_32_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_32_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 49)
    {
      chk_sum_2 ^= stage_v_32_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_33_1 = ((st_var_1_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_1_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 30)
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
  if (stage_v_33_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 30)
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
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
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
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 42)
    {
      chk_sum_1 ^= stage_v_37_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_37_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 42)
    {
      chk_sum_2 ^= stage_v_37_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 40) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = (st_var_0_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_0_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_43_1 = table_1[3];
  int stage_v_43_2 = table_2[3];
  table_1[3] = (table_1[0] + 87) & 63;
  table_2[3] = (table_2[0] + 87) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = (st_var_1_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_1_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 27)
    {
      chk_sum_1 ^= stage_v_48_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_48_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 27)
    {
      chk_sum_2 ^= stage_v_48_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 50) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 50) & 15;
  int stage_v_49_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_49_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= stage_v_49_1;
  chk_sum_2 ^= stage_v_49_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 51) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = table_1[0];
  int stage_v_52_2 = table_2[0];
  table_1[0] = (table_1[1] + 105) & 63;
  table_2[0] = (table_2[1] + 105) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((st_var_1_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_1_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 35)
    {
      chk_sum_1 ^= stage_v_55_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_55_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 35)
    {
      chk_sum_2 ^= stage_v_55_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 59) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 59) & 15;
  int stage_v_58_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_58_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= stage_v_58_1;
  chk_sum_2 ^= stage_v_58_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 60) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 60) & 15;
  int stage_v_59_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_59_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= stage_v_59_1;
  chk_sum_2 ^= stage_v_59_2;
  int stage_v_60_1 = ((st_var_0_1.buffer[0] * 2) + 187) & 63;
  int stage_v_60_2 = ((st_var_0_2.buffer[0] * 2) + 187) & 63;
  if (stage_v_60_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_60_1) - 5) & 255;
    if (stage_v_60_1 > 47)
    {
      chk_sum_1 ^= stage_v_60_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_60_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_60_2) - 5) & 255;
    if (stage_v_60_2 > 47)
    {
      chk_sum_2 ^= stage_v_60_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_61_1 = table_1[1];
  int stage_v_61_2 = table_2[1];
  table_1[1] = (table_1[2] + 123) & 63;
  table_2[1] = (table_2[2] + 123) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_62_1 = ((stage_v_62_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_62_2 = ((stage_v_62_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = table_1[3];
  int stage_v_63_2 = table_2[3];
  table_1[3] = (table_1[0] + 127) & 63;
  table_2[3] = (table_2[0] + 127) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 67) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 67) & 15;
  int stage_v_66_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_66_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= stage_v_66_1;
  chk_sum_2 ^= stage_v_66_2;
  int stage_v_67_1 = (st_var_1_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_1_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  int stage_v_68_1 = (st_var_0_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_0_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 70) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
  int stage_v_70_1 = (st_var_0_1.buffer[0] ^ 73) & 3;
  int stage_v_70_2 = (st_var_0_2.buffer[0] ^ 73) & 3;
  switch (stage_v_70_1)
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

  switch (stage_v_70_2)
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

  int stage_v_71_1 = (st_var_1_1.buffer[0] ^ 74) & 3;
  int stage_v_71_2 = (st_var_1_2.buffer[0] ^ 74) & 3;
  switch (stage_v_71_1)
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

  switch (stage_v_71_2)
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

  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 39)
    {
      chk_sum_1 ^= stage_v_72_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_72_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 39)
    {
      chk_sum_2 ^= stage_v_72_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_73_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_73_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_74_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_74_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_75_1 = (st_var_1_1.buffer[0] ^ 78) & 3;
  int stage_v_75_2 = (st_var_1_2.buffer[0] ^ 78) & 3;
  switch (stage_v_75_1)
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

  switch (stage_v_75_2)
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

  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000457_8_1 & 1) != 0)
  {
    if ((sec_r000457_4_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000457_13_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000457_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000457_13_1 + 7) & 127;
  }
  if ((sec_r000457_8_2 & 1) != 0)
  {
    if ((sec_r000457_4_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000457_13_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000457_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000457_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000457_14_1 & 1) != 0)
  {
    if ((sec_r000457_3_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000457_14_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000457_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000457_14_1 + 7) & 127;
  }
  if ((sec_r000457_14_2 & 1) != 0)
  {
    if ((sec_r000457_3_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000457_14_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000457_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000457_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000457_7_1 & 1) != 0)
  {
    if ((sec_r000457_6_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000457_5_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000457_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000457_5_1 + 7) & 127;
  }
  if ((sec_r000457_7_2 & 1) != 0)
  {
    if ((sec_r000457_6_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000457_5_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000457_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000457_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000457_16_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000457_11_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000457_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000457_11_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000457_16_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000457_11_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000457_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000457_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000457_14_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000457_12_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000457_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000457_12_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000457_14_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000457_12_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000457_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000457_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000457_17_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000457_14_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000457_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000457_14_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000457_17_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000457_14_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000457_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000457_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000457_10_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000457_1_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000457_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000457_1_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000457_10_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000457_1_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000457_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000457_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000457_7_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000457_5_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000457_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000457_5_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000457_7_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000457_5_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000457_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000457_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000457_16_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000457_1_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000457_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000457_1_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000457_16_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000457_1_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000457_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000457_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000457_7_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000457_13_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000457_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000457_13_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000457_7_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000457_13_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000457_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000457_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000457_11_1 & 1) != 0)
  {
    if ((sec_r000457_11_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000457_6_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000457_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000457_6_1 + 7) & 127;
  }
  if ((sec_r000457_11_2 & 1) != 0)
  {
    if ((sec_r000457_11_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000457_6_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000457_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000457_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000457_12_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000457_8_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000457_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000457_8_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000457_12_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000457_8_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000457_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000457_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000457_15_1 & 1) != 0)
  {
    if ((sec_r000457_5_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000457_18_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000457_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000457_18_1 + 7) & 127;
  }
  if ((sec_r000457_15_2 & 1) != 0)
  {
    if ((sec_r000457_5_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000457_18_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000457_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000457_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000457_3_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000457_11_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000457_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000457_11_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000457_3_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000457_11_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000457_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000457_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000457_18_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000457_8_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000457_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000457_8_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000457_18_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000457_8_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000457_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000457_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000457_13_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000457_14_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000457_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000457_14_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000457_13_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000457_14_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000457_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000457_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000457_5_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000457_12_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000457_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000457_12_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000457_5_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000457_12_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000457_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000457_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000457_12_1 & 1) != 0)
  {
    if ((sec_r000457_15_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000457_13_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000457_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000457_13_1 + 7) & 127;
  }
  if ((sec_r000457_12_2 & 1) != 0)
  {
    if ((sec_r000457_15_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000457_13_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000457_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000457_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000457_16_1 & 1) != 0)
  {
    if ((sec_r000457_10_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000457_18_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000457_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000457_18_1 + 7) & 127;
  }
  if ((sec_r000457_16_2 & 1) != 0)
  {
    if ((sec_r000457_10_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000457_18_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000457_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000457_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000457_7_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000457_18_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000457_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000457_18_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000457_7_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000457_18_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000457_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000457_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000457_15_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000457_11_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000457_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000457_11_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000457_15_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000457_11_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000457_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000457_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000457_5_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000457_8_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000457_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000457_8_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000457_5_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000457_8_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000457_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000457_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000457_15_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000457_6_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000457_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000457_6_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000457_15_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000457_6_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000457_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000457_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000457_9_1 & 1) != 0)
  {
    if ((sec_r000457_9_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000457_13_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000457_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000457_13_1 + 7) & 127;
  }
  if ((sec_r000457_9_2 & 1) != 0)
  {
    if ((sec_r000457_9_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000457_13_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000457_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000457_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000457_2_1 & 1) != 0)
  {
    if ((sec_r000457_5_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000457_16_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000457_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000457_16_1 + 7) & 127;
  }
  if ((sec_r000457_2_2 & 1) != 0)
  {
    if ((sec_r000457_5_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000457_16_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000457_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000457_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000457_9_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000457_5_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000457_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000457_5_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000457_9_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000457_5_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000457_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000457_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000457_16_1 & 1) != 0)
  {
    if ((sec_r000457_18_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000457_2_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000457_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000457_2_1 + 7) & 127;
  }
  if ((sec_r000457_16_2 & 1) != 0)
  {
    if ((sec_r000457_18_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000457_2_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000457_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000457_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000457_6_1 & 1) != 0)
  {
    if ((sec_r000457_11_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000457_4_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000457_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000457_4_1 + 7) & 127;
  }
  if ((sec_r000457_6_2 & 1) != 0)
  {
    if ((sec_r000457_11_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000457_4_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000457_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000457_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000457_0_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000457_3_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000457_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000457_3_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000457_0_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000457_3_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000457_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000457_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000457_16_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000457_2_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000457_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000457_2_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000457_16_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000457_2_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000457_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000457_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000457_9_1 & 1) != 0)
  {
    if ((sec_r000457_3_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000457_8_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000457_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000457_8_1 + 7) & 127;
  }
  if ((sec_r000457_9_2 & 1) != 0)
  {
    if ((sec_r000457_3_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000457_8_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000457_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000457_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000457_5_1 & 1) != 0)
  {
    if ((sec_r000457_1_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000457_12_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000457_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000457_12_1 + 7) & 127;
  }
  if ((sec_r000457_5_2 & 1) != 0)
  {
    if ((sec_r000457_1_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000457_12_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000457_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000457_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000457_16_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000457_6_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000457_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000457_6_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000457_16_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000457_6_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000457_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000457_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000457_16_1 & 1) != 0)
  {
    if ((sec_r000457_2_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000457_4_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000457_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000457_4_1 + 7) & 127;
  }
  if ((sec_r000457_16_2 & 1) != 0)
  {
    if ((sec_r000457_2_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000457_4_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000457_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000457_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000457_11_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000457_1_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000457_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000457_1_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000457_11_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000457_1_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000457_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000457_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000457_2_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000457_14_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000457_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000457_14_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000457_2_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000457_14_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000457_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000457_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000457_7_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000457_9_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000457_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000457_9_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000457_7_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000457_9_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000457_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000457_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000457_17_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000457_7_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000457_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000457_7_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000457_17_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000457_7_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000457_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000457_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000457_6_1 & 1) != 0)
  {
    if ((sec_r000457_15_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000457_10_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000457_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000457_10_1 + 7) & 127;
  }
  if ((sec_r000457_6_2 & 1) != 0)
  {
    if ((sec_r000457_15_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000457_10_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000457_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000457_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000457_8_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000457_14_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000457_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000457_14_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000457_8_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000457_14_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000457_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000457_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000457_6_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000457_8_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000457_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000457_8_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000457_6_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000457_8_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000457_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000457_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000457_2_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000457_0_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000457_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000457_0_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000457_2_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000457_0_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000457_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000457_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000457_17_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000457_0_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000457_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000457_0_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000457_17_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000457_0_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000457_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000457_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000457_12_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000457_12_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000457_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000457_12_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000457_12_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000457_12_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000457_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000457_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000457_0_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000457_5_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000457_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000457_5_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000457_0_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000457_5_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000457_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000457_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000457_4_1 & 1) != 0)
  {
    if ((sec_r000457_13_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000457_6_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000457_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000457_6_1 + 7) & 127;
  }
  if ((sec_r000457_4_2 & 1) != 0)
  {
    if ((sec_r000457_13_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000457_6_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000457_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000457_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000457_16_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000457_15_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000457_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000457_15_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000457_16_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000457_15_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000457_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000457_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000457_7_1 & 1) != 0)
  {
    if ((sec_r000457_12_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000457_17_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000457_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000457_17_1 + 7) & 127;
  }
  if ((sec_r000457_7_2 & 1) != 0)
  {
    if ((sec_r000457_12_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000457_17_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000457_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000457_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000457_9_1 & 1) != 0)
  {
    if ((sec_r000457_4_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000457_5_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000457_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000457_5_1 + 7) & 127;
  }
  if ((sec_r000457_9_2 & 1) != 0)
  {
    if ((sec_r000457_4_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000457_5_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000457_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000457_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000457_13_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000457_13_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000457_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000457_13_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000457_13_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000457_13_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000457_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000457_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000457_4_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000457_0_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000457_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000457_0_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000457_4_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000457_0_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000457_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000457_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000457_6_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000457_0_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000457_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000457_0_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000457_6_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000457_0_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000457_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000457_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000457_17_1 & 1) != 0)
  {
    if ((sec_r000457_18_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000457_0_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000457_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000457_0_1 + 7) & 127;
  }
  if ((sec_r000457_17_2 & 1) != 0)
  {
    if ((sec_r000457_18_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000457_0_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000457_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000457_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000457_13_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000457_2_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000457_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000457_2_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000457_13_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000457_2_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000457_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000457_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000457_4_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000457_17_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000457_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000457_17_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000457_4_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000457_17_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000457_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000457_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000457_3_1 & 1) != 0)
  {
    if ((sec_r000457_7_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000457_6_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000457_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000457_6_1 + 7) & 127;
  }
  if ((sec_r000457_3_2 & 1) != 0)
  {
    if ((sec_r000457_7_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000457_6_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000457_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000457_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000457_3_1 & 1) != 0)
  {
    if ((sec_r000457_8_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000457_2_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000457_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000457_2_1 + 7) & 127;
  }
  if ((sec_r000457_3_2 & 1) != 0)
  {
    if ((sec_r000457_8_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000457_2_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000457_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000457_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000457_14_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000457_4_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000457_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000457_4_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000457_14_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000457_4_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000457_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000457_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000457_7_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000457_0_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000457_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000457_0_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000457_7_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000457_0_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000457_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000457_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000457_13_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000457_5_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000457_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000457_5_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000457_13_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000457_5_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000457_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000457_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((sec_r000457_3_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000457_6_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000457_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000457_6_1 + 7) & 127;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((sec_r000457_3_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000457_6_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000457_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000457_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((sec_r000457_12_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000457_12_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000457_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000457_12_1 + 7) & 127;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((sec_r000457_12_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000457_12_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000457_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000457_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000457_6_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000457_11_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000457_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000457_11_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000457_6_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000457_11_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000457_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000457_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000457_4_1 & 1) != 0)
  {
    if ((sec_r000457_9_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000457_5_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000457_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000457_5_1 + 7) & 127;
  }
  if ((sec_r000457_4_2 & 1) != 0)
  {
    if ((sec_r000457_9_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000457_5_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000457_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000457_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000457_11_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000457_16_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000457_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000457_16_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000457_11_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000457_16_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000457_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000457_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000457_17_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000457_10_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000457_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000457_10_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000457_17_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000457_10_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000457_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000457_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((sec_r000457_3_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000457_1_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000457_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000457_1_1 + 7) & 127;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((sec_r000457_3_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000457_1_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000457_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000457_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((sec_r000457_8_1 & 1) != 0)
  {
    if ((sec_r000457_15_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000457_6_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000457_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000457_6_1 + 7) & 127;
  }
  if ((sec_r000457_8_2 & 1) != 0)
  {
    if ((sec_r000457_15_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000457_6_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000457_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000457_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000457_5_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000457_7_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000457_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000457_7_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000457_5_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000457_7_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000457_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000457_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000457_15_1 & 1) != 0)
  {
    if ((sec_r000457_11_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000457_17_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000457_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000457_17_1 + 7) & 127;
  }
  if ((sec_r000457_15_2 & 1) != 0)
  {
    if ((sec_r000457_11_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000457_17_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000457_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000457_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000457_17_1 & 1) != 0)
  {
    if ((sec_r000457_0_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000457_14_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000457_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000457_14_1 + 7) & 127;
  }
  if ((sec_r000457_17_2 & 1) != 0)
  {
    if ((sec_r000457_0_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000457_14_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000457_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000457_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000457_14_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000457_12_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000457_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000457_12_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000457_14_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000457_12_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000457_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000457_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000457_5_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000457_8_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000457_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000457_8_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000457_5_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000457_8_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000457_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000457_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((sec_r000457_16_1 & 1) != 0)
  {
    if ((sec_r000457_4_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000457_15_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000457_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000457_15_1 + 7) & 127;
  }
  if ((sec_r000457_16_2 & 1) != 0)
  {
    if ((sec_r000457_4_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000457_15_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000457_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000457_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((sec_r000457_9_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000457_9_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000457_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000457_9_1 + 7) & 127;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((sec_r000457_9_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000457_9_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000457_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000457_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000457_5_1 & 1) != 0)
  {
    if ((sec_r000457_2_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000457_12_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000457_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000457_12_1 + 7) & 127;
  }
  if ((sec_r000457_5_2 & 1) != 0)
  {
    if ((sec_r000457_2_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000457_12_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000457_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000457_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000457_2_1 != sec_r000457_2_2);
  __CPROVER_assume(sec_r000457_11_1 != sec_r000457_11_2);
  __CPROVER_assume(sec_r000457_17_1 != sec_r000457_17_2);
  __CPROVER_assume(pub_r000457_17_1 == pub_r000457_17_2);
  __CPROVER_assume(sec_r000457_1_1 != sec_r000457_1_2);
  __CPROVER_assume(sec_r000457_14_1 != sec_r000457_14_2);
  __CPROVER_assume(sec_r000457_10_1 != sec_r000457_10_2);
  __CPROVER_assume(pub_r000457_14_1 == pub_r000457_14_2);
  __CPROVER_assume(pub_r000457_5_1 == pub_r000457_5_2);
  __CPROVER_assume(pub_r000457_11_1 == pub_r000457_11_2);
  __CPROVER_assume(sec_r000457_4_1 != sec_r000457_4_2);
  __CPROVER_assume(pub_r000457_0_1 == pub_r000457_0_2);
  __CPROVER_assume(pub_r000457_4_1 == pub_r000457_4_2);
  __CPROVER_assume(pub_r000457_16_1 == pub_r000457_16_2);
  __CPROVER_assume(sec_r000457_0_1 != sec_r000457_0_2);
  __CPROVER_assume(sec_r000457_16_1 != sec_r000457_16_2);
  __CPROVER_assume(pub_r000457_13_1 == pub_r000457_13_2);
  __CPROVER_assume(pub_r000457_9_1 == pub_r000457_9_2);
  __CPROVER_assume(sec_r000457_8_1 != sec_r000457_8_2);
  __CPROVER_assume(sec_r000457_7_1 != sec_r000457_7_2);
  __CPROVER_assume(sec_r000457_9_1 != sec_r000457_9_2);
  __CPROVER_assume(pub_r000457_12_1 == pub_r000457_12_2);
  __CPROVER_assume(sec_r000457_3_1 != sec_r000457_3_2);
  __CPROVER_assume(pub_r000457_15_1 == pub_r000457_15_2);
  __CPROVER_assume(sec_r000457_15_1 != sec_r000457_15_2);
  __CPROVER_assume(pub_r000457_7_1 == pub_r000457_7_2);
  __CPROVER_assume(pub_r000457_6_1 == pub_r000457_6_2);
  __CPROVER_assume(sec_r000457_6_1 != sec_r000457_6_2);
  __CPROVER_assume(pub_r000457_3_1 == pub_r000457_3_2);
  __CPROVER_assume(sec_r000457_18_1 != sec_r000457_18_2);
  __CPROVER_assume(pub_r000457_1_1 == pub_r000457_1_2);
  __CPROVER_assume(pub_r000457_10_1 == pub_r000457_10_2);
  __CPROVER_assume(pub_r000457_8_1 == pub_r000457_8_2);
  __CPROVER_assume(sec_r000457_5_1 != sec_r000457_5_2);
  __CPROVER_assume(sec_r000457_12_1 != sec_r000457_12_2);
  __CPROVER_assume(sec_r000457_13_1 != sec_r000457_13_2);
  __CPROVER_assume(pub_r000457_18_1 == pub_r000457_18_2);
  __CPROVER_assume(pub_r000457_2_1 == pub_r000457_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.dim == st_var_1_2.dim);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.density == st_var_1_2.density);
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
}


