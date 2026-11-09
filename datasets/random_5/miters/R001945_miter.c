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
struct Vector3D_R001945_4513_0
{
  short pitch;
  int coord_x;
  int coord_z;
  int buffer[3];
};
struct MatrixBlock_R001945_4513_1
{
  unsigned char density;
  int dim;
  short trace;
  unsigned char determinant;
  int buffer[3];
};
union RegisterBank_R001945_4513_0
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
void fn_R001945_4513_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001945_4513_1 st_1 = {0};
  struct MatrixBlock_R001945_4513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int anchor_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_41_1)
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

  switch (anchor_41_2)
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
  int metric_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_12_1 > 28)
  {
    acc_1 = ((acc_1 + (metric_12_1 * 2)) + 5) & 127;
    aux_1 ^= metric_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_12_2 > 28)
  {
    acc_2 = ((acc_2 + (metric_12_2 * 2)) + 5) & 127;
    aux_2 ^= metric_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_79_1) & 63;
  aux_2 = (aux_2 + offset_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_41_1 == anchor_41_2);
  assert(metric_12_1 == metric_12_2);
  assert(offset_79_1 == offset_79_2);
}

int fn_R001945_4513_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001945_4513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int anchor_41 = (aux + st.buffer[1]) & 3;
  switch (anchor_41)
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
  int metric_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_12 > 28)
  {
    acc = ((acc + (metric_12 * 2)) + 5) & 127;
    aux ^= metric_12 & 15;
  }
  else
  {
    acc = ((acc - metric_12) + 11) & 127;
    aux += 3;
  }
  int offset_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_79) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001945_4513_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st_1 = {0};
  struct Vector3D_R001945_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int factor_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_47_1 > 42)
  {
    acc_1 = ((acc_1 + (factor_47_1 * 2)) + 5) & 127;
    aux_1 ^= factor_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_47_2 > 42)
  {
    acc_2 = ((acc_2 + (factor_47_2 * 2)) + 5) & 127;
    aux_2 ^= factor_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_29_1 = 0;
  int damping_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_29_1 = ((damping_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_29_2 = ((damping_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_29_1) & 127;
    acc_2 = (acc_2 + damping_29_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_42_1 = local_arr_1[aux_1 % 3];
  int anchor_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_42_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_47_1 == factor_47_2);
  assert(damping_29_1 == damping_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_42_1 == anchor_42_2);
}

int fn_R001945_4513_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int factor_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_47 > 42)
  {
    acc = ((acc + (factor_47 * 2)) + 5) & 127;
    aux ^= factor_47 & 15;
  }
  else
  {
    acc = ((acc - factor_47) + 11) & 127;
    aux += 3;
  }
  int damping_29 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_29 = ((damping_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_29) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_42 = local_arr[aux % 3];
  acc = (acc + (anchor_42 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001945_4513_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st_1 = {0};
  struct Vector3D_R001945_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int margin_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_77_1 > 43)
  {
    acc_1 = ((acc_1 + (margin_77_1 * 2)) + 5) & 127;
    aux_1 ^= margin_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_77_2 > 43)
  {
    acc_2 = ((acc_2 + (margin_77_2 * 2)) + 5) & 127;
    aux_2 ^= margin_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_80_1) & 63;
  aux_2 = (aux_2 + metric_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_53_1 = local_arr_1[aux_1 % 3];
  int anchor_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_53_2 * 2)) & 127;
  int parity_15_1 = 0;
  int parity_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_15_1 = ((parity_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_15_2 = ((parity_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_15_1) & 127;
    acc_2 = (acc_2 + parity_15_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_77_1 == margin_77_2);
  assert(metric_80_1 == metric_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_53_1 == anchor_53_2);
  assert(parity_15_1 == parity_15_2);
}

int fn_R001945_4513_2(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int margin_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_77 > 43)
  {
    acc = ((acc + (margin_77 * 2)) + 5) & 127;
    aux ^= margin_77 & 15;
  }
  else
  {
    acc = ((acc - margin_77) + 11) & 127;
    aux += 3;
  }
  int metric_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_80) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_53 = local_arr[aux % 3];
  acc = (acc + (anchor_53 * 2)) & 127;
  int parity_15 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_15 = ((parity_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_15) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001945_4513_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st_1 = {0};
  struct Vector3D_R001945_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int phase_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_21_1) & 63;
  aux_2 = (aux_2 + phase_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_70_1 = 0;
  int stride_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_70_1 = ((stride_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_70_2 = ((stride_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_70_1) & 127;
    acc_2 = (acc_2 + stride_70_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_21_1 == phase_21_2);
  assert(stride_70_1 == stride_70_2);
}

int fn_R001945_4513_3(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int phase_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_21) & 63;
  acc ^= aux;
  int stride_70 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_70 = ((stride_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_70) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001945_4513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001945_4513_1 st_1 = {0};
  struct MatrixBlock_R001945_4513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int coefficient_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_46_1) & 63;
  aux_2 = (aux_2 + coefficient_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_57_1)
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

  switch (phase_57_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_46_1 == coefficient_46_2);
  assert(phase_57_1 == phase_57_2);
}

int fn_R001945_4513_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001945_4513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int coefficient_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_46) & 63;
  acc ^= aux;
  int phase_57 = (aux + st.buffer[1]) & 3;
  switch (phase_57)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001945_4513_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st_1 = {0};
  struct Vector3D_R001945_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int window_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_48_1) & 63;
  aux_2 = (aux_2 + window_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_63_1 > 41)
  {
    acc_1 = ((acc_1 + (parity_63_1 * 2)) + 5) & 127;
    aux_1 ^= parity_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_63_2 > 41)
  {
    acc_2 = ((acc_2 + (parity_63_2 * 2)) + 5) & 127;
    aux_2 ^= parity_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_68_1 = local_arr_1[aux_1 % 3];
  int window_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_48_1 == window_48_2);
  assert(parity_63_1 == parity_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_68_1 == window_68_2);
}

int fn_R001945_4513_5(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int window_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_48) & 63;
  acc ^= aux;
  int parity_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_63 > 41)
  {
    acc = ((acc + (parity_63 * 2)) + 5) & 127;
    aux ^= parity_63 & 15;
  }
  else
  {
    acc = ((acc - parity_63) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_68 = local_arr[aux % 3];
  acc = (acc + (window_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001945_4513_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001945_4513_1 st_1 = {0};
  struct MatrixBlock_R001945_4513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int metric_19_1 = 0;
  int metric_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_19_1 = ((metric_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_19_2 = ((metric_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_19_1) & 127;
    acc_2 = (acc_2 + metric_19_2) & 127;
  }

  int residue_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_62_1 > 32)
  {
    acc_1 = ((acc_1 + (residue_62_1 * 2)) + 5) & 127;
    aux_1 ^= residue_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_62_2 > 32)
  {
    acc_2 = ((acc_2 + (residue_62_2 * 2)) + 5) & 127;
    aux_2 ^= residue_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_62_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_19_1 == metric_19_2);
  assert(residue_62_1 == residue_62_2);
}

int fn_R001945_4513_6(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001945_4513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int metric_19 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_19 = ((metric_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_19) & 127;
  }

  int residue_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_62 > 32)
  {
    acc = ((acc + (residue_62 * 2)) + 5) & 127;
    aux ^= residue_62 & 15;
  }
  else
  {
    acc = ((acc - residue_62) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001945_4513_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001945_4513_1 st_1 = {0};
  struct MatrixBlock_R001945_4513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_67_1 = local_arr_1[aux_1 % 3];
  int checksum_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_67_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_67_1) & 63;
  aux_2 = (aux_2 + tracker_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_67_1 == checksum_67_2);
  assert(tracker_67_1 == tracker_67_2);
}

int fn_R001945_4513_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001945_4513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int checksum_67 = local_arr[aux % 3];
  acc = (acc + (checksum_67 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_67) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001945_4513_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st_1 = {0};
  struct Vector3D_R001945_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int segment_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_85_1) & 63;
  aux_2 = (aux_2 + segment_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_25_1)
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

  switch (stride_25_2)
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

  int tracker_59_1 = 0;
  int tracker_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_59_1 = ((tracker_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_59_2 = ((tracker_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_59_1) & 127;
    acc_2 = (acc_2 + tracker_59_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_85_1 == segment_85_2);
  assert(stride_25_1 == stride_25_2);
  assert(tracker_59_1 == tracker_59_2);
}

int fn_R001945_4513_8(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int segment_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_85) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_25 = (aux + st.buffer[1]) & 3;
  switch (stride_25)
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

  int tracker_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_59 = ((tracker_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_59) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001945_4513_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001945_4513_1 st_1 = {0};
  struct MatrixBlock_R001945_4513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int anchor_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_86_1)
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

  switch (anchor_86_2)
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

  int pivot_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_52_1 > 43)
  {
    acc_1 = ((acc_1 + (pivot_52_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_52_2 > 43)
  {
    acc_2 = ((acc_2 + (pivot_52_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_16_1) & 63;
  aux_2 = (aux_2 + sample_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_86_1 == anchor_86_2);
  assert(pivot_52_1 == pivot_52_2);
  assert(sample_16_1 == sample_16_2);
}

int fn_R001945_4513_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001945_4513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int anchor_86 = (aux + st.buffer[1]) & 3;
  switch (anchor_86)
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

  int pivot_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_52 > 43)
  {
    acc = ((acc + (pivot_52 * 2)) + 5) & 127;
    aux ^= pivot_52 & 15;
  }
  else
  {
    acc = ((acc - pivot_52) + 11) & 127;
    aux += 3;
  }
  int sample_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001945_4513_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st_1 = {0};
  struct Vector3D_R001945_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int factor_29_1 = 0;
  int factor_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_29_1 = ((factor_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_29_2 = ((factor_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_29_1) & 127;
    acc_2 = (acc_2 + factor_29_2) & 127;
  }

  int threshold_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_25_1)
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

  switch (threshold_25_2)
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

  int margin_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_80_1) & 63;
  aux_2 = (aux_2 + margin_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_29_1 == factor_29_2);
  assert(threshold_25_1 == threshold_25_2);
  assert(margin_80_1 == margin_80_2);
}

int fn_R001945_4513_10(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int factor_29 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_29 = ((factor_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_29) & 127;
  }

  int threshold_25 = (aux + st.buffer[1]) & 3;
  switch (threshold_25)
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

  int margin_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001945_4513_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st_1 = {0};
  struct Vector3D_R001945_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int coefficient_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_62_1 > 20)
  {
    acc_1 = ((acc_1 + (coefficient_62_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_62_2 > 20)
  {
    acc_2 = ((acc_2 + (coefficient_62_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_52_1 = 0;
  int bound_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_52_1 = ((bound_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_52_2 = ((bound_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_52_1) & 127;
    acc_2 = (acc_2 + bound_52_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_24_1 = local_arr_1[aux_1 % 3];
  int threshold_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_24_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_62_1 == coefficient_62_2);
  assert(bound_52_1 == bound_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_24_1 == threshold_24_2);
}

int fn_R001945_4513_11(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int coefficient_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_62 > 20)
  {
    acc = ((acc + (coefficient_62 * 2)) + 5) & 127;
    aux ^= coefficient_62 & 15;
  }
  else
  {
    acc = ((acc - coefficient_62) + 11) & 127;
    aux += 3;
  }
  int bound_52 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_52 = ((bound_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_52) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_24 = local_arr[aux % 3];
  acc = (acc + (threshold_24 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001945_4513_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st_1 = {0};
  struct Vector3D_R001945_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int damping_23_1 = 0;
  int damping_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_23_1 = ((damping_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_23_2 = ((damping_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_23_1) & 127;
    acc_2 = (acc_2 + damping_23_2) & 127;
  }

  int delta_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_77_1)
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

  switch (delta_77_2)
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
  int sample_42_1 = local_arr_1[aux_1 % 3];
  int sample_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_42_2 * 2)) & 127;
  int segment_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_18_1) & 63;
  aux_2 = (aux_2 + segment_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_23_1 == damping_23_2);
  assert(delta_77_1 == delta_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_42_1 == sample_42_2);
  assert(segment_18_1 == segment_18_2);
}

int fn_R001945_4513_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int damping_23 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_23 = ((damping_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_23) & 127;
  }

  int delta_77 = (aux + st.buffer[1]) & 3;
  switch (delta_77)
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
  int sample_42 = local_arr[aux % 3];
  acc = (acc + (sample_42 * 2)) & 127;
  int segment_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_18) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001945_4513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st_1 = {0};
  struct Vector3D_R001945_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int scale_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_96_1) & 63;
  aux_2 = (aux_2 + scale_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_39_1)
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

  switch (weight_39_2)
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
  int sample_77_1 = local_arr_1[aux_1 % 3];
  int sample_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_96_1 == scale_96_2);
  assert(weight_39_1 == weight_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_77_1 == sample_77_2);
}

int fn_R001945_4513_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001945_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int scale_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_96) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_39 = (aux + st.buffer[1]) & 3;
  switch (weight_39)
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
  int sample_77 = local_arr[aux % 3];
  acc = (acc + (sample_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001945_0_1;
  int sec_r001945_0_2;
  int sec_r001945_1_1;
  int sec_r001945_1_2;
  int sec_r001945_2_1;
  int sec_r001945_2_2;
  int sec_r001945_3_1;
  int sec_r001945_3_2;
  int sec_r001945_4_1;
  int sec_r001945_4_2;
  int sec_r001945_5_1;
  int sec_r001945_5_2;
  int sec_r001945_6_1;
  int sec_r001945_6_2;
  int sec_r001945_7_1;
  int sec_r001945_7_2;
  int sec_r001945_8_1;
  int sec_r001945_8_2;
  int sec_r001945_9_1;
  int sec_r001945_9_2;
  int sec_r001945_10_1;
  int sec_r001945_10_2;
  int sec_r001945_11_1;
  int sec_r001945_11_2;
  int sec_r001945_12_1;
  int sec_r001945_12_2;
  int sec_r001945_13_1;
  int sec_r001945_13_2;
  int sec_r001945_14_1;
  int sec_r001945_14_2;
  int sec_r001945_15_1;
  int sec_r001945_15_2;
  int sec_r001945_16_1;
  int sec_r001945_16_2;
  int pub_r001945_0_1;
  int pub_r001945_0_2;
  int pub_r001945_1_1;
  int pub_r001945_1_2;
  int pub_r001945_2_1;
  int pub_r001945_2_2;
  int pub_r001945_3_1;
  int pub_r001945_3_2;
  int pub_r001945_4_1;
  int pub_r001945_4_2;
  int pub_r001945_5_1;
  int pub_r001945_5_2;
  int pub_r001945_6_1;
  int pub_r001945_6_2;
  int pub_r001945_7_1;
  int pub_r001945_7_2;
  int pub_r001945_8_1;
  int pub_r001945_8_2;
  int pub_r001945_9_1;
  int pub_r001945_9_2;
  int pub_r001945_10_1;
  int pub_r001945_10_2;
  int pub_r001945_11_1;
  int pub_r001945_11_2;
  int pub_r001945_12_1;
  int pub_r001945_12_2;
  int pub_r001945_13_1;
  int pub_r001945_13_2;
  int pub_r001945_14_1;
  int pub_r001945_14_2;
  int pub_r001945_15_1;
  int pub_r001945_15_2;
  int pub_r001945_16_1;
  int pub_r001945_16_2;
  int pub_r001945_17_1;
  int pub_r001945_17_2;
  int pub_r001945_18_1;
  int pub_r001945_18_2;
  int pub_r001945_19_1;
  int pub_r001945_19_2;
  int pub_r001945_20_1;
  int pub_r001945_20_2;
  int pub_r001945_21_1;
  int pub_r001945_21_2;
  int pub_r001945_22_1;
  int pub_r001945_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001945_0_1 >= (-100)) && (pub_r001945_0_1 <= 100));
  __CPROVER_assume((pub_r001945_0_2 >= (-100)) && (pub_r001945_0_2 <= 100));
  __CPROVER_assume((pub_r001945_1_1 >= (-100)) && (pub_r001945_1_1 <= 100));
  __CPROVER_assume((pub_r001945_1_2 >= (-100)) && (pub_r001945_1_2 <= 100));
  __CPROVER_assume((pub_r001945_2_1 >= (-100)) && (pub_r001945_2_1 <= 100));
  __CPROVER_assume((pub_r001945_2_2 >= (-100)) && (pub_r001945_2_2 <= 100));
  __CPROVER_assume((pub_r001945_3_1 >= (-100)) && (pub_r001945_3_1 <= 100));
  __CPROVER_assume((pub_r001945_3_2 >= (-100)) && (pub_r001945_3_2 <= 100));
  __CPROVER_assume((pub_r001945_4_1 >= (-100)) && (pub_r001945_4_1 <= 100));
  __CPROVER_assume((pub_r001945_4_2 >= (-100)) && (pub_r001945_4_2 <= 100));
  __CPROVER_assume((pub_r001945_5_1 >= (-100)) && (pub_r001945_5_1 <= 100));
  __CPROVER_assume((pub_r001945_5_2 >= (-100)) && (pub_r001945_5_2 <= 100));
  __CPROVER_assume((pub_r001945_6_1 >= (-100)) && (pub_r001945_6_1 <= 100));
  __CPROVER_assume((pub_r001945_6_2 >= (-100)) && (pub_r001945_6_2 <= 100));
  __CPROVER_assume((pub_r001945_7_1 >= (-100)) && (pub_r001945_7_1 <= 100));
  __CPROVER_assume((pub_r001945_7_2 >= (-100)) && (pub_r001945_7_2 <= 100));
  __CPROVER_assume((pub_r001945_8_1 >= (-100)) && (pub_r001945_8_1 <= 100));
  __CPROVER_assume((pub_r001945_8_2 >= (-100)) && (pub_r001945_8_2 <= 100));
  __CPROVER_assume((pub_r001945_9_1 >= (-100)) && (pub_r001945_9_1 <= 100));
  __CPROVER_assume((pub_r001945_9_2 >= (-100)) && (pub_r001945_9_2 <= 100));
  __CPROVER_assume((pub_r001945_10_1 >= (-100)) && (pub_r001945_10_1 <= 100));
  __CPROVER_assume((pub_r001945_10_2 >= (-100)) && (pub_r001945_10_2 <= 100));
  __CPROVER_assume((pub_r001945_11_1 >= (-100)) && (pub_r001945_11_1 <= 100));
  __CPROVER_assume((pub_r001945_11_2 >= (-100)) && (pub_r001945_11_2 <= 100));
  __CPROVER_assume((pub_r001945_12_1 >= (-100)) && (pub_r001945_12_1 <= 100));
  __CPROVER_assume((pub_r001945_12_2 >= (-100)) && (pub_r001945_12_2 <= 100));
  __CPROVER_assume((pub_r001945_13_1 >= (-100)) && (pub_r001945_13_1 <= 100));
  __CPROVER_assume((pub_r001945_13_2 >= (-100)) && (pub_r001945_13_2 <= 100));
  __CPROVER_assume((pub_r001945_14_1 >= (-100)) && (pub_r001945_14_1 <= 100));
  __CPROVER_assume((pub_r001945_14_2 >= (-100)) && (pub_r001945_14_2 <= 100));
  __CPROVER_assume((pub_r001945_15_1 >= (-100)) && (pub_r001945_15_1 <= 100));
  __CPROVER_assume((pub_r001945_15_2 >= (-100)) && (pub_r001945_15_2 <= 100));
  __CPROVER_assume((pub_r001945_16_1 >= (-100)) && (pub_r001945_16_1 <= 100));
  __CPROVER_assume((pub_r001945_16_2 >= (-100)) && (pub_r001945_16_2 <= 100));
  __CPROVER_assume((pub_r001945_17_1 >= (-100)) && (pub_r001945_17_1 <= 100));
  __CPROVER_assume((pub_r001945_17_2 >= (-100)) && (pub_r001945_17_2 <= 100));
  __CPROVER_assume((pub_r001945_18_1 >= (-100)) && (pub_r001945_18_1 <= 100));
  __CPROVER_assume((pub_r001945_18_2 >= (-100)) && (pub_r001945_18_2 <= 100));
  __CPROVER_assume((pub_r001945_19_1 >= (-100)) && (pub_r001945_19_1 <= 100));
  __CPROVER_assume((pub_r001945_19_2 >= (-100)) && (pub_r001945_19_2 <= 100));
  __CPROVER_assume((pub_r001945_20_1 >= (-100)) && (pub_r001945_20_1 <= 100));
  __CPROVER_assume((pub_r001945_20_2 >= (-100)) && (pub_r001945_20_2 <= 100));
  __CPROVER_assume((pub_r001945_21_1 >= (-100)) && (pub_r001945_21_1 <= 100));
  __CPROVER_assume((pub_r001945_21_2 >= (-100)) && (pub_r001945_21_2 <= 100));
  __CPROVER_assume((pub_r001945_22_1 >= (-100)) && (pub_r001945_22_1 <= 100));
  __CPROVER_assume((pub_r001945_22_2 >= (-100)) && (pub_r001945_22_2 <= 100));
  __CPROVER_assume((sec_r001945_0_1 >= 0) && (sec_r001945_0_1 <= 255));
  __CPROVER_assume((sec_r001945_0_2 >= 0) && (sec_r001945_0_2 <= 255));
  __CPROVER_assume((sec_r001945_1_1 >= 0) && (sec_r001945_1_1 <= 255));
  __CPROVER_assume((sec_r001945_1_2 >= 0) && (sec_r001945_1_2 <= 255));
  __CPROVER_assume((sec_r001945_2_1 >= 0) && (sec_r001945_2_1 <= 255));
  __CPROVER_assume((sec_r001945_2_2 >= 0) && (sec_r001945_2_2 <= 255));
  __CPROVER_assume((sec_r001945_3_1 >= 0) && (sec_r001945_3_1 <= 255));
  __CPROVER_assume((sec_r001945_3_2 >= 0) && (sec_r001945_3_2 <= 255));
  __CPROVER_assume((sec_r001945_4_1 >= 0) && (sec_r001945_4_1 <= 255));
  __CPROVER_assume((sec_r001945_4_2 >= 0) && (sec_r001945_4_2 <= 255));
  __CPROVER_assume((sec_r001945_5_1 >= 0) && (sec_r001945_5_1 <= 255));
  __CPROVER_assume((sec_r001945_5_2 >= 0) && (sec_r001945_5_2 <= 255));
  __CPROVER_assume((sec_r001945_6_1 >= 0) && (sec_r001945_6_1 <= 255));
  __CPROVER_assume((sec_r001945_6_2 >= 0) && (sec_r001945_6_2 <= 255));
  __CPROVER_assume((sec_r001945_7_1 >= 0) && (sec_r001945_7_1 <= 255));
  __CPROVER_assume((sec_r001945_7_2 >= 0) && (sec_r001945_7_2 <= 255));
  __CPROVER_assume((sec_r001945_8_1 >= 0) && (sec_r001945_8_1 <= 255));
  __CPROVER_assume((sec_r001945_8_2 >= 0) && (sec_r001945_8_2 <= 255));
  __CPROVER_assume((sec_r001945_9_1 >= 0) && (sec_r001945_9_1 <= 255));
  __CPROVER_assume((sec_r001945_9_2 >= 0) && (sec_r001945_9_2 <= 255));
  __CPROVER_assume((sec_r001945_10_1 >= 0) && (sec_r001945_10_1 <= 255));
  __CPROVER_assume((sec_r001945_10_2 >= 0) && (sec_r001945_10_2 <= 255));
  __CPROVER_assume((sec_r001945_11_1 >= 0) && (sec_r001945_11_1 <= 255));
  __CPROVER_assume((sec_r001945_11_2 >= 0) && (sec_r001945_11_2 <= 255));
  __CPROVER_assume((sec_r001945_12_1 >= 0) && (sec_r001945_12_1 <= 255));
  __CPROVER_assume((sec_r001945_12_2 >= 0) && (sec_r001945_12_2 <= 255));
  __CPROVER_assume((sec_r001945_13_1 >= 0) && (sec_r001945_13_1 <= 255));
  __CPROVER_assume((sec_r001945_13_2 >= 0) && (sec_r001945_13_2 <= 255));
  __CPROVER_assume((sec_r001945_14_1 >= 0) && (sec_r001945_14_1 <= 255));
  __CPROVER_assume((sec_r001945_14_2 >= 0) && (sec_r001945_14_2 <= 255));
  __CPROVER_assume((sec_r001945_15_1 >= 0) && (sec_r001945_15_1 <= 255));
  __CPROVER_assume((sec_r001945_15_2 >= 0) && (sec_r001945_15_2 <= 255));
  __CPROVER_assume((sec_r001945_16_1 >= 0) && (sec_r001945_16_1 <= 255));
  __CPROVER_assume((sec_r001945_16_2 >= 0) && (sec_r001945_16_2 <= 255));
  struct Vector3D_R001945_4513_0 st_var_0_1 = {0};
  struct Vector3D_R001945_4513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001945_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001945_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001945_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001945_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001945_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001945_0_2 + 7) & 15;
  struct MatrixBlock_R001945_4513_1 st_var_1_1 = {0};
  struct MatrixBlock_R001945_4513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001945_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001945_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001945_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001945_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001945_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001945_0_2 + 9) & 15;
  union RegisterBank_R001945_4513_0 u_var_1;
  union RegisterBank_R001945_4513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001945_4513_0(sec_r001945_0_1, pub_r001945_1_1, pub_r001945_2_1, pub_r001945_3_1);
  int helper_flow_0_2 = fn_R001945_4513_0(sec_r001945_0_2, pub_r001945_1_2, pub_r001945_2_2, pub_r001945_3_2);
  fn_R001945_4513_0_2(sec_r001945_0_1, pub_r001945_1_1, pub_r001945_2_1, pub_r001945_3_1, sec_r001945_0_2, pub_r001945_1_2, pub_r001945_2_2, pub_r001945_3_2);
  int helper_flow_1_1 = fn_R001945_4513_1(sec_r001945_1_1, pub_r001945_2_1, pub_r001945_3_1, pub_r001945_4_1, pub_r001945_5_1);
  int helper_flow_1_2 = fn_R001945_4513_1(sec_r001945_1_2, pub_r001945_2_2, pub_r001945_3_2, pub_r001945_4_2, pub_r001945_5_2);
  fn_R001945_4513_1_2(sec_r001945_1_1, pub_r001945_2_1, pub_r001945_3_1, pub_r001945_4_1, pub_r001945_5_1, sec_r001945_1_2, pub_r001945_2_2, pub_r001945_3_2, pub_r001945_4_2, pub_r001945_5_2);
  int helper_flow_2_1 = fn_R001945_4513_2(sec_r001945_2_1, sec_r001945_3_1, pub_r001945_4_1);
  int helper_flow_2_2 = fn_R001945_4513_2(sec_r001945_2_2, sec_r001945_3_2, pub_r001945_4_2);
  fn_R001945_4513_2_2(sec_r001945_2_1, sec_r001945_3_1, pub_r001945_4_1, sec_r001945_2_2, sec_r001945_3_2, pub_r001945_4_2);
  int helper_flow_3_1 = fn_R001945_4513_3(sec_r001945_3_1, pub_r001945_4_1);
  int helper_flow_3_2 = fn_R001945_4513_3(sec_r001945_3_2, pub_r001945_4_2);
  fn_R001945_4513_3_2(sec_r001945_3_1, pub_r001945_4_1, sec_r001945_3_2, pub_r001945_4_2);
  int helper_flow_4_1 = fn_R001945_4513_4(sec_r001945_4_1, sec_r001945_5_1, pub_r001945_6_1, pub_r001945_7_1);
  int helper_flow_4_2 = fn_R001945_4513_4(sec_r001945_4_2, sec_r001945_5_2, pub_r001945_6_2, pub_r001945_7_2);
  fn_R001945_4513_4_2(sec_r001945_4_1, sec_r001945_5_1, pub_r001945_6_1, pub_r001945_7_1, sec_r001945_4_2, sec_r001945_5_2, pub_r001945_6_2, pub_r001945_7_2);
  int helper_flow_5_1 = fn_R001945_4513_5(sec_r001945_5_1, pub_r001945_6_1);
  int helper_flow_5_2 = fn_R001945_4513_5(sec_r001945_5_2, pub_r001945_6_2);
  fn_R001945_4513_5_2(sec_r001945_5_1, pub_r001945_6_1, sec_r001945_5_2, pub_r001945_6_2);
  int helper_flow_6_1 = fn_R001945_4513_6(sec_r001945_6_1, sec_r001945_7_1);
  int helper_flow_6_2 = fn_R001945_4513_6(sec_r001945_6_2, sec_r001945_7_2);
  fn_R001945_4513_6_2(sec_r001945_6_1, sec_r001945_7_1, sec_r001945_6_2, sec_r001945_7_2);
  int stage_v_0_1 = ((sec_r001945_3_1 << 1) ^ (pub_r001945_5_1 >> 1)) & 127;
  int stage_v_0_2 = ((sec_r001945_3_2 << 1) ^ (pub_r001945_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_0_2 + 1) & 15;
  out_sink_1 ^= stage_v_0_1 & 63;
  out_sink_2 ^= stage_v_0_2 & 63;
  int stage_v_1_1 = ((pub_r001945_21_1 * 2) + 39) & 63;
  int stage_v_1_2 = ((pub_r001945_21_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((sec_r001945_16_1 << 1) ^ (pub_r001945_19_1 >> 1)) & 127;
  int stage_v_2_2 = ((sec_r001945_16_2 << 1) ^ (pub_r001945_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_2_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_2_2 + 1) & 15;
  out_sink_1 ^= stage_v_2_1 & 63;
  out_sink_2 ^= stage_v_2_2 & 63;
  int stage_v_3_1 = ((pub_r001945_0_1 * 2) + 12) & 63;
  int stage_v_3_2 = ((pub_r001945_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((sec_r001945_15_1 << 1) ^ (pub_r001945_2_1 >> 1)) & 127;
  int stage_v_4_2 = ((sec_r001945_15_2 << 1) ^ (pub_r001945_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_4_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_4_2 + 1) & 15;
  out_sink_1 ^= stage_v_4_1 & 63;
  out_sink_2 ^= stage_v_4_2 & 63;
  int stage_v_5_1 = ((pub_r001945_4_1 * 2) + 6) & 63;
  int stage_v_5_2 = ((pub_r001945_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((stage_v_4_1 << 1) ^ (pub_r001945_16_1 >> 1)) & 127;
  int stage_v_6_2 = ((stage_v_4_2 << 1) ^ (pub_r001945_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_6_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_6_2 + 1) & 15;
  out_sink_1 ^= stage_v_6_1 & 63;
  out_sink_2 ^= stage_v_6_2 & 63;
  int stage_v_7_1 = ((sec_r001945_3_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_7_2 = ((sec_r001945_3_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_7_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_7_2 + 1) & 15;
  out_sink_1 ^= stage_v_7_1 & 63;
  out_sink_2 ^= stage_v_7_2 & 63;
  int stage_v_8_1 = ((sec_r001945_5_1 << 1) ^ (pub_r001945_22_1 >> 1)) & 127;
  int stage_v_8_2 = ((sec_r001945_5_2 << 1) ^ (pub_r001945_22_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_8_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_8_2 + 1) & 15;
  out_sink_1 ^= stage_v_8_1 & 63;
  out_sink_2 ^= stage_v_8_2 & 63;
  int stage_v_9_1 = ((sec_r001945_16_1 << 1) ^ (pub_r001945_0_1 >> 1)) & 127;
  int stage_v_9_2 = ((sec_r001945_16_2 << 1) ^ (pub_r001945_0_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_9_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_9_2 + 1) & 15;
  out_sink_1 ^= stage_v_9_1 & 63;
  out_sink_2 ^= stage_v_9_2 & 63;
  int stage_v_10_1 = ((pub_r001945_10_1 * 2) + 31) & 63;
  int stage_v_10_2 = ((pub_r001945_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((sec_r001945_14_1 << 1) ^ (pub_r001945_7_1 >> 1)) & 127;
  int stage_v_11_2 = ((sec_r001945_14_2 << 1) ^ (pub_r001945_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_11_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_11_2 + 1) & 15;
  out_sink_1 ^= stage_v_11_1 & 63;
  out_sink_2 ^= stage_v_11_2 & 63;
  int stage_v_12_1 = ((sec_r001945_6_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_12_2 = ((sec_r001945_6_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_12_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_12_2 + 1) & 15;
  out_sink_1 ^= stage_v_12_1 & 63;
  out_sink_2 ^= stage_v_12_2 & 63;
  int stage_v_13_1 = ((stage_v_7_1 << 1) ^ (pub_r001945_18_1 >> 1)) & 127;
  int stage_v_13_2 = ((stage_v_7_2 << 1) ^ (pub_r001945_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_13_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_13_2 + 1) & 15;
  out_sink_1 ^= stage_v_13_1 & 63;
  out_sink_2 ^= stage_v_13_2 & 63;
  int stage_v_14_1 = ((helper_flow_2_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_14_2 = ((helper_flow_2_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((sec_r001945_1_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_15_2 = ((sec_r001945_1_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_15_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_15_2 + 1) & 15;
  out_sink_1 ^= stage_v_15_1 & 63;
  out_sink_2 ^= stage_v_15_2 & 63;
  int stage_v_16_1 = ((stage_v_0_1 << 1) ^ (pub_r001945_18_1 >> 1)) & 127;
  int stage_v_16_2 = ((stage_v_0_2 << 1) ^ (pub_r001945_18_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_16_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_16_2 + 1) & 15;
  out_sink_1 ^= stage_v_16_1 & 63;
  out_sink_2 ^= stage_v_16_2 & 63;
  int stage_v_17_1 = ((pub_r001945_11_1 * 2) + 25) & 63;
  int stage_v_17_2 = ((pub_r001945_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((stage_v_12_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_18_2 = ((stage_v_12_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_18_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_18_2 + 1) & 15;
  out_sink_1 ^= stage_v_18_1 & 63;
  out_sink_2 ^= stage_v_18_2 & 63;
  int stage_v_19_1 = ((pub_r001945_8_1 * 2) + 42) & 63;
  int stage_v_19_2 = ((pub_r001945_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001945_1_1 * 2) + 37) & 63;
  int stage_v_20_2 = ((pub_r001945_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((helper_flow_5_1 << 1) ^ (pub_r001945_3_1 >> 1)) & 127;
  int stage_v_21_2 = ((helper_flow_5_2 << 1) ^ (pub_r001945_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_21_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_21_2 + 1) & 15;
  out_sink_1 ^= stage_v_21_1 & 63;
  out_sink_2 ^= stage_v_21_2 & 63;
  int stage_v_22_1 = ((sec_r001945_15_1 << 1) ^ (pub_r001945_8_1 >> 1)) & 127;
  int stage_v_22_2 = ((sec_r001945_15_2 << 1) ^ (pub_r001945_8_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_22_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_22_2 + 1) & 15;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = ((pub_r001945_5_1 * 2) + 43) & 63;
  int stage_v_23_2 = ((pub_r001945_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((sec_r001945_14_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_24_2 = ((sec_r001945_14_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_24_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_24_2 + 1) & 15;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = ((sec_r001945_8_1 << 1) ^ (pub_r001945_17_1 >> 1)) & 127;
  int stage_v_25_2 = ((sec_r001945_8_2 << 1) ^ (pub_r001945_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_25_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_25_2 + 1) & 15;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = ((pub_r001945_8_1 * 2) + 36) & 63;
  int stage_v_26_2 = ((pub_r001945_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001945_6_1 * 2) + 15) & 63;
  int stage_v_27_2 = ((pub_r001945_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((stage_v_8_1 << 1) ^ (pub_r001945_16_1 >> 1)) & 127;
  int stage_v_28_2 = ((stage_v_8_2 << 1) ^ (pub_r001945_16_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_28_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_28_2 + 1) & 15;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = ((pub_r001945_9_1 * 2) + 49) & 63;
  int stage_v_29_2 = ((pub_r001945_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((stage_v_11_1 << 1) ^ (pub_r001945_8_1 >> 1)) & 127;
  int stage_v_30_2 = ((stage_v_11_2 << 1) ^ (pub_r001945_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_30_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_30_2 + 1) & 15;
  out_sink_1 ^= stage_v_30_1 & 63;
  out_sink_2 ^= stage_v_30_2 & 63;
  int stage_v_31_1 = ((helper_flow_0_1 << 1) ^ (pub_r001945_2_1 >> 1)) & 127;
  int stage_v_31_2 = ((helper_flow_0_2 << 1) ^ (pub_r001945_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_31_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_31_2 + 1) & 15;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = ((pub_r001945_0_1 * 2) + 14) & 63;
  int stage_v_32_2 = ((pub_r001945_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((stage_v_31_1 << 1) ^ (pub_r001945_14_1 >> 1)) & 127;
  int stage_v_33_2 = ((stage_v_31_2 << 1) ^ (pub_r001945_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_33_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_33_2 + 1) & 15;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = ((stage_v_7_1 << 1) ^ (pub_r001945_17_1 >> 1)) & 127;
  int stage_v_34_2 = ((stage_v_7_2 << 1) ^ (pub_r001945_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_34_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_34_2 + 1) & 15;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = ((pub_r001945_11_1 * 2) + 15) & 63;
  int stage_v_35_2 = ((pub_r001945_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((stage_v_0_1 << 1) ^ (pub_r001945_17_1 >> 1)) & 127;
  int stage_v_36_2 = ((stage_v_0_2 << 1) ^ (pub_r001945_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_36_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_36_2 + 1) & 15;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = ((pub_r001945_1_1 * 2) + 46) & 63;
  int stage_v_37_2 = ((pub_r001945_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001945_20_1 * 2) + 5) & 63;
  int stage_v_38_2 = ((pub_r001945_20_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((helper_flow_0_1 << 1) ^ (pub_r001945_7_1 >> 1)) & 127;
  int stage_v_39_2 = ((helper_flow_0_2 << 1) ^ (pub_r001945_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_39_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_39_2 + 1) & 15;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = ((pub_r001945_14_1 * 2) + 16) & 63;
  int stage_v_40_2 = ((pub_r001945_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((stage_v_4_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_41_2 = ((stage_v_4_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_41_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_41_2 + 1) & 15;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = ((stage_v_21_1 << 1) ^ (pub_r001945_1_1 >> 1)) & 127;
  int stage_v_42_2 = ((stage_v_21_2 << 1) ^ (pub_r001945_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_42_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_42_2 + 1) & 15;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = ((pub_r001945_2_1 * 2) + 35) & 63;
  int stage_v_43_2 = ((pub_r001945_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001945_13_1 * 2) + 45) & 63;
  int stage_v_44_2 = ((pub_r001945_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001945_13_1 * 2) + 37) & 63;
  int stage_v_45_2 = ((pub_r001945_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001945_2_1 * 2) + 20) & 63;
  int stage_v_46_2 = ((pub_r001945_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((stage_v_18_1 << 1) ^ (pub_r001945_4_1 >> 1)) & 127;
  int stage_v_47_2 = ((stage_v_18_2 << 1) ^ (pub_r001945_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_47_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_47_2 + 1) & 15;
  out_sink_1 ^= stage_v_47_1 & 63;
  out_sink_2 ^= stage_v_47_2 & 63;
  int stage_v_48_1 = ((pub_r001945_6_1 * 2) + 21) & 63;
  int stage_v_48_2 = ((pub_r001945_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((sec_r001945_0_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_49_2 = ((sec_r001945_0_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_49_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_49_2 + 1) & 15;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = ((helper_flow_2_1 << 1) ^ (pub_r001945_8_1 >> 1)) & 127;
  int stage_v_50_2 = ((helper_flow_2_2 << 1) ^ (pub_r001945_8_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_50_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_50_2 + 1) & 15;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = ((pub_r001945_6_1 * 2) + 47) & 63;
  int stage_v_51_2 = ((pub_r001945_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001945_14_1 * 2) + 42) & 63;
  int stage_v_52_2 = ((pub_r001945_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((sec_r001945_12_1 << 1) ^ (pub_r001945_9_1 >> 1)) & 127;
  int stage_v_53_2 = ((sec_r001945_12_2 << 1) ^ (pub_r001945_9_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_53_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_53_2 + 1) & 15;
  out_sink_1 ^= stage_v_53_1 & 63;
  out_sink_2 ^= stage_v_53_2 & 63;
  int stage_v_54_1 = ((pub_r001945_0_1 * 2) + 24) & 63;
  int stage_v_54_2 = ((pub_r001945_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((helper_flow_1_1 << 1) ^ (pub_r001945_11_1 >> 1)) & 127;
  int stage_v_55_2 = ((helper_flow_1_2 << 1) ^ (pub_r001945_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_55_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_55_2 + 1) & 15;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = ((stage_v_42_1 << 1) ^ (pub_r001945_10_1 >> 1)) & 127;
  int stage_v_56_2 = ((stage_v_42_2 << 1) ^ (pub_r001945_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_56_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_56_2 + 1) & 15;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = ((stage_v_22_1 << 1) ^ (pub_r001945_19_1 >> 1)) & 127;
  int stage_v_57_2 = ((stage_v_22_2 << 1) ^ (pub_r001945_19_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_57_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_57_2 + 1) & 15;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = ((pub_r001945_10_1 * 2) + 47) & 63;
  int stage_v_58_2 = ((pub_r001945_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001945_0_1 * 2) + 34) & 63;
  int stage_v_59_2 = ((pub_r001945_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001945_7_1 * 2) + 36) & 63;
  int stage_v_60_2 = ((pub_r001945_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001945_1_1 * 2) + 29) & 63;
  int stage_v_61_2 = ((pub_r001945_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((stage_v_13_1 << 1) ^ (pub_r001945_6_1 >> 1)) & 127;
  int stage_v_62_2 = ((stage_v_13_2 << 1) ^ (pub_r001945_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_62_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_62_2 + 1) & 15;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = ((pub_r001945_5_1 * 2) + 13) & 63;
  int stage_v_63_2 = ((pub_r001945_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001945_4_1 * 2) + 7) & 63;
  int stage_v_64_2 = ((pub_r001945_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((stage_v_31_1 << 1) ^ (pub_r001945_12_1 >> 1)) & 127;
  int stage_v_65_2 = ((stage_v_31_2 << 1) ^ (pub_r001945_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_65_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_65_2 + 1) & 15;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = ((pub_r001945_0_1 * 2) + 16) & 63;
  int stage_v_66_2 = ((pub_r001945_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((stage_v_36_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_67_2 = ((stage_v_36_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_67_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_67_2 + 1) & 15;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = ((pub_r001945_17_1 * 2) + 33) & 63;
  int stage_v_68_2 = ((pub_r001945_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((stage_v_67_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_69_2 = ((stage_v_67_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_69_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_69_2 + 1) & 15;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = ((stage_v_57_1 << 1) ^ (pub_r001945_3_1 >> 1)) & 127;
  int stage_v_70_2 = ((stage_v_57_2 << 1) ^ (pub_r001945_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_70_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_70_2 + 1) & 15;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = ((pub_r001945_9_1 * 2) + 35) & 63;
  int stage_v_71_2 = ((pub_r001945_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001945_9_1 * 2) + 23) & 63;
  int stage_v_72_2 = ((pub_r001945_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((stage_v_69_1 << 1) ^ (pub_r001945_3_1 >> 1)) & 127;
  int stage_v_73_2 = ((stage_v_69_2 << 1) ^ (pub_r001945_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_73_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_73_2 + 1) & 15;
  out_sink_1 ^= stage_v_73_1 & 63;
  out_sink_2 ^= stage_v_73_2 & 63;
  int stage_v_74_1 = ((pub_r001945_15_1 * 2) + 49) & 63;
  int stage_v_74_2 = ((pub_r001945_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((stage_v_4_1 << 1) ^ (pub_r001945_16_1 >> 1)) & 127;
  int stage_v_75_2 = ((stage_v_4_2 << 1) ^ (pub_r001945_16_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_75_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_75_2 + 1) & 15;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = ((pub_r001945_4_1 * 2) + 37) & 63;
  int stage_v_76_2 = ((pub_r001945_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001945_17_1 * 2) + 18) & 63;
  int stage_v_77_2 = ((pub_r001945_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001945_21_1 * 2) + 9) & 63;
  int stage_v_78_2 = ((pub_r001945_21_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((sec_r001945_16_1 << 1) ^ (pub_r001945_17_1 >> 1)) & 127;
  int stage_v_79_2 = ((sec_r001945_16_2 << 1) ^ (pub_r001945_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_79_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_79_2 + 1) & 15;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = ((stage_v_14_1 << 1) ^ (pub_r001945_1_1 >> 1)) & 127;
  int stage_v_80_2 = ((stage_v_14_2 << 1) ^ (pub_r001945_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_80_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_80_2 + 1) & 15;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = ((stage_v_12_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_81_2 = ((stage_v_12_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_81_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_81_2 + 1) & 15;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = ((stage_v_36_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_82_2 = ((stage_v_36_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_82_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_82_2 + 1) & 15;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = ((pub_r001945_16_1 * 2) + 16) & 63;
  int stage_v_83_2 = ((pub_r001945_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((stage_v_8_1 << 1) ^ (pub_r001945_16_1 >> 1)) & 127;
  int stage_v_84_2 = ((stage_v_8_2 << 1) ^ (pub_r001945_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_84_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_84_2 + 1) & 15;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = ((stage_v_14_1 << 1) ^ (pub_r001945_12_1 >> 1)) & 127;
  int stage_v_85_2 = ((stage_v_14_2 << 1) ^ (pub_r001945_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_85_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_85_2 + 1) & 15;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = ((stage_v_84_1 << 1) ^ (pub_r001945_12_1 >> 1)) & 127;
  int stage_v_86_2 = ((stage_v_84_2 << 1) ^ (pub_r001945_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_86_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_86_2 + 1) & 15;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = ((pub_r001945_20_1 * 2) + 44) & 63;
  int stage_v_87_2 = ((pub_r001945_20_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001945_12_1 * 2) + 50) & 63;
  int stage_v_88_2 = ((pub_r001945_12_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((stage_v_49_1 << 1) ^ (pub_r001945_22_1 >> 1)) & 127;
  int stage_v_89_2 = ((stage_v_49_2 << 1) ^ (pub_r001945_22_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_89_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_89_2 + 1) & 15;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = ((pub_r001945_13_1 * 2) + 14) & 63;
  int stage_v_90_2 = ((pub_r001945_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001945_2_1 * 2) + 5) & 63;
  int stage_v_91_2 = ((pub_r001945_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((stage_v_6_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_92_2 = ((stage_v_6_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_92_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_92_2 + 1) & 15;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = ((sec_r001945_4_1 << 1) ^ (pub_r001945_6_1 >> 1)) & 127;
  int stage_v_93_2 = ((sec_r001945_4_2 << 1) ^ (pub_r001945_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_93_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_93_2 + 1) & 15;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = ((stage_v_79_1 << 1) ^ (pub_r001945_14_1 >> 1)) & 127;
  int stage_v_94_2 = ((stage_v_79_2 << 1) ^ (pub_r001945_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_94_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_94_2 + 1) & 15;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = ((sec_r001945_7_1 << 1) ^ (pub_r001945_10_1 >> 1)) & 127;
  int stage_v_95_2 = ((sec_r001945_7_2 << 1) ^ (pub_r001945_10_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_95_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_95_2 + 1) & 15;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = ((sec_r001945_15_1 << 1) ^ (pub_r001945_4_1 >> 1)) & 127;
  int stage_v_96_2 = ((sec_r001945_15_2 << 1) ^ (pub_r001945_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_96_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_96_2 + 1) & 15;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = ((pub_r001945_0_1 * 2) + 50) & 63;
  int stage_v_97_2 = ((pub_r001945_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001945_9_1 * 2) + 15) & 63;
  int stage_v_98_2 = ((pub_r001945_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((stage_v_55_1 << 1) ^ (pub_r001945_4_1 >> 1)) & 127;
  int stage_v_99_2 = ((stage_v_55_2 << 1) ^ (pub_r001945_4_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_99_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_99_2 + 1) & 15;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = ((pub_r001945_15_1 * 2) + 44) & 63;
  int stage_v_100_2 = ((pub_r001945_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((stage_v_80_1 << 1) ^ (pub_r001945_16_1 >> 1)) & 127;
  int stage_v_101_2 = ((stage_v_80_2 << 1) ^ (pub_r001945_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_101_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_101_2 + 1) & 15;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = ((pub_r001945_15_1 * 2) + 23) & 63;
  int stage_v_102_2 = ((pub_r001945_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_53_1 << 1) ^ (pub_r001945_4_1 >> 1)) & 127;
  int stage_v_103_2 = ((stage_v_53_2 << 1) ^ (pub_r001945_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_103_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_103_2 + 1) & 15;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = ((sec_r001945_1_1 << 1) ^ (pub_r001945_17_1 >> 1)) & 127;
  int stage_v_104_2 = ((sec_r001945_1_2 << 1) ^ (pub_r001945_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_104_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_104_2 + 1) & 15;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = ((sec_r001945_12_1 << 1) ^ (pub_r001945_12_1 >> 1)) & 127;
  int stage_v_105_2 = ((sec_r001945_12_2 << 1) ^ (pub_r001945_12_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_105_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_105_2 + 1) & 15;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = ((pub_r001945_16_1 * 2) + 30) & 63;
  int stage_v_106_2 = ((pub_r001945_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001945_13_1 * 2) + 35) & 63;
  int stage_v_107_2 = ((pub_r001945_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001945_10_1 * 2) + 38) & 63;
  int stage_v_108_2 = ((pub_r001945_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_82_1 << 1) ^ (pub_r001945_19_1 >> 1)) & 127;
  int stage_v_109_2 = ((stage_v_82_2 << 1) ^ (pub_r001945_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_109_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_109_2 + 1) & 15;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = ((stage_v_92_1 << 1) ^ (pub_r001945_19_1 >> 1)) & 127;
  int stage_v_110_2 = ((stage_v_92_2 << 1) ^ (pub_r001945_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_110_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_110_2 + 1) & 15;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = ((stage_v_62_1 << 1) ^ (pub_r001945_4_1 >> 1)) & 127;
  int stage_v_111_2 = ((stage_v_62_2 << 1) ^ (pub_r001945_4_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_111_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_111_2 + 1) & 15;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = ((pub_r001945_6_1 * 2) + 38) & 63;
  int stage_v_112_2 = ((pub_r001945_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((stage_v_11_1 << 1) ^ (pub_r001945_6_1 >> 1)) & 127;
  int stage_v_113_2 = ((stage_v_11_2 << 1) ^ (pub_r001945_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_113_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_113_2 + 1) & 15;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = ((pub_r001945_21_1 * 2) + 6) & 63;
  int stage_v_114_2 = ((pub_r001945_21_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001945_19_1 * 2) + 9) & 63;
  int stage_v_115_2 = ((pub_r001945_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001945_22_1 * 2) + 50) & 63;
  int stage_v_116_2 = ((pub_r001945_22_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((stage_v_84_1 << 1) ^ (pub_r001945_4_1 >> 1)) & 127;
  int stage_v_117_2 = ((stage_v_84_2 << 1) ^ (pub_r001945_4_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_117_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_117_2 + 1) & 15;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = ((stage_v_57_1 << 1) ^ (pub_r001945_8_1 >> 1)) & 127;
  int stage_v_118_2 = ((stage_v_57_2 << 1) ^ (pub_r001945_8_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_118_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_118_2 + 1) & 15;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = ((sec_r001945_4_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_119_2 = ((sec_r001945_4_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_119_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_119_2 + 1) & 15;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = ((pub_r001945_7_1 * 2) + 39) & 63;
  int stage_v_120_2 = ((pub_r001945_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001945_20_1 * 2) + 7) & 63;
  int stage_v_121_2 = ((pub_r001945_20_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((stage_v_70_1 << 1) ^ (pub_r001945_14_1 >> 1)) & 127;
  int stage_v_122_2 = ((stage_v_70_2 << 1) ^ (pub_r001945_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_122_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_122_2 + 1) & 15;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = ((pub_r001945_19_1 * 2) + 37) & 63;
  int stage_v_123_2 = ((pub_r001945_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((sec_r001945_8_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_124_2 = ((sec_r001945_8_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_124_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_124_2 + 1) & 15;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = ((stage_v_16_1 << 1) ^ (pub_r001945_0_1 >> 1)) & 127;
  int stage_v_125_2 = ((stage_v_16_2 << 1) ^ (pub_r001945_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_125_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_125_2 + 1) & 15;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = ((stage_v_89_1 << 1) ^ (pub_r001945_0_1 >> 1)) & 127;
  int stage_v_126_2 = ((stage_v_89_2 << 1) ^ (pub_r001945_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_126_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_126_2 + 1) & 15;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = ((stage_v_119_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_127_2 = ((stage_v_119_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_127_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_127_2 + 1) & 15;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = ((stage_v_24_1 << 1) ^ (pub_r001945_6_1 >> 1)) & 127;
  int stage_v_128_2 = ((stage_v_24_2 << 1) ^ (pub_r001945_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_128_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_128_2 + 1) & 15;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = ((pub_r001945_17_1 * 2) + 42) & 63;
  int stage_v_129_2 = ((pub_r001945_17_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001945_18_1 * 2) + 32) & 63;
  int stage_v_130_2 = ((pub_r001945_18_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((sec_r001945_16_1 << 1) ^ (pub_r001945_1_1 >> 1)) & 127;
  int stage_v_131_2 = ((sec_r001945_16_2 << 1) ^ (pub_r001945_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_131_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_131_2 + 1) & 15;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = ((pub_r001945_15_1 * 2) + 43) & 63;
  int stage_v_132_2 = ((pub_r001945_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001945_20_1 * 2) + 8) & 63;
  int stage_v_133_2 = ((pub_r001945_20_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001945_20_1 * 2) + 10) & 63;
  int stage_v_134_2 = ((pub_r001945_20_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001945_1_1 * 2) + 16) & 63;
  int stage_v_135_2 = ((pub_r001945_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001945_14_1 * 2) + 49) & 63;
  int stage_v_136_2 = ((pub_r001945_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((stage_v_50_1 << 1) ^ (pub_r001945_5_1 >> 1)) & 127;
  int stage_v_137_2 = ((stage_v_50_2 << 1) ^ (pub_r001945_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_137_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_137_2 + 1) & 15;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = ((stage_v_41_1 << 1) ^ (pub_r001945_8_1 >> 1)) & 127;
  int stage_v_138_2 = ((stage_v_41_2 << 1) ^ (pub_r001945_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_138_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_138_2 + 1) & 15;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = ((pub_r001945_22_1 * 2) + 38) & 63;
  int stage_v_139_2 = ((pub_r001945_22_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001945_11_1 * 2) + 44) & 63;
  int stage_v_140_2 = ((pub_r001945_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((stage_v_69_1 << 1) ^ (pub_r001945_8_1 >> 1)) & 127;
  int stage_v_141_2 = ((stage_v_69_2 << 1) ^ (pub_r001945_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_141_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_141_2 + 1) & 15;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = ((stage_v_127_1 << 1) ^ (pub_r001945_22_1 >> 1)) & 127;
  int stage_v_142_2 = ((stage_v_127_2 << 1) ^ (pub_r001945_22_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_142_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_142_2 + 1) & 15;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = ((pub_r001945_20_1 * 2) + 28) & 63;
  int stage_v_143_2 = ((pub_r001945_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((stage_v_95_1 << 1) ^ (pub_r001945_3_1 >> 1)) & 127;
  int stage_v_144_2 = ((stage_v_95_2 << 1) ^ (pub_r001945_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_144_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_144_2 + 1) & 15;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = ((pub_r001945_17_1 * 2) + 25) & 63;
  int stage_v_145_2 = ((pub_r001945_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001945_19_1 * 2) + 46) & 63;
  int stage_v_146_2 = ((pub_r001945_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((stage_v_11_1 << 1) ^ (pub_r001945_1_1 >> 1)) & 127;
  int stage_v_147_2 = ((stage_v_11_2 << 1) ^ (pub_r001945_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_147_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_147_2 + 1) & 15;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = ((stage_v_70_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_148_2 = ((stage_v_70_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_148_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_148_2 + 1) & 15;
  out_sink_1 ^= stage_v_148_1 & 63;
  out_sink_2 ^= stage_v_148_2 & 63;
  int stage_v_149_1 = ((stage_v_142_1 << 1) ^ (pub_r001945_3_1 >> 1)) & 127;
  int stage_v_149_2 = ((stage_v_142_2 << 1) ^ (pub_r001945_3_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_149_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_149_2 + 1) & 15;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = ((stage_v_105_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_150_2 = ((stage_v_105_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_150_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_150_2 + 1) & 15;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = ((pub_r001945_4_1 * 2) + 34) & 63;
  int stage_v_151_2 = ((pub_r001945_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001945_15_1 * 2) + 33) & 63;
  int stage_v_152_2 = ((pub_r001945_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((sec_r001945_5_1 << 1) ^ (pub_r001945_2_1 >> 1)) & 127;
  int stage_v_153_2 = ((sec_r001945_5_2 << 1) ^ (pub_r001945_2_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_153_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_153_2 + 1) & 15;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = ((stage_v_109_1 << 1) ^ (pub_r001945_16_1 >> 1)) & 127;
  int stage_v_154_2 = ((stage_v_109_2 << 1) ^ (pub_r001945_16_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_154_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_154_2 + 1) & 15;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = ((stage_v_92_1 << 1) ^ (pub_r001945_7_1 >> 1)) & 127;
  int stage_v_155_2 = ((stage_v_92_2 << 1) ^ (pub_r001945_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_155_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_155_2 + 1) & 15;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = ((stage_v_50_1 << 1) ^ (pub_r001945_10_1 >> 1)) & 127;
  int stage_v_156_2 = ((stage_v_50_2 << 1) ^ (pub_r001945_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_156_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_156_2 + 1) & 15;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = ((stage_v_104_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_157_2 = ((stage_v_104_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_157_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_157_2 + 1) & 15;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = ((pub_r001945_18_1 * 2) + 20) & 63;
  int stage_v_158_2 = ((pub_r001945_18_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((stage_v_118_1 << 1) ^ (pub_r001945_3_1 >> 1)) & 127;
  int stage_v_159_2 = ((stage_v_118_2 << 1) ^ (pub_r001945_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_159_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_159_2 + 1) & 15;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = ((stage_v_128_1 << 1) ^ (pub_r001945_6_1 >> 1)) & 127;
  int stage_v_160_2 = ((stage_v_128_2 << 1) ^ (pub_r001945_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_160_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_160_2 + 1) & 15;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = ((stage_v_82_1 << 1) ^ (pub_r001945_4_1 >> 1)) & 127;
  int stage_v_161_2 = ((stage_v_82_2 << 1) ^ (pub_r001945_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_161_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_161_2 + 1) & 15;
  out_sink_1 ^= stage_v_161_1 & 63;
  out_sink_2 ^= stage_v_161_2 & 63;
  int stage_v_162_1 = ((pub_r001945_19_1 * 2) + 48) & 63;
  int stage_v_162_2 = ((pub_r001945_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((stage_v_6_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_163_2 = ((stage_v_6_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_163_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_163_2 + 1) & 15;
  out_sink_1 ^= stage_v_163_1 & 63;
  out_sink_2 ^= stage_v_163_2 & 63;
  int stage_v_164_1 = ((pub_r001945_5_1 * 2) + 14) & 63;
  int stage_v_164_2 = ((pub_r001945_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((sec_r001945_11_1 << 1) ^ (pub_r001945_9_1 >> 1)) & 127;
  int stage_v_165_2 = ((sec_r001945_11_2 << 1) ^ (pub_r001945_9_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_165_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_165_2 + 1) & 15;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = ((stage_v_39_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_166_2 = ((stage_v_39_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_166_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_166_2 + 1) & 15;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = ((stage_v_75_1 << 1) ^ (pub_r001945_0_1 >> 1)) & 127;
  int stage_v_167_2 = ((stage_v_75_2 << 1) ^ (pub_r001945_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_167_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_167_2 + 1) & 15;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = ((sec_r001945_3_1 << 1) ^ (pub_r001945_5_1 >> 1)) & 127;
  int stage_v_168_2 = ((sec_r001945_3_2 << 1) ^ (pub_r001945_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_168_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_168_2 + 1) & 15;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = ((pub_r001945_21_1 * 2) + 30) & 63;
  int stage_v_169_2 = ((pub_r001945_21_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((stage_v_18_1 << 1) ^ (pub_r001945_6_1 >> 1)) & 127;
  int stage_v_170_2 = ((stage_v_18_2 << 1) ^ (pub_r001945_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_170_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_170_2 + 1) & 15;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = ((pub_r001945_13_1 * 2) + 36) & 63;
  int stage_v_171_2 = ((pub_r001945_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_28_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_172_2 = ((stage_v_28_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_172_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_172_2 + 1) & 15;
  out_sink_1 ^= stage_v_172_1 & 63;
  out_sink_2 ^= stage_v_172_2 & 63;
  int stage_v_173_1 = ((pub_r001945_4_1 * 2) + 29) & 63;
  int stage_v_173_2 = ((pub_r001945_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001945_15_1 * 2) + 6) & 63;
  int stage_v_174_2 = ((pub_r001945_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001945_10_1 * 2) + 28) & 63;
  int stage_v_175_2 = ((pub_r001945_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001945_2_1 * 2) + 41) & 63;
  int stage_v_176_2 = ((pub_r001945_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((stage_v_167_1 << 1) ^ (pub_r001945_19_1 >> 1)) & 127;
  int stage_v_177_2 = ((stage_v_167_2 << 1) ^ (pub_r001945_19_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_177_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_177_2 + 1) & 15;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = ((stage_v_160_1 << 1) ^ (pub_r001945_0_1 >> 1)) & 127;
  int stage_v_178_2 = ((stage_v_160_2 << 1) ^ (pub_r001945_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_178_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_178_2 + 1) & 15;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = ((pub_r001945_15_1 * 2) + 37) & 63;
  int stage_v_179_2 = ((pub_r001945_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((sec_r001945_10_1 << 1) ^ (pub_r001945_5_1 >> 1)) & 127;
  int stage_v_180_2 = ((sec_r001945_10_2 << 1) ^ (pub_r001945_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_180_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_180_2 + 1) & 15;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = ((pub_r001945_18_1 * 2) + 37) & 63;
  int stage_v_181_2 = ((pub_r001945_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_104_1 << 1) ^ (pub_r001945_2_1 >> 1)) & 127;
  int stage_v_182_2 = ((stage_v_104_2 << 1) ^ (pub_r001945_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_182_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_182_2 + 1) & 15;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = ((stage_v_65_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_183_2 = ((stage_v_65_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_183_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_183_2 + 1) & 15;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = ((pub_r001945_1_1 * 2) + 41) & 63;
  int stage_v_184_2 = ((pub_r001945_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((stage_v_2_1 << 1) ^ (pub_r001945_10_1 >> 1)) & 127;
  int stage_v_185_2 = ((stage_v_2_2 << 1) ^ (pub_r001945_10_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_185_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_185_2 + 1) & 15;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = ((pub_r001945_9_1 * 2) + 48) & 63;
  int stage_v_186_2 = ((pub_r001945_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_6_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_187_2 = ((stage_v_6_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_187_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_187_2 + 1) & 15;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = ((stage_v_165_1 << 1) ^ (pub_r001945_1_1 >> 1)) & 127;
  int stage_v_188_2 = ((stage_v_165_2 << 1) ^ (pub_r001945_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_188_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_188_2 + 1) & 15;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = ((sec_r001945_5_1 << 1) ^ (pub_r001945_3_1 >> 1)) & 127;
  int stage_v_189_2 = ((sec_r001945_5_2 << 1) ^ (pub_r001945_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_189_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_189_2 + 1) & 15;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = ((helper_flow_0_1 << 1) ^ (pub_r001945_1_1 >> 1)) & 127;
  int stage_v_190_2 = ((helper_flow_0_2 << 1) ^ (pub_r001945_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_190_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_190_2 + 1) & 15;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = ((stage_v_93_1 << 1) ^ (pub_r001945_0_1 >> 1)) & 127;
  int stage_v_191_2 = ((stage_v_93_2 << 1) ^ (pub_r001945_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((stage_v_113_1 << 1) ^ (pub_r001945_12_1 >> 1)) & 127;
  int stage_v_192_2 = ((stage_v_113_2 << 1) ^ (pub_r001945_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_192_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_192_2 + 1) & 15;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = ((pub_r001945_6_1 * 2) + 15) & 63;
  int stage_v_193_2 = ((pub_r001945_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_79_1 << 1) ^ (pub_r001945_11_1 >> 1)) & 127;
  int stage_v_194_2 = ((stage_v_79_2 << 1) ^ (pub_r001945_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_194_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_194_2 + 1) & 15;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = ((stage_v_153_1 << 1) ^ (pub_r001945_18_1 >> 1)) & 127;
  int stage_v_195_2 = ((stage_v_153_2 << 1) ^ (pub_r001945_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_195_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_195_2 + 1) & 15;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = ((stage_v_69_1 << 1) ^ (pub_r001945_9_1 >> 1)) & 127;
  int stage_v_196_2 = ((stage_v_69_2 << 1) ^ (pub_r001945_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_196_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_196_2 + 1) & 15;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = ((stage_v_53_1 << 1) ^ (pub_r001945_5_1 >> 1)) & 127;
  int stage_v_197_2 = ((stage_v_53_2 << 1) ^ (pub_r001945_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_197_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_197_2 + 1) & 15;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = ((stage_v_156_1 << 1) ^ (pub_r001945_16_1 >> 1)) & 127;
  int stage_v_198_2 = ((stage_v_156_2 << 1) ^ (pub_r001945_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_198_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_198_2 + 1) & 15;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = ((stage_v_196_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_199_2 = ((stage_v_196_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_199_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_199_2 + 1) & 15;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = ((pub_r001945_21_1 * 2) + 22) & 63;
  int stage_v_200_2 = ((pub_r001945_21_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((stage_v_197_1 << 1) ^ (pub_r001945_14_1 >> 1)) & 127;
  int stage_v_201_2 = ((stage_v_197_2 << 1) ^ (pub_r001945_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_201_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_201_2 + 1) & 15;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = ((stage_v_194_1 << 1) ^ (pub_r001945_12_1 >> 1)) & 127;
  int stage_v_202_2 = ((stage_v_194_2 << 1) ^ (pub_r001945_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_202_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_202_2 + 1) & 15;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = ((stage_v_94_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_203_2 = ((stage_v_94_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_203_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_203_2 + 1) & 15;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = ((pub_r001945_3_1 * 2) + 32) & 63;
  int stage_v_204_2 = ((pub_r001945_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001945_16_1 * 2) + 10) & 63;
  int stage_v_205_2 = ((pub_r001945_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001945_1_1 * 2) + 11) & 63;
  int stage_v_206_2 = ((pub_r001945_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((stage_v_31_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_207_2 = ((stage_v_31_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_207_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_207_2 + 1) & 15;
  out_sink_1 ^= stage_v_207_1 & 63;
  out_sink_2 ^= stage_v_207_2 & 63;
  int stage_v_208_1 = ((stage_v_82_1 << 1) ^ (pub_r001945_17_1 >> 1)) & 127;
  int stage_v_208_2 = ((stage_v_82_2 << 1) ^ (pub_r001945_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_208_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_208_2 + 1) & 15;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = ((stage_v_161_1 << 1) ^ (pub_r001945_3_1 >> 1)) & 127;
  int stage_v_209_2 = ((stage_v_161_2 << 1) ^ (pub_r001945_3_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_209_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_209_2 + 1) & 15;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = ((stage_v_148_1 << 1) ^ (pub_r001945_5_1 >> 1)) & 127;
  int stage_v_210_2 = ((stage_v_148_2 << 1) ^ (pub_r001945_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_210_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_210_2 + 1) & 15;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = ((sec_r001945_3_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_211_2 = ((sec_r001945_3_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_211_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_211_2 + 1) & 15;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = ((pub_r001945_1_1 * 2) + 13) & 63;
  int stage_v_212_2 = ((pub_r001945_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((stage_v_56_1 << 1) ^ (pub_r001945_0_1 >> 1)) & 127;
  int stage_v_213_2 = ((stage_v_56_2 << 1) ^ (pub_r001945_0_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_213_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_213_2 + 1) & 15;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = ((pub_r001945_12_1 * 2) + 38) & 63;
  int stage_v_214_2 = ((pub_r001945_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001945_13_1 * 2) + 18) & 63;
  int stage_v_215_2 = ((pub_r001945_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((stage_v_142_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_216_2 = ((stage_v_142_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_216_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_216_2 + 1) & 15;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = ((stage_v_153_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_217_2 = ((stage_v_153_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_217_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_217_2 + 1) & 15;
  out_sink_1 ^= stage_v_217_1 & 63;
  out_sink_2 ^= stage_v_217_2 & 63;
  int stage_v_218_1 = ((pub_r001945_0_1 * 2) + 37) & 63;
  int stage_v_218_2 = ((pub_r001945_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((sec_r001945_13_1 << 1) ^ (pub_r001945_1_1 >> 1)) & 127;
  int stage_v_219_2 = ((sec_r001945_13_2 << 1) ^ (pub_r001945_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_219_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_219_2 + 1) & 15;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = ((sec_r001945_9_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_220_2 = ((sec_r001945_9_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_220_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_220_2 + 1) & 15;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = ((stage_v_128_1 << 1) ^ (pub_r001945_8_1 >> 1)) & 127;
  int stage_v_221_2 = ((stage_v_128_2 << 1) ^ (pub_r001945_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_221_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_221_2 + 1) & 15;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = ((stage_v_6_1 << 1) ^ (pub_r001945_10_1 >> 1)) & 127;
  int stage_v_222_2 = ((stage_v_6_2 << 1) ^ (pub_r001945_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_222_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_222_2 + 1) & 15;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = ((stage_v_8_1 << 1) ^ (pub_r001945_8_1 >> 1)) & 127;
  int stage_v_223_2 = ((stage_v_8_2 << 1) ^ (pub_r001945_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_223_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_223_2 + 1) & 15;
  out_sink_1 ^= stage_v_223_1 & 63;
  out_sink_2 ^= stage_v_223_2 & 63;
  int stage_v_224_1 = ((pub_r001945_13_1 * 2) + 11) & 63;
  int stage_v_224_2 = ((pub_r001945_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001945_4_1 * 2) + 40) & 63;
  int stage_v_225_2 = ((pub_r001945_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((stage_v_197_1 << 1) ^ (pub_r001945_6_1 >> 1)) & 127;
  int stage_v_226_2 = ((stage_v_197_2 << 1) ^ (pub_r001945_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_226_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_226_2 + 1) & 15;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = ((pub_r001945_8_1 * 2) + 36) & 63;
  int stage_v_227_2 = ((pub_r001945_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001945_11_1 * 2) + 34) & 63;
  int stage_v_228_2 = ((pub_r001945_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((stage_v_217_1 << 1) ^ (pub_r001945_9_1 >> 1)) & 127;
  int stage_v_229_2 = ((stage_v_217_2 << 1) ^ (pub_r001945_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_229_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_229_2 + 1) & 15;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = ((pub_r001945_17_1 * 2) + 19) & 63;
  int stage_v_230_2 = ((pub_r001945_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001945_11_1 * 2) + 37) & 63;
  int stage_v_231_2 = ((pub_r001945_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((helper_flow_6_1 << 1) ^ (pub_r001945_1_1 >> 1)) & 127;
  int stage_v_232_2 = ((helper_flow_6_2 << 1) ^ (pub_r001945_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_232_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_232_2 + 1) & 15;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = ((pub_r001945_17_1 * 2) + 19) & 63;
  int stage_v_233_2 = ((pub_r001945_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001945_4_1 * 2) + 7) & 63;
  int stage_v_234_2 = ((pub_r001945_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((sec_r001945_10_1 << 1) ^ (pub_r001945_0_1 >> 1)) & 127;
  int stage_v_235_2 = ((sec_r001945_10_2 << 1) ^ (pub_r001945_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_235_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_235_2 + 1) & 15;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = ((stage_v_9_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_236_2 = ((stage_v_9_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_236_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_236_2 + 1) & 15;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = ((stage_v_75_1 << 1) ^ (pub_r001945_16_1 >> 1)) & 127;
  int stage_v_237_2 = ((stage_v_75_2 << 1) ^ (pub_r001945_16_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_237_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_237_2 + 1) & 15;
  out_sink_1 ^= stage_v_237_1 & 63;
  out_sink_2 ^= stage_v_237_2 & 63;
  int stage_v_238_1 = ((stage_v_188_1 << 1) ^ (pub_r001945_10_1 >> 1)) & 127;
  int stage_v_238_2 = ((stage_v_188_2 << 1) ^ (pub_r001945_10_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_238_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_238_2 + 1) & 15;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = ((pub_r001945_5_1 * 2) + 26) & 63;
  int stage_v_239_2 = ((pub_r001945_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((stage_v_80_1 << 1) ^ (pub_r001945_22_1 >> 1)) & 127;
  int stage_v_240_2 = ((stage_v_80_2 << 1) ^ (pub_r001945_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_240_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_240_2 + 1) & 15;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = ((pub_r001945_12_1 * 2) + 29) & 63;
  int stage_v_241_2 = ((pub_r001945_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((pub_r001945_10_1 * 2) + 47) & 63;
  int stage_v_242_2 = ((pub_r001945_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001945_12_1 * 2) + 20) & 63;
  int stage_v_243_2 = ((pub_r001945_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((stage_v_9_1 << 1) ^ (pub_r001945_3_1 >> 1)) & 127;
  int stage_v_244_2 = ((stage_v_9_2 << 1) ^ (pub_r001945_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_244_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_244_2 + 1) & 15;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = ((stage_v_160_1 << 1) ^ (pub_r001945_2_1 >> 1)) & 127;
  int stage_v_245_2 = ((stage_v_160_2 << 1) ^ (pub_r001945_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_245_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_245_2 + 1) & 15;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = ((stage_v_159_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_246_2 = ((stage_v_159_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_246_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_246_2 + 1) & 15;
  out_sink_1 ^= stage_v_246_1 & 63;
  out_sink_2 ^= stage_v_246_2 & 63;
  int stage_v_247_1 = ((stage_v_138_1 << 1) ^ (pub_r001945_18_1 >> 1)) & 127;
  int stage_v_247_2 = ((stage_v_138_2 << 1) ^ (pub_r001945_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_247_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_247_2 + 1) & 15;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = ((pub_r001945_22_1 * 2) + 9) & 63;
  int stage_v_248_2 = ((pub_r001945_22_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001945_21_1 * 2) + 29) & 63;
  int stage_v_249_2 = ((pub_r001945_21_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((stage_v_81_1 << 1) ^ (pub_r001945_12_1 >> 1)) & 127;
  int stage_v_250_2 = ((stage_v_81_2 << 1) ^ (pub_r001945_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_250_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_250_2 + 1) & 15;
  out_sink_1 ^= stage_v_250_1 & 63;
  out_sink_2 ^= stage_v_250_2 & 63;
  int stage_v_251_1 = ((stage_v_126_1 << 1) ^ (pub_r001945_2_1 >> 1)) & 127;
  int stage_v_251_2 = ((stage_v_126_2 << 1) ^ (pub_r001945_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_251_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_251_2 + 1) & 15;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = ((stage_v_101_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_252_2 = ((stage_v_101_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_252_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_252_2 + 1) & 15;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = ((stage_v_25_1 << 1) ^ (pub_r001945_7_1 >> 1)) & 127;
  int stage_v_253_2 = ((stage_v_25_2 << 1) ^ (pub_r001945_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((pub_r001945_5_1 * 2) + 46) & 63;
  int stage_v_254_2 = ((pub_r001945_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((stage_v_34_1 << 1) ^ (pub_r001945_9_1 >> 1)) & 127;
  int stage_v_255_2 = ((stage_v_34_2 << 1) ^ (pub_r001945_9_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_255_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_255_2 + 1) & 15;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = ((stage_v_110_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_256_2 = ((stage_v_110_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((stage_v_252_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_257_2 = ((stage_v_252_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_257_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_257_2 + 1) & 15;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = ((pub_r001945_12_1 * 2) + 17) & 63;
  int stage_v_258_2 = ((pub_r001945_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((stage_v_257_1 << 1) ^ (pub_r001945_17_1 >> 1)) & 127;
  int stage_v_259_2 = ((stage_v_257_2 << 1) ^ (pub_r001945_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_259_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_259_2 + 1) & 15;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = ((stage_v_104_1 << 1) ^ (pub_r001945_10_1 >> 1)) & 127;
  int stage_v_260_2 = ((stage_v_104_2 << 1) ^ (pub_r001945_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_260_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_260_2 + 1) & 15;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = ((stage_v_196_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_261_2 = ((stage_v_196_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_261_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_261_2 + 1) & 15;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = ((pub_r001945_1_1 * 2) + 25) & 63;
  int stage_v_262_2 = ((pub_r001945_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001945_14_1 * 2) + 42) & 63;
  int stage_v_263_2 = ((pub_r001945_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((stage_v_207_1 << 1) ^ (pub_r001945_4_1 >> 1)) & 127;
  int stage_v_264_2 = ((stage_v_207_2 << 1) ^ (pub_r001945_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_264_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_264_2 + 1) & 15;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = ((stage_v_217_1 << 1) ^ (pub_r001945_3_1 >> 1)) & 127;
  int stage_v_265_2 = ((stage_v_217_2 << 1) ^ (pub_r001945_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_265_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_265_2 + 1) & 15;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = ((pub_r001945_20_1 * 2) + 38) & 63;
  int stage_v_266_2 = ((pub_r001945_20_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001945_9_1 * 2) + 34) & 63;
  int stage_v_267_2 = ((pub_r001945_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001945_8_1 * 2) + 11) & 63;
  int stage_v_268_2 = ((pub_r001945_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001945_11_1 * 2) + 19) & 63;
  int stage_v_269_2 = ((pub_r001945_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001945_17_1 * 2) + 9) & 63;
  int stage_v_270_2 = ((pub_r001945_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001945_3_1 * 2) + 29) & 63;
  int stage_v_271_2 = ((pub_r001945_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001945_9_1 * 2) + 28) & 63;
  int stage_v_272_2 = ((pub_r001945_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001945_17_1 * 2) + 38) & 63;
  int stage_v_273_2 = ((pub_r001945_17_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((stage_v_84_1 << 1) ^ (pub_r001945_5_1 >> 1)) & 127;
  int stage_v_274_2 = ((stage_v_84_2 << 1) ^ (pub_r001945_5_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_274_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_274_2 + 1) & 15;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = ((stage_v_124_1 << 1) ^ (pub_r001945_11_1 >> 1)) & 127;
  int stage_v_275_2 = ((stage_v_124_2 << 1) ^ (pub_r001945_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_275_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_275_2 + 1) & 15;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = ((stage_v_256_1 << 1) ^ (pub_r001945_5_1 >> 1)) & 127;
  int stage_v_276_2 = ((stage_v_256_2 << 1) ^ (pub_r001945_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_276_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_276_2 + 1) & 15;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = ((stage_v_117_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_277_2 = ((stage_v_117_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_277_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_277_2 + 1) & 15;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = ((stage_v_168_1 << 1) ^ (pub_r001945_9_1 >> 1)) & 127;
  int stage_v_278_2 = ((stage_v_168_2 << 1) ^ (pub_r001945_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_278_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_278_2 + 1) & 15;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = ((stage_v_159_1 << 1) ^ (pub_r001945_1_1 >> 1)) & 127;
  int stage_v_279_2 = ((stage_v_159_2 << 1) ^ (pub_r001945_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_279_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_279_2 + 1) & 15;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = ((pub_r001945_3_1 * 2) + 22) & 63;
  int stage_v_280_2 = ((pub_r001945_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((stage_v_89_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_281_2 = ((stage_v_89_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_281_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_281_2 + 1) & 15;
  out_sink_1 ^= stage_v_281_1 & 63;
  out_sink_2 ^= stage_v_281_2 & 63;
  int stage_v_282_1 = ((stage_v_67_1 << 1) ^ (pub_r001945_3_1 >> 1)) & 127;
  int stage_v_282_2 = ((stage_v_67_2 << 1) ^ (pub_r001945_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_282_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_282_2 + 1) & 15;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = ((pub_r001945_6_1 * 2) + 46) & 63;
  int stage_v_283_2 = ((pub_r001945_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((stage_v_191_1 << 1) ^ (pub_r001945_4_1 >> 1)) & 127;
  int stage_v_284_2 = ((stage_v_191_2 << 1) ^ (pub_r001945_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_284_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_284_2 + 1) & 15;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = ((pub_r001945_12_1 * 2) + 41) & 63;
  int stage_v_285_2 = ((pub_r001945_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001945_8_1 * 2) + 16) & 63;
  int stage_v_286_2 = ((pub_r001945_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((stage_v_126_1 << 1) ^ (pub_r001945_7_1 >> 1)) & 127;
  int stage_v_287_2 = ((stage_v_126_2 << 1) ^ (pub_r001945_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_287_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_287_2 + 1) & 15;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = ((stage_v_238_1 << 1) ^ (pub_r001945_18_1 >> 1)) & 127;
  int stage_v_288_2 = ((stage_v_238_2 << 1) ^ (pub_r001945_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_288_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_288_2 + 1) & 15;
  out_sink_1 ^= stage_v_288_1 & 63;
  out_sink_2 ^= stage_v_288_2 & 63;
  int stage_v_289_1 = ((pub_r001945_15_1 * 2) + 48) & 63;
  int stage_v_289_2 = ((pub_r001945_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001945_12_1 * 2) + 18) & 63;
  int stage_v_290_2 = ((pub_r001945_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((pub_r001945_6_1 * 2) + 24) & 63;
  int stage_v_291_2 = ((pub_r001945_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001945_8_1 * 2) + 40) & 63;
  int stage_v_292_2 = ((pub_r001945_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001945_8_1 * 2) + 8) & 63;
  int stage_v_293_2 = ((pub_r001945_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001945_0_1 * 2) + 10) & 63;
  int stage_v_294_2 = ((pub_r001945_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001945_7_1 * 2) + 8) & 63;
  int stage_v_295_2 = ((pub_r001945_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((pub_r001945_7_1 * 2) + 35) & 63;
  int stage_v_296_2 = ((pub_r001945_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001945_20_1 * 2) + 29) & 63;
  int stage_v_297_2 = ((pub_r001945_20_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001945_16_1 * 2) + 28) & 63;
  int stage_v_298_2 = ((pub_r001945_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((stage_v_220_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_299_2 = ((stage_v_220_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_299_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_299_2 + 1) & 15;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = ((stage_v_99_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_300_2 = ((stage_v_99_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_300_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_300_2 + 1) & 15;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = ((pub_r001945_15_1 * 2) + 47) & 63;
  int stage_v_301_2 = ((pub_r001945_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((stage_v_208_1 << 1) ^ (pub_r001945_19_1 >> 1)) & 127;
  int stage_v_302_2 = ((stage_v_208_2 << 1) ^ (pub_r001945_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_302_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_302_2 + 1) & 15;
  out_sink_1 ^= stage_v_302_1 & 63;
  out_sink_2 ^= stage_v_302_2 & 63;
  int stage_v_303_1 = ((stage_v_261_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_303_2 = ((stage_v_261_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_303_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_303_2 + 1) & 15;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = ((stage_v_246_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_304_2 = ((stage_v_246_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_304_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_304_2 + 1) & 15;
  out_sink_1 ^= stage_v_304_1 & 63;
  out_sink_2 ^= stage_v_304_2 & 63;
  int stage_v_305_1 = ((stage_v_229_1 << 1) ^ (pub_r001945_18_1 >> 1)) & 127;
  int stage_v_305_2 = ((stage_v_229_2 << 1) ^ (pub_r001945_18_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_305_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_305_2 + 1) & 15;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  int stage_v_306_1 = ((stage_v_201_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_306_2 = ((stage_v_201_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_306_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_306_2 + 1) & 15;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = ((stage_v_220_1 << 1) ^ (pub_r001945_16_1 >> 1)) & 127;
  int stage_v_307_2 = ((stage_v_220_2 << 1) ^ (pub_r001945_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_307_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_307_2 + 1) & 15;
  out_sink_1 ^= stage_v_307_1 & 63;
  out_sink_2 ^= stage_v_307_2 & 63;
  int stage_v_308_1 = ((stage_v_80_1 << 1) ^ (pub_r001945_12_1 >> 1)) & 127;
  int stage_v_308_2 = ((stage_v_80_2 << 1) ^ (pub_r001945_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_308_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_308_2 + 1) & 15;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = ((pub_r001945_16_1 * 2) + 16) & 63;
  int stage_v_309_2 = ((pub_r001945_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((stage_v_94_1 << 1) ^ (pub_r001945_11_1 >> 1)) & 127;
  int stage_v_310_2 = ((stage_v_94_2 << 1) ^ (pub_r001945_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_310_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_310_2 + 1) & 15;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = ((stage_v_69_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_311_2 = ((stage_v_69_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_311_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_311_2 + 1) & 15;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = ((pub_r001945_8_1 * 2) + 46) & 63;
  int stage_v_312_2 = ((pub_r001945_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((stage_v_42_1 << 1) ^ (pub_r001945_22_1 >> 1)) & 127;
  int stage_v_313_2 = ((stage_v_42_2 << 1) ^ (pub_r001945_22_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_313_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_313_2 + 1) & 15;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = ((pub_r001945_16_1 * 2) + 47) & 63;
  int stage_v_314_2 = ((pub_r001945_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001945_10_1 * 2) + 29) & 63;
  int stage_v_315_2 = ((pub_r001945_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((stage_v_148_1 << 1) ^ (pub_r001945_6_1 >> 1)) & 127;
  int stage_v_316_2 = ((stage_v_148_2 << 1) ^ (pub_r001945_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_316_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_316_2 + 1) & 15;
  out_sink_1 ^= stage_v_316_1 & 63;
  out_sink_2 ^= stage_v_316_2 & 63;
  int stage_v_317_1 = ((pub_r001945_0_1 * 2) + 43) & 63;
  int stage_v_317_2 = ((pub_r001945_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001945_22_1 * 2) + 12) & 63;
  int stage_v_318_2 = ((pub_r001945_22_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001945_9_1 * 2) + 12) & 63;
  int stage_v_319_2 = ((pub_r001945_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((stage_v_275_1 << 1) ^ (pub_r001945_9_1 >> 1)) & 127;
  int stage_v_320_2 = ((stage_v_275_2 << 1) ^ (pub_r001945_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_320_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_320_2 + 1) & 15;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = ((stage_v_144_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_321_2 = ((stage_v_144_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_321_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_321_2 + 1) & 15;
  out_sink_1 ^= stage_v_321_1 & 63;
  out_sink_2 ^= stage_v_321_2 & 63;
  int stage_v_322_1 = ((pub_r001945_15_1 * 2) + 26) & 63;
  int stage_v_322_2 = ((pub_r001945_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001945_15_1 * 2) + 26) & 63;
  int stage_v_323_2 = ((pub_r001945_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((stage_v_96_1 << 1) ^ (pub_r001945_2_1 >> 1)) & 127;
  int stage_v_324_2 = ((stage_v_96_2 << 1) ^ (pub_r001945_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_324_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_324_2 + 1) & 15;
  out_sink_1 ^= stage_v_324_1 & 63;
  out_sink_2 ^= stage_v_324_2 & 63;
  int stage_v_325_1 = ((stage_v_257_1 << 1) ^ (pub_r001945_14_1 >> 1)) & 127;
  int stage_v_325_2 = ((stage_v_257_2 << 1) ^ (pub_r001945_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_325_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_325_2 + 1) & 15;
  out_sink_1 ^= stage_v_325_1 & 63;
  out_sink_2 ^= stage_v_325_2 & 63;
  int stage_v_326_1 = ((stage_v_12_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_326_2 = ((stage_v_12_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_326_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_326_2 + 1) & 15;
  out_sink_1 ^= stage_v_326_1 & 63;
  out_sink_2 ^= stage_v_326_2 & 63;
  int stage_v_327_1 = ((pub_r001945_9_1 * 2) + 26) & 63;
  int stage_v_327_2 = ((pub_r001945_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((stage_v_7_1 << 1) ^ (pub_r001945_8_1 >> 1)) & 127;
  int stage_v_328_2 = ((stage_v_7_2 << 1) ^ (pub_r001945_8_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_328_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_328_2 + 1) & 15;
  out_sink_1 ^= stage_v_328_1 & 63;
  out_sink_2 ^= stage_v_328_2 & 63;
  int stage_v_329_1 = ((stage_v_2_1 << 1) ^ (pub_r001945_0_1 >> 1)) & 127;
  int stage_v_329_2 = ((stage_v_2_2 << 1) ^ (pub_r001945_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_329_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_329_2 + 1) & 15;
  out_sink_1 ^= stage_v_329_1 & 63;
  out_sink_2 ^= stage_v_329_2 & 63;
  int stage_v_330_1 = ((pub_r001945_13_1 * 2) + 37) & 63;
  int stage_v_330_2 = ((pub_r001945_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001945_19_1 * 2) + 17) & 63;
  int stage_v_331_2 = ((pub_r001945_19_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001945_3_1 * 2) + 35) & 63;
  int stage_v_332_2 = ((pub_r001945_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((stage_v_101_1 << 1) ^ (pub_r001945_14_1 >> 1)) & 127;
  int stage_v_333_2 = ((stage_v_101_2 << 1) ^ (pub_r001945_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_333_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_333_2 + 1) & 15;
  out_sink_1 ^= stage_v_333_1 & 63;
  out_sink_2 ^= stage_v_333_2 & 63;
  int stage_v_334_1 = ((stage_v_7_1 << 1) ^ (pub_r001945_1_1 >> 1)) & 127;
  int stage_v_334_2 = ((stage_v_7_2 << 1) ^ (pub_r001945_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_334_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_334_2 + 1) & 15;
  out_sink_1 ^= stage_v_334_1 & 63;
  out_sink_2 ^= stage_v_334_2 & 63;
  int stage_v_335_1 = ((stage_v_252_1 << 1) ^ (pub_r001945_19_1 >> 1)) & 127;
  int stage_v_335_2 = ((stage_v_252_2 << 1) ^ (pub_r001945_19_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_335_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_335_2 + 1) & 15;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = ((pub_r001945_11_1 * 2) + 47) & 63;
  int stage_v_336_2 = ((pub_r001945_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((helper_flow_6_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_337_2 = ((helper_flow_6_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_337_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_337_2 + 1) & 15;
  out_sink_1 ^= stage_v_337_1 & 63;
  out_sink_2 ^= stage_v_337_2 & 63;
  int stage_v_338_1 = ((pub_r001945_19_1 * 2) + 39) & 63;
  int stage_v_338_2 = ((pub_r001945_19_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001945_8_1 * 2) + 26) & 63;
  int stage_v_339_2 = ((pub_r001945_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001945_9_1 * 2) + 29) & 63;
  int stage_v_340_2 = ((pub_r001945_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((stage_v_75_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_341_2 = ((stage_v_75_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_341_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_341_2 + 1) & 15;
  out_sink_1 ^= stage_v_341_1 & 63;
  out_sink_2 ^= stage_v_341_2 & 63;
  int stage_v_342_1 = ((pub_r001945_3_1 * 2) + 7) & 63;
  int stage_v_342_2 = ((pub_r001945_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001945_7_1 * 2) + 38) & 63;
  int stage_v_343_2 = ((pub_r001945_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((stage_v_80_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_344_2 = ((stage_v_80_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_344_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_344_2 + 1) & 15;
  out_sink_1 ^= stage_v_344_1 & 63;
  out_sink_2 ^= stage_v_344_2 & 63;
  int stage_v_345_1 = ((stage_v_55_1 << 1) ^ (pub_r001945_9_1 >> 1)) & 127;
  int stage_v_345_2 = ((stage_v_55_2 << 1) ^ (pub_r001945_9_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_345_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_345_2 + 1) & 15;
  out_sink_1 ^= stage_v_345_1 & 63;
  out_sink_2 ^= stage_v_345_2 & 63;
  int stage_v_346_1 = ((sec_r001945_14_1 << 1) ^ (pub_r001945_17_1 >> 1)) & 127;
  int stage_v_346_2 = ((sec_r001945_14_2 << 1) ^ (pub_r001945_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_346_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_346_2 + 1) & 15;
  out_sink_1 ^= stage_v_346_1 & 63;
  out_sink_2 ^= stage_v_346_2 & 63;
  int stage_v_347_1 = ((stage_v_189_1 << 1) ^ (pub_r001945_8_1 >> 1)) & 127;
  int stage_v_347_2 = ((stage_v_189_2 << 1) ^ (pub_r001945_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_347_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_347_2 + 1) & 15;
  out_sink_1 ^= stage_v_347_1 & 63;
  out_sink_2 ^= stage_v_347_2 & 63;
  int stage_v_348_1 = ((stage_v_36_1 << 1) ^ (pub_r001945_6_1 >> 1)) & 127;
  int stage_v_348_2 = ((stage_v_36_2 << 1) ^ (pub_r001945_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_348_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_348_2 + 1) & 15;
  out_sink_1 ^= stage_v_348_1 & 63;
  out_sink_2 ^= stage_v_348_2 & 63;
  int stage_v_349_1 = ((pub_r001945_17_1 * 2) + 20) & 63;
  int stage_v_349_2 = ((pub_r001945_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((stage_v_281_1 << 1) ^ (pub_r001945_0_1 >> 1)) & 127;
  int stage_v_350_2 = ((stage_v_281_2 << 1) ^ (pub_r001945_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((pub_r001945_20_1 * 2) + 17) & 63;
  int stage_v_351_2 = ((pub_r001945_20_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001945_8_1 * 2) + 5) & 63;
  int stage_v_352_2 = ((pub_r001945_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001945_3_1 * 2) + 32) & 63;
  int stage_v_353_2 = ((pub_r001945_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((stage_v_125_1 << 1) ^ (pub_r001945_19_1 >> 1)) & 127;
  int stage_v_354_2 = ((stage_v_125_2 << 1) ^ (pub_r001945_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_354_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_354_2 + 1) & 15;
  out_sink_1 ^= stage_v_354_1 & 63;
  out_sink_2 ^= stage_v_354_2 & 63;
  int stage_v_355_1 = ((pub_r001945_19_1 * 2) + 31) & 63;
  int stage_v_355_2 = ((pub_r001945_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((stage_v_320_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_356_2 = ((stage_v_320_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_356_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_356_2 + 1) & 15;
  out_sink_1 ^= stage_v_356_1 & 63;
  out_sink_2 ^= stage_v_356_2 & 63;
  int stage_v_357_1 = ((pub_r001945_8_1 * 2) + 6) & 63;
  int stage_v_357_2 = ((pub_r001945_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001945_12_1 * 2) + 6) & 63;
  int stage_v_358_2 = ((pub_r001945_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001945_2_1 * 2) + 40) & 63;
  int stage_v_359_2 = ((pub_r001945_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((stage_v_207_1 << 1) ^ (pub_r001945_14_1 >> 1)) & 127;
  int stage_v_360_2 = ((stage_v_207_2 << 1) ^ (pub_r001945_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_360_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_360_2 + 1) & 15;
  out_sink_1 ^= stage_v_360_1 & 63;
  out_sink_2 ^= stage_v_360_2 & 63;
  int stage_v_361_1 = ((pub_r001945_10_1 * 2) + 16) & 63;
  int stage_v_361_2 = ((pub_r001945_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((stage_v_240_1 << 1) ^ (pub_r001945_10_1 >> 1)) & 127;
  int stage_v_362_2 = ((stage_v_240_2 << 1) ^ (pub_r001945_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_362_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_362_2 + 1) & 15;
  out_sink_1 ^= stage_v_362_1 & 63;
  out_sink_2 ^= stage_v_362_2 & 63;
  int stage_v_363_1 = ((stage_v_238_1 << 1) ^ (pub_r001945_3_1 >> 1)) & 127;
  int stage_v_363_2 = ((stage_v_238_2 << 1) ^ (pub_r001945_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((pub_r001945_15_1 * 2) + 18) & 63;
  int stage_v_364_2 = ((pub_r001945_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((stage_v_329_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_329_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((stage_v_235_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_366_2 = ((stage_v_235_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_366_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_366_2 + 1) & 15;
  out_sink_1 ^= stage_v_366_1 & 63;
  out_sink_2 ^= stage_v_366_2 & 63;
  int stage_v_367_1 = ((pub_r001945_6_1 * 2) + 21) & 63;
  int stage_v_367_2 = ((pub_r001945_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((stage_v_93_1 << 1) ^ (pub_r001945_4_1 >> 1)) & 127;
  int stage_v_368_2 = ((stage_v_93_2 << 1) ^ (pub_r001945_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_368_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_368_2 + 1) & 15;
  out_sink_1 ^= stage_v_368_1 & 63;
  out_sink_2 ^= stage_v_368_2 & 63;
  int stage_v_369_1 = ((pub_r001945_15_1 * 2) + 46) & 63;
  int stage_v_369_2 = ((pub_r001945_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001945_4_1 * 2) + 29) & 63;
  int stage_v_370_2 = ((pub_r001945_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001945_12_1 * 2) + 30) & 63;
  int stage_v_371_2 = ((pub_r001945_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001945_0_1 * 2) + 39) & 63;
  int stage_v_372_2 = ((pub_r001945_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((stage_v_316_1 << 1) ^ (pub_r001945_6_1 >> 1)) & 127;
  int stage_v_373_2 = ((stage_v_316_2 << 1) ^ (pub_r001945_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_373_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_373_2 + 1) & 15;
  out_sink_1 ^= stage_v_373_1 & 63;
  out_sink_2 ^= stage_v_373_2 & 63;
  int stage_v_374_1 = ((stage_v_62_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_374_2 = ((stage_v_62_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_374_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_374_2 + 1) & 15;
  out_sink_1 ^= stage_v_374_1 & 63;
  out_sink_2 ^= stage_v_374_2 & 63;
  int stage_v_375_1 = ((stage_v_155_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_375_2 = ((stage_v_155_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_375_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_375_2 + 1) & 15;
  out_sink_1 ^= stage_v_375_1 & 63;
  out_sink_2 ^= stage_v_375_2 & 63;
  int stage_v_376_1 = ((pub_r001945_9_1 * 2) + 35) & 63;
  int stage_v_376_2 = ((pub_r001945_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((stage_v_131_1 << 1) ^ (pub_r001945_9_1 >> 1)) & 127;
  int stage_v_377_2 = ((stage_v_131_2 << 1) ^ (pub_r001945_9_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_377_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_377_2 + 1) & 15;
  out_sink_1 ^= stage_v_377_1 & 63;
  out_sink_2 ^= stage_v_377_2 & 63;
  int stage_v_378_1 = ((stage_v_84_1 << 1) ^ (pub_r001945_6_1 >> 1)) & 127;
  int stage_v_378_2 = ((stage_v_84_2 << 1) ^ (pub_r001945_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((stage_v_126_1 << 1) ^ (pub_r001945_1_1 >> 1)) & 127;
  int stage_v_379_2 = ((stage_v_126_2 << 1) ^ (pub_r001945_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_379_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_379_2 + 1) & 15;
  out_sink_1 ^= stage_v_379_1 & 63;
  out_sink_2 ^= stage_v_379_2 & 63;
  int stage_v_380_1 = ((stage_v_313_1 << 1) ^ (pub_r001945_22_1 >> 1)) & 127;
  int stage_v_380_2 = ((stage_v_313_2 << 1) ^ (pub_r001945_22_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_380_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_380_2 + 1) & 15;
  out_sink_1 ^= stage_v_380_1 & 63;
  out_sink_2 ^= stage_v_380_2 & 63;
  int stage_v_381_1 = ((stage_v_281_1 << 1) ^ (pub_r001945_7_1 >> 1)) & 127;
  int stage_v_381_2 = ((stage_v_281_2 << 1) ^ (pub_r001945_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_381_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_381_2 + 1) & 15;
  out_sink_1 ^= stage_v_381_1 & 63;
  out_sink_2 ^= stage_v_381_2 & 63;
  int stage_v_382_1 = ((pub_r001945_18_1 * 2) + 44) & 63;
  int stage_v_382_2 = ((pub_r001945_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((stage_v_195_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_383_2 = ((stage_v_195_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_383_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_383_2 + 1) & 15;
  out_sink_1 ^= stage_v_383_1 & 63;
  out_sink_2 ^= stage_v_383_2 & 63;
  int stage_v_384_1 = ((pub_r001945_1_1 * 2) + 18) & 63;
  int stage_v_384_2 = ((pub_r001945_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((stage_v_182_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_385_2 = ((stage_v_182_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_385_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_385_2 + 1) & 15;
  out_sink_1 ^= stage_v_385_1 & 63;
  out_sink_2 ^= stage_v_385_2 & 63;
  int stage_v_386_1 = ((pub_r001945_2_1 * 2) + 47) & 63;
  int stage_v_386_2 = ((pub_r001945_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((stage_v_147_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_387_2 = ((stage_v_147_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_387_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_387_2 + 1) & 15;
  out_sink_1 ^= stage_v_387_1 & 63;
  out_sink_2 ^= stage_v_387_2 & 63;
  int stage_v_388_1 = ((pub_r001945_20_1 * 2) + 10) & 63;
  int stage_v_388_2 = ((pub_r001945_20_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((stage_v_118_1 << 1) ^ (pub_r001945_16_1 >> 1)) & 127;
  int stage_v_389_2 = ((stage_v_118_2 << 1) ^ (pub_r001945_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_389_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_389_2 + 1) & 15;
  out_sink_1 ^= stage_v_389_1 & 63;
  out_sink_2 ^= stage_v_389_2 & 63;
  int stage_v_390_1 = ((pub_r001945_7_1 * 2) + 14) & 63;
  int stage_v_390_2 = ((pub_r001945_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((stage_v_160_1 << 1) ^ (pub_r001945_17_1 >> 1)) & 127;
  int stage_v_391_2 = ((stage_v_160_2 << 1) ^ (pub_r001945_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_391_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_391_2 + 1) & 15;
  out_sink_1 ^= stage_v_391_1 & 63;
  out_sink_2 ^= stage_v_391_2 & 63;
  int stage_v_392_1 = ((pub_r001945_8_1 * 2) + 7) & 63;
  int stage_v_392_2 = ((pub_r001945_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((stage_v_329_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_393_2 = ((stage_v_329_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_393_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_393_2 + 1) & 15;
  out_sink_1 ^= stage_v_393_1 & 63;
  out_sink_2 ^= stage_v_393_2 & 63;
  int stage_v_394_1 = ((sec_r001945_4_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_394_2 = ((sec_r001945_4_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_394_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_394_2 + 1) & 15;
  out_sink_1 ^= stage_v_394_1 & 63;
  out_sink_2 ^= stage_v_394_2 & 63;
  int stage_v_395_1 = ((pub_r001945_20_1 * 2) + 39) & 63;
  int stage_v_395_2 = ((pub_r001945_20_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((stage_v_335_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_396_2 = ((stage_v_335_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_396_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_396_2 + 1) & 15;
  out_sink_1 ^= stage_v_396_1 & 63;
  out_sink_2 ^= stage_v_396_2 & 63;
  int stage_v_397_1 = ((pub_r001945_9_1 * 2) + 19) & 63;
  int stage_v_397_2 = ((pub_r001945_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((stage_v_160_1 << 1) ^ (pub_r001945_2_1 >> 1)) & 127;
  int stage_v_398_2 = ((stage_v_160_2 << 1) ^ (pub_r001945_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_398_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_398_2 + 1) & 15;
  out_sink_1 ^= stage_v_398_1 & 63;
  out_sink_2 ^= stage_v_398_2 & 63;
  int stage_v_399_1 = ((pub_r001945_16_1 * 2) + 30) & 63;
  int stage_v_399_2 = ((pub_r001945_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001945_5_1 * 2) + 22) & 63;
  int stage_v_400_2 = ((pub_r001945_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((stage_v_79_1 << 1) ^ (pub_r001945_2_1 >> 1)) & 127;
  int stage_v_401_2 = ((stage_v_79_2 << 1) ^ (pub_r001945_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_401_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_401_2 + 1) & 15;
  out_sink_1 ^= stage_v_401_1 & 63;
  out_sink_2 ^= stage_v_401_2 & 63;
  int stage_v_402_1 = ((stage_v_383_1 << 1) ^ (pub_r001945_19_1 >> 1)) & 127;
  int stage_v_402_2 = ((stage_v_383_2 << 1) ^ (pub_r001945_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_402_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_402_2 + 1) & 15;
  out_sink_1 ^= stage_v_402_1 & 63;
  out_sink_2 ^= stage_v_402_2 & 63;
  int stage_v_403_1 = ((pub_r001945_17_1 * 2) + 7) & 63;
  int stage_v_403_2 = ((pub_r001945_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((stage_v_190_1 << 1) ^ (pub_r001945_1_1 >> 1)) & 127;
  int stage_v_404_2 = ((stage_v_190_2 << 1) ^ (pub_r001945_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_404_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_404_2 + 1) & 15;
  out_sink_1 ^= stage_v_404_1 & 63;
  out_sink_2 ^= stage_v_404_2 & 63;
  int stage_v_405_1 = ((pub_r001945_1_1 * 2) + 29) & 63;
  int stage_v_405_2 = ((pub_r001945_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((stage_v_147_1 << 1) ^ (pub_r001945_12_1 >> 1)) & 127;
  int stage_v_406_2 = ((stage_v_147_2 << 1) ^ (pub_r001945_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_406_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_406_2 + 1) & 15;
  out_sink_1 ^= stage_v_406_1 & 63;
  out_sink_2 ^= stage_v_406_2 & 63;
  int stage_v_407_1 = ((stage_v_163_1 << 1) ^ (pub_r001945_11_1 >> 1)) & 127;
  int stage_v_407_2 = ((stage_v_163_2 << 1) ^ (pub_r001945_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_407_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_407_2 + 1) & 15;
  out_sink_1 ^= stage_v_407_1 & 63;
  out_sink_2 ^= stage_v_407_2 & 63;
  int stage_v_408_1 = ((stage_v_341_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_408_2 = ((stage_v_341_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_408_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_408_2 + 1) & 15;
  out_sink_1 ^= stage_v_408_1 & 63;
  out_sink_2 ^= stage_v_408_2 & 63;
  int stage_v_409_1 = ((stage_v_156_1 << 1) ^ (pub_r001945_16_1 >> 1)) & 127;
  int stage_v_409_2 = ((stage_v_156_2 << 1) ^ (pub_r001945_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_409_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_409_2 + 1) & 15;
  out_sink_1 ^= stage_v_409_1 & 63;
  out_sink_2 ^= stage_v_409_2 & 63;
  int stage_v_410_1 = ((pub_r001945_13_1 * 2) + 43) & 63;
  int stage_v_410_2 = ((pub_r001945_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001945_6_1 * 2) + 24) & 63;
  int stage_v_411_2 = ((pub_r001945_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((stage_v_209_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_412_2 = ((stage_v_209_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_412_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_412_2 + 1) & 15;
  out_sink_1 ^= stage_v_412_1 & 63;
  out_sink_2 ^= stage_v_412_2 & 63;
  int stage_v_413_1 = ((stage_v_333_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_413_2 = ((stage_v_333_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_413_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_413_2 + 1) & 15;
  out_sink_1 ^= stage_v_413_1 & 63;
  out_sink_2 ^= stage_v_413_2 & 63;
  int stage_v_414_1 = ((stage_v_389_1 << 1) ^ (pub_r001945_21_1 >> 1)) & 127;
  int stage_v_414_2 = ((stage_v_389_2 << 1) ^ (pub_r001945_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_414_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_414_2 + 1) & 15;
  out_sink_1 ^= stage_v_414_1 & 63;
  out_sink_2 ^= stage_v_414_2 & 63;
  int stage_v_415_1 = ((stage_v_122_1 << 1) ^ (pub_r001945_2_1 >> 1)) & 127;
  int stage_v_415_2 = ((stage_v_122_2 << 1) ^ (pub_r001945_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_415_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_415_2 + 1) & 15;
  out_sink_1 ^= stage_v_415_1 & 63;
  out_sink_2 ^= stage_v_415_2 & 63;
  int stage_v_416_1 = ((pub_r001945_22_1 * 2) + 46) & 63;
  int stage_v_416_2 = ((pub_r001945_22_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((pub_r001945_22_1 * 2) + 18) & 63;
  int stage_v_417_2 = ((pub_r001945_22_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001945_6_1 * 2) + 29) & 63;
  int stage_v_418_2 = ((pub_r001945_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((pub_r001945_22_1 * 2) + 7) & 63;
  int stage_v_419_2 = ((pub_r001945_22_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((sec_r001945_1_1 << 1) ^ (pub_r001945_15_1 >> 1)) & 127;
  int stage_v_420_2 = ((sec_r001945_1_2 << 1) ^ (pub_r001945_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_420_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_420_2 + 1) & 15;
  out_sink_1 ^= stage_v_420_1 & 63;
  out_sink_2 ^= stage_v_420_2 & 63;
  int stage_v_421_1 = ((stage_v_279_1 << 1) ^ (pub_r001945_14_1 >> 1)) & 127;
  int stage_v_421_2 = ((stage_v_279_2 << 1) ^ (pub_r001945_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_421_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_421_2 + 1) & 15;
  out_sink_1 ^= stage_v_421_1 & 63;
  out_sink_2 ^= stage_v_421_2 & 63;
  int stage_v_422_1 = ((stage_v_21_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_422_2 = ((stage_v_21_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_422_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_422_2 + 1) & 15;
  out_sink_1 ^= stage_v_422_1 & 63;
  out_sink_2 ^= stage_v_422_2 & 63;
  int stage_v_423_1 = ((stage_v_39_1 << 1) ^ (pub_r001945_11_1 >> 1)) & 127;
  int stage_v_423_2 = ((stage_v_39_2 << 1) ^ (pub_r001945_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_423_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_423_2 + 1) & 15;
  out_sink_1 ^= stage_v_423_1 & 63;
  out_sink_2 ^= stage_v_423_2 & 63;
  int stage_v_424_1 = ((pub_r001945_16_1 * 2) + 7) & 63;
  int stage_v_424_2 = ((pub_r001945_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((stage_v_33_1 << 1) ^ (pub_r001945_16_1 >> 1)) & 127;
  int stage_v_425_2 = ((stage_v_33_2 << 1) ^ (pub_r001945_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_425_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_425_2 + 1) & 15;
  out_sink_1 ^= stage_v_425_1 & 63;
  out_sink_2 ^= stage_v_425_2 & 63;
  int stage_v_426_1 = ((pub_r001945_21_1 * 2) + 49) & 63;
  int stage_v_426_2 = ((pub_r001945_21_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((pub_r001945_6_1 * 2) + 50) & 63;
  int stage_v_427_2 = ((pub_r001945_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((pub_r001945_16_1 * 2) + 39) & 63;
  int stage_v_428_2 = ((pub_r001945_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((stage_v_325_1 << 1) ^ (pub_r001945_6_1 >> 1)) & 127;
  int stage_v_429_2 = ((stage_v_325_2 << 1) ^ (pub_r001945_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_429_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_429_2 + 1) & 15;
  out_sink_1 ^= stage_v_429_1 & 63;
  out_sink_2 ^= stage_v_429_2 & 63;
  int stage_v_430_1 = ((stage_v_240_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_430_2 = ((stage_v_240_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_430_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_430_2 + 1) & 15;
  out_sink_1 ^= stage_v_430_1 & 63;
  out_sink_2 ^= stage_v_430_2 & 63;
  int stage_v_431_1 = ((sec_r001945_6_1 << 1) ^ (pub_r001945_22_1 >> 1)) & 127;
  int stage_v_431_2 = ((sec_r001945_6_2 << 1) ^ (pub_r001945_22_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_431_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_431_2 + 1) & 15;
  out_sink_1 ^= stage_v_431_1 & 63;
  out_sink_2 ^= stage_v_431_2 & 63;
  int stage_v_432_1 = ((pub_r001945_4_1 * 2) + 17) & 63;
  int stage_v_432_2 = ((pub_r001945_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((pub_r001945_1_1 * 2) + 13) & 63;
  int stage_v_433_2 = ((pub_r001945_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = ((pub_r001945_5_1 * 2) + 36) & 63;
  int stage_v_434_2 = ((pub_r001945_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((helper_flow_2_1 << 1) ^ (pub_r001945_6_1 >> 1)) & 127;
  int stage_v_435_2 = ((helper_flow_2_2 << 1) ^ (pub_r001945_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_435_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_435_2 + 1) & 15;
  out_sink_1 ^= stage_v_435_1 & 63;
  out_sink_2 ^= stage_v_435_2 & 63;
  int stage_v_436_1 = ((pub_r001945_15_1 * 2) + 32) & 63;
  int stage_v_436_2 = ((pub_r001945_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((stage_v_209_1 << 1) ^ (pub_r001945_12_1 >> 1)) & 127;
  int stage_v_437_2 = ((stage_v_209_2 << 1) ^ (pub_r001945_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_437_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_437_2 + 1) & 15;
  out_sink_1 ^= stage_v_437_1 & 63;
  out_sink_2 ^= stage_v_437_2 & 63;
  int stage_v_438_1 = ((pub_r001945_15_1 * 2) + 28) & 63;
  int stage_v_438_2 = ((pub_r001945_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((pub_r001945_11_1 * 2) + 17) & 63;
  int stage_v_439_2 = ((pub_r001945_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = ((pub_r001945_2_1 * 2) + 44) & 63;
  int stage_v_440_2 = ((pub_r001945_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((stage_v_124_1 << 1) ^ (pub_r001945_11_1 >> 1)) & 127;
  int stage_v_441_2 = ((stage_v_124_2 << 1) ^ (pub_r001945_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_441_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_441_2 + 1) & 15;
  out_sink_1 ^= stage_v_441_1 & 63;
  out_sink_2 ^= stage_v_441_2 & 63;
  int stage_v_442_1 = ((stage_v_257_1 << 1) ^ (pub_r001945_13_1 >> 1)) & 127;
  int stage_v_442_2 = ((stage_v_257_2 << 1) ^ (pub_r001945_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_442_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_442_2 + 1) & 15;
  out_sink_1 ^= stage_v_442_1 & 63;
  out_sink_2 ^= stage_v_442_2 & 63;
  int stage_v_443_1 = ((stage_v_94_1 << 1) ^ (pub_r001945_19_1 >> 1)) & 127;
  int stage_v_443_2 = ((stage_v_94_2 << 1) ^ (pub_r001945_19_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_443_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_443_2 + 1) & 15;
  out_sink_1 ^= stage_v_443_1 & 63;
  out_sink_2 ^= stage_v_443_2 & 63;
  int stage_v_444_1 = ((stage_v_65_1 << 1) ^ (pub_r001945_19_1 >> 1)) & 127;
  int stage_v_444_2 = ((stage_v_65_2 << 1) ^ (pub_r001945_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_444_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_444_2 + 1) & 15;
  out_sink_1 ^= stage_v_444_1 & 63;
  out_sink_2 ^= stage_v_444_2 & 63;
  int stage_v_445_1 = ((pub_r001945_4_1 * 2) + 6) & 63;
  int stage_v_445_2 = ((pub_r001945_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((stage_v_407_1 << 1) ^ (pub_r001945_14_1 >> 1)) & 127;
  int stage_v_446_2 = ((stage_v_407_2 << 1) ^ (pub_r001945_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_446_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_446_2 + 1) & 15;
  out_sink_1 ^= stage_v_446_1 & 63;
  out_sink_2 ^= stage_v_446_2 & 63;
  int stage_v_447_1 = ((pub_r001945_5_1 * 2) + 26) & 63;
  int stage_v_447_2 = ((pub_r001945_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((stage_v_154_1 << 1) ^ (pub_r001945_20_1 >> 1)) & 127;
  int stage_v_448_2 = ((stage_v_154_2 << 1) ^ (pub_r001945_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_448_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_448_2 + 1) & 15;
  out_sink_1 ^= stage_v_448_1 & 63;
  out_sink_2 ^= stage_v_448_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001945_12_1 != sec_r001945_12_2);
  __CPROVER_assume(pub_r001945_11_1 == pub_r001945_11_2);
  __CPROVER_assume(sec_r001945_15_1 != sec_r001945_15_2);
  __CPROVER_assume(pub_r001945_9_1 == pub_r001945_9_2);
  __CPROVER_assume(pub_r001945_16_1 == pub_r001945_16_2);
  __CPROVER_assume(sec_r001945_10_1 != sec_r001945_10_2);
  __CPROVER_assume(pub_r001945_6_1 == pub_r001945_6_2);
  __CPROVER_assume(pub_r001945_3_1 == pub_r001945_3_2);
  __CPROVER_assume(pub_r001945_0_1 == pub_r001945_0_2);
  __CPROVER_assume(sec_r001945_16_1 != sec_r001945_16_2);
  __CPROVER_assume(pub_r001945_1_1 == pub_r001945_1_2);
  __CPROVER_assume(sec_r001945_13_1 != sec_r001945_13_2);
  __CPROVER_assume(pub_r001945_7_1 == pub_r001945_7_2);
  __CPROVER_assume(sec_r001945_4_1 != sec_r001945_4_2);
  __CPROVER_assume(pub_r001945_18_1 == pub_r001945_18_2);
  __CPROVER_assume(pub_r001945_20_1 == pub_r001945_20_2);
  __CPROVER_assume(sec_r001945_0_1 != sec_r001945_0_2);
  __CPROVER_assume(pub_r001945_13_1 == pub_r001945_13_2);
  __CPROVER_assume(sec_r001945_6_1 != sec_r001945_6_2);
  __CPROVER_assume(pub_r001945_2_1 == pub_r001945_2_2);
  __CPROVER_assume(pub_r001945_21_1 == pub_r001945_21_2);
  __CPROVER_assume(pub_r001945_12_1 == pub_r001945_12_2);
  __CPROVER_assume(pub_r001945_5_1 == pub_r001945_5_2);
  __CPROVER_assume(sec_r001945_11_1 != sec_r001945_11_2);
  __CPROVER_assume(pub_r001945_14_1 == pub_r001945_14_2);
  __CPROVER_assume(pub_r001945_15_1 == pub_r001945_15_2);
  __CPROVER_assume(sec_r001945_3_1 != sec_r001945_3_2);
  __CPROVER_assume(pub_r001945_10_1 == pub_r001945_10_2);
  __CPROVER_assume(sec_r001945_9_1 != sec_r001945_9_2);
  __CPROVER_assume(sec_r001945_2_1 != sec_r001945_2_2);
  __CPROVER_assume(sec_r001945_7_1 != sec_r001945_7_2);
  __CPROVER_assume(sec_r001945_5_1 != sec_r001945_5_2);
  __CPROVER_assume(pub_r001945_4_1 == pub_r001945_4_2);
  __CPROVER_assume(sec_r001945_8_1 != sec_r001945_8_2);
  __CPROVER_assume(sec_r001945_1_1 != sec_r001945_1_2);
  __CPROVER_assume(sec_r001945_14_1 != sec_r001945_14_2);
  __CPROVER_assume(pub_r001945_17_1 == pub_r001945_17_2);
  __CPROVER_assume(pub_r001945_19_1 == pub_r001945_19_2);
  __CPROVER_assume(pub_r001945_22_1 == pub_r001945_22_2);
  __CPROVER_assume(pub_r001945_8_1 == pub_r001945_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.dim == st_var_1_2.dim);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
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
}


