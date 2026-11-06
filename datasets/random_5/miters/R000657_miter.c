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
struct AudioFrame_R000657_5713_0
{
  int sample_rate;
  int gain;
  short envelope;
  int buffer[3];
};
struct Transaction_R000657_5713_1
{
  int balance;
  int status;
  int fee;
  int rate;
  int auth_code;
  int buffer[3];
};
struct MatrixBlock_R000657_5713_2
{
  int trace;
  unsigned char dim;
  int scale;
  int buffer[3];
};
struct EventLog_R000657_5713_3
{
  short signature;
  int facility;
  int code;
  int severity;
  int timestamp;
  int buffer[3];
};
union RegisterBank_R000657_5713_0
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
void fn_R000657_5713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000657_5713_2 st_1 = {0};
  struct MatrixBlock_R000657_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int bound_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_92_1) & 63;
  aux_2 = (aux_2 + bound_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_68_1 = local_arr_1[aux_1 % 3];
  int segment_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_68_2 * 2)) & 127;
  int bound_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_30_1)
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

  switch (bound_30_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_92_1 == bound_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_68_1 == segment_68_2);
  assert(bound_30_1 == bound_30_2);
}

int fn_R000657_5713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000657_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int bound_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_92) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_68 = local_arr[aux % 3];
  acc = (acc + (segment_68 * 2)) & 127;
  int bound_30 = (aux + st.buffer[1]) & 3;
  switch (bound_30)
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

void fn_R000657_5713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000657_5713_3 st_1 = {0};
  struct EventLog_R000657_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int sample_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_64_1)
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

  switch (sample_64_2)
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

  int tally_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_17_1) & 63;
  aux_2 = (aux_2 + tally_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_35_1 > 39)
  {
    acc_1 = ((acc_1 + (stride_35_1 * 2)) + 5) & 127;
    aux_1 ^= stride_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_35_2 > 39)
  {
    acc_2 = ((acc_2 + (stride_35_2 * 2)) + 5) & 127;
    aux_2 ^= stride_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_64_1 == sample_64_2);
  assert(tally_17_1 == tally_17_2);
  assert(stride_35_1 == stride_35_2);
}

int fn_R000657_5713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000657_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int sample_64 = (aux + st.buffer[1]) & 3;
  switch (sample_64)
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

  int tally_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_17) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_35 > 39)
  {
    acc = ((acc + (stride_35 * 2)) + 5) & 127;
    aux ^= stride_35 & 15;
  }
  else
  {
    acc = ((acc - stride_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000657_5713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000657_5713_1 st_1 = {0};
  struct Transaction_R000657_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_82_1 > 39)
  {
    acc_1 = ((acc_1 + (delta_82_1 * 2)) + 5) & 127;
    aux_1 ^= delta_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_82_2 > 39)
  {
    acc_2 = ((acc_2 + (delta_82_2 * 2)) + 5) & 127;
    aux_2 ^= delta_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_82_1 == delta_82_2);
}

int fn_R000657_5713_2(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000657_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_82 > 39)
  {
    acc = ((acc + (delta_82 * 2)) + 5) & 127;
    aux ^= delta_82 & 15;
  }
  else
  {
    acc = ((acc - delta_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000657_5713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000657_5713_2 st_1 = {0};
  struct MatrixBlock_R000657_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int threshold_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_29_1 > 10)
  {
    acc_1 = ((acc_1 + (threshold_29_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_29_2 > 10)
  {
    acc_2 = ((acc_2 + (threshold_29_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_12_1 = local_arr_1[aux_1 % 3];
  int vector_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_12_2 * 2)) & 127;
  int metric_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_33_1) & 63;
  aux_2 = (aux_2 + metric_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_74_1)
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

  switch (weight_74_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_29_1 == threshold_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_12_1 == vector_12_2);
  assert(metric_33_1 == metric_33_2);
  assert(weight_74_1 == weight_74_2);
}

int fn_R000657_5713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000657_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int threshold_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_29 > 10)
  {
    acc = ((acc + (threshold_29 * 2)) + 5) & 127;
    aux ^= threshold_29 & 15;
  }
  else
  {
    acc = ((acc - threshold_29) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_12 = local_arr[aux % 3];
  acc = (acc + (vector_12 * 2)) & 127;
  int metric_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_33) & 63;
  acc ^= aux;
  int weight_74 = (aux + st.buffer[1]) & 3;
  switch (weight_74)
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

void fn_R000657_5713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000657_5713_2 st_1 = {0};
  struct MatrixBlock_R000657_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int damping_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_14_1) & 63;
  aux_2 = (aux_2 + damping_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_35_1 > 38)
  {
    acc_1 = ((acc_1 + (residue_35_1 * 2)) + 5) & 127;
    aux_1 ^= residue_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_35_2 > 38)
  {
    acc_2 = ((acc_2 + (residue_35_2 * 2)) + 5) & 127;
    aux_2 ^= residue_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_14_1 == damping_14_2);
  assert(residue_35_1 == residue_35_2);
}

int fn_R000657_5713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000657_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int damping_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_14) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_35 > 38)
  {
    acc = ((acc + (residue_35 * 2)) + 5) & 127;
    aux ^= residue_35 & 15;
  }
  else
  {
    acc = ((acc - residue_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000657_5713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000657_5713_3 st_1 = {0};
  struct EventLog_R000657_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_80_1 > 46)
  {
    acc_1 = ((acc_1 + (delta_80_1 * 2)) + 5) & 127;
    aux_1 ^= delta_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_80_2 > 46)
  {
    acc_2 = ((acc_2 + (delta_80_2 * 2)) + 5) & 127;
    aux_2 ^= delta_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_80_1 == delta_80_2);
}

int fn_R000657_5713_5(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000657_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_80 > 46)
  {
    acc = ((acc + (delta_80 * 2)) + 5) & 127;
    aux ^= delta_80 & 15;
  }
  else
  {
    acc = ((acc - delta_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000657_5713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000657_5713_1 st_1 = {0};
  struct Transaction_R000657_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int metric_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_61_1) & 63;
  aux_2 = (aux_2 + metric_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_44_1 > 29)
  {
    acc_1 = ((acc_1 + (anchor_44_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_44_2 > 29)
  {
    acc_2 = ((acc_2 + (anchor_44_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_61_1 == metric_61_2);
  assert(anchor_44_1 == anchor_44_2);
}

int fn_R000657_5713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000657_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int metric_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_61) & 63;
  acc ^= aux;
  int anchor_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_44 > 29)
  {
    acc = ((acc + (anchor_44 * 2)) + 5) & 127;
    aux ^= anchor_44 & 15;
  }
  else
  {
    acc = ((acc - anchor_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000657_5713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000657_5713_3 st_1 = {0};
  struct EventLog_R000657_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_56_1) & 63;
  aux_2 = (aux_2 + parity_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_56_1 == parity_56_2);
}

int fn_R000657_5713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000657_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000657_5713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000657_5713_2 st_1 = {0};
  struct MatrixBlock_R000657_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int index_reg_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_94_1)
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

  switch (index_reg_94_2)
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

  int vector_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_14_1 > 23)
  {
    acc_1 = ((acc_1 + (vector_14_1 * 2)) + 5) & 127;
    aux_1 ^= vector_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_14_2 > 23)
  {
    acc_2 = ((acc_2 + (vector_14_2 * 2)) + 5) & 127;
    aux_2 ^= vector_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_14_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_94_1 == index_reg_94_2);
  assert(vector_14_1 == vector_14_2);
}

int fn_R000657_5713_8(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000657_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int index_reg_94 = (aux + st.buffer[1]) & 3;
  switch (index_reg_94)
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

  int vector_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_14 > 23)
  {
    acc = ((acc + (vector_14 * 2)) + 5) & 127;
    aux ^= vector_14 & 15;
  }
  else
  {
    acc = ((acc - vector_14) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000657_5713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000657_5713_3 st_1 = {0};
  struct EventLog_R000657_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int accumulator_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_13_1 > 31)
  {
    acc_1 = ((acc_1 + (accumulator_13_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_13_2 > 31)
  {
    acc_2 = ((acc_2 + (accumulator_13_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_98_1 = local_arr_1[aux_1 % 3];
  int index_reg_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_98_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_13_1 == accumulator_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_98_1 == index_reg_98_2);
}

int fn_R000657_5713_9(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000657_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int accumulator_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_13 > 31)
  {
    acc = ((acc + (accumulator_13 * 2)) + 5) & 127;
    aux ^= accumulator_13 & 15;
  }
  else
  {
    acc = ((acc - accumulator_13) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_98 = local_arr[aux % 3];
  acc = (acc + (index_reg_98 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000657_5713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000657_5713_1 st_1 = {0};
  struct Transaction_R000657_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int factor_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_71_1)
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

  switch (factor_71_2)
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
  int delta_77_1 = local_arr_1[aux_1 % 3];
  int delta_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_77_2 * 2)) & 127;
  int tally_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_32_1) & 63;
  aux_2 = (aux_2 + tally_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_71_1 == factor_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_77_1 == delta_77_2);
  assert(tally_32_1 == tally_32_2);
}

int fn_R000657_5713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000657_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int factor_71 = (aux + st.buffer[1]) & 3;
  switch (factor_71)
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
  int delta_77 = local_arr[aux % 3];
  acc = (acc + (delta_77 * 2)) & 127;
  int tally_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_32) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000657_5713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000657_5713_1 st_1 = {0};
  struct Transaction_R000657_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int checksum_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_20_1 > 44)
  {
    acc_1 = ((acc_1 + (checksum_20_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_20_2 > 44)
  {
    acc_2 = ((acc_2 + (checksum_20_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_20_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_20_1 == checksum_20_2);
}

int fn_R000657_5713_11(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000657_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int checksum_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_20 > 44)
  {
    acc = ((acc + (checksum_20 * 2)) + 5) & 127;
    aux ^= checksum_20 & 15;
  }
  else
  {
    acc = ((acc - checksum_20) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000657_5713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000657_5713_2 st_1 = {0};
  struct MatrixBlock_R000657_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_49_1 = local_arr_1[aux_1 % 3];
  int delta_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_49_2 * 2)) & 127;
  int accumulator_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_33_1) & 63;
  aux_2 = (aux_2 + accumulator_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_29_1 > 32)
  {
    acc_1 = ((acc_1 + (quotient_29_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_29_2 > 32)
  {
    acc_2 = ((acc_2 + (quotient_29_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_29_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
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

  assert(delta_49_1 == delta_49_2);
  assert(accumulator_33_1 == accumulator_33_2);
  assert(quotient_29_1 == quotient_29_2);
}

int fn_R000657_5713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000657_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int delta_49 = local_arr[aux % 3];
  acc = (acc + (delta_49 * 2)) & 127;
  int accumulator_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_33) & 63;
  acc ^= aux;
  int quotient_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_29 > 32)
  {
    acc = ((acc + (quotient_29 * 2)) + 5) & 127;
    aux ^= quotient_29 & 15;
  }
  else
  {
    acc = ((acc - quotient_29) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000657_5713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000657_5713_3 st_1 = {0};
  struct EventLog_R000657_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_57_1 = local_arr_1[aux_1 % 3];
  int cursor_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_57_2 * 2)) & 127;
  int threshold_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_56_1)
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

  switch (threshold_56_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_57_1 == cursor_57_2);
  assert(threshold_56_1 == threshold_56_2);
}

int fn_R000657_5713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000657_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int cursor_57 = local_arr[aux % 3];
  acc = (acc + (cursor_57 * 2)) & 127;
  int threshold_56 = (aux + st.buffer[1]) & 3;
  switch (threshold_56)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000657_5713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000657_5713_0 st_1 = {0};
  struct AudioFrame_R000657_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int anchor_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_23_1)
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

  switch (anchor_23_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_19_1 = local_arr_1[aux_1 % 3];
  int mask_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_23_1 == anchor_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_19_1 == mask_19_2);
}

int fn_R000657_5713_14(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000657_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int anchor_23 = (aux + st.buffer[1]) & 3;
  switch (anchor_23)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_19 = local_arr[aux % 3];
  acc = (acc + (mask_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000657_5713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000657_5713_2 st_1 = {0};
  struct MatrixBlock_R000657_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_43_1 = local_arr_1[aux_1 % 3];
  int factor_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_43_2 * 2)) & 127;
  int checksum_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_13_1 > 35)
  {
    acc_1 = ((acc_1 + (checksum_13_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_13_2 > 35)
  {
    acc_2 = ((acc_2 + (checksum_13_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_64_1) & 63;
  aux_2 = (aux_2 + weight_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
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

  assert(factor_43_1 == factor_43_2);
  assert(checksum_13_1 == checksum_13_2);
  assert(weight_64_1 == weight_64_2);
}

int fn_R000657_5713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000657_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int factor_43 = local_arr[aux % 3];
  acc = (acc + (factor_43 * 2)) & 127;
  int checksum_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_13 > 35)
  {
    acc = ((acc + (checksum_13 * 2)) + 5) & 127;
    aux ^= checksum_13 & 15;
  }
  else
  {
    acc = ((acc - checksum_13) + 11) & 127;
    aux += 3;
  }
  int weight_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000657_5713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000657_5713_0 st_1 = {0};
  struct AudioFrame_R000657_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_99_1 > 33)
  {
    acc_1 = ((acc_1 + (damping_99_1 * 2)) + 5) & 127;
    aux_1 ^= damping_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_99_2 > 33)
  {
    acc_2 = ((acc_2 + (damping_99_2 * 2)) + 5) & 127;
    aux_2 ^= damping_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_99_1 == damping_99_2);
}

int fn_R000657_5713_16(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000657_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_99 > 33)
  {
    acc = ((acc + (damping_99 * 2)) + 5) & 127;
    aux ^= damping_99 & 15;
  }
  else
  {
    acc = ((acc - damping_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000657_0_1;
  int sec_r000657_0_2;
  int sec_r000657_1_1;
  int sec_r000657_1_2;
  int sec_r000657_2_1;
  int sec_r000657_2_2;
  int sec_r000657_3_1;
  int sec_r000657_3_2;
  int sec_r000657_4_1;
  int sec_r000657_4_2;
  int sec_r000657_5_1;
  int sec_r000657_5_2;
  int sec_r000657_6_1;
  int sec_r000657_6_2;
  int sec_r000657_7_1;
  int sec_r000657_7_2;
  int sec_r000657_8_1;
  int sec_r000657_8_2;
  int sec_r000657_9_1;
  int sec_r000657_9_2;
  int sec_r000657_10_1;
  int sec_r000657_10_2;
  int sec_r000657_11_1;
  int sec_r000657_11_2;
  int sec_r000657_12_1;
  int sec_r000657_12_2;
  int sec_r000657_13_1;
  int sec_r000657_13_2;
  int sec_r000657_14_1;
  int sec_r000657_14_2;
  int sec_r000657_15_1;
  int sec_r000657_15_2;
  int pub_r000657_0_1;
  int pub_r000657_0_2;
  int pub_r000657_1_1;
  int pub_r000657_1_2;
  int pub_r000657_2_1;
  int pub_r000657_2_2;
  int pub_r000657_3_1;
  int pub_r000657_3_2;
  int pub_r000657_4_1;
  int pub_r000657_4_2;
  int pub_r000657_5_1;
  int pub_r000657_5_2;
  int pub_r000657_6_1;
  int pub_r000657_6_2;
  int pub_r000657_7_1;
  int pub_r000657_7_2;
  int pub_r000657_8_1;
  int pub_r000657_8_2;
  int pub_r000657_9_1;
  int pub_r000657_9_2;
  int pub_r000657_10_1;
  int pub_r000657_10_2;
  int pub_r000657_11_1;
  int pub_r000657_11_2;
  int pub_r000657_12_1;
  int pub_r000657_12_2;
  int pub_r000657_13_1;
  int pub_r000657_13_2;
  int pub_r000657_14_1;
  int pub_r000657_14_2;
  int pub_r000657_15_1;
  int pub_r000657_15_2;
  int pub_r000657_16_1;
  int pub_r000657_16_2;
  int pub_r000657_17_1;
  int pub_r000657_17_2;
  int pub_r000657_18_1;
  int pub_r000657_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000657_0_1 >= (-100)) && (pub_r000657_0_1 <= 100));
  __CPROVER_assume((pub_r000657_0_2 >= (-100)) && (pub_r000657_0_2 <= 100));
  __CPROVER_assume((pub_r000657_1_1 >= (-100)) && (pub_r000657_1_1 <= 100));
  __CPROVER_assume((pub_r000657_1_2 >= (-100)) && (pub_r000657_1_2 <= 100));
  __CPROVER_assume((pub_r000657_2_1 >= (-100)) && (pub_r000657_2_1 <= 100));
  __CPROVER_assume((pub_r000657_2_2 >= (-100)) && (pub_r000657_2_2 <= 100));
  __CPROVER_assume((pub_r000657_3_1 >= (-100)) && (pub_r000657_3_1 <= 100));
  __CPROVER_assume((pub_r000657_3_2 >= (-100)) && (pub_r000657_3_2 <= 100));
  __CPROVER_assume((pub_r000657_4_1 >= (-100)) && (pub_r000657_4_1 <= 100));
  __CPROVER_assume((pub_r000657_4_2 >= (-100)) && (pub_r000657_4_2 <= 100));
  __CPROVER_assume((pub_r000657_5_1 >= (-100)) && (pub_r000657_5_1 <= 100));
  __CPROVER_assume((pub_r000657_5_2 >= (-100)) && (pub_r000657_5_2 <= 100));
  __CPROVER_assume((pub_r000657_6_1 >= (-100)) && (pub_r000657_6_1 <= 100));
  __CPROVER_assume((pub_r000657_6_2 >= (-100)) && (pub_r000657_6_2 <= 100));
  __CPROVER_assume((pub_r000657_7_1 >= (-100)) && (pub_r000657_7_1 <= 100));
  __CPROVER_assume((pub_r000657_7_2 >= (-100)) && (pub_r000657_7_2 <= 100));
  __CPROVER_assume((pub_r000657_8_1 >= (-100)) && (pub_r000657_8_1 <= 100));
  __CPROVER_assume((pub_r000657_8_2 >= (-100)) && (pub_r000657_8_2 <= 100));
  __CPROVER_assume((pub_r000657_9_1 >= (-100)) && (pub_r000657_9_1 <= 100));
  __CPROVER_assume((pub_r000657_9_2 >= (-100)) && (pub_r000657_9_2 <= 100));
  __CPROVER_assume((pub_r000657_10_1 >= (-100)) && (pub_r000657_10_1 <= 100));
  __CPROVER_assume((pub_r000657_10_2 >= (-100)) && (pub_r000657_10_2 <= 100));
  __CPROVER_assume((pub_r000657_11_1 >= (-100)) && (pub_r000657_11_1 <= 100));
  __CPROVER_assume((pub_r000657_11_2 >= (-100)) && (pub_r000657_11_2 <= 100));
  __CPROVER_assume((pub_r000657_12_1 >= (-100)) && (pub_r000657_12_1 <= 100));
  __CPROVER_assume((pub_r000657_12_2 >= (-100)) && (pub_r000657_12_2 <= 100));
  __CPROVER_assume((pub_r000657_13_1 >= (-100)) && (pub_r000657_13_1 <= 100));
  __CPROVER_assume((pub_r000657_13_2 >= (-100)) && (pub_r000657_13_2 <= 100));
  __CPROVER_assume((pub_r000657_14_1 >= (-100)) && (pub_r000657_14_1 <= 100));
  __CPROVER_assume((pub_r000657_14_2 >= (-100)) && (pub_r000657_14_2 <= 100));
  __CPROVER_assume((pub_r000657_15_1 >= (-100)) && (pub_r000657_15_1 <= 100));
  __CPROVER_assume((pub_r000657_15_2 >= (-100)) && (pub_r000657_15_2 <= 100));
  __CPROVER_assume((pub_r000657_16_1 >= (-100)) && (pub_r000657_16_1 <= 100));
  __CPROVER_assume((pub_r000657_16_2 >= (-100)) && (pub_r000657_16_2 <= 100));
  __CPROVER_assume((pub_r000657_17_1 >= (-100)) && (pub_r000657_17_1 <= 100));
  __CPROVER_assume((pub_r000657_17_2 >= (-100)) && (pub_r000657_17_2 <= 100));
  __CPROVER_assume((pub_r000657_18_1 >= (-100)) && (pub_r000657_18_1 <= 100));
  __CPROVER_assume((pub_r000657_18_2 >= (-100)) && (pub_r000657_18_2 <= 100));
  __CPROVER_assume((sec_r000657_0_1 >= 0) && (sec_r000657_0_1 <= 255));
  __CPROVER_assume((sec_r000657_0_2 >= 0) && (sec_r000657_0_2 <= 255));
  __CPROVER_assume((sec_r000657_1_1 >= 0) && (sec_r000657_1_1 <= 255));
  __CPROVER_assume((sec_r000657_1_2 >= 0) && (sec_r000657_1_2 <= 255));
  __CPROVER_assume((sec_r000657_2_1 >= 0) && (sec_r000657_2_1 <= 255));
  __CPROVER_assume((sec_r000657_2_2 >= 0) && (sec_r000657_2_2 <= 255));
  __CPROVER_assume((sec_r000657_3_1 >= 0) && (sec_r000657_3_1 <= 255));
  __CPROVER_assume((sec_r000657_3_2 >= 0) && (sec_r000657_3_2 <= 255));
  __CPROVER_assume((sec_r000657_4_1 >= 0) && (sec_r000657_4_1 <= 255));
  __CPROVER_assume((sec_r000657_4_2 >= 0) && (sec_r000657_4_2 <= 255));
  __CPROVER_assume((sec_r000657_5_1 >= 0) && (sec_r000657_5_1 <= 255));
  __CPROVER_assume((sec_r000657_5_2 >= 0) && (sec_r000657_5_2 <= 255));
  __CPROVER_assume((sec_r000657_6_1 >= 0) && (sec_r000657_6_1 <= 255));
  __CPROVER_assume((sec_r000657_6_2 >= 0) && (sec_r000657_6_2 <= 255));
  __CPROVER_assume((sec_r000657_7_1 >= 0) && (sec_r000657_7_1 <= 255));
  __CPROVER_assume((sec_r000657_7_2 >= 0) && (sec_r000657_7_2 <= 255));
  __CPROVER_assume((sec_r000657_8_1 >= 0) && (sec_r000657_8_1 <= 255));
  __CPROVER_assume((sec_r000657_8_2 >= 0) && (sec_r000657_8_2 <= 255));
  __CPROVER_assume((sec_r000657_9_1 >= 0) && (sec_r000657_9_1 <= 255));
  __CPROVER_assume((sec_r000657_9_2 >= 0) && (sec_r000657_9_2 <= 255));
  __CPROVER_assume((sec_r000657_10_1 >= 0) && (sec_r000657_10_1 <= 255));
  __CPROVER_assume((sec_r000657_10_2 >= 0) && (sec_r000657_10_2 <= 255));
  __CPROVER_assume((sec_r000657_11_1 >= 0) && (sec_r000657_11_1 <= 255));
  __CPROVER_assume((sec_r000657_11_2 >= 0) && (sec_r000657_11_2 <= 255));
  __CPROVER_assume((sec_r000657_12_1 >= 0) && (sec_r000657_12_1 <= 255));
  __CPROVER_assume((sec_r000657_12_2 >= 0) && (sec_r000657_12_2 <= 255));
  __CPROVER_assume((sec_r000657_13_1 >= 0) && (sec_r000657_13_1 <= 255));
  __CPROVER_assume((sec_r000657_13_2 >= 0) && (sec_r000657_13_2 <= 255));
  __CPROVER_assume((sec_r000657_14_1 >= 0) && (sec_r000657_14_1 <= 255));
  __CPROVER_assume((sec_r000657_14_2 >= 0) && (sec_r000657_14_2 <= 255));
  __CPROVER_assume((sec_r000657_15_1 >= 0) && (sec_r000657_15_1 <= 255));
  __CPROVER_assume((sec_r000657_15_2 >= 0) && (sec_r000657_15_2 <= 255));
  struct AudioFrame_R000657_5713_0 st_var_0_1 = {0};
  struct AudioFrame_R000657_5713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000657_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000657_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000657_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000657_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000657_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000657_0_2 + 7) & 15;
  struct Transaction_R000657_5713_1 st_var_1_1 = {0};
  struct Transaction_R000657_5713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000657_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000657_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000657_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000657_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000657_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000657_0_2 + 9) & 15;
  struct MatrixBlock_R000657_5713_2 st_var_2_1 = {0};
  struct MatrixBlock_R000657_5713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000657_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000657_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000657_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000657_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000657_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000657_0_2 + 11) & 15;
  struct EventLog_R000657_5713_3 st_var_3_1 = {0};
  struct EventLog_R000657_5713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000657_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000657_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000657_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000657_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000657_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000657_0_2 + 13) & 15;
  union RegisterBank_R000657_5713_0 u_var_1;
  union RegisterBank_R000657_5713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 44)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 44)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  int stage_v_3_1 = ((st_var_3_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_3_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 29)
    {
      chk_sum_1 ^= stage_v_3_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_3_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 29)
    {
      chk_sum_2 ^= stage_v_3_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
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
  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 45)
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
  if (stage_v_9_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 45)
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
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = (st_var_3_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_3_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = (st_var_0_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_0_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  int stage_v_22_1 = (st_var_2_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_2_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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
  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 39)
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
  if (stage_v_25_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 39)
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
  int stage_v_26_1 = (st_var_2_1.buffer[0] ^ 29) & 3;
  int stage_v_26_2 = (st_var_2_2.buffer[0] ^ 29) & 3;
  switch (stage_v_26_1)
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

  switch (stage_v_26_2)
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

  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 28) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 29) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  int stage_v_29_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_29_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_31_1 = (st_var_3_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_3_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 33) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = (st_var_2_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_2_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_37_1 = ((stage_v_37_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_37_2 = ((stage_v_37_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (st_var_2_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_2_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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

  int stage_v_39_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_39_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_40_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_40_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  int stage_v_42_1 = (st_var_2_1.buffer[0] ^ 45) & 3;
  int stage_v_42_2 = (st_var_2_2.buffer[0] ^ 45) & 3;
  switch (stage_v_42_1)
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

  switch (stage_v_42_2)
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

  int stage_v_43_1 = table_1[3];
  int stage_v_43_2 = table_2[3];
  table_1[3] = (table_1[0] + 87) & 63;
  table_2[3] = (table_2[0] + 87) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((sec_r000657_12_1 & 1) != 0)
  {
    if ((sec_r000657_2_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000657_6_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000657_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000657_6_1 + 7) & 127;
  }
  if ((sec_r000657_12_2 & 1) != 0)
  {
    if ((sec_r000657_2_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000657_6_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000657_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000657_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((sec_r000657_15_1 & 1) != 0)
  {
    if ((sec_r000657_15_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000657_5_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000657_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000657_5_1 + 7) & 127;
  }
  if ((sec_r000657_15_2 & 1) != 0)
  {
    if ((sec_r000657_15_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000657_5_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000657_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000657_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000657_1_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000657_11_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000657_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000657_11_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000657_1_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000657_11_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000657_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000657_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000657_5_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000657_2_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000657_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000657_2_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000657_5_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000657_2_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000657_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000657_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000657_7_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000657_17_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000657_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000657_17_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000657_7_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000657_17_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000657_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000657_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000657_9_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000657_10_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000657_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000657_10_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000657_9_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000657_10_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000657_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000657_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000657_8_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000657_14_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000657_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000657_14_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000657_8_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000657_14_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000657_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000657_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((sec_r000657_7_1 & 1) != 0)
  {
    if ((sec_r000657_1_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000657_13_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000657_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000657_13_1 + 7) & 127;
  }
  if ((sec_r000657_7_2 & 1) != 0)
  {
    if ((sec_r000657_1_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000657_13_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000657_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000657_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((sec_r000657_0_1 & 1) != 0)
  {
    if ((sec_r000657_9_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000657_14_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000657_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000657_14_1 + 7) & 127;
  }
  if ((sec_r000657_0_2 & 1) != 0)
  {
    if ((sec_r000657_9_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000657_14_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000657_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000657_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((sec_r000657_12_1 & 1) != 0)
  {
    if ((sec_r000657_11_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000657_7_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000657_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000657_7_1 + 7) & 127;
  }
  if ((sec_r000657_12_2 & 1) != 0)
  {
    if ((sec_r000657_11_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000657_7_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000657_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000657_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000657_7_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000657_12_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000657_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000657_12_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000657_7_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000657_12_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000657_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000657_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000657_1_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000657_8_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000657_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000657_8_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000657_1_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000657_8_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000657_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000657_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000657_11_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000657_11_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000657_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000657_11_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000657_11_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000657_11_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000657_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000657_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000657_2_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000657_1_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000657_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000657_1_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000657_2_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000657_1_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000657_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000657_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000657_6_1 & 1) != 0)
  {
    if ((sec_r000657_5_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000657_4_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000657_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000657_4_1 + 7) & 127;
  }
  if ((sec_r000657_6_2 & 1) != 0)
  {
    if ((sec_r000657_5_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000657_4_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000657_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000657_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000657_0_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000657_14_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000657_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000657_14_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000657_0_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000657_14_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000657_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000657_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000657_15_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000657_7_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000657_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000657_7_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000657_15_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000657_7_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000657_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000657_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000657_15_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000657_15_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000657_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000657_15_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000657_15_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000657_15_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000657_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000657_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000657_15_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000657_5_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000657_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000657_5_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000657_15_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000657_5_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000657_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000657_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000657_14_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000657_3_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000657_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000657_3_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000657_14_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000657_3_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000657_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000657_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000657_6_1 & 1) != 0)
  {
    if ((sec_r000657_13_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000657_12_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000657_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000657_12_1 + 7) & 127;
  }
  if ((sec_r000657_6_2 & 1) != 0)
  {
    if ((sec_r000657_13_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000657_12_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000657_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000657_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000657_4_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000657_11_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000657_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000657_11_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000657_4_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000657_11_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000657_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000657_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000657_8_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000657_10_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000657_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000657_10_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000657_8_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000657_10_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000657_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000657_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000657_13_1 & 1) != 0)
  {
    if ((sec_r000657_10_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000657_3_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000657_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000657_3_1 + 7) & 127;
  }
  if ((sec_r000657_13_2 & 1) != 0)
  {
    if ((sec_r000657_10_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000657_3_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000657_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000657_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((sec_r000657_3_1 & 1) != 0)
  {
    if ((sec_r000657_13_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000657_17_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000657_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000657_17_1 + 7) & 127;
  }
  if ((sec_r000657_3_2 & 1) != 0)
  {
    if ((sec_r000657_13_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000657_17_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000657_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000657_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000657_4_1 & 1) != 0)
  {
    if ((sec_r000657_6_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000657_2_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000657_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000657_2_1 + 7) & 127;
  }
  if ((sec_r000657_4_2 & 1) != 0)
  {
    if ((sec_r000657_6_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000657_2_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000657_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000657_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000657_10_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000657_1_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000657_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000657_1_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000657_10_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000657_1_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000657_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000657_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000657_12_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000657_5_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000657_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000657_5_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000657_12_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000657_5_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000657_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000657_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000657_12_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000657_17_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000657_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000657_17_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000657_12_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000657_17_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000657_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000657_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000657_6_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000657_11_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000657_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000657_11_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000657_6_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000657_11_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000657_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000657_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000657_4_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000657_2_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000657_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000657_2_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000657_4_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000657_2_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000657_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000657_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000657_11_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000657_3_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000657_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000657_3_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000657_11_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000657_3_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000657_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000657_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000657_11_1 & 1) != 0)
  {
    if ((sec_r000657_5_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000657_16_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000657_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000657_16_1 + 7) & 127;
  }
  if ((sec_r000657_11_2 & 1) != 0)
  {
    if ((sec_r000657_5_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000657_16_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000657_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000657_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000657_0_1 & 1) != 0)
  {
    if ((sec_r000657_13_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000657_14_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000657_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000657_14_1 + 7) & 127;
  }
  if ((sec_r000657_0_2 & 1) != 0)
  {
    if ((sec_r000657_13_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000657_14_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000657_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000657_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000657_1_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000657_18_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000657_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000657_18_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000657_1_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000657_18_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000657_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000657_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000657_7_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000657_15_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000657_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000657_15_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000657_7_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000657_15_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000657_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000657_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000657_8_1 & 1) != 0)
  {
    if ((sec_r000657_7_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000657_2_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000657_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000657_2_1 + 7) & 127;
  }
  if ((sec_r000657_8_2 & 1) != 0)
  {
    if ((sec_r000657_7_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000657_2_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000657_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000657_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000657_14_1 & 1) != 0)
  {
    if ((sec_r000657_15_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000657_7_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000657_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000657_7_1 + 7) & 127;
  }
  if ((sec_r000657_14_2 & 1) != 0)
  {
    if ((sec_r000657_15_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000657_7_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000657_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000657_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000657_7_1 & 1) != 0)
  {
    if ((sec_r000657_3_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000657_14_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000657_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000657_14_1 + 7) & 127;
  }
  if ((sec_r000657_7_2 & 1) != 0)
  {
    if ((sec_r000657_3_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000657_14_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000657_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000657_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000657_1_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000657_9_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000657_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000657_9_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000657_1_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000657_9_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000657_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000657_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000657_14_1 & 1) != 0)
  {
    if ((sec_r000657_9_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000657_13_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000657_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000657_13_1 + 7) & 127;
  }
  if ((sec_r000657_14_2 & 1) != 0)
  {
    if ((sec_r000657_9_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000657_13_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000657_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000657_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000657_12_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000657_4_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000657_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000657_4_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000657_12_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000657_4_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000657_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000657_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000657_7_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000657_16_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000657_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000657_16_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000657_7_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000657_16_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000657_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000657_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000657_14_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000657_2_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000657_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000657_2_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000657_14_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000657_2_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000657_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000657_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000657_13_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000657_4_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000657_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000657_4_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000657_13_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000657_4_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000657_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000657_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000657_6_1 & 1) != 0)
  {
    if ((sec_r000657_0_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000657_1_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000657_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000657_1_1 + 7) & 127;
  }
  if ((sec_r000657_6_2 & 1) != 0)
  {
    if ((sec_r000657_0_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000657_1_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000657_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000657_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000657_7_1 & 1) != 0)
  {
    if ((sec_r000657_7_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000657_2_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000657_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000657_2_1 + 7) & 127;
  }
  if ((sec_r000657_7_2 & 1) != 0)
  {
    if ((sec_r000657_7_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000657_2_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000657_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000657_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000657_7_1 & 1) != 0)
  {
    if ((sec_r000657_13_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000657_3_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000657_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000657_3_1 + 7) & 127;
  }
  if ((sec_r000657_7_2 & 1) != 0)
  {
    if ((sec_r000657_13_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000657_3_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000657_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000657_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000657_3_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000657_7_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000657_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000657_7_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000657_3_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000657_7_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000657_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000657_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000657_0_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000657_6_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000657_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000657_6_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000657_0_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000657_6_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000657_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000657_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000657_4_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000657_9_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000657_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000657_9_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000657_4_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000657_9_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000657_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000657_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000657_11_1 & 1) != 0)
  {
    if ((sec_r000657_6_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000657_0_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000657_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000657_0_1 + 7) & 127;
  }
  if ((sec_r000657_11_2 & 1) != 0)
  {
    if ((sec_r000657_6_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000657_0_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000657_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000657_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000657_13_1 & 1) != 0)
  {
    if ((sec_r000657_0_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000657_7_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000657_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000657_7_1 + 7) & 127;
  }
  if ((sec_r000657_13_2 & 1) != 0)
  {
    if ((sec_r000657_0_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000657_7_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000657_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000657_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000657_0_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000657_5_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000657_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000657_5_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000657_0_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000657_5_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000657_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000657_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000657_0_1 & 1) != 0)
  {
    if ((sec_r000657_14_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000657_9_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000657_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000657_9_1 + 7) & 127;
  }
  if ((sec_r000657_0_2 & 1) != 0)
  {
    if ((sec_r000657_14_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000657_9_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000657_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000657_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000657_11_1 & 1) != 0)
  {
    if ((sec_r000657_11_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000657_14_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000657_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000657_14_1 + 7) & 127;
  }
  if ((sec_r000657_11_2 & 1) != 0)
  {
    if ((sec_r000657_11_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000657_14_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000657_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000657_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000657_11_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000657_1_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000657_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000657_1_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000657_11_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000657_1_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000657_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000657_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000657_6_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000657_14_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000657_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000657_14_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000657_6_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000657_14_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000657_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000657_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000657_3_1 & 1) != 0)
  {
    if ((sec_r000657_15_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000657_13_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000657_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000657_13_1 + 7) & 127;
  }
  if ((sec_r000657_3_2 & 1) != 0)
  {
    if ((sec_r000657_15_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000657_13_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000657_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000657_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000657_9_1 & 1) != 0)
  {
    if ((sec_r000657_11_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000657_4_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000657_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000657_4_1 + 7) & 127;
  }
  if ((sec_r000657_9_2 & 1) != 0)
  {
    if ((sec_r000657_11_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000657_4_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000657_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000657_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000657_1_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000657_6_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000657_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000657_6_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000657_1_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000657_6_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000657_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000657_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000657_10_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000657_1_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000657_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000657_1_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000657_10_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000657_1_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000657_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000657_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000657_6_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000657_17_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000657_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000657_17_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000657_6_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000657_17_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000657_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000657_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000657_15_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000657_12_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000657_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000657_12_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000657_15_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000657_12_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000657_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000657_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000657_4_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000657_1_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000657_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000657_1_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000657_4_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000657_1_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000657_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000657_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000657_8_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000657_3_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000657_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000657_3_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000657_8_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000657_3_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000657_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000657_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000657_0_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000657_15_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000657_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000657_15_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000657_0_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000657_15_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000657_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000657_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000657_3_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000657_14_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000657_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000657_14_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000657_3_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000657_14_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000657_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000657_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000657_14_1 & 1) != 0)
  {
    if ((sec_r000657_5_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000657_6_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000657_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000657_6_1 + 7) & 127;
  }
  if ((sec_r000657_14_2 & 1) != 0)
  {
    if ((sec_r000657_5_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000657_6_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000657_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000657_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000657_9_1 & 1) != 0)
  {
    if ((sec_r000657_4_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000657_8_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000657_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000657_8_1 + 7) & 127;
  }
  if ((sec_r000657_9_2 & 1) != 0)
  {
    if ((sec_r000657_4_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000657_8_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000657_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000657_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000657_8_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000657_2_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000657_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000657_2_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000657_8_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000657_2_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000657_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000657_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000657_14_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000657_18_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000657_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000657_18_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000657_14_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000657_18_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000657_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000657_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000657_1_1 & 1) != 0)
  {
    if ((sec_r000657_2_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000657_16_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000657_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000657_16_1 + 7) & 127;
  }
  if ((sec_r000657_1_2 & 1) != 0)
  {
    if ((sec_r000657_2_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000657_16_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000657_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000657_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000657_15_1 & 1) != 0)
  {
    if ((sec_r000657_9_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000657_10_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000657_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000657_10_1 + 7) & 127;
  }
  if ((sec_r000657_15_2 & 1) != 0)
  {
    if ((sec_r000657_9_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000657_10_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000657_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000657_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000657_15_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000657_2_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000657_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000657_2_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000657_15_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000657_2_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000657_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000657_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000657_3_1 & 1) != 0)
  {
    if ((sec_r000657_2_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000657_0_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000657_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000657_0_1 + 7) & 127;
  }
  if ((sec_r000657_3_2 & 1) != 0)
  {
    if ((sec_r000657_2_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000657_0_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000657_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000657_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000657_15_1 & 1) != 0)
  {
    if ((sec_r000657_5_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000657_0_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000657_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000657_0_1 + 7) & 127;
  }
  if ((sec_r000657_15_2 & 1) != 0)
  {
    if ((sec_r000657_5_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000657_0_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000657_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000657_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000657_14_1 & 1) != 0)
  {
    if ((sec_r000657_3_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000657_0_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000657_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000657_0_1 + 7) & 127;
  }
  if ((sec_r000657_14_2 & 1) != 0)
  {
    if ((sec_r000657_3_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000657_0_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000657_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000657_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000657_1_1 & 1) != 0)
  {
    if ((sec_r000657_8_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000657_11_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000657_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000657_11_1 + 7) & 127;
  }
  if ((sec_r000657_1_2 & 1) != 0)
  {
    if ((sec_r000657_8_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000657_11_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000657_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000657_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000657_14_1 & 1) != 0)
  {
    if ((sec_r000657_12_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000657_8_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000657_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000657_8_1 + 7) & 127;
  }
  if ((sec_r000657_14_2 & 1) != 0)
  {
    if ((sec_r000657_12_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000657_8_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000657_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000657_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000657_6_1 & 1) != 0)
  {
    if ((sec_r000657_4_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000657_2_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000657_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000657_2_1 + 7) & 127;
  }
  if ((sec_r000657_6_2 & 1) != 0)
  {
    if ((sec_r000657_4_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000657_2_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000657_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000657_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000657_3_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000657_18_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000657_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000657_18_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000657_3_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000657_18_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000657_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000657_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000657_9_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000657_2_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000657_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000657_2_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000657_9_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000657_2_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000657_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000657_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000657_15_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000657_10_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000657_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000657_10_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000657_15_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000657_10_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000657_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000657_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000657_15_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000657_15_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000657_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000657_15_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000657_15_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000657_15_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000657_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000657_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000657_6_1 & 1) != 0)
  {
    if ((sec_r000657_7_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000657_5_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000657_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000657_5_1 + 7) & 127;
  }
  if ((sec_r000657_6_2 & 1) != 0)
  {
    if ((sec_r000657_7_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000657_5_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000657_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000657_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000657_15_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000657_17_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000657_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000657_17_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000657_15_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000657_17_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000657_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000657_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000657_7_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000657_7_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000657_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000657_7_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000657_7_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000657_7_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000657_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000657_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000657_15_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000657_9_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000657_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000657_9_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000657_15_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000657_9_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000657_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000657_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000657_1_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000657_17_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000657_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000657_17_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000657_1_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000657_17_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000657_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000657_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000657_2_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000657_10_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000657_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000657_10_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000657_2_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000657_10_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000657_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000657_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000657_10_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000657_5_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000657_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000657_5_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000657_10_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000657_5_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000657_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000657_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000657_6_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000657_2_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000657_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000657_2_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000657_6_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000657_2_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000657_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000657_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000657_13_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000657_2_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000657_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000657_2_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000657_13_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000657_2_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000657_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000657_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000657_13_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000657_15_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000657_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000657_15_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000657_13_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000657_15_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000657_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000657_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000657_2_1 & 1) != 0)
  {
    if ((sec_r000657_13_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000657_4_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000657_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000657_4_1 + 7) & 127;
  }
  if ((sec_r000657_2_2 & 1) != 0)
  {
    if ((sec_r000657_13_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000657_4_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000657_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000657_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000657_5_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000657_12_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000657_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000657_12_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000657_5_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000657_12_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000657_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000657_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000657_9_1 & 1) != 0)
  {
    if ((sec_r000657_8_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000657_2_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000657_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000657_2_1 + 7) & 127;
  }
  if ((sec_r000657_9_2 & 1) != 0)
  {
    if ((sec_r000657_8_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000657_2_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000657_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000657_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000657_6_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000657_6_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000657_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000657_6_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000657_6_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000657_6_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000657_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000657_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((sec_r000657_10_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000657_7_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000657_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000657_7_1 + 7) & 127;
  }
  if ((stage_v_142_2 & 1) != 0)
  {
    if ((sec_r000657_10_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000657_7_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000657_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000657_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000657_15_1 & 1) != 0)
  {
    if ((sec_r000657_12_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000657_5_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000657_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000657_5_1 + 7) & 127;
  }
  if ((sec_r000657_15_2 & 1) != 0)
  {
    if ((sec_r000657_12_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000657_5_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000657_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000657_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000657_8_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000657_5_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000657_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000657_5_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000657_8_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000657_5_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000657_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000657_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000657_14_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000657_5_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000657_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000657_5_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000657_14_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000657_5_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000657_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000657_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((sec_r000657_1_1 & 1) != 0)
  {
    if ((sec_r000657_11_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000657_17_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000657_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000657_17_1 + 7) & 127;
  }
  if ((sec_r000657_1_2 & 1) != 0)
  {
    if ((sec_r000657_11_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000657_17_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000657_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000657_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000657_13_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000657_17_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000657_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000657_17_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000657_13_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000657_17_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000657_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000657_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000657_13_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000657_1_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000657_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000657_1_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000657_13_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000657_1_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000657_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000657_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000657_7_1 == pub_r000657_7_2);
  __CPROVER_assume(sec_r000657_15_1 != sec_r000657_15_2);
  __CPROVER_assume(pub_r000657_14_1 == pub_r000657_14_2);
  __CPROVER_assume(sec_r000657_11_1 != sec_r000657_11_2);
  __CPROVER_assume(pub_r000657_16_1 == pub_r000657_16_2);
  __CPROVER_assume(sec_r000657_7_1 != sec_r000657_7_2);
  __CPROVER_assume(pub_r000657_17_1 == pub_r000657_17_2);
  __CPROVER_assume(pub_r000657_2_1 == pub_r000657_2_2);
  __CPROVER_assume(pub_r000657_10_1 == pub_r000657_10_2);
  __CPROVER_assume(sec_r000657_2_1 != sec_r000657_2_2);
  __CPROVER_assume(pub_r000657_8_1 == pub_r000657_8_2);
  __CPROVER_assume(sec_r000657_0_1 != sec_r000657_0_2);
  __CPROVER_assume(pub_r000657_13_1 == pub_r000657_13_2);
  __CPROVER_assume(sec_r000657_12_1 != sec_r000657_12_2);
  __CPROVER_assume(pub_r000657_5_1 == pub_r000657_5_2);
  __CPROVER_assume(pub_r000657_4_1 == pub_r000657_4_2);
  __CPROVER_assume(sec_r000657_4_1 != sec_r000657_4_2);
  __CPROVER_assume(sec_r000657_10_1 != sec_r000657_10_2);
  __CPROVER_assume(pub_r000657_18_1 == pub_r000657_18_2);
  __CPROVER_assume(sec_r000657_14_1 != sec_r000657_14_2);
  __CPROVER_assume(sec_r000657_1_1 != sec_r000657_1_2);
  __CPROVER_assume(pub_r000657_15_1 == pub_r000657_15_2);
  __CPROVER_assume(pub_r000657_6_1 == pub_r000657_6_2);
  __CPROVER_assume(sec_r000657_5_1 != sec_r000657_5_2);
  __CPROVER_assume(pub_r000657_3_1 == pub_r000657_3_2);
  __CPROVER_assume(pub_r000657_0_1 == pub_r000657_0_2);
  __CPROVER_assume(sec_r000657_13_1 != sec_r000657_13_2);
  __CPROVER_assume(pub_r000657_9_1 == pub_r000657_9_2);
  __CPROVER_assume(pub_r000657_1_1 == pub_r000657_1_2);
  __CPROVER_assume(sec_r000657_8_1 != sec_r000657_8_2);
  __CPROVER_assume(pub_r000657_12_1 == pub_r000657_12_2);
  __CPROVER_assume(pub_r000657_11_1 == pub_r000657_11_2);
  __CPROVER_assume(sec_r000657_3_1 != sec_r000657_3_2);
  __CPROVER_assume(sec_r000657_6_1 != sec_r000657_6_2);
  __CPROVER_assume(sec_r000657_9_1 != sec_r000657_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.balance == st_var_1_2.balance);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.signature == st_var_3_2.signature);
  assert(st_var_3_1.facility == st_var_3_2.facility);
  assert(st_var_3_1.code == st_var_3_2.code);
  assert(st_var_3_1.severity == st_var_3_2.severity);
  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
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
}


