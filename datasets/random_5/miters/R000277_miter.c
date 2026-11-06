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
struct MatrixBlock_R000277_7713_0
{
  unsigned char scale;
  short trace;
  int determinant;
  short density;
  int stride;
  int dim;
  int buffer[3];
};
struct Vector3D_R000277_7713_1
{
  int coord_x;
  unsigned char heading;
  unsigned char norm_sq;
  int buffer[3];
};
struct DeviceConfig_R000277_7713_2
{
  unsigned char parity;
  int timeout;
  short port;
  int baud_rate;
  int id;
  int buffer[3];
};
struct Transaction_R000277_7713_3
{
  int status;
  unsigned char rate;
  int auth_code;
  short fee;
  int buffer[3];
};
union ColorPixel_R000277_7713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000277_7713_1
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
void fn_R000277_7713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st_1 = {0};
  struct Transaction_R000277_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int coefficient_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_76_1)
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

  switch (coefficient_76_2)
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

  int scale_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_31_1 > 14)
  {
    acc_1 = ((acc_1 + (scale_31_1 * 2)) + 5) & 127;
    aux_1 ^= scale_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_31_2 > 14)
  {
    acc_2 = ((acc_2 + (scale_31_2 * 2)) + 5) & 127;
    aux_2 ^= scale_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_40_1) & 63;
  aux_2 = (aux_2 + coefficient_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_76_1 == coefficient_76_2);
  assert(scale_31_1 == scale_31_2);
  assert(coefficient_40_1 == coefficient_40_2);
}

int fn_R000277_7713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int coefficient_76 = (aux + st.buffer[1]) & 3;
  switch (coefficient_76)
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

  int scale_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_31 > 14)
  {
    acc = ((acc + (scale_31 * 2)) + 5) & 127;
    aux ^= scale_31 & 15;
  }
  else
  {
    acc = ((acc - scale_31) + 11) & 127;
    aux += 3;
  }
  int coefficient_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_40) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000277_7713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st_1 = {0};
  struct Transaction_R000277_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_62_1)
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

  switch (mask_62_2)
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

  int coefficient_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_96_1) & 63;
  aux_2 = (aux_2 + coefficient_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_62_1 == mask_62_2);
  assert(coefficient_96_1 == coefficient_96_2);
}

int fn_R000277_7713_1(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_62 = (aux + st.buffer[1]) & 3;
  switch (mask_62)
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

  int coefficient_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000277_7713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st_1 = {0};
  struct Transaction_R000277_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int vector_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_45_1 > 36)
  {
    acc_1 = ((acc_1 + (vector_45_1 * 2)) + 5) & 127;
    aux_1 ^= vector_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_45_2 > 36)
  {
    acc_2 = ((acc_2 + (vector_45_2 * 2)) + 5) & 127;
    aux_2 ^= vector_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_91_1)
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

  switch (metric_91_2)
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

  int tally_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_54_1) & 63;
  aux_2 = (aux_2 + tally_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_45_1 == vector_45_2);
  assert(metric_91_1 == metric_91_2);
  assert(tally_54_1 == tally_54_2);
}

int fn_R000277_7713_2(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int vector_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_45 > 36)
  {
    acc = ((acc + (vector_45 * 2)) + 5) & 127;
    aux ^= vector_45 & 15;
  }
  else
  {
    acc = ((acc - vector_45) + 11) & 127;
    aux += 3;
  }
  int metric_91 = (aux + st.buffer[1]) & 3;
  switch (metric_91)
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

  int tally_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_54) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000277_7713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000277_7713_0 st_1 = {0};
  struct MatrixBlock_R000277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int scale_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_70_1)
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

  switch (scale_70_2)
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

  int index_reg_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_46_1) & 63;
  aux_2 = (aux_2 + index_reg_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_81_1 = local_arr_1[aux_1 % 3];
  int coefficient_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_70_1 == scale_70_2);
  assert(index_reg_46_1 == index_reg_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_81_1 == coefficient_81_2);
}

int fn_R000277_7713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int scale_70 = (aux + st.buffer[1]) & 3;
  switch (scale_70)
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

  int index_reg_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_46) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_81 = local_arr[aux % 3];
  acc = (acc + (coefficient_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000277_7713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000277_7713_0 st_1 = {0};
  struct MatrixBlock_R000277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_78_1 = local_arr_1[aux_1 % 3];
  int tracker_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_78_2 * 2)) & 127;
  int segment_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_88_1)
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

  switch (segment_88_2)
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

  int cursor_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_71_1) & 63;
  aux_2 = (aux_2 + cursor_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_78_1 == tracker_78_2);
  assert(segment_88_1 == segment_88_2);
  assert(cursor_71_1 == cursor_71_2);
}

int fn_R000277_7713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int tracker_78 = local_arr[aux % 3];
  acc = (acc + (tracker_78 * 2)) & 127;
  int segment_88 = (aux + st.buffer[1]) & 3;
  switch (segment_88)
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

  int cursor_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_71) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000277_7713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st_1 = {0};
  struct DeviceConfig_R000277_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int segment_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_98_1) & 63;
  aux_2 = (aux_2 + segment_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_98_1 == segment_98_2);
}

int fn_R000277_7713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int segment_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_98) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000277_7713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st_1 = {0};
  struct DeviceConfig_R000277_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int mask_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_73_1 > 28)
  {
    acc_1 = ((acc_1 + (mask_73_1 * 2)) + 5) & 127;
    aux_1 ^= mask_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_73_2 > 28)
  {
    acc_2 = ((acc_2 + (mask_73_2 * 2)) + 5) & 127;
    aux_2 ^= mask_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_94_1 = local_arr_1[aux_1 % 3];
  int metric_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_94_2 * 2)) & 127;
  int parity_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_72_1)
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

  switch (parity_72_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_73_1 == mask_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_94_1 == metric_94_2);
  assert(parity_72_1 == parity_72_2);
}

int fn_R000277_7713_6(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int mask_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_73 > 28)
  {
    acc = ((acc + (mask_73 * 2)) + 5) & 127;
    aux ^= mask_73 & 15;
  }
  else
  {
    acc = ((acc - mask_73) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_94 = local_arr[aux % 3];
  acc = (acc + (metric_94 * 2)) & 127;
  int parity_72 = (aux + st.buffer[1]) & 3;
  switch (parity_72)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000277_7713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000277_7713_0 st_1 = {0};
  struct MatrixBlock_R000277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int accumulator_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_37_1 > 26)
  {
    acc_1 = ((acc_1 + (accumulator_37_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_37_2 > 26)
  {
    acc_2 = ((acc_2 + (accumulator_37_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_64_1)
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

  switch (window_64_2)
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
  int index_reg_35_1 = local_arr_1[aux_1 % 3];
  int index_reg_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_35_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_37_1 == accumulator_37_2);
  assert(window_64_1 == window_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_35_1 == index_reg_35_2);
}

int fn_R000277_7713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int accumulator_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_37 > 26)
  {
    acc = ((acc + (accumulator_37 * 2)) + 5) & 127;
    aux ^= accumulator_37 & 15;
  }
  else
  {
    acc = ((acc - accumulator_37) + 11) & 127;
    aux += 3;
  }
  int window_64 = (aux + st.buffer[1]) & 3;
  switch (window_64)
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
  int index_reg_35 = local_arr[aux % 3];
  acc = (acc + (index_reg_35 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000277_7713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000277_7713_0 st_1 = {0};
  struct MatrixBlock_R000277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_78_1 > 14)
  {
    acc_1 = ((acc_1 + (offset_78_1 * 2)) + 5) & 127;
    aux_1 ^= offset_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_78_2 > 14)
  {
    acc_2 = ((acc_2 + (offset_78_2 * 2)) + 5) & 127;
    aux_2 ^= offset_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_78_1 == offset_78_2);
}

int fn_R000277_7713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_78 > 14)
  {
    acc = ((acc + (offset_78 * 2)) + 5) & 127;
    aux ^= offset_78 & 15;
  }
  else
  {
    acc = ((acc - offset_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000277_7713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000277_7713_1 st_1 = {0};
  struct Vector3D_R000277_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int cursor_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_49_1) & 63;
  aux_2 = (aux_2 + cursor_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_49_1 == cursor_49_2);
}

int fn_R000277_7713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000277_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int cursor_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_49) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000277_7713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st_1 = {0};
  struct Transaction_R000277_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int margin_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_64_1) & 63;
  aux_2 = (aux_2 + margin_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_56_1 > 10)
  {
    acc_1 = ((acc_1 + (offset_56_1 * 2)) + 5) & 127;
    aux_1 ^= offset_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_56_2 > 10)
  {
    acc_2 = ((acc_2 + (offset_56_2 * 2)) + 5) & 127;
    aux_2 ^= offset_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_16_1)
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

  switch (phase_16_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_64_1 == margin_64_2);
  assert(offset_56_1 == offset_56_2);
  assert(phase_16_1 == phase_16_2);
}

int fn_R000277_7713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int margin_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_64) & 63;
  acc ^= aux;
  int offset_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_56 > 10)
  {
    acc = ((acc + (offset_56 * 2)) + 5) & 127;
    aux ^= offset_56 & 15;
  }
  else
  {
    acc = ((acc - offset_56) + 11) & 127;
    aux += 3;
  }
  int phase_16 = (aux + st.buffer[1]) & 3;
  switch (phase_16)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000277_7713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st_1 = {0};
  struct DeviceConfig_R000277_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_10_1)
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

  switch (quotient_10_2)
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
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_10_1 == quotient_10_2);
}

int fn_R000277_7713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_10 = (aux + st.buffer[1]) & 3;
  switch (quotient_10)
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

void fn_R000277_7713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st_1 = {0};
  struct DeviceConfig_R000277_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int tracker_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_41_1)
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

  switch (tracker_41_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_41_1 == tracker_41_2);
}

int fn_R000277_7713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int tracker_41 = (aux + st.buffer[1]) & 3;
  switch (tracker_41)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000277_7713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st_1 = {0};
  struct DeviceConfig_R000277_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_85_1 = local_arr_1[aux_1 % 3];
  int cursor_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_85_2 * 2)) & 127;
  int offset_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_59_1)
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

  switch (offset_59_2)
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
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_85_1 == cursor_85_2);
  assert(offset_59_1 == offset_59_2);
}

int fn_R000277_7713_13(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int cursor_85 = local_arr[aux % 3];
  acc = (acc + (cursor_85 * 2)) & 127;
  int offset_59 = (aux + st.buffer[1]) & 3;
  switch (offset_59)
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

void fn_R000277_7713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st_1 = {0};
  struct Transaction_R000277_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int margin_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_63_1)
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

  switch (margin_63_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_80_1 = local_arr_1[aux_1 % 3];
  int vector_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_80_2 * 2)) & 127;
  int factor_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_31_1) & 63;
  aux_2 = (aux_2 + factor_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_63_1 == margin_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_80_1 == vector_80_2);
  assert(factor_31_1 == factor_31_2);
}

int fn_R000277_7713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int margin_63 = (aux + st.buffer[1]) & 3;
  switch (margin_63)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_80 = local_arr[aux % 3];
  acc = (acc + (vector_80 * 2)) & 127;
  int factor_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000277_7713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st_1 = {0};
  struct DeviceConfig_R000277_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_54_1)
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

  switch (cursor_54_2)
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

  int pivot_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_40_1) & 63;
  aux_2 = (aux_2 + pivot_40_2) & 63;
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
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_54_1 == cursor_54_2);
  assert(pivot_40_1 == pivot_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_92_1 == threshold_92_2);
}

int fn_R000277_7713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_54 = (aux + st.buffer[1]) & 3;
  switch (cursor_54)
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

  int pivot_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_40) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_92 = local_arr[aux % 3];
  acc = (acc + (threshold_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000277_7713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000277_7713_0 st_1 = {0};
  struct MatrixBlock_R000277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_13_1 = local_arr_1[aux_1 % 3];
  int tracker_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_13_2 * 2)) & 127;
  int quantum_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_99_1) & 63;
  aux_2 = (aux_2 + quantum_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_61_1 > 14)
  {
    acc_1 = ((acc_1 + (anchor_61_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_61_2 > 14)
  {
    acc_2 = ((acc_2 + (anchor_61_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_61_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_13_1 == tracker_13_2);
  assert(quantum_99_1 == quantum_99_2);
  assert(anchor_61_1 == anchor_61_2);
}

int fn_R000277_7713_16(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int tracker_13 = local_arr[aux % 3];
  acc = (acc + (tracker_13 * 2)) & 127;
  int quantum_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_99) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_61 > 14)
  {
    acc = ((acc + (anchor_61 * 2)) + 5) & 127;
    aux ^= anchor_61 & 15;
  }
  else
  {
    acc = ((acc - anchor_61) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000277_7713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st_1 = {0};
  struct Transaction_R000277_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_95_1 = local_arr_1[aux_1 % 3];
  int anchor_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_95_2 * 2)) & 127;
  int window_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_76_1) & 63;
  aux_2 = (aux_2 + window_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_87_1)
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

  switch (vector_87_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_95_1 == anchor_95_2);
  assert(window_76_1 == window_76_2);
  assert(vector_87_1 == vector_87_2);
}

int fn_R000277_7713_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int anchor_95 = local_arr[aux % 3];
  acc = (acc + (anchor_95 * 2)) & 127;
  int window_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_76) & 63;
  acc ^= aux;
  int vector_87 = (aux + st.buffer[1]) & 3;
  switch (vector_87)
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

void fn_R000277_7713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000277_7713_1 st_1 = {0};
  struct Vector3D_R000277_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int quantum_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_18_1 > 50)
  {
    acc_1 = ((acc_1 + (quantum_18_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_18_2 > 50)
  {
    acc_2 = ((acc_2 + (quantum_18_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_81_1 = local_arr_1[aux_1 % 3];
  int quantum_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_81_2 * 2)) & 127;
  int sample_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_71_1) & 63;
  aux_2 = (aux_2 + sample_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_23_1)
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

  switch (residue_23_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_18_1 == quantum_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_81_1 == quantum_81_2);
  assert(sample_71_1 == sample_71_2);
  assert(residue_23_1 == residue_23_2);
}

int fn_R000277_7713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000277_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int quantum_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_18 > 50)
  {
    acc = ((acc + (quantum_18 * 2)) + 5) & 127;
    aux ^= quantum_18 & 15;
  }
  else
  {
    acc = ((acc - quantum_18) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_81 = local_arr[aux % 3];
  acc = (acc + (quantum_81 * 2)) & 127;
  int sample_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_71) & 63;
  acc ^= aux;
  int residue_23 = (aux + st.buffer[1]) & 3;
  switch (residue_23)
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

void fn_R000277_7713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st_1 = {0};
  struct DeviceConfig_R000277_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_31_1 = local_arr_1[aux_1 % 3];
  int checksum_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_31_2 * 2)) & 127;
  int parity_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_20_1) & 63;
  aux_2 = (aux_2 + parity_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_15_1 > 50)
  {
    acc_1 = ((acc_1 + (vector_15_1 * 2)) + 5) & 127;
    aux_1 ^= vector_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_15_2 > 50)
  {
    acc_2 = ((acc_2 + (vector_15_2 * 2)) + 5) & 127;
    aux_2 ^= vector_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_31_1 == checksum_31_2);
  assert(parity_20_1 == parity_20_2);
  assert(vector_15_1 == vector_15_2);
}

int fn_R000277_7713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int checksum_31 = local_arr[aux % 3];
  acc = (acc + (checksum_31 * 2)) & 127;
  int parity_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_20) & 63;
  acc ^= aux;
  int vector_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_15 > 50)
  {
    acc = ((acc + (vector_15 * 2)) + 5) & 127;
    aux ^= vector_15 & 15;
  }
  else
  {
    acc = ((acc - vector_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000277_7713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st_1 = {0};
  struct Transaction_R000277_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int residue_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_81_1)
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

  switch (residue_81_2)
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

  int anchor_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_92_1 > 38)
  {
    acc_1 = ((acc_1 + (anchor_92_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_92_2 > 38)
  {
    acc_2 = ((acc_2 + (anchor_92_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_81_1 == residue_81_2);
  assert(anchor_92_1 == anchor_92_2);
}

int fn_R000277_7713_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int residue_81 = (aux + st.buffer[1]) & 3;
  switch (residue_81)
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

  int anchor_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_92 > 38)
  {
    acc = ((acc + (anchor_92 * 2)) + 5) & 127;
    aux ^= anchor_92 & 15;
  }
  else
  {
    acc = ((acc - anchor_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000277_7713_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st_1 = {0};
  struct Transaction_R000277_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int tally_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_92_1)
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

  switch (tally_92_2)
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

  int metric_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_27_1 > 11)
  {
    acc_1 = ((acc_1 + (metric_27_1 * 2)) + 5) & 127;
    aux_1 ^= metric_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_27_2 > 11)
  {
    acc_2 = ((acc_2 + (metric_27_2 * 2)) + 5) & 127;
    aux_2 ^= metric_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_75_1) & 63;
  aux_2 = (aux_2 + sample_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_88_1 = local_arr_1[aux_1 % 3];
  int index_reg_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_88_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_92_1 == tally_92_2);
  assert(metric_27_1 == metric_27_2);
  assert(sample_75_1 == sample_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_88_1 == index_reg_88_2);
}

int fn_R000277_7713_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000277_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int tally_92 = (aux + st.buffer[1]) & 3;
  switch (tally_92)
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

  int metric_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_27 > 11)
  {
    acc = ((acc + (metric_27 * 2)) + 5) & 127;
    aux ^= metric_27 & 15;
  }
  else
  {
    acc = ((acc - metric_27) + 11) & 127;
    aux += 3;
  }
  int sample_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_75) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_88 = local_arr[aux % 3];
  acc = (acc + (index_reg_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000277_7713_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000277_7713_0 st_1 = {0};
  struct MatrixBlock_R000277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int vector_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_95_1) & 63;
  aux_2 = (aux_2 + vector_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_47_1 = local_arr_1[aux_1 % 3];
  int bound_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_47_2 * 2)) & 127;
  int parity_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_67_1 > 26)
  {
    acc_1 = ((acc_1 + (parity_67_1 * 2)) + 5) & 127;
    aux_1 ^= parity_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_67_2 > 26)
  {
    acc_2 = ((acc_2 + (parity_67_2 * 2)) + 5) & 127;
    aux_2 ^= parity_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_95_1 == vector_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_47_1 == bound_47_2);
  assert(parity_67_1 == parity_67_2);
}

int fn_R000277_7713_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int vector_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_95) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_47 = local_arr[aux % 3];
  acc = (acc + (bound_47 * 2)) & 127;
  int parity_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_67 > 26)
  {
    acc = ((acc + (parity_67 * 2)) + 5) & 127;
    aux ^= parity_67 & 15;
  }
  else
  {
    acc = ((acc - parity_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000277_7713_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st_1 = {0};
  struct DeviceConfig_R000277_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int phase_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_82_1 > 24)
  {
    acc_1 = ((acc_1 + (phase_82_1 * 2)) + 5) & 127;
    aux_1 ^= phase_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_82_2 > 24)
  {
    acc_2 = ((acc_2 + (phase_82_2 * 2)) + 5) & 127;
    aux_2 ^= phase_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_82_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_82_1 == phase_82_2);
}

int fn_R000277_7713_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000277_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int phase_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_82 > 24)
  {
    acc = ((acc + (phase_82 * 2)) + 5) & 127;
    aux ^= phase_82 & 15;
  }
  else
  {
    acc = ((acc - phase_82) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000277_0_1;
  int sec_r000277_0_2;
  int sec_r000277_1_1;
  int sec_r000277_1_2;
  int sec_r000277_2_1;
  int sec_r000277_2_2;
  int sec_r000277_3_1;
  int sec_r000277_3_2;
  int sec_r000277_4_1;
  int sec_r000277_4_2;
  int sec_r000277_5_1;
  int sec_r000277_5_2;
  int sec_r000277_6_1;
  int sec_r000277_6_2;
  int sec_r000277_7_1;
  int sec_r000277_7_2;
  int sec_r000277_8_1;
  int sec_r000277_8_2;
  int sec_r000277_9_1;
  int sec_r000277_9_2;
  int sec_r000277_10_1;
  int sec_r000277_10_2;
  int sec_r000277_11_1;
  int sec_r000277_11_2;
  int sec_r000277_12_1;
  int sec_r000277_12_2;
  int sec_r000277_13_1;
  int sec_r000277_13_2;
  int sec_r000277_14_1;
  int sec_r000277_14_2;
  int sec_r000277_15_1;
  int sec_r000277_15_2;
  int pub_r000277_0_1;
  int pub_r000277_0_2;
  int pub_r000277_1_1;
  int pub_r000277_1_2;
  int pub_r000277_2_1;
  int pub_r000277_2_2;
  int pub_r000277_3_1;
  int pub_r000277_3_2;
  int pub_r000277_4_1;
  int pub_r000277_4_2;
  int pub_r000277_5_1;
  int pub_r000277_5_2;
  int pub_r000277_6_1;
  int pub_r000277_6_2;
  int pub_r000277_7_1;
  int pub_r000277_7_2;
  int pub_r000277_8_1;
  int pub_r000277_8_2;
  int pub_r000277_9_1;
  int pub_r000277_9_2;
  int pub_r000277_10_1;
  int pub_r000277_10_2;
  int pub_r000277_11_1;
  int pub_r000277_11_2;
  int pub_r000277_12_1;
  int pub_r000277_12_2;
  int pub_r000277_13_1;
  int pub_r000277_13_2;
  int pub_r000277_14_1;
  int pub_r000277_14_2;
  int pub_r000277_15_1;
  int pub_r000277_15_2;
  int pub_r000277_16_1;
  int pub_r000277_16_2;
  int pub_r000277_17_1;
  int pub_r000277_17_2;
  int pub_r000277_18_1;
  int pub_r000277_18_2;
  int pub_r000277_19_1;
  int pub_r000277_19_2;
  int pub_r000277_20_1;
  int pub_r000277_20_2;
  int pub_r000277_21_1;
  int pub_r000277_21_2;
  int pub_r000277_22_1;
  int pub_r000277_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000277_0_1 >= (-100)) && (pub_r000277_0_1 <= 100));
  __CPROVER_assume((pub_r000277_0_2 >= (-100)) && (pub_r000277_0_2 <= 100));
  __CPROVER_assume((pub_r000277_1_1 >= (-100)) && (pub_r000277_1_1 <= 100));
  __CPROVER_assume((pub_r000277_1_2 >= (-100)) && (pub_r000277_1_2 <= 100));
  __CPROVER_assume((pub_r000277_2_1 >= (-100)) && (pub_r000277_2_1 <= 100));
  __CPROVER_assume((pub_r000277_2_2 >= (-100)) && (pub_r000277_2_2 <= 100));
  __CPROVER_assume((pub_r000277_3_1 >= (-100)) && (pub_r000277_3_1 <= 100));
  __CPROVER_assume((pub_r000277_3_2 >= (-100)) && (pub_r000277_3_2 <= 100));
  __CPROVER_assume((pub_r000277_4_1 >= (-100)) && (pub_r000277_4_1 <= 100));
  __CPROVER_assume((pub_r000277_4_2 >= (-100)) && (pub_r000277_4_2 <= 100));
  __CPROVER_assume((pub_r000277_5_1 >= (-100)) && (pub_r000277_5_1 <= 100));
  __CPROVER_assume((pub_r000277_5_2 >= (-100)) && (pub_r000277_5_2 <= 100));
  __CPROVER_assume((pub_r000277_6_1 >= (-100)) && (pub_r000277_6_1 <= 100));
  __CPROVER_assume((pub_r000277_6_2 >= (-100)) && (pub_r000277_6_2 <= 100));
  __CPROVER_assume((pub_r000277_7_1 >= (-100)) && (pub_r000277_7_1 <= 100));
  __CPROVER_assume((pub_r000277_7_2 >= (-100)) && (pub_r000277_7_2 <= 100));
  __CPROVER_assume((pub_r000277_8_1 >= (-100)) && (pub_r000277_8_1 <= 100));
  __CPROVER_assume((pub_r000277_8_2 >= (-100)) && (pub_r000277_8_2 <= 100));
  __CPROVER_assume((pub_r000277_9_1 >= (-100)) && (pub_r000277_9_1 <= 100));
  __CPROVER_assume((pub_r000277_9_2 >= (-100)) && (pub_r000277_9_2 <= 100));
  __CPROVER_assume((pub_r000277_10_1 >= (-100)) && (pub_r000277_10_1 <= 100));
  __CPROVER_assume((pub_r000277_10_2 >= (-100)) && (pub_r000277_10_2 <= 100));
  __CPROVER_assume((pub_r000277_11_1 >= (-100)) && (pub_r000277_11_1 <= 100));
  __CPROVER_assume((pub_r000277_11_2 >= (-100)) && (pub_r000277_11_2 <= 100));
  __CPROVER_assume((pub_r000277_12_1 >= (-100)) && (pub_r000277_12_1 <= 100));
  __CPROVER_assume((pub_r000277_12_2 >= (-100)) && (pub_r000277_12_2 <= 100));
  __CPROVER_assume((pub_r000277_13_1 >= (-100)) && (pub_r000277_13_1 <= 100));
  __CPROVER_assume((pub_r000277_13_2 >= (-100)) && (pub_r000277_13_2 <= 100));
  __CPROVER_assume((pub_r000277_14_1 >= (-100)) && (pub_r000277_14_1 <= 100));
  __CPROVER_assume((pub_r000277_14_2 >= (-100)) && (pub_r000277_14_2 <= 100));
  __CPROVER_assume((pub_r000277_15_1 >= (-100)) && (pub_r000277_15_1 <= 100));
  __CPROVER_assume((pub_r000277_15_2 >= (-100)) && (pub_r000277_15_2 <= 100));
  __CPROVER_assume((pub_r000277_16_1 >= (-100)) && (pub_r000277_16_1 <= 100));
  __CPROVER_assume((pub_r000277_16_2 >= (-100)) && (pub_r000277_16_2 <= 100));
  __CPROVER_assume((pub_r000277_17_1 >= (-100)) && (pub_r000277_17_1 <= 100));
  __CPROVER_assume((pub_r000277_17_2 >= (-100)) && (pub_r000277_17_2 <= 100));
  __CPROVER_assume((pub_r000277_18_1 >= (-100)) && (pub_r000277_18_1 <= 100));
  __CPROVER_assume((pub_r000277_18_2 >= (-100)) && (pub_r000277_18_2 <= 100));
  __CPROVER_assume((pub_r000277_19_1 >= (-100)) && (pub_r000277_19_1 <= 100));
  __CPROVER_assume((pub_r000277_19_2 >= (-100)) && (pub_r000277_19_2 <= 100));
  __CPROVER_assume((pub_r000277_20_1 >= (-100)) && (pub_r000277_20_1 <= 100));
  __CPROVER_assume((pub_r000277_20_2 >= (-100)) && (pub_r000277_20_2 <= 100));
  __CPROVER_assume((pub_r000277_21_1 >= (-100)) && (pub_r000277_21_1 <= 100));
  __CPROVER_assume((pub_r000277_21_2 >= (-100)) && (pub_r000277_21_2 <= 100));
  __CPROVER_assume((pub_r000277_22_1 >= (-100)) && (pub_r000277_22_1 <= 100));
  __CPROVER_assume((pub_r000277_22_2 >= (-100)) && (pub_r000277_22_2 <= 100));
  __CPROVER_assume((sec_r000277_0_1 >= 0) && (sec_r000277_0_1 <= 255));
  __CPROVER_assume((sec_r000277_0_2 >= 0) && (sec_r000277_0_2 <= 255));
  __CPROVER_assume((sec_r000277_1_1 >= 0) && (sec_r000277_1_1 <= 255));
  __CPROVER_assume((sec_r000277_1_2 >= 0) && (sec_r000277_1_2 <= 255));
  __CPROVER_assume((sec_r000277_2_1 >= 0) && (sec_r000277_2_1 <= 255));
  __CPROVER_assume((sec_r000277_2_2 >= 0) && (sec_r000277_2_2 <= 255));
  __CPROVER_assume((sec_r000277_3_1 >= 0) && (sec_r000277_3_1 <= 255));
  __CPROVER_assume((sec_r000277_3_2 >= 0) && (sec_r000277_3_2 <= 255));
  __CPROVER_assume((sec_r000277_4_1 >= 0) && (sec_r000277_4_1 <= 255));
  __CPROVER_assume((sec_r000277_4_2 >= 0) && (sec_r000277_4_2 <= 255));
  __CPROVER_assume((sec_r000277_5_1 >= 0) && (sec_r000277_5_1 <= 255));
  __CPROVER_assume((sec_r000277_5_2 >= 0) && (sec_r000277_5_2 <= 255));
  __CPROVER_assume((sec_r000277_6_1 >= 0) && (sec_r000277_6_1 <= 255));
  __CPROVER_assume((sec_r000277_6_2 >= 0) && (sec_r000277_6_2 <= 255));
  __CPROVER_assume((sec_r000277_7_1 >= 0) && (sec_r000277_7_1 <= 255));
  __CPROVER_assume((sec_r000277_7_2 >= 0) && (sec_r000277_7_2 <= 255));
  __CPROVER_assume((sec_r000277_8_1 >= 0) && (sec_r000277_8_1 <= 255));
  __CPROVER_assume((sec_r000277_8_2 >= 0) && (sec_r000277_8_2 <= 255));
  __CPROVER_assume((sec_r000277_9_1 >= 0) && (sec_r000277_9_1 <= 255));
  __CPROVER_assume((sec_r000277_9_2 >= 0) && (sec_r000277_9_2 <= 255));
  __CPROVER_assume((sec_r000277_10_1 >= 0) && (sec_r000277_10_1 <= 255));
  __CPROVER_assume((sec_r000277_10_2 >= 0) && (sec_r000277_10_2 <= 255));
  __CPROVER_assume((sec_r000277_11_1 >= 0) && (sec_r000277_11_1 <= 255));
  __CPROVER_assume((sec_r000277_11_2 >= 0) && (sec_r000277_11_2 <= 255));
  __CPROVER_assume((sec_r000277_12_1 >= 0) && (sec_r000277_12_1 <= 255));
  __CPROVER_assume((sec_r000277_12_2 >= 0) && (sec_r000277_12_2 <= 255));
  __CPROVER_assume((sec_r000277_13_1 >= 0) && (sec_r000277_13_1 <= 255));
  __CPROVER_assume((sec_r000277_13_2 >= 0) && (sec_r000277_13_2 <= 255));
  __CPROVER_assume((sec_r000277_14_1 >= 0) && (sec_r000277_14_1 <= 255));
  __CPROVER_assume((sec_r000277_14_2 >= 0) && (sec_r000277_14_2 <= 255));
  __CPROVER_assume((sec_r000277_15_1 >= 0) && (sec_r000277_15_1 <= 255));
  __CPROVER_assume((sec_r000277_15_2 >= 0) && (sec_r000277_15_2 <= 255));
  struct MatrixBlock_R000277_7713_0 st_var_0_1 = {0};
  struct MatrixBlock_R000277_7713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000277_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000277_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000277_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000277_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000277_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000277_0_2 + 7) & 15;
  struct Vector3D_R000277_7713_1 st_var_1_1 = {0};
  struct Vector3D_R000277_7713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000277_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000277_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000277_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000277_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000277_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000277_0_2 + 9) & 15;
  struct DeviceConfig_R000277_7713_2 st_var_2_1 = {0};
  struct DeviceConfig_R000277_7713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000277_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000277_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000277_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000277_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000277_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000277_0_2 + 11) & 15;
  struct Transaction_R000277_7713_3 st_var_3_1 = {0};
  struct Transaction_R000277_7713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000277_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000277_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000277_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000277_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000277_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000277_0_2 + 13) & 15;
  union ColorPixel_R000277_7713_0 u_var_1;
  union ColorPixel_R000277_7713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 37)
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
  if (stage_v_0_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 37)
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
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 33)
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
  if (stage_v_2_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 33)
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
  int stage_v_3_1 = (st_var_3_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_3_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 7) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = ((st_var_3_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_3_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 39)
    {
      chk_sum_1 ^= stage_v_7_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_7_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 39)
    {
      chk_sum_2 ^= stage_v_7_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
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

  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
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
  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 39)
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
  if (stage_v_13_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 39)
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
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 16) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = ((st_var_0_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_0_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 46)
    {
      chk_sum_1 ^= stage_v_16_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_16_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 46)
    {
      chk_sum_2 ^= stage_v_16_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 19) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 20) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 20) & 15;
  int stage_v_19_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_19_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= stage_v_19_1;
  chk_sum_2 ^= stage_v_19_2;
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
  int stage_v_21_1 = ((st_var_1_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_1_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 50)
    {
      chk_sum_1 ^= stage_v_21_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_21_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 50)
    {
      chk_sum_2 ^= stage_v_21_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_22_1 = ((st_var_2_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_2_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 30)
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
  if (stage_v_22_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 30)
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
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((sec_r000277_2_1 & 1) != 0)
  {
    if ((sec_r000277_6_1 & 2) != 0)
    {
      stage_v_25_1 = (pub_r000277_19_1 + 31) & 127;
    }
    else
    {
      stage_v_25_1 = (pub_r000277_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_1 = (pub_r000277_19_1 + 7) & 127;
  }
  if ((sec_r000277_2_2 & 1) != 0)
  {
    if ((sec_r000277_6_2 & 2) != 0)
    {
      stage_v_25_2 = (pub_r000277_19_2 + 31) & 127;
    }
    else
    {
      stage_v_25_2 = (pub_r000277_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_2 = (pub_r000277_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000277_7_1 & 2) != 0)
    {
      stage_v_26_1 = (pub_r000277_16_1 + 31) & 127;
    }
    else
    {
      stage_v_26_1 = (pub_r000277_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_1 = (pub_r000277_16_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000277_7_2 & 2) != 0)
    {
      stage_v_26_2 = (pub_r000277_16_2 + 31) & 127;
    }
    else
    {
      stage_v_26_2 = (pub_r000277_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_2 = (pub_r000277_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000277_12_1 & 2) != 0)
    {
      stage_v_27_1 = (pub_r000277_3_1 + 31) & 127;
    }
    else
    {
      stage_v_27_1 = (pub_r000277_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_1 = (pub_r000277_3_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000277_12_2 & 2) != 0)
    {
      stage_v_27_2 = (pub_r000277_3_2 + 31) & 127;
    }
    else
    {
      stage_v_27_2 = (pub_r000277_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_2 = (pub_r000277_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000277_6_1 & 2) != 0)
    {
      stage_v_28_1 = (pub_r000277_12_1 + 31) & 127;
    }
    else
    {
      stage_v_28_1 = (pub_r000277_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_1 = (pub_r000277_12_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000277_6_2 & 2) != 0)
    {
      stage_v_28_2 = (pub_r000277_12_2 + 31) & 127;
    }
    else
    {
      stage_v_28_2 = (pub_r000277_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_2 = (pub_r000277_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((sec_r000277_11_1 & 1) != 0)
  {
    if ((sec_r000277_15_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000277_3_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000277_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000277_3_1 + 7) & 127;
  }
  if ((sec_r000277_11_2 & 1) != 0)
  {
    if ((sec_r000277_15_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000277_3_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000277_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000277_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000277_11_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000277_6_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000277_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000277_6_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000277_11_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000277_6_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000277_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000277_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((sec_r000277_10_1 & 1) != 0)
  {
    if ((sec_r000277_5_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000277_8_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000277_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000277_8_1 + 7) & 127;
  }
  if ((sec_r000277_10_2 & 1) != 0)
  {
    if ((sec_r000277_5_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000277_8_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000277_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000277_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000277_12_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000277_21_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000277_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000277_21_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000277_12_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000277_21_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000277_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000277_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((sec_r000277_7_1 & 1) != 0)
  {
    if ((sec_r000277_8_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000277_3_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000277_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000277_3_1 + 7) & 127;
  }
  if ((sec_r000277_7_2 & 1) != 0)
  {
    if ((sec_r000277_8_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000277_3_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000277_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000277_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((sec_r000277_2_1 & 1) != 0)
  {
    if ((sec_r000277_11_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000277_0_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000277_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000277_0_1 + 7) & 127;
  }
  if ((sec_r000277_2_2 & 1) != 0)
  {
    if ((sec_r000277_11_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000277_0_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000277_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000277_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000277_15_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000277_18_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000277_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000277_18_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000277_15_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000277_18_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000277_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000277_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000277_13_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000277_6_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000277_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000277_6_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000277_13_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000277_6_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000277_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000277_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000277_3_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000277_21_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000277_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000277_21_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000277_3_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000277_21_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000277_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000277_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((sec_r000277_1_1 & 1) != 0)
  {
    if ((sec_r000277_1_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000277_6_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000277_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000277_6_1 + 7) & 127;
  }
  if ((sec_r000277_1_2 & 1) != 0)
  {
    if ((sec_r000277_1_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000277_6_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000277_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000277_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((sec_r000277_12_1 & 1) != 0)
  {
    if ((sec_r000277_7_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000277_4_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000277_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000277_4_1 + 7) & 127;
  }
  if ((sec_r000277_12_2 & 1) != 0)
  {
    if ((sec_r000277_7_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000277_4_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000277_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000277_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000277_7_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000277_19_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000277_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000277_19_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000277_7_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000277_19_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000277_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000277_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000277_13_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000277_10_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000277_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000277_10_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000277_13_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000277_10_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000277_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000277_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((sec_r000277_15_1 & 1) != 0)
  {
    if ((sec_r000277_9_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000277_17_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000277_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000277_17_1 + 7) & 127;
  }
  if ((sec_r000277_15_2 & 1) != 0)
  {
    if ((sec_r000277_9_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000277_17_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000277_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000277_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000277_13_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000277_12_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000277_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000277_12_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000277_13_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000277_12_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000277_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000277_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000277_3_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000277_15_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000277_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000277_15_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000277_3_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000277_15_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000277_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000277_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000277_9_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000277_3_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000277_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000277_3_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000277_9_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000277_3_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000277_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000277_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000277_12_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000277_14_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000277_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000277_14_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000277_12_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000277_14_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000277_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000277_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000277_7_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000277_6_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000277_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000277_6_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000277_7_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000277_6_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000277_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000277_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000277_8_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000277_18_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000277_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000277_18_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000277_8_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000277_18_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000277_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000277_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000277_9_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000277_0_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000277_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000277_0_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000277_9_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000277_0_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000277_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000277_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000277_11_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000277_10_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000277_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000277_10_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000277_11_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000277_10_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000277_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000277_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((sec_r000277_3_1 & 1) != 0)
  {
    if ((sec_r000277_10_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000277_8_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000277_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000277_8_1 + 7) & 127;
  }
  if ((sec_r000277_3_2 & 1) != 0)
  {
    if ((sec_r000277_10_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000277_8_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000277_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000277_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((sec_r000277_1_1 & 1) != 0)
  {
    if ((sec_r000277_11_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000277_0_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000277_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000277_0_1 + 7) & 127;
  }
  if ((sec_r000277_1_2 & 1) != 0)
  {
    if ((sec_r000277_11_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000277_0_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000277_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000277_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000277_12_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000277_6_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000277_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000277_6_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000277_12_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000277_6_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000277_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000277_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000277_7_1 & 1) != 0)
  {
    if ((sec_r000277_9_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000277_3_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000277_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000277_3_1 + 7) & 127;
  }
  if ((sec_r000277_7_2 & 1) != 0)
  {
    if ((sec_r000277_9_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000277_3_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000277_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000277_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000277_4_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000277_9_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000277_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000277_9_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000277_4_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000277_9_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000277_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000277_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000277_1_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000277_6_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000277_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000277_6_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000277_1_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000277_6_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000277_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000277_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000277_0_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000277_9_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000277_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000277_9_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000277_0_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000277_9_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000277_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000277_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000277_9_1 & 1) != 0)
  {
    if ((sec_r000277_13_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000277_15_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000277_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000277_15_1 + 7) & 127;
  }
  if ((sec_r000277_9_2 & 1) != 0)
  {
    if ((sec_r000277_13_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000277_15_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000277_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000277_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000277_7_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000277_1_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000277_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000277_1_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000277_7_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000277_1_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000277_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000277_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000277_12_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000277_7_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000277_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000277_7_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000277_12_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000277_7_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000277_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000277_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((sec_r000277_3_1 & 1) != 0)
  {
    if ((sec_r000277_10_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000277_19_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000277_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000277_19_1 + 7) & 127;
  }
  if ((sec_r000277_3_2 & 1) != 0)
  {
    if ((sec_r000277_10_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000277_19_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000277_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000277_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000277_2_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000277_4_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000277_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000277_4_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000277_2_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000277_4_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000277_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000277_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000277_0_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000277_6_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000277_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000277_6_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000277_0_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000277_6_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000277_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000277_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000277_11_1 & 1) != 0)
  {
    if ((sec_r000277_5_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000277_10_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000277_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000277_10_1 + 7) & 127;
  }
  if ((sec_r000277_11_2 & 1) != 0)
  {
    if ((sec_r000277_5_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000277_10_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000277_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000277_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000277_1_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000277_13_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000277_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000277_13_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000277_1_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000277_13_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000277_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000277_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000277_1_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000277_12_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000277_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000277_12_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000277_1_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000277_12_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000277_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000277_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000277_9_1 & 1) != 0)
  {
    if ((sec_r000277_12_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000277_11_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000277_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000277_11_1 + 7) & 127;
  }
  if ((sec_r000277_9_2 & 1) != 0)
  {
    if ((sec_r000277_12_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000277_11_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000277_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000277_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000277_12_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000277_21_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000277_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000277_21_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000277_12_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000277_21_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000277_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000277_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000277_0_1 & 1) != 0)
  {
    if ((sec_r000277_10_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000277_8_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000277_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000277_8_1 + 7) & 127;
  }
  if ((sec_r000277_0_2 & 1) != 0)
  {
    if ((sec_r000277_10_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000277_8_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000277_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000277_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000277_4_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000277_16_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000277_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000277_16_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000277_4_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000277_16_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000277_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000277_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000277_0_1 & 1) != 0)
  {
    if ((sec_r000277_1_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000277_2_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000277_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000277_2_1 + 7) & 127;
  }
  if ((sec_r000277_0_2 & 1) != 0)
  {
    if ((sec_r000277_1_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000277_2_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000277_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000277_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000277_0_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000277_17_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000277_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000277_17_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000277_0_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000277_17_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000277_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000277_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000277_4_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000277_12_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000277_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000277_12_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000277_4_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000277_12_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000277_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000277_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000277_10_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000277_1_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000277_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000277_1_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000277_10_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000277_1_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000277_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000277_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000277_2_1 & 1) != 0)
  {
    if ((sec_r000277_0_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000277_22_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000277_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000277_22_1 + 7) & 127;
  }
  if ((sec_r000277_2_2 & 1) != 0)
  {
    if ((sec_r000277_0_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000277_22_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000277_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000277_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000277_1_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000277_14_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000277_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000277_14_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000277_1_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000277_14_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000277_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000277_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000277_10_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000277_10_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000277_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000277_10_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000277_10_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000277_10_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000277_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000277_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000277_7_1 & 1) != 0)
  {
    if ((sec_r000277_12_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000277_6_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000277_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000277_6_1 + 7) & 127;
  }
  if ((sec_r000277_7_2 & 1) != 0)
  {
    if ((sec_r000277_12_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000277_6_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000277_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000277_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000277_2_1 & 1) != 0)
  {
    if ((sec_r000277_1_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000277_3_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000277_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000277_3_1 + 7) & 127;
  }
  if ((sec_r000277_2_2 & 1) != 0)
  {
    if ((sec_r000277_1_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000277_3_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000277_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000277_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000277_11_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000277_10_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000277_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000277_10_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000277_11_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000277_10_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000277_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000277_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000277_13_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000277_18_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000277_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000277_18_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000277_13_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000277_18_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000277_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000277_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000277_2_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000277_4_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000277_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000277_4_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000277_2_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000277_4_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000277_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000277_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000277_0_1 & 1) != 0)
  {
    if ((sec_r000277_9_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000277_13_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000277_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000277_13_1 + 7) & 127;
  }
  if ((sec_r000277_0_2 & 1) != 0)
  {
    if ((sec_r000277_9_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000277_13_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000277_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000277_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000277_13_1 & 1) != 0)
  {
    if ((sec_r000277_11_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000277_14_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000277_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000277_14_1 + 7) & 127;
  }
  if ((sec_r000277_13_2 & 1) != 0)
  {
    if ((sec_r000277_11_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000277_14_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000277_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000277_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000277_10_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000277_16_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000277_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000277_16_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000277_10_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000277_16_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000277_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000277_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000277_10_1 & 1) != 0)
  {
    if ((sec_r000277_0_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000277_22_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000277_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000277_22_1 + 7) & 127;
  }
  if ((sec_r000277_10_2 & 1) != 0)
  {
    if ((sec_r000277_0_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000277_22_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000277_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000277_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000277_4_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000277_0_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000277_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000277_0_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000277_4_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000277_0_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000277_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000277_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000277_13_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000277_3_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000277_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000277_3_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000277_13_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000277_3_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000277_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000277_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000277_13_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000277_13_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000277_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000277_13_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000277_13_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000277_13_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000277_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000277_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000277_14_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000277_12_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000277_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000277_12_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000277_14_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000277_12_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000277_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000277_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000277_8_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000277_20_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000277_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000277_20_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000277_8_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000277_20_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000277_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000277_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000277_4_1 & 1) != 0)
  {
    if ((sec_r000277_3_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000277_4_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000277_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000277_4_1 + 7) & 127;
  }
  if ((sec_r000277_4_2 & 1) != 0)
  {
    if ((sec_r000277_3_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000277_4_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000277_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000277_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000277_7_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000277_9_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000277_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000277_9_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000277_7_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000277_9_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000277_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000277_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000277_3_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000277_17_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000277_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000277_17_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000277_3_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000277_17_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000277_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000277_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000277_7_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000277_10_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000277_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000277_10_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000277_7_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000277_10_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000277_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000277_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000277_2_1 & 1) != 0)
  {
    if ((sec_r000277_15_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000277_8_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000277_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000277_8_1 + 7) & 127;
  }
  if ((sec_r000277_2_2 & 1) != 0)
  {
    if ((sec_r000277_15_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000277_8_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000277_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000277_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000277_10_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000277_3_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000277_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000277_3_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000277_10_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000277_3_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000277_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000277_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000277_3_1 & 1) != 0)
  {
    if ((sec_r000277_15_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000277_10_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000277_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000277_10_1 + 7) & 127;
  }
  if ((sec_r000277_3_2 & 1) != 0)
  {
    if ((sec_r000277_15_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000277_10_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000277_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000277_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000277_1_1 & 1) != 0)
  {
    if ((sec_r000277_3_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000277_9_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000277_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000277_9_1 + 7) & 127;
  }
  if ((sec_r000277_1_2 & 1) != 0)
  {
    if ((sec_r000277_3_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000277_9_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000277_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000277_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000277_2_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000277_12_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000277_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000277_12_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000277_2_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000277_12_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000277_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000277_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000277_7_1 & 1) != 0)
  {
    if ((sec_r000277_2_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000277_21_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000277_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000277_21_1 + 7) & 127;
  }
  if ((sec_r000277_7_2 & 1) != 0)
  {
    if ((sec_r000277_2_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000277_21_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000277_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000277_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000277_13_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000277_5_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000277_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000277_5_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000277_13_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000277_5_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000277_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000277_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000277_8_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000277_14_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000277_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000277_14_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000277_8_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000277_14_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000277_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000277_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000277_14_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000277_8_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000277_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000277_8_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000277_14_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000277_8_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000277_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000277_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000277_4_1 & 1) != 0)
  {
    if ((sec_r000277_12_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000277_21_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000277_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000277_21_1 + 7) & 127;
  }
  if ((sec_r000277_4_2 & 1) != 0)
  {
    if ((sec_r000277_12_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000277_21_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000277_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000277_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000277_4_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000277_21_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000277_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000277_21_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000277_4_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000277_21_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000277_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000277_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000277_12_1 & 1) != 0)
  {
    if ((sec_r000277_6_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000277_7_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000277_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000277_7_1 + 7) & 127;
  }
  if ((sec_r000277_12_2 & 1) != 0)
  {
    if ((sec_r000277_6_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000277_7_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000277_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000277_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000277_2_1 & 1) != 0)
  {
    if ((sec_r000277_6_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000277_14_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000277_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000277_14_1 + 7) & 127;
  }
  if ((sec_r000277_2_2 & 1) != 0)
  {
    if ((sec_r000277_6_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000277_14_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000277_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000277_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000277_10_1 & 1) != 0)
  {
    if ((sec_r000277_11_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000277_20_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000277_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000277_20_1 + 7) & 127;
  }
  if ((sec_r000277_10_2 & 1) != 0)
  {
    if ((sec_r000277_11_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000277_20_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000277_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000277_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000277_0_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000277_16_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000277_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000277_16_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000277_0_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000277_16_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000277_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000277_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000277_6_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000277_0_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000277_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000277_0_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000277_6_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000277_0_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000277_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000277_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000277_3_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000277_17_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000277_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000277_17_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000277_3_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000277_17_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000277_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000277_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000277_2_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000277_12_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000277_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000277_12_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000277_2_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000277_12_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000277_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000277_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000277_4_1 & 1) != 0)
  {
    if ((sec_r000277_13_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000277_8_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000277_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000277_8_1 + 7) & 127;
  }
  if ((sec_r000277_4_2 & 1) != 0)
  {
    if ((sec_r000277_13_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000277_8_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000277_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000277_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000277_13_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000277_21_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000277_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000277_21_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000277_13_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000277_21_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000277_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000277_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000277_12_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000277_9_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000277_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000277_9_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000277_12_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000277_9_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000277_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000277_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000277_11_1 & 1) != 0)
  {
    if ((sec_r000277_10_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000277_4_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000277_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000277_4_1 + 7) & 127;
  }
  if ((sec_r000277_11_2 & 1) != 0)
  {
    if ((sec_r000277_10_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000277_4_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000277_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000277_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000277_6_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000277_3_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000277_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000277_3_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000277_6_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000277_3_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000277_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000277_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000277_8_1 & 1) != 0)
  {
    if ((sec_r000277_5_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000277_7_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000277_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000277_7_1 + 7) & 127;
  }
  if ((sec_r000277_8_2 & 1) != 0)
  {
    if ((sec_r000277_5_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000277_7_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000277_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000277_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000277_3_1 & 1) != 0)
  {
    if ((sec_r000277_7_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000277_2_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000277_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000277_2_1 + 7) & 127;
  }
  if ((sec_r000277_3_2 & 1) != 0)
  {
    if ((sec_r000277_7_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000277_2_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000277_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000277_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000277_5_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000277_1_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000277_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000277_1_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000277_5_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000277_1_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000277_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000277_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000277_4_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000277_22_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000277_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000277_22_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000277_4_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000277_22_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000277_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000277_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000277_15_1 & 1) != 0)
  {
    if ((sec_r000277_9_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000277_4_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000277_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000277_4_1 + 7) & 127;
  }
  if ((sec_r000277_15_2 & 1) != 0)
  {
    if ((sec_r000277_9_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000277_4_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000277_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000277_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000277_9_1 & 1) != 0)
  {
    if ((sec_r000277_7_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000277_18_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000277_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000277_18_1 + 7) & 127;
  }
  if ((sec_r000277_9_2 & 1) != 0)
  {
    if ((sec_r000277_7_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000277_18_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000277_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000277_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000277_5_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000277_18_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000277_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000277_18_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000277_5_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000277_18_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000277_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000277_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000277_12_1 & 1) != 0)
  {
    if ((sec_r000277_0_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000277_19_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000277_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000277_19_1 + 7) & 127;
  }
  if ((sec_r000277_12_2 & 1) != 0)
  {
    if ((sec_r000277_0_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000277_19_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000277_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000277_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000277_11_1 & 1) != 0)
  {
    if ((sec_r000277_7_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000277_11_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000277_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000277_11_1 + 7) & 127;
  }
  if ((sec_r000277_11_2 & 1) != 0)
  {
    if ((sec_r000277_7_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000277_11_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000277_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000277_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000277_9_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000277_10_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000277_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000277_10_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000277_9_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000277_10_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000277_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000277_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000277_3_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000277_16_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000277_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000277_16_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000277_3_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000277_16_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000277_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000277_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000277_5_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000277_7_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000277_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000277_7_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000277_5_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000277_7_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000277_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000277_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000277_11_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000277_8_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000277_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000277_8_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000277_11_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000277_8_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000277_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000277_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000277_15_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000277_7_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000277_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000277_7_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000277_15_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000277_7_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000277_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000277_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000277_12_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000277_7_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000277_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000277_7_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000277_12_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000277_7_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000277_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000277_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000277_2_1 == pub_r000277_2_2);
  __CPROVER_assume(pub_r000277_22_1 == pub_r000277_22_2);
  __CPROVER_assume(pub_r000277_11_1 == pub_r000277_11_2);
  __CPROVER_assume(sec_r000277_10_1 != sec_r000277_10_2);
  __CPROVER_assume(sec_r000277_15_1 != sec_r000277_15_2);
  __CPROVER_assume(sec_r000277_11_1 != sec_r000277_11_2);
  __CPROVER_assume(sec_r000277_14_1 != sec_r000277_14_2);
  __CPROVER_assume(sec_r000277_12_1 != sec_r000277_12_2);
  __CPROVER_assume(pub_r000277_3_1 == pub_r000277_3_2);
  __CPROVER_assume(sec_r000277_9_1 != sec_r000277_9_2);
  __CPROVER_assume(pub_r000277_4_1 == pub_r000277_4_2);
  __CPROVER_assume(pub_r000277_6_1 == pub_r000277_6_2);
  __CPROVER_assume(pub_r000277_18_1 == pub_r000277_18_2);
  __CPROVER_assume(pub_r000277_0_1 == pub_r000277_0_2);
  __CPROVER_assume(sec_r000277_8_1 != sec_r000277_8_2);
  __CPROVER_assume(sec_r000277_3_1 != sec_r000277_3_2);
  __CPROVER_assume(pub_r000277_19_1 == pub_r000277_19_2);
  __CPROVER_assume(pub_r000277_21_1 == pub_r000277_21_2);
  __CPROVER_assume(sec_r000277_5_1 != sec_r000277_5_2);
  __CPROVER_assume(sec_r000277_2_1 != sec_r000277_2_2);
  __CPROVER_assume(pub_r000277_10_1 == pub_r000277_10_2);
  __CPROVER_assume(sec_r000277_0_1 != sec_r000277_0_2);
  __CPROVER_assume(sec_r000277_1_1 != sec_r000277_1_2);
  __CPROVER_assume(pub_r000277_15_1 == pub_r000277_15_2);
  __CPROVER_assume(pub_r000277_7_1 == pub_r000277_7_2);
  __CPROVER_assume(pub_r000277_13_1 == pub_r000277_13_2);
  __CPROVER_assume(sec_r000277_4_1 != sec_r000277_4_2);
  __CPROVER_assume(pub_r000277_12_1 == pub_r000277_12_2);
  __CPROVER_assume(pub_r000277_16_1 == pub_r000277_16_2);
  __CPROVER_assume(pub_r000277_8_1 == pub_r000277_8_2);
  __CPROVER_assume(sec_r000277_6_1 != sec_r000277_6_2);
  __CPROVER_assume(sec_r000277_13_1 != sec_r000277_13_2);
  __CPROVER_assume(pub_r000277_5_1 == pub_r000277_5_2);
  __CPROVER_assume(pub_r000277_14_1 == pub_r000277_14_2);
  __CPROVER_assume(pub_r000277_9_1 == pub_r000277_9_2);
  __CPROVER_assume(sec_r000277_7_1 != sec_r000277_7_2);
  __CPROVER_assume(pub_r000277_1_1 == pub_r000277_1_2);
  __CPROVER_assume(pub_r000277_20_1 == pub_r000277_20_2);
  __CPROVER_assume(pub_r000277_17_1 == pub_r000277_17_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  assert(st_var_2_1.port == st_var_2_2.port);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.id == st_var_2_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.status == st_var_3_2.status);
  assert(st_var_3_1.rate == st_var_3_2.rate);
  assert(st_var_3_1.auth_code == st_var_3_2.auth_code);
  assert(st_var_3_1.fee == st_var_3_2.fee);
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
}


