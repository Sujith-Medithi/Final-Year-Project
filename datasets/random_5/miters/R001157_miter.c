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
struct Vector3D_R001157_5713_0
{
  short pitch;
  short norm_sq;
  int coord_x;
  short heading;
  int buffer[3];
};
struct CipherContext_R001157_5713_1
{
  int round_key;
  int flags;
  short iv;
  unsigned char nonce;
  int counter;
  int tag;
  int buffer[3];
};
struct MatrixBlock_R001157_5713_2
{
  short density;
  int dim;
  unsigned char trace;
  int determinant;
  int scale;
  int stride;
  int buffer[3];
};
union TelemetryField_R001157_5713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001157_5713_1
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
void fn_R001157_5713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st_1 = {0};
  struct CipherContext_R001157_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int accumulator_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_97_1)
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

  switch (accumulator_97_2)
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
  int quotient_66_1 = local_arr_1[aux_1 % 3];
  int quotient_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_66_2 * 2)) & 127;
  int threshold_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_10_1 > 38)
  {
    acc_1 = ((acc_1 + (threshold_10_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_10_2 > 38)
  {
    acc_2 = ((acc_2 + (threshold_10_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_12_1) & 63;
  aux_2 = (aux_2 + factor_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_97_1 == accumulator_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_66_1 == quotient_66_2);
  assert(threshold_10_1 == threshold_10_2);
  assert(factor_12_1 == factor_12_2);
}

int fn_R001157_5713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int accumulator_97 = (aux + st.buffer[1]) & 3;
  switch (accumulator_97)
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
  int quotient_66 = local_arr[aux % 3];
  acc = (acc + (quotient_66 * 2)) & 127;
  int threshold_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_10 > 38)
  {
    acc = ((acc + (threshold_10 * 2)) + 5) & 127;
    aux ^= threshold_10 & 15;
  }
  else
  {
    acc = ((acc - threshold_10) + 11) & 127;
    aux += 3;
  }
  int factor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_12) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001157_5713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st_1 = {0};
  struct MatrixBlock_R001157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int metric_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_17_1)
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

  switch (metric_17_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_17_1 == metric_17_2);
}

int fn_R001157_5713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int metric_17 = (aux + st.buffer[1]) & 3;
  switch (metric_17)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001157_5713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st_1 = {0};
  struct CipherContext_R001157_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int scale_33_1 = 0;
  int scale_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_33_1 = ((scale_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_33_2 = ((scale_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_33_1) & 127;
    acc_2 = (acc_2 + scale_33_2) & 127;
  }

  int scale_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_79_1) & 63;
  aux_2 = (aux_2 + scale_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_37_1 > 29)
  {
    acc_1 = ((acc_1 + (scale_37_1 * 2)) + 5) & 127;
    aux_1 ^= scale_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_37_2 > 29)
  {
    acc_2 = ((acc_2 + (scale_37_2 * 2)) + 5) & 127;
    aux_2 ^= scale_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_37_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_33_1 == scale_33_2);
  assert(scale_79_1 == scale_79_2);
  assert(scale_37_1 == scale_37_2);
}

int fn_R001157_5713_2(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int scale_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_33 = ((scale_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_33) & 127;
  }

  int scale_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_79) & 63;
  acc ^= aux;
  int scale_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_37 > 29)
  {
    acc = ((acc + (scale_37 * 2)) + 5) & 127;
    aux ^= scale_37 & 15;
  }
  else
  {
    acc = ((acc - scale_37) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001157_5713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001157_5713_0 st_1 = {0};
  struct Vector3D_R001157_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_74_1 = local_arr_1[aux_1 % 3];
  int quotient_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_74_2 * 2)) & 127;
  int residue_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_40_1)
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

  switch (residue_40_2)
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
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_74_1 == quotient_74_2);
  assert(residue_40_1 == residue_40_2);
}

int fn_R001157_5713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001157_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int quotient_74 = local_arr[aux % 3];
  acc = (acc + (quotient_74 * 2)) & 127;
  int residue_40 = (aux + st.buffer[1]) & 3;
  switch (residue_40)
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

void fn_R001157_5713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st_1 = {0};
  struct CipherContext_R001157_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_55_1) & 63;
  aux_2 = (aux_2 + weight_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_30_1)
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

  switch (quantum_30_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_55_1 == weight_55_2);
  assert(quantum_30_1 == quantum_30_2);
}

int fn_R001157_5713_4(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_55) & 63;
  acc ^= aux;
  int quantum_30 = (aux + st.buffer[1]) & 3;
  switch (quantum_30)
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

  return (acc + aux) & 255;
}

void fn_R001157_5713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001157_5713_0 st_1 = {0};
  struct Vector3D_R001157_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int tally_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_35_1)
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

  switch (tally_35_2)
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

  int sample_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_23_1 > 23)
  {
    acc_1 = ((acc_1 + (sample_23_1 * 2)) + 5) & 127;
    aux_1 ^= sample_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_23_2 > 23)
  {
    acc_2 = ((acc_2 + (sample_23_2 * 2)) + 5) & 127;
    aux_2 ^= sample_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_23_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_35_1 == tally_35_2);
  assert(sample_23_1 == sample_23_2);
}

int fn_R001157_5713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001157_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int tally_35 = (aux + st.buffer[1]) & 3;
  switch (tally_35)
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

  int sample_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_23 > 23)
  {
    acc = ((acc + (sample_23 * 2)) + 5) & 127;
    aux ^= sample_23 & 15;
  }
  else
  {
    acc = ((acc - sample_23) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001157_5713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st_1 = {0};
  struct MatrixBlock_R001157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int phase_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_10_1)
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

  switch (phase_10_2)
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
  int residue_15_1 = local_arr_1[aux_1 % 3];
  int residue_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_15_2 * 2)) & 127;
  int mask_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_49_1) & 63;
  aux_2 = (aux_2 + mask_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_70_1 > 26)
  {
    acc_1 = ((acc_1 + (offset_70_1 * 2)) + 5) & 127;
    aux_1 ^= offset_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_70_2 > 26)
  {
    acc_2 = ((acc_2 + (offset_70_2 * 2)) + 5) & 127;
    aux_2 ^= offset_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_10_1 == phase_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_15_1 == residue_15_2);
  assert(mask_49_1 == mask_49_2);
  assert(offset_70_1 == offset_70_2);
}

int fn_R001157_5713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int phase_10 = (aux + st.buffer[1]) & 3;
  switch (phase_10)
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
  int residue_15 = local_arr[aux % 3];
  acc = (acc + (residue_15 * 2)) & 127;
  int mask_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_49) & 63;
  acc ^= aux;
  int offset_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_70 > 26)
  {
    acc = ((acc + (offset_70 * 2)) + 5) & 127;
    aux ^= offset_70 & 15;
  }
  else
  {
    acc = ((acc - offset_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001157_5713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st_1 = {0};
  struct CipherContext_R001157_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_12_1 > 20)
  {
    acc_1 = ((acc_1 + (anchor_12_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_12_2 > 20)
  {
    acc_2 = ((acc_2 + (anchor_12_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_12_1 == anchor_12_2);
}

int fn_R001157_5713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_12 > 20)
  {
    acc = ((acc + (anchor_12 * 2)) + 5) & 127;
    aux ^= anchor_12 & 15;
  }
  else
  {
    acc = ((acc - anchor_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001157_5713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st_1 = {0};
  struct MatrixBlock_R001157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_19_1 = local_arr_1[aux_1 % 3];
  int vector_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_19_2 * 2)) & 127;
  int residue_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_71_1)
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

  switch (residue_71_2)
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
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_19_1 == vector_19_2);
  assert(residue_71_1 == residue_71_2);
}

int fn_R001157_5713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int vector_19 = local_arr[aux % 3];
  acc = (acc + (vector_19 * 2)) & 127;
  int residue_71 = (aux + st.buffer[1]) & 3;
  switch (residue_71)
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

void fn_R001157_5713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st_1 = {0};
  struct MatrixBlock_R001157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int cursor_39_1 = 0;
  int cursor_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_39_1 = ((cursor_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_39_2 = ((cursor_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_39_1) & 127;
    acc_2 = (acc_2 + cursor_39_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_39_1 == cursor_39_2);
}

int fn_R001157_5713_9(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int cursor_39 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_39 = ((cursor_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_39) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001157_5713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st_1 = {0};
  struct CipherContext_R001157_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_79_1) & 63;
  aux_2 = (aux_2 + pivot_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_79_1 == pivot_79_2);
}

int fn_R001157_5713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_79) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001157_5713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st_1 = {0};
  struct MatrixBlock_R001157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int tally_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_80_1) & 63;
  aux_2 = (aux_2 + tally_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_80_1 == tally_80_2);
}

int fn_R001157_5713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int tally_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_80) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001157_5713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001157_5713_0 st_1 = {0};
  struct Vector3D_R001157_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int cursor_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_91_1) & 63;
  aux_2 = (aux_2 + cursor_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_61_1 = 0;
  int quotient_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_61_1 = ((quotient_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_61_2 = ((quotient_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_61_1) & 127;
    acc_2 = (acc_2 + quotient_61_2) & 127;
  }

  int offset_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_80_1)
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

  switch (offset_80_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_91_1 == cursor_91_2);
  assert(quotient_61_1 == quotient_61_2);
  assert(offset_80_1 == offset_80_2);
}

int fn_R001157_5713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001157_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int cursor_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_91) & 63;
  acc ^= aux;
  int quotient_61 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_61 = ((quotient_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_61) & 127;
  }

  int offset_80 = (aux + st.buffer[1]) & 3;
  switch (offset_80)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001157_5713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st_1 = {0};
  struct MatrixBlock_R001157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int quantum_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_62_1) & 63;
  aux_2 = (aux_2 + quantum_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_72_1 = local_arr_1[aux_1 % 3];
  int phase_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_72_2 * 2)) & 127;
  int factor_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_31_1)
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

  switch (factor_31_2)
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
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_62_1 == quantum_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_72_1 == phase_72_2);
  assert(factor_31_1 == factor_31_2);
}

int fn_R001157_5713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int quantum_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_62) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_72 = local_arr[aux % 3];
  acc = (acc + (phase_72 * 2)) & 127;
  int factor_31 = (aux + st.buffer[1]) & 3;
  switch (factor_31)
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

void fn_R001157_5713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st_1 = {0};
  struct MatrixBlock_R001157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int stride_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_97_1 > 34)
  {
    acc_1 = ((acc_1 + (stride_97_1 * 2)) + 5) & 127;
    aux_1 ^= stride_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_97_2 > 34)
  {
    acc_2 = ((acc_2 + (stride_97_2 * 2)) + 5) & 127;
    aux_2 ^= stride_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_67_1)
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

  switch (stride_67_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_68_1 = local_arr_1[aux_1 % 3];
  int sample_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_97_1 == stride_97_2);
  assert(stride_67_1 == stride_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_68_1 == sample_68_2);
}

int fn_R001157_5713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int stride_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_97 > 34)
  {
    acc = ((acc + (stride_97 * 2)) + 5) & 127;
    aux ^= stride_97 & 15;
  }
  else
  {
    acc = ((acc - stride_97) + 11) & 127;
    aux += 3;
  }
  int stride_67 = (aux + st.buffer[1]) & 3;
  switch (stride_67)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_68 = local_arr[aux % 3];
  acc = (acc + (sample_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001157_5713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001157_5713_0 st_1 = {0};
  struct Vector3D_R001157_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int offset_65_1 = 0;
  int offset_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_65_1 = ((offset_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_65_2 = ((offset_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_65_1) & 127;
    acc_2 = (acc_2 + offset_65_2) & 127;
  }

  int stride_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_33_1) & 63;
  aux_2 = (aux_2 + stride_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_55_1)
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

  switch (tracker_55_2)
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
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_65_1 == offset_65_2);
  assert(stride_33_1 == stride_33_2);
  assert(tracker_55_1 == tracker_55_2);
}

int fn_R001157_5713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001157_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int offset_65 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_65 = ((offset_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_65) & 127;
  }

  int stride_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_33) & 63;
  acc ^= aux;
  int tracker_55 = (aux + st.buffer[1]) & 3;
  switch (tracker_55)
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

void fn_R001157_5713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st_1 = {0};
  struct MatrixBlock_R001157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_66_1) & 63;
  aux_2 = (aux_2 + pivot_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_90_1)
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

  switch (metric_90_2)
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
  int cursor_69_1 = local_arr_1[aux_1 % 3];
  int cursor_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_69_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_66_1 == pivot_66_2);
  assert(metric_90_1 == metric_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_69_1 == cursor_69_2);
}

int fn_R001157_5713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_66) & 63;
  acc ^= aux;
  int metric_90 = (aux + st.buffer[1]) & 3;
  switch (metric_90)
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
  int cursor_69 = local_arr[aux % 3];
  acc = (acc + (cursor_69 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001157_5713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st_1 = {0};
  struct CipherContext_R001157_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int residue_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_75_1 > 35)
  {
    acc_1 = ((acc_1 + (residue_75_1 * 2)) + 5) & 127;
    aux_1 ^= residue_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_75_2 > 35)
  {
    acc_2 = ((acc_2 + (residue_75_2 * 2)) + 5) & 127;
    aux_2 ^= residue_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_47_1) & 63;
  aux_2 = (aux_2 + offset_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_75_1 == residue_75_2);
  assert(offset_47_1 == offset_47_2);
}

int fn_R001157_5713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int residue_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_75 > 35)
  {
    acc = ((acc + (residue_75 * 2)) + 5) & 127;
    aux ^= residue_75 & 15;
  }
  else
  {
    acc = ((acc - residue_75) + 11) & 127;
    aux += 3;
  }
  int offset_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001157_5713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st_1 = {0};
  struct CipherContext_R001157_5713_1 st_2 = {0};
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
  int tracker_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_40_1 > 50)
  {
    acc_1 = ((acc_1 + (tracker_40_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_40_2 > 50)
  {
    acc_2 = ((acc_2 + (tracker_40_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_83_1)
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

  switch (vector_83_2)
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
  int quotient_72_1 = local_arr_1[aux_1 % 3];
  int quotient_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_72_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_40_1 == tracker_40_2);
  assert(vector_83_1 == vector_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_72_1 == quotient_72_2);
}

int fn_R001157_5713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001157_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_40 > 50)
  {
    acc = ((acc + (tracker_40 * 2)) + 5) & 127;
    aux ^= tracker_40 & 15;
  }
  else
  {
    acc = ((acc - tracker_40) + 11) & 127;
    aux += 3;
  }
  int vector_83 = (aux + st.buffer[1]) & 3;
  switch (vector_83)
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
  int quotient_72 = local_arr[aux % 3];
  acc = (acc + (quotient_72 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001157_5713_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st_1 = {0};
  struct MatrixBlock_R001157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_93_1 = local_arr_1[aux_1 % 3];
  int damping_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_93_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_71_1) & 63;
  aux_2 = (aux_2 + parity_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_45_1 > 11)
  {
    acc_1 = ((acc_1 + (margin_45_1 * 2)) + 5) & 127;
    aux_1 ^= margin_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_45_2 > 11)
  {
    acc_2 = ((acc_2 + (margin_45_2 * 2)) + 5) & 127;
    aux_2 ^= margin_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_93_1 == damping_93_2);
  assert(parity_71_1 == parity_71_2);
  assert(margin_45_1 == margin_45_2);
}

int fn_R001157_5713_19(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int damping_93 = local_arr[aux % 3];
  acc = (acc + (damping_93 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_71) & 63;
  acc ^= aux;
  int margin_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_45 > 11)
  {
    acc = ((acc + (margin_45 * 2)) + 5) & 127;
    aux ^= margin_45 & 15;
  }
  else
  {
    acc = ((acc - margin_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001157_5713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st_1 = {0};
  struct MatrixBlock_R001157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int pivot_26_1 = 0;
  int pivot_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_26_1 = ((pivot_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_26_2 = ((pivot_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_26_1) & 127;
    acc_2 = (acc_2 + pivot_26_2) & 127;
  }

  int bound_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_60_1)
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

  switch (bound_60_2)
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
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_26_1 == pivot_26_2);
  assert(bound_60_1 == bound_60_2);
}

int fn_R001157_5713_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int pivot_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_26 = ((pivot_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_26) & 127;
  }

  int bound_60 = (aux + st.buffer[1]) & 3;
  switch (bound_60)
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

void fn_R001157_5713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001157_5713_0 st_1 = {0};
  struct Vector3D_R001157_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_87_1 = local_arr_1[aux_1 % 3];
  int delta_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_87_2 * 2)) & 127;
  int parity_19_1 = 0;
  int parity_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_19_1 = ((parity_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_19_2 = ((parity_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_19_1) & 127;
    acc_2 = (acc_2 + parity_19_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_87_1 == delta_87_2);
  assert(parity_19_1 == parity_19_2);
}

int fn_R001157_5713_21(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001157_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int delta_87 = local_arr[aux % 3];
  acc = (acc + (delta_87 * 2)) & 127;
  int parity_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_19 = ((parity_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_19) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001157_5713_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st_1 = {0};
  struct MatrixBlock_R001157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_73_1 = local_arr_1[aux_1 % 3];
  int sample_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_73_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_41_1)
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

  switch (sample_41_2)
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
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_73_1 == sample_73_2);
  assert(sample_41_1 == sample_41_2);
}

int fn_R001157_5713_22(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int sample_73 = local_arr[aux % 3];
  acc = (acc + (sample_73 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_41 = (aux + st.buffer[1]) & 3;
  switch (sample_41)
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

void main()
{
  int sec_r001157_0_1;
  int sec_r001157_0_2;
  int sec_r001157_1_1;
  int sec_r001157_1_2;
  int sec_r001157_2_1;
  int sec_r001157_2_2;
  int sec_r001157_3_1;
  int sec_r001157_3_2;
  int sec_r001157_4_1;
  int sec_r001157_4_2;
  int sec_r001157_5_1;
  int sec_r001157_5_2;
  int sec_r001157_6_1;
  int sec_r001157_6_2;
  int sec_r001157_7_1;
  int sec_r001157_7_2;
  int sec_r001157_8_1;
  int sec_r001157_8_2;
  int sec_r001157_9_1;
  int sec_r001157_9_2;
  int sec_r001157_10_1;
  int sec_r001157_10_2;
  int sec_r001157_11_1;
  int sec_r001157_11_2;
  int sec_r001157_12_1;
  int sec_r001157_12_2;
  int sec_r001157_13_1;
  int sec_r001157_13_2;
  int sec_r001157_14_1;
  int sec_r001157_14_2;
  int sec_r001157_15_1;
  int sec_r001157_15_2;
  int sec_r001157_16_1;
  int sec_r001157_16_2;
  int sec_r001157_17_1;
  int sec_r001157_17_2;
  int sec_r001157_18_1;
  int sec_r001157_18_2;
  int sec_r001157_19_1;
  int sec_r001157_19_2;
  int sec_r001157_20_1;
  int sec_r001157_20_2;
  int pub_r001157_0_1;
  int pub_r001157_0_2;
  int pub_r001157_1_1;
  int pub_r001157_1_2;
  int pub_r001157_2_1;
  int pub_r001157_2_2;
  int pub_r001157_3_1;
  int pub_r001157_3_2;
  int pub_r001157_4_1;
  int pub_r001157_4_2;
  int pub_r001157_5_1;
  int pub_r001157_5_2;
  int pub_r001157_6_1;
  int pub_r001157_6_2;
  int pub_r001157_7_1;
  int pub_r001157_7_2;
  int pub_r001157_8_1;
  int pub_r001157_8_2;
  int pub_r001157_9_1;
  int pub_r001157_9_2;
  int pub_r001157_10_1;
  int pub_r001157_10_2;
  int pub_r001157_11_1;
  int pub_r001157_11_2;
  int pub_r001157_12_1;
  int pub_r001157_12_2;
  int pub_r001157_13_1;
  int pub_r001157_13_2;
  int pub_r001157_14_1;
  int pub_r001157_14_2;
  int pub_r001157_15_1;
  int pub_r001157_15_2;
  int pub_r001157_16_1;
  int pub_r001157_16_2;
  int pub_r001157_17_1;
  int pub_r001157_17_2;
  int pub_r001157_18_1;
  int pub_r001157_18_2;
  int pub_r001157_19_1;
  int pub_r001157_19_2;
  int pub_r001157_20_1;
  int pub_r001157_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001157_0_1 >= (-100)) && (pub_r001157_0_1 <= 100));
  __CPROVER_assume((pub_r001157_0_2 >= (-100)) && (pub_r001157_0_2 <= 100));
  __CPROVER_assume((pub_r001157_1_1 >= (-100)) && (pub_r001157_1_1 <= 100));
  __CPROVER_assume((pub_r001157_1_2 >= (-100)) && (pub_r001157_1_2 <= 100));
  __CPROVER_assume((pub_r001157_2_1 >= (-100)) && (pub_r001157_2_1 <= 100));
  __CPROVER_assume((pub_r001157_2_2 >= (-100)) && (pub_r001157_2_2 <= 100));
  __CPROVER_assume((pub_r001157_3_1 >= (-100)) && (pub_r001157_3_1 <= 100));
  __CPROVER_assume((pub_r001157_3_2 >= (-100)) && (pub_r001157_3_2 <= 100));
  __CPROVER_assume((pub_r001157_4_1 >= (-100)) && (pub_r001157_4_1 <= 100));
  __CPROVER_assume((pub_r001157_4_2 >= (-100)) && (pub_r001157_4_2 <= 100));
  __CPROVER_assume((pub_r001157_5_1 >= (-100)) && (pub_r001157_5_1 <= 100));
  __CPROVER_assume((pub_r001157_5_2 >= (-100)) && (pub_r001157_5_2 <= 100));
  __CPROVER_assume((pub_r001157_6_1 >= (-100)) && (pub_r001157_6_1 <= 100));
  __CPROVER_assume((pub_r001157_6_2 >= (-100)) && (pub_r001157_6_2 <= 100));
  __CPROVER_assume((pub_r001157_7_1 >= (-100)) && (pub_r001157_7_1 <= 100));
  __CPROVER_assume((pub_r001157_7_2 >= (-100)) && (pub_r001157_7_2 <= 100));
  __CPROVER_assume((pub_r001157_8_1 >= (-100)) && (pub_r001157_8_1 <= 100));
  __CPROVER_assume((pub_r001157_8_2 >= (-100)) && (pub_r001157_8_2 <= 100));
  __CPROVER_assume((pub_r001157_9_1 >= (-100)) && (pub_r001157_9_1 <= 100));
  __CPROVER_assume((pub_r001157_9_2 >= (-100)) && (pub_r001157_9_2 <= 100));
  __CPROVER_assume((pub_r001157_10_1 >= (-100)) && (pub_r001157_10_1 <= 100));
  __CPROVER_assume((pub_r001157_10_2 >= (-100)) && (pub_r001157_10_2 <= 100));
  __CPROVER_assume((pub_r001157_11_1 >= (-100)) && (pub_r001157_11_1 <= 100));
  __CPROVER_assume((pub_r001157_11_2 >= (-100)) && (pub_r001157_11_2 <= 100));
  __CPROVER_assume((pub_r001157_12_1 >= (-100)) && (pub_r001157_12_1 <= 100));
  __CPROVER_assume((pub_r001157_12_2 >= (-100)) && (pub_r001157_12_2 <= 100));
  __CPROVER_assume((pub_r001157_13_1 >= (-100)) && (pub_r001157_13_1 <= 100));
  __CPROVER_assume((pub_r001157_13_2 >= (-100)) && (pub_r001157_13_2 <= 100));
  __CPROVER_assume((pub_r001157_14_1 >= (-100)) && (pub_r001157_14_1 <= 100));
  __CPROVER_assume((pub_r001157_14_2 >= (-100)) && (pub_r001157_14_2 <= 100));
  __CPROVER_assume((pub_r001157_15_1 >= (-100)) && (pub_r001157_15_1 <= 100));
  __CPROVER_assume((pub_r001157_15_2 >= (-100)) && (pub_r001157_15_2 <= 100));
  __CPROVER_assume((pub_r001157_16_1 >= (-100)) && (pub_r001157_16_1 <= 100));
  __CPROVER_assume((pub_r001157_16_2 >= (-100)) && (pub_r001157_16_2 <= 100));
  __CPROVER_assume((pub_r001157_17_1 >= (-100)) && (pub_r001157_17_1 <= 100));
  __CPROVER_assume((pub_r001157_17_2 >= (-100)) && (pub_r001157_17_2 <= 100));
  __CPROVER_assume((pub_r001157_18_1 >= (-100)) && (pub_r001157_18_1 <= 100));
  __CPROVER_assume((pub_r001157_18_2 >= (-100)) && (pub_r001157_18_2 <= 100));
  __CPROVER_assume((pub_r001157_19_1 >= (-100)) && (pub_r001157_19_1 <= 100));
  __CPROVER_assume((pub_r001157_19_2 >= (-100)) && (pub_r001157_19_2 <= 100));
  __CPROVER_assume((pub_r001157_20_1 >= (-100)) && (pub_r001157_20_1 <= 100));
  __CPROVER_assume((pub_r001157_20_2 >= (-100)) && (pub_r001157_20_2 <= 100));
  __CPROVER_assume((sec_r001157_0_1 >= 0) && (sec_r001157_0_1 <= 255));
  __CPROVER_assume((sec_r001157_0_2 >= 0) && (sec_r001157_0_2 <= 255));
  __CPROVER_assume((sec_r001157_1_1 >= 0) && (sec_r001157_1_1 <= 255));
  __CPROVER_assume((sec_r001157_1_2 >= 0) && (sec_r001157_1_2 <= 255));
  __CPROVER_assume((sec_r001157_2_1 >= 0) && (sec_r001157_2_1 <= 255));
  __CPROVER_assume((sec_r001157_2_2 >= 0) && (sec_r001157_2_2 <= 255));
  __CPROVER_assume((sec_r001157_3_1 >= 0) && (sec_r001157_3_1 <= 255));
  __CPROVER_assume((sec_r001157_3_2 >= 0) && (sec_r001157_3_2 <= 255));
  __CPROVER_assume((sec_r001157_4_1 >= 0) && (sec_r001157_4_1 <= 255));
  __CPROVER_assume((sec_r001157_4_2 >= 0) && (sec_r001157_4_2 <= 255));
  __CPROVER_assume((sec_r001157_5_1 >= 0) && (sec_r001157_5_1 <= 255));
  __CPROVER_assume((sec_r001157_5_2 >= 0) && (sec_r001157_5_2 <= 255));
  __CPROVER_assume((sec_r001157_6_1 >= 0) && (sec_r001157_6_1 <= 255));
  __CPROVER_assume((sec_r001157_6_2 >= 0) && (sec_r001157_6_2 <= 255));
  __CPROVER_assume((sec_r001157_7_1 >= 0) && (sec_r001157_7_1 <= 255));
  __CPROVER_assume((sec_r001157_7_2 >= 0) && (sec_r001157_7_2 <= 255));
  __CPROVER_assume((sec_r001157_8_1 >= 0) && (sec_r001157_8_1 <= 255));
  __CPROVER_assume((sec_r001157_8_2 >= 0) && (sec_r001157_8_2 <= 255));
  __CPROVER_assume((sec_r001157_9_1 >= 0) && (sec_r001157_9_1 <= 255));
  __CPROVER_assume((sec_r001157_9_2 >= 0) && (sec_r001157_9_2 <= 255));
  __CPROVER_assume((sec_r001157_10_1 >= 0) && (sec_r001157_10_1 <= 255));
  __CPROVER_assume((sec_r001157_10_2 >= 0) && (sec_r001157_10_2 <= 255));
  __CPROVER_assume((sec_r001157_11_1 >= 0) && (sec_r001157_11_1 <= 255));
  __CPROVER_assume((sec_r001157_11_2 >= 0) && (sec_r001157_11_2 <= 255));
  __CPROVER_assume((sec_r001157_12_1 >= 0) && (sec_r001157_12_1 <= 255));
  __CPROVER_assume((sec_r001157_12_2 >= 0) && (sec_r001157_12_2 <= 255));
  __CPROVER_assume((sec_r001157_13_1 >= 0) && (sec_r001157_13_1 <= 255));
  __CPROVER_assume((sec_r001157_13_2 >= 0) && (sec_r001157_13_2 <= 255));
  __CPROVER_assume((sec_r001157_14_1 >= 0) && (sec_r001157_14_1 <= 255));
  __CPROVER_assume((sec_r001157_14_2 >= 0) && (sec_r001157_14_2 <= 255));
  __CPROVER_assume((sec_r001157_15_1 >= 0) && (sec_r001157_15_1 <= 255));
  __CPROVER_assume((sec_r001157_15_2 >= 0) && (sec_r001157_15_2 <= 255));
  __CPROVER_assume((sec_r001157_16_1 >= 0) && (sec_r001157_16_1 <= 255));
  __CPROVER_assume((sec_r001157_16_2 >= 0) && (sec_r001157_16_2 <= 255));
  __CPROVER_assume((sec_r001157_17_1 >= 0) && (sec_r001157_17_1 <= 255));
  __CPROVER_assume((sec_r001157_17_2 >= 0) && (sec_r001157_17_2 <= 255));
  __CPROVER_assume((sec_r001157_18_1 >= 0) && (sec_r001157_18_1 <= 255));
  __CPROVER_assume((sec_r001157_18_2 >= 0) && (sec_r001157_18_2 <= 255));
  __CPROVER_assume((sec_r001157_19_1 >= 0) && (sec_r001157_19_1 <= 255));
  __CPROVER_assume((sec_r001157_19_2 >= 0) && (sec_r001157_19_2 <= 255));
  __CPROVER_assume((sec_r001157_20_1 >= 0) && (sec_r001157_20_1 <= 255));
  __CPROVER_assume((sec_r001157_20_2 >= 0) && (sec_r001157_20_2 <= 255));
  struct Vector3D_R001157_5713_0 st_var_0_1 = {0};
  struct Vector3D_R001157_5713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001157_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001157_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001157_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001157_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001157_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001157_0_2 + 7) & 15;
  struct CipherContext_R001157_5713_1 st_var_1_1 = {0};
  struct CipherContext_R001157_5713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001157_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001157_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001157_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001157_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001157_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001157_0_2 + 9) & 15;
  struct MatrixBlock_R001157_5713_2 st_var_2_1 = {0};
  struct MatrixBlock_R001157_5713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001157_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001157_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001157_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001157_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001157_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001157_0_2 + 11) & 15;
  union TelemetryField_R001157_5713_0 u_var_1;
  union TelemetryField_R001157_5713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001157_5713_0(sec_r001157_0_1, pub_r001157_1_1, pub_r001157_2_1, pub_r001157_3_1, pub_r001157_4_1);
  int helper_flow_0_2 = fn_R001157_5713_0(sec_r001157_0_2, pub_r001157_1_2, pub_r001157_2_2, pub_r001157_3_2, pub_r001157_4_2);
  fn_R001157_5713_0_2(sec_r001157_0_1, pub_r001157_1_1, pub_r001157_2_1, pub_r001157_3_1, pub_r001157_4_1, sec_r001157_0_2, pub_r001157_1_2, pub_r001157_2_2, pub_r001157_3_2, pub_r001157_4_2);
  int helper_flow_1_1 = fn_R001157_5713_1(sec_r001157_1_1, sec_r001157_2_1, pub_r001157_3_1, pub_r001157_4_1);
  int helper_flow_1_2 = fn_R001157_5713_1(sec_r001157_1_2, sec_r001157_2_2, pub_r001157_3_2, pub_r001157_4_2);
  fn_R001157_5713_1_2(sec_r001157_1_1, sec_r001157_2_1, pub_r001157_3_1, pub_r001157_4_1, sec_r001157_1_2, sec_r001157_2_2, pub_r001157_3_2, pub_r001157_4_2);
  int helper_flow_2_1 = fn_R001157_5713_2(sec_r001157_2_1, pub_r001157_3_1);
  int helper_flow_2_2 = fn_R001157_5713_2(sec_r001157_2_2, pub_r001157_3_2);
  fn_R001157_5713_2_2(sec_r001157_2_1, pub_r001157_3_1, sec_r001157_2_2, pub_r001157_3_2);
  int helper_flow_3_1 = fn_R001157_5713_3(sec_r001157_3_1, sec_r001157_4_1, pub_r001157_5_1, pub_r001157_6_1);
  int helper_flow_3_2 = fn_R001157_5713_3(sec_r001157_3_2, sec_r001157_4_2, pub_r001157_5_2, pub_r001157_6_2);
  fn_R001157_5713_3_2(sec_r001157_3_1, sec_r001157_4_1, pub_r001157_5_1, pub_r001157_6_1, sec_r001157_3_2, sec_r001157_4_2, pub_r001157_5_2, pub_r001157_6_2);
  int helper_flow_4_1 = fn_R001157_5713_4(sec_r001157_4_1, pub_r001157_5_1);
  int helper_flow_4_2 = fn_R001157_5713_4(sec_r001157_4_2, pub_r001157_5_2);
  fn_R001157_5713_4_2(sec_r001157_4_1, pub_r001157_5_1, sec_r001157_4_2, pub_r001157_5_2);
  int helper_flow_5_1 = fn_R001157_5713_5(sec_r001157_5_1, pub_r001157_6_1, pub_r001157_7_1, pub_r001157_8_1);
  int helper_flow_5_2 = fn_R001157_5713_5(sec_r001157_5_2, pub_r001157_6_2, pub_r001157_7_2, pub_r001157_8_2);
  fn_R001157_5713_5_2(sec_r001157_5_1, pub_r001157_6_1, pub_r001157_7_1, pub_r001157_8_1, sec_r001157_5_2, pub_r001157_6_2, pub_r001157_7_2, pub_r001157_8_2);
  int helper_flow_6_1 = fn_R001157_5713_6(sec_r001157_6_1, pub_r001157_7_1, pub_r001157_8_1);
  int helper_flow_6_2 = fn_R001157_5713_6(sec_r001157_6_2, pub_r001157_7_2, pub_r001157_8_2);
  fn_R001157_5713_6_2(sec_r001157_6_1, pub_r001157_7_1, pub_r001157_8_1, sec_r001157_6_2, pub_r001157_7_2, pub_r001157_8_2);
  int stage_v_0_1 = ((pub_r001157_1_1 * 2) + 43) & 63;
  int stage_v_0_2 = ((pub_r001157_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (sec_r001157_5_1 ^ pub_r001157_13_1) & 63;
  int stage_v_1_2 = (sec_r001157_5_2 ^ pub_r001157_13_2) & 63;
  if ((stage_v_1_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_1_1 * 2)) & 255;
  }
  if ((stage_v_1_2 & 1) != 0)
  {
    if ((helper_flow_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_1_2 * 2)) & 255;
  }
  int stage_v_2_1 = (helper_flow_0_1 ^ pub_r001157_12_1) & 63;
  int stage_v_2_2 = (helper_flow_0_2 ^ pub_r001157_12_2) & 63;
  if ((stage_v_2_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_2_1 * 2)) & 255;
  }
  if ((stage_v_2_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_2_2 * 2)) & 255;
  }
  int stage_v_3_1 = (sec_r001157_3_1 ^ pub_r001157_8_1) & 63;
  int stage_v_3_2 = (sec_r001157_3_2 ^ pub_r001157_8_2) & 63;
  if ((stage_v_3_1 & 1) != 0)
  {
    if ((sec_r001157_6_1 & 2) != 0)
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
    if ((sec_r001157_6_2 & 2) != 0)
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
  int stage_v_4_1 = (helper_flow_4_1 ^ pub_r001157_18_1) & 63;
  int stage_v_4_2 = (helper_flow_4_2 ^ pub_r001157_18_2) & 63;
  if ((stage_v_4_1 & 1) != 0)
  {
    if ((sec_r001157_16_1 & 2) != 0)
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
    if ((sec_r001157_16_2 & 2) != 0)
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
  int stage_v_5_1 = ((pub_r001157_10_1 * 2) + 40) & 63;
  int stage_v_5_2 = ((pub_r001157_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001157_4_1 * 2) + 15) & 63;
  int stage_v_6_2 = ((pub_r001157_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001157_12_1 * 2) + 18) & 63;
  int stage_v_7_2 = ((pub_r001157_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (sec_r001157_7_1 ^ pub_r001157_13_1) & 63;
  int stage_v_8_2 = (sec_r001157_7_2 ^ pub_r001157_13_2) & 63;
  if ((stage_v_8_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
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
    if ((helper_flow_0_2 & 2) != 0)
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
  int stage_v_9_1 = (stage_v_2_1 ^ pub_r001157_17_1) & 63;
  int stage_v_9_2 = (stage_v_2_2 ^ pub_r001157_17_2) & 63;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((sec_r001157_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_9_1 * 2)) & 255;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((sec_r001157_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_9_2 * 2)) & 255;
  }
  int stage_v_10_1 = ((pub_r001157_9_1 * 2) + 10) & 63;
  int stage_v_10_2 = ((pub_r001157_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001157_15_1 * 2) + 33) & 63;
  int stage_v_11_2 = ((pub_r001157_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (stage_v_2_1 ^ pub_r001157_15_1) & 63;
  int stage_v_12_2 = (stage_v_2_2 ^ pub_r001157_15_2) & 63;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
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
    if ((helper_flow_5_2 & 2) != 0)
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
  int stage_v_13_1 = (sec_r001157_11_1 ^ pub_r001157_1_1) & 63;
  int stage_v_13_2 = (sec_r001157_11_2 ^ pub_r001157_1_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_14_1 = (sec_r001157_8_1 ^ pub_r001157_13_1) & 63;
  int stage_v_14_2 = (sec_r001157_8_2 ^ pub_r001157_13_2) & 63;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r001157_8_1 & 2) != 0)
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
    if ((sec_r001157_8_2 & 2) != 0)
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
  int stage_v_15_1 = ((pub_r001157_9_1 * 2) + 36) & 63;
  int stage_v_15_2 = ((pub_r001157_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001157_11_1 * 2) + 10) & 63;
  int stage_v_16_2 = ((pub_r001157_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (sec_r001157_16_1 ^ pub_r001157_11_1) & 63;
  int stage_v_17_2 = (sec_r001157_16_2 ^ pub_r001157_11_2) & 63;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
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
    if ((stage_v_9_2 & 2) != 0)
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
  int stage_v_18_1 = (sec_r001157_20_1 ^ pub_r001157_1_1) & 63;
  int stage_v_18_2 = (sec_r001157_20_2 ^ pub_r001157_1_2) & 63;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r001157_12_1 & 2) != 0)
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
    if ((sec_r001157_12_2 & 2) != 0)
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
  int stage_v_19_1 = (sec_r001157_15_1 ^ pub_r001157_13_1) & 63;
  int stage_v_19_2 = (sec_r001157_15_2 ^ pub_r001157_13_2) & 63;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r001157_2_1 & 2) != 0)
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
    if ((sec_r001157_2_2 & 2) != 0)
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
  int stage_v_20_1 = ((pub_r001157_12_1 * 2) + 5) & 63;
  int stage_v_20_2 = ((pub_r001157_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (helper_flow_3_1 ^ pub_r001157_7_1) & 63;
  int stage_v_21_2 = (helper_flow_3_2 ^ pub_r001157_7_2) & 63;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_21_1 * 2)) & 255;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_21_2 * 2)) & 255;
  }
  int stage_v_22_1 = (sec_r001157_0_1 ^ pub_r001157_14_1) & 63;
  int stage_v_22_2 = (sec_r001157_0_2 ^ pub_r001157_14_2) & 63;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r001157_13_1 & 2) != 0)
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
    if ((sec_r001157_13_2 & 2) != 0)
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
  int stage_v_23_1 = ((pub_r001157_16_1 * 2) + 50) & 63;
  int stage_v_23_2 = ((pub_r001157_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (sec_r001157_1_1 ^ pub_r001157_20_1) & 63;
  int stage_v_24_2 = (sec_r001157_1_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r001157_11_1 & 2) != 0)
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
    if ((sec_r001157_11_2 & 2) != 0)
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
  int stage_v_25_1 = (sec_r001157_20_1 ^ pub_r001157_8_1) & 63;
  int stage_v_25_2 = (sec_r001157_20_2 ^ pub_r001157_8_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_26_1 = ((pub_r001157_20_1 * 2) + 18) & 63;
  int stage_v_26_2 = ((pub_r001157_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = (stage_v_9_1 ^ pub_r001157_13_1) & 63;
  int stage_v_27_2 = (stage_v_9_2 ^ pub_r001157_13_2) & 63;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r001157_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_27_1 * 2)) & 255;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r001157_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_27_2 * 2)) & 255;
  }
  int stage_v_28_1 = ((pub_r001157_19_1 * 2) + 15) & 63;
  int stage_v_28_2 = ((pub_r001157_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (stage_v_1_1 ^ pub_r001157_8_1) & 63;
  int stage_v_29_2 = (stage_v_1_2 ^ pub_r001157_8_2) & 63;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
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
    if ((stage_v_21_2 & 2) != 0)
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
  int stage_v_30_1 = (stage_v_14_1 ^ pub_r001157_3_1) & 63;
  int stage_v_30_2 = (stage_v_14_2 ^ pub_r001157_3_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r001157_12_1 & 2) != 0)
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
    if ((sec_r001157_12_2 & 2) != 0)
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
  int stage_v_31_1 = ((pub_r001157_10_1 * 2) + 50) & 63;
  int stage_v_31_2 = ((pub_r001157_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001157_19_1 * 2) + 18) & 63;
  int stage_v_32_2 = ((pub_r001157_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (sec_r001157_3_1 ^ pub_r001157_8_1) & 63;
  int stage_v_33_2 = (sec_r001157_3_2 ^ pub_r001157_8_2) & 63;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_34_1 = (helper_flow_2_1 ^ pub_r001157_0_1) & 63;
  int stage_v_34_2 = (helper_flow_2_2 ^ pub_r001157_0_2) & 63;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_34_1 * 2)) & 255;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((stage_v_25_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_34_2 * 2)) & 255;
  }
  int stage_v_35_1 = ((pub_r001157_6_1 * 2) + 17) & 63;
  int stage_v_35_2 = ((pub_r001157_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (helper_flow_3_1 ^ pub_r001157_18_1) & 63;
  int stage_v_36_2 = (helper_flow_3_2 ^ pub_r001157_18_2) & 63;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_37_1 = ((pub_r001157_8_1 * 2) + 45) & 63;
  int stage_v_37_2 = ((pub_r001157_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (sec_r001157_1_1 ^ pub_r001157_19_1) & 63;
  int stage_v_38_2 = (sec_r001157_1_2 ^ pub_r001157_19_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
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
    if ((helper_flow_2_2 & 2) != 0)
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
  int stage_v_39_1 = (sec_r001157_19_1 ^ pub_r001157_20_1) & 63;
  int stage_v_39_2 = (sec_r001157_19_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r001157_17_1 & 2) != 0)
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
    if ((sec_r001157_17_2 & 2) != 0)
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
  int stage_v_40_1 = ((pub_r001157_6_1 * 2) + 23) & 63;
  int stage_v_40_2 = ((pub_r001157_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001157_2_1 * 2) + 18) & 63;
  int stage_v_41_2 = ((pub_r001157_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001157_0_1 * 2) + 49) & 63;
  int stage_v_42_2 = ((pub_r001157_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (stage_v_24_1 ^ pub_r001157_8_1) & 63;
  int stage_v_43_2 = (stage_v_24_2 ^ pub_r001157_8_2) & 63;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((stage_v_24_1 & 2) != 0)
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
    if ((stage_v_24_2 & 2) != 0)
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
  int stage_v_44_1 = ((pub_r001157_17_1 * 2) + 47) & 63;
  int stage_v_44_2 = ((pub_r001157_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (sec_r001157_2_1 ^ pub_r001157_8_1) & 63;
  int stage_v_45_2 = (sec_r001157_2_2 ^ pub_r001157_8_2) & 63;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r001157_19_1 & 2) != 0)
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
    if ((sec_r001157_19_2 & 2) != 0)
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
  int stage_v_46_1 = ((pub_r001157_9_1 * 2) + 28) & 63;
  int stage_v_46_2 = ((pub_r001157_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001157_15_1 * 2) + 17) & 63;
  int stage_v_47_2 = ((pub_r001157_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (sec_r001157_17_1 ^ pub_r001157_16_1) & 63;
  int stage_v_48_2 = (sec_r001157_17_2 ^ pub_r001157_16_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
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
    if ((stage_v_21_2 & 2) != 0)
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
  int stage_v_49_1 = ((pub_r001157_6_1 * 2) + 17) & 63;
  int stage_v_49_2 = ((pub_r001157_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001157_14_1 * 2) + 44) & 63;
  int stage_v_50_2 = ((pub_r001157_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (stage_v_38_1 ^ pub_r001157_10_1) & 63;
  int stage_v_51_2 = (stage_v_38_2 ^ pub_r001157_10_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
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
    if ((stage_v_18_2 & 2) != 0)
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
  int stage_v_52_1 = ((pub_r001157_13_1 * 2) + 42) & 63;
  int stage_v_52_2 = ((pub_r001157_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (stage_v_38_1 ^ pub_r001157_10_1) & 63;
  int stage_v_53_2 = (stage_v_38_2 ^ pub_r001157_10_2) & 63;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r001157_11_1 & 2) != 0)
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
    if ((sec_r001157_11_2 & 2) != 0)
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
  int stage_v_54_1 = (stage_v_27_1 ^ pub_r001157_15_1) & 63;
  int stage_v_54_2 = (stage_v_27_2 ^ pub_r001157_15_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
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
    if ((stage_v_9_2 & 2) != 0)
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
  int stage_v_55_1 = (sec_r001157_13_1 ^ pub_r001157_5_1) & 63;
  int stage_v_55_2 = (sec_r001157_13_2 ^ pub_r001157_5_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r001157_17_1 & 2) != 0)
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
    if ((sec_r001157_17_2 & 2) != 0)
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
  int stage_v_56_1 = (sec_r001157_10_1 ^ pub_r001157_2_1) & 63;
  int stage_v_56_2 = (sec_r001157_10_2 ^ pub_r001157_2_2) & 63;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((stage_v_22_1 & 2) != 0)
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
    if ((stage_v_22_2 & 2) != 0)
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
  int stage_v_57_1 = (stage_v_34_1 ^ pub_r001157_15_1) & 63;
  int stage_v_57_2 = (stage_v_34_2 ^ pub_r001157_15_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((stage_v_45_1 & 2) != 0)
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
    if ((stage_v_45_2 & 2) != 0)
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
  int stage_v_58_1 = ((pub_r001157_6_1 * 2) + 11) & 63;
  int stage_v_58_2 = ((pub_r001157_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (helper_flow_4_1 ^ pub_r001157_12_1) & 63;
  int stage_v_59_2 = (helper_flow_4_2 ^ pub_r001157_12_2) & 63;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
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
    if ((stage_v_55_2 & 2) != 0)
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
  int stage_v_60_1 = ((pub_r001157_11_1 * 2) + 50) & 63;
  int stage_v_60_2 = ((pub_r001157_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (stage_v_43_1 ^ pub_r001157_14_1) & 63;
  int stage_v_61_2 = (stage_v_43_2 ^ pub_r001157_14_2) & 63;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
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
    if ((helper_flow_0_2 & 2) != 0)
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
  int stage_v_62_1 = ((pub_r001157_5_1 * 2) + 43) & 63;
  int stage_v_62_2 = ((pub_r001157_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001157_19_1 * 2) + 7) & 63;
  int stage_v_63_2 = ((pub_r001157_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (stage_v_13_1 ^ pub_r001157_20_1) & 63;
  int stage_v_64_2 = (stage_v_13_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r001157_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_64_1 * 2)) & 255;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r001157_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_64_2 * 2)) & 255;
  }
  int stage_v_65_1 = ((pub_r001157_4_1 * 2) + 11) & 63;
  int stage_v_65_2 = ((pub_r001157_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001157_5_1 * 2) + 7) & 63;
  int stage_v_66_2 = ((pub_r001157_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (sec_r001157_0_1 ^ pub_r001157_6_1) & 63;
  int stage_v_67_2 = (sec_r001157_0_2 ^ pub_r001157_6_2) & 63;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r001157_2_1 & 2) != 0)
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
    if ((sec_r001157_2_2 & 2) != 0)
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
  int stage_v_68_1 = (stage_v_21_1 ^ pub_r001157_0_1) & 63;
  int stage_v_68_2 = (stage_v_21_2 ^ pub_r001157_0_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
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
    if ((stage_v_25_2 & 2) != 0)
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
  int stage_v_69_1 = ((pub_r001157_11_1 * 2) + 15) & 63;
  int stage_v_69_2 = ((pub_r001157_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (sec_r001157_13_1 ^ pub_r001157_18_1) & 63;
  int stage_v_70_2 = (sec_r001157_13_2 ^ pub_r001157_18_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((stage_v_29_1 & 2) != 0)
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
    if ((stage_v_29_2 & 2) != 0)
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
  int stage_v_71_1 = (sec_r001157_0_1 ^ pub_r001157_10_1) & 63;
  int stage_v_71_2 = (sec_r001157_0_2 ^ pub_r001157_10_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_72_1 = (stage_v_3_1 ^ pub_r001157_11_1) & 63;
  int stage_v_72_2 = (stage_v_3_2 ^ pub_r001157_11_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
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
    if ((stage_v_12_2 & 2) != 0)
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
  int stage_v_73_1 = (stage_v_17_1 ^ pub_r001157_8_1) & 63;
  int stage_v_73_2 = (stage_v_17_2 ^ pub_r001157_8_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r001157_18_1 & 2) != 0)
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
    if ((sec_r001157_18_2 & 2) != 0)
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
  int stage_v_74_1 = (stage_v_4_1 ^ pub_r001157_2_1) & 63;
  int stage_v_74_2 = (stage_v_4_2 ^ pub_r001157_2_2) & 63;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r001157_6_1 & 2) != 0)
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
    if ((sec_r001157_6_2 & 2) != 0)
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
  int stage_v_75_1 = ((pub_r001157_12_1 * 2) + 11) & 63;
  int stage_v_75_2 = ((pub_r001157_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001157_2_1 * 2) + 7) & 63;
  int stage_v_76_2 = ((pub_r001157_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (stage_v_67_1 ^ pub_r001157_6_1) & 63;
  int stage_v_77_2 = (stage_v_67_2 ^ pub_r001157_6_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r001157_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r001157_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  }
  int stage_v_78_1 = (stage_v_64_1 ^ pub_r001157_10_1) & 63;
  int stage_v_78_2 = (stage_v_64_2 ^ pub_r001157_10_2) & 63;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((stage_v_48_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  }
  int stage_v_79_1 = (sec_r001157_2_1 ^ pub_r001157_10_1) & 63;
  int stage_v_79_2 = (sec_r001157_2_2 ^ pub_r001157_10_2) & 63;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
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
    if ((stage_v_4_2 & 2) != 0)
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
  int stage_v_80_1 = (stage_v_12_1 ^ pub_r001157_9_1) & 63;
  int stage_v_80_2 = (stage_v_12_2 ^ pub_r001157_9_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r001157_19_1 & 2) != 0)
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
    if ((sec_r001157_19_2 & 2) != 0)
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
  int stage_v_81_1 = (sec_r001157_17_1 ^ pub_r001157_4_1) & 63;
  int stage_v_81_2 = (sec_r001157_17_2 ^ pub_r001157_4_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r001157_14_1 & 2) != 0)
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
    if ((sec_r001157_14_2 & 2) != 0)
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
  int stage_v_82_1 = (stage_v_79_1 ^ pub_r001157_20_1) & 63;
  int stage_v_82_2 = (stage_v_79_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r001157_6_1 & 2) != 0)
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
    if ((sec_r001157_6_2 & 2) != 0)
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
  int stage_v_83_1 = ((pub_r001157_12_1 * 2) + 32) & 63;
  int stage_v_83_2 = ((pub_r001157_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (stage_v_51_1 ^ pub_r001157_20_1) & 63;
  int stage_v_84_2 = (stage_v_51_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
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
    if ((stage_v_72_2 & 2) != 0)
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
  int stage_v_85_1 = ((pub_r001157_1_1 * 2) + 28) & 63;
  int stage_v_85_2 = ((pub_r001157_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001157_13_1 * 2) + 41) & 63;
  int stage_v_86_2 = ((pub_r001157_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (stage_v_4_1 ^ pub_r001157_7_1) & 63;
  int stage_v_87_2 = (stage_v_4_2 ^ pub_r001157_7_2) & 63;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((stage_v_36_1 & 2) != 0)
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
    if ((stage_v_36_2 & 2) != 0)
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
  int stage_v_88_1 = ((pub_r001157_4_1 * 2) + 11) & 63;
  int stage_v_88_2 = ((pub_r001157_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (helper_flow_1_1 ^ pub_r001157_20_1) & 63;
  int stage_v_89_2 = (helper_flow_1_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((stage_v_80_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  }
  int stage_v_90_1 = (sec_r001157_17_1 ^ pub_r001157_1_1) & 63;
  int stage_v_90_2 = (sec_r001157_17_2 ^ pub_r001157_1_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((stage_v_70_1 & 2) != 0)
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
    if ((stage_v_70_2 & 2) != 0)
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
  int stage_v_91_1 = (sec_r001157_17_1 ^ pub_r001157_8_1) & 63;
  int stage_v_91_2 = (sec_r001157_17_2 ^ pub_r001157_8_2) & 63;
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
  int stage_v_92_1 = (sec_r001157_18_1 ^ pub_r001157_14_1) & 63;
  int stage_v_92_2 = (sec_r001157_18_2 ^ pub_r001157_14_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((stage_v_43_1 & 2) != 0)
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
    if ((stage_v_43_2 & 2) != 0)
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
  int stage_v_93_1 = (stage_v_22_1 ^ pub_r001157_7_1) & 63;
  int stage_v_93_2 = (stage_v_22_2 ^ pub_r001157_7_2) & 63;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r001157_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r001157_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  }
  int stage_v_94_1 = (stage_v_34_1 ^ pub_r001157_5_1) & 63;
  int stage_v_94_2 = (stage_v_34_2 ^ pub_r001157_5_2) & 63;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
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
    if ((stage_v_19_2 & 2) != 0)
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
  int stage_v_95_1 = ((pub_r001157_19_1 * 2) + 23) & 63;
  int stage_v_95_2 = ((pub_r001157_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001157_2_1 * 2) + 40) & 63;
  int stage_v_96_2 = ((pub_r001157_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (stage_v_82_1 ^ pub_r001157_16_1) & 63;
  int stage_v_97_2 = (stage_v_82_2 ^ pub_r001157_16_2) & 63;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((stage_v_87_1 & 2) != 0)
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
    if ((stage_v_87_2 & 2) != 0)
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
  int stage_v_98_1 = ((pub_r001157_3_1 * 2) + 38) & 63;
  int stage_v_98_2 = ((pub_r001157_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001157_7_1 * 2) + 30) & 63;
  int stage_v_99_2 = ((pub_r001157_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (stage_v_64_1 ^ pub_r001157_17_1) & 63;
  int stage_v_100_2 = (stage_v_64_2 ^ pub_r001157_17_2) & 63;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
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
    if ((stage_v_27_2 & 2) != 0)
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
  int stage_v_101_1 = ((pub_r001157_2_1 * 2) + 20) & 63;
  int stage_v_101_2 = ((pub_r001157_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (stage_v_81_1 ^ pub_r001157_2_1) & 63;
  int stage_v_102_2 = (stage_v_81_2 ^ pub_r001157_2_2) & 63;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((stage_v_91_1 & 2) != 0)
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
    if ((stage_v_91_2 & 2) != 0)
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
  int stage_v_103_1 = (stage_v_18_1 ^ pub_r001157_17_1) & 63;
  int stage_v_103_2 = (stage_v_18_2 ^ pub_r001157_17_2) & 63;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r001157_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r001157_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  }
  int stage_v_104_1 = (stage_v_38_1 ^ pub_r001157_9_1) & 63;
  int stage_v_104_2 = (stage_v_38_2 ^ pub_r001157_9_2) & 63;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((stage_v_97_1 & 2) != 0)
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
    if ((stage_v_97_2 & 2) != 0)
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
  int stage_v_105_1 = ((pub_r001157_10_1 * 2) + 26) & 63;
  int stage_v_105_2 = ((pub_r001157_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001157_8_1 * 2) + 47) & 63;
  int stage_v_106_2 = ((pub_r001157_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001157_12_1 * 2) + 12) & 63;
  int stage_v_107_2 = ((pub_r001157_12_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001157_8_1 * 2) + 38) & 63;
  int stage_v_108_2 = ((pub_r001157_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (stage_v_12_1 ^ pub_r001157_4_1) & 63;
  int stage_v_109_2 = (stage_v_12_2 ^ pub_r001157_4_2) & 63;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((stage_v_64_1 & 2) != 0)
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
    if ((stage_v_64_2 & 2) != 0)
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
  int stage_v_110_1 = (sec_r001157_19_1 ^ pub_r001157_12_1) & 63;
  int stage_v_110_2 = (sec_r001157_19_2 ^ pub_r001157_12_2) & 63;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
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
    if ((stage_v_9_2 & 2) != 0)
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
  int stage_v_111_1 = (stage_v_51_1 ^ pub_r001157_16_1) & 63;
  int stage_v_111_2 = (stage_v_51_2 ^ pub_r001157_16_2) & 63;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((stage_v_71_1 & 2) != 0)
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
    if ((stage_v_71_2 & 2) != 0)
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
  int stage_v_112_1 = (stage_v_43_1 ^ pub_r001157_20_1) & 63;
  int stage_v_112_2 = (stage_v_43_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((stage_v_93_1 & 2) != 0)
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
    if ((stage_v_93_2 & 2) != 0)
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
  int stage_v_113_1 = ((pub_r001157_13_1 * 2) + 42) & 63;
  int stage_v_113_2 = ((pub_r001157_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (sec_r001157_4_1 ^ pub_r001157_19_1) & 63;
  int stage_v_114_2 = (sec_r001157_4_2 ^ pub_r001157_19_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_115_1 = (stage_v_92_1 ^ pub_r001157_8_1) & 63;
  int stage_v_115_2 = (stage_v_92_2 ^ pub_r001157_8_2) & 63;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r001157_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r001157_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  }
  int stage_v_116_1 = (stage_v_68_1 ^ pub_r001157_20_1) & 63;
  int stage_v_116_2 = (stage_v_68_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((stage_v_39_1 & 2) != 0)
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
    if ((stage_v_39_2 & 2) != 0)
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
  int stage_v_117_1 = (stage_v_29_1 ^ pub_r001157_8_1) & 63;
  int stage_v_117_2 = (stage_v_29_2 ^ pub_r001157_8_2) & 63;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r001157_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r001157_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  }
  int stage_v_118_1 = ((pub_r001157_2_1 * 2) + 48) & 63;
  int stage_v_118_2 = ((pub_r001157_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001157_19_1 * 2) + 14) & 63;
  int stage_v_119_2 = ((pub_r001157_19_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (stage_v_97_1 ^ pub_r001157_8_1) & 63;
  int stage_v_120_2 = (stage_v_97_2 ^ pub_r001157_8_2) & 63;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((stage_v_38_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  }
  int stage_v_121_1 = (stage_v_12_1 ^ pub_r001157_14_1) & 63;
  int stage_v_121_2 = (stage_v_12_2 ^ pub_r001157_14_2) & 63;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_122_1 = (stage_v_67_1 ^ pub_r001157_11_1) & 63;
  int stage_v_122_2 = (stage_v_67_2 ^ pub_r001157_11_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
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
    if ((stage_v_38_2 & 2) != 0)
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
  int stage_v_123_1 = (helper_flow_5_1 ^ pub_r001157_10_1) & 63;
  int stage_v_123_2 = (helper_flow_5_2 ^ pub_r001157_10_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
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
    if ((helper_flow_0_2 & 2) != 0)
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
  int stage_v_124_1 = ((pub_r001157_16_1 * 2) + 5) & 63;
  int stage_v_124_2 = ((pub_r001157_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001157_18_1 * 2) + 19) & 63;
  int stage_v_125_2 = ((pub_r001157_18_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001157_9_1 * 2) + 21) & 63;
  int stage_v_126_2 = ((pub_r001157_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001157_5_1 * 2) + 13) & 63;
  int stage_v_127_2 = ((pub_r001157_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (stage_v_82_1 ^ pub_r001157_1_1) & 63;
  int stage_v_128_2 = (stage_v_82_2 ^ pub_r001157_1_2) & 63;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((sec_r001157_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((sec_r001157_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  }
  int stage_v_129_1 = ((pub_r001157_11_1 * 2) + 13) & 63;
  int stage_v_129_2 = ((pub_r001157_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (stage_v_56_1 ^ pub_r001157_5_1) & 63;
  int stage_v_130_2 = (stage_v_56_2 ^ pub_r001157_5_2) & 63;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_131_1 = (stage_v_103_1 ^ pub_r001157_8_1) & 63;
  int stage_v_131_2 = (stage_v_103_2 ^ pub_r001157_8_2) & 63;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((sec_r001157_1_1 & 2) != 0)
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
    if ((sec_r001157_1_2 & 2) != 0)
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
  int stage_v_132_1 = (sec_r001157_5_1 ^ pub_r001157_18_1) & 63;
  int stage_v_132_2 = (sec_r001157_5_2 ^ pub_r001157_18_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((stage_v_94_1 & 2) != 0)
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
    if ((stage_v_94_2 & 2) != 0)
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
  int stage_v_133_1 = ((pub_r001157_3_1 * 2) + 27) & 63;
  int stage_v_133_2 = ((pub_r001157_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001157_9_1 * 2) + 23) & 63;
  int stage_v_134_2 = ((pub_r001157_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001157_13_1 * 2) + 20) & 63;
  int stage_v_135_2 = ((pub_r001157_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (stage_v_116_1 ^ pub_r001157_20_1) & 63;
  int stage_v_136_2 = (stage_v_116_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((stage_v_97_1 & 2) != 0)
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
    if ((stage_v_97_2 & 2) != 0)
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
  int stage_v_137_1 = ((pub_r001157_19_1 * 2) + 24) & 63;
  int stage_v_137_2 = ((pub_r001157_19_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (stage_v_87_1 ^ pub_r001157_15_1) & 63;
  int stage_v_138_2 = (stage_v_87_2 ^ pub_r001157_15_2) & 63;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((stage_v_116_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((stage_v_116_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  }
  int stage_v_139_1 = (stage_v_68_1 ^ pub_r001157_0_1) & 63;
  int stage_v_139_2 = (stage_v_68_2 ^ pub_r001157_0_2) & 63;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((sec_r001157_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  }
  if ((stage_v_139_2 & 1) != 0)
  {
    if ((sec_r001157_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  }
  int stage_v_140_1 = ((pub_r001157_5_1 * 2) + 43) & 63;
  int stage_v_140_2 = ((pub_r001157_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001157_12_1 * 2) + 11) & 63;
  int stage_v_141_2 = ((pub_r001157_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (stage_v_121_1 ^ pub_r001157_16_1) & 63;
  int stage_v_142_2 = (stage_v_121_2 ^ pub_r001157_16_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((stage_v_71_1 & 2) != 0)
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
    if ((stage_v_71_2 & 2) != 0)
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
  int stage_v_143_1 = ((pub_r001157_11_1 * 2) + 18) & 63;
  int stage_v_143_2 = ((pub_r001157_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001157_13_1 * 2) + 49) & 63;
  int stage_v_144_2 = ((pub_r001157_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001157_14_1 * 2) + 17) & 63;
  int stage_v_145_2 = ((pub_r001157_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (stage_v_117_1 ^ pub_r001157_9_1) & 63;
  int stage_v_146_2 = (stage_v_117_2 ^ pub_r001157_9_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((stage_v_100_1 & 2) != 0)
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
    if ((stage_v_100_2 & 2) != 0)
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
  int stage_v_147_1 = ((pub_r001157_13_1 * 2) + 23) & 63;
  int stage_v_147_2 = ((pub_r001157_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (sec_r001157_0_1 ^ pub_r001157_14_1) & 63;
  int stage_v_148_2 = (sec_r001157_0_2 ^ pub_r001157_14_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((stage_v_54_1 & 2) != 0)
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
    if ((stage_v_54_2 & 2) != 0)
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
  int stage_v_149_1 = (stage_v_56_1 ^ pub_r001157_9_1) & 63;
  int stage_v_149_2 = (stage_v_56_2 ^ pub_r001157_9_2) & 63;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((stage_v_115_1 & 2) != 0)
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
    if ((stage_v_115_2 & 2) != 0)
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
  int stage_v_150_1 = (sec_r001157_18_1 ^ pub_r001157_20_1) & 63;
  int stage_v_150_2 = (sec_r001157_18_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((sec_r001157_20_1 & 2) != 0)
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
    if ((sec_r001157_20_2 & 2) != 0)
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
  int stage_v_151_1 = (sec_r001157_17_1 ^ pub_r001157_16_1) & 63;
  int stage_v_151_2 = (sec_r001157_17_2 ^ pub_r001157_16_2) & 63;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((sec_r001157_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  }
  if ((stage_v_151_2 & 1) != 0)
  {
    if ((sec_r001157_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  }
  int stage_v_152_1 = (sec_r001157_12_1 ^ pub_r001157_7_1) & 63;
  int stage_v_152_2 = (sec_r001157_12_2 ^ pub_r001157_7_2) & 63;
  if ((stage_v_152_1 & 1) != 0)
  {
    if ((stage_v_103_1 & 2) != 0)
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
    if ((stage_v_103_2 & 2) != 0)
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
  int stage_v_153_1 = (stage_v_34_1 ^ pub_r001157_2_1) & 63;
  int stage_v_153_2 = (stage_v_34_2 ^ pub_r001157_2_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((stage_v_77_1 & 2) != 0)
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
    if ((stage_v_77_2 & 2) != 0)
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
  int stage_v_154_1 = (stage_v_4_1 ^ pub_r001157_0_1) & 63;
  int stage_v_154_2 = (stage_v_4_2 ^ pub_r001157_0_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((stage_v_104_1 & 2) != 0)
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
    if ((stage_v_104_2 & 2) != 0)
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
  int stage_v_155_1 = ((pub_r001157_19_1 * 2) + 31) & 63;
  int stage_v_155_2 = ((pub_r001157_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (stage_v_71_1 ^ pub_r001157_12_1) & 63;
  int stage_v_156_2 = (stage_v_71_2 ^ pub_r001157_12_2) & 63;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((stage_v_54_1 & 2) != 0)
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
    if ((stage_v_54_2 & 2) != 0)
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
  int stage_v_157_1 = ((pub_r001157_15_1 * 2) + 9) & 63;
  int stage_v_157_2 = ((pub_r001157_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (stage_v_156_1 ^ pub_r001157_19_1) & 63;
  int stage_v_158_2 = (stage_v_156_2 ^ pub_r001157_19_2) & 63;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
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
    if ((helper_flow_1_2 & 2) != 0)
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
  int stage_v_159_1 = ((pub_r001157_19_1 * 2) + 18) & 63;
  int stage_v_159_2 = ((pub_r001157_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (stage_v_18_1 ^ pub_r001157_13_1) & 63;
  int stage_v_160_2 = (stage_v_18_2 ^ pub_r001157_13_2) & 63;
  if ((stage_v_160_1 & 1) != 0)
  {
    if ((stage_v_117_1 & 2) != 0)
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
    if ((stage_v_117_2 & 2) != 0)
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
  int stage_v_161_1 = (stage_v_132_1 ^ pub_r001157_19_1) & 63;
  int stage_v_161_2 = (stage_v_132_2 ^ pub_r001157_19_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((stage_v_115_1 & 2) != 0)
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
    if ((stage_v_115_2 & 2) != 0)
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
  int stage_v_162_1 = (stage_v_80_1 ^ pub_r001157_14_1) & 63;
  int stage_v_162_2 = (stage_v_80_2 ^ pub_r001157_14_2) & 63;
  if ((stage_v_162_1 & 1) != 0)
  {
    if ((stage_v_71_1 & 2) != 0)
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
    if ((stage_v_71_2 & 2) != 0)
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
  int stage_v_163_1 = ((pub_r001157_15_1 * 2) + 29) & 63;
  int stage_v_163_2 = ((pub_r001157_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (stage_v_97_1 ^ pub_r001157_17_1) & 63;
  int stage_v_164_2 = (stage_v_97_2 ^ pub_r001157_17_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
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
    if ((stage_v_3_2 & 2) != 0)
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
  int stage_v_165_1 = ((pub_r001157_14_1 * 2) + 17) & 63;
  int stage_v_165_2 = ((pub_r001157_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (helper_flow_0_1 ^ pub_r001157_5_1) & 63;
  int stage_v_166_2 = (helper_flow_0_2 ^ pub_r001157_5_2) & 63;
  if ((stage_v_166_1 & 1) != 0)
  {
    if ((stage_v_149_1 & 2) != 0)
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
    if ((stage_v_149_2 & 2) != 0)
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
  int stage_v_167_1 = (stage_v_116_1 ^ pub_r001157_20_1) & 63;
  int stage_v_167_2 = (stage_v_116_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((sec_r001157_20_1 & 2) != 0)
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
    if ((sec_r001157_20_2 & 2) != 0)
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
  int stage_v_168_1 = (sec_r001157_9_1 ^ pub_r001157_4_1) & 63;
  int stage_v_168_2 = (sec_r001157_9_2 ^ pub_r001157_4_2) & 63;
  if ((stage_v_168_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
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
    if ((stage_v_80_2 & 2) != 0)
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
  int stage_v_169_1 = (stage_v_138_1 ^ pub_r001157_3_1) & 63;
  int stage_v_169_2 = (stage_v_138_2 ^ pub_r001157_3_2) & 63;
  if ((stage_v_169_1 & 1) != 0)
  {
    if ((stage_v_154_1 & 2) != 0)
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
    if ((stage_v_154_2 & 2) != 0)
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
  int stage_v_170_1 = ((pub_r001157_7_1 * 2) + 49) & 63;
  int stage_v_170_2 = ((pub_r001157_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001157_18_1 * 2) + 31) & 63;
  int stage_v_171_2 = ((pub_r001157_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001157_2_1 * 2) + 43) & 63;
  int stage_v_172_2 = ((pub_r001157_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001157_20_1 * 2) + 25) & 63;
  int stage_v_173_2 = ((pub_r001157_20_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001157_10_1 * 2) + 38) & 63;
  int stage_v_174_2 = ((pub_r001157_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (stage_v_12_1 ^ pub_r001157_13_1) & 63;
  int stage_v_175_2 = (stage_v_12_2 ^ pub_r001157_13_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
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
    if ((stage_v_80_2 & 2) != 0)
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
  int stage_v_176_1 = (stage_v_162_1 ^ pub_r001157_14_1) & 63;
  int stage_v_176_2 = (stage_v_162_2 ^ pub_r001157_14_2) & 63;
  if ((stage_v_176_1 & 1) != 0)
  {
    if ((stage_v_153_1 & 2) != 0)
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
    if ((stage_v_153_2 & 2) != 0)
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
  int stage_v_177_1 = (sec_r001157_13_1 ^ pub_r001157_1_1) & 63;
  int stage_v_177_2 = (sec_r001157_13_2 ^ pub_r001157_1_2) & 63;
  if ((stage_v_177_1 & 1) != 0)
  {
    if ((stage_v_64_1 & 2) != 0)
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
    if ((stage_v_64_2 & 2) != 0)
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
  int stage_v_178_1 = ((pub_r001157_2_1 * 2) + 42) & 63;
  int stage_v_178_2 = ((pub_r001157_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (stage_v_56_1 ^ pub_r001157_3_1) & 63;
  int stage_v_179_2 = (stage_v_56_2 ^ pub_r001157_3_2) & 63;
  if ((stage_v_179_1 & 1) != 0)
  {
    if ((stage_v_164_1 & 2) != 0)
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
    if ((stage_v_164_2 & 2) != 0)
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
  int stage_v_180_1 = (stage_v_90_1 ^ pub_r001157_9_1) & 63;
  int stage_v_180_2 = (stage_v_90_2 ^ pub_r001157_9_2) & 63;
  if ((stage_v_180_1 & 1) != 0)
  {
    if ((stage_v_142_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_180_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  }
  if ((stage_v_180_2 & 1) != 0)
  {
    if ((stage_v_142_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_180_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  }
  int stage_v_181_1 = (stage_v_21_1 ^ pub_r001157_20_1) & 63;
  int stage_v_181_2 = (stage_v_21_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_181_1 & 1) != 0)
  {
    if ((stage_v_161_1 & 2) != 0)
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
    if ((stage_v_161_2 & 2) != 0)
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
  int stage_v_182_1 = (stage_v_17_1 ^ pub_r001157_2_1) & 63;
  int stage_v_182_2 = (stage_v_17_2 ^ pub_r001157_2_2) & 63;
  if ((stage_v_182_1 & 1) != 0)
  {
    if ((stage_v_8_1 & 2) != 0)
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
    if ((stage_v_8_2 & 2) != 0)
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
  int stage_v_183_1 = ((pub_r001157_1_1 * 2) + 10) & 63;
  int stage_v_183_2 = ((pub_r001157_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (sec_r001157_10_1 ^ pub_r001157_20_1) & 63;
  int stage_v_184_2 = (sec_r001157_10_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_184_1 & 1) != 0)
  {
    if ((stage_v_64_1 & 2) != 0)
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
    if ((stage_v_64_2 & 2) != 0)
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
  int stage_v_185_1 = (stage_v_122_1 ^ pub_r001157_20_1) & 63;
  int stage_v_185_2 = (stage_v_122_2 ^ pub_r001157_20_2) & 63;
  if ((stage_v_185_1 & 1) != 0)
  {
    if ((stage_v_112_1 & 2) != 0)
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
    if ((stage_v_112_2 & 2) != 0)
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
  int stage_v_186_1 = ((pub_r001157_14_1 * 2) + 35) & 63;
  int stage_v_186_2 = ((pub_r001157_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (stage_v_22_1 ^ pub_r001157_16_1) & 63;
  int stage_v_187_2 = (stage_v_22_2 ^ pub_r001157_16_2) & 63;
  if ((stage_v_187_1 & 1) != 0)
  {
    if ((sec_r001157_13_1 & 2) != 0)
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
    if ((sec_r001157_13_2 & 2) != 0)
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
  int stage_v_188_1 = (sec_r001157_20_1 ^ pub_r001157_15_1) & 63;
  int stage_v_188_2 = (sec_r001157_20_2 ^ pub_r001157_15_2) & 63;
  if ((stage_v_188_1 & 1) != 0)
  {
    if ((stage_v_162_1 & 2) != 0)
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
    if ((stage_v_162_2 & 2) != 0)
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
  int stage_v_189_1 = ((pub_r001157_4_1 * 2) + 18) & 63;
  int stage_v_189_2 = ((pub_r001157_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001157_1_1 * 2) + 49) & 63;
  int stage_v_190_2 = ((pub_r001157_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001157_15_1 * 2) + 46) & 63;
  int stage_v_191_2 = ((pub_r001157_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001157_16_1 * 2) + 50) & 63;
  int stage_v_192_2 = ((pub_r001157_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (stage_v_91_1 ^ pub_r001157_0_1) & 63;
  int stage_v_193_2 = (stage_v_91_2 ^ pub_r001157_0_2) & 63;
  if ((stage_v_193_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_193_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  }
  if ((stage_v_193_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_193_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  }
  int stage_v_194_1 = ((pub_r001157_10_1 * 2) + 15) & 63;
  int stage_v_194_2 = ((pub_r001157_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (stage_v_59_1 ^ pub_r001157_3_1) & 63;
  int stage_v_195_2 = (stage_v_59_2 ^ pub_r001157_3_2) & 63;
  if ((stage_v_195_1 & 1) != 0)
  {
    if ((stage_v_43_1 & 2) != 0)
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
    if ((stage_v_43_2 & 2) != 0)
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
  int stage_v_196_1 = (sec_r001157_6_1 ^ pub_r001157_13_1) & 63;
  int stage_v_196_2 = (sec_r001157_6_2 ^ pub_r001157_13_2) & 63;
  if ((stage_v_196_1 & 1) != 0)
  {
    if ((sec_r001157_9_1 & 2) != 0)
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
    if ((sec_r001157_9_2 & 2) != 0)
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
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001157_16_1 == pub_r001157_16_2);
  __CPROVER_assume(pub_r001157_5_1 == pub_r001157_5_2);
  __CPROVER_assume(sec_r001157_5_1 != sec_r001157_5_2);
  __CPROVER_assume(pub_r001157_0_1 == pub_r001157_0_2);
  __CPROVER_assume(sec_r001157_13_1 != sec_r001157_13_2);
  __CPROVER_assume(pub_r001157_4_1 == pub_r001157_4_2);
  __CPROVER_assume(pub_r001157_6_1 == pub_r001157_6_2);
  __CPROVER_assume(sec_r001157_3_1 != sec_r001157_3_2);
  __CPROVER_assume(sec_r001157_12_1 != sec_r001157_12_2);
  __CPROVER_assume(pub_r001157_12_1 == pub_r001157_12_2);
  __CPROVER_assume(sec_r001157_15_1 != sec_r001157_15_2);
  __CPROVER_assume(pub_r001157_11_1 == pub_r001157_11_2);
  __CPROVER_assume(sec_r001157_2_1 != sec_r001157_2_2);
  __CPROVER_assume(pub_r001157_18_1 == pub_r001157_18_2);
  __CPROVER_assume(sec_r001157_17_1 != sec_r001157_17_2);
  __CPROVER_assume(pub_r001157_14_1 == pub_r001157_14_2);
  __CPROVER_assume(sec_r001157_10_1 != sec_r001157_10_2);
  __CPROVER_assume(sec_r001157_19_1 != sec_r001157_19_2);
  __CPROVER_assume(pub_r001157_7_1 == pub_r001157_7_2);
  __CPROVER_assume(pub_r001157_3_1 == pub_r001157_3_2);
  __CPROVER_assume(sec_r001157_20_1 != sec_r001157_20_2);
  __CPROVER_assume(pub_r001157_9_1 == pub_r001157_9_2);
  __CPROVER_assume(sec_r001157_0_1 != sec_r001157_0_2);
  __CPROVER_assume(pub_r001157_15_1 == pub_r001157_15_2);
  __CPROVER_assume(sec_r001157_11_1 != sec_r001157_11_2);
  __CPROVER_assume(pub_r001157_13_1 == pub_r001157_13_2);
  __CPROVER_assume(sec_r001157_4_1 != sec_r001157_4_2);
  __CPROVER_assume(sec_r001157_9_1 != sec_r001157_9_2);
  __CPROVER_assume(sec_r001157_18_1 != sec_r001157_18_2);
  __CPROVER_assume(pub_r001157_8_1 == pub_r001157_8_2);
  __CPROVER_assume(sec_r001157_14_1 != sec_r001157_14_2);
  __CPROVER_assume(pub_r001157_19_1 == pub_r001157_19_2);
  __CPROVER_assume(sec_r001157_1_1 != sec_r001157_1_2);
  __CPROVER_assume(pub_r001157_20_1 == pub_r001157_20_2);
  __CPROVER_assume(pub_r001157_2_1 == pub_r001157_2_2);
  __CPROVER_assume(pub_r001157_1_1 == pub_r001157_1_2);
  __CPROVER_assume(pub_r001157_10_1 == pub_r001157_10_2);
  __CPROVER_assume(sec_r001157_8_1 != sec_r001157_8_2);
  __CPROVER_assume(pub_r001157_17_1 == pub_r001157_17_2);
  __CPROVER_assume(sec_r001157_6_1 != sec_r001157_6_2);
  __CPROVER_assume(sec_r001157_16_1 != sec_r001157_16_2);
  __CPROVER_assume(sec_r001157_7_1 != sec_r001157_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.flags == st_var_1_2.flags);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.tag == st_var_1_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.stride == st_var_2_2.stride);
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
}


