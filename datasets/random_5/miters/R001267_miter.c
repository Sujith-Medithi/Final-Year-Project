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
struct MatrixBlock_R001267_6713_0
{
  unsigned char scale;
  int trace;
  short stride;
  int determinant;
  short dim;
  int buffer[3];
};
struct DeviceConfig_R001267_6713_1
{
  unsigned char id;
  unsigned char timeout;
  int parity;
  int stop_bits;
  short port;
  int buffer[3];
};
struct Vector3D_R001267_6713_2
{
  short coord_y;
  int norm_sq;
  short pitch;
  unsigned char coord_x;
  int coord_z;
  short heading;
  int buffer[3];
};
union RegisterBank_R001267_6713_0
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
void fn_R001267_6713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001267_6713_2 st_1 = {0};
  struct Vector3D_R001267_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_38_1 = local_arr_1[aux_1 % 3];
  int window_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_38_2 * 2)) & 127;
  int phase_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_28_1 > 29)
  {
    acc_1 = ((acc_1 + (phase_28_1 * 2)) + 5) & 127;
    aux_1 ^= phase_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_28_2 > 29)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_38_1 == window_38_2);
  assert(phase_28_1 == phase_28_2);
}

int fn_R001267_6713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001267_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int window_38 = local_arr[aux % 3];
  acc = (acc + (window_38 * 2)) & 127;
  int phase_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_28 > 29)
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

void fn_R001267_6713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001267_6713_0 st_1 = {0};
  struct MatrixBlock_R001267_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int tally_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_86_1)
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

  switch (tally_86_2)
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
  int bound_65_1 = local_arr_1[aux_1 % 3];
  int bound_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_65_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_86_1 == tally_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_65_1 == bound_65_2);
}

int fn_R001267_6713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int tally_86 = (aux + st.buffer[1]) & 3;
  switch (tally_86)
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
  int bound_65 = local_arr[aux % 3];
  acc = (acc + (bound_65 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001267_6713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001267_6713_0 st_1 = {0};
  struct MatrixBlock_R001267_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_38_1) & 63;
  aux_2 = (aux_2 + segment_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_95_1 > 50)
  {
    acc_1 = ((acc_1 + (window_95_1 * 2)) + 5) & 127;
    aux_1 ^= window_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_95_2 > 50)
  {
    acc_2 = ((acc_2 + (window_95_2 * 2)) + 5) & 127;
    aux_2 ^= window_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_54_1)
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

  switch (coefficient_54_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_38_1 == segment_38_2);
  assert(window_95_1 == window_95_2);
  assert(coefficient_54_1 == coefficient_54_2);
}

int fn_R001267_6713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_38) & 63;
  acc ^= aux;
  int window_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_95 > 50)
  {
    acc = ((acc + (window_95 * 2)) + 5) & 127;
    aux ^= window_95 & 15;
  }
  else
  {
    acc = ((acc - window_95) + 11) & 127;
    aux += 3;
  }
  int coefficient_54 = (aux + st.buffer[1]) & 3;
  switch (coefficient_54)
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

void fn_R001267_6713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001267_6713_1 st_1 = {0};
  struct DeviceConfig_R001267_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_26_1 > 19)
  {
    acc_1 = ((acc_1 + (factor_26_1 * 2)) + 5) & 127;
    aux_1 ^= factor_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_26_2 > 19)
  {
    acc_2 = ((acc_2 + (factor_26_2 * 2)) + 5) & 127;
    aux_2 ^= factor_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_26_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_26_1 == factor_26_2);
}

int fn_R001267_6713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001267_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_26 > 19)
  {
    acc = ((acc + (factor_26 * 2)) + 5) & 127;
    aux ^= factor_26 & 15;
  }
  else
  {
    acc = ((acc - factor_26) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001267_6713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001267_6713_0 st_1 = {0};
  struct MatrixBlock_R001267_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int threshold_64_1 = 0;
  int threshold_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_64_1 = ((threshold_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_64_2 = ((threshold_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_64_1) & 127;
    acc_2 = (acc_2 + threshold_64_2) & 127;
  }

  int checksum_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_69_1)
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

  switch (checksum_69_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_64_1 == threshold_64_2);
  assert(checksum_69_1 == checksum_69_2);
}

int fn_R001267_6713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int threshold_64 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_64 = ((threshold_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_64) & 127;
  }

  int checksum_69 = (aux + st.buffer[1]) & 3;
  switch (checksum_69)
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

void fn_R001267_6713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001267_6713_2 st_1 = {0};
  struct Vector3D_R001267_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_35_1 > 49)
  {
    acc_1 = ((acc_1 + (sample_35_1 * 2)) + 5) & 127;
    aux_1 ^= sample_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_35_2 > 49)
  {
    acc_2 = ((acc_2 + (sample_35_2 * 2)) + 5) & 127;
    aux_2 ^= sample_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_26_1)
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

  switch (tracker_26_2)
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
  int checksum_25_1 = local_arr_1[aux_1 % 3];
  int checksum_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_25_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_35_1 == sample_35_2);
  assert(tracker_26_1 == tracker_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_25_1 == checksum_25_2);
}

int fn_R001267_6713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001267_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_35 > 49)
  {
    acc = ((acc + (sample_35 * 2)) + 5) & 127;
    aux ^= sample_35 & 15;
  }
  else
  {
    acc = ((acc - sample_35) + 11) & 127;
    aux += 3;
  }
  int tracker_26 = (aux + st.buffer[1]) & 3;
  switch (tracker_26)
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
  int checksum_25 = local_arr[aux % 3];
  acc = (acc + (checksum_25 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001267_6713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001267_6713_1 st_1 = {0};
  struct DeviceConfig_R001267_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int stride_32_1 = 0;
  int stride_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_32_1 = ((stride_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_32_2 = ((stride_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_32_1) & 127;
    acc_2 = (acc_2 + stride_32_2) & 127;
  }

  int segment_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_48_1) & 63;
  aux_2 = (aux_2 + segment_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_32_1 == stride_32_2);
  assert(segment_48_1 == segment_48_2);
}

int fn_R001267_6713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001267_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int stride_32 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_32 = ((stride_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_32) & 127;
  }

  int segment_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001267_6713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001267_6713_0 st_1 = {0};
  struct MatrixBlock_R001267_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int accumulator_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_16_1 > 13)
  {
    acc_1 = ((acc_1 + (accumulator_16_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_16_2 > 13)
  {
    acc_2 = ((acc_2 + (accumulator_16_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_10_1 = 0;
  int anchor_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_10_1 = ((anchor_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_10_2 = ((anchor_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_10_1) & 127;
    acc_2 = (acc_2 + anchor_10_2) & 127;
  }

  int delta_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_16_1) & 63;
  aux_2 = (aux_2 + delta_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_38_1)
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

  switch (index_reg_38_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_16_1 == accumulator_16_2);
  assert(anchor_10_1 == anchor_10_2);
  assert(delta_16_1 == delta_16_2);
  assert(index_reg_38_1 == index_reg_38_2);
}

int fn_R001267_6713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int accumulator_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_16 > 13)
  {
    acc = ((acc + (accumulator_16 * 2)) + 5) & 127;
    aux ^= accumulator_16 & 15;
  }
  else
  {
    acc = ((acc - accumulator_16) + 11) & 127;
    aux += 3;
  }
  int anchor_10 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_10 = ((anchor_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_10) & 127;
  }

  int delta_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_16) & 63;
  acc ^= aux;
  int index_reg_38 = (aux + st.buffer[1]) & 3;
  switch (index_reg_38)
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

void fn_R001267_6713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001267_6713_2 st_1 = {0};
  struct Vector3D_R001267_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_64_1 = local_arr_1[aux_1 % 3];
  int margin_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_64_2 * 2)) & 127;
  int offset_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_33_1 > 44)
  {
    acc_1 = ((acc_1 + (offset_33_1 * 2)) + 5) & 127;
    aux_1 ^= offset_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_33_2 > 44)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_64_1 == margin_64_2);
  assert(offset_33_1 == offset_33_2);
}

int fn_R001267_6713_8(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001267_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int margin_64 = local_arr[aux % 3];
  acc = (acc + (margin_64 * 2)) & 127;
  int offset_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_33 > 44)
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

void fn_R001267_6713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001267_6713_1 st_1 = {0};
  struct DeviceConfig_R001267_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int scale_24_1 = 0;
  int scale_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_24_1 = ((scale_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_24_2 = ((scale_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_24_1) & 127;
    acc_2 = (acc_2 + scale_24_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_52_1 > 44)
  {
    acc_1 = ((acc_1 + (coefficient_52_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_52_2 > 44)
  {
    acc_2 = ((acc_2 + (coefficient_52_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_52_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_24_1 == scale_24_2);
  assert(coefficient_52_1 == coefficient_52_2);
}

int fn_R001267_6713_9(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001267_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int scale_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_24 = ((scale_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_24) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_52 > 44)
  {
    acc = ((acc + (coefficient_52 * 2)) + 5) & 127;
    aux ^= coefficient_52 & 15;
  }
  else
  {
    acc = ((acc - coefficient_52) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001267_6713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001267_6713_1 st_1 = {0};
  struct DeviceConfig_R001267_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int parity_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_39_1)
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

  switch (parity_39_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_39_1 == parity_39_2);
}

int fn_R001267_6713_10(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001267_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int parity_39 = (aux + st.buffer[1]) & 3;
  switch (parity_39)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001267_6713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001267_6713_2 st_1 = {0};
  struct Vector3D_R001267_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_36_1 = local_arr_1[aux_1 % 3];
  int quantum_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_36_2 * 2)) & 127;
  int quantum_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_82_1 > 48)
  {
    acc_1 = ((acc_1 + (quantum_82_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_82_2 > 48)
  {
    acc_2 = ((acc_2 + (quantum_82_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_36_1 == quantum_36_2);
  assert(quantum_82_1 == quantum_82_2);
}

int fn_R001267_6713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001267_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int quantum_36 = local_arr[aux % 3];
  acc = (acc + (quantum_36 * 2)) & 127;
  int quantum_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_82 > 48)
  {
    acc = ((acc + (quantum_82 * 2)) + 5) & 127;
    aux ^= quantum_82 & 15;
  }
  else
  {
    acc = ((acc - quantum_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001267_6713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001267_6713_0 st_1 = {0};
  struct MatrixBlock_R001267_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int phase_88_1 = 0;
  int phase_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_88_1 = ((phase_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_88_2 = ((phase_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_88_1) & 127;
    acc_2 = (acc_2 + phase_88_2) & 127;
  }

  int offset_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_77_1) & 63;
  aux_2 = (aux_2 + offset_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_60_1)
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

  switch (threshold_60_2)
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

  int mask_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_75_1 > 16)
  {
    acc_1 = ((acc_1 + (mask_75_1 * 2)) + 5) & 127;
    aux_1 ^= mask_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_75_2 > 16)
  {
    acc_2 = ((acc_2 + (mask_75_2 * 2)) + 5) & 127;
    aux_2 ^= mask_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_75_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_88_1 == phase_88_2);
  assert(offset_77_1 == offset_77_2);
  assert(threshold_60_1 == threshold_60_2);
  assert(mask_75_1 == mask_75_2);
}

int fn_R001267_6713_12(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int phase_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_88 = ((phase_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_88) & 127;
  }

  int offset_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_77) & 63;
  acc ^= aux;
  int threshold_60 = (aux + st.buffer[1]) & 3;
  switch (threshold_60)
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

  int mask_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_75 > 16)
  {
    acc = ((acc + (mask_75 * 2)) + 5) & 127;
    aux ^= mask_75 & 15;
  }
  else
  {
    acc = ((acc - mask_75) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001267_6713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001267_6713_1 st_1 = {0};
  struct DeviceConfig_R001267_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int checksum_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_86_1) & 63;
  aux_2 = (aux_2 + checksum_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_86_1 == checksum_86_2);
}

int fn_R001267_6713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001267_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int checksum_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_86) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001267_0_1;
  int sec_r001267_0_2;
  int sec_r001267_1_1;
  int sec_r001267_1_2;
  int sec_r001267_2_1;
  int sec_r001267_2_2;
  int sec_r001267_3_1;
  int sec_r001267_3_2;
  int sec_r001267_4_1;
  int sec_r001267_4_2;
  int sec_r001267_5_1;
  int sec_r001267_5_2;
  int sec_r001267_6_1;
  int sec_r001267_6_2;
  int sec_r001267_7_1;
  int sec_r001267_7_2;
  int sec_r001267_8_1;
  int sec_r001267_8_2;
  int sec_r001267_9_1;
  int sec_r001267_9_2;
  int sec_r001267_10_1;
  int sec_r001267_10_2;
  int sec_r001267_11_1;
  int sec_r001267_11_2;
  int sec_r001267_12_1;
  int sec_r001267_12_2;
  int sec_r001267_13_1;
  int sec_r001267_13_2;
  int sec_r001267_14_1;
  int sec_r001267_14_2;
  int sec_r001267_15_1;
  int sec_r001267_15_2;
  int sec_r001267_16_1;
  int sec_r001267_16_2;
  int sec_r001267_17_1;
  int sec_r001267_17_2;
  int sec_r001267_18_1;
  int sec_r001267_18_2;
  int sec_r001267_19_1;
  int sec_r001267_19_2;
  int sec_r001267_20_1;
  int sec_r001267_20_2;
  int sec_r001267_21_1;
  int sec_r001267_21_2;
  int sec_r001267_22_1;
  int sec_r001267_22_2;
  int pub_r001267_0_1;
  int pub_r001267_0_2;
  int pub_r001267_1_1;
  int pub_r001267_1_2;
  int pub_r001267_2_1;
  int pub_r001267_2_2;
  int pub_r001267_3_1;
  int pub_r001267_3_2;
  int pub_r001267_4_1;
  int pub_r001267_4_2;
  int pub_r001267_5_1;
  int pub_r001267_5_2;
  int pub_r001267_6_1;
  int pub_r001267_6_2;
  int pub_r001267_7_1;
  int pub_r001267_7_2;
  int pub_r001267_8_1;
  int pub_r001267_8_2;
  int pub_r001267_9_1;
  int pub_r001267_9_2;
  int pub_r001267_10_1;
  int pub_r001267_10_2;
  int pub_r001267_11_1;
  int pub_r001267_11_2;
  int pub_r001267_12_1;
  int pub_r001267_12_2;
  int pub_r001267_13_1;
  int pub_r001267_13_2;
  int pub_r001267_14_1;
  int pub_r001267_14_2;
  int pub_r001267_15_1;
  int pub_r001267_15_2;
  int pub_r001267_16_1;
  int pub_r001267_16_2;
  int pub_r001267_17_1;
  int pub_r001267_17_2;
  int pub_r001267_18_1;
  int pub_r001267_18_2;
  int pub_r001267_19_1;
  int pub_r001267_19_2;
  int pub_r001267_20_1;
  int pub_r001267_20_2;
  int pub_r001267_21_1;
  int pub_r001267_21_2;
  int pub_r001267_22_1;
  int pub_r001267_22_2;
  int pub_r001267_23_1;
  int pub_r001267_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001267_0_1 >= (-100)) && (pub_r001267_0_1 <= 100));
  __CPROVER_assume((pub_r001267_0_2 >= (-100)) && (pub_r001267_0_2 <= 100));
  __CPROVER_assume((pub_r001267_1_1 >= (-100)) && (pub_r001267_1_1 <= 100));
  __CPROVER_assume((pub_r001267_1_2 >= (-100)) && (pub_r001267_1_2 <= 100));
  __CPROVER_assume((pub_r001267_2_1 >= (-100)) && (pub_r001267_2_1 <= 100));
  __CPROVER_assume((pub_r001267_2_2 >= (-100)) && (pub_r001267_2_2 <= 100));
  __CPROVER_assume((pub_r001267_3_1 >= (-100)) && (pub_r001267_3_1 <= 100));
  __CPROVER_assume((pub_r001267_3_2 >= (-100)) && (pub_r001267_3_2 <= 100));
  __CPROVER_assume((pub_r001267_4_1 >= (-100)) && (pub_r001267_4_1 <= 100));
  __CPROVER_assume((pub_r001267_4_2 >= (-100)) && (pub_r001267_4_2 <= 100));
  __CPROVER_assume((pub_r001267_5_1 >= (-100)) && (pub_r001267_5_1 <= 100));
  __CPROVER_assume((pub_r001267_5_2 >= (-100)) && (pub_r001267_5_2 <= 100));
  __CPROVER_assume((pub_r001267_6_1 >= (-100)) && (pub_r001267_6_1 <= 100));
  __CPROVER_assume((pub_r001267_6_2 >= (-100)) && (pub_r001267_6_2 <= 100));
  __CPROVER_assume((pub_r001267_7_1 >= (-100)) && (pub_r001267_7_1 <= 100));
  __CPROVER_assume((pub_r001267_7_2 >= (-100)) && (pub_r001267_7_2 <= 100));
  __CPROVER_assume((pub_r001267_8_1 >= (-100)) && (pub_r001267_8_1 <= 100));
  __CPROVER_assume((pub_r001267_8_2 >= (-100)) && (pub_r001267_8_2 <= 100));
  __CPROVER_assume((pub_r001267_9_1 >= (-100)) && (pub_r001267_9_1 <= 100));
  __CPROVER_assume((pub_r001267_9_2 >= (-100)) && (pub_r001267_9_2 <= 100));
  __CPROVER_assume((pub_r001267_10_1 >= (-100)) && (pub_r001267_10_1 <= 100));
  __CPROVER_assume((pub_r001267_10_2 >= (-100)) && (pub_r001267_10_2 <= 100));
  __CPROVER_assume((pub_r001267_11_1 >= (-100)) && (pub_r001267_11_1 <= 100));
  __CPROVER_assume((pub_r001267_11_2 >= (-100)) && (pub_r001267_11_2 <= 100));
  __CPROVER_assume((pub_r001267_12_1 >= (-100)) && (pub_r001267_12_1 <= 100));
  __CPROVER_assume((pub_r001267_12_2 >= (-100)) && (pub_r001267_12_2 <= 100));
  __CPROVER_assume((pub_r001267_13_1 >= (-100)) && (pub_r001267_13_1 <= 100));
  __CPROVER_assume((pub_r001267_13_2 >= (-100)) && (pub_r001267_13_2 <= 100));
  __CPROVER_assume((pub_r001267_14_1 >= (-100)) && (pub_r001267_14_1 <= 100));
  __CPROVER_assume((pub_r001267_14_2 >= (-100)) && (pub_r001267_14_2 <= 100));
  __CPROVER_assume((pub_r001267_15_1 >= (-100)) && (pub_r001267_15_1 <= 100));
  __CPROVER_assume((pub_r001267_15_2 >= (-100)) && (pub_r001267_15_2 <= 100));
  __CPROVER_assume((pub_r001267_16_1 >= (-100)) && (pub_r001267_16_1 <= 100));
  __CPROVER_assume((pub_r001267_16_2 >= (-100)) && (pub_r001267_16_2 <= 100));
  __CPROVER_assume((pub_r001267_17_1 >= (-100)) && (pub_r001267_17_1 <= 100));
  __CPROVER_assume((pub_r001267_17_2 >= (-100)) && (pub_r001267_17_2 <= 100));
  __CPROVER_assume((pub_r001267_18_1 >= (-100)) && (pub_r001267_18_1 <= 100));
  __CPROVER_assume((pub_r001267_18_2 >= (-100)) && (pub_r001267_18_2 <= 100));
  __CPROVER_assume((pub_r001267_19_1 >= (-100)) && (pub_r001267_19_1 <= 100));
  __CPROVER_assume((pub_r001267_19_2 >= (-100)) && (pub_r001267_19_2 <= 100));
  __CPROVER_assume((pub_r001267_20_1 >= (-100)) && (pub_r001267_20_1 <= 100));
  __CPROVER_assume((pub_r001267_20_2 >= (-100)) && (pub_r001267_20_2 <= 100));
  __CPROVER_assume((pub_r001267_21_1 >= (-100)) && (pub_r001267_21_1 <= 100));
  __CPROVER_assume((pub_r001267_21_2 >= (-100)) && (pub_r001267_21_2 <= 100));
  __CPROVER_assume((pub_r001267_22_1 >= (-100)) && (pub_r001267_22_1 <= 100));
  __CPROVER_assume((pub_r001267_22_2 >= (-100)) && (pub_r001267_22_2 <= 100));
  __CPROVER_assume((pub_r001267_23_1 >= (-100)) && (pub_r001267_23_1 <= 100));
  __CPROVER_assume((pub_r001267_23_2 >= (-100)) && (pub_r001267_23_2 <= 100));
  __CPROVER_assume((sec_r001267_0_1 >= 0) && (sec_r001267_0_1 <= 255));
  __CPROVER_assume((sec_r001267_0_2 >= 0) && (sec_r001267_0_2 <= 255));
  __CPROVER_assume((sec_r001267_1_1 >= 0) && (sec_r001267_1_1 <= 255));
  __CPROVER_assume((sec_r001267_1_2 >= 0) && (sec_r001267_1_2 <= 255));
  __CPROVER_assume((sec_r001267_2_1 >= 0) && (sec_r001267_2_1 <= 255));
  __CPROVER_assume((sec_r001267_2_2 >= 0) && (sec_r001267_2_2 <= 255));
  __CPROVER_assume((sec_r001267_3_1 >= 0) && (sec_r001267_3_1 <= 255));
  __CPROVER_assume((sec_r001267_3_2 >= 0) && (sec_r001267_3_2 <= 255));
  __CPROVER_assume((sec_r001267_4_1 >= 0) && (sec_r001267_4_1 <= 255));
  __CPROVER_assume((sec_r001267_4_2 >= 0) && (sec_r001267_4_2 <= 255));
  __CPROVER_assume((sec_r001267_5_1 >= 0) && (sec_r001267_5_1 <= 255));
  __CPROVER_assume((sec_r001267_5_2 >= 0) && (sec_r001267_5_2 <= 255));
  __CPROVER_assume((sec_r001267_6_1 >= 0) && (sec_r001267_6_1 <= 255));
  __CPROVER_assume((sec_r001267_6_2 >= 0) && (sec_r001267_6_2 <= 255));
  __CPROVER_assume((sec_r001267_7_1 >= 0) && (sec_r001267_7_1 <= 255));
  __CPROVER_assume((sec_r001267_7_2 >= 0) && (sec_r001267_7_2 <= 255));
  __CPROVER_assume((sec_r001267_8_1 >= 0) && (sec_r001267_8_1 <= 255));
  __CPROVER_assume((sec_r001267_8_2 >= 0) && (sec_r001267_8_2 <= 255));
  __CPROVER_assume((sec_r001267_9_1 >= 0) && (sec_r001267_9_1 <= 255));
  __CPROVER_assume((sec_r001267_9_2 >= 0) && (sec_r001267_9_2 <= 255));
  __CPROVER_assume((sec_r001267_10_1 >= 0) && (sec_r001267_10_1 <= 255));
  __CPROVER_assume((sec_r001267_10_2 >= 0) && (sec_r001267_10_2 <= 255));
  __CPROVER_assume((sec_r001267_11_1 >= 0) && (sec_r001267_11_1 <= 255));
  __CPROVER_assume((sec_r001267_11_2 >= 0) && (sec_r001267_11_2 <= 255));
  __CPROVER_assume((sec_r001267_12_1 >= 0) && (sec_r001267_12_1 <= 255));
  __CPROVER_assume((sec_r001267_12_2 >= 0) && (sec_r001267_12_2 <= 255));
  __CPROVER_assume((sec_r001267_13_1 >= 0) && (sec_r001267_13_1 <= 255));
  __CPROVER_assume((sec_r001267_13_2 >= 0) && (sec_r001267_13_2 <= 255));
  __CPROVER_assume((sec_r001267_14_1 >= 0) && (sec_r001267_14_1 <= 255));
  __CPROVER_assume((sec_r001267_14_2 >= 0) && (sec_r001267_14_2 <= 255));
  __CPROVER_assume((sec_r001267_15_1 >= 0) && (sec_r001267_15_1 <= 255));
  __CPROVER_assume((sec_r001267_15_2 >= 0) && (sec_r001267_15_2 <= 255));
  __CPROVER_assume((sec_r001267_16_1 >= 0) && (sec_r001267_16_1 <= 255));
  __CPROVER_assume((sec_r001267_16_2 >= 0) && (sec_r001267_16_2 <= 255));
  __CPROVER_assume((sec_r001267_17_1 >= 0) && (sec_r001267_17_1 <= 255));
  __CPROVER_assume((sec_r001267_17_2 >= 0) && (sec_r001267_17_2 <= 255));
  __CPROVER_assume((sec_r001267_18_1 >= 0) && (sec_r001267_18_1 <= 255));
  __CPROVER_assume((sec_r001267_18_2 >= 0) && (sec_r001267_18_2 <= 255));
  __CPROVER_assume((sec_r001267_19_1 >= 0) && (sec_r001267_19_1 <= 255));
  __CPROVER_assume((sec_r001267_19_2 >= 0) && (sec_r001267_19_2 <= 255));
  __CPROVER_assume((sec_r001267_20_1 >= 0) && (sec_r001267_20_1 <= 255));
  __CPROVER_assume((sec_r001267_20_2 >= 0) && (sec_r001267_20_2 <= 255));
  __CPROVER_assume((sec_r001267_21_1 >= 0) && (sec_r001267_21_1 <= 255));
  __CPROVER_assume((sec_r001267_21_2 >= 0) && (sec_r001267_21_2 <= 255));
  __CPROVER_assume((sec_r001267_22_1 >= 0) && (sec_r001267_22_1 <= 255));
  __CPROVER_assume((sec_r001267_22_2 >= 0) && (sec_r001267_22_2 <= 255));
  struct MatrixBlock_R001267_6713_0 st_var_0_1 = {0};
  struct MatrixBlock_R001267_6713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001267_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001267_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001267_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001267_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001267_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001267_0_2 + 7) & 15;
  struct DeviceConfig_R001267_6713_1 st_var_1_1 = {0};
  struct DeviceConfig_R001267_6713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001267_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001267_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001267_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001267_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001267_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001267_0_2 + 9) & 15;
  struct Vector3D_R001267_6713_2 st_var_2_1 = {0};
  struct Vector3D_R001267_6713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001267_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001267_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001267_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001267_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001267_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001267_0_2 + 11) & 15;
  union RegisterBank_R001267_6713_0 u_var_1;
  union RegisterBank_R001267_6713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001267_6713_0(sec_r001267_0_1, pub_r001267_1_1, pub_r001267_2_1);
  int helper_flow_0_2 = fn_R001267_6713_0(sec_r001267_0_2, pub_r001267_1_2, pub_r001267_2_2);
  fn_R001267_6713_0_2(sec_r001267_0_1, pub_r001267_1_1, pub_r001267_2_1, sec_r001267_0_2, pub_r001267_1_2, pub_r001267_2_2);
  int helper_flow_1_1 = fn_R001267_6713_1(sec_r001267_1_1, sec_r001267_2_1, pub_r001267_3_1);
  int helper_flow_1_2 = fn_R001267_6713_1(sec_r001267_1_2, sec_r001267_2_2, pub_r001267_3_2);
  fn_R001267_6713_1_2(sec_r001267_1_1, sec_r001267_2_1, pub_r001267_3_1, sec_r001267_1_2, sec_r001267_2_2, pub_r001267_3_2);
  int helper_flow_2_1 = fn_R001267_6713_2(sec_r001267_2_1, sec_r001267_3_1, pub_r001267_4_1);
  int helper_flow_2_2 = fn_R001267_6713_2(sec_r001267_2_2, sec_r001267_3_2, pub_r001267_4_2);
  fn_R001267_6713_2_2(sec_r001267_2_1, sec_r001267_3_1, pub_r001267_4_1, sec_r001267_2_2, sec_r001267_3_2, pub_r001267_4_2);
  int helper_flow_3_1 = fn_R001267_6713_3(sec_r001267_3_1, sec_r001267_4_1, pub_r001267_5_1, pub_r001267_6_1);
  int helper_flow_3_2 = fn_R001267_6713_3(sec_r001267_3_2, sec_r001267_4_2, pub_r001267_5_2, pub_r001267_6_2);
  fn_R001267_6713_3_2(sec_r001267_3_1, sec_r001267_4_1, pub_r001267_5_1, pub_r001267_6_1, sec_r001267_3_2, sec_r001267_4_2, pub_r001267_5_2, pub_r001267_6_2);
  int helper_flow_4_1 = fn_R001267_6713_4(sec_r001267_4_1, sec_r001267_5_1, pub_r001267_6_1);
  int helper_flow_4_2 = fn_R001267_6713_4(sec_r001267_4_2, sec_r001267_5_2, pub_r001267_6_2);
  fn_R001267_6713_4_2(sec_r001267_4_1, sec_r001267_5_1, pub_r001267_6_1, sec_r001267_4_2, sec_r001267_5_2, pub_r001267_6_2);
  int helper_flow_5_1 = fn_R001267_6713_5(sec_r001267_5_1, pub_r001267_6_1, pub_r001267_7_1, pub_r001267_8_1);
  int helper_flow_5_2 = fn_R001267_6713_5(sec_r001267_5_2, pub_r001267_6_2, pub_r001267_7_2, pub_r001267_8_2);
  fn_R001267_6713_5_2(sec_r001267_5_1, pub_r001267_6_1, pub_r001267_7_1, pub_r001267_8_1, sec_r001267_5_2, pub_r001267_6_2, pub_r001267_7_2, pub_r001267_8_2);
  int helper_flow_6_1 = fn_R001267_6713_6(sec_r001267_6_1, sec_r001267_7_1, pub_r001267_8_1, pub_r001267_9_1);
  int helper_flow_6_2 = fn_R001267_6713_6(sec_r001267_6_2, sec_r001267_7_2, pub_r001267_8_2, pub_r001267_9_2);
  fn_R001267_6713_6_2(sec_r001267_6_1, sec_r001267_7_1, pub_r001267_8_1, pub_r001267_9_1, sec_r001267_6_2, sec_r001267_7_2, pub_r001267_8_2, pub_r001267_9_2);
  int helper_flow_7_1 = fn_R001267_6713_7(sec_r001267_7_1, sec_r001267_8_1, pub_r001267_9_1, pub_r001267_10_1);
  int helper_flow_7_2 = fn_R001267_6713_7(sec_r001267_7_2, sec_r001267_8_2, pub_r001267_9_2, pub_r001267_10_2);
  fn_R001267_6713_7_2(sec_r001267_7_1, sec_r001267_8_1, pub_r001267_9_1, pub_r001267_10_1, sec_r001267_7_2, sec_r001267_8_2, pub_r001267_9_2, pub_r001267_10_2);
  int helper_flow_8_1 = fn_R001267_6713_8(sec_r001267_8_1, pub_r001267_9_1);
  int helper_flow_8_2 = fn_R001267_6713_8(sec_r001267_8_2, pub_r001267_9_2);
  fn_R001267_6713_8_2(sec_r001267_8_1, pub_r001267_9_1, sec_r001267_8_2, pub_r001267_9_2);
  int stage_v_0_1 = (sec_r001267_6_1 ^ pub_r001267_22_1) & 63;
  int stage_v_0_2 = (sec_r001267_6_2 ^ pub_r001267_22_2) & 63;
  if ((stage_v_0_1 & 1) != 0)
  {
    if ((sec_r001267_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_0_1 * 2)) & 255;
  }
  if ((stage_v_0_2 & 1) != 0)
  {
    if ((sec_r001267_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_0_2 * 2)) & 255;
  }
  int stage_v_1_1 = ((pub_r001267_14_1 * 2) + 21) & 63;
  int stage_v_1_2 = ((pub_r001267_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001267_19_1 * 2) + 13) & 63;
  int stage_v_2_2 = ((pub_r001267_19_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001267_17_1 * 2) + 26) & 63;
  int stage_v_3_2 = ((pub_r001267_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (helper_flow_7_1 ^ pub_r001267_18_1) & 63;
  int stage_v_4_2 = (helper_flow_7_2 ^ pub_r001267_18_2) & 63;
  if ((stage_v_4_1 & 1) != 0)
  {
    if ((sec_r001267_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_4_1 * 2)) & 255;
  }
  if ((stage_v_4_2 & 1) != 0)
  {
    if ((sec_r001267_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_4_2 * 2)) & 255;
  }
  int stage_v_5_1 = (sec_r001267_6_1 ^ pub_r001267_6_1) & 63;
  int stage_v_5_2 = (sec_r001267_6_2 ^ pub_r001267_6_2) & 63;
  if ((stage_v_5_1 & 1) != 0)
  {
    if ((sec_r001267_22_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_5_1 * 2)) & 255;
  }
  if ((stage_v_5_2 & 1) != 0)
  {
    if ((sec_r001267_22_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_5_2 * 2)) & 255;
  }
  int stage_v_6_1 = (sec_r001267_8_1 ^ pub_r001267_21_1) & 63;
  int stage_v_6_2 = (sec_r001267_8_2 ^ pub_r001267_21_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((sec_r001267_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_6_1 * 2)) & 255;
  }
  if ((stage_v_6_2 & 1) != 0)
  {
    if ((sec_r001267_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_6_2 * 2)) & 255;
  }
  int stage_v_7_1 = (sec_r001267_17_1 ^ pub_r001267_12_1) & 63;
  int stage_v_7_2 = (sec_r001267_17_2 ^ pub_r001267_12_2) & 63;
  if ((stage_v_7_1 & 1) != 0)
  {
    if ((sec_r001267_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_7_1 * 2)) & 255;
  }
  if ((stage_v_7_2 & 1) != 0)
  {
    if ((sec_r001267_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_7_2 * 2)) & 255;
  }
  int stage_v_8_1 = ((pub_r001267_0_1 * 2) + 35) & 63;
  int stage_v_8_2 = ((pub_r001267_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001267_4_1 * 2) + 5) & 63;
  int stage_v_9_2 = ((pub_r001267_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (sec_r001267_10_1 ^ pub_r001267_8_1) & 63;
  int stage_v_10_2 = (sec_r001267_10_2 ^ pub_r001267_8_2) & 63;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((stage_v_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_10_1 * 2)) & 255;
  }
  if ((stage_v_10_2 & 1) != 0)
  {
    if ((stage_v_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_10_2 * 2)) & 255;
  }
  int stage_v_11_1 = ((pub_r001267_21_1 * 2) + 5) & 63;
  int stage_v_11_2 = ((pub_r001267_21_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (stage_v_0_1 ^ pub_r001267_4_1) & 63;
  int stage_v_12_2 = (stage_v_0_2 ^ pub_r001267_4_2) & 63;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((sec_r001267_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_12_1 * 2)) & 255;
  }
  if ((stage_v_12_2 & 1) != 0)
  {
    if ((sec_r001267_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_12_2 * 2)) & 255;
  }
  int stage_v_13_1 = (stage_v_4_1 ^ pub_r001267_6_1) & 63;
  int stage_v_13_2 = (stage_v_4_2 ^ pub_r001267_6_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r001267_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_13_1 * 2)) & 255;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r001267_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_13_2 * 2)) & 255;
  }
  int stage_v_14_1 = (stage_v_0_1 ^ pub_r001267_0_1) & 63;
  int stage_v_14_2 = (stage_v_0_2 ^ pub_r001267_0_2) & 63;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_14_1 * 2)) & 255;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_14_2 * 2)) & 255;
  }
  int stage_v_15_1 = (helper_flow_1_1 ^ pub_r001267_18_1) & 63;
  int stage_v_15_2 = (helper_flow_1_2 ^ pub_r001267_18_2) & 63;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_15_1 * 2)) & 255;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_15_2 * 2)) & 255;
  }
  int stage_v_16_1 = ((pub_r001267_20_1 * 2) + 32) & 63;
  int stage_v_16_2 = ((pub_r001267_20_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (sec_r001267_5_1 ^ pub_r001267_16_1) & 63;
  int stage_v_17_2 = (sec_r001267_5_2 ^ pub_r001267_16_2) & 63;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((stage_v_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_17_1 * 2)) & 255;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((stage_v_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_17_2 * 2)) & 255;
  }
  int stage_v_18_1 = (sec_r001267_18_1 ^ pub_r001267_18_1) & 63;
  int stage_v_18_2 = (sec_r001267_18_2 ^ pub_r001267_18_2) & 63;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_18_1 * 2)) & 255;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_18_2 * 2)) & 255;
  }
  int stage_v_19_1 = ((pub_r001267_1_1 * 2) + 10) & 63;
  int stage_v_19_2 = ((pub_r001267_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (stage_v_10_1 ^ pub_r001267_6_1) & 63;
  int stage_v_20_2 = (stage_v_10_2 ^ pub_r001267_6_2) & 63;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r001267_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_20_1 * 2)) & 255;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r001267_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_20_2 * 2)) & 255;
  }
  int stage_v_21_1 = ((pub_r001267_4_1 * 2) + 39) & 63;
  int stage_v_21_2 = ((pub_r001267_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001267_2_1 * 2) + 14) & 63;
  int stage_v_22_2 = ((pub_r001267_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (helper_flow_3_1 ^ pub_r001267_9_1) & 63;
  int stage_v_23_2 = (helper_flow_3_2 ^ pub_r001267_9_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r001267_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_23_1 * 2)) & 255;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r001267_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_23_2 * 2)) & 255;
  }
  int stage_v_24_1 = ((pub_r001267_14_1 * 2) + 13) & 63;
  int stage_v_24_2 = ((pub_r001267_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (sec_r001267_5_1 ^ pub_r001267_0_1) & 63;
  int stage_v_25_2 = (sec_r001267_5_2 ^ pub_r001267_0_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_25_1 * 2)) & 255;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_25_2 * 2)) & 255;
  }
  int stage_v_26_1 = (sec_r001267_3_1 ^ pub_r001267_18_1) & 63;
  int stage_v_26_2 = (sec_r001267_3_2 ^ pub_r001267_18_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r001267_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_26_1 * 2)) & 255;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r001267_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_26_2 * 2)) & 255;
  }
  int stage_v_27_1 = ((pub_r001267_16_1 * 2) + 30) & 63;
  int stage_v_27_2 = ((pub_r001267_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (sec_r001267_21_1 ^ pub_r001267_23_1) & 63;
  int stage_v_28_2 = (sec_r001267_21_2 ^ pub_r001267_23_2) & 63;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r001267_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_28_1 * 2)) & 255;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r001267_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_28_2 * 2)) & 255;
  }
  int stage_v_29_1 = (stage_v_7_1 ^ pub_r001267_11_1) & 63;
  int stage_v_29_2 = (stage_v_7_2 ^ pub_r001267_11_2) & 63;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((stage_v_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_29_1 * 2)) & 255;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((stage_v_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_29_2 * 2)) & 255;
  }
  int stage_v_30_1 = (helper_flow_8_1 ^ pub_r001267_9_1) & 63;
  int stage_v_30_2 = (helper_flow_8_2 ^ pub_r001267_9_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_30_1 * 2)) & 255;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_30_2 * 2)) & 255;
  }
  int stage_v_31_1 = ((pub_r001267_7_1 * 2) + 21) & 63;
  int stage_v_31_2 = ((pub_r001267_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (sec_r001267_21_1 ^ pub_r001267_22_1) & 63;
  int stage_v_32_2 = (sec_r001267_21_2 ^ pub_r001267_22_2) & 63;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_32_1 * 2)) & 255;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_32_2 * 2)) & 255;
  }
  int stage_v_33_1 = (sec_r001267_8_1 ^ pub_r001267_1_1) & 63;
  int stage_v_33_2 = (sec_r001267_8_2 ^ pub_r001267_1_2) & 63;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_33_1 * 2)) & 255;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_33_2 * 2)) & 255;
  }
  int stage_v_34_1 = ((pub_r001267_22_1 * 2) + 39) & 63;
  int stage_v_34_2 = ((pub_r001267_22_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001267_13_1 * 2) + 46) & 63;
  int stage_v_35_2 = ((pub_r001267_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (sec_r001267_8_1 ^ pub_r001267_17_1) & 63;
  int stage_v_36_2 = (sec_r001267_8_2 ^ pub_r001267_17_2) & 63;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r001267_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_36_1 * 2)) & 255;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r001267_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_36_2 * 2)) & 255;
  }
  int stage_v_37_1 = (sec_r001267_7_1 ^ pub_r001267_10_1) & 63;
  int stage_v_37_2 = (sec_r001267_7_2 ^ pub_r001267_10_2) & 63;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_37_1 * 2)) & 255;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((stage_v_25_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_37_2 * 2)) & 255;
  }
  int stage_v_38_1 = (stage_v_4_1 ^ pub_r001267_11_1) & 63;
  int stage_v_38_2 = (stage_v_4_2 ^ pub_r001267_11_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_38_1 * 2)) & 255;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((stage_v_28_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_38_2 * 2)) & 255;
  }
  int stage_v_39_1 = ((pub_r001267_16_1 * 2) + 35) & 63;
  int stage_v_39_2 = ((pub_r001267_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (helper_flow_3_1 ^ pub_r001267_7_1) & 63;
  int stage_v_40_2 = (helper_flow_3_2 ^ pub_r001267_7_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r001267_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_40_1 * 2)) & 255;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r001267_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_40_2 * 2)) & 255;
  }
  int stage_v_41_1 = (helper_flow_4_1 ^ pub_r001267_15_1) & 63;
  int stage_v_41_2 = (helper_flow_4_2 ^ pub_r001267_15_2) & 63;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_41_1 * 2)) & 255;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_41_2 * 2)) & 255;
  }
  int stage_v_42_1 = (sec_r001267_4_1 ^ pub_r001267_4_1) & 63;
  int stage_v_42_2 = (sec_r001267_4_2 ^ pub_r001267_4_2) & 63;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r001267_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_42_1 * 2)) & 255;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r001267_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_42_2 * 2)) & 255;
  }
  int stage_v_43_1 = (stage_v_38_1 ^ pub_r001267_18_1) & 63;
  int stage_v_43_2 = (stage_v_38_2 ^ pub_r001267_18_2) & 63;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r001267_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_43_1 * 2)) & 255;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r001267_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_43_2 * 2)) & 255;
  }
  int stage_v_44_1 = ((pub_r001267_6_1 * 2) + 29) & 63;
  int stage_v_44_2 = ((pub_r001267_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (stage_v_38_1 ^ pub_r001267_6_1) & 63;
  int stage_v_45_2 = (stage_v_38_2 ^ pub_r001267_6_2) & 63;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_45_1 * 2)) & 255;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_45_2 * 2)) & 255;
  }
  int stage_v_46_1 = (sec_r001267_11_1 ^ pub_r001267_1_1) & 63;
  int stage_v_46_2 = (sec_r001267_11_2 ^ pub_r001267_1_2) & 63;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((stage_v_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_46_1 * 2)) & 255;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((stage_v_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_46_2 * 2)) & 255;
  }
  int stage_v_47_1 = (sec_r001267_3_1 ^ pub_r001267_11_1) & 63;
  int stage_v_47_2 = (sec_r001267_3_2 ^ pub_r001267_11_2) & 63;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_47_1 * 2)) & 255;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_47_2 * 2)) & 255;
  }
  int stage_v_48_1 = ((pub_r001267_12_1 * 2) + 8) & 63;
  int stage_v_48_2 = ((pub_r001267_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001267_12_1 * 2) + 36) & 63;
  int stage_v_49_2 = ((pub_r001267_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (stage_v_15_1 ^ pub_r001267_10_1) & 63;
  int stage_v_50_2 = (stage_v_15_2 ^ pub_r001267_10_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r001267_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_50_1 * 2)) & 255;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r001267_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_50_2 * 2)) & 255;
  }
  int stage_v_51_1 = (stage_v_36_1 ^ pub_r001267_4_1) & 63;
  int stage_v_51_2 = (stage_v_36_2 ^ pub_r001267_4_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_51_1 * 2)) & 255;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_51_2 * 2)) & 255;
  }
  int stage_v_52_1 = ((pub_r001267_12_1 * 2) + 22) & 63;
  int stage_v_52_2 = ((pub_r001267_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001267_20_1 * 2) + 31) & 63;
  int stage_v_53_2 = ((pub_r001267_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (sec_r001267_6_1 ^ pub_r001267_12_1) & 63;
  int stage_v_54_2 = (sec_r001267_6_2 ^ pub_r001267_12_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((stage_v_51_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_54_1 * 2)) & 255;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((stage_v_51_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_54_2 * 2)) & 255;
  }
  int stage_v_55_1 = (sec_r001267_20_1 ^ pub_r001267_8_1) & 63;
  int stage_v_55_2 = (sec_r001267_20_2 ^ pub_r001267_8_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((stage_v_41_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_55_1 * 2)) & 255;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((stage_v_41_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_55_2 * 2)) & 255;
  }
  int stage_v_56_1 = ((pub_r001267_18_1 * 2) + 38) & 63;
  int stage_v_56_2 = ((pub_r001267_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001267_13_1 * 2) + 33) & 63;
  int stage_v_57_2 = ((pub_r001267_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (stage_v_28_1 ^ pub_r001267_3_1) & 63;
  int stage_v_58_2 = (stage_v_28_2 ^ pub_r001267_3_2) & 63;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((stage_v_41_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_58_1 * 2)) & 255;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((stage_v_41_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_58_2 * 2)) & 255;
  }
  int stage_v_59_1 = (stage_v_50_1 ^ pub_r001267_20_1) & 63;
  int stage_v_59_2 = (stage_v_50_2 ^ pub_r001267_20_2) & 63;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_59_1 * 2)) & 255;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((stage_v_38_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_59_2 * 2)) & 255;
  }
  int stage_v_60_1 = (stage_v_43_1 ^ pub_r001267_5_1) & 63;
  int stage_v_60_2 = (stage_v_43_2 ^ pub_r001267_5_2) & 63;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r001267_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r001267_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  }
  int stage_v_61_1 = (sec_r001267_21_1 ^ pub_r001267_17_1) & 63;
  int stage_v_61_2 = (sec_r001267_21_2 ^ pub_r001267_17_2) & 63;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r001267_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r001267_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  }
  int stage_v_62_1 = (sec_r001267_1_1 ^ pub_r001267_8_1) & 63;
  int stage_v_62_2 = (sec_r001267_1_2 ^ pub_r001267_8_2) & 63;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_62_1 * 2)) & 255;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_62_2 * 2)) & 255;
  }
  int stage_v_63_1 = (stage_v_12_1 ^ pub_r001267_19_1) & 63;
  int stage_v_63_2 = (stage_v_12_2 ^ pub_r001267_19_2) & 63;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_63_1 * 2)) & 255;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_63_2 * 2)) & 255;
  }
  int stage_v_64_1 = ((pub_r001267_0_1 * 2) + 42) & 63;
  int stage_v_64_2 = ((pub_r001267_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (stage_v_12_1 ^ pub_r001267_13_1) & 63;
  int stage_v_65_2 = (stage_v_12_2 ^ pub_r001267_13_2) & 63;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((stage_v_46_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_65_1 * 2)) & 255;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((stage_v_46_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_65_2 * 2)) & 255;
  }
  int stage_v_66_1 = ((pub_r001267_2_1 * 2) + 33) & 63;
  int stage_v_66_2 = ((pub_r001267_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (stage_v_12_1 ^ pub_r001267_21_1) & 63;
  int stage_v_67_2 = (stage_v_12_2 ^ pub_r001267_21_2) & 63;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((stage_v_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_67_1 * 2)) & 255;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((stage_v_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_67_2 * 2)) & 255;
  }
  int stage_v_68_1 = (sec_r001267_1_1 ^ pub_r001267_13_1) & 63;
  int stage_v_68_2 = (sec_r001267_1_2 ^ pub_r001267_13_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r001267_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r001267_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  }
  int stage_v_69_1 = ((pub_r001267_19_1 * 2) + 46) & 63;
  int stage_v_69_2 = ((pub_r001267_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (stage_v_23_1 ^ pub_r001267_8_1) & 63;
  int stage_v_70_2 = (stage_v_23_2 ^ pub_r001267_8_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r001267_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r001267_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  }
  int stage_v_71_1 = (helper_flow_3_1 ^ pub_r001267_23_1) & 63;
  int stage_v_71_2 = (helper_flow_3_2 ^ pub_r001267_23_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r001267_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r001267_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  }
  int stage_v_72_1 = (stage_v_46_1 ^ pub_r001267_4_1) & 63;
  int stage_v_72_2 = (stage_v_46_2 ^ pub_r001267_4_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  }
  int stage_v_73_1 = (sec_r001267_15_1 ^ pub_r001267_17_1) & 63;
  int stage_v_73_2 = (sec_r001267_15_2 ^ pub_r001267_17_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r001267_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r001267_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  }
  int stage_v_74_1 = ((pub_r001267_10_1 * 2) + 38) & 63;
  int stage_v_74_2 = ((pub_r001267_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (sec_r001267_14_1 ^ pub_r001267_3_1) & 63;
  int stage_v_75_2 = (sec_r001267_14_2 ^ pub_r001267_3_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r001267_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r001267_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  }
  int stage_v_76_1 = ((pub_r001267_5_1 * 2) + 36) & 63;
  int stage_v_76_2 = ((pub_r001267_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001267_22_1 * 2) + 46) & 63;
  int stage_v_77_2 = ((pub_r001267_22_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001267_9_1 * 2) + 48) & 63;
  int stage_v_78_2 = ((pub_r001267_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001267_19_1 * 2) + 15) & 63;
  int stage_v_79_2 = ((pub_r001267_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (stage_v_40_1 ^ pub_r001267_19_1) & 63;
  int stage_v_80_2 = (stage_v_40_2 ^ pub_r001267_19_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((stage_v_65_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((stage_v_65_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  }
  int stage_v_81_1 = (sec_r001267_6_1 ^ pub_r001267_3_1) & 63;
  int stage_v_81_2 = (sec_r001267_6_2 ^ pub_r001267_3_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  }
  int stage_v_82_1 = (helper_flow_4_1 ^ pub_r001267_3_1) & 63;
  int stage_v_82_2 = (helper_flow_4_2 ^ pub_r001267_3_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r001267_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r001267_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  }
  int stage_v_83_1 = (sec_r001267_4_1 ^ pub_r001267_11_1) & 63;
  int stage_v_83_2 = (sec_r001267_4_2 ^ pub_r001267_11_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((stage_v_65_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((stage_v_65_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  }
  int stage_v_84_1 = (stage_v_41_1 ^ pub_r001267_13_1) & 63;
  int stage_v_84_2 = (stage_v_41_2 ^ pub_r001267_13_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((stage_v_33_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((stage_v_33_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  }
  int stage_v_85_1 = ((pub_r001267_10_1 * 2) + 9) & 63;
  int stage_v_85_2 = ((pub_r001267_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (stage_v_63_1 ^ pub_r001267_22_1) & 63;
  int stage_v_86_2 = (stage_v_63_2 ^ pub_r001267_22_2) & 63;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  }
  int stage_v_87_1 = (stage_v_10_1 ^ pub_r001267_15_1) & 63;
  int stage_v_87_2 = (stage_v_10_2 ^ pub_r001267_15_2) & 63;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r001267_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r001267_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  }
  int stage_v_88_1 = ((pub_r001267_13_1 * 2) + 15) & 63;
  int stage_v_88_2 = ((pub_r001267_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001267_20_1 * 2) + 22) & 63;
  int stage_v_89_2 = ((pub_r001267_20_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (sec_r001267_11_1 ^ pub_r001267_8_1) & 63;
  int stage_v_90_2 = (sec_r001267_11_2 ^ pub_r001267_8_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((stage_v_43_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((stage_v_43_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  }
  int stage_v_91_1 = ((pub_r001267_15_1 * 2) + 41) & 63;
  int stage_v_91_2 = ((pub_r001267_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (stage_v_15_1 ^ pub_r001267_17_1) & 63;
  int stage_v_92_2 = (stage_v_15_2 ^ pub_r001267_17_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((stage_v_73_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((stage_v_73_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  }
  int stage_v_93_1 = ((pub_r001267_5_1 * 2) + 27) & 63;
  int stage_v_93_2 = ((pub_r001267_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001267_3_1 * 2) + 14) & 63;
  int stage_v_94_2 = ((pub_r001267_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (sec_r001267_2_1 ^ pub_r001267_7_1) & 63;
  int stage_v_95_2 = (sec_r001267_2_2 ^ pub_r001267_7_2) & 63;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((stage_v_30_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  }
  int stage_v_96_1 = (stage_v_37_1 ^ pub_r001267_0_1) & 63;
  int stage_v_96_2 = (stage_v_37_2 ^ pub_r001267_0_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((stage_v_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((stage_v_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  }
  int stage_v_97_1 = (sec_r001267_1_1 ^ pub_r001267_4_1) & 63;
  int stage_v_97_2 = (sec_r001267_1_2 ^ pub_r001267_4_2) & 63;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((stage_v_75_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((stage_v_75_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  }
  int stage_v_98_1 = (sec_r001267_17_1 ^ pub_r001267_14_1) & 63;
  int stage_v_98_2 = (sec_r001267_17_2 ^ pub_r001267_14_2) & 63;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((stage_v_63_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((stage_v_63_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  }
  int stage_v_99_1 = ((pub_r001267_2_1 * 2) + 17) & 63;
  int stage_v_99_2 = ((pub_r001267_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (sec_r001267_19_1 ^ pub_r001267_1_1) & 63;
  int stage_v_100_2 = (sec_r001267_19_2 ^ pub_r001267_1_2) & 63;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((stage_v_51_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((stage_v_51_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  }
  int stage_v_101_1 = ((pub_r001267_13_1 * 2) + 47) & 63;
  int stage_v_101_2 = ((pub_r001267_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001267_9_1 * 2) + 32) & 63;
  int stage_v_102_2 = ((pub_r001267_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001267_12_1 * 2) + 22) & 63;
  int stage_v_103_2 = ((pub_r001267_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001267_18_1 * 2) + 7) & 63;
  int stage_v_104_2 = ((pub_r001267_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (stage_v_28_1 ^ pub_r001267_4_1) & 63;
  int stage_v_105_2 = (stage_v_28_2 ^ pub_r001267_4_2) & 63;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((stage_v_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  }
  int stage_v_106_1 = (stage_v_32_1 ^ pub_r001267_2_1) & 63;
  int stage_v_106_2 = (stage_v_32_2 ^ pub_r001267_2_2) & 63;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((stage_v_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((stage_v_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  }
  int stage_v_107_1 = ((pub_r001267_5_1 * 2) + 40) & 63;
  int stage_v_107_2 = ((pub_r001267_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001267_6_1 * 2) + 16) & 63;
  int stage_v_108_2 = ((pub_r001267_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (sec_r001267_8_1 ^ pub_r001267_20_1) & 63;
  int stage_v_109_2 = (sec_r001267_8_2 ^ pub_r001267_20_2) & 63;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((stage_v_65_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((stage_v_65_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  }
  int stage_v_110_1 = (stage_v_54_1 ^ pub_r001267_17_1) & 63;
  int stage_v_110_2 = (stage_v_54_2 ^ pub_r001267_17_2) & 63;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r001267_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r001267_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  }
  int stage_v_111_1 = (sec_r001267_6_1 ^ pub_r001267_14_1) & 63;
  int stage_v_111_2 = (sec_r001267_6_2 ^ pub_r001267_14_2) & 63;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((stage_v_105_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((stage_v_105_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  }
  int stage_v_112_1 = (sec_r001267_13_1 ^ pub_r001267_18_1) & 63;
  int stage_v_112_2 = (sec_r001267_13_2 ^ pub_r001267_18_2) & 63;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((stage_v_90_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((stage_v_90_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  }
  int stage_v_113_1 = ((pub_r001267_17_1 * 2) + 49) & 63;
  int stage_v_113_2 = ((pub_r001267_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001267_21_1 * 2) + 49) & 63;
  int stage_v_114_2 = ((pub_r001267_21_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001267_1_1 * 2) + 47) & 63;
  int stage_v_115_2 = ((pub_r001267_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (stage_v_68_1 ^ pub_r001267_0_1) & 63;
  int stage_v_116_2 = (stage_v_68_2 ^ pub_r001267_0_2) & 63;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((stage_v_98_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((stage_v_98_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  }
  int stage_v_117_1 = ((pub_r001267_23_1 * 2) + 5) & 63;
  int stage_v_117_2 = ((pub_r001267_23_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (stage_v_28_1 ^ pub_r001267_12_1) & 63;
  int stage_v_118_2 = (stage_v_28_2 ^ pub_r001267_12_2) & 63;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r001267_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r001267_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  }
  int stage_v_119_1 = ((pub_r001267_22_1 * 2) + 5) & 63;
  int stage_v_119_2 = ((pub_r001267_22_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001267_13_1 * 2) + 43) & 63;
  int stage_v_120_2 = ((pub_r001267_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001267_0_1 * 2) + 26) & 63;
  int stage_v_121_2 = ((pub_r001267_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (stage_v_84_1 ^ pub_r001267_4_1) & 63;
  int stage_v_122_2 = (stage_v_84_2 ^ pub_r001267_4_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  }
  int stage_v_123_1 = (stage_v_118_1 ^ pub_r001267_9_1) & 63;
  int stage_v_123_2 = (stage_v_118_2 ^ pub_r001267_9_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((stage_v_90_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((stage_v_90_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  }
  int stage_v_124_1 = (stage_v_26_1 ^ pub_r001267_5_1) & 63;
  int stage_v_124_2 = (stage_v_26_2 ^ pub_r001267_5_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r001267_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r001267_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  }
  int stage_v_125_1 = (stage_v_13_1 ^ pub_r001267_17_1) & 63;
  int stage_v_125_2 = (stage_v_13_2 ^ pub_r001267_17_2) & 63;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((stage_v_29_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((stage_v_29_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  }
  int stage_v_126_1 = ((pub_r001267_17_1 * 2) + 34) & 63;
  int stage_v_126_2 = ((pub_r001267_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (helper_flow_6_1 ^ pub_r001267_22_1) & 63;
  int stage_v_127_2 = (helper_flow_6_2 ^ pub_r001267_22_2) & 63;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((stage_v_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  }
  int stage_v_128_1 = ((pub_r001267_1_1 * 2) + 14) & 63;
  int stage_v_128_2 = ((pub_r001267_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (helper_flow_6_1 ^ pub_r001267_12_1) & 63;
  int stage_v_129_2 = (helper_flow_6_2 ^ pub_r001267_12_2) & 63;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  }
  if ((stage_v_129_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  }
  int stage_v_130_1 = (sec_r001267_10_1 ^ pub_r001267_18_1) & 63;
  int stage_v_130_2 = (sec_r001267_10_2 ^ pub_r001267_18_2) & 63;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((stage_v_116_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((stage_v_116_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  }
  int stage_v_131_1 = ((pub_r001267_3_1 * 2) + 43) & 63;
  int stage_v_131_2 = ((pub_r001267_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001267_0_1 * 2) + 49) & 63;
  int stage_v_132_2 = ((pub_r001267_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (stage_v_118_1 ^ pub_r001267_22_1) & 63;
  int stage_v_133_2 = (stage_v_118_2 ^ pub_r001267_22_2) & 63;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((stage_v_62_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((stage_v_62_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  }
  int stage_v_134_1 = ((pub_r001267_3_1 * 2) + 39) & 63;
  int stage_v_134_2 = ((pub_r001267_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (stage_v_125_1 ^ pub_r001267_2_1) & 63;
  int stage_v_135_2 = (stage_v_125_2 ^ pub_r001267_2_2) & 63;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  }
  if ((stage_v_135_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  }
  int stage_v_136_1 = ((pub_r001267_18_1 * 2) + 7) & 63;
  int stage_v_136_2 = ((pub_r001267_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (stage_v_23_1 ^ pub_r001267_7_1) & 63;
  int stage_v_137_2 = (stage_v_23_2 ^ pub_r001267_7_2) & 63;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((sec_r001267_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  }
  if ((stage_v_137_2 & 1) != 0)
  {
    if ((sec_r001267_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  }
  int stage_v_138_1 = ((pub_r001267_22_1 * 2) + 7) & 63;
  int stage_v_138_2 = ((pub_r001267_22_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001267_5_1 * 2) + 7) & 63;
  int stage_v_139_2 = ((pub_r001267_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (stage_v_41_1 ^ pub_r001267_4_1) & 63;
  int stage_v_140_2 = (stage_v_41_2 ^ pub_r001267_4_2) & 63;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((sec_r001267_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((sec_r001267_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  }
  int stage_v_141_1 = (stage_v_140_1 ^ pub_r001267_1_1) & 63;
  int stage_v_141_2 = (stage_v_140_2 ^ pub_r001267_1_2) & 63;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((stage_v_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  }
  if ((stage_v_141_2 & 1) != 0)
  {
    if ((stage_v_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  }
  int stage_v_142_1 = (stage_v_36_1 ^ pub_r001267_20_1) & 63;
  int stage_v_142_2 = (stage_v_36_2 ^ pub_r001267_20_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  }
  if ((stage_v_142_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  }
  int stage_v_143_1 = (stage_v_111_1 ^ pub_r001267_7_1) & 63;
  int stage_v_143_2 = (stage_v_111_2 ^ pub_r001267_7_2) & 63;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((sec_r001267_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  }
  if ((stage_v_143_2 & 1) != 0)
  {
    if ((sec_r001267_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  }
  int stage_v_144_1 = (stage_v_15_1 ^ pub_r001267_11_1) & 63;
  int stage_v_144_2 = (stage_v_15_2 ^ pub_r001267_11_2) & 63;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((stage_v_41_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  }
  if ((stage_v_144_2 & 1) != 0)
  {
    if ((stage_v_41_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  }
  int stage_v_145_1 = ((pub_r001267_11_1 * 2) + 8) & 63;
  int stage_v_145_2 = ((pub_r001267_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (stage_v_17_1 ^ pub_r001267_13_1) & 63;
  int stage_v_146_2 = (stage_v_17_2 ^ pub_r001267_13_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((sec_r001267_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  }
  if ((stage_v_146_2 & 1) != 0)
  {
    if ((sec_r001267_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  }
  int stage_v_147_1 = (stage_v_23_1 ^ pub_r001267_3_1) & 63;
  int stage_v_147_2 = (stage_v_23_2 ^ pub_r001267_3_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((stage_v_98_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  }
  if ((stage_v_147_2 & 1) != 0)
  {
    if ((stage_v_98_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  }
  int stage_v_148_1 = (stage_v_58_1 ^ pub_r001267_21_1) & 63;
  int stage_v_148_2 = (stage_v_58_2 ^ pub_r001267_21_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((stage_v_71_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  }
  if ((stage_v_148_2 & 1) != 0)
  {
    if ((stage_v_71_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  }
  int stage_v_149_1 = ((pub_r001267_5_1 * 2) + 38) & 63;
  int stage_v_149_2 = ((pub_r001267_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (stage_v_143_1 ^ pub_r001267_6_1) & 63;
  int stage_v_150_2 = (stage_v_143_2 ^ pub_r001267_6_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  }
  int stage_v_151_1 = ((pub_r001267_20_1 * 2) + 18) & 63;
  int stage_v_151_2 = ((pub_r001267_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (stage_v_72_1 ^ pub_r001267_14_1) & 63;
  int stage_v_152_2 = (stage_v_72_2 ^ pub_r001267_14_2) & 63;
  if ((stage_v_152_1 & 1) != 0)
  {
    if ((sec_r001267_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  }
  if ((stage_v_152_2 & 1) != 0)
  {
    if ((sec_r001267_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  }
  int stage_v_153_1 = (stage_v_80_1 ^ pub_r001267_9_1) & 63;
  int stage_v_153_2 = (stage_v_80_2 ^ pub_r001267_9_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((sec_r001267_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  }
  if ((stage_v_153_2 & 1) != 0)
  {
    if ((sec_r001267_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  }
  int stage_v_154_1 = (stage_v_86_1 ^ pub_r001267_22_1) & 63;
  int stage_v_154_2 = (stage_v_86_2 ^ pub_r001267_22_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  }
  if ((stage_v_154_2 & 1) != 0)
  {
    if ((stage_v_80_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  }
  int stage_v_155_1 = (stage_v_73_1 ^ pub_r001267_13_1) & 63;
  int stage_v_155_2 = (stage_v_73_2 ^ pub_r001267_13_2) & 63;
  if ((stage_v_155_1 & 1) != 0)
  {
    if ((sec_r001267_22_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  }
  if ((stage_v_155_2 & 1) != 0)
  {
    if ((sec_r001267_22_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  }
  int stage_v_156_1 = (stage_v_45_1 ^ pub_r001267_14_1) & 63;
  int stage_v_156_2 = (stage_v_45_2 ^ pub_r001267_14_2) & 63;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((stage_v_37_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  }
  if ((stage_v_156_2 & 1) != 0)
  {
    if ((stage_v_37_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  }
  int stage_v_157_1 = (stage_v_58_1 ^ pub_r001267_15_1) & 63;
  int stage_v_157_2 = (stage_v_58_2 ^ pub_r001267_15_2) & 63;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((stage_v_118_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  }
  if ((stage_v_157_2 & 1) != 0)
  {
    if ((stage_v_118_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  }
  int stage_v_158_1 = (stage_v_54_1 ^ pub_r001267_8_1) & 63;
  int stage_v_158_2 = (stage_v_54_2 ^ pub_r001267_8_2) & 63;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((stage_v_153_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  }
  if ((stage_v_158_2 & 1) != 0)
  {
    if ((stage_v_153_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  }
  int stage_v_159_1 = (stage_v_137_1 ^ pub_r001267_7_1) & 63;
  int stage_v_159_2 = (stage_v_137_2 ^ pub_r001267_7_2) & 63;
  if ((stage_v_159_1 & 1) != 0)
  {
    if ((stage_v_54_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_159_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  }
  if ((stage_v_159_2 & 1) != 0)
  {
    if ((stage_v_54_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_159_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  }
  int stage_v_160_1 = (stage_v_70_1 ^ pub_r001267_5_1) & 63;
  int stage_v_160_2 = (stage_v_70_2 ^ pub_r001267_5_2) & 63;
  if ((stage_v_160_1 & 1) != 0)
  {
    if ((stage_v_124_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_160_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  }
  if ((stage_v_160_2 & 1) != 0)
  {
    if ((stage_v_124_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_160_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  }
  int stage_v_161_1 = (stage_v_141_1 ^ pub_r001267_22_1) & 63;
  int stage_v_161_2 = (stage_v_141_2 ^ pub_r001267_22_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((stage_v_82_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  }
  if ((stage_v_161_2 & 1) != 0)
  {
    if ((stage_v_82_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  }
  int stage_v_162_1 = (stage_v_40_1 ^ pub_r001267_18_1) & 63;
  int stage_v_162_2 = (stage_v_40_2 ^ pub_r001267_18_2) & 63;
  if ((stage_v_162_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  }
  if ((stage_v_162_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  }
  int stage_v_163_1 = ((pub_r001267_20_1 * 2) + 35) & 63;
  int stage_v_163_2 = ((pub_r001267_20_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (stage_v_73_1 ^ pub_r001267_16_1) & 63;
  int stage_v_164_2 = (stage_v_73_2 ^ pub_r001267_16_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((stage_v_152_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  }
  if ((stage_v_164_2 & 1) != 0)
  {
    if ((stage_v_152_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  }
  int stage_v_165_1 = ((pub_r001267_13_1 * 2) + 33) & 63;
  int stage_v_165_2 = ((pub_r001267_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001267_9_1 * 2) + 15) & 63;
  int stage_v_166_2 = ((pub_r001267_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001267_19_1 * 2) + 44) & 63;
  int stage_v_167_2 = ((pub_r001267_19_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001267_12_1 * 2) + 11) & 63;
  int stage_v_168_2 = ((pub_r001267_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (stage_v_96_1 ^ pub_r001267_21_1) & 63;
  int stage_v_169_2 = (stage_v_96_2 ^ pub_r001267_21_2) & 63;
  if ((stage_v_169_1 & 1) != 0)
  {
    if ((stage_v_43_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  }
  if ((stage_v_169_2 & 1) != 0)
  {
    if ((stage_v_43_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  }
  int stage_v_170_1 = ((pub_r001267_12_1 * 2) + 13) & 63;
  int stage_v_170_2 = ((pub_r001267_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (stage_v_51_1 ^ pub_r001267_9_1) & 63;
  int stage_v_171_2 = (stage_v_51_2 ^ pub_r001267_9_2) & 63;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((stage_v_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_171_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  }
  if ((stage_v_171_2 & 1) != 0)
  {
    if ((stage_v_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_171_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  }
  int stage_v_172_1 = ((pub_r001267_2_1 * 2) + 7) & 63;
  int stage_v_172_2 = ((pub_r001267_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001267_10_1 * 2) + 7) & 63;
  int stage_v_173_2 = ((pub_r001267_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (stage_v_50_1 ^ pub_r001267_6_1) & 63;
  int stage_v_174_2 = (stage_v_50_2 ^ pub_r001267_6_2) & 63;
  if ((stage_v_174_1 & 1) != 0)
  {
    if ((sec_r001267_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_174_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  }
  if ((stage_v_174_2 & 1) != 0)
  {
    if ((sec_r001267_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_174_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  }
  int stage_v_175_1 = (helper_flow_5_1 ^ pub_r001267_4_1) & 63;
  int stage_v_175_2 = (helper_flow_5_2 ^ pub_r001267_4_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((stage_v_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_175_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  }
  if ((stage_v_175_2 & 1) != 0)
  {
    if ((stage_v_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_175_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  }
  int stage_v_176_1 = (sec_r001267_19_1 ^ pub_r001267_17_1) & 63;
  int stage_v_176_2 = (sec_r001267_19_2 ^ pub_r001267_17_2) & 63;
  if ((stage_v_176_1 & 1) != 0)
  {
    if ((sec_r001267_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  }
  if ((stage_v_176_2 & 1) != 0)
  {
    if ((sec_r001267_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  }
  int stage_v_177_1 = (stage_v_37_1 ^ pub_r001267_16_1) & 63;
  int stage_v_177_2 = (stage_v_37_2 ^ pub_r001267_16_2) & 63;
  if ((stage_v_177_1 & 1) != 0)
  {
    if ((sec_r001267_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_177_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  }
  if ((stage_v_177_2 & 1) != 0)
  {
    if ((sec_r001267_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_177_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  }
  int stage_v_178_1 = (stage_v_141_1 ^ pub_r001267_11_1) & 63;
  int stage_v_178_2 = (stage_v_141_2 ^ pub_r001267_11_2) & 63;
  if ((stage_v_178_1 & 1) != 0)
  {
    if ((stage_v_84_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_178_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  }
  if ((stage_v_178_2 & 1) != 0)
  {
    if ((stage_v_84_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_178_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  }
  int stage_v_179_1 = ((pub_r001267_12_1 * 2) + 27) & 63;
  int stage_v_179_2 = ((pub_r001267_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001267_23_1 * 2) + 48) & 63;
  int stage_v_180_2 = ((pub_r001267_23_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001267_17_1 * 2) + 50) & 63;
  int stage_v_181_2 = ((pub_r001267_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (stage_v_84_1 ^ pub_r001267_13_1) & 63;
  int stage_v_182_2 = (stage_v_84_2 ^ pub_r001267_13_2) & 63;
  if ((stage_v_182_1 & 1) != 0)
  {
    if ((stage_v_116_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_182_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  }
  if ((stage_v_182_2 & 1) != 0)
  {
    if ((stage_v_116_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_182_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  }
  int stage_v_183_1 = (stage_v_177_1 ^ pub_r001267_10_1) & 63;
  int stage_v_183_2 = (stage_v_177_2 ^ pub_r001267_10_2) & 63;
  if ((stage_v_183_1 & 1) != 0)
  {
    if ((stage_v_162_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_183_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  }
  if ((stage_v_183_2 & 1) != 0)
  {
    if ((stage_v_162_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_183_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  }
  int stage_v_184_1 = ((pub_r001267_10_1 * 2) + 15) & 63;
  int stage_v_184_2 = ((pub_r001267_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (stage_v_175_1 ^ pub_r001267_17_1) & 63;
  int stage_v_185_2 = (stage_v_175_2 ^ pub_r001267_17_2) & 63;
  if ((stage_v_185_1 & 1) != 0)
  {
    if ((sec_r001267_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_185_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  }
  if ((stage_v_185_2 & 1) != 0)
  {
    if ((sec_r001267_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_185_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  }
  int stage_v_186_1 = (stage_v_73_1 ^ pub_r001267_5_1) & 63;
  int stage_v_186_2 = (stage_v_73_2 ^ pub_r001267_5_2) & 63;
  if ((stage_v_186_1 & 1) != 0)
  {
    if ((sec_r001267_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_186_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  }
  if ((stage_v_186_2 & 1) != 0)
  {
    if ((sec_r001267_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_186_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  }
  int stage_v_187_1 = (stage_v_60_1 ^ pub_r001267_9_1) & 63;
  int stage_v_187_2 = (stage_v_60_2 ^ pub_r001267_9_2) & 63;
  if ((stage_v_187_1 & 1) != 0)
  {
    if ((stage_v_123_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_187_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  }
  if ((stage_v_187_2 & 1) != 0)
  {
    if ((stage_v_123_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_187_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  }
  int stage_v_188_1 = (stage_v_144_1 ^ pub_r001267_7_1) & 63;
  int stage_v_188_2 = (stage_v_144_2 ^ pub_r001267_7_2) & 63;
  if ((stage_v_188_1 & 1) != 0)
  {
    if ((stage_v_106_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_188_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  }
  if ((stage_v_188_2 & 1) != 0)
  {
    if ((stage_v_106_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_188_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  }
  int stage_v_189_1 = ((pub_r001267_3_1 * 2) + 9) & 63;
  int stage_v_189_2 = ((pub_r001267_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001267_6_1 * 2) + 20) & 63;
  int stage_v_190_2 = ((pub_r001267_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (stage_v_15_1 ^ pub_r001267_0_1) & 63;
  int stage_v_191_2 = (stage_v_15_2 ^ pub_r001267_0_2) & 63;
  if ((stage_v_191_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_191_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  }
  if ((stage_v_191_2 & 1) != 0)
  {
    if ((stage_v_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_191_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  }
  int stage_v_192_1 = ((pub_r001267_22_1 * 2) + 44) & 63;
  int stage_v_192_2 = ((pub_r001267_22_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001267_8_1 * 2) + 6) & 63;
  int stage_v_193_2 = ((pub_r001267_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (stage_v_98_1 ^ pub_r001267_13_1) & 63;
  int stage_v_194_2 = (stage_v_98_2 ^ pub_r001267_13_2) & 63;
  if ((stage_v_194_1 & 1) != 0)
  {
    if ((stage_v_112_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_194_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  }
  if ((stage_v_194_2 & 1) != 0)
  {
    if ((stage_v_112_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_194_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  }
  int stage_v_195_1 = (helper_flow_8_1 ^ pub_r001267_2_1) & 63;
  int stage_v_195_2 = (helper_flow_8_2 ^ pub_r001267_2_2) & 63;
  if ((stage_v_195_1 & 1) != 0)
  {
    if ((stage_v_164_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_195_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  }
  if ((stage_v_195_2 & 1) != 0)
  {
    if ((stage_v_164_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_195_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  }
  int stage_v_196_1 = (sec_r001267_15_1 ^ pub_r001267_23_1) & 63;
  int stage_v_196_2 = (sec_r001267_15_2 ^ pub_r001267_23_2) & 63;
  if ((stage_v_196_1 & 1) != 0)
  {
    if ((stage_v_110_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_196_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  }
  if ((stage_v_196_2 & 1) != 0)
  {
    if ((stage_v_110_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_196_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  }
  int stage_v_197_1 = (stage_v_6_1 ^ pub_r001267_14_1) & 63;
  int stage_v_197_2 = (stage_v_6_2 ^ pub_r001267_14_2) & 63;
  if ((stage_v_197_1 & 1) != 0)
  {
    if ((stage_v_183_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_197_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  }
  if ((stage_v_197_2 & 1) != 0)
  {
    if ((stage_v_183_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_197_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  }
  int stage_v_198_1 = (stage_v_157_1 ^ pub_r001267_20_1) & 63;
  int stage_v_198_2 = (stage_v_157_2 ^ pub_r001267_20_2) & 63;
  if ((stage_v_198_1 & 1) != 0)
  {
    if ((sec_r001267_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_198_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  }
  if ((stage_v_198_2 & 1) != 0)
  {
    if ((sec_r001267_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_198_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  }
  int stage_v_199_1 = (stage_v_41_1 ^ pub_r001267_2_1) & 63;
  int stage_v_199_2 = (stage_v_41_2 ^ pub_r001267_2_2) & 63;
  if ((stage_v_199_1 & 1) != 0)
  {
    if ((stage_v_81_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_199_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  }
  if ((stage_v_199_2 & 1) != 0)
  {
    if ((stage_v_81_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_199_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  }
  int stage_v_200_1 = (stage_v_10_1 ^ pub_r001267_0_1) & 63;
  int stage_v_200_2 = (stage_v_10_2 ^ pub_r001267_0_2) & 63;
  if ((stage_v_200_1 & 1) != 0)
  {
    if ((stage_v_195_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_200_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  }
  if ((stage_v_200_2 & 1) != 0)
  {
    if ((stage_v_195_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_200_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  }
  int stage_v_201_1 = (helper_flow_3_1 ^ pub_r001267_10_1) & 63;
  int stage_v_201_2 = (helper_flow_3_2 ^ pub_r001267_10_2) & 63;
  if ((stage_v_201_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_201_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  }
  if ((stage_v_201_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_201_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  }
  int stage_v_202_1 = (stage_v_58_1 ^ pub_r001267_8_1) & 63;
  int stage_v_202_2 = (stage_v_58_2 ^ pub_r001267_8_2) & 63;
  if ((stage_v_202_1 & 1) != 0)
  {
    if ((stage_v_45_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_202_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  }
  if ((stage_v_202_2 & 1) != 0)
  {
    if ((stage_v_45_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_202_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  }
  int stage_v_203_1 = (stage_v_6_1 ^ pub_r001267_17_1) & 63;
  int stage_v_203_2 = (stage_v_6_2 ^ pub_r001267_17_2) & 63;
  if ((stage_v_203_1 & 1) != 0)
  {
    if ((sec_r001267_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_203_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  }
  if ((stage_v_203_2 & 1) != 0)
  {
    if ((sec_r001267_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_203_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  }
  int stage_v_204_1 = (stage_v_186_1 ^ pub_r001267_8_1) & 63;
  int stage_v_204_2 = (stage_v_186_2 ^ pub_r001267_8_2) & 63;
  if ((stage_v_204_1 & 1) != 0)
  {
    if ((sec_r001267_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_204_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  }
  if ((stage_v_204_2 & 1) != 0)
  {
    if ((sec_r001267_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_204_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  }
  int stage_v_205_1 = (stage_v_153_1 ^ pub_r001267_12_1) & 63;
  int stage_v_205_2 = (stage_v_153_2 ^ pub_r001267_12_2) & 63;
  if ((stage_v_205_1 & 1) != 0)
  {
    if ((stage_v_124_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_205_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  }
  if ((stage_v_205_2 & 1) != 0)
  {
    if ((stage_v_124_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_205_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  }
  int stage_v_206_1 = ((pub_r001267_14_1 * 2) + 5) & 63;
  int stage_v_206_2 = ((pub_r001267_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (stage_v_176_1 ^ pub_r001267_11_1) & 63;
  int stage_v_207_2 = (stage_v_176_2 ^ pub_r001267_11_2) & 63;
  if ((stage_v_207_1 & 1) != 0)
  {
    if ((stage_v_191_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_207_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  }
  if ((stage_v_207_2 & 1) != 0)
  {
    if ((stage_v_191_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_207_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  }
  int stage_v_208_1 = (helper_flow_0_1 ^ pub_r001267_20_1) & 63;
  int stage_v_208_2 = (helper_flow_0_2 ^ pub_r001267_20_2) & 63;
  if ((stage_v_208_1 & 1) != 0)
  {
    if ((stage_v_59_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_208_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  }
  if ((stage_v_208_2 & 1) != 0)
  {
    if ((stage_v_59_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_208_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  }
  int stage_v_209_1 = (stage_v_154_1 ^ pub_r001267_8_1) & 63;
  int stage_v_209_2 = (stage_v_154_2 ^ pub_r001267_8_2) & 63;
  if ((stage_v_209_1 & 1) != 0)
  {
    if ((stage_v_147_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_209_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  }
  if ((stage_v_209_2 & 1) != 0)
  {
    if ((stage_v_147_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_209_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  }
  int stage_v_210_1 = ((pub_r001267_18_1 * 2) + 44) & 63;
  int stage_v_210_2 = ((pub_r001267_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (stage_v_106_1 ^ pub_r001267_0_1) & 63;
  int stage_v_211_2 = (stage_v_106_2 ^ pub_r001267_0_2) & 63;
  if ((stage_v_211_1 & 1) != 0)
  {
    if ((stage_v_36_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_211_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  }
  if ((stage_v_211_2 & 1) != 0)
  {
    if ((stage_v_36_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_211_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  }
  int stage_v_212_1 = (stage_v_55_1 ^ pub_r001267_23_1) & 63;
  int stage_v_212_2 = (stage_v_55_2 ^ pub_r001267_23_2) & 63;
  if ((stage_v_212_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_212_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  }
  if ((stage_v_212_2 & 1) != 0)
  {
    if ((helper_flow_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_212_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  }
  int stage_v_213_1 = (sec_r001267_10_1 ^ pub_r001267_20_1) & 63;
  int stage_v_213_2 = (sec_r001267_10_2 ^ pub_r001267_20_2) & 63;
  if ((stage_v_213_1 & 1) != 0)
  {
    if ((stage_v_158_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_213_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_213_1 * 2)) & 255;
  }
  if ((stage_v_213_2 & 1) != 0)
  {
    if ((stage_v_158_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_213_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_213_2 * 2)) & 255;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001267_14_1 != sec_r001267_14_2);
  __CPROVER_assume(sec_r001267_10_1 != sec_r001267_10_2);
  __CPROVER_assume(pub_r001267_12_1 == pub_r001267_12_2);
  __CPROVER_assume(sec_r001267_13_1 != sec_r001267_13_2);
  __CPROVER_assume(pub_r001267_4_1 == pub_r001267_4_2);
  __CPROVER_assume(pub_r001267_23_1 == pub_r001267_23_2);
  __CPROVER_assume(sec_r001267_7_1 != sec_r001267_7_2);
  __CPROVER_assume(pub_r001267_1_1 == pub_r001267_1_2);
  __CPROVER_assume(sec_r001267_1_1 != sec_r001267_1_2);
  __CPROVER_assume(pub_r001267_21_1 == pub_r001267_21_2);
  __CPROVER_assume(pub_r001267_2_1 == pub_r001267_2_2);
  __CPROVER_assume(pub_r001267_22_1 == pub_r001267_22_2);
  __CPROVER_assume(pub_r001267_15_1 == pub_r001267_15_2);
  __CPROVER_assume(sec_r001267_16_1 != sec_r001267_16_2);
  __CPROVER_assume(sec_r001267_2_1 != sec_r001267_2_2);
  __CPROVER_assume(pub_r001267_3_1 == pub_r001267_3_2);
  __CPROVER_assume(pub_r001267_20_1 == pub_r001267_20_2);
  __CPROVER_assume(sec_r001267_12_1 != sec_r001267_12_2);
  __CPROVER_assume(sec_r001267_18_1 != sec_r001267_18_2);
  __CPROVER_assume(pub_r001267_8_1 == pub_r001267_8_2);
  __CPROVER_assume(pub_r001267_7_1 == pub_r001267_7_2);
  __CPROVER_assume(pub_r001267_14_1 == pub_r001267_14_2);
  __CPROVER_assume(sec_r001267_5_1 != sec_r001267_5_2);
  __CPROVER_assume(sec_r001267_8_1 != sec_r001267_8_2);
  __CPROVER_assume(sec_r001267_21_1 != sec_r001267_21_2);
  __CPROVER_assume(sec_r001267_6_1 != sec_r001267_6_2);
  __CPROVER_assume(sec_r001267_11_1 != sec_r001267_11_2);
  __CPROVER_assume(pub_r001267_6_1 == pub_r001267_6_2);
  __CPROVER_assume(sec_r001267_0_1 != sec_r001267_0_2);
  __CPROVER_assume(sec_r001267_15_1 != sec_r001267_15_2);
  __CPROVER_assume(pub_r001267_19_1 == pub_r001267_19_2);
  __CPROVER_assume(sec_r001267_19_1 != sec_r001267_19_2);
  __CPROVER_assume(sec_r001267_4_1 != sec_r001267_4_2);
  __CPROVER_assume(pub_r001267_10_1 == pub_r001267_10_2);
  __CPROVER_assume(sec_r001267_20_1 != sec_r001267_20_2);
  __CPROVER_assume(pub_r001267_9_1 == pub_r001267_9_2);
  __CPROVER_assume(pub_r001267_17_1 == pub_r001267_17_2);
  __CPROVER_assume(sec_r001267_22_1 != sec_r001267_22_2);
  __CPROVER_assume(pub_r001267_18_1 == pub_r001267_18_2);
  __CPROVER_assume(pub_r001267_0_1 == pub_r001267_0_2);
  __CPROVER_assume(sec_r001267_17_1 != sec_r001267_17_2);
  __CPROVER_assume(pub_r001267_11_1 == pub_r001267_11_2);
  __CPROVER_assume(pub_r001267_13_1 == pub_r001267_13_2);
  __CPROVER_assume(pub_r001267_16_1 == pub_r001267_16_2);
  __CPROVER_assume(sec_r001267_3_1 != sec_r001267_3_2);
  __CPROVER_assume(pub_r001267_5_1 == pub_r001267_5_2);
  __CPROVER_assume(sec_r001267_9_1 != sec_r001267_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.port == st_var_1_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.heading == st_var_2_2.heading);
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
}


