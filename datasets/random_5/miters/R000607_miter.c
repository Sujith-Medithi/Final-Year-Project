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
struct AudioFrame_R000607_713_0
{
  short gain;
  unsigned char sample_rate;
  int rms;
  unsigned char peak;
  int channels;
  int envelope;
  int buffer[3];
};
struct MatrixBlock_R000607_713_1
{
  int dim;
  int trace;
  int scale;
  unsigned char stride;
  int buffer[3];
};
struct EventLog_R000607_713_2
{
  short code;
  int seq;
  int timestamp;
  int signature;
  unsigned char severity;
  unsigned char facility;
  int buffer[3];
};
union ColorPixel_R000607_713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000607_713_1
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
void fn_R000607_713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000607_713_2 st_1 = {0};
  struct EventLog_R000607_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_76_1 = local_arr_1[aux_1 % 3];
  int mask_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_76_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_76_1 == mask_76_2);
}

int fn_R000607_713_0(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000607_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int mask_76 = local_arr[aux % 3];
  acc = (acc + (mask_76 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000607_713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st_1 = {0};
  struct MatrixBlock_R000607_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int stride_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_53_1 > 17)
  {
    acc_1 = ((acc_1 + (stride_53_1 * 2)) + 5) & 127;
    aux_1 ^= stride_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_53_2 > 17)
  {
    acc_2 = ((acc_2 + (stride_53_2 * 2)) + 5) & 127;
    aux_2 ^= stride_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_35_1 = local_arr_1[aux_1 % 3];
  int threshold_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_35_2 * 2)) & 127;
  int pivot_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_18_1) & 63;
  aux_2 = (aux_2 + pivot_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_53_1 == stride_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_35_1 == threshold_35_2);
  assert(pivot_18_1 == pivot_18_2);
}

int fn_R000607_713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int stride_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_53 > 17)
  {
    acc = ((acc + (stride_53 * 2)) + 5) & 127;
    aux ^= stride_53 & 15;
  }
  else
  {
    acc = ((acc - stride_53) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_35 = local_arr[aux % 3];
  acc = (acc + (threshold_35 * 2)) & 127;
  int pivot_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_18) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000607_713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st_1 = {0};
  struct MatrixBlock_R000607_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int segment_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_97_1) & 63;
  aux_2 = (aux_2 + segment_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_24_1 > 47)
  {
    acc_1 = ((acc_1 + (mask_24_1 * 2)) + 5) & 127;
    aux_1 ^= mask_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_24_2 > 47)
  {
    acc_2 = ((acc_2 + (mask_24_2 * 2)) + 5) & 127;
    aux_2 ^= mask_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_48_1)
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

  switch (index_reg_48_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_97_1 == segment_97_2);
  assert(mask_24_1 == mask_24_2);
  assert(index_reg_48_1 == index_reg_48_2);
}

int fn_R000607_713_2(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int segment_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_97) & 63;
  acc ^= aux;
  int mask_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_24 > 47)
  {
    acc = ((acc + (mask_24 * 2)) + 5) & 127;
    aux ^= mask_24 & 15;
  }
  else
  {
    acc = ((acc - mask_24) + 11) & 127;
    aux += 3;
  }
  int index_reg_48 = (aux + st.buffer[1]) & 3;
  switch (index_reg_48)
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

void fn_R000607_713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st_1 = {0};
  struct MatrixBlock_R000607_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int vector_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_94_1 > 48)
  {
    acc_1 = ((acc_1 + (vector_94_1 * 2)) + 5) & 127;
    aux_1 ^= vector_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_94_2 > 48)
  {
    acc_2 = ((acc_2 + (vector_94_2 * 2)) + 5) & 127;
    aux_2 ^= vector_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_43_1 = local_arr_1[aux_1 % 3];
  int segment_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_43_2 * 2)) & 127;
  int parity_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_70_1) & 63;
  aux_2 = (aux_2 + parity_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_10_1)
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

  switch (tracker_10_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_94_1 == vector_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_43_1 == segment_43_2);
  assert(parity_70_1 == parity_70_2);
  assert(tracker_10_1 == tracker_10_2);
}

int fn_R000607_713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int vector_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_94 > 48)
  {
    acc = ((acc + (vector_94 * 2)) + 5) & 127;
    aux ^= vector_94 & 15;
  }
  else
  {
    acc = ((acc - vector_94) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_43 = local_arr[aux % 3];
  acc = (acc + (segment_43 * 2)) & 127;
  int parity_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_70) & 63;
  acc ^= aux;
  int tracker_10 = (aux + st.buffer[1]) & 3;
  switch (tracker_10)
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

void fn_R000607_713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000607_713_0 st_1 = {0};
  struct AudioFrame_R000607_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_20_1) & 63;
  aux_2 = (aux_2 + stride_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_20_1 == stride_20_2);
}

int fn_R000607_713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000607_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_20) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000607_713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000607_713_0 st_1 = {0};
  struct AudioFrame_R000607_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int stride_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_75_1) & 63;
  aux_2 = (aux_2 + stride_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_94_1 > 25)
  {
    acc_1 = ((acc_1 + (offset_94_1 * 2)) + 5) & 127;
    aux_1 ^= offset_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_94_2 > 25)
  {
    acc_2 = ((acc_2 + (offset_94_2 * 2)) + 5) & 127;
    aux_2 ^= offset_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_94_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_56_1 = local_arr_1[aux_1 % 3];
  int residue_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_75_1 == stride_75_2);
  assert(offset_94_1 == offset_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_56_1 == residue_56_2);
}

int fn_R000607_713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000607_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int stride_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_75) & 63;
  acc ^= aux;
  int offset_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_94 > 25)
  {
    acc = ((acc + (offset_94 * 2)) + 5) & 127;
    aux ^= offset_94 & 15;
  }
  else
  {
    acc = ((acc - offset_94) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_56 = local_arr[aux % 3];
  acc = (acc + (residue_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000607_713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000607_713_0 st_1 = {0};
  struct AudioFrame_R000607_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int damping_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_74_1)
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

  switch (damping_74_2)
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
  int metric_86_1 = local_arr_1[aux_1 % 3];
  int metric_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_74_1 == damping_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_86_1 == metric_86_2);
}

int fn_R000607_713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000607_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int damping_74 = (aux + st.buffer[1]) & 3;
  switch (damping_74)
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
  int metric_86 = local_arr[aux % 3];
  acc = (acc + (metric_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000607_713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000607_713_2 st_1 = {0};
  struct EventLog_R000607_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int tracker_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_90_1) & 63;
  aux_2 = (aux_2 + tracker_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_47_1)
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

  switch (sample_47_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_90_1 == tracker_90_2);
  assert(sample_47_1 == sample_47_2);
}

int fn_R000607_713_7(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000607_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int tracker_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_90) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_47 = (aux + st.buffer[1]) & 3;
  switch (sample_47)
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

void fn_R000607_713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st_1 = {0};
  struct MatrixBlock_R000607_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_37_1 = local_arr_1[aux_1 % 3];
  int residue_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
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

  assert(residue_37_1 == residue_37_2);
}

int fn_R000607_713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_37 = local_arr[aux % 3];
  acc = (acc + (residue_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000607_713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000607_713_0 st_1 = {0};
  struct AudioFrame_R000607_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int threshold_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_45_1) & 63;
  aux_2 = (aux_2 + threshold_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_45_1 == threshold_45_2);
}

int fn_R000607_713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000607_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int threshold_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_45) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000607_713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000607_713_2 st_1 = {0};
  struct EventLog_R000607_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int tracker_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_87_1 > 27)
  {
    acc_1 = ((acc_1 + (tracker_87_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_87_2 > 27)
  {
    acc_2 = ((acc_2 + (tracker_87_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_87_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_88_1)
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

  switch (metric_88_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_34_1 = local_arr_1[aux_1 % 3];
  int offset_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_34_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_87_1 == tracker_87_2);
  assert(metric_88_1 == metric_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_34_1 == offset_34_2);
}

int fn_R000607_713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000607_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int tracker_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_87 > 27)
  {
    acc = ((acc + (tracker_87 * 2)) + 5) & 127;
    aux ^= tracker_87 & 15;
  }
  else
  {
    acc = ((acc - tracker_87) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_88 = (aux + st.buffer[1]) & 3;
  switch (metric_88)
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

  int local_arr[3] = {4, 9, 15};
  int offset_34 = local_arr[aux % 3];
  acc = (acc + (offset_34 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000607_713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000607_713_0 st_1 = {0};
  struct AudioFrame_R000607_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int residue_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_61_1)
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

  switch (residue_61_2)
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
  int quotient_47_1 = local_arr_1[aux_1 % 3];
  int quotient_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_47_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_61_1 == residue_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_47_1 == quotient_47_2);
}

int fn_R000607_713_11(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000607_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int residue_61 = (aux + st.buffer[1]) & 3;
  switch (residue_61)
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
  int quotient_47 = local_arr[aux % 3];
  acc = (acc + (quotient_47 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000607_713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000607_713_0 st_1 = {0};
  struct AudioFrame_R000607_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int residue_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_85_1 > 47)
  {
    acc_1 = ((acc_1 + (residue_85_1 * 2)) + 5) & 127;
    aux_1 ^= residue_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_85_2 > 47)
  {
    acc_2 = ((acc_2 + (residue_85_2 * 2)) + 5) & 127;
    aux_2 ^= residue_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_19_1) & 63;
  aux_2 = (aux_2 + mask_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_82_1)
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

  switch (tally_82_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_85_1 == residue_85_2);
  assert(mask_19_1 == mask_19_2);
  assert(tally_82_1 == tally_82_2);
}

int fn_R000607_713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000607_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int residue_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_85 > 47)
  {
    acc = ((acc + (residue_85 * 2)) + 5) & 127;
    aux ^= residue_85 & 15;
  }
  else
  {
    acc = ((acc - residue_85) + 11) & 127;
    aux += 3;
  }
  int mask_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_19) & 63;
  acc ^= aux;
  int tally_82 = (aux + st.buffer[1]) & 3;
  switch (tally_82)
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

void fn_R000607_713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st_1 = {0};
  struct MatrixBlock_R000607_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_36_1 = local_arr_1[aux_1 % 3];
  int delta_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_36_2 * 2)) & 127;
  int residue_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_96_1) & 63;
  aux_2 = (aux_2 + residue_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_23_1)
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

  switch (cursor_23_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
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

  assert(delta_36_1 == delta_36_2);
  assert(residue_96_1 == residue_96_2);
  assert(cursor_23_1 == cursor_23_2);
}

int fn_R000607_713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int delta_36 = local_arr[aux % 3];
  acc = (acc + (delta_36 * 2)) & 127;
  int residue_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_96) & 63;
  acc ^= aux;
  int cursor_23 = (aux + st.buffer[1]) & 3;
  switch (cursor_23)
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

void fn_R000607_713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st_1 = {0};
  struct MatrixBlock_R000607_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_35_1 = local_arr_1[aux_1 % 3];
  int delta_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_35_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_38_1)
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

  switch (weight_38_2)
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

  int mask_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_11_1) & 63;
  aux_2 = (aux_2 + mask_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
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

  assert(delta_35_1 == delta_35_2);
  assert(weight_38_1 == weight_38_2);
  assert(mask_11_1 == mask_11_2);
}

int fn_R000607_713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int delta_35 = local_arr[aux % 3];
  acc = (acc + (delta_35 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_38 = (aux + st.buffer[1]) & 3;
  switch (weight_38)
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

  int mask_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_11) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000607_713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st_1 = {0};
  struct MatrixBlock_R000607_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quantum_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_95_1 > 33)
  {
    acc_1 = ((acc_1 + (quantum_95_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_95_2 > 33)
  {
    acc_2 = ((acc_2 + (quantum_95_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_50_1 = local_arr_1[aux_1 % 3];
  int offset_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_50_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_95_1 == quantum_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_50_1 == offset_50_2);
}

int fn_R000607_713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000607_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quantum_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_95 > 33)
  {
    acc = ((acc + (quantum_95 * 2)) + 5) & 127;
    aux ^= quantum_95 & 15;
  }
  else
  {
    acc = ((acc - quantum_95) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_50 = local_arr[aux % 3];
  acc = (acc + (offset_50 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000607_0_1;
  int sec_r000607_0_2;
  int sec_r000607_1_1;
  int sec_r000607_1_2;
  int sec_r000607_2_1;
  int sec_r000607_2_2;
  int sec_r000607_3_1;
  int sec_r000607_3_2;
  int sec_r000607_4_1;
  int sec_r000607_4_2;
  int sec_r000607_5_1;
  int sec_r000607_5_2;
  int sec_r000607_6_1;
  int sec_r000607_6_2;
  int sec_r000607_7_1;
  int sec_r000607_7_2;
  int sec_r000607_8_1;
  int sec_r000607_8_2;
  int sec_r000607_9_1;
  int sec_r000607_9_2;
  int sec_r000607_10_1;
  int sec_r000607_10_2;
  int sec_r000607_11_1;
  int sec_r000607_11_2;
  int sec_r000607_12_1;
  int sec_r000607_12_2;
  int sec_r000607_13_1;
  int sec_r000607_13_2;
  int sec_r000607_14_1;
  int sec_r000607_14_2;
  int sec_r000607_15_1;
  int sec_r000607_15_2;
  int sec_r000607_16_1;
  int sec_r000607_16_2;
  int sec_r000607_17_1;
  int sec_r000607_17_2;
  int sec_r000607_18_1;
  int sec_r000607_18_2;
  int pub_r000607_0_1;
  int pub_r000607_0_2;
  int pub_r000607_1_1;
  int pub_r000607_1_2;
  int pub_r000607_2_1;
  int pub_r000607_2_2;
  int pub_r000607_3_1;
  int pub_r000607_3_2;
  int pub_r000607_4_1;
  int pub_r000607_4_2;
  int pub_r000607_5_1;
  int pub_r000607_5_2;
  int pub_r000607_6_1;
  int pub_r000607_6_2;
  int pub_r000607_7_1;
  int pub_r000607_7_2;
  int pub_r000607_8_1;
  int pub_r000607_8_2;
  int pub_r000607_9_1;
  int pub_r000607_9_2;
  int pub_r000607_10_1;
  int pub_r000607_10_2;
  int pub_r000607_11_1;
  int pub_r000607_11_2;
  int pub_r000607_12_1;
  int pub_r000607_12_2;
  int pub_r000607_13_1;
  int pub_r000607_13_2;
  int pub_r000607_14_1;
  int pub_r000607_14_2;
  int pub_r000607_15_1;
  int pub_r000607_15_2;
  int pub_r000607_16_1;
  int pub_r000607_16_2;
  int pub_r000607_17_1;
  int pub_r000607_17_2;
  int pub_r000607_18_1;
  int pub_r000607_18_2;
  int pub_r000607_19_1;
  int pub_r000607_19_2;
  int pub_r000607_20_1;
  int pub_r000607_20_2;
  int pub_r000607_21_1;
  int pub_r000607_21_2;
  int pub_r000607_22_1;
  int pub_r000607_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000607_0_1 >= (-100)) && (pub_r000607_0_1 <= 100));
  __CPROVER_assume((pub_r000607_0_2 >= (-100)) && (pub_r000607_0_2 <= 100));
  __CPROVER_assume((pub_r000607_1_1 >= (-100)) && (pub_r000607_1_1 <= 100));
  __CPROVER_assume((pub_r000607_1_2 >= (-100)) && (pub_r000607_1_2 <= 100));
  __CPROVER_assume((pub_r000607_2_1 >= (-100)) && (pub_r000607_2_1 <= 100));
  __CPROVER_assume((pub_r000607_2_2 >= (-100)) && (pub_r000607_2_2 <= 100));
  __CPROVER_assume((pub_r000607_3_1 >= (-100)) && (pub_r000607_3_1 <= 100));
  __CPROVER_assume((pub_r000607_3_2 >= (-100)) && (pub_r000607_3_2 <= 100));
  __CPROVER_assume((pub_r000607_4_1 >= (-100)) && (pub_r000607_4_1 <= 100));
  __CPROVER_assume((pub_r000607_4_2 >= (-100)) && (pub_r000607_4_2 <= 100));
  __CPROVER_assume((pub_r000607_5_1 >= (-100)) && (pub_r000607_5_1 <= 100));
  __CPROVER_assume((pub_r000607_5_2 >= (-100)) && (pub_r000607_5_2 <= 100));
  __CPROVER_assume((pub_r000607_6_1 >= (-100)) && (pub_r000607_6_1 <= 100));
  __CPROVER_assume((pub_r000607_6_2 >= (-100)) && (pub_r000607_6_2 <= 100));
  __CPROVER_assume((pub_r000607_7_1 >= (-100)) && (pub_r000607_7_1 <= 100));
  __CPROVER_assume((pub_r000607_7_2 >= (-100)) && (pub_r000607_7_2 <= 100));
  __CPROVER_assume((pub_r000607_8_1 >= (-100)) && (pub_r000607_8_1 <= 100));
  __CPROVER_assume((pub_r000607_8_2 >= (-100)) && (pub_r000607_8_2 <= 100));
  __CPROVER_assume((pub_r000607_9_1 >= (-100)) && (pub_r000607_9_1 <= 100));
  __CPROVER_assume((pub_r000607_9_2 >= (-100)) && (pub_r000607_9_2 <= 100));
  __CPROVER_assume((pub_r000607_10_1 >= (-100)) && (pub_r000607_10_1 <= 100));
  __CPROVER_assume((pub_r000607_10_2 >= (-100)) && (pub_r000607_10_2 <= 100));
  __CPROVER_assume((pub_r000607_11_1 >= (-100)) && (pub_r000607_11_1 <= 100));
  __CPROVER_assume((pub_r000607_11_2 >= (-100)) && (pub_r000607_11_2 <= 100));
  __CPROVER_assume((pub_r000607_12_1 >= (-100)) && (pub_r000607_12_1 <= 100));
  __CPROVER_assume((pub_r000607_12_2 >= (-100)) && (pub_r000607_12_2 <= 100));
  __CPROVER_assume((pub_r000607_13_1 >= (-100)) && (pub_r000607_13_1 <= 100));
  __CPROVER_assume((pub_r000607_13_2 >= (-100)) && (pub_r000607_13_2 <= 100));
  __CPROVER_assume((pub_r000607_14_1 >= (-100)) && (pub_r000607_14_1 <= 100));
  __CPROVER_assume((pub_r000607_14_2 >= (-100)) && (pub_r000607_14_2 <= 100));
  __CPROVER_assume((pub_r000607_15_1 >= (-100)) && (pub_r000607_15_1 <= 100));
  __CPROVER_assume((pub_r000607_15_2 >= (-100)) && (pub_r000607_15_2 <= 100));
  __CPROVER_assume((pub_r000607_16_1 >= (-100)) && (pub_r000607_16_1 <= 100));
  __CPROVER_assume((pub_r000607_16_2 >= (-100)) && (pub_r000607_16_2 <= 100));
  __CPROVER_assume((pub_r000607_17_1 >= (-100)) && (pub_r000607_17_1 <= 100));
  __CPROVER_assume((pub_r000607_17_2 >= (-100)) && (pub_r000607_17_2 <= 100));
  __CPROVER_assume((pub_r000607_18_1 >= (-100)) && (pub_r000607_18_1 <= 100));
  __CPROVER_assume((pub_r000607_18_2 >= (-100)) && (pub_r000607_18_2 <= 100));
  __CPROVER_assume((pub_r000607_19_1 >= (-100)) && (pub_r000607_19_1 <= 100));
  __CPROVER_assume((pub_r000607_19_2 >= (-100)) && (pub_r000607_19_2 <= 100));
  __CPROVER_assume((pub_r000607_20_1 >= (-100)) && (pub_r000607_20_1 <= 100));
  __CPROVER_assume((pub_r000607_20_2 >= (-100)) && (pub_r000607_20_2 <= 100));
  __CPROVER_assume((pub_r000607_21_1 >= (-100)) && (pub_r000607_21_1 <= 100));
  __CPROVER_assume((pub_r000607_21_2 >= (-100)) && (pub_r000607_21_2 <= 100));
  __CPROVER_assume((pub_r000607_22_1 >= (-100)) && (pub_r000607_22_1 <= 100));
  __CPROVER_assume((pub_r000607_22_2 >= (-100)) && (pub_r000607_22_2 <= 100));
  __CPROVER_assume((sec_r000607_0_1 >= 0) && (sec_r000607_0_1 <= 255));
  __CPROVER_assume((sec_r000607_0_2 >= 0) && (sec_r000607_0_2 <= 255));
  __CPROVER_assume((sec_r000607_1_1 >= 0) && (sec_r000607_1_1 <= 255));
  __CPROVER_assume((sec_r000607_1_2 >= 0) && (sec_r000607_1_2 <= 255));
  __CPROVER_assume((sec_r000607_2_1 >= 0) && (sec_r000607_2_1 <= 255));
  __CPROVER_assume((sec_r000607_2_2 >= 0) && (sec_r000607_2_2 <= 255));
  __CPROVER_assume((sec_r000607_3_1 >= 0) && (sec_r000607_3_1 <= 255));
  __CPROVER_assume((sec_r000607_3_2 >= 0) && (sec_r000607_3_2 <= 255));
  __CPROVER_assume((sec_r000607_4_1 >= 0) && (sec_r000607_4_1 <= 255));
  __CPROVER_assume((sec_r000607_4_2 >= 0) && (sec_r000607_4_2 <= 255));
  __CPROVER_assume((sec_r000607_5_1 >= 0) && (sec_r000607_5_1 <= 255));
  __CPROVER_assume((sec_r000607_5_2 >= 0) && (sec_r000607_5_2 <= 255));
  __CPROVER_assume((sec_r000607_6_1 >= 0) && (sec_r000607_6_1 <= 255));
  __CPROVER_assume((sec_r000607_6_2 >= 0) && (sec_r000607_6_2 <= 255));
  __CPROVER_assume((sec_r000607_7_1 >= 0) && (sec_r000607_7_1 <= 255));
  __CPROVER_assume((sec_r000607_7_2 >= 0) && (sec_r000607_7_2 <= 255));
  __CPROVER_assume((sec_r000607_8_1 >= 0) && (sec_r000607_8_1 <= 255));
  __CPROVER_assume((sec_r000607_8_2 >= 0) && (sec_r000607_8_2 <= 255));
  __CPROVER_assume((sec_r000607_9_1 >= 0) && (sec_r000607_9_1 <= 255));
  __CPROVER_assume((sec_r000607_9_2 >= 0) && (sec_r000607_9_2 <= 255));
  __CPROVER_assume((sec_r000607_10_1 >= 0) && (sec_r000607_10_1 <= 255));
  __CPROVER_assume((sec_r000607_10_2 >= 0) && (sec_r000607_10_2 <= 255));
  __CPROVER_assume((sec_r000607_11_1 >= 0) && (sec_r000607_11_1 <= 255));
  __CPROVER_assume((sec_r000607_11_2 >= 0) && (sec_r000607_11_2 <= 255));
  __CPROVER_assume((sec_r000607_12_1 >= 0) && (sec_r000607_12_1 <= 255));
  __CPROVER_assume((sec_r000607_12_2 >= 0) && (sec_r000607_12_2 <= 255));
  __CPROVER_assume((sec_r000607_13_1 >= 0) && (sec_r000607_13_1 <= 255));
  __CPROVER_assume((sec_r000607_13_2 >= 0) && (sec_r000607_13_2 <= 255));
  __CPROVER_assume((sec_r000607_14_1 >= 0) && (sec_r000607_14_1 <= 255));
  __CPROVER_assume((sec_r000607_14_2 >= 0) && (sec_r000607_14_2 <= 255));
  __CPROVER_assume((sec_r000607_15_1 >= 0) && (sec_r000607_15_1 <= 255));
  __CPROVER_assume((sec_r000607_15_2 >= 0) && (sec_r000607_15_2 <= 255));
  __CPROVER_assume((sec_r000607_16_1 >= 0) && (sec_r000607_16_1 <= 255));
  __CPROVER_assume((sec_r000607_16_2 >= 0) && (sec_r000607_16_2 <= 255));
  __CPROVER_assume((sec_r000607_17_1 >= 0) && (sec_r000607_17_1 <= 255));
  __CPROVER_assume((sec_r000607_17_2 >= 0) && (sec_r000607_17_2 <= 255));
  __CPROVER_assume((sec_r000607_18_1 >= 0) && (sec_r000607_18_1 <= 255));
  __CPROVER_assume((sec_r000607_18_2 >= 0) && (sec_r000607_18_2 <= 255));
  struct AudioFrame_R000607_713_0 st_var_0_1 = {0};
  struct AudioFrame_R000607_713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000607_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000607_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000607_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000607_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000607_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000607_0_2 + 7) & 15;
  struct MatrixBlock_R000607_713_1 st_var_1_1 = {0};
  struct MatrixBlock_R000607_713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000607_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000607_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000607_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000607_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000607_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000607_0_2 + 9) & 15;
  struct EventLog_R000607_713_2 st_var_2_1 = {0};
  struct EventLog_R000607_713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000607_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000607_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000607_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000607_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000607_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000607_0_2 + 11) & 15;
  union ColorPixel_R000607_713_0 u_var_1;
  union ColorPixel_R000607_713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = (st_var_0_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_0_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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
  int stage_v_6_1 = ((st_var_0_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_0_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 54)
    {
      chk_sum_1 ^= stage_v_6_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_6_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 54)
    {
      chk_sum_2 ^= stage_v_6_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
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
  int stage_v_9_1 = (st_var_0_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_0_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 11) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (st_var_0_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_0_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
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
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 30) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 30) & 15;
  int stage_v_29_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_29_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= stage_v_29_1;
  chk_sum_2 ^= stage_v_29_2;
  int stage_v_30_1 = (st_var_0_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_0_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  int stage_v_31_1 = ((st_var_1_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_1_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 29)
    {
      chk_sum_1 ^= stage_v_31_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_31_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 29)
    {
      chk_sum_2 ^= stage_v_31_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 52)
    {
      chk_sum_1 ^= stage_v_36_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_36_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 52)
    {
      chk_sum_2 ^= stage_v_36_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((st_var_0_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_0_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 45)
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
  if (stage_v_39_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 45)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 41) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
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
  int stage_v_43_1 = (st_var_1_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_1_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = ((st_var_2_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_2_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 54)
    {
      chk_sum_1 ^= stage_v_44_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_44_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 54)
    {
      chk_sum_2 ^= stage_v_44_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 46) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = (st_var_1_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_1_2.buffer[0] ^ 49) & 3;
  switch (stage_v_46_1)
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

  switch (stage_v_46_2)
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

  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 35)
    {
      chk_sum_1 ^= stage_v_48_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_48_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 35)
    {
      chk_sum_2 ^= stage_v_48_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = (st_var_0_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_0_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 53) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 56) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 57) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
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
  int stage_v_61_1 = ((st_var_1_1.buffer[1] * 2) + 190) & 63;
  int stage_v_61_2 = ((st_var_1_2.buffer[1] * 2) + 190) & 63;
  if (stage_v_61_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 27)
    {
      chk_sum_1 ^= stage_v_61_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_61_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 27)
    {
      chk_sum_2 ^= stage_v_61_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_62_1 = table_1[2];
  int stage_v_62_2 = table_2[2];
  table_1[2] = (table_1[3] + 125) & 63;
  table_2[2] = (table_2[3] + 125) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000607_18_1 & 1) != 0)
  {
    if ((sec_r000607_2_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000607_16_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000607_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000607_16_1 + 7) & 127;
  }
  if ((sec_r000607_18_2 & 1) != 0)
  {
    if ((sec_r000607_2_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000607_16_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000607_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000607_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000607_13_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000607_20_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000607_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000607_20_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000607_13_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000607_20_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000607_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000607_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000607_14_1 & 1) != 0)
  {
    if ((sec_r000607_11_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000607_1_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000607_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000607_1_1 + 7) & 127;
  }
  if ((sec_r000607_14_2 & 1) != 0)
  {
    if ((sec_r000607_11_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000607_1_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000607_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000607_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000607_13_1 & 1) != 0)
  {
    if ((sec_r000607_16_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000607_11_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000607_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000607_11_1 + 7) & 127;
  }
  if ((sec_r000607_13_2 & 1) != 0)
  {
    if ((sec_r000607_16_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000607_11_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000607_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000607_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((sec_r000607_3_1 & 1) != 0)
  {
    if ((sec_r000607_1_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000607_3_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000607_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000607_3_1 + 7) & 127;
  }
  if ((sec_r000607_3_2 & 1) != 0)
  {
    if ((sec_r000607_1_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000607_3_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000607_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000607_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000607_0_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000607_21_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000607_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000607_21_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000607_0_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000607_21_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000607_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000607_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000607_3_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000607_4_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000607_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000607_4_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000607_3_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000607_4_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000607_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000607_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000607_9_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000607_0_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000607_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000607_0_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000607_9_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000607_0_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000607_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000607_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000607_2_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000607_5_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000607_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000607_5_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000607_2_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000607_5_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000607_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000607_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000607_9_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000607_19_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000607_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000607_19_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000607_9_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000607_19_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000607_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000607_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000607_9_1 & 1) != 0)
  {
    if ((sec_r000607_5_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000607_7_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000607_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000607_7_1 + 7) & 127;
  }
  if ((sec_r000607_9_2 & 1) != 0)
  {
    if ((sec_r000607_5_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000607_7_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000607_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000607_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000607_7_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000607_20_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000607_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000607_20_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000607_7_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000607_20_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000607_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000607_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000607_2_1 & 1) != 0)
  {
    if ((sec_r000607_18_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000607_15_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000607_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000607_15_1 + 7) & 127;
  }
  if ((sec_r000607_2_2 & 1) != 0)
  {
    if ((sec_r000607_18_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000607_15_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000607_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000607_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000607_5_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000607_11_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000607_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000607_11_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000607_5_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000607_11_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000607_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000607_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000607_6_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000607_17_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000607_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000607_17_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000607_6_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000607_17_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000607_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000607_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000607_3_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000607_19_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000607_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000607_19_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000607_3_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000607_19_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000607_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000607_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000607_17_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000607_2_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000607_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000607_2_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000607_17_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000607_2_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000607_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000607_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000607_13_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000607_21_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000607_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000607_21_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000607_13_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000607_21_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000607_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000607_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000607_12_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000607_21_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000607_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000607_21_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000607_12_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000607_21_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000607_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000607_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000607_4_1 & 1) != 0)
  {
    if ((sec_r000607_16_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000607_4_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000607_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000607_4_1 + 7) & 127;
  }
  if ((sec_r000607_4_2 & 1) != 0)
  {
    if ((sec_r000607_16_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000607_4_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000607_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000607_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000607_8_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000607_6_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000607_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000607_6_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000607_8_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000607_6_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000607_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000607_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000607_1_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000607_22_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000607_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000607_22_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000607_1_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000607_22_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000607_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000607_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000607_16_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000607_14_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000607_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000607_14_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000607_16_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000607_14_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000607_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000607_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000607_12_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000607_21_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000607_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000607_21_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000607_12_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000607_21_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000607_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000607_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000607_12_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000607_12_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000607_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000607_12_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000607_12_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000607_12_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000607_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000607_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000607_13_1 & 1) != 0)
  {
    if ((sec_r000607_9_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000607_6_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000607_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000607_6_1 + 7) & 127;
  }
  if ((sec_r000607_13_2 & 1) != 0)
  {
    if ((sec_r000607_9_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000607_6_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000607_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000607_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000607_0_1 & 1) != 0)
  {
    if ((sec_r000607_2_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000607_9_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000607_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000607_9_1 + 7) & 127;
  }
  if ((sec_r000607_0_2 & 1) != 0)
  {
    if ((sec_r000607_2_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000607_9_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000607_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000607_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000607_9_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000607_8_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000607_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000607_8_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000607_9_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000607_8_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000607_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000607_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000607_12_1 & 1) != 0)
  {
    if ((sec_r000607_12_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000607_12_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000607_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000607_12_1 + 7) & 127;
  }
  if ((sec_r000607_12_2 & 1) != 0)
  {
    if ((sec_r000607_12_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000607_12_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000607_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000607_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000607_16_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000607_9_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000607_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000607_9_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000607_16_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000607_9_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000607_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000607_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000607_18_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000607_7_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000607_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000607_7_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000607_18_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000607_7_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000607_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000607_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000607_14_1 & 1) != 0)
  {
    if ((sec_r000607_1_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000607_11_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000607_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000607_11_1 + 7) & 127;
  }
  if ((sec_r000607_14_2 & 1) != 0)
  {
    if ((sec_r000607_1_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000607_11_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000607_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000607_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000607_0_1 & 1) != 0)
  {
    if ((sec_r000607_11_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000607_2_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000607_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000607_2_1 + 7) & 127;
  }
  if ((sec_r000607_0_2 & 1) != 0)
  {
    if ((sec_r000607_11_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000607_2_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000607_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000607_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000607_9_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000607_16_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000607_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000607_16_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000607_9_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000607_16_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000607_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000607_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000607_18_1 & 1) != 0)
  {
    if ((sec_r000607_18_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000607_9_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000607_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000607_9_1 + 7) & 127;
  }
  if ((sec_r000607_18_2 & 1) != 0)
  {
    if ((sec_r000607_18_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000607_9_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000607_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000607_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000607_17_1 & 1) != 0)
  {
    if ((sec_r000607_6_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000607_5_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000607_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000607_5_1 + 7) & 127;
  }
  if ((sec_r000607_17_2 & 1) != 0)
  {
    if ((sec_r000607_6_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000607_5_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000607_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000607_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000607_16_1 & 1) != 0)
  {
    if ((sec_r000607_5_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000607_10_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000607_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000607_10_1 + 7) & 127;
  }
  if ((sec_r000607_16_2 & 1) != 0)
  {
    if ((sec_r000607_5_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000607_10_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000607_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000607_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000607_15_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000607_0_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000607_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000607_0_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000607_15_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000607_0_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000607_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000607_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000607_7_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000607_8_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000607_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000607_8_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000607_7_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000607_8_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000607_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000607_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000607_13_1 & 1) != 0)
  {
    if ((sec_r000607_11_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000607_0_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000607_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000607_0_1 + 7) & 127;
  }
  if ((sec_r000607_13_2 & 1) != 0)
  {
    if ((sec_r000607_11_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000607_0_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000607_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000607_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000607_14_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000607_4_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000607_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000607_4_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000607_14_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000607_4_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000607_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000607_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000607_15_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000607_14_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000607_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000607_14_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000607_15_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000607_14_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000607_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000607_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000607_4_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000607_16_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000607_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000607_16_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000607_4_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000607_16_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000607_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000607_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000607_13_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000607_13_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000607_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000607_13_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000607_13_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000607_13_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000607_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000607_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000607_17_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000607_21_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000607_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000607_21_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000607_17_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000607_21_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000607_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000607_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000607_12_1 & 1) != 0)
  {
    if ((sec_r000607_6_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000607_15_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000607_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000607_15_1 + 7) & 127;
  }
  if ((sec_r000607_12_2 & 1) != 0)
  {
    if ((sec_r000607_6_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000607_15_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000607_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000607_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000607_8_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000607_8_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000607_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000607_8_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000607_8_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000607_8_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000607_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000607_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000607_16_1 & 1) != 0)
  {
    if ((sec_r000607_0_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000607_22_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000607_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000607_22_1 + 7) & 127;
  }
  if ((sec_r000607_16_2 & 1) != 0)
  {
    if ((sec_r000607_0_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000607_22_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000607_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000607_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000607_14_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000607_15_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000607_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000607_15_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000607_14_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000607_15_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000607_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000607_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000607_16_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000607_15_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000607_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000607_15_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000607_16_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000607_15_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000607_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000607_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000607_16_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000607_13_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000607_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000607_13_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000607_16_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000607_13_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000607_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000607_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000607_2_1 & 1) != 0)
  {
    if ((sec_r000607_13_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000607_10_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000607_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000607_10_1 + 7) & 127;
  }
  if ((sec_r000607_2_2 & 1) != 0)
  {
    if ((sec_r000607_13_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000607_10_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000607_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000607_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000607_10_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000607_11_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000607_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000607_11_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000607_10_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000607_11_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000607_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000607_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000607_17_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000607_7_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000607_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000607_7_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000607_17_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000607_7_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000607_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000607_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000607_5_1 & 1) != 0)
  {
    if ((sec_r000607_10_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000607_21_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000607_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000607_21_1 + 7) & 127;
  }
  if ((sec_r000607_5_2 & 1) != 0)
  {
    if ((sec_r000607_10_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000607_21_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000607_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000607_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000607_16_1 & 1) != 0)
  {
    if ((sec_r000607_17_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000607_4_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000607_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000607_4_1 + 7) & 127;
  }
  if ((sec_r000607_16_2 & 1) != 0)
  {
    if ((sec_r000607_17_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000607_4_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000607_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000607_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000607_3_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000607_7_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000607_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000607_7_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000607_3_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000607_7_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000607_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000607_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000607_13_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000607_1_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000607_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000607_1_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000607_13_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000607_1_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000607_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000607_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r000607_14_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000607_15_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000607_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000607_15_1 + 7) & 127;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((sec_r000607_14_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000607_15_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000607_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000607_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000607_17_1 & 1) != 0)
  {
    if ((sec_r000607_6_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000607_9_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000607_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000607_9_1 + 7) & 127;
  }
  if ((sec_r000607_17_2 & 1) != 0)
  {
    if ((sec_r000607_6_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000607_9_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000607_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000607_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000607_5_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000607_22_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000607_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000607_22_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000607_5_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000607_22_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000607_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000607_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000607_3_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000607_12_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000607_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000607_12_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000607_3_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000607_12_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000607_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000607_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000607_10_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000607_17_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000607_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000607_17_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000607_10_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000607_17_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000607_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000607_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000607_18_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000607_1_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000607_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000607_1_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000607_18_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000607_1_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000607_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000607_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000607_1_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000607_20_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000607_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000607_20_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000607_1_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000607_20_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000607_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000607_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000607_9_1 & 1) != 0)
  {
    if ((sec_r000607_11_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000607_11_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000607_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000607_11_1 + 7) & 127;
  }
  if ((sec_r000607_9_2 & 1) != 0)
  {
    if ((sec_r000607_11_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000607_11_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000607_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000607_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000607_7_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000607_22_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000607_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000607_22_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000607_7_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000607_22_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000607_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000607_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000607_1_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000607_2_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000607_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000607_2_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000607_1_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000607_2_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000607_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000607_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000607_11_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000607_19_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000607_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000607_19_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000607_11_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000607_19_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000607_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000607_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000607_17_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000607_4_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000607_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000607_4_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000607_17_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000607_4_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000607_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000607_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000607_11_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000607_15_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000607_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000607_15_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000607_11_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000607_15_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000607_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000607_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000607_8_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000607_22_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000607_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000607_22_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000607_8_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000607_22_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000607_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000607_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((sec_r000607_11_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000607_22_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000607_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000607_22_1 + 7) & 127;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((sec_r000607_11_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000607_22_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000607_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000607_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000607_10_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000607_4_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000607_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000607_4_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000607_10_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000607_4_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000607_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000607_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000607_11_1 & 1) != 0)
  {
    if ((sec_r000607_15_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000607_18_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000607_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000607_18_1 + 7) & 127;
  }
  if ((sec_r000607_11_2 & 1) != 0)
  {
    if ((sec_r000607_15_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000607_18_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000607_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000607_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((sec_r000607_2_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000607_5_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000607_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000607_5_1 + 7) & 127;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((sec_r000607_2_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000607_5_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000607_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000607_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000607_11_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000607_12_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000607_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000607_12_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000607_11_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000607_12_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000607_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000607_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000607_13_1 & 1) != 0)
  {
    if ((sec_r000607_15_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000607_0_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000607_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000607_0_1 + 7) & 127;
  }
  if ((sec_r000607_13_2 & 1) != 0)
  {
    if ((sec_r000607_15_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000607_0_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000607_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000607_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((sec_r000607_5_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000607_11_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000607_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000607_11_1 + 7) & 127;
  }
  if ((stage_v_141_2 & 1) != 0)
  {
    if ((sec_r000607_5_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000607_11_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000607_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000607_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((sec_r000607_14_1 & 1) != 0)
  {
    if ((sec_r000607_10_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000607_8_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000607_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000607_8_1 + 7) & 127;
  }
  if ((sec_r000607_14_2 & 1) != 0)
  {
    if ((sec_r000607_10_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000607_8_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000607_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000607_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000607_2_1 & 1) != 0)
  {
    if ((sec_r000607_6_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000607_3_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000607_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000607_3_1 + 7) & 127;
  }
  if ((sec_r000607_2_2 & 1) != 0)
  {
    if ((sec_r000607_6_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000607_3_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000607_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000607_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((sec_r000607_16_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000607_5_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000607_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000607_5_1 + 7) & 127;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((sec_r000607_16_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000607_5_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000607_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000607_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000607_16_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000607_9_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000607_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000607_9_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000607_16_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000607_9_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000607_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000607_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000607_7_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000607_7_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000607_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000607_7_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000607_7_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000607_7_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000607_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000607_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000607_11_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000607_3_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000607_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000607_3_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000607_11_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000607_3_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000607_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000607_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((sec_r000607_11_1 & 1) != 0)
  {
    if ((sec_r000607_16_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000607_6_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000607_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000607_6_1 + 7) & 127;
  }
  if ((sec_r000607_11_2 & 1) != 0)
  {
    if ((sec_r000607_16_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000607_6_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000607_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000607_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((sec_r000607_1_1 & 1) != 0)
  {
    if ((sec_r000607_7_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000607_20_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000607_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000607_20_1 + 7) & 127;
  }
  if ((sec_r000607_1_2 & 1) != 0)
  {
    if ((sec_r000607_7_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000607_20_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000607_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000607_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000607_5_1 & 1) != 0)
  {
    if ((sec_r000607_9_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000607_1_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000607_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000607_1_1 + 7) & 127;
  }
  if ((sec_r000607_5_2 & 1) != 0)
  {
    if ((sec_r000607_9_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000607_1_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000607_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000607_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000607_4_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000607_15_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000607_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000607_15_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000607_4_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000607_15_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000607_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000607_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((sec_r000607_3_1 & 1) != 0)
  {
    if ((sec_r000607_13_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000607_7_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000607_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000607_7_1 + 7) & 127;
  }
  if ((sec_r000607_3_2 & 1) != 0)
  {
    if ((sec_r000607_13_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000607_7_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000607_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000607_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000607_12_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000607_6_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000607_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000607_6_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000607_12_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000607_6_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000607_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000607_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((sec_r000607_17_1 & 1) != 0)
  {
    if ((sec_r000607_12_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000607_8_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000607_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000607_8_1 + 7) & 127;
  }
  if ((sec_r000607_17_2 & 1) != 0)
  {
    if ((sec_r000607_12_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000607_8_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000607_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000607_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((sec_r000607_9_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000607_0_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000607_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000607_0_1 + 7) & 127;
  }
  if ((stage_v_146_2 & 1) != 0)
  {
    if ((sec_r000607_9_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000607_0_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000607_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000607_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000607_12_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000607_14_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000607_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000607_14_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000607_12_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000607_14_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000607_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000607_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((sec_r000607_10_1 & 1) != 0)
  {
    if ((sec_r000607_2_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000607_22_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000607_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000607_22_1 + 7) & 127;
  }
  if ((sec_r000607_10_2 & 1) != 0)
  {
    if ((sec_r000607_2_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000607_22_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000607_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000607_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000607_17_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000607_13_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000607_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000607_13_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000607_17_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000607_13_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000607_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000607_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r000607_2_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000607_1_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000607_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000607_1_1 + 7) & 127;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r000607_2_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000607_1_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000607_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000607_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000607_14_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000607_4_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000607_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000607_4_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000607_14_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000607_4_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000607_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000607_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r000607_10_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000607_0_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000607_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000607_0_1 + 7) & 127;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r000607_10_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000607_0_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000607_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000607_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000607_0_1 & 2) != 0)
    {
      stage_v_163_1 = (pub_r000607_2_1 + 31) & 127;
    }
    else
    {
      stage_v_163_1 = (pub_r000607_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_1 = (pub_r000607_2_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000607_0_2 & 2) != 0)
    {
      stage_v_163_2 = (pub_r000607_2_2 + 31) & 127;
    }
    else
    {
      stage_v_163_2 = (pub_r000607_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_2 = (pub_r000607_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((sec_r000607_18_1 & 2) != 0)
    {
      stage_v_164_1 = (pub_r000607_7_1 + 31) & 127;
    }
    else
    {
      stage_v_164_1 = (pub_r000607_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_1 = (pub_r000607_7_1 + 7) & 127;
  }
  if ((stage_v_148_2 & 1) != 0)
  {
    if ((sec_r000607_18_2 & 2) != 0)
    {
      stage_v_164_2 = (pub_r000607_7_2 + 31) & 127;
    }
    else
    {
      stage_v_164_2 = (pub_r000607_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_2 = (pub_r000607_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000607_17_1 & 2) != 0)
    {
      stage_v_165_1 = (pub_r000607_11_1 + 31) & 127;
    }
    else
    {
      stage_v_165_1 = (pub_r000607_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_1 = (pub_r000607_11_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000607_17_2 & 2) != 0)
    {
      stage_v_165_2 = (pub_r000607_11_2 + 31) & 127;
    }
    else
    {
      stage_v_165_2 = (pub_r000607_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_2 = (pub_r000607_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000607_1_1 & 2) != 0)
    {
      stage_v_166_1 = (pub_r000607_9_1 + 31) & 127;
    }
    else
    {
      stage_v_166_1 = (pub_r000607_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_1 = (pub_r000607_9_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000607_1_2 & 2) != 0)
    {
      stage_v_166_2 = (pub_r000607_9_2 + 31) & 127;
    }
    else
    {
      stage_v_166_2 = (pub_r000607_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_2 = (pub_r000607_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((sec_r000607_3_1 & 2) != 0)
    {
      stage_v_167_1 = (pub_r000607_14_1 + 31) & 127;
    }
    else
    {
      stage_v_167_1 = (pub_r000607_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_1 = (pub_r000607_14_1 + 7) & 127;
  }
  if ((stage_v_142_2 & 1) != 0)
  {
    if ((sec_r000607_3_2 & 2) != 0)
    {
      stage_v_167_2 = (pub_r000607_14_2 + 31) & 127;
    }
    else
    {
      stage_v_167_2 = (pub_r000607_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_2 = (pub_r000607_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000607_1_1 & 2) != 0)
    {
      stage_v_168_1 = (pub_r000607_17_1 + 31) & 127;
    }
    else
    {
      stage_v_168_1 = (pub_r000607_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_168_1 = (pub_r000607_17_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000607_1_2 & 2) != 0)
    {
      stage_v_168_2 = (pub_r000607_17_2 + 31) & 127;
    }
    else
    {
      stage_v_168_2 = (pub_r000607_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_168_2 = (pub_r000607_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  if ((sec_r000607_15_1 & 1) != 0)
  {
    if ((sec_r000607_18_1 & 2) != 0)
    {
      stage_v_169_1 = (pub_r000607_0_1 + 31) & 127;
    }
    else
    {
      stage_v_169_1 = (pub_r000607_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_169_1 = (pub_r000607_0_1 + 7) & 127;
  }
  if ((sec_r000607_15_2 & 1) != 0)
  {
    if ((sec_r000607_18_2 & 2) != 0)
    {
      stage_v_169_2 = (pub_r000607_0_2 + 31) & 127;
    }
    else
    {
      stage_v_169_2 = (pub_r000607_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_169_2 = (pub_r000607_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000607_3_1 & 2) != 0)
    {
      stage_v_170_1 = (pub_r000607_18_1 + 31) & 127;
    }
    else
    {
      stage_v_170_1 = (pub_r000607_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_170_1 = (pub_r000607_18_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000607_3_2 & 2) != 0)
    {
      stage_v_170_2 = (pub_r000607_18_2 + 31) & 127;
    }
    else
    {
      stage_v_170_2 = (pub_r000607_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_170_2 = (pub_r000607_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  if ((sec_r000607_11_1 & 1) != 0)
  {
    if ((sec_r000607_1_1 & 2) != 0)
    {
      stage_v_171_1 = (pub_r000607_12_1 + 31) & 127;
    }
    else
    {
      stage_v_171_1 = (pub_r000607_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_171_1 = (pub_r000607_12_1 + 7) & 127;
  }
  if ((sec_r000607_11_2 & 1) != 0)
  {
    if ((sec_r000607_1_2 & 2) != 0)
    {
      stage_v_171_2 = (pub_r000607_12_2 + 31) & 127;
    }
    else
    {
      stage_v_171_2 = (pub_r000607_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_171_2 = (pub_r000607_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000607_11_1 != sec_r000607_11_2);
  __CPROVER_assume(sec_r000607_9_1 != sec_r000607_9_2);
  __CPROVER_assume(pub_r000607_9_1 == pub_r000607_9_2);
  __CPROVER_assume(pub_r000607_6_1 == pub_r000607_6_2);
  __CPROVER_assume(pub_r000607_14_1 == pub_r000607_14_2);
  __CPROVER_assume(pub_r000607_2_1 == pub_r000607_2_2);
  __CPROVER_assume(sec_r000607_16_1 != sec_r000607_16_2);
  __CPROVER_assume(sec_r000607_12_1 != sec_r000607_12_2);
  __CPROVER_assume(pub_r000607_13_1 == pub_r000607_13_2);
  __CPROVER_assume(pub_r000607_19_1 == pub_r000607_19_2);
  __CPROVER_assume(pub_r000607_15_1 == pub_r000607_15_2);
  __CPROVER_assume(sec_r000607_2_1 != sec_r000607_2_2);
  __CPROVER_assume(pub_r000607_18_1 == pub_r000607_18_2);
  __CPROVER_assume(pub_r000607_11_1 == pub_r000607_11_2);
  __CPROVER_assume(pub_r000607_12_1 == pub_r000607_12_2);
  __CPROVER_assume(pub_r000607_7_1 == pub_r000607_7_2);
  __CPROVER_assume(sec_r000607_7_1 != sec_r000607_7_2);
  __CPROVER_assume(sec_r000607_3_1 != sec_r000607_3_2);
  __CPROVER_assume(pub_r000607_16_1 == pub_r000607_16_2);
  __CPROVER_assume(sec_r000607_0_1 != sec_r000607_0_2);
  __CPROVER_assume(pub_r000607_0_1 == pub_r000607_0_2);
  __CPROVER_assume(sec_r000607_15_1 != sec_r000607_15_2);
  __CPROVER_assume(pub_r000607_21_1 == pub_r000607_21_2);
  __CPROVER_assume(sec_r000607_13_1 != sec_r000607_13_2);
  __CPROVER_assume(pub_r000607_8_1 == pub_r000607_8_2);
  __CPROVER_assume(pub_r000607_1_1 == pub_r000607_1_2);
  __CPROVER_assume(pub_r000607_4_1 == pub_r000607_4_2);
  __CPROVER_assume(pub_r000607_17_1 == pub_r000607_17_2);
  __CPROVER_assume(sec_r000607_10_1 != sec_r000607_10_2);
  __CPROVER_assume(sec_r000607_8_1 != sec_r000607_8_2);
  __CPROVER_assume(sec_r000607_14_1 != sec_r000607_14_2);
  __CPROVER_assume(sec_r000607_1_1 != sec_r000607_1_2);
  __CPROVER_assume(pub_r000607_3_1 == pub_r000607_3_2);
  __CPROVER_assume(sec_r000607_18_1 != sec_r000607_18_2);
  __CPROVER_assume(sec_r000607_6_1 != sec_r000607_6_2);
  __CPROVER_assume(pub_r000607_5_1 == pub_r000607_5_2);
  __CPROVER_assume(pub_r000607_22_1 == pub_r000607_22_2);
  __CPROVER_assume(sec_r000607_17_1 != sec_r000607_17_2);
  __CPROVER_assume(sec_r000607_4_1 != sec_r000607_4_2);
  __CPROVER_assume(sec_r000607_5_1 != sec_r000607_5_2);
  __CPROVER_assume(pub_r000607_20_1 == pub_r000607_20_2);
  __CPROVER_assume(pub_r000607_10_1 == pub_r000607_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.dim == st_var_1_2.dim);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.stride == st_var_1_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.code == st_var_2_2.code);
  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.signature == st_var_2_2.signature);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.facility == st_var_2_2.facility);
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
}


