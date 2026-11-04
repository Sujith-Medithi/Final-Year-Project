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
struct MatrixBlock_R000889_8917_0
{
  int stride;
  int scale;
  int density;
  int buffer[3];
};
struct Vector3D_R000889_8917_1
{
  short coord_y;
  int norm_sq;
  int coord_z;
  int coord_x;
  int buffer[3];
};
union TelemetryField_R000889_8917_0
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
void fn_R000889_8917_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st_1 = {0};
  struct Vector3D_R000889_8917_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_68_1 = local_arr_1[aux_1 % 3];
  int weight_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_68_2 * 2)) & 127;
  int offset_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_66_1)
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

  switch (offset_66_2)
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

  int offset_81_1 = 0;
  int offset_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_81_1 = ((offset_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_81_2 = ((offset_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_81_1) & 127;
    acc_2 = (acc_2 + offset_81_2) & 127;
  }

  int margin_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_83_1 > 19)
  {
    acc_1 = ((acc_1 + (margin_83_1 * 2)) + 5) & 127;
    aux_1 ^= margin_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_83_2 > 19)
  {
    acc_2 = ((acc_2 + (margin_83_2 * 2)) + 5) & 127;
    aux_2 ^= margin_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_68_1 == weight_68_2);
  assert(offset_66_1 == offset_66_2);
  assert(offset_81_1 == offset_81_2);
  assert(margin_83_1 == margin_83_2);
}

int fn_R000889_8917_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int weight_68 = local_arr[aux % 3];
  acc = (acc + (weight_68 * 2)) & 127;
  int offset_66 = (aux + st.buffer[1]) & 3;
  switch (offset_66)
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

  int offset_81 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_81 = ((offset_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_81) & 127;
  }

  int margin_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_83 > 19)
  {
    acc = ((acc + (margin_83 * 2)) + 5) & 127;
    aux ^= margin_83 & 15;
  }
  else
  {
    acc = ((acc - margin_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000889_8917_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st_1 = {0};
  struct Vector3D_R000889_8917_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int coefficient_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_39_1 > 20)
  {
    acc_1 = ((acc_1 + (coefficient_39_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_39_2 > 20)
  {
    acc_2 = ((acc_2 + (coefficient_39_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_95_1 = local_arr_1[aux_1 % 3];
  int quantum_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_39_1 == coefficient_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_95_1 == quantum_95_2);
}

int fn_R000889_8917_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int coefficient_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_39 > 20)
  {
    acc = ((acc + (coefficient_39 * 2)) + 5) & 127;
    aux ^= coefficient_39 & 15;
  }
  else
  {
    acc = ((acc - coefficient_39) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_95 = local_arr[aux % 3];
  acc = (acc + (quantum_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000889_8917_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int offset_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_68_1 > 24)
  {
    acc_1 = ((acc_1 + (offset_68_1 * 2)) + 5) & 127;
    aux_1 ^= offset_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_68_2 > 24)
  {
    acc_2 = ((acc_2 + (offset_68_2 * 2)) + 5) & 127;
    aux_2 ^= offset_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_26_1) & 63;
  aux_2 = (aux_2 + damping_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_57_1 = local_arr_1[aux_1 % 3];
  int tracker_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_57_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_68_1 == offset_68_2);
  assert(damping_26_1 == damping_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_57_1 == tracker_57_2);
}

int fn_R000889_8917_2(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int offset_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_68 > 24)
  {
    acc = ((acc + (offset_68 * 2)) + 5) & 127;
    aux ^= offset_68 & 15;
  }
  else
  {
    acc = ((acc - offset_68) + 11) & 127;
    aux += 3;
  }
  int damping_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_26) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_57 = local_arr[aux % 3];
  acc = (acc + (tracker_57 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000889_8917_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st_1 = {0};
  struct Vector3D_R000889_8917_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_49_1 > 49)
  {
    acc_1 = ((acc_1 + (factor_49_1 * 2)) + 5) & 127;
    aux_1 ^= factor_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_49_2 > 49)
  {
    acc_2 = ((acc_2 + (factor_49_2 * 2)) + 5) & 127;
    aux_2 ^= factor_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_49_1 == factor_49_2);
}

int fn_R000889_8917_3(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_49 > 49)
  {
    acc = ((acc + (factor_49 * 2)) + 5) & 127;
    aux ^= factor_49 & 15;
  }
  else
  {
    acc = ((acc - factor_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000889_8917_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int coefficient_51_1 = 0;
  int coefficient_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_51_1 = ((coefficient_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_51_2 = ((coefficient_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_51_1) & 127;
    acc_2 = (acc_2 + coefficient_51_2) & 127;
  }

  int vector_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_37_1)
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

  switch (vector_37_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_51_1 == coefficient_51_2);
  assert(vector_37_1 == vector_37_2);
}

int fn_R000889_8917_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int coefficient_51 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_51 = ((coefficient_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_51) & 127;
  }

  int vector_37 = (aux + st.buffer[1]) & 3;
  switch (vector_37)
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

void fn_R000889_8917_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_26_1 > 39)
  {
    acc_1 = ((acc_1 + (delta_26_1 * 2)) + 5) & 127;
    aux_1 ^= delta_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_26_2 > 39)
  {
    acc_2 = ((acc_2 + (delta_26_2 * 2)) + 5) & 127;
    aux_2 ^= delta_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_82_1 = local_arr_1[aux_1 % 3];
  int offset_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_82_2 * 2)) & 127;
  int factor_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_56_1)
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

  switch (factor_56_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_26_1 == delta_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_82_1 == offset_82_2);
  assert(factor_56_1 == factor_56_2);
}

int fn_R000889_8917_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_26 > 39)
  {
    acc = ((acc + (delta_26 * 2)) + 5) & 127;
    aux ^= delta_26 & 15;
  }
  else
  {
    acc = ((acc - delta_26) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_82 = local_arr[aux % 3];
  acc = (acc + (offset_82 * 2)) & 127;
  int factor_56 = (aux + st.buffer[1]) & 3;
  switch (factor_56)
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

void fn_R000889_8917_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int sample_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_29_1)
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

  switch (sample_29_2)
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
  int delta_50_1 = local_arr_1[aux_1 % 3];
  int delta_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_50_2 * 2)) & 127;
  int segment_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_19_1 > 20)
  {
    acc_1 = ((acc_1 + (segment_19_1 * 2)) + 5) & 127;
    aux_1 ^= segment_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_19_2 > 20)
  {
    acc_2 = ((acc_2 + (segment_19_2 * 2)) + 5) & 127;
    aux_2 ^= segment_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_10_1) & 63;
  aux_2 = (aux_2 + stride_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_29_1 == sample_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_50_1 == delta_50_2);
  assert(segment_19_1 == segment_19_2);
  assert(stride_10_1 == stride_10_2);
}

int fn_R000889_8917_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int sample_29 = (aux + st.buffer[1]) & 3;
  switch (sample_29)
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
  int delta_50 = local_arr[aux % 3];
  acc = (acc + (delta_50 * 2)) & 127;
  int segment_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_19 > 20)
  {
    acc = ((acc + (segment_19 * 2)) + 5) & 127;
    aux ^= segment_19 & 15;
  }
  else
  {
    acc = ((acc - segment_19) + 11) & 127;
    aux += 3;
  }
  int stride_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_10) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000889_8917_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_74_1 = local_arr_1[aux_1 % 3];
  int damping_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_74_2 * 2)) & 127;
  int segment_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_81_1 > 29)
  {
    acc_1 = ((acc_1 + (segment_81_1 * 2)) + 5) & 127;
    aux_1 ^= segment_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_81_2 > 29)
  {
    acc_2 = ((acc_2 + (segment_81_2 * 2)) + 5) & 127;
    aux_2 ^= segment_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_74_1 == damping_74_2);
  assert(segment_81_1 == segment_81_2);
}

int fn_R000889_8917_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int damping_74 = local_arr[aux % 3];
  acc = (acc + (damping_74 * 2)) & 127;
  int segment_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_81 > 29)
  {
    acc = ((acc + (segment_81 * 2)) + 5) & 127;
    aux ^= segment_81 & 15;
  }
  else
  {
    acc = ((acc - segment_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000889_8917_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int stride_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_49_1)
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

  switch (stride_49_2)
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

  int sample_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_20_1) & 63;
  aux_2 = (aux_2 + sample_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_49_1 == stride_49_2);
  assert(sample_20_1 == sample_20_2);
}

int fn_R000889_8917_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int stride_49 = (aux + st.buffer[1]) & 3;
  switch (stride_49)
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

  int sample_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_20) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000889_8917_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int scale_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_21_1) & 63;
  aux_2 = (aux_2 + scale_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_40_1 = 0;
  int coefficient_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_40_1 = ((coefficient_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_40_2 = ((coefficient_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_40_1) & 127;
    acc_2 = (acc_2 + coefficient_40_2) & 127;
  }

  int tracker_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_14_1 > 40)
  {
    acc_1 = ((acc_1 + (tracker_14_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_14_2 > 40)
  {
    acc_2 = ((acc_2 + (tracker_14_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_81_1)
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

  switch (residue_81_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_21_1 == scale_21_2);
  assert(coefficient_40_1 == coefficient_40_2);
  assert(tracker_14_1 == tracker_14_2);
  assert(residue_81_1 == residue_81_2);
}

int fn_R000889_8917_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int scale_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_21) & 63;
  acc ^= aux;
  int coefficient_40 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_40 = ((coefficient_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_40) & 127;
  }

  int tracker_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_14 > 40)
  {
    acc = ((acc + (tracker_14 * 2)) + 5) & 127;
    aux ^= tracker_14 & 15;
  }
  else
  {
    acc = ((acc - tracker_14) + 11) & 127;
    aux += 3;
  }
  int residue_81 = (aux + st.buffer[1]) & 3;
  switch (residue_81)
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

void fn_R000889_8917_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int checksum_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_21_1 > 30)
  {
    acc_1 = ((acc_1 + (checksum_21_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_21_2 > 30)
  {
    acc_2 = ((acc_2 + (checksum_21_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_25_1 = local_arr_1[aux_1 % 3];
  int threshold_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_25_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_71_1 = 0;
  int quantum_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_71_1 = ((quantum_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_71_2 = ((quantum_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_71_1) & 127;
    acc_2 = (acc_2 + quantum_71_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_21_1 == checksum_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_25_1 == threshold_25_2);
  assert(quantum_71_1 == quantum_71_2);
}

int fn_R000889_8917_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int checksum_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_21 > 30)
  {
    acc = ((acc + (checksum_21 * 2)) + 5) & 127;
    aux ^= checksum_21 & 15;
  }
  else
  {
    acc = ((acc - checksum_21) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_25 = local_arr[aux % 3];
  acc = (acc + (threshold_25 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_71 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_71 = ((quantum_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_71) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000889_8917_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st_1 = {0};
  struct Vector3D_R000889_8917_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int delta_29_1 = 0;
  int delta_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_29_1 = ((delta_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_29_2 = ((delta_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_29_1) & 127;
    acc_2 = (acc_2 + delta_29_2) & 127;
  }

  int offset_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_26_1)
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

  switch (offset_26_2)
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

  int weight_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_23_1 > 20)
  {
    acc_1 = ((acc_1 + (weight_23_1 * 2)) + 5) & 127;
    aux_1 ^= weight_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_23_2 > 20)
  {
    acc_2 = ((acc_2 + (weight_23_2 * 2)) + 5) & 127;
    aux_2 ^= weight_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_23_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_29_1 == delta_29_2);
  assert(offset_26_1 == offset_26_2);
  assert(weight_23_1 == weight_23_2);
}

int fn_R000889_8917_11(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int delta_29 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_29 = ((delta_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_29) & 127;
  }

  int offset_26 = (aux + st.buffer[1]) & 3;
  switch (offset_26)
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

  int weight_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_23 > 20)
  {
    acc = ((acc + (weight_23 * 2)) + 5) & 127;
    aux ^= weight_23 & 15;
  }
  else
  {
    acc = ((acc - weight_23) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000889_8917_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int checksum_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_72_1)
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

  switch (checksum_72_2)
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
  int quotient_78_1 = local_arr_1[aux_1 % 3];
  int quotient_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_78_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_72_1 == checksum_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_78_1 == quotient_78_2);
}

int fn_R000889_8917_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int checksum_72 = (aux + st.buffer[1]) & 3;
  switch (checksum_72)
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
  int quotient_78 = local_arr[aux % 3];
  acc = (acc + (quotient_78 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000889_8917_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int stride_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_60_1 > 24)
  {
    acc_1 = ((acc_1 + (stride_60_1 * 2)) + 5) & 127;
    aux_1 ^= stride_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_60_2 > 24)
  {
    acc_2 = ((acc_2 + (stride_60_2 * 2)) + 5) & 127;
    aux_2 ^= stride_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_60_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_60_1 == stride_60_2);
}

int fn_R000889_8917_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int stride_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_60 > 24)
  {
    acc = ((acc + (stride_60 * 2)) + 5) & 127;
    aux ^= stride_60 & 15;
  }
  else
  {
    acc = ((acc - stride_60) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000889_8917_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_80_1 = 0;
  int accumulator_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_80_1 = ((accumulator_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_80_2 = ((accumulator_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_80_1) & 127;
    acc_2 = (acc_2 + accumulator_80_2) & 127;
  }

  int phase_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_11_1)
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

  switch (phase_11_2)
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

  int metric_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_18_1 > 38)
  {
    acc_1 = ((acc_1 + (metric_18_1 * 2)) + 5) & 127;
    aux_1 ^= metric_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_18_2 > 38)
  {
    acc_2 = ((acc_2 + (metric_18_2 * 2)) + 5) & 127;
    aux_2 ^= metric_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_18_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_80_1 == accumulator_80_2);
  assert(phase_11_1 == phase_11_2);
  assert(metric_18_1 == metric_18_2);
}

int fn_R000889_8917_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_80 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_80 = ((accumulator_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_80) & 127;
  }

  int phase_11 = (aux + st.buffer[1]) & 3;
  switch (phase_11)
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

  int metric_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_18 > 38)
  {
    acc = ((acc + (metric_18 * 2)) + 5) & 127;
    aux ^= metric_18 & 15;
  }
  else
  {
    acc = ((acc - metric_18) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000889_8917_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int delta_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_18_1)
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

  switch (delta_18_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_84_1) & 63;
  aux_2 = (aux_2 + parity_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_18_1 == delta_18_2);
  assert(parity_84_1 == parity_84_2);
}

int fn_R000889_8917_15(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int delta_18 = (aux + st.buffer[1]) & 3;
  switch (delta_18)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000889_8917_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int damping_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_68_1 > 49)
  {
    acc_1 = ((acc_1 + (damping_68_1 * 2)) + 5) & 127;
    aux_1 ^= damping_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_68_2 > 49)
  {
    acc_2 = ((acc_2 + (damping_68_2 * 2)) + 5) & 127;
    aux_2 ^= damping_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_66_1 = local_arr_1[aux_1 % 3];
  int parity_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_66_2 * 2)) & 127;
  int mask_28_1 = 0;
  int mask_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_28_1 = ((mask_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_28_2 = ((mask_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_28_1) & 127;
    acc_2 = (acc_2 + mask_28_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_68_1 == damping_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_66_1 == parity_66_2);
  assert(mask_28_1 == mask_28_2);
}

int fn_R000889_8917_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int damping_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_68 > 49)
  {
    acc = ((acc + (damping_68 * 2)) + 5) & 127;
    aux ^= damping_68 & 15;
  }
  else
  {
    acc = ((acc - damping_68) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_66 = local_arr[aux % 3];
  acc = (acc + (parity_66 * 2)) & 127;
  int mask_28 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_28 = ((mask_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_28) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000889_8917_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int factor_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_79_1 > 48)
  {
    acc_1 = ((acc_1 + (factor_79_1 * 2)) + 5) & 127;
    aux_1 ^= factor_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_79_2 > 48)
  {
    acc_2 = ((acc_2 + (factor_79_2 * 2)) + 5) & 127;
    aux_2 ^= factor_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_95_1) & 63;
  aux_2 = (aux_2 + coefficient_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_79_1 == factor_79_2);
  assert(coefficient_95_1 == coefficient_95_2);
}

int fn_R000889_8917_17(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int factor_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_79 > 48)
  {
    acc = ((acc + (factor_79 * 2)) + 5) & 127;
    aux ^= factor_79 & 15;
  }
  else
  {
    acc = ((acc - factor_79) + 11) & 127;
    aux += 3;
  }
  int coefficient_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_95) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000889_8917_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int cursor_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_99_1)
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

  switch (cursor_99_2)
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

  int parity_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_65_1) & 63;
  aux_2 = (aux_2 + parity_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_99_1 == cursor_99_2);
  assert(parity_65_1 == parity_65_2);
}

int fn_R000889_8917_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int cursor_99 = (aux + st.buffer[1]) & 3;
  switch (cursor_99)
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

  int parity_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000889_8917_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int anchor_30_1 = 0;
  int anchor_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_30_1 = ((anchor_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_30_2 = ((anchor_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_30_1) & 127;
    acc_2 = (acc_2 + anchor_30_2) & 127;
  }

  int margin_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_76_1) & 63;
  aux_2 = (aux_2 + margin_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_71_1)
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

  switch (quantum_71_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_30_1 == anchor_30_2);
  assert(margin_76_1 == margin_76_2);
  assert(quantum_71_1 == quantum_71_2);
}

int fn_R000889_8917_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int anchor_30 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_30 = ((anchor_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_30) & 127;
  }

  int margin_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_76) & 63;
  acc ^= aux;
  int quantum_71 = (aux + st.buffer[1]) & 3;
  switch (quantum_71)
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

void fn_R000889_8917_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st_1 = {0};
  struct Vector3D_R000889_8917_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_23_1 = local_arr_1[aux_1 % 3];
  int quantum_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_23_2 * 2)) & 127;
  int bound_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_17_1) & 63;
  aux_2 = (aux_2 + bound_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_23_1 == quantum_23_2);
  assert(bound_17_1 == bound_17_2);
}

int fn_R000889_8917_20(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int quantum_23 = local_arr[aux % 3];
  acc = (acc + (quantum_23 * 2)) & 127;
  int bound_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_17) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000889_8917_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int coefficient_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_22_1) & 63;
  aux_2 = (aux_2 + coefficient_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_58_1 = local_arr_1[aux_1 % 3];
  int window_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_58_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_70_1 > 35)
  {
    acc_1 = ((acc_1 + (tracker_70_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_70_2 > 35)
  {
    acc_2 = ((acc_2 + (tracker_70_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_22_1 == coefficient_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_58_1 == window_58_2);
  assert(tracker_70_1 == tracker_70_2);
}

int fn_R000889_8917_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int coefficient_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_22) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_58 = local_arr[aux % 3];
  acc = (acc + (window_58 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_70 > 35)
  {
    acc = ((acc + (tracker_70 * 2)) + 5) & 127;
    aux ^= tracker_70 & 15;
  }
  else
  {
    acc = ((acc - tracker_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000889_8917_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st_1 = {0};
  struct Vector3D_R000889_8917_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_65_1 = local_arr_1[aux_1 % 3];
  int vector_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_65_2 * 2)) & 127;
  int damping_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_72_1 > 30)
  {
    acc_1 = ((acc_1 + (damping_72_1 * 2)) + 5) & 127;
    aux_1 ^= damping_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_72_2 > 30)
  {
    acc_2 = ((acc_2 + (damping_72_2 * 2)) + 5) & 127;
    aux_2 ^= damping_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_94_1) & 63;
  aux_2 = (aux_2 + delta_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_65_1 == vector_65_2);
  assert(damping_72_1 == damping_72_2);
  assert(delta_94_1 == delta_94_2);
}

int fn_R000889_8917_22(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int vector_65 = local_arr[aux % 3];
  acc = (acc + (vector_65 * 2)) & 127;
  int damping_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_72 > 30)
  {
    acc = ((acc + (damping_72 * 2)) + 5) & 127;
    aux ^= damping_72 & 15;
  }
  else
  {
    acc = ((acc - damping_72) + 11) & 127;
    aux += 3;
  }
  int delta_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_94) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000889_8917_23_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st_1 = {0};
  struct Vector3D_R000889_8917_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quantum_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_11_1) & 63;
  aux_2 = (aux_2 + quantum_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_61_1 = local_arr_1[aux_1 % 3];
  int parity_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_11_1 == quantum_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_61_1 == parity_61_2);
}

int fn_R000889_8917_23(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000889_8917_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quantum_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_11) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_61 = local_arr[aux % 3];
  acc = (acc + (parity_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000889_8917_24_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int offset_62_1 = 0;
  int offset_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_62_1 = ((offset_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_62_2 = ((offset_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_62_1) & 127;
    acc_2 = (acc_2 + offset_62_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_10_1 = local_arr_1[aux_1 % 3];
  int sample_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_10_2 * 2)) & 127;
  int margin_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_25_1) & 63;
  aux_2 = (aux_2 + margin_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_62_1 == offset_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_10_1 == sample_10_2);
  assert(margin_25_1 == margin_25_2);
}

int fn_R000889_8917_24(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000889_8917_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int offset_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_62 = ((offset_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_62) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_10 = local_arr[aux % 3];
  acc = (acc + (sample_10 * 2)) & 127;
  int margin_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_25) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000889_0_1;
  int sec_r000889_0_2;
  int sec_r000889_1_1;
  int sec_r000889_1_2;
  int sec_r000889_2_1;
  int sec_r000889_2_2;
  int sec_r000889_3_1;
  int sec_r000889_3_2;
  int sec_r000889_4_1;
  int sec_r000889_4_2;
  int sec_r000889_5_1;
  int sec_r000889_5_2;
  int sec_r000889_6_1;
  int sec_r000889_6_2;
  int sec_r000889_7_1;
  int sec_r000889_7_2;
  int sec_r000889_8_1;
  int sec_r000889_8_2;
  int sec_r000889_9_1;
  int sec_r000889_9_2;
  int sec_r000889_10_1;
  int sec_r000889_10_2;
  int sec_r000889_11_1;
  int sec_r000889_11_2;
  int sec_r000889_12_1;
  int sec_r000889_12_2;
  int sec_r000889_13_1;
  int sec_r000889_13_2;
  int sec_r000889_14_1;
  int sec_r000889_14_2;
  int sec_r000889_15_1;
  int sec_r000889_15_2;
  int pub_r000889_0_1;
  int pub_r000889_0_2;
  int pub_r000889_1_1;
  int pub_r000889_1_2;
  int pub_r000889_2_1;
  int pub_r000889_2_2;
  int pub_r000889_3_1;
  int pub_r000889_3_2;
  int pub_r000889_4_1;
  int pub_r000889_4_2;
  int pub_r000889_5_1;
  int pub_r000889_5_2;
  int pub_r000889_6_1;
  int pub_r000889_6_2;
  int pub_r000889_7_1;
  int pub_r000889_7_2;
  int pub_r000889_8_1;
  int pub_r000889_8_2;
  int pub_r000889_9_1;
  int pub_r000889_9_2;
  int pub_r000889_10_1;
  int pub_r000889_10_2;
  int pub_r000889_11_1;
  int pub_r000889_11_2;
  int pub_r000889_12_1;
  int pub_r000889_12_2;
  int pub_r000889_13_1;
  int pub_r000889_13_2;
  int pub_r000889_14_1;
  int pub_r000889_14_2;
  int pub_r000889_15_1;
  int pub_r000889_15_2;
  int pub_r000889_16_1;
  int pub_r000889_16_2;
  int pub_r000889_17_1;
  int pub_r000889_17_2;
  int pub_r000889_18_1;
  int pub_r000889_18_2;
  int pub_r000889_19_1;
  int pub_r000889_19_2;
  int pub_r000889_20_1;
  int pub_r000889_20_2;
  int pub_r000889_21_1;
  int pub_r000889_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000889_0_1 >= (-100)) && (pub_r000889_0_1 <= 100));
  __CPROVER_assume((pub_r000889_0_2 >= (-100)) && (pub_r000889_0_2 <= 100));
  __CPROVER_assume((pub_r000889_1_1 >= (-100)) && (pub_r000889_1_1 <= 100));
  __CPROVER_assume((pub_r000889_1_2 >= (-100)) && (pub_r000889_1_2 <= 100));
  __CPROVER_assume((pub_r000889_2_1 >= (-100)) && (pub_r000889_2_1 <= 100));
  __CPROVER_assume((pub_r000889_2_2 >= (-100)) && (pub_r000889_2_2 <= 100));
  __CPROVER_assume((pub_r000889_3_1 >= (-100)) && (pub_r000889_3_1 <= 100));
  __CPROVER_assume((pub_r000889_3_2 >= (-100)) && (pub_r000889_3_2 <= 100));
  __CPROVER_assume((pub_r000889_4_1 >= (-100)) && (pub_r000889_4_1 <= 100));
  __CPROVER_assume((pub_r000889_4_2 >= (-100)) && (pub_r000889_4_2 <= 100));
  __CPROVER_assume((pub_r000889_5_1 >= (-100)) && (pub_r000889_5_1 <= 100));
  __CPROVER_assume((pub_r000889_5_2 >= (-100)) && (pub_r000889_5_2 <= 100));
  __CPROVER_assume((pub_r000889_6_1 >= (-100)) && (pub_r000889_6_1 <= 100));
  __CPROVER_assume((pub_r000889_6_2 >= (-100)) && (pub_r000889_6_2 <= 100));
  __CPROVER_assume((pub_r000889_7_1 >= (-100)) && (pub_r000889_7_1 <= 100));
  __CPROVER_assume((pub_r000889_7_2 >= (-100)) && (pub_r000889_7_2 <= 100));
  __CPROVER_assume((pub_r000889_8_1 >= (-100)) && (pub_r000889_8_1 <= 100));
  __CPROVER_assume((pub_r000889_8_2 >= (-100)) && (pub_r000889_8_2 <= 100));
  __CPROVER_assume((pub_r000889_9_1 >= (-100)) && (pub_r000889_9_1 <= 100));
  __CPROVER_assume((pub_r000889_9_2 >= (-100)) && (pub_r000889_9_2 <= 100));
  __CPROVER_assume((pub_r000889_10_1 >= (-100)) && (pub_r000889_10_1 <= 100));
  __CPROVER_assume((pub_r000889_10_2 >= (-100)) && (pub_r000889_10_2 <= 100));
  __CPROVER_assume((pub_r000889_11_1 >= (-100)) && (pub_r000889_11_1 <= 100));
  __CPROVER_assume((pub_r000889_11_2 >= (-100)) && (pub_r000889_11_2 <= 100));
  __CPROVER_assume((pub_r000889_12_1 >= (-100)) && (pub_r000889_12_1 <= 100));
  __CPROVER_assume((pub_r000889_12_2 >= (-100)) && (pub_r000889_12_2 <= 100));
  __CPROVER_assume((pub_r000889_13_1 >= (-100)) && (pub_r000889_13_1 <= 100));
  __CPROVER_assume((pub_r000889_13_2 >= (-100)) && (pub_r000889_13_2 <= 100));
  __CPROVER_assume((pub_r000889_14_1 >= (-100)) && (pub_r000889_14_1 <= 100));
  __CPROVER_assume((pub_r000889_14_2 >= (-100)) && (pub_r000889_14_2 <= 100));
  __CPROVER_assume((pub_r000889_15_1 >= (-100)) && (pub_r000889_15_1 <= 100));
  __CPROVER_assume((pub_r000889_15_2 >= (-100)) && (pub_r000889_15_2 <= 100));
  __CPROVER_assume((pub_r000889_16_1 >= (-100)) && (pub_r000889_16_1 <= 100));
  __CPROVER_assume((pub_r000889_16_2 >= (-100)) && (pub_r000889_16_2 <= 100));
  __CPROVER_assume((pub_r000889_17_1 >= (-100)) && (pub_r000889_17_1 <= 100));
  __CPROVER_assume((pub_r000889_17_2 >= (-100)) && (pub_r000889_17_2 <= 100));
  __CPROVER_assume((pub_r000889_18_1 >= (-100)) && (pub_r000889_18_1 <= 100));
  __CPROVER_assume((pub_r000889_18_2 >= (-100)) && (pub_r000889_18_2 <= 100));
  __CPROVER_assume((pub_r000889_19_1 >= (-100)) && (pub_r000889_19_1 <= 100));
  __CPROVER_assume((pub_r000889_19_2 >= (-100)) && (pub_r000889_19_2 <= 100));
  __CPROVER_assume((pub_r000889_20_1 >= (-100)) && (pub_r000889_20_1 <= 100));
  __CPROVER_assume((pub_r000889_20_2 >= (-100)) && (pub_r000889_20_2 <= 100));
  __CPROVER_assume((pub_r000889_21_1 >= (-100)) && (pub_r000889_21_1 <= 100));
  __CPROVER_assume((pub_r000889_21_2 >= (-100)) && (pub_r000889_21_2 <= 100));
  __CPROVER_assume((sec_r000889_0_1 >= 0) && (sec_r000889_0_1 <= 255));
  __CPROVER_assume((sec_r000889_0_2 >= 0) && (sec_r000889_0_2 <= 255));
  __CPROVER_assume((sec_r000889_1_1 >= 0) && (sec_r000889_1_1 <= 255));
  __CPROVER_assume((sec_r000889_1_2 >= 0) && (sec_r000889_1_2 <= 255));
  __CPROVER_assume((sec_r000889_2_1 >= 0) && (sec_r000889_2_1 <= 255));
  __CPROVER_assume((sec_r000889_2_2 >= 0) && (sec_r000889_2_2 <= 255));
  __CPROVER_assume((sec_r000889_3_1 >= 0) && (sec_r000889_3_1 <= 255));
  __CPROVER_assume((sec_r000889_3_2 >= 0) && (sec_r000889_3_2 <= 255));
  __CPROVER_assume((sec_r000889_4_1 >= 0) && (sec_r000889_4_1 <= 255));
  __CPROVER_assume((sec_r000889_4_2 >= 0) && (sec_r000889_4_2 <= 255));
  __CPROVER_assume((sec_r000889_5_1 >= 0) && (sec_r000889_5_1 <= 255));
  __CPROVER_assume((sec_r000889_5_2 >= 0) && (sec_r000889_5_2 <= 255));
  __CPROVER_assume((sec_r000889_6_1 >= 0) && (sec_r000889_6_1 <= 255));
  __CPROVER_assume((sec_r000889_6_2 >= 0) && (sec_r000889_6_2 <= 255));
  __CPROVER_assume((sec_r000889_7_1 >= 0) && (sec_r000889_7_1 <= 255));
  __CPROVER_assume((sec_r000889_7_2 >= 0) && (sec_r000889_7_2 <= 255));
  __CPROVER_assume((sec_r000889_8_1 >= 0) && (sec_r000889_8_1 <= 255));
  __CPROVER_assume((sec_r000889_8_2 >= 0) && (sec_r000889_8_2 <= 255));
  __CPROVER_assume((sec_r000889_9_1 >= 0) && (sec_r000889_9_1 <= 255));
  __CPROVER_assume((sec_r000889_9_2 >= 0) && (sec_r000889_9_2 <= 255));
  __CPROVER_assume((sec_r000889_10_1 >= 0) && (sec_r000889_10_1 <= 255));
  __CPROVER_assume((sec_r000889_10_2 >= 0) && (sec_r000889_10_2 <= 255));
  __CPROVER_assume((sec_r000889_11_1 >= 0) && (sec_r000889_11_1 <= 255));
  __CPROVER_assume((sec_r000889_11_2 >= 0) && (sec_r000889_11_2 <= 255));
  __CPROVER_assume((sec_r000889_12_1 >= 0) && (sec_r000889_12_1 <= 255));
  __CPROVER_assume((sec_r000889_12_2 >= 0) && (sec_r000889_12_2 <= 255));
  __CPROVER_assume((sec_r000889_13_1 >= 0) && (sec_r000889_13_1 <= 255));
  __CPROVER_assume((sec_r000889_13_2 >= 0) && (sec_r000889_13_2 <= 255));
  __CPROVER_assume((sec_r000889_14_1 >= 0) && (sec_r000889_14_1 <= 255));
  __CPROVER_assume((sec_r000889_14_2 >= 0) && (sec_r000889_14_2 <= 255));
  __CPROVER_assume((sec_r000889_15_1 >= 0) && (sec_r000889_15_1 <= 255));
  __CPROVER_assume((sec_r000889_15_2 >= 0) && (sec_r000889_15_2 <= 255));
  struct MatrixBlock_R000889_8917_0 st_var_0_1 = {0};
  struct MatrixBlock_R000889_8917_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000889_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000889_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000889_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000889_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000889_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000889_0_2 + 7) & 15;
  struct Vector3D_R000889_8917_1 st_var_1_1 = {0};
  struct Vector3D_R000889_8917_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000889_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000889_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000889_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000889_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000889_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000889_0_2 + 9) & 15;
  union TelemetryField_R000889_8917_0 u_var_1;
  union TelemetryField_R000889_8917_0 u_var_2;
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
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 32)
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
  if (stage_v_4_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 32)
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
  int stage_v_6_1 = (st_var_0_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_0_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = (st_var_0_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_0_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = (st_var_0_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_0_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 20) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 20) & 15;
  int stage_v_19_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_19_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= stage_v_19_1;
  chk_sum_2 ^= stage_v_19_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 21) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  int stage_v_26_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (31 & 31);
  int stage_v_26_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (31 & 31);
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= (stage_v_26_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_26_2 << 1) & 127;
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
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
  int stage_v_32_1 = (st_var_0_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_0_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 35) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 36) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
  int stage_v_39_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_39_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_40_1 = (st_var_0_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_0_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = ((st_var_0_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_0_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 46)
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
  if (stage_v_46_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 46)
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
  int stage_v_47_1 = ((st_var_1_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_1_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 46)
    {
      chk_sum_1 ^= stage_v_47_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_47_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 46)
    {
      chk_sum_2 ^= stage_v_47_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_48_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_48_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (st_var_0_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_0_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_51_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = ((st_var_1_1.buffer[0] * 2) + 178) & 63;
  int stage_v_57_2 = ((st_var_1_2.buffer[0] * 2) + 178) & 63;
  if (stage_v_57_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 27)
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
  if (stage_v_57_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 27)
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
  int stage_v_58_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (63 & 31);
  int stage_v_58_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (63 & 31);
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= (stage_v_58_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_58_2 << 1) & 127;
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
  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
  int stage_v_62_1 = table_1[2];
  int stage_v_62_2 = table_2[2];
  table_1[2] = (table_1[3] + 125) & 63;
  table_2[2] = (table_2[3] + 125) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = table_1[3];
  int stage_v_63_2 = table_2[3];
  table_1[3] = (table_1[0] + 127) & 63;
  table_2[3] = (table_2[0] + 127) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((st_var_0_1.buffer[1] * 2) + 199) & 63;
  int stage_v_64_2 = ((st_var_0_2.buffer[1] * 2) + 199) & 63;
  if (stage_v_64_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_64_1) - 5) & 255;
    if (stage_v_64_1 > 32)
    {
      chk_sum_1 ^= stage_v_64_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_64_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_64_2) - 5) & 255;
    if (stage_v_64_2 > 32)
    {
      chk_sum_2 ^= stage_v_64_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 66) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
  int stage_v_66_1 = ((st_var_0_1.buffer[0] * 2) + 205) & 63;
  int stage_v_66_2 = ((st_var_0_2.buffer[0] * 2) + 205) & 63;
  if (stage_v_66_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_66_1) - 5) & 255;
    if (stage_v_66_1 > 40)
    {
      chk_sum_1 ^= stage_v_66_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_66_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_66_2) - 5) & 255;
    if (stage_v_66_2 > 40)
    {
      chk_sum_2 ^= stage_v_66_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_67_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_67_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_68_1 = table_1[0];
  int stage_v_68_2 = table_2[0];
  table_1[0] = (table_1[1] + 137) & 63;
  table_2[0] = (table_2[1] + 137) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 70) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_71_1 = ((stage_v_71_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_71_2 = ((stage_v_71_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_73_1 = ((st_var_1_1.buffer[1] * 2) + 226) & 63;
  int stage_v_73_2 = ((st_var_1_2.buffer[1] * 2) + 226) & 63;
  if (stage_v_73_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_73_1) - 5) & 255;
    if (stage_v_73_1 > 49)
    {
      chk_sum_1 ^= stage_v_73_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_73_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_73_2) - 5) & 255;
    if (stage_v_73_2 > 49)
    {
      chk_sum_2 ^= stage_v_73_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_74_1 = (st_var_0_1.buffer[0] ^ 77) & 3;
  int stage_v_74_2 = (st_var_0_2.buffer[0] ^ 77) & 3;
  switch (stage_v_74_1)
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

  switch (stage_v_74_2)
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

  int stage_v_75_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_75_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_76_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (81 & 31);
  int stage_v_76_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (81 & 31);
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= (stage_v_76_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_76_2 << 1) & 127;
  int stage_v_77_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_77_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_77_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_77_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_78_1 = ((stage_v_78_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_78_2 = ((stage_v_78_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 80) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 80) & 15;
  int stage_v_79_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_79_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  chk_sum_1 ^= stage_v_79_1;
  chk_sum_2 ^= stage_v_79_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 81) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 81) & 15;
  int stage_v_80_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_80_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= stage_v_80_1;
  chk_sum_2 ^= stage_v_80_2;
  int stage_v_81_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_81_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 83) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 83) & 15;
  int stage_v_82_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_82_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= stage_v_82_1;
  chk_sum_2 ^= stage_v_82_2;
  int stage_v_83_1 = table_1[3];
  int stage_v_83_2 = table_2[3];
  table_1[3] = (table_1[0] + 167) & 63;
  table_2[3] = (table_2[0] + 167) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = table_1[0];
  int stage_v_84_2 = table_2[0];
  table_1[0] = (table_1[1] + 169) & 63;
  table_2[0] = (table_2[1] + 169) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((st_var_0_1.buffer[2] * 2) + 265) & 63;
  int stage_v_86_2 = ((st_var_0_2.buffer[2] * 2) + 265) & 63;
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
  int stage_v_87_1 = ((st_var_1_1.buffer[0] * 2) + 268) & 63;
  int stage_v_87_2 = ((st_var_1_2.buffer[0] * 2) + 268) & 63;
  if (stage_v_87_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_87_1) - 5) & 255;
    if (stage_v_87_1 > 36)
    {
      chk_sum_1 ^= stage_v_87_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_87_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_87_2) - 5) & 255;
    if (stage_v_87_2 > 36)
    {
      chk_sum_2 ^= stage_v_87_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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
  int stage_v_89_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_89_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_89_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_89_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 91) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 91) & 15;
  int stage_v_90_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_90_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= stage_v_90_1;
  chk_sum_2 ^= stage_v_90_2;
  int stage_v_91_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (96 & 31);
  int stage_v_91_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (96 & 31);
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= (stage_v_91_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_91_2 << 1) & 127;
  int stage_v_92_1 = (st_var_0_1.buffer[0] ^ 95) & 3;
  int stage_v_92_2 = (st_var_0_2.buffer[0] ^ 95) & 3;
  switch (stage_v_92_1)
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

  switch (stage_v_92_2)
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

  int stage_v_93_1 = table_1[1];
  int stage_v_93_2 = table_2[1];
  table_1[1] = (table_1[2] + 187) & 63;
  table_2[1] = (table_2[2] + 187) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (99 & 31);
  int stage_v_94_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (99 & 31);
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  chk_sum_1 ^= (stage_v_94_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_94_2 << 1) & 127;
  int stage_v_95_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_95_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_95_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_95_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_96_1 = ((st_var_0_1.buffer[0] * 2) + 295) & 63;
  int stage_v_96_2 = ((st_var_0_2.buffer[0] * 2) + 295) & 63;
  if (stage_v_96_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_96_1) - 5) & 255;
    if (stage_v_96_1 > 54)
    {
      chk_sum_1 ^= stage_v_96_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_96_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_96_2) - 5) & 255;
    if (stage_v_96_2 > 54)
    {
      chk_sum_2 ^= stage_v_96_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 98) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 98) & 15;
  int stage_v_97_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_97_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= stage_v_97_1;
  chk_sum_2 ^= stage_v_97_2;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_98_1 = ((stage_v_98_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_98_2 = ((stage_v_98_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = table_1[3];
  int stage_v_99_2 = table_2[3];
  table_1[3] = (table_1[0] + 199) & 63;
  table_2[3] = (table_2[0] + 199) & 63;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_100_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_100_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_100_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_101_1 = (st_var_1_1.buffer[0] ^ 104) & 3;
  int stage_v_101_2 = (st_var_1_2.buffer[0] ^ 104) & 3;
  switch (stage_v_101_1)
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

  switch (stage_v_101_2)
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

  int stage_v_102_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_102_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_102_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_102_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_103_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (108 & 31);
  int stage_v_103_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (108 & 31);
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  chk_sum_1 ^= (stage_v_103_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_103_2 << 1) & 127;
  int stage_v_104_1 = (st_var_0_1.buffer[0] ^ 107) & 3;
  int stage_v_104_2 = (st_var_0_2.buffer[0] ^ 107) & 3;
  switch (stage_v_104_1)
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

  switch (stage_v_104_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 106) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 106) & 15;
  int stage_v_105_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_105_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= stage_v_105_1;
  chk_sum_2 ^= stage_v_105_2;
  int stage_v_106_1 = table_1[2];
  int stage_v_106_2 = table_2[2];
  table_1[2] = (table_1[3] + 213) & 63;
  table_2[2] = (table_2[3] + 213) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 108) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 108) & 15;
  int stage_v_107_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_107_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  chk_sum_1 ^= stage_v_107_1;
  chk_sum_2 ^= stage_v_107_2;
  int stage_v_108_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_108_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_108_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_108_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_109_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (114 & 31);
  int stage_v_109_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (114 & 31);
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  chk_sum_1 ^= (stage_v_109_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_109_2 << 1) & 127;
  int stage_v_110_1 = table_1[2];
  int stage_v_110_2 = table_2[2];
  table_1[2] = (table_1[3] + 221) & 63;
  table_2[2] = (table_2[3] + 221) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_111_1 = ((stage_v_111_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_111_2 = ((stage_v_111_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = table_1[0];
  int stage_v_112_2 = table_2[0];
  table_1[0] = (table_1[1] + 225) & 63;
  table_2[0] = (table_2[1] + 225) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 114) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 114) & 15;
  int stage_v_113_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_113_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  chk_sum_1 ^= stage_v_113_1;
  chk_sum_2 ^= stage_v_113_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 115) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 115) & 15;
  int stage_v_114_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_114_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= stage_v_114_1;
  chk_sum_2 ^= stage_v_114_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 116) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 116) & 15;
  int stage_v_115_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_115_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  chk_sum_1 ^= stage_v_115_1;
  chk_sum_2 ^= stage_v_115_2;
  int stage_v_116_1 = ((st_var_0_1.buffer[2] * 2) + 355) & 63;
  int stage_v_116_2 = ((st_var_0_2.buffer[2] * 2) + 355) & 63;
  if (stage_v_116_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_116_1) - 5) & 255;
    if (stage_v_116_1 > 29)
    {
      chk_sum_1 ^= stage_v_116_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_116_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_116_2) - 5) & 255;
    if (stage_v_116_2 > 29)
    {
      chk_sum_2 ^= stage_v_116_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_117_1 = (st_var_1_1.buffer[0] ^ 120) & 3;
  int stage_v_117_2 = (st_var_1_2.buffer[0] ^ 120) & 3;
  switch (stage_v_117_1)
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

  switch (stage_v_117_2)
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

  int stage_v_118_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_118_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_118_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_118_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 120) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 120) & 15;
  int stage_v_119_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_119_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  chk_sum_1 ^= stage_v_119_1;
  chk_sum_2 ^= stage_v_119_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 121) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 121) & 15;
  int stage_v_120_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_120_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  chk_sum_1 ^= stage_v_120_1;
  chk_sum_2 ^= stage_v_120_2;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_121_1 = ((stage_v_121_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_121_2 = ((stage_v_121_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 123) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 123) & 15;
  int stage_v_122_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_122_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  chk_sum_1 ^= stage_v_122_1;
  chk_sum_2 ^= stage_v_122_2;
  int stage_v_123_1 = (st_var_1_1.buffer[0] ^ 126) & 3;
  int stage_v_123_2 = (st_var_1_2.buffer[0] ^ 126) & 3;
  switch (stage_v_123_1)
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

  switch (stage_v_123_2)
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

  int stage_v_124_1 = ((st_var_0_1.buffer[1] * 2) + 379) & 63;
  int stage_v_124_2 = ((st_var_0_2.buffer[1] * 2) + 379) & 63;
  if (stage_v_124_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_124_1) - 5) & 255;
    if (stage_v_124_1 > 39)
    {
      chk_sum_1 ^= stage_v_124_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_124_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_124_2) - 5) & 255;
    if (stage_v_124_2 > 39)
    {
      chk_sum_2 ^= stage_v_124_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_125_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_125_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_125_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_125_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 127) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 127) & 15;
  int stage_v_126_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_126_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  chk_sum_1 ^= stage_v_126_1;
  chk_sum_2 ^= stage_v_126_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 128) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 128) & 15;
  int stage_v_127_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_127_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  chk_sum_1 ^= stage_v_127_1;
  chk_sum_2 ^= stage_v_127_2;
  int stage_v_128_1 = ((st_var_0_1.buffer[2] * 2) + 391) & 63;
  int stage_v_128_2 = ((st_var_0_2.buffer[2] * 2) + 391) & 63;
  if (stage_v_128_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_128_1) - 5) & 255;
    if (stage_v_128_1 > 54)
    {
      chk_sum_1 ^= stage_v_128_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_128_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_128_2) - 5) & 255;
    if (stage_v_128_2 > 54)
    {
      chk_sum_2 ^= stage_v_128_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_129_1 = ((st_var_1_1.buffer[0] * 2) + 394) & 63;
  int stage_v_129_2 = ((st_var_1_2.buffer[0] * 2) + 394) & 63;
  if (stage_v_129_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_129_1) - 5) & 255;
    if (stage_v_129_1 > 48)
    {
      chk_sum_1 ^= stage_v_129_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_129_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_129_2) - 5) & 255;
    if (stage_v_129_2 > 48)
    {
      chk_sum_2 ^= stage_v_129_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_130_1 = ((stage_v_130_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_130_2 = ((stage_v_130_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_131_1 = ((stage_v_131_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_131_2 = ((stage_v_131_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((st_var_0_1.buffer[0] * 2) + 403) & 63;
  int stage_v_132_2 = ((st_var_0_2.buffer[0] * 2) + 403) & 63;
  if (stage_v_132_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_132_1) - 5) & 255;
    if (stage_v_132_1 > 34)
    {
      chk_sum_1 ^= stage_v_132_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_132_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_132_2) - 5) & 255;
    if (stage_v_132_2 > 34)
    {
      chk_sum_2 ^= stage_v_132_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_133_1 = (st_var_1_1.buffer[0] ^ 136) & 3;
  int stage_v_133_2 = (st_var_1_2.buffer[0] ^ 136) & 3;
  switch (stage_v_133_1)
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

  switch (stage_v_133_2)
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

  int stage_v_134_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (139 & 31);
  int stage_v_134_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (139 & 31);
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= (stage_v_134_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_134_2 << 1) & 127;
  int stage_v_135_1 = table_1[3];
  int stage_v_135_2 = table_2[3];
  table_1[3] = (table_1[0] + 271) & 63;
  table_2[3] = (table_2[0] + 271) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_136_1 = ((stage_v_136_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_136_2 = ((stage_v_136_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_137_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_138_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (143 & 31);
  int stage_v_138_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (143 & 31);
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  chk_sum_1 ^= (stage_v_138_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_138_2 << 1) & 127;
  int stage_v_139_1 = (st_var_1_1.buffer[0] ^ 142) & 3;
  int stage_v_139_2 = (st_var_1_2.buffer[0] ^ 142) & 3;
  switch (stage_v_139_1)
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

  switch (stage_v_139_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 141) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 141) & 15;
  int stage_v_140_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_140_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  chk_sum_1 ^= stage_v_140_1;
  chk_sum_2 ^= stage_v_140_2;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_141_1 = ((stage_v_141_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_141_2 = ((stage_v_141_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_142_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_142_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_142_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_143_1 = (st_var_1_1.buffer[0] ^ 146) & 3;
  int stage_v_143_2 = (st_var_1_2.buffer[0] ^ 146) & 3;
  switch (stage_v_143_1)
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

  switch (stage_v_143_2)
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

  int stage_v_144_1 = ((st_var_0_1.buffer[0] * 2) + 439) & 63;
  int stage_v_144_2 = ((st_var_0_2.buffer[0] * 2) + 439) & 63;
  if (stage_v_144_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_144_1) - 5) & 255;
    if (stage_v_144_1 > 28)
    {
      chk_sum_1 ^= stage_v_144_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_144_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_144_2) - 5) & 255;
    if (stage_v_144_2 > 28)
    {
      chk_sum_2 ^= stage_v_144_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_145_1 = ((stage_v_145_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_145_2 = ((stage_v_145_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (st_var_0_1.buffer[0] ^ 149) & 3;
  int stage_v_146_2 = (st_var_0_2.buffer[0] ^ 149) & 3;
  switch (stage_v_146_1)
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

  switch (stage_v_146_2)
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

  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_147_1 = ((stage_v_147_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_147_2 = ((stage_v_147_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (st_var_0_1.buffer[0] ^ 151) & 3;
  int stage_v_148_2 = (st_var_0_2.buffer[0] ^ 151) & 3;
  switch (stage_v_148_1)
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

  switch (stage_v_148_2)
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

  int stage_v_149_1 = (st_var_1_1.buffer[0] ^ 152) & 3;
  int stage_v_149_2 = (st_var_1_2.buffer[0] ^ 152) & 3;
  switch (stage_v_149_1)
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

  switch (stage_v_149_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 151) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 151) & 15;
  int stage_v_150_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_150_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  chk_sum_1 ^= stage_v_150_1;
  chk_sum_2 ^= stage_v_150_2;
  int stage_v_151_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (156 & 31);
  int stage_v_151_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (156 & 31);
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  chk_sum_1 ^= (stage_v_151_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_151_2 << 1) & 127;
  int stage_v_152_1 = table_1[0];
  int stage_v_152_2 = table_2[0];
  table_1[0] = (table_1[1] + 305) & 63;
  table_2[0] = (table_2[1] + 305) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = table_1[1];
  int stage_v_153_2 = table_2[1];
  table_1[1] = (table_1[2] + 307) & 63;
  table_2[1] = (table_2[2] + 307) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (159 & 31);
  int stage_v_154_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (159 & 31);
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  chk_sum_1 ^= (stage_v_154_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_154_2 << 1) & 127;
  int stage_v_155_1 = ((st_var_1_1.buffer[2] * 2) + 472) & 63;
  int stage_v_155_2 = ((st_var_1_2.buffer[2] * 2) + 472) & 63;
  if (stage_v_155_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_155_1) - 5) & 255;
    if (stage_v_155_1 > 29)
    {
      chk_sum_1 ^= stage_v_155_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_155_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_155_2) - 5) & 255;
    if (stage_v_155_2 > 29)
    {
      chk_sum_2 ^= stage_v_155_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_156_1 = ((st_var_0_1.buffer[0] * 2) + 475) & 63;
  int stage_v_156_2 = ((st_var_0_2.buffer[0] * 2) + 475) & 63;
  if (stage_v_156_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_156_1) - 5) & 255;
    if (stage_v_156_1 > 31)
    {
      chk_sum_1 ^= stage_v_156_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_156_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_156_2) - 5) & 255;
    if (stage_v_156_2 > 31)
    {
      chk_sum_2 ^= stage_v_156_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 158) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 158) & 15;
  int stage_v_157_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_157_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  chk_sum_1 ^= stage_v_157_1;
  chk_sum_2 ^= stage_v_157_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 159) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 159) & 15;
  int stage_v_158_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_158_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  chk_sum_1 ^= stage_v_158_1;
  chk_sum_2 ^= stage_v_158_2;
  int stage_v_159_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_159_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_159_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_159_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_160_1 = table_1[0];
  int stage_v_160_2 = table_2[0];
  table_1[0] = (table_1[1] + 321) & 63;
  table_2[0] = (table_2[1] + 321) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 162) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 162) & 15;
  int stage_v_161_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_161_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  chk_sum_1 ^= stage_v_161_1;
  chk_sum_2 ^= stage_v_161_2;
  int stage_v_162_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_162_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_162_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_162_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_163_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_163_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_164_1 = ((stage_v_164_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_164_2 = ((stage_v_164_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((st_var_1_1.buffer[0] * 2) + 502) & 63;
  int stage_v_165_2 = ((st_var_1_2.buffer[0] * 2) + 502) & 63;
  if (stage_v_165_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_165_1) - 5) & 255;
    if (stage_v_165_1 > 45)
    {
      chk_sum_1 ^= stage_v_165_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_165_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_165_2) - 5) & 255;
    if (stage_v_165_2 > 45)
    {
      chk_sum_2 ^= stage_v_165_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 167) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 167) & 15;
  int stage_v_166_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_166_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  chk_sum_1 ^= stage_v_166_1;
  chk_sum_2 ^= stage_v_166_2;
  int stage_v_167_1 = (st_var_1_1.buffer[0] ^ 170) & 3;
  int stage_v_167_2 = (st_var_1_2.buffer[0] ^ 170) & 3;
  switch (stage_v_167_1)
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

  switch (stage_v_167_2)
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

  int stage_v_168_1 = ((st_var_0_1.buffer[0] * 2) + 511) & 63;
  int stage_v_168_2 = ((st_var_0_2.buffer[0] * 2) + 511) & 63;
  if (stage_v_168_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_168_1) - 5) & 255;
    if (stage_v_168_1 > 26)
    {
      chk_sum_1 ^= stage_v_168_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_168_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_168_2) - 5) & 255;
    if (stage_v_168_2 > 26)
    {
      chk_sum_2 ^= stage_v_168_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_169_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (174 & 31);
  int stage_v_169_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (174 & 31);
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  chk_sum_1 ^= (stage_v_169_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_169_2 << 1) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 171) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 171) & 15;
  int stage_v_170_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_170_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  chk_sum_1 ^= stage_v_170_1;
  chk_sum_2 ^= stage_v_170_2;
  int stage_v_171_1 = (st_var_1_1.buffer[0] ^ 174) & 3;
  int stage_v_171_2 = (st_var_1_2.buffer[0] ^ 174) & 3;
  switch (stage_v_171_1)
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

  switch (stage_v_171_2)
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

  int stage_v_172_1 = table_1[0];
  int stage_v_172_2 = table_2[0];
  table_1[0] = (table_1[1] + 345) & 63;
  table_2[0] = (table_2[1] + 345) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = table_1[1];
  int stage_v_173_2 = table_2[1];
  table_1[1] = (table_1[2] + 347) & 63;
  table_2[1] = (table_2[2] + 347) & 63;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = 0;
  int stage_v_174_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_174_1 = ((stage_v_174_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_174_2 = ((stage_v_174_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((st_var_1_1.buffer[1] * 2) + 532) & 63;
  int stage_v_175_2 = ((st_var_1_2.buffer[1] * 2) + 532) & 63;
  if (stage_v_175_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_175_1) - 5) & 255;
    if (stage_v_175_1 > 26)
    {
      chk_sum_1 ^= stage_v_175_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_175_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_175_2) - 5) & 255;
    if (stage_v_175_2 > 26)
    {
      chk_sum_2 ^= stage_v_175_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_176_1 = (st_var_0_1.buffer[0] ^ 179) & 3;
  int stage_v_176_2 = (st_var_0_2.buffer[0] ^ 179) & 3;
  switch (stage_v_176_1)
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

  switch (stage_v_176_2)
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

  int stage_v_177_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_177_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_177_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_177_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_178_1 = (st_var_0_1.buffer[0] ^ 181) & 3;
  int stage_v_178_2 = (st_var_0_2.buffer[0] ^ 181) & 3;
  switch (stage_v_178_1)
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

  switch (stage_v_178_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 180) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 180) & 15;
  int stage_v_179_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_179_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  chk_sum_1 ^= stage_v_179_1;
  chk_sum_2 ^= stage_v_179_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 181) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 181) & 15;
  int stage_v_180_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_180_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  chk_sum_1 ^= stage_v_180_1;
  chk_sum_2 ^= stage_v_180_2;
  int stage_v_181_1 = table_1[1];
  int stage_v_181_2 = table_2[1];
  table_1[1] = (table_1[2] + 363) & 63;
  table_2[1] = (table_2[2] + 363) & 63;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 183) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 183) & 15;
  int stage_v_182_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_182_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  chk_sum_1 ^= stage_v_182_1;
  chk_sum_2 ^= stage_v_182_2;
  int stage_v_183_1 = ((st_var_1_1.buffer[0] * 2) + 556) & 63;
  int stage_v_183_2 = ((st_var_1_2.buffer[0] * 2) + 556) & 63;
  if (stage_v_183_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_183_1) - 5) & 255;
    if (stage_v_183_1 > 27)
    {
      chk_sum_1 ^= stage_v_183_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_183_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_183_2) - 5) & 255;
    if (stage_v_183_2 > 27)
    {
      chk_sum_2 ^= stage_v_183_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_184_1 = 0;
  int stage_v_184_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_184_1 = ((stage_v_184_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_184_2 = ((stage_v_184_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((st_var_1_1.buffer[2] * 2) + 562) & 63;
  int stage_v_185_2 = ((st_var_1_2.buffer[2] * 2) + 562) & 63;
  if (stage_v_185_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_185_1) - 5) & 255;
    if (stage_v_185_1 > 36)
    {
      chk_sum_1 ^= stage_v_185_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_185_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_185_2) - 5) & 255;
    if (stage_v_185_2 > 36)
    {
      chk_sum_2 ^= stage_v_185_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_186_1 = 0;
  int stage_v_186_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_186_1 = ((stage_v_186_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_186_2 = ((stage_v_186_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = 0;
  int stage_v_187_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_187_1 = ((stage_v_187_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_187_2 = ((stage_v_187_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = 0;
  int stage_v_188_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_188_1 = ((stage_v_188_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_188_2 = ((stage_v_188_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int s_lut_1[4] = {44, 12, 93, 47};
  int s_lut_2[4] = {44, 12, 93, 47};
  int s_idx_1 = sec_r000889_5_1 & 3;
  int s_idx_2 = sec_r000889_5_2 & 3;
  out_sink_1 += s_lut_1[s_idx_1];
  out_sink_2 += s_lut_2[s_idx_2];
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000889_9_1 != sec_r000889_9_2);
  __CPROVER_assume(sec_r000889_1_1 != sec_r000889_1_2);
  __CPROVER_assume(sec_r000889_13_1 != sec_r000889_13_2);
  __CPROVER_assume(pub_r000889_5_1 == pub_r000889_5_2);
  __CPROVER_assume(sec_r000889_7_1 != sec_r000889_7_2);
  __CPROVER_assume(pub_r000889_15_1 == pub_r000889_15_2);
  __CPROVER_assume(sec_r000889_8_1 != sec_r000889_8_2);
  __CPROVER_assume(sec_r000889_15_1 != sec_r000889_15_2);
  __CPROVER_assume(pub_r000889_20_1 == pub_r000889_20_2);
  __CPROVER_assume(pub_r000889_18_1 == pub_r000889_18_2);
  __CPROVER_assume(pub_r000889_12_1 == pub_r000889_12_2);
  __CPROVER_assume(sec_r000889_10_1 != sec_r000889_10_2);
  __CPROVER_assume(pub_r000889_4_1 == pub_r000889_4_2);
  __CPROVER_assume(pub_r000889_17_1 == pub_r000889_17_2);
  __CPROVER_assume(sec_r000889_2_1 != sec_r000889_2_2);
  __CPROVER_assume(sec_r000889_5_1 != sec_r000889_5_2);
  __CPROVER_assume(sec_r000889_11_1 != sec_r000889_11_2);
  __CPROVER_assume(pub_r000889_19_1 == pub_r000889_19_2);
  __CPROVER_assume(sec_r000889_3_1 != sec_r000889_3_2);
  __CPROVER_assume(sec_r000889_6_1 != sec_r000889_6_2);
  __CPROVER_assume(pub_r000889_2_1 == pub_r000889_2_2);
  __CPROVER_assume(sec_r000889_14_1 != sec_r000889_14_2);
  __CPROVER_assume(pub_r000889_7_1 == pub_r000889_7_2);
  __CPROVER_assume(sec_r000889_4_1 != sec_r000889_4_2);
  __CPROVER_assume(pub_r000889_10_1 == pub_r000889_10_2);
  __CPROVER_assume(pub_r000889_1_1 == pub_r000889_1_2);
  __CPROVER_assume(pub_r000889_13_1 == pub_r000889_13_2);
  __CPROVER_assume(pub_r000889_6_1 == pub_r000889_6_2);
  __CPROVER_assume(pub_r000889_0_1 == pub_r000889_0_2);
  __CPROVER_assume(pub_r000889_3_1 == pub_r000889_3_2);
  __CPROVER_assume(pub_r000889_14_1 == pub_r000889_14_2);
  __CPROVER_assume(pub_r000889_21_1 == pub_r000889_21_2);
  __CPROVER_assume(pub_r000889_9_1 == pub_r000889_9_2);
  __CPROVER_assume(pub_r000889_8_1 == pub_r000889_8_2);
  __CPROVER_assume(pub_r000889_16_1 == pub_r000889_16_2);
  __CPROVER_assume(sec_r000889_12_1 != sec_r000889_12_2);
  __CPROVER_assume(sec_r000889_0_1 != sec_r000889_0_2);
  __CPROVER_assume(pub_r000889_11_1 == pub_r000889_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.density == st_var_0_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
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
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(s_lut_1[i_0] == s_lut_2[i_0]);
  }

  assert(s_idx_1 == s_idx_2);
}


