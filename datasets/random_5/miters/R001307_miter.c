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
struct StreamBuffer_R001307_713_0
{
  short checksum;
  short watermark;
  int head;
  unsigned char state;
  short capacity;
  int tail;
  int buffer[3];
};
struct AudioFrame_R001307_713_1
{
  unsigned char envelope;
  int rms;
  int gain;
  unsigned char peak;
  short sample_rate;
  short channels;
  int buffer[3];
};
struct CipherContext_R001307_713_2
{
  short flags;
  int counter;
  unsigned char nonce;
  unsigned char tag;
  unsigned char iv;
  int round_key;
  int buffer[3];
};
struct MatrixBlock_R001307_713_3
{
  short scale;
  int density;
  int stride;
  short trace;
  int dim;
  int buffer[3];
};
union ColorPixel_R001307_713_0
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
void fn_R001307_713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001307_713_3 st_1 = {0};
  struct MatrixBlock_R001307_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int sample_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_71_1)
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

  switch (sample_71_2)
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
  int metric_94_1 = local_arr_1[aux_1 % 3];
  int metric_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_94_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_71_1 == sample_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_94_1 == metric_94_2);
}

int fn_R001307_713_0(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001307_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int sample_71 = (aux + st.buffer[1]) & 3;
  switch (sample_71)
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
  int metric_94 = local_arr[aux % 3];
  acc = (acc + (metric_94 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001307_713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001307_713_2 st_1 = {0};
  struct CipherContext_R001307_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_57_1 = 0;
  int coefficient_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_57_1 = ((coefficient_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_57_2 = ((coefficient_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_57_1) & 127;
    acc_2 = (acc_2 + coefficient_57_2) & 127;
  }

  int factor_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_82_1 > 24)
  {
    acc_1 = ((acc_1 + (factor_82_1 * 2)) + 5) & 127;
    aux_1 ^= factor_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_82_2 > 24)
  {
    acc_2 = ((acc_2 + (factor_82_2 * 2)) + 5) & 127;
    aux_2 ^= factor_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_70_1)
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

  switch (quotient_70_2)
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
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_57_1 == coefficient_57_2);
  assert(factor_82_1 == factor_82_2);
  assert(quotient_70_1 == quotient_70_2);
}

int fn_R001307_713_1(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001307_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_57 = ((coefficient_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_57) & 127;
  }

  int factor_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_82 > 24)
  {
    acc = ((acc + (factor_82 * 2)) + 5) & 127;
    aux ^= factor_82 & 15;
  }
  else
  {
    acc = ((acc - factor_82) + 11) & 127;
    aux += 3;
  }
  int quotient_70 = (aux + st.buffer[1]) & 3;
  switch (quotient_70)
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

void fn_R001307_713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001307_713_1 st_1 = {0};
  struct AudioFrame_R001307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_21_1 = local_arr_1[aux_1 % 3];
  int accumulator_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_21_2 * 2)) & 127;
  int weight_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_26_1 > 22)
  {
    acc_1 = ((acc_1 + (weight_26_1 * 2)) + 5) & 127;
    aux_1 ^= weight_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_26_2 > 22)
  {
    acc_2 = ((acc_2 + (weight_26_2 * 2)) + 5) & 127;
    aux_2 ^= weight_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_26_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_21_1 == accumulator_21_2);
  assert(weight_26_1 == weight_26_2);
}

int fn_R001307_713_2(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int accumulator_21 = local_arr[aux % 3];
  acc = (acc + (accumulator_21 * 2)) & 127;
  int weight_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_26 > 22)
  {
    acc = ((acc + (weight_26 * 2)) + 5) & 127;
    aux ^= weight_26 & 15;
  }
  else
  {
    acc = ((acc - weight_26) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001307_713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001307_713_2 st_1 = {0};
  struct CipherContext_R001307_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int margin_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_28_1) & 63;
  aux_2 = (aux_2 + margin_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_42_1 = local_arr_1[aux_1 % 3];
  int offset_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_42_2 * 2)) & 127;
  int cursor_15_1 = 0;
  int cursor_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_15_1 = ((cursor_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_15_2 = ((cursor_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_15_1) & 127;
    acc_2 = (acc_2 + cursor_15_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_28_1 == margin_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_42_1 == offset_42_2);
  assert(cursor_15_1 == cursor_15_2);
}

int fn_R001307_713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001307_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int margin_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_28) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_42 = local_arr[aux % 3];
  acc = (acc + (offset_42 * 2)) & 127;
  int cursor_15 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_15 = ((cursor_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_15) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001307_713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001307_713_3 st_1 = {0};
  struct MatrixBlock_R001307_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int quantum_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_91_1)
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

  switch (quantum_91_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_91_1 == quantum_91_2);
}

int fn_R001307_713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001307_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int quantum_91 = (aux + st.buffer[1]) & 3;
  switch (quantum_91)
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

void fn_R001307_713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001307_713_2 st_1 = {0};
  struct CipherContext_R001307_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tally_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_12_1)
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

  switch (tally_12_2)
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
  int vector_33_1 = local_arr_1[aux_1 % 3];
  int vector_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_33_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_12_1 == tally_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_33_1 == vector_33_2);
}

int fn_R001307_713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001307_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tally_12 = (aux + st.buffer[1]) & 3;
  switch (tally_12)
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
  int vector_33 = local_arr[aux % 3];
  acc = (acc + (vector_33 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001307_713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001307_713_1 st_1 = {0};
  struct AudioFrame_R001307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int index_reg_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_29_1)
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

  switch (index_reg_29_2)
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
  int anchor_72_1 = local_arr_1[aux_1 % 3];
  int anchor_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_72_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_29_1 == index_reg_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_72_1 == anchor_72_2);
}

int fn_R001307_713_6(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int index_reg_29 = (aux + st.buffer[1]) & 3;
  switch (index_reg_29)
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
  int anchor_72 = local_arr[aux % 3];
  acc = (acc + (anchor_72 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001307_713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001307_713_1 st_1 = {0};
  struct AudioFrame_R001307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int metric_79_1 = 0;
  int metric_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_79_1 = ((metric_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_79_2 = ((metric_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_79_1) & 127;
    acc_2 = (acc_2 + metric_79_2) & 127;
  }

  int offset_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_56_1)
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

  switch (offset_56_2)
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

  int pivot_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_14_1 > 46)
  {
    acc_1 = ((acc_1 + (pivot_14_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_14_2 > 46)
  {
    acc_2 = ((acc_2 + (pivot_14_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_14_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_79_1 == metric_79_2);
  assert(offset_56_1 == offset_56_2);
  assert(pivot_14_1 == pivot_14_2);
}

int fn_R001307_713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int metric_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_79 = ((metric_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_79) & 127;
  }

  int offset_56 = (aux + st.buffer[1]) & 3;
  switch (offset_56)
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

  int pivot_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_14 > 46)
  {
    acc = ((acc + (pivot_14 * 2)) + 5) & 127;
    aux ^= pivot_14 & 15;
  }
  else
  {
    acc = ((acc - pivot_14) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001307_713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001307_713_3 st_1 = {0};
  struct MatrixBlock_R001307_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int phase_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_26_1 > 16)
  {
    acc_1 = ((acc_1 + (phase_26_1 * 2)) + 5) & 127;
    aux_1 ^= phase_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_26_2 > 16)
  {
    acc_2 = ((acc_2 + (phase_26_2 * 2)) + 5) & 127;
    aux_2 ^= phase_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_10_1)
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

  switch (margin_10_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_26_1 == phase_26_2);
  assert(margin_10_1 == margin_10_2);
}

int fn_R001307_713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001307_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int phase_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_26 > 16)
  {
    acc = ((acc + (phase_26 * 2)) + 5) & 127;
    aux ^= phase_26 & 15;
  }
  else
  {
    acc = ((acc - phase_26) + 11) & 127;
    aux += 3;
  }
  int margin_10 = (aux + st.buffer[1]) & 3;
  switch (margin_10)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001307_713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001307_713_1 st_1 = {0};
  struct AudioFrame_R001307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int residue_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_54_1 > 10)
  {
    acc_1 = ((acc_1 + (residue_54_1 * 2)) + 5) & 127;
    aux_1 ^= residue_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_54_2 > 10)
  {
    acc_2 = ((acc_2 + (residue_54_2 * 2)) + 5) & 127;
    aux_2 ^= residue_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_45_1 = local_arr_1[aux_1 % 3];
  int damping_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_45_2 * 2)) & 127;
  int residue_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_92_1) & 63;
  aux_2 = (aux_2 + residue_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_43_1)
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

  switch (metric_43_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_54_1 == residue_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_45_1 == damping_45_2);
  assert(residue_92_1 == residue_92_2);
  assert(metric_43_1 == metric_43_2);
}

int fn_R001307_713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int residue_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_54 > 10)
  {
    acc = ((acc + (residue_54 * 2)) + 5) & 127;
    aux ^= residue_54 & 15;
  }
  else
  {
    acc = ((acc - residue_54) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int damping_45 = local_arr[aux % 3];
  acc = (acc + (damping_45 * 2)) & 127;
  int residue_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_92) & 63;
  acc ^= aux;
  int metric_43 = (aux + st.buffer[1]) & 3;
  switch (metric_43)
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

void fn_R001307_713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001307_713_3 st_1 = {0};
  struct MatrixBlock_R001307_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int metric_73_1 = 0;
  int metric_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_73_1 = ((metric_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_73_2 = ((metric_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_73_1) & 127;
    acc_2 = (acc_2 + metric_73_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_73_1 == metric_73_2);
}

int fn_R001307_713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001307_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int metric_73 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_73 = ((metric_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_73) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001307_713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001307_713_0 st_1 = {0};
  struct StreamBuffer_R001307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int residue_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_17_1 > 17)
  {
    acc_1 = ((acc_1 + (residue_17_1 * 2)) + 5) & 127;
    aux_1 ^= residue_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_17_2 > 17)
  {
    acc_2 = ((acc_2 + (residue_17_2 * 2)) + 5) & 127;
    aux_2 ^= residue_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_51_1) & 63;
  aux_2 = (aux_2 + damping_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_33_1)
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

  switch (threshold_33_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_17_1 == residue_17_2);
  assert(damping_51_1 == damping_51_2);
  assert(threshold_33_1 == threshold_33_2);
}

int fn_R001307_713_11(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int residue_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_17 > 17)
  {
    acc = ((acc + (residue_17 * 2)) + 5) & 127;
    aux ^= residue_17 & 15;
  }
  else
  {
    acc = ((acc - residue_17) + 11) & 127;
    aux += 3;
  }
  int damping_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_51) & 63;
  acc ^= aux;
  int threshold_33 = (aux + st.buffer[1]) & 3;
  switch (threshold_33)
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

void fn_R001307_713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001307_713_2 st_1 = {0};
  struct CipherContext_R001307_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int threshold_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_26_1 > 23)
  {
    acc_1 = ((acc_1 + (threshold_26_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_26_2 > 23)
  {
    acc_2 = ((acc_2 + (threshold_26_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_87_1) & 63;
  aux_2 = (aux_2 + factor_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_62_1 = 0;
  int scale_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_62_1 = ((scale_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_62_2 = ((scale_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_62_1) & 127;
    acc_2 = (acc_2 + scale_62_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_26_1 == threshold_26_2);
  assert(factor_87_1 == factor_87_2);
  assert(scale_62_1 == scale_62_2);
}

int fn_R001307_713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001307_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int threshold_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_26 > 23)
  {
    acc = ((acc + (threshold_26 * 2)) + 5) & 127;
    aux ^= threshold_26 & 15;
  }
  else
  {
    acc = ((acc - threshold_26) + 11) & 127;
    aux += 3;
  }
  int factor_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_87) & 63;
  acc ^= aux;
  int scale_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_62 = ((scale_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_62) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001307_713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001307_713_0 st_1 = {0};
  struct StreamBuffer_R001307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int parity_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_83_1)
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

  switch (parity_83_2)
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

  int accumulator_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_43_1 > 26)
  {
    acc_1 = ((acc_1 + (accumulator_43_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_43_2 > 26)
  {
    acc_2 = ((acc_2 + (accumulator_43_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_45_1 = 0;
  int vector_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_45_1 = ((vector_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_45_2 = ((vector_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_45_1) & 127;
    acc_2 = (acc_2 + vector_45_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_67_1 = local_arr_1[aux_1 % 3];
  int parity_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_67_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_83_1 == parity_83_2);
  assert(accumulator_43_1 == accumulator_43_2);
  assert(vector_45_1 == vector_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_67_1 == parity_67_2);
}

int fn_R001307_713_13(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int parity_83 = (aux + st.buffer[1]) & 3;
  switch (parity_83)
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

  int accumulator_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_43 > 26)
  {
    acc = ((acc + (accumulator_43 * 2)) + 5) & 127;
    aux ^= accumulator_43 & 15;
  }
  else
  {
    acc = ((acc - accumulator_43) + 11) & 127;
    aux += 3;
  }
  int vector_45 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_45 = ((vector_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_45) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int parity_67 = local_arr[aux % 3];
  acc = (acc + (parity_67 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001307_713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001307_713_1 st_1 = {0};
  struct AudioFrame_R001307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int factor_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_80_1 > 33)
  {
    acc_1 = ((acc_1 + (factor_80_1 * 2)) + 5) & 127;
    aux_1 ^= factor_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_80_2 > 33)
  {
    acc_2 = ((acc_2 + (factor_80_2 * 2)) + 5) & 127;
    aux_2 ^= factor_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_93_1 = local_arr_1[aux_1 % 3];
  int index_reg_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_93_2 * 2)) & 127;
  int tally_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_77_1)
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

  switch (tally_77_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_80_1 == factor_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_93_1 == index_reg_93_2);
  assert(tally_77_1 == tally_77_2);
}

int fn_R001307_713_14(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int factor_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_80 > 33)
  {
    acc = ((acc + (factor_80 * 2)) + 5) & 127;
    aux ^= factor_80 & 15;
  }
  else
  {
    acc = ((acc - factor_80) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_93 = local_arr[aux % 3];
  acc = (acc + (index_reg_93 * 2)) & 127;
  int tally_77 = (aux + st.buffer[1]) & 3;
  switch (tally_77)
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

void fn_R001307_713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001307_713_1 st_1 = {0};
  struct AudioFrame_R001307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_36_1 = local_arr_1[aux_1 % 3];
  int quotient_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_36_2 * 2)) & 127;
  int delta_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_69_1 > 12)
  {
    acc_1 = ((acc_1 + (delta_69_1 * 2)) + 5) & 127;
    aux_1 ^= delta_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_69_2 > 12)
  {
    acc_2 = ((acc_2 + (delta_69_2 * 2)) + 5) & 127;
    aux_2 ^= delta_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_95_1 = 0;
  int weight_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_95_1 = ((weight_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_95_2 = ((weight_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_95_1) & 127;
    acc_2 = (acc_2 + weight_95_2) & 127;
  }

  int bound_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_34_1) & 63;
  aux_2 = (aux_2 + bound_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_36_1 == quotient_36_2);
  assert(delta_69_1 == delta_69_2);
  assert(weight_95_1 == weight_95_2);
  assert(bound_34_1 == bound_34_2);
}

int fn_R001307_713_15(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int quotient_36 = local_arr[aux % 3];
  acc = (acc + (quotient_36 * 2)) & 127;
  int delta_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_69 > 12)
  {
    acc = ((acc + (delta_69 * 2)) + 5) & 127;
    aux ^= delta_69 & 15;
  }
  else
  {
    acc = ((acc - delta_69) + 11) & 127;
    aux += 3;
  }
  int weight_95 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_95 = ((weight_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_95) & 127;
  }

  int bound_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001307_0_1;
  int sec_r001307_0_2;
  int sec_r001307_1_1;
  int sec_r001307_1_2;
  int sec_r001307_2_1;
  int sec_r001307_2_2;
  int sec_r001307_3_1;
  int sec_r001307_3_2;
  int sec_r001307_4_1;
  int sec_r001307_4_2;
  int sec_r001307_5_1;
  int sec_r001307_5_2;
  int sec_r001307_6_1;
  int sec_r001307_6_2;
  int sec_r001307_7_1;
  int sec_r001307_7_2;
  int sec_r001307_8_1;
  int sec_r001307_8_2;
  int sec_r001307_9_1;
  int sec_r001307_9_2;
  int sec_r001307_10_1;
  int sec_r001307_10_2;
  int sec_r001307_11_1;
  int sec_r001307_11_2;
  int sec_r001307_12_1;
  int sec_r001307_12_2;
  int sec_r001307_13_1;
  int sec_r001307_13_2;
  int sec_r001307_14_1;
  int sec_r001307_14_2;
  int sec_r001307_15_1;
  int sec_r001307_15_2;
  int sec_r001307_16_1;
  int sec_r001307_16_2;
  int pub_r001307_0_1;
  int pub_r001307_0_2;
  int pub_r001307_1_1;
  int pub_r001307_1_2;
  int pub_r001307_2_1;
  int pub_r001307_2_2;
  int pub_r001307_3_1;
  int pub_r001307_3_2;
  int pub_r001307_4_1;
  int pub_r001307_4_2;
  int pub_r001307_5_1;
  int pub_r001307_5_2;
  int pub_r001307_6_1;
  int pub_r001307_6_2;
  int pub_r001307_7_1;
  int pub_r001307_7_2;
  int pub_r001307_8_1;
  int pub_r001307_8_2;
  int pub_r001307_9_1;
  int pub_r001307_9_2;
  int pub_r001307_10_1;
  int pub_r001307_10_2;
  int pub_r001307_11_1;
  int pub_r001307_11_2;
  int pub_r001307_12_1;
  int pub_r001307_12_2;
  int pub_r001307_13_1;
  int pub_r001307_13_2;
  int pub_r001307_14_1;
  int pub_r001307_14_2;
  int pub_r001307_15_1;
  int pub_r001307_15_2;
  int pub_r001307_16_1;
  int pub_r001307_16_2;
  int pub_r001307_17_1;
  int pub_r001307_17_2;
  int pub_r001307_18_1;
  int pub_r001307_18_2;
  int pub_r001307_19_1;
  int pub_r001307_19_2;
  int pub_r001307_20_1;
  int pub_r001307_20_2;
  int pub_r001307_21_1;
  int pub_r001307_21_2;
  int pub_r001307_22_1;
  int pub_r001307_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001307_0_1 >= (-100)) && (pub_r001307_0_1 <= 100));
  __CPROVER_assume((pub_r001307_0_2 >= (-100)) && (pub_r001307_0_2 <= 100));
  __CPROVER_assume((pub_r001307_1_1 >= (-100)) && (pub_r001307_1_1 <= 100));
  __CPROVER_assume((pub_r001307_1_2 >= (-100)) && (pub_r001307_1_2 <= 100));
  __CPROVER_assume((pub_r001307_2_1 >= (-100)) && (pub_r001307_2_1 <= 100));
  __CPROVER_assume((pub_r001307_2_2 >= (-100)) && (pub_r001307_2_2 <= 100));
  __CPROVER_assume((pub_r001307_3_1 >= (-100)) && (pub_r001307_3_1 <= 100));
  __CPROVER_assume((pub_r001307_3_2 >= (-100)) && (pub_r001307_3_2 <= 100));
  __CPROVER_assume((pub_r001307_4_1 >= (-100)) && (pub_r001307_4_1 <= 100));
  __CPROVER_assume((pub_r001307_4_2 >= (-100)) && (pub_r001307_4_2 <= 100));
  __CPROVER_assume((pub_r001307_5_1 >= (-100)) && (pub_r001307_5_1 <= 100));
  __CPROVER_assume((pub_r001307_5_2 >= (-100)) && (pub_r001307_5_2 <= 100));
  __CPROVER_assume((pub_r001307_6_1 >= (-100)) && (pub_r001307_6_1 <= 100));
  __CPROVER_assume((pub_r001307_6_2 >= (-100)) && (pub_r001307_6_2 <= 100));
  __CPROVER_assume((pub_r001307_7_1 >= (-100)) && (pub_r001307_7_1 <= 100));
  __CPROVER_assume((pub_r001307_7_2 >= (-100)) && (pub_r001307_7_2 <= 100));
  __CPROVER_assume((pub_r001307_8_1 >= (-100)) && (pub_r001307_8_1 <= 100));
  __CPROVER_assume((pub_r001307_8_2 >= (-100)) && (pub_r001307_8_2 <= 100));
  __CPROVER_assume((pub_r001307_9_1 >= (-100)) && (pub_r001307_9_1 <= 100));
  __CPROVER_assume((pub_r001307_9_2 >= (-100)) && (pub_r001307_9_2 <= 100));
  __CPROVER_assume((pub_r001307_10_1 >= (-100)) && (pub_r001307_10_1 <= 100));
  __CPROVER_assume((pub_r001307_10_2 >= (-100)) && (pub_r001307_10_2 <= 100));
  __CPROVER_assume((pub_r001307_11_1 >= (-100)) && (pub_r001307_11_1 <= 100));
  __CPROVER_assume((pub_r001307_11_2 >= (-100)) && (pub_r001307_11_2 <= 100));
  __CPROVER_assume((pub_r001307_12_1 >= (-100)) && (pub_r001307_12_1 <= 100));
  __CPROVER_assume((pub_r001307_12_2 >= (-100)) && (pub_r001307_12_2 <= 100));
  __CPROVER_assume((pub_r001307_13_1 >= (-100)) && (pub_r001307_13_1 <= 100));
  __CPROVER_assume((pub_r001307_13_2 >= (-100)) && (pub_r001307_13_2 <= 100));
  __CPROVER_assume((pub_r001307_14_1 >= (-100)) && (pub_r001307_14_1 <= 100));
  __CPROVER_assume((pub_r001307_14_2 >= (-100)) && (pub_r001307_14_2 <= 100));
  __CPROVER_assume((pub_r001307_15_1 >= (-100)) && (pub_r001307_15_1 <= 100));
  __CPROVER_assume((pub_r001307_15_2 >= (-100)) && (pub_r001307_15_2 <= 100));
  __CPROVER_assume((pub_r001307_16_1 >= (-100)) && (pub_r001307_16_1 <= 100));
  __CPROVER_assume((pub_r001307_16_2 >= (-100)) && (pub_r001307_16_2 <= 100));
  __CPROVER_assume((pub_r001307_17_1 >= (-100)) && (pub_r001307_17_1 <= 100));
  __CPROVER_assume((pub_r001307_17_2 >= (-100)) && (pub_r001307_17_2 <= 100));
  __CPROVER_assume((pub_r001307_18_1 >= (-100)) && (pub_r001307_18_1 <= 100));
  __CPROVER_assume((pub_r001307_18_2 >= (-100)) && (pub_r001307_18_2 <= 100));
  __CPROVER_assume((pub_r001307_19_1 >= (-100)) && (pub_r001307_19_1 <= 100));
  __CPROVER_assume((pub_r001307_19_2 >= (-100)) && (pub_r001307_19_2 <= 100));
  __CPROVER_assume((pub_r001307_20_1 >= (-100)) && (pub_r001307_20_1 <= 100));
  __CPROVER_assume((pub_r001307_20_2 >= (-100)) && (pub_r001307_20_2 <= 100));
  __CPROVER_assume((pub_r001307_21_1 >= (-100)) && (pub_r001307_21_1 <= 100));
  __CPROVER_assume((pub_r001307_21_2 >= (-100)) && (pub_r001307_21_2 <= 100));
  __CPROVER_assume((pub_r001307_22_1 >= (-100)) && (pub_r001307_22_1 <= 100));
  __CPROVER_assume((pub_r001307_22_2 >= (-100)) && (pub_r001307_22_2 <= 100));
  __CPROVER_assume((sec_r001307_0_1 >= 0) && (sec_r001307_0_1 <= 255));
  __CPROVER_assume((sec_r001307_0_2 >= 0) && (sec_r001307_0_2 <= 255));
  __CPROVER_assume((sec_r001307_1_1 >= 0) && (sec_r001307_1_1 <= 255));
  __CPROVER_assume((sec_r001307_1_2 >= 0) && (sec_r001307_1_2 <= 255));
  __CPROVER_assume((sec_r001307_2_1 >= 0) && (sec_r001307_2_1 <= 255));
  __CPROVER_assume((sec_r001307_2_2 >= 0) && (sec_r001307_2_2 <= 255));
  __CPROVER_assume((sec_r001307_3_1 >= 0) && (sec_r001307_3_1 <= 255));
  __CPROVER_assume((sec_r001307_3_2 >= 0) && (sec_r001307_3_2 <= 255));
  __CPROVER_assume((sec_r001307_4_1 >= 0) && (sec_r001307_4_1 <= 255));
  __CPROVER_assume((sec_r001307_4_2 >= 0) && (sec_r001307_4_2 <= 255));
  __CPROVER_assume((sec_r001307_5_1 >= 0) && (sec_r001307_5_1 <= 255));
  __CPROVER_assume((sec_r001307_5_2 >= 0) && (sec_r001307_5_2 <= 255));
  __CPROVER_assume((sec_r001307_6_1 >= 0) && (sec_r001307_6_1 <= 255));
  __CPROVER_assume((sec_r001307_6_2 >= 0) && (sec_r001307_6_2 <= 255));
  __CPROVER_assume((sec_r001307_7_1 >= 0) && (sec_r001307_7_1 <= 255));
  __CPROVER_assume((sec_r001307_7_2 >= 0) && (sec_r001307_7_2 <= 255));
  __CPROVER_assume((sec_r001307_8_1 >= 0) && (sec_r001307_8_1 <= 255));
  __CPROVER_assume((sec_r001307_8_2 >= 0) && (sec_r001307_8_2 <= 255));
  __CPROVER_assume((sec_r001307_9_1 >= 0) && (sec_r001307_9_1 <= 255));
  __CPROVER_assume((sec_r001307_9_2 >= 0) && (sec_r001307_9_2 <= 255));
  __CPROVER_assume((sec_r001307_10_1 >= 0) && (sec_r001307_10_1 <= 255));
  __CPROVER_assume((sec_r001307_10_2 >= 0) && (sec_r001307_10_2 <= 255));
  __CPROVER_assume((sec_r001307_11_1 >= 0) && (sec_r001307_11_1 <= 255));
  __CPROVER_assume((sec_r001307_11_2 >= 0) && (sec_r001307_11_2 <= 255));
  __CPROVER_assume((sec_r001307_12_1 >= 0) && (sec_r001307_12_1 <= 255));
  __CPROVER_assume((sec_r001307_12_2 >= 0) && (sec_r001307_12_2 <= 255));
  __CPROVER_assume((sec_r001307_13_1 >= 0) && (sec_r001307_13_1 <= 255));
  __CPROVER_assume((sec_r001307_13_2 >= 0) && (sec_r001307_13_2 <= 255));
  __CPROVER_assume((sec_r001307_14_1 >= 0) && (sec_r001307_14_1 <= 255));
  __CPROVER_assume((sec_r001307_14_2 >= 0) && (sec_r001307_14_2 <= 255));
  __CPROVER_assume((sec_r001307_15_1 >= 0) && (sec_r001307_15_1 <= 255));
  __CPROVER_assume((sec_r001307_15_2 >= 0) && (sec_r001307_15_2 <= 255));
  __CPROVER_assume((sec_r001307_16_1 >= 0) && (sec_r001307_16_1 <= 255));
  __CPROVER_assume((sec_r001307_16_2 >= 0) && (sec_r001307_16_2 <= 255));
  struct StreamBuffer_R001307_713_0 st_var_0_1 = {0};
  struct StreamBuffer_R001307_713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001307_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001307_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001307_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001307_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001307_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001307_0_2 + 7) & 15;
  struct AudioFrame_R001307_713_1 st_var_1_1 = {0};
  struct AudioFrame_R001307_713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001307_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001307_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001307_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001307_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001307_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001307_0_2 + 9) & 15;
  struct CipherContext_R001307_713_2 st_var_2_1 = {0};
  struct CipherContext_R001307_713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001307_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001307_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001307_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001307_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001307_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001307_0_2 + 11) & 15;
  struct MatrixBlock_R001307_713_3 st_var_3_1 = {0};
  struct MatrixBlock_R001307_713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001307_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001307_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001307_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001307_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001307_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001307_0_2 + 13) & 15;
  union ColorPixel_R001307_713_0 u_var_1;
  union ColorPixel_R001307_713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001307_713_0(sec_r001307_0_1, pub_r001307_1_1);
  int helper_flow_0_2 = fn_R001307_713_0(sec_r001307_0_2, pub_r001307_1_2);
  fn_R001307_713_0_2(sec_r001307_0_1, pub_r001307_1_1, sec_r001307_0_2, pub_r001307_1_2);
  int helper_flow_1_1 = fn_R001307_713_1(sec_r001307_1_1, sec_r001307_2_1);
  int helper_flow_1_2 = fn_R001307_713_1(sec_r001307_1_2, sec_r001307_2_2);
  fn_R001307_713_1_2(sec_r001307_1_1, sec_r001307_2_1, sec_r001307_1_2, sec_r001307_2_2);
  int helper_flow_2_1 = fn_R001307_713_2(sec_r001307_2_1, sec_r001307_3_1);
  int helper_flow_2_2 = fn_R001307_713_2(sec_r001307_2_2, sec_r001307_3_2);
  fn_R001307_713_2_2(sec_r001307_2_1, sec_r001307_3_1, sec_r001307_2_2, sec_r001307_3_2);
  int helper_flow_3_1 = fn_R001307_713_3(sec_r001307_3_1, pub_r001307_4_1, pub_r001307_5_1, pub_r001307_6_1);
  int helper_flow_3_2 = fn_R001307_713_3(sec_r001307_3_2, pub_r001307_4_2, pub_r001307_5_2, pub_r001307_6_2);
  fn_R001307_713_3_2(sec_r001307_3_1, pub_r001307_4_1, pub_r001307_5_1, pub_r001307_6_1, sec_r001307_3_2, pub_r001307_4_2, pub_r001307_5_2, pub_r001307_6_2);
  int helper_flow_4_1 = fn_R001307_713_4(sec_r001307_4_1, sec_r001307_5_1, pub_r001307_6_1, pub_r001307_7_1);
  int helper_flow_4_2 = fn_R001307_713_4(sec_r001307_4_2, sec_r001307_5_2, pub_r001307_6_2, pub_r001307_7_2);
  fn_R001307_713_4_2(sec_r001307_4_1, sec_r001307_5_1, pub_r001307_6_1, pub_r001307_7_1, sec_r001307_4_2, sec_r001307_5_2, pub_r001307_6_2, pub_r001307_7_2);
  int helper_flow_5_1 = fn_R001307_713_5(sec_r001307_5_1, sec_r001307_6_1, pub_r001307_7_1, pub_r001307_8_1, pub_r001307_9_1);
  int helper_flow_5_2 = fn_R001307_713_5(sec_r001307_5_2, sec_r001307_6_2, pub_r001307_7_2, pub_r001307_8_2, pub_r001307_9_2);
  fn_R001307_713_5_2(sec_r001307_5_1, sec_r001307_6_1, pub_r001307_7_1, pub_r001307_8_1, pub_r001307_9_1, sec_r001307_5_2, sec_r001307_6_2, pub_r001307_7_2, pub_r001307_8_2, pub_r001307_9_2);
  int helper_flow_6_1 = fn_R001307_713_6(sec_r001307_6_1, sec_r001307_7_1);
  int helper_flow_6_2 = fn_R001307_713_6(sec_r001307_6_2, sec_r001307_7_2);
  fn_R001307_713_6_2(sec_r001307_6_1, sec_r001307_7_1, sec_r001307_6_2, sec_r001307_7_2);
  int helper_flow_7_1 = fn_R001307_713_7(sec_r001307_7_1, pub_r001307_8_1, pub_r001307_9_1, pub_r001307_10_1, pub_r001307_11_1);
  int helper_flow_7_2 = fn_R001307_713_7(sec_r001307_7_2, pub_r001307_8_2, pub_r001307_9_2, pub_r001307_10_2, pub_r001307_11_2);
  fn_R001307_713_7_2(sec_r001307_7_1, pub_r001307_8_1, pub_r001307_9_1, pub_r001307_10_1, pub_r001307_11_1, sec_r001307_7_2, pub_r001307_8_2, pub_r001307_9_2, pub_r001307_10_2, pub_r001307_11_2);
  int helper_flow_8_1 = fn_R001307_713_8(sec_r001307_8_1, pub_r001307_9_1, pub_r001307_10_1);
  int helper_flow_8_2 = fn_R001307_713_8(sec_r001307_8_2, pub_r001307_9_2, pub_r001307_10_2);
  fn_R001307_713_8_2(sec_r001307_8_1, pub_r001307_9_1, pub_r001307_10_1, sec_r001307_8_2, pub_r001307_9_2, pub_r001307_10_2);
  int helper_flow_9_1 = fn_R001307_713_9(sec_r001307_9_1, sec_r001307_10_1, pub_r001307_11_1, pub_r001307_12_1);
  int helper_flow_9_2 = fn_R001307_713_9(sec_r001307_9_2, sec_r001307_10_2, pub_r001307_11_2, pub_r001307_12_2);
  fn_R001307_713_9_2(sec_r001307_9_1, sec_r001307_10_1, pub_r001307_11_1, pub_r001307_12_1, sec_r001307_9_2, sec_r001307_10_2, pub_r001307_11_2, pub_r001307_12_2);
  int helper_flow_10_1 = fn_R001307_713_10(sec_r001307_10_1, sec_r001307_11_1, pub_r001307_12_1, pub_r001307_13_1);
  int helper_flow_10_2 = fn_R001307_713_10(sec_r001307_10_2, sec_r001307_11_2, pub_r001307_12_2, pub_r001307_13_2);
  fn_R001307_713_10_2(sec_r001307_10_1, sec_r001307_11_1, pub_r001307_12_1, pub_r001307_13_1, sec_r001307_10_2, sec_r001307_11_2, pub_r001307_12_2, pub_r001307_13_2);
  int stage_v_0_1 = ((pub_r001307_13_1 * 2) + 39) & 63;
  int stage_v_0_2 = ((pub_r001307_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (helper_flow_0_1 ^ pub_r001307_11_1) & 63;
  int stage_v_1_2 = (helper_flow_0_2 ^ pub_r001307_11_2) & 63;
  if ((stage_v_1_1 & 1) != 0)
  {
    if ((sec_r001307_1_1 & 2) != 0)
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
    if ((sec_r001307_1_2 & 2) != 0)
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
  int stage_v_2_1 = (sec_r001307_8_1 ^ pub_r001307_21_1) & 63;
  int stage_v_2_2 = (sec_r001307_8_2 ^ pub_r001307_21_2) & 63;
  if ((stage_v_2_1 & 1) != 0)
  {
    if ((sec_r001307_6_1 & 2) != 0)
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
    if ((sec_r001307_6_2 & 2) != 0)
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
  int stage_v_3_1 = (sec_r001307_1_1 ^ pub_r001307_0_1) & 63;
  int stage_v_3_2 = (sec_r001307_1_2 ^ pub_r001307_0_2) & 63;
  if ((stage_v_3_1 & 1) != 0)
  {
    if ((sec_r001307_10_1 & 2) != 0)
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
    if ((sec_r001307_10_2 & 2) != 0)
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
  int stage_v_4_1 = (sec_r001307_4_1 ^ pub_r001307_8_1) & 63;
  int stage_v_4_2 = (sec_r001307_4_2 ^ pub_r001307_8_2) & 63;
  if ((stage_v_4_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
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
    if ((stage_v_2_2 & 2) != 0)
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
  int stage_v_5_1 = (helper_flow_9_1 ^ pub_r001307_20_1) & 63;
  int stage_v_5_2 = (helper_flow_9_2 ^ pub_r001307_20_2) & 63;
  if ((stage_v_5_1 & 1) != 0)
  {
    if ((sec_r001307_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_5_1 * 2)) & 255;
  }
  if ((stage_v_5_2 & 1) != 0)
  {
    if ((sec_r001307_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_5_2 * 2)) & 255;
  }
  int stage_v_6_1 = (sec_r001307_3_1 ^ pub_r001307_9_1) & 63;
  int stage_v_6_2 = (sec_r001307_3_2 ^ pub_r001307_9_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((sec_r001307_16_1 & 2) != 0)
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
    if ((sec_r001307_16_2 & 2) != 0)
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
  int stage_v_7_1 = ((pub_r001307_4_1 * 2) + 38) & 63;
  int stage_v_7_2 = ((pub_r001307_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001307_16_1 * 2) + 26) & 63;
  int stage_v_8_2 = ((pub_r001307_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (sec_r001307_2_1 ^ pub_r001307_17_1) & 63;
  int stage_v_9_2 = (sec_r001307_2_2 ^ pub_r001307_17_2) & 63;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((sec_r001307_1_1 & 2) != 0)
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
    if ((sec_r001307_1_2 & 2) != 0)
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
  int stage_v_10_1 = (sec_r001307_1_1 ^ pub_r001307_20_1) & 63;
  int stage_v_10_2 = (sec_r001307_1_2 ^ pub_r001307_20_2) & 63;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_11_1 = (sec_r001307_12_1 ^ pub_r001307_2_1) & 63;
  int stage_v_11_2 = (sec_r001307_12_2 ^ pub_r001307_2_2) & 63;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((sec_r001307_1_1 & 2) != 0)
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
    if ((sec_r001307_1_2 & 2) != 0)
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
  int stage_v_12_1 = ((pub_r001307_6_1 * 2) + 21) & 63;
  int stage_v_12_2 = ((pub_r001307_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (sec_r001307_7_1 ^ pub_r001307_11_1) & 63;
  int stage_v_13_2 = (sec_r001307_7_2 ^ pub_r001307_11_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r001307_2_1 & 2) != 0)
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
    if ((sec_r001307_2_2 & 2) != 0)
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
  int stage_v_14_1 = (sec_r001307_10_1 ^ pub_r001307_16_1) & 63;
  int stage_v_14_2 = (sec_r001307_10_2 ^ pub_r001307_16_2) & 63;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r001307_1_1 & 2) != 0)
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
    if ((sec_r001307_1_2 & 2) != 0)
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
  int stage_v_15_1 = ((pub_r001307_16_1 * 2) + 38) & 63;
  int stage_v_15_2 = ((pub_r001307_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (sec_r001307_10_1 ^ pub_r001307_8_1) & 63;
  int stage_v_16_2 = (sec_r001307_10_2 ^ pub_r001307_8_2) & 63;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
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
    if ((stage_v_13_2 & 2) != 0)
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
  int stage_v_17_1 = ((pub_r001307_6_1 * 2) + 16) & 63;
  int stage_v_17_2 = ((pub_r001307_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001307_20_1 * 2) + 17) & 63;
  int stage_v_18_2 = ((pub_r001307_20_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001307_11_1 * 2) + 34) & 63;
  int stage_v_19_2 = ((pub_r001307_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001307_11_1 * 2) + 17) & 63;
  int stage_v_20_2 = ((pub_r001307_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001307_4_1 * 2) + 35) & 63;
  int stage_v_21_2 = ((pub_r001307_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001307_8_1 * 2) + 34) & 63;
  int stage_v_22_2 = ((pub_r001307_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (stage_v_16_1 ^ pub_r001307_6_1) & 63;
  int stage_v_23_2 = (stage_v_16_2 ^ pub_r001307_6_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r001307_4_1 & 2) != 0)
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
    if ((sec_r001307_4_2 & 2) != 0)
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
  int stage_v_24_1 = ((pub_r001307_14_1 * 2) + 20) & 63;
  int stage_v_24_2 = ((pub_r001307_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (sec_r001307_5_1 ^ pub_r001307_1_1) & 63;
  int stage_v_25_2 = (sec_r001307_5_2 ^ pub_r001307_1_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
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
    if ((stage_v_3_2 & 2) != 0)
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
  int stage_v_26_1 = (sec_r001307_1_1 ^ pub_r001307_4_1) & 63;
  int stage_v_26_2 = (sec_r001307_1_2 ^ pub_r001307_4_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_27_1 = (helper_flow_10_1 ^ pub_r001307_5_1) & 63;
  int stage_v_27_2 = (helper_flow_10_2 ^ pub_r001307_5_2) & 63;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
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
    if ((helper_flow_7_2 & 2) != 0)
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
  int stage_v_28_1 = (stage_v_25_1 ^ pub_r001307_21_1) & 63;
  int stage_v_28_2 = (stage_v_25_2 ^ pub_r001307_21_2) & 63;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r001307_8_1 & 2) != 0)
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
    if ((sec_r001307_8_2 & 2) != 0)
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
  int stage_v_29_1 = (stage_v_13_1 ^ pub_r001307_17_1) & 63;
  int stage_v_29_2 = (stage_v_13_2 ^ pub_r001307_17_2) & 63;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
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
    if ((stage_v_4_2 & 2) != 0)
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
  int stage_v_30_1 = (stage_v_26_1 ^ pub_r001307_22_1) & 63;
  int stage_v_30_2 = (stage_v_26_2 ^ pub_r001307_22_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_31_1 = (stage_v_16_1 ^ pub_r001307_2_1) & 63;
  int stage_v_31_2 = (stage_v_16_2 ^ pub_r001307_2_2) & 63;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((stage_v_29_1 & 2) != 0)
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
    if ((stage_v_29_2 & 2) != 0)
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
  int stage_v_32_1 = ((pub_r001307_20_1 * 2) + 30) & 63;
  int stage_v_32_2 = ((pub_r001307_20_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (helper_flow_7_1 ^ pub_r001307_6_1) & 63;
  int stage_v_33_2 = (helper_flow_7_2 ^ pub_r001307_6_2) & 63;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r001307_10_1 & 2) != 0)
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
    if ((sec_r001307_10_2 & 2) != 0)
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
  int stage_v_34_1 = (sec_r001307_0_1 ^ pub_r001307_20_1) & 63;
  int stage_v_34_2 = (sec_r001307_0_2 ^ pub_r001307_20_2) & 63;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_35_1 = (sec_r001307_15_1 ^ pub_r001307_19_1) & 63;
  int stage_v_35_2 = (sec_r001307_15_2 ^ pub_r001307_19_2) & 63;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
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
    if ((stage_v_3_2 & 2) != 0)
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
  int stage_v_36_1 = (stage_v_25_1 ^ pub_r001307_19_1) & 63;
  int stage_v_36_2 = (stage_v_25_2 ^ pub_r001307_19_2) & 63;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r001307_14_1 & 2) != 0)
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
    if ((sec_r001307_14_2 & 2) != 0)
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
  int stage_v_37_1 = ((pub_r001307_9_1 * 2) + 27) & 63;
  int stage_v_37_2 = ((pub_r001307_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001307_10_1 * 2) + 19) & 63;
  int stage_v_38_2 = ((pub_r001307_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001307_21_1 * 2) + 42) & 63;
  int stage_v_39_2 = ((pub_r001307_21_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001307_12_1 * 2) + 46) & 63;
  int stage_v_40_2 = ((pub_r001307_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (stage_v_5_1 ^ pub_r001307_19_1) & 63;
  int stage_v_41_2 = (stage_v_5_2 ^ pub_r001307_19_2) & 63;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
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
    if ((stage_v_2_2 & 2) != 0)
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
  int stage_v_42_1 = (stage_v_13_1 ^ pub_r001307_5_1) & 63;
  int stage_v_42_2 = (stage_v_13_2 ^ pub_r001307_5_2) & 63;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r001307_10_1 & 2) != 0)
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
    if ((sec_r001307_10_2 & 2) != 0)
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
  int stage_v_43_1 = ((pub_r001307_5_1 * 2) + 23) & 63;
  int stage_v_43_2 = ((pub_r001307_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (stage_v_6_1 ^ pub_r001307_13_1) & 63;
  int stage_v_44_2 = (stage_v_6_2 ^ pub_r001307_13_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((helper_flow_9_1 & 2) != 0)
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
    if ((helper_flow_9_2 & 2) != 0)
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
  int stage_v_45_1 = ((pub_r001307_3_1 * 2) + 18) & 63;
  int stage_v_45_2 = ((pub_r001307_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001307_2_1 * 2) + 42) & 63;
  int stage_v_46_2 = ((pub_r001307_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (sec_r001307_7_1 ^ pub_r001307_3_1) & 63;
  int stage_v_47_2 = (sec_r001307_7_2 ^ pub_r001307_3_2) & 63;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r001307_2_1 & 2) != 0)
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
    if ((sec_r001307_2_2 & 2) != 0)
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
  int stage_v_48_1 = (helper_flow_0_1 ^ pub_r001307_22_1) & 63;
  int stage_v_48_2 = (helper_flow_0_2 ^ pub_r001307_22_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
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
    if ((helper_flow_1_2 & 2) != 0)
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
  int stage_v_49_1 = ((pub_r001307_20_1 * 2) + 16) & 63;
  int stage_v_49_2 = ((pub_r001307_20_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001307_19_1 * 2) + 9) & 63;
  int stage_v_50_2 = ((pub_r001307_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001307_20_1 * 2) + 5) & 63;
  int stage_v_51_2 = ((pub_r001307_20_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (stage_v_16_1 ^ pub_r001307_7_1) & 63;
  int stage_v_52_2 = (stage_v_16_2 ^ pub_r001307_7_2) & 63;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((stage_v_29_1 & 2) != 0)
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
    if ((stage_v_29_2 & 2) != 0)
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
  int stage_v_53_1 = (stage_v_48_1 ^ pub_r001307_14_1) & 63;
  int stage_v_53_2 = (stage_v_48_2 ^ pub_r001307_14_2) & 63;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
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
    if ((stage_v_26_2 & 2) != 0)
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
  int stage_v_54_1 = (sec_r001307_4_1 ^ pub_r001307_21_1) & 63;
  int stage_v_54_2 = (sec_r001307_4_2 ^ pub_r001307_21_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((stage_v_33_1 & 2) != 0)
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
    if ((stage_v_33_2 & 2) != 0)
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
  int stage_v_55_1 = ((pub_r001307_1_1 * 2) + 22) & 63;
  int stage_v_55_2 = ((pub_r001307_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (stage_v_47_1 ^ pub_r001307_12_1) & 63;
  int stage_v_56_2 = (stage_v_47_2 ^ pub_r001307_12_2) & 63;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((stage_v_33_1 & 2) != 0)
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
    if ((stage_v_33_2 & 2) != 0)
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
  int stage_v_57_1 = (stage_v_23_1 ^ pub_r001307_10_1) & 63;
  int stage_v_57_2 = (stage_v_23_2 ^ pub_r001307_10_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r001307_4_1 & 2) != 0)
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
    if ((sec_r001307_4_2 & 2) != 0)
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
  int stage_v_58_1 = ((pub_r001307_16_1 * 2) + 30) & 63;
  int stage_v_58_2 = ((pub_r001307_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001307_7_1 * 2) + 16) & 63;
  int stage_v_59_2 = ((pub_r001307_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (helper_flow_8_1 ^ pub_r001307_16_1) & 63;
  int stage_v_60_2 = (helper_flow_8_2 ^ pub_r001307_16_2) & 63;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r001307_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r001307_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  }
  int stage_v_61_1 = ((pub_r001307_0_1 * 2) + 21) & 63;
  int stage_v_61_2 = ((pub_r001307_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001307_18_1 * 2) + 23) & 63;
  int stage_v_62_2 = ((pub_r001307_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001307_20_1 * 2) + 10) & 63;
  int stage_v_63_2 = ((pub_r001307_20_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (stage_v_33_1 ^ pub_r001307_18_1) & 63;
  int stage_v_64_2 = (stage_v_33_2 ^ pub_r001307_18_2) & 63;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
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
    if ((stage_v_28_2 & 2) != 0)
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
  int stage_v_65_1 = (stage_v_9_1 ^ pub_r001307_14_1) & 63;
  int stage_v_65_2 = (stage_v_9_2 ^ pub_r001307_14_2) & 63;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((stage_v_5_1 & 2) != 0)
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
    if ((stage_v_5_2 & 2) != 0)
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
  int stage_v_66_1 = (stage_v_42_1 ^ pub_r001307_8_1) & 63;
  int stage_v_66_2 = (stage_v_42_2 ^ pub_r001307_8_2) & 63;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r001307_9_1 & 2) != 0)
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
    if ((sec_r001307_9_2 & 2) != 0)
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
  int stage_v_67_1 = (stage_v_33_1 ^ pub_r001307_21_1) & 63;
  int stage_v_67_2 = (stage_v_33_2 ^ pub_r001307_21_2) & 63;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
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
    if ((stage_v_6_2 & 2) != 0)
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
  int stage_v_68_1 = (helper_flow_3_1 ^ pub_r001307_17_1) & 63;
  int stage_v_68_2 = (helper_flow_3_2 ^ pub_r001307_17_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
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
    if ((stage_v_60_2 & 2) != 0)
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
  int stage_v_69_1 = ((pub_r001307_17_1 * 2) + 8) & 63;
  int stage_v_69_2 = ((pub_r001307_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (stage_v_52_1 ^ pub_r001307_2_1) & 63;
  int stage_v_70_2 = (stage_v_52_2 ^ pub_r001307_2_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((stage_v_68_1 & 2) != 0)
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
    if ((stage_v_68_2 & 2) != 0)
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
  int stage_v_71_1 = (stage_v_26_1 ^ pub_r001307_16_1) & 63;
  int stage_v_71_2 = (stage_v_26_2 ^ pub_r001307_16_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
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
    if ((helper_flow_0_2 & 2) != 0)
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
  int stage_v_72_1 = ((pub_r001307_15_1 * 2) + 41) & 63;
  int stage_v_72_2 = ((pub_r001307_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (helper_flow_8_1 ^ pub_r001307_8_1) & 63;
  int stage_v_73_2 = (helper_flow_8_2 ^ pub_r001307_8_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_74_1 = (stage_v_23_1 ^ pub_r001307_5_1) & 63;
  int stage_v_74_2 = (stage_v_23_2 ^ pub_r001307_5_2) & 63;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((stage_v_53_1 & 2) != 0)
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
    if ((stage_v_53_2 & 2) != 0)
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
  int stage_v_75_1 = (stage_v_57_1 ^ pub_r001307_6_1) & 63;
  int stage_v_75_2 = (stage_v_57_2 ^ pub_r001307_6_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
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
    if ((stage_v_27_2 & 2) != 0)
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
  int stage_v_76_1 = (stage_v_52_1 ^ pub_r001307_15_1) & 63;
  int stage_v_76_2 = (stage_v_52_2 ^ pub_r001307_15_2) & 63;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((stage_v_11_1 & 2) != 0)
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
    if ((stage_v_11_2 & 2) != 0)
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
  int stage_v_77_1 = (helper_flow_9_1 ^ pub_r001307_7_1) & 63;
  int stage_v_77_2 = (helper_flow_9_2 ^ pub_r001307_7_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
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
    if ((stage_v_27_2 & 2) != 0)
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
  int stage_v_78_1 = (helper_flow_6_1 ^ pub_r001307_6_1) & 63;
  int stage_v_78_2 = (helper_flow_6_2 ^ pub_r001307_6_2) & 63;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((stage_v_5_1 & 2) != 0)
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
    if ((stage_v_5_2 & 2) != 0)
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
  int stage_v_79_1 = (stage_v_44_1 ^ pub_r001307_13_1) & 63;
  int stage_v_79_2 = (stage_v_44_2 ^ pub_r001307_13_2) & 63;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((stage_v_52_1 & 2) != 0)
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
    if ((stage_v_52_2 & 2) != 0)
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
  int stage_v_80_1 = (stage_v_3_1 ^ pub_r001307_19_1) & 63;
  int stage_v_80_2 = (stage_v_3_2 ^ pub_r001307_19_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_81_1 = (stage_v_52_1 ^ pub_r001307_6_1) & 63;
  int stage_v_81_2 = (stage_v_52_2 ^ pub_r001307_6_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r001307_10_1 & 2) != 0)
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
    if ((sec_r001307_10_2 & 2) != 0)
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
  int stage_v_82_1 = (stage_v_48_1 ^ pub_r001307_3_1) & 63;
  int stage_v_82_2 = (stage_v_48_2 ^ pub_r001307_3_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
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
    if ((stage_v_60_2 & 2) != 0)
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
  int stage_v_83_1 = (stage_v_30_1 ^ pub_r001307_21_1) & 63;
  int stage_v_83_2 = (stage_v_30_2 ^ pub_r001307_21_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r001307_9_1 & 2) != 0)
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
    if ((sec_r001307_9_2 & 2) != 0)
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
  int stage_v_84_1 = (stage_v_73_1 ^ pub_r001307_17_1) & 63;
  int stage_v_84_2 = (stage_v_73_2 ^ pub_r001307_17_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((stage_v_41_1 & 2) != 0)
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
    if ((stage_v_41_2 & 2) != 0)
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
  int stage_v_85_1 = (stage_v_44_1 ^ pub_r001307_5_1) & 63;
  int stage_v_85_2 = (stage_v_44_2 ^ pub_r001307_5_2) & 63;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((stage_v_67_1 & 2) != 0)
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
    if ((stage_v_67_2 & 2) != 0)
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
  int stage_v_86_1 = ((pub_r001307_3_1 * 2) + 36) & 63;
  int stage_v_86_2 = ((pub_r001307_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001307_9_1 * 2) + 22) & 63;
  int stage_v_87_2 = ((pub_r001307_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001307_9_1 * 2) + 7) & 63;
  int stage_v_88_2 = ((pub_r001307_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (stage_v_82_1 ^ pub_r001307_17_1) & 63;
  int stage_v_89_2 = (stage_v_82_2 ^ pub_r001307_17_2) & 63;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
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
    if ((helper_flow_1_2 & 2) != 0)
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
  int stage_v_90_1 = (stage_v_31_1 ^ pub_r001307_21_1) & 63;
  int stage_v_90_2 = (stage_v_31_2 ^ pub_r001307_21_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
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
    if ((stage_v_66_2 & 2) != 0)
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
  int stage_v_91_1 = (sec_r001307_8_1 ^ pub_r001307_19_1) & 63;
  int stage_v_91_2 = (sec_r001307_8_2 ^ pub_r001307_19_2) & 63;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((helper_flow_9_1 & 2) != 0)
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
    if ((helper_flow_9_2 & 2) != 0)
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
  int stage_v_92_1 = ((pub_r001307_18_1 * 2) + 22) & 63;
  int stage_v_92_2 = ((pub_r001307_18_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (helper_flow_5_1 ^ pub_r001307_5_1) & 63;
  int stage_v_93_2 = (helper_flow_5_2 ^ pub_r001307_5_2) & 63;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((stage_v_76_1 & 2) != 0)
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
    if ((stage_v_76_2 & 2) != 0)
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
  int stage_v_94_1 = (stage_v_47_1 ^ pub_r001307_16_1) & 63;
  int stage_v_94_2 = (stage_v_47_2 ^ pub_r001307_16_2) & 63;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((stage_v_74_1 & 2) != 0)
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
    if ((stage_v_74_2 & 2) != 0)
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
  int stage_v_95_1 = (stage_v_70_1 ^ pub_r001307_6_1) & 63;
  int stage_v_95_2 = (stage_v_70_2 ^ pub_r001307_6_2) & 63;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r001307_9_1 & 2) != 0)
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
    if ((sec_r001307_9_2 & 2) != 0)
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
  int stage_v_96_1 = ((pub_r001307_22_1 * 2) + 27) & 63;
  int stage_v_96_2 = ((pub_r001307_22_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (helper_flow_4_1 ^ pub_r001307_12_1) & 63;
  int stage_v_97_2 = (helper_flow_4_2 ^ pub_r001307_12_2) & 63;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((stage_v_77_1 & 2) != 0)
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
    if ((stage_v_77_2 & 2) != 0)
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
  int stage_v_98_1 = (stage_v_78_1 ^ pub_r001307_12_1) & 63;
  int stage_v_98_2 = (stage_v_78_2 ^ pub_r001307_12_2) & 63;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r001307_16_1 & 2) != 0)
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
    if ((sec_r001307_16_2 & 2) != 0)
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
  int stage_v_99_1 = (stage_v_79_1 ^ pub_r001307_12_1) & 63;
  int stage_v_99_2 = (stage_v_79_2 ^ pub_r001307_12_2) & 63;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((stage_v_67_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((stage_v_67_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  }
  int stage_v_100_1 = ((pub_r001307_8_1 * 2) + 49) & 63;
  int stage_v_100_2 = ((pub_r001307_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001307_5_1 * 2) + 16) & 63;
  int stage_v_101_2 = ((pub_r001307_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001307_13_1 * 2) + 21) & 63;
  int stage_v_102_2 = ((pub_r001307_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (sec_r001307_10_1 ^ pub_r001307_22_1) & 63;
  int stage_v_103_2 = (sec_r001307_10_2 ^ pub_r001307_22_2) & 63;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r001307_0_1 & 2) != 0)
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
    if ((sec_r001307_0_2 & 2) != 0)
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
  int stage_v_104_1 = ((pub_r001307_1_1 * 2) + 11) & 63;
  int stage_v_104_2 = ((pub_r001307_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001307_10_1 * 2) + 36) & 63;
  int stage_v_105_2 = ((pub_r001307_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (sec_r001307_3_1 ^ pub_r001307_1_1) & 63;
  int stage_v_106_2 = (sec_r001307_3_2 ^ pub_r001307_1_2) & 63;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((stage_v_57_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((stage_v_57_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  }
  int stage_v_107_1 = (stage_v_44_1 ^ pub_r001307_18_1) & 63;
  int stage_v_107_2 = (stage_v_44_2 ^ pub_r001307_18_2) & 63;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((stage_v_99_1 & 2) != 0)
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
    if ((stage_v_99_2 & 2) != 0)
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
  int stage_v_108_1 = (stage_v_103_1 ^ pub_r001307_4_1) & 63;
  int stage_v_108_2 = (stage_v_103_2 ^ pub_r001307_4_2) & 63;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((stage_v_91_1 & 2) != 0)
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
    if ((stage_v_91_2 & 2) != 0)
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
  int stage_v_109_1 = ((pub_r001307_6_1 * 2) + 13) & 63;
  int stage_v_109_2 = ((pub_r001307_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001307_19_1 * 2) + 6) & 63;
  int stage_v_110_2 = ((pub_r001307_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (sec_r001307_13_1 ^ pub_r001307_11_1) & 63;
  int stage_v_111_2 = (sec_r001307_13_2 ^ pub_r001307_11_2) & 63;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r001307_4_1 & 2) != 0)
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
    if ((sec_r001307_4_2 & 2) != 0)
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
  int stage_v_112_1 = (sec_r001307_8_1 ^ pub_r001307_16_1) & 63;
  int stage_v_112_2 = (sec_r001307_8_2 ^ pub_r001307_16_2) & 63;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((stage_v_85_1 & 2) != 0)
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
    if ((stage_v_85_2 & 2) != 0)
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
  int stage_v_113_1 = (stage_v_106_1 ^ pub_r001307_8_1) & 63;
  int stage_v_113_2 = (stage_v_106_2 ^ pub_r001307_8_2) & 63;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((stage_v_82_1 & 2) != 0)
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
    if ((stage_v_82_2 & 2) != 0)
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
  int stage_v_114_1 = (sec_r001307_8_1 ^ pub_r001307_18_1) & 63;
  int stage_v_114_2 = (sec_r001307_8_2 ^ pub_r001307_18_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((stage_v_83_1 & 2) != 0)
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
    if ((stage_v_83_2 & 2) != 0)
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
  int stage_v_115_1 = (stage_v_68_1 ^ pub_r001307_20_1) & 63;
  int stage_v_115_2 = (stage_v_68_2 ^ pub_r001307_20_2) & 63;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((stage_v_74_1 & 2) != 0)
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
    if ((stage_v_74_2 & 2) != 0)
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
  int stage_v_116_1 = ((pub_r001307_11_1 * 2) + 33) & 63;
  int stage_v_116_2 = ((pub_r001307_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001307_20_1 * 2) + 32) & 63;
  int stage_v_117_2 = ((pub_r001307_20_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (stage_v_113_1 ^ pub_r001307_13_1) & 63;
  int stage_v_118_2 = (stage_v_113_2 ^ pub_r001307_13_2) & 63;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((stage_v_93_1 & 2) != 0)
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
    if ((stage_v_93_2 & 2) != 0)
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
  int stage_v_119_1 = ((pub_r001307_9_1 * 2) + 17) & 63;
  int stage_v_119_2 = ((pub_r001307_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001307_3_1 * 2) + 43) & 63;
  int stage_v_120_2 = ((pub_r001307_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001307_9_1 * 2) + 49) & 63;
  int stage_v_121_2 = ((pub_r001307_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001307_0_1 * 2) + 20) & 63;
  int stage_v_122_2 = ((pub_r001307_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (stage_v_33_1 ^ pub_r001307_5_1) & 63;
  int stage_v_123_2 = (stage_v_33_2 ^ pub_r001307_5_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((stage_v_95_1 & 2) != 0)
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
    if ((stage_v_95_2 & 2) != 0)
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
  int stage_v_124_1 = (stage_v_2_1 ^ pub_r001307_18_1) & 63;
  int stage_v_124_2 = (stage_v_2_2 ^ pub_r001307_18_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
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
    if ((stage_v_3_2 & 2) != 0)
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
  int stage_v_125_1 = (stage_v_54_1 ^ pub_r001307_0_1) & 63;
  int stage_v_125_2 = (stage_v_54_2 ^ pub_r001307_0_2) & 63;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
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
    if ((stage_v_27_2 & 2) != 0)
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
  int stage_v_126_1 = (sec_r001307_12_1 ^ pub_r001307_5_1) & 63;
  int stage_v_126_2 = (sec_r001307_12_2 ^ pub_r001307_5_2) & 63;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((stage_v_41_1 & 2) != 0)
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
    if ((stage_v_41_2 & 2) != 0)
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
  int stage_v_127_1 = (stage_v_48_1 ^ pub_r001307_9_1) & 63;
  int stage_v_127_2 = (stage_v_48_2 ^ pub_r001307_9_2) & 63;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((stage_v_65_1 & 2) != 0)
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
    if ((stage_v_65_2 & 2) != 0)
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
  int stage_v_128_1 = (stage_v_70_1 ^ pub_r001307_7_1) & 63;
  int stage_v_128_2 = (stage_v_70_2 ^ pub_r001307_7_2) & 63;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((stage_v_79_1 & 2) != 0)
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
    if ((stage_v_79_2 & 2) != 0)
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
  int stage_v_129_1 = (stage_v_64_1 ^ pub_r001307_22_1) & 63;
  int stage_v_129_2 = (stage_v_64_2 ^ pub_r001307_22_2) & 63;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((stage_v_41_1 & 2) != 0)
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
    if ((stage_v_41_2 & 2) != 0)
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
  int stage_v_130_1 = (stage_v_80_1 ^ pub_r001307_22_1) & 63;
  int stage_v_130_2 = (stage_v_80_2 ^ pub_r001307_22_2) & 63;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((stage_v_127_1 & 2) != 0)
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
    if ((stage_v_127_2 & 2) != 0)
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
  int stage_v_131_1 = (stage_v_108_1 ^ pub_r001307_5_1) & 63;
  int stage_v_131_2 = (stage_v_108_2 ^ pub_r001307_5_2) & 63;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
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
    if ((helper_flow_0_2 & 2) != 0)
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
  int stage_v_132_1 = (stage_v_131_1 ^ pub_r001307_22_1) & 63;
  int stage_v_132_2 = (stage_v_131_2 ^ pub_r001307_22_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
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
    if ((stage_v_26_2 & 2) != 0)
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
  int stage_v_133_1 = (sec_r001307_8_1 ^ pub_r001307_1_1) & 63;
  int stage_v_133_2 = (sec_r001307_8_2 ^ pub_r001307_1_2) & 63;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((sec_r001307_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((sec_r001307_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  }
  int stage_v_134_1 = (stage_v_47_1 ^ pub_r001307_18_1) & 63;
  int stage_v_134_2 = (stage_v_47_2 ^ pub_r001307_18_2) & 63;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((stage_v_89_1 & 2) != 0)
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
    if ((stage_v_89_2 & 2) != 0)
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
  int stage_v_135_1 = (stage_v_129_1 ^ pub_r001307_7_1) & 63;
  int stage_v_135_2 = (stage_v_129_2 ^ pub_r001307_7_2) & 63;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((stage_v_84_1 & 2) != 0)
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
    if ((stage_v_84_2 & 2) != 0)
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
  int stage_v_136_1 = (stage_v_74_1 ^ pub_r001307_9_1) & 63;
  int stage_v_136_2 = (stage_v_74_2 ^ pub_r001307_9_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((stage_v_93_1 & 2) != 0)
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
    if ((stage_v_93_2 & 2) != 0)
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
  int stage_v_137_1 = (stage_v_95_1 ^ pub_r001307_17_1) & 63;
  int stage_v_137_2 = (stage_v_95_2 ^ pub_r001307_17_2) & 63;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((stage_v_135_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  }
  if ((stage_v_137_2 & 1) != 0)
  {
    if ((stage_v_135_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  }
  int stage_v_138_1 = (stage_v_67_1 ^ pub_r001307_5_1) & 63;
  int stage_v_138_2 = (stage_v_67_2 ^ pub_r001307_5_2) & 63;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((stage_v_103_1 & 2) != 0)
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
    if ((stage_v_103_2 & 2) != 0)
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
  int stage_v_139_1 = (helper_flow_8_1 ^ pub_r001307_16_1) & 63;
  int stage_v_139_2 = (helper_flow_8_2 ^ pub_r001307_16_2) & 63;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
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
    if ((stage_v_44_2 & 2) != 0)
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
  int stage_v_140_1 = (stage_v_115_1 ^ pub_r001307_12_1) & 63;
  int stage_v_140_2 = (stage_v_115_2 ^ pub_r001307_12_2) & 63;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((sec_r001307_12_1 & 2) != 0)
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
    if ((sec_r001307_12_2 & 2) != 0)
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
  int stage_v_141_1 = (helper_flow_6_1 ^ pub_r001307_3_1) & 63;
  int stage_v_141_2 = (helper_flow_6_2 ^ pub_r001307_3_2) & 63;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((stage_v_125_1 & 2) != 0)
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
    if ((stage_v_125_2 & 2) != 0)
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
  int stage_v_142_1 = (stage_v_90_1 ^ pub_r001307_0_1) & 63;
  int stage_v_142_2 = (stage_v_90_2 ^ pub_r001307_0_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((stage_v_89_1 & 2) != 0)
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
    if ((stage_v_89_2 & 2) != 0)
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
  int stage_v_143_1 = (helper_flow_2_1 ^ pub_r001307_6_1) & 63;
  int stage_v_143_2 = (helper_flow_2_2 ^ pub_r001307_6_2) & 63;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((sec_r001307_11_1 & 2) != 0)
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
    if ((sec_r001307_11_2 & 2) != 0)
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
  int stage_v_144_1 = ((pub_r001307_10_1 * 2) + 24) & 63;
  int stage_v_144_2 = ((pub_r001307_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001307_13_1 * 2) + 7) & 63;
  int stage_v_145_2 = ((pub_r001307_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001307_2_1 * 2) + 30) & 63;
  int stage_v_146_2 = ((pub_r001307_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (stage_v_126_1 ^ pub_r001307_9_1) & 63;
  int stage_v_147_2 = (stage_v_126_2 ^ pub_r001307_9_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
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
    if ((stage_v_14_2 & 2) != 0)
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
  int stage_v_148_1 = (stage_v_147_1 ^ pub_r001307_0_1) & 63;
  int stage_v_148_2 = (stage_v_147_2 ^ pub_r001307_0_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((sec_r001307_9_1 & 2) != 0)
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
    if ((sec_r001307_9_2 & 2) != 0)
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
  int stage_v_149_1 = ((pub_r001307_7_1 * 2) + 16) & 63;
  int stage_v_149_2 = ((pub_r001307_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001307_22_1 * 2) + 38) & 63;
  int stage_v_150_2 = ((pub_r001307_22_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (stage_v_80_1 ^ pub_r001307_5_1) & 63;
  int stage_v_151_2 = (stage_v_80_2 ^ pub_r001307_5_2) & 63;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((stage_v_98_1 & 2) != 0)
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
    if ((stage_v_98_2 & 2) != 0)
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
  int stage_v_152_1 = (helper_flow_5_1 ^ pub_r001307_7_1) & 63;
  int stage_v_152_2 = (helper_flow_5_2 ^ pub_r001307_7_2) & 63;
  if ((stage_v_152_1 & 1) != 0)
  {
    if ((sec_r001307_3_1 & 2) != 0)
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
    if ((sec_r001307_3_2 & 2) != 0)
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
  int stage_v_153_1 = (helper_flow_3_1 ^ pub_r001307_0_1) & 63;
  int stage_v_153_2 = (helper_flow_3_2 ^ pub_r001307_0_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((sec_r001307_13_1 & 2) != 0)
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
    if ((sec_r001307_13_2 & 2) != 0)
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
  int stage_v_154_1 = (stage_v_97_1 ^ pub_r001307_9_1) & 63;
  int stage_v_154_2 = (stage_v_97_2 ^ pub_r001307_9_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((stage_v_11_1 & 2) != 0)
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
    if ((stage_v_11_2 & 2) != 0)
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
  int stage_v_155_1 = (stage_v_153_1 ^ pub_r001307_8_1) & 63;
  int stage_v_155_2 = (stage_v_153_2 ^ pub_r001307_8_2) & 63;
  if ((stage_v_155_1 & 1) != 0)
  {
    if ((sec_r001307_2_1 & 2) != 0)
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
    if ((sec_r001307_2_2 & 2) != 0)
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
  int stage_v_156_1 = (stage_v_54_1 ^ pub_r001307_1_1) & 63;
  int stage_v_156_2 = (stage_v_54_2 ^ pub_r001307_1_2) & 63;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((stage_v_137_1 & 2) != 0)
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
    if ((stage_v_137_2 & 2) != 0)
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
  int stage_v_157_1 = (stage_v_98_1 ^ pub_r001307_6_1) & 63;
  int stage_v_157_2 = (stage_v_98_2 ^ pub_r001307_6_2) & 63;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((stage_v_54_1 & 2) != 0)
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
    if ((stage_v_54_2 & 2) != 0)
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
  int stage_v_158_1 = ((pub_r001307_8_1 * 2) + 20) & 63;
  int stage_v_158_2 = ((pub_r001307_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001307_6_1 * 2) + 44) & 63;
  int stage_v_159_2 = ((pub_r001307_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001307_15_1 * 2) + 26) & 63;
  int stage_v_160_2 = ((pub_r001307_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (stage_v_130_1 ^ pub_r001307_2_1) & 63;
  int stage_v_161_2 = (stage_v_130_2 ^ pub_r001307_2_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((sec_r001307_14_1 & 2) != 0)
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
    if ((sec_r001307_14_2 & 2) != 0)
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
  int stage_v_162_1 = ((pub_r001307_15_1 * 2) + 41) & 63;
  int stage_v_162_2 = ((pub_r001307_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (stage_v_98_1 ^ pub_r001307_14_1) & 63;
  int stage_v_163_2 = (stage_v_98_2 ^ pub_r001307_14_2) & 63;
  if ((stage_v_163_1 & 1) != 0)
  {
    if ((stage_v_77_1 & 2) != 0)
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
    if ((stage_v_77_2 & 2) != 0)
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
  int stage_v_164_1 = ((pub_r001307_14_1 * 2) + 39) & 63;
  int stage_v_164_2 = ((pub_r001307_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (sec_r001307_5_1 ^ pub_r001307_13_1) & 63;
  int stage_v_165_2 = (sec_r001307_5_2 ^ pub_r001307_13_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_127_1 & 2) != 0)
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
    if ((stage_v_127_2 & 2) != 0)
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
  int stage_v_166_1 = ((pub_r001307_22_1 * 2) + 16) & 63;
  int stage_v_166_2 = ((pub_r001307_22_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (sec_r001307_4_1 ^ pub_r001307_16_1) & 63;
  int stage_v_167_2 = (sec_r001307_4_2 ^ pub_r001307_16_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((stage_v_75_1 & 2) != 0)
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
    if ((stage_v_75_2 & 2) != 0)
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
  int stage_v_168_1 = (sec_r001307_13_1 ^ pub_r001307_6_1) & 63;
  int stage_v_168_2 = (sec_r001307_13_2 ^ pub_r001307_6_2) & 63;
  if ((stage_v_168_1 & 1) != 0)
  {
    if ((stage_v_107_1 & 2) != 0)
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
    if ((stage_v_107_2 & 2) != 0)
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
  int stage_v_169_1 = (stage_v_4_1 ^ pub_r001307_9_1) & 63;
  int stage_v_169_2 = (stage_v_4_2 ^ pub_r001307_9_2) & 63;
  if ((stage_v_169_1 & 1) != 0)
  {
    if ((stage_v_52_1 & 2) != 0)
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
    if ((stage_v_52_2 & 2) != 0)
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
  int stage_v_170_1 = (helper_flow_0_1 ^ pub_r001307_22_1) & 63;
  int stage_v_170_2 = (helper_flow_0_2 ^ pub_r001307_22_2) & 63;
  if ((stage_v_170_1 & 1) != 0)
  {
    if ((sec_r001307_9_1 & 2) != 0)
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
    if ((sec_r001307_9_2 & 2) != 0)
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
  int stage_v_171_1 = ((pub_r001307_21_1 * 2) + 44) & 63;
  int stage_v_171_2 = ((pub_r001307_21_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001307_5_1 * 2) + 39) & 63;
  int stage_v_172_2 = ((pub_r001307_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001307_20_1 * 2) + 39) & 63;
  int stage_v_173_2 = ((pub_r001307_20_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (stage_v_153_1 ^ pub_r001307_20_1) & 63;
  int stage_v_174_2 = (stage_v_153_2 ^ pub_r001307_20_2) & 63;
  if ((stage_v_174_1 & 1) != 0)
  {
    if ((sec_r001307_14_1 & 2) != 0)
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
    if ((sec_r001307_14_2 & 2) != 0)
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
  int stage_v_175_1 = (stage_v_53_1 ^ pub_r001307_17_1) & 63;
  int stage_v_175_2 = (stage_v_53_2 ^ pub_r001307_17_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
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
    if ((stage_v_48_2 & 2) != 0)
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
  int stage_v_176_1 = (stage_v_78_1 ^ pub_r001307_19_1) & 63;
  int stage_v_176_2 = (stage_v_78_2 ^ pub_r001307_19_2) & 63;
  if ((stage_v_176_1 & 1) != 0)
  {
    if ((stage_v_118_1 & 2) != 0)
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
    if ((stage_v_118_2 & 2) != 0)
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
  int stage_v_177_1 = ((pub_r001307_10_1 * 2) + 25) & 63;
  int stage_v_177_2 = ((pub_r001307_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (helper_flow_0_1 ^ pub_r001307_11_1) & 63;
  int stage_v_178_2 = (helper_flow_0_2 ^ pub_r001307_11_2) & 63;
  if ((stage_v_178_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
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
    if ((stage_v_27_2 & 2) != 0)
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
  int stage_v_179_1 = (stage_v_70_1 ^ pub_r001307_14_1) & 63;
  int stage_v_179_2 = (stage_v_70_2 ^ pub_r001307_14_2) & 63;
  if ((stage_v_179_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
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
    if ((stage_v_2_2 & 2) != 0)
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
  int stage_v_180_1 = (stage_v_140_1 ^ pub_r001307_2_1) & 63;
  int stage_v_180_2 = (stage_v_140_2 ^ pub_r001307_2_2) & 63;
  if ((stage_v_180_1 & 1) != 0)
  {
    if ((stage_v_148_1 & 2) != 0)
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
    if ((stage_v_148_2 & 2) != 0)
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
  int stage_v_181_1 = (stage_v_54_1 ^ pub_r001307_7_1) & 63;
  int stage_v_181_2 = (stage_v_54_2 ^ pub_r001307_7_2) & 63;
  if ((stage_v_181_1 & 1) != 0)
  {
    if ((sec_r001307_16_1 & 2) != 0)
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
    if ((sec_r001307_16_2 & 2) != 0)
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
  int stage_v_182_1 = ((pub_r001307_20_1 * 2) + 19) & 63;
  int stage_v_182_2 = ((pub_r001307_20_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (helper_flow_9_1 ^ pub_r001307_4_1) & 63;
  int stage_v_183_2 = (helper_flow_9_2 ^ pub_r001307_4_2) & 63;
  if ((stage_v_183_1 & 1) != 0)
  {
    if ((stage_v_136_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_183_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  }
  if ((stage_v_183_2 & 1) != 0)
  {
    if ((stage_v_136_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_183_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  }
  int stage_v_184_1 = (stage_v_108_1 ^ pub_r001307_19_1) & 63;
  int stage_v_184_2 = (stage_v_108_2 ^ pub_r001307_19_2) & 63;
  if ((stage_v_184_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
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
    if ((stage_v_23_2 & 2) != 0)
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
  int stage_v_185_1 = (stage_v_132_1 ^ pub_r001307_13_1) & 63;
  int stage_v_185_2 = (stage_v_132_2 ^ pub_r001307_13_2) & 63;
  if ((stage_v_185_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
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
    if ((helper_flow_2_2 & 2) != 0)
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
  int stage_v_186_1 = (sec_r001307_5_1 ^ pub_r001307_16_1) & 63;
  int stage_v_186_2 = (sec_r001307_5_2 ^ pub_r001307_16_2) & 63;
  if ((stage_v_186_1 & 1) != 0)
  {
    if ((stage_v_93_1 & 2) != 0)
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
    if ((stage_v_93_2 & 2) != 0)
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
  int stage_v_187_1 = ((pub_r001307_19_1 * 2) + 37) & 63;
  int stage_v_187_2 = ((pub_r001307_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001307_5_1 * 2) + 23) & 63;
  int stage_v_188_2 = ((pub_r001307_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (sec_r001307_2_1 ^ pub_r001307_5_1) & 63;
  int stage_v_189_2 = (sec_r001307_2_2 ^ pub_r001307_5_2) & 63;
  if ((stage_v_189_1 & 1) != 0)
  {
    if ((stage_v_152_1 & 2) != 0)
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
    if ((stage_v_152_2 & 2) != 0)
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
  int stage_v_190_1 = (stage_v_95_1 ^ pub_r001307_4_1) & 63;
  int stage_v_190_2 = (stage_v_95_2 ^ pub_r001307_4_2) & 63;
  if ((stage_v_190_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_190_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  }
  if ((stage_v_190_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_190_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  }
  int stage_v_191_1 = (stage_v_53_1 ^ pub_r001307_21_1) & 63;
  int stage_v_191_2 = (stage_v_53_2 ^ pub_r001307_21_2) & 63;
  if ((stage_v_191_1 & 1) != 0)
  {
    if ((stage_v_190_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_191_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  }
  if ((stage_v_191_2 & 1) != 0)
  {
    if ((stage_v_190_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_191_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  }
  int stage_v_192_1 = (stage_v_60_1 ^ pub_r001307_8_1) & 63;
  int stage_v_192_2 = (stage_v_60_2 ^ pub_r001307_8_2) & 63;
  if ((stage_v_192_1 & 1) != 0)
  {
    if ((sec_r001307_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_192_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  }
  if ((stage_v_192_2 & 1) != 0)
  {
    if ((sec_r001307_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_192_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  }
  int stage_v_193_1 = (stage_v_112_1 ^ pub_r001307_10_1) & 63;
  int stage_v_193_2 = (stage_v_112_2 ^ pub_r001307_10_2) & 63;
  if ((stage_v_193_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
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
    if ((stage_v_66_2 & 2) != 0)
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
  int stage_v_194_1 = (stage_v_52_1 ^ pub_r001307_3_1) & 63;
  int stage_v_194_2 = (stage_v_52_2 ^ pub_r001307_3_2) & 63;
  if ((stage_v_194_1 & 1) != 0)
  {
    if ((stage_v_67_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_194_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  }
  if ((stage_v_194_2 & 1) != 0)
  {
    if ((stage_v_67_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_194_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  }
  int stage_v_195_1 = ((pub_r001307_20_1 * 2) + 37) & 63;
  int stage_v_195_2 = ((pub_r001307_20_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (stage_v_74_1 ^ pub_r001307_19_1) & 63;
  int stage_v_196_2 = (stage_v_74_2 ^ pub_r001307_19_2) & 63;
  if ((stage_v_196_1 & 1) != 0)
  {
    if ((helper_flow_9_1 & 2) != 0)
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
    if ((helper_flow_9_2 & 2) != 0)
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
  int stage_v_197_1 = ((pub_r001307_22_1 * 2) + 8) & 63;
  int stage_v_197_2 = ((pub_r001307_22_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (sec_r001307_7_1 ^ pub_r001307_6_1) & 63;
  int stage_v_198_2 = (sec_r001307_7_2 ^ pub_r001307_6_2) & 63;
  if ((stage_v_198_1 & 1) != 0)
  {
    if ((sec_r001307_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_198_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  }
  if ((stage_v_198_2 & 1) != 0)
  {
    if ((sec_r001307_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_198_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  }
  int stage_v_199_1 = (sec_r001307_2_1 ^ pub_r001307_6_1) & 63;
  int stage_v_199_2 = (sec_r001307_2_2 ^ pub_r001307_6_2) & 63;
  if ((stage_v_199_1 & 1) != 0)
  {
    if ((stage_v_91_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_199_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  }
  if ((stage_v_199_2 & 1) != 0)
  {
    if ((stage_v_91_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_199_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  }
  int stage_v_200_1 = (stage_v_31_1 ^ pub_r001307_6_1) & 63;
  int stage_v_200_2 = (stage_v_31_2 ^ pub_r001307_6_2) & 63;
  if ((stage_v_200_1 & 1) != 0)
  {
    if ((stage_v_84_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_200_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  }
  if ((stage_v_200_2 & 1) != 0)
  {
    if ((stage_v_84_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_200_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  }
  int stage_v_201_1 = (stage_v_175_1 ^ pub_r001307_15_1) & 63;
  int stage_v_201_2 = (stage_v_175_2 ^ pub_r001307_15_2) & 63;
  if ((stage_v_201_1 & 1) != 0)
  {
    if ((stage_v_107_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_201_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  }
  if ((stage_v_201_2 & 1) != 0)
  {
    if ((stage_v_107_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_201_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  }
  int stage_v_202_1 = ((pub_r001307_14_1 * 2) + 6) & 63;
  int stage_v_202_2 = ((pub_r001307_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001307_2_1 * 2) + 46) & 63;
  int stage_v_203_2 = ((pub_r001307_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (sec_r001307_6_1 ^ pub_r001307_22_1) & 63;
  int stage_v_204_2 = (sec_r001307_6_2 ^ pub_r001307_22_2) & 63;
  if ((stage_v_204_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_204_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  }
  if ((stage_v_204_2 & 1) != 0)
  {
    if ((stage_v_66_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_204_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  }
  int stage_v_205_1 = (stage_v_74_1 ^ pub_r001307_14_1) & 63;
  int stage_v_205_2 = (stage_v_74_2 ^ pub_r001307_14_2) & 63;
  if ((stage_v_205_1 & 1) != 0)
  {
    if ((stage_v_107_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_205_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  }
  if ((stage_v_205_2 & 1) != 0)
  {
    if ((stage_v_107_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_205_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  }
  int stage_v_206_1 = (stage_v_31_1 ^ pub_r001307_19_1) & 63;
  int stage_v_206_2 = (stage_v_31_2 ^ pub_r001307_19_2) & 63;
  if ((stage_v_206_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_206_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  }
  if ((stage_v_206_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_206_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  }
  int stage_v_207_1 = (stage_v_161_1 ^ pub_r001307_8_1) & 63;
  int stage_v_207_2 = (stage_v_161_2 ^ pub_r001307_8_2) & 63;
  if ((stage_v_207_1 & 1) != 0)
  {
    if ((stage_v_115_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_207_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  }
  if ((stage_v_207_2 & 1) != 0)
  {
    if ((stage_v_115_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_207_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  }
  int stage_v_208_1 = (stage_v_9_1 ^ pub_r001307_10_1) & 63;
  int stage_v_208_2 = (stage_v_9_2 ^ pub_r001307_10_2) & 63;
  if ((stage_v_208_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_208_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  }
  if ((stage_v_208_2 & 1) != 0)
  {
    if ((stage_v_48_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_208_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  }
  int stage_v_209_1 = (stage_v_152_1 ^ pub_r001307_3_1) & 63;
  int stage_v_209_2 = (stage_v_152_2 ^ pub_r001307_3_2) & 63;
  if ((stage_v_209_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_209_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  }
  if ((stage_v_209_2 & 1) != 0)
  {
    if ((stage_v_30_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_209_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  }
  int stage_v_210_1 = (stage_v_140_1 ^ pub_r001307_3_1) & 63;
  int stage_v_210_2 = (stage_v_140_2 ^ pub_r001307_3_2) & 63;
  if ((stage_v_210_1 & 1) != 0)
  {
    if ((sec_r001307_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_210_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  }
  if ((stage_v_210_2 & 1) != 0)
  {
    if ((sec_r001307_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_210_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  }
  int stage_v_211_1 = (stage_v_141_1 ^ pub_r001307_1_1) & 63;
  int stage_v_211_2 = (stage_v_141_2 ^ pub_r001307_1_2) & 63;
  if ((stage_v_211_1 & 1) != 0)
  {
    if ((stage_v_47_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_211_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  }
  if ((stage_v_211_2 & 1) != 0)
  {
    if ((stage_v_47_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_211_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  }
  int stage_v_212_1 = (sec_r001307_16_1 ^ pub_r001307_12_1) & 63;
  int stage_v_212_2 = (sec_r001307_16_2 ^ pub_r001307_12_2) & 63;
  if ((stage_v_212_1 & 1) != 0)
  {
    if ((stage_v_193_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_212_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  }
  if ((stage_v_212_2 & 1) != 0)
  {
    if ((stage_v_193_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_212_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  }
  int stage_v_213_1 = ((pub_r001307_7_1 * 2) + 48) & 63;
  int stage_v_213_2 = ((pub_r001307_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (stage_v_67_1 ^ pub_r001307_19_1) & 63;
  int stage_v_214_2 = (stage_v_67_2 ^ pub_r001307_19_2) & 63;
  if ((stage_v_214_1 & 1) != 0)
  {
    if ((stage_v_204_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_214_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  }
  if ((stage_v_214_2 & 1) != 0)
  {
    if ((stage_v_204_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_214_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  }
  int stage_v_215_1 = ((pub_r001307_15_1 * 2) + 33) & 63;
  int stage_v_215_2 = ((pub_r001307_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = (stage_v_27_1 ^ pub_r001307_15_1) & 63;
  int stage_v_216_2 = (stage_v_27_2 ^ pub_r001307_15_2) & 63;
  if ((stage_v_216_1 & 1) != 0)
  {
    if ((stage_v_29_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_216_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_216_1 * 2)) & 255;
  }
  if ((stage_v_216_2 & 1) != 0)
  {
    if ((stage_v_29_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_216_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_216_2 * 2)) & 255;
  }
  int stage_v_217_1 = (stage_v_157_1 ^ pub_r001307_13_1) & 63;
  int stage_v_217_2 = (stage_v_157_2 ^ pub_r001307_13_2) & 63;
  if ((stage_v_217_1 & 1) != 0)
  {
    if ((stage_v_118_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_217_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_217_1 * 2)) & 255;
  }
  if ((stage_v_217_2 & 1) != 0)
  {
    if ((stage_v_118_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_217_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_217_2 * 2)) & 255;
  }
  int stage_v_218_1 = (helper_flow_9_1 ^ pub_r001307_8_1) & 63;
  int stage_v_218_2 = (helper_flow_9_2 ^ pub_r001307_8_2) & 63;
  if ((stage_v_218_1 & 1) != 0)
  {
    if ((stage_v_52_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_218_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_218_1 * 2)) & 255;
  }
  if ((stage_v_218_2 & 1) != 0)
  {
    if ((stage_v_52_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_218_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_218_2 * 2)) & 255;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001307_16_1 != sec_r001307_16_2);
  __CPROVER_assume(pub_r001307_18_1 == pub_r001307_18_2);
  __CPROVER_assume(sec_r001307_9_1 != sec_r001307_9_2);
  __CPROVER_assume(pub_r001307_3_1 == pub_r001307_3_2);
  __CPROVER_assume(sec_r001307_13_1 != sec_r001307_13_2);
  __CPROVER_assume(pub_r001307_5_1 == pub_r001307_5_2);
  __CPROVER_assume(sec_r001307_5_1 != sec_r001307_5_2);
  __CPROVER_assume(sec_r001307_4_1 != sec_r001307_4_2);
  __CPROVER_assume(sec_r001307_2_1 != sec_r001307_2_2);
  __CPROVER_assume(sec_r001307_8_1 != sec_r001307_8_2);
  __CPROVER_assume(pub_r001307_21_1 == pub_r001307_21_2);
  __CPROVER_assume(sec_r001307_1_1 != sec_r001307_1_2);
  __CPROVER_assume(pub_r001307_14_1 == pub_r001307_14_2);
  __CPROVER_assume(pub_r001307_19_1 == pub_r001307_19_2);
  __CPROVER_assume(pub_r001307_12_1 == pub_r001307_12_2);
  __CPROVER_assume(sec_r001307_6_1 != sec_r001307_6_2);
  __CPROVER_assume(pub_r001307_8_1 == pub_r001307_8_2);
  __CPROVER_assume(sec_r001307_11_1 != sec_r001307_11_2);
  __CPROVER_assume(pub_r001307_6_1 == pub_r001307_6_2);
  __CPROVER_assume(pub_r001307_9_1 == pub_r001307_9_2);
  __CPROVER_assume(pub_r001307_10_1 == pub_r001307_10_2);
  __CPROVER_assume(pub_r001307_20_1 == pub_r001307_20_2);
  __CPROVER_assume(sec_r001307_7_1 != sec_r001307_7_2);
  __CPROVER_assume(pub_r001307_13_1 == pub_r001307_13_2);
  __CPROVER_assume(pub_r001307_4_1 == pub_r001307_4_2);
  __CPROVER_assume(pub_r001307_17_1 == pub_r001307_17_2);
  __CPROVER_assume(sec_r001307_15_1 != sec_r001307_15_2);
  __CPROVER_assume(sec_r001307_3_1 != sec_r001307_3_2);
  __CPROVER_assume(pub_r001307_15_1 == pub_r001307_15_2);
  __CPROVER_assume(pub_r001307_0_1 == pub_r001307_0_2);
  __CPROVER_assume(pub_r001307_22_1 == pub_r001307_22_2);
  __CPROVER_assume(pub_r001307_16_1 == pub_r001307_16_2);
  __CPROVER_assume(pub_r001307_11_1 == pub_r001307_11_2);
  __CPROVER_assume(sec_r001307_12_1 != sec_r001307_12_2);
  __CPROVER_assume(sec_r001307_14_1 != sec_r001307_14_2);
  __CPROVER_assume(sec_r001307_0_1 != sec_r001307_0_2);
  __CPROVER_assume(pub_r001307_2_1 == pub_r001307_2_2);
  __CPROVER_assume(sec_r001307_10_1 != sec_r001307_10_2);
  __CPROVER_assume(pub_r001307_7_1 == pub_r001307_7_2);
  __CPROVER_assume(pub_r001307_1_1 == pub_r001307_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.head == st_var_0_2.head);
  assert(st_var_0_1.state == st_var_0_2.state);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.flags == st_var_2_2.flags);
  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
  assert(st_var_2_1.tag == st_var_2_2.tag);
  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.round_key == st_var_2_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.scale == st_var_3_2.scale);
  assert(st_var_3_1.density == st_var_3_2.density);
  assert(st_var_3_1.stride == st_var_3_2.stride);
  assert(st_var_3_1.trace == st_var_3_2.trace);
  assert(st_var_3_1.dim == st_var_3_2.dim);
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
}


