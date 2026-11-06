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
struct CipherContext_R000546_4613_0
{
  int iv;
  short flags;
  int counter;
  int buffer[3];
};
struct Vector3D_R000546_4613_1
{
  int norm_sq;
  int heading;
  int coord_y;
  short pitch;
  int buffer[3];
};
struct MatrixBlock_R000546_4613_2
{
  unsigned char determinant;
  short density;
  int dim;
  int scale;
  int trace;
  int buffer[3];
};
union ColorPixel_R000546_4613_0
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
void fn_R000546_4613_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st_1 = {0};
  struct Vector3D_R000546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_16_1 = local_arr_1[aux_1 % 3];
  int sample_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_16_2 * 2)) & 127;
  int metric_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_64_1) & 63;
  aux_2 = (aux_2 + metric_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_16_1 == sample_16_2);
  assert(metric_64_1 == metric_64_2);
}

int fn_R000546_4613_0(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int sample_16 = local_arr[aux % 3];
  acc = (acc + (sample_16 * 2)) & 127;
  int metric_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000546_4613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000546_4613_0 st_1 = {0};
  struct CipherContext_R000546_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int mask_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_28_1) & 63;
  aux_2 = (aux_2 + mask_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_16_1 > 19)
  {
    acc_1 = ((acc_1 + (pivot_16_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_16_2 > 19)
  {
    acc_2 = ((acc_2 + (pivot_16_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_16_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_91_1)
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

  switch (parity_91_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_28_1 == mask_28_2);
  assert(pivot_16_1 == pivot_16_2);
  assert(parity_91_1 == parity_91_2);
}

int fn_R000546_4613_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000546_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int mask_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_28) & 63;
  acc ^= aux;
  int pivot_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_16 > 19)
  {
    acc = ((acc + (pivot_16 * 2)) + 5) & 127;
    aux ^= pivot_16 & 15;
  }
  else
  {
    acc = ((acc - pivot_16) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_91 = (aux + st.buffer[1]) & 3;
  switch (parity_91)
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

void fn_R000546_4613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000546_4613_0 st_1 = {0};
  struct CipherContext_R000546_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int sample_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_27_1) & 63;
  aux_2 = (aux_2 + sample_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_54_1 = local_arr_1[aux_1 % 3];
  int parity_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_27_1 == sample_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_54_1 == parity_54_2);
}

int fn_R000546_4613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000546_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int sample_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_27) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_54 = local_arr[aux % 3];
  acc = (acc + (parity_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000546_4613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st_1 = {0};
  struct Vector3D_R000546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int parity_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_69_1)
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

  switch (parity_69_2)
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
  int bound_34_1 = local_arr_1[aux_1 % 3];
  int bound_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_34_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_97_1 > 16)
  {
    acc_1 = ((acc_1 + (margin_97_1 * 2)) + 5) & 127;
    aux_1 ^= margin_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_97_2 > 16)
  {
    acc_2 = ((acc_2 + (margin_97_2 * 2)) + 5) & 127;
    aux_2 ^= margin_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_69_1 == parity_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_34_1 == bound_34_2);
  assert(margin_97_1 == margin_97_2);
}

int fn_R000546_4613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int parity_69 = (aux + st.buffer[1]) & 3;
  switch (parity_69)
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
  int bound_34 = local_arr[aux % 3];
  acc = (acc + (bound_34 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_97 > 16)
  {
    acc = ((acc + (margin_97 * 2)) + 5) & 127;
    aux ^= margin_97 & 15;
  }
  else
  {
    acc = ((acc - margin_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000546_4613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st_1 = {0};
  struct Vector3D_R000546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int index_reg_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_69_1) & 63;
  aux_2 = (aux_2 + index_reg_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_26_1 > 22)
  {
    acc_1 = ((acc_1 + (damping_26_1 * 2)) + 5) & 127;
    aux_1 ^= damping_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_26_2 > 22)
  {
    acc_2 = ((acc_2 + (damping_26_2 * 2)) + 5) & 127;
    aux_2 ^= damping_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_26_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_69_1 == index_reg_69_2);
  assert(damping_26_1 == damping_26_2);
}

int fn_R000546_4613_4(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int index_reg_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_69) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_26 > 22)
  {
    acc = ((acc + (damping_26 * 2)) + 5) & 127;
    aux ^= damping_26 & 15;
  }
  else
  {
    acc = ((acc - damping_26) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000546_4613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st_1 = {0};
  struct Vector3D_R000546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tracker_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_39_1) & 63;
  aux_2 = (aux_2 + tracker_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_54_1 = local_arr_1[aux_1 % 3];
  int bound_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_54_2 * 2)) & 127;
  int checksum_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_11_1 > 41)
  {
    acc_1 = ((acc_1 + (checksum_11_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_11_2 > 41)
  {
    acc_2 = ((acc_2 + (checksum_11_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_39_1 == tracker_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_54_1 == bound_54_2);
  assert(checksum_11_1 == checksum_11_2);
}

int fn_R000546_4613_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tracker_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_39) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_54 = local_arr[aux % 3];
  acc = (acc + (bound_54 * 2)) & 127;
  int checksum_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_11 > 41)
  {
    acc = ((acc + (checksum_11 * 2)) + 5) & 127;
    aux ^= checksum_11 & 15;
  }
  else
  {
    acc = ((acc - checksum_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000546_4613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st_1 = {0};
  struct Vector3D_R000546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_50_1) & 63;
  aux_2 = (aux_2 + checksum_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_27_1 = local_arr_1[aux_1 % 3];
  int tracker_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_27_2 * 2)) & 127;
  int coefficient_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_14_1 > 39)
  {
    acc_1 = ((acc_1 + (coefficient_14_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_14_2 > 39)
  {
    acc_2 = ((acc_2 + (coefficient_14_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_14_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_50_1 == checksum_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_27_1 == tracker_27_2);
  assert(coefficient_14_1 == coefficient_14_2);
}

int fn_R000546_4613_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_50) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_27 = local_arr[aux % 3];
  acc = (acc + (tracker_27 * 2)) & 127;
  int coefficient_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_14 > 39)
  {
    acc = ((acc + (coefficient_14 * 2)) + 5) & 127;
    aux ^= coefficient_14 & 15;
  }
  else
  {
    acc = ((acc - coefficient_14) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000546_4613_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000546_4613_2 st_1 = {0};
  struct MatrixBlock_R000546_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_19_1 = local_arr_1[aux_1 % 3];
  int sample_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_19_2 * 2)) & 127;
  int mask_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_83_1 > 38)
  {
    acc_1 = ((acc_1 + (mask_83_1 * 2)) + 5) & 127;
    aux_1 ^= mask_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_83_2 > 38)
  {
    acc_2 = ((acc_2 + (mask_83_2 * 2)) + 5) & 127;
    aux_2 ^= mask_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_68_1)
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

  switch (factor_68_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_19_1 == sample_19_2);
  assert(mask_83_1 == mask_83_2);
  assert(factor_68_1 == factor_68_2);
}

int fn_R000546_4613_7(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000546_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_19 = local_arr[aux % 3];
  acc = (acc + (sample_19 * 2)) & 127;
  int mask_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_83 > 38)
  {
    acc = ((acc + (mask_83 * 2)) + 5) & 127;
    aux ^= mask_83 & 15;
  }
  else
  {
    acc = ((acc - mask_83) + 11) & 127;
    aux += 3;
  }
  int factor_68 = (aux + st.buffer[1]) & 3;
  switch (factor_68)
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

void fn_R000546_4613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st_1 = {0};
  struct Vector3D_R000546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_62_1) & 63;
  aux_2 = (aux_2 + accumulator_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_62_1 == accumulator_62_2);
}

int fn_R000546_4613_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000546_4613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st_1 = {0};
  struct Vector3D_R000546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int coefficient_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_15_1 > 10)
  {
    acc_1 = ((acc_1 + (coefficient_15_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_15_2 > 10)
  {
    acc_2 = ((acc_2 + (coefficient_15_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_12_1) & 63;
  aux_2 = (aux_2 + window_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_25_1)
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

  switch (window_25_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_15_1 == coefficient_15_2);
  assert(window_12_1 == window_12_2);
  assert(window_25_1 == window_25_2);
}

int fn_R000546_4613_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int coefficient_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_15 > 10)
  {
    acc = ((acc + (coefficient_15 * 2)) + 5) & 127;
    aux ^= coefficient_15 & 15;
  }
  else
  {
    acc = ((acc - coefficient_15) + 11) & 127;
    aux += 3;
  }
  int window_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_12) & 63;
  acc ^= aux;
  int window_25 = (aux + st.buffer[1]) & 3;
  switch (window_25)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000546_4613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st_1 = {0};
  struct Vector3D_R000546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int offset_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_76_1)
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

  switch (offset_76_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_98_1 = local_arr_1[aux_1 % 3];
  int offset_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_98_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_76_1 == offset_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_98_1 == offset_98_2);
}

int fn_R000546_4613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int offset_76 = (aux + st.buffer[1]) & 3;
  switch (offset_76)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_98 = local_arr[aux % 3];
  acc = (acc + (offset_98 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000546_4613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000546_4613_2 st_1 = {0};
  struct MatrixBlock_R000546_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int phase_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_21_1) & 63;
  aux_2 = (aux_2 + phase_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_66_1 = local_arr_1[aux_1 % 3];
  int tracker_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_21_1 == phase_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_66_1 == tracker_66_2);
}

int fn_R000546_4613_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000546_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int phase_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_21) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_66 = local_arr[aux % 3];
  acc = (acc + (tracker_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000546_4613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st_1 = {0};
  struct Vector3D_R000546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_99_1 = local_arr_1[aux_1 % 3];
  int offset_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_99_2 * 2)) & 127;
  int tracker_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_32_1 > 27)
  {
    acc_1 = ((acc_1 + (tracker_32_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_32_2 > 27)
  {
    acc_2 = ((acc_2 + (tracker_32_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_12_1)
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

  switch (sample_12_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_99_1 == offset_99_2);
  assert(tracker_32_1 == tracker_32_2);
  assert(sample_12_1 == sample_12_2);
}

int fn_R000546_4613_12(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int offset_99 = local_arr[aux % 3];
  acc = (acc + (offset_99 * 2)) & 127;
  int tracker_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_32 > 27)
  {
    acc = ((acc + (tracker_32 * 2)) + 5) & 127;
    aux ^= tracker_32 & 15;
  }
  else
  {
    acc = ((acc - tracker_32) + 11) & 127;
    aux += 3;
  }
  int sample_12 = (aux + st.buffer[1]) & 3;
  switch (sample_12)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000546_4613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st_1 = {0};
  struct Vector3D_R000546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_96_1 = local_arr_1[aux_1 % 3];
  int checksum_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_96_2 * 2)) & 127;
  int stride_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_30_1)
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

  switch (stride_30_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_96_1 == checksum_96_2);
  assert(stride_30_1 == stride_30_2);
}

int fn_R000546_4613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int checksum_96 = local_arr[aux % 3];
  acc = (acc + (checksum_96 * 2)) & 127;
  int stride_30 = (aux + st.buffer[1]) & 3;
  switch (stride_30)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000546_4613_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000546_4613_0 st_1 = {0};
  struct CipherContext_R000546_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int stride_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_16_1) & 63;
  aux_2 = (aux_2 + stride_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_22_1 > 31)
  {
    acc_1 = ((acc_1 + (margin_22_1 * 2)) + 5) & 127;
    aux_1 ^= margin_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_22_2 > 31)
  {
    acc_2 = ((acc_2 + (margin_22_2 * 2)) + 5) & 127;
    aux_2 ^= margin_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_16_1 == stride_16_2);
  assert(margin_22_1 == margin_22_2);
}

int fn_R000546_4613_14(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000546_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int stride_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_16) & 63;
  acc ^= aux;
  int margin_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_22 > 31)
  {
    acc = ((acc + (margin_22 * 2)) + 5) & 127;
    aux ^= margin_22 & 15;
  }
  else
  {
    acc = ((acc - margin_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000546_4613_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000546_4613_2 st_1 = {0};
  struct MatrixBlock_R000546_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int accumulator_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_11_1) & 63;
  aux_2 = (aux_2 + accumulator_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_11_1 == accumulator_11_2);
}

int fn_R000546_4613_15(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000546_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int accumulator_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_11) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000546_4613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000546_4613_0 st_1 = {0};
  struct CipherContext_R000546_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int residue_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_91_1 > 10)
  {
    acc_1 = ((acc_1 + (residue_91_1 * 2)) + 5) & 127;
    aux_1 ^= residue_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_91_2 > 10)
  {
    acc_2 = ((acc_2 + (residue_91_2 * 2)) + 5) & 127;
    aux_2 ^= residue_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_69_1 = local_arr_1[aux_1 % 3];
  int metric_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_69_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_38_1) & 63;
  aux_2 = (aux_2 + tally_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_91_1 == residue_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_69_1 == metric_69_2);
  assert(tally_38_1 == tally_38_2);
}

int fn_R000546_4613_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000546_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int residue_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_91 > 10)
  {
    acc = ((acc + (residue_91 * 2)) + 5) & 127;
    aux ^= residue_91 & 15;
  }
  else
  {
    acc = ((acc - residue_91) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_69 = local_arr[aux % 3];
  acc = (acc + (metric_69 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000546_4613_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000546_4613_0 st_1 = {0};
  struct CipherContext_R000546_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_81_1 = local_arr_1[aux_1 % 3];
  int tracker_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_81_2 * 2)) & 127;
  int residue_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_69_1)
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

  switch (residue_69_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_81_1 == tracker_81_2);
  assert(residue_69_1 == residue_69_2);
}

int fn_R000546_4613_17(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000546_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int tracker_81 = local_arr[aux % 3];
  acc = (acc + (tracker_81 * 2)) & 127;
  int residue_69 = (aux + st.buffer[1]) & 3;
  switch (residue_69)
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
  return (acc + aux) & 255;
}

void fn_R000546_4613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000546_4613_2 st_1 = {0};
  struct MatrixBlock_R000546_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int sample_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_87_1 > 39)
  {
    acc_1 = ((acc_1 + (sample_87_1 * 2)) + 5) & 127;
    aux_1 ^= sample_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_87_2 > 39)
  {
    acc_2 = ((acc_2 + (sample_87_2 * 2)) + 5) & 127;
    aux_2 ^= sample_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_29_1 = local_arr_1[aux_1 % 3];
  int segment_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_29_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_32_1)
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

  switch (scale_32_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_87_1 == sample_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_29_1 == segment_29_2);
  assert(scale_32_1 == scale_32_2);
}

int fn_R000546_4613_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000546_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int sample_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_87 > 39)
  {
    acc = ((acc + (sample_87 * 2)) + 5) & 127;
    aux ^= sample_87 & 15;
  }
  else
  {
    acc = ((acc - sample_87) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_29 = local_arr[aux % 3];
  acc = (acc + (segment_29 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_32 = (aux + st.buffer[1]) & 3;
  switch (scale_32)
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

void main()
{
  int sec_r000546_0_1;
  int sec_r000546_0_2;
  int sec_r000546_1_1;
  int sec_r000546_1_2;
  int sec_r000546_2_1;
  int sec_r000546_2_2;
  int sec_r000546_3_1;
  int sec_r000546_3_2;
  int sec_r000546_4_1;
  int sec_r000546_4_2;
  int sec_r000546_5_1;
  int sec_r000546_5_2;
  int sec_r000546_6_1;
  int sec_r000546_6_2;
  int sec_r000546_7_1;
  int sec_r000546_7_2;
  int sec_r000546_8_1;
  int sec_r000546_8_2;
  int sec_r000546_9_1;
  int sec_r000546_9_2;
  int sec_r000546_10_1;
  int sec_r000546_10_2;
  int sec_r000546_11_1;
  int sec_r000546_11_2;
  int sec_r000546_12_1;
  int sec_r000546_12_2;
  int sec_r000546_13_1;
  int sec_r000546_13_2;
  int sec_r000546_14_1;
  int sec_r000546_14_2;
  int sec_r000546_15_1;
  int sec_r000546_15_2;
  int sec_r000546_16_1;
  int sec_r000546_16_2;
  int sec_r000546_17_1;
  int sec_r000546_17_2;
  int sec_r000546_18_1;
  int sec_r000546_18_2;
  int sec_r000546_19_1;
  int sec_r000546_19_2;
  int pub_r000546_0_1;
  int pub_r000546_0_2;
  int pub_r000546_1_1;
  int pub_r000546_1_2;
  int pub_r000546_2_1;
  int pub_r000546_2_2;
  int pub_r000546_3_1;
  int pub_r000546_3_2;
  int pub_r000546_4_1;
  int pub_r000546_4_2;
  int pub_r000546_5_1;
  int pub_r000546_5_2;
  int pub_r000546_6_1;
  int pub_r000546_6_2;
  int pub_r000546_7_1;
  int pub_r000546_7_2;
  int pub_r000546_8_1;
  int pub_r000546_8_2;
  int pub_r000546_9_1;
  int pub_r000546_9_2;
  int pub_r000546_10_1;
  int pub_r000546_10_2;
  int pub_r000546_11_1;
  int pub_r000546_11_2;
  int pub_r000546_12_1;
  int pub_r000546_12_2;
  int pub_r000546_13_1;
  int pub_r000546_13_2;
  int pub_r000546_14_1;
  int pub_r000546_14_2;
  int pub_r000546_15_1;
  int pub_r000546_15_2;
  int pub_r000546_16_1;
  int pub_r000546_16_2;
  int pub_r000546_17_1;
  int pub_r000546_17_2;
  int pub_r000546_18_1;
  int pub_r000546_18_2;
  int pub_r000546_19_1;
  int pub_r000546_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000546_0_1 >= (-100)) && (pub_r000546_0_1 <= 100));
  __CPROVER_assume((pub_r000546_0_2 >= (-100)) && (pub_r000546_0_2 <= 100));
  __CPROVER_assume((pub_r000546_1_1 >= (-100)) && (pub_r000546_1_1 <= 100));
  __CPROVER_assume((pub_r000546_1_2 >= (-100)) && (pub_r000546_1_2 <= 100));
  __CPROVER_assume((pub_r000546_2_1 >= (-100)) && (pub_r000546_2_1 <= 100));
  __CPROVER_assume((pub_r000546_2_2 >= (-100)) && (pub_r000546_2_2 <= 100));
  __CPROVER_assume((pub_r000546_3_1 >= (-100)) && (pub_r000546_3_1 <= 100));
  __CPROVER_assume((pub_r000546_3_2 >= (-100)) && (pub_r000546_3_2 <= 100));
  __CPROVER_assume((pub_r000546_4_1 >= (-100)) && (pub_r000546_4_1 <= 100));
  __CPROVER_assume((pub_r000546_4_2 >= (-100)) && (pub_r000546_4_2 <= 100));
  __CPROVER_assume((pub_r000546_5_1 >= (-100)) && (pub_r000546_5_1 <= 100));
  __CPROVER_assume((pub_r000546_5_2 >= (-100)) && (pub_r000546_5_2 <= 100));
  __CPROVER_assume((pub_r000546_6_1 >= (-100)) && (pub_r000546_6_1 <= 100));
  __CPROVER_assume((pub_r000546_6_2 >= (-100)) && (pub_r000546_6_2 <= 100));
  __CPROVER_assume((pub_r000546_7_1 >= (-100)) && (pub_r000546_7_1 <= 100));
  __CPROVER_assume((pub_r000546_7_2 >= (-100)) && (pub_r000546_7_2 <= 100));
  __CPROVER_assume((pub_r000546_8_1 >= (-100)) && (pub_r000546_8_1 <= 100));
  __CPROVER_assume((pub_r000546_8_2 >= (-100)) && (pub_r000546_8_2 <= 100));
  __CPROVER_assume((pub_r000546_9_1 >= (-100)) && (pub_r000546_9_1 <= 100));
  __CPROVER_assume((pub_r000546_9_2 >= (-100)) && (pub_r000546_9_2 <= 100));
  __CPROVER_assume((pub_r000546_10_1 >= (-100)) && (pub_r000546_10_1 <= 100));
  __CPROVER_assume((pub_r000546_10_2 >= (-100)) && (pub_r000546_10_2 <= 100));
  __CPROVER_assume((pub_r000546_11_1 >= (-100)) && (pub_r000546_11_1 <= 100));
  __CPROVER_assume((pub_r000546_11_2 >= (-100)) && (pub_r000546_11_2 <= 100));
  __CPROVER_assume((pub_r000546_12_1 >= (-100)) && (pub_r000546_12_1 <= 100));
  __CPROVER_assume((pub_r000546_12_2 >= (-100)) && (pub_r000546_12_2 <= 100));
  __CPROVER_assume((pub_r000546_13_1 >= (-100)) && (pub_r000546_13_1 <= 100));
  __CPROVER_assume((pub_r000546_13_2 >= (-100)) && (pub_r000546_13_2 <= 100));
  __CPROVER_assume((pub_r000546_14_1 >= (-100)) && (pub_r000546_14_1 <= 100));
  __CPROVER_assume((pub_r000546_14_2 >= (-100)) && (pub_r000546_14_2 <= 100));
  __CPROVER_assume((pub_r000546_15_1 >= (-100)) && (pub_r000546_15_1 <= 100));
  __CPROVER_assume((pub_r000546_15_2 >= (-100)) && (pub_r000546_15_2 <= 100));
  __CPROVER_assume((pub_r000546_16_1 >= (-100)) && (pub_r000546_16_1 <= 100));
  __CPROVER_assume((pub_r000546_16_2 >= (-100)) && (pub_r000546_16_2 <= 100));
  __CPROVER_assume((pub_r000546_17_1 >= (-100)) && (pub_r000546_17_1 <= 100));
  __CPROVER_assume((pub_r000546_17_2 >= (-100)) && (pub_r000546_17_2 <= 100));
  __CPROVER_assume((pub_r000546_18_1 >= (-100)) && (pub_r000546_18_1 <= 100));
  __CPROVER_assume((pub_r000546_18_2 >= (-100)) && (pub_r000546_18_2 <= 100));
  __CPROVER_assume((pub_r000546_19_1 >= (-100)) && (pub_r000546_19_1 <= 100));
  __CPROVER_assume((pub_r000546_19_2 >= (-100)) && (pub_r000546_19_2 <= 100));
  __CPROVER_assume((sec_r000546_0_1 >= 0) && (sec_r000546_0_1 <= 255));
  __CPROVER_assume((sec_r000546_0_2 >= 0) && (sec_r000546_0_2 <= 255));
  __CPROVER_assume((sec_r000546_1_1 >= 0) && (sec_r000546_1_1 <= 255));
  __CPROVER_assume((sec_r000546_1_2 >= 0) && (sec_r000546_1_2 <= 255));
  __CPROVER_assume((sec_r000546_2_1 >= 0) && (sec_r000546_2_1 <= 255));
  __CPROVER_assume((sec_r000546_2_2 >= 0) && (sec_r000546_2_2 <= 255));
  __CPROVER_assume((sec_r000546_3_1 >= 0) && (sec_r000546_3_1 <= 255));
  __CPROVER_assume((sec_r000546_3_2 >= 0) && (sec_r000546_3_2 <= 255));
  __CPROVER_assume((sec_r000546_4_1 >= 0) && (sec_r000546_4_1 <= 255));
  __CPROVER_assume((sec_r000546_4_2 >= 0) && (sec_r000546_4_2 <= 255));
  __CPROVER_assume((sec_r000546_5_1 >= 0) && (sec_r000546_5_1 <= 255));
  __CPROVER_assume((sec_r000546_5_2 >= 0) && (sec_r000546_5_2 <= 255));
  __CPROVER_assume((sec_r000546_6_1 >= 0) && (sec_r000546_6_1 <= 255));
  __CPROVER_assume((sec_r000546_6_2 >= 0) && (sec_r000546_6_2 <= 255));
  __CPROVER_assume((sec_r000546_7_1 >= 0) && (sec_r000546_7_1 <= 255));
  __CPROVER_assume((sec_r000546_7_2 >= 0) && (sec_r000546_7_2 <= 255));
  __CPROVER_assume((sec_r000546_8_1 >= 0) && (sec_r000546_8_1 <= 255));
  __CPROVER_assume((sec_r000546_8_2 >= 0) && (sec_r000546_8_2 <= 255));
  __CPROVER_assume((sec_r000546_9_1 >= 0) && (sec_r000546_9_1 <= 255));
  __CPROVER_assume((sec_r000546_9_2 >= 0) && (sec_r000546_9_2 <= 255));
  __CPROVER_assume((sec_r000546_10_1 >= 0) && (sec_r000546_10_1 <= 255));
  __CPROVER_assume((sec_r000546_10_2 >= 0) && (sec_r000546_10_2 <= 255));
  __CPROVER_assume((sec_r000546_11_1 >= 0) && (sec_r000546_11_1 <= 255));
  __CPROVER_assume((sec_r000546_11_2 >= 0) && (sec_r000546_11_2 <= 255));
  __CPROVER_assume((sec_r000546_12_1 >= 0) && (sec_r000546_12_1 <= 255));
  __CPROVER_assume((sec_r000546_12_2 >= 0) && (sec_r000546_12_2 <= 255));
  __CPROVER_assume((sec_r000546_13_1 >= 0) && (sec_r000546_13_1 <= 255));
  __CPROVER_assume((sec_r000546_13_2 >= 0) && (sec_r000546_13_2 <= 255));
  __CPROVER_assume((sec_r000546_14_1 >= 0) && (sec_r000546_14_1 <= 255));
  __CPROVER_assume((sec_r000546_14_2 >= 0) && (sec_r000546_14_2 <= 255));
  __CPROVER_assume((sec_r000546_15_1 >= 0) && (sec_r000546_15_1 <= 255));
  __CPROVER_assume((sec_r000546_15_2 >= 0) && (sec_r000546_15_2 <= 255));
  __CPROVER_assume((sec_r000546_16_1 >= 0) && (sec_r000546_16_1 <= 255));
  __CPROVER_assume((sec_r000546_16_2 >= 0) && (sec_r000546_16_2 <= 255));
  __CPROVER_assume((sec_r000546_17_1 >= 0) && (sec_r000546_17_1 <= 255));
  __CPROVER_assume((sec_r000546_17_2 >= 0) && (sec_r000546_17_2 <= 255));
  __CPROVER_assume((sec_r000546_18_1 >= 0) && (sec_r000546_18_1 <= 255));
  __CPROVER_assume((sec_r000546_18_2 >= 0) && (sec_r000546_18_2 <= 255));
  __CPROVER_assume((sec_r000546_19_1 >= 0) && (sec_r000546_19_1 <= 255));
  __CPROVER_assume((sec_r000546_19_2 >= 0) && (sec_r000546_19_2 <= 255));
  struct CipherContext_R000546_4613_0 st_var_0_1 = {0};
  struct CipherContext_R000546_4613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000546_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000546_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000546_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000546_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000546_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000546_0_2 + 7) & 15;
  struct Vector3D_R000546_4613_1 st_var_1_1 = {0};
  struct Vector3D_R000546_4613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000546_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000546_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000546_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000546_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000546_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000546_0_2 + 9) & 15;
  struct MatrixBlock_R000546_4613_2 st_var_2_1 = {0};
  struct MatrixBlock_R000546_4613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000546_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000546_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000546_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000546_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000546_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000546_0_2 + 11) & 15;
  union ColorPixel_R000546_4613_0 u_var_1;
  union ColorPixel_R000546_4613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = table_1[0];
  int stage_v_0_2 = table_2[0];
  table_1[0] = (table_1[1] + 1) & 63;
  table_2[0] = (table_2[1] + 1) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 8) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 9) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
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
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 12) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  if ((sec_r000546_5_1 & 63) > 33)
  {
    stage_v_12_1 = ((pub_r000546_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  }
  else
  {
    stage_v_12_1 = ((pub_r000546_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
  }
  if ((sec_r000546_5_2 & 63) > 33)
  {
    stage_v_12_2 = ((pub_r000546_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  }
  else
  {
    stage_v_12_2 = ((pub_r000546_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  if ((sec_r000546_17_1 & 63) > 50)
  {
    stage_v_13_1 = ((pub_r000546_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  }
  else
  {
    stage_v_13_1 = ((pub_r000546_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
  }
  if ((sec_r000546_17_2 & 63) > 50)
  {
    stage_v_13_2 = ((pub_r000546_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  }
  else
  {
    stage_v_13_2 = ((pub_r000546_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  if ((stage_v_13_1 & 63) > 48)
  {
    stage_v_14_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  }
  else
  {
    stage_v_14_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
  }
  if ((stage_v_13_2 & 63) > 48)
  {
    stage_v_14_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  }
  else
  {
    stage_v_14_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  if ((stage_v_13_1 & 63) > 37)
  {
    stage_v_15_1 = ((pub_r000546_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  }
  else
  {
    stage_v_15_1 = ((pub_r000546_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
  }
  if ((stage_v_13_2 & 63) > 37)
  {
    stage_v_15_2 = ((pub_r000546_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  }
  else
  {
    stage_v_15_2 = ((pub_r000546_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  if ((sec_r000546_16_1 & 63) > 45)
  {
    stage_v_16_1 = ((pub_r000546_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  }
  else
  {
    stage_v_16_1 = ((pub_r000546_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
  }
  if ((sec_r000546_16_2 & 63) > 45)
  {
    stage_v_16_2 = ((pub_r000546_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  }
  else
  {
    stage_v_16_2 = ((pub_r000546_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  if ((stage_v_13_1 & 63) > 40)
  {
    stage_v_17_1 = ((pub_r000546_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  }
  else
  {
    stage_v_17_1 = ((pub_r000546_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
  }
  if ((stage_v_13_2 & 63) > 40)
  {
    stage_v_17_2 = ((pub_r000546_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  }
  else
  {
    stage_v_17_2 = ((pub_r000546_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  if ((stage_v_13_1 & 63) > 17)
  {
    stage_v_18_1 = ((pub_r000546_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  }
  else
  {
    stage_v_18_1 = ((pub_r000546_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
  }
  if ((stage_v_13_2 & 63) > 17)
  {
    stage_v_18_2 = ((pub_r000546_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  }
  else
  {
    stage_v_18_2 = ((pub_r000546_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  if ((stage_v_17_1 & 63) > 17)
  {
    stage_v_19_1 = ((pub_r000546_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  }
  else
  {
    stage_v_19_1 = ((pub_r000546_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
  }
  if ((stage_v_17_2 & 63) > 17)
  {
    stage_v_19_2 = ((pub_r000546_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  }
  else
  {
    stage_v_19_2 = ((pub_r000546_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  if ((stage_v_16_1 & 63) > 54)
  {
    stage_v_20_1 = ((pub_r000546_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  }
  else
  {
    stage_v_20_1 = ((pub_r000546_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
  }
  if ((stage_v_16_2 & 63) > 54)
  {
    stage_v_20_2 = ((pub_r000546_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  }
  else
  {
    stage_v_20_2 = ((pub_r000546_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  if ((stage_v_16_1 & 63) > 15)
  {
    stage_v_21_1 = ((pub_r000546_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  }
  else
  {
    stage_v_21_1 = ((pub_r000546_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
  }
  if ((stage_v_16_2 & 63) > 15)
  {
    stage_v_21_2 = ((pub_r000546_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  }
  else
  {
    stage_v_21_2 = ((pub_r000546_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  if ((sec_r000546_8_1 & 63) > 36)
  {
    stage_v_22_1 = ((pub_r000546_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  }
  else
  {
    stage_v_22_1 = ((pub_r000546_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
  }
  if ((sec_r000546_8_2 & 63) > 36)
  {
    stage_v_22_2 = ((pub_r000546_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  }
  else
  {
    stage_v_22_2 = ((pub_r000546_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  if ((stage_v_21_1 & 63) > 34)
  {
    stage_v_23_1 = ((pub_r000546_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  }
  else
  {
    stage_v_23_1 = ((pub_r000546_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
  }
  if ((stage_v_21_2 & 63) > 34)
  {
    stage_v_23_2 = ((pub_r000546_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  }
  else
  {
    stage_v_23_2 = ((pub_r000546_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  if ((sec_r000546_2_1 & 63) > 50)
  {
    stage_v_24_1 = ((pub_r000546_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  }
  else
  {
    stage_v_24_1 = ((pub_r000546_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
  }
  if ((sec_r000546_2_2 & 63) > 50)
  {
    stage_v_24_2 = ((pub_r000546_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  }
  else
  {
    stage_v_24_2 = ((pub_r000546_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((stage_v_24_1 & 63) > 22)
  {
    stage_v_25_1 = ((pub_r000546_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  }
  else
  {
    stage_v_25_1 = ((pub_r000546_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
  }
  if ((stage_v_24_2 & 63) > 22)
  {
    stage_v_25_2 = ((pub_r000546_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  }
  else
  {
    stage_v_25_2 = ((pub_r000546_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((sec_r000546_13_1 & 63) > 51)
  {
    stage_v_26_1 = ((pub_r000546_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  }
  else
  {
    stage_v_26_1 = ((pub_r000546_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
  }
  if ((sec_r000546_13_2 & 63) > 51)
  {
    stage_v_26_2 = ((pub_r000546_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  }
  else
  {
    stage_v_26_2 = ((pub_r000546_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((stage_v_21_1 & 63) > 40)
  {
    stage_v_27_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  }
  else
  {
    stage_v_27_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
  }
  if ((stage_v_21_2 & 63) > 40)
  {
    stage_v_27_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  }
  else
  {
    stage_v_27_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((sec_r000546_8_1 & 63) > 31)
  {
    stage_v_28_1 = ((pub_r000546_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  }
  else
  {
    stage_v_28_1 = ((pub_r000546_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
  }
  if ((sec_r000546_8_2 & 63) > 31)
  {
    stage_v_28_2 = ((pub_r000546_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  }
  else
  {
    stage_v_28_2 = ((pub_r000546_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((sec_r000546_10_1 & 63) > 35)
  {
    stage_v_29_1 = ((pub_r000546_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  }
  else
  {
    stage_v_29_1 = ((pub_r000546_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
  }
  if ((sec_r000546_10_2 & 63) > 35)
  {
    stage_v_29_2 = ((pub_r000546_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  }
  else
  {
    stage_v_29_2 = ((pub_r000546_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((stage_v_29_1 & 63) > 58)
  {
    stage_v_30_1 = ((pub_r000546_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  }
  else
  {
    stage_v_30_1 = ((pub_r000546_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
  }
  if ((stage_v_29_2 & 63) > 58)
  {
    stage_v_30_2 = ((pub_r000546_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  }
  else
  {
    stage_v_30_2 = ((pub_r000546_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((stage_v_21_1 & 63) > 40)
  {
    stage_v_31_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  }
  else
  {
    stage_v_31_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
  }
  if ((stage_v_21_2 & 63) > 40)
  {
    stage_v_31_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  }
  else
  {
    stage_v_31_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((stage_v_31_1 & 63) > 49)
  {
    stage_v_32_1 = ((pub_r000546_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  }
  else
  {
    stage_v_32_1 = ((pub_r000546_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
  }
  if ((stage_v_31_2 & 63) > 49)
  {
    stage_v_32_2 = ((pub_r000546_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  }
  else
  {
    stage_v_32_2 = ((pub_r000546_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((sec_r000546_11_1 & 63) > 42)
  {
    stage_v_33_1 = ((pub_r000546_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  }
  else
  {
    stage_v_33_1 = ((pub_r000546_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
  }
  if ((sec_r000546_11_2 & 63) > 42)
  {
    stage_v_33_2 = ((pub_r000546_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  }
  else
  {
    stage_v_33_2 = ((pub_r000546_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((stage_v_13_1 & 63) > 40)
  {
    stage_v_34_1 = ((pub_r000546_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  }
  else
  {
    stage_v_34_1 = ((pub_r000546_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
  }
  if ((stage_v_13_2 & 63) > 40)
  {
    stage_v_34_2 = ((pub_r000546_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  }
  else
  {
    stage_v_34_2 = ((pub_r000546_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((stage_v_24_1 & 63) > 15)
  {
    stage_v_35_1 = ((pub_r000546_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  }
  else
  {
    stage_v_35_1 = ((pub_r000546_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
  }
  if ((stage_v_24_2 & 63) > 15)
  {
    stage_v_35_2 = ((pub_r000546_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  }
  else
  {
    stage_v_35_2 = ((pub_r000546_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((sec_r000546_11_1 & 63) > 59)
  {
    stage_v_36_1 = ((pub_r000546_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  }
  else
  {
    stage_v_36_1 = ((pub_r000546_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
  }
  if ((sec_r000546_11_2 & 63) > 59)
  {
    stage_v_36_2 = ((pub_r000546_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  }
  else
  {
    stage_v_36_2 = ((pub_r000546_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((sec_r000546_16_1 & 63) > 47)
  {
    stage_v_37_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  }
  else
  {
    stage_v_37_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
  }
  if ((sec_r000546_16_2 & 63) > 47)
  {
    stage_v_37_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  }
  else
  {
    stage_v_37_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((sec_r000546_0_1 & 63) > 29)
  {
    stage_v_38_1 = ((pub_r000546_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  }
  else
  {
    stage_v_38_1 = ((pub_r000546_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
  }
  if ((sec_r000546_0_2 & 63) > 29)
  {
    stage_v_38_2 = ((pub_r000546_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  }
  else
  {
    stage_v_38_2 = ((pub_r000546_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_33_1 & 63) > 32)
  {
    stage_v_39_1 = ((pub_r000546_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  }
  else
  {
    stage_v_39_1 = ((pub_r000546_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
  }
  if ((stage_v_33_2 & 63) > 32)
  {
    stage_v_39_2 = ((pub_r000546_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  }
  else
  {
    stage_v_39_2 = ((pub_r000546_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((sec_r000546_7_1 & 63) > 39)
  {
    stage_v_40_1 = ((pub_r000546_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  }
  else
  {
    stage_v_40_1 = ((pub_r000546_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
  }
  if ((sec_r000546_7_2 & 63) > 39)
  {
    stage_v_40_2 = ((pub_r000546_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  }
  else
  {
    stage_v_40_2 = ((pub_r000546_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((sec_r000546_1_1 & 63) > 37)
  {
    stage_v_41_1 = ((pub_r000546_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  }
  else
  {
    stage_v_41_1 = ((pub_r000546_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
  }
  if ((sec_r000546_1_2 & 63) > 37)
  {
    stage_v_41_2 = ((pub_r000546_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  }
  else
  {
    stage_v_41_2 = ((pub_r000546_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((sec_r000546_17_1 & 63) > 34)
  {
    stage_v_42_1 = ((pub_r000546_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  }
  else
  {
    stage_v_42_1 = ((pub_r000546_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
  }
  if ((sec_r000546_17_2 & 63) > 34)
  {
    stage_v_42_2 = ((pub_r000546_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  }
  else
  {
    stage_v_42_2 = ((pub_r000546_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_17_1 & 63) > 17)
  {
    stage_v_43_1 = ((pub_r000546_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  }
  else
  {
    stage_v_43_1 = ((pub_r000546_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
  }
  if ((stage_v_17_2 & 63) > 17)
  {
    stage_v_43_2 = ((pub_r000546_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  }
  else
  {
    stage_v_43_2 = ((pub_r000546_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_34_1 & 63) > 32)
  {
    stage_v_44_1 = ((pub_r000546_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  }
  else
  {
    stage_v_44_1 = ((pub_r000546_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
  }
  if ((stage_v_34_2 & 63) > 32)
  {
    stage_v_44_2 = ((pub_r000546_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  }
  else
  {
    stage_v_44_2 = ((pub_r000546_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_41_1 & 63) > 41)
  {
    stage_v_45_1 = ((pub_r000546_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  }
  else
  {
    stage_v_45_1 = ((pub_r000546_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
  }
  if ((stage_v_41_2 & 63) > 41)
  {
    stage_v_45_2 = ((pub_r000546_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  }
  else
  {
    stage_v_45_2 = ((pub_r000546_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_43_1 & 63) > 55)
  {
    stage_v_46_1 = ((pub_r000546_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  }
  else
  {
    stage_v_46_1 = ((pub_r000546_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
  }
  if ((stage_v_43_2 & 63) > 55)
  {
    stage_v_46_2 = ((pub_r000546_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  }
  else
  {
    stage_v_46_2 = ((pub_r000546_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_37_1 & 63) > 45)
  {
    stage_v_47_1 = ((pub_r000546_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  }
  else
  {
    stage_v_47_1 = ((pub_r000546_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
  }
  if ((stage_v_37_2 & 63) > 45)
  {
    stage_v_47_2 = ((pub_r000546_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  }
  else
  {
    stage_v_47_2 = ((pub_r000546_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_44_1 & 63) > 44)
  {
    stage_v_48_1 = ((pub_r000546_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  }
  else
  {
    stage_v_48_1 = ((pub_r000546_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
  }
  if ((stage_v_44_2 & 63) > 44)
  {
    stage_v_48_2 = ((pub_r000546_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  }
  else
  {
    stage_v_48_2 = ((pub_r000546_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_23_1 & 63) > 26)
  {
    stage_v_49_1 = ((pub_r000546_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  }
  else
  {
    stage_v_49_1 = ((pub_r000546_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
  }
  if ((stage_v_23_2 & 63) > 26)
  {
    stage_v_49_2 = ((pub_r000546_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  }
  else
  {
    stage_v_49_2 = ((pub_r000546_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((sec_r000546_15_1 & 63) > 22)
  {
    stage_v_50_1 = ((pub_r000546_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  }
  else
  {
    stage_v_50_1 = ((pub_r000546_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
  }
  if ((sec_r000546_15_2 & 63) > 22)
  {
    stage_v_50_2 = ((pub_r000546_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  }
  else
  {
    stage_v_50_2 = ((pub_r000546_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_44_1 & 63) > 17)
  {
    stage_v_51_1 = ((pub_r000546_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  }
  else
  {
    stage_v_51_1 = ((pub_r000546_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
  }
  if ((stage_v_44_2 & 63) > 17)
  {
    stage_v_51_2 = ((pub_r000546_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  }
  else
  {
    stage_v_51_2 = ((pub_r000546_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_37_1 & 63) > 49)
  {
    stage_v_52_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  }
  else
  {
    stage_v_52_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
  }
  if ((stage_v_37_2 & 63) > 49)
  {
    stage_v_52_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  }
  else
  {
    stage_v_52_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_45_1 & 63) > 21)
  {
    stage_v_53_1 = ((pub_r000546_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  }
  else
  {
    stage_v_53_1 = ((pub_r000546_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
  }
  if ((stage_v_45_2 & 63) > 21)
  {
    stage_v_53_2 = ((pub_r000546_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  }
  else
  {
    stage_v_53_2 = ((pub_r000546_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_22_1 & 63) > 42)
  {
    stage_v_54_1 = ((pub_r000546_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  }
  else
  {
    stage_v_54_1 = ((pub_r000546_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
  }
  if ((stage_v_22_2 & 63) > 42)
  {
    stage_v_54_2 = ((pub_r000546_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  }
  else
  {
    stage_v_54_2 = ((pub_r000546_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_46_1 & 63) > 42)
  {
    stage_v_55_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  }
  else
  {
    stage_v_55_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
  }
  if ((stage_v_46_2 & 63) > 42)
  {
    stage_v_55_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  }
  else
  {
    stage_v_55_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((sec_r000546_14_1 & 63) > 50)
  {
    stage_v_56_1 = ((pub_r000546_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  }
  else
  {
    stage_v_56_1 = ((pub_r000546_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
  }
  if ((sec_r000546_14_2 & 63) > 50)
  {
    stage_v_56_2 = ((pub_r000546_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  }
  else
  {
    stage_v_56_2 = ((pub_r000546_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_36_1 & 63) > 54)
  {
    stage_v_57_1 = ((pub_r000546_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  }
  else
  {
    stage_v_57_1 = ((pub_r000546_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
  }
  if ((stage_v_36_2 & 63) > 54)
  {
    stage_v_57_2 = ((pub_r000546_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  }
  else
  {
    stage_v_57_2 = ((pub_r000546_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000546_16_1 & 63) > 26)
  {
    stage_v_58_1 = ((pub_r000546_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  }
  else
  {
    stage_v_58_1 = ((pub_r000546_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
  }
  if ((sec_r000546_16_2 & 63) > 26)
  {
    stage_v_58_2 = ((pub_r000546_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  }
  else
  {
    stage_v_58_2 = ((pub_r000546_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((sec_r000546_12_1 & 63) > 19)
  {
    stage_v_59_1 = ((pub_r000546_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  }
  else
  {
    stage_v_59_1 = ((pub_r000546_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
  }
  if ((sec_r000546_12_2 & 63) > 19)
  {
    stage_v_59_2 = ((pub_r000546_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  }
  else
  {
    stage_v_59_2 = ((pub_r000546_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000546_5_1 & 63) > 47)
  {
    stage_v_60_1 = ((pub_r000546_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  }
  else
  {
    stage_v_60_1 = ((pub_r000546_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
  }
  if ((sec_r000546_5_2 & 63) > 47)
  {
    stage_v_60_2 = ((pub_r000546_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  }
  else
  {
    stage_v_60_2 = ((pub_r000546_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_14_1 & 63) > 32)
  {
    stage_v_61_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  }
  else
  {
    stage_v_61_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
  }
  if ((stage_v_14_2 & 63) > 32)
  {
    stage_v_61_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  }
  else
  {
    stage_v_61_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000546_18_1 & 63) > 53)
  {
    stage_v_62_1 = ((pub_r000546_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  }
  else
  {
    stage_v_62_1 = ((pub_r000546_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
  }
  if ((sec_r000546_18_2 & 63) > 53)
  {
    stage_v_62_2 = ((pub_r000546_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  }
  else
  {
    stage_v_62_2 = ((pub_r000546_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_31_1 & 63) > 38)
  {
    stage_v_63_1 = ((pub_r000546_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  }
  else
  {
    stage_v_63_1 = ((pub_r000546_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
  }
  if ((stage_v_31_2 & 63) > 38)
  {
    stage_v_63_2 = ((pub_r000546_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  }
  else
  {
    stage_v_63_2 = ((pub_r000546_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000546_11_1 & 63) > 31)
  {
    stage_v_64_1 = ((pub_r000546_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  }
  else
  {
    stage_v_64_1 = ((pub_r000546_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
  }
  if ((sec_r000546_11_2 & 63) > 31)
  {
    stage_v_64_2 = ((pub_r000546_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  }
  else
  {
    stage_v_64_2 = ((pub_r000546_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_37_1 & 63) > 47)
  {
    stage_v_65_1 = ((pub_r000546_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  }
  else
  {
    stage_v_65_1 = ((pub_r000546_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
  }
  if ((stage_v_37_2 & 63) > 47)
  {
    stage_v_65_2 = ((pub_r000546_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  }
  else
  {
    stage_v_65_2 = ((pub_r000546_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_17_1 & 63) > 15)
  {
    stage_v_66_1 = ((pub_r000546_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  }
  else
  {
    stage_v_66_1 = ((pub_r000546_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
  }
  if ((stage_v_17_2 & 63) > 15)
  {
    stage_v_66_2 = ((pub_r000546_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  }
  else
  {
    stage_v_66_2 = ((pub_r000546_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000546_4_1 & 63) > 40)
  {
    stage_v_67_1 = ((pub_r000546_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  }
  else
  {
    stage_v_67_1 = ((pub_r000546_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
  }
  if ((sec_r000546_4_2 & 63) > 40)
  {
    stage_v_67_2 = ((pub_r000546_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  }
  else
  {
    stage_v_67_2 = ((pub_r000546_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_25_1 & 63) > 21)
  {
    stage_v_68_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  }
  else
  {
    stage_v_68_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
  }
  if ((stage_v_25_2 & 63) > 21)
  {
    stage_v_68_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  }
  else
  {
    stage_v_68_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_55_1 & 63) > 50)
  {
    stage_v_69_1 = ((pub_r000546_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  }
  else
  {
    stage_v_69_1 = ((pub_r000546_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
  }
  if ((stage_v_55_2 & 63) > 50)
  {
    stage_v_69_2 = ((pub_r000546_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  }
  else
  {
    stage_v_69_2 = ((pub_r000546_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_18_1 & 63) > 33)
  {
    stage_v_70_1 = ((pub_r000546_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  }
  else
  {
    stage_v_70_1 = ((pub_r000546_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
  }
  if ((stage_v_18_2 & 63) > 33)
  {
    stage_v_70_2 = ((pub_r000546_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  }
  else
  {
    stage_v_70_2 = ((pub_r000546_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_25_1 & 63) > 17)
  {
    stage_v_71_1 = ((pub_r000546_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  }
  else
  {
    stage_v_71_1 = ((pub_r000546_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
  }
  if ((stage_v_25_2 & 63) > 17)
  {
    stage_v_71_2 = ((pub_r000546_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  }
  else
  {
    stage_v_71_2 = ((pub_r000546_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_38_1 & 63) > 34)
  {
    stage_v_72_1 = ((pub_r000546_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  }
  else
  {
    stage_v_72_1 = ((pub_r000546_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
  }
  if ((stage_v_38_2 & 63) > 34)
  {
    stage_v_72_2 = ((pub_r000546_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  }
  else
  {
    stage_v_72_2 = ((pub_r000546_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_69_1 & 63) > 17)
  {
    stage_v_73_1 = ((pub_r000546_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  }
  else
  {
    stage_v_73_1 = ((pub_r000546_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
  }
  if ((stage_v_69_2 & 63) > 17)
  {
    stage_v_73_2 = ((pub_r000546_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  }
  else
  {
    stage_v_73_2 = ((pub_r000546_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_28_1 & 63) > 15)
  {
    stage_v_74_1 = ((pub_r000546_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  }
  else
  {
    stage_v_74_1 = ((pub_r000546_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
  }
  if ((stage_v_28_2 & 63) > 15)
  {
    stage_v_74_2 = ((pub_r000546_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  }
  else
  {
    stage_v_74_2 = ((pub_r000546_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_15_1 & 63) > 56)
  {
    stage_v_75_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  }
  else
  {
    stage_v_75_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
  }
  if ((stage_v_15_2 & 63) > 56)
  {
    stage_v_75_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  }
  else
  {
    stage_v_75_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_30_1 & 63) > 42)
  {
    stage_v_76_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  }
  else
  {
    stage_v_76_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
  }
  if ((stage_v_30_2 & 63) > 42)
  {
    stage_v_76_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  }
  else
  {
    stage_v_76_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_38_1 & 63) > 24)
  {
    stage_v_77_1 = ((pub_r000546_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  }
  else
  {
    stage_v_77_1 = ((pub_r000546_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
  }
  if ((stage_v_38_2 & 63) > 24)
  {
    stage_v_77_2 = ((pub_r000546_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  }
  else
  {
    stage_v_77_2 = ((pub_r000546_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_73_1 & 63) > 46)
  {
    stage_v_78_1 = ((pub_r000546_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  }
  else
  {
    stage_v_78_1 = ((pub_r000546_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
  }
  if ((stage_v_73_2 & 63) > 46)
  {
    stage_v_78_2 = ((pub_r000546_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  }
  else
  {
    stage_v_78_2 = ((pub_r000546_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_55_1 & 63) > 51)
  {
    stage_v_79_1 = ((pub_r000546_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  }
  else
  {
    stage_v_79_1 = ((pub_r000546_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
  }
  if ((stage_v_55_2 & 63) > 51)
  {
    stage_v_79_2 = ((pub_r000546_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  }
  else
  {
    stage_v_79_2 = ((pub_r000546_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_54_1 & 63) > 57)
  {
    stage_v_80_1 = ((pub_r000546_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  }
  else
  {
    stage_v_80_1 = ((pub_r000546_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
  }
  if ((stage_v_54_2 & 63) > 57)
  {
    stage_v_80_2 = ((pub_r000546_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  }
  else
  {
    stage_v_80_2 = ((pub_r000546_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_12_1 & 63) > 29)
  {
    stage_v_81_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  }
  else
  {
    stage_v_81_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
  }
  if ((stage_v_12_2 & 63) > 29)
  {
    stage_v_81_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  }
  else
  {
    stage_v_81_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000546_9_1 & 63) > 40)
  {
    stage_v_82_1 = ((pub_r000546_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  }
  else
  {
    stage_v_82_1 = ((pub_r000546_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
  }
  if ((sec_r000546_9_2 & 63) > 40)
  {
    stage_v_82_2 = ((pub_r000546_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  }
  else
  {
    stage_v_82_2 = ((pub_r000546_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_30_1 & 63) > 37)
  {
    stage_v_83_1 = ((pub_r000546_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  }
  else
  {
    stage_v_83_1 = ((pub_r000546_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
  }
  if ((stage_v_30_2 & 63) > 37)
  {
    stage_v_83_2 = ((pub_r000546_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  }
  else
  {
    stage_v_83_2 = ((pub_r000546_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_77_1 & 63) > 40)
  {
    stage_v_84_1 = ((pub_r000546_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  }
  else
  {
    stage_v_84_1 = ((pub_r000546_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
  }
  if ((stage_v_77_2 & 63) > 40)
  {
    stage_v_84_2 = ((pub_r000546_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  }
  else
  {
    stage_v_84_2 = ((pub_r000546_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_39_1 & 63) > 39)
  {
    stage_v_85_1 = ((pub_r000546_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  }
  else
  {
    stage_v_85_1 = ((pub_r000546_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
  }
  if ((stage_v_39_2 & 63) > 39)
  {
    stage_v_85_2 = ((pub_r000546_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  }
  else
  {
    stage_v_85_2 = ((pub_r000546_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_60_1 & 63) > 48)
  {
    stage_v_86_1 = ((pub_r000546_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  }
  else
  {
    stage_v_86_1 = ((pub_r000546_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
  }
  if ((stage_v_60_2 & 63) > 48)
  {
    stage_v_86_2 = ((pub_r000546_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  }
  else
  {
    stage_v_86_2 = ((pub_r000546_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_34_1 & 63) > 49)
  {
    stage_v_87_1 = ((pub_r000546_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  }
  else
  {
    stage_v_87_1 = ((pub_r000546_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
  }
  if ((stage_v_34_2 & 63) > 49)
  {
    stage_v_87_2 = ((pub_r000546_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  }
  else
  {
    stage_v_87_2 = ((pub_r000546_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_86_1 & 63) > 39)
  {
    stage_v_88_1 = ((pub_r000546_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  }
  else
  {
    stage_v_88_1 = ((pub_r000546_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
  }
  if ((stage_v_86_2 & 63) > 39)
  {
    stage_v_88_2 = ((pub_r000546_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  }
  else
  {
    stage_v_88_2 = ((pub_r000546_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000546_18_1 & 63) > 55)
  {
    stage_v_89_1 = ((pub_r000546_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  }
  else
  {
    stage_v_89_1 = ((pub_r000546_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
  }
  if ((sec_r000546_18_2 & 63) > 55)
  {
    stage_v_89_2 = ((pub_r000546_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  }
  else
  {
    stage_v_89_2 = ((pub_r000546_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_47_1 & 63) > 26)
  {
    stage_v_90_1 = ((pub_r000546_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  }
  else
  {
    stage_v_90_1 = ((pub_r000546_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
  }
  if ((stage_v_47_2 & 63) > 26)
  {
    stage_v_90_2 = ((pub_r000546_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  }
  else
  {
    stage_v_90_2 = ((pub_r000546_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_48_1 & 63) > 18)
  {
    stage_v_91_1 = ((pub_r000546_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  }
  else
  {
    stage_v_91_1 = ((pub_r000546_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
  }
  if ((stage_v_48_2 & 63) > 18)
  {
    stage_v_91_2 = ((pub_r000546_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  }
  else
  {
    stage_v_91_2 = ((pub_r000546_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_54_1 & 63) > 16)
  {
    stage_v_92_1 = ((pub_r000546_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  }
  else
  {
    stage_v_92_1 = ((pub_r000546_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
  }
  if ((stage_v_54_2 & 63) > 16)
  {
    stage_v_92_2 = ((pub_r000546_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  }
  else
  {
    stage_v_92_2 = ((pub_r000546_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000546_18_1 & 63) > 49)
  {
    stage_v_93_1 = ((pub_r000546_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  }
  else
  {
    stage_v_93_1 = ((pub_r000546_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
  }
  if ((sec_r000546_18_2 & 63) > 49)
  {
    stage_v_93_2 = ((pub_r000546_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  }
  else
  {
    stage_v_93_2 = ((pub_r000546_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000546_11_1 & 63) > 45)
  {
    stage_v_94_1 = ((pub_r000546_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  }
  else
  {
    stage_v_94_1 = ((pub_r000546_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
  }
  if ((sec_r000546_11_2 & 63) > 45)
  {
    stage_v_94_2 = ((pub_r000546_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  }
  else
  {
    stage_v_94_2 = ((pub_r000546_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_65_1 & 63) > 19)
  {
    stage_v_95_1 = ((pub_r000546_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  }
  else
  {
    stage_v_95_1 = ((pub_r000546_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
  }
  if ((stage_v_65_2 & 63) > 19)
  {
    stage_v_95_2 = ((pub_r000546_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  }
  else
  {
    stage_v_95_2 = ((pub_r000546_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_35_1 & 63) > 25)
  {
    stage_v_96_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  }
  else
  {
    stage_v_96_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
  }
  if ((stage_v_35_2 & 63) > 25)
  {
    stage_v_96_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  }
  else
  {
    stage_v_96_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_78_1 & 63) > 50)
  {
    stage_v_97_1 = ((pub_r000546_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  }
  else
  {
    stage_v_97_1 = ((pub_r000546_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
  }
  if ((stage_v_78_2 & 63) > 50)
  {
    stage_v_97_2 = ((pub_r000546_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  }
  else
  {
    stage_v_97_2 = ((pub_r000546_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000546_11_1 & 63) > 20)
  {
    stage_v_98_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  }
  else
  {
    stage_v_98_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
  }
  if ((sec_r000546_11_2 & 63) > 20)
  {
    stage_v_98_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  }
  else
  {
    stage_v_98_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_42_1 & 63) > 59)
  {
    stage_v_99_1 = ((pub_r000546_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  }
  else
  {
    stage_v_99_1 = ((pub_r000546_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
  }
  if ((stage_v_42_2 & 63) > 59)
  {
    stage_v_99_2 = ((pub_r000546_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  }
  else
  {
    stage_v_99_2 = ((pub_r000546_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_23_1 & 63) > 22)
  {
    stage_v_100_1 = ((pub_r000546_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  }
  else
  {
    stage_v_100_1 = ((pub_r000546_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
  }
  if ((stage_v_23_2 & 63) > 22)
  {
    stage_v_100_2 = ((pub_r000546_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  }
  else
  {
    stage_v_100_2 = ((pub_r000546_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_69_1 & 63) > 44)
  {
    stage_v_101_1 = ((pub_r000546_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  }
  else
  {
    stage_v_101_1 = ((pub_r000546_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
  }
  if ((stage_v_69_2 & 63) > 44)
  {
    stage_v_101_2 = ((pub_r000546_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  }
  else
  {
    stage_v_101_2 = ((pub_r000546_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000546_17_1 & 63) > 39)
  {
    stage_v_102_1 = ((pub_r000546_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  }
  else
  {
    stage_v_102_1 = ((pub_r000546_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
  }
  if ((sec_r000546_17_2 & 63) > 39)
  {
    stage_v_102_2 = ((pub_r000546_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  }
  else
  {
    stage_v_102_2 = ((pub_r000546_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_27_1 & 63) > 26)
  {
    stage_v_103_1 = ((pub_r000546_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  }
  else
  {
    stage_v_103_1 = ((pub_r000546_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
  }
  if ((stage_v_27_2 & 63) > 26)
  {
    stage_v_103_2 = ((pub_r000546_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  }
  else
  {
    stage_v_103_2 = ((pub_r000546_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000546_0_1 & 63) > 17)
  {
    stage_v_104_1 = ((pub_r000546_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  }
  else
  {
    stage_v_104_1 = ((pub_r000546_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
  }
  if ((sec_r000546_0_2 & 63) > 17)
  {
    stage_v_104_2 = ((pub_r000546_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  }
  else
  {
    stage_v_104_2 = ((pub_r000546_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000546_0_1 & 63) > 26)
  {
    stage_v_105_1 = ((pub_r000546_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  }
  else
  {
    stage_v_105_1 = ((pub_r000546_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
  }
  if ((sec_r000546_0_2 & 63) > 26)
  {
    stage_v_105_2 = ((pub_r000546_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  }
  else
  {
    stage_v_105_2 = ((pub_r000546_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_33_1 & 63) > 30)
  {
    stage_v_106_1 = ((pub_r000546_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  }
  else
  {
    stage_v_106_1 = ((pub_r000546_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
  }
  if ((stage_v_33_2 & 63) > 30)
  {
    stage_v_106_2 = ((pub_r000546_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  }
  else
  {
    stage_v_106_2 = ((pub_r000546_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_91_1 & 63) > 42)
  {
    stage_v_107_1 = ((pub_r000546_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  }
  else
  {
    stage_v_107_1 = ((pub_r000546_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
  }
  if ((stage_v_91_2 & 63) > 42)
  {
    stage_v_107_2 = ((pub_r000546_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  }
  else
  {
    stage_v_107_2 = ((pub_r000546_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_81_1 & 63) > 23)
  {
    stage_v_108_1 = ((pub_r000546_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  }
  else
  {
    stage_v_108_1 = ((pub_r000546_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
  }
  if ((stage_v_81_2 & 63) > 23)
  {
    stage_v_108_2 = ((pub_r000546_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  }
  else
  {
    stage_v_108_2 = ((pub_r000546_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000546_18_1 & 63) > 59)
  {
    stage_v_109_1 = ((pub_r000546_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  }
  else
  {
    stage_v_109_1 = ((pub_r000546_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
  }
  if ((sec_r000546_18_2 & 63) > 59)
  {
    stage_v_109_2 = ((pub_r000546_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  }
  else
  {
    stage_v_109_2 = ((pub_r000546_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_91_1 & 63) > 49)
  {
    stage_v_110_1 = ((pub_r000546_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  }
  else
  {
    stage_v_110_1 = ((pub_r000546_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
  }
  if ((stage_v_91_2 & 63) > 49)
  {
    stage_v_110_2 = ((pub_r000546_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  }
  else
  {
    stage_v_110_2 = ((pub_r000546_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_68_1 & 63) > 36)
  {
    stage_v_111_1 = ((pub_r000546_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  }
  else
  {
    stage_v_111_1 = ((pub_r000546_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
  }
  if ((stage_v_68_2 & 63) > 36)
  {
    stage_v_111_2 = ((pub_r000546_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  }
  else
  {
    stage_v_111_2 = ((pub_r000546_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000546_19_1 & 63) > 41)
  {
    stage_v_112_1 = ((pub_r000546_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  }
  else
  {
    stage_v_112_1 = ((pub_r000546_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
  }
  if ((sec_r000546_19_2 & 63) > 41)
  {
    stage_v_112_2 = ((pub_r000546_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  }
  else
  {
    stage_v_112_2 = ((pub_r000546_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_49_1 & 63) > 36)
  {
    stage_v_113_1 = ((pub_r000546_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  }
  else
  {
    stage_v_113_1 = ((pub_r000546_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
  }
  if ((stage_v_49_2 & 63) > 36)
  {
    stage_v_113_2 = ((pub_r000546_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  }
  else
  {
    stage_v_113_2 = ((pub_r000546_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_88_1 & 63) > 57)
  {
    stage_v_114_1 = ((pub_r000546_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  }
  else
  {
    stage_v_114_1 = ((pub_r000546_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
  }
  if ((stage_v_88_2 & 63) > 57)
  {
    stage_v_114_2 = ((pub_r000546_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  }
  else
  {
    stage_v_114_2 = ((pub_r000546_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000546_7_1 & 63) > 38)
  {
    stage_v_115_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  }
  else
  {
    stage_v_115_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
  }
  if ((sec_r000546_7_2 & 63) > 38)
  {
    stage_v_115_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  }
  else
  {
    stage_v_115_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_51_1 & 63) > 56)
  {
    stage_v_116_1 = ((pub_r000546_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  }
  else
  {
    stage_v_116_1 = ((pub_r000546_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
  }
  if ((stage_v_51_2 & 63) > 56)
  {
    stage_v_116_2 = ((pub_r000546_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  }
  else
  {
    stage_v_116_2 = ((pub_r000546_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_77_1 & 63) > 20)
  {
    stage_v_117_1 = ((pub_r000546_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  }
  else
  {
    stage_v_117_1 = ((pub_r000546_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
  }
  if ((stage_v_77_2 & 63) > 20)
  {
    stage_v_117_2 = ((pub_r000546_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  }
  else
  {
    stage_v_117_2 = ((pub_r000546_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000546_15_1 & 63) > 21)
  {
    stage_v_118_1 = ((pub_r000546_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  }
  else
  {
    stage_v_118_1 = ((pub_r000546_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
  }
  if ((sec_r000546_15_2 & 63) > 21)
  {
    stage_v_118_2 = ((pub_r000546_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  }
  else
  {
    stage_v_118_2 = ((pub_r000546_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_108_1 & 63) > 42)
  {
    stage_v_119_1 = ((pub_r000546_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  }
  else
  {
    stage_v_119_1 = ((pub_r000546_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
  }
  if ((stage_v_108_2 & 63) > 42)
  {
    stage_v_119_2 = ((pub_r000546_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  }
  else
  {
    stage_v_119_2 = ((pub_r000546_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000546_16_1 & 63) > 18)
  {
    stage_v_120_1 = ((pub_r000546_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  }
  else
  {
    stage_v_120_1 = ((pub_r000546_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
  }
  if ((sec_r000546_16_2 & 63) > 18)
  {
    stage_v_120_2 = ((pub_r000546_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  }
  else
  {
    stage_v_120_2 = ((pub_r000546_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_73_1 & 63) > 26)
  {
    stage_v_121_1 = ((pub_r000546_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  }
  else
  {
    stage_v_121_1 = ((pub_r000546_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
  }
  if ((stage_v_73_2 & 63) > 26)
  {
    stage_v_121_2 = ((pub_r000546_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  }
  else
  {
    stage_v_121_2 = ((pub_r000546_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_67_1 & 63) > 47)
  {
    stage_v_122_1 = ((pub_r000546_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  }
  else
  {
    stage_v_122_1 = ((pub_r000546_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
  }
  if ((stage_v_67_2 & 63) > 47)
  {
    stage_v_122_2 = ((pub_r000546_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  }
  else
  {
    stage_v_122_2 = ((pub_r000546_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_121_1 & 63) > 30)
  {
    stage_v_123_1 = ((pub_r000546_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  }
  else
  {
    stage_v_123_1 = ((pub_r000546_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
  }
  if ((stage_v_121_2 & 63) > 30)
  {
    stage_v_123_2 = ((pub_r000546_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  }
  else
  {
    stage_v_123_2 = ((pub_r000546_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_14_1 & 63) > 34)
  {
    stage_v_124_1 = ((pub_r000546_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  }
  else
  {
    stage_v_124_1 = ((pub_r000546_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
  }
  if ((stage_v_14_2 & 63) > 34)
  {
    stage_v_124_2 = ((pub_r000546_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  }
  else
  {
    stage_v_124_2 = ((pub_r000546_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000546_6_1 & 63) > 35)
  {
    stage_v_125_1 = ((pub_r000546_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  }
  else
  {
    stage_v_125_1 = ((pub_r000546_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
  }
  if ((sec_r000546_6_2 & 63) > 35)
  {
    stage_v_125_2 = ((pub_r000546_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  }
  else
  {
    stage_v_125_2 = ((pub_r000546_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_39_1 & 63) > 23)
  {
    stage_v_126_1 = ((pub_r000546_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  }
  else
  {
    stage_v_126_1 = ((pub_r000546_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
  }
  if ((stage_v_39_2 & 63) > 23)
  {
    stage_v_126_2 = ((pub_r000546_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  }
  else
  {
    stage_v_126_2 = ((pub_r000546_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000546_2_1 & 63) > 43)
  {
    stage_v_127_1 = ((pub_r000546_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  }
  else
  {
    stage_v_127_1 = ((pub_r000546_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
  }
  if ((sec_r000546_2_2 & 63) > 43)
  {
    stage_v_127_2 = ((pub_r000546_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  }
  else
  {
    stage_v_127_2 = ((pub_r000546_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_67_1 & 63) > 43)
  {
    stage_v_128_1 = ((pub_r000546_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  }
  else
  {
    stage_v_128_1 = ((pub_r000546_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
  }
  if ((stage_v_67_2 & 63) > 43)
  {
    stage_v_128_2 = ((pub_r000546_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  }
  else
  {
    stage_v_128_2 = ((pub_r000546_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000546_9_1 & 63) > 23)
  {
    stage_v_129_1 = ((pub_r000546_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  }
  else
  {
    stage_v_129_1 = ((pub_r000546_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
  }
  if ((sec_r000546_9_2 & 63) > 23)
  {
    stage_v_129_2 = ((pub_r000546_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  }
  else
  {
    stage_v_129_2 = ((pub_r000546_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_43_1 & 63) > 27)
  {
    stage_v_130_1 = ((pub_r000546_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  }
  else
  {
    stage_v_130_1 = ((pub_r000546_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
  }
  if ((stage_v_43_2 & 63) > 27)
  {
    stage_v_130_2 = ((pub_r000546_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  }
  else
  {
    stage_v_130_2 = ((pub_r000546_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000546_11_1 & 63) > 15)
  {
    stage_v_131_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  }
  else
  {
    stage_v_131_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
  }
  if ((sec_r000546_11_2 & 63) > 15)
  {
    stage_v_131_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  }
  else
  {
    stage_v_131_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000546_12_1 & 63) > 52)
  {
    stage_v_132_1 = ((pub_r000546_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  }
  else
  {
    stage_v_132_1 = ((pub_r000546_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
  }
  if ((sec_r000546_12_2 & 63) > 52)
  {
    stage_v_132_2 = ((pub_r000546_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  }
  else
  {
    stage_v_132_2 = ((pub_r000546_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000546_0_1 & 63) > 46)
  {
    stage_v_133_1 = ((pub_r000546_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  }
  else
  {
    stage_v_133_1 = ((pub_r000546_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
  }
  if ((sec_r000546_0_2 & 63) > 46)
  {
    stage_v_133_2 = ((pub_r000546_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  }
  else
  {
    stage_v_133_2 = ((pub_r000546_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_70_1 & 63) > 33)
  {
    stage_v_134_1 = ((pub_r000546_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  }
  else
  {
    stage_v_134_1 = ((pub_r000546_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
  }
  if ((stage_v_70_2 & 63) > 33)
  {
    stage_v_134_2 = ((pub_r000546_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  }
  else
  {
    stage_v_134_2 = ((pub_r000546_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000546_19_1 & 63) > 54)
  {
    stage_v_135_1 = ((pub_r000546_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  }
  else
  {
    stage_v_135_1 = ((pub_r000546_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
  }
  if ((sec_r000546_19_2 & 63) > 54)
  {
    stage_v_135_2 = ((pub_r000546_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  }
  else
  {
    stage_v_135_2 = ((pub_r000546_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000546_17_1 & 63) > 25)
  {
    stage_v_136_1 = ((pub_r000546_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  }
  else
  {
    stage_v_136_1 = ((pub_r000546_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
  }
  if ((sec_r000546_17_2 & 63) > 25)
  {
    stage_v_136_2 = ((pub_r000546_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  }
  else
  {
    stage_v_136_2 = ((pub_r000546_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_32_1 & 63) > 15)
  {
    stage_v_137_1 = ((pub_r000546_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  }
  else
  {
    stage_v_137_1 = ((pub_r000546_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
  }
  if ((stage_v_32_2 & 63) > 15)
  {
    stage_v_137_2 = ((pub_r000546_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  }
  else
  {
    stage_v_137_2 = ((pub_r000546_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000546_7_1 & 63) > 33)
  {
    stage_v_138_1 = ((pub_r000546_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  }
  else
  {
    stage_v_138_1 = ((pub_r000546_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
  }
  if ((sec_r000546_7_2 & 63) > 33)
  {
    stage_v_138_2 = ((pub_r000546_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  }
  else
  {
    stage_v_138_2 = ((pub_r000546_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_95_1 & 63) > 57)
  {
    stage_v_139_1 = ((pub_r000546_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  }
  else
  {
    stage_v_139_1 = ((pub_r000546_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
  }
  if ((stage_v_95_2 & 63) > 57)
  {
    stage_v_139_2 = ((pub_r000546_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  }
  else
  {
    stage_v_139_2 = ((pub_r000546_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_136_1 & 63) > 44)
  {
    stage_v_140_1 = ((pub_r000546_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  }
  else
  {
    stage_v_140_1 = ((pub_r000546_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
  }
  if ((stage_v_136_2 & 63) > 44)
  {
    stage_v_140_2 = ((pub_r000546_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  }
  else
  {
    stage_v_140_2 = ((pub_r000546_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_85_1 & 63) > 40)
  {
    stage_v_141_1 = ((pub_r000546_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  }
  else
  {
    stage_v_141_1 = ((pub_r000546_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
  }
  if ((stage_v_85_2 & 63) > 40)
  {
    stage_v_141_2 = ((pub_r000546_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  }
  else
  {
    stage_v_141_2 = ((pub_r000546_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_105_1 & 63) > 57)
  {
    stage_v_142_1 = ((pub_r000546_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  }
  else
  {
    stage_v_142_1 = ((pub_r000546_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
  }
  if ((stage_v_105_2 & 63) > 57)
  {
    stage_v_142_2 = ((pub_r000546_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  }
  else
  {
    stage_v_142_2 = ((pub_r000546_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_78_1 & 63) > 27)
  {
    stage_v_143_1 = ((pub_r000546_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  }
  else
  {
    stage_v_143_1 = ((pub_r000546_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
  }
  if ((stage_v_78_2 & 63) > 27)
  {
    stage_v_143_2 = ((pub_r000546_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  }
  else
  {
    stage_v_143_2 = ((pub_r000546_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000546_13_1 & 63) > 24)
  {
    stage_v_144_1 = ((pub_r000546_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  }
  else
  {
    stage_v_144_1 = ((pub_r000546_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
  }
  if ((sec_r000546_13_2 & 63) > 24)
  {
    stage_v_144_2 = ((pub_r000546_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  }
  else
  {
    stage_v_144_2 = ((pub_r000546_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000546_15_1 & 63) > 19)
  {
    stage_v_145_1 = ((pub_r000546_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  }
  else
  {
    stage_v_145_1 = ((pub_r000546_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
  }
  if ((sec_r000546_15_2 & 63) > 19)
  {
    stage_v_145_2 = ((pub_r000546_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  }
  else
  {
    stage_v_145_2 = ((pub_r000546_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_128_1 & 63) > 30)
  {
    stage_v_146_1 = ((pub_r000546_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  }
  else
  {
    stage_v_146_1 = ((pub_r000546_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
  }
  if ((stage_v_128_2 & 63) > 30)
  {
    stage_v_146_2 = ((pub_r000546_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  }
  else
  {
    stage_v_146_2 = ((pub_r000546_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_29_1 & 63) > 29)
  {
    stage_v_147_1 = ((pub_r000546_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  }
  else
  {
    stage_v_147_1 = ((pub_r000546_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
  }
  if ((stage_v_29_2 & 63) > 29)
  {
    stage_v_147_2 = ((pub_r000546_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  }
  else
  {
    stage_v_147_2 = ((pub_r000546_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_67_1 & 63) > 37)
  {
    stage_v_148_1 = ((pub_r000546_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  }
  else
  {
    stage_v_148_1 = ((pub_r000546_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
  }
  if ((stage_v_67_2 & 63) > 37)
  {
    stage_v_148_2 = ((pub_r000546_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  }
  else
  {
    stage_v_148_2 = ((pub_r000546_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_34_1 & 63) > 60)
  {
    stage_v_149_1 = ((pub_r000546_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  }
  else
  {
    stage_v_149_1 = ((pub_r000546_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
  }
  if ((stage_v_34_2 & 63) > 60)
  {
    stage_v_149_2 = ((pub_r000546_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  }
  else
  {
    stage_v_149_2 = ((pub_r000546_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((sec_r000546_8_1 & 63) > 28)
  {
    stage_v_150_1 = ((pub_r000546_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  }
  else
  {
    stage_v_150_1 = ((pub_r000546_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
  }
  if ((sec_r000546_8_2 & 63) > 28)
  {
    stage_v_150_2 = ((pub_r000546_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  }
  else
  {
    stage_v_150_2 = ((pub_r000546_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((stage_v_142_1 & 63) > 38)
  {
    stage_v_151_1 = ((pub_r000546_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  }
  else
  {
    stage_v_151_1 = ((pub_r000546_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
  }
  if ((stage_v_142_2 & 63) > 38)
  {
    stage_v_151_2 = ((pub_r000546_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  }
  else
  {
    stage_v_151_2 = ((pub_r000546_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_52_1 & 63) > 32)
  {
    stage_v_152_1 = ((pub_r000546_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  }
  else
  {
    stage_v_152_1 = ((pub_r000546_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
  }
  if ((stage_v_52_2 & 63) > 32)
  {
    stage_v_152_2 = ((pub_r000546_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  }
  else
  {
    stage_v_152_2 = ((pub_r000546_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_91_1 & 63) > 26)
  {
    stage_v_153_1 = ((pub_r000546_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  }
  else
  {
    stage_v_153_1 = ((pub_r000546_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
  }
  if ((stage_v_91_2 & 63) > 26)
  {
    stage_v_153_2 = ((pub_r000546_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  }
  else
  {
    stage_v_153_2 = ((pub_r000546_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_150_1 & 63) > 43)
  {
    stage_v_154_1 = ((pub_r000546_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  }
  else
  {
    stage_v_154_1 = ((pub_r000546_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
  }
  if ((stage_v_150_2 & 63) > 43)
  {
    stage_v_154_2 = ((pub_r000546_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  }
  else
  {
    stage_v_154_2 = ((pub_r000546_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((sec_r000546_2_1 & 63) > 47)
  {
    stage_v_155_1 = ((pub_r000546_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  }
  else
  {
    stage_v_155_1 = ((pub_r000546_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
  }
  if ((sec_r000546_2_2 & 63) > 47)
  {
    stage_v_155_2 = ((pub_r000546_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  }
  else
  {
    stage_v_155_2 = ((pub_r000546_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_107_1 & 63) > 43)
  {
    stage_v_156_1 = ((pub_r000546_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  }
  else
  {
    stage_v_156_1 = ((pub_r000546_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
  }
  if ((stage_v_107_2 & 63) > 43)
  {
    stage_v_156_2 = ((pub_r000546_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  }
  else
  {
    stage_v_156_2 = ((pub_r000546_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((sec_r000546_2_1 & 63) > 50)
  {
    stage_v_157_1 = ((pub_r000546_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  }
  else
  {
    stage_v_157_1 = ((pub_r000546_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
  }
  if ((sec_r000546_2_2 & 63) > 50)
  {
    stage_v_157_2 = ((pub_r000546_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  }
  else
  {
    stage_v_157_2 = ((pub_r000546_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_123_1 & 63) > 28)
  {
    stage_v_158_1 = ((pub_r000546_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  }
  else
  {
    stage_v_158_1 = ((pub_r000546_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
  }
  if ((stage_v_123_2 & 63) > 28)
  {
    stage_v_158_2 = ((pub_r000546_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  }
  else
  {
    stage_v_158_2 = ((pub_r000546_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((stage_v_155_1 & 63) > 50)
  {
    stage_v_159_1 = ((pub_r000546_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  }
  else
  {
    stage_v_159_1 = ((pub_r000546_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 9) & 255;
  }
  if ((stage_v_155_2 & 63) > 50)
  {
    stage_v_159_2 = ((pub_r000546_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  }
  else
  {
    stage_v_159_2 = ((pub_r000546_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((sec_r000546_6_1 & 63) > 46)
  {
    stage_v_160_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  }
  else
  {
    stage_v_160_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 9) & 255;
  }
  if ((sec_r000546_6_2 & 63) > 46)
  {
    stage_v_160_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  }
  else
  {
    stage_v_160_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((stage_v_124_1 & 63) > 21)
  {
    stage_v_161_1 = ((pub_r000546_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  }
  else
  {
    stage_v_161_1 = ((pub_r000546_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
  }
  if ((stage_v_124_2 & 63) > 21)
  {
    stage_v_161_2 = ((pub_r000546_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  }
  else
  {
    stage_v_161_2 = ((pub_r000546_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((stage_v_31_1 & 63) > 47)
  {
    stage_v_162_1 = ((pub_r000546_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  }
  else
  {
    stage_v_162_1 = ((pub_r000546_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
  }
  if ((stage_v_31_2 & 63) > 47)
  {
    stage_v_162_2 = ((pub_r000546_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  }
  else
  {
    stage_v_162_2 = ((pub_r000546_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((stage_v_30_1 & 63) > 24)
  {
    stage_v_163_1 = ((pub_r000546_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  }
  else
  {
    stage_v_163_1 = ((pub_r000546_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
  }
  if ((stage_v_30_2 & 63) > 24)
  {
    stage_v_163_2 = ((pub_r000546_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  }
  else
  {
    stage_v_163_2 = ((pub_r000546_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((stage_v_64_1 & 63) > 38)
  {
    stage_v_164_1 = ((pub_r000546_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  }
  else
  {
    stage_v_164_1 = ((pub_r000546_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
  }
  if ((stage_v_64_2 & 63) > 38)
  {
    stage_v_164_2 = ((pub_r000546_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  }
  else
  {
    stage_v_164_2 = ((pub_r000546_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((stage_v_118_1 & 63) > 19)
  {
    stage_v_165_1 = ((pub_r000546_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  }
  else
  {
    stage_v_165_1 = ((pub_r000546_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
  }
  if ((stage_v_118_2 & 63) > 19)
  {
    stage_v_165_2 = ((pub_r000546_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  }
  else
  {
    stage_v_165_2 = ((pub_r000546_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  if ((stage_v_50_1 & 63) > 53)
  {
    stage_v_166_1 = ((pub_r000546_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  }
  else
  {
    stage_v_166_1 = ((pub_r000546_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 9) & 255;
  }
  if ((stage_v_50_2 & 63) > 53)
  {
    stage_v_166_2 = ((pub_r000546_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  }
  else
  {
    stage_v_166_2 = ((pub_r000546_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  if ((stage_v_68_1 & 63) > 34)
  {
    stage_v_167_1 = ((pub_r000546_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  }
  else
  {
    stage_v_167_1 = ((pub_r000546_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 9) & 255;
  }
  if ((stage_v_68_2 & 63) > 34)
  {
    stage_v_167_2 = ((pub_r000546_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  }
  else
  {
    stage_v_167_2 = ((pub_r000546_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  if ((stage_v_106_1 & 63) > 37)
  {
    stage_v_168_1 = ((pub_r000546_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  }
  else
  {
    stage_v_168_1 = ((pub_r000546_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 9) & 255;
  }
  if ((stage_v_106_2 & 63) > 37)
  {
    stage_v_168_2 = ((pub_r000546_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  }
  else
  {
    stage_v_168_2 = ((pub_r000546_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  if ((stage_v_160_1 & 63) > 45)
  {
    stage_v_169_1 = ((pub_r000546_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  }
  else
  {
    stage_v_169_1 = ((pub_r000546_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
  }
  if ((stage_v_160_2 & 63) > 45)
  {
    stage_v_169_2 = ((pub_r000546_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  }
  else
  {
    stage_v_169_2 = ((pub_r000546_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  if ((stage_v_78_1 & 63) > 52)
  {
    stage_v_170_1 = ((pub_r000546_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  }
  else
  {
    stage_v_170_1 = ((pub_r000546_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 9) & 255;
  }
  if ((stage_v_78_2 & 63) > 52)
  {
    stage_v_170_2 = ((pub_r000546_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  }
  else
  {
    stage_v_170_2 = ((pub_r000546_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  if ((sec_r000546_15_1 & 63) > 53)
  {
    stage_v_171_1 = ((pub_r000546_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  }
  else
  {
    stage_v_171_1 = ((pub_r000546_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 9) & 255;
  }
  if ((sec_r000546_15_2 & 63) > 53)
  {
    stage_v_171_2 = ((pub_r000546_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  }
  else
  {
    stage_v_171_2 = ((pub_r000546_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  if ((sec_r000546_8_1 & 63) > 42)
  {
    stage_v_172_1 = ((pub_r000546_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  }
  else
  {
    stage_v_172_1 = ((pub_r000546_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
  }
  if ((sec_r000546_8_2 & 63) > 42)
  {
    stage_v_172_2 = ((pub_r000546_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  }
  else
  {
    stage_v_172_2 = ((pub_r000546_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = 0;
  int stage_v_173_2 = 0;
  if ((sec_r000546_19_1 & 63) > 60)
  {
    stage_v_173_1 = ((pub_r000546_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  }
  else
  {
    stage_v_173_1 = ((pub_r000546_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 9) & 255;
  }
  if ((sec_r000546_19_2 & 63) > 60)
  {
    stage_v_173_2 = ((pub_r000546_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  }
  else
  {
    stage_v_173_2 = ((pub_r000546_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = 0;
  int stage_v_174_2 = 0;
  if ((sec_r000546_4_1 & 63) > 20)
  {
    stage_v_174_1 = ((pub_r000546_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  }
  else
  {
    stage_v_174_1 = ((pub_r000546_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 9) & 255;
  }
  if ((sec_r000546_4_2 & 63) > 20)
  {
    stage_v_174_2 = ((pub_r000546_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  }
  else
  {
    stage_v_174_2 = ((pub_r000546_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = 0;
  int stage_v_175_2 = 0;
  if ((stage_v_77_1 & 63) > 34)
  {
    stage_v_175_1 = ((pub_r000546_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  }
  else
  {
    stage_v_175_1 = ((pub_r000546_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 9) & 255;
  }
  if ((stage_v_77_2 & 63) > 34)
  {
    stage_v_175_2 = ((pub_r000546_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  }
  else
  {
    stage_v_175_2 = ((pub_r000546_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = 0;
  int stage_v_176_2 = 0;
  if ((sec_r000546_11_1 & 63) > 58)
  {
    stage_v_176_1 = ((pub_r000546_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  }
  else
  {
    stage_v_176_1 = ((pub_r000546_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
  }
  if ((sec_r000546_11_2 & 63) > 58)
  {
    stage_v_176_2 = ((pub_r000546_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  }
  else
  {
    stage_v_176_2 = ((pub_r000546_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = 0;
  int stage_v_177_2 = 0;
  if ((stage_v_62_1 & 63) > 26)
  {
    stage_v_177_1 = ((pub_r000546_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  }
  else
  {
    stage_v_177_1 = ((pub_r000546_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 9) & 255;
  }
  if ((stage_v_62_2 & 63) > 26)
  {
    stage_v_177_2 = ((pub_r000546_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  }
  else
  {
    stage_v_177_2 = ((pub_r000546_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = 0;
  int stage_v_178_2 = 0;
  if ((stage_v_110_1 & 63) > 59)
  {
    stage_v_178_1 = ((pub_r000546_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  }
  else
  {
    stage_v_178_1 = ((pub_r000546_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 9) & 255;
  }
  if ((stage_v_110_2 & 63) > 59)
  {
    stage_v_178_2 = ((pub_r000546_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  }
  else
  {
    stage_v_178_2 = ((pub_r000546_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = 0;
  int stage_v_179_2 = 0;
  if ((stage_v_50_1 & 63) > 60)
  {
    stage_v_179_1 = ((pub_r000546_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  }
  else
  {
    stage_v_179_1 = ((pub_r000546_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 9) & 255;
  }
  if ((stage_v_50_2 & 63) > 60)
  {
    stage_v_179_2 = ((pub_r000546_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  }
  else
  {
    stage_v_179_2 = ((pub_r000546_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = 0;
  int stage_v_180_2 = 0;
  if ((sec_r000546_2_1 & 63) > 44)
  {
    stage_v_180_1 = ((pub_r000546_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  }
  else
  {
    stage_v_180_1 = ((pub_r000546_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 9) & 255;
  }
  if ((sec_r000546_2_2 & 63) > 44)
  {
    stage_v_180_2 = ((pub_r000546_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  }
  else
  {
    stage_v_180_2 = ((pub_r000546_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = 0;
  int stage_v_181_2 = 0;
  if ((stage_v_106_1 & 63) > 23)
  {
    stage_v_181_1 = ((pub_r000546_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  }
  else
  {
    stage_v_181_1 = ((pub_r000546_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 9) & 255;
  }
  if ((stage_v_106_2 & 63) > 23)
  {
    stage_v_181_2 = ((pub_r000546_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  }
  else
  {
    stage_v_181_2 = ((pub_r000546_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = 0;
  int stage_v_182_2 = 0;
  if ((sec_r000546_13_1 & 63) > 21)
  {
    stage_v_182_1 = ((pub_r000546_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  }
  else
  {
    stage_v_182_1 = ((pub_r000546_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 9) & 255;
  }
  if ((sec_r000546_13_2 & 63) > 21)
  {
    stage_v_182_2 = ((pub_r000546_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  }
  else
  {
    stage_v_182_2 = ((pub_r000546_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = 0;
  int stage_v_183_2 = 0;
  if ((stage_v_134_1 & 63) > 59)
  {
    stage_v_183_1 = ((pub_r000546_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  }
  else
  {
    stage_v_183_1 = ((pub_r000546_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 9) & 255;
  }
  if ((stage_v_134_2 & 63) > 59)
  {
    stage_v_183_2 = ((pub_r000546_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  }
  else
  {
    stage_v_183_2 = ((pub_r000546_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = 0;
  int stage_v_184_2 = 0;
  if ((sec_r000546_5_1 & 63) > 56)
  {
    stage_v_184_1 = ((pub_r000546_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  }
  else
  {
    stage_v_184_1 = ((pub_r000546_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 9) & 255;
  }
  if ((sec_r000546_5_2 & 63) > 56)
  {
    stage_v_184_2 = ((pub_r000546_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  }
  else
  {
    stage_v_184_2 = ((pub_r000546_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = 0;
  int stage_v_185_2 = 0;
  if ((stage_v_157_1 & 63) > 59)
  {
    stage_v_185_1 = ((pub_r000546_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  }
  else
  {
    stage_v_185_1 = ((pub_r000546_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 9) & 255;
  }
  if ((stage_v_157_2 & 63) > 59)
  {
    stage_v_185_2 = ((pub_r000546_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  }
  else
  {
    stage_v_185_2 = ((pub_r000546_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = 0;
  int stage_v_186_2 = 0;
  if ((sec_r000546_6_1 & 63) > 60)
  {
    stage_v_186_1 = ((pub_r000546_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  }
  else
  {
    stage_v_186_1 = ((pub_r000546_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 9) & 255;
  }
  if ((sec_r000546_6_2 & 63) > 60)
  {
    stage_v_186_2 = ((pub_r000546_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  }
  else
  {
    stage_v_186_2 = ((pub_r000546_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = 0;
  int stage_v_187_2 = 0;
  if ((stage_v_112_1 & 63) > 40)
  {
    stage_v_187_1 = ((pub_r000546_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  }
  else
  {
    stage_v_187_1 = ((pub_r000546_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 9) & 255;
  }
  if ((stage_v_112_2 & 63) > 40)
  {
    stage_v_187_2 = ((pub_r000546_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  }
  else
  {
    stage_v_187_2 = ((pub_r000546_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = 0;
  int stage_v_188_2 = 0;
  if ((sec_r000546_17_1 & 63) > 36)
  {
    stage_v_188_1 = ((pub_r000546_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  }
  else
  {
    stage_v_188_1 = ((pub_r000546_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 9) & 255;
  }
  if ((sec_r000546_17_2 & 63) > 36)
  {
    stage_v_188_2 = ((pub_r000546_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  }
  else
  {
    stage_v_188_2 = ((pub_r000546_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = 0;
  int stage_v_189_2 = 0;
  if ((stage_v_17_1 & 63) > 45)
  {
    stage_v_189_1 = ((pub_r000546_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  }
  else
  {
    stage_v_189_1 = ((pub_r000546_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 9) & 255;
  }
  if ((stage_v_17_2 & 63) > 45)
  {
    stage_v_189_2 = ((pub_r000546_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  }
  else
  {
    stage_v_189_2 = ((pub_r000546_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000546_17_1 == pub_r000546_17_2);
  __CPROVER_assume(sec_r000546_14_1 != sec_r000546_14_2);
  __CPROVER_assume(sec_r000546_12_1 != sec_r000546_12_2);
  __CPROVER_assume(pub_r000546_15_1 == pub_r000546_15_2);
  __CPROVER_assume(pub_r000546_14_1 == pub_r000546_14_2);
  __CPROVER_assume(sec_r000546_7_1 != sec_r000546_7_2);
  __CPROVER_assume(pub_r000546_6_1 == pub_r000546_6_2);
  __CPROVER_assume(sec_r000546_2_1 != sec_r000546_2_2);
  __CPROVER_assume(pub_r000546_10_1 == pub_r000546_10_2);
  __CPROVER_assume(sec_r000546_1_1 != sec_r000546_1_2);
  __CPROVER_assume(pub_r000546_9_1 == pub_r000546_9_2);
  __CPROVER_assume(sec_r000546_5_1 != sec_r000546_5_2);
  __CPROVER_assume(sec_r000546_0_1 != sec_r000546_0_2);
  __CPROVER_assume(sec_r000546_8_1 != sec_r000546_8_2);
  __CPROVER_assume(pub_r000546_12_1 == pub_r000546_12_2);
  __CPROVER_assume(pub_r000546_16_1 == pub_r000546_16_2);
  __CPROVER_assume(sec_r000546_3_1 != sec_r000546_3_2);
  __CPROVER_assume(pub_r000546_0_1 == pub_r000546_0_2);
  __CPROVER_assume(pub_r000546_19_1 == pub_r000546_19_2);
  __CPROVER_assume(pub_r000546_2_1 == pub_r000546_2_2);
  __CPROVER_assume(pub_r000546_4_1 == pub_r000546_4_2);
  __CPROVER_assume(pub_r000546_1_1 == pub_r000546_1_2);
  __CPROVER_assume(sec_r000546_18_1 != sec_r000546_18_2);
  __CPROVER_assume(pub_r000546_3_1 == pub_r000546_3_2);
  __CPROVER_assume(sec_r000546_9_1 != sec_r000546_9_2);
  __CPROVER_assume(sec_r000546_15_1 != sec_r000546_15_2);
  __CPROVER_assume(sec_r000546_4_1 != sec_r000546_4_2);
  __CPROVER_assume(sec_r000546_13_1 != sec_r000546_13_2);
  __CPROVER_assume(pub_r000546_5_1 == pub_r000546_5_2);
  __CPROVER_assume(pub_r000546_8_1 == pub_r000546_8_2);
  __CPROVER_assume(sec_r000546_11_1 != sec_r000546_11_2);
  __CPROVER_assume(pub_r000546_7_1 == pub_r000546_7_2);
  __CPROVER_assume(sec_r000546_10_1 != sec_r000546_10_2);
  __CPROVER_assume(sec_r000546_17_1 != sec_r000546_17_2);
  __CPROVER_assume(sec_r000546_19_1 != sec_r000546_19_2);
  __CPROVER_assume(pub_r000546_13_1 == pub_r000546_13_2);
  __CPROVER_assume(pub_r000546_18_1 == pub_r000546_18_2);
  __CPROVER_assume(sec_r000546_16_1 != sec_r000546_16_2);
  __CPROVER_assume(sec_r000546_6_1 != sec_r000546_6_2);
  __CPROVER_assume(pub_r000546_11_1 == pub_r000546_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.trace == st_var_2_2.trace);
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
}


