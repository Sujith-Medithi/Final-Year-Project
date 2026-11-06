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
struct MatrixBlock_R000777_7713_0
{
  int determinant;
  unsigned char trace;
  short density;
  int dim;
  int stride;
  int buffer[3];
};
struct Transaction_R000777_7713_1
{
  int balance;
  int status;
  int fee;
  int buffer[3];
};
struct Vector3D_R000777_7713_2
{
  int heading;
  int coord_x;
  int norm_sq;
  short coord_y;
  int coord_z;
  int pitch;
  int buffer[3];
};
union TelemetryField_R000777_7713_0
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
void fn_R000777_7713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st_1 = {0};
  struct Vector3D_R000777_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int vector_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_77_1 > 36)
  {
    acc_1 = ((acc_1 + (vector_77_1 * 2)) + 5) & 127;
    aux_1 ^= vector_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_77_2 > 36)
  {
    acc_2 = ((acc_2 + (vector_77_2 * 2)) + 5) & 127;
    aux_2 ^= vector_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_43_1) & 63;
  aux_2 = (aux_2 + weight_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_27_1 = local_arr_1[aux_1 % 3];
  int quotient_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_27_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_77_1 == vector_77_2);
  assert(weight_43_1 == weight_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_27_1 == quotient_27_2);
}

int fn_R000777_7713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int vector_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_77 > 36)
  {
    acc = ((acc + (vector_77 * 2)) + 5) & 127;
    aux ^= vector_77 & 15;
  }
  else
  {
    acc = ((acc - vector_77) + 11) & 127;
    aux += 3;
  }
  int weight_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_43) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_27 = local_arr[aux % 3];
  acc = (acc + (quotient_27 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000777_7713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000777_7713_1 st_1 = {0};
  struct Transaction_R000777_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_35_1) & 63;
  aux_2 = (aux_2 + index_reg_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_75_1 = local_arr_1[aux_1 % 3];
  int mask_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_75_2 * 2)) & 127;
  int damping_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_34_1)
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

  switch (damping_34_2)
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
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_35_1 == index_reg_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_75_1 == mask_75_2);
  assert(damping_34_1 == damping_34_2);
}

int fn_R000777_7713_1(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000777_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_35) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int mask_75 = local_arr[aux % 3];
  acc = (acc + (mask_75 * 2)) & 127;
  int damping_34 = (aux + st.buffer[1]) & 3;
  switch (damping_34)
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

void fn_R000777_7713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000777_7713_1 st_1 = {0};
  struct Transaction_R000777_7713_1 st_2 = {0};
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
  int stride_72_1 = local_arr_1[aux_1 % 3];
  int stride_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_72_2 * 2)) & 127;
  int mask_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_12_1)
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

  switch (mask_12_2)
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
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_72_1 == stride_72_2);
  assert(mask_12_1 == mask_12_2);
}

int fn_R000777_7713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000777_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int stride_72 = local_arr[aux % 3];
  acc = (acc + (stride_72 * 2)) & 127;
  int mask_12 = (aux + st.buffer[1]) & 3;
  switch (mask_12)
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

void fn_R000777_7713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000777_7713_0 st_1 = {0};
  struct MatrixBlock_R000777_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_93_1 = local_arr_1[aux_1 % 3];
  int offset_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_93_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_93_1 == offset_93_2);
}

int fn_R000777_7713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000777_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int offset_93 = local_arr[aux % 3];
  acc = (acc + (offset_93 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000777_7713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000777_7713_0 st_1 = {0};
  struct MatrixBlock_R000777_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_45_1 = local_arr_1[aux_1 % 3];
  int weight_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_45_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_47_1) & 63;
  aux_2 = (aux_2 + metric_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_45_1 == weight_45_2);
  assert(metric_47_1 == metric_47_2);
}

int fn_R000777_7713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000777_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int weight_45 = local_arr[aux % 3];
  acc = (acc + (weight_45 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000777_7713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st_1 = {0};
  struct Vector3D_R000777_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int anchor_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_42_1)
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

  switch (anchor_42_2)
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

  int quantum_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_30_1 > 44)
  {
    acc_1 = ((acc_1 + (quantum_30_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_30_2 > 44)
  {
    acc_2 = ((acc_2 + (quantum_30_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_30_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_42_1 == anchor_42_2);
  assert(quantum_30_1 == quantum_30_2);
}

int fn_R000777_7713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int anchor_42 = (aux + st.buffer[1]) & 3;
  switch (anchor_42)
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

  int quantum_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_30 > 44)
  {
    acc = ((acc + (quantum_30 * 2)) + 5) & 127;
    aux ^= quantum_30 & 15;
  }
  else
  {
    acc = ((acc - quantum_30) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000777_7713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000777_7713_1 st_1 = {0};
  struct Transaction_R000777_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int phase_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_83_1)
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

  switch (phase_83_2)
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

  int damping_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_72_1 > 33)
  {
    acc_1 = ((acc_1 + (damping_72_1 * 2)) + 5) & 127;
    aux_1 ^= damping_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_72_2 > 33)
  {
    acc_2 = ((acc_2 + (damping_72_2 * 2)) + 5) & 127;
    aux_2 ^= damping_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_72_1 = local_arr_1[aux_1 % 3];
  int factor_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_72_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_83_1 == phase_83_2);
  assert(damping_72_1 == damping_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_72_1 == factor_72_2);
}

int fn_R000777_7713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000777_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int phase_83 = (aux + st.buffer[1]) & 3;
  switch (phase_83)
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

  int damping_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_72 > 33)
  {
    acc = ((acc + (damping_72 * 2)) + 5) & 127;
    aux ^= damping_72 & 15;
  }
  else
  {
    acc = ((acc - damping_72) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_72 = local_arr[aux % 3];
  acc = (acc + (factor_72 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000777_7713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st_1 = {0};
  struct Vector3D_R000777_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int pivot_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_88_1) & 63;
  aux_2 = (aux_2 + pivot_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_35_1 > 39)
  {
    acc_1 = ((acc_1 + (metric_35_1 * 2)) + 5) & 127;
    aux_1 ^= metric_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_35_2 > 39)
  {
    acc_2 = ((acc_2 + (metric_35_2 * 2)) + 5) & 127;
    aux_2 ^= metric_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_35_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_42_1 = local_arr_1[aux_1 % 3];
  int cursor_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_42_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_88_1 == pivot_88_2);
  assert(metric_35_1 == metric_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_42_1 == cursor_42_2);
}

int fn_R000777_7713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int pivot_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_88) & 63;
  acc ^= aux;
  int metric_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_35 > 39)
  {
    acc = ((acc + (metric_35 * 2)) + 5) & 127;
    aux ^= metric_35 & 15;
  }
  else
  {
    acc = ((acc - metric_35) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int cursor_42 = local_arr[aux % 3];
  acc = (acc + (cursor_42 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000777_7713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000777_7713_1 st_1 = {0};
  struct Transaction_R000777_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_21_1 = local_arr_1[aux_1 % 3];
  int index_reg_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_21_2 * 2)) & 127;
  int stride_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_56_1)
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

  switch (stride_56_2)
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

  int cursor_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_79_1 > 43)
  {
    acc_1 = ((acc_1 + (cursor_79_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_79_2 > 43)
  {
    acc_2 = ((acc_2 + (cursor_79_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_10_1) & 63;
  aux_2 = (aux_2 + threshold_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_21_1 == index_reg_21_2);
  assert(stride_56_1 == stride_56_2);
  assert(cursor_79_1 == cursor_79_2);
  assert(threshold_10_1 == threshold_10_2);
}

int fn_R000777_7713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000777_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int index_reg_21 = local_arr[aux % 3];
  acc = (acc + (index_reg_21 * 2)) & 127;
  int stride_56 = (aux + st.buffer[1]) & 3;
  switch (stride_56)
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

  int cursor_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_79 > 43)
  {
    acc = ((acc + (cursor_79 * 2)) + 5) & 127;
    aux ^= cursor_79 & 15;
  }
  else
  {
    acc = ((acc - cursor_79) + 11) & 127;
    aux += 3;
  }
  int threshold_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_10) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000777_7713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st_1 = {0};
  struct Vector3D_R000777_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int bound_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_92_1) & 63;
  aux_2 = (aux_2 + bound_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_85_1)
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

  switch (bound_85_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_10_1 > 44)
  {
    acc_1 = ((acc_1 + (vector_10_1 * 2)) + 5) & 127;
    aux_1 ^= vector_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_10_2 > 44)
  {
    acc_2 = ((acc_2 + (vector_10_2 * 2)) + 5) & 127;
    aux_2 ^= vector_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_92_1 == bound_92_2);
  assert(bound_85_1 == bound_85_2);
  assert(vector_10_1 == vector_10_2);
}

int fn_R000777_7713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int bound_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_92) & 63;
  acc ^= aux;
  int bound_85 = (aux + st.buffer[1]) & 3;
  switch (bound_85)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_10 > 44)
  {
    acc = ((acc + (vector_10 * 2)) + 5) & 127;
    aux ^= vector_10 & 15;
  }
  else
  {
    acc = ((acc - vector_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000777_7713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st_1 = {0};
  struct Vector3D_R000777_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int accumulator_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_73_1) & 63;
  aux_2 = (aux_2 + accumulator_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_55_1 = local_arr_1[aux_1 % 3];
  int quantum_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_55_2 * 2)) & 127;
  int index_reg_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_18_1)
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

  switch (index_reg_18_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_73_1 == accumulator_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_55_1 == quantum_55_2);
  assert(index_reg_18_1 == index_reg_18_2);
}

int fn_R000777_7713_10(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int accumulator_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_73) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_55 = local_arr[aux % 3];
  acc = (acc + (quantum_55 * 2)) & 127;
  int index_reg_18 = (aux + st.buffer[1]) & 3;
  switch (index_reg_18)
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

void fn_R000777_7713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st_1 = {0};
  struct Vector3D_R000777_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int phase_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_84_1 > 21)
  {
    acc_1 = ((acc_1 + (phase_84_1 * 2)) + 5) & 127;
    aux_1 ^= phase_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_84_2 > 21)
  {
    acc_2 = ((acc_2 + (phase_84_2 * 2)) + 5) & 127;
    aux_2 ^= phase_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_84_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_73_1 = local_arr_1[aux_1 % 3];
  int factor_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_73_2 * 2)) & 127;
  int metric_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_31_1) & 63;
  aux_2 = (aux_2 + metric_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_84_1 == phase_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_73_1 == factor_73_2);
  assert(metric_31_1 == metric_31_2);
}

int fn_R000777_7713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int phase_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_84 > 21)
  {
    acc = ((acc + (phase_84 * 2)) + 5) & 127;
    aux ^= phase_84 & 15;
  }
  else
  {
    acc = ((acc - phase_84) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_73 = local_arr[aux % 3];
  acc = (acc + (factor_73 * 2)) & 127;
  int metric_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000777_7713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000777_7713_1 st_1 = {0};
  struct Transaction_R000777_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int tally_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_49_1) & 63;
  aux_2 = (aux_2 + tally_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_49_1 == tally_49_2);
}

int fn_R000777_7713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000777_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int tally_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_49) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000777_7713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st_1 = {0};
  struct Vector3D_R000777_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int quotient_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_29_1)
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

  switch (quotient_29_2)
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

  int metric_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_37_1 > 24)
  {
    acc_1 = ((acc_1 + (metric_37_1 * 2)) + 5) & 127;
    aux_1 ^= metric_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_37_2 > 24)
  {
    acc_2 = ((acc_2 + (metric_37_2 * 2)) + 5) & 127;
    aux_2 ^= metric_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_33_1) & 63;
  aux_2 = (aux_2 + threshold_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_29_1 == quotient_29_2);
  assert(metric_37_1 == metric_37_2);
  assert(threshold_33_1 == threshold_33_2);
}

int fn_R000777_7713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000777_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int quotient_29 = (aux + st.buffer[1]) & 3;
  switch (quotient_29)
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

  int metric_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_37 > 24)
  {
    acc = ((acc + (metric_37 * 2)) + 5) & 127;
    aux ^= metric_37 & 15;
  }
  else
  {
    acc = ((acc - metric_37) + 11) & 127;
    aux += 3;
  }
  int threshold_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_33) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000777_0_1;
  int sec_r000777_0_2;
  int sec_r000777_1_1;
  int sec_r000777_1_2;
  int sec_r000777_2_1;
  int sec_r000777_2_2;
  int sec_r000777_3_1;
  int sec_r000777_3_2;
  int sec_r000777_4_1;
  int sec_r000777_4_2;
  int sec_r000777_5_1;
  int sec_r000777_5_2;
  int sec_r000777_6_1;
  int sec_r000777_6_2;
  int sec_r000777_7_1;
  int sec_r000777_7_2;
  int sec_r000777_8_1;
  int sec_r000777_8_2;
  int sec_r000777_9_1;
  int sec_r000777_9_2;
  int sec_r000777_10_1;
  int sec_r000777_10_2;
  int sec_r000777_11_1;
  int sec_r000777_11_2;
  int sec_r000777_12_1;
  int sec_r000777_12_2;
  int sec_r000777_13_1;
  int sec_r000777_13_2;
  int sec_r000777_14_1;
  int sec_r000777_14_2;
  int sec_r000777_15_1;
  int sec_r000777_15_2;
  int sec_r000777_16_1;
  int sec_r000777_16_2;
  int sec_r000777_17_1;
  int sec_r000777_17_2;
  int sec_r000777_18_1;
  int sec_r000777_18_2;
  int pub_r000777_0_1;
  int pub_r000777_0_2;
  int pub_r000777_1_1;
  int pub_r000777_1_2;
  int pub_r000777_2_1;
  int pub_r000777_2_2;
  int pub_r000777_3_1;
  int pub_r000777_3_2;
  int pub_r000777_4_1;
  int pub_r000777_4_2;
  int pub_r000777_5_1;
  int pub_r000777_5_2;
  int pub_r000777_6_1;
  int pub_r000777_6_2;
  int pub_r000777_7_1;
  int pub_r000777_7_2;
  int pub_r000777_8_1;
  int pub_r000777_8_2;
  int pub_r000777_9_1;
  int pub_r000777_9_2;
  int pub_r000777_10_1;
  int pub_r000777_10_2;
  int pub_r000777_11_1;
  int pub_r000777_11_2;
  int pub_r000777_12_1;
  int pub_r000777_12_2;
  int pub_r000777_13_1;
  int pub_r000777_13_2;
  int pub_r000777_14_1;
  int pub_r000777_14_2;
  int pub_r000777_15_1;
  int pub_r000777_15_2;
  int pub_r000777_16_1;
  int pub_r000777_16_2;
  int pub_r000777_17_1;
  int pub_r000777_17_2;
  int pub_r000777_18_1;
  int pub_r000777_18_2;
  int pub_r000777_19_1;
  int pub_r000777_19_2;
  int pub_r000777_20_1;
  int pub_r000777_20_2;
  int pub_r000777_21_1;
  int pub_r000777_21_2;
  int pub_r000777_22_1;
  int pub_r000777_22_2;
  int pub_r000777_23_1;
  int pub_r000777_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000777_0_1 >= (-100)) && (pub_r000777_0_1 <= 100));
  __CPROVER_assume((pub_r000777_0_2 >= (-100)) && (pub_r000777_0_2 <= 100));
  __CPROVER_assume((pub_r000777_1_1 >= (-100)) && (pub_r000777_1_1 <= 100));
  __CPROVER_assume((pub_r000777_1_2 >= (-100)) && (pub_r000777_1_2 <= 100));
  __CPROVER_assume((pub_r000777_2_1 >= (-100)) && (pub_r000777_2_1 <= 100));
  __CPROVER_assume((pub_r000777_2_2 >= (-100)) && (pub_r000777_2_2 <= 100));
  __CPROVER_assume((pub_r000777_3_1 >= (-100)) && (pub_r000777_3_1 <= 100));
  __CPROVER_assume((pub_r000777_3_2 >= (-100)) && (pub_r000777_3_2 <= 100));
  __CPROVER_assume((pub_r000777_4_1 >= (-100)) && (pub_r000777_4_1 <= 100));
  __CPROVER_assume((pub_r000777_4_2 >= (-100)) && (pub_r000777_4_2 <= 100));
  __CPROVER_assume((pub_r000777_5_1 >= (-100)) && (pub_r000777_5_1 <= 100));
  __CPROVER_assume((pub_r000777_5_2 >= (-100)) && (pub_r000777_5_2 <= 100));
  __CPROVER_assume((pub_r000777_6_1 >= (-100)) && (pub_r000777_6_1 <= 100));
  __CPROVER_assume((pub_r000777_6_2 >= (-100)) && (pub_r000777_6_2 <= 100));
  __CPROVER_assume((pub_r000777_7_1 >= (-100)) && (pub_r000777_7_1 <= 100));
  __CPROVER_assume((pub_r000777_7_2 >= (-100)) && (pub_r000777_7_2 <= 100));
  __CPROVER_assume((pub_r000777_8_1 >= (-100)) && (pub_r000777_8_1 <= 100));
  __CPROVER_assume((pub_r000777_8_2 >= (-100)) && (pub_r000777_8_2 <= 100));
  __CPROVER_assume((pub_r000777_9_1 >= (-100)) && (pub_r000777_9_1 <= 100));
  __CPROVER_assume((pub_r000777_9_2 >= (-100)) && (pub_r000777_9_2 <= 100));
  __CPROVER_assume((pub_r000777_10_1 >= (-100)) && (pub_r000777_10_1 <= 100));
  __CPROVER_assume((pub_r000777_10_2 >= (-100)) && (pub_r000777_10_2 <= 100));
  __CPROVER_assume((pub_r000777_11_1 >= (-100)) && (pub_r000777_11_1 <= 100));
  __CPROVER_assume((pub_r000777_11_2 >= (-100)) && (pub_r000777_11_2 <= 100));
  __CPROVER_assume((pub_r000777_12_1 >= (-100)) && (pub_r000777_12_1 <= 100));
  __CPROVER_assume((pub_r000777_12_2 >= (-100)) && (pub_r000777_12_2 <= 100));
  __CPROVER_assume((pub_r000777_13_1 >= (-100)) && (pub_r000777_13_1 <= 100));
  __CPROVER_assume((pub_r000777_13_2 >= (-100)) && (pub_r000777_13_2 <= 100));
  __CPROVER_assume((pub_r000777_14_1 >= (-100)) && (pub_r000777_14_1 <= 100));
  __CPROVER_assume((pub_r000777_14_2 >= (-100)) && (pub_r000777_14_2 <= 100));
  __CPROVER_assume((pub_r000777_15_1 >= (-100)) && (pub_r000777_15_1 <= 100));
  __CPROVER_assume((pub_r000777_15_2 >= (-100)) && (pub_r000777_15_2 <= 100));
  __CPROVER_assume((pub_r000777_16_1 >= (-100)) && (pub_r000777_16_1 <= 100));
  __CPROVER_assume((pub_r000777_16_2 >= (-100)) && (pub_r000777_16_2 <= 100));
  __CPROVER_assume((pub_r000777_17_1 >= (-100)) && (pub_r000777_17_1 <= 100));
  __CPROVER_assume((pub_r000777_17_2 >= (-100)) && (pub_r000777_17_2 <= 100));
  __CPROVER_assume((pub_r000777_18_1 >= (-100)) && (pub_r000777_18_1 <= 100));
  __CPROVER_assume((pub_r000777_18_2 >= (-100)) && (pub_r000777_18_2 <= 100));
  __CPROVER_assume((pub_r000777_19_1 >= (-100)) && (pub_r000777_19_1 <= 100));
  __CPROVER_assume((pub_r000777_19_2 >= (-100)) && (pub_r000777_19_2 <= 100));
  __CPROVER_assume((pub_r000777_20_1 >= (-100)) && (pub_r000777_20_1 <= 100));
  __CPROVER_assume((pub_r000777_20_2 >= (-100)) && (pub_r000777_20_2 <= 100));
  __CPROVER_assume((pub_r000777_21_1 >= (-100)) && (pub_r000777_21_1 <= 100));
  __CPROVER_assume((pub_r000777_21_2 >= (-100)) && (pub_r000777_21_2 <= 100));
  __CPROVER_assume((pub_r000777_22_1 >= (-100)) && (pub_r000777_22_1 <= 100));
  __CPROVER_assume((pub_r000777_22_2 >= (-100)) && (pub_r000777_22_2 <= 100));
  __CPROVER_assume((pub_r000777_23_1 >= (-100)) && (pub_r000777_23_1 <= 100));
  __CPROVER_assume((pub_r000777_23_2 >= (-100)) && (pub_r000777_23_2 <= 100));
  __CPROVER_assume((sec_r000777_0_1 >= 0) && (sec_r000777_0_1 <= 255));
  __CPROVER_assume((sec_r000777_0_2 >= 0) && (sec_r000777_0_2 <= 255));
  __CPROVER_assume((sec_r000777_1_1 >= 0) && (sec_r000777_1_1 <= 255));
  __CPROVER_assume((sec_r000777_1_2 >= 0) && (sec_r000777_1_2 <= 255));
  __CPROVER_assume((sec_r000777_2_1 >= 0) && (sec_r000777_2_1 <= 255));
  __CPROVER_assume((sec_r000777_2_2 >= 0) && (sec_r000777_2_2 <= 255));
  __CPROVER_assume((sec_r000777_3_1 >= 0) && (sec_r000777_3_1 <= 255));
  __CPROVER_assume((sec_r000777_3_2 >= 0) && (sec_r000777_3_2 <= 255));
  __CPROVER_assume((sec_r000777_4_1 >= 0) && (sec_r000777_4_1 <= 255));
  __CPROVER_assume((sec_r000777_4_2 >= 0) && (sec_r000777_4_2 <= 255));
  __CPROVER_assume((sec_r000777_5_1 >= 0) && (sec_r000777_5_1 <= 255));
  __CPROVER_assume((sec_r000777_5_2 >= 0) && (sec_r000777_5_2 <= 255));
  __CPROVER_assume((sec_r000777_6_1 >= 0) && (sec_r000777_6_1 <= 255));
  __CPROVER_assume((sec_r000777_6_2 >= 0) && (sec_r000777_6_2 <= 255));
  __CPROVER_assume((sec_r000777_7_1 >= 0) && (sec_r000777_7_1 <= 255));
  __CPROVER_assume((sec_r000777_7_2 >= 0) && (sec_r000777_7_2 <= 255));
  __CPROVER_assume((sec_r000777_8_1 >= 0) && (sec_r000777_8_1 <= 255));
  __CPROVER_assume((sec_r000777_8_2 >= 0) && (sec_r000777_8_2 <= 255));
  __CPROVER_assume((sec_r000777_9_1 >= 0) && (sec_r000777_9_1 <= 255));
  __CPROVER_assume((sec_r000777_9_2 >= 0) && (sec_r000777_9_2 <= 255));
  __CPROVER_assume((sec_r000777_10_1 >= 0) && (sec_r000777_10_1 <= 255));
  __CPROVER_assume((sec_r000777_10_2 >= 0) && (sec_r000777_10_2 <= 255));
  __CPROVER_assume((sec_r000777_11_1 >= 0) && (sec_r000777_11_1 <= 255));
  __CPROVER_assume((sec_r000777_11_2 >= 0) && (sec_r000777_11_2 <= 255));
  __CPROVER_assume((sec_r000777_12_1 >= 0) && (sec_r000777_12_1 <= 255));
  __CPROVER_assume((sec_r000777_12_2 >= 0) && (sec_r000777_12_2 <= 255));
  __CPROVER_assume((sec_r000777_13_1 >= 0) && (sec_r000777_13_1 <= 255));
  __CPROVER_assume((sec_r000777_13_2 >= 0) && (sec_r000777_13_2 <= 255));
  __CPROVER_assume((sec_r000777_14_1 >= 0) && (sec_r000777_14_1 <= 255));
  __CPROVER_assume((sec_r000777_14_2 >= 0) && (sec_r000777_14_2 <= 255));
  __CPROVER_assume((sec_r000777_15_1 >= 0) && (sec_r000777_15_1 <= 255));
  __CPROVER_assume((sec_r000777_15_2 >= 0) && (sec_r000777_15_2 <= 255));
  __CPROVER_assume((sec_r000777_16_1 >= 0) && (sec_r000777_16_1 <= 255));
  __CPROVER_assume((sec_r000777_16_2 >= 0) && (sec_r000777_16_2 <= 255));
  __CPROVER_assume((sec_r000777_17_1 >= 0) && (sec_r000777_17_1 <= 255));
  __CPROVER_assume((sec_r000777_17_2 >= 0) && (sec_r000777_17_2 <= 255));
  __CPROVER_assume((sec_r000777_18_1 >= 0) && (sec_r000777_18_1 <= 255));
  __CPROVER_assume((sec_r000777_18_2 >= 0) && (sec_r000777_18_2 <= 255));
  struct MatrixBlock_R000777_7713_0 st_var_0_1 = {0};
  struct MatrixBlock_R000777_7713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000777_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000777_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000777_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000777_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000777_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000777_0_2 + 7) & 15;
  struct Transaction_R000777_7713_1 st_var_1_1 = {0};
  struct Transaction_R000777_7713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000777_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000777_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000777_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000777_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000777_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000777_0_2 + 9) & 15;
  struct Vector3D_R000777_7713_2 st_var_2_1 = {0};
  struct Vector3D_R000777_7713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000777_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000777_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000777_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000777_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000777_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000777_0_2 + 11) & 15;
  union TelemetryField_R000777_7713_0 u_var_1;
  union TelemetryField_R000777_7713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
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

  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = ((st_var_0_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_0_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 32)
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
  if (stage_v_9_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 32)
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
  int stage_v_10_1 = ((st_var_1_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_1_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 45)
    {
      chk_sum_1 ^= stage_v_10_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_10_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 45)
    {
      chk_sum_2 ^= stage_v_10_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_11_1 = ((st_var_2_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_2_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 36)
    {
      chk_sum_1 ^= stage_v_11_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_11_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 36)
    {
      chk_sum_2 ^= stage_v_11_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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
  int stage_v_17_1 = (st_var_2_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_2_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = ((st_var_1_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_1_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 31)
    {
      chk_sum_1 ^= stage_v_19_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_19_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 31)
    {
      chk_sum_2 ^= stage_v_19_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (st_var_0_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_0_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 5) & 255;
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
      out_sink_2 = (out_sink_2 + 5) & 255;
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

  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 51)
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
  if (stage_v_26_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 51)
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
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = table_1[1];
  int stage_v_29_2 = table_2[1];
  table_1[1] = (table_1[2] + 59) & 63;
  table_2[1] = (table_2[2] + 59) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
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
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (st_var_0_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_0_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 35) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = (st_var_2_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_2_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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
  if (stage_v_37_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 43)
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
  if (stage_v_37_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 43)
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
  int stage_v_39_1 = ((st_var_0_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_0_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 46)
    {
      chk_sum_1 ^= stage_v_39_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_39_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 46)
    {
      chk_sum_2 ^= stage_v_39_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = ((st_var_2_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_2_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 31)
    {
      chk_sum_1 ^= stage_v_41_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_41_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 31)
    {
      chk_sum_2 ^= stage_v_41_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 45) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 46) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_0_2.buffer[0] * 3) & 63;
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
  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 53) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_53_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_54_1 = (st_var_0_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_0_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  int stage_v_55_1 = (st_var_1_1.buffer[0] ^ 58) & 3;
  int stage_v_55_2 = (st_var_1_2.buffer[0] ^ 58) & 3;
  switch (stage_v_55_1)
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

  switch (stage_v_55_2)
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

  int stage_v_56_1 = (st_var_2_1.buffer[0] ^ 59) & 3;
  int stage_v_56_2 = (st_var_2_2.buffer[0] ^ 59) & 3;
  switch (stage_v_56_1)
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

  switch (stage_v_56_2)
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

  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((st_var_1_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_1_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 47)
    {
      chk_sum_1 ^= stage_v_58_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_58_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 47)
    {
      chk_sum_2 ^= stage_v_58_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_59_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_59_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 61) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 61) & 15;
  int stage_v_60_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_60_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= stage_v_60_1;
  chk_sum_2 ^= stage_v_60_2;
  int stage_v_61_1 = (st_var_1_1.buffer[0] ^ 64) & 3;
  int stage_v_61_2 = (st_var_1_2.buffer[0] ^ 64) & 3;
  switch (stage_v_61_1)
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

  switch (stage_v_61_2)
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
  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_64_1 = (st_var_1_1.buffer[0] ^ 67) & 3;
  int stage_v_64_2 = (st_var_1_2.buffer[0] ^ 67) & 3;
  switch (stage_v_64_1)
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

  switch (stage_v_64_2)
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

  int stage_v_65_1 = (st_var_2_1.buffer[0] ^ 68) & 3;
  int stage_v_65_2 = (st_var_2_2.buffer[0] ^ 68) & 3;
  switch (stage_v_65_1)
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

  switch (stage_v_65_2)
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

  int stage_v_66_1 = (st_var_0_1.buffer[0] ^ 69) & 3;
  int stage_v_66_2 = (st_var_0_2.buffer[0] ^ 69) & 3;
  switch (stage_v_66_1)
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

  switch (stage_v_66_2)
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

  int stage_v_67_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (72 & 31);
  int stage_v_67_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (72 & 31);
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= (stage_v_67_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_67_2 << 1) & 127;
  int stage_v_68_1 = (st_var_2_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_2_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 5) & 255;
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
      out_sink_2 = (out_sink_2 + 5) & 255;
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 70) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
  int stage_v_70_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_70_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_71_1 = ((st_var_2_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_2_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 52)
    {
      chk_sum_1 ^= stage_v_71_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_71_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 52)
    {
      chk_sum_2 ^= stage_v_71_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_73_1 = ((stage_v_73_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_73_2 = ((stage_v_73_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((st_var_0_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_0_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 54)
    {
      chk_sum_1 ^= stage_v_75_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_75_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 54)
    {
      chk_sum_2 ^= stage_v_75_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_76_1 = table_1[0];
  int stage_v_76_2 = table_2[0];
  table_1[0] = (table_1[1] + 153) & 63;
  table_2[0] = (table_2[1] + 153) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 78) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= stage_v_77_1;
  chk_sum_2 ^= stage_v_77_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 79) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 79) & 15;
  int stage_v_78_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_78_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= stage_v_78_1;
  chk_sum_2 ^= stage_v_78_2;
  int stage_v_79_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (84 & 31);
  int stage_v_79_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (84 & 31);
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  chk_sum_1 ^= (stage_v_79_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_79_2 << 1) & 127;
  int stage_v_80_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (85 & 31);
  int stage_v_80_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (85 & 31);
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= (stage_v_80_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_80_2 << 1) & 127;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (st_var_2_1.buffer[0] ^ 86) & 3;
  int stage_v_83_2 = (st_var_2_2.buffer[0] ^ 86) & 3;
  switch (stage_v_83_1)
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

  switch (stage_v_83_2)
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

  int stage_v_84_1 = (st_var_0_1.buffer[0] ^ 87) & 3;
  int stage_v_84_2 = (st_var_0_2.buffer[0] ^ 87) & 3;
  switch (stage_v_84_1)
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

  switch (stage_v_84_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 86) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 86) & 15;
  int stage_v_85_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_85_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= stage_v_85_1;
  chk_sum_2 ^= stage_v_85_2;
  int stage_v_86_1 = ((st_var_2_1.buffer[2] * 2) + 265) & 63;
  int stage_v_86_2 = ((st_var_2_2.buffer[2] * 2) + 265) & 63;
  if (stage_v_86_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_86_1) - 5) & 255;
    if (stage_v_86_1 > 49)
    {
      chk_sum_1 ^= stage_v_86_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_86_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_86_2) - 5) & 255;
    if (stage_v_86_2 > 49)
    {
      chk_sum_2 ^= stage_v_86_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_87_1 = (st_var_0_1.buffer[0] ^ 90) & 3;
  int stage_v_87_2 = (st_var_0_2.buffer[0] ^ 90) & 3;
  switch (stage_v_87_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 5) & 255;
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

  switch (stage_v_87_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 5) & 255;
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

  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_88_1 = ((stage_v_88_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (94 & 31);
  int stage_v_89_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (94 & 31);
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= (stage_v_89_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_89_2 << 1) & 127;
  int stage_v_90_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_90_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_91_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_91_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_91_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_91_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000777_4_1 & 1) != 0)
  {
    if ((sec_r000777_2_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000777_12_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000777_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000777_12_1 + 7) & 127;
  }
  if ((sec_r000777_4_2 & 1) != 0)
  {
    if ((sec_r000777_2_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000777_12_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000777_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000777_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000777_18_1 & 1) != 0)
  {
    if ((sec_r000777_3_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000777_22_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000777_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000777_22_1 + 7) & 127;
  }
  if ((sec_r000777_18_2 & 1) != 0)
  {
    if ((sec_r000777_3_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000777_22_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000777_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000777_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000777_4_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000777_20_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000777_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000777_20_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000777_4_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000777_20_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000777_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000777_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000777_6_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000777_21_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000777_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000777_21_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000777_6_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000777_21_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000777_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000777_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000777_6_1 & 1) != 0)
  {
    if ((sec_r000777_13_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000777_18_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000777_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000777_18_1 + 7) & 127;
  }
  if ((sec_r000777_6_2 & 1) != 0)
  {
    if ((sec_r000777_13_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000777_18_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000777_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000777_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000777_0_1 & 1) != 0)
  {
    if ((sec_r000777_17_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000777_16_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000777_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000777_16_1 + 7) & 127;
  }
  if ((sec_r000777_0_2 & 1) != 0)
  {
    if ((sec_r000777_17_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000777_16_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000777_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000777_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000777_3_1 & 1) != 0)
  {
    if ((sec_r000777_10_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000777_19_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000777_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000777_19_1 + 7) & 127;
  }
  if ((sec_r000777_3_2 & 1) != 0)
  {
    if ((sec_r000777_10_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000777_19_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000777_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000777_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000777_9_1 & 1) != 0)
  {
    if ((sec_r000777_18_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000777_23_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000777_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000777_23_1 + 7) & 127;
  }
  if ((sec_r000777_9_2 & 1) != 0)
  {
    if ((sec_r000777_18_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000777_23_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000777_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000777_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000777_2_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000777_16_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000777_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000777_16_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000777_2_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000777_16_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000777_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000777_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000777_7_1 & 1) != 0)
  {
    if ((sec_r000777_4_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000777_2_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000777_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000777_2_1 + 7) & 127;
  }
  if ((sec_r000777_7_2 & 1) != 0)
  {
    if ((sec_r000777_4_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000777_2_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000777_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000777_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000777_14_1 & 1) != 0)
  {
    if ((sec_r000777_1_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000777_19_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000777_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000777_19_1 + 7) & 127;
  }
  if ((sec_r000777_14_2 & 1) != 0)
  {
    if ((sec_r000777_1_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000777_19_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000777_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000777_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000777_9_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000777_15_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000777_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000777_15_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000777_9_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000777_15_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000777_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000777_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000777_18_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000777_7_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000777_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000777_7_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000777_18_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000777_7_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000777_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000777_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000777_7_1 & 1) != 0)
  {
    if ((sec_r000777_1_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000777_23_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000777_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000777_23_1 + 7) & 127;
  }
  if ((sec_r000777_7_2 & 1) != 0)
  {
    if ((sec_r000777_1_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000777_23_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000777_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000777_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000777_3_1 & 1) != 0)
  {
    if ((sec_r000777_17_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000777_3_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000777_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000777_3_1 + 7) & 127;
  }
  if ((sec_r000777_3_2 & 1) != 0)
  {
    if ((sec_r000777_17_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000777_3_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000777_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000777_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000777_15_1 & 1) != 0)
  {
    if ((sec_r000777_7_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000777_4_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000777_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000777_4_1 + 7) & 127;
  }
  if ((sec_r000777_15_2 & 1) != 0)
  {
    if ((sec_r000777_7_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000777_4_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000777_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000777_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000777_11_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000777_13_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000777_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000777_13_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000777_11_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000777_13_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000777_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000777_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000777_13_1 & 1) != 0)
  {
    if ((sec_r000777_3_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000777_19_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000777_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000777_19_1 + 7) & 127;
  }
  if ((sec_r000777_13_2 & 1) != 0)
  {
    if ((sec_r000777_3_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000777_19_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000777_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000777_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000777_2_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000777_19_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000777_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000777_19_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000777_2_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000777_19_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000777_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000777_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000777_6_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000777_19_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000777_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000777_19_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000777_6_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000777_19_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000777_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000777_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000777_2_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000777_5_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000777_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000777_5_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000777_2_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000777_5_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000777_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000777_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000777_3_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000777_17_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000777_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000777_17_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000777_3_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000777_17_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000777_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000777_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000777_6_1 & 1) != 0)
  {
    if ((sec_r000777_9_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000777_14_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000777_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000777_14_1 + 7) & 127;
  }
  if ((sec_r000777_6_2 & 1) != 0)
  {
    if ((sec_r000777_9_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000777_14_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000777_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000777_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000777_8_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000777_5_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000777_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000777_5_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000777_8_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000777_5_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000777_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000777_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000777_5_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000777_17_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000777_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000777_17_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000777_5_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000777_17_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000777_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000777_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000777_10_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000777_6_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000777_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000777_6_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000777_10_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000777_6_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000777_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000777_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000777_13_1 & 1) != 0)
  {
    if ((sec_r000777_8_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000777_6_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000777_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000777_6_1 + 7) & 127;
  }
  if ((sec_r000777_13_2 & 1) != 0)
  {
    if ((sec_r000777_8_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000777_6_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000777_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000777_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000777_5_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000777_8_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000777_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000777_8_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000777_5_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000777_8_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000777_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000777_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000777_15_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000777_6_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000777_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000777_6_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000777_15_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000777_6_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000777_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000777_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000777_8_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000777_12_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000777_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000777_12_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000777_8_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000777_12_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000777_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000777_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000777_12_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000777_14_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000777_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000777_14_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000777_12_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000777_14_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000777_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000777_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000777_17_1 & 1) != 0)
  {
    if ((sec_r000777_8_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000777_0_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000777_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000777_0_1 + 7) & 127;
  }
  if ((sec_r000777_17_2 & 1) != 0)
  {
    if ((sec_r000777_8_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000777_0_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000777_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000777_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000777_2_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000777_11_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000777_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000777_11_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000777_2_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000777_11_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000777_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000777_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000777_8_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000777_2_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000777_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000777_2_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000777_8_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000777_2_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000777_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000777_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000777_0_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000777_12_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000777_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000777_12_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000777_0_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000777_12_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000777_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000777_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000777_11_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000777_12_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000777_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000777_12_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000777_11_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000777_12_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000777_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000777_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000777_11_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000777_15_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000777_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000777_15_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000777_11_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000777_15_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000777_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000777_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000777_1_1 & 1) != 0)
  {
    if ((sec_r000777_2_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000777_2_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000777_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000777_2_1 + 7) & 127;
  }
  if ((sec_r000777_1_2 & 1) != 0)
  {
    if ((sec_r000777_2_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000777_2_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000777_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000777_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000777_11_1 & 1) != 0)
  {
    if ((sec_r000777_13_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000777_17_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000777_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000777_17_1 + 7) & 127;
  }
  if ((sec_r000777_11_2 & 1) != 0)
  {
    if ((sec_r000777_13_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000777_17_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000777_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000777_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000777_18_1 & 1) != 0)
  {
    if ((sec_r000777_10_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000777_7_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000777_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000777_7_1 + 7) & 127;
  }
  if ((sec_r000777_18_2 & 1) != 0)
  {
    if ((sec_r000777_10_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000777_7_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000777_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000777_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000777_9_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000777_4_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000777_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000777_4_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000777_9_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000777_4_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000777_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000777_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000777_3_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000777_21_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000777_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000777_21_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000777_3_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000777_21_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000777_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000777_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000777_11_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000777_19_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000777_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000777_19_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000777_11_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000777_19_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000777_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000777_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000777_16_1 & 1) != 0)
  {
    if ((sec_r000777_0_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000777_7_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000777_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000777_7_1 + 7) & 127;
  }
  if ((sec_r000777_16_2 & 1) != 0)
  {
    if ((sec_r000777_0_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000777_7_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000777_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000777_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000777_10_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000777_20_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000777_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000777_20_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000777_10_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000777_20_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000777_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000777_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000777_1_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000777_9_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000777_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000777_9_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000777_1_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000777_9_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000777_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000777_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000777_17_1 & 1) != 0)
  {
    if ((sec_r000777_8_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000777_9_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000777_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000777_9_1 + 7) & 127;
  }
  if ((sec_r000777_17_2 & 1) != 0)
  {
    if ((sec_r000777_8_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000777_9_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000777_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000777_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000777_11_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000777_19_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000777_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000777_19_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000777_11_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000777_19_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000777_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000777_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000777_11_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000777_23_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000777_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000777_23_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000777_11_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000777_23_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000777_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000777_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000777_4_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000777_22_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000777_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000777_22_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000777_4_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000777_22_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000777_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000777_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((sec_r000777_11_1 & 1) != 0)
  {
    if ((sec_r000777_5_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000777_16_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000777_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000777_16_1 + 7) & 127;
  }
  if ((sec_r000777_11_2 & 1) != 0)
  {
    if ((sec_r000777_5_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000777_16_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000777_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000777_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000777_17_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000777_1_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000777_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000777_1_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000777_17_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000777_1_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000777_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000777_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000777_8_1 & 1) != 0)
  {
    if ((sec_r000777_11_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000777_5_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000777_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000777_5_1 + 7) & 127;
  }
  if ((sec_r000777_8_2 & 1) != 0)
  {
    if ((sec_r000777_11_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000777_5_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000777_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000777_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((sec_r000777_15_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000777_20_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000777_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000777_20_1 + 7) & 127;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((sec_r000777_15_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000777_20_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000777_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000777_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000777_11_1 & 1) != 0)
  {
    if ((sec_r000777_13_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000777_15_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000777_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000777_15_1 + 7) & 127;
  }
  if ((sec_r000777_11_2 & 1) != 0)
  {
    if ((sec_r000777_13_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000777_15_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000777_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000777_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((sec_r000777_10_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000777_6_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000777_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000777_6_1 + 7) & 127;
  }
  if ((stage_v_143_2 & 1) != 0)
  {
    if ((sec_r000777_10_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000777_6_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000777_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000777_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000777_8_1 & 1) != 0)
  {
    if ((sec_r000777_4_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000777_2_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000777_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000777_2_1 + 7) & 127;
  }
  if ((sec_r000777_8_2 & 1) != 0)
  {
    if ((sec_r000777_4_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000777_2_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000777_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000777_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((sec_r000777_18_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000777_9_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000777_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000777_9_1 + 7) & 127;
  }
  if ((stage_v_141_2 & 1) != 0)
  {
    if ((sec_r000777_18_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000777_9_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000777_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000777_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((sec_r000777_15_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000777_20_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000777_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000777_20_1 + 7) & 127;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((sec_r000777_15_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000777_20_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000777_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000777_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000777_18_1 & 1) != 0)
  {
    if ((sec_r000777_0_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000777_10_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000777_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000777_10_1 + 7) & 127;
  }
  if ((sec_r000777_18_2 & 1) != 0)
  {
    if ((sec_r000777_0_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000777_10_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000777_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000777_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000777_13_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000777_3_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000777_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000777_3_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000777_13_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000777_3_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000777_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000777_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000777_13_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000777_12_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000777_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000777_12_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000777_13_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000777_12_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000777_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000777_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((sec_r000777_11_1 & 1) != 0)
  {
    if ((sec_r000777_7_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000777_19_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000777_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000777_19_1 + 7) & 127;
  }
  if ((sec_r000777_11_2 & 1) != 0)
  {
    if ((sec_r000777_7_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000777_19_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000777_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000777_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((sec_r000777_17_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000777_0_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000777_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000777_0_1 + 7) & 127;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((sec_r000777_17_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000777_0_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000777_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000777_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((sec_r000777_17_1 & 1) != 0)
  {
    if ((sec_r000777_8_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000777_21_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000777_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000777_21_1 + 7) & 127;
  }
  if ((sec_r000777_17_2 & 1) != 0)
  {
    if ((sec_r000777_8_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000777_21_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000777_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000777_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((sec_r000777_8_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000777_9_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000777_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000777_9_1 + 7) & 127;
  }
  if ((stage_v_153_2 & 1) != 0)
  {
    if ((sec_r000777_8_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000777_9_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000777_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000777_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((sec_r000777_9_1 & 1) != 0)
  {
    if ((sec_r000777_1_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000777_8_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000777_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000777_8_1 + 7) & 127;
  }
  if ((sec_r000777_9_2 & 1) != 0)
  {
    if ((sec_r000777_1_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000777_8_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000777_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000777_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000777_6_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000777_0_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000777_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000777_0_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000777_6_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000777_0_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000777_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000777_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((sec_r000777_10_1 & 1) != 0)
  {
    if ((sec_r000777_6_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000777_19_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000777_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000777_19_1 + 7) & 127;
  }
  if ((sec_r000777_10_2 & 1) != 0)
  {
    if ((sec_r000777_6_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000777_19_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000777_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000777_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((sec_r000777_7_1 & 1) != 0)
  {
    if ((sec_r000777_13_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000777_8_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000777_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000777_8_1 + 7) & 127;
  }
  if ((sec_r000777_7_2 & 1) != 0)
  {
    if ((sec_r000777_13_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000777_8_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000777_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000777_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((sec_r000777_4_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000777_4_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000777_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000777_4_1 + 7) & 127;
  }
  if ((stage_v_154_2 & 1) != 0)
  {
    if ((sec_r000777_4_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000777_4_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000777_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000777_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000777_6_1 & 2) != 0)
    {
      stage_v_163_1 = (pub_r000777_16_1 + 31) & 127;
    }
    else
    {
      stage_v_163_1 = (pub_r000777_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_1 = (pub_r000777_16_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000777_6_2 & 2) != 0)
    {
      stage_v_163_2 = (pub_r000777_16_2 + 31) & 127;
    }
    else
    {
      stage_v_163_2 = (pub_r000777_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_2 = (pub_r000777_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((sec_r000777_18_1 & 2) != 0)
    {
      stage_v_164_1 = (pub_r000777_17_1 + 31) & 127;
    }
    else
    {
      stage_v_164_1 = (pub_r000777_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_1 = (pub_r000777_17_1 + 7) & 127;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((sec_r000777_18_2 & 2) != 0)
    {
      stage_v_164_2 = (pub_r000777_17_2 + 31) & 127;
    }
    else
    {
      stage_v_164_2 = (pub_r000777_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_2 = (pub_r000777_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((sec_r000777_10_1 & 2) != 0)
    {
      stage_v_165_1 = (pub_r000777_21_1 + 31) & 127;
    }
    else
    {
      stage_v_165_1 = (pub_r000777_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_1 = (pub_r000777_21_1 + 7) & 127;
  }
  if ((stage_v_142_2 & 1) != 0)
  {
    if ((sec_r000777_10_2 & 2) != 0)
    {
      stage_v_165_2 = (pub_r000777_21_2 + 31) & 127;
    }
    else
    {
      stage_v_165_2 = (pub_r000777_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_2 = (pub_r000777_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  if ((sec_r000777_3_1 & 1) != 0)
  {
    if ((sec_r000777_7_1 & 2) != 0)
    {
      stage_v_166_1 = (pub_r000777_2_1 + 31) & 127;
    }
    else
    {
      stage_v_166_1 = (pub_r000777_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_1 = (pub_r000777_2_1 + 7) & 127;
  }
  if ((sec_r000777_3_2 & 1) != 0)
  {
    if ((sec_r000777_7_2 & 2) != 0)
    {
      stage_v_166_2 = (pub_r000777_2_2 + 31) & 127;
    }
    else
    {
      stage_v_166_2 = (pub_r000777_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_2 = (pub_r000777_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  if ((sec_r000777_11_1 & 1) != 0)
  {
    if ((sec_r000777_4_1 & 2) != 0)
    {
      stage_v_167_1 = (pub_r000777_7_1 + 31) & 127;
    }
    else
    {
      stage_v_167_1 = (pub_r000777_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_1 = (pub_r000777_7_1 + 7) & 127;
  }
  if ((sec_r000777_11_2 & 1) != 0)
  {
    if ((sec_r000777_4_2 & 2) != 0)
    {
      stage_v_167_2 = (pub_r000777_7_2 + 31) & 127;
    }
    else
    {
      stage_v_167_2 = (pub_r000777_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_2 = (pub_r000777_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000777_9_1 & 2) != 0)
    {
      stage_v_168_1 = (pub_r000777_18_1 + 31) & 127;
    }
    else
    {
      stage_v_168_1 = (pub_r000777_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_168_1 = (pub_r000777_18_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000777_9_2 & 2) != 0)
    {
      stage_v_168_2 = (pub_r000777_18_2 + 31) & 127;
    }
    else
    {
      stage_v_168_2 = (pub_r000777_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_168_2 = (pub_r000777_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  if ((sec_r000777_7_1 & 1) != 0)
  {
    if ((sec_r000777_12_1 & 2) != 0)
    {
      stage_v_169_1 = (pub_r000777_9_1 + 31) & 127;
    }
    else
    {
      stage_v_169_1 = (pub_r000777_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_169_1 = (pub_r000777_9_1 + 7) & 127;
  }
  if ((sec_r000777_7_2 & 1) != 0)
  {
    if ((sec_r000777_12_2 & 2) != 0)
    {
      stage_v_169_2 = (pub_r000777_9_2 + 31) & 127;
    }
    else
    {
      stage_v_169_2 = (pub_r000777_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_169_2 = (pub_r000777_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000777_8_1 & 2) != 0)
    {
      stage_v_170_1 = (pub_r000777_14_1 + 31) & 127;
    }
    else
    {
      stage_v_170_1 = (pub_r000777_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_170_1 = (pub_r000777_14_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000777_8_2 & 2) != 0)
    {
      stage_v_170_2 = (pub_r000777_14_2 + 31) & 127;
    }
    else
    {
      stage_v_170_2 = (pub_r000777_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_170_2 = (pub_r000777_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  if ((sec_r000777_9_1 & 1) != 0)
  {
    if ((sec_r000777_12_1 & 2) != 0)
    {
      stage_v_171_1 = (pub_r000777_8_1 + 31) & 127;
    }
    else
    {
      stage_v_171_1 = (pub_r000777_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_171_1 = (pub_r000777_8_1 + 7) & 127;
  }
  if ((sec_r000777_9_2 & 1) != 0)
  {
    if ((sec_r000777_12_2 & 2) != 0)
    {
      stage_v_171_2 = (pub_r000777_8_2 + 31) & 127;
    }
    else
    {
      stage_v_171_2 = (pub_r000777_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_171_2 = (pub_r000777_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  if ((sec_r000777_3_1 & 1) != 0)
  {
    if ((sec_r000777_7_1 & 2) != 0)
    {
      stage_v_172_1 = (pub_r000777_0_1 + 31) & 127;
    }
    else
    {
      stage_v_172_1 = (pub_r000777_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_172_1 = (pub_r000777_0_1 + 7) & 127;
  }
  if ((sec_r000777_3_2 & 1) != 0)
  {
    if ((sec_r000777_7_2 & 2) != 0)
    {
      stage_v_172_2 = (pub_r000777_0_2 + 31) & 127;
    }
    else
    {
      stage_v_172_2 = (pub_r000777_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_172_2 = (pub_r000777_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = 0;
  int stage_v_173_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000777_17_1 & 2) != 0)
    {
      stage_v_173_1 = (pub_r000777_13_1 + 31) & 127;
    }
    else
    {
      stage_v_173_1 = (pub_r000777_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_173_1 = (pub_r000777_13_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000777_17_2 & 2) != 0)
    {
      stage_v_173_2 = (pub_r000777_13_2 + 31) & 127;
    }
    else
    {
      stage_v_173_2 = (pub_r000777_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_173_2 = (pub_r000777_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = 0;
  int stage_v_174_2 = 0;
  if ((stage_v_163_1 & 1) != 0)
  {
    if ((sec_r000777_15_1 & 2) != 0)
    {
      stage_v_174_1 = (pub_r000777_21_1 + 31) & 127;
    }
    else
    {
      stage_v_174_1 = (pub_r000777_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_174_1 = (pub_r000777_21_1 + 7) & 127;
  }
  if ((stage_v_163_2 & 1) != 0)
  {
    if ((sec_r000777_15_2 & 2) != 0)
    {
      stage_v_174_2 = (pub_r000777_21_2 + 31) & 127;
    }
    else
    {
      stage_v_174_2 = (pub_r000777_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_174_2 = (pub_r000777_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = 0;
  int stage_v_175_2 = 0;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((sec_r000777_11_1 & 2) != 0)
    {
      stage_v_175_1 = (pub_r000777_6_1 + 31) & 127;
    }
    else
    {
      stage_v_175_1 = (pub_r000777_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_175_1 = (pub_r000777_6_1 + 7) & 127;
  }
  if ((stage_v_161_2 & 1) != 0)
  {
    if ((sec_r000777_11_2 & 2) != 0)
    {
      stage_v_175_2 = (pub_r000777_6_2 + 31) & 127;
    }
    else
    {
      stage_v_175_2 = (pub_r000777_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_175_2 = (pub_r000777_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000777_11_1 != sec_r000777_11_2);
  __CPROVER_assume(pub_r000777_21_1 == pub_r000777_21_2);
  __CPROVER_assume(sec_r000777_4_1 != sec_r000777_4_2);
  __CPROVER_assume(sec_r000777_18_1 != sec_r000777_18_2);
  __CPROVER_assume(pub_r000777_15_1 == pub_r000777_15_2);
  __CPROVER_assume(pub_r000777_18_1 == pub_r000777_18_2);
  __CPROVER_assume(pub_r000777_20_1 == pub_r000777_20_2);
  __CPROVER_assume(sec_r000777_16_1 != sec_r000777_16_2);
  __CPROVER_assume(sec_r000777_15_1 != sec_r000777_15_2);
  __CPROVER_assume(pub_r000777_22_1 == pub_r000777_22_2);
  __CPROVER_assume(pub_r000777_3_1 == pub_r000777_3_2);
  __CPROVER_assume(sec_r000777_0_1 != sec_r000777_0_2);
  __CPROVER_assume(pub_r000777_11_1 == pub_r000777_11_2);
  __CPROVER_assume(pub_r000777_14_1 == pub_r000777_14_2);
  __CPROVER_assume(pub_r000777_7_1 == pub_r000777_7_2);
  __CPROVER_assume(sec_r000777_10_1 != sec_r000777_10_2);
  __CPROVER_assume(sec_r000777_13_1 != sec_r000777_13_2);
  __CPROVER_assume(pub_r000777_13_1 == pub_r000777_13_2);
  __CPROVER_assume(pub_r000777_10_1 == pub_r000777_10_2);
  __CPROVER_assume(sec_r000777_9_1 != sec_r000777_9_2);
  __CPROVER_assume(pub_r000777_6_1 == pub_r000777_6_2);
  __CPROVER_assume(sec_r000777_14_1 != sec_r000777_14_2);
  __CPROVER_assume(sec_r000777_12_1 != sec_r000777_12_2);
  __CPROVER_assume(pub_r000777_23_1 == pub_r000777_23_2);
  __CPROVER_assume(pub_r000777_19_1 == pub_r000777_19_2);
  __CPROVER_assume(pub_r000777_1_1 == pub_r000777_1_2);
  __CPROVER_assume(pub_r000777_0_1 == pub_r000777_0_2);
  __CPROVER_assume(pub_r000777_5_1 == pub_r000777_5_2);
  __CPROVER_assume(pub_r000777_9_1 == pub_r000777_9_2);
  __CPROVER_assume(sec_r000777_17_1 != sec_r000777_17_2);
  __CPROVER_assume(pub_r000777_4_1 == pub_r000777_4_2);
  __CPROVER_assume(sec_r000777_2_1 != sec_r000777_2_2);
  __CPROVER_assume(pub_r000777_12_1 == pub_r000777_12_2);
  __CPROVER_assume(sec_r000777_6_1 != sec_r000777_6_2);
  __CPROVER_assume(sec_r000777_1_1 != sec_r000777_1_2);
  __CPROVER_assume(sec_r000777_3_1 != sec_r000777_3_2);
  __CPROVER_assume(pub_r000777_16_1 == pub_r000777_16_2);
  __CPROVER_assume(pub_r000777_17_1 == pub_r000777_17_2);
  __CPROVER_assume(pub_r000777_2_1 == pub_r000777_2_2);
  __CPROVER_assume(sec_r000777_7_1 != sec_r000777_7_2);
  __CPROVER_assume(pub_r000777_8_1 == pub_r000777_8_2);
  __CPROVER_assume(sec_r000777_5_1 != sec_r000777_5_2);
  __CPROVER_assume(sec_r000777_8_1 != sec_r000777_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.balance == st_var_1_2.balance);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
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
}


