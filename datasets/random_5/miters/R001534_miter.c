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
struct AudioFrame_R001534_3413_0
{
  int rms;
  int peak;
  short sample_rate;
  int gain;
  int channels;
  int envelope;
  int buffer[3];
};
struct MatrixBlock_R001534_3413_1
{
  unsigned char dim;
  unsigned char stride;
  unsigned char trace;
  int scale;
  short density;
  int determinant;
  int buffer[3];
};
struct CipherContext_R001534_3413_2
{
  unsigned char flags;
  short counter;
  int nonce;
  unsigned char iv;
  int round_key;
  int tag;
  int buffer[3];
};
struct StreamBuffer_R001534_3413_3
{
  int head;
  unsigned char tail;
  unsigned char watermark;
  int buffer[3];
};
union TelemetryField_R001534_3413_0
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
void fn_R001534_3413_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001534_3413_3 st_1 = {0};
  struct StreamBuffer_R001534_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int segment_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_74_1) & 63;
  aux_2 = (aux_2 + segment_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_74_1 == segment_74_2);
}

int fn_R001534_3413_0(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001534_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int segment_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_74) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001534_3413_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001534_3413_3 st_1 = {0};
  struct StreamBuffer_R001534_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int quantum_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_15_1 > 43)
  {
    acc_1 = ((acc_1 + (quantum_15_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_15_2 > 43)
  {
    acc_2 = ((acc_2 + (quantum_15_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_63_1 = local_arr_1[aux_1 % 3];
  int threshold_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_63_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_15_1 == quantum_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_63_1 == threshold_63_2);
}

int fn_R001534_3413_1(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001534_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int quantum_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_15 > 43)
  {
    acc = ((acc + (quantum_15 * 2)) + 5) & 127;
    aux ^= quantum_15 & 15;
  }
  else
  {
    acc = ((acc - quantum_15) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_63 = local_arr[aux % 3];
  acc = (acc + (threshold_63 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001534_3413_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001534_3413_0 st_1 = {0};
  struct AudioFrame_R001534_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_72_1)
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

  switch (offset_72_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_72_1 == offset_72_2);
}

int fn_R001534_3413_2(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001534_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_72 = (aux + st.buffer[1]) & 3;
  switch (offset_72)
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

void fn_R001534_3413_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001534_3413_1 st_1 = {0};
  struct MatrixBlock_R001534_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int factor_28_1 = 0;
  int factor_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_28_1 = ((factor_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_28_2 = ((factor_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_28_1) & 127;
    acc_2 = (acc_2 + factor_28_2) & 127;
  }

  int sample_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_58_1) & 63;
  aux_2 = (aux_2 + sample_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_28_1 == factor_28_2);
  assert(sample_58_1 == sample_58_2);
}

int fn_R001534_3413_3(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001534_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int factor_28 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_28 = ((factor_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_28) & 127;
  }

  int sample_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_58) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001534_3413_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001534_3413_1 st_1 = {0};
  struct MatrixBlock_R001534_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int delta_19_1 = 0;
  int delta_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_19_1 = ((delta_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_19_2 = ((delta_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_19_1) & 127;
    acc_2 = (acc_2 + delta_19_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_23_1) & 63;
  aux_2 = (aux_2 + phase_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_91_1 = local_arr_1[aux_1 % 3];
  int metric_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_91_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_19_1 == delta_19_2);
  assert(phase_23_1 == phase_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_91_1 == metric_91_2);
}

int fn_R001534_3413_4(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001534_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int delta_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_19 = ((delta_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_19) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_23) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_91 = local_arr[aux % 3];
  acc = (acc + (metric_91 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001534_3413_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001534_3413_1 st_1 = {0};
  struct MatrixBlock_R001534_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int window_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_34_1 > 27)
  {
    acc_1 = ((acc_1 + (window_34_1 * 2)) + 5) & 127;
    aux_1 ^= window_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_34_2 > 27)
  {
    acc_2 = ((acc_2 + (window_34_2 * 2)) + 5) & 127;
    aux_2 ^= window_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_95_1)
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

  switch (window_95_2)
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

  int residue_30_1 = 0;
  int residue_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_30_1 = ((residue_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_30_2 = ((residue_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_30_1) & 127;
    acc_2 = (acc_2 + residue_30_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_34_1 == window_34_2);
  assert(window_95_1 == window_95_2);
  assert(residue_30_1 == residue_30_2);
}

int fn_R001534_3413_5(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001534_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int window_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_34 > 27)
  {
    acc = ((acc + (window_34 * 2)) + 5) & 127;
    aux ^= window_34 & 15;
  }
  else
  {
    acc = ((acc - window_34) + 11) & 127;
    aux += 3;
  }
  int window_95 = (aux + st.buffer[1]) & 3;
  switch (window_95)
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

  int residue_30 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_30 = ((residue_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_30) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001534_3413_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st_1 = {0};
  struct CipherContext_R001534_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int vector_26_1 = 0;
  int vector_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_26_1 = ((vector_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_26_2 = ((vector_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_26_1) & 127;
    acc_2 = (acc_2 + vector_26_2) & 127;
  }

  int threshold_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_59_1) & 63;
  aux_2 = (aux_2 + threshold_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_38_1 = local_arr_1[aux_1 % 3];
  int tracker_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_38_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_26_1 == vector_26_2);
  assert(threshold_59_1 == threshold_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_38_1 == tracker_38_2);
}

int fn_R001534_3413_6(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int vector_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_26 = ((vector_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_26) & 127;
  }

  int threshold_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_59) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_38 = local_arr[aux % 3];
  acc = (acc + (tracker_38 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001534_3413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001534_3413_3 st_1 = {0};
  struct StreamBuffer_R001534_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int accumulator_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_32_1) & 63;
  aux_2 = (aux_2 + accumulator_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_70_1)
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

  switch (factor_70_2)
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
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_32_1 == accumulator_32_2);
  assert(factor_70_1 == factor_70_2);
}

int fn_R001534_3413_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001534_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int accumulator_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_32) & 63;
  acc ^= aux;
  int factor_70 = (aux + st.buffer[1]) & 3;
  switch (factor_70)
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

void fn_R001534_3413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001534_3413_0 st_1 = {0};
  struct AudioFrame_R001534_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_17_1 = local_arr_1[aux_1 % 3];
  int coefficient_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_17_2 * 2)) & 127;
  int factor_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_11_1 > 28)
  {
    acc_1 = ((acc_1 + (factor_11_1 * 2)) + 5) & 127;
    aux_1 ^= factor_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_11_2 > 28)
  {
    acc_2 = ((acc_2 + (factor_11_2 * 2)) + 5) & 127;
    aux_2 ^= factor_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_17_1 == coefficient_17_2);
  assert(factor_11_1 == factor_11_2);
}

int fn_R001534_3413_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001534_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int coefficient_17 = local_arr[aux % 3];
  acc = (acc + (coefficient_17 * 2)) & 127;
  int factor_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_11 > 28)
  {
    acc = ((acc + (factor_11 * 2)) + 5) & 127;
    aux ^= factor_11 & 15;
  }
  else
  {
    acc = ((acc - factor_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001534_3413_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st_1 = {0};
  struct CipherContext_R001534_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int index_reg_91_1 = 0;
  int index_reg_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_91_1 = ((index_reg_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_91_2 = ((index_reg_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_91_1) & 127;
    acc_2 = (acc_2 + index_reg_91_2) & 127;
  }

  int threshold_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_10_1 > 48)
  {
    acc_1 = ((acc_1 + (threshold_10_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_10_2 > 48)
  {
    acc_2 = ((acc_2 + (threshold_10_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_54_1 = local_arr_1[aux_1 % 3];
  int factor_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_91_1 == index_reg_91_2);
  assert(threshold_10_1 == threshold_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_54_1 == factor_54_2);
}

int fn_R001534_3413_9(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int index_reg_91 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_91 = ((index_reg_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_91) & 127;
  }

  int threshold_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_10 > 48)
  {
    acc = ((acc + (threshold_10 * 2)) + 5) & 127;
    aux ^= threshold_10 & 15;
  }
  else
  {
    acc = ((acc - threshold_10) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_54 = local_arr[aux % 3];
  acc = (acc + (factor_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001534_3413_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st_1 = {0};
  struct CipherContext_R001534_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_58_1 = local_arr_1[aux_1 % 3];
  int stride_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_58_2 * 2)) & 127;
  int pivot_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_77_1)
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

  switch (pivot_77_2)
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

  int margin_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_43_1) & 63;
  aux_2 = (aux_2 + margin_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_58_1 == stride_58_2);
  assert(pivot_77_1 == pivot_77_2);
  assert(margin_43_1 == margin_43_2);
}

int fn_R001534_3413_10(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int stride_58 = local_arr[aux % 3];
  acc = (acc + (stride_58 * 2)) & 127;
  int pivot_77 = (aux + st.buffer[1]) & 3;
  switch (pivot_77)
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

  int margin_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_43) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001534_3413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001534_3413_1 st_1 = {0};
  struct MatrixBlock_R001534_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int weight_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_40_1 > 21)
  {
    acc_1 = ((acc_1 + (weight_40_1 * 2)) + 5) & 127;
    aux_1 ^= weight_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_40_2 > 21)
  {
    acc_2 = ((acc_2 + (weight_40_2 * 2)) + 5) & 127;
    aux_2 ^= weight_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_40_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_71_1 = local_arr_1[aux_1 % 3];
  int parity_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_71_2 * 2)) & 127;
  int quantum_16_1 = 0;
  int quantum_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_16_1 = ((quantum_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_16_2 = ((quantum_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_16_1) & 127;
    acc_2 = (acc_2 + quantum_16_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_40_1 == weight_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_71_1 == parity_71_2);
  assert(quantum_16_1 == quantum_16_2);
}

int fn_R001534_3413_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001534_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int weight_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_40 > 21)
  {
    acc = ((acc + (weight_40 * 2)) + 5) & 127;
    aux ^= weight_40 & 15;
  }
  else
  {
    acc = ((acc - weight_40) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_71 = local_arr[aux % 3];
  acc = (acc + (parity_71 * 2)) & 127;
  int quantum_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_16 = ((quantum_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_16) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001534_3413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001534_3413_0 st_1 = {0};
  struct AudioFrame_R001534_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int margin_58_1 = 0;
  int margin_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_58_1 = ((margin_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_58_2 = ((margin_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_58_1) & 127;
    acc_2 = (acc_2 + margin_58_2) & 127;
  }

  int tracker_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_34_1 > 21)
  {
    acc_1 = ((acc_1 + (tracker_34_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_34_2 > 21)
  {
    acc_2 = ((acc_2 + (tracker_34_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_87_1)
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

  switch (stride_87_2)
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

  int quotient_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_46_1) & 63;
  aux_2 = (aux_2 + quotient_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_58_1 == margin_58_2);
  assert(tracker_34_1 == tracker_34_2);
  assert(stride_87_1 == stride_87_2);
  assert(quotient_46_1 == quotient_46_2);
}

int fn_R001534_3413_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001534_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int margin_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_58 = ((margin_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_58) & 127;
  }

  int tracker_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_34 > 21)
  {
    acc = ((acc + (tracker_34 * 2)) + 5) & 127;
    aux ^= tracker_34 & 15;
  }
  else
  {
    acc = ((acc - tracker_34) + 11) & 127;
    aux += 3;
  }
  int stride_87 = (aux + st.buffer[1]) & 3;
  switch (stride_87)
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

  int quotient_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_46) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001534_3413_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st_1 = {0};
  struct CipherContext_R001534_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int index_reg_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_31_1 > 15)
  {
    acc_1 = ((acc_1 + (index_reg_31_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_31_2 > 15)
  {
    acc_2 = ((acc_2 + (index_reg_31_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_31_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_25_1 = local_arr_1[aux_1 % 3];
  int vector_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_25_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_31_1 == index_reg_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_25_1 == vector_25_2);
}

int fn_R001534_3413_13(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int index_reg_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_31 > 15)
  {
    acc = ((acc + (index_reg_31 * 2)) + 5) & 127;
    aux ^= index_reg_31 & 15;
  }
  else
  {
    acc = ((acc - index_reg_31) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_25 = local_arr[aux % 3];
  acc = (acc + (vector_25 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001534_3413_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st_1 = {0};
  struct CipherContext_R001534_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int margin_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_17_1) & 63;
  aux_2 = (aux_2 + margin_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_85_1)
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

  switch (stride_85_2)
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
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_17_1 == margin_17_2);
  assert(stride_85_1 == stride_85_2);
}

int fn_R001534_3413_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int margin_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_17) & 63;
  acc ^= aux;
  int stride_85 = (aux + st.buffer[1]) & 3;
  switch (stride_85)
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

void fn_R001534_3413_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001534_3413_1 st_1 = {0};
  struct MatrixBlock_R001534_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int accumulator_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_91_1) & 63;
  aux_2 = (aux_2 + accumulator_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_33_1 > 15)
  {
    acc_1 = ((acc_1 + (quotient_33_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_33_2 > 15)
  {
    acc_2 = ((acc_2 + (quotient_33_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_14_1 = local_arr_1[aux_1 % 3];
  int sample_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_14_2 * 2)) & 127;
  int bound_16_1 = 0;
  int bound_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_16_1 = ((bound_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_16_2 = ((bound_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_16_1) & 127;
    acc_2 = (acc_2 + bound_16_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_91_1 == accumulator_91_2);
  assert(quotient_33_1 == quotient_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_14_1 == sample_14_2);
  assert(bound_16_1 == bound_16_2);
}

int fn_R001534_3413_15(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001534_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int accumulator_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_91) & 63;
  acc ^= aux;
  int quotient_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_33 > 15)
  {
    acc = ((acc + (quotient_33 * 2)) + 5) & 127;
    aux ^= quotient_33 & 15;
  }
  else
  {
    acc = ((acc - quotient_33) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_14 = local_arr[aux % 3];
  acc = (acc + (sample_14 * 2)) & 127;
  int bound_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_16 = ((bound_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_16) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001534_3413_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st_1 = {0};
  struct CipherContext_R001534_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int residue_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_79_1)
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

  switch (residue_79_2)
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

  int window_58_1 = 0;
  int window_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_58_1 = ((window_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_58_2 = ((window_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_58_1) & 127;
    acc_2 = (acc_2 + window_58_2) & 127;
  }

  int bound_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_79_1) & 63;
  aux_2 = (aux_2 + bound_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_79_1 == residue_79_2);
  assert(window_58_1 == window_58_2);
  assert(bound_79_1 == bound_79_2);
}

int fn_R001534_3413_16(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int residue_79 = (aux + st.buffer[1]) & 3;
  switch (residue_79)
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

  int window_58 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_58 = ((window_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_58) & 127;
  }

  int bound_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_79) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001534_3413_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001534_3413_0 st_1 = {0};
  struct AudioFrame_R001534_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int anchor_80_1 = 0;
  int anchor_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_80_1 = ((anchor_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_80_2 = ((anchor_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_80_1) & 127;
    acc_2 = (acc_2 + anchor_80_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_35_1 = local_arr_1[aux_1 % 3];
  int offset_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_35_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_56_1 > 37)
  {
    acc_1 = ((acc_1 + (mask_56_1 * 2)) + 5) & 127;
    aux_1 ^= mask_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_56_2 > 37)
  {
    acc_2 = ((acc_2 + (mask_56_2 * 2)) + 5) & 127;
    aux_2 ^= mask_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_80_1 == anchor_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_35_1 == offset_35_2);
  assert(mask_56_1 == mask_56_2);
}

int fn_R001534_3413_17(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001534_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int anchor_80 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_80 = ((anchor_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_80) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int offset_35 = local_arr[aux % 3];
  acc = (acc + (offset_35 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_56 > 37)
  {
    acc = ((acc + (mask_56 * 2)) + 5) & 127;
    aux ^= mask_56 & 15;
  }
  else
  {
    acc = ((acc - mask_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001534_3413_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001534_3413_0 st_1 = {0};
  struct AudioFrame_R001534_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_19_1 = local_arr_1[aux_1 % 3];
  int quantum_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_19_2 * 2)) & 127;
  int bound_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_23_1)
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

  switch (bound_23_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_19_1 == quantum_19_2);
  assert(bound_23_1 == bound_23_2);
}

int fn_R001534_3413_18(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001534_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int quantum_19 = local_arr[aux % 3];
  acc = (acc + (quantum_19 * 2)) & 127;
  int bound_23 = (aux + st.buffer[1]) & 3;
  switch (bound_23)
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

void fn_R001534_3413_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001534_3413_3 st_1 = {0};
  struct StreamBuffer_R001534_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int scale_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_49_1) & 63;
  aux_2 = (aux_2 + scale_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_24_1)
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

  switch (window_24_2)
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
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_49_1 == scale_49_2);
  assert(window_24_1 == window_24_2);
}

int fn_R001534_3413_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001534_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int scale_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_49) & 63;
  acc ^= aux;
  int window_24 = (aux + st.buffer[1]) & 3;
  switch (window_24)
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

void fn_R001534_3413_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st_1 = {0};
  struct CipherContext_R001534_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int phase_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_22_1)
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

  switch (phase_22_2)
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
  int window_92_1 = local_arr_1[aux_1 % 3];
  int window_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_92_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_51_1) & 63;
  aux_2 = (aux_2 + metric_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_22_1 == phase_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_92_1 == window_92_2);
  assert(metric_51_1 == metric_51_2);
}

int fn_R001534_3413_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001534_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int phase_22 = (aux + st.buffer[1]) & 3;
  switch (phase_22)
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
  int window_92 = local_arr[aux % 3];
  acc = (acc + (window_92 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_51) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001534_3413_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001534_3413_0 st_1 = {0};
  struct AudioFrame_R001534_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int checksum_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_39_1)
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

  switch (checksum_39_2)
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

  int index_reg_87_1 = 0;
  int index_reg_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_87_1 = ((index_reg_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_87_2 = ((index_reg_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_87_1) & 127;
    acc_2 = (acc_2 + index_reg_87_2) & 127;
  }

  int offset_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_24_1) & 63;
  aux_2 = (aux_2 + offset_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_39_1 == checksum_39_2);
  assert(index_reg_87_1 == index_reg_87_2);
  assert(offset_24_1 == offset_24_2);
}

int fn_R001534_3413_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001534_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int checksum_39 = (aux + st.buffer[1]) & 3;
  switch (checksum_39)
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

  int index_reg_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_87 = ((index_reg_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_87) & 127;
  }

  int offset_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_24) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001534_3413_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001534_3413_3 st_1 = {0};
  struct StreamBuffer_R001534_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_53_1) & 63;
  aux_2 = (aux_2 + offset_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_12_1 > 26)
  {
    acc_1 = ((acc_1 + (vector_12_1 * 2)) + 5) & 127;
    aux_1 ^= vector_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_12_2 > 26)
  {
    acc_2 = ((acc_2 + (vector_12_2 * 2)) + 5) & 127;
    aux_2 ^= vector_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_53_1 == offset_53_2);
  assert(vector_12_1 == vector_12_2);
}

int fn_R001534_3413_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001534_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_53) & 63;
  acc ^= aux;
  int vector_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_12 > 26)
  {
    acc = ((acc + (vector_12 * 2)) + 5) & 127;
    aux ^= vector_12 & 15;
  }
  else
  {
    acc = ((acc - vector_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001534_3413_23_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001534_3413_3 st_1 = {0};
  struct StreamBuffer_R001534_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int damping_46_1 = 0;
  int damping_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_46_1 = ((damping_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_46_2 = ((damping_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_46_1) & 127;
    acc_2 = (acc_2 + damping_46_2) & 127;
  }

  int scale_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_69_1) & 63;
  aux_2 = (aux_2 + scale_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_96_1 > 38)
  {
    acc_1 = ((acc_1 + (checksum_96_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_96_2 > 38)
  {
    acc_2 = ((acc_2 + (checksum_96_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_96_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_46_1 == damping_46_2);
  assert(scale_69_1 == scale_69_2);
  assert(checksum_96_1 == checksum_96_2);
}

int fn_R001534_3413_23(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001534_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int damping_46 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_46 = ((damping_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_46) & 127;
  }

  int scale_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_69) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_96 > 38)
  {
    acc = ((acc + (checksum_96 * 2)) + 5) & 127;
    aux ^= checksum_96 & 15;
  }
  else
  {
    acc = ((acc - checksum_96) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001534_0_1;
  int sec_r001534_0_2;
  int sec_r001534_1_1;
  int sec_r001534_1_2;
  int sec_r001534_2_1;
  int sec_r001534_2_2;
  int sec_r001534_3_1;
  int sec_r001534_3_2;
  int sec_r001534_4_1;
  int sec_r001534_4_2;
  int sec_r001534_5_1;
  int sec_r001534_5_2;
  int sec_r001534_6_1;
  int sec_r001534_6_2;
  int sec_r001534_7_1;
  int sec_r001534_7_2;
  int sec_r001534_8_1;
  int sec_r001534_8_2;
  int sec_r001534_9_1;
  int sec_r001534_9_2;
  int sec_r001534_10_1;
  int sec_r001534_10_2;
  int sec_r001534_11_1;
  int sec_r001534_11_2;
  int sec_r001534_12_1;
  int sec_r001534_12_2;
  int sec_r001534_13_1;
  int sec_r001534_13_2;
  int sec_r001534_14_1;
  int sec_r001534_14_2;
  int sec_r001534_15_1;
  int sec_r001534_15_2;
  int sec_r001534_16_1;
  int sec_r001534_16_2;
  int sec_r001534_17_1;
  int sec_r001534_17_2;
  int sec_r001534_18_1;
  int sec_r001534_18_2;
  int sec_r001534_19_1;
  int sec_r001534_19_2;
  int sec_r001534_20_1;
  int sec_r001534_20_2;
  int sec_r001534_21_1;
  int sec_r001534_21_2;
  int pub_r001534_0_1;
  int pub_r001534_0_2;
  int pub_r001534_1_1;
  int pub_r001534_1_2;
  int pub_r001534_2_1;
  int pub_r001534_2_2;
  int pub_r001534_3_1;
  int pub_r001534_3_2;
  int pub_r001534_4_1;
  int pub_r001534_4_2;
  int pub_r001534_5_1;
  int pub_r001534_5_2;
  int pub_r001534_6_1;
  int pub_r001534_6_2;
  int pub_r001534_7_1;
  int pub_r001534_7_2;
  int pub_r001534_8_1;
  int pub_r001534_8_2;
  int pub_r001534_9_1;
  int pub_r001534_9_2;
  int pub_r001534_10_1;
  int pub_r001534_10_2;
  int pub_r001534_11_1;
  int pub_r001534_11_2;
  int pub_r001534_12_1;
  int pub_r001534_12_2;
  int pub_r001534_13_1;
  int pub_r001534_13_2;
  int pub_r001534_14_1;
  int pub_r001534_14_2;
  int pub_r001534_15_1;
  int pub_r001534_15_2;
  int pub_r001534_16_1;
  int pub_r001534_16_2;
  int pub_r001534_17_1;
  int pub_r001534_17_2;
  int pub_r001534_18_1;
  int pub_r001534_18_2;
  int pub_r001534_19_1;
  int pub_r001534_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001534_0_1 >= (-100)) && (pub_r001534_0_1 <= 100));
  __CPROVER_assume((pub_r001534_0_2 >= (-100)) && (pub_r001534_0_2 <= 100));
  __CPROVER_assume((pub_r001534_1_1 >= (-100)) && (pub_r001534_1_1 <= 100));
  __CPROVER_assume((pub_r001534_1_2 >= (-100)) && (pub_r001534_1_2 <= 100));
  __CPROVER_assume((pub_r001534_2_1 >= (-100)) && (pub_r001534_2_1 <= 100));
  __CPROVER_assume((pub_r001534_2_2 >= (-100)) && (pub_r001534_2_2 <= 100));
  __CPROVER_assume((pub_r001534_3_1 >= (-100)) && (pub_r001534_3_1 <= 100));
  __CPROVER_assume((pub_r001534_3_2 >= (-100)) && (pub_r001534_3_2 <= 100));
  __CPROVER_assume((pub_r001534_4_1 >= (-100)) && (pub_r001534_4_1 <= 100));
  __CPROVER_assume((pub_r001534_4_2 >= (-100)) && (pub_r001534_4_2 <= 100));
  __CPROVER_assume((pub_r001534_5_1 >= (-100)) && (pub_r001534_5_1 <= 100));
  __CPROVER_assume((pub_r001534_5_2 >= (-100)) && (pub_r001534_5_2 <= 100));
  __CPROVER_assume((pub_r001534_6_1 >= (-100)) && (pub_r001534_6_1 <= 100));
  __CPROVER_assume((pub_r001534_6_2 >= (-100)) && (pub_r001534_6_2 <= 100));
  __CPROVER_assume((pub_r001534_7_1 >= (-100)) && (pub_r001534_7_1 <= 100));
  __CPROVER_assume((pub_r001534_7_2 >= (-100)) && (pub_r001534_7_2 <= 100));
  __CPROVER_assume((pub_r001534_8_1 >= (-100)) && (pub_r001534_8_1 <= 100));
  __CPROVER_assume((pub_r001534_8_2 >= (-100)) && (pub_r001534_8_2 <= 100));
  __CPROVER_assume((pub_r001534_9_1 >= (-100)) && (pub_r001534_9_1 <= 100));
  __CPROVER_assume((pub_r001534_9_2 >= (-100)) && (pub_r001534_9_2 <= 100));
  __CPROVER_assume((pub_r001534_10_1 >= (-100)) && (pub_r001534_10_1 <= 100));
  __CPROVER_assume((pub_r001534_10_2 >= (-100)) && (pub_r001534_10_2 <= 100));
  __CPROVER_assume((pub_r001534_11_1 >= (-100)) && (pub_r001534_11_1 <= 100));
  __CPROVER_assume((pub_r001534_11_2 >= (-100)) && (pub_r001534_11_2 <= 100));
  __CPROVER_assume((pub_r001534_12_1 >= (-100)) && (pub_r001534_12_1 <= 100));
  __CPROVER_assume((pub_r001534_12_2 >= (-100)) && (pub_r001534_12_2 <= 100));
  __CPROVER_assume((pub_r001534_13_1 >= (-100)) && (pub_r001534_13_1 <= 100));
  __CPROVER_assume((pub_r001534_13_2 >= (-100)) && (pub_r001534_13_2 <= 100));
  __CPROVER_assume((pub_r001534_14_1 >= (-100)) && (pub_r001534_14_1 <= 100));
  __CPROVER_assume((pub_r001534_14_2 >= (-100)) && (pub_r001534_14_2 <= 100));
  __CPROVER_assume((pub_r001534_15_1 >= (-100)) && (pub_r001534_15_1 <= 100));
  __CPROVER_assume((pub_r001534_15_2 >= (-100)) && (pub_r001534_15_2 <= 100));
  __CPROVER_assume((pub_r001534_16_1 >= (-100)) && (pub_r001534_16_1 <= 100));
  __CPROVER_assume((pub_r001534_16_2 >= (-100)) && (pub_r001534_16_2 <= 100));
  __CPROVER_assume((pub_r001534_17_1 >= (-100)) && (pub_r001534_17_1 <= 100));
  __CPROVER_assume((pub_r001534_17_2 >= (-100)) && (pub_r001534_17_2 <= 100));
  __CPROVER_assume((pub_r001534_18_1 >= (-100)) && (pub_r001534_18_1 <= 100));
  __CPROVER_assume((pub_r001534_18_2 >= (-100)) && (pub_r001534_18_2 <= 100));
  __CPROVER_assume((pub_r001534_19_1 >= (-100)) && (pub_r001534_19_1 <= 100));
  __CPROVER_assume((pub_r001534_19_2 >= (-100)) && (pub_r001534_19_2 <= 100));
  __CPROVER_assume((sec_r001534_0_1 >= 0) && (sec_r001534_0_1 <= 255));
  __CPROVER_assume((sec_r001534_0_2 >= 0) && (sec_r001534_0_2 <= 255));
  __CPROVER_assume((sec_r001534_1_1 >= 0) && (sec_r001534_1_1 <= 255));
  __CPROVER_assume((sec_r001534_1_2 >= 0) && (sec_r001534_1_2 <= 255));
  __CPROVER_assume((sec_r001534_2_1 >= 0) && (sec_r001534_2_1 <= 255));
  __CPROVER_assume((sec_r001534_2_2 >= 0) && (sec_r001534_2_2 <= 255));
  __CPROVER_assume((sec_r001534_3_1 >= 0) && (sec_r001534_3_1 <= 255));
  __CPROVER_assume((sec_r001534_3_2 >= 0) && (sec_r001534_3_2 <= 255));
  __CPROVER_assume((sec_r001534_4_1 >= 0) && (sec_r001534_4_1 <= 255));
  __CPROVER_assume((sec_r001534_4_2 >= 0) && (sec_r001534_4_2 <= 255));
  __CPROVER_assume((sec_r001534_5_1 >= 0) && (sec_r001534_5_1 <= 255));
  __CPROVER_assume((sec_r001534_5_2 >= 0) && (sec_r001534_5_2 <= 255));
  __CPROVER_assume((sec_r001534_6_1 >= 0) && (sec_r001534_6_1 <= 255));
  __CPROVER_assume((sec_r001534_6_2 >= 0) && (sec_r001534_6_2 <= 255));
  __CPROVER_assume((sec_r001534_7_1 >= 0) && (sec_r001534_7_1 <= 255));
  __CPROVER_assume((sec_r001534_7_2 >= 0) && (sec_r001534_7_2 <= 255));
  __CPROVER_assume((sec_r001534_8_1 >= 0) && (sec_r001534_8_1 <= 255));
  __CPROVER_assume((sec_r001534_8_2 >= 0) && (sec_r001534_8_2 <= 255));
  __CPROVER_assume((sec_r001534_9_1 >= 0) && (sec_r001534_9_1 <= 255));
  __CPROVER_assume((sec_r001534_9_2 >= 0) && (sec_r001534_9_2 <= 255));
  __CPROVER_assume((sec_r001534_10_1 >= 0) && (sec_r001534_10_1 <= 255));
  __CPROVER_assume((sec_r001534_10_2 >= 0) && (sec_r001534_10_2 <= 255));
  __CPROVER_assume((sec_r001534_11_1 >= 0) && (sec_r001534_11_1 <= 255));
  __CPROVER_assume((sec_r001534_11_2 >= 0) && (sec_r001534_11_2 <= 255));
  __CPROVER_assume((sec_r001534_12_1 >= 0) && (sec_r001534_12_1 <= 255));
  __CPROVER_assume((sec_r001534_12_2 >= 0) && (sec_r001534_12_2 <= 255));
  __CPROVER_assume((sec_r001534_13_1 >= 0) && (sec_r001534_13_1 <= 255));
  __CPROVER_assume((sec_r001534_13_2 >= 0) && (sec_r001534_13_2 <= 255));
  __CPROVER_assume((sec_r001534_14_1 >= 0) && (sec_r001534_14_1 <= 255));
  __CPROVER_assume((sec_r001534_14_2 >= 0) && (sec_r001534_14_2 <= 255));
  __CPROVER_assume((sec_r001534_15_1 >= 0) && (sec_r001534_15_1 <= 255));
  __CPROVER_assume((sec_r001534_15_2 >= 0) && (sec_r001534_15_2 <= 255));
  __CPROVER_assume((sec_r001534_16_1 >= 0) && (sec_r001534_16_1 <= 255));
  __CPROVER_assume((sec_r001534_16_2 >= 0) && (sec_r001534_16_2 <= 255));
  __CPROVER_assume((sec_r001534_17_1 >= 0) && (sec_r001534_17_1 <= 255));
  __CPROVER_assume((sec_r001534_17_2 >= 0) && (sec_r001534_17_2 <= 255));
  __CPROVER_assume((sec_r001534_18_1 >= 0) && (sec_r001534_18_1 <= 255));
  __CPROVER_assume((sec_r001534_18_2 >= 0) && (sec_r001534_18_2 <= 255));
  __CPROVER_assume((sec_r001534_19_1 >= 0) && (sec_r001534_19_1 <= 255));
  __CPROVER_assume((sec_r001534_19_2 >= 0) && (sec_r001534_19_2 <= 255));
  __CPROVER_assume((sec_r001534_20_1 >= 0) && (sec_r001534_20_1 <= 255));
  __CPROVER_assume((sec_r001534_20_2 >= 0) && (sec_r001534_20_2 <= 255));
  __CPROVER_assume((sec_r001534_21_1 >= 0) && (sec_r001534_21_1 <= 255));
  __CPROVER_assume((sec_r001534_21_2 >= 0) && (sec_r001534_21_2 <= 255));
  struct AudioFrame_R001534_3413_0 st_var_0_1 = {0};
  struct AudioFrame_R001534_3413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001534_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001534_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001534_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001534_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001534_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001534_0_2 + 7) & 15;
  struct MatrixBlock_R001534_3413_1 st_var_1_1 = {0};
  struct MatrixBlock_R001534_3413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001534_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001534_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001534_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001534_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001534_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001534_0_2 + 9) & 15;
  struct CipherContext_R001534_3413_2 st_var_2_1 = {0};
  struct CipherContext_R001534_3413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001534_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001534_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001534_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001534_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001534_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001534_0_2 + 11) & 15;
  struct StreamBuffer_R001534_3413_3 st_var_3_1 = {0};
  struct StreamBuffer_R001534_3413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001534_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001534_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001534_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001534_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001534_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001534_0_2 + 13) & 15;
  union TelemetryField_R001534_3413_0 u_var_1;
  union TelemetryField_R001534_3413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001534_3413_0(sec_r001534_0_1, sec_r001534_1_1, pub_r001534_2_1);
  int helper_flow_0_2 = fn_R001534_3413_0(sec_r001534_0_2, sec_r001534_1_2, pub_r001534_2_2);
  fn_R001534_3413_0_2(sec_r001534_0_1, sec_r001534_1_1, pub_r001534_2_1, sec_r001534_0_2, sec_r001534_1_2, pub_r001534_2_2);
  int helper_flow_1_1 = fn_R001534_3413_1(sec_r001534_1_1, sec_r001534_2_1);
  int helper_flow_1_2 = fn_R001534_3413_1(sec_r001534_1_2, sec_r001534_2_2);
  fn_R001534_3413_1_2(sec_r001534_1_1, sec_r001534_2_1, sec_r001534_1_2, sec_r001534_2_2);
  int helper_flow_2_1 = fn_R001534_3413_2(sec_r001534_2_1, sec_r001534_3_1);
  int helper_flow_2_2 = fn_R001534_3413_2(sec_r001534_2_2, sec_r001534_3_2);
  fn_R001534_3413_2_2(sec_r001534_2_1, sec_r001534_3_1, sec_r001534_2_2, sec_r001534_3_2);
  int helper_flow_3_1 = fn_R001534_3413_3(sec_r001534_3_1, pub_r001534_4_1, pub_r001534_5_1);
  int helper_flow_3_2 = fn_R001534_3413_3(sec_r001534_3_2, pub_r001534_4_2, pub_r001534_5_2);
  fn_R001534_3413_3_2(sec_r001534_3_1, pub_r001534_4_1, pub_r001534_5_1, sec_r001534_3_2, pub_r001534_4_2, pub_r001534_5_2);
  int helper_flow_4_1 = fn_R001534_3413_4(sec_r001534_4_1, sec_r001534_5_1);
  int helper_flow_4_2 = fn_R001534_3413_4(sec_r001534_4_2, sec_r001534_5_2);
  fn_R001534_3413_4_2(sec_r001534_4_1, sec_r001534_5_1, sec_r001534_4_2, sec_r001534_5_2);
  int stage_v_0_1 = ((pub_r001534_2_1 * 2) + 6) & 63;
  int stage_v_0_2 = ((pub_r001534_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001534_11_1 * 3) + pub_r001534_15_1) + 30) & 127;
  int stage_v_1_2 = (((sec_r001534_11_2 * 3) + pub_r001534_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = (((sec_r001534_8_1 * 3) + pub_r001534_7_1) + 10) & 127;
  int stage_v_2_2 = (((sec_r001534_8_2 * 3) + pub_r001534_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = ((pub_r001534_10_1 * 2) + 11) & 63;
  int stage_v_3_2 = ((pub_r001534_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001534_10_1 * 2) + 43) & 63;
  int stage_v_4_2 = ((pub_r001534_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((helper_flow_2_1 * 3) + pub_r001534_16_1) + 3) & 127;
  int stage_v_5_2 = (((helper_flow_2_2 * 3) + pub_r001534_16_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = (((sec_r001534_6_1 * 3) + pub_r001534_2_1) + 38) & 127;
  int stage_v_6_2 = (((sec_r001534_6_2 * 3) + pub_r001534_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = ((pub_r001534_7_1 * 2) + 49) & 63;
  int stage_v_7_2 = ((pub_r001534_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001534_12_1 * 3) + pub_r001534_1_1) + 14) & 127;
  int stage_v_8_2 = (((sec_r001534_12_2 * 3) + pub_r001534_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = ((pub_r001534_16_1 * 2) + 48) & 63;
  int stage_v_9_2 = ((pub_r001534_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((helper_flow_3_1 * 3) + pub_r001534_14_1) + 6) & 127;
  int stage_v_10_2 = (((helper_flow_3_2 * 3) + pub_r001534_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = (((sec_r001534_14_1 * 3) + pub_r001534_11_1) + 24) & 127;
  int stage_v_11_2 = (((sec_r001534_14_2 * 3) + pub_r001534_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = ((pub_r001534_16_1 * 2) + 29) & 63;
  int stage_v_12_2 = ((pub_r001534_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((sec_r001534_8_1 * 3) + pub_r001534_8_1) + 43) & 127;
  int stage_v_13_2 = (((sec_r001534_8_2 * 3) + pub_r001534_8_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = ((pub_r001534_15_1 * 2) + 27) & 63;
  int stage_v_14_2 = ((pub_r001534_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001534_16_1 * 2) + 10) & 63;
  int stage_v_15_2 = ((pub_r001534_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001534_12_1 * 2) + 30) & 63;
  int stage_v_16_2 = ((pub_r001534_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001534_18_1 * 2) + 30) & 63;
  int stage_v_17_2 = ((pub_r001534_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001534_14_1 * 2) + 22) & 63;
  int stage_v_18_2 = ((pub_r001534_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001534_7_1 * 3) + pub_r001534_3_1) + 31) & 127;
  int stage_v_19_2 = (((sec_r001534_7_2 * 3) + pub_r001534_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001534_18_1 * 2) + 33) & 63;
  int stage_v_20_2 = ((pub_r001534_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((sec_r001534_8_1 * 3) + pub_r001534_18_1) + 27) & 127;
  int stage_v_21_2 = (((sec_r001534_8_2 * 3) + pub_r001534_18_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = (((sec_r001534_20_1 * 3) + pub_r001534_14_1) + 27) & 127;
  int stage_v_22_2 = (((sec_r001534_20_2 * 3) + pub_r001534_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = ((pub_r001534_1_1 * 2) + 40) & 63;
  int stage_v_23_2 = ((pub_r001534_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((sec_r001534_8_1 * 3) + pub_r001534_12_1) + 14) & 127;
  int stage_v_24_2 = (((sec_r001534_8_2 * 3) + pub_r001534_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((helper_flow_0_1 * 3) + pub_r001534_3_1) + 40) & 127;
  int stage_v_25_2 = (((helper_flow_0_2 * 3) + pub_r001534_3_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((sec_r001534_20_1 * 3) + pub_r001534_8_1) + 39) & 127;
  int stage_v_26_2 = (((sec_r001534_20_2 * 3) + pub_r001534_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = ((pub_r001534_10_1 * 2) + 48) & 63;
  int stage_v_27_2 = ((pub_r001534_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((stage_v_24_1 * 3) + pub_r001534_10_1) + 35) & 127;
  int stage_v_28_2 = (((stage_v_24_2 * 3) + pub_r001534_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((stage_v_11_1 * 3) + pub_r001534_3_1) + 8) & 127;
  int stage_v_29_2 = (((stage_v_11_2 * 3) + pub_r001534_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = ((pub_r001534_12_1 * 2) + 32) & 63;
  int stage_v_30_2 = ((pub_r001534_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001534_1_1 * 2) + 45) & 63;
  int stage_v_31_2 = ((pub_r001534_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((helper_flow_0_1 * 3) + pub_r001534_0_1) + 18) & 127;
  int stage_v_32_2 = (((helper_flow_0_2 * 3) + pub_r001534_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = (((sec_r001534_13_1 * 3) + pub_r001534_13_1) + 6) & 127;
  int stage_v_33_2 = (((sec_r001534_13_2 * 3) + pub_r001534_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = ((pub_r001534_18_1 * 2) + 8) & 63;
  int stage_v_34_2 = ((pub_r001534_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001534_10_1 * 2) + 40) & 63;
  int stage_v_35_2 = ((pub_r001534_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001534_6_1 * 2) + 5) & 63;
  int stage_v_36_2 = ((pub_r001534_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((stage_v_22_1 * 3) + pub_r001534_15_1) + 38) & 127;
  int stage_v_37_2 = (((stage_v_22_2 * 3) + pub_r001534_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = (((stage_v_24_1 * 3) + pub_r001534_18_1) + 30) & 127;
  int stage_v_38_2 = (((stage_v_24_2 * 3) + pub_r001534_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = (((sec_r001534_18_1 * 3) + pub_r001534_3_1) + 45) & 127;
  int stage_v_39_2 = (((sec_r001534_18_2 * 3) + pub_r001534_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = (((sec_r001534_21_1 * 3) + pub_r001534_13_1) + 37) & 127;
  int stage_v_40_2 = (((sec_r001534_21_2 * 3) + pub_r001534_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((sec_r001534_21_1 * 3) + pub_r001534_5_1) + 14) & 127;
  int stage_v_41_2 = (((sec_r001534_21_2 * 3) + pub_r001534_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = ((pub_r001534_0_1 * 2) + 18) & 63;
  int stage_v_42_2 = ((pub_r001534_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001534_6_1 * 2) + 40) & 63;
  int stage_v_43_2 = ((pub_r001534_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001534_15_1 * 2) + 16) & 63;
  int stage_v_44_2 = ((pub_r001534_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((stage_v_39_1 * 3) + pub_r001534_1_1) + 34) & 127;
  int stage_v_45_2 = (((stage_v_39_2 * 3) + pub_r001534_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((stage_v_39_1 * 3) + pub_r001534_7_1) + 4) & 127;
  int stage_v_46_2 = (((stage_v_39_2 * 3) + pub_r001534_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = (((stage_v_25_1 * 3) + pub_r001534_14_1) + 8) & 127;
  int stage_v_47_2 = (((stage_v_25_2 * 3) + pub_r001534_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = ((pub_r001534_16_1 * 2) + 45) & 63;
  int stage_v_48_2 = ((pub_r001534_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001534_12_1 * 2) + 41) & 63;
  int stage_v_49_2 = ((pub_r001534_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001534_2_1 * 2) + 14) & 63;
  int stage_v_50_2 = ((pub_r001534_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001534_5_1 * 2) + 45) & 63;
  int stage_v_51_2 = ((pub_r001534_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((sec_r001534_8_1 * 3) + pub_r001534_12_1) + 19) & 127;
  int stage_v_52_2 = (((sec_r001534_8_2 * 3) + pub_r001534_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001534_1_1 * 2) + 42) & 63;
  int stage_v_53_2 = ((pub_r001534_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001534_2_1 * 2) + 12) & 63;
  int stage_v_54_2 = ((pub_r001534_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001534_4_1 * 2) + 30) & 63;
  int stage_v_55_2 = ((pub_r001534_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((sec_r001534_11_1 * 3) + pub_r001534_5_1) + 18) & 127;
  int stage_v_56_2 = (((sec_r001534_11_2 * 3) + pub_r001534_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((stage_v_19_1 * 3) + pub_r001534_11_1) + 31) & 127;
  int stage_v_57_2 = (((stage_v_19_2 * 3) + pub_r001534_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = ((pub_r001534_14_1 * 2) + 43) & 63;
  int stage_v_58_2 = ((pub_r001534_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001534_18_1 * 2) + 46) & 63;
  int stage_v_59_2 = ((pub_r001534_18_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((sec_r001534_21_1 * 3) + pub_r001534_10_1) + 13) & 127;
  int stage_v_60_2 = (((sec_r001534_21_2 * 3) + pub_r001534_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((helper_flow_4_1 * 3) + pub_r001534_7_1) + 30) & 127;
  int stage_v_61_2 = (((helper_flow_4_2 * 3) + pub_r001534_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001534_15_1 * 2) + 30) & 63;
  int stage_v_62_2 = ((pub_r001534_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001534_0_1 * 2) + 21) & 63;
  int stage_v_63_2 = ((pub_r001534_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((stage_v_37_1 * 3) + pub_r001534_5_1) + 16) & 127;
  int stage_v_64_2 = (((stage_v_37_2 * 3) + pub_r001534_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = ((pub_r001534_5_1 * 2) + 30) & 63;
  int stage_v_65_2 = ((pub_r001534_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((stage_v_45_1 * 3) + pub_r001534_14_1) + 32) & 127;
  int stage_v_66_2 = (((stage_v_45_2 * 3) + pub_r001534_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((helper_flow_3_1 * 3) + pub_r001534_3_1) + 22) & 127;
  int stage_v_67_2 = (((helper_flow_3_2 * 3) + pub_r001534_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((stage_v_6_1 * 3) + pub_r001534_8_1) + 35) & 127;
  int stage_v_68_2 = (((stage_v_6_2 * 3) + pub_r001534_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = (((sec_r001534_7_1 * 3) + pub_r001534_3_1) + 5) & 127;
  int stage_v_69_2 = (((sec_r001534_7_2 * 3) + pub_r001534_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = ((pub_r001534_16_1 * 2) + 46) & 63;
  int stage_v_70_2 = ((pub_r001534_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = (((stage_v_37_1 * 3) + pub_r001534_8_1) + 32) & 127;
  int stage_v_71_2 = (((stage_v_37_2 * 3) + pub_r001534_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = (((sec_r001534_10_1 * 3) + pub_r001534_18_1) + 21) & 127;
  int stage_v_72_2 = (((sec_r001534_10_2 * 3) + pub_r001534_18_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001534_12_1 * 2) + 32) & 63;
  int stage_v_73_2 = ((pub_r001534_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (((sec_r001534_17_1 * 3) + pub_r001534_14_1) + 40) & 127;
  int stage_v_74_2 = (((sec_r001534_17_2 * 3) + pub_r001534_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((stage_v_37_1 * 3) + pub_r001534_19_1) + 22) & 127;
  int stage_v_75_2 = (((stage_v_37_2 * 3) + pub_r001534_19_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((stage_v_64_1 * 3) + pub_r001534_17_1) + 8) & 127;
  int stage_v_76_2 = (((stage_v_64_2 * 3) + pub_r001534_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = (((stage_v_76_1 * 3) + pub_r001534_13_1) + 29) & 127;
  int stage_v_77_2 = (((stage_v_76_2 * 3) + pub_r001534_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = (((stage_v_22_1 * 3) + pub_r001534_13_1) + 32) & 127;
  int stage_v_78_2 = (((stage_v_22_2 * 3) + pub_r001534_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = (((helper_flow_3_1 * 3) + pub_r001534_4_1) + 43) & 127;
  int stage_v_79_2 = (((helper_flow_3_2 * 3) + pub_r001534_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001534_5_1 * 2) + 19) & 63;
  int stage_v_80_2 = ((pub_r001534_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((sec_r001534_10_1 * 3) + pub_r001534_17_1) + 29) & 127;
  int stage_v_81_2 = (((sec_r001534_10_2 * 3) + pub_r001534_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = ((pub_r001534_6_1 * 2) + 48) & 63;
  int stage_v_82_2 = ((pub_r001534_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((sec_r001534_19_1 * 3) + pub_r001534_9_1) + 15) & 127;
  int stage_v_83_2 = (((sec_r001534_19_2 * 3) + pub_r001534_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = (((stage_v_74_1 * 3) + pub_r001534_16_1) + 17) & 127;
  int stage_v_84_2 = (((stage_v_74_2 * 3) + pub_r001534_16_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001534_4_1 * 2) + 10) & 63;
  int stage_v_85_2 = ((pub_r001534_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((stage_v_1_1 * 3) + pub_r001534_3_1) + 10) & 127;
  int stage_v_86_2 = (((stage_v_1_2 * 3) + pub_r001534_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = (((stage_v_2_1 * 3) + pub_r001534_2_1) + 5) & 127;
  int stage_v_87_2 = (((stage_v_2_2 * 3) + pub_r001534_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = ((pub_r001534_11_1 * 2) + 38) & 63;
  int stage_v_88_2 = ((pub_r001534_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001534_3_1 * 2) + 39) & 63;
  int stage_v_89_2 = ((pub_r001534_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001534_5_1 * 2) + 15) & 63;
  int stage_v_90_2 = ((pub_r001534_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (((stage_v_83_1 * 3) + pub_r001534_17_1) + 6) & 127;
  int stage_v_91_2 = (((stage_v_83_2 * 3) + pub_r001534_17_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = ((pub_r001534_15_1 * 2) + 43) & 63;
  int stage_v_92_2 = ((pub_r001534_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001534_7_1 * 2) + 40) & 63;
  int stage_v_93_2 = ((pub_r001534_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((stage_v_61_1 * 3) + pub_r001534_18_1) + 35) & 127;
  int stage_v_94_2 = (((stage_v_61_2 * 3) + pub_r001534_18_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((stage_v_71_1 * 3) + pub_r001534_16_1) + 5) & 127;
  int stage_v_95_2 = (((stage_v_71_2 * 3) + pub_r001534_16_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = (((helper_flow_3_1 * 3) + pub_r001534_14_1) + 26) & 127;
  int stage_v_96_2 = (((helper_flow_3_2 * 3) + pub_r001534_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001534_16_1 * 2) + 48) & 63;
  int stage_v_97_2 = ((pub_r001534_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001534_15_1 * 2) + 50) & 63;
  int stage_v_98_2 = ((pub_r001534_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((stage_v_56_1 * 3) + pub_r001534_19_1) + 40) & 127;
  int stage_v_99_2 = (((stage_v_56_2 * 3) + pub_r001534_19_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001534_18_1 * 2) + 45) & 63;
  int stage_v_100_2 = ((pub_r001534_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_21_1 * 3) + pub_r001534_12_1) + 28) & 127;
  int stage_v_101_2 = (((stage_v_21_2 * 3) + pub_r001534_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001534_3_1 * 2) + 35) & 63;
  int stage_v_102_2 = ((pub_r001534_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001534_8_1 * 2) + 28) & 63;
  int stage_v_103_2 = ((pub_r001534_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((sec_r001534_11_1 * 3) + pub_r001534_16_1) + 22) & 127;
  int stage_v_104_2 = (((sec_r001534_11_2 * 3) + pub_r001534_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = (((sec_r001534_3_1 * 3) + pub_r001534_2_1) + 18) & 127;
  int stage_v_105_2 = (((sec_r001534_3_2 * 3) + pub_r001534_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = ((pub_r001534_3_1 * 2) + 36) & 63;
  int stage_v_106_2 = ((pub_r001534_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((stage_v_69_1 * 3) + pub_r001534_9_1) + 17) & 127;
  int stage_v_107_2 = (((stage_v_69_2 * 3) + pub_r001534_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = (((stage_v_96_1 * 3) + pub_r001534_7_1) + 28) & 127;
  int stage_v_108_2 = (((stage_v_96_2 * 3) + pub_r001534_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((stage_v_19_1 * 3) + pub_r001534_14_1) + 8) & 127;
  int stage_v_109_2 = (((stage_v_19_2 * 3) + pub_r001534_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = ((pub_r001534_12_1 * 2) + 43) & 63;
  int stage_v_110_2 = ((pub_r001534_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001534_0_1 * 2) + 9) & 63;
  int stage_v_111_2 = ((pub_r001534_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001534_16_1 * 2) + 15) & 63;
  int stage_v_112_2 = ((pub_r001534_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_75_1 * 3) + pub_r001534_17_1) + 38) & 127;
  int stage_v_113_2 = (((stage_v_75_2 * 3) + pub_r001534_17_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001534_7_1 * 2) + 28) & 63;
  int stage_v_114_2 = ((pub_r001534_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (((sec_r001534_13_1 * 3) + pub_r001534_9_1) + 4) & 127;
  int stage_v_115_2 = (((sec_r001534_13_2 * 3) + pub_r001534_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = ((pub_r001534_12_1 * 2) + 5) & 63;
  int stage_v_116_2 = ((pub_r001534_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((stage_v_64_1 * 3) + pub_r001534_16_1) + 10) & 127;
  int stage_v_117_2 = (((stage_v_64_2 * 3) + pub_r001534_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = ((pub_r001534_14_1 * 2) + 42) & 63;
  int stage_v_118_2 = ((pub_r001534_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001534_8_1 * 2) + 32) & 63;
  int stage_v_119_2 = ((pub_r001534_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((sec_r001534_10_1 * 3) + pub_r001534_4_1) + 22) & 127;
  int stage_v_120_2 = (((sec_r001534_10_2 * 3) + pub_r001534_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = (((stage_v_25_1 * 3) + pub_r001534_9_1) + 41) & 127;
  int stage_v_121_2 = (((stage_v_25_2 * 3) + pub_r001534_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = ((pub_r001534_8_1 * 2) + 37) & 63;
  int stage_v_122_2 = ((pub_r001534_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001534_17_1 * 2) + 26) & 63;
  int stage_v_123_2 = ((pub_r001534_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001534_13_1 * 2) + 40) & 63;
  int stage_v_124_2 = ((pub_r001534_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((sec_r001534_10_1 * 3) + pub_r001534_9_1) + 17) & 127;
  int stage_v_125_2 = (((sec_r001534_10_2 * 3) + pub_r001534_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((stage_v_61_1 * 3) + pub_r001534_8_1) + 15) & 127;
  int stage_v_126_2 = (((stage_v_61_2 * 3) + pub_r001534_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((stage_v_96_1 * 3) + pub_r001534_17_1) + 8) & 127;
  int stage_v_127_2 = (((stage_v_96_2 * 3) + pub_r001534_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((stage_v_57_1 * 3) + pub_r001534_8_1) + 10) & 127;
  int stage_v_128_2 = (((stage_v_57_2 * 3) + pub_r001534_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((stage_v_69_1 * 3) + pub_r001534_0_1) + 16) & 127;
  int stage_v_129_2 = (((stage_v_69_2 * 3) + pub_r001534_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((stage_v_108_1 * 3) + pub_r001534_12_1) + 4) & 127;
  int stage_v_130_2 = (((stage_v_108_2 * 3) + pub_r001534_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001534_1_1 * 2) + 32) & 63;
  int stage_v_131_2 = ((pub_r001534_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((sec_r001534_2_1 * 3) + pub_r001534_16_1) + 45) & 127;
  int stage_v_132_2 = (((sec_r001534_2_2 * 3) + pub_r001534_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = ((pub_r001534_19_1 * 2) + 18) & 63;
  int stage_v_133_2 = ((pub_r001534_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (((sec_r001534_7_1 * 3) + pub_r001534_11_1) + 30) & 127;
  int stage_v_134_2 = (((sec_r001534_7_2 * 3) + pub_r001534_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((stage_v_128_1 * 3) + pub_r001534_5_1) + 20) & 127;
  int stage_v_135_2 = (((stage_v_128_2 * 3) + pub_r001534_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = ((pub_r001534_2_1 * 2) + 27) & 63;
  int stage_v_136_2 = ((pub_r001534_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (((sec_r001534_1_1 * 3) + pub_r001534_1_1) + 11) & 127;
  int stage_v_137_2 = (((sec_r001534_1_2 * 3) + pub_r001534_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = ((pub_r001534_6_1 * 2) + 41) & 63;
  int stage_v_138_2 = ((pub_r001534_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001534_0_1 * 2) + 21) & 63;
  int stage_v_139_2 = ((pub_r001534_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001534_1_1 * 2) + 19) & 63;
  int stage_v_140_2 = ((pub_r001534_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001534_5_1 * 2) + 17) & 63;
  int stage_v_141_2 = ((pub_r001534_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001534_0_1 * 2) + 32) & 63;
  int stage_v_142_2 = ((pub_r001534_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((sec_r001534_14_1 * 3) + pub_r001534_5_1) + 42) & 127;
  int stage_v_143_2 = (((sec_r001534_14_2 * 3) + pub_r001534_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = (((stage_v_74_1 * 3) + pub_r001534_3_1) + 18) & 127;
  int stage_v_144_2 = (((stage_v_74_2 * 3) + pub_r001534_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((stage_v_74_1 * 3) + pub_r001534_15_1) + 38) & 127;
  int stage_v_145_2 = (((stage_v_74_2 * 3) + pub_r001534_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = (((stage_v_66_1 * 3) + pub_r001534_17_1) + 44) & 127;
  int stage_v_146_2 = (((stage_v_66_2 * 3) + pub_r001534_17_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_146_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_146_2 * 2)) & 255;
  int stage_v_147_1 = ((pub_r001534_5_1 * 2) + 24) & 63;
  int stage_v_147_2 = ((pub_r001534_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001534_6_1 * 2) + 26) & 63;
  int stage_v_148_2 = ((pub_r001534_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((stage_v_127_1 * 3) + pub_r001534_17_1) + 4) & 127;
  int stage_v_149_2 = (((stage_v_127_2 * 3) + pub_r001534_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_83_1 * 3) + pub_r001534_1_1) + 23) & 127;
  int stage_v_150_2 = (((stage_v_83_2 * 3) + pub_r001534_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((stage_v_144_1 * 3) + pub_r001534_15_1) + 38) & 127;
  int stage_v_151_2 = (((stage_v_144_2 * 3) + pub_r001534_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = ((pub_r001534_0_1 * 2) + 9) & 63;
  int stage_v_152_2 = ((pub_r001534_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_94_1 * 3) + pub_r001534_12_1) + 9) & 127;
  int stage_v_153_2 = (((stage_v_94_2 * 3) + pub_r001534_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = (((stage_v_47_1 * 3) + pub_r001534_18_1) + 26) & 127;
  int stage_v_154_2 = (((stage_v_47_2 * 3) + pub_r001534_18_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = (((stage_v_46_1 * 3) + pub_r001534_10_1) + 25) & 127;
  int stage_v_155_2 = (((stage_v_46_2 * 3) + pub_r001534_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((stage_v_108_1 * 3) + pub_r001534_16_1) + 23) & 127;
  int stage_v_156_2 = (((stage_v_108_2 * 3) + pub_r001534_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = ((pub_r001534_7_1 * 2) + 48) & 63;
  int stage_v_157_2 = ((pub_r001534_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001534_16_1 * 2) + 40) & 63;
  int stage_v_158_2 = ((pub_r001534_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001534_17_1 * 2) + 48) & 63;
  int stage_v_159_2 = ((pub_r001534_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((helper_flow_3_1 * 3) + pub_r001534_4_1) + 43) & 127;
  int stage_v_160_2 = (((helper_flow_3_2 * 3) + pub_r001534_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = ((pub_r001534_17_1 * 2) + 11) & 63;
  int stage_v_161_2 = ((pub_r001534_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((stage_v_160_1 * 3) + pub_r001534_12_1) + 8) & 127;
  int stage_v_162_2 = (((stage_v_160_2 * 3) + pub_r001534_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = (((stage_v_64_1 * 3) + pub_r001534_11_1) + 24) & 127;
  int stage_v_163_2 = (((stage_v_64_2 * 3) + pub_r001534_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = (((stage_v_60_1 * 3) + pub_r001534_2_1) + 10) & 127;
  int stage_v_164_2 = (((stage_v_60_2 * 3) + pub_r001534_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = ((pub_r001534_19_1 * 2) + 6) & 63;
  int stage_v_165_2 = ((pub_r001534_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001534_6_1 * 2) + 39) & 63;
  int stage_v_166_2 = ((pub_r001534_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((sec_r001534_2_1 * 3) + pub_r001534_15_1) + 4) & 127;
  int stage_v_167_2 = (((sec_r001534_2_2 * 3) + pub_r001534_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001534_14_1 * 2) + 50) & 63;
  int stage_v_168_2 = ((pub_r001534_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_145_1 * 3) + pub_r001534_4_1) + 22) & 127;
  int stage_v_169_2 = (((stage_v_145_2 * 3) + pub_r001534_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((stage_v_162_1 * 3) + pub_r001534_15_1) + 22) & 127;
  int stage_v_170_2 = (((stage_v_162_2 * 3) + pub_r001534_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001534_10_1 * 2) + 50) & 63;
  int stage_v_171_2 = ((pub_r001534_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001534_1_1 * 2) + 41) & 63;
  int stage_v_172_2 = ((pub_r001534_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001534_3_1 * 2) + 43) & 63;
  int stage_v_173_2 = ((pub_r001534_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001534_13_1 * 2) + 13) & 63;
  int stage_v_174_2 = ((pub_r001534_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_126_1 * 3) + pub_r001534_10_1) + 12) & 127;
  int stage_v_175_2 = (((stage_v_126_2 * 3) + pub_r001534_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = ((pub_r001534_3_1 * 2) + 20) & 63;
  int stage_v_176_2 = ((pub_r001534_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((stage_v_81_1 * 3) + pub_r001534_4_1) + 35) & 127;
  int stage_v_177_2 = (((stage_v_81_2 * 3) + pub_r001534_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = ((pub_r001534_4_1 * 2) + 5) & 63;
  int stage_v_178_2 = ((pub_r001534_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (((stage_v_71_1 * 3) + pub_r001534_8_1) + 9) & 127;
  int stage_v_179_2 = (((stage_v_71_2 * 3) + pub_r001534_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = ((pub_r001534_1_1 * 2) + 21) & 63;
  int stage_v_180_2 = ((pub_r001534_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001534_4_1 * 2) + 35) & 63;
  int stage_v_181_2 = ((pub_r001534_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((helper_flow_4_1 * 3) + pub_r001534_19_1) + 25) & 127;
  int stage_v_182_2 = (((helper_flow_4_2 * 3) + pub_r001534_19_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = (((helper_flow_2_1 * 3) + pub_r001534_16_1) + 8) & 127;
  int stage_v_183_2 = (((helper_flow_2_2 * 3) + pub_r001534_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((stage_v_115_1 * 3) + pub_r001534_3_1) + 30) & 127;
  int stage_v_184_2 = (((stage_v_115_2 * 3) + pub_r001534_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((stage_v_169_1 * 3) + pub_r001534_5_1) + 39) & 127;
  int stage_v_185_2 = (((stage_v_169_2 * 3) + pub_r001534_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = (((stage_v_66_1 * 3) + pub_r001534_12_1) + 25) & 127;
  int stage_v_186_2 = (((stage_v_66_2 * 3) + pub_r001534_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = (((stage_v_61_1 * 3) + pub_r001534_13_1) + 33) & 127;
  int stage_v_187_2 = (((stage_v_61_2 * 3) + pub_r001534_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = (((sec_r001534_6_1 * 3) + pub_r001534_7_1) + 44) & 127;
  int stage_v_188_2 = (((sec_r001534_6_2 * 3) + pub_r001534_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001534_14_1 * 2) + 14) & 63;
  int stage_v_189_2 = ((pub_r001534_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_127_1 * 3) + pub_r001534_15_1) + 37) & 127;
  int stage_v_190_2 = (((stage_v_127_2 * 3) + pub_r001534_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = ((pub_r001534_13_1 * 2) + 43) & 63;
  int stage_v_191_2 = ((pub_r001534_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001534_2_1 * 2) + 29) & 63;
  int stage_v_192_2 = ((pub_r001534_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001534_3_1 * 2) + 17) & 63;
  int stage_v_193_2 = ((pub_r001534_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001534_13_1 * 2) + 46) & 63;
  int stage_v_194_2 = ((pub_r001534_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001534_15_1 * 2) + 36) & 63;
  int stage_v_195_2 = ((pub_r001534_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_26_1 * 3) + pub_r001534_0_1) + 11) & 127;
  int stage_v_196_2 = (((stage_v_26_2 * 3) + pub_r001534_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001534_6_1 * 2) + 48) & 63;
  int stage_v_197_2 = ((pub_r001534_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_78_1 * 3) + pub_r001534_13_1) + 29) & 127;
  int stage_v_198_2 = (((stage_v_78_2 * 3) + pub_r001534_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001534_7_1 * 2) + 15) & 63;
  int stage_v_199_2 = ((pub_r001534_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001534_3_1 * 2) + 18) & 63;
  int stage_v_200_2 = ((pub_r001534_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((stage_v_74_1 * 3) + pub_r001534_19_1) + 38) & 127;
  int stage_v_201_2 = (((stage_v_74_2 * 3) + pub_r001534_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = ((pub_r001534_12_1 * 2) + 44) & 63;
  int stage_v_202_2 = ((pub_r001534_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001534_6_1 * 2) + 47) & 63;
  int stage_v_203_2 = ((pub_r001534_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((stage_v_1_1 * 3) + pub_r001534_6_1) + 22) & 127;
  int stage_v_204_2 = (((stage_v_1_2 * 3) + pub_r001534_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((sec_r001534_2_1 * 3) + pub_r001534_8_1) + 30) & 127;
  int stage_v_205_2 = (((sec_r001534_2_2 * 3) + pub_r001534_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((stage_v_81_1 * 3) + pub_r001534_17_1) + 4) & 127;
  int stage_v_206_2 = (((stage_v_81_2 * 3) + pub_r001534_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = (((sec_r001534_15_1 * 3) + pub_r001534_15_1) + 43) & 127;
  int stage_v_207_2 = (((sec_r001534_15_2 * 3) + pub_r001534_15_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001534_7_1 * 2) + 25) & 63;
  int stage_v_208_2 = ((pub_r001534_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_32_1 * 3) + pub_r001534_2_1) + 11) & 127;
  int stage_v_209_2 = (((stage_v_32_2 * 3) + pub_r001534_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = (((stage_v_143_1 * 3) + pub_r001534_13_1) + 40) & 127;
  int stage_v_210_2 = (((stage_v_143_2 * 3) + pub_r001534_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((sec_r001534_5_1 * 3) + pub_r001534_5_1) + 38) & 127;
  int stage_v_211_2 = (((sec_r001534_5_2 * 3) + pub_r001534_5_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((stage_v_177_1 * 3) + pub_r001534_12_1) + 13) & 127;
  int stage_v_212_2 = (((stage_v_177_2 * 3) + pub_r001534_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = ((pub_r001534_14_1 * 2) + 17) & 63;
  int stage_v_213_2 = ((pub_r001534_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001534_0_1 * 2) + 7) & 63;
  int stage_v_214_2 = ((pub_r001534_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((sec_r001534_14_1 * 3) + pub_r001534_17_1) + 44) & 127;
  int stage_v_215_2 = (((sec_r001534_14_2 * 3) + pub_r001534_17_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = ((pub_r001534_19_1 * 2) + 38) & 63;
  int stage_v_216_2 = ((pub_r001534_19_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_125_1 * 3) + pub_r001534_15_1) + 29) & 127;
  int stage_v_217_2 = (((stage_v_125_2 * 3) + pub_r001534_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = ((pub_r001534_18_1 * 2) + 38) & 63;
  int stage_v_218_2 = ((pub_r001534_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((sec_r001534_11_1 * 3) + pub_r001534_13_1) + 44) & 127;
  int stage_v_219_2 = (((sec_r001534_11_2 * 3) + pub_r001534_13_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_52_1 * 3) + pub_r001534_3_1) + 27) & 127;
  int stage_v_220_2 = (((stage_v_52_2 * 3) + pub_r001534_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = ((pub_r001534_8_1 * 2) + 30) & 63;
  int stage_v_221_2 = ((pub_r001534_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_6_1 * 3) + pub_r001534_3_1) + 23) & 127;
  int stage_v_222_2 = (((stage_v_6_2 * 3) + pub_r001534_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001534_14_1 * 2) + 28) & 63;
  int stage_v_223_2 = ((pub_r001534_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = (((stage_v_68_1 * 3) + pub_r001534_4_1) + 19) & 127;
  int stage_v_224_2 = (((stage_v_68_2 * 3) + pub_r001534_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = ((pub_r001534_12_1 * 2) + 38) & 63;
  int stage_v_225_2 = ((pub_r001534_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((stage_v_99_1 * 3) + pub_r001534_13_1) + 45) & 127;
  int stage_v_226_2 = (((stage_v_99_2 * 3) + pub_r001534_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((stage_v_86_1 * 3) + pub_r001534_0_1) + 41) & 127;
  int stage_v_227_2 = (((stage_v_86_2 * 3) + pub_r001534_0_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = (((stage_v_86_1 * 3) + pub_r001534_9_1) + 12) & 127;
  int stage_v_228_2 = (((stage_v_86_2 * 3) + pub_r001534_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = (((stage_v_40_1 * 3) + pub_r001534_6_1) + 24) & 127;
  int stage_v_229_2 = (((stage_v_40_2 * 3) + pub_r001534_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = ((pub_r001534_5_1 * 2) + 14) & 63;
  int stage_v_230_2 = ((pub_r001534_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((sec_r001534_6_1 * 3) + pub_r001534_16_1) + 11) & 127;
  int stage_v_231_2 = (((sec_r001534_6_2 * 3) + pub_r001534_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = (((stage_v_39_1 * 3) + pub_r001534_1_1) + 21) & 127;
  int stage_v_232_2 = (((stage_v_39_2 * 3) + pub_r001534_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = ((pub_r001534_11_1 * 2) + 44) & 63;
  int stage_v_233_2 = ((pub_r001534_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = (((stage_v_29_1 * 3) + pub_r001534_5_1) + 44) & 127;
  int stage_v_234_2 = (((stage_v_29_2 * 3) + pub_r001534_5_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((stage_v_170_1 * 3) + pub_r001534_3_1) + 43) & 127;
  int stage_v_235_2 = (((stage_v_170_2 * 3) + pub_r001534_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = ((pub_r001534_8_1 * 2) + 19) & 63;
  int stage_v_236_2 = ((pub_r001534_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001534_13_1 * 2) + 7) & 63;
  int stage_v_237_2 = ((pub_r001534_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001534_13_1 * 2) + 20) & 63;
  int stage_v_238_2 = ((pub_r001534_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001534_11_1 * 2) + 47) & 63;
  int stage_v_239_2 = ((pub_r001534_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001534_1_1 * 2) + 15) & 63;
  int stage_v_240_2 = ((pub_r001534_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((pub_r001534_8_1 * 2) + 32) & 63;
  int stage_v_241_2 = ((pub_r001534_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((pub_r001534_10_1 * 2) + 19) & 63;
  int stage_v_242_2 = ((pub_r001534_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = (((stage_v_154_1 * 3) + pub_r001534_1_1) + 22) & 127;
  int stage_v_243_2 = (((stage_v_154_2 * 3) + pub_r001534_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_215_1 * 3) + pub_r001534_10_1) + 24) & 127;
  int stage_v_244_2 = (((stage_v_215_2 * 3) + pub_r001534_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((stage_v_60_1 * 3) + pub_r001534_4_1) + 10) & 127;
  int stage_v_245_2 = (((stage_v_60_2 * 3) + pub_r001534_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001534_10_1 * 2) + 36) & 63;
  int stage_v_246_2 = ((pub_r001534_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((stage_v_72_1 * 3) + pub_r001534_12_1) + 44) & 127;
  int stage_v_247_2 = (((stage_v_72_2 * 3) + pub_r001534_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = (((stage_v_22_1 * 3) + pub_r001534_6_1) + 22) & 127;
  int stage_v_248_2 = (((stage_v_22_2 * 3) + pub_r001534_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((stage_v_235_1 * 3) + pub_r001534_8_1) + 24) & 127;
  int stage_v_249_2 = (((stage_v_235_2 * 3) + pub_r001534_8_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_77_1 * 3) + pub_r001534_10_1) + 15) & 127;
  int stage_v_250_2 = (((stage_v_77_2 * 3) + pub_r001534_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((stage_v_210_1 * 3) + pub_r001534_11_1) + 34) & 127;
  int stage_v_251_2 = (((stage_v_210_2 * 3) + pub_r001534_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((stage_v_183_1 * 3) + pub_r001534_5_1) + 22) & 127;
  int stage_v_252_2 = (((stage_v_183_2 * 3) + pub_r001534_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((stage_v_57_1 * 3) + pub_r001534_16_1) + 33) & 127;
  int stage_v_253_2 = (((stage_v_57_2 * 3) + pub_r001534_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = (((stage_v_37_1 * 3) + pub_r001534_5_1) + 5) & 127;
  int stage_v_254_2 = (((stage_v_37_2 * 3) + pub_r001534_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001534_6_1 * 2) + 38) & 63;
  int stage_v_255_2 = ((pub_r001534_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001534_14_1 * 2) + 25) & 63;
  int stage_v_256_2 = ((pub_r001534_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001534_11_1 * 2) + 35) & 63;
  int stage_v_257_2 = ((pub_r001534_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_87_1 * 3) + pub_r001534_16_1) + 19) & 127;
  int stage_v_258_2 = (((stage_v_87_2 * 3) + pub_r001534_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = (((stage_v_183_1 * 3) + pub_r001534_10_1) + 42) & 127;
  int stage_v_259_2 = (((stage_v_183_2 * 3) + pub_r001534_10_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = ((pub_r001534_0_1 * 2) + 28) & 63;
  int stage_v_260_2 = ((pub_r001534_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001534_0_1 * 2) + 27) & 63;
  int stage_v_261_2 = ((pub_r001534_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = (((stage_v_5_1 * 3) + pub_r001534_18_1) + 32) & 127;
  int stage_v_262_2 = (((stage_v_5_2 * 3) + pub_r001534_18_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = (((stage_v_179_1 * 3) + pub_r001534_14_1) + 24) & 127;
  int stage_v_263_2 = (((stage_v_179_2 * 3) + pub_r001534_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = (((stage_v_253_1 * 3) + pub_r001534_0_1) + 3) & 127;
  int stage_v_264_2 = (((stage_v_253_2 * 3) + pub_r001534_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = (((stage_v_46_1 * 3) + pub_r001534_8_1) + 40) & 127;
  int stage_v_265_2 = (((stage_v_46_2 * 3) + pub_r001534_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_56_1 * 3) + pub_r001534_11_1) + 6) & 127;
  int stage_v_266_2 = (((stage_v_56_2 * 3) + pub_r001534_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = ((pub_r001534_15_1 * 2) + 39) & 63;
  int stage_v_267_2 = ((pub_r001534_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = (((stage_v_72_1 * 3) + pub_r001534_15_1) + 11) & 127;
  int stage_v_268_2 = (((stage_v_72_2 * 3) + pub_r001534_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001534_4_1 * 2) + 47) & 63;
  int stage_v_269_2 = ((pub_r001534_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = (((stage_v_262_1 * 3) + pub_r001534_19_1) + 30) & 127;
  int stage_v_270_2 = (((stage_v_262_2 * 3) + pub_r001534_19_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = (((stage_v_248_1 * 3) + pub_r001534_2_1) + 34) & 127;
  int stage_v_271_2 = (((stage_v_248_2 * 3) + pub_r001534_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = (((helper_flow_2_1 * 3) + pub_r001534_8_1) + 8) & 127;
  int stage_v_272_2 = (((helper_flow_2_2 * 3) + pub_r001534_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((stage_v_6_1 * 3) + pub_r001534_3_1) + 41) & 127;
  int stage_v_273_2 = (((stage_v_6_2 * 3) + pub_r001534_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001534_17_1 * 2) + 8) & 63;
  int stage_v_274_2 = ((pub_r001534_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001534_11_1 * 2) + 31) & 63;
  int stage_v_275_2 = ((pub_r001534_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = (((stage_v_69_1 * 3) + pub_r001534_19_1) + 39) & 127;
  int stage_v_276_2 = (((stage_v_69_2 * 3) + pub_r001534_19_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = (((stage_v_77_1 * 3) + pub_r001534_5_1) + 4) & 127;
  int stage_v_277_2 = (((stage_v_77_2 * 3) + pub_r001534_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = ((pub_r001534_2_1 * 2) + 36) & 63;
  int stage_v_278_2 = ((pub_r001534_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = (((stage_v_144_1 * 3) + pub_r001534_6_1) + 43) & 127;
  int stage_v_279_2 = (((stage_v_144_2 * 3) + pub_r001534_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = ((pub_r001534_5_1 * 2) + 39) & 63;
  int stage_v_280_2 = ((pub_r001534_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = (((sec_r001534_12_1 * 3) + pub_r001534_5_1) + 45) & 127;
  int stage_v_281_2 = (((sec_r001534_12_2 * 3) + pub_r001534_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = (((stage_v_167_1 * 3) + pub_r001534_3_1) + 22) & 127;
  int stage_v_282_2 = (((stage_v_167_2 * 3) + pub_r001534_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = ((pub_r001534_14_1 * 2) + 13) & 63;
  int stage_v_283_2 = ((pub_r001534_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001534_15_1 * 2) + 6) & 63;
  int stage_v_284_2 = ((pub_r001534_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = (((stage_v_254_1 * 3) + pub_r001534_18_1) + 43) & 127;
  int stage_v_285_2 = (((stage_v_254_2 * 3) + pub_r001534_18_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = ((pub_r001534_18_1 * 2) + 18) & 63;
  int stage_v_286_2 = ((pub_r001534_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001534_15_1 * 2) + 14) & 63;
  int stage_v_287_2 = ((pub_r001534_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001534_4_1 * 2) + 30) & 63;
  int stage_v_288_2 = ((pub_r001534_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_81_1 * 3) + pub_r001534_9_1) + 17) & 127;
  int stage_v_289_2 = (((stage_v_81_2 * 3) + pub_r001534_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = ((pub_r001534_10_1 * 2) + 20) & 63;
  int stage_v_290_2 = ((pub_r001534_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = (((stage_v_64_1 * 3) + pub_r001534_8_1) + 26) & 127;
  int stage_v_291_2 = (((stage_v_64_2 * 3) + pub_r001534_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001534_6_1 * 2) + 50) & 63;
  int stage_v_292_2 = ((pub_r001534_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = (((stage_v_66_1 * 3) + pub_r001534_11_1) + 19) & 127;
  int stage_v_293_2 = (((stage_v_66_2 * 3) + pub_r001534_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = ((pub_r001534_9_1 * 2) + 37) & 63;
  int stage_v_294_2 = ((pub_r001534_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001534_4_1 * 2) + 15) & 63;
  int stage_v_295_2 = ((pub_r001534_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = (((stage_v_5_1 * 3) + pub_r001534_19_1) + 14) & 127;
  int stage_v_296_2 = (((stage_v_5_2 * 3) + pub_r001534_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001534_13_1 * 2) + 43) & 63;
  int stage_v_297_2 = ((pub_r001534_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001534_18_1 * 2) + 22) & 63;
  int stage_v_298_2 = ((pub_r001534_18_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001534_7_1 * 2) + 42) & 63;
  int stage_v_299_2 = ((pub_r001534_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001534_0_1 * 2) + 24) & 63;
  int stage_v_300_2 = ((pub_r001534_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001534_19_1 * 2) + 20) & 63;
  int stage_v_301_2 = ((pub_r001534_19_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001534_15_1 * 2) + 31) & 63;
  int stage_v_302_2 = ((pub_r001534_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001534_9_1 * 2) + 38) & 63;
  int stage_v_303_2 = ((pub_r001534_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = (((stage_v_270_1 * 3) + pub_r001534_3_1) + 23) & 127;
  int stage_v_304_2 = (((stage_v_270_2 * 3) + pub_r001534_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001534_5_1 * 2) + 35) & 63;
  int stage_v_305_2 = ((pub_r001534_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_270_1 * 3) + pub_r001534_0_1) + 38) & 127;
  int stage_v_306_2 = (((stage_v_270_2 * 3) + pub_r001534_0_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = (((stage_v_99_1 * 3) + pub_r001534_10_1) + 45) & 127;
  int stage_v_307_2 = (((stage_v_99_2 * 3) + pub_r001534_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = (((sec_r001534_9_1 * 3) + pub_r001534_6_1) + 35) & 127;
  int stage_v_308_2 = (((sec_r001534_9_2 * 3) + pub_r001534_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = ((pub_r001534_2_1 * 2) + 23) & 63;
  int stage_v_309_2 = ((pub_r001534_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = (((stage_v_289_1 * 3) + pub_r001534_2_1) + 11) & 127;
  int stage_v_310_2 = (((stage_v_289_2 * 3) + pub_r001534_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = (((stage_v_39_1 * 3) + pub_r001534_2_1) + 5) & 127;
  int stage_v_311_2 = (((stage_v_39_2 * 3) + pub_r001534_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = (((stage_v_228_1 * 3) + pub_r001534_9_1) + 5) & 127;
  int stage_v_312_2 = (((stage_v_228_2 * 3) + pub_r001534_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = ((pub_r001534_19_1 * 2) + 33) & 63;
  int stage_v_313_2 = ((pub_r001534_19_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_296_1 * 3) + pub_r001534_19_1) + 15) & 127;
  int stage_v_314_2 = (((stage_v_296_2 * 3) + pub_r001534_19_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = (((stage_v_52_1 * 3) + pub_r001534_9_1) + 4) & 127;
  int stage_v_315_2 = (((stage_v_52_2 * 3) + pub_r001534_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_128_1 * 3) + pub_r001534_10_1) + 37) & 127;
  int stage_v_316_2 = (((stage_v_128_2 * 3) + pub_r001534_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((stage_v_265_1 * 3) + pub_r001534_11_1) + 18) & 127;
  int stage_v_317_2 = (((stage_v_265_2 * 3) + pub_r001534_11_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = (((stage_v_235_1 * 3) + pub_r001534_9_1) + 37) & 127;
  int stage_v_318_2 = (((stage_v_235_2 * 3) + pub_r001534_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = (((sec_r001534_20_1 * 3) + pub_r001534_9_1) + 28) & 127;
  int stage_v_319_2 = (((sec_r001534_20_2 * 3) + pub_r001534_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = (((stage_v_182_1 * 3) + pub_r001534_10_1) + 42) & 127;
  int stage_v_320_2 = (((stage_v_182_2 * 3) + pub_r001534_10_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = ((pub_r001534_18_1 * 2) + 7) & 63;
  int stage_v_321_2 = ((pub_r001534_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001534_10_1 * 2) + 31) & 63;
  int stage_v_322_2 = ((pub_r001534_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001534_13_1 * 2) + 44) & 63;
  int stage_v_323_2 = ((pub_r001534_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((sec_r001534_4_1 * 3) + pub_r001534_10_1) + 27) & 127;
  int stage_v_324_2 = (((sec_r001534_4_2 * 3) + pub_r001534_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = ((pub_r001534_3_1 * 2) + 9) & 63;
  int stage_v_325_2 = ((pub_r001534_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001534_1_1 * 2) + 43) & 63;
  int stage_v_326_2 = ((pub_r001534_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001534_4_1 * 2) + 40) & 63;
  int stage_v_327_2 = ((pub_r001534_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((stage_v_10_1 * 3) + pub_r001534_15_1) + 28) & 127;
  int stage_v_328_2 = (((stage_v_10_2 * 3) + pub_r001534_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = ((pub_r001534_13_1 * 2) + 46) & 63;
  int stage_v_329_2 = ((pub_r001534_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = (((stage_v_41_1 * 3) + pub_r001534_5_1) + 9) & 127;
  int stage_v_330_2 = (((stage_v_41_2 * 3) + pub_r001534_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = ((pub_r001534_9_1 * 2) + 32) & 63;
  int stage_v_331_2 = ((pub_r001534_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((stage_v_185_1 * 3) + pub_r001534_16_1) + 9) & 127;
  int stage_v_332_2 = (((stage_v_185_2 * 3) + pub_r001534_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((stage_v_72_1 * 3) + pub_r001534_13_1) + 10) & 127;
  int stage_v_333_2 = (((stage_v_72_2 * 3) + pub_r001534_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = (((stage_v_263_1 * 3) + pub_r001534_10_1) + 4) & 127;
  int stage_v_334_2 = (((stage_v_263_2 * 3) + pub_r001534_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001534_12_1 * 2) + 21) & 63;
  int stage_v_335_2 = ((pub_r001534_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = (((stage_v_307_1 * 3) + pub_r001534_6_1) + 25) & 127;
  int stage_v_336_2 = (((stage_v_307_2 * 3) + pub_r001534_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_232_1 * 3) + pub_r001534_4_1) + 34) & 127;
  int stage_v_337_2 = (((stage_v_232_2 * 3) + pub_r001534_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((stage_v_10_1 * 3) + pub_r001534_8_1) + 11) & 127;
  int stage_v_338_2 = (((stage_v_10_2 * 3) + pub_r001534_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = (((helper_flow_4_1 * 3) + pub_r001534_3_1) + 43) & 127;
  int stage_v_339_2 = (((helper_flow_4_2 * 3) + pub_r001534_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = (((stage_v_310_1 * 3) + pub_r001534_12_1) + 34) & 127;
  int stage_v_340_2 = (((stage_v_310_2 * 3) + pub_r001534_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = ((pub_r001534_4_1 * 2) + 35) & 63;
  int stage_v_341_2 = ((pub_r001534_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001534_17_1 * 2) + 29) & 63;
  int stage_v_342_2 = ((pub_r001534_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = (((stage_v_163_1 * 3) + pub_r001534_9_1) + 12) & 127;
  int stage_v_343_2 = (((stage_v_163_2 * 3) + pub_r001534_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_150_1 * 3) + pub_r001534_8_1) + 8) & 127;
  int stage_v_344_2 = (((stage_v_150_2 * 3) + pub_r001534_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = (((sec_r001534_2_1 * 3) + pub_r001534_5_1) + 3) & 127;
  int stage_v_345_2 = (((sec_r001534_2_2 * 3) + pub_r001534_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = (((stage_v_204_1 * 3) + pub_r001534_4_1) + 42) & 127;
  int stage_v_346_2 = (((stage_v_204_2 * 3) + pub_r001534_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = (((stage_v_56_1 * 3) + pub_r001534_16_1) + 24) & 127;
  int stage_v_347_2 = (((stage_v_56_2 * 3) + pub_r001534_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_117_1 * 3) + pub_r001534_2_1) + 34) & 127;
  int stage_v_348_2 = (((stage_v_117_2 * 3) + pub_r001534_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_333_1 * 3) + pub_r001534_1_1) + 24) & 127;
  int stage_v_349_2 = (((stage_v_333_2 * 3) + pub_r001534_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_209_1 * 3) + pub_r001534_6_1) + 4) & 127;
  int stage_v_350_2 = (((stage_v_209_2 * 3) + pub_r001534_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001534_15_1 * 2) + 17) & 63;
  int stage_v_351_2 = ((pub_r001534_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = (((stage_v_109_1 * 3) + pub_r001534_4_1) + 45) & 127;
  int stage_v_352_2 = (((stage_v_109_2 * 3) + pub_r001534_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = (((stage_v_66_1 * 3) + pub_r001534_8_1) + 45) & 127;
  int stage_v_353_2 = (((stage_v_66_2 * 3) + pub_r001534_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = ((pub_r001534_19_1 * 2) + 22) & 63;
  int stage_v_354_2 = ((pub_r001534_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = (((stage_v_66_1 * 3) + pub_r001534_16_1) + 36) & 127;
  int stage_v_355_2 = (((stage_v_66_2 * 3) + pub_r001534_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_188_1 * 3) + pub_r001534_8_1) + 13) & 127;
  int stage_v_356_2 = (((stage_v_188_2 * 3) + pub_r001534_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = (((stage_v_107_1 * 3) + pub_r001534_0_1) + 37) & 127;
  int stage_v_357_2 = (((stage_v_107_2 * 3) + pub_r001534_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = (((stage_v_188_1 * 3) + pub_r001534_8_1) + 13) & 127;
  int stage_v_358_2 = (((stage_v_188_2 * 3) + pub_r001534_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = (((stage_v_320_1 * 3) + pub_r001534_16_1) + 24) & 127;
  int stage_v_359_2 = (((stage_v_320_2 * 3) + pub_r001534_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = (((stage_v_66_1 * 3) + pub_r001534_9_1) + 25) & 127;
  int stage_v_360_2 = (((stage_v_66_2 * 3) + pub_r001534_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = ((pub_r001534_13_1 * 2) + 14) & 63;
  int stage_v_361_2 = ((pub_r001534_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001534_7_1 * 2) + 34) & 63;
  int stage_v_362_2 = ((pub_r001534_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001534_1_1 * 2) + 38) & 63;
  int stage_v_363_2 = ((pub_r001534_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = (((stage_v_344_1 * 3) + pub_r001534_4_1) + 18) & 127;
  int stage_v_364_2 = (((stage_v_344_2 * 3) + pub_r001534_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = ((pub_r001534_6_1 * 2) + 37) & 63;
  int stage_v_365_2 = ((pub_r001534_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001534_11_1 * 2) + 19) & 63;
  int stage_v_366_2 = ((pub_r001534_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001534_9_1 * 2) + 36) & 63;
  int stage_v_367_2 = ((pub_r001534_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001534_12_1 * 2) + 33) & 63;
  int stage_v_368_2 = ((pub_r001534_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = (((stage_v_94_1 * 3) + pub_r001534_13_1) + 7) & 127;
  int stage_v_369_2 = (((stage_v_94_2 * 3) + pub_r001534_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = (((stage_v_285_1 * 3) + pub_r001534_13_1) + 44) & 127;
  int stage_v_370_2 = (((stage_v_285_2 * 3) + pub_r001534_13_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = ((pub_r001534_1_1 * 2) + 47) & 63;
  int stage_v_371_2 = ((pub_r001534_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001534_11_1 * 2) + 43) & 63;
  int stage_v_372_2 = ((pub_r001534_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = (((stage_v_1_1 * 3) + pub_r001534_16_1) + 15) & 127;
  int stage_v_373_2 = (((stage_v_1_2 * 3) + pub_r001534_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001534_3_1 != sec_r001534_3_2);
  __CPROVER_assume(sec_r001534_4_1 != sec_r001534_4_2);
  __CPROVER_assume(sec_r001534_6_1 != sec_r001534_6_2);
  __CPROVER_assume(sec_r001534_9_1 != sec_r001534_9_2);
  __CPROVER_assume(sec_r001534_14_1 != sec_r001534_14_2);
  __CPROVER_assume(pub_r001534_2_1 == pub_r001534_2_2);
  __CPROVER_assume(pub_r001534_7_1 == pub_r001534_7_2);
  __CPROVER_assume(sec_r001534_10_1 != sec_r001534_10_2);
  __CPROVER_assume(pub_r001534_0_1 == pub_r001534_0_2);
  __CPROVER_assume(pub_r001534_19_1 == pub_r001534_19_2);
  __CPROVER_assume(sec_r001534_21_1 != sec_r001534_21_2);
  __CPROVER_assume(pub_r001534_14_1 == pub_r001534_14_2);
  __CPROVER_assume(sec_r001534_16_1 != sec_r001534_16_2);
  __CPROVER_assume(pub_r001534_15_1 == pub_r001534_15_2);
  __CPROVER_assume(sec_r001534_12_1 != sec_r001534_12_2);
  __CPROVER_assume(sec_r001534_7_1 != sec_r001534_7_2);
  __CPROVER_assume(sec_r001534_19_1 != sec_r001534_19_2);
  __CPROVER_assume(pub_r001534_11_1 == pub_r001534_11_2);
  __CPROVER_assume(sec_r001534_13_1 != sec_r001534_13_2);
  __CPROVER_assume(pub_r001534_3_1 == pub_r001534_3_2);
  __CPROVER_assume(pub_r001534_18_1 == pub_r001534_18_2);
  __CPROVER_assume(pub_r001534_6_1 == pub_r001534_6_2);
  __CPROVER_assume(sec_r001534_5_1 != sec_r001534_5_2);
  __CPROVER_assume(sec_r001534_15_1 != sec_r001534_15_2);
  __CPROVER_assume(pub_r001534_13_1 == pub_r001534_13_2);
  __CPROVER_assume(sec_r001534_1_1 != sec_r001534_1_2);
  __CPROVER_assume(sec_r001534_20_1 != sec_r001534_20_2);
  __CPROVER_assume(sec_r001534_0_1 != sec_r001534_0_2);
  __CPROVER_assume(pub_r001534_4_1 == pub_r001534_4_2);
  __CPROVER_assume(pub_r001534_1_1 == pub_r001534_1_2);
  __CPROVER_assume(pub_r001534_17_1 == pub_r001534_17_2);
  __CPROVER_assume(pub_r001534_9_1 == pub_r001534_9_2);
  __CPROVER_assume(pub_r001534_8_1 == pub_r001534_8_2);
  __CPROVER_assume(sec_r001534_8_1 != sec_r001534_8_2);
  __CPROVER_assume(sec_r001534_17_1 != sec_r001534_17_2);
  __CPROVER_assume(sec_r001534_18_1 != sec_r001534_18_2);
  __CPROVER_assume(sec_r001534_2_1 != sec_r001534_2_2);
  __CPROVER_assume(pub_r001534_10_1 == pub_r001534_10_2);
  __CPROVER_assume(sec_r001534_11_1 != sec_r001534_11_2);
  __CPROVER_assume(pub_r001534_16_1 == pub_r001534_16_2);
  __CPROVER_assume(pub_r001534_5_1 == pub_r001534_5_2);
  __CPROVER_assume(pub_r001534_12_1 == pub_r001534_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.dim == st_var_1_2.dim);
  assert(st_var_1_1.stride == st_var_1_2.stride);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.flags == st_var_2_2.flags);
  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.round_key == st_var_2_2.round_key);
  assert(st_var_2_1.tag == st_var_2_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.head == st_var_3_2.head);
  assert(st_var_3_1.tail == st_var_3_2.tail);
  assert(st_var_3_1.watermark == st_var_3_2.watermark);
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
  assert(stage_v_237_1 == stage_v_237_2);
  assert(stage_v_238_1 == stage_v_238_2);
  assert(stage_v_239_1 == stage_v_239_2);
  assert(stage_v_240_1 == stage_v_240_2);
  assert(stage_v_241_1 == stage_v_241_2);
  assert(stage_v_242_1 == stage_v_242_2);
  assert(stage_v_243_1 == stage_v_243_2);
  assert(stage_v_244_1 == stage_v_244_2);
  assert(stage_v_245_1 == stage_v_245_2);
  assert(stage_v_246_1 == stage_v_246_2);
  assert(stage_v_247_1 == stage_v_247_2);
  assert(stage_v_248_1 == stage_v_248_2);
  assert(stage_v_249_1 == stage_v_249_2);
  assert(stage_v_250_1 == stage_v_250_2);
  assert(stage_v_251_1 == stage_v_251_2);
  assert(stage_v_252_1 == stage_v_252_2);
  assert(stage_v_253_1 == stage_v_253_2);
  assert(stage_v_254_1 == stage_v_254_2);
  assert(stage_v_255_1 == stage_v_255_2);
  assert(stage_v_256_1 == stage_v_256_2);
  assert(stage_v_257_1 == stage_v_257_2);
  assert(stage_v_258_1 == stage_v_258_2);
  assert(stage_v_259_1 == stage_v_259_2);
  assert(stage_v_260_1 == stage_v_260_2);
  assert(stage_v_261_1 == stage_v_261_2);
  assert(stage_v_262_1 == stage_v_262_2);
  assert(stage_v_263_1 == stage_v_263_2);
  assert(stage_v_264_1 == stage_v_264_2);
  assert(stage_v_265_1 == stage_v_265_2);
  assert(stage_v_266_1 == stage_v_266_2);
  assert(stage_v_267_1 == stage_v_267_2);
  assert(stage_v_268_1 == stage_v_268_2);
  assert(stage_v_269_1 == stage_v_269_2);
  assert(stage_v_270_1 == stage_v_270_2);
  assert(stage_v_271_1 == stage_v_271_2);
  assert(stage_v_272_1 == stage_v_272_2);
  assert(stage_v_273_1 == stage_v_273_2);
  assert(stage_v_274_1 == stage_v_274_2);
  assert(stage_v_275_1 == stage_v_275_2);
  assert(stage_v_276_1 == stage_v_276_2);
  assert(stage_v_277_1 == stage_v_277_2);
  assert(stage_v_278_1 == stage_v_278_2);
  assert(stage_v_279_1 == stage_v_279_2);
  assert(stage_v_280_1 == stage_v_280_2);
  assert(stage_v_281_1 == stage_v_281_2);
  assert(stage_v_282_1 == stage_v_282_2);
  assert(stage_v_283_1 == stage_v_283_2);
  assert(stage_v_284_1 == stage_v_284_2);
  assert(stage_v_285_1 == stage_v_285_2);
  assert(stage_v_286_1 == stage_v_286_2);
  assert(stage_v_287_1 == stage_v_287_2);
  assert(stage_v_288_1 == stage_v_288_2);
  assert(stage_v_289_1 == stage_v_289_2);
  assert(stage_v_290_1 == stage_v_290_2);
  assert(stage_v_291_1 == stage_v_291_2);
  assert(stage_v_292_1 == stage_v_292_2);
  assert(stage_v_293_1 == stage_v_293_2);
  assert(stage_v_294_1 == stage_v_294_2);
  assert(stage_v_295_1 == stage_v_295_2);
  assert(stage_v_296_1 == stage_v_296_2);
  assert(stage_v_297_1 == stage_v_297_2);
  assert(stage_v_298_1 == stage_v_298_2);
  assert(stage_v_299_1 == stage_v_299_2);
  assert(stage_v_300_1 == stage_v_300_2);
  assert(stage_v_301_1 == stage_v_301_2);
  assert(stage_v_302_1 == stage_v_302_2);
  assert(stage_v_303_1 == stage_v_303_2);
  assert(stage_v_304_1 == stage_v_304_2);
  assert(stage_v_305_1 == stage_v_305_2);
  assert(stage_v_306_1 == stage_v_306_2);
  assert(stage_v_307_1 == stage_v_307_2);
  assert(stage_v_308_1 == stage_v_308_2);
  assert(stage_v_309_1 == stage_v_309_2);
  assert(stage_v_310_1 == stage_v_310_2);
  assert(stage_v_311_1 == stage_v_311_2);
  assert(stage_v_312_1 == stage_v_312_2);
  assert(stage_v_313_1 == stage_v_313_2);
  assert(stage_v_314_1 == stage_v_314_2);
  assert(stage_v_315_1 == stage_v_315_2);
  assert(stage_v_316_1 == stage_v_316_2);
  assert(stage_v_317_1 == stage_v_317_2);
  assert(stage_v_318_1 == stage_v_318_2);
  assert(stage_v_319_1 == stage_v_319_2);
  assert(stage_v_320_1 == stage_v_320_2);
  assert(stage_v_321_1 == stage_v_321_2);
  assert(stage_v_322_1 == stage_v_322_2);
  assert(stage_v_323_1 == stage_v_323_2);
  assert(stage_v_324_1 == stage_v_324_2);
  assert(stage_v_325_1 == stage_v_325_2);
  assert(stage_v_326_1 == stage_v_326_2);
  assert(stage_v_327_1 == stage_v_327_2);
  assert(stage_v_328_1 == stage_v_328_2);
  assert(stage_v_329_1 == stage_v_329_2);
  assert(stage_v_330_1 == stage_v_330_2);
  assert(stage_v_331_1 == stage_v_331_2);
  assert(stage_v_332_1 == stage_v_332_2);
  assert(stage_v_333_1 == stage_v_333_2);
  assert(stage_v_334_1 == stage_v_334_2);
  assert(stage_v_335_1 == stage_v_335_2);
  assert(stage_v_336_1 == stage_v_336_2);
  assert(stage_v_337_1 == stage_v_337_2);
  assert(stage_v_338_1 == stage_v_338_2);
  assert(stage_v_339_1 == stage_v_339_2);
  assert(stage_v_340_1 == stage_v_340_2);
  assert(stage_v_341_1 == stage_v_341_2);
  assert(stage_v_342_1 == stage_v_342_2);
  assert(stage_v_343_1 == stage_v_343_2);
  assert(stage_v_344_1 == stage_v_344_2);
  assert(stage_v_345_1 == stage_v_345_2);
  assert(stage_v_346_1 == stage_v_346_2);
  assert(stage_v_347_1 == stage_v_347_2);
  assert(stage_v_348_1 == stage_v_348_2);
  assert(stage_v_349_1 == stage_v_349_2);
  assert(stage_v_350_1 == stage_v_350_2);
  assert(stage_v_351_1 == stage_v_351_2);
  assert(stage_v_352_1 == stage_v_352_2);
  assert(stage_v_353_1 == stage_v_353_2);
  assert(stage_v_354_1 == stage_v_354_2);
  assert(stage_v_355_1 == stage_v_355_2);
  assert(stage_v_356_1 == stage_v_356_2);
  assert(stage_v_357_1 == stage_v_357_2);
  assert(stage_v_358_1 == stage_v_358_2);
  assert(stage_v_359_1 == stage_v_359_2);
  assert(stage_v_360_1 == stage_v_360_2);
  assert(stage_v_361_1 == stage_v_361_2);
  assert(stage_v_362_1 == stage_v_362_2);
  assert(stage_v_363_1 == stage_v_363_2);
  assert(stage_v_364_1 == stage_v_364_2);
  assert(stage_v_365_1 == stage_v_365_2);
  assert(stage_v_366_1 == stage_v_366_2);
  assert(stage_v_367_1 == stage_v_367_2);
  assert(stage_v_368_1 == stage_v_368_2);
  assert(stage_v_369_1 == stage_v_369_2);
  assert(stage_v_370_1 == stage_v_370_2);
  assert(stage_v_371_1 == stage_v_371_2);
  assert(stage_v_372_1 == stage_v_372_2);
  assert(stage_v_373_1 == stage_v_373_2);
}


