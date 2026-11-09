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
struct MatrixBlock_R001196_9613_0
{
  int determinant;
  short density;
  int stride;
  int trace;
  short dim;
  short scale;
  int buffer[3];
};
struct StreamBuffer_R001196_9613_1
{
  int state;
  int checksum;
  int capacity;
  unsigned char tail;
  unsigned char watermark;
  int buffer[3];
};
union RegisterBank_R001196_9613_0
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
void fn_R001196_9613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001196_9613_0 st_1 = {0};
  struct MatrixBlock_R001196_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int accumulator_18_1 = 0;
  int accumulator_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_18_1 = ((accumulator_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_18_2 = ((accumulator_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_18_1) & 127;
    acc_2 = (acc_2 + accumulator_18_2) & 127;
  }

  int window_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_72_1) & 63;
  aux_2 = (aux_2 + window_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_35_1 = local_arr_1[aux_1 % 3];
  int window_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_18_1 == accumulator_18_2);
  assert(window_72_1 == window_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_35_1 == window_35_2);
}

int fn_R001196_9613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001196_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int accumulator_18 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_18 = ((accumulator_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_18) & 127;
  }

  int window_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_72) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_35 = local_arr[aux % 3];
  acc = (acc + (window_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001196_9613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st_1 = {0};
  struct StreamBuffer_R001196_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int mask_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_99_1)
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

  switch (mask_99_2)
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
  int parity_55_1 = 0;
  int parity_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_55_1 = ((parity_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_55_2 = ((parity_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_55_1) & 127;
    acc_2 = (acc_2 + parity_55_2) & 127;
  }

  int anchor_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_47_1) & 63;
  aux_2 = (aux_2 + anchor_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_99_1 == mask_99_2);
  assert(parity_55_1 == parity_55_2);
  assert(anchor_47_1 == anchor_47_2);
}

int fn_R001196_9613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int mask_99 = (aux + st.buffer[1]) & 3;
  switch (mask_99)
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
  int parity_55 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_55 = ((parity_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_55) & 127;
  }

  int anchor_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001196_9613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st_1 = {0};
  struct StreamBuffer_R001196_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_83_1 = local_arr_1[aux_1 % 3];
  int cursor_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_83_2 * 2)) & 127;
  int sample_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_72_1 > 30)
  {
    acc_1 = ((acc_1 + (sample_72_1 * 2)) + 5) & 127;
    aux_1 ^= sample_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_72_2 > 30)
  {
    acc_2 = ((acc_2 + (sample_72_2 * 2)) + 5) & 127;
    aux_2 ^= sample_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_72_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
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

  assert(cursor_83_1 == cursor_83_2);
  assert(sample_72_1 == sample_72_2);
}

int fn_R001196_9613_2(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int cursor_83 = local_arr[aux % 3];
  acc = (acc + (cursor_83 * 2)) & 127;
  int sample_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_72 > 30)
  {
    acc = ((acc + (sample_72 * 2)) + 5) & 127;
    aux ^= sample_72 & 15;
  }
  else
  {
    acc = ((acc - sample_72) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001196_9613_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001196_9613_0 st_1 = {0};
  struct MatrixBlock_R001196_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int window_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_32_1 > 26)
  {
    acc_1 = ((acc_1 + (window_32_1 * 2)) + 5) & 127;
    aux_1 ^= window_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_32_2 > 26)
  {
    acc_2 = ((acc_2 + (window_32_2 * 2)) + 5) & 127;
    aux_2 ^= window_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_65_1 = local_arr_1[aux_1 % 3];
  int coefficient_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_65_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_32_1 == window_32_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_65_1 == coefficient_65_2);
}

int fn_R001196_9613_3(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001196_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int window_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_32 > 26)
  {
    acc = ((acc + (window_32 * 2)) + 5) & 127;
    aux ^= window_32 & 15;
  }
  else
  {
    acc = ((acc - window_32) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_65 = local_arr[aux % 3];
  acc = (acc + (coefficient_65 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001196_9613_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st_1 = {0};
  struct StreamBuffer_R001196_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_19_1) & 63;
  aux_2 = (aux_2 + coefficient_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_19_1 == coefficient_19_2);
}

int fn_R001196_9613_4(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_19) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001196_9613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st_1 = {0};
  struct StreamBuffer_R001196_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_30_1) & 63;
  aux_2 = (aux_2 + window_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_61_1 = local_arr_1[aux_1 % 3];
  int weight_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_30_1 == window_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_61_1 == weight_61_2);
}

int fn_R001196_9613_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_30) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_61 = local_arr[aux % 3];
  acc = (acc + (weight_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001196_9613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001196_9613_0 st_1 = {0};
  struct MatrixBlock_R001196_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int checksum_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_95_1) & 63;
  aux_2 = (aux_2 + checksum_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_60_1 = local_arr_1[aux_1 % 3];
  int bound_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_60_2 * 2)) & 127;
  int index_reg_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_53_1 > 42)
  {
    acc_1 = ((acc_1 + (index_reg_53_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_53_2 > 42)
  {
    acc_2 = ((acc_2 + (index_reg_53_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_95_1 == checksum_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_60_1 == bound_60_2);
  assert(index_reg_53_1 == index_reg_53_2);
}

int fn_R001196_9613_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001196_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int checksum_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_95) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_60 = local_arr[aux % 3];
  acc = (acc + (bound_60 * 2)) & 127;
  int index_reg_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_53 > 42)
  {
    acc = ((acc + (index_reg_53 * 2)) + 5) & 127;
    aux ^= index_reg_53 & 15;
  }
  else
  {
    acc = ((acc - index_reg_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001196_9613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st_1 = {0};
  struct StreamBuffer_R001196_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_18_1 = local_arr_1[aux_1 % 3];
  int factor_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_18_2 * 2)) & 127;
  int tally_92_1 = 0;
  int tally_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_92_1 = ((tally_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_92_2 = ((tally_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_92_1) & 127;
    acc_2 = (acc_2 + tally_92_2) & 127;
  }

  int cursor_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_73_1 > 37)
  {
    acc_1 = ((acc_1 + (cursor_73_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_73_2 > 37)
  {
    acc_2 = ((acc_2 + (cursor_73_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_28_1)
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

  switch (offset_28_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
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

  assert(factor_18_1 == factor_18_2);
  assert(tally_92_1 == tally_92_2);
  assert(cursor_73_1 == cursor_73_2);
  assert(offset_28_1 == offset_28_2);
}

int fn_R001196_9613_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int factor_18 = local_arr[aux % 3];
  acc = (acc + (factor_18 * 2)) & 127;
  int tally_92 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_92 = ((tally_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_92) & 127;
  }

  int cursor_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_73 > 37)
  {
    acc = ((acc + (cursor_73 * 2)) + 5) & 127;
    aux ^= cursor_73 & 15;
  }
  else
  {
    acc = ((acc - cursor_73) + 11) & 127;
    aux += 3;
  }
  int offset_28 = (aux + st.buffer[1]) & 3;
  switch (offset_28)
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

void fn_R001196_9613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001196_9613_0 st_1 = {0};
  struct MatrixBlock_R001196_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_69_1 = local_arr_1[aux_1 % 3];
  int quantum_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_69_2 * 2)) & 127;
  int factor_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_28_1 > 37)
  {
    acc_1 = ((acc_1 + (factor_28_1 * 2)) + 5) & 127;
    aux_1 ^= factor_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_28_2 > 37)
  {
    acc_2 = ((acc_2 + (factor_28_2 * 2)) + 5) & 127;
    aux_2 ^= factor_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_28_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_96_1)
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

  switch (weight_96_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_69_1 == quantum_69_2);
  assert(factor_28_1 == factor_28_2);
  assert(weight_96_1 == weight_96_2);
}

int fn_R001196_9613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001196_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int quantum_69 = local_arr[aux % 3];
  acc = (acc + (quantum_69 * 2)) & 127;
  int factor_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_28 > 37)
  {
    acc = ((acc + (factor_28 * 2)) + 5) & 127;
    aux ^= factor_28 & 15;
  }
  else
  {
    acc = ((acc - factor_28) + 11) & 127;
    aux += 3;
  }
  int weight_96 = (aux + st.buffer[1]) & 3;
  switch (weight_96)
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

void fn_R001196_9613_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st_1 = {0};
  struct StreamBuffer_R001196_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_13_1) & 63;
  aux_2 = (aux_2 + segment_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_13_1 == segment_13_2);
}

int fn_R001196_9613_9(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001196_9613_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st_1 = {0};
  struct StreamBuffer_R001196_9613_1 st_2 = {0};
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
  int cursor_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_41_1) & 63;
  aux_2 = (aux_2 + cursor_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_34_1)
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

  switch (tally_34_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_41_1 == cursor_41_2);
  assert(tally_34_1 == tally_34_2);
}

int fn_R001196_9613_10(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_41) & 63;
  acc ^= aux;
  int tally_34 = (aux + st.buffer[1]) & 3;
  switch (tally_34)
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

void fn_R001196_9613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st_1 = {0};
  struct StreamBuffer_R001196_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_50_1 = local_arr_1[aux_1 % 3];
  int coefficient_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_50_2 * 2)) & 127;
  int cursor_24_1 = 0;
  int cursor_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_24_1 = ((cursor_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_24_2 = ((cursor_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_24_1) & 127;
    acc_2 = (acc_2 + cursor_24_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
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

  assert(coefficient_50_1 == coefficient_50_2);
  assert(cursor_24_1 == cursor_24_2);
}

int fn_R001196_9613_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int coefficient_50 = local_arr[aux % 3];
  acc = (acc + (coefficient_50 * 2)) & 127;
  int cursor_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_24 = ((cursor_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_24) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001196_9613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st_1 = {0};
  struct StreamBuffer_R001196_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_66_1 = local_arr_1[aux_1 % 3];
  int quotient_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_66_2 * 2)) & 127;
  int threshold_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_29_1 > 38)
  {
    acc_1 = ((acc_1 + (threshold_29_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_29_2 > 38)
  {
    acc_2 = ((acc_2 + (threshold_29_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
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

  assert(quotient_66_1 == quotient_66_2);
  assert(threshold_29_1 == threshold_29_2);
}

int fn_R001196_9613_12(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001196_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int quotient_66 = local_arr[aux % 3];
  acc = (acc + (quotient_66 * 2)) & 127;
  int threshold_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_29 > 38)
  {
    acc = ((acc + (threshold_29 * 2)) + 5) & 127;
    aux ^= threshold_29 & 15;
  }
  else
  {
    acc = ((acc - threshold_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001196_9613_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001196_9613_0 st_1 = {0};
  struct MatrixBlock_R001196_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int phase_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_33_1)
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

  switch (phase_33_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_33_1 == phase_33_2);
}

int fn_R001196_9613_13(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001196_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int phase_33 = (aux + st.buffer[1]) & 3;
  switch (phase_33)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001196_9613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001196_9613_0 st_1 = {0};
  struct MatrixBlock_R001196_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int factor_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_17_1)
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

  switch (factor_17_2)
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
  int tracker_19_1 = local_arr_1[aux_1 % 3];
  int tracker_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_17_1 == factor_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_19_1 == tracker_19_2);
}

int fn_R001196_9613_14(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001196_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int factor_17 = (aux + st.buffer[1]) & 3;
  switch (factor_17)
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
  int tracker_19 = local_arr[aux % 3];
  acc = (acc + (tracker_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001196_0_1;
  int sec_r001196_0_2;
  int sec_r001196_1_1;
  int sec_r001196_1_2;
  int sec_r001196_2_1;
  int sec_r001196_2_2;
  int sec_r001196_3_1;
  int sec_r001196_3_2;
  int sec_r001196_4_1;
  int sec_r001196_4_2;
  int sec_r001196_5_1;
  int sec_r001196_5_2;
  int sec_r001196_6_1;
  int sec_r001196_6_2;
  int sec_r001196_7_1;
  int sec_r001196_7_2;
  int sec_r001196_8_1;
  int sec_r001196_8_2;
  int sec_r001196_9_1;
  int sec_r001196_9_2;
  int sec_r001196_10_1;
  int sec_r001196_10_2;
  int sec_r001196_11_1;
  int sec_r001196_11_2;
  int sec_r001196_12_1;
  int sec_r001196_12_2;
  int sec_r001196_13_1;
  int sec_r001196_13_2;
  int sec_r001196_14_1;
  int sec_r001196_14_2;
  int sec_r001196_15_1;
  int sec_r001196_15_2;
  int sec_r001196_16_1;
  int sec_r001196_16_2;
  int sec_r001196_17_1;
  int sec_r001196_17_2;
  int pub_r001196_0_1;
  int pub_r001196_0_2;
  int pub_r001196_1_1;
  int pub_r001196_1_2;
  int pub_r001196_2_1;
  int pub_r001196_2_2;
  int pub_r001196_3_1;
  int pub_r001196_3_2;
  int pub_r001196_4_1;
  int pub_r001196_4_2;
  int pub_r001196_5_1;
  int pub_r001196_5_2;
  int pub_r001196_6_1;
  int pub_r001196_6_2;
  int pub_r001196_7_1;
  int pub_r001196_7_2;
  int pub_r001196_8_1;
  int pub_r001196_8_2;
  int pub_r001196_9_1;
  int pub_r001196_9_2;
  int pub_r001196_10_1;
  int pub_r001196_10_2;
  int pub_r001196_11_1;
  int pub_r001196_11_2;
  int pub_r001196_12_1;
  int pub_r001196_12_2;
  int pub_r001196_13_1;
  int pub_r001196_13_2;
  int pub_r001196_14_1;
  int pub_r001196_14_2;
  int pub_r001196_15_1;
  int pub_r001196_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001196_0_1 >= (-100)) && (pub_r001196_0_1 <= 100));
  __CPROVER_assume((pub_r001196_0_2 >= (-100)) && (pub_r001196_0_2 <= 100));
  __CPROVER_assume((pub_r001196_1_1 >= (-100)) && (pub_r001196_1_1 <= 100));
  __CPROVER_assume((pub_r001196_1_2 >= (-100)) && (pub_r001196_1_2 <= 100));
  __CPROVER_assume((pub_r001196_2_1 >= (-100)) && (pub_r001196_2_1 <= 100));
  __CPROVER_assume((pub_r001196_2_2 >= (-100)) && (pub_r001196_2_2 <= 100));
  __CPROVER_assume((pub_r001196_3_1 >= (-100)) && (pub_r001196_3_1 <= 100));
  __CPROVER_assume((pub_r001196_3_2 >= (-100)) && (pub_r001196_3_2 <= 100));
  __CPROVER_assume((pub_r001196_4_1 >= (-100)) && (pub_r001196_4_1 <= 100));
  __CPROVER_assume((pub_r001196_4_2 >= (-100)) && (pub_r001196_4_2 <= 100));
  __CPROVER_assume((pub_r001196_5_1 >= (-100)) && (pub_r001196_5_1 <= 100));
  __CPROVER_assume((pub_r001196_5_2 >= (-100)) && (pub_r001196_5_2 <= 100));
  __CPROVER_assume((pub_r001196_6_1 >= (-100)) && (pub_r001196_6_1 <= 100));
  __CPROVER_assume((pub_r001196_6_2 >= (-100)) && (pub_r001196_6_2 <= 100));
  __CPROVER_assume((pub_r001196_7_1 >= (-100)) && (pub_r001196_7_1 <= 100));
  __CPROVER_assume((pub_r001196_7_2 >= (-100)) && (pub_r001196_7_2 <= 100));
  __CPROVER_assume((pub_r001196_8_1 >= (-100)) && (pub_r001196_8_1 <= 100));
  __CPROVER_assume((pub_r001196_8_2 >= (-100)) && (pub_r001196_8_2 <= 100));
  __CPROVER_assume((pub_r001196_9_1 >= (-100)) && (pub_r001196_9_1 <= 100));
  __CPROVER_assume((pub_r001196_9_2 >= (-100)) && (pub_r001196_9_2 <= 100));
  __CPROVER_assume((pub_r001196_10_1 >= (-100)) && (pub_r001196_10_1 <= 100));
  __CPROVER_assume((pub_r001196_10_2 >= (-100)) && (pub_r001196_10_2 <= 100));
  __CPROVER_assume((pub_r001196_11_1 >= (-100)) && (pub_r001196_11_1 <= 100));
  __CPROVER_assume((pub_r001196_11_2 >= (-100)) && (pub_r001196_11_2 <= 100));
  __CPROVER_assume((pub_r001196_12_1 >= (-100)) && (pub_r001196_12_1 <= 100));
  __CPROVER_assume((pub_r001196_12_2 >= (-100)) && (pub_r001196_12_2 <= 100));
  __CPROVER_assume((pub_r001196_13_1 >= (-100)) && (pub_r001196_13_1 <= 100));
  __CPROVER_assume((pub_r001196_13_2 >= (-100)) && (pub_r001196_13_2 <= 100));
  __CPROVER_assume((pub_r001196_14_1 >= (-100)) && (pub_r001196_14_1 <= 100));
  __CPROVER_assume((pub_r001196_14_2 >= (-100)) && (pub_r001196_14_2 <= 100));
  __CPROVER_assume((pub_r001196_15_1 >= (-100)) && (pub_r001196_15_1 <= 100));
  __CPROVER_assume((pub_r001196_15_2 >= (-100)) && (pub_r001196_15_2 <= 100));
  __CPROVER_assume((sec_r001196_0_1 >= 0) && (sec_r001196_0_1 <= 255));
  __CPROVER_assume((sec_r001196_0_2 >= 0) && (sec_r001196_0_2 <= 255));
  __CPROVER_assume((sec_r001196_1_1 >= 0) && (sec_r001196_1_1 <= 255));
  __CPROVER_assume((sec_r001196_1_2 >= 0) && (sec_r001196_1_2 <= 255));
  __CPROVER_assume((sec_r001196_2_1 >= 0) && (sec_r001196_2_1 <= 255));
  __CPROVER_assume((sec_r001196_2_2 >= 0) && (sec_r001196_2_2 <= 255));
  __CPROVER_assume((sec_r001196_3_1 >= 0) && (sec_r001196_3_1 <= 255));
  __CPROVER_assume((sec_r001196_3_2 >= 0) && (sec_r001196_3_2 <= 255));
  __CPROVER_assume((sec_r001196_4_1 >= 0) && (sec_r001196_4_1 <= 255));
  __CPROVER_assume((sec_r001196_4_2 >= 0) && (sec_r001196_4_2 <= 255));
  __CPROVER_assume((sec_r001196_5_1 >= 0) && (sec_r001196_5_1 <= 255));
  __CPROVER_assume((sec_r001196_5_2 >= 0) && (sec_r001196_5_2 <= 255));
  __CPROVER_assume((sec_r001196_6_1 >= 0) && (sec_r001196_6_1 <= 255));
  __CPROVER_assume((sec_r001196_6_2 >= 0) && (sec_r001196_6_2 <= 255));
  __CPROVER_assume((sec_r001196_7_1 >= 0) && (sec_r001196_7_1 <= 255));
  __CPROVER_assume((sec_r001196_7_2 >= 0) && (sec_r001196_7_2 <= 255));
  __CPROVER_assume((sec_r001196_8_1 >= 0) && (sec_r001196_8_1 <= 255));
  __CPROVER_assume((sec_r001196_8_2 >= 0) && (sec_r001196_8_2 <= 255));
  __CPROVER_assume((sec_r001196_9_1 >= 0) && (sec_r001196_9_1 <= 255));
  __CPROVER_assume((sec_r001196_9_2 >= 0) && (sec_r001196_9_2 <= 255));
  __CPROVER_assume((sec_r001196_10_1 >= 0) && (sec_r001196_10_1 <= 255));
  __CPROVER_assume((sec_r001196_10_2 >= 0) && (sec_r001196_10_2 <= 255));
  __CPROVER_assume((sec_r001196_11_1 >= 0) && (sec_r001196_11_1 <= 255));
  __CPROVER_assume((sec_r001196_11_2 >= 0) && (sec_r001196_11_2 <= 255));
  __CPROVER_assume((sec_r001196_12_1 >= 0) && (sec_r001196_12_1 <= 255));
  __CPROVER_assume((sec_r001196_12_2 >= 0) && (sec_r001196_12_2 <= 255));
  __CPROVER_assume((sec_r001196_13_1 >= 0) && (sec_r001196_13_1 <= 255));
  __CPROVER_assume((sec_r001196_13_2 >= 0) && (sec_r001196_13_2 <= 255));
  __CPROVER_assume((sec_r001196_14_1 >= 0) && (sec_r001196_14_1 <= 255));
  __CPROVER_assume((sec_r001196_14_2 >= 0) && (sec_r001196_14_2 <= 255));
  __CPROVER_assume((sec_r001196_15_1 >= 0) && (sec_r001196_15_1 <= 255));
  __CPROVER_assume((sec_r001196_15_2 >= 0) && (sec_r001196_15_2 <= 255));
  __CPROVER_assume((sec_r001196_16_1 >= 0) && (sec_r001196_16_1 <= 255));
  __CPROVER_assume((sec_r001196_16_2 >= 0) && (sec_r001196_16_2 <= 255));
  __CPROVER_assume((sec_r001196_17_1 >= 0) && (sec_r001196_17_1 <= 255));
  __CPROVER_assume((sec_r001196_17_2 >= 0) && (sec_r001196_17_2 <= 255));
  struct MatrixBlock_R001196_9613_0 st_var_0_1 = {0};
  struct MatrixBlock_R001196_9613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001196_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001196_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001196_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001196_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001196_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001196_0_2 + 7) & 15;
  struct StreamBuffer_R001196_9613_1 st_var_1_1 = {0};
  struct StreamBuffer_R001196_9613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001196_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001196_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001196_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001196_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001196_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001196_0_2 + 9) & 15;
  union RegisterBank_R001196_9613_0 u_var_1;
  union RegisterBank_R001196_9613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001196_9613_0(sec_r001196_0_1, sec_r001196_1_1, pub_r001196_2_1, pub_r001196_3_1, pub_r001196_4_1);
  int helper_flow_0_2 = fn_R001196_9613_0(sec_r001196_0_2, sec_r001196_1_2, pub_r001196_2_2, pub_r001196_3_2, pub_r001196_4_2);
  fn_R001196_9613_0_2(sec_r001196_0_1, sec_r001196_1_1, pub_r001196_2_1, pub_r001196_3_1, pub_r001196_4_1, sec_r001196_0_2, sec_r001196_1_2, pub_r001196_2_2, pub_r001196_3_2, pub_r001196_4_2);
  int helper_flow_1_1 = fn_R001196_9613_1(sec_r001196_1_1, sec_r001196_2_1, pub_r001196_3_1);
  int helper_flow_1_2 = fn_R001196_9613_1(sec_r001196_1_2, sec_r001196_2_2, pub_r001196_3_2);
  fn_R001196_9613_1_2(sec_r001196_1_1, sec_r001196_2_1, pub_r001196_3_1, sec_r001196_1_2, sec_r001196_2_2, pub_r001196_3_2);
  int helper_flow_2_1 = fn_R001196_9613_2(sec_r001196_2_1, sec_r001196_3_1);
  int helper_flow_2_2 = fn_R001196_9613_2(sec_r001196_2_2, sec_r001196_3_2);
  fn_R001196_9613_2_2(sec_r001196_2_1, sec_r001196_3_1, sec_r001196_2_2, sec_r001196_3_2);
  int helper_flow_3_1 = fn_R001196_9613_3(sec_r001196_3_1, sec_r001196_4_1, pub_r001196_5_1);
  int helper_flow_3_2 = fn_R001196_9613_3(sec_r001196_3_2, sec_r001196_4_2, pub_r001196_5_2);
  fn_R001196_9613_3_2(sec_r001196_3_1, sec_r001196_4_1, pub_r001196_5_1, sec_r001196_3_2, sec_r001196_4_2, pub_r001196_5_2);
  int helper_flow_4_1 = fn_R001196_9613_4(sec_r001196_4_1, pub_r001196_5_1, pub_r001196_6_1);
  int helper_flow_4_2 = fn_R001196_9613_4(sec_r001196_4_2, pub_r001196_5_2, pub_r001196_6_2);
  fn_R001196_9613_4_2(sec_r001196_4_1, pub_r001196_5_1, pub_r001196_6_1, sec_r001196_4_2, pub_r001196_5_2, pub_r001196_6_2);
  int helper_flow_5_1 = fn_R001196_9613_5(sec_r001196_5_1, pub_r001196_6_1, pub_r001196_7_1, pub_r001196_8_1);
  int helper_flow_5_2 = fn_R001196_9613_5(sec_r001196_5_2, pub_r001196_6_2, pub_r001196_7_2, pub_r001196_8_2);
  fn_R001196_9613_5_2(sec_r001196_5_1, pub_r001196_6_1, pub_r001196_7_1, pub_r001196_8_1, sec_r001196_5_2, pub_r001196_6_2, pub_r001196_7_2, pub_r001196_8_2);
  int helper_flow_6_1 = fn_R001196_9613_6(sec_r001196_6_1, pub_r001196_7_1, pub_r001196_8_1, pub_r001196_9_1);
  int helper_flow_6_2 = fn_R001196_9613_6(sec_r001196_6_2, pub_r001196_7_2, pub_r001196_8_2, pub_r001196_9_2);
  fn_R001196_9613_6_2(sec_r001196_6_1, pub_r001196_7_1, pub_r001196_8_1, pub_r001196_9_1, sec_r001196_6_2, pub_r001196_7_2, pub_r001196_8_2, pub_r001196_9_2);
  int stage_v_0_1 = ((sec_r001196_4_1 + (pub_r001196_8_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001196_4_2 + (pub_r001196_8_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((pub_r001196_11_1 * 2) + 42) & 63;
  int stage_v_1_2 = ((pub_r001196_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((helper_flow_0_1 + (pub_r001196_2_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((helper_flow_0_2 + (pub_r001196_2_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((sec_r001196_10_1 + (pub_r001196_14_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001196_10_2 + (pub_r001196_14_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001196_5_1 * 2) + 23) & 63;
  int stage_v_4_2 = ((pub_r001196_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((sec_r001196_9_1 + (pub_r001196_4_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001196_9_2 + (pub_r001196_4_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((helper_flow_0_1 + (pub_r001196_15_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((helper_flow_0_2 + (pub_r001196_15_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((sec_r001196_7_1 + (pub_r001196_11_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001196_7_2 + (pub_r001196_11_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((sec_r001196_12_1 + (pub_r001196_15_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((sec_r001196_12_2 + (pub_r001196_15_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((sec_r001196_10_1 + (pub_r001196_0_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((sec_r001196_10_2 + (pub_r001196_0_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((pub_r001196_14_1 * 2) + 7) & 63;
  int stage_v_10_2 = ((pub_r001196_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001196_1_1 * 2) + 14) & 63;
  int stage_v_11_2 = ((pub_r001196_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((sec_r001196_14_1 + (pub_r001196_1_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001196_14_2 + (pub_r001196_1_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((sec_r001196_15_1 + (pub_r001196_1_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001196_15_2 + (pub_r001196_1_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((stage_v_2_1 + (pub_r001196_10_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((stage_v_2_2 + (pub_r001196_10_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((sec_r001196_7_1 + (pub_r001196_4_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((sec_r001196_7_2 + (pub_r001196_4_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((pub_r001196_7_1 * 2) + 29) & 63;
  int stage_v_16_2 = ((pub_r001196_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001196_13_1 * 2) + 16) & 63;
  int stage_v_17_2 = ((pub_r001196_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((sec_r001196_10_1 + (pub_r001196_2_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((sec_r001196_10_2 + (pub_r001196_2_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((stage_v_15_1 + (pub_r001196_3_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((stage_v_15_2 + (pub_r001196_3_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((sec_r001196_17_1 + (pub_r001196_5_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((sec_r001196_17_2 + (pub_r001196_5_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((pub_r001196_1_1 * 2) + 31) & 63;
  int stage_v_21_2 = ((pub_r001196_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((helper_flow_3_1 + (pub_r001196_2_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((helper_flow_3_2 + (pub_r001196_2_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((helper_flow_1_1 + (pub_r001196_3_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((helper_flow_1_2 + (pub_r001196_3_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((stage_v_2_1 + (pub_r001196_0_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((stage_v_2_2 + (pub_r001196_0_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((sec_r001196_1_1 + (pub_r001196_5_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((sec_r001196_1_2 + (pub_r001196_5_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((pub_r001196_4_1 * 2) + 20) & 63;
  int stage_v_26_2 = ((pub_r001196_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((sec_r001196_14_1 + (pub_r001196_7_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((sec_r001196_14_2 + (pub_r001196_7_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((stage_v_0_1 + (pub_r001196_12_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_0_2 + (pub_r001196_12_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((helper_flow_1_1 + (pub_r001196_15_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((helper_flow_1_2 + (pub_r001196_15_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((pub_r001196_2_1 * 2) + 27) & 63;
  int stage_v_30_2 = ((pub_r001196_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((stage_v_3_1 + (pub_r001196_14_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((stage_v_3_2 + (pub_r001196_14_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((pub_r001196_3_1 * 2) + 44) & 63;
  int stage_v_32_2 = ((pub_r001196_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((sec_r001196_11_1 + (pub_r001196_4_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((sec_r001196_11_2 + (pub_r001196_4_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((stage_v_25_1 + (pub_r001196_6_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((stage_v_25_2 + (pub_r001196_6_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((stage_v_27_1 + (pub_r001196_12_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((stage_v_27_2 + (pub_r001196_12_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((sec_r001196_5_1 + (pub_r001196_9_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((sec_r001196_5_2 + (pub_r001196_9_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((sec_r001196_5_1 + (pub_r001196_2_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((sec_r001196_5_2 + (pub_r001196_2_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((pub_r001196_4_1 * 2) + 31) & 63;
  int stage_v_38_2 = ((pub_r001196_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((sec_r001196_9_1 + (pub_r001196_2_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((sec_r001196_9_2 + (pub_r001196_2_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((sec_r001196_12_1 + (pub_r001196_15_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((sec_r001196_12_2 + (pub_r001196_15_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((sec_r001196_2_1 + (pub_r001196_15_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((sec_r001196_2_2 + (pub_r001196_15_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((stage_v_36_1 + (pub_r001196_3_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((stage_v_36_2 + (pub_r001196_3_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((sec_r001196_12_1 + (pub_r001196_7_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((sec_r001196_12_2 + (pub_r001196_7_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((pub_r001196_15_1 * 2) + 21) & 63;
  int stage_v_44_2 = ((pub_r001196_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((sec_r001196_16_1 + (pub_r001196_13_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((sec_r001196_16_2 + (pub_r001196_13_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((stage_v_24_1 + (pub_r001196_13_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_24_2 + (pub_r001196_13_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((pub_r001196_7_1 * 2) + 18) & 63;
  int stage_v_47_2 = ((pub_r001196_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((stage_v_36_1 + (pub_r001196_5_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_36_2 + (pub_r001196_5_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((pub_r001196_3_1 * 2) + 28) & 63;
  int stage_v_49_2 = ((pub_r001196_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001196_13_1 * 2) + 40) & 63;
  int stage_v_50_2 = ((pub_r001196_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001196_1_1 * 2) + 36) & 63;
  int stage_v_51_2 = ((pub_r001196_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((sec_r001196_5_1 + (pub_r001196_13_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((sec_r001196_5_2 + (pub_r001196_13_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((sec_r001196_13_1 + (pub_r001196_15_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((sec_r001196_13_2 + (pub_r001196_15_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((stage_v_31_1 + (pub_r001196_11_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((stage_v_31_2 + (pub_r001196_11_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((sec_r001196_5_1 + (pub_r001196_7_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((sec_r001196_5_2 + (pub_r001196_7_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((stage_v_25_1 + (pub_r001196_5_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((stage_v_25_2 + (pub_r001196_5_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((sec_r001196_14_1 + (pub_r001196_10_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((sec_r001196_14_2 + (pub_r001196_10_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((pub_r001196_5_1 * 2) + 23) & 63;
  int stage_v_58_2 = ((pub_r001196_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001196_8_1 * 2) + 24) & 63;
  int stage_v_59_2 = ((pub_r001196_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((stage_v_18_1 + (pub_r001196_8_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_18_2 + (pub_r001196_8_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((sec_r001196_17_1 + (pub_r001196_0_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((sec_r001196_17_2 + (pub_r001196_0_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((stage_v_56_1 + (pub_r001196_1_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_56_2 + (pub_r001196_1_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((pub_r001196_11_1 * 2) + 47) & 63;
  int stage_v_63_2 = ((pub_r001196_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((stage_v_45_1 + (pub_r001196_14_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_45_2 + (pub_r001196_14_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((pub_r001196_13_1 * 2) + 29) & 63;
  int stage_v_65_2 = ((pub_r001196_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((stage_v_7_1 + (pub_r001196_10_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((stage_v_7_2 + (pub_r001196_10_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((stage_v_14_1 + (pub_r001196_10_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_14_2 + (pub_r001196_10_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((pub_r001196_8_1 * 2) + 28) & 63;
  int stage_v_68_2 = ((pub_r001196_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((sec_r001196_12_1 + (pub_r001196_2_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((sec_r001196_12_2 + (pub_r001196_2_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((pub_r001196_8_1 * 2) + 41) & 63;
  int stage_v_70_2 = ((pub_r001196_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001196_4_1 * 2) + 39) & 63;
  int stage_v_71_2 = ((pub_r001196_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((helper_flow_4_1 + (pub_r001196_3_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((helper_flow_4_2 + (pub_r001196_3_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_27_1 + (pub_r001196_1_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_27_2 + (pub_r001196_1_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((stage_v_48_1 + (pub_r001196_2_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_48_2 + (pub_r001196_2_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((pub_r001196_15_1 * 2) + 40) & 63;
  int stage_v_75_2 = ((pub_r001196_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((sec_r001196_2_1 + (pub_r001196_9_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((sec_r001196_2_2 + (pub_r001196_9_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((stage_v_6_1 + (pub_r001196_11_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_6_2 + (pub_r001196_11_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((pub_r001196_5_1 * 2) + 17) & 63;
  int stage_v_78_2 = ((pub_r001196_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001196_9_1 * 2) + 38) & 63;
  int stage_v_79_2 = ((pub_r001196_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((stage_v_6_1 + (pub_r001196_13_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_6_2 + (pub_r001196_13_2 * 2)) + 245) & 127;
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
  int stage_v_81_1 = ((pub_r001196_15_1 * 2) + 13) & 63;
  int stage_v_81_2 = ((pub_r001196_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_67_1 + (pub_r001196_6_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_67_2 + (pub_r001196_6_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((pub_r001196_5_1 * 2) + 26) & 63;
  int stage_v_83_2 = ((pub_r001196_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((stage_v_36_1 + (pub_r001196_10_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_36_2 + (pub_r001196_10_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((pub_r001196_8_1 * 2) + 13) & 63;
  int stage_v_85_2 = ((pub_r001196_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((helper_flow_5_1 + (pub_r001196_5_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((helper_flow_5_2 + (pub_r001196_5_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((helper_flow_1_1 + (pub_r001196_10_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((helper_flow_1_2 + (pub_r001196_10_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((pub_r001196_4_1 * 2) + 44) & 63;
  int stage_v_88_2 = ((pub_r001196_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((stage_v_67_1 + (pub_r001196_10_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_67_2 + (pub_r001196_10_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((stage_v_27_1 + (pub_r001196_8_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_27_2 + (pub_r001196_8_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((stage_v_13_1 + (pub_r001196_6_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_13_2 + (pub_r001196_6_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((stage_v_37_1 + (pub_r001196_6_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_37_2 + (pub_r001196_6_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((stage_v_66_1 + (pub_r001196_11_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_66_2 + (pub_r001196_11_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_43_1 + (pub_r001196_4_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_43_2 + (pub_r001196_4_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_19_1 + (pub_r001196_15_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_19_2 + (pub_r001196_15_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((stage_v_66_1 + (pub_r001196_12_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_66_2 + (pub_r001196_12_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((pub_r001196_9_1 * 2) + 33) & 63;
  int stage_v_97_2 = ((pub_r001196_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001196_5_1 * 2) + 9) & 63;
  int stage_v_98_2 = ((pub_r001196_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((stage_v_84_1 + (pub_r001196_11_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_84_2 + (pub_r001196_11_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_2_1 + (pub_r001196_13_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_2_2 + (pub_r001196_13_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((stage_v_20_1 + (pub_r001196_7_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_20_2 + (pub_r001196_7_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((sec_r001196_0_1 + (pub_r001196_4_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((sec_r001196_0_2 + (pub_r001196_4_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((sec_r001196_0_1 + (pub_r001196_4_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((sec_r001196_0_2 + (pub_r001196_4_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((helper_flow_1_1 + (pub_r001196_12_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((helper_flow_1_2 + (pub_r001196_12_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_91_1 + (pub_r001196_15_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_91_2 + (pub_r001196_15_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_18_1 + (pub_r001196_0_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_18_2 + (pub_r001196_0_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((pub_r001196_4_1 * 2) + 38) & 63;
  int stage_v_107_2 = ((pub_r001196_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((sec_r001196_2_1 + (pub_r001196_7_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((sec_r001196_2_2 + (pub_r001196_7_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_0_1 + (pub_r001196_1_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_0_2 + (pub_r001196_1_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((helper_flow_6_1 + (pub_r001196_12_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((helper_flow_6_2 + (pub_r001196_12_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((stage_v_109_1 + (pub_r001196_9_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_109_2 + (pub_r001196_9_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((pub_r001196_9_1 * 2) + 19) & 63;
  int stage_v_112_2 = ((pub_r001196_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((sec_r001196_8_1 + (pub_r001196_10_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((sec_r001196_8_2 + (pub_r001196_10_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((stage_v_90_1 + (pub_r001196_8_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_90_2 + (pub_r001196_8_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((stage_v_14_1 + (pub_r001196_10_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_14_2 + (pub_r001196_10_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_108_1 + (pub_r001196_11_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_108_2 + (pub_r001196_11_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((helper_flow_2_1 + (pub_r001196_1_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((helper_flow_2_2 + (pub_r001196_1_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((stage_v_106_1 + (pub_r001196_15_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_106_2 + (pub_r001196_15_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_45_1 + (pub_r001196_5_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_45_2 + (pub_r001196_5_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((stage_v_114_1 + (pub_r001196_6_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_114_2 + (pub_r001196_6_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((pub_r001196_7_1 * 2) + 22) & 63;
  int stage_v_121_2 = ((pub_r001196_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((stage_v_3_1 + (pub_r001196_14_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_3_2 + (pub_r001196_14_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_84_1 + (pub_r001196_9_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_84_2 + (pub_r001196_9_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((pub_r001196_5_1 * 2) + 7) & 63;
  int stage_v_124_2 = ((pub_r001196_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001196_13_1 * 2) + 42) & 63;
  int stage_v_125_2 = ((pub_r001196_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((stage_v_115_1 + (pub_r001196_15_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_115_2 + (pub_r001196_15_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((sec_r001196_13_1 + (pub_r001196_9_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((sec_r001196_13_2 + (pub_r001196_9_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((helper_flow_6_1 + (pub_r001196_12_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((helper_flow_6_2 + (pub_r001196_12_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((pub_r001196_9_1 * 2) + 32) & 63;
  int stage_v_129_2 = ((pub_r001196_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((stage_v_101_1 + (pub_r001196_11_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_101_2 + (pub_r001196_11_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((stage_v_22_1 + (pub_r001196_8_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_22_2 + (pub_r001196_8_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((sec_r001196_4_1 + (pub_r001196_6_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((sec_r001196_4_2 + (pub_r001196_6_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((sec_r001196_4_1 + (pub_r001196_4_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((sec_r001196_4_2 + (pub_r001196_4_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((stage_v_31_1 + (pub_r001196_11_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_31_2 + (pub_r001196_11_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((stage_v_133_1 + (pub_r001196_5_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_133_2 + (pub_r001196_5_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_22_1 + (pub_r001196_3_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_22_2 + (pub_r001196_3_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_128_1 + (pub_r001196_2_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_128_2 + (pub_r001196_2_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((pub_r001196_10_1 * 2) + 49) & 63;
  int stage_v_138_2 = ((pub_r001196_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((stage_v_111_1 + (pub_r001196_2_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((stage_v_111_2 + (pub_r001196_2_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_99_1 + (pub_r001196_11_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_99_2 + (pub_r001196_11_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((pub_r001196_2_1 * 2) + 36) & 63;
  int stage_v_141_2 = ((pub_r001196_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001196_8_1 * 2) + 29) & 63;
  int stage_v_142_2 = ((pub_r001196_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((helper_flow_4_1 + (pub_r001196_8_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((helper_flow_4_2 + (pub_r001196_8_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((stage_v_56_1 + (pub_r001196_5_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_56_2 + (pub_r001196_5_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((helper_flow_6_1 + (pub_r001196_10_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((helper_flow_6_2 + (pub_r001196_10_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_128_1 + (pub_r001196_7_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_128_2 + (pub_r001196_7_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_123_1 + (pub_r001196_11_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_123_2 + (pub_r001196_11_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_18_1 + (pub_r001196_9_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_18_2 + (pub_r001196_9_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((stage_v_135_1 + (pub_r001196_9_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((stage_v_135_2 + (pub_r001196_9_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((stage_v_96_1 + (pub_r001196_6_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_96_2 + (pub_r001196_6_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((stage_v_89_1 + (pub_r001196_2_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_89_2 + (pub_r001196_2_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_91_1 + (pub_r001196_4_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_91_2 + (pub_r001196_4_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((pub_r001196_14_1 * 2) + 44) & 63;
  int stage_v_153_2 = ((pub_r001196_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((sec_r001196_4_1 + (pub_r001196_13_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((sec_r001196_4_2 + (pub_r001196_13_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((sec_r001196_5_1 + (pub_r001196_11_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((sec_r001196_5_2 + (pub_r001196_11_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((pub_r001196_7_1 * 2) + 47) & 63;
  int stage_v_156_2 = ((pub_r001196_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((stage_v_14_1 + (pub_r001196_9_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_14_2 + (pub_r001196_9_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_119_1 + (pub_r001196_9_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_119_2 + (pub_r001196_9_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_157_1 + (pub_r001196_11_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_157_2 + (pub_r001196_11_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_60_1 + (pub_r001196_1_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_60_2 + (pub_r001196_1_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((stage_v_144_1 + (pub_r001196_3_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_144_2 + (pub_r001196_3_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((stage_v_106_1 + (pub_r001196_1_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_106_2 + (pub_r001196_1_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((stage_v_33_1 + (pub_r001196_4_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_33_2 + (pub_r001196_4_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((sec_r001196_12_1 + (pub_r001196_6_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((sec_r001196_12_2 + (pub_r001196_6_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((stage_v_76_1 + (pub_r001196_2_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_76_2 + (pub_r001196_2_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((pub_r001196_1_1 * 2) + 22) & 63;
  int stage_v_166_2 = ((pub_r001196_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((stage_v_131_1 + (pub_r001196_15_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_131_2 + (pub_r001196_15_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_56_1 + (pub_r001196_7_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_56_2 + (pub_r001196_7_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_103_1 + (pub_r001196_8_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_103_2 + (pub_r001196_8_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((stage_v_131_1 + (pub_r001196_4_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_131_2 + (pub_r001196_4_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((pub_r001196_9_1 * 2) + 44) & 63;
  int stage_v_171_2 = ((pub_r001196_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001196_15_1 * 2) + 37) & 63;
  int stage_v_172_2 = ((pub_r001196_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((stage_v_139_1 + (pub_r001196_5_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_139_2 + (pub_r001196_5_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((pub_r001196_10_1 * 2) + 29) & 63;
  int stage_v_174_2 = ((pub_r001196_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((stage_v_114_1 + (pub_r001196_1_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_114_2 + (pub_r001196_1_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((pub_r001196_15_1 * 2) + 12) & 63;
  int stage_v_176_2 = ((pub_r001196_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((stage_v_89_1 + (pub_r001196_5_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_89_2 + (pub_r001196_5_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((stage_v_33_1 + (pub_r001196_5_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_33_2 + (pub_r001196_5_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((stage_v_157_1 + (pub_r001196_14_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_157_2 + (pub_r001196_14_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((stage_v_131_1 + (pub_r001196_13_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_131_2 + (pub_r001196_13_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((stage_v_160_1 + (pub_r001196_3_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_160_2 + (pub_r001196_3_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((pub_r001196_12_1 * 2) + 45) & 63;
  int stage_v_182_2 = ((pub_r001196_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_122_1 + (pub_r001196_0_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_122_2 + (pub_r001196_0_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_89_1 + (pub_r001196_2_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_89_2 + (pub_r001196_2_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((pub_r001196_6_1 * 2) + 48) & 63;
  int stage_v_185_2 = ((pub_r001196_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001196_14_1 * 2) + 44) & 63;
  int stage_v_186_2 = ((pub_r001196_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_169_1 + (pub_r001196_14_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_169_2 + (pub_r001196_14_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((stage_v_117_1 + (pub_r001196_7_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((stage_v_117_2 + (pub_r001196_7_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((pub_r001196_3_1 * 2) + 40) & 63;
  int stage_v_189_2 = ((pub_r001196_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001196_9_1 * 2) + 42) & 63;
  int stage_v_190_2 = ((pub_r001196_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((helper_flow_1_1 + (pub_r001196_10_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((helper_flow_1_2 + (pub_r001196_10_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((stage_v_157_1 + (pub_r001196_4_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_157_2 + (pub_r001196_4_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((sec_r001196_10_1 + (pub_r001196_10_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((sec_r001196_10_2 + (pub_r001196_10_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_191_1 + (pub_r001196_12_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_191_2 + (pub_r001196_12_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_169_1 + (pub_r001196_6_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_169_2 + (pub_r001196_6_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((pub_r001196_9_1 * 2) + 26) & 63;
  int stage_v_196_2 = ((pub_r001196_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((stage_v_84_1 + (pub_r001196_0_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_84_2 + (pub_r001196_0_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((stage_v_35_1 + (pub_r001196_12_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_35_2 + (pub_r001196_12_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_80_1 + (pub_r001196_13_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_80_2 + (pub_r001196_13_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_87_1 + (pub_r001196_11_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_87_2 + (pub_r001196_11_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((sec_r001196_3_1 + (pub_r001196_12_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((sec_r001196_3_2 + (pub_r001196_12_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((pub_r001196_9_1 * 2) + 34) & 63;
  int stage_v_202_2 = ((pub_r001196_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((stage_v_181_1 + (pub_r001196_8_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((stage_v_181_2 + (pub_r001196_8_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((stage_v_165_1 + (pub_r001196_12_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_165_2 + (pub_r001196_12_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((stage_v_119_1 + (pub_r001196_7_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_119_2 + (pub_r001196_7_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((pub_r001196_11_1 * 2) + 8) & 63;
  int stage_v_206_2 = ((pub_r001196_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((stage_v_122_1 + (pub_r001196_9_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_122_2 + (pub_r001196_9_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_162_1 + (pub_r001196_0_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_162_2 + (pub_r001196_0_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((pub_r001196_2_1 * 2) + 16) & 63;
  int stage_v_209_2 = ((pub_r001196_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001196_13_1 * 2) + 13) & 63;
  int stage_v_210_2 = ((pub_r001196_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((stage_v_7_1 + (pub_r001196_4_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((stage_v_7_2 + (pub_r001196_4_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((pub_r001196_7_1 * 2) + 20) & 63;
  int stage_v_212_2 = ((pub_r001196_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((stage_v_73_1 + (pub_r001196_9_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_73_2 + (pub_r001196_9_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((stage_v_157_1 + (pub_r001196_15_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_157_2 + (pub_r001196_15_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((stage_v_103_1 + (pub_r001196_6_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((stage_v_103_2 + (pub_r001196_6_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((pub_r001196_9_1 * 2) + 17) & 63;
  int stage_v_216_2 = ((pub_r001196_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001196_5_1 * 2) + 42) & 63;
  int stage_v_217_2 = ((pub_r001196_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((stage_v_178_1 + (pub_r001196_15_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_178_2 + (pub_r001196_15_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_123_1 + (pub_r001196_8_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_123_2 + (pub_r001196_8_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((stage_v_108_1 + (pub_r001196_4_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((stage_v_108_2 + (pub_r001196_4_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_221_1 = ((stage_v_211_1 + (pub_r001196_8_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_211_2 + (pub_r001196_8_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((stage_v_99_1 + (pub_r001196_1_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_99_2 + (pub_r001196_1_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_140_1 + (pub_r001196_15_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_140_2 + (pub_r001196_15_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((stage_v_137_1 + (pub_r001196_2_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_137_2 + (pub_r001196_2_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((pub_r001196_9_1 * 2) + 47) & 63;
  int stage_v_225_2 = ((pub_r001196_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001196_8_1 * 2) + 48) & 63;
  int stage_v_226_2 = ((pub_r001196_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((stage_v_8_1 + (pub_r001196_6_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_8_2 + (pub_r001196_6_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((sec_r001196_10_1 + (pub_r001196_13_1 * 2)) + 689) & 127;
  int stage_v_228_2 = ((sec_r001196_10_2 + (pub_r001196_13_2 * 2)) + 689) & 127;
  if (stage_v_228_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_228_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_228_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_228_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_229_1 = ((pub_r001196_5_1 * 2) + 44) & 63;
  int stage_v_229_2 = ((pub_r001196_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((stage_v_20_1 + (pub_r001196_6_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_20_2 + (pub_r001196_6_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((stage_v_95_1 + (pub_r001196_14_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_95_2 + (pub_r001196_14_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((pub_r001196_0_1 * 2) + 25) & 63;
  int stage_v_232_2 = ((pub_r001196_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001196_15_1 * 2) + 23) & 63;
  int stage_v_233_2 = ((pub_r001196_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001196_1_1 * 2) + 6) & 63;
  int stage_v_234_2 = ((pub_r001196_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((stage_v_219_1 + (pub_r001196_4_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((stage_v_219_2 + (pub_r001196_4_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((pub_r001196_8_1 * 2) + 39) & 63;
  int stage_v_236_2 = ((pub_r001196_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001196_9_1 != sec_r001196_9_2);
  __CPROVER_assume(sec_r001196_17_1 != sec_r001196_17_2);
  __CPROVER_assume(pub_r001196_9_1 == pub_r001196_9_2);
  __CPROVER_assume(pub_r001196_2_1 == pub_r001196_2_2);
  __CPROVER_assume(pub_r001196_7_1 == pub_r001196_7_2);
  __CPROVER_assume(pub_r001196_8_1 == pub_r001196_8_2);
  __CPROVER_assume(pub_r001196_0_1 == pub_r001196_0_2);
  __CPROVER_assume(pub_r001196_1_1 == pub_r001196_1_2);
  __CPROVER_assume(sec_r001196_3_1 != sec_r001196_3_2);
  __CPROVER_assume(sec_r001196_10_1 != sec_r001196_10_2);
  __CPROVER_assume(pub_r001196_15_1 == pub_r001196_15_2);
  __CPROVER_assume(sec_r001196_5_1 != sec_r001196_5_2);
  __CPROVER_assume(pub_r001196_6_1 == pub_r001196_6_2);
  __CPROVER_assume(pub_r001196_13_1 == pub_r001196_13_2);
  __CPROVER_assume(sec_r001196_15_1 != sec_r001196_15_2);
  __CPROVER_assume(sec_r001196_8_1 != sec_r001196_8_2);
  __CPROVER_assume(sec_r001196_6_1 != sec_r001196_6_2);
  __CPROVER_assume(sec_r001196_16_1 != sec_r001196_16_2);
  __CPROVER_assume(sec_r001196_14_1 != sec_r001196_14_2);
  __CPROVER_assume(pub_r001196_4_1 == pub_r001196_4_2);
  __CPROVER_assume(sec_r001196_7_1 != sec_r001196_7_2);
  __CPROVER_assume(pub_r001196_11_1 == pub_r001196_11_2);
  __CPROVER_assume(pub_r001196_5_1 == pub_r001196_5_2);
  __CPROVER_assume(pub_r001196_3_1 == pub_r001196_3_2);
  __CPROVER_assume(sec_r001196_1_1 != sec_r001196_1_2);
  __CPROVER_assume(pub_r001196_10_1 == pub_r001196_10_2);
  __CPROVER_assume(sec_r001196_11_1 != sec_r001196_11_2);
  __CPROVER_assume(pub_r001196_12_1 == pub_r001196_12_2);
  __CPROVER_assume(sec_r001196_4_1 != sec_r001196_4_2);
  __CPROVER_assume(sec_r001196_0_1 != sec_r001196_0_2);
  __CPROVER_assume(pub_r001196_14_1 == pub_r001196_14_2);
  __CPROVER_assume(sec_r001196_12_1 != sec_r001196_12_2);
  __CPROVER_assume(sec_r001196_13_1 != sec_r001196_13_2);
  __CPROVER_assume(sec_r001196_2_1 != sec_r001196_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
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
}


