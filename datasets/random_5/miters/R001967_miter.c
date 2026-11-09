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
struct StreamBuffer_R001967_6713_0
{
  int checksum;
  short state;
  unsigned char tail;
  short watermark;
  int buffer[3];
};
struct Vector3D_R001967_6713_1
{
  int coord_z;
  short pitch;
  unsigned char heading;
  unsigned char coord_y;
  short coord_x;
  short norm_sq;
  int buffer[3];
};
struct MatrixBlock_R001967_6713_2
{
  int scale;
  int density;
  int dim;
  int buffer[3];
};
union ColorPixel_R001967_6713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001967_6713_1
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
void fn_R001967_6713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st_1 = {0};
  struct MatrixBlock_R001967_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int cursor_31_1 = 0;
  int cursor_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_31_1 = ((cursor_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_31_2 = ((cursor_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_31_1) & 127;
    acc_2 = (acc_2 + cursor_31_2) & 127;
  }

  int checksum_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_67_1) & 63;
  aux_2 = (aux_2 + checksum_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_27_1 = local_arr_1[aux_1 % 3];
  int parity_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_27_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_31_1 == cursor_31_2);
  assert(checksum_67_1 == checksum_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_27_1 == parity_27_2);
}

int fn_R001967_6713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int cursor_31 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_31 = ((cursor_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_31) & 127;
  }

  int checksum_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_27 = local_arr[aux % 3];
  acc = (acc + (parity_27 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001967_6713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st_1 = {0};
  struct MatrixBlock_R001967_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int pivot_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_96_1 > 47)
  {
    acc_1 = ((acc_1 + (pivot_96_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_96_2 > 47)
  {
    acc_2 = ((acc_2 + (pivot_96_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_59_1)
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

  switch (metric_59_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_96_1 == pivot_96_2);
  assert(metric_59_1 == metric_59_2);
}

int fn_R001967_6713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int pivot_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_96 > 47)
  {
    acc = ((acc + (pivot_96 * 2)) + 5) & 127;
    aux ^= pivot_96 & 15;
  }
  else
  {
    acc = ((acc - pivot_96) + 11) & 127;
    aux += 3;
  }
  int metric_59 = (aux + st.buffer[1]) & 3;
  switch (metric_59)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001967_6713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st_1 = {0};
  struct MatrixBlock_R001967_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int scale_41_1 = 0;
  int scale_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_41_1 = ((scale_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_41_2 = ((scale_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_41_1) & 127;
    acc_2 = (acc_2 + scale_41_2) & 127;
  }

  int threshold_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_78_1 > 22)
  {
    acc_1 = ((acc_1 + (threshold_78_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_78_2 > 22)
  {
    acc_2 = ((acc_2 + (threshold_78_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_85_1) & 63;
  aux_2 = (aux_2 + offset_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_32_1)
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

  switch (coefficient_32_2)
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
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_41_1 == scale_41_2);
  assert(threshold_78_1 == threshold_78_2);
  assert(offset_85_1 == offset_85_2);
  assert(coefficient_32_1 == coefficient_32_2);
}

int fn_R001967_6713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int scale_41 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_41 = ((scale_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_41) & 127;
  }

  int threshold_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_78 > 22)
  {
    acc = ((acc + (threshold_78 * 2)) + 5) & 127;
    aux ^= threshold_78 & 15;
  }
  else
  {
    acc = ((acc - threshold_78) + 11) & 127;
    aux += 3;
  }
  int offset_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_85) & 63;
  acc ^= aux;
  int coefficient_32 = (aux + st.buffer[1]) & 3;
  switch (coefficient_32)
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

void fn_R001967_6713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st_1 = {0};
  struct MatrixBlock_R001967_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int parity_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_59_1 > 35)
  {
    acc_1 = ((acc_1 + (parity_59_1 * 2)) + 5) & 127;
    aux_1 ^= parity_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_59_2 > 35)
  {
    acc_2 = ((acc_2 + (parity_59_2 * 2)) + 5) & 127;
    aux_2 ^= parity_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_35_1)
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

  switch (pivot_35_2)
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
  int vector_23_1 = local_arr_1[aux_1 % 3];
  int vector_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_23_2 * 2)) & 127;
  int margin_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_99_1) & 63;
  aux_2 = (aux_2 + margin_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_59_1 == parity_59_2);
  assert(pivot_35_1 == pivot_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_23_1 == vector_23_2);
  assert(margin_99_1 == margin_99_2);
}

int fn_R001967_6713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int parity_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_59 > 35)
  {
    acc = ((acc + (parity_59 * 2)) + 5) & 127;
    aux ^= parity_59 & 15;
  }
  else
  {
    acc = ((acc - parity_59) + 11) & 127;
    aux += 3;
  }
  int pivot_35 = (aux + st.buffer[1]) & 3;
  switch (pivot_35)
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
  int vector_23 = local_arr[aux % 3];
  acc = (acc + (vector_23 * 2)) & 127;
  int margin_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001967_6713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st_1 = {0};
  struct Vector3D_R001967_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int threshold_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_37_1 > 37)
  {
    acc_1 = ((acc_1 + (threshold_37_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_37_2 > 37)
  {
    acc_2 = ((acc_2 + (threshold_37_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_77_1)
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

  switch (tally_77_2)
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

  int window_85_1 = 0;
  int window_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_85_1 = ((window_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_85_2 = ((window_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_85_1) & 127;
    acc_2 = (acc_2 + window_85_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_42_1 = local_arr_1[aux_1 % 3];
  int coefficient_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_42_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_37_1 == threshold_37_2);
  assert(tally_77_1 == tally_77_2);
  assert(window_85_1 == window_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_42_1 == coefficient_42_2);
}

int fn_R001967_6713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int threshold_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_37 > 37)
  {
    acc = ((acc + (threshold_37 * 2)) + 5) & 127;
    aux ^= threshold_37 & 15;
  }
  else
  {
    acc = ((acc - threshold_37) + 11) & 127;
    aux += 3;
  }
  int tally_77 = (aux + st.buffer[1]) & 3;
  switch (tally_77)
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

  int window_85 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_85 = ((window_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_85) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int coefficient_42 = local_arr[aux % 3];
  acc = (acc + (coefficient_42 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001967_6713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st_1 = {0};
  struct Vector3D_R001967_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int threshold_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_74_1)
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

  switch (threshold_74_2)
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

  int damping_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_55_1 > 34)
  {
    acc_1 = ((acc_1 + (damping_55_1 * 2)) + 5) & 127;
    aux_1 ^= damping_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_55_2 > 34)
  {
    acc_2 = ((acc_2 + (damping_55_2 * 2)) + 5) & 127;
    aux_2 ^= damping_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_88_1 = 0;
  int pivot_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_88_1 = ((pivot_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_88_2 = ((pivot_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_88_1) & 127;
    acc_2 = (acc_2 + pivot_88_2) & 127;
  }

  int bound_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_18_1) & 63;
  aux_2 = (aux_2 + bound_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_74_1 == threshold_74_2);
  assert(damping_55_1 == damping_55_2);
  assert(pivot_88_1 == pivot_88_2);
  assert(bound_18_1 == bound_18_2);
}

int fn_R001967_6713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int threshold_74 = (aux + st.buffer[1]) & 3;
  switch (threshold_74)
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

  int damping_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_55 > 34)
  {
    acc = ((acc + (damping_55 * 2)) + 5) & 127;
    aux ^= damping_55 & 15;
  }
  else
  {
    acc = ((acc - damping_55) + 11) & 127;
    aux += 3;
  }
  int pivot_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_88 = ((pivot_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_88) & 127;
  }

  int bound_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_18) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001967_6713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st_1 = {0};
  struct MatrixBlock_R001967_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int index_reg_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_69_1)
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

  switch (index_reg_69_2)
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

  int vector_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_74_1) & 63;
  aux_2 = (aux_2 + vector_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_69_1 == index_reg_69_2);
  assert(vector_74_1 == vector_74_2);
}

int fn_R001967_6713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int index_reg_69 = (aux + st.buffer[1]) & 3;
  switch (index_reg_69)
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

  int vector_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_74) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001967_6713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st_1 = {0};
  struct Vector3D_R001967_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_40_1 > 12)
  {
    acc_1 = ((acc_1 + (vector_40_1 * 2)) + 5) & 127;
    aux_1 ^= vector_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_40_2 > 12)
  {
    acc_2 = ((acc_2 + (vector_40_2 * 2)) + 5) & 127;
    aux_2 ^= vector_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_53_1)
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

  switch (accumulator_53_2)
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
  int delta_91_1 = local_arr_1[aux_1 % 3];
  int delta_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_91_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_40_1 == vector_40_2);
  assert(accumulator_53_1 == accumulator_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_91_1 == delta_91_2);
}

int fn_R001967_6713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_40 > 12)
  {
    acc = ((acc + (vector_40 * 2)) + 5) & 127;
    aux ^= vector_40 & 15;
  }
  else
  {
    acc = ((acc - vector_40) + 11) & 127;
    aux += 3;
  }
  int accumulator_53 = (aux + st.buffer[1]) & 3;
  switch (accumulator_53)
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
  int delta_91 = local_arr[aux % 3];
  acc = (acc + (delta_91 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001967_6713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st_1 = {0};
  struct MatrixBlock_R001967_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int weight_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_26_1 > 48)
  {
    acc_1 = ((acc_1 + (weight_26_1 * 2)) + 5) & 127;
    aux_1 ^= weight_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_26_2 > 48)
  {
    acc_2 = ((acc_2 + (weight_26_2 * 2)) + 5) & 127;
    aux_2 ^= weight_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_20_1 = local_arr_1[aux_1 % 3];
  int bound_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_20_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_44_1) & 63;
  aux_2 = (aux_2 + residue_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_26_1 == weight_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_20_1 == bound_20_2);
  assert(residue_44_1 == residue_44_2);
}

int fn_R001967_6713_8(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int weight_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_26 > 48)
  {
    acc = ((acc + (weight_26 * 2)) + 5) & 127;
    aux ^= weight_26 & 15;
  }
  else
  {
    acc = ((acc - weight_26) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_20 = local_arr[aux % 3];
  acc = (acc + (bound_20 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001967_6713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st_1 = {0};
  struct Vector3D_R001967_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int quotient_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_52_1) & 63;
  aux_2 = (aux_2 + quotient_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_18_1 = 0;
  int bound_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_18_1 = ((bound_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_18_2 = ((bound_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_18_1) & 127;
    acc_2 = (acc_2 + bound_18_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_52_1 == quotient_52_2);
  assert(bound_18_1 == bound_18_2);
}

int fn_R001967_6713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int quotient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_52) & 63;
  acc ^= aux;
  int bound_18 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_18 = ((bound_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_18) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001967_6713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st_1 = {0};
  struct Vector3D_R001967_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_95_1)
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

  switch (factor_95_2)
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
  int index_reg_16_1 = local_arr_1[aux_1 % 3];
  int index_reg_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_16_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_95_1 == factor_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_16_1 == index_reg_16_2);
}

int fn_R001967_6713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_95 = (aux + st.buffer[1]) & 3;
  switch (factor_95)
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
  int index_reg_16 = local_arr[aux % 3];
  acc = (acc + (index_reg_16 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001967_6713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st_1 = {0};
  struct MatrixBlock_R001967_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int scale_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_77_1)
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

  switch (scale_77_2)
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

  int pivot_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_15_1 > 13)
  {
    acc_1 = ((acc_1 + (pivot_15_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_15_2 > 13)
  {
    acc_2 = ((acc_2 + (pivot_15_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_15_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_54_1 = local_arr_1[aux_1 % 3];
  int quantum_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_77_1 == scale_77_2);
  assert(pivot_15_1 == pivot_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_54_1 == quantum_54_2);
}

int fn_R001967_6713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int scale_77 = (aux + st.buffer[1]) & 3;
  switch (scale_77)
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

  int pivot_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_15 > 13)
  {
    acc = ((acc + (pivot_15 * 2)) + 5) & 127;
    aux ^= pivot_15 & 15;
  }
  else
  {
    acc = ((acc - pivot_15) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quantum_54 = local_arr[aux % 3];
  acc = (acc + (quantum_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001967_6713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001967_6713_0 st_1 = {0};
  struct StreamBuffer_R001967_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int phase_74_1 = 0;
  int phase_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_74_1 = ((phase_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_74_2 = ((phase_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_74_1) & 127;
    acc_2 = (acc_2 + phase_74_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_74_1 = local_arr_1[aux_1 % 3];
  int weight_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_74_2 * 2)) & 127;
  int delta_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_18_1 > 39)
  {
    acc_1 = ((acc_1 + (delta_18_1 * 2)) + 5) & 127;
    aux_1 ^= delta_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_18_2 > 39)
  {
    acc_2 = ((acc_2 + (delta_18_2 * 2)) + 5) & 127;
    aux_2 ^= delta_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_18_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_74_1 == phase_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_74_1 == weight_74_2);
  assert(delta_18_1 == delta_18_2);
}

int fn_R001967_6713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001967_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int phase_74 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_74 = ((phase_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_74) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int weight_74 = local_arr[aux % 3];
  acc = (acc + (weight_74 * 2)) & 127;
  int delta_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_18 > 39)
  {
    acc = ((acc + (delta_18 * 2)) + 5) & 127;
    aux ^= delta_18 & 15;
  }
  else
  {
    acc = ((acc - delta_18) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001967_6713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001967_6713_0 st_1 = {0};
  struct StreamBuffer_R001967_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
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

  int residue_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_81_1) & 63;
  aux_2 = (aux_2 + residue_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_83_1 = local_arr_1[aux_1 % 3];
  int accumulator_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_83_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_43_1 == vector_43_2);
  assert(residue_81_1 == residue_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_83_1 == accumulator_83_2);
}

int fn_R001967_6713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001967_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
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

  int residue_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_81) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_83 = local_arr[aux % 3];
  acc = (acc + (accumulator_83 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001967_6713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st_1 = {0};
  struct MatrixBlock_R001967_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_62_1) & 63;
  aux_2 = (aux_2 + tally_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_87_1)
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

  switch (scale_87_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_62_1 == tally_62_2);
  assert(scale_87_1 == scale_87_2);
}

int fn_R001967_6713_14(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_62) & 63;
  acc ^= aux;
  int scale_87 = (aux + st.buffer[1]) & 3;
  switch (scale_87)
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

void fn_R001967_6713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001967_6713_0 st_1 = {0};
  struct StreamBuffer_R001967_6713_0 st_2 = {0};
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
  int anchor_74_1 = local_arr_1[aux_1 % 3];
  int anchor_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_74_1 == anchor_74_2);
}

int fn_R001967_6713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001967_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_74 = local_arr[aux % 3];
  acc = (acc + (anchor_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001967_6713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001967_6713_0 st_1 = {0};
  struct StreamBuffer_R001967_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int index_reg_23_1 = 0;
  int index_reg_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_23_1 = ((index_reg_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_23_2 = ((index_reg_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_23_1) & 127;
    acc_2 = (acc_2 + index_reg_23_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_72_1) & 63;
  aux_2 = (aux_2 + tracker_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_56_1 = local_arr_1[aux_1 % 3];
  int metric_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_23_1 == index_reg_23_2);
  assert(tracker_72_1 == tracker_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_56_1 == metric_56_2);
}

int fn_R001967_6713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001967_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int index_reg_23 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_23 = ((index_reg_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_23) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_72) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_56 = local_arr[aux % 3];
  acc = (acc + (metric_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001967_6713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st_1 = {0};
  struct Vector3D_R001967_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int delta_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_28_1 > 23)
  {
    acc_1 = ((acc_1 + (delta_28_1 * 2)) + 5) & 127;
    aux_1 ^= delta_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_28_2 > 23)
  {
    acc_2 = ((acc_2 + (delta_28_2 * 2)) + 5) & 127;
    aux_2 ^= delta_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_28_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_31_1) & 63;
  aux_2 = (aux_2 + quotient_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_28_1 == delta_28_2);
  assert(quotient_31_1 == quotient_31_2);
}

int fn_R001967_6713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int delta_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_28 > 23)
  {
    acc = ((acc + (delta_28 * 2)) + 5) & 127;
    aux ^= delta_28 & 15;
  }
  else
  {
    acc = ((acc - delta_28) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001967_6713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001967_6713_0 st_1 = {0};
  struct StreamBuffer_R001967_6713_0 st_2 = {0};
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
  int pivot_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_10_1)
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

  switch (pivot_10_2)
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

  int pivot_42_1 = 0;
  int pivot_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_42_1 = ((pivot_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_42_2 = ((pivot_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_42_1) & 127;
    acc_2 = (acc_2 + pivot_42_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_10_1 == pivot_10_2);
  assert(pivot_42_1 == pivot_42_2);
}

int fn_R001967_6713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001967_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_10 = (aux + st.buffer[1]) & 3;
  switch (pivot_10)
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

  int pivot_42 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_42 = ((pivot_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_42) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001967_6713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st_1 = {0};
  struct MatrixBlock_R001967_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int threshold_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_14_1) & 63;
  aux_2 = (aux_2 + threshold_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_92_1 = local_arr_1[aux_1 % 3];
  int threshold_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_92_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_14_1 == threshold_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_92_1 == threshold_92_2);
}

int fn_R001967_6713_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int threshold_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_14) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_92 = local_arr[aux % 3];
  acc = (acc + (threshold_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001967_6713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001967_6713_0 st_1 = {0};
  struct StreamBuffer_R001967_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_92_1 = local_arr_1[aux_1 % 3];
  int offset_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_92_2 * 2)) & 127;
  int index_reg_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_34_1)
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

  switch (index_reg_34_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_92_1 == offset_92_2);
  assert(index_reg_34_1 == index_reg_34_2);
}

int fn_R001967_6713_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001967_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_92 = local_arr[aux % 3];
  acc = (acc + (offset_92 * 2)) & 127;
  int index_reg_34 = (aux + st.buffer[1]) & 3;
  switch (index_reg_34)
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

void fn_R001967_6713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st_1 = {0};
  struct Vector3D_R001967_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int damping_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_64_1) & 63;
  aux_2 = (aux_2 + damping_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_96_1 = local_arr_1[aux_1 % 3];
  int threshold_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_96_2 * 2)) & 127;
  int offset_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_60_1 > 50)
  {
    acc_1 = ((acc_1 + (offset_60_1 * 2)) + 5) & 127;
    aux_1 ^= offset_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_60_2 > 50)
  {
    acc_2 = ((acc_2 + (offset_60_2 * 2)) + 5) & 127;
    aux_2 ^= offset_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_24_1 = 0;
  int offset_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_24_1 = ((offset_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_24_2 = ((offset_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_24_1) & 127;
    acc_2 = (acc_2 + offset_24_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_64_1 == damping_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_96_1 == threshold_96_2);
  assert(offset_60_1 == offset_60_2);
  assert(offset_24_1 == offset_24_2);
}

int fn_R001967_6713_21(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001967_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int damping_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_64) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_96 = local_arr[aux % 3];
  acc = (acc + (threshold_96 * 2)) & 127;
  int offset_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_60 > 50)
  {
    acc = ((acc + (offset_60 * 2)) + 5) & 127;
    aux ^= offset_60 & 15;
  }
  else
  {
    acc = ((acc - offset_60) + 11) & 127;
    aux += 3;
  }
  int offset_24 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_24 = ((offset_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_24) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001967_6713_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st_1 = {0};
  struct MatrixBlock_R001967_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int segment_63_1 = 0;
  int segment_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_63_1 = ((segment_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_63_2 = ((segment_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_63_1) & 127;
    acc_2 = (acc_2 + segment_63_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_20_1 = local_arr_1[aux_1 % 3];
  int tally_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_20_2 * 2)) & 127;
  int delta_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_22_1)
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

  switch (delta_22_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_63_1 == segment_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_20_1 == tally_20_2);
  assert(delta_22_1 == delta_22_2);
}

int fn_R001967_6713_22(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001967_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int segment_63 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_63 = ((segment_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_63) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tally_20 = local_arr[aux % 3];
  acc = (acc + (tally_20 * 2)) & 127;
  int delta_22 = (aux + st.buffer[1]) & 3;
  switch (delta_22)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001967_0_1;
  int sec_r001967_0_2;
  int sec_r001967_1_1;
  int sec_r001967_1_2;
  int sec_r001967_2_1;
  int sec_r001967_2_2;
  int sec_r001967_3_1;
  int sec_r001967_3_2;
  int sec_r001967_4_1;
  int sec_r001967_4_2;
  int sec_r001967_5_1;
  int sec_r001967_5_2;
  int sec_r001967_6_1;
  int sec_r001967_6_2;
  int sec_r001967_7_1;
  int sec_r001967_7_2;
  int sec_r001967_8_1;
  int sec_r001967_8_2;
  int sec_r001967_9_1;
  int sec_r001967_9_2;
  int sec_r001967_10_1;
  int sec_r001967_10_2;
  int sec_r001967_11_1;
  int sec_r001967_11_2;
  int sec_r001967_12_1;
  int sec_r001967_12_2;
  int sec_r001967_13_1;
  int sec_r001967_13_2;
  int sec_r001967_14_1;
  int sec_r001967_14_2;
  int sec_r001967_15_1;
  int sec_r001967_15_2;
  int sec_r001967_16_1;
  int sec_r001967_16_2;
  int sec_r001967_17_1;
  int sec_r001967_17_2;
  int sec_r001967_18_1;
  int sec_r001967_18_2;
  int sec_r001967_19_1;
  int sec_r001967_19_2;
  int pub_r001967_0_1;
  int pub_r001967_0_2;
  int pub_r001967_1_1;
  int pub_r001967_1_2;
  int pub_r001967_2_1;
  int pub_r001967_2_2;
  int pub_r001967_3_1;
  int pub_r001967_3_2;
  int pub_r001967_4_1;
  int pub_r001967_4_2;
  int pub_r001967_5_1;
  int pub_r001967_5_2;
  int pub_r001967_6_1;
  int pub_r001967_6_2;
  int pub_r001967_7_1;
  int pub_r001967_7_2;
  int pub_r001967_8_1;
  int pub_r001967_8_2;
  int pub_r001967_9_1;
  int pub_r001967_9_2;
  int pub_r001967_10_1;
  int pub_r001967_10_2;
  int pub_r001967_11_1;
  int pub_r001967_11_2;
  int pub_r001967_12_1;
  int pub_r001967_12_2;
  int pub_r001967_13_1;
  int pub_r001967_13_2;
  int pub_r001967_14_1;
  int pub_r001967_14_2;
  int pub_r001967_15_1;
  int pub_r001967_15_2;
  int pub_r001967_16_1;
  int pub_r001967_16_2;
  int pub_r001967_17_1;
  int pub_r001967_17_2;
  int pub_r001967_18_1;
  int pub_r001967_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001967_0_1 >= (-100)) && (pub_r001967_0_1 <= 100));
  __CPROVER_assume((pub_r001967_0_2 >= (-100)) && (pub_r001967_0_2 <= 100));
  __CPROVER_assume((pub_r001967_1_1 >= (-100)) && (pub_r001967_1_1 <= 100));
  __CPROVER_assume((pub_r001967_1_2 >= (-100)) && (pub_r001967_1_2 <= 100));
  __CPROVER_assume((pub_r001967_2_1 >= (-100)) && (pub_r001967_2_1 <= 100));
  __CPROVER_assume((pub_r001967_2_2 >= (-100)) && (pub_r001967_2_2 <= 100));
  __CPROVER_assume((pub_r001967_3_1 >= (-100)) && (pub_r001967_3_1 <= 100));
  __CPROVER_assume((pub_r001967_3_2 >= (-100)) && (pub_r001967_3_2 <= 100));
  __CPROVER_assume((pub_r001967_4_1 >= (-100)) && (pub_r001967_4_1 <= 100));
  __CPROVER_assume((pub_r001967_4_2 >= (-100)) && (pub_r001967_4_2 <= 100));
  __CPROVER_assume((pub_r001967_5_1 >= (-100)) && (pub_r001967_5_1 <= 100));
  __CPROVER_assume((pub_r001967_5_2 >= (-100)) && (pub_r001967_5_2 <= 100));
  __CPROVER_assume((pub_r001967_6_1 >= (-100)) && (pub_r001967_6_1 <= 100));
  __CPROVER_assume((pub_r001967_6_2 >= (-100)) && (pub_r001967_6_2 <= 100));
  __CPROVER_assume((pub_r001967_7_1 >= (-100)) && (pub_r001967_7_1 <= 100));
  __CPROVER_assume((pub_r001967_7_2 >= (-100)) && (pub_r001967_7_2 <= 100));
  __CPROVER_assume((pub_r001967_8_1 >= (-100)) && (pub_r001967_8_1 <= 100));
  __CPROVER_assume((pub_r001967_8_2 >= (-100)) && (pub_r001967_8_2 <= 100));
  __CPROVER_assume((pub_r001967_9_1 >= (-100)) && (pub_r001967_9_1 <= 100));
  __CPROVER_assume((pub_r001967_9_2 >= (-100)) && (pub_r001967_9_2 <= 100));
  __CPROVER_assume((pub_r001967_10_1 >= (-100)) && (pub_r001967_10_1 <= 100));
  __CPROVER_assume((pub_r001967_10_2 >= (-100)) && (pub_r001967_10_2 <= 100));
  __CPROVER_assume((pub_r001967_11_1 >= (-100)) && (pub_r001967_11_1 <= 100));
  __CPROVER_assume((pub_r001967_11_2 >= (-100)) && (pub_r001967_11_2 <= 100));
  __CPROVER_assume((pub_r001967_12_1 >= (-100)) && (pub_r001967_12_1 <= 100));
  __CPROVER_assume((pub_r001967_12_2 >= (-100)) && (pub_r001967_12_2 <= 100));
  __CPROVER_assume((pub_r001967_13_1 >= (-100)) && (pub_r001967_13_1 <= 100));
  __CPROVER_assume((pub_r001967_13_2 >= (-100)) && (pub_r001967_13_2 <= 100));
  __CPROVER_assume((pub_r001967_14_1 >= (-100)) && (pub_r001967_14_1 <= 100));
  __CPROVER_assume((pub_r001967_14_2 >= (-100)) && (pub_r001967_14_2 <= 100));
  __CPROVER_assume((pub_r001967_15_1 >= (-100)) && (pub_r001967_15_1 <= 100));
  __CPROVER_assume((pub_r001967_15_2 >= (-100)) && (pub_r001967_15_2 <= 100));
  __CPROVER_assume((pub_r001967_16_1 >= (-100)) && (pub_r001967_16_1 <= 100));
  __CPROVER_assume((pub_r001967_16_2 >= (-100)) && (pub_r001967_16_2 <= 100));
  __CPROVER_assume((pub_r001967_17_1 >= (-100)) && (pub_r001967_17_1 <= 100));
  __CPROVER_assume((pub_r001967_17_2 >= (-100)) && (pub_r001967_17_2 <= 100));
  __CPROVER_assume((pub_r001967_18_1 >= (-100)) && (pub_r001967_18_1 <= 100));
  __CPROVER_assume((pub_r001967_18_2 >= (-100)) && (pub_r001967_18_2 <= 100));
  __CPROVER_assume((sec_r001967_0_1 >= 0) && (sec_r001967_0_1 <= 255));
  __CPROVER_assume((sec_r001967_0_2 >= 0) && (sec_r001967_0_2 <= 255));
  __CPROVER_assume((sec_r001967_1_1 >= 0) && (sec_r001967_1_1 <= 255));
  __CPROVER_assume((sec_r001967_1_2 >= 0) && (sec_r001967_1_2 <= 255));
  __CPROVER_assume((sec_r001967_2_1 >= 0) && (sec_r001967_2_1 <= 255));
  __CPROVER_assume((sec_r001967_2_2 >= 0) && (sec_r001967_2_2 <= 255));
  __CPROVER_assume((sec_r001967_3_1 >= 0) && (sec_r001967_3_1 <= 255));
  __CPROVER_assume((sec_r001967_3_2 >= 0) && (sec_r001967_3_2 <= 255));
  __CPROVER_assume((sec_r001967_4_1 >= 0) && (sec_r001967_4_1 <= 255));
  __CPROVER_assume((sec_r001967_4_2 >= 0) && (sec_r001967_4_2 <= 255));
  __CPROVER_assume((sec_r001967_5_1 >= 0) && (sec_r001967_5_1 <= 255));
  __CPROVER_assume((sec_r001967_5_2 >= 0) && (sec_r001967_5_2 <= 255));
  __CPROVER_assume((sec_r001967_6_1 >= 0) && (sec_r001967_6_1 <= 255));
  __CPROVER_assume((sec_r001967_6_2 >= 0) && (sec_r001967_6_2 <= 255));
  __CPROVER_assume((sec_r001967_7_1 >= 0) && (sec_r001967_7_1 <= 255));
  __CPROVER_assume((sec_r001967_7_2 >= 0) && (sec_r001967_7_2 <= 255));
  __CPROVER_assume((sec_r001967_8_1 >= 0) && (sec_r001967_8_1 <= 255));
  __CPROVER_assume((sec_r001967_8_2 >= 0) && (sec_r001967_8_2 <= 255));
  __CPROVER_assume((sec_r001967_9_1 >= 0) && (sec_r001967_9_1 <= 255));
  __CPROVER_assume((sec_r001967_9_2 >= 0) && (sec_r001967_9_2 <= 255));
  __CPROVER_assume((sec_r001967_10_1 >= 0) && (sec_r001967_10_1 <= 255));
  __CPROVER_assume((sec_r001967_10_2 >= 0) && (sec_r001967_10_2 <= 255));
  __CPROVER_assume((sec_r001967_11_1 >= 0) && (sec_r001967_11_1 <= 255));
  __CPROVER_assume((sec_r001967_11_2 >= 0) && (sec_r001967_11_2 <= 255));
  __CPROVER_assume((sec_r001967_12_1 >= 0) && (sec_r001967_12_1 <= 255));
  __CPROVER_assume((sec_r001967_12_2 >= 0) && (sec_r001967_12_2 <= 255));
  __CPROVER_assume((sec_r001967_13_1 >= 0) && (sec_r001967_13_1 <= 255));
  __CPROVER_assume((sec_r001967_13_2 >= 0) && (sec_r001967_13_2 <= 255));
  __CPROVER_assume((sec_r001967_14_1 >= 0) && (sec_r001967_14_1 <= 255));
  __CPROVER_assume((sec_r001967_14_2 >= 0) && (sec_r001967_14_2 <= 255));
  __CPROVER_assume((sec_r001967_15_1 >= 0) && (sec_r001967_15_1 <= 255));
  __CPROVER_assume((sec_r001967_15_2 >= 0) && (sec_r001967_15_2 <= 255));
  __CPROVER_assume((sec_r001967_16_1 >= 0) && (sec_r001967_16_1 <= 255));
  __CPROVER_assume((sec_r001967_16_2 >= 0) && (sec_r001967_16_2 <= 255));
  __CPROVER_assume((sec_r001967_17_1 >= 0) && (sec_r001967_17_1 <= 255));
  __CPROVER_assume((sec_r001967_17_2 >= 0) && (sec_r001967_17_2 <= 255));
  __CPROVER_assume((sec_r001967_18_1 >= 0) && (sec_r001967_18_1 <= 255));
  __CPROVER_assume((sec_r001967_18_2 >= 0) && (sec_r001967_18_2 <= 255));
  __CPROVER_assume((sec_r001967_19_1 >= 0) && (sec_r001967_19_1 <= 255));
  __CPROVER_assume((sec_r001967_19_2 >= 0) && (sec_r001967_19_2 <= 255));
  struct StreamBuffer_R001967_6713_0 st_var_0_1 = {0};
  struct StreamBuffer_R001967_6713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001967_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001967_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001967_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001967_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001967_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001967_0_2 + 7) & 15;
  struct Vector3D_R001967_6713_1 st_var_1_1 = {0};
  struct Vector3D_R001967_6713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001967_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001967_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001967_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001967_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001967_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001967_0_2 + 9) & 15;
  struct MatrixBlock_R001967_6713_2 st_var_2_1 = {0};
  struct MatrixBlock_R001967_6713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001967_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001967_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001967_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001967_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001967_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001967_0_2 + 11) & 15;
  union ColorPixel_R001967_6713_0 u_var_1;
  union ColorPixel_R001967_6713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001967_6713_0(sec_r001967_0_1, sec_r001967_1_1, pub_r001967_2_1, pub_r001967_3_1, pub_r001967_4_1);
  int helper_flow_0_2 = fn_R001967_6713_0(sec_r001967_0_2, sec_r001967_1_2, pub_r001967_2_2, pub_r001967_3_2, pub_r001967_4_2);
  fn_R001967_6713_0_2(sec_r001967_0_1, sec_r001967_1_1, pub_r001967_2_1, pub_r001967_3_1, pub_r001967_4_1, sec_r001967_0_2, sec_r001967_1_2, pub_r001967_2_2, pub_r001967_3_2, pub_r001967_4_2);
  int helper_flow_1_1 = fn_R001967_6713_1(sec_r001967_1_1, pub_r001967_2_1, pub_r001967_3_1, pub_r001967_4_1);
  int helper_flow_1_2 = fn_R001967_6713_1(sec_r001967_1_2, pub_r001967_2_2, pub_r001967_3_2, pub_r001967_4_2);
  fn_R001967_6713_1_2(sec_r001967_1_1, pub_r001967_2_1, pub_r001967_3_1, pub_r001967_4_1, sec_r001967_1_2, pub_r001967_2_2, pub_r001967_3_2, pub_r001967_4_2);
  int helper_flow_2_1 = fn_R001967_6713_2(sec_r001967_2_1, pub_r001967_3_1, pub_r001967_4_1);
  int helper_flow_2_2 = fn_R001967_6713_2(sec_r001967_2_2, pub_r001967_3_2, pub_r001967_4_2);
  fn_R001967_6713_2_2(sec_r001967_2_1, pub_r001967_3_1, pub_r001967_4_1, sec_r001967_2_2, pub_r001967_3_2, pub_r001967_4_2);
  int helper_flow_3_1 = fn_R001967_6713_3(sec_r001967_3_1, pub_r001967_4_1, pub_r001967_5_1);
  int helper_flow_3_2 = fn_R001967_6713_3(sec_r001967_3_2, pub_r001967_4_2, pub_r001967_5_2);
  fn_R001967_6713_3_2(sec_r001967_3_1, pub_r001967_4_1, pub_r001967_5_1, sec_r001967_3_2, pub_r001967_4_2, pub_r001967_5_2);
  int helper_flow_4_1 = fn_R001967_6713_4(sec_r001967_4_1, sec_r001967_5_1, pub_r001967_6_1, pub_r001967_7_1, pub_r001967_8_1);
  int helper_flow_4_2 = fn_R001967_6713_4(sec_r001967_4_2, sec_r001967_5_2, pub_r001967_6_2, pub_r001967_7_2, pub_r001967_8_2);
  fn_R001967_6713_4_2(sec_r001967_4_1, sec_r001967_5_1, pub_r001967_6_1, pub_r001967_7_1, pub_r001967_8_1, sec_r001967_4_2, sec_r001967_5_2, pub_r001967_6_2, pub_r001967_7_2, pub_r001967_8_2);
  int helper_flow_5_1 = fn_R001967_6713_5(sec_r001967_5_1, sec_r001967_6_1, pub_r001967_7_1, pub_r001967_8_1);
  int helper_flow_5_2 = fn_R001967_6713_5(sec_r001967_5_2, sec_r001967_6_2, pub_r001967_7_2, pub_r001967_8_2);
  fn_R001967_6713_5_2(sec_r001967_5_1, sec_r001967_6_1, pub_r001967_7_1, pub_r001967_8_1, sec_r001967_5_2, sec_r001967_6_2, pub_r001967_7_2, pub_r001967_8_2);
  int helper_flow_6_1 = fn_R001967_6713_6(sec_r001967_6_1, sec_r001967_7_1, pub_r001967_8_1, pub_r001967_9_1, pub_r001967_10_1);
  int helper_flow_6_2 = fn_R001967_6713_6(sec_r001967_6_2, sec_r001967_7_2, pub_r001967_8_2, pub_r001967_9_2, pub_r001967_10_2);
  fn_R001967_6713_6_2(sec_r001967_6_1, sec_r001967_7_1, pub_r001967_8_1, pub_r001967_9_1, pub_r001967_10_1, sec_r001967_6_2, sec_r001967_7_2, pub_r001967_8_2, pub_r001967_9_2, pub_r001967_10_2);
  int helper_flow_7_1 = fn_R001967_6713_7(sec_r001967_7_1, sec_r001967_8_1, pub_r001967_9_1, pub_r001967_10_1, pub_r001967_11_1);
  int helper_flow_7_2 = fn_R001967_6713_7(sec_r001967_7_2, sec_r001967_8_2, pub_r001967_9_2, pub_r001967_10_2, pub_r001967_11_2);
  fn_R001967_6713_7_2(sec_r001967_7_1, sec_r001967_8_1, pub_r001967_9_1, pub_r001967_10_1, pub_r001967_11_1, sec_r001967_7_2, sec_r001967_8_2, pub_r001967_9_2, pub_r001967_10_2, pub_r001967_11_2);
  int helper_flow_8_1 = fn_R001967_6713_8(sec_r001967_8_1, pub_r001967_9_1);
  int helper_flow_8_2 = fn_R001967_6713_8(sec_r001967_8_2, pub_r001967_9_2);
  fn_R001967_6713_8_2(sec_r001967_8_1, pub_r001967_9_1, sec_r001967_8_2, pub_r001967_9_2);
  int helper_flow_9_1 = fn_R001967_6713_9(sec_r001967_9_1, sec_r001967_10_1, pub_r001967_11_1);
  int helper_flow_9_2 = fn_R001967_6713_9(sec_r001967_9_2, sec_r001967_10_2, pub_r001967_11_2);
  fn_R001967_6713_9_2(sec_r001967_9_1, sec_r001967_10_1, pub_r001967_11_1, sec_r001967_9_2, sec_r001967_10_2, pub_r001967_11_2);
  int helper_flow_10_1 = fn_R001967_6713_10(sec_r001967_10_1, pub_r001967_11_1, pub_r001967_12_1, pub_r001967_13_1, pub_r001967_14_1);
  int helper_flow_10_2 = fn_R001967_6713_10(sec_r001967_10_2, pub_r001967_11_2, pub_r001967_12_2, pub_r001967_13_2, pub_r001967_14_2);
  fn_R001967_6713_10_2(sec_r001967_10_1, pub_r001967_11_1, pub_r001967_12_1, pub_r001967_13_1, pub_r001967_14_1, sec_r001967_10_2, pub_r001967_11_2, pub_r001967_12_2, pub_r001967_13_2, pub_r001967_14_2);
  int stage_v_0_1 = ((pub_r001967_4_1 * 2) + 11) & 63;
  int stage_v_0_2 = ((pub_r001967_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001967_17_1 * 2) + 32) & 63;
  int stage_v_1_2 = ((pub_r001967_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001967_8_1 * 2) + 35) & 63;
  int stage_v_2_2 = ((pub_r001967_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (sec_r001967_4_1 ^ pub_r001967_16_1) & 63;
  int stage_v_3_2 = (sec_r001967_4_2 ^ pub_r001967_16_2) & 63;
  if ((stage_v_3_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_3_1 * 2)) & 255;
  }
  if ((stage_v_3_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_3_2 * 2)) & 255;
  }
  int stage_v_4_1 = (sec_r001967_18_1 ^ pub_r001967_0_1) & 63;
  int stage_v_4_2 = (sec_r001967_18_2 ^ pub_r001967_0_2) & 63;
  if ((stage_v_4_1 & 1) != 0)
  {
    if ((sec_r001967_2_1 & 2) != 0)
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
    if ((sec_r001967_2_2 & 2) != 0)
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
  int stage_v_5_1 = ((pub_r001967_18_1 * 2) + 22) & 63;
  int stage_v_5_2 = ((pub_r001967_18_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (sec_r001967_10_1 ^ pub_r001967_17_1) & 63;
  int stage_v_6_2 = (sec_r001967_10_2 ^ pub_r001967_17_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((sec_r001967_10_1 & 2) != 0)
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
    if ((sec_r001967_10_2 & 2) != 0)
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
  int stage_v_7_1 = (sec_r001967_4_1 ^ pub_r001967_17_1) & 63;
  int stage_v_7_2 = (sec_r001967_4_2 ^ pub_r001967_17_2) & 63;
  if ((stage_v_7_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
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
    if ((stage_v_6_2 & 2) != 0)
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
  int stage_v_8_1 = (helper_flow_4_1 ^ pub_r001967_7_1) & 63;
  int stage_v_8_2 = (helper_flow_4_2 ^ pub_r001967_7_2) & 63;
  if ((stage_v_8_1 & 1) != 0)
  {
    if ((sec_r001967_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_8_1 * 2)) & 255;
  }
  if ((stage_v_8_2 & 1) != 0)
  {
    if ((sec_r001967_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_8_2 * 2)) & 255;
  }
  int stage_v_9_1 = ((pub_r001967_17_1 * 2) + 22) & 63;
  int stage_v_9_2 = ((pub_r001967_17_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (stage_v_8_1 ^ pub_r001967_0_1) & 63;
  int stage_v_10_2 = (stage_v_8_2 ^ pub_r001967_0_2) & 63;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((helper_flow_10_1 & 2) != 0)
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
    if ((helper_flow_10_2 & 2) != 0)
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
  int stage_v_11_1 = ((pub_r001967_15_1 * 2) + 29) & 63;
  int stage_v_11_2 = ((pub_r001967_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (helper_flow_10_1 ^ pub_r001967_14_1) & 63;
  int stage_v_12_2 = (helper_flow_10_2 ^ pub_r001967_14_2) & 63;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((sec_r001967_18_1 & 2) != 0)
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
    if ((sec_r001967_18_2 & 2) != 0)
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
  int stage_v_13_1 = (sec_r001967_11_1 ^ pub_r001967_3_1) & 63;
  int stage_v_13_2 = (sec_r001967_11_2 ^ pub_r001967_3_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r001967_10_1 & 2) != 0)
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
    if ((sec_r001967_10_2 & 2) != 0)
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
  int stage_v_14_1 = ((pub_r001967_13_1 * 2) + 5) & 63;
  int stage_v_14_2 = ((pub_r001967_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001967_7_1 * 2) + 22) & 63;
  int stage_v_15_2 = ((pub_r001967_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (sec_r001967_17_1 ^ pub_r001967_9_1) & 63;
  int stage_v_16_2 = (sec_r001967_17_2 ^ pub_r001967_9_2) & 63;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((helper_flow_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_16_1 * 2)) & 255;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((helper_flow_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_16_2 * 2)) & 255;
  }
  int stage_v_17_1 = (stage_v_6_1 ^ pub_r001967_5_1) & 63;
  int stage_v_17_2 = (stage_v_6_2 ^ pub_r001967_5_2) & 63;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_18_1 = (sec_r001967_9_1 ^ pub_r001967_10_1) & 63;
  int stage_v_18_2 = (sec_r001967_9_2 ^ pub_r001967_10_2) & 63;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
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
    if ((helper_flow_7_2 & 2) != 0)
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
  int stage_v_19_1 = (stage_v_10_1 ^ pub_r001967_1_1) & 63;
  int stage_v_19_2 = (stage_v_10_2 ^ pub_r001967_1_2) & 63;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_19_1 * 2)) & 255;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_19_2 * 2)) & 255;
  }
  int stage_v_20_1 = (sec_r001967_0_1 ^ pub_r001967_14_1) & 63;
  int stage_v_20_2 = (sec_r001967_0_2 ^ pub_r001967_14_2) & 63;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r001967_19_1 & 2) != 0)
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
    if ((sec_r001967_19_2 & 2) != 0)
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
  int stage_v_21_1 = ((pub_r001967_7_1 * 2) + 44) & 63;
  int stage_v_21_2 = ((pub_r001967_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (stage_v_8_1 ^ pub_r001967_11_1) & 63;
  int stage_v_22_2 = (stage_v_8_2 ^ pub_r001967_11_2) & 63;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r001967_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_22_1 * 2)) & 255;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r001967_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_22_2 * 2)) & 255;
  }
  int stage_v_23_1 = (stage_v_17_1 ^ pub_r001967_10_1) & 63;
  int stage_v_23_2 = (stage_v_17_2 ^ pub_r001967_10_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
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
    if ((helper_flow_2_2 & 2) != 0)
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
  int stage_v_24_1 = (helper_flow_0_1 ^ pub_r001967_5_1) & 63;
  int stage_v_24_2 = (helper_flow_0_2 ^ pub_r001967_5_2) & 63;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_24_1 * 2)) & 255;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_24_2 * 2)) & 255;
  }
  int stage_v_25_1 = (helper_flow_0_1 ^ pub_r001967_0_1) & 63;
  int stage_v_25_2 = (helper_flow_0_2 ^ pub_r001967_0_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r001967_16_1 & 2) != 0)
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
    if ((sec_r001967_16_2 & 2) != 0)
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
  int stage_v_26_1 = (stage_v_20_1 ^ pub_r001967_7_1) & 63;
  int stage_v_26_2 = (stage_v_20_2 ^ pub_r001967_7_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((helper_flow_10_1 & 2) != 0)
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
    if ((helper_flow_10_2 & 2) != 0)
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
  int stage_v_27_1 = ((pub_r001967_7_1 * 2) + 43) & 63;
  int stage_v_27_2 = ((pub_r001967_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001967_9_1 * 2) + 44) & 63;
  int stage_v_28_2 = ((pub_r001967_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (sec_r001967_0_1 ^ pub_r001967_17_1) & 63;
  int stage_v_29_2 = (sec_r001967_0_2 ^ pub_r001967_17_2) & 63;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((stage_v_8_1 & 2) != 0)
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
    if ((stage_v_8_2 & 2) != 0)
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
  int stage_v_30_1 = ((pub_r001967_7_1 * 2) + 11) & 63;
  int stage_v_30_2 = ((pub_r001967_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (helper_flow_2_1 ^ pub_r001967_13_1) & 63;
  int stage_v_31_2 = (helper_flow_2_2 ^ pub_r001967_13_2) & 63;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_31_1 * 2)) & 255;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_31_2 * 2)) & 255;
  }
  int stage_v_32_1 = ((pub_r001967_5_1 * 2) + 18) & 63;
  int stage_v_32_2 = ((pub_r001967_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001967_5_1 * 2) + 20) & 63;
  int stage_v_33_2 = ((pub_r001967_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001967_9_1 * 2) + 13) & 63;
  int stage_v_34_2 = ((pub_r001967_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (stage_v_25_1 ^ pub_r001967_15_1) & 63;
  int stage_v_35_2 = (stage_v_25_2 ^ pub_r001967_15_2) & 63;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_35_1 * 2)) & 255;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((stage_v_25_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_35_2 * 2)) & 255;
  }
  int stage_v_36_1 = (stage_v_29_1 ^ pub_r001967_18_1) & 63;
  int stage_v_36_2 = (stage_v_29_2 ^ pub_r001967_18_2) & 63;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r001967_2_1 & 2) != 0)
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
    if ((sec_r001967_2_2 & 2) != 0)
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
  int stage_v_37_1 = (helper_flow_6_1 ^ pub_r001967_10_1) & 63;
  int stage_v_37_2 = (helper_flow_6_2 ^ pub_r001967_10_2) & 63;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r001967_15_1 & 2) != 0)
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
    if ((sec_r001967_15_2 & 2) != 0)
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
  int stage_v_38_1 = ((pub_r001967_12_1 * 2) + 40) & 63;
  int stage_v_38_2 = ((pub_r001967_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (sec_r001967_7_1 ^ pub_r001967_12_1) & 63;
  int stage_v_39_2 = (sec_r001967_7_2 ^ pub_r001967_12_2) & 63;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r001967_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_39_1 * 2)) & 255;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r001967_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_39_2 * 2)) & 255;
  }
  int stage_v_40_1 = (sec_r001967_14_1 ^ pub_r001967_7_1) & 63;
  int stage_v_40_2 = (sec_r001967_14_2 ^ pub_r001967_7_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r001967_2_1 & 2) != 0)
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
    if ((sec_r001967_2_2 & 2) != 0)
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
  int stage_v_41_1 = (stage_v_6_1 ^ pub_r001967_15_1) & 63;
  int stage_v_41_2 = (stage_v_6_2 ^ pub_r001967_15_2) & 63;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
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
    if ((stage_v_31_2 & 2) != 0)
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
  int stage_v_42_1 = (stage_v_16_1 ^ pub_r001967_13_1) & 63;
  int stage_v_42_2 = (stage_v_16_2 ^ pub_r001967_13_2) & 63;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r001967_19_1 & 2) != 0)
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
    if ((sec_r001967_19_2 & 2) != 0)
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
  int stage_v_43_1 = (stage_v_31_1 ^ pub_r001967_14_1) & 63;
  int stage_v_43_2 = (stage_v_31_2 ^ pub_r001967_14_2) & 63;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((stage_v_36_1 & 2) != 0)
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
    if ((stage_v_36_2 & 2) != 0)
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
  int stage_v_44_1 = (helper_flow_1_1 ^ pub_r001967_4_1) & 63;
  int stage_v_44_2 = (helper_flow_1_2 ^ pub_r001967_4_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_44_1 * 2)) & 255;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((stage_v_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_44_2 * 2)) & 255;
  }
  int stage_v_45_1 = (stage_v_17_1 ^ pub_r001967_4_1) & 63;
  int stage_v_45_2 = (stage_v_17_2 ^ pub_r001967_4_2) & 63;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r001967_14_1 & 2) != 0)
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
    if ((sec_r001967_14_2 & 2) != 0)
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
  int stage_v_46_1 = ((pub_r001967_4_1 * 2) + 46) & 63;
  int stage_v_46_2 = ((pub_r001967_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (stage_v_31_1 ^ pub_r001967_5_1) & 63;
  int stage_v_47_2 = (stage_v_31_2 ^ pub_r001967_5_2) & 63;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
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
    if ((stage_v_7_2 & 2) != 0)
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
  int stage_v_48_1 = (stage_v_13_1 ^ pub_r001967_14_1) & 63;
  int stage_v_48_2 = (stage_v_13_2 ^ pub_r001967_14_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_48_1 * 2)) & 255;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((stage_v_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_48_2 * 2)) & 255;
  }
  int stage_v_49_1 = (stage_v_8_1 ^ pub_r001967_0_1) & 63;
  int stage_v_49_2 = (stage_v_8_2 ^ pub_r001967_0_2) & 63;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_49_1 * 2)) & 255;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_49_2 * 2)) & 255;
  }
  int stage_v_50_1 = (helper_flow_5_1 ^ pub_r001967_16_1) & 63;
  int stage_v_50_2 = (helper_flow_5_2 ^ pub_r001967_16_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
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
    if ((stage_v_13_2 & 2) != 0)
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
  int stage_v_51_1 = ((pub_r001967_18_1 * 2) + 41) & 63;
  int stage_v_51_2 = ((pub_r001967_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001967_6_1 * 2) + 15) & 63;
  int stage_v_52_2 = ((pub_r001967_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (stage_v_39_1 ^ pub_r001967_17_1) & 63;
  int stage_v_53_2 = (stage_v_39_2 ^ pub_r001967_17_2) & 63;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r001967_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_53_1 * 2)) & 255;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r001967_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_53_2 * 2)) & 255;
  }
  int stage_v_54_1 = (stage_v_6_1 ^ pub_r001967_9_1) & 63;
  int stage_v_54_2 = (stage_v_6_2 ^ pub_r001967_9_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r001967_1_1 & 2) != 0)
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
    if ((sec_r001967_1_2 & 2) != 0)
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
  int stage_v_55_1 = ((pub_r001967_2_1 * 2) + 41) & 63;
  int stage_v_55_2 = ((pub_r001967_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (helper_flow_1_1 ^ pub_r001967_18_1) & 63;
  int stage_v_56_2 = (helper_flow_1_2 ^ pub_r001967_18_2) & 63;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_56_1 * 2)) & 255;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((stage_v_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_56_2 * 2)) & 255;
  }
  int stage_v_57_1 = (stage_v_26_1 ^ pub_r001967_7_1) & 63;
  int stage_v_57_2 = (stage_v_26_2 ^ pub_r001967_7_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r001967_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_57_1 * 2)) & 255;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r001967_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_57_2 * 2)) & 255;
  }
  int stage_v_58_1 = (helper_flow_7_1 ^ pub_r001967_7_1) & 63;
  int stage_v_58_2 = (helper_flow_7_2 ^ pub_r001967_7_2) & 63;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r001967_4_1 & 2) != 0)
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
    if ((sec_r001967_4_2 & 2) != 0)
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
  int stage_v_59_1 = ((pub_r001967_14_1 * 2) + 43) & 63;
  int stage_v_59_2 = ((pub_r001967_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001967_7_1 * 2) + 37) & 63;
  int stage_v_60_2 = ((pub_r001967_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (stage_v_40_1 ^ pub_r001967_16_1) & 63;
  int stage_v_61_2 = (stage_v_40_2 ^ pub_r001967_16_2) & 63;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
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
    if ((helper_flow_6_2 & 2) != 0)
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
  int stage_v_62_1 = ((pub_r001967_6_1 * 2) + 35) & 63;
  int stage_v_62_2 = ((pub_r001967_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001967_5_1 * 2) + 32) & 63;
  int stage_v_63_2 = ((pub_r001967_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001967_14_1 * 2) + 34) & 63;
  int stage_v_64_2 = ((pub_r001967_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (sec_r001967_4_1 ^ pub_r001967_1_1) & 63;
  int stage_v_65_2 = (sec_r001967_4_2 ^ pub_r001967_1_2) & 63;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
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
    if ((helper_flow_5_2 & 2) != 0)
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
  int stage_v_66_1 = (helper_flow_6_1 ^ pub_r001967_15_1) & 63;
  int stage_v_66_2 = (helper_flow_6_2 ^ pub_r001967_15_2) & 63;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((helper_flow_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_66_1 * 2)) & 255;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((helper_flow_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_66_2 * 2)) & 255;
  }
  int stage_v_67_1 = ((pub_r001967_9_1 * 2) + 19) & 63;
  int stage_v_67_2 = ((pub_r001967_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (sec_r001967_8_1 ^ pub_r001967_7_1) & 63;
  int stage_v_68_2 = (sec_r001967_8_2 ^ pub_r001967_7_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((stage_v_53_1 & 2) != 0)
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
    if ((stage_v_53_2 & 2) != 0)
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
  int stage_v_69_1 = ((pub_r001967_10_1 * 2) + 33) & 63;
  int stage_v_69_2 = ((pub_r001967_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (sec_r001967_0_1 ^ pub_r001967_12_1) & 63;
  int stage_v_70_2 = (sec_r001967_0_2 ^ pub_r001967_12_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
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
    if ((stage_v_26_2 & 2) != 0)
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
  int stage_v_71_1 = (helper_flow_9_1 ^ pub_r001967_2_1) & 63;
  int stage_v_71_2 = (helper_flow_9_2 ^ pub_r001967_2_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r001967_17_1 & 2) != 0)
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
    if ((sec_r001967_17_2 & 2) != 0)
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
  int stage_v_72_1 = (stage_v_24_1 ^ pub_r001967_17_1) & 63;
  int stage_v_72_2 = (stage_v_24_2 ^ pub_r001967_17_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r001967_19_1 & 2) != 0)
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
    if ((sec_r001967_19_2 & 2) != 0)
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
  int stage_v_73_1 = (helper_flow_6_1 ^ pub_r001967_9_1) & 63;
  int stage_v_73_2 = (helper_flow_6_2 ^ pub_r001967_9_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((stage_v_54_1 & 2) != 0)
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
    if ((stage_v_54_2 & 2) != 0)
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
  int stage_v_74_1 = (sec_r001967_17_1 ^ pub_r001967_1_1) & 63;
  int stage_v_74_2 = (sec_r001967_17_2 ^ pub_r001967_1_2) & 63;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r001967_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r001967_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  }
  int stage_v_75_1 = (stage_v_17_1 ^ pub_r001967_4_1) & 63;
  int stage_v_75_2 = (stage_v_17_2 ^ pub_r001967_4_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
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
    if ((helper_flow_2_2 & 2) != 0)
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
  int stage_v_76_1 = ((pub_r001967_3_1 * 2) + 36) & 63;
  int stage_v_76_2 = ((pub_r001967_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001967_8_1 * 2) + 47) & 63;
  int stage_v_77_2 = ((pub_r001967_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001967_2_1 * 2) + 26) & 63;
  int stage_v_78_2 = ((pub_r001967_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (stage_v_25_1 ^ pub_r001967_1_1) & 63;
  int stage_v_79_2 = (stage_v_25_2 ^ pub_r001967_1_2) & 63;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((stage_v_57_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((stage_v_57_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  }
  int stage_v_80_1 = ((pub_r001967_14_1 * 2) + 18) & 63;
  int stage_v_80_2 = ((pub_r001967_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (stage_v_26_1 ^ pub_r001967_16_1) & 63;
  int stage_v_81_2 = (stage_v_26_2 ^ pub_r001967_16_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((stage_v_58_1 & 2) != 0)
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
    if ((stage_v_58_2 & 2) != 0)
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
  int stage_v_82_1 = (stage_v_7_1 ^ pub_r001967_12_1) & 63;
  int stage_v_82_2 = (stage_v_7_2 ^ pub_r001967_12_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((stage_v_81_1 & 2) != 0)
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
    if ((stage_v_81_2 & 2) != 0)
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
  int stage_v_83_1 = (stage_v_17_1 ^ pub_r001967_14_1) & 63;
  int stage_v_83_2 = (stage_v_17_2 ^ pub_r001967_14_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
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
    if ((helper_flow_8_2 & 2) != 0)
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
  int stage_v_84_1 = ((pub_r001967_8_1 * 2) + 24) & 63;
  int stage_v_84_2 = ((pub_r001967_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (stage_v_31_1 ^ pub_r001967_8_1) & 63;
  int stage_v_85_2 = (stage_v_31_2 ^ pub_r001967_8_2) & 63;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r001967_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r001967_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  }
  int stage_v_86_1 = (stage_v_79_1 ^ pub_r001967_3_1) & 63;
  int stage_v_86_2 = (stage_v_79_2 ^ pub_r001967_3_2) & 63;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((stage_v_61_1 & 2) != 0)
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
    if ((stage_v_61_2 & 2) != 0)
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
  int stage_v_87_1 = (stage_v_23_1 ^ pub_r001967_5_1) & 63;
  int stage_v_87_2 = (stage_v_23_2 ^ pub_r001967_5_2) & 63;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r001967_6_1 & 2) != 0)
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
    if ((sec_r001967_6_2 & 2) != 0)
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
  int stage_v_88_1 = (sec_r001967_6_1 ^ pub_r001967_7_1) & 63;
  int stage_v_88_2 = (sec_r001967_6_2 ^ pub_r001967_7_2) & 63;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r001967_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r001967_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  }
  int stage_v_89_1 = ((pub_r001967_18_1 * 2) + 37) & 63;
  int stage_v_89_2 = ((pub_r001967_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (helper_flow_7_1 ^ pub_r001967_2_1) & 63;
  int stage_v_90_2 = (helper_flow_7_2 ^ pub_r001967_2_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((stage_v_85_1 & 2) != 0)
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
    if ((stage_v_85_2 & 2) != 0)
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
  int stage_v_91_1 = (stage_v_41_1 ^ pub_r001967_5_1) & 63;
  int stage_v_91_2 = (stage_v_41_2 ^ pub_r001967_5_2) & 63;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((stage_v_24_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((stage_v_24_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  }
  int stage_v_92_1 = (stage_v_35_1 ^ pub_r001967_4_1) & 63;
  int stage_v_92_2 = (stage_v_35_2 ^ pub_r001967_4_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((stage_v_81_1 & 2) != 0)
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
    if ((stage_v_81_2 & 2) != 0)
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
  int stage_v_93_1 = ((pub_r001967_7_1 * 2) + 27) & 63;
  int stage_v_93_2 = ((pub_r001967_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (stage_v_74_1 ^ pub_r001967_0_1) & 63;
  int stage_v_94_2 = (stage_v_74_2 ^ pub_r001967_0_2) & 63;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r001967_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r001967_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  }
  int stage_v_95_1 = (stage_v_22_1 ^ pub_r001967_17_1) & 63;
  int stage_v_95_2 = (stage_v_22_2 ^ pub_r001967_17_2) & 63;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((stage_v_65_1 & 2) != 0)
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
    if ((stage_v_65_2 & 2) != 0)
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
  int stage_v_96_1 = (stage_v_72_1 ^ pub_r001967_7_1) & 63;
  int stage_v_96_2 = (stage_v_72_2 ^ pub_r001967_7_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r001967_4_1 & 2) != 0)
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
    if ((sec_r001967_4_2 & 2) != 0)
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
  int stage_v_97_1 = (sec_r001967_14_1 ^ pub_r001967_15_1) & 63;
  int stage_v_97_2 = (sec_r001967_14_2 ^ pub_r001967_15_2) & 63;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r001967_3_1 & 2) != 0)
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
    if ((sec_r001967_3_2 & 2) != 0)
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
  int stage_v_98_1 = (helper_flow_8_1 ^ pub_r001967_0_1) & 63;
  int stage_v_98_2 = (helper_flow_8_2 ^ pub_r001967_0_2) & 63;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((stage_v_91_1 & 2) != 0)
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
    if ((stage_v_91_2 & 2) != 0)
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
  int stage_v_99_1 = ((pub_r001967_0_1 * 2) + 45) & 63;
  int stage_v_99_2 = ((pub_r001967_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (stage_v_56_1 ^ pub_r001967_10_1) & 63;
  int stage_v_100_2 = (stage_v_56_2 ^ pub_r001967_10_2) & 63;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r001967_2_1 & 2) != 0)
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
    if ((sec_r001967_2_2 & 2) != 0)
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
  int stage_v_101_1 = (stage_v_39_1 ^ pub_r001967_5_1) & 63;
  int stage_v_101_2 = (stage_v_39_2 ^ pub_r001967_5_2) & 63;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((stage_v_98_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((stage_v_98_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  }
  int stage_v_102_1 = (stage_v_88_1 ^ pub_r001967_8_1) & 63;
  int stage_v_102_2 = (stage_v_88_2 ^ pub_r001967_8_2) & 63;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  }
  int stage_v_103_1 = ((pub_r001967_13_1 * 2) + 47) & 63;
  int stage_v_103_2 = ((pub_r001967_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (sec_r001967_14_1 ^ pub_r001967_7_1) & 63;
  int stage_v_104_2 = (sec_r001967_14_2 ^ pub_r001967_7_2) & 63;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((stage_v_58_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((stage_v_58_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  }
  int stage_v_105_1 = (stage_v_86_1 ^ pub_r001967_15_1) & 63;
  int stage_v_105_2 = (stage_v_86_2 ^ pub_r001967_15_2) & 63;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((stage_v_94_1 & 2) != 0)
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
    if ((stage_v_94_2 & 2) != 0)
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
  int stage_v_106_1 = ((pub_r001967_2_1 * 2) + 8) & 63;
  int stage_v_106_2 = ((pub_r001967_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001967_13_1 * 2) + 19) & 63;
  int stage_v_107_2 = ((pub_r001967_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (helper_flow_9_1 ^ pub_r001967_3_1) & 63;
  int stage_v_108_2 = (helper_flow_9_2 ^ pub_r001967_3_2) & 63;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r001967_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r001967_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  }
  int stage_v_109_1 = ((pub_r001967_18_1 * 2) + 17) & 63;
  int stage_v_109_2 = ((pub_r001967_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001967_0_1 * 2) + 8) & 63;
  int stage_v_110_2 = ((pub_r001967_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (stage_v_10_1 ^ pub_r001967_3_1) & 63;
  int stage_v_111_2 = (stage_v_10_2 ^ pub_r001967_3_2) & 63;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r001967_15_1 & 2) != 0)
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
    if ((sec_r001967_15_2 & 2) != 0)
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
  int stage_v_112_1 = (sec_r001967_12_1 ^ pub_r001967_16_1) & 63;
  int stage_v_112_2 = (sec_r001967_12_2 ^ pub_r001967_16_2) & 63;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((stage_v_83_1 & 2) != 0)
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
    if ((stage_v_83_2 & 2) != 0)
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
  int stage_v_113_1 = (helper_flow_8_1 ^ pub_r001967_5_1) & 63;
  int stage_v_113_2 = (helper_flow_8_2 ^ pub_r001967_5_2) & 63;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r001967_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r001967_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  }
  int stage_v_114_1 = (stage_v_12_1 ^ pub_r001967_6_1) & 63;
  int stage_v_114_2 = (stage_v_12_2 ^ pub_r001967_6_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((stage_v_57_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((stage_v_57_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  }
  int stage_v_115_1 = ((pub_r001967_15_1 * 2) + 49) & 63;
  int stage_v_115_2 = ((pub_r001967_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001967_17_1 * 2) + 28) & 63;
  int stage_v_116_2 = ((pub_r001967_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001967_9_1 * 2) + 14) & 63;
  int stage_v_117_2 = ((pub_r001967_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (sec_r001967_16_1 ^ pub_r001967_5_1) & 63;
  int stage_v_118_2 = (sec_r001967_16_2 ^ pub_r001967_5_2) & 63;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((stage_v_113_1 & 2) != 0)
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
    if ((stage_v_113_2 & 2) != 0)
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
  int stage_v_119_1 = (stage_v_85_1 ^ pub_r001967_13_1) & 63;
  int stage_v_119_2 = (stage_v_85_2 ^ pub_r001967_13_2) & 63;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r001967_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r001967_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  }
  int stage_v_120_1 = ((pub_r001967_13_1 * 2) + 6) & 63;
  int stage_v_120_2 = ((pub_r001967_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (stage_v_4_1 ^ pub_r001967_17_1) & 63;
  int stage_v_121_2 = (stage_v_4_2 ^ pub_r001967_17_2) & 63;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((stage_v_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  }
  int stage_v_122_1 = ((pub_r001967_16_1 * 2) + 13) & 63;
  int stage_v_122_2 = ((pub_r001967_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001967_16_1 * 2) + 7) & 63;
  int stage_v_123_2 = ((pub_r001967_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (sec_r001967_16_1 ^ pub_r001967_6_1) & 63;
  int stage_v_124_2 = (sec_r001967_16_2 ^ pub_r001967_6_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r001967_5_1 & 2) != 0)
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
    if ((sec_r001967_5_2 & 2) != 0)
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
  int stage_v_125_1 = ((pub_r001967_17_1 * 2) + 18) & 63;
  int stage_v_125_2 = ((pub_r001967_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001967_16_1 * 2) + 28) & 63;
  int stage_v_126_2 = ((pub_r001967_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001967_15_1 * 2) + 15) & 63;
  int stage_v_127_2 = ((pub_r001967_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001967_2_1 * 2) + 14) & 63;
  int stage_v_128_2 = ((pub_r001967_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001967_18_1 * 2) + 28) & 63;
  int stage_v_129_2 = ((pub_r001967_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (helper_flow_7_1 ^ pub_r001967_14_1) & 63;
  int stage_v_130_2 = (helper_flow_7_2 ^ pub_r001967_14_2) & 63;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
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
    if ((stage_v_10_2 & 2) != 0)
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
  int stage_v_131_1 = (stage_v_74_1 ^ pub_r001967_17_1) & 63;
  int stage_v_131_2 = (stage_v_74_2 ^ pub_r001967_17_2) & 63;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((stage_v_61_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((stage_v_61_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  }
  int stage_v_132_1 = (stage_v_19_1 ^ pub_r001967_4_1) & 63;
  int stage_v_132_2 = (stage_v_19_2 ^ pub_r001967_4_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((stage_v_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  }
  int stage_v_133_1 = ((pub_r001967_12_1 * 2) + 31) & 63;
  int stage_v_133_2 = ((pub_r001967_12_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (sec_r001967_19_1 ^ pub_r001967_2_1) & 63;
  int stage_v_134_2 = (sec_r001967_19_2 ^ pub_r001967_2_2) & 63;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((stage_v_100_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((stage_v_100_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  }
  int stage_v_135_1 = (stage_v_85_1 ^ pub_r001967_3_1) & 63;
  int stage_v_135_2 = (stage_v_85_2 ^ pub_r001967_3_2) & 63;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
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
    if ((stage_v_25_2 & 2) != 0)
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
  int stage_v_136_1 = (helper_flow_0_1 ^ pub_r001967_12_1) & 63;
  int stage_v_136_2 = (helper_flow_0_2 ^ pub_r001967_12_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((stage_v_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((stage_v_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  }
  int stage_v_137_1 = ((pub_r001967_6_1 * 2) + 13) & 63;
  int stage_v_137_2 = ((pub_r001967_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001967_14_1 * 2) + 38) & 63;
  int stage_v_138_2 = ((pub_r001967_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001967_6_1 * 2) + 31) & 63;
  int stage_v_139_2 = ((pub_r001967_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (stage_v_49_1 ^ pub_r001967_7_1) & 63;
  int stage_v_140_2 = (stage_v_49_2 ^ pub_r001967_7_2) & 63;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((stage_v_134_1 & 2) != 0)
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
    if ((stage_v_134_2 & 2) != 0)
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
  int stage_v_141_1 = (stage_v_12_1 ^ pub_r001967_17_1) & 63;
  int stage_v_141_2 = (stage_v_12_2 ^ pub_r001967_17_2) & 63;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((stage_v_104_1 & 2) != 0)
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
    if ((stage_v_104_2 & 2) != 0)
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
  int stage_v_142_1 = (helper_flow_8_1 ^ pub_r001967_14_1) & 63;
  int stage_v_142_2 = (helper_flow_8_2 ^ pub_r001967_14_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((stage_v_22_1 & 2) != 0)
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
    if ((stage_v_22_2 & 2) != 0)
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
  int stage_v_143_1 = (stage_v_57_1 ^ pub_r001967_12_1) & 63;
  int stage_v_143_2 = (stage_v_57_2 ^ pub_r001967_12_2) & 63;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((stage_v_82_1 & 2) != 0)
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
    if ((stage_v_82_2 & 2) != 0)
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
  int stage_v_144_1 = ((pub_r001967_1_1 * 2) + 29) & 63;
  int stage_v_144_2 = ((pub_r001967_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (stage_v_3_1 ^ pub_r001967_18_1) & 63;
  int stage_v_145_2 = (stage_v_3_2 ^ pub_r001967_18_2) & 63;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((stage_v_134_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((stage_v_134_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  }
  int stage_v_146_1 = (helper_flow_3_1 ^ pub_r001967_4_1) & 63;
  int stage_v_146_2 = (helper_flow_3_2 ^ pub_r001967_4_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((stage_v_65_1 & 2) != 0)
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
    if ((stage_v_65_2 & 2) != 0)
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
  int stage_v_147_1 = (stage_v_39_1 ^ pub_r001967_8_1) & 63;
  int stage_v_147_2 = (stage_v_39_2 ^ pub_r001967_8_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
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
    if ((helper_flow_5_2 & 2) != 0)
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
  int stage_v_148_1 = (helper_flow_6_1 ^ pub_r001967_17_1) & 63;
  int stage_v_148_2 = (helper_flow_6_2 ^ pub_r001967_17_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
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
    if ((stage_v_12_2 & 2) != 0)
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
  int stage_v_149_1 = (stage_v_29_1 ^ pub_r001967_9_1) & 63;
  int stage_v_149_2 = (stage_v_29_2 ^ pub_r001967_9_2) & 63;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((stage_v_49_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  }
  if ((stage_v_149_2 & 1) != 0)
  {
    if ((stage_v_49_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  }
  int stage_v_150_1 = (stage_v_98_1 ^ pub_r001967_0_1) & 63;
  int stage_v_150_2 = (stage_v_98_2 ^ pub_r001967_0_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
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
    if ((helper_flow_7_2 & 2) != 0)
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
  int stage_v_151_1 = ((pub_r001967_7_1 * 2) + 6) & 63;
  int stage_v_151_2 = ((pub_r001967_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001967_11_1 * 2) + 27) & 63;
  int stage_v_152_2 = ((pub_r001967_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (stage_v_56_1 ^ pub_r001967_12_1) & 63;
  int stage_v_153_2 = (stage_v_56_2 ^ pub_r001967_12_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((sec_r001967_19_1 & 2) != 0)
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
    if ((sec_r001967_19_2 & 2) != 0)
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
  int stage_v_154_1 = ((pub_r001967_17_1 * 2) + 13) & 63;
  int stage_v_154_2 = ((pub_r001967_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001967_5_1 * 2) + 14) & 63;
  int stage_v_155_2 = ((pub_r001967_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001967_8_1 * 2) + 45) & 63;
  int stage_v_156_2 = ((pub_r001967_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001967_18_1 * 2) + 37) & 63;
  int stage_v_157_2 = ((pub_r001967_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (stage_v_10_1 ^ pub_r001967_5_1) & 63;
  int stage_v_158_2 = (stage_v_10_2 ^ pub_r001967_5_2) & 63;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((stage_v_147_1 & 2) != 0)
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
    if ((stage_v_147_2 & 2) != 0)
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
  int stage_v_159_1 = (stage_v_8_1 ^ pub_r001967_5_1) & 63;
  int stage_v_159_2 = (stage_v_8_2 ^ pub_r001967_5_2) & 63;
  if ((stage_v_159_1 & 1) != 0)
  {
    if ((stage_v_91_1 & 2) != 0)
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
    if ((stage_v_91_2 & 2) != 0)
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
  int stage_v_160_1 = (stage_v_75_1 ^ pub_r001967_7_1) & 63;
  int stage_v_160_2 = (stage_v_75_2 ^ pub_r001967_7_2) & 63;
  if ((stage_v_160_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
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
    if ((stage_v_25_2 & 2) != 0)
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
  int stage_v_161_1 = (stage_v_6_1 ^ pub_r001967_12_1) & 63;
  int stage_v_161_2 = (stage_v_6_2 ^ pub_r001967_12_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
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
    if ((stage_v_7_2 & 2) != 0)
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
  int stage_v_162_1 = ((pub_r001967_9_1 * 2) + 41) & 63;
  int stage_v_162_2 = ((pub_r001967_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (stage_v_124_1 ^ pub_r001967_14_1) & 63;
  int stage_v_163_2 = (stage_v_124_2 ^ pub_r001967_14_2) & 63;
  if ((stage_v_163_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  }
  if ((stage_v_163_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  }
  int stage_v_164_1 = (helper_flow_7_1 ^ pub_r001967_3_1) & 63;
  int stage_v_164_2 = (helper_flow_7_2 ^ pub_r001967_3_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
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
    if ((stage_v_31_2 & 2) != 0)
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
  int stage_v_165_1 = (stage_v_91_1 ^ pub_r001967_10_1) & 63;
  int stage_v_165_2 = (stage_v_91_2 ^ pub_r001967_10_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_105_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  }
  if ((stage_v_165_2 & 1) != 0)
  {
    if ((stage_v_105_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  }
  int stage_v_166_1 = (stage_v_141_1 ^ pub_r001967_15_1) & 63;
  int stage_v_166_2 = (stage_v_141_2 ^ pub_r001967_15_2) & 63;
  if ((stage_v_166_1 & 1) != 0)
  {
    if ((stage_v_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_166_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  }
  if ((stage_v_166_2 & 1) != 0)
  {
    if ((stage_v_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_166_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  }
  int stage_v_167_1 = (stage_v_150_1 ^ pub_r001967_0_1) & 63;
  int stage_v_167_2 = (stage_v_150_2 ^ pub_r001967_0_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((stage_v_58_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_167_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  }
  if ((stage_v_167_2 & 1) != 0)
  {
    if ((stage_v_58_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_167_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  }
  int stage_v_168_1 = (stage_v_91_1 ^ pub_r001967_7_1) & 63;
  int stage_v_168_2 = (stage_v_91_2 ^ pub_r001967_7_2) & 63;
  if ((stage_v_168_1 & 1) != 0)
  {
    if ((stage_v_114_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_168_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  }
  if ((stage_v_168_2 & 1) != 0)
  {
    if ((stage_v_114_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_168_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  }
  int stage_v_169_1 = (sec_r001967_13_1 ^ pub_r001967_18_1) & 63;
  int stage_v_169_2 = (sec_r001967_13_2 ^ pub_r001967_18_2) & 63;
  if ((stage_v_169_1 & 1) != 0)
  {
    if ((stage_v_104_1 & 2) != 0)
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
    if ((stage_v_104_2 & 2) != 0)
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
  int stage_v_170_1 = ((pub_r001967_13_1 * 2) + 40) & 63;
  int stage_v_170_2 = ((pub_r001967_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001967_0_1 * 2) + 11) & 63;
  int stage_v_171_2 = ((pub_r001967_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (stage_v_169_1 ^ pub_r001967_14_1) & 63;
  int stage_v_172_2 = (stage_v_169_2 ^ pub_r001967_14_2) & 63;
  if ((stage_v_172_1 & 1) != 0)
  {
    if ((stage_v_74_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  }
  if ((stage_v_172_2 & 1) != 0)
  {
    if ((stage_v_74_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  }
  int stage_v_173_1 = ((pub_r001967_16_1 * 2) + 21) & 63;
  int stage_v_173_2 = ((pub_r001967_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001967_11_1 * 2) + 48) & 63;
  int stage_v_174_2 = ((pub_r001967_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (stage_v_111_1 ^ pub_r001967_7_1) & 63;
  int stage_v_175_2 = (stage_v_111_2 ^ pub_r001967_7_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((stage_v_83_1 & 2) != 0)
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
    if ((stage_v_83_2 & 2) != 0)
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
  int stage_v_176_1 = ((pub_r001967_7_1 * 2) + 11) & 63;
  int stage_v_176_2 = ((pub_r001967_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001967_9_1 * 2) + 43) & 63;
  int stage_v_177_2 = ((pub_r001967_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001967_7_1 * 2) + 40) & 63;
  int stage_v_178_2 = ((pub_r001967_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (stage_v_111_1 ^ pub_r001967_14_1) & 63;
  int stage_v_179_2 = (stage_v_111_2 ^ pub_r001967_14_2) & 63;
  if ((stage_v_179_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_179_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  }
  if ((stage_v_179_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_179_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  }
  int stage_v_180_1 = ((pub_r001967_1_1 * 2) + 23) & 63;
  int stage_v_180_2 = ((pub_r001967_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (stage_v_112_1 ^ pub_r001967_0_1) & 63;
  int stage_v_181_2 = (stage_v_112_2 ^ pub_r001967_0_2) & 63;
  if ((stage_v_181_1 & 1) != 0)
  {
    if ((stage_v_101_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_181_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  }
  if ((stage_v_181_2 & 1) != 0)
  {
    if ((stage_v_101_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_181_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  }
  int stage_v_182_1 = (stage_v_8_1 ^ pub_r001967_9_1) & 63;
  int stage_v_182_2 = (stage_v_8_2 ^ pub_r001967_9_2) & 63;
  if ((stage_v_182_1 & 1) != 0)
  {
    if ((helper_flow_10_1 & 2) != 0)
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
    if ((helper_flow_10_2 & 2) != 0)
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
  int stage_v_183_1 = ((pub_r001967_11_1 * 2) + 19) & 63;
  int stage_v_183_2 = ((pub_r001967_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (stage_v_167_1 ^ pub_r001967_8_1) & 63;
  int stage_v_184_2 = (stage_v_167_2 ^ pub_r001967_8_2) & 63;
  if ((stage_v_184_1 & 1) != 0)
  {
    if ((sec_r001967_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_184_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  }
  if ((stage_v_184_2 & 1) != 0)
  {
    if ((sec_r001967_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_184_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  }
  int stage_v_185_1 = ((pub_r001967_14_1 * 2) + 16) & 63;
  int stage_v_185_2 = ((pub_r001967_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (helper_flow_3_1 ^ pub_r001967_10_1) & 63;
  int stage_v_186_2 = (helper_flow_3_2 ^ pub_r001967_10_2) & 63;
  if ((stage_v_186_1 & 1) != 0)
  {
    if ((stage_v_153_1 & 2) != 0)
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
    if ((stage_v_153_2 & 2) != 0)
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
  int stage_v_187_1 = (sec_r001967_12_1 ^ pub_r001967_14_1) & 63;
  int stage_v_187_2 = (sec_r001967_12_2 ^ pub_r001967_14_2) & 63;
  if ((stage_v_187_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
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
    if ((stage_v_44_2 & 2) != 0)
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
  int stage_v_188_1 = (stage_v_91_1 ^ pub_r001967_4_1) & 63;
  int stage_v_188_2 = (stage_v_91_2 ^ pub_r001967_4_2) & 63;
  if ((stage_v_188_1 & 1) != 0)
  {
    if ((stage_v_134_1 & 2) != 0)
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
    if ((stage_v_134_2 & 2) != 0)
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
  int stage_v_189_1 = (stage_v_143_1 ^ pub_r001967_2_1) & 63;
  int stage_v_189_2 = (stage_v_143_2 ^ pub_r001967_2_2) & 63;
  if ((stage_v_189_1 & 1) != 0)
  {
    if ((sec_r001967_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_189_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  }
  if ((stage_v_189_2 & 1) != 0)
  {
    if ((sec_r001967_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_189_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001967_15_1 == pub_r001967_15_2);
  __CPROVER_assume(sec_r001967_1_1 != sec_r001967_1_2);
  __CPROVER_assume(sec_r001967_12_1 != sec_r001967_12_2);
  __CPROVER_assume(pub_r001967_5_1 == pub_r001967_5_2);
  __CPROVER_assume(pub_r001967_12_1 == pub_r001967_12_2);
  __CPROVER_assume(pub_r001967_18_1 == pub_r001967_18_2);
  __CPROVER_assume(pub_r001967_16_1 == pub_r001967_16_2);
  __CPROVER_assume(pub_r001967_9_1 == pub_r001967_9_2);
  __CPROVER_assume(pub_r001967_13_1 == pub_r001967_13_2);
  __CPROVER_assume(pub_r001967_17_1 == pub_r001967_17_2);
  __CPROVER_assume(sec_r001967_18_1 != sec_r001967_18_2);
  __CPROVER_assume(sec_r001967_8_1 != sec_r001967_8_2);
  __CPROVER_assume(sec_r001967_0_1 != sec_r001967_0_2);
  __CPROVER_assume(pub_r001967_2_1 == pub_r001967_2_2);
  __CPROVER_assume(pub_r001967_8_1 == pub_r001967_8_2);
  __CPROVER_assume(pub_r001967_3_1 == pub_r001967_3_2);
  __CPROVER_assume(pub_r001967_0_1 == pub_r001967_0_2);
  __CPROVER_assume(sec_r001967_6_1 != sec_r001967_6_2);
  __CPROVER_assume(pub_r001967_6_1 == pub_r001967_6_2);
  __CPROVER_assume(sec_r001967_11_1 != sec_r001967_11_2);
  __CPROVER_assume(sec_r001967_19_1 != sec_r001967_19_2);
  __CPROVER_assume(sec_r001967_9_1 != sec_r001967_9_2);
  __CPROVER_assume(sec_r001967_5_1 != sec_r001967_5_2);
  __CPROVER_assume(sec_r001967_15_1 != sec_r001967_15_2);
  __CPROVER_assume(sec_r001967_3_1 != sec_r001967_3_2);
  __CPROVER_assume(sec_r001967_14_1 != sec_r001967_14_2);
  __CPROVER_assume(pub_r001967_7_1 == pub_r001967_7_2);
  __CPROVER_assume(sec_r001967_16_1 != sec_r001967_16_2);
  __CPROVER_assume(pub_r001967_1_1 == pub_r001967_1_2);
  __CPROVER_assume(sec_r001967_13_1 != sec_r001967_13_2);
  __CPROVER_assume(sec_r001967_7_1 != sec_r001967_7_2);
  __CPROVER_assume(pub_r001967_11_1 == pub_r001967_11_2);
  __CPROVER_assume(sec_r001967_2_1 != sec_r001967_2_2);
  __CPROVER_assume(sec_r001967_17_1 != sec_r001967_17_2);
  __CPROVER_assume(pub_r001967_10_1 == pub_r001967_10_2);
  __CPROVER_assume(sec_r001967_10_1 != sec_r001967_10_2);
  __CPROVER_assume(pub_r001967_4_1 == pub_r001967_4_2);
  __CPROVER_assume(pub_r001967_14_1 == pub_r001967_14_2);
  __CPROVER_assume(sec_r001967_4_1 != sec_r001967_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.state == st_var_0_2.state);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.dim == st_var_2_2.dim);
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
}


