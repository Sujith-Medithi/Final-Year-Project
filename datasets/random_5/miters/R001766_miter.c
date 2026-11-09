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
struct SensorNode_R001766_6613_0
{
  unsigned char offset;
  short gain;
  short threshold;
  int calib;
  int buffer[3];
};
struct MatrixBlock_R001766_6613_1
{
  int stride;
  int determinant;
  int dim;
  unsigned char density;
  int scale;
  short trace;
  int buffer[3];
};
union ColorPixel_R001766_6613_0
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
void fn_R001766_6613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st_1 = {0};
  struct SensorNode_R001766_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int residue_86_1 = 0;
  int residue_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_86_1 = ((residue_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_86_2 = ((residue_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_86_1) & 127;
    acc_2 = (acc_2 + residue_86_2) & 127;
  }

  int offset_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_54_1)
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

  switch (offset_54_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_86_1 == residue_86_2);
  assert(offset_54_1 == offset_54_2);
}

int fn_R001766_6613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int residue_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_86 = ((residue_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_86) & 127;
  }

  int offset_54 = (aux + st.buffer[1]) & 3;
  switch (offset_54)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001766_6613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st_1 = {0};
  struct MatrixBlock_R001766_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int offset_89_1 = 0;
  int offset_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_89_1 = ((offset_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_89_2 = ((offset_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_89_1) & 127;
    acc_2 = (acc_2 + offset_89_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_40_1)
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

  switch (accumulator_40_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_89_1 == offset_89_2);
  assert(accumulator_40_1 == accumulator_40_2);
}

int fn_R001766_6613_1(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int offset_89 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_89 = ((offset_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_89) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_40 = (aux + st.buffer[1]) & 3;
  switch (accumulator_40)
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

void fn_R001766_6613_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st_1 = {0};
  struct SensorNode_R001766_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int residue_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_57_1)
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

  switch (residue_57_2)
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

  int parity_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_24_1 > 44)
  {
    acc_1 = ((acc_1 + (parity_24_1 * 2)) + 5) & 127;
    aux_1 ^= parity_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_24_2 > 44)
  {
    acc_2 = ((acc_2 + (parity_24_2 * 2)) + 5) & 127;
    aux_2 ^= parity_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_57_1 == residue_57_2);
  assert(parity_24_1 == parity_24_2);
}

int fn_R001766_6613_2(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int residue_57 = (aux + st.buffer[1]) & 3;
  switch (residue_57)
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

  int parity_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_24 > 44)
  {
    acc = ((acc + (parity_24 * 2)) + 5) & 127;
    aux ^= parity_24 & 15;
  }
  else
  {
    acc = ((acc - parity_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001766_6613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st_1 = {0};
  struct MatrixBlock_R001766_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_56_1 = local_arr_1[aux_1 % 3];
  int index_reg_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_56_2 * 2)) & 127;
  int vector_41_1 = 0;
  int vector_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_41_1 = ((vector_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_41_2 = ((vector_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_41_1) & 127;
    acc_2 = (acc_2 + vector_41_2) & 127;
  }

  int damping_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_27_1) & 63;
  aux_2 = (aux_2 + damping_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
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

  assert(index_reg_56_1 == index_reg_56_2);
  assert(vector_41_1 == vector_41_2);
  assert(damping_27_1 == damping_27_2);
}

int fn_R001766_6613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int index_reg_56 = local_arr[aux % 3];
  acc = (acc + (index_reg_56 * 2)) & 127;
  int vector_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_41 = ((vector_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_41) & 127;
  }

  int damping_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_27) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001766_6613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st_1 = {0};
  struct MatrixBlock_R001766_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int pivot_31_1 = 0;
  int pivot_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_31_1 = ((pivot_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_31_2 = ((pivot_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_31_1) & 127;
    acc_2 = (acc_2 + pivot_31_2) & 127;
  }

  int margin_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_51_1 > 45)
  {
    acc_1 = ((acc_1 + (margin_51_1 * 2)) + 5) & 127;
    aux_1 ^= margin_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_51_2 > 45)
  {
    acc_2 = ((acc_2 + (margin_51_2 * 2)) + 5) & 127;
    aux_2 ^= margin_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_51_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_31_1 == pivot_31_2);
  assert(margin_51_1 == margin_51_2);
}

int fn_R001766_6613_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int pivot_31 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_31 = ((pivot_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_31) & 127;
  }

  int margin_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_51 > 45)
  {
    acc = ((acc + (margin_51 * 2)) + 5) & 127;
    aux ^= margin_51 & 15;
  }
  else
  {
    acc = ((acc - margin_51) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001766_6613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st_1 = {0};
  struct SensorNode_R001766_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_42_1 = 0;
  int parity_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_42_1 = ((parity_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_42_2 = ((parity_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_42_1) & 127;
    acc_2 = (acc_2 + parity_42_2) & 127;
  }

  int anchor_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_33_1)
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

  switch (anchor_33_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_42_1 == parity_42_2);
  assert(anchor_33_1 == anchor_33_2);
}

int fn_R001766_6613_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_42 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_42 = ((parity_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_42) & 127;
  }

  int anchor_33 = (aux + st.buffer[1]) & 3;
  switch (anchor_33)
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

void fn_R001766_6613_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st_1 = {0};
  struct SensorNode_R001766_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_84_1 > 40)
  {
    acc_1 = ((acc_1 + (cursor_84_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_84_2 > 40)
  {
    acc_2 = ((acc_2 + (cursor_84_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_94_1) & 63;
  aux_2 = (aux_2 + margin_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_84_1 == cursor_84_2);
  assert(margin_94_1 == margin_94_2);
}

int fn_R001766_6613_6(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_84 > 40)
  {
    acc = ((acc + (cursor_84 * 2)) + 5) & 127;
    aux ^= cursor_84 & 15;
  }
  else
  {
    acc = ((acc - cursor_84) + 11) & 127;
    aux += 3;
  }
  int margin_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_94) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001766_6613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st_1 = {0};
  struct SensorNode_R001766_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_10_1 = local_arr_1[aux_1 % 3];
  int coefficient_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_10_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_62_1 > 49)
  {
    acc_1 = ((acc_1 + (index_reg_62_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_62_2 > 49)
  {
    acc_2 = ((acc_2 + (index_reg_62_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_62_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_10_1 == coefficient_10_2);
  assert(index_reg_62_1 == index_reg_62_2);
}

int fn_R001766_6613_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int coefficient_10 = local_arr[aux % 3];
  acc = (acc + (coefficient_10 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_62 > 49)
  {
    acc = ((acc + (index_reg_62 * 2)) + 5) & 127;
    aux ^= index_reg_62 & 15;
  }
  else
  {
    acc = ((acc - index_reg_62) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001766_6613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st_1 = {0};
  struct SensorNode_R001766_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_83_1 = 0;
  int metric_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_83_1 = ((metric_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_83_2 = ((metric_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_83_1) & 127;
    acc_2 = (acc_2 + metric_83_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_83_1 == metric_83_2);
}

int fn_R001766_6613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_83 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_83 = ((metric_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_83) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001766_6613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st_1 = {0};
  struct SensorNode_R001766_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_62_1 = local_arr_1[aux_1 % 3];
  int anchor_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_62_2 * 2)) & 127;
  int metric_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_54_1) & 63;
  aux_2 = (aux_2 + metric_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_44_1 = 0;
  int stride_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_44_1 = ((stride_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_44_2 = ((stride_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_44_1) & 127;
    acc_2 = (acc_2 + stride_44_2) & 127;
  }

  int parity_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_83_1 > 23)
  {
    acc_1 = ((acc_1 + (parity_83_1 * 2)) + 5) & 127;
    aux_1 ^= parity_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_83_2 > 23)
  {
    acc_2 = ((acc_2 + (parity_83_2 * 2)) + 5) & 127;
    aux_2 ^= parity_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_62_1 == anchor_62_2);
  assert(metric_54_1 == metric_54_2);
  assert(stride_44_1 == stride_44_2);
  assert(parity_83_1 == parity_83_2);
}

int fn_R001766_6613_9(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int anchor_62 = local_arr[aux % 3];
  acc = (acc + (anchor_62 * 2)) & 127;
  int metric_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_54) & 63;
  acc ^= aux;
  int stride_44 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_44 = ((stride_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_44) & 127;
  }

  int parity_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_83 > 23)
  {
    acc = ((acc + (parity_83 * 2)) + 5) & 127;
    aux ^= parity_83 & 15;
  }
  else
  {
    acc = ((acc - parity_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001766_6613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st_1 = {0};
  struct SensorNode_R001766_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int factor_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_44_1)
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

  switch (factor_44_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_18_1) & 63;
  aux_2 = (aux_2 + delta_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_44_1 == factor_44_2);
  assert(delta_18_1 == delta_18_2);
}

int fn_R001766_6613_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int factor_44 = (aux + st.buffer[1]) & 3;
  switch (factor_44)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_18) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001766_6613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st_1 = {0};
  struct SensorNode_R001766_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int vector_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_71_1 > 26)
  {
    acc_1 = ((acc_1 + (vector_71_1 * 2)) + 5) & 127;
    aux_1 ^= vector_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_71_2 > 26)
  {
    acc_2 = ((acc_2 + (vector_71_2 * 2)) + 5) & 127;
    aux_2 ^= vector_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_55_1 = 0;
  int offset_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_55_1 = ((offset_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_55_2 = ((offset_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_55_1) & 127;
    acc_2 = (acc_2 + offset_55_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_71_1 == vector_71_2);
  assert(offset_55_1 == offset_55_2);
}

int fn_R001766_6613_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int vector_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_71 > 26)
  {
    acc = ((acc + (vector_71 * 2)) + 5) & 127;
    aux ^= vector_71 & 15;
  }
  else
  {
    acc = ((acc - vector_71) + 11) & 127;
    aux += 3;
  }
  int offset_55 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_55 = ((offset_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_55) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001766_6613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st_1 = {0};
  struct MatrixBlock_R001766_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int factor_13_1 = 0;
  int factor_13_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_13_1 = ((factor_13_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_13_2 = ((factor_13_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_13_1) & 127;
    acc_2 = (acc_2 + factor_13_2) & 127;
  }

  int scale_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_67_1)
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

  switch (scale_67_2)
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

  int tally_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_38_1 > 36)
  {
    acc_1 = ((acc_1 + (tally_38_1 * 2)) + 5) & 127;
    aux_1 ^= tally_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_38_2 > 36)
  {
    acc_2 = ((acc_2 + (tally_38_2 * 2)) + 5) & 127;
    aux_2 ^= tally_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_38_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_13_1 == factor_13_2);
  assert(scale_67_1 == scale_67_2);
  assert(tally_38_1 == tally_38_2);
}

int fn_R001766_6613_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int factor_13 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_13 = ((factor_13 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_13) & 127;
  }

  int scale_67 = (aux + st.buffer[1]) & 3;
  switch (scale_67)
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

  int tally_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_38 > 36)
  {
    acc = ((acc + (tally_38 * 2)) + 5) & 127;
    aux ^= tally_38 & 15;
  }
  else
  {
    acc = ((acc - tally_38) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001766_6613_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st_1 = {0};
  struct MatrixBlock_R001766_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int factor_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_17_1)
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

  switch (factor_17_2)
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

  int parity_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_92_1) & 63;
  aux_2 = (aux_2 + parity_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_17_1 == factor_17_2);
  assert(parity_92_1 == parity_92_2);
}

int fn_R001766_6613_13(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int factor_17 = (aux + st.buffer[1]) & 3;
  switch (factor_17)
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

  int parity_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001766_6613_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st_1 = {0};
  struct SensorNode_R001766_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_19_1 = local_arr_1[aux_1 % 3];
  int bound_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_19_2 * 2)) & 127;
  int anchor_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_18_1 > 33)
  {
    acc_1 = ((acc_1 + (anchor_18_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_18_2 > 33)
  {
    acc_2 = ((acc_2 + (anchor_18_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_31_1) & 63;
  aux_2 = (aux_2 + index_reg_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_19_1 == bound_19_2);
  assert(anchor_18_1 == anchor_18_2);
  assert(index_reg_31_1 == index_reg_31_2);
}

int fn_R001766_6613_14(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_19 = local_arr[aux % 3];
  acc = (acc + (bound_19 * 2)) & 127;
  int anchor_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_18 > 33)
  {
    acc = ((acc + (anchor_18 * 2)) + 5) & 127;
    aux ^= anchor_18 & 15;
  }
  else
  {
    acc = ((acc - anchor_18) + 11) & 127;
    aux += 3;
  }
  int index_reg_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001766_6613_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st_1 = {0};
  struct MatrixBlock_R001766_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int threshold_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_43_1)
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

  switch (threshold_43_2)
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
  int tracker_52_1 = local_arr_1[aux_1 % 3];
  int tracker_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_52_2 * 2)) & 127;
  int bound_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_48_1) & 63;
  aux_2 = (aux_2 + bound_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_43_1 == threshold_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_52_1 == tracker_52_2);
  assert(bound_48_1 == bound_48_2);
}

int fn_R001766_6613_15(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int threshold_43 = (aux + st.buffer[1]) & 3;
  switch (threshold_43)
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
  int tracker_52 = local_arr[aux % 3];
  acc = (acc + (tracker_52 * 2)) & 127;
  int bound_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001766_6613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st_1 = {0};
  struct SensorNode_R001766_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_86_1)
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

  switch (accumulator_86_2)
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

  int residue_52_1 = 0;
  int residue_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_52_1 = ((residue_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_52_2 = ((residue_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_52_1) & 127;
    acc_2 = (acc_2 + residue_52_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_52_1 = local_arr_1[aux_1 % 3];
  int sample_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_86_1 == accumulator_86_2);
  assert(residue_52_1 == residue_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_52_1 == sample_52_2);
}

int fn_R001766_6613_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_86 = (aux + st.buffer[1]) & 3;
  switch (accumulator_86)
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

  int residue_52 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_52 = ((residue_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_52) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int sample_52 = local_arr[aux % 3];
  acc = (acc + (sample_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001766_6613_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st_1 = {0};
  struct MatrixBlock_R001766_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quotient_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_19_1) & 63;
  aux_2 = (aux_2 + quotient_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_68_1 = local_arr_1[aux_1 % 3];
  int factor_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_19_1 == quotient_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_68_1 == factor_68_2);
}

int fn_R001766_6613_17(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quotient_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_19) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_68 = local_arr[aux % 3];
  acc = (acc + (factor_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001766_6613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st_1 = {0};
  struct SensorNode_R001766_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_35_1 = local_arr_1[aux_1 % 3];
  int delta_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_35_2 * 2)) & 127;
  int vector_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_20_1) & 63;
  aux_2 = (aux_2 + vector_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_35_1 == delta_35_2);
  assert(vector_20_1 == vector_20_2);
}

int fn_R001766_6613_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int delta_35 = local_arr[aux % 3];
  acc = (acc + (delta_35 * 2)) & 127;
  int vector_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_20) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001766_6613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st_1 = {0};
  struct MatrixBlock_R001766_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int cursor_65_1 = 0;
  int cursor_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_65_1 = ((cursor_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_65_2 = ((cursor_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_65_1) & 127;
    acc_2 = (acc_2 + cursor_65_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_84_1 = local_arr_1[aux_1 % 3];
  int mask_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_84_2 * 2)) & 127;
  int scale_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_11_1)
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

  switch (scale_11_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_65_1 == cursor_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_84_1 == mask_84_2);
  assert(scale_11_1 == scale_11_2);
}

int fn_R001766_6613_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int cursor_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_65 = ((cursor_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_65) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int mask_84 = local_arr[aux % 3];
  acc = (acc + (mask_84 * 2)) & 127;
  int scale_11 = (aux + st.buffer[1]) & 3;
  switch (scale_11)
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

void fn_R001766_6613_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st_1 = {0};
  struct MatrixBlock_R001766_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int delta_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_69_1) & 63;
  aux_2 = (aux_2 + delta_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_43_1 > 18)
  {
    acc_1 = ((acc_1 + (scale_43_1 * 2)) + 5) & 127;
    aux_1 ^= scale_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_43_2 > 18)
  {
    acc_2 = ((acc_2 + (scale_43_2 * 2)) + 5) & 127;
    aux_2 ^= scale_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_18_1 = local_arr_1[aux_1 % 3];
  int residue_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_18_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_69_1 == delta_69_2);
  assert(scale_43_1 == scale_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_18_1 == residue_18_2);
}

int fn_R001766_6613_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int delta_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_69) & 63;
  acc ^= aux;
  int scale_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_43 > 18)
  {
    acc = ((acc + (scale_43 * 2)) + 5) & 127;
    aux ^= scale_43 & 15;
  }
  else
  {
    acc = ((acc - scale_43) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_18 = local_arr[aux % 3];
  acc = (acc + (residue_18 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001766_6613_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st_1 = {0};
  struct MatrixBlock_R001766_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int metric_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_63_1)
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

  switch (metric_63_2)
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
  int weight_48_1 = local_arr_1[aux_1 % 3];
  int weight_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_48_2 * 2)) & 127;
  int bound_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_68_1) & 63;
  aux_2 = (aux_2 + bound_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_63_1 == metric_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_48_1 == weight_48_2);
  assert(bound_68_1 == bound_68_2);
}

int fn_R001766_6613_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int metric_63 = (aux + st.buffer[1]) & 3;
  switch (metric_63)
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
  int weight_48 = local_arr[aux % 3];
  acc = (acc + (weight_48 * 2)) & 127;
  int bound_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001766_6613_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st_1 = {0};
  struct SensorNode_R001766_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_41_1 = local_arr_1[aux_1 % 3];
  int scale_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_41_2 * 2)) & 127;
  int residue_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_20_1) & 63;
  aux_2 = (aux_2 + residue_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_69_1 > 36)
  {
    acc_1 = ((acc_1 + (vector_69_1 * 2)) + 5) & 127;
    aux_1 ^= vector_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_69_2 > 36)
  {
    acc_2 = ((acc_2 + (vector_69_2 * 2)) + 5) & 127;
    aux_2 ^= vector_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_75_1 = 0;
  int margin_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_75_1 = ((margin_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_75_2 = ((margin_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_75_1) & 127;
    acc_2 = (acc_2 + margin_75_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_41_1 == scale_41_2);
  assert(residue_20_1 == residue_20_2);
  assert(vector_69_1 == vector_69_2);
  assert(margin_75_1 == margin_75_2);
}

int fn_R001766_6613_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001766_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int scale_41 = local_arr[aux % 3];
  acc = (acc + (scale_41 * 2)) & 127;
  int residue_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_20) & 63;
  acc ^= aux;
  int vector_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_69 > 36)
  {
    acc = ((acc + (vector_69 * 2)) + 5) & 127;
    aux ^= vector_69 & 15;
  }
  else
  {
    acc = ((acc - vector_69) + 11) & 127;
    aux += 3;
  }
  int margin_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_75 = ((margin_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_75) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001766_6613_23_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st_1 = {0};
  struct MatrixBlock_R001766_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int threshold_33_1 = 0;
  int threshold_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_33_1 = ((threshold_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_33_2 = ((threshold_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_33_1) & 127;
    acc_2 = (acc_2 + threshold_33_2) & 127;
  }

  int vector_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_35_1) & 63;
  aux_2 = (aux_2 + vector_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_85_1 > 28)
  {
    acc_1 = ((acc_1 + (phase_85_1 * 2)) + 5) & 127;
    aux_1 ^= phase_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_85_2 > 28)
  {
    acc_2 = ((acc_2 + (phase_85_2 * 2)) + 5) & 127;
    aux_2 ^= phase_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_33_1 == threshold_33_2);
  assert(vector_35_1 == vector_35_2);
  assert(phase_85_1 == phase_85_2);
}

int fn_R001766_6613_23(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001766_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int threshold_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_33 = ((threshold_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_33) & 127;
  }

  int vector_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_35) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_85 > 28)
  {
    acc = ((acc + (phase_85 * 2)) + 5) & 127;
    aux ^= phase_85 & 15;
  }
  else
  {
    acc = ((acc - phase_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001766_0_1;
  int sec_r001766_0_2;
  int sec_r001766_1_1;
  int sec_r001766_1_2;
  int sec_r001766_2_1;
  int sec_r001766_2_2;
  int sec_r001766_3_1;
  int sec_r001766_3_2;
  int sec_r001766_4_1;
  int sec_r001766_4_2;
  int sec_r001766_5_1;
  int sec_r001766_5_2;
  int sec_r001766_6_1;
  int sec_r001766_6_2;
  int sec_r001766_7_1;
  int sec_r001766_7_2;
  int sec_r001766_8_1;
  int sec_r001766_8_2;
  int sec_r001766_9_1;
  int sec_r001766_9_2;
  int sec_r001766_10_1;
  int sec_r001766_10_2;
  int sec_r001766_11_1;
  int sec_r001766_11_2;
  int sec_r001766_12_1;
  int sec_r001766_12_2;
  int sec_r001766_13_1;
  int sec_r001766_13_2;
  int sec_r001766_14_1;
  int sec_r001766_14_2;
  int sec_r001766_15_1;
  int sec_r001766_15_2;
  int sec_r001766_16_1;
  int sec_r001766_16_2;
  int sec_r001766_17_1;
  int sec_r001766_17_2;
  int sec_r001766_18_1;
  int sec_r001766_18_2;
  int sec_r001766_19_1;
  int sec_r001766_19_2;
  int sec_r001766_20_1;
  int sec_r001766_20_2;
  int pub_r001766_0_1;
  int pub_r001766_0_2;
  int pub_r001766_1_1;
  int pub_r001766_1_2;
  int pub_r001766_2_1;
  int pub_r001766_2_2;
  int pub_r001766_3_1;
  int pub_r001766_3_2;
  int pub_r001766_4_1;
  int pub_r001766_4_2;
  int pub_r001766_5_1;
  int pub_r001766_5_2;
  int pub_r001766_6_1;
  int pub_r001766_6_2;
  int pub_r001766_7_1;
  int pub_r001766_7_2;
  int pub_r001766_8_1;
  int pub_r001766_8_2;
  int pub_r001766_9_1;
  int pub_r001766_9_2;
  int pub_r001766_10_1;
  int pub_r001766_10_2;
  int pub_r001766_11_1;
  int pub_r001766_11_2;
  int pub_r001766_12_1;
  int pub_r001766_12_2;
  int pub_r001766_13_1;
  int pub_r001766_13_2;
  int pub_r001766_14_1;
  int pub_r001766_14_2;
  int pub_r001766_15_1;
  int pub_r001766_15_2;
  int pub_r001766_16_1;
  int pub_r001766_16_2;
  int pub_r001766_17_1;
  int pub_r001766_17_2;
  int pub_r001766_18_1;
  int pub_r001766_18_2;
  int pub_r001766_19_1;
  int pub_r001766_19_2;
  int pub_r001766_20_1;
  int pub_r001766_20_2;
  int pub_r001766_21_1;
  int pub_r001766_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001766_0_1 >= (-100)) && (pub_r001766_0_1 <= 100));
  __CPROVER_assume((pub_r001766_0_2 >= (-100)) && (pub_r001766_0_2 <= 100));
  __CPROVER_assume((pub_r001766_1_1 >= (-100)) && (pub_r001766_1_1 <= 100));
  __CPROVER_assume((pub_r001766_1_2 >= (-100)) && (pub_r001766_1_2 <= 100));
  __CPROVER_assume((pub_r001766_2_1 >= (-100)) && (pub_r001766_2_1 <= 100));
  __CPROVER_assume((pub_r001766_2_2 >= (-100)) && (pub_r001766_2_2 <= 100));
  __CPROVER_assume((pub_r001766_3_1 >= (-100)) && (pub_r001766_3_1 <= 100));
  __CPROVER_assume((pub_r001766_3_2 >= (-100)) && (pub_r001766_3_2 <= 100));
  __CPROVER_assume((pub_r001766_4_1 >= (-100)) && (pub_r001766_4_1 <= 100));
  __CPROVER_assume((pub_r001766_4_2 >= (-100)) && (pub_r001766_4_2 <= 100));
  __CPROVER_assume((pub_r001766_5_1 >= (-100)) && (pub_r001766_5_1 <= 100));
  __CPROVER_assume((pub_r001766_5_2 >= (-100)) && (pub_r001766_5_2 <= 100));
  __CPROVER_assume((pub_r001766_6_1 >= (-100)) && (pub_r001766_6_1 <= 100));
  __CPROVER_assume((pub_r001766_6_2 >= (-100)) && (pub_r001766_6_2 <= 100));
  __CPROVER_assume((pub_r001766_7_1 >= (-100)) && (pub_r001766_7_1 <= 100));
  __CPROVER_assume((pub_r001766_7_2 >= (-100)) && (pub_r001766_7_2 <= 100));
  __CPROVER_assume((pub_r001766_8_1 >= (-100)) && (pub_r001766_8_1 <= 100));
  __CPROVER_assume((pub_r001766_8_2 >= (-100)) && (pub_r001766_8_2 <= 100));
  __CPROVER_assume((pub_r001766_9_1 >= (-100)) && (pub_r001766_9_1 <= 100));
  __CPROVER_assume((pub_r001766_9_2 >= (-100)) && (pub_r001766_9_2 <= 100));
  __CPROVER_assume((pub_r001766_10_1 >= (-100)) && (pub_r001766_10_1 <= 100));
  __CPROVER_assume((pub_r001766_10_2 >= (-100)) && (pub_r001766_10_2 <= 100));
  __CPROVER_assume((pub_r001766_11_1 >= (-100)) && (pub_r001766_11_1 <= 100));
  __CPROVER_assume((pub_r001766_11_2 >= (-100)) && (pub_r001766_11_2 <= 100));
  __CPROVER_assume((pub_r001766_12_1 >= (-100)) && (pub_r001766_12_1 <= 100));
  __CPROVER_assume((pub_r001766_12_2 >= (-100)) && (pub_r001766_12_2 <= 100));
  __CPROVER_assume((pub_r001766_13_1 >= (-100)) && (pub_r001766_13_1 <= 100));
  __CPROVER_assume((pub_r001766_13_2 >= (-100)) && (pub_r001766_13_2 <= 100));
  __CPROVER_assume((pub_r001766_14_1 >= (-100)) && (pub_r001766_14_1 <= 100));
  __CPROVER_assume((pub_r001766_14_2 >= (-100)) && (pub_r001766_14_2 <= 100));
  __CPROVER_assume((pub_r001766_15_1 >= (-100)) && (pub_r001766_15_1 <= 100));
  __CPROVER_assume((pub_r001766_15_2 >= (-100)) && (pub_r001766_15_2 <= 100));
  __CPROVER_assume((pub_r001766_16_1 >= (-100)) && (pub_r001766_16_1 <= 100));
  __CPROVER_assume((pub_r001766_16_2 >= (-100)) && (pub_r001766_16_2 <= 100));
  __CPROVER_assume((pub_r001766_17_1 >= (-100)) && (pub_r001766_17_1 <= 100));
  __CPROVER_assume((pub_r001766_17_2 >= (-100)) && (pub_r001766_17_2 <= 100));
  __CPROVER_assume((pub_r001766_18_1 >= (-100)) && (pub_r001766_18_1 <= 100));
  __CPROVER_assume((pub_r001766_18_2 >= (-100)) && (pub_r001766_18_2 <= 100));
  __CPROVER_assume((pub_r001766_19_1 >= (-100)) && (pub_r001766_19_1 <= 100));
  __CPROVER_assume((pub_r001766_19_2 >= (-100)) && (pub_r001766_19_2 <= 100));
  __CPROVER_assume((pub_r001766_20_1 >= (-100)) && (pub_r001766_20_1 <= 100));
  __CPROVER_assume((pub_r001766_20_2 >= (-100)) && (pub_r001766_20_2 <= 100));
  __CPROVER_assume((pub_r001766_21_1 >= (-100)) && (pub_r001766_21_1 <= 100));
  __CPROVER_assume((pub_r001766_21_2 >= (-100)) && (pub_r001766_21_2 <= 100));
  __CPROVER_assume((sec_r001766_0_1 >= 0) && (sec_r001766_0_1 <= 255));
  __CPROVER_assume((sec_r001766_0_2 >= 0) && (sec_r001766_0_2 <= 255));
  __CPROVER_assume((sec_r001766_1_1 >= 0) && (sec_r001766_1_1 <= 255));
  __CPROVER_assume((sec_r001766_1_2 >= 0) && (sec_r001766_1_2 <= 255));
  __CPROVER_assume((sec_r001766_2_1 >= 0) && (sec_r001766_2_1 <= 255));
  __CPROVER_assume((sec_r001766_2_2 >= 0) && (sec_r001766_2_2 <= 255));
  __CPROVER_assume((sec_r001766_3_1 >= 0) && (sec_r001766_3_1 <= 255));
  __CPROVER_assume((sec_r001766_3_2 >= 0) && (sec_r001766_3_2 <= 255));
  __CPROVER_assume((sec_r001766_4_1 >= 0) && (sec_r001766_4_1 <= 255));
  __CPROVER_assume((sec_r001766_4_2 >= 0) && (sec_r001766_4_2 <= 255));
  __CPROVER_assume((sec_r001766_5_1 >= 0) && (sec_r001766_5_1 <= 255));
  __CPROVER_assume((sec_r001766_5_2 >= 0) && (sec_r001766_5_2 <= 255));
  __CPROVER_assume((sec_r001766_6_1 >= 0) && (sec_r001766_6_1 <= 255));
  __CPROVER_assume((sec_r001766_6_2 >= 0) && (sec_r001766_6_2 <= 255));
  __CPROVER_assume((sec_r001766_7_1 >= 0) && (sec_r001766_7_1 <= 255));
  __CPROVER_assume((sec_r001766_7_2 >= 0) && (sec_r001766_7_2 <= 255));
  __CPROVER_assume((sec_r001766_8_1 >= 0) && (sec_r001766_8_1 <= 255));
  __CPROVER_assume((sec_r001766_8_2 >= 0) && (sec_r001766_8_2 <= 255));
  __CPROVER_assume((sec_r001766_9_1 >= 0) && (sec_r001766_9_1 <= 255));
  __CPROVER_assume((sec_r001766_9_2 >= 0) && (sec_r001766_9_2 <= 255));
  __CPROVER_assume((sec_r001766_10_1 >= 0) && (sec_r001766_10_1 <= 255));
  __CPROVER_assume((sec_r001766_10_2 >= 0) && (sec_r001766_10_2 <= 255));
  __CPROVER_assume((sec_r001766_11_1 >= 0) && (sec_r001766_11_1 <= 255));
  __CPROVER_assume((sec_r001766_11_2 >= 0) && (sec_r001766_11_2 <= 255));
  __CPROVER_assume((sec_r001766_12_1 >= 0) && (sec_r001766_12_1 <= 255));
  __CPROVER_assume((sec_r001766_12_2 >= 0) && (sec_r001766_12_2 <= 255));
  __CPROVER_assume((sec_r001766_13_1 >= 0) && (sec_r001766_13_1 <= 255));
  __CPROVER_assume((sec_r001766_13_2 >= 0) && (sec_r001766_13_2 <= 255));
  __CPROVER_assume((sec_r001766_14_1 >= 0) && (sec_r001766_14_1 <= 255));
  __CPROVER_assume((sec_r001766_14_2 >= 0) && (sec_r001766_14_2 <= 255));
  __CPROVER_assume((sec_r001766_15_1 >= 0) && (sec_r001766_15_1 <= 255));
  __CPROVER_assume((sec_r001766_15_2 >= 0) && (sec_r001766_15_2 <= 255));
  __CPROVER_assume((sec_r001766_16_1 >= 0) && (sec_r001766_16_1 <= 255));
  __CPROVER_assume((sec_r001766_16_2 >= 0) && (sec_r001766_16_2 <= 255));
  __CPROVER_assume((sec_r001766_17_1 >= 0) && (sec_r001766_17_1 <= 255));
  __CPROVER_assume((sec_r001766_17_2 >= 0) && (sec_r001766_17_2 <= 255));
  __CPROVER_assume((sec_r001766_18_1 >= 0) && (sec_r001766_18_1 <= 255));
  __CPROVER_assume((sec_r001766_18_2 >= 0) && (sec_r001766_18_2 <= 255));
  __CPROVER_assume((sec_r001766_19_1 >= 0) && (sec_r001766_19_1 <= 255));
  __CPROVER_assume((sec_r001766_19_2 >= 0) && (sec_r001766_19_2 <= 255));
  __CPROVER_assume((sec_r001766_20_1 >= 0) && (sec_r001766_20_1 <= 255));
  __CPROVER_assume((sec_r001766_20_2 >= 0) && (sec_r001766_20_2 <= 255));
  struct SensorNode_R001766_6613_0 st_var_0_1 = {0};
  struct SensorNode_R001766_6613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001766_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001766_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001766_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001766_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001766_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001766_0_2 + 7) & 15;
  struct MatrixBlock_R001766_6613_1 st_var_1_1 = {0};
  struct MatrixBlock_R001766_6613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001766_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001766_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001766_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001766_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001766_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001766_0_2 + 9) & 15;
  union ColorPixel_R001766_6613_0 u_var_1;
  union ColorPixel_R001766_6613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001766_6613_0(sec_r001766_0_1, pub_r001766_1_1, pub_r001766_2_1, pub_r001766_3_1, pub_r001766_4_1);
  int helper_flow_0_2 = fn_R001766_6613_0(sec_r001766_0_2, pub_r001766_1_2, pub_r001766_2_2, pub_r001766_3_2, pub_r001766_4_2);
  fn_R001766_6613_0_2(sec_r001766_0_1, pub_r001766_1_1, pub_r001766_2_1, pub_r001766_3_1, pub_r001766_4_1, sec_r001766_0_2, pub_r001766_1_2, pub_r001766_2_2, pub_r001766_3_2, pub_r001766_4_2);
  int helper_flow_1_1 = fn_R001766_6613_1(sec_r001766_1_1, pub_r001766_2_1);
  int helper_flow_1_2 = fn_R001766_6613_1(sec_r001766_1_2, pub_r001766_2_2);
  fn_R001766_6613_1_2(sec_r001766_1_1, pub_r001766_2_1, sec_r001766_1_2, pub_r001766_2_2);
  int helper_flow_2_1 = fn_R001766_6613_2(sec_r001766_2_1, pub_r001766_3_1, pub_r001766_4_1);
  int helper_flow_2_2 = fn_R001766_6613_2(sec_r001766_2_2, pub_r001766_3_2, pub_r001766_4_2);
  fn_R001766_6613_2_2(sec_r001766_2_1, pub_r001766_3_1, pub_r001766_4_1, sec_r001766_2_2, pub_r001766_3_2, pub_r001766_4_2);
  int helper_flow_3_1 = fn_R001766_6613_3(sec_r001766_3_1, sec_r001766_4_1, pub_r001766_5_1, pub_r001766_6_1, pub_r001766_7_1);
  int helper_flow_3_2 = fn_R001766_6613_3(sec_r001766_3_2, sec_r001766_4_2, pub_r001766_5_2, pub_r001766_6_2, pub_r001766_7_2);
  fn_R001766_6613_3_2(sec_r001766_3_1, sec_r001766_4_1, pub_r001766_5_1, pub_r001766_6_1, pub_r001766_7_1, sec_r001766_3_2, sec_r001766_4_2, pub_r001766_5_2, pub_r001766_6_2, pub_r001766_7_2);
  int helper_flow_4_1 = fn_R001766_6613_4(sec_r001766_4_1, sec_r001766_5_1, pub_r001766_6_1, pub_r001766_7_1, pub_r001766_8_1);
  int helper_flow_4_2 = fn_R001766_6613_4(sec_r001766_4_2, sec_r001766_5_2, pub_r001766_6_2, pub_r001766_7_2, pub_r001766_8_2);
  fn_R001766_6613_4_2(sec_r001766_4_1, sec_r001766_5_1, pub_r001766_6_1, pub_r001766_7_1, pub_r001766_8_1, sec_r001766_4_2, sec_r001766_5_2, pub_r001766_6_2, pub_r001766_7_2, pub_r001766_8_2);
  int helper_flow_5_1 = fn_R001766_6613_5(sec_r001766_5_1, sec_r001766_6_1, pub_r001766_7_1, pub_r001766_8_1);
  int helper_flow_5_2 = fn_R001766_6613_5(sec_r001766_5_2, sec_r001766_6_2, pub_r001766_7_2, pub_r001766_8_2);
  fn_R001766_6613_5_2(sec_r001766_5_1, sec_r001766_6_1, pub_r001766_7_1, pub_r001766_8_1, sec_r001766_5_2, sec_r001766_6_2, pub_r001766_7_2, pub_r001766_8_2);
  int helper_flow_6_1 = fn_R001766_6613_6(sec_r001766_6_1, sec_r001766_7_1, pub_r001766_8_1);
  int helper_flow_6_2 = fn_R001766_6613_6(sec_r001766_6_2, sec_r001766_7_2, pub_r001766_8_2);
  fn_R001766_6613_6_2(sec_r001766_6_1, sec_r001766_7_1, pub_r001766_8_1, sec_r001766_6_2, sec_r001766_7_2, pub_r001766_8_2);
  int helper_flow_7_1 = fn_R001766_6613_7(sec_r001766_7_1, pub_r001766_8_1, pub_r001766_9_1, pub_r001766_10_1);
  int helper_flow_7_2 = fn_R001766_6613_7(sec_r001766_7_2, pub_r001766_8_2, pub_r001766_9_2, pub_r001766_10_2);
  fn_R001766_6613_7_2(sec_r001766_7_1, pub_r001766_8_1, pub_r001766_9_1, pub_r001766_10_1, sec_r001766_7_2, pub_r001766_8_2, pub_r001766_9_2, pub_r001766_10_2);
  int helper_flow_8_1 = fn_R001766_6613_8(sec_r001766_8_1, sec_r001766_9_1, pub_r001766_10_1, pub_r001766_11_1);
  int helper_flow_8_2 = fn_R001766_6613_8(sec_r001766_8_2, sec_r001766_9_2, pub_r001766_10_2, pub_r001766_11_2);
  fn_R001766_6613_8_2(sec_r001766_8_1, sec_r001766_9_1, pub_r001766_10_1, pub_r001766_11_1, sec_r001766_8_2, sec_r001766_9_2, pub_r001766_10_2, pub_r001766_11_2);
  int helper_flow_9_1 = fn_R001766_6613_9(sec_r001766_9_1, sec_r001766_10_1);
  int helper_flow_9_2 = fn_R001766_6613_9(sec_r001766_9_2, sec_r001766_10_2);
  fn_R001766_6613_9_2(sec_r001766_9_1, sec_r001766_10_1, sec_r001766_9_2, sec_r001766_10_2);
  int helper_flow_10_1 = fn_R001766_6613_10(sec_r001766_10_1, sec_r001766_11_1, pub_r001766_12_1, pub_r001766_13_1);
  int helper_flow_10_2 = fn_R001766_6613_10(sec_r001766_10_2, sec_r001766_11_2, pub_r001766_12_2, pub_r001766_13_2);
  fn_R001766_6613_10_2(sec_r001766_10_1, sec_r001766_11_1, pub_r001766_12_1, pub_r001766_13_1, sec_r001766_10_2, sec_r001766_11_2, pub_r001766_12_2, pub_r001766_13_2);
  int stage_v_0_1 = ((sec_r001766_10_1 + (pub_r001766_13_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001766_10_2 + (pub_r001766_13_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((helper_flow_9_1 + (pub_r001766_6_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((helper_flow_9_2 + (pub_r001766_6_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((sec_r001766_14_1 + (pub_r001766_3_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001766_14_2 + (pub_r001766_3_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((helper_flow_8_1 + (pub_r001766_6_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((helper_flow_8_2 + (pub_r001766_6_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001766_1_1 * 2) + 28) & 63;
  int stage_v_4_2 = ((pub_r001766_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((sec_r001766_12_1 + (pub_r001766_7_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001766_12_2 + (pub_r001766_7_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((sec_r001766_20_1 + (pub_r001766_1_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001766_20_2 + (pub_r001766_1_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((helper_flow_8_1 + (pub_r001766_1_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((helper_flow_8_2 + (pub_r001766_1_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((sec_r001766_2_1 + (pub_r001766_11_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((sec_r001766_2_2 + (pub_r001766_11_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((pub_r001766_21_1 * 2) + 47) & 63;
  int stage_v_9_2 = ((pub_r001766_21_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001766_11_1 * 2) + 26) & 63;
  int stage_v_10_2 = ((pub_r001766_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001766_11_1 * 2) + 50) & 63;
  int stage_v_11_2 = ((pub_r001766_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((sec_r001766_9_1 + (pub_r001766_12_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001766_9_2 + (pub_r001766_12_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((sec_r001766_17_1 + (pub_r001766_12_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001766_17_2 + (pub_r001766_12_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((helper_flow_8_1 + (pub_r001766_20_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((helper_flow_8_2 + (pub_r001766_20_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((stage_v_5_1 + (pub_r001766_9_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((stage_v_5_2 + (pub_r001766_9_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((sec_r001766_18_1 + (pub_r001766_8_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((sec_r001766_18_2 + (pub_r001766_8_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((helper_flow_7_1 + (pub_r001766_3_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((helper_flow_7_2 + (pub_r001766_3_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((sec_r001766_19_1 + (pub_r001766_10_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((sec_r001766_19_2 + (pub_r001766_10_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((stage_v_12_1 + (pub_r001766_15_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((stage_v_12_2 + (pub_r001766_15_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((pub_r001766_17_1 * 2) + 11) & 63;
  int stage_v_20_2 = ((pub_r001766_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((stage_v_5_1 + (pub_r001766_0_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_5_2 + (pub_r001766_0_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((stage_v_2_1 + (pub_r001766_14_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((stage_v_2_2 + (pub_r001766_14_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((helper_flow_5_1 + (pub_r001766_6_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((helper_flow_5_2 + (pub_r001766_6_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((stage_v_2_1 + (pub_r001766_8_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((stage_v_2_2 + (pub_r001766_8_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((helper_flow_2_1 + (pub_r001766_17_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((helper_flow_2_2 + (pub_r001766_17_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((stage_v_16_1 + (pub_r001766_18_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((stage_v_16_2 + (pub_r001766_18_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((pub_r001766_11_1 * 2) + 46) & 63;
  int stage_v_27_2 = ((pub_r001766_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((stage_v_2_1 + (pub_r001766_14_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_2_2 + (pub_r001766_14_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((stage_v_6_1 + (pub_r001766_3_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((stage_v_6_2 + (pub_r001766_3_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((stage_v_23_1 + (pub_r001766_13_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((stage_v_23_2 + (pub_r001766_13_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((sec_r001766_5_1 + (pub_r001766_12_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((sec_r001766_5_2 + (pub_r001766_12_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((pub_r001766_6_1 * 2) + 39) & 63;
  int stage_v_32_2 = ((pub_r001766_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((helper_flow_10_1 + (pub_r001766_3_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((helper_flow_10_2 + (pub_r001766_3_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((stage_v_23_1 + (pub_r001766_0_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((stage_v_23_2 + (pub_r001766_0_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((sec_r001766_10_1 + (pub_r001766_20_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((sec_r001766_10_2 + (pub_r001766_20_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((pub_r001766_17_1 * 2) + 43) & 63;
  int stage_v_36_2 = ((pub_r001766_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((helper_flow_9_1 + (pub_r001766_9_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((helper_flow_9_2 + (pub_r001766_9_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((sec_r001766_10_1 + (pub_r001766_16_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((sec_r001766_10_2 + (pub_r001766_16_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((helper_flow_7_1 + (pub_r001766_0_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((helper_flow_7_2 + (pub_r001766_0_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((sec_r001766_11_1 + (pub_r001766_18_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((sec_r001766_11_2 + (pub_r001766_18_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((pub_r001766_8_1 * 2) + 35) & 63;
  int stage_v_41_2 = ((pub_r001766_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((stage_v_14_1 + (pub_r001766_2_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((stage_v_14_2 + (pub_r001766_2_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((pub_r001766_9_1 * 2) + 7) & 63;
  int stage_v_43_2 = ((pub_r001766_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((sec_r001766_11_1 + (pub_r001766_8_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((sec_r001766_11_2 + (pub_r001766_8_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((pub_r001766_9_1 * 2) + 29) & 63;
  int stage_v_45_2 = ((pub_r001766_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((sec_r001766_10_1 + (pub_r001766_4_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((sec_r001766_10_2 + (pub_r001766_4_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((sec_r001766_12_1 + (pub_r001766_7_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((sec_r001766_12_2 + (pub_r001766_7_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((pub_r001766_8_1 * 2) + 32) & 63;
  int stage_v_48_2 = ((pub_r001766_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((helper_flow_4_1 + (pub_r001766_3_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((helper_flow_4_2 + (pub_r001766_3_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((pub_r001766_3_1 * 2) + 45) & 63;
  int stage_v_50_2 = ((pub_r001766_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001766_15_1 * 2) + 5) & 63;
  int stage_v_51_2 = ((pub_r001766_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001766_3_1 * 2) + 8) & 63;
  int stage_v_52_2 = ((pub_r001766_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((stage_v_13_1 + (pub_r001766_21_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((stage_v_13_2 + (pub_r001766_21_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((sec_r001766_0_1 + (pub_r001766_9_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((sec_r001766_0_2 + (pub_r001766_9_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((pub_r001766_1_1 * 2) + 18) & 63;
  int stage_v_55_2 = ((pub_r001766_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001766_13_1 * 2) + 39) & 63;
  int stage_v_56_2 = ((pub_r001766_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((stage_v_42_1 + (pub_r001766_13_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_42_2 + (pub_r001766_13_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((stage_v_37_1 + (pub_r001766_6_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_37_2 + (pub_r001766_6_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((pub_r001766_2_1 * 2) + 45) & 63;
  int stage_v_59_2 = ((pub_r001766_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001766_15_1 * 2) + 13) & 63;
  int stage_v_60_2 = ((pub_r001766_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001766_4_1 * 2) + 30) & 63;
  int stage_v_61_2 = ((pub_r001766_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((sec_r001766_11_1 + (pub_r001766_14_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((sec_r001766_11_2 + (pub_r001766_14_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((stage_v_14_1 + (pub_r001766_11_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_14_2 + (pub_r001766_11_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((helper_flow_1_1 + (pub_r001766_21_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((helper_flow_1_2 + (pub_r001766_21_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((pub_r001766_2_1 * 2) + 48) & 63;
  int stage_v_65_2 = ((pub_r001766_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((stage_v_2_1 + (pub_r001766_6_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((stage_v_2_2 + (pub_r001766_6_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((stage_v_14_1 + (pub_r001766_3_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_14_2 + (pub_r001766_3_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((pub_r001766_9_1 * 2) + 37) & 63;
  int stage_v_68_2 = ((pub_r001766_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001766_18_1 * 2) + 5) & 63;
  int stage_v_69_2 = ((pub_r001766_18_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((helper_flow_0_1 + (pub_r001766_18_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((helper_flow_0_2 + (pub_r001766_18_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((stage_v_25_1 + (pub_r001766_0_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_25_2 + (pub_r001766_0_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((pub_r001766_16_1 * 2) + 50) & 63;
  int stage_v_72_2 = ((pub_r001766_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001766_17_1 * 2) + 6) & 63;
  int stage_v_73_2 = ((pub_r001766_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((stage_v_0_1 + (pub_r001766_20_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_0_2 + (pub_r001766_20_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((pub_r001766_11_1 * 2) + 10) & 63;
  int stage_v_75_2 = ((pub_r001766_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001766_7_1 * 2) + 28) & 63;
  int stage_v_76_2 = ((pub_r001766_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((stage_v_28_1 + (pub_r001766_20_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_28_2 + (pub_r001766_20_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_74_1 + (pub_r001766_7_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_74_2 + (pub_r001766_7_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((pub_r001766_11_1 * 2) + 22) & 63;
  int stage_v_79_2 = ((pub_r001766_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((stage_v_22_1 + (pub_r001766_10_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_22_2 + (pub_r001766_10_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((helper_flow_7_1 + (pub_r001766_13_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((helper_flow_7_2 + (pub_r001766_13_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((pub_r001766_2_1 * 2) + 47) & 63;
  int stage_v_82_2 = ((pub_r001766_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001766_18_1 * 2) + 47) & 63;
  int stage_v_83_2 = ((pub_r001766_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((stage_v_54_1 + (pub_r001766_19_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_54_2 + (pub_r001766_19_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((stage_v_44_1 + (pub_r001766_15_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_44_2 + (pub_r001766_15_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_57_1 + (pub_r001766_12_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_57_2 + (pub_r001766_12_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_80_1 + (pub_r001766_3_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_80_2 + (pub_r001766_3_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((pub_r001766_16_1 * 2) + 40) & 63;
  int stage_v_88_2 = ((pub_r001766_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001766_21_1 * 2) + 44) & 63;
  int stage_v_89_2 = ((pub_r001766_21_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((stage_v_0_1 + (pub_r001766_2_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_0_2 + (pub_r001766_2_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((stage_v_53_1 + (pub_r001766_20_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_53_2 + (pub_r001766_20_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((stage_v_35_1 + (pub_r001766_10_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_35_2 + (pub_r001766_10_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((sec_r001766_5_1 + (pub_r001766_12_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((sec_r001766_5_2 + (pub_r001766_12_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_12_1 + (pub_r001766_19_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_12_2 + (pub_r001766_19_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_38_1 + (pub_r001766_20_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_38_2 + (pub_r001766_20_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((pub_r001766_4_1 * 2) + 7) & 63;
  int stage_v_96_2 = ((pub_r001766_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001766_3_1 * 2) + 12) & 63;
  int stage_v_97_2 = ((pub_r001766_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((stage_v_74_1 + (pub_r001766_16_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_74_2 + (pub_r001766_16_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((stage_v_64_1 + (pub_r001766_15_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_64_2 + (pub_r001766_15_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((sec_r001766_3_1 + (pub_r001766_8_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((sec_r001766_3_2 + (pub_r001766_8_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((helper_flow_9_1 + (pub_r001766_7_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((helper_flow_9_2 + (pub_r001766_7_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((stage_v_38_1 + (pub_r001766_9_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_38_2 + (pub_r001766_9_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((stage_v_87_1 + (pub_r001766_3_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_87_2 + (pub_r001766_3_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001766_4_1 * 2) + 32) & 63;
  int stage_v_104_2 = ((pub_r001766_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((stage_v_26_1 + (pub_r001766_2_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_26_2 + (pub_r001766_2_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((helper_flow_2_1 + (pub_r001766_15_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((helper_flow_2_2 + (pub_r001766_15_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((stage_v_103_1 + (pub_r001766_18_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_103_2 + (pub_r001766_18_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((helper_flow_0_1 + (pub_r001766_7_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((helper_flow_0_2 + (pub_r001766_7_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_98_1 + (pub_r001766_6_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_98_2 + (pub_r001766_6_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((pub_r001766_6_1 * 2) + 17) & 63;
  int stage_v_110_2 = ((pub_r001766_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001766_15_1 * 2) + 47) & 63;
  int stage_v_111_2 = ((pub_r001766_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((sec_r001766_20_1 + (pub_r001766_8_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((sec_r001766_20_2 + (pub_r001766_8_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((pub_r001766_16_1 * 2) + 27) & 63;
  int stage_v_113_2 = ((pub_r001766_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001766_12_1 * 2) + 27) & 63;
  int stage_v_114_2 = ((pub_r001766_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((stage_v_23_1 + (pub_r001766_17_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_23_2 + (pub_r001766_17_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_44_1 + (pub_r001766_21_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_44_2 + (pub_r001766_21_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((stage_v_66_1 + (pub_r001766_18_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((stage_v_66_2 + (pub_r001766_18_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((pub_r001766_8_1 * 2) + 39) & 63;
  int stage_v_118_2 = ((pub_r001766_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001766_6_1 * 2) + 15) & 63;
  int stage_v_119_2 = ((pub_r001766_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((stage_v_85_1 + (pub_r001766_9_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_85_2 + (pub_r001766_9_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((pub_r001766_5_1 * 2) + 9) & 63;
  int stage_v_121_2 = ((pub_r001766_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((stage_v_91_1 + (pub_r001766_14_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_91_2 + (pub_r001766_14_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_38_1 + (pub_r001766_1_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_38_2 + (pub_r001766_1_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((sec_r001766_13_1 + (pub_r001766_1_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((sec_r001766_13_2 + (pub_r001766_1_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((pub_r001766_1_1 * 2) + 29) & 63;
  int stage_v_125_2 = ((pub_r001766_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001766_17_1 * 2) + 25) & 63;
  int stage_v_126_2 = ((pub_r001766_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001766_15_1 * 2) + 11) & 63;
  int stage_v_127_2 = ((pub_r001766_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001766_21_1 * 2) + 15) & 63;
  int stage_v_128_2 = ((pub_r001766_21_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001766_2_1 * 2) + 11) & 63;
  int stage_v_129_2 = ((pub_r001766_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((stage_v_103_1 + (pub_r001766_9_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_103_2 + (pub_r001766_9_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((stage_v_6_1 + (pub_r001766_2_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_6_2 + (pub_r001766_2_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((sec_r001766_12_1 + (pub_r001766_7_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((sec_r001766_12_2 + (pub_r001766_7_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((sec_r001766_3_1 + (pub_r001766_15_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((sec_r001766_3_2 + (pub_r001766_15_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((pub_r001766_4_1 * 2) + 32) & 63;
  int stage_v_134_2 = ((pub_r001766_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((sec_r001766_17_1 + (pub_r001766_18_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((sec_r001766_17_2 + (pub_r001766_18_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_15_1 + (pub_r001766_20_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_15_2 + (pub_r001766_20_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_23_1 + (pub_r001766_16_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_23_2 + (pub_r001766_16_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((pub_r001766_3_1 * 2) + 21) & 63;
  int stage_v_138_2 = ((pub_r001766_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((sec_r001766_1_1 + (pub_r001766_4_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((sec_r001766_1_2 + (pub_r001766_4_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((sec_r001766_9_1 + (pub_r001766_8_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((sec_r001766_9_2 + (pub_r001766_8_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((stage_v_85_1 + (pub_r001766_7_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_85_2 + (pub_r001766_7_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((sec_r001766_19_1 + (pub_r001766_20_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((sec_r001766_19_2 + (pub_r001766_20_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((stage_v_135_1 + (pub_r001766_18_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_135_2 + (pub_r001766_18_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((stage_v_112_1 + (pub_r001766_14_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_112_2 + (pub_r001766_14_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((stage_v_132_1 + (pub_r001766_19_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_132_2 + (pub_r001766_19_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_80_1 + (pub_r001766_7_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_80_2 + (pub_r001766_7_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((pub_r001766_7_1 * 2) + 26) & 63;
  int stage_v_147_2 = ((pub_r001766_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((stage_v_39_1 + (pub_r001766_5_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_39_2 + (pub_r001766_5_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((pub_r001766_4_1 * 2) + 5) & 63;
  int stage_v_149_2 = ((pub_r001766_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_1_1 + (pub_r001766_9_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_1_2 + (pub_r001766_9_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((pub_r001766_11_1 * 2) + 5) & 63;
  int stage_v_151_2 = ((pub_r001766_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((stage_v_19_1 + (pub_r001766_6_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_19_2 + (pub_r001766_6_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_135_1 + (pub_r001766_16_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_135_2 + (pub_r001766_16_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((helper_flow_8_1 + (pub_r001766_20_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((helper_flow_8_2 + (pub_r001766_20_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((stage_v_93_1 + (pub_r001766_13_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_93_2 + (pub_r001766_13_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((pub_r001766_15_1 * 2) + 37) & 63;
  int stage_v_156_2 = ((pub_r001766_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001766_13_1 * 2) + 14) & 63;
  int stage_v_157_2 = ((pub_r001766_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001766_6_1 * 2) + 37) & 63;
  int stage_v_158_2 = ((pub_r001766_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((stage_v_39_1 + (pub_r001766_13_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_39_2 + (pub_r001766_13_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((sec_r001766_18_1 + (pub_r001766_7_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((sec_r001766_18_2 + (pub_r001766_7_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((stage_v_54_1 + (pub_r001766_18_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_54_2 + (pub_r001766_18_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((pub_r001766_17_1 * 2) + 13) & 63;
  int stage_v_162_2 = ((pub_r001766_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((stage_v_133_1 + (pub_r001766_9_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_133_2 + (pub_r001766_9_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((stage_v_74_1 + (pub_r001766_0_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_74_2 + (pub_r001766_0_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((pub_r001766_17_1 * 2) + 37) & 63;
  int stage_v_165_2 = ((pub_r001766_17_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001766_13_1 * 2) + 10) & 63;
  int stage_v_166_2 = ((pub_r001766_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((stage_v_2_1 + (pub_r001766_10_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_2_2 + (pub_r001766_10_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_47_1 + (pub_r001766_2_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_47_2 + (pub_r001766_2_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_164_1 + (pub_r001766_11_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_164_2 + (pub_r001766_11_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((stage_v_100_1 + (pub_r001766_15_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_100_2 + (pub_r001766_15_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((sec_r001766_13_1 + (pub_r001766_12_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((sec_r001766_13_2 + (pub_r001766_12_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((stage_v_84_1 + (pub_r001766_1_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_84_2 + (pub_r001766_1_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((stage_v_130_1 + (pub_r001766_15_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_130_2 + (pub_r001766_15_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((sec_r001766_19_1 + (pub_r001766_19_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((sec_r001766_19_2 + (pub_r001766_19_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_54_1 + (pub_r001766_8_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_54_2 + (pub_r001766_8_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((pub_r001766_8_1 * 2) + 7) & 63;
  int stage_v_176_2 = ((pub_r001766_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((stage_v_101_1 + (pub_r001766_9_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_101_2 + (pub_r001766_9_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((stage_v_122_1 + (pub_r001766_18_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_122_2 + (pub_r001766_18_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((pub_r001766_2_1 * 2) + 31) & 63;
  int stage_v_179_2 = ((pub_r001766_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((sec_r001766_14_1 + (pub_r001766_21_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((sec_r001766_14_2 + (pub_r001766_21_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((pub_r001766_9_1 * 2) + 23) & 63;
  int stage_v_181_2 = ((pub_r001766_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001766_20_1 * 2) + 11) & 63;
  int stage_v_182_2 = ((pub_r001766_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001766_13_1 * 2) + 8) & 63;
  int stage_v_183_2 = ((pub_r001766_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((stage_v_115_1 + (pub_r001766_16_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_115_2 + (pub_r001766_16_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((pub_r001766_7_1 * 2) + 20) & 63;
  int stage_v_185_2 = ((pub_r001766_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001766_11_1 * 2) + 21) & 63;
  int stage_v_186_2 = ((pub_r001766_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001766_4_1 * 2) + 20) & 63;
  int stage_v_187_2 = ((pub_r001766_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((stage_v_178_1 + (pub_r001766_4_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((stage_v_178_2 + (pub_r001766_4_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((sec_r001766_11_1 + (pub_r001766_9_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((sec_r001766_11_2 + (pub_r001766_9_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((pub_r001766_2_1 * 2) + 34) & 63;
  int stage_v_190_2 = ((pub_r001766_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001766_4_1 * 2) + 42) & 63;
  int stage_v_191_2 = ((pub_r001766_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001766_14_1 * 2) + 8) & 63;
  int stage_v_192_2 = ((pub_r001766_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((stage_v_148_1 + (pub_r001766_6_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_148_2 + (pub_r001766_6_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((sec_r001766_20_1 + (pub_r001766_18_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((sec_r001766_20_2 + (pub_r001766_18_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_31_1 + (pub_r001766_16_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_31_2 + (pub_r001766_16_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((sec_r001766_19_1 + (pub_r001766_10_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((sec_r001766_19_2 + (pub_r001766_10_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((pub_r001766_17_1 * 2) + 21) & 63;
  int stage_v_197_2 = ((pub_r001766_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((stage_v_100_1 + (pub_r001766_4_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_100_2 + (pub_r001766_4_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_102_1 + (pub_r001766_11_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_102_2 + (pub_r001766_11_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_160_1 + (pub_r001766_20_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_160_2 + (pub_r001766_20_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((stage_v_86_1 + (pub_r001766_13_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_86_2 + (pub_r001766_13_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_169_1 + (pub_r001766_10_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_169_2 + (pub_r001766_10_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((stage_v_5_1 + (pub_r001766_14_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((stage_v_5_2 + (pub_r001766_14_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((pub_r001766_4_1 * 2) + 22) & 63;
  int stage_v_204_2 = ((pub_r001766_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((sec_r001766_9_1 + (pub_r001766_17_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((sec_r001766_9_2 + (pub_r001766_17_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((sec_r001766_0_1 + (pub_r001766_4_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((sec_r001766_0_2 + (pub_r001766_4_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((stage_v_195_1 + (pub_r001766_21_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_195_2 + (pub_r001766_21_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_70_1 + (pub_r001766_11_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_70_2 + (pub_r001766_11_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((pub_r001766_4_1 * 2) + 26) & 63;
  int stage_v_209_2 = ((pub_r001766_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((stage_v_139_1 + (pub_r001766_16_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_139_2 + (pub_r001766_16_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((pub_r001766_20_1 * 2) + 11) & 63;
  int stage_v_211_2 = ((pub_r001766_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((stage_v_198_1 + (pub_r001766_20_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_198_2 + (pub_r001766_20_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((stage_v_18_1 + (pub_r001766_7_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_18_2 + (pub_r001766_7_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((pub_r001766_13_1 * 2) + 19) & 63;
  int stage_v_214_2 = ((pub_r001766_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((helper_flow_5_1 + (pub_r001766_9_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((helper_flow_5_2 + (pub_r001766_9_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((pub_r001766_15_1 * 2) + 39) & 63;
  int stage_v_216_2 = ((pub_r001766_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((sec_r001766_10_1 + (pub_r001766_21_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((sec_r001766_10_2 + (pub_r001766_21_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_206_1 + (pub_r001766_3_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_206_2 + (pub_r001766_3_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((sec_r001766_19_1 + (pub_r001766_1_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((sec_r001766_19_2 + (pub_r001766_1_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((stage_v_54_1 + (pub_r001766_4_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((stage_v_54_2 + (pub_r001766_4_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_221_1 = ((stage_v_193_1 + (pub_r001766_9_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_193_2 + (pub_r001766_9_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((stage_v_38_1 + (pub_r001766_12_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_38_2 + (pub_r001766_12_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((sec_r001766_5_1 + (pub_r001766_12_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((sec_r001766_5_2 + (pub_r001766_12_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((stage_v_195_1 + (pub_r001766_20_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_195_2 + (pub_r001766_20_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((pub_r001766_16_1 * 2) + 29) & 63;
  int stage_v_225_2 = ((pub_r001766_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((stage_v_94_1 + (pub_r001766_7_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((stage_v_94_2 + (pub_r001766_7_2 * 2)) + 683) & 127;
  if (stage_v_226_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_226_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_226_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_226_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_227_1 = ((pub_r001766_21_1 * 2) + 36) & 63;
  int stage_v_227_2 = ((pub_r001766_21_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001766_4_1 * 2) + 36) & 63;
  int stage_v_228_2 = ((pub_r001766_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001766_1_1 * 2) + 11) & 63;
  int stage_v_229_2 = ((pub_r001766_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((sec_r001766_16_1 + (pub_r001766_21_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((sec_r001766_16_2 + (pub_r001766_21_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001766_21_1 == pub_r001766_21_2);
  __CPROVER_assume(pub_r001766_18_1 == pub_r001766_18_2);
  __CPROVER_assume(pub_r001766_12_1 == pub_r001766_12_2);
  __CPROVER_assume(sec_r001766_5_1 != sec_r001766_5_2);
  __CPROVER_assume(sec_r001766_19_1 != sec_r001766_19_2);
  __CPROVER_assume(sec_r001766_1_1 != sec_r001766_1_2);
  __CPROVER_assume(pub_r001766_17_1 == pub_r001766_17_2);
  __CPROVER_assume(sec_r001766_20_1 != sec_r001766_20_2);
  __CPROVER_assume(pub_r001766_2_1 == pub_r001766_2_2);
  __CPROVER_assume(pub_r001766_13_1 == pub_r001766_13_2);
  __CPROVER_assume(sec_r001766_6_1 != sec_r001766_6_2);
  __CPROVER_assume(pub_r001766_1_1 == pub_r001766_1_2);
  __CPROVER_assume(pub_r001766_14_1 == pub_r001766_14_2);
  __CPROVER_assume(sec_r001766_4_1 != sec_r001766_4_2);
  __CPROVER_assume(pub_r001766_20_1 == pub_r001766_20_2);
  __CPROVER_assume(pub_r001766_15_1 == pub_r001766_15_2);
  __CPROVER_assume(pub_r001766_5_1 == pub_r001766_5_2);
  __CPROVER_assume(sec_r001766_16_1 != sec_r001766_16_2);
  __CPROVER_assume(sec_r001766_8_1 != sec_r001766_8_2);
  __CPROVER_assume(sec_r001766_18_1 != sec_r001766_18_2);
  __CPROVER_assume(sec_r001766_9_1 != sec_r001766_9_2);
  __CPROVER_assume(sec_r001766_3_1 != sec_r001766_3_2);
  __CPROVER_assume(sec_r001766_15_1 != sec_r001766_15_2);
  __CPROVER_assume(pub_r001766_0_1 == pub_r001766_0_2);
  __CPROVER_assume(pub_r001766_11_1 == pub_r001766_11_2);
  __CPROVER_assume(sec_r001766_13_1 != sec_r001766_13_2);
  __CPROVER_assume(pub_r001766_19_1 == pub_r001766_19_2);
  __CPROVER_assume(sec_r001766_2_1 != sec_r001766_2_2);
  __CPROVER_assume(sec_r001766_14_1 != sec_r001766_14_2);
  __CPROVER_assume(sec_r001766_10_1 != sec_r001766_10_2);
  __CPROVER_assume(sec_r001766_7_1 != sec_r001766_7_2);
  __CPROVER_assume(pub_r001766_3_1 == pub_r001766_3_2);
  __CPROVER_assume(pub_r001766_6_1 == pub_r001766_6_2);
  __CPROVER_assume(pub_r001766_10_1 == pub_r001766_10_2);
  __CPROVER_assume(sec_r001766_12_1 != sec_r001766_12_2);
  __CPROVER_assume(pub_r001766_9_1 == pub_r001766_9_2);
  __CPROVER_assume(pub_r001766_8_1 == pub_r001766_8_2);
  __CPROVER_assume(sec_r001766_17_1 != sec_r001766_17_2);
  __CPROVER_assume(sec_r001766_11_1 != sec_r001766_11_2);
  __CPROVER_assume(sec_r001766_0_1 != sec_r001766_0_2);
  __CPROVER_assume(pub_r001766_7_1 == pub_r001766_7_2);
  __CPROVER_assume(pub_r001766_4_1 == pub_r001766_4_2);
  __CPROVER_assume(pub_r001766_16_1 == pub_r001766_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.stride == st_var_1_2.stride);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.dim == st_var_1_2.dim);
  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.trace == st_var_1_2.trace);
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
}


