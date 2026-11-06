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
struct EventLog_R000592_9213_0
{
  short timestamp;
  int signature;
  int seq;
  int buffer[3];
};
struct MatrixBlock_R000592_9213_1
{
  unsigned char stride;
  int trace;
  int dim;
  int determinant;
  int buffer[3];
};
struct DeviceConfig_R000592_9213_2
{
  int port;
  int parity;
  int baud_rate;
  unsigned char id;
  int buffer[3];
};
struct SensorNode_R000592_9213_3
{
  int gain;
  short reading;
  int offset;
  short calib;
  short status;
  int buffer[3];
};
union RegisterBank_R000592_9213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000592_9213_1
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
void fn_R000592_9213_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000592_9213_1 st_1 = {0};
  struct MatrixBlock_R000592_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int weight_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_70_1) & 63;
  aux_2 = (aux_2 + weight_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_70_1 == weight_70_2);
}

int fn_R000592_9213_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000592_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int weight_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_70) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000592_9213_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000592_9213_0 st_1 = {0};
  struct EventLog_R000592_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int delta_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_98_1)
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

  switch (delta_98_2)
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

  int phase_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_20_1) & 63;
  aux_2 = (aux_2 + phase_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_90_1 > 34)
  {
    acc_1 = ((acc_1 + (tally_90_1 * 2)) + 5) & 127;
    aux_1 ^= tally_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_90_2 > 34)
  {
    acc_2 = ((acc_2 + (tally_90_2 * 2)) + 5) & 127;
    aux_2 ^= tally_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_90_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_98_1 == delta_98_2);
  assert(phase_20_1 == phase_20_2);
  assert(tally_90_1 == tally_90_2);
}

int fn_R000592_9213_1(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000592_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int delta_98 = (aux + st.buffer[1]) & 3;
  switch (delta_98)
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

  int phase_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_20) & 63;
  acc ^= aux;
  int tally_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_90 > 34)
  {
    acc = ((acc + (tally_90 * 2)) + 5) & 127;
    aux ^= tally_90 & 15;
  }
  else
  {
    acc = ((acc - tally_90) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000592_9213_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000592_9213_1 st_1 = {0};
  struct MatrixBlock_R000592_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int segment_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_86_1) & 63;
  aux_2 = (aux_2 + segment_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_40_1 > 48)
  {
    acc_1 = ((acc_1 + (anchor_40_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_40_2 > 48)
  {
    acc_2 = ((acc_2 + (anchor_40_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_40_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_53_1 = local_arr_1[aux_1 % 3];
  int pivot_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_53_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_86_1 == segment_86_2);
  assert(anchor_40_1 == anchor_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_53_1 == pivot_53_2);
}

int fn_R000592_9213_2(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000592_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int segment_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_86) & 63;
  acc ^= aux;
  int anchor_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_40 > 48)
  {
    acc = ((acc + (anchor_40 * 2)) + 5) & 127;
    aux ^= anchor_40 & 15;
  }
  else
  {
    acc = ((acc - anchor_40) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_53 = local_arr[aux % 3];
  acc = (acc + (pivot_53 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000592_9213_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000592_9213_0 st_1 = {0};
  struct EventLog_R000592_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int bound_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_78_1)
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

  switch (bound_78_2)
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
  int sample_17_1 = local_arr_1[aux_1 % 3];
  int sample_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_17_2 * 2)) & 127;
  int bound_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_83_1 > 18)
  {
    acc_1 = ((acc_1 + (bound_83_1 * 2)) + 5) & 127;
    aux_1 ^= bound_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_83_2 > 18)
  {
    acc_2 = ((acc_2 + (bound_83_2 * 2)) + 5) & 127;
    aux_2 ^= bound_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_60_1) & 63;
  aux_2 = (aux_2 + accumulator_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_78_1 == bound_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_17_1 == sample_17_2);
  assert(bound_83_1 == bound_83_2);
  assert(accumulator_60_1 == accumulator_60_2);
}

int fn_R000592_9213_3(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000592_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int bound_78 = (aux + st.buffer[1]) & 3;
  switch (bound_78)
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
  int sample_17 = local_arr[aux % 3];
  acc = (acc + (sample_17 * 2)) & 127;
  int bound_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_83 > 18)
  {
    acc = ((acc + (bound_83 * 2)) + 5) & 127;
    aux ^= bound_83 & 15;
  }
  else
  {
    acc = ((acc - bound_83) + 11) & 127;
    aux += 3;
  }
  int accumulator_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_60) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000592_9213_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000592_9213_1 st_1 = {0};
  struct MatrixBlock_R000592_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_77_1) & 63;
  aux_2 = (aux_2 + offset_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_97_1)
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

  switch (segment_97_2)
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
  int factor_96_1 = local_arr_1[aux_1 % 3];
  int factor_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_96_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_77_1 == offset_77_2);
  assert(segment_97_1 == segment_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_96_1 == factor_96_2);
}

int fn_R000592_9213_4(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000592_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_77) & 63;
  acc ^= aux;
  int segment_97 = (aux + st.buffer[1]) & 3;
  switch (segment_97)
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
  int factor_96 = local_arr[aux % 3];
  acc = (acc + (factor_96 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000592_9213_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000592_9213_3 st_1 = {0};
  struct SensorNode_R000592_9213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tally_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_56_1)
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

  switch (tally_56_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_77_1 = local_arr_1[aux_1 % 3];
  int vector_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_77_2 * 2)) & 127;
  int offset_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_45_1) & 63;
  aux_2 = (aux_2 + offset_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_56_1 == tally_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_77_1 == vector_77_2);
  assert(offset_45_1 == offset_45_2);
}

int fn_R000592_9213_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000592_9213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tally_56 = (aux + st.buffer[1]) & 3;
  switch (tally_56)
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
  int local_arr[3] = {4, 9, 15};
  int vector_77 = local_arr[aux % 3];
  acc = (acc + (vector_77 * 2)) & 127;
  int offset_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_45) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000592_9213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000592_9213_2 st_1 = {0};
  struct DeviceConfig_R000592_9213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_48_1 = local_arr_1[aux_1 % 3];
  int window_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_48_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_69_1) & 63;
  aux_2 = (aux_2 + sample_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_48_1 == window_48_2);
  assert(sample_69_1 == sample_69_2);
}

int fn_R000592_9213_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000592_9213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int window_48 = local_arr[aux % 3];
  acc = (acc + (window_48 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000592_9213_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000592_9213_0 st_1 = {0};
  struct EventLog_R000592_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_45_1 = local_arr_1[aux_1 % 3];
  int stride_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_45_2 * 2)) & 127;
  int segment_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_68_1 > 16)
  {
    acc_1 = ((acc_1 + (segment_68_1 * 2)) + 5) & 127;
    aux_1 ^= segment_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_68_2 > 16)
  {
    acc_2 = ((acc_2 + (segment_68_2 * 2)) + 5) & 127;
    aux_2 ^= segment_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_78_1) & 63;
  aux_2 = (aux_2 + metric_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_45_1 == stride_45_2);
  assert(segment_68_1 == segment_68_2);
  assert(metric_78_1 == metric_78_2);
}

int fn_R000592_9213_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000592_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int stride_45 = local_arr[aux % 3];
  acc = (acc + (stride_45 * 2)) & 127;
  int segment_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_68 > 16)
  {
    acc = ((acc + (segment_68 * 2)) + 5) & 127;
    aux ^= segment_68 & 15;
  }
  else
  {
    acc = ((acc - segment_68) + 11) & 127;
    aux += 3;
  }
  int metric_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_78) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000592_9213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000592_9213_2 st_1 = {0};
  struct DeviceConfig_R000592_9213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int index_reg_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_31_1) & 63;
  aux_2 = (aux_2 + index_reg_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_48_1)
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

  switch (residue_48_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_31_1 == index_reg_31_2);
  assert(residue_48_1 == residue_48_2);
}

int fn_R000592_9213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000592_9213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int index_reg_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_31) & 63;
  acc ^= aux;
  int residue_48 = (aux + st.buffer[1]) & 3;
  switch (residue_48)
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

void fn_R000592_9213_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000592_9213_2 st_1 = {0};
  struct DeviceConfig_R000592_9213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int scale_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_30_1)
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

  switch (scale_30_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_68_1 = local_arr_1[aux_1 % 3];
  int pivot_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_30_1 == scale_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_68_1 == pivot_68_2);
}

int fn_R000592_9213_9(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000592_9213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int scale_30 = (aux + st.buffer[1]) & 3;
  switch (scale_30)
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

  int local_arr[3] = {4, 9, 15};
  int pivot_68 = local_arr[aux % 3];
  acc = (acc + (pivot_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000592_9213_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000592_9213_2 st_1 = {0};
  struct DeviceConfig_R000592_9213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int index_reg_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_86_1) & 63;
  aux_2 = (aux_2 + index_reg_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_69_1 > 38)
  {
    acc_1 = ((acc_1 + (cursor_69_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_69_2 > 38)
  {
    acc_2 = ((acc_2 + (cursor_69_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_37_1 = local_arr_1[aux_1 % 3];
  int parity_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_37_2 * 2)) & 127;
  int cursor_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_19_1)
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

  switch (cursor_19_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_86_1 == index_reg_86_2);
  assert(cursor_69_1 == cursor_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_37_1 == parity_37_2);
  assert(cursor_19_1 == cursor_19_2);
}

int fn_R000592_9213_10(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000592_9213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int index_reg_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_86) & 63;
  acc ^= aux;
  int cursor_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_69 > 38)
  {
    acc = ((acc + (cursor_69 * 2)) + 5) & 127;
    aux ^= cursor_69 & 15;
  }
  else
  {
    acc = ((acc - cursor_69) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_37 = local_arr[aux % 3];
  acc = (acc + (parity_37 * 2)) & 127;
  int cursor_19 = (aux + st.buffer[1]) & 3;
  switch (cursor_19)
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

void fn_R000592_9213_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000592_9213_3 st_1 = {0};
  struct SensorNode_R000592_9213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int margin_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_32_1 > 49)
  {
    acc_1 = ((acc_1 + (margin_32_1 * 2)) + 5) & 127;
    aux_1 ^= margin_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_32_2 > 49)
  {
    acc_2 = ((acc_2 + (margin_32_2 * 2)) + 5) & 127;
    aux_2 ^= margin_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_32_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_27_1) & 63;
  aux_2 = (aux_2 + quantum_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_70_1)
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

  switch (damping_70_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_32_1 == margin_32_2);
  assert(quantum_27_1 == quantum_27_2);
  assert(damping_70_1 == damping_70_2);
}

int fn_R000592_9213_11(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000592_9213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int margin_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_32 > 49)
  {
    acc = ((acc + (margin_32 * 2)) + 5) & 127;
    aux ^= margin_32 & 15;
  }
  else
  {
    acc = ((acc - margin_32) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_27) & 63;
  acc ^= aux;
  int damping_70 = (aux + st.buffer[1]) & 3;
  switch (damping_70)
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

void fn_R000592_9213_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000592_9213_1 st_1 = {0};
  struct MatrixBlock_R000592_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int stride_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_49_1)
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

  switch (stride_49_2)
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

  int quotient_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_72_1 > 37)
  {
    acc_1 = ((acc_1 + (quotient_72_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_72_2 > 37)
  {
    acc_2 = ((acc_2 + (quotient_72_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_62_1) & 63;
  aux_2 = (aux_2 + coefficient_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_49_1 == stride_49_2);
  assert(quotient_72_1 == quotient_72_2);
  assert(coefficient_62_1 == coefficient_62_2);
}

int fn_R000592_9213_12(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000592_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int stride_49 = (aux + st.buffer[1]) & 3;
  switch (stride_49)
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

  int quotient_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_72 > 37)
  {
    acc = ((acc + (quotient_72 * 2)) + 5) & 127;
    aux ^= quotient_72 & 15;
  }
  else
  {
    acc = ((acc - quotient_72) + 11) & 127;
    aux += 3;
  }
  int coefficient_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000592_9213_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000592_9213_3 st_1 = {0};
  struct SensorNode_R000592_9213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_89_1) & 63;
  aux_2 = (aux_2 + coefficient_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_89_1 == coefficient_89_2);
}

int fn_R000592_9213_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000592_9213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_89) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000592_9213_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000592_9213_1 st_1 = {0};
  struct MatrixBlock_R000592_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int index_reg_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_64_1) & 63;
  aux_2 = (aux_2 + index_reg_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_89_1 = local_arr_1[aux_1 % 3];
  int margin_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_89_2 * 2)) & 127;
  int anchor_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_45_1 > 40)
  {
    acc_1 = ((acc_1 + (anchor_45_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_45_2 > 40)
  {
    acc_2 = ((acc_2 + (anchor_45_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_64_1 == index_reg_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_89_1 == margin_89_2);
  assert(anchor_45_1 == anchor_45_2);
}

int fn_R000592_9213_14(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000592_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int index_reg_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_64) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_89 = local_arr[aux % 3];
  acc = (acc + (margin_89 * 2)) & 127;
  int anchor_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_45 > 40)
  {
    acc = ((acc + (anchor_45 * 2)) + 5) & 127;
    aux ^= anchor_45 & 15;
  }
  else
  {
    acc = ((acc - anchor_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000592_9213_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000592_9213_3 st_1 = {0};
  struct SensorNode_R000592_9213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int stride_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_13_1)
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

  switch (stride_13_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_13_1 == stride_13_2);
}

int fn_R000592_9213_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000592_9213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int stride_13 = (aux + st.buffer[1]) & 3;
  switch (stride_13)
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
  return (acc + aux) & 255;
}

void fn_R000592_9213_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000592_9213_0 st_1 = {0};
  struct EventLog_R000592_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int parity_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_16_1 > 27)
  {
    acc_1 = ((acc_1 + (parity_16_1 * 2)) + 5) & 127;
    aux_1 ^= parity_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_16_2 > 27)
  {
    acc_2 = ((acc_2 + (parity_16_2 * 2)) + 5) & 127;
    aux_2 ^= parity_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_16_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_16_1 == parity_16_2);
}

int fn_R000592_9213_16(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000592_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int parity_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_16 > 27)
  {
    acc = ((acc + (parity_16 * 2)) + 5) & 127;
    aux ^= parity_16 & 15;
  }
  else
  {
    acc = ((acc - parity_16) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000592_9213_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000592_9213_1 st_1 = {0};
  struct MatrixBlock_R000592_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int quantum_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_45_1)
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

  switch (quantum_45_2)
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
  int threshold_53_1 = local_arr_1[aux_1 % 3];
  int threshold_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_53_2 * 2)) & 127;
  int vector_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_88_1 > 49)
  {
    acc_1 = ((acc_1 + (vector_88_1 * 2)) + 5) & 127;
    aux_1 ^= vector_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_88_2 > 49)
  {
    acc_2 = ((acc_2 + (vector_88_2 * 2)) + 5) & 127;
    aux_2 ^= vector_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_88_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_45_1 == quantum_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_53_1 == threshold_53_2);
  assert(vector_88_1 == vector_88_2);
}

int fn_R000592_9213_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000592_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int quantum_45 = (aux + st.buffer[1]) & 3;
  switch (quantum_45)
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
  int threshold_53 = local_arr[aux % 3];
  acc = (acc + (threshold_53 * 2)) & 127;
  int vector_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_88 > 49)
  {
    acc = ((acc + (vector_88 * 2)) + 5) & 127;
    aux ^= vector_88 & 15;
  }
  else
  {
    acc = ((acc - vector_88) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000592_9213_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000592_9213_2 st_1 = {0};
  struct DeviceConfig_R000592_9213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int factor_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_24_1) & 63;
  aux_2 = (aux_2 + factor_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_24_1 == factor_24_2);
}

int fn_R000592_9213_18(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000592_9213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int factor_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_24) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000592_0_1;
  int sec_r000592_0_2;
  int sec_r000592_1_1;
  int sec_r000592_1_2;
  int sec_r000592_2_1;
  int sec_r000592_2_2;
  int sec_r000592_3_1;
  int sec_r000592_3_2;
  int sec_r000592_4_1;
  int sec_r000592_4_2;
  int sec_r000592_5_1;
  int sec_r000592_5_2;
  int sec_r000592_6_1;
  int sec_r000592_6_2;
  int sec_r000592_7_1;
  int sec_r000592_7_2;
  int sec_r000592_8_1;
  int sec_r000592_8_2;
  int sec_r000592_9_1;
  int sec_r000592_9_2;
  int sec_r000592_10_1;
  int sec_r000592_10_2;
  int sec_r000592_11_1;
  int sec_r000592_11_2;
  int sec_r000592_12_1;
  int sec_r000592_12_2;
  int sec_r000592_13_1;
  int sec_r000592_13_2;
  int sec_r000592_14_1;
  int sec_r000592_14_2;
  int sec_r000592_15_1;
  int sec_r000592_15_2;
  int sec_r000592_16_1;
  int sec_r000592_16_2;
  int sec_r000592_17_1;
  int sec_r000592_17_2;
  int pub_r000592_0_1;
  int pub_r000592_0_2;
  int pub_r000592_1_1;
  int pub_r000592_1_2;
  int pub_r000592_2_1;
  int pub_r000592_2_2;
  int pub_r000592_3_1;
  int pub_r000592_3_2;
  int pub_r000592_4_1;
  int pub_r000592_4_2;
  int pub_r000592_5_1;
  int pub_r000592_5_2;
  int pub_r000592_6_1;
  int pub_r000592_6_2;
  int pub_r000592_7_1;
  int pub_r000592_7_2;
  int pub_r000592_8_1;
  int pub_r000592_8_2;
  int pub_r000592_9_1;
  int pub_r000592_9_2;
  int pub_r000592_10_1;
  int pub_r000592_10_2;
  int pub_r000592_11_1;
  int pub_r000592_11_2;
  int pub_r000592_12_1;
  int pub_r000592_12_2;
  int pub_r000592_13_1;
  int pub_r000592_13_2;
  int pub_r000592_14_1;
  int pub_r000592_14_2;
  int pub_r000592_15_1;
  int pub_r000592_15_2;
  int pub_r000592_16_1;
  int pub_r000592_16_2;
  int pub_r000592_17_1;
  int pub_r000592_17_2;
  int pub_r000592_18_1;
  int pub_r000592_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000592_0_1 >= (-100)) && (pub_r000592_0_1 <= 100));
  __CPROVER_assume((pub_r000592_0_2 >= (-100)) && (pub_r000592_0_2 <= 100));
  __CPROVER_assume((pub_r000592_1_1 >= (-100)) && (pub_r000592_1_1 <= 100));
  __CPROVER_assume((pub_r000592_1_2 >= (-100)) && (pub_r000592_1_2 <= 100));
  __CPROVER_assume((pub_r000592_2_1 >= (-100)) && (pub_r000592_2_1 <= 100));
  __CPROVER_assume((pub_r000592_2_2 >= (-100)) && (pub_r000592_2_2 <= 100));
  __CPROVER_assume((pub_r000592_3_1 >= (-100)) && (pub_r000592_3_1 <= 100));
  __CPROVER_assume((pub_r000592_3_2 >= (-100)) && (pub_r000592_3_2 <= 100));
  __CPROVER_assume((pub_r000592_4_1 >= (-100)) && (pub_r000592_4_1 <= 100));
  __CPROVER_assume((pub_r000592_4_2 >= (-100)) && (pub_r000592_4_2 <= 100));
  __CPROVER_assume((pub_r000592_5_1 >= (-100)) && (pub_r000592_5_1 <= 100));
  __CPROVER_assume((pub_r000592_5_2 >= (-100)) && (pub_r000592_5_2 <= 100));
  __CPROVER_assume((pub_r000592_6_1 >= (-100)) && (pub_r000592_6_1 <= 100));
  __CPROVER_assume((pub_r000592_6_2 >= (-100)) && (pub_r000592_6_2 <= 100));
  __CPROVER_assume((pub_r000592_7_1 >= (-100)) && (pub_r000592_7_1 <= 100));
  __CPROVER_assume((pub_r000592_7_2 >= (-100)) && (pub_r000592_7_2 <= 100));
  __CPROVER_assume((pub_r000592_8_1 >= (-100)) && (pub_r000592_8_1 <= 100));
  __CPROVER_assume((pub_r000592_8_2 >= (-100)) && (pub_r000592_8_2 <= 100));
  __CPROVER_assume((pub_r000592_9_1 >= (-100)) && (pub_r000592_9_1 <= 100));
  __CPROVER_assume((pub_r000592_9_2 >= (-100)) && (pub_r000592_9_2 <= 100));
  __CPROVER_assume((pub_r000592_10_1 >= (-100)) && (pub_r000592_10_1 <= 100));
  __CPROVER_assume((pub_r000592_10_2 >= (-100)) && (pub_r000592_10_2 <= 100));
  __CPROVER_assume((pub_r000592_11_1 >= (-100)) && (pub_r000592_11_1 <= 100));
  __CPROVER_assume((pub_r000592_11_2 >= (-100)) && (pub_r000592_11_2 <= 100));
  __CPROVER_assume((pub_r000592_12_1 >= (-100)) && (pub_r000592_12_1 <= 100));
  __CPROVER_assume((pub_r000592_12_2 >= (-100)) && (pub_r000592_12_2 <= 100));
  __CPROVER_assume((pub_r000592_13_1 >= (-100)) && (pub_r000592_13_1 <= 100));
  __CPROVER_assume((pub_r000592_13_2 >= (-100)) && (pub_r000592_13_2 <= 100));
  __CPROVER_assume((pub_r000592_14_1 >= (-100)) && (pub_r000592_14_1 <= 100));
  __CPROVER_assume((pub_r000592_14_2 >= (-100)) && (pub_r000592_14_2 <= 100));
  __CPROVER_assume((pub_r000592_15_1 >= (-100)) && (pub_r000592_15_1 <= 100));
  __CPROVER_assume((pub_r000592_15_2 >= (-100)) && (pub_r000592_15_2 <= 100));
  __CPROVER_assume((pub_r000592_16_1 >= (-100)) && (pub_r000592_16_1 <= 100));
  __CPROVER_assume((pub_r000592_16_2 >= (-100)) && (pub_r000592_16_2 <= 100));
  __CPROVER_assume((pub_r000592_17_1 >= (-100)) && (pub_r000592_17_1 <= 100));
  __CPROVER_assume((pub_r000592_17_2 >= (-100)) && (pub_r000592_17_2 <= 100));
  __CPROVER_assume((pub_r000592_18_1 >= (-100)) && (pub_r000592_18_1 <= 100));
  __CPROVER_assume((pub_r000592_18_2 >= (-100)) && (pub_r000592_18_2 <= 100));
  __CPROVER_assume((sec_r000592_0_1 >= 0) && (sec_r000592_0_1 <= 255));
  __CPROVER_assume((sec_r000592_0_2 >= 0) && (sec_r000592_0_2 <= 255));
  __CPROVER_assume((sec_r000592_1_1 >= 0) && (sec_r000592_1_1 <= 255));
  __CPROVER_assume((sec_r000592_1_2 >= 0) && (sec_r000592_1_2 <= 255));
  __CPROVER_assume((sec_r000592_2_1 >= 0) && (sec_r000592_2_1 <= 255));
  __CPROVER_assume((sec_r000592_2_2 >= 0) && (sec_r000592_2_2 <= 255));
  __CPROVER_assume((sec_r000592_3_1 >= 0) && (sec_r000592_3_1 <= 255));
  __CPROVER_assume((sec_r000592_3_2 >= 0) && (sec_r000592_3_2 <= 255));
  __CPROVER_assume((sec_r000592_4_1 >= 0) && (sec_r000592_4_1 <= 255));
  __CPROVER_assume((sec_r000592_4_2 >= 0) && (sec_r000592_4_2 <= 255));
  __CPROVER_assume((sec_r000592_5_1 >= 0) && (sec_r000592_5_1 <= 255));
  __CPROVER_assume((sec_r000592_5_2 >= 0) && (sec_r000592_5_2 <= 255));
  __CPROVER_assume((sec_r000592_6_1 >= 0) && (sec_r000592_6_1 <= 255));
  __CPROVER_assume((sec_r000592_6_2 >= 0) && (sec_r000592_6_2 <= 255));
  __CPROVER_assume((sec_r000592_7_1 >= 0) && (sec_r000592_7_1 <= 255));
  __CPROVER_assume((sec_r000592_7_2 >= 0) && (sec_r000592_7_2 <= 255));
  __CPROVER_assume((sec_r000592_8_1 >= 0) && (sec_r000592_8_1 <= 255));
  __CPROVER_assume((sec_r000592_8_2 >= 0) && (sec_r000592_8_2 <= 255));
  __CPROVER_assume((sec_r000592_9_1 >= 0) && (sec_r000592_9_1 <= 255));
  __CPROVER_assume((sec_r000592_9_2 >= 0) && (sec_r000592_9_2 <= 255));
  __CPROVER_assume((sec_r000592_10_1 >= 0) && (sec_r000592_10_1 <= 255));
  __CPROVER_assume((sec_r000592_10_2 >= 0) && (sec_r000592_10_2 <= 255));
  __CPROVER_assume((sec_r000592_11_1 >= 0) && (sec_r000592_11_1 <= 255));
  __CPROVER_assume((sec_r000592_11_2 >= 0) && (sec_r000592_11_2 <= 255));
  __CPROVER_assume((sec_r000592_12_1 >= 0) && (sec_r000592_12_1 <= 255));
  __CPROVER_assume((sec_r000592_12_2 >= 0) && (sec_r000592_12_2 <= 255));
  __CPROVER_assume((sec_r000592_13_1 >= 0) && (sec_r000592_13_1 <= 255));
  __CPROVER_assume((sec_r000592_13_2 >= 0) && (sec_r000592_13_2 <= 255));
  __CPROVER_assume((sec_r000592_14_1 >= 0) && (sec_r000592_14_1 <= 255));
  __CPROVER_assume((sec_r000592_14_2 >= 0) && (sec_r000592_14_2 <= 255));
  __CPROVER_assume((sec_r000592_15_1 >= 0) && (sec_r000592_15_1 <= 255));
  __CPROVER_assume((sec_r000592_15_2 >= 0) && (sec_r000592_15_2 <= 255));
  __CPROVER_assume((sec_r000592_16_1 >= 0) && (sec_r000592_16_1 <= 255));
  __CPROVER_assume((sec_r000592_16_2 >= 0) && (sec_r000592_16_2 <= 255));
  __CPROVER_assume((sec_r000592_17_1 >= 0) && (sec_r000592_17_1 <= 255));
  __CPROVER_assume((sec_r000592_17_2 >= 0) && (sec_r000592_17_2 <= 255));
  struct EventLog_R000592_9213_0 st_var_0_1 = {0};
  struct EventLog_R000592_9213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000592_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000592_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000592_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000592_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000592_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000592_0_2 + 7) & 15;
  struct MatrixBlock_R000592_9213_1 st_var_1_1 = {0};
  struct MatrixBlock_R000592_9213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000592_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000592_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000592_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000592_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000592_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000592_0_2 + 9) & 15;
  struct DeviceConfig_R000592_9213_2 st_var_2_1 = {0};
  struct DeviceConfig_R000592_9213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000592_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000592_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000592_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000592_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000592_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000592_0_2 + 11) & 15;
  struct SensorNode_R000592_9213_3 st_var_3_1 = {0};
  struct SensorNode_R000592_9213_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000592_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000592_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000592_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000592_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000592_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000592_0_2 + 13) & 15;
  union RegisterBank_R000592_9213_0 u_var_1;
  union RegisterBank_R000592_9213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 49)
    {
      chk_sum_1 ^= stage_v_0_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_0_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 49)
    {
      chk_sum_2 ^= stage_v_0_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = (st_var_2_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_2_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 11) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = (st_var_3_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_3_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = ((st_var_3_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_3_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 47)
    {
      chk_sum_1 ^= stage_v_15_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_15_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 47)
    {
      chk_sum_2 ^= stage_v_15_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (st_var_3_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_3_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = ((sec_r000592_11_1 + pub_r000592_6_1) + 25) & 127;
  int stage_v_21_2 = ((sec_r000592_11_2 + pub_r000592_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((sec_r000592_13_1 + pub_r000592_0_1) + 6) & 127;
  int stage_v_22_2 = ((sec_r000592_13_2 + pub_r000592_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((stage_v_22_1 + pub_r000592_9_1) + 43) & 127;
  int stage_v_23_2 = ((stage_v_22_2 + pub_r000592_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((stage_v_22_1 + pub_r000592_15_1) + 18) & 127;
  int stage_v_24_2 = ((stage_v_22_2 + pub_r000592_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((stage_v_22_1 + pub_r000592_10_1) + 14) & 127;
  int stage_v_25_2 = ((stage_v_22_2 + pub_r000592_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((stage_v_21_1 + pub_r000592_18_1) + 15) & 127;
  int stage_v_26_2 = ((stage_v_21_2 + pub_r000592_18_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((sec_r000592_15_1 + pub_r000592_13_1) + 22) & 127;
  int stage_v_27_2 = ((sec_r000592_15_2 + pub_r000592_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((stage_v_26_1 + pub_r000592_2_1) + 36) & 127;
  int stage_v_28_2 = ((stage_v_26_2 + pub_r000592_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((sec_r000592_12_1 + pub_r000592_13_1) + 36) & 127;
  int stage_v_29_2 = ((sec_r000592_12_2 + pub_r000592_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((stage_v_29_1 + pub_r000592_7_1) + 7) & 127;
  int stage_v_30_2 = ((stage_v_29_2 + pub_r000592_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((sec_r000592_4_1 + pub_r000592_2_1) + 43) & 127;
  int stage_v_31_2 = ((sec_r000592_4_2 + pub_r000592_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((stage_v_27_1 + pub_r000592_12_1) + 46) & 127;
  int stage_v_32_2 = ((stage_v_27_2 + pub_r000592_12_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((sec_r000592_16_1 + pub_r000592_4_1) + 24) & 127;
  int stage_v_33_2 = ((sec_r000592_16_2 + pub_r000592_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((sec_r000592_3_1 + pub_r000592_9_1) + 14) & 127;
  int stage_v_34_2 = ((sec_r000592_3_2 + pub_r000592_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((stage_v_26_1 + pub_r000592_9_1) + 48) & 127;
  int stage_v_35_2 = ((stage_v_26_2 + pub_r000592_9_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((stage_v_29_1 + pub_r000592_0_1) + 25) & 127;
  int stage_v_36_2 = ((stage_v_29_2 + pub_r000592_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((sec_r000592_7_1 + pub_r000592_9_1) + 33) & 127;
  int stage_v_37_2 = ((sec_r000592_7_2 + pub_r000592_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((stage_v_24_1 + pub_r000592_6_1) + 6) & 127;
  int stage_v_38_2 = ((stage_v_24_2 + pub_r000592_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((stage_v_30_1 + pub_r000592_10_1) + 8) & 127;
  int stage_v_39_2 = ((stage_v_30_2 + pub_r000592_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((stage_v_29_1 + pub_r000592_15_1) + 40) & 127;
  int stage_v_40_2 = ((stage_v_29_2 + pub_r000592_15_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((stage_v_24_1 + pub_r000592_18_1) + 4) & 127;
  int stage_v_41_2 = ((stage_v_24_2 + pub_r000592_18_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((stage_v_30_1 + pub_r000592_15_1) + 19) & 127;
  int stage_v_42_2 = ((stage_v_30_2 + pub_r000592_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((sec_r000592_2_1 + pub_r000592_4_1) + 37) & 127;
  int stage_v_43_2 = ((sec_r000592_2_2 + pub_r000592_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((sec_r000592_0_1 + pub_r000592_1_1) + 35) & 127;
  int stage_v_44_2 = ((sec_r000592_0_2 + pub_r000592_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((stage_v_41_1 + pub_r000592_7_1) + 3) & 127;
  int stage_v_45_2 = ((stage_v_41_2 + pub_r000592_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((stage_v_26_1 + pub_r000592_11_1) + 32) & 127;
  int stage_v_46_2 = ((stage_v_26_2 + pub_r000592_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((sec_r000592_11_1 + pub_r000592_16_1) + 43) & 127;
  int stage_v_47_2 = ((sec_r000592_11_2 + pub_r000592_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((stage_v_41_1 + pub_r000592_12_1) + 24) & 127;
  int stage_v_48_2 = ((stage_v_41_2 + pub_r000592_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((stage_v_44_1 + pub_r000592_10_1) + 7) & 127;
  int stage_v_49_2 = ((stage_v_44_2 + pub_r000592_10_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((sec_r000592_10_1 + pub_r000592_8_1) + 48) & 127;
  int stage_v_50_2 = ((sec_r000592_10_2 + pub_r000592_8_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((sec_r000592_2_1 + pub_r000592_4_1) + 19) & 127;
  int stage_v_51_2 = ((sec_r000592_2_2 + pub_r000592_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((sec_r000592_9_1 + pub_r000592_15_1) + 34) & 127;
  int stage_v_52_2 = ((sec_r000592_9_2 + pub_r000592_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((stage_v_43_1 + pub_r000592_3_1) + 48) & 127;
  int stage_v_53_2 = ((stage_v_43_2 + pub_r000592_3_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((stage_v_49_1 + pub_r000592_9_1) + 39) & 127;
  int stage_v_54_2 = ((stage_v_49_2 + pub_r000592_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((stage_v_28_1 + pub_r000592_5_1) + 38) & 127;
  int stage_v_55_2 = ((stage_v_28_2 + pub_r000592_5_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((sec_r000592_15_1 + pub_r000592_17_1) + 36) & 127;
  int stage_v_56_2 = ((sec_r000592_15_2 + pub_r000592_17_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((sec_r000592_8_1 + pub_r000592_18_1) + 13) & 127;
  int stage_v_57_2 = ((sec_r000592_8_2 + pub_r000592_18_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((stage_v_26_1 + pub_r000592_6_1) + 25) & 127;
  int stage_v_58_2 = ((stage_v_26_2 + pub_r000592_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((stage_v_57_1 + pub_r000592_13_1) + 24) & 127;
  int stage_v_59_2 = ((stage_v_57_2 + pub_r000592_13_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((stage_v_52_1 + pub_r000592_18_1) + 6) & 127;
  int stage_v_60_2 = ((stage_v_52_2 + pub_r000592_18_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((stage_v_39_1 + pub_r000592_1_1) + 35) & 127;
  int stage_v_61_2 = ((stage_v_39_2 + pub_r000592_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((sec_r000592_17_1 + pub_r000592_13_1) + 23) & 127;
  int stage_v_62_2 = ((sec_r000592_17_2 + pub_r000592_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((stage_v_28_1 + pub_r000592_13_1) + 29) & 127;
  int stage_v_63_2 = ((stage_v_28_2 + pub_r000592_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((stage_v_62_1 + pub_r000592_14_1) + 4) & 127;
  int stage_v_64_2 = ((stage_v_62_2 + pub_r000592_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((stage_v_39_1 + pub_r000592_18_1) + 10) & 127;
  int stage_v_65_2 = ((stage_v_39_2 + pub_r000592_18_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((stage_v_25_1 + pub_r000592_2_1) + 29) & 127;
  int stage_v_66_2 = ((stage_v_25_2 + pub_r000592_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((stage_v_61_1 + pub_r000592_10_1) + 15) & 127;
  int stage_v_67_2 = ((stage_v_61_2 + pub_r000592_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((stage_v_42_1 + pub_r000592_15_1) + 21) & 127;
  int stage_v_68_2 = ((stage_v_42_2 + pub_r000592_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((stage_v_55_1 + pub_r000592_15_1) + 6) & 127;
  int stage_v_69_2 = ((stage_v_55_2 + pub_r000592_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((stage_v_28_1 + pub_r000592_11_1) + 25) & 127;
  int stage_v_70_2 = ((stage_v_28_2 + pub_r000592_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((sec_r000592_3_1 + pub_r000592_5_1) + 21) & 127;
  int stage_v_71_2 = ((sec_r000592_3_2 + pub_r000592_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((stage_v_56_1 + pub_r000592_18_1) + 15) & 127;
  int stage_v_72_2 = ((stage_v_56_2 + pub_r000592_18_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((stage_v_68_1 + pub_r000592_16_1) + 3) & 127;
  int stage_v_73_2 = ((stage_v_68_2 + pub_r000592_16_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((stage_v_59_1 + pub_r000592_0_1) + 19) & 127;
  int stage_v_74_2 = ((stage_v_59_2 + pub_r000592_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((sec_r000592_3_1 + pub_r000592_6_1) + 33) & 127;
  int stage_v_75_2 = ((sec_r000592_3_2 + pub_r000592_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((stage_v_70_1 + pub_r000592_10_1) + 20) & 127;
  int stage_v_76_2 = ((stage_v_70_2 + pub_r000592_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((sec_r000592_0_1 + pub_r000592_9_1) + 11) & 127;
  int stage_v_77_2 = ((sec_r000592_0_2 + pub_r000592_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((stage_v_74_1 + pub_r000592_6_1) + 29) & 127;
  int stage_v_78_2 = ((stage_v_74_2 + pub_r000592_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((sec_r000592_12_1 + pub_r000592_7_1) + 18) & 127;
  int stage_v_79_2 = ((sec_r000592_12_2 + pub_r000592_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((stage_v_50_1 + pub_r000592_17_1) + 27) & 127;
  int stage_v_80_2 = ((stage_v_50_2 + pub_r000592_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((stage_v_24_1 + pub_r000592_6_1) + 20) & 127;
  int stage_v_81_2 = ((stage_v_24_2 + pub_r000592_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((sec_r000592_0_1 + pub_r000592_11_1) + 15) & 127;
  int stage_v_82_2 = ((sec_r000592_0_2 + pub_r000592_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((stage_v_64_1 + pub_r000592_11_1) + 49) & 127;
  int stage_v_83_2 = ((stage_v_64_2 + pub_r000592_11_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((stage_v_54_1 + pub_r000592_11_1) + 7) & 127;
  int stage_v_84_2 = ((stage_v_54_2 + pub_r000592_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((stage_v_61_1 + pub_r000592_16_1) + 46) & 127;
  int stage_v_85_2 = ((stage_v_61_2 + pub_r000592_16_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((stage_v_54_1 + pub_r000592_9_1) + 5) & 127;
  int stage_v_86_2 = ((stage_v_54_2 + pub_r000592_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((stage_v_52_1 + pub_r000592_4_1) + 44) & 127;
  int stage_v_87_2 = ((stage_v_52_2 + pub_r000592_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((sec_r000592_7_1 + pub_r000592_13_1) + 11) & 127;
  int stage_v_88_2 = ((sec_r000592_7_2 + pub_r000592_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((stage_v_71_1 + pub_r000592_8_1) + 15) & 127;
  int stage_v_89_2 = ((stage_v_71_2 + pub_r000592_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((stage_v_22_1 + pub_r000592_2_1) + 4) & 127;
  int stage_v_90_2 = ((stage_v_22_2 + pub_r000592_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((stage_v_43_1 + pub_r000592_8_1) + 6) & 127;
  int stage_v_91_2 = ((stage_v_43_2 + pub_r000592_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((stage_v_80_1 + pub_r000592_6_1) + 15) & 127;
  int stage_v_92_2 = ((stage_v_80_2 + pub_r000592_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((sec_r000592_0_1 + pub_r000592_5_1) + 11) & 127;
  int stage_v_93_2 = ((sec_r000592_0_2 + pub_r000592_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((sec_r000592_4_1 + pub_r000592_18_1) + 8) & 127;
  int stage_v_94_2 = ((sec_r000592_4_2 + pub_r000592_18_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((stage_v_89_1 + pub_r000592_4_1) + 12) & 127;
  int stage_v_95_2 = ((stage_v_89_2 + pub_r000592_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((sec_r000592_10_1 + pub_r000592_8_1) + 17) & 127;
  int stage_v_96_2 = ((sec_r000592_10_2 + pub_r000592_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((stage_v_67_1 + pub_r000592_2_1) + 8) & 127;
  int stage_v_97_2 = ((stage_v_67_2 + pub_r000592_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((sec_r000592_2_1 + pub_r000592_11_1) + 10) & 127;
  int stage_v_98_2 = ((sec_r000592_2_2 + pub_r000592_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((sec_r000592_1_1 + pub_r000592_2_1) + 6) & 127;
  int stage_v_99_2 = ((sec_r000592_1_2 + pub_r000592_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((sec_r000592_14_1 + pub_r000592_12_1) + 5) & 127;
  int stage_v_100_2 = ((sec_r000592_14_2 + pub_r000592_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((stage_v_22_1 + pub_r000592_12_1) + 42) & 127;
  int stage_v_101_2 = ((stage_v_22_2 + pub_r000592_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((sec_r000592_10_1 + pub_r000592_7_1) + 42) & 127;
  int stage_v_102_2 = ((sec_r000592_10_2 + pub_r000592_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((sec_r000592_1_1 + pub_r000592_0_1) + 12) & 127;
  int stage_v_103_2 = ((sec_r000592_1_2 + pub_r000592_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((stage_v_103_1 + pub_r000592_18_1) + 17) & 127;
  int stage_v_104_2 = ((stage_v_103_2 + pub_r000592_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((sec_r000592_15_1 + pub_r000592_16_1) + 16) & 127;
  int stage_v_105_2 = ((sec_r000592_15_2 + pub_r000592_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((stage_v_91_1 + pub_r000592_9_1) + 18) & 127;
  int stage_v_106_2 = ((stage_v_91_2 + pub_r000592_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((stage_v_42_1 + pub_r000592_13_1) + 38) & 127;
  int stage_v_107_2 = ((stage_v_42_2 + pub_r000592_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((stage_v_55_1 + pub_r000592_14_1) + 32) & 127;
  int stage_v_108_2 = ((stage_v_55_2 + pub_r000592_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((stage_v_86_1 + pub_r000592_15_1) + 30) & 127;
  int stage_v_109_2 = ((stage_v_86_2 + pub_r000592_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((sec_r000592_5_1 + pub_r000592_14_1) + 5) & 127;
  int stage_v_110_2 = ((sec_r000592_5_2 + pub_r000592_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((stage_v_38_1 + pub_r000592_3_1) + 14) & 127;
  int stage_v_111_2 = ((stage_v_38_2 + pub_r000592_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((sec_r000592_4_1 + pub_r000592_12_1) + 11) & 127;
  int stage_v_112_2 = ((sec_r000592_4_2 + pub_r000592_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((sec_r000592_2_1 + pub_r000592_2_1) + 33) & 127;
  int stage_v_113_2 = ((sec_r000592_2_2 + pub_r000592_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((stage_v_82_1 + pub_r000592_11_1) + 17) & 127;
  int stage_v_114_2 = ((stage_v_82_2 + pub_r000592_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((sec_r000592_2_1 + pub_r000592_1_1) + 5) & 127;
  int stage_v_115_2 = ((sec_r000592_2_2 + pub_r000592_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((stage_v_50_1 + pub_r000592_4_1) + 35) & 127;
  int stage_v_116_2 = ((stage_v_50_2 + pub_r000592_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((stage_v_67_1 + pub_r000592_8_1) + 31) & 127;
  int stage_v_117_2 = ((stage_v_67_2 + pub_r000592_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((stage_v_39_1 + pub_r000592_6_1) + 15) & 127;
  int stage_v_118_2 = ((stage_v_39_2 + pub_r000592_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((stage_v_53_1 + pub_r000592_14_1) + 3) & 127;
  int stage_v_119_2 = ((stage_v_53_2 + pub_r000592_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((sec_r000592_17_1 + pub_r000592_9_1) + 49) & 127;
  int stage_v_120_2 = ((sec_r000592_17_2 + pub_r000592_9_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((stage_v_44_1 + pub_r000592_3_1) + 17) & 127;
  int stage_v_121_2 = ((stage_v_44_2 + pub_r000592_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((stage_v_30_1 + pub_r000592_4_1) + 47) & 127;
  int stage_v_122_2 = ((stage_v_30_2 + pub_r000592_4_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((stage_v_97_1 + pub_r000592_11_1) + 33) & 127;
  int stage_v_123_2 = ((stage_v_97_2 + pub_r000592_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((stage_v_100_1 + pub_r000592_8_1) + 33) & 127;
  int stage_v_124_2 = ((stage_v_100_2 + pub_r000592_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((sec_r000592_1_1 + pub_r000592_12_1) + 39) & 127;
  int stage_v_125_2 = ((sec_r000592_1_2 + pub_r000592_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((stage_v_76_1 + pub_r000592_12_1) + 36) & 127;
  int stage_v_126_2 = ((stage_v_76_2 + pub_r000592_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((stage_v_22_1 + pub_r000592_10_1) + 26) & 127;
  int stage_v_127_2 = ((stage_v_22_2 + pub_r000592_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((stage_v_88_1 + pub_r000592_7_1) + 16) & 127;
  int stage_v_128_2 = ((stage_v_88_2 + pub_r000592_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((stage_v_56_1 + pub_r000592_15_1) + 49) & 127;
  int stage_v_129_2 = ((stage_v_56_2 + pub_r000592_15_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((stage_v_112_1 + pub_r000592_6_1) + 43) & 127;
  int stage_v_130_2 = ((stage_v_112_2 + pub_r000592_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((sec_r000592_8_1 + pub_r000592_12_1) + 22) & 127;
  int stage_v_131_2 = ((sec_r000592_8_2 + pub_r000592_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((sec_r000592_12_1 + pub_r000592_11_1) + 19) & 127;
  int stage_v_132_2 = ((sec_r000592_12_2 + pub_r000592_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((stage_v_54_1 + pub_r000592_11_1) + 5) & 127;
  int stage_v_133_2 = ((stage_v_54_2 + pub_r000592_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((sec_r000592_7_1 + pub_r000592_16_1) + 5) & 127;
  int stage_v_134_2 = ((sec_r000592_7_2 + pub_r000592_16_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((stage_v_120_1 + pub_r000592_9_1) + 38) & 127;
  int stage_v_135_2 = ((stage_v_120_2 + pub_r000592_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((stage_v_58_1 + pub_r000592_9_1) + 7) & 127;
  int stage_v_136_2 = ((stage_v_58_2 + pub_r000592_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((sec_r000592_5_1 + pub_r000592_8_1) + 13) & 127;
  int stage_v_137_2 = ((sec_r000592_5_2 + pub_r000592_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((stage_v_119_1 + pub_r000592_1_1) + 9) & 127;
  int stage_v_138_2 = ((stage_v_119_2 + pub_r000592_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((sec_r000592_9_1 + pub_r000592_9_1) + 45) & 127;
  int stage_v_139_2 = ((sec_r000592_9_2 + pub_r000592_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((sec_r000592_3_1 + pub_r000592_8_1) + 47) & 127;
  int stage_v_140_2 = ((sec_r000592_3_2 + pub_r000592_8_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((sec_r000592_9_1 + pub_r000592_4_1) + 41) & 127;
  int stage_v_141_2 = ((sec_r000592_9_2 + pub_r000592_4_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((sec_r000592_14_1 + pub_r000592_10_1) + 26) & 127;
  int stage_v_142_2 = ((sec_r000592_14_2 + pub_r000592_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((stage_v_28_1 + pub_r000592_14_1) + 44) & 127;
  int stage_v_143_2 = ((stage_v_28_2 + pub_r000592_14_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((sec_r000592_4_1 + pub_r000592_6_1) + 38) & 127;
  int stage_v_144_2 = ((sec_r000592_4_2 + pub_r000592_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((stage_v_88_1 + pub_r000592_11_1) + 47) & 127;
  int stage_v_145_2 = ((stage_v_88_2 + pub_r000592_11_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((stage_v_22_1 + pub_r000592_13_1) + 12) & 127;
  int stage_v_146_2 = ((stage_v_22_2 + pub_r000592_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((stage_v_109_1 + pub_r000592_15_1) + 28) & 127;
  int stage_v_147_2 = ((stage_v_109_2 + pub_r000592_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((stage_v_68_1 + pub_r000592_15_1) + 35) & 127;
  int stage_v_148_2 = ((stage_v_68_2 + pub_r000592_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((stage_v_144_1 + pub_r000592_11_1) + 12) & 127;
  int stage_v_149_2 = ((stage_v_144_2 + pub_r000592_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((stage_v_146_1 + pub_r000592_12_1) + 24) & 127;
  int stage_v_150_2 = ((stage_v_146_2 + pub_r000592_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((sec_r000592_9_1 + pub_r000592_17_1) + 43) & 127;
  int stage_v_151_2 = ((sec_r000592_9_2 + pub_r000592_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((stage_v_56_1 + pub_r000592_11_1) + 43) & 127;
  int stage_v_152_2 = ((stage_v_56_2 + pub_r000592_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((sec_r000592_2_1 + pub_r000592_6_1) + 23) & 127;
  int stage_v_153_2 = ((sec_r000592_2_2 + pub_r000592_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((stage_v_74_1 + pub_r000592_8_1) + 48) & 127;
  int stage_v_154_2 = ((stage_v_74_2 + pub_r000592_8_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((stage_v_111_1 + pub_r000592_0_1) + 7) & 127;
  int stage_v_155_2 = ((stage_v_111_2 + pub_r000592_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((stage_v_107_1 + pub_r000592_8_1) + 46) & 127;
  int stage_v_156_2 = ((stage_v_107_2 + pub_r000592_8_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((sec_r000592_10_1 + pub_r000592_6_1) + 12) & 127;
  int stage_v_157_2 = ((sec_r000592_10_2 + pub_r000592_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((stage_v_143_1 + pub_r000592_11_1) + 37) & 127;
  int stage_v_158_2 = ((stage_v_143_2 + pub_r000592_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((stage_v_116_1 + pub_r000592_12_1) + 49) & 127;
  int stage_v_159_2 = ((stage_v_116_2 + pub_r000592_12_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((stage_v_65_1 + pub_r000592_0_1) + 44) & 127;
  int stage_v_160_2 = ((stage_v_65_2 + pub_r000592_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((sec_r000592_16_1 + pub_r000592_9_1) + 41) & 127;
  int stage_v_161_2 = ((sec_r000592_16_2 + pub_r000592_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((sec_r000592_1_1 + pub_r000592_9_1) + 22) & 127;
  int stage_v_162_2 = ((sec_r000592_1_2 + pub_r000592_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((stage_v_70_1 + pub_r000592_18_1) + 37) & 127;
  int stage_v_163_2 = ((stage_v_70_2 + pub_r000592_18_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((stage_v_128_1 + pub_r000592_7_1) + 19) & 127;
  int stage_v_164_2 = ((stage_v_128_2 + pub_r000592_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((sec_r000592_1_1 + pub_r000592_10_1) + 29) & 127;
  int stage_v_165_2 = ((sec_r000592_1_2 + pub_r000592_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((stage_v_81_1 + pub_r000592_12_1) + 31) & 127;
  int stage_v_166_2 = ((stage_v_81_2 + pub_r000592_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((stage_v_72_1 + pub_r000592_15_1) + 45) & 127;
  int stage_v_167_2 = ((stage_v_72_2 + pub_r000592_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((stage_v_72_1 + pub_r000592_14_1) + 5) & 127;
  int stage_v_168_2 = ((stage_v_72_2 + pub_r000592_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((stage_v_45_1 + pub_r000592_6_1) + 35) & 127;
  int stage_v_169_2 = ((stage_v_45_2 + pub_r000592_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((stage_v_143_1 + pub_r000592_0_1) + 45) & 127;
  int stage_v_170_2 = ((stage_v_143_2 + pub_r000592_0_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((stage_v_128_1 + pub_r000592_0_1) + 49) & 127;
  int stage_v_171_2 = ((stage_v_128_2 + pub_r000592_0_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((stage_v_78_1 + pub_r000592_8_1) + 34) & 127;
  int stage_v_172_2 = ((stage_v_78_2 + pub_r000592_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((stage_v_42_1 + pub_r000592_15_1) + 23) & 127;
  int stage_v_173_2 = ((stage_v_42_2 + pub_r000592_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((stage_v_119_1 + pub_r000592_3_1) + 35) & 127;
  int stage_v_174_2 = ((stage_v_119_2 + pub_r000592_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((sec_r000592_13_1 + pub_r000592_9_1) + 32) & 127;
  int stage_v_175_2 = ((sec_r000592_13_2 + pub_r000592_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((sec_r000592_11_1 + pub_r000592_12_1) + 6) & 127;
  int stage_v_176_2 = ((sec_r000592_11_2 + pub_r000592_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((stage_v_113_1 + pub_r000592_15_1) + 47) & 127;
  int stage_v_177_2 = ((stage_v_113_2 + pub_r000592_15_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((sec_r000592_10_1 + pub_r000592_6_1) + 30) & 127;
  int stage_v_178_2 = ((sec_r000592_10_2 + pub_r000592_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((stage_v_41_1 + pub_r000592_8_1) + 25) & 127;
  int stage_v_179_2 = ((stage_v_41_2 + pub_r000592_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((sec_r000592_16_1 + pub_r000592_6_1) + 41) & 127;
  int stage_v_180_2 = ((sec_r000592_16_2 + pub_r000592_6_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((stage_v_134_1 + pub_r000592_13_1) + 31) & 127;
  int stage_v_181_2 = ((stage_v_134_2 + pub_r000592_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((sec_r000592_4_1 + pub_r000592_7_1) + 47) & 127;
  int stage_v_182_2 = ((sec_r000592_4_2 + pub_r000592_7_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((stage_v_62_1 + pub_r000592_13_1) + 17) & 127;
  int stage_v_183_2 = ((stage_v_62_2 + pub_r000592_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((sec_r000592_11_1 + pub_r000592_7_1) + 4) & 127;
  int stage_v_184_2 = ((sec_r000592_11_2 + pub_r000592_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((stage_v_79_1 + pub_r000592_6_1) + 36) & 127;
  int stage_v_185_2 = ((stage_v_79_2 + pub_r000592_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((stage_v_106_1 + pub_r000592_10_1) + 12) & 127;
  int stage_v_186_2 = ((stage_v_106_2 + pub_r000592_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((stage_v_31_1 + pub_r000592_13_1) + 33) & 127;
  int stage_v_187_2 = ((stage_v_31_2 + pub_r000592_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((stage_v_76_1 + pub_r000592_16_1) + 42) & 127;
  int stage_v_188_2 = ((stage_v_76_2 + pub_r000592_16_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((stage_v_118_1 + pub_r000592_7_1) + 30) & 127;
  int stage_v_189_2 = ((stage_v_118_2 + pub_r000592_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((stage_v_64_1 + pub_r000592_4_1) + 35) & 127;
  int stage_v_190_2 = ((stage_v_64_2 + pub_r000592_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((stage_v_27_1 + pub_r000592_8_1) + 15) & 127;
  int stage_v_191_2 = ((stage_v_27_2 + pub_r000592_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((sec_r000592_3_1 + pub_r000592_12_1) + 16) & 127;
  int stage_v_192_2 = ((sec_r000592_3_2 + pub_r000592_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((stage_v_142_1 + pub_r000592_10_1) + 18) & 127;
  int stage_v_193_2 = ((stage_v_142_2 + pub_r000592_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((sec_r000592_1_1 + pub_r000592_10_1) + 16) & 127;
  int stage_v_194_2 = ((sec_r000592_1_2 + pub_r000592_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((stage_v_175_1 + pub_r000592_18_1) + 17) & 127;
  int stage_v_195_2 = ((stage_v_175_2 + pub_r000592_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((stage_v_188_1 + pub_r000592_5_1) + 18) & 127;
  int stage_v_196_2 = ((stage_v_188_2 + pub_r000592_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((sec_r000592_1_1 + pub_r000592_6_1) + 43) & 127;
  int stage_v_197_2 = ((sec_r000592_1_2 + pub_r000592_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((stage_v_183_1 + pub_r000592_6_1) + 17) & 127;
  int stage_v_198_2 = ((stage_v_183_2 + pub_r000592_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((stage_v_189_1 + pub_r000592_7_1) + 42) & 127;
  int stage_v_199_2 = ((stage_v_189_2 + pub_r000592_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((stage_v_97_1 + pub_r000592_8_1) + 11) & 127;
  int stage_v_200_2 = ((stage_v_97_2 + pub_r000592_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((stage_v_145_1 + pub_r000592_8_1) + 30) & 127;
  int stage_v_201_2 = ((stage_v_145_2 + pub_r000592_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((stage_v_44_1 + pub_r000592_4_1) + 40) & 127;
  int stage_v_202_2 = ((stage_v_44_2 + pub_r000592_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((sec_r000592_14_1 + pub_r000592_3_1) + 10) & 127;
  int stage_v_203_2 = ((sec_r000592_14_2 + pub_r000592_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((sec_r000592_3_1 + pub_r000592_11_1) + 26) & 127;
  int stage_v_204_2 = ((sec_r000592_3_2 + pub_r000592_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((sec_r000592_15_1 + pub_r000592_3_1) + 14) & 127;
  int stage_v_205_2 = ((sec_r000592_15_2 + pub_r000592_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((sec_r000592_0_1 + pub_r000592_18_1) + 34) & 127;
  int stage_v_206_2 = ((sec_r000592_0_2 + pub_r000592_18_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((stage_v_55_1 + pub_r000592_5_1) + 21) & 127;
  int stage_v_207_2 = ((stage_v_55_2 + pub_r000592_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((sec_r000592_4_1 + pub_r000592_16_1) + 41) & 127;
  int stage_v_208_2 = ((sec_r000592_4_2 + pub_r000592_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((stage_v_128_1 + pub_r000592_8_1) + 49) & 127;
  int stage_v_209_2 = ((stage_v_128_2 + pub_r000592_8_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((stage_v_87_1 + pub_r000592_5_1) + 43) & 127;
  int stage_v_210_2 = ((stage_v_87_2 + pub_r000592_5_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((sec_r000592_5_1 + pub_r000592_14_1) + 20) & 127;
  int stage_v_211_2 = ((sec_r000592_5_2 + pub_r000592_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((sec_r000592_7_1 + pub_r000592_6_1) + 10) & 127;
  int stage_v_212_2 = ((sec_r000592_7_2 + pub_r000592_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((stage_v_151_1 + pub_r000592_15_1) + 40) & 127;
  int stage_v_213_2 = ((stage_v_151_2 + pub_r000592_15_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((stage_v_142_1 + pub_r000592_15_1) + 9) & 127;
  int stage_v_214_2 = ((stage_v_142_2 + pub_r000592_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((stage_v_170_1 + pub_r000592_11_1) + 16) & 127;
  int stage_v_215_2 = ((stage_v_170_2 + pub_r000592_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((sec_r000592_9_1 + pub_r000592_4_1) + 6) & 127;
  int stage_v_216_2 = ((sec_r000592_9_2 + pub_r000592_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((stage_v_94_1 + pub_r000592_12_1) + 28) & 127;
  int stage_v_217_2 = ((stage_v_94_2 + pub_r000592_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((stage_v_78_1 + pub_r000592_17_1) + 41) & 127;
  int stage_v_218_2 = ((stage_v_78_2 + pub_r000592_17_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((sec_r000592_6_1 + pub_r000592_1_1) + 21) & 127;
  int stage_v_219_2 = ((sec_r000592_6_2 + pub_r000592_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((stage_v_117_1 + pub_r000592_5_1) + 17) & 127;
  int stage_v_220_2 = ((stage_v_117_2 + pub_r000592_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((stage_v_48_1 + pub_r000592_12_1) + 41) & 127;
  int stage_v_221_2 = ((stage_v_48_2 + pub_r000592_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((stage_v_102_1 + pub_r000592_18_1) + 30) & 127;
  int stage_v_222_2 = ((stage_v_102_2 + pub_r000592_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((sec_r000592_16_1 + pub_r000592_13_1) + 42) & 127;
  int stage_v_223_2 = ((sec_r000592_16_2 + pub_r000592_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((stage_v_109_1 + pub_r000592_16_1) + 20) & 127;
  int stage_v_224_2 = ((stage_v_109_2 + pub_r000592_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((sec_r000592_6_1 + pub_r000592_14_1) + 31) & 127;
  int stage_v_225_2 = ((sec_r000592_6_2 + pub_r000592_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((stage_v_61_1 + pub_r000592_0_1) + 15) & 127;
  int stage_v_226_2 = ((stage_v_61_2 + pub_r000592_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((stage_v_225_1 + pub_r000592_8_1) + 19) & 127;
  int stage_v_227_2 = ((stage_v_225_2 + pub_r000592_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((sec_r000592_13_1 + pub_r000592_4_1) + 43) & 127;
  int stage_v_228_2 = ((sec_r000592_13_2 + pub_r000592_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((stage_v_27_1 + pub_r000592_10_1) + 18) & 127;
  int stage_v_229_2 = ((stage_v_27_2 + pub_r000592_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((stage_v_148_1 + pub_r000592_2_1) + 39) & 127;
  int stage_v_230_2 = ((stage_v_148_2 + pub_r000592_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((sec_r000592_8_1 + pub_r000592_13_1) + 33) & 127;
  int stage_v_231_2 = ((sec_r000592_8_2 + pub_r000592_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((stage_v_141_1 + pub_r000592_16_1) + 39) & 127;
  int stage_v_232_2 = ((stage_v_141_2 + pub_r000592_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((sec_r000592_5_1 + pub_r000592_3_1) + 33) & 127;
  int stage_v_233_2 = ((sec_r000592_5_2 + pub_r000592_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((sec_r000592_3_1 + pub_r000592_0_1) + 21) & 127;
  int stage_v_234_2 = ((sec_r000592_3_2 + pub_r000592_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((sec_r000592_11_1 + pub_r000592_15_1) + 49) & 127;
  int stage_v_235_2 = ((sec_r000592_11_2 + pub_r000592_15_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((stage_v_180_1 + pub_r000592_10_1) + 23) & 127;
  int stage_v_236_2 = ((stage_v_180_2 + pub_r000592_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((stage_v_211_1 + pub_r000592_18_1) + 18) & 127;
  int stage_v_237_2 = ((stage_v_211_2 + pub_r000592_18_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((stage_v_68_1 + pub_r000592_2_1) + 15) & 127;
  int stage_v_238_2 = ((stage_v_68_2 + pub_r000592_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((sec_r000592_17_1 + pub_r000592_6_1) + 15) & 127;
  int stage_v_239_2 = ((sec_r000592_17_2 + pub_r000592_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((sec_r000592_12_1 + pub_r000592_6_1) + 29) & 127;
  int stage_v_240_2 = ((sec_r000592_12_2 + pub_r000592_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((sec_r000592_2_1 + pub_r000592_0_1) + 46) & 127;
  int stage_v_241_2 = ((sec_r000592_2_2 + pub_r000592_0_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((sec_r000592_5_1 + pub_r000592_9_1) + 36) & 127;
  int stage_v_242_2 = ((sec_r000592_5_2 + pub_r000592_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((sec_r000592_16_1 + pub_r000592_9_1) + 46) & 127;
  int stage_v_243_2 = ((sec_r000592_16_2 + pub_r000592_9_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((stage_v_160_1 + pub_r000592_16_1) + 8) & 127;
  int stage_v_244_2 = ((stage_v_160_2 + pub_r000592_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((sec_r000592_12_1 + pub_r000592_13_1) + 14) & 127;
  int stage_v_245_2 = ((sec_r000592_12_2 + pub_r000592_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((stage_v_172_1 + pub_r000592_1_1) + 19) & 127;
  int stage_v_246_2 = ((stage_v_172_2 + pub_r000592_1_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((stage_v_243_1 + pub_r000592_16_1) + 12) & 127;
  int stage_v_247_2 = ((stage_v_243_2 + pub_r000592_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((sec_r000592_15_1 + pub_r000592_15_1) + 9) & 127;
  int stage_v_248_2 = ((sec_r000592_15_2 + pub_r000592_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((sec_r000592_7_1 + pub_r000592_4_1) + 33) & 127;
  int stage_v_249_2 = ((sec_r000592_7_2 + pub_r000592_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((stage_v_57_1 + pub_r000592_7_1) + 20) & 127;
  int stage_v_250_2 = ((stage_v_57_2 + pub_r000592_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((stage_v_149_1 + pub_r000592_2_1) + 35) & 127;
  int stage_v_251_2 = ((stage_v_149_2 + pub_r000592_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((stage_v_112_1 + pub_r000592_13_1) + 40) & 127;
  int stage_v_252_2 = ((stage_v_112_2 + pub_r000592_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((stage_v_55_1 + pub_r000592_10_1) + 9) & 127;
  int stage_v_253_2 = ((stage_v_55_2 + pub_r000592_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((stage_v_210_1 + pub_r000592_14_1) + 34) & 127;
  int stage_v_254_2 = ((stage_v_210_2 + pub_r000592_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((stage_v_226_1 + pub_r000592_11_1) + 26) & 127;
  int stage_v_255_2 = ((stage_v_226_2 + pub_r000592_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((stage_v_25_1 + pub_r000592_15_1) + 34) & 127;
  int stage_v_256_2 = ((stage_v_25_2 + pub_r000592_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((stage_v_155_1 + pub_r000592_2_1) + 27) & 127;
  int stage_v_257_2 = ((stage_v_155_2 + pub_r000592_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((stage_v_225_1 + pub_r000592_18_1) + 28) & 127;
  int stage_v_258_2 = ((stage_v_225_2 + pub_r000592_18_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((sec_r000592_4_1 + pub_r000592_3_1) + 10) & 127;
  int stage_v_259_2 = ((sec_r000592_4_2 + pub_r000592_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((stage_v_200_1 + pub_r000592_5_1) + 49) & 127;
  int stage_v_260_2 = ((stage_v_200_2 + pub_r000592_5_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((stage_v_93_1 + pub_r000592_5_1) + 23) & 127;
  int stage_v_261_2 = ((stage_v_93_2 + pub_r000592_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((stage_v_32_1 + pub_r000592_18_1) + 32) & 127;
  int stage_v_262_2 = ((stage_v_32_2 + pub_r000592_18_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((sec_r000592_9_1 + pub_r000592_8_1) + 31) & 127;
  int stage_v_263_2 = ((sec_r000592_9_2 + pub_r000592_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((stage_v_133_1 + pub_r000592_17_1) + 18) & 127;
  int stage_v_264_2 = ((stage_v_133_2 + pub_r000592_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((stage_v_72_1 + pub_r000592_1_1) + 14) & 127;
  int stage_v_265_2 = ((stage_v_72_2 + pub_r000592_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((sec_r000592_13_1 + pub_r000592_9_1) + 16) & 127;
  int stage_v_266_2 = ((sec_r000592_13_2 + pub_r000592_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((sec_r000592_7_1 + pub_r000592_4_1) + 5) & 127;
  int stage_v_267_2 = ((sec_r000592_7_2 + pub_r000592_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((sec_r000592_12_1 + pub_r000592_13_1) + 19) & 127;
  int stage_v_268_2 = ((sec_r000592_12_2 + pub_r000592_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((stage_v_245_1 + pub_r000592_13_1) + 17) & 127;
  int stage_v_269_2 = ((stage_v_245_2 + pub_r000592_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((stage_v_79_1 + pub_r000592_0_1) + 36) & 127;
  int stage_v_270_2 = ((stage_v_79_2 + pub_r000592_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((stage_v_224_1 + pub_r000592_15_1) + 19) & 127;
  int stage_v_271_2 = ((stage_v_224_2 + pub_r000592_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((stage_v_255_1 + pub_r000592_4_1) + 21) & 127;
  int stage_v_272_2 = ((stage_v_255_2 + pub_r000592_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((stage_v_48_1 + pub_r000592_8_1) + 34) & 127;
  int stage_v_273_2 = ((stage_v_48_2 + pub_r000592_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((stage_v_21_1 + pub_r000592_12_1) + 35) & 127;
  int stage_v_274_2 = ((stage_v_21_2 + pub_r000592_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((stage_v_272_1 + pub_r000592_10_1) + 6) & 127;
  int stage_v_275_2 = ((stage_v_272_2 + pub_r000592_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((stage_v_264_1 + pub_r000592_18_1) + 23) & 127;
  int stage_v_276_2 = ((stage_v_264_2 + pub_r000592_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((stage_v_172_1 + pub_r000592_5_1) + 31) & 127;
  int stage_v_277_2 = ((stage_v_172_2 + pub_r000592_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((stage_v_111_1 + pub_r000592_10_1) + 44) & 127;
  int stage_v_278_2 = ((stage_v_111_2 + pub_r000592_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((stage_v_49_1 + pub_r000592_5_1) + 4) & 127;
  int stage_v_279_2 = ((stage_v_49_2 + pub_r000592_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((stage_v_170_1 + pub_r000592_10_1) + 26) & 127;
  int stage_v_280_2 = ((stage_v_170_2 + pub_r000592_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((sec_r000592_9_1 + pub_r000592_1_1) + 22) & 127;
  int stage_v_281_2 = ((sec_r000592_9_2 + pub_r000592_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((sec_r000592_2_1 + pub_r000592_14_1) + 8) & 127;
  int stage_v_282_2 = ((sec_r000592_2_2 + pub_r000592_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((stage_v_232_1 + pub_r000592_10_1) + 23) & 127;
  int stage_v_283_2 = ((stage_v_232_2 + pub_r000592_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((sec_r000592_3_1 + pub_r000592_0_1) + 39) & 127;
  int stage_v_284_2 = ((sec_r000592_3_2 + pub_r000592_0_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((sec_r000592_13_1 + pub_r000592_9_1) + 31) & 127;
  int stage_v_285_2 = ((sec_r000592_13_2 + pub_r000592_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((stage_v_216_1 + pub_r000592_17_1) + 5) & 127;
  int stage_v_286_2 = ((stage_v_216_2 + pub_r000592_17_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((stage_v_172_1 + pub_r000592_16_1) + 4) & 127;
  int stage_v_287_2 = ((stage_v_172_2 + pub_r000592_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((sec_r000592_13_1 + pub_r000592_10_1) + 39) & 127;
  int stage_v_288_2 = ((sec_r000592_13_2 + pub_r000592_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((stage_v_104_1 + pub_r000592_15_1) + 27) & 127;
  int stage_v_289_2 = ((stage_v_104_2 + pub_r000592_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((stage_v_150_1 + pub_r000592_4_1) + 44) & 127;
  int stage_v_290_2 = ((stage_v_150_2 + pub_r000592_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((stage_v_224_1 + pub_r000592_12_1) + 42) & 127;
  int stage_v_291_2 = ((stage_v_224_2 + pub_r000592_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((stage_v_185_1 + pub_r000592_9_1) + 3) & 127;
  int stage_v_292_2 = ((stage_v_185_2 + pub_r000592_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((stage_v_280_1 + pub_r000592_18_1) + 36) & 127;
  int stage_v_293_2 = ((stage_v_280_2 + pub_r000592_18_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((stage_v_252_1 + pub_r000592_14_1) + 42) & 127;
  int stage_v_294_2 = ((stage_v_252_2 + pub_r000592_14_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((stage_v_99_1 + pub_r000592_4_1) + 30) & 127;
  int stage_v_295_2 = ((stage_v_99_2 + pub_r000592_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((sec_r000592_13_1 + pub_r000592_4_1) + 18) & 127;
  int stage_v_296_2 = ((sec_r000592_13_2 + pub_r000592_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((stage_v_205_1 + pub_r000592_14_1) + 22) & 127;
  int stage_v_297_2 = ((stage_v_205_2 + pub_r000592_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((sec_r000592_3_1 + pub_r000592_10_1) + 35) & 127;
  int stage_v_298_2 = ((sec_r000592_3_2 + pub_r000592_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((sec_r000592_5_1 + pub_r000592_15_1) + 42) & 127;
  int stage_v_299_2 = ((sec_r000592_5_2 + pub_r000592_15_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((sec_r000592_5_1 + pub_r000592_10_1) + 13) & 127;
  int stage_v_300_2 = ((sec_r000592_5_2 + pub_r000592_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((stage_v_298_1 + pub_r000592_3_1) + 31) & 127;
  int stage_v_301_2 = ((stage_v_298_2 + pub_r000592_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((stage_v_85_1 + pub_r000592_10_1) + 35) & 127;
  int stage_v_302_2 = ((stage_v_85_2 + pub_r000592_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((stage_v_216_1 + pub_r000592_15_1) + 17) & 127;
  int stage_v_303_2 = ((stage_v_216_2 + pub_r000592_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((sec_r000592_13_1 + pub_r000592_11_1) + 35) & 127;
  int stage_v_304_2 = ((sec_r000592_13_2 + pub_r000592_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((stage_v_88_1 + pub_r000592_5_1) + 24) & 127;
  int stage_v_305_2 = ((stage_v_88_2 + pub_r000592_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((stage_v_24_1 + pub_r000592_17_1) + 23) & 127;
  int stage_v_306_2 = ((stage_v_24_2 + pub_r000592_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((stage_v_223_1 + pub_r000592_16_1) + 35) & 127;
  int stage_v_307_2 = ((stage_v_223_2 + pub_r000592_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((stage_v_95_1 + pub_r000592_14_1) + 22) & 127;
  int stage_v_308_2 = ((stage_v_95_2 + pub_r000592_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((stage_v_190_1 + pub_r000592_0_1) + 16) & 127;
  int stage_v_309_2 = ((stage_v_190_2 + pub_r000592_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((sec_r000592_3_1 + pub_r000592_3_1) + 17) & 127;
  int stage_v_310_2 = ((sec_r000592_3_2 + pub_r000592_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((stage_v_80_1 + pub_r000592_14_1) + 10) & 127;
  int stage_v_311_2 = ((stage_v_80_2 + pub_r000592_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((sec_r000592_16_1 + pub_r000592_7_1) + 36) & 127;
  int stage_v_312_2 = ((sec_r000592_16_2 + pub_r000592_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((stage_v_96_1 + pub_r000592_6_1) + 36) & 127;
  int stage_v_313_2 = ((stage_v_96_2 + pub_r000592_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((stage_v_66_1 + pub_r000592_16_1) + 11) & 127;
  int stage_v_314_2 = ((stage_v_66_2 + pub_r000592_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((stage_v_84_1 + pub_r000592_8_1) + 14) & 127;
  int stage_v_315_2 = ((stage_v_84_2 + pub_r000592_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((stage_v_139_1 + pub_r000592_5_1) + 27) & 127;
  int stage_v_316_2 = ((stage_v_139_2 + pub_r000592_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((stage_v_65_1 + pub_r000592_17_1) + 13) & 127;
  int stage_v_317_2 = ((stage_v_65_2 + pub_r000592_17_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((stage_v_314_1 + pub_r000592_1_1) + 9) & 127;
  int stage_v_318_2 = ((stage_v_314_2 + pub_r000592_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((sec_r000592_5_1 + pub_r000592_11_1) + 28) & 127;
  int stage_v_319_2 = ((sec_r000592_5_2 + pub_r000592_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((sec_r000592_5_1 + pub_r000592_4_1) + 30) & 127;
  int stage_v_320_2 = ((sec_r000592_5_2 + pub_r000592_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((sec_r000592_3_1 + pub_r000592_15_1) + 4) & 127;
  int stage_v_321_2 = ((sec_r000592_3_2 + pub_r000592_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int stage_v_322_1 = ((sec_r000592_4_1 + pub_r000592_17_1) + 6) & 127;
  int stage_v_322_2 = ((sec_r000592_4_2 + pub_r000592_17_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int stage_v_323_1 = ((stage_v_163_1 + pub_r000592_8_1) + 14) & 127;
  int stage_v_323_2 = ((stage_v_163_2 + pub_r000592_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int stage_v_324_1 = ((stage_v_248_1 + pub_r000592_14_1) + 31) & 127;
  int stage_v_324_2 = ((stage_v_248_2 + pub_r000592_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int stage_v_325_1 = ((stage_v_258_1 + pub_r000592_12_1) + 12) & 127;
  int stage_v_325_2 = ((stage_v_258_2 + pub_r000592_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  int stage_v_326_1 = ((sec_r000592_14_1 + pub_r000592_10_1) + 34) & 127;
  int stage_v_326_2 = ((sec_r000592_14_2 + pub_r000592_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_326_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_326_2) & 255;
  int stage_v_327_1 = ((stage_v_271_1 + pub_r000592_10_1) + 47) & 127;
  int stage_v_327_2 = ((stage_v_271_2 + pub_r000592_10_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_327_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_327_2) & 255;
  int stage_v_328_1 = ((stage_v_276_1 + pub_r000592_6_1) + 43) & 127;
  int stage_v_328_2 = ((stage_v_276_2 + pub_r000592_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_328_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_328_2) & 255;
  int stage_v_329_1 = ((sec_r000592_3_1 + pub_r000592_12_1) + 20) & 127;
  int stage_v_329_2 = ((sec_r000592_3_2 + pub_r000592_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_329_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_329_2) & 255;
  int stage_v_330_1 = ((sec_r000592_3_1 + pub_r000592_2_1) + 17) & 127;
  int stage_v_330_2 = ((sec_r000592_3_2 + pub_r000592_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_330_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_330_2) & 255;
  int stage_v_331_1 = ((stage_v_257_1 + pub_r000592_5_1) + 7) & 127;
  int stage_v_331_2 = ((stage_v_257_2 + pub_r000592_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_331_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_331_2) & 255;
  int stage_v_332_1 = ((sec_r000592_14_1 + pub_r000592_8_1) + 8) & 127;
  int stage_v_332_2 = ((sec_r000592_14_2 + pub_r000592_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_332_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_332_2) & 255;
  int stage_v_333_1 = ((stage_v_275_1 + pub_r000592_10_1) + 43) & 127;
  int stage_v_333_2 = ((stage_v_275_2 + pub_r000592_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_333_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_333_2) & 255;
  int stage_v_334_1 = ((stage_v_102_1 + pub_r000592_10_1) + 48) & 127;
  int stage_v_334_2 = ((stage_v_102_2 + pub_r000592_10_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_334_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_334_2) & 255;
  int stage_v_335_1 = ((sec_r000592_15_1 + pub_r000592_11_1) + 8) & 127;
  int stage_v_335_2 = ((sec_r000592_15_2 + pub_r000592_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_335_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_335_2) & 255;
  int stage_v_336_1 = ((stage_v_47_1 + pub_r000592_6_1) + 33) & 127;
  int stage_v_336_2 = ((stage_v_47_2 + pub_r000592_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_336_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_336_2) & 255;
  int stage_v_337_1 = ((stage_v_49_1 + pub_r000592_3_1) + 8) & 127;
  int stage_v_337_2 = ((stage_v_49_2 + pub_r000592_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_337_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_337_2) & 255;
  int stage_v_338_1 = ((sec_r000592_16_1 + pub_r000592_2_1) + 36) & 127;
  int stage_v_338_2 = ((sec_r000592_16_2 + pub_r000592_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_338_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_338_2) & 255;
  int stage_v_339_1 = ((stage_v_237_1 + pub_r000592_9_1) + 24) & 127;
  int stage_v_339_2 = ((stage_v_237_2 + pub_r000592_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_339_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_339_2) & 255;
  int stage_v_340_1 = ((stage_v_74_1 + pub_r000592_10_1) + 18) & 127;
  int stage_v_340_2 = ((stage_v_74_2 + pub_r000592_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_340_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_340_2) & 255;
  int stage_v_341_1 = ((stage_v_146_1 + pub_r000592_12_1) + 28) & 127;
  int stage_v_341_2 = ((stage_v_146_2 + pub_r000592_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_341_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_341_2) & 255;
  int stage_v_342_1 = ((stage_v_163_1 + pub_r000592_0_1) + 34) & 127;
  int stage_v_342_2 = ((stage_v_163_2 + pub_r000592_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_342_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_342_2) & 255;
  int stage_v_343_1 = ((stage_v_212_1 + pub_r000592_8_1) + 12) & 127;
  int stage_v_343_2 = ((stage_v_212_2 + pub_r000592_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_343_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_343_2) & 255;
  int stage_v_344_1 = ((stage_v_70_1 + pub_r000592_3_1) + 16) & 127;
  int stage_v_344_2 = ((stage_v_70_2 + pub_r000592_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_344_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_344_2) & 255;
  int stage_v_345_1 = ((stage_v_61_1 + pub_r000592_13_1) + 17) & 127;
  int stage_v_345_2 = ((stage_v_61_2 + pub_r000592_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_345_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_345_2) & 255;
  int stage_v_346_1 = ((stage_v_29_1 + pub_r000592_4_1) + 27) & 127;
  int stage_v_346_2 = ((stage_v_29_2 + pub_r000592_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_346_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_346_2) & 255;
  int stage_v_347_1 = ((sec_r000592_17_1 + pub_r000592_5_1) + 31) & 127;
  int stage_v_347_2 = ((sec_r000592_17_2 + pub_r000592_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_347_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_347_2) & 255;
  int stage_v_348_1 = ((stage_v_167_1 + pub_r000592_5_1) + 6) & 127;
  int stage_v_348_2 = ((stage_v_167_2 + pub_r000592_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_348_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_348_2) & 255;
  int stage_v_349_1 = ((stage_v_192_1 + pub_r000592_2_1) + 30) & 127;
  int stage_v_349_2 = ((stage_v_192_2 + pub_r000592_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_349_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_349_2) & 255;
  int stage_v_350_1 = ((stage_v_142_1 + pub_r000592_1_1) + 32) & 127;
  int stage_v_350_2 = ((stage_v_142_2 + pub_r000592_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_350_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_350_2) & 255;
  int stage_v_351_1 = ((sec_r000592_3_1 + pub_r000592_7_1) + 9) & 127;
  int stage_v_351_2 = ((sec_r000592_3_2 + pub_r000592_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_351_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_351_2) & 255;
  int stage_v_352_1 = ((stage_v_75_1 + pub_r000592_5_1) + 11) & 127;
  int stage_v_352_2 = ((stage_v_75_2 + pub_r000592_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_352_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_352_2) & 255;
  int stage_v_353_1 = ((stage_v_138_1 + pub_r000592_6_1) + 45) & 127;
  int stage_v_353_2 = ((stage_v_138_2 + pub_r000592_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_353_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_353_2) & 255;
  int stage_v_354_1 = ((stage_v_149_1 + pub_r000592_1_1) + 47) & 127;
  int stage_v_354_2 = ((stage_v_149_2 + pub_r000592_1_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_354_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_354_2) & 255;
  int stage_v_355_1 = ((sec_r000592_10_1 + pub_r000592_3_1) + 16) & 127;
  int stage_v_355_2 = ((sec_r000592_10_2 + pub_r000592_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_355_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_355_2) & 255;
  int stage_v_356_1 = ((stage_v_147_1 + pub_r000592_15_1) + 45) & 127;
  int stage_v_356_2 = ((stage_v_147_2 + pub_r000592_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_356_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_356_2) & 255;
  int stage_v_357_1 = ((stage_v_297_1 + pub_r000592_12_1) + 47) & 127;
  int stage_v_357_2 = ((stage_v_297_2 + pub_r000592_12_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_357_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_357_2) & 255;
  int stage_v_358_1 = ((stage_v_92_1 + pub_r000592_0_1) + 47) & 127;
  int stage_v_358_2 = ((stage_v_92_2 + pub_r000592_0_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_358_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_358_2) & 255;
  int stage_v_359_1 = ((stage_v_205_1 + pub_r000592_5_1) + 46) & 127;
  int stage_v_359_2 = ((stage_v_205_2 + pub_r000592_5_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_359_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_359_2) & 255;
  int stage_v_360_1 = ((stage_v_348_1 + pub_r000592_14_1) + 41) & 127;
  int stage_v_360_2 = ((stage_v_348_2 + pub_r000592_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_360_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_360_2) & 255;
  int stage_v_361_1 = ((stage_v_43_1 + pub_r000592_10_1) + 43) & 127;
  int stage_v_361_2 = ((stage_v_43_2 + pub_r000592_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_361_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_361_2) & 255;
  int stage_v_362_1 = ((sec_r000592_0_1 + pub_r000592_5_1) + 20) & 127;
  int stage_v_362_2 = ((sec_r000592_0_2 + pub_r000592_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_362_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_362_2) & 255;
  int stage_v_363_1 = ((stage_v_224_1 + pub_r000592_10_1) + 26) & 127;
  int stage_v_363_2 = ((stage_v_224_2 + pub_r000592_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_363_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_363_2) & 255;
  int stage_v_364_1 = ((stage_v_104_1 + pub_r000592_15_1) + 28) & 127;
  int stage_v_364_2 = ((stage_v_104_2 + pub_r000592_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_364_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_364_2) & 255;
  int stage_v_365_1 = ((stage_v_137_1 + pub_r000592_2_1) + 47) & 127;
  int stage_v_365_2 = ((stage_v_137_2 + pub_r000592_2_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_365_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_365_2) & 255;
  int stage_v_366_1 = ((stage_v_219_1 + pub_r000592_15_1) + 12) & 127;
  int stage_v_366_2 = ((stage_v_219_2 + pub_r000592_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_366_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_366_2) & 255;
  int stage_v_367_1 = ((sec_r000592_7_1 + pub_r000592_1_1) + 5) & 127;
  int stage_v_367_2 = ((sec_r000592_7_2 + pub_r000592_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_367_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_367_2) & 255;
  int stage_v_368_1 = ((stage_v_312_1 + pub_r000592_2_1) + 23) & 127;
  int stage_v_368_2 = ((stage_v_312_2 + pub_r000592_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_368_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_368_2) & 255;
  int stage_v_369_1 = ((stage_v_153_1 + pub_r000592_1_1) + 31) & 127;
  int stage_v_369_2 = ((stage_v_153_2 + pub_r000592_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_369_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_369_2) & 255;
  int stage_v_370_1 = ((stage_v_127_1 + pub_r000592_0_1) + 45) & 127;
  int stage_v_370_2 = ((stage_v_127_2 + pub_r000592_0_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_370_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_370_2) & 255;
  int stage_v_371_1 = ((stage_v_47_1 + pub_r000592_12_1) + 11) & 127;
  int stage_v_371_2 = ((stage_v_47_2 + pub_r000592_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_371_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_371_2) & 255;
  int stage_v_372_1 = ((sec_r000592_5_1 + pub_r000592_7_1) + 43) & 127;
  int stage_v_372_2 = ((sec_r000592_5_2 + pub_r000592_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_372_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_372_2) & 255;
  int stage_v_373_1 = ((stage_v_32_1 + pub_r000592_17_1) + 43) & 127;
  int stage_v_373_2 = ((stage_v_32_2 + pub_r000592_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_373_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_373_2) & 255;
  int stage_v_374_1 = ((sec_r000592_0_1 + pub_r000592_10_1) + 29) & 127;
  int stage_v_374_2 = ((sec_r000592_0_2 + pub_r000592_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_374_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_374_2) & 255;
  int stage_v_375_1 = ((stage_v_319_1 + pub_r000592_4_1) + 9) & 127;
  int stage_v_375_2 = ((stage_v_319_2 + pub_r000592_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_375_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_375_2) & 255;
  int stage_v_376_1 = ((stage_v_357_1 + pub_r000592_6_1) + 34) & 127;
  int stage_v_376_2 = ((stage_v_357_2 + pub_r000592_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_376_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_376_2) & 255;
  int stage_v_377_1 = ((stage_v_276_1 + pub_r000592_3_1) + 19) & 127;
  int stage_v_377_2 = ((stage_v_276_2 + pub_r000592_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_377_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_377_2) & 255;
  int stage_v_378_1 = ((sec_r000592_17_1 + pub_r000592_18_1) + 28) & 127;
  int stage_v_378_2 = ((sec_r000592_17_2 + pub_r000592_18_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_378_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_378_2) & 255;
  int stage_v_379_1 = ((stage_v_235_1 + pub_r000592_13_1) + 10) & 127;
  int stage_v_379_2 = ((stage_v_235_2 + pub_r000592_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_379_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_379_2) & 255;
  int stage_v_380_1 = ((stage_v_363_1 + pub_r000592_8_1) + 3) & 127;
  int stage_v_380_2 = ((stage_v_363_2 + pub_r000592_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_380_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_380_2) & 255;
  int stage_v_381_1 = ((stage_v_185_1 + pub_r000592_14_1) + 37) & 127;
  int stage_v_381_2 = ((stage_v_185_2 + pub_r000592_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_381_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_381_2) & 255;
  int stage_v_382_1 = ((stage_v_54_1 + pub_r000592_11_1) + 11) & 127;
  int stage_v_382_2 = ((stage_v_54_2 + pub_r000592_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_382_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_382_2) & 255;
  int stage_v_383_1 = ((stage_v_31_1 + pub_r000592_15_1) + 28) & 127;
  int stage_v_383_2 = ((stage_v_31_2 + pub_r000592_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_383_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_383_2) & 255;
  int stage_v_384_1 = ((stage_v_257_1 + pub_r000592_6_1) + 38) & 127;
  int stage_v_384_2 = ((stage_v_257_2 + pub_r000592_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_384_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_384_2) & 255;
  int stage_v_385_1 = ((sec_r000592_6_1 + pub_r000592_5_1) + 11) & 127;
  int stage_v_385_2 = ((sec_r000592_6_2 + pub_r000592_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_385_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_385_2) & 255;
  int stage_v_386_1 = ((stage_v_226_1 + pub_r000592_18_1) + 38) & 127;
  int stage_v_386_2 = ((stage_v_226_2 + pub_r000592_18_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_386_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_386_2) & 255;
  int stage_v_387_1 = ((stage_v_336_1 + pub_r000592_8_1) + 40) & 127;
  int stage_v_387_2 = ((stage_v_336_2 + pub_r000592_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_387_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_387_2) & 255;
  int stage_v_388_1 = ((stage_v_316_1 + pub_r000592_16_1) + 39) & 127;
  int stage_v_388_2 = ((stage_v_316_2 + pub_r000592_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_388_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_388_2) & 255;
  int stage_v_389_1 = ((stage_v_316_1 + pub_r000592_12_1) + 47) & 127;
  int stage_v_389_2 = ((stage_v_316_2 + pub_r000592_12_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_389_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_389_2) & 255;
  int stage_v_390_1 = ((stage_v_79_1 + pub_r000592_10_1) + 28) & 127;
  int stage_v_390_2 = ((stage_v_79_2 + pub_r000592_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_390_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_390_2) & 255;
  int stage_v_391_1 = ((sec_r000592_7_1 + pub_r000592_10_1) + 10) & 127;
  int stage_v_391_2 = ((sec_r000592_7_2 + pub_r000592_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_391_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_391_2) & 255;
  int stage_v_392_1 = ((stage_v_254_1 + pub_r000592_7_1) + 13) & 127;
  int stage_v_392_2 = ((stage_v_254_2 + pub_r000592_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_392_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_392_2) & 255;
  int stage_v_393_1 = ((sec_r000592_17_1 + pub_r000592_4_1) + 45) & 127;
  int stage_v_393_2 = ((sec_r000592_17_2 + pub_r000592_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_393_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_393_2) & 255;
  int stage_v_394_1 = ((sec_r000592_1_1 + pub_r000592_7_1) + 33) & 127;
  int stage_v_394_2 = ((sec_r000592_1_2 + pub_r000592_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_394_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_394_2) & 255;
  int stage_v_395_1 = ((stage_v_63_1 + pub_r000592_9_1) + 8) & 127;
  int stage_v_395_2 = ((stage_v_63_2 + pub_r000592_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_395_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_395_2) & 255;
  int stage_v_396_1 = ((stage_v_291_1 + pub_r000592_15_1) + 4) & 127;
  int stage_v_396_2 = ((stage_v_291_2 + pub_r000592_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_396_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_396_2) & 255;
  int stage_v_397_1 = ((sec_r000592_16_1 + pub_r000592_16_1) + 47) & 127;
  int stage_v_397_2 = ((sec_r000592_16_2 + pub_r000592_16_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_397_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_397_2) & 255;
  int stage_v_398_1 = ((stage_v_342_1 + pub_r000592_4_1) + 41) & 127;
  int stage_v_398_2 = ((stage_v_342_2 + pub_r000592_4_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_398_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_398_2) & 255;
  int stage_v_399_1 = ((stage_v_186_1 + pub_r000592_8_1) + 35) & 127;
  int stage_v_399_2 = ((stage_v_186_2 + pub_r000592_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_399_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_399_2) & 255;
  int stage_v_400_1 = ((sec_r000592_6_1 + pub_r000592_6_1) + 34) & 127;
  int stage_v_400_2 = ((sec_r000592_6_2 + pub_r000592_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_400_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_400_2) & 255;
  int stage_v_401_1 = ((sec_r000592_3_1 + pub_r000592_2_1) + 49) & 127;
  int stage_v_401_2 = ((sec_r000592_3_2 + pub_r000592_2_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_401_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_401_2) & 255;
  int stage_v_402_1 = ((stage_v_211_1 + pub_r000592_7_1) + 4) & 127;
  int stage_v_402_2 = ((stage_v_211_2 + pub_r000592_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_402_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_402_2) & 255;
  int stage_v_403_1 = ((sec_r000592_8_1 + pub_r000592_7_1) + 36) & 127;
  int stage_v_403_2 = ((sec_r000592_8_2 + pub_r000592_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_403_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_403_2) & 255;
  int stage_v_404_1 = ((stage_v_382_1 + pub_r000592_15_1) + 14) & 127;
  int stage_v_404_2 = ((stage_v_382_2 + pub_r000592_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_404_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_404_2) & 255;
  int stage_v_405_1 = ((stage_v_298_1 + pub_r000592_4_1) + 31) & 127;
  int stage_v_405_2 = ((stage_v_298_2 + pub_r000592_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_405_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_405_2) & 255;
  int stage_v_406_1 = ((stage_v_141_1 + pub_r000592_12_1) + 39) & 127;
  int stage_v_406_2 = ((stage_v_141_2 + pub_r000592_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_406_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_406_2) & 255;
  int stage_v_407_1 = ((stage_v_220_1 + pub_r000592_17_1) + 38) & 127;
  int stage_v_407_2 = ((stage_v_220_2 + pub_r000592_17_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_407_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_407_2) & 255;
  int stage_v_408_1 = ((stage_v_369_1 + pub_r000592_7_1) + 15) & 127;
  int stage_v_408_2 = ((stage_v_369_2 + pub_r000592_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_408_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_408_2) & 255;
  int stage_v_409_1 = ((stage_v_54_1 + pub_r000592_17_1) + 27) & 127;
  int stage_v_409_2 = ((stage_v_54_2 + pub_r000592_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_409_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_409_2) & 255;
  int stage_v_410_1 = ((sec_r000592_6_1 + pub_r000592_18_1) + 3) & 127;
  int stage_v_410_2 = ((sec_r000592_6_2 + pub_r000592_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_410_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_410_2) & 255;
  int stage_v_411_1 = ((stage_v_200_1 + pub_r000592_12_1) + 39) & 127;
  int stage_v_411_2 = ((stage_v_200_2 + pub_r000592_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_411_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_411_2) & 255;
  int stage_v_412_1 = ((stage_v_333_1 + pub_r000592_1_1) + 36) & 127;
  int stage_v_412_2 = ((stage_v_333_2 + pub_r000592_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_412_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_412_2) & 255;
  int stage_v_413_1 = ((stage_v_143_1 + pub_r000592_9_1) + 47) & 127;
  int stage_v_413_2 = ((stage_v_143_2 + pub_r000592_9_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_413_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_413_2) & 255;
  int stage_v_414_1 = ((stage_v_274_1 + pub_r000592_14_1) + 8) & 127;
  int stage_v_414_2 = ((stage_v_274_2 + pub_r000592_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_414_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_414_2) & 255;
  int stage_v_415_1 = ((stage_v_330_1 + pub_r000592_3_1) + 33) & 127;
  int stage_v_415_2 = ((stage_v_330_2 + pub_r000592_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_415_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_415_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000592_6_1 != sec_r000592_6_2);
  __CPROVER_assume(sec_r000592_7_1 != sec_r000592_7_2);
  __CPROVER_assume(sec_r000592_5_1 != sec_r000592_5_2);
  __CPROVER_assume(pub_r000592_16_1 == pub_r000592_16_2);
  __CPROVER_assume(sec_r000592_0_1 != sec_r000592_0_2);
  __CPROVER_assume(sec_r000592_1_1 != sec_r000592_1_2);
  __CPROVER_assume(pub_r000592_1_1 == pub_r000592_1_2);
  __CPROVER_assume(pub_r000592_7_1 == pub_r000592_7_2);
  __CPROVER_assume(pub_r000592_10_1 == pub_r000592_10_2);
  __CPROVER_assume(pub_r000592_11_1 == pub_r000592_11_2);
  __CPROVER_assume(sec_r000592_16_1 != sec_r000592_16_2);
  __CPROVER_assume(pub_r000592_12_1 == pub_r000592_12_2);
  __CPROVER_assume(sec_r000592_8_1 != sec_r000592_8_2);
  __CPROVER_assume(sec_r000592_10_1 != sec_r000592_10_2);
  __CPROVER_assume(pub_r000592_6_1 == pub_r000592_6_2);
  __CPROVER_assume(sec_r000592_14_1 != sec_r000592_14_2);
  __CPROVER_assume(sec_r000592_9_1 != sec_r000592_9_2);
  __CPROVER_assume(pub_r000592_2_1 == pub_r000592_2_2);
  __CPROVER_assume(pub_r000592_9_1 == pub_r000592_9_2);
  __CPROVER_assume(pub_r000592_17_1 == pub_r000592_17_2);
  __CPROVER_assume(pub_r000592_0_1 == pub_r000592_0_2);
  __CPROVER_assume(pub_r000592_18_1 == pub_r000592_18_2);
  __CPROVER_assume(pub_r000592_8_1 == pub_r000592_8_2);
  __CPROVER_assume(pub_r000592_14_1 == pub_r000592_14_2);
  __CPROVER_assume(sec_r000592_2_1 != sec_r000592_2_2);
  __CPROVER_assume(sec_r000592_4_1 != sec_r000592_4_2);
  __CPROVER_assume(sec_r000592_12_1 != sec_r000592_12_2);
  __CPROVER_assume(sec_r000592_17_1 != sec_r000592_17_2);
  __CPROVER_assume(sec_r000592_11_1 != sec_r000592_11_2);
  __CPROVER_assume(sec_r000592_15_1 != sec_r000592_15_2);
  __CPROVER_assume(pub_r000592_3_1 == pub_r000592_3_2);
  __CPROVER_assume(pub_r000592_5_1 == pub_r000592_5_2);
  __CPROVER_assume(pub_r000592_15_1 == pub_r000592_15_2);
  __CPROVER_assume(pub_r000592_4_1 == pub_r000592_4_2);
  __CPROVER_assume(sec_r000592_3_1 != sec_r000592_3_2);
  __CPROVER_assume(pub_r000592_13_1 == pub_r000592_13_2);
  __CPROVER_assume(sec_r000592_13_1 != sec_r000592_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.stride == st_var_1_2.stride);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.dim == st_var_1_2.dim);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.port == st_var_2_2.port);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.id == st_var_2_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.reading == st_var_3_2.reading);
  assert(st_var_3_1.offset == st_var_3_2.offset);
  assert(st_var_3_1.calib == st_var_3_2.calib);
  assert(st_var_3_1.status == st_var_3_2.status);
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
  assert(stage_v_374_1 == stage_v_374_2);
  assert(stage_v_375_1 == stage_v_375_2);
  assert(stage_v_376_1 == stage_v_376_2);
  assert(stage_v_377_1 == stage_v_377_2);
  assert(stage_v_378_1 == stage_v_378_2);
  assert(stage_v_379_1 == stage_v_379_2);
  assert(stage_v_380_1 == stage_v_380_2);
  assert(stage_v_381_1 == stage_v_381_2);
  assert(stage_v_382_1 == stage_v_382_2);
  assert(stage_v_383_1 == stage_v_383_2);
  assert(stage_v_384_1 == stage_v_384_2);
  assert(stage_v_385_1 == stage_v_385_2);
  assert(stage_v_386_1 == stage_v_386_2);
  assert(stage_v_387_1 == stage_v_387_2);
  assert(stage_v_388_1 == stage_v_388_2);
  assert(stage_v_389_1 == stage_v_389_2);
  assert(stage_v_390_1 == stage_v_390_2);
  assert(stage_v_391_1 == stage_v_391_2);
  assert(stage_v_392_1 == stage_v_392_2);
  assert(stage_v_393_1 == stage_v_393_2);
  assert(stage_v_394_1 == stage_v_394_2);
  assert(stage_v_395_1 == stage_v_395_2);
  assert(stage_v_396_1 == stage_v_396_2);
  assert(stage_v_397_1 == stage_v_397_2);
  assert(stage_v_398_1 == stage_v_398_2);
  assert(stage_v_399_1 == stage_v_399_2);
  assert(stage_v_400_1 == stage_v_400_2);
  assert(stage_v_401_1 == stage_v_401_2);
  assert(stage_v_402_1 == stage_v_402_2);
  assert(stage_v_403_1 == stage_v_403_2);
  assert(stage_v_404_1 == stage_v_404_2);
  assert(stage_v_405_1 == stage_v_405_2);
  assert(stage_v_406_1 == stage_v_406_2);
  assert(stage_v_407_1 == stage_v_407_2);
  assert(stage_v_408_1 == stage_v_408_2);
  assert(stage_v_409_1 == stage_v_409_2);
  assert(stage_v_410_1 == stage_v_410_2);
  assert(stage_v_411_1 == stage_v_411_2);
  assert(stage_v_412_1 == stage_v_412_2);
  assert(stage_v_413_1 == stage_v_413_2);
  assert(stage_v_414_1 == stage_v_414_2);
  assert(stage_v_415_1 == stage_v_415_2);
}


