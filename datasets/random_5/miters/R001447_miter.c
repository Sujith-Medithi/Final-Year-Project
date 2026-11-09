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
struct CipherContext_R001447_4713_0
{
  int iv;
  int counter;
  short tag;
  unsigned char round_key;
  unsigned char nonce;
  int buffer[3];
};
struct AudioFrame_R001447_4713_1
{
  unsigned char envelope;
  int peak;
  unsigned char sample_rate;
  short gain;
  int buffer[3];
};
struct Vector3D_R001447_4713_2
{
  short coord_x;
  unsigned char heading;
  unsigned char coord_z;
  int norm_sq;
  int buffer[3];
};
struct MatrixBlock_R001447_4713_3
{
  int stride;
  short dim;
  unsigned char trace;
  int density;
  int scale;
  int determinant;
  int buffer[3];
};
union TelemetryField_R001447_4713_0
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
void fn_R001447_4713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001447_4713_3 st_1 = {0};
  struct MatrixBlock_R001447_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int accumulator_93_1 = 0;
  int accumulator_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_93_1 = ((accumulator_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_93_2 = ((accumulator_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_93_1) & 127;
    acc_2 = (acc_2 + accumulator_93_2) & 127;
  }

  int window_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_99_1)
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

  switch (window_99_2)
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
  int coefficient_68_1 = local_arr_1[aux_1 % 3];
  int coefficient_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_68_2 * 2)) & 127;
  int weight_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_66_1 > 15)
  {
    acc_1 = ((acc_1 + (weight_66_1 * 2)) + 5) & 127;
    aux_1 ^= weight_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_66_2 > 15)
  {
    acc_2 = ((acc_2 + (weight_66_2 * 2)) + 5) & 127;
    aux_2 ^= weight_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_93_1 == accumulator_93_2);
  assert(window_99_1 == window_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_68_1 == coefficient_68_2);
  assert(weight_66_1 == weight_66_2);
}

int fn_R001447_4713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001447_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int accumulator_93 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_93 = ((accumulator_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_93) & 127;
  }

  int window_99 = (aux + st.buffer[1]) & 3;
  switch (window_99)
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
  int coefficient_68 = local_arr[aux % 3];
  acc = (acc + (coefficient_68 * 2)) & 127;
  int weight_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_66 > 15)
  {
    acc = ((acc + (weight_66 * 2)) + 5) & 127;
    aux ^= weight_66 & 15;
  }
  else
  {
    acc = ((acc - weight_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001447_4713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001447_4713_1 st_1 = {0};
  struct AudioFrame_R001447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int quantum_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_20_1 > 32)
  {
    acc_1 = ((acc_1 + (quantum_20_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_20_2 > 32)
  {
    acc_2 = ((acc_2 + (quantum_20_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_20_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_38_1 = local_arr_1[aux_1 % 3];
  int phase_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_38_2 * 2)) & 127;
  int vector_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_35_1)
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

  switch (vector_35_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_20_1 == quantum_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_38_1 == phase_38_2);
  assert(vector_35_1 == vector_35_2);
}

int fn_R001447_4713_1(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int quantum_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_20 > 32)
  {
    acc = ((acc + (quantum_20 * 2)) + 5) & 127;
    aux ^= quantum_20 & 15;
  }
  else
  {
    acc = ((acc - quantum_20) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_38 = local_arr[aux % 3];
  acc = (acc + (phase_38 * 2)) & 127;
  int vector_35 = (aux + st.buffer[1]) & 3;
  switch (vector_35)
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

void fn_R001447_4713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001447_4713_0 st_1 = {0};
  struct CipherContext_R001447_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_75_1) & 63;
  aux_2 = (aux_2 + window_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_75_1 == window_75_2);
}

int fn_R001447_4713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001447_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001447_4713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001447_4713_3 st_1 = {0};
  struct MatrixBlock_R001447_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int index_reg_77_1 = 0;
  int index_reg_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_77_1 = ((index_reg_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_77_2 = ((index_reg_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_77_1) & 127;
    acc_2 = (acc_2 + index_reg_77_2) & 127;
  }

  int window_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_43_1 > 14)
  {
    acc_1 = ((acc_1 + (window_43_1 * 2)) + 5) & 127;
    aux_1 ^= window_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_43_2 > 14)
  {
    acc_2 = ((acc_2 + (window_43_2 * 2)) + 5) & 127;
    aux_2 ^= window_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_43_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_77_1 == index_reg_77_2);
  assert(window_43_1 == window_43_2);
}

int fn_R001447_4713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001447_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int index_reg_77 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_77 = ((index_reg_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_77) & 127;
  }

  int window_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_43 > 14)
  {
    acc = ((acc + (window_43 * 2)) + 5) & 127;
    aux ^= window_43 & 15;
  }
  else
  {
    acc = ((acc - window_43) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001447_4713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001447_4713_2 st_1 = {0};
  struct Vector3D_R001447_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_32_1 = local_arr_1[aux_1 % 3];
  int threshold_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_32_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_32_1 == threshold_32_2);
}

int fn_R001447_4713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001447_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int threshold_32 = local_arr[aux % 3];
  acc = (acc + (threshold_32 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001447_4713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001447_4713_3 st_1 = {0};
  struct MatrixBlock_R001447_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int accumulator_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_12_1) & 63;
  aux_2 = (aux_2 + accumulator_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_25_1 = 0;
  int margin_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_25_1 = ((margin_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_25_2 = ((margin_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_25_1) & 127;
    acc_2 = (acc_2 + margin_25_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_12_1 == accumulator_12_2);
  assert(margin_25_1 == margin_25_2);
}

int fn_R001447_4713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001447_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int accumulator_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_12) & 63;
  acc ^= aux;
  int margin_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_25 = ((margin_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_25) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001447_4713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001447_4713_2 st_1 = {0};
  struct Vector3D_R001447_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_17_1 = local_arr_1[aux_1 % 3];
  int cursor_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_17_2 * 2)) & 127;
  int tally_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_52_1 > 19)
  {
    acc_1 = ((acc_1 + (tally_52_1 * 2)) + 5) & 127;
    aux_1 ^= tally_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_52_2 > 19)
  {
    acc_2 = ((acc_2 + (tally_52_2 * 2)) + 5) & 127;
    aux_2 ^= tally_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_66_1 = 0;
  int factor_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_66_1 = ((factor_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_66_2 = ((factor_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_66_1) & 127;
    acc_2 = (acc_2 + factor_66_2) & 127;
  }

  int tracker_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_78_1) & 63;
  aux_2 = (aux_2 + tracker_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_17_1 == cursor_17_2);
  assert(tally_52_1 == tally_52_2);
  assert(factor_66_1 == factor_66_2);
  assert(tracker_78_1 == tracker_78_2);
}

int fn_R001447_4713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001447_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int cursor_17 = local_arr[aux % 3];
  acc = (acc + (cursor_17 * 2)) & 127;
  int tally_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_52 > 19)
  {
    acc = ((acc + (tally_52 * 2)) + 5) & 127;
    aux ^= tally_52 & 15;
  }
  else
  {
    acc = ((acc - tally_52) + 11) & 127;
    aux += 3;
  }
  int factor_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_66 = ((factor_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_66) & 127;
  }

  int tracker_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_78) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001447_4713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001447_4713_0 st_1 = {0};
  struct CipherContext_R001447_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int residue_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_97_1) & 63;
  aux_2 = (aux_2 + residue_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_27_1 > 48)
  {
    acc_1 = ((acc_1 + (segment_27_1 * 2)) + 5) & 127;
    aux_1 ^= segment_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_27_2 > 48)
  {
    acc_2 = ((acc_2 + (segment_27_2 * 2)) + 5) & 127;
    aux_2 ^= segment_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_45_1)
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

  switch (cursor_45_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_97_1 == residue_97_2);
  assert(segment_27_1 == segment_27_2);
  assert(cursor_45_1 == cursor_45_2);
}

int fn_R001447_4713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001447_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int residue_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_97) & 63;
  acc ^= aux;
  int segment_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_27 > 48)
  {
    acc = ((acc + (segment_27 * 2)) + 5) & 127;
    aux ^= segment_27 & 15;
  }
  else
  {
    acc = ((acc - segment_27) + 11) & 127;
    aux += 3;
  }
  int cursor_45 = (aux + st.buffer[1]) & 3;
  switch (cursor_45)
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

void fn_R001447_4713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001447_4713_3 st_1 = {0};
  struct MatrixBlock_R001447_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_47_1 > 45)
  {
    acc_1 = ((acc_1 + (bound_47_1 * 2)) + 5) & 127;
    aux_1 ^= bound_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_47_2 > 45)
  {
    acc_2 = ((acc_2 + (bound_47_2 * 2)) + 5) & 127;
    aux_2 ^= bound_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_36_1 = local_arr_1[aux_1 % 3];
  int window_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_36_2 * 2)) & 127;
  int segment_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_10_1) & 63;
  aux_2 = (aux_2 + segment_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_47_1 == bound_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_36_1 == window_36_2);
  assert(segment_10_1 == segment_10_2);
}

int fn_R001447_4713_8(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001447_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_47 > 45)
  {
    acc = ((acc + (bound_47 * 2)) + 5) & 127;
    aux ^= bound_47 & 15;
  }
  else
  {
    acc = ((acc - bound_47) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_36 = local_arr[aux % 3];
  acc = (acc + (window_36 * 2)) & 127;
  int segment_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_10) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001447_4713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001447_4713_1 st_1 = {0};
  struct AudioFrame_R001447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int accumulator_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_99_1)
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

  switch (accumulator_99_2)
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

  int vector_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_14_1) & 63;
  aux_2 = (aux_2 + vector_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_22_1 > 46)
  {
    acc_1 = ((acc_1 + (damping_22_1 * 2)) + 5) & 127;
    aux_1 ^= damping_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_22_2 > 46)
  {
    acc_2 = ((acc_2 + (damping_22_2 * 2)) + 5) & 127;
    aux_2 ^= damping_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_22_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_99_1 == accumulator_99_2);
  assert(vector_14_1 == vector_14_2);
  assert(damping_22_1 == damping_22_2);
}

int fn_R001447_4713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int accumulator_99 = (aux + st.buffer[1]) & 3;
  switch (accumulator_99)
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

  int vector_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_14) & 63;
  acc ^= aux;
  int damping_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_22 > 46)
  {
    acc = ((acc + (damping_22 * 2)) + 5) & 127;
    aux ^= damping_22 & 15;
  }
  else
  {
    acc = ((acc - damping_22) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001447_4713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001447_4713_0 st_1 = {0};
  struct CipherContext_R001447_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int sample_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_47_1) & 63;
  aux_2 = (aux_2 + sample_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_92_1 > 26)
  {
    acc_1 = ((acc_1 + (phase_92_1 * 2)) + 5) & 127;
    aux_1 ^= phase_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_92_2 > 26)
  {
    acc_2 = ((acc_2 + (phase_92_2 * 2)) + 5) & 127;
    aux_2 ^= phase_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_47_1 == sample_47_2);
  assert(phase_92_1 == phase_92_2);
}

int fn_R001447_4713_10(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001447_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int sample_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_47) & 63;
  acc ^= aux;
  int phase_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_92 > 26)
  {
    acc = ((acc + (phase_92 * 2)) + 5) & 127;
    aux ^= phase_92 & 15;
  }
  else
  {
    acc = ((acc - phase_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001447_4713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001447_4713_3 st_1 = {0};
  struct MatrixBlock_R001447_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int scale_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_13_1 > 46)
  {
    acc_1 = ((acc_1 + (scale_13_1 * 2)) + 5) & 127;
    aux_1 ^= scale_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_13_2 > 46)
  {
    acc_2 = ((acc_2 + (scale_13_2 * 2)) + 5) & 127;
    aux_2 ^= scale_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_52_1 = 0;
  int weight_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_52_1 = ((weight_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_52_2 = ((weight_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_52_1) & 127;
    acc_2 = (acc_2 + weight_52_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_34_1 = local_arr_1[aux_1 % 3];
  int window_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_34_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_13_1 == scale_13_2);
  assert(weight_52_1 == weight_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_34_1 == window_34_2);
}

int fn_R001447_4713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001447_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int scale_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_13 > 46)
  {
    acc = ((acc + (scale_13 * 2)) + 5) & 127;
    aux ^= scale_13 & 15;
  }
  else
  {
    acc = ((acc - scale_13) + 11) & 127;
    aux += 3;
  }
  int weight_52 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_52 = ((weight_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_52) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int window_34 = local_arr[aux % 3];
  acc = (acc + (window_34 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001447_4713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001447_4713_1 st_1 = {0};
  struct AudioFrame_R001447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int sample_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_97_1 > 33)
  {
    acc_1 = ((acc_1 + (sample_97_1 * 2)) + 5) & 127;
    aux_1 ^= sample_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_97_2 > 33)
  {
    acc_2 = ((acc_2 + (sample_97_2 * 2)) + 5) & 127;
    aux_2 ^= sample_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_42_1 = local_arr_1[aux_1 % 3];
  int offset_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_42_2 * 2)) & 127;
  int phase_61_1 = 0;
  int phase_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_61_1 = ((phase_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_61_2 = ((phase_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_61_1) & 127;
    acc_2 = (acc_2 + phase_61_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_97_1 == sample_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_42_1 == offset_42_2);
  assert(phase_61_1 == phase_61_2);
}

int fn_R001447_4713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int sample_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_97 > 33)
  {
    acc = ((acc + (sample_97 * 2)) + 5) & 127;
    aux ^= sample_97 & 15;
  }
  else
  {
    acc = ((acc - sample_97) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_42 = local_arr[aux % 3];
  acc = (acc + (offset_42 * 2)) & 127;
  int phase_61 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_61 = ((phase_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_61) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001447_4713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001447_4713_1 st_1 = {0};
  struct AudioFrame_R001447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int phase_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_25_1) & 63;
  aux_2 = (aux_2 + phase_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_59_1 > 32)
  {
    acc_1 = ((acc_1 + (margin_59_1 * 2)) + 5) & 127;
    aux_1 ^= margin_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_59_2 > 32)
  {
    acc_2 = ((acc_2 + (margin_59_2 * 2)) + 5) & 127;
    aux_2 ^= margin_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_47_1 = 0;
  int metric_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_47_1 = ((metric_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_47_2 = ((metric_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_47_1) & 127;
    acc_2 = (acc_2 + metric_47_2) & 127;
  }

  int sample_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_33_1)
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

  switch (sample_33_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_25_1 == phase_25_2);
  assert(margin_59_1 == margin_59_2);
  assert(metric_47_1 == metric_47_2);
  assert(sample_33_1 == sample_33_2);
}

int fn_R001447_4713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int phase_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_25) & 63;
  acc ^= aux;
  int margin_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_59 > 32)
  {
    acc = ((acc + (margin_59 * 2)) + 5) & 127;
    aux ^= margin_59 & 15;
  }
  else
  {
    acc = ((acc - margin_59) + 11) & 127;
    aux += 3;
  }
  int metric_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_47 = ((metric_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_47) & 127;
  }

  int sample_33 = (aux + st.buffer[1]) & 3;
  switch (sample_33)
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

void fn_R001447_4713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001447_4713_1 st_1 = {0};
  struct AudioFrame_R001447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int vector_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_29_1) & 63;
  aux_2 = (aux_2 + vector_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_91_1 = 0;
  int vector_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_91_1 = ((vector_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_91_2 = ((vector_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_91_1) & 127;
    acc_2 = (acc_2 + vector_91_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_29_1 == vector_29_2);
  assert(vector_91_1 == vector_91_2);
}

int fn_R001447_4713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int vector_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_29) & 63;
  acc ^= aux;
  int vector_91 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_91 = ((vector_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_91) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001447_4713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001447_4713_0 st_1 = {0};
  struct CipherContext_R001447_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int stride_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_78_1)
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

  switch (stride_78_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_70_1 = 0;
  int threshold_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_70_1 = ((threshold_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_70_2 = ((threshold_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_70_1) & 127;
    acc_2 = (acc_2 + threshold_70_2) & 127;
  }

  int vector_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_48_1 > 13)
  {
    acc_1 = ((acc_1 + (vector_48_1 * 2)) + 5) & 127;
    aux_1 ^= vector_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_48_2 > 13)
  {
    acc_2 = ((acc_2 + (vector_48_2 * 2)) + 5) & 127;
    aux_2 ^= vector_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_48_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_78_1 == stride_78_2);
  assert(threshold_70_1 == threshold_70_2);
  assert(vector_48_1 == vector_48_2);
}

int fn_R001447_4713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001447_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int stride_78 = (aux + st.buffer[1]) & 3;
  switch (stride_78)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_70 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_70 = ((threshold_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_70) & 127;
  }

  int vector_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_48 > 13)
  {
    acc = ((acc + (vector_48 * 2)) + 5) & 127;
    aux ^= vector_48 & 15;
  }
  else
  {
    acc = ((acc - vector_48) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001447_4713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001447_4713_2 st_1 = {0};
  struct Vector3D_R001447_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int cursor_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_84_1 > 38)
  {
    acc_1 = ((acc_1 + (cursor_84_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_84_2 > 38)
  {
    acc_2 = ((acc_2 + (cursor_84_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_60_1) & 63;
  aux_2 = (aux_2 + tracker_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_53_1)
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

  switch (scale_53_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_84_1 == cursor_84_2);
  assert(tracker_60_1 == tracker_60_2);
  assert(scale_53_1 == scale_53_2);
}

int fn_R001447_4713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001447_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int cursor_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_84 > 38)
  {
    acc = ((acc + (cursor_84 * 2)) + 5) & 127;
    aux ^= cursor_84 & 15;
  }
  else
  {
    acc = ((acc - cursor_84) + 11) & 127;
    aux += 3;
  }
  int tracker_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_60) & 63;
  acc ^= aux;
  int scale_53 = (aux + st.buffer[1]) & 3;
  switch (scale_53)
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
  int sec_r001447_0_1;
  int sec_r001447_0_2;
  int sec_r001447_1_1;
  int sec_r001447_1_2;
  int sec_r001447_2_1;
  int sec_r001447_2_2;
  int sec_r001447_3_1;
  int sec_r001447_3_2;
  int sec_r001447_4_1;
  int sec_r001447_4_2;
  int sec_r001447_5_1;
  int sec_r001447_5_2;
  int sec_r001447_6_1;
  int sec_r001447_6_2;
  int sec_r001447_7_1;
  int sec_r001447_7_2;
  int sec_r001447_8_1;
  int sec_r001447_8_2;
  int sec_r001447_9_1;
  int sec_r001447_9_2;
  int sec_r001447_10_1;
  int sec_r001447_10_2;
  int sec_r001447_11_1;
  int sec_r001447_11_2;
  int sec_r001447_12_1;
  int sec_r001447_12_2;
  int sec_r001447_13_1;
  int sec_r001447_13_2;
  int sec_r001447_14_1;
  int sec_r001447_14_2;
  int sec_r001447_15_1;
  int sec_r001447_15_2;
  int sec_r001447_16_1;
  int sec_r001447_16_2;
  int sec_r001447_17_1;
  int sec_r001447_17_2;
  int sec_r001447_18_1;
  int sec_r001447_18_2;
  int sec_r001447_19_1;
  int sec_r001447_19_2;
  int sec_r001447_20_1;
  int sec_r001447_20_2;
  int sec_r001447_21_1;
  int sec_r001447_21_2;
  int pub_r001447_0_1;
  int pub_r001447_0_2;
  int pub_r001447_1_1;
  int pub_r001447_1_2;
  int pub_r001447_2_1;
  int pub_r001447_2_2;
  int pub_r001447_3_1;
  int pub_r001447_3_2;
  int pub_r001447_4_1;
  int pub_r001447_4_2;
  int pub_r001447_5_1;
  int pub_r001447_5_2;
  int pub_r001447_6_1;
  int pub_r001447_6_2;
  int pub_r001447_7_1;
  int pub_r001447_7_2;
  int pub_r001447_8_1;
  int pub_r001447_8_2;
  int pub_r001447_9_1;
  int pub_r001447_9_2;
  int pub_r001447_10_1;
  int pub_r001447_10_2;
  int pub_r001447_11_1;
  int pub_r001447_11_2;
  int pub_r001447_12_1;
  int pub_r001447_12_2;
  int pub_r001447_13_1;
  int pub_r001447_13_2;
  int pub_r001447_14_1;
  int pub_r001447_14_2;
  int pub_r001447_15_1;
  int pub_r001447_15_2;
  int pub_r001447_16_1;
  int pub_r001447_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001447_0_1 >= (-100)) && (pub_r001447_0_1 <= 100));
  __CPROVER_assume((pub_r001447_0_2 >= (-100)) && (pub_r001447_0_2 <= 100));
  __CPROVER_assume((pub_r001447_1_1 >= (-100)) && (pub_r001447_1_1 <= 100));
  __CPROVER_assume((pub_r001447_1_2 >= (-100)) && (pub_r001447_1_2 <= 100));
  __CPROVER_assume((pub_r001447_2_1 >= (-100)) && (pub_r001447_2_1 <= 100));
  __CPROVER_assume((pub_r001447_2_2 >= (-100)) && (pub_r001447_2_2 <= 100));
  __CPROVER_assume((pub_r001447_3_1 >= (-100)) && (pub_r001447_3_1 <= 100));
  __CPROVER_assume((pub_r001447_3_2 >= (-100)) && (pub_r001447_3_2 <= 100));
  __CPROVER_assume((pub_r001447_4_1 >= (-100)) && (pub_r001447_4_1 <= 100));
  __CPROVER_assume((pub_r001447_4_2 >= (-100)) && (pub_r001447_4_2 <= 100));
  __CPROVER_assume((pub_r001447_5_1 >= (-100)) && (pub_r001447_5_1 <= 100));
  __CPROVER_assume((pub_r001447_5_2 >= (-100)) && (pub_r001447_5_2 <= 100));
  __CPROVER_assume((pub_r001447_6_1 >= (-100)) && (pub_r001447_6_1 <= 100));
  __CPROVER_assume((pub_r001447_6_2 >= (-100)) && (pub_r001447_6_2 <= 100));
  __CPROVER_assume((pub_r001447_7_1 >= (-100)) && (pub_r001447_7_1 <= 100));
  __CPROVER_assume((pub_r001447_7_2 >= (-100)) && (pub_r001447_7_2 <= 100));
  __CPROVER_assume((pub_r001447_8_1 >= (-100)) && (pub_r001447_8_1 <= 100));
  __CPROVER_assume((pub_r001447_8_2 >= (-100)) && (pub_r001447_8_2 <= 100));
  __CPROVER_assume((pub_r001447_9_1 >= (-100)) && (pub_r001447_9_1 <= 100));
  __CPROVER_assume((pub_r001447_9_2 >= (-100)) && (pub_r001447_9_2 <= 100));
  __CPROVER_assume((pub_r001447_10_1 >= (-100)) && (pub_r001447_10_1 <= 100));
  __CPROVER_assume((pub_r001447_10_2 >= (-100)) && (pub_r001447_10_2 <= 100));
  __CPROVER_assume((pub_r001447_11_1 >= (-100)) && (pub_r001447_11_1 <= 100));
  __CPROVER_assume((pub_r001447_11_2 >= (-100)) && (pub_r001447_11_2 <= 100));
  __CPROVER_assume((pub_r001447_12_1 >= (-100)) && (pub_r001447_12_1 <= 100));
  __CPROVER_assume((pub_r001447_12_2 >= (-100)) && (pub_r001447_12_2 <= 100));
  __CPROVER_assume((pub_r001447_13_1 >= (-100)) && (pub_r001447_13_1 <= 100));
  __CPROVER_assume((pub_r001447_13_2 >= (-100)) && (pub_r001447_13_2 <= 100));
  __CPROVER_assume((pub_r001447_14_1 >= (-100)) && (pub_r001447_14_1 <= 100));
  __CPROVER_assume((pub_r001447_14_2 >= (-100)) && (pub_r001447_14_2 <= 100));
  __CPROVER_assume((pub_r001447_15_1 >= (-100)) && (pub_r001447_15_1 <= 100));
  __CPROVER_assume((pub_r001447_15_2 >= (-100)) && (pub_r001447_15_2 <= 100));
  __CPROVER_assume((pub_r001447_16_1 >= (-100)) && (pub_r001447_16_1 <= 100));
  __CPROVER_assume((pub_r001447_16_2 >= (-100)) && (pub_r001447_16_2 <= 100));
  __CPROVER_assume((sec_r001447_0_1 >= 0) && (sec_r001447_0_1 <= 255));
  __CPROVER_assume((sec_r001447_0_2 >= 0) && (sec_r001447_0_2 <= 255));
  __CPROVER_assume((sec_r001447_1_1 >= 0) && (sec_r001447_1_1 <= 255));
  __CPROVER_assume((sec_r001447_1_2 >= 0) && (sec_r001447_1_2 <= 255));
  __CPROVER_assume((sec_r001447_2_1 >= 0) && (sec_r001447_2_1 <= 255));
  __CPROVER_assume((sec_r001447_2_2 >= 0) && (sec_r001447_2_2 <= 255));
  __CPROVER_assume((sec_r001447_3_1 >= 0) && (sec_r001447_3_1 <= 255));
  __CPROVER_assume((sec_r001447_3_2 >= 0) && (sec_r001447_3_2 <= 255));
  __CPROVER_assume((sec_r001447_4_1 >= 0) && (sec_r001447_4_1 <= 255));
  __CPROVER_assume((sec_r001447_4_2 >= 0) && (sec_r001447_4_2 <= 255));
  __CPROVER_assume((sec_r001447_5_1 >= 0) && (sec_r001447_5_1 <= 255));
  __CPROVER_assume((sec_r001447_5_2 >= 0) && (sec_r001447_5_2 <= 255));
  __CPROVER_assume((sec_r001447_6_1 >= 0) && (sec_r001447_6_1 <= 255));
  __CPROVER_assume((sec_r001447_6_2 >= 0) && (sec_r001447_6_2 <= 255));
  __CPROVER_assume((sec_r001447_7_1 >= 0) && (sec_r001447_7_1 <= 255));
  __CPROVER_assume((sec_r001447_7_2 >= 0) && (sec_r001447_7_2 <= 255));
  __CPROVER_assume((sec_r001447_8_1 >= 0) && (sec_r001447_8_1 <= 255));
  __CPROVER_assume((sec_r001447_8_2 >= 0) && (sec_r001447_8_2 <= 255));
  __CPROVER_assume((sec_r001447_9_1 >= 0) && (sec_r001447_9_1 <= 255));
  __CPROVER_assume((sec_r001447_9_2 >= 0) && (sec_r001447_9_2 <= 255));
  __CPROVER_assume((sec_r001447_10_1 >= 0) && (sec_r001447_10_1 <= 255));
  __CPROVER_assume((sec_r001447_10_2 >= 0) && (sec_r001447_10_2 <= 255));
  __CPROVER_assume((sec_r001447_11_1 >= 0) && (sec_r001447_11_1 <= 255));
  __CPROVER_assume((sec_r001447_11_2 >= 0) && (sec_r001447_11_2 <= 255));
  __CPROVER_assume((sec_r001447_12_1 >= 0) && (sec_r001447_12_1 <= 255));
  __CPROVER_assume((sec_r001447_12_2 >= 0) && (sec_r001447_12_2 <= 255));
  __CPROVER_assume((sec_r001447_13_1 >= 0) && (sec_r001447_13_1 <= 255));
  __CPROVER_assume((sec_r001447_13_2 >= 0) && (sec_r001447_13_2 <= 255));
  __CPROVER_assume((sec_r001447_14_1 >= 0) && (sec_r001447_14_1 <= 255));
  __CPROVER_assume((sec_r001447_14_2 >= 0) && (sec_r001447_14_2 <= 255));
  __CPROVER_assume((sec_r001447_15_1 >= 0) && (sec_r001447_15_1 <= 255));
  __CPROVER_assume((sec_r001447_15_2 >= 0) && (sec_r001447_15_2 <= 255));
  __CPROVER_assume((sec_r001447_16_1 >= 0) && (sec_r001447_16_1 <= 255));
  __CPROVER_assume((sec_r001447_16_2 >= 0) && (sec_r001447_16_2 <= 255));
  __CPROVER_assume((sec_r001447_17_1 >= 0) && (sec_r001447_17_1 <= 255));
  __CPROVER_assume((sec_r001447_17_2 >= 0) && (sec_r001447_17_2 <= 255));
  __CPROVER_assume((sec_r001447_18_1 >= 0) && (sec_r001447_18_1 <= 255));
  __CPROVER_assume((sec_r001447_18_2 >= 0) && (sec_r001447_18_2 <= 255));
  __CPROVER_assume((sec_r001447_19_1 >= 0) && (sec_r001447_19_1 <= 255));
  __CPROVER_assume((sec_r001447_19_2 >= 0) && (sec_r001447_19_2 <= 255));
  __CPROVER_assume((sec_r001447_20_1 >= 0) && (sec_r001447_20_1 <= 255));
  __CPROVER_assume((sec_r001447_20_2 >= 0) && (sec_r001447_20_2 <= 255));
  __CPROVER_assume((sec_r001447_21_1 >= 0) && (sec_r001447_21_1 <= 255));
  __CPROVER_assume((sec_r001447_21_2 >= 0) && (sec_r001447_21_2 <= 255));
  struct CipherContext_R001447_4713_0 st_var_0_1 = {0};
  struct CipherContext_R001447_4713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001447_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001447_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001447_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001447_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001447_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001447_0_2 + 7) & 15;
  struct AudioFrame_R001447_4713_1 st_var_1_1 = {0};
  struct AudioFrame_R001447_4713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001447_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001447_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001447_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001447_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001447_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001447_0_2 + 9) & 15;
  struct Vector3D_R001447_4713_2 st_var_2_1 = {0};
  struct Vector3D_R001447_4713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001447_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001447_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001447_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001447_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001447_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001447_0_2 + 11) & 15;
  struct MatrixBlock_R001447_4713_3 st_var_3_1 = {0};
  struct MatrixBlock_R001447_4713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001447_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001447_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001447_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001447_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001447_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001447_0_2 + 13) & 15;
  union TelemetryField_R001447_4713_0 u_var_1;
  union TelemetryField_R001447_4713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001447_4713_0(sec_r001447_0_1, pub_r001447_1_1, pub_r001447_2_1, pub_r001447_3_1);
  int helper_flow_0_2 = fn_R001447_4713_0(sec_r001447_0_2, pub_r001447_1_2, pub_r001447_2_2, pub_r001447_3_2);
  fn_R001447_4713_0_2(sec_r001447_0_1, pub_r001447_1_1, pub_r001447_2_1, pub_r001447_3_1, sec_r001447_0_2, pub_r001447_1_2, pub_r001447_2_2, pub_r001447_3_2);
  int helper_flow_1_1 = fn_R001447_4713_1(sec_r001447_1_1, sec_r001447_2_1);
  int helper_flow_1_2 = fn_R001447_4713_1(sec_r001447_1_2, sec_r001447_2_2);
  fn_R001447_4713_1_2(sec_r001447_1_1, sec_r001447_2_1, sec_r001447_1_2, sec_r001447_2_2);
  int helper_flow_2_1 = fn_R001447_4713_2(sec_r001447_2_1, sec_r001447_3_1, pub_r001447_4_1);
  int helper_flow_2_2 = fn_R001447_4713_2(sec_r001447_2_2, sec_r001447_3_2, pub_r001447_4_2);
  fn_R001447_4713_2_2(sec_r001447_2_1, sec_r001447_3_1, pub_r001447_4_1, sec_r001447_2_2, sec_r001447_3_2, pub_r001447_4_2);
  int helper_flow_3_1 = fn_R001447_4713_3(sec_r001447_3_1, sec_r001447_4_1, pub_r001447_5_1, pub_r001447_6_1);
  int helper_flow_3_2 = fn_R001447_4713_3(sec_r001447_3_2, sec_r001447_4_2, pub_r001447_5_2, pub_r001447_6_2);
  fn_R001447_4713_3_2(sec_r001447_3_1, sec_r001447_4_1, pub_r001447_5_1, pub_r001447_6_1, sec_r001447_3_2, sec_r001447_4_2, pub_r001447_5_2, pub_r001447_6_2);
  int helper_flow_4_1 = fn_R001447_4713_4(sec_r001447_4_1, pub_r001447_5_1, pub_r001447_6_1, pub_r001447_7_1, pub_r001447_8_1);
  int helper_flow_4_2 = fn_R001447_4713_4(sec_r001447_4_2, pub_r001447_5_2, pub_r001447_6_2, pub_r001447_7_2, pub_r001447_8_2);
  fn_R001447_4713_4_2(sec_r001447_4_1, pub_r001447_5_1, pub_r001447_6_1, pub_r001447_7_1, pub_r001447_8_1, sec_r001447_4_2, pub_r001447_5_2, pub_r001447_6_2, pub_r001447_7_2, pub_r001447_8_2);
  int helper_flow_5_1 = fn_R001447_4713_5(sec_r001447_5_1, pub_r001447_6_1, pub_r001447_7_1, pub_r001447_8_1);
  int helper_flow_5_2 = fn_R001447_4713_5(sec_r001447_5_2, pub_r001447_6_2, pub_r001447_7_2, pub_r001447_8_2);
  fn_R001447_4713_5_2(sec_r001447_5_1, pub_r001447_6_1, pub_r001447_7_1, pub_r001447_8_1, sec_r001447_5_2, pub_r001447_6_2, pub_r001447_7_2, pub_r001447_8_2);
  int helper_flow_6_1 = fn_R001447_4713_6(sec_r001447_6_1, sec_r001447_7_1, pub_r001447_8_1, pub_r001447_9_1, pub_r001447_10_1);
  int helper_flow_6_2 = fn_R001447_4713_6(sec_r001447_6_2, sec_r001447_7_2, pub_r001447_8_2, pub_r001447_9_2, pub_r001447_10_2);
  fn_R001447_4713_6_2(sec_r001447_6_1, sec_r001447_7_1, pub_r001447_8_1, pub_r001447_9_1, pub_r001447_10_1, sec_r001447_6_2, sec_r001447_7_2, pub_r001447_8_2, pub_r001447_9_2, pub_r001447_10_2);
  int stage_v_0_1 = ((pub_r001447_2_1 * 2) + 23) & 63;
  int stage_v_0_2 = ((pub_r001447_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (sec_r001447_6_1 ^ pub_r001447_7_1) & 63;
  int stage_v_1_2 = (sec_r001447_6_2 ^ pub_r001447_7_2) & 63;
  if ((stage_v_1_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_2_1 = (sec_r001447_14_1 ^ pub_r001447_5_1) & 63;
  int stage_v_2_2 = (sec_r001447_14_2 ^ pub_r001447_5_2) & 63;
  if ((stage_v_2_1 & 1) != 0)
  {
    if ((sec_r001447_3_1 & 2) != 0)
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
    if ((sec_r001447_3_2 & 2) != 0)
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
  int stage_v_3_1 = (sec_r001447_3_1 ^ pub_r001447_5_1) & 63;
  int stage_v_3_2 = (sec_r001447_3_2 ^ pub_r001447_5_2) & 63;
  if ((stage_v_3_1 & 1) != 0)
  {
    if ((sec_r001447_9_1 & 2) != 0)
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
    if ((sec_r001447_9_2 & 2) != 0)
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
  int stage_v_4_1 = ((pub_r001447_0_1 * 2) + 49) & 63;
  int stage_v_4_2 = ((pub_r001447_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001447_14_1 * 2) + 40) & 63;
  int stage_v_5_2 = ((pub_r001447_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (sec_r001447_9_1 ^ pub_r001447_14_1) & 63;
  int stage_v_6_2 = (sec_r001447_9_2 ^ pub_r001447_14_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((sec_r001447_20_1 & 2) != 0)
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
    if ((sec_r001447_20_2 & 2) != 0)
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
  int stage_v_7_1 = (sec_r001447_3_1 ^ pub_r001447_5_1) & 63;
  int stage_v_7_2 = (sec_r001447_3_2 ^ pub_r001447_5_2) & 63;
  if ((stage_v_7_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
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
    if ((stage_v_2_2 & 2) != 0)
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
  int stage_v_8_1 = (sec_r001447_9_1 ^ pub_r001447_2_1) & 63;
  int stage_v_8_2 = (sec_r001447_9_2 ^ pub_r001447_2_2) & 63;
  if ((stage_v_8_1 & 1) != 0)
  {
    if ((sec_r001447_3_1 & 2) != 0)
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
    if ((sec_r001447_3_2 & 2) != 0)
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
  int stage_v_9_1 = ((pub_r001447_12_1 * 2) + 28) & 63;
  int stage_v_9_2 = ((pub_r001447_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001447_11_1 * 2) + 36) & 63;
  int stage_v_10_2 = ((pub_r001447_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (stage_v_6_1 ^ pub_r001447_3_1) & 63;
  int stage_v_11_2 = (stage_v_6_2 ^ pub_r001447_3_2) & 63;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((stage_v_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_11_1 * 2)) & 255;
  }
  if ((stage_v_11_2 & 1) != 0)
  {
    if ((stage_v_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_11_2 * 2)) & 255;
  }
  int stage_v_12_1 = ((pub_r001447_10_1 * 2) + 28) & 63;
  int stage_v_12_2 = ((pub_r001447_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (sec_r001447_13_1 ^ pub_r001447_5_1) & 63;
  int stage_v_13_2 = (sec_r001447_13_2 ^ pub_r001447_5_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r001447_13_1 & 2) != 0)
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
    if ((sec_r001447_13_2 & 2) != 0)
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
  int stage_v_14_1 = ((pub_r001447_16_1 * 2) + 30) & 63;
  int stage_v_14_2 = ((pub_r001447_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001447_10_1 * 2) + 39) & 63;
  int stage_v_15_2 = ((pub_r001447_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (stage_v_2_1 ^ pub_r001447_16_1) & 63;
  int stage_v_16_2 = (stage_v_2_2 ^ pub_r001447_16_2) & 63;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r001447_18_1 & 2) != 0)
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
    if ((sec_r001447_18_2 & 2) != 0)
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
  int stage_v_17_1 = ((pub_r001447_15_1 * 2) + 25) & 63;
  int stage_v_17_2 = ((pub_r001447_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001447_5_1 * 2) + 33) & 63;
  int stage_v_18_2 = ((pub_r001447_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001447_10_1 * 2) + 6) & 63;
  int stage_v_19_2 = ((pub_r001447_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (stage_v_6_1 ^ pub_r001447_1_1) & 63;
  int stage_v_20_2 = (stage_v_6_2 ^ pub_r001447_1_2) & 63;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r001447_18_1 & 2) != 0)
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
    if ((sec_r001447_18_2 & 2) != 0)
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
  int stage_v_21_1 = (sec_r001447_3_1 ^ pub_r001447_15_1) & 63;
  int stage_v_21_2 = (sec_r001447_3_2 ^ pub_r001447_15_2) & 63;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((stage_v_11_1 & 2) != 0)
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
    if ((stage_v_11_2 & 2) != 0)
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
  int stage_v_22_1 = (sec_r001447_16_1 ^ pub_r001447_12_1) & 63;
  int stage_v_22_2 = (sec_r001447_16_2 ^ pub_r001447_12_2) & 63;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r001447_3_1 & 2) != 0)
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
    if ((sec_r001447_3_2 & 2) != 0)
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
  int stage_v_23_1 = ((pub_r001447_14_1 * 2) + 31) & 63;
  int stage_v_23_2 = ((pub_r001447_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001447_2_1 * 2) + 29) & 63;
  int stage_v_24_2 = ((pub_r001447_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (sec_r001447_2_1 ^ pub_r001447_9_1) & 63;
  int stage_v_25_2 = (sec_r001447_2_2 ^ pub_r001447_9_2) & 63;
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
  int stage_v_26_1 = ((pub_r001447_15_1 * 2) + 39) & 63;
  int stage_v_26_2 = ((pub_r001447_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001447_8_1 * 2) + 10) & 63;
  int stage_v_27_2 = ((pub_r001447_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (sec_r001447_2_1 ^ pub_r001447_10_1) & 63;
  int stage_v_28_2 = (sec_r001447_2_2 ^ pub_r001447_10_2) & 63;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_29_1 = ((pub_r001447_2_1 * 2) + 32) & 63;
  int stage_v_29_2 = ((pub_r001447_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (stage_v_7_1 ^ pub_r001447_9_1) & 63;
  int stage_v_30_2 = (stage_v_7_2 ^ pub_r001447_9_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r001447_15_1 & 2) != 0)
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
    if ((sec_r001447_15_2 & 2) != 0)
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
  int stage_v_31_1 = (sec_r001447_4_1 ^ pub_r001447_2_1) & 63;
  int stage_v_31_2 = (sec_r001447_4_2 ^ pub_r001447_2_2) & 63;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r001447_2_1 & 2) != 0)
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
    if ((sec_r001447_2_2 & 2) != 0)
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
  int stage_v_32_1 = (stage_v_28_1 ^ pub_r001447_13_1) & 63;
  int stage_v_32_2 = (stage_v_28_2 ^ pub_r001447_13_2) & 63;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
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
    if ((stage_v_31_2 & 2) != 0)
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
  int stage_v_33_1 = (sec_r001447_21_1 ^ pub_r001447_0_1) & 63;
  int stage_v_33_2 = (sec_r001447_21_2 ^ pub_r001447_0_2) & 63;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r001447_11_1 & 2) != 0)
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
    if ((sec_r001447_11_2 & 2) != 0)
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
  int stage_v_34_1 = (sec_r001447_5_1 ^ pub_r001447_5_1) & 63;
  int stage_v_34_2 = (sec_r001447_5_2 ^ pub_r001447_5_2) & 63;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
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
    if ((helper_flow_6_2 & 2) != 0)
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
  int stage_v_35_1 = ((pub_r001447_15_1 * 2) + 50) & 63;
  int stage_v_35_2 = ((pub_r001447_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001447_2_1 * 2) + 49) & 63;
  int stage_v_36_2 = ((pub_r001447_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (stage_v_32_1 ^ pub_r001447_14_1) & 63;
  int stage_v_37_2 = (stage_v_32_2 ^ pub_r001447_14_2) & 63;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
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
    if ((stage_v_31_2 & 2) != 0)
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
  int stage_v_38_1 = (sec_r001447_19_1 ^ pub_r001447_4_1) & 63;
  int stage_v_38_2 = (sec_r001447_19_2 ^ pub_r001447_4_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
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
    if ((stage_v_21_2 & 2) != 0)
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
  int stage_v_39_1 = ((pub_r001447_12_1 * 2) + 26) & 63;
  int stage_v_39_2 = ((pub_r001447_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (stage_v_2_1 ^ pub_r001447_16_1) & 63;
  int stage_v_40_2 = (stage_v_2_2 ^ pub_r001447_16_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((stage_v_22_1 & 2) != 0)
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
    if ((stage_v_22_2 & 2) != 0)
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
  int stage_v_41_1 = (stage_v_25_1 ^ pub_r001447_2_1) & 63;
  int stage_v_41_2 = (stage_v_25_2 ^ pub_r001447_2_2) & 63;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r001447_18_1 & 2) != 0)
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
    if ((sec_r001447_18_2 & 2) != 0)
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
  int stage_v_42_1 = (sec_r001447_5_1 ^ pub_r001447_0_1) & 63;
  int stage_v_42_2 = (sec_r001447_5_2 ^ pub_r001447_0_2) & 63;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r001447_13_1 & 2) != 0)
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
    if ((sec_r001447_13_2 & 2) != 0)
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
  int stage_v_43_1 = ((pub_r001447_6_1 * 2) + 24) & 63;
  int stage_v_43_2 = ((pub_r001447_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (sec_r001447_8_1 ^ pub_r001447_7_1) & 63;
  int stage_v_44_2 = (sec_r001447_8_2 ^ pub_r001447_7_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
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
    if ((stage_v_21_2 & 2) != 0)
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
  int stage_v_45_1 = ((pub_r001447_2_1 * 2) + 41) & 63;
  int stage_v_45_2 = ((pub_r001447_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001447_3_1 * 2) + 25) & 63;
  int stage_v_46_2 = ((pub_r001447_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001447_11_1 * 2) + 49) & 63;
  int stage_v_47_2 = ((pub_r001447_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (stage_v_33_1 ^ pub_r001447_1_1) & 63;
  int stage_v_48_2 = (stage_v_33_2 ^ pub_r001447_1_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
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
    if ((stage_v_32_2 & 2) != 0)
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
  int stage_v_49_1 = (sec_r001447_16_1 ^ pub_r001447_12_1) & 63;
  int stage_v_49_2 = (sec_r001447_16_2 ^ pub_r001447_12_2) & 63;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_50_1 = (stage_v_25_1 ^ pub_r001447_14_1) & 63;
  int stage_v_50_2 = (stage_v_25_2 ^ pub_r001447_14_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r001447_9_1 & 2) != 0)
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
    if ((sec_r001447_9_2 & 2) != 0)
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
  int stage_v_51_1 = ((pub_r001447_9_1 * 2) + 17) & 63;
  int stage_v_51_2 = ((pub_r001447_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (stage_v_32_1 ^ pub_r001447_6_1) & 63;
  int stage_v_52_2 = (stage_v_32_2 ^ pub_r001447_6_2) & 63;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((stage_v_50_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_52_1 * 2)) & 255;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((stage_v_50_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_52_2 * 2)) & 255;
  }
  int stage_v_53_1 = ((pub_r001447_7_1 * 2) + 32) & 63;
  int stage_v_53_2 = ((pub_r001447_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001447_6_1 * 2) + 6) & 63;
  int stage_v_54_2 = ((pub_r001447_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (stage_v_3_1 ^ pub_r001447_15_1) & 63;
  int stage_v_55_2 = (stage_v_3_2 ^ pub_r001447_15_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r001447_21_1 & 2) != 0)
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
    if ((sec_r001447_21_2 & 2) != 0)
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
  int stage_v_56_1 = ((pub_r001447_13_1 * 2) + 36) & 63;
  int stage_v_56_2 = ((pub_r001447_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (helper_flow_0_1 ^ pub_r001447_12_1) & 63;
  int stage_v_57_2 = (helper_flow_0_2 ^ pub_r001447_12_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r001447_9_1 & 2) != 0)
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
    if ((sec_r001447_9_2 & 2) != 0)
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
  int stage_v_58_1 = ((pub_r001447_10_1 * 2) + 21) & 63;
  int stage_v_58_2 = ((pub_r001447_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001447_15_1 * 2) + 31) & 63;
  int stage_v_59_2 = ((pub_r001447_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001447_4_1 * 2) + 14) & 63;
  int stage_v_60_2 = ((pub_r001447_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (helper_flow_4_1 ^ pub_r001447_13_1) & 63;
  int stage_v_61_2 = (helper_flow_4_2 ^ pub_r001447_13_2) & 63;
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
  int stage_v_62_1 = (sec_r001447_1_1 ^ pub_r001447_10_1) & 63;
  int stage_v_62_2 = (sec_r001447_1_2 ^ pub_r001447_10_2) & 63;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r001447_8_1 & 2) != 0)
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
    if ((sec_r001447_8_2 & 2) != 0)
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
  int stage_v_63_1 = ((pub_r001447_9_1 * 2) + 16) & 63;
  int stage_v_63_2 = ((pub_r001447_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (sec_r001447_0_1 ^ pub_r001447_8_1) & 63;
  int stage_v_64_2 = (sec_r001447_0_2 ^ pub_r001447_8_2) & 63;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
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
    if ((stage_v_30_2 & 2) != 0)
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
  int stage_v_65_1 = (sec_r001447_4_1 ^ pub_r001447_4_1) & 63;
  int stage_v_65_2 = (sec_r001447_4_2 ^ pub_r001447_4_2) & 63;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r001447_8_1 & 2) != 0)
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
    if ((sec_r001447_8_2 & 2) != 0)
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
  int stage_v_66_1 = ((pub_r001447_14_1 * 2) + 36) & 63;
  int stage_v_66_2 = ((pub_r001447_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (helper_flow_5_1 ^ pub_r001447_3_1) & 63;
  int stage_v_67_2 = (helper_flow_5_2 ^ pub_r001447_3_2) & 63;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r001447_5_1 & 2) != 0)
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
    if ((sec_r001447_5_2 & 2) != 0)
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
  int stage_v_68_1 = ((pub_r001447_1_1 * 2) + 46) & 63;
  int stage_v_68_2 = ((pub_r001447_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001447_6_1 * 2) + 41) & 63;
  int stage_v_69_2 = ((pub_r001447_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001447_4_1 * 2) + 47) & 63;
  int stage_v_70_2 = ((pub_r001447_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001447_4_1 * 2) + 38) & 63;
  int stage_v_71_2 = ((pub_r001447_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (sec_r001447_9_1 ^ pub_r001447_2_1) & 63;
  int stage_v_72_2 = (sec_r001447_9_2 ^ pub_r001447_2_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r001447_15_1 & 2) != 0)
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
    if ((sec_r001447_15_2 & 2) != 0)
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
  int stage_v_73_1 = ((pub_r001447_13_1 * 2) + 47) & 63;
  int stage_v_73_2 = ((pub_r001447_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (stage_v_25_1 ^ pub_r001447_5_1) & 63;
  int stage_v_74_2 = (stage_v_25_2 ^ pub_r001447_5_2) & 63;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r001447_3_1 & 2) != 0)
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
    if ((sec_r001447_3_2 & 2) != 0)
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
  int stage_v_75_1 = (stage_v_1_1 ^ pub_r001447_14_1) & 63;
  int stage_v_75_2 = (stage_v_1_2 ^ pub_r001447_14_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r001447_11_1 & 2) != 0)
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
    if ((sec_r001447_11_2 & 2) != 0)
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
  int stage_v_76_1 = (sec_r001447_4_1 ^ pub_r001447_14_1) & 63;
  int stage_v_76_2 = (sec_r001447_4_2 ^ pub_r001447_14_2) & 63;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  }
  int stage_v_77_1 = (sec_r001447_14_1 ^ pub_r001447_15_1) & 63;
  int stage_v_77_2 = (sec_r001447_14_2 ^ pub_r001447_15_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((stage_v_61_1 & 2) != 0)
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
    if ((stage_v_61_2 & 2) != 0)
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
  int stage_v_78_1 = (helper_flow_3_1 ^ pub_r001447_0_1) & 63;
  int stage_v_78_2 = (helper_flow_3_2 ^ pub_r001447_0_2) & 63;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
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
    if ((stage_v_38_2 & 2) != 0)
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
  int stage_v_79_1 = (stage_v_49_1 ^ pub_r001447_3_1) & 63;
  int stage_v_79_2 = (stage_v_49_2 ^ pub_r001447_3_2) & 63;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((stage_v_67_1 & 2) != 0)
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
    if ((stage_v_67_2 & 2) != 0)
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
  int stage_v_80_1 = (sec_r001447_6_1 ^ pub_r001447_4_1) & 63;
  int stage_v_80_2 = (sec_r001447_6_2 ^ pub_r001447_4_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
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
    if ((stage_v_21_2 & 2) != 0)
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
  int stage_v_81_1 = ((pub_r001447_10_1 * 2) + 13) & 63;
  int stage_v_81_2 = ((pub_r001447_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (stage_v_48_1 ^ pub_r001447_3_1) & 63;
  int stage_v_82_2 = (stage_v_48_2 ^ pub_r001447_3_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
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
    if ((stage_v_55_2 & 2) != 0)
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
  int stage_v_83_1 = (stage_v_3_1 ^ pub_r001447_12_1) & 63;
  int stage_v_83_2 = (stage_v_3_2 ^ pub_r001447_12_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
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
    if ((helper_flow_1_2 & 2) != 0)
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
  int stage_v_84_1 = (stage_v_57_1 ^ pub_r001447_16_1) & 63;
  int stage_v_84_2 = (stage_v_57_2 ^ pub_r001447_16_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
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
    if ((helper_flow_5_2 & 2) != 0)
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
  int stage_v_85_1 = (sec_r001447_2_1 ^ pub_r001447_6_1) & 63;
  int stage_v_85_2 = (sec_r001447_2_2 ^ pub_r001447_6_2) & 63;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((stage_v_84_1 & 2) != 0)
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
    if ((stage_v_84_2 & 2) != 0)
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
  int stage_v_86_1 = (helper_flow_6_1 ^ pub_r001447_16_1) & 63;
  int stage_v_86_2 = (helper_flow_6_2 ^ pub_r001447_16_2) & 63;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
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
    if ((stage_v_80_2 & 2) != 0)
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
  int stage_v_87_1 = ((pub_r001447_13_1 * 2) + 41) & 63;
  int stage_v_87_2 = ((pub_r001447_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (stage_v_1_1 ^ pub_r001447_6_1) & 63;
  int stage_v_88_2 = (stage_v_1_2 ^ pub_r001447_6_2) & 63;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
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
    if ((stage_v_55_2 & 2) != 0)
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
  int stage_v_89_1 = (stage_v_52_1 ^ pub_r001447_0_1) & 63;
  int stage_v_89_2 = (stage_v_52_2 ^ pub_r001447_0_2) & 63;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
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
    if ((stage_v_72_2 & 2) != 0)
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
  int stage_v_90_1 = (stage_v_77_1 ^ pub_r001447_5_1) & 63;
  int stage_v_90_2 = (stage_v_77_2 ^ pub_r001447_5_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
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
    if ((stage_v_30_2 & 2) != 0)
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
  int stage_v_91_1 = (sec_r001447_15_1 ^ pub_r001447_15_1) & 63;
  int stage_v_91_2 = (sec_r001447_15_2 ^ pub_r001447_15_2) & 63;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
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
    if ((stage_v_7_2 & 2) != 0)
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
  int stage_v_92_1 = (stage_v_67_1 ^ pub_r001447_4_1) & 63;
  int stage_v_92_2 = (stage_v_67_2 ^ pub_r001447_4_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((stage_v_89_1 & 2) != 0)
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
    if ((stage_v_89_2 & 2) != 0)
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
  int stage_v_93_1 = (sec_r001447_9_1 ^ pub_r001447_3_1) & 63;
  int stage_v_93_2 = (sec_r001447_9_2 ^ pub_r001447_3_2) & 63;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r001447_7_1 & 2) != 0)
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
    if ((sec_r001447_7_2 & 2) != 0)
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
  int stage_v_94_1 = (stage_v_84_1 ^ pub_r001447_4_1) & 63;
  int stage_v_94_2 = (stage_v_84_2 ^ pub_r001447_4_2) & 63;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
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
    if ((stage_v_48_2 & 2) != 0)
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
  int stage_v_95_1 = (stage_v_89_1 ^ pub_r001447_1_1) & 63;
  int stage_v_95_2 = (stage_v_89_2 ^ pub_r001447_1_2) & 63;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
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
    if ((stage_v_40_2 & 2) != 0)
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
  int stage_v_96_1 = ((pub_r001447_8_1 * 2) + 33) & 63;
  int stage_v_96_2 = ((pub_r001447_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (sec_r001447_0_1 ^ pub_r001447_1_1) & 63;
  int stage_v_97_2 = (sec_r001447_0_2 ^ pub_r001447_1_2) & 63;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r001447_14_1 & 2) != 0)
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
    if ((sec_r001447_14_2 & 2) != 0)
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
  int stage_v_98_1 = (stage_v_48_1 ^ pub_r001447_15_1) & 63;
  int stage_v_98_2 = (stage_v_48_2 ^ pub_r001447_15_2) & 63;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r001447_12_1 & 2) != 0)
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
    if ((sec_r001447_12_2 & 2) != 0)
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
  int stage_v_99_1 = ((pub_r001447_6_1 * 2) + 21) & 63;
  int stage_v_99_2 = ((pub_r001447_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (helper_flow_5_1 ^ pub_r001447_3_1) & 63;
  int stage_v_100_2 = (helper_flow_5_2 ^ pub_r001447_3_2) & 63;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
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
    if ((stage_v_80_2 & 2) != 0)
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
  int stage_v_101_1 = (stage_v_20_1 ^ pub_r001447_15_1) & 63;
  int stage_v_101_2 = (stage_v_20_2 ^ pub_r001447_15_2) & 63;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
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
    if ((helper_flow_2_2 & 2) != 0)
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
  int stage_v_102_1 = ((pub_r001447_11_1 * 2) + 7) & 63;
  int stage_v_102_2 = ((pub_r001447_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (stage_v_16_1 ^ pub_r001447_9_1) & 63;
  int stage_v_103_2 = (stage_v_16_2 ^ pub_r001447_9_2) & 63;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r001447_20_1 & 2) != 0)
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
    if ((sec_r001447_20_2 & 2) != 0)
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
  int stage_v_104_1 = (stage_v_79_1 ^ pub_r001447_4_1) & 63;
  int stage_v_104_2 = (stage_v_79_2 ^ pub_r001447_4_2) & 63;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((stage_v_62_1 & 2) != 0)
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
    if ((stage_v_62_2 & 2) != 0)
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
  int stage_v_105_1 = ((pub_r001447_16_1 * 2) + 13) & 63;
  int stage_v_105_2 = ((pub_r001447_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001447_6_1 * 2) + 35) & 63;
  int stage_v_106_2 = ((pub_r001447_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (stage_v_55_1 ^ pub_r001447_16_1) & 63;
  int stage_v_107_2 = (stage_v_55_2 ^ pub_r001447_16_2) & 63;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((stage_v_97_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((stage_v_97_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  }
  int stage_v_108_1 = ((pub_r001447_7_1 * 2) + 33) & 63;
  int stage_v_108_2 = ((pub_r001447_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (sec_r001447_8_1 ^ pub_r001447_7_1) & 63;
  int stage_v_109_2 = (sec_r001447_8_2 ^ pub_r001447_7_2) & 63;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
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
    if ((stage_v_3_2 & 2) != 0)
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
  int stage_v_110_1 = ((pub_r001447_7_1 * 2) + 26) & 63;
  int stage_v_110_2 = ((pub_r001447_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (stage_v_109_1 ^ pub_r001447_4_1) & 63;
  int stage_v_111_2 = (stage_v_109_2 ^ pub_r001447_4_2) & 63;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((stage_v_16_1 & 2) != 0)
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
    if ((stage_v_16_2 & 2) != 0)
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
  int stage_v_112_1 = (sec_r001447_13_1 ^ pub_r001447_0_1) & 63;
  int stage_v_112_2 = (sec_r001447_13_2 ^ pub_r001447_0_2) & 63;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((stage_v_78_1 & 2) != 0)
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
    if ((stage_v_78_2 & 2) != 0)
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
  int stage_v_113_1 = (stage_v_80_1 ^ pub_r001447_15_1) & 63;
  int stage_v_113_2 = (stage_v_80_2 ^ pub_r001447_15_2) & 63;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((stage_v_49_1 & 2) != 0)
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
    if ((stage_v_49_2 & 2) != 0)
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
  int stage_v_114_1 = (sec_r001447_17_1 ^ pub_r001447_14_1) & 63;
  int stage_v_114_2 = (sec_r001447_17_2 ^ pub_r001447_14_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((stage_v_100_1 & 2) != 0)
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
    if ((stage_v_100_2 & 2) != 0)
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
  int stage_v_115_1 = (stage_v_8_1 ^ pub_r001447_15_1) & 63;
  int stage_v_115_2 = (stage_v_8_2 ^ pub_r001447_15_2) & 63;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((stage_v_112_1 & 2) != 0)
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
    if ((stage_v_112_2 & 2) != 0)
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
  int stage_v_116_1 = (stage_v_11_1 ^ pub_r001447_8_1) & 63;
  int stage_v_116_2 = (stage_v_11_2 ^ pub_r001447_8_2) & 63;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_117_1 = ((pub_r001447_10_1 * 2) + 28) & 63;
  int stage_v_117_2 = ((pub_r001447_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001447_11_1 * 2) + 32) & 63;
  int stage_v_118_2 = ((pub_r001447_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (stage_v_84_1 ^ pub_r001447_12_1) & 63;
  int stage_v_119_2 = (stage_v_84_2 ^ pub_r001447_12_2) & 63;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((stage_v_100_1 & 2) != 0)
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
    if ((stage_v_100_2 & 2) != 0)
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
  int stage_v_120_1 = (sec_r001447_5_1 ^ pub_r001447_13_1) & 63;
  int stage_v_120_2 = (sec_r001447_5_2 ^ pub_r001447_13_2) & 63;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((stage_v_49_1 & 2) != 0)
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
    if ((stage_v_49_2 & 2) != 0)
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
  int stage_v_121_1 = (stage_v_86_1 ^ pub_r001447_10_1) & 63;
  int stage_v_121_2 = (stage_v_86_2 ^ pub_r001447_10_2) & 63;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
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
    if ((stage_v_6_2 & 2) != 0)
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
  int stage_v_122_1 = ((pub_r001447_3_1 * 2) + 27) & 63;
  int stage_v_122_2 = ((pub_r001447_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (stage_v_113_1 ^ pub_r001447_6_1) & 63;
  int stage_v_123_2 = (stage_v_113_2 ^ pub_r001447_6_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((stage_v_100_1 & 2) != 0)
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
    if ((stage_v_100_2 & 2) != 0)
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
  int stage_v_124_1 = ((pub_r001447_9_1 * 2) + 23) & 63;
  int stage_v_124_2 = ((pub_r001447_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (stage_v_32_1 ^ pub_r001447_6_1) & 63;
  int stage_v_125_2 = (stage_v_32_2 ^ pub_r001447_6_2) & 63;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
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
    if ((stage_v_13_2 & 2) != 0)
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
  int stage_v_126_1 = (stage_v_100_1 ^ pub_r001447_11_1) & 63;
  int stage_v_126_2 = (stage_v_100_2 ^ pub_r001447_11_2) & 63;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((stage_v_90_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((stage_v_90_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  }
  int stage_v_127_1 = (stage_v_126_1 ^ pub_r001447_6_1) & 63;
  int stage_v_127_2 = (stage_v_126_2 ^ pub_r001447_6_2) & 63;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((sec_r001447_11_1 & 2) != 0)
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
    if ((sec_r001447_11_2 & 2) != 0)
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
  int stage_v_128_1 = (sec_r001447_6_1 ^ pub_r001447_8_1) & 63;
  int stage_v_128_2 = (sec_r001447_6_2 ^ pub_r001447_8_2) & 63;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_129_1 = (stage_v_11_1 ^ pub_r001447_11_1) & 63;
  int stage_v_129_2 = (stage_v_11_2 ^ pub_r001447_11_2) & 63;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((sec_r001447_15_1 & 2) != 0)
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
    if ((sec_r001447_15_2 & 2) != 0)
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
  int stage_v_130_1 = (stage_v_92_1 ^ pub_r001447_14_1) & 63;
  int stage_v_130_2 = (stage_v_92_2 ^ pub_r001447_14_2) & 63;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
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
    if ((stage_v_44_2 & 2) != 0)
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
  int stage_v_131_1 = (sec_r001447_5_1 ^ pub_r001447_11_1) & 63;
  int stage_v_131_2 = (sec_r001447_5_2 ^ pub_r001447_11_2) & 63;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((sec_r001447_14_1 & 2) != 0)
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
    if ((sec_r001447_14_2 & 2) != 0)
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
  int stage_v_132_1 = ((pub_r001447_14_1 * 2) + 26) & 63;
  int stage_v_132_2 = ((pub_r001447_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001447_12_1 * 2) + 26) & 63;
  int stage_v_133_2 = ((pub_r001447_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001447_3_1 * 2) + 12) & 63;
  int stage_v_134_2 = ((pub_r001447_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (sec_r001447_11_1 ^ pub_r001447_9_1) & 63;
  int stage_v_135_2 = (sec_r001447_11_2 ^ pub_r001447_9_2) & 63;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((stage_v_83_1 & 2) != 0)
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
    if ((stage_v_83_2 & 2) != 0)
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
  int stage_v_136_1 = ((pub_r001447_3_1 * 2) + 38) & 63;
  int stage_v_136_2 = ((pub_r001447_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001447_1_1 * 2) + 42) & 63;
  int stage_v_137_2 = ((pub_r001447_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001447_16_1 * 2) + 44) & 63;
  int stage_v_138_2 = ((pub_r001447_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (stage_v_82_1 ^ pub_r001447_4_1) & 63;
  int stage_v_139_2 = (stage_v_82_2 ^ pub_r001447_4_2) & 63;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
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
    if ((stage_v_48_2 & 2) != 0)
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
  int stage_v_140_1 = (sec_r001447_8_1 ^ pub_r001447_9_1) & 63;
  int stage_v_140_2 = (sec_r001447_8_2 ^ pub_r001447_9_2) & 63;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((stage_v_86_1 & 2) != 0)
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
    if ((stage_v_86_2 & 2) != 0)
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
  int stage_v_141_1 = (sec_r001447_15_1 ^ pub_r001447_2_1) & 63;
  int stage_v_141_2 = (sec_r001447_15_2 ^ pub_r001447_2_2) & 63;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((sec_r001447_15_1 & 2) != 0)
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
    if ((sec_r001447_15_2 & 2) != 0)
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
  int stage_v_142_1 = (sec_r001447_6_1 ^ pub_r001447_10_1) & 63;
  int stage_v_142_2 = (sec_r001447_6_2 ^ pub_r001447_10_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_143_1 = (stage_v_44_1 ^ pub_r001447_13_1) & 63;
  int stage_v_143_2 = (stage_v_44_2 ^ pub_r001447_13_2) & 63;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((stage_v_41_1 & 2) != 0)
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
    if ((stage_v_41_2 & 2) != 0)
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
  int stage_v_144_1 = ((pub_r001447_9_1 * 2) + 24) & 63;
  int stage_v_144_2 = ((pub_r001447_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001447_6_1 * 2) + 38) & 63;
  int stage_v_145_2 = ((pub_r001447_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001447_1_1 * 2) + 49) & 63;
  int stage_v_146_2 = ((pub_r001447_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (stage_v_119_1 ^ pub_r001447_3_1) & 63;
  int stage_v_147_2 = (stage_v_119_2 ^ pub_r001447_3_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((stage_v_140_1 & 2) != 0)
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
    if ((stage_v_140_2 & 2) != 0)
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
  int stage_v_148_1 = (sec_r001447_0_1 ^ pub_r001447_11_1) & 63;
  int stage_v_148_2 = (sec_r001447_0_2 ^ pub_r001447_11_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
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
    if ((stage_v_38_2 & 2) != 0)
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
  int stage_v_149_1 = (stage_v_94_1 ^ pub_r001447_9_1) & 63;
  int stage_v_149_2 = (stage_v_94_2 ^ pub_r001447_9_2) & 63;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((sec_r001447_19_1 & 2) != 0)
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
    if ((sec_r001447_19_2 & 2) != 0)
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
  int stage_v_150_1 = (stage_v_88_1 ^ pub_r001447_7_1) & 63;
  int stage_v_150_2 = (stage_v_88_2 ^ pub_r001447_7_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_151_1 = ((pub_r001447_9_1 * 2) + 5) & 63;
  int stage_v_151_2 = ((pub_r001447_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (helper_flow_6_1 ^ pub_r001447_5_1) & 63;
  int stage_v_152_2 = (helper_flow_6_2 ^ pub_r001447_5_2) & 63;
  if ((stage_v_152_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
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
    if ((stage_v_2_2 & 2) != 0)
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
  int stage_v_153_1 = (stage_v_115_1 ^ pub_r001447_0_1) & 63;
  int stage_v_153_2 = (stage_v_115_2 ^ pub_r001447_0_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((stage_v_152_1 & 2) != 0)
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
    if ((stage_v_152_2 & 2) != 0)
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
  int stage_v_154_1 = (sec_r001447_10_1 ^ pub_r001447_10_1) & 63;
  int stage_v_154_2 = (sec_r001447_10_2 ^ pub_r001447_10_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((stage_v_86_1 & 2) != 0)
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
    if ((stage_v_86_2 & 2) != 0)
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
  int stage_v_155_1 = (stage_v_140_1 ^ pub_r001447_11_1) & 63;
  int stage_v_155_2 = (stage_v_140_2 ^ pub_r001447_11_2) & 63;
  if ((stage_v_155_1 & 1) != 0)
  {
    if ((stage_v_153_1 & 2) != 0)
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
    if ((stage_v_153_2 & 2) != 0)
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
  int stage_v_156_1 = ((pub_r001447_11_1 * 2) + 25) & 63;
  int stage_v_156_2 = ((pub_r001447_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (stage_v_40_1 ^ pub_r001447_2_1) & 63;
  int stage_v_157_2 = (stage_v_40_2 ^ pub_r001447_2_2) & 63;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((stage_v_20_1 & 2) != 0)
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
    if ((stage_v_20_2 & 2) != 0)
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
  int stage_v_158_1 = ((pub_r001447_5_1 * 2) + 29) & 63;
  int stage_v_158_2 = ((pub_r001447_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001447_12_1 * 2) + 9) & 63;
  int stage_v_159_2 = ((pub_r001447_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001447_9_1 * 2) + 20) & 63;
  int stage_v_160_2 = ((pub_r001447_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (stage_v_61_1 ^ pub_r001447_12_1) & 63;
  int stage_v_161_2 = (stage_v_61_2 ^ pub_r001447_12_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((sec_r001447_4_1 & 2) != 0)
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
    if ((sec_r001447_4_2 & 2) != 0)
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
  int stage_v_162_1 = (stage_v_95_1 ^ pub_r001447_8_1) & 63;
  int stage_v_162_2 = (stage_v_95_2 ^ pub_r001447_8_2) & 63;
  if ((stage_v_162_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
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
    if ((helper_flow_1_2 & 2) != 0)
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
  int stage_v_163_1 = (stage_v_67_1 ^ pub_r001447_0_1) & 63;
  int stage_v_163_2 = (stage_v_67_2 ^ pub_r001447_0_2) & 63;
  if ((stage_v_163_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
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
    if ((stage_v_44_2 & 2) != 0)
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
  int stage_v_164_1 = (stage_v_157_1 ^ pub_r001447_5_1) & 63;
  int stage_v_164_2 = (stage_v_157_2 ^ pub_r001447_5_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((stage_v_41_1 & 2) != 0)
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
    if ((stage_v_41_2 & 2) != 0)
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
  int stage_v_165_1 = (stage_v_67_1 ^ pub_r001447_13_1) & 63;
  int stage_v_165_2 = (stage_v_67_2 ^ pub_r001447_13_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((sec_r001447_9_1 & 2) != 0)
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
    if ((sec_r001447_9_2 & 2) != 0)
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
  int stage_v_166_1 = (stage_v_101_1 ^ pub_r001447_9_1) & 63;
  int stage_v_166_2 = (stage_v_101_2 ^ pub_r001447_9_2) & 63;
  if ((stage_v_166_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
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
    if ((stage_v_30_2 & 2) != 0)
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
  int stage_v_167_1 = (sec_r001447_7_1 ^ pub_r001447_1_1) & 63;
  int stage_v_167_2 = (sec_r001447_7_2 ^ pub_r001447_1_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((stage_v_61_1 & 2) != 0)
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
    if ((stage_v_61_2 & 2) != 0)
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
  int stage_v_168_1 = (sec_r001447_2_1 ^ pub_r001447_3_1) & 63;
  int stage_v_168_2 = (sec_r001447_2_2 ^ pub_r001447_3_2) & 63;
  if ((stage_v_168_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
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
    if ((stage_v_3_2 & 2) != 0)
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
  int stage_v_169_1 = ((pub_r001447_16_1 * 2) + 45) & 63;
  int stage_v_169_2 = ((pub_r001447_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (sec_r001447_20_1 ^ pub_r001447_1_1) & 63;
  int stage_v_170_2 = (sec_r001447_20_2 ^ pub_r001447_1_2) & 63;
  if ((stage_v_170_1 & 1) != 0)
  {
    if ((stage_v_109_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_170_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  }
  if ((stage_v_170_2 & 1) != 0)
  {
    if ((stage_v_109_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_170_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  }
  int stage_v_171_1 = (stage_v_7_1 ^ pub_r001447_1_1) & 63;
  int stage_v_171_2 = (stage_v_7_2 ^ pub_r001447_1_2) & 63;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
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
    if ((stage_v_80_2 & 2) != 0)
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
  int stage_v_172_1 = ((pub_r001447_8_1 * 2) + 18) & 63;
  int stage_v_172_2 = ((pub_r001447_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (stage_v_80_1 ^ pub_r001447_13_1) & 63;
  int stage_v_173_2 = (stage_v_80_2 ^ pub_r001447_13_2) & 63;
  if ((stage_v_173_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_173_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  }
  if ((stage_v_173_2 & 1) != 0)
  {
    if ((stage_v_25_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_173_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  }
  int stage_v_174_1 = (stage_v_20_1 ^ pub_r001447_16_1) & 63;
  int stage_v_174_2 = (stage_v_20_2 ^ pub_r001447_16_2) & 63;
  if ((stage_v_174_1 & 1) != 0)
  {
    if ((stage_v_148_1 & 2) != 0)
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
    if ((stage_v_148_2 & 2) != 0)
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
  int stage_v_175_1 = (stage_v_161_1 ^ pub_r001447_8_1) & 63;
  int stage_v_175_2 = (stage_v_161_2 ^ pub_r001447_8_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_176_1 = ((pub_r001447_12_1 * 2) + 49) & 63;
  int stage_v_176_2 = ((pub_r001447_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (stage_v_126_1 ^ pub_r001447_15_1) & 63;
  int stage_v_177_2 = (stage_v_126_2 ^ pub_r001447_15_2) & 63;
  if ((stage_v_177_1 & 1) != 0)
  {
    if ((stage_v_116_1 & 2) != 0)
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
    if ((stage_v_116_2 & 2) != 0)
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
  int stage_v_178_1 = (stage_v_83_1 ^ pub_r001447_4_1) & 63;
  int stage_v_178_2 = (stage_v_83_2 ^ pub_r001447_4_2) & 63;
  if ((stage_v_178_1 & 1) != 0)
  {
    if ((stage_v_175_1 & 2) != 0)
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
    if ((stage_v_175_2 & 2) != 0)
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
  int stage_v_179_1 = (stage_v_42_1 ^ pub_r001447_15_1) & 63;
  int stage_v_179_2 = (stage_v_42_2 ^ pub_r001447_15_2) & 63;
  if ((stage_v_179_1 & 1) != 0)
  {
    if ((sec_r001447_20_1 & 2) != 0)
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
    if ((sec_r001447_20_2 & 2) != 0)
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
  int stage_v_180_1 = (stage_v_55_1 ^ pub_r001447_3_1) & 63;
  int stage_v_180_2 = (stage_v_55_2 ^ pub_r001447_3_2) & 63;
  if ((stage_v_180_1 & 1) != 0)
  {
    if ((stage_v_85_1 & 2) != 0)
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
    if ((stage_v_85_2 & 2) != 0)
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
  int stage_v_181_1 = (sec_r001447_3_1 ^ pub_r001447_1_1) & 63;
  int stage_v_181_2 = (sec_r001447_3_2 ^ pub_r001447_1_2) & 63;
  if ((stage_v_181_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_182_1 = ((pub_r001447_1_1 * 2) + 22) & 63;
  int stage_v_182_2 = ((pub_r001447_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001447_15_1 * 2) + 39) & 63;
  int stage_v_183_2 = ((pub_r001447_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (sec_r001447_0_1 ^ pub_r001447_7_1) & 63;
  int stage_v_184_2 = (sec_r001447_0_2 ^ pub_r001447_7_2) & 63;
  if ((stage_v_184_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
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
    if ((stage_v_32_2 & 2) != 0)
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
  int stage_v_185_1 = ((pub_r001447_5_1 * 2) + 36) & 63;
  int stage_v_185_2 = ((pub_r001447_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (sec_r001447_6_1 ^ pub_r001447_7_1) & 63;
  int stage_v_186_2 = (sec_r001447_6_2 ^ pub_r001447_7_2) & 63;
  if ((stage_v_186_1 & 1) != 0)
  {
    if ((stage_v_131_1 & 2) != 0)
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
    if ((stage_v_131_2 & 2) != 0)
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
  int stage_v_187_1 = ((pub_r001447_5_1 * 2) + 44) & 63;
  int stage_v_187_2 = ((pub_r001447_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (stage_v_92_1 ^ pub_r001447_13_1) & 63;
  int stage_v_188_2 = (stage_v_92_2 ^ pub_r001447_13_2) & 63;
  if ((stage_v_188_1 & 1) != 0)
  {
    if ((stage_v_103_1 & 2) != 0)
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
    if ((stage_v_103_2 & 2) != 0)
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
  int stage_v_189_1 = (sec_r001447_13_1 ^ pub_r001447_5_1) & 63;
  int stage_v_189_2 = (sec_r001447_13_2 ^ pub_r001447_5_2) & 63;
  if ((stage_v_189_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
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
    if ((stage_v_7_2 & 2) != 0)
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
  __CPROVER_assume(sec_r001447_5_1 != sec_r001447_5_2);
  __CPROVER_assume(pub_r001447_8_1 == pub_r001447_8_2);
  __CPROVER_assume(sec_r001447_3_1 != sec_r001447_3_2);
  __CPROVER_assume(sec_r001447_7_1 != sec_r001447_7_2);
  __CPROVER_assume(sec_r001447_8_1 != sec_r001447_8_2);
  __CPROVER_assume(pub_r001447_13_1 == pub_r001447_13_2);
  __CPROVER_assume(pub_r001447_15_1 == pub_r001447_15_2);
  __CPROVER_assume(pub_r001447_9_1 == pub_r001447_9_2);
  __CPROVER_assume(pub_r001447_11_1 == pub_r001447_11_2);
  __CPROVER_assume(sec_r001447_14_1 != sec_r001447_14_2);
  __CPROVER_assume(sec_r001447_2_1 != sec_r001447_2_2);
  __CPROVER_assume(pub_r001447_1_1 == pub_r001447_1_2);
  __CPROVER_assume(pub_r001447_4_1 == pub_r001447_4_2);
  __CPROVER_assume(pub_r001447_16_1 == pub_r001447_16_2);
  __CPROVER_assume(sec_r001447_13_1 != sec_r001447_13_2);
  __CPROVER_assume(sec_r001447_19_1 != sec_r001447_19_2);
  __CPROVER_assume(sec_r001447_20_1 != sec_r001447_20_2);
  __CPROVER_assume(sec_r001447_11_1 != sec_r001447_11_2);
  __CPROVER_assume(sec_r001447_12_1 != sec_r001447_12_2);
  __CPROVER_assume(sec_r001447_15_1 != sec_r001447_15_2);
  __CPROVER_assume(sec_r001447_18_1 != sec_r001447_18_2);
  __CPROVER_assume(sec_r001447_4_1 != sec_r001447_4_2);
  __CPROVER_assume(sec_r001447_21_1 != sec_r001447_21_2);
  __CPROVER_assume(pub_r001447_0_1 == pub_r001447_0_2);
  __CPROVER_assume(pub_r001447_12_1 == pub_r001447_12_2);
  __CPROVER_assume(pub_r001447_14_1 == pub_r001447_14_2);
  __CPROVER_assume(pub_r001447_7_1 == pub_r001447_7_2);
  __CPROVER_assume(sec_r001447_1_1 != sec_r001447_1_2);
  __CPROVER_assume(pub_r001447_6_1 == pub_r001447_6_2);
  __CPROVER_assume(pub_r001447_10_1 == pub_r001447_10_2);
  __CPROVER_assume(pub_r001447_3_1 == pub_r001447_3_2);
  __CPROVER_assume(pub_r001447_2_1 == pub_r001447_2_2);
  __CPROVER_assume(sec_r001447_0_1 != sec_r001447_0_2);
  __CPROVER_assume(sec_r001447_17_1 != sec_r001447_17_2);
  __CPROVER_assume(sec_r001447_9_1 != sec_r001447_9_2);
  __CPROVER_assume(sec_r001447_16_1 != sec_r001447_16_2);
  __CPROVER_assume(sec_r001447_6_1 != sec_r001447_6_2);
  __CPROVER_assume(pub_r001447_5_1 == pub_r001447_5_2);
  __CPROVER_assume(sec_r001447_10_1 != sec_r001447_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.stride == st_var_3_2.stride);
  assert(st_var_3_1.dim == st_var_3_2.dim);
  assert(st_var_3_1.trace == st_var_3_2.trace);
  assert(st_var_3_1.density == st_var_3_2.density);
  assert(st_var_3_1.scale == st_var_3_2.scale);
  assert(st_var_3_1.determinant == st_var_3_2.determinant);
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
}


