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
struct MatrixBlock_R000590_9013_0
{
  short scale;
  short trace;
  int stride;
  int density;
  int buffer[3];
};
struct EventLog_R000590_9013_1
{
  int signature;
  int timestamp;
  short facility;
  short severity;
  int seq;
  int code;
  int buffer[3];
};
struct Transaction_R000590_9013_2
{
  int rate;
  short fee;
  int status;
  int auth_code;
  int buffer[3];
};
union RegisterBank_R000590_9013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000590_9013_1
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
void fn_R000590_9013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000590_9013_0 st_1 = {0};
  struct MatrixBlock_R000590_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_22_1 = local_arr_1[aux_1 % 3];
  int sample_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_22_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_22_1 == sample_22_2);
}

int fn_R000590_9013_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000590_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_22 = local_arr[aux % 3];
  acc = (acc + (sample_22 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000590_9013_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st_1 = {0};
  struct EventLog_R000590_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_78_1 = local_arr_1[aux_1 % 3];
  int anchor_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_78_2 * 2)) & 127;
  int cursor_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_64_1 > 34)
  {
    acc_1 = ((acc_1 + (cursor_64_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_64_2 > 34)
  {
    acc_2 = ((acc_2 + (cursor_64_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_61_1) & 63;
  aux_2 = (aux_2 + accumulator_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_78_1 == anchor_78_2);
  assert(cursor_64_1 == cursor_64_2);
  assert(accumulator_61_1 == accumulator_61_2);
}

int fn_R000590_9013_1(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int anchor_78 = local_arr[aux % 3];
  acc = (acc + (anchor_78 * 2)) & 127;
  int cursor_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_64 > 34)
  {
    acc = ((acc + (cursor_64 * 2)) + 5) & 127;
    aux ^= cursor_64 & 15;
  }
  else
  {
    acc = ((acc - cursor_64) + 11) & 127;
    aux += 3;
  }
  int accumulator_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_61) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000590_9013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000590_9013_2 st_1 = {0};
  struct Transaction_R000590_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int margin_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_75_1 > 22)
  {
    acc_1 = ((acc_1 + (margin_75_1 * 2)) + 5) & 127;
    aux_1 ^= margin_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_75_2 > 22)
  {
    acc_2 = ((acc_2 + (margin_75_2 * 2)) + 5) & 127;
    aux_2 ^= margin_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_55_1) & 63;
  aux_2 = (aux_2 + vector_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_79_1 = local_arr_1[aux_1 % 3];
  int weight_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_79_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_75_1 == margin_75_2);
  assert(vector_55_1 == vector_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_79_1 == weight_79_2);
}

int fn_R000590_9013_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000590_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int margin_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_75 > 22)
  {
    acc = ((acc + (margin_75 * 2)) + 5) & 127;
    aux ^= margin_75 & 15;
  }
  else
  {
    acc = ((acc - margin_75) + 11) & 127;
    aux += 3;
  }
  int vector_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_55) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_79 = local_arr[aux % 3];
  acc = (acc + (weight_79 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000590_9013_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st_1 = {0};
  struct EventLog_R000590_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int segment_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_71_1)
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

  switch (segment_71_2)
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

  int tally_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_12_1) & 63;
  aux_2 = (aux_2 + tally_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_93_1 = local_arr_1[aux_1 % 3];
  int delta_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_93_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_71_1 == segment_71_2);
  assert(tally_12_1 == tally_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_93_1 == delta_93_2);
}

int fn_R000590_9013_3(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int segment_71 = (aux + st.buffer[1]) & 3;
  switch (segment_71)
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

  int tally_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_12) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_93 = local_arr[aux % 3];
  acc = (acc + (delta_93 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000590_9013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000590_9013_2 st_1 = {0};
  struct Transaction_R000590_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int sample_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_61_1 > 27)
  {
    acc_1 = ((acc_1 + (sample_61_1 * 2)) + 5) & 127;
    aux_1 ^= sample_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_61_2 > 27)
  {
    acc_2 = ((acc_2 + (sample_61_2 * 2)) + 5) & 127;
    aux_2 ^= sample_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_40_1)
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

  switch (threshold_40_2)
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
  int quantum_28_1 = local_arr_1[aux_1 % 3];
  int quantum_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_61_1 == sample_61_2);
  assert(threshold_40_1 == threshold_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_28_1 == quantum_28_2);
}

int fn_R000590_9013_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000590_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int sample_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_61 > 27)
  {
    acc = ((acc + (sample_61 * 2)) + 5) & 127;
    aux ^= sample_61 & 15;
  }
  else
  {
    acc = ((acc - sample_61) + 11) & 127;
    aux += 3;
  }
  int threshold_40 = (aux + st.buffer[1]) & 3;
  switch (threshold_40)
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
  int quantum_28 = local_arr[aux % 3];
  acc = (acc + (quantum_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000590_9013_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000590_9013_2 st_1 = {0};
  struct Transaction_R000590_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int damping_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_73_1 > 44)
  {
    acc_1 = ((acc_1 + (damping_73_1 * 2)) + 5) & 127;
    aux_1 ^= damping_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_73_2 > 44)
  {
    acc_2 = ((acc_2 + (damping_73_2 * 2)) + 5) & 127;
    aux_2 ^= damping_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_15_1) & 63;
  aux_2 = (aux_2 + weight_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_68_1 = local_arr_1[aux_1 % 3];
  int accumulator_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_73_1 == damping_73_2);
  assert(weight_15_1 == weight_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_68_1 == accumulator_68_2);
}

int fn_R000590_9013_5(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000590_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int damping_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_73 > 44)
  {
    acc = ((acc + (damping_73 * 2)) + 5) & 127;
    aux ^= damping_73 & 15;
  }
  else
  {
    acc = ((acc - damping_73) + 11) & 127;
    aux += 3;
  }
  int weight_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_15) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_68 = local_arr[aux % 3];
  acc = (acc + (accumulator_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000590_9013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000590_9013_2 st_1 = {0};
  struct Transaction_R000590_9013_2 st_2 = {0};
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
  int window_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_64_1 > 29)
  {
    acc_1 = ((acc_1 + (window_64_1 * 2)) + 5) & 127;
    aux_1 ^= window_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_64_2 > 29)
  {
    acc_2 = ((acc_2 + (window_64_2 * 2)) + 5) & 127;
    aux_2 ^= window_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_64_1 == window_64_2);
}

int fn_R000590_9013_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000590_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_64 > 29)
  {
    acc = ((acc + (window_64 * 2)) + 5) & 127;
    aux ^= window_64 & 15;
  }
  else
  {
    acc = ((acc - window_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000590_9013_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st_1 = {0};
  struct EventLog_R000590_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quantum_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_65_1)
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

  switch (quantum_65_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_65_1 == quantum_65_2);
}

int fn_R000590_9013_7(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quantum_65 = (aux + st.buffer[1]) & 3;
  switch (quantum_65)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000590_9013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st_1 = {0};
  struct EventLog_R000590_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_71_1 = local_arr_1[aux_1 % 3];
  int cursor_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_71_2 * 2)) & 127;
  int damping_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_66_1)
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

  switch (damping_66_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_71_1 == cursor_71_2);
  assert(damping_66_1 == damping_66_2);
}

int fn_R000590_9013_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int cursor_71 = local_arr[aux % 3];
  acc = (acc + (cursor_71 * 2)) & 127;
  int damping_66 = (aux + st.buffer[1]) & 3;
  switch (damping_66)
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

void fn_R000590_9013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000590_9013_0 st_1 = {0};
  struct MatrixBlock_R000590_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int sample_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_58_1) & 63;
  aux_2 = (aux_2 + sample_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_74_1 > 15)
  {
    acc_1 = ((acc_1 + (pivot_74_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_74_2 > 15)
  {
    acc_2 = ((acc_2 + (pivot_74_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_55_1)
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

  switch (tracker_55_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_58_1 == sample_58_2);
  assert(pivot_74_1 == pivot_74_2);
  assert(tracker_55_1 == tracker_55_2);
}

int fn_R000590_9013_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000590_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int sample_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_58) & 63;
  acc ^= aux;
  int pivot_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_74 > 15)
  {
    acc = ((acc + (pivot_74 * 2)) + 5) & 127;
    aux ^= pivot_74 & 15;
  }
  else
  {
    acc = ((acc - pivot_74) + 11) & 127;
    aux += 3;
  }
  int tracker_55 = (aux + st.buffer[1]) & 3;
  switch (tracker_55)
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
  return (acc + aux) & 255;
}

void fn_R000590_9013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000590_9013_2 st_1 = {0};
  struct Transaction_R000590_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int scale_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_10_1) & 63;
  aux_2 = (aux_2 + scale_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_82_1 > 50)
  {
    acc_1 = ((acc_1 + (metric_82_1 * 2)) + 5) & 127;
    aux_1 ^= metric_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_82_2 > 50)
  {
    acc_2 = ((acc_2 + (metric_82_2 * 2)) + 5) & 127;
    aux_2 ^= metric_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_10_1 == scale_10_2);
  assert(metric_82_1 == metric_82_2);
}

int fn_R000590_9013_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000590_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int scale_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_10) & 63;
  acc ^= aux;
  int metric_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_82 > 50)
  {
    acc = ((acc + (metric_82 * 2)) + 5) & 127;
    aux ^= metric_82 & 15;
  }
  else
  {
    acc = ((acc - metric_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000590_9013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st_1 = {0};
  struct EventLog_R000590_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_79_1 = local_arr_1[aux_1 % 3];
  int delta_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_79_2 * 2)) & 127;
  int phase_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_53_1)
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

  switch (phase_53_2)
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

  int weight_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_18_1 > 10)
  {
    acc_1 = ((acc_1 + (weight_18_1 * 2)) + 5) & 127;
    aux_1 ^= weight_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_18_2 > 10)
  {
    acc_2 = ((acc_2 + (weight_18_2 * 2)) + 5) & 127;
    aux_2 ^= weight_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_18_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_79_1 == delta_79_2);
  assert(phase_53_1 == phase_53_2);
  assert(weight_18_1 == weight_18_2);
}

int fn_R000590_9013_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_79 = local_arr[aux % 3];
  acc = (acc + (delta_79 * 2)) & 127;
  int phase_53 = (aux + st.buffer[1]) & 3;
  switch (phase_53)
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

  int weight_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_18 > 10)
  {
    acc = ((acc + (weight_18 * 2)) + 5) & 127;
    aux ^= weight_18 & 15;
  }
  else
  {
    acc = ((acc - weight_18) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000590_9013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st_1 = {0};
  struct EventLog_R000590_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int damping_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_19_1) & 63;
  aux_2 = (aux_2 + damping_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_90_1 > 26)
  {
    acc_1 = ((acc_1 + (tally_90_1 * 2)) + 5) & 127;
    aux_1 ^= tally_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_90_2 > 26)
  {
    acc_2 = ((acc_2 + (tally_90_2 * 2)) + 5) & 127;
    aux_2 ^= tally_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_34_1)
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

  switch (threshold_34_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_19_1 == damping_19_2);
  assert(tally_90_1 == tally_90_2);
  assert(threshold_34_1 == threshold_34_2);
}

int fn_R000590_9013_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int damping_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_19) & 63;
  acc ^= aux;
  int tally_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_90 > 26)
  {
    acc = ((acc + (tally_90 * 2)) + 5) & 127;
    aux ^= tally_90 & 15;
  }
  else
  {
    acc = ((acc - tally_90) + 11) & 127;
    aux += 3;
  }
  int threshold_34 = (aux + st.buffer[1]) & 3;
  switch (threshold_34)
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

void fn_R000590_9013_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st_1 = {0};
  struct EventLog_R000590_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_41_1 = local_arr_1[aux_1 % 3];
  int checksum_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_41_2 * 2)) & 127;
  int phase_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_82_1)
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

  switch (phase_82_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_41_1 == checksum_41_2);
  assert(phase_82_1 == phase_82_2);
}

int fn_R000590_9013_13(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int checksum_41 = local_arr[aux % 3];
  acc = (acc + (checksum_41 * 2)) & 127;
  int phase_82 = (aux + st.buffer[1]) & 3;
  switch (phase_82)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000590_9013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000590_9013_0 st_1 = {0};
  struct MatrixBlock_R000590_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_94_1 > 18)
  {
    acc_1 = ((acc_1 + (scale_94_1 * 2)) + 5) & 127;
    aux_1 ^= scale_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_94_2 > 18)
  {
    acc_2 = ((acc_2 + (scale_94_2 * 2)) + 5) & 127;
    aux_2 ^= scale_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_76_1)
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

  switch (checksum_76_2)
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
  int damping_72_1 = local_arr_1[aux_1 % 3];
  int damping_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_72_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_94_1 == scale_94_2);
  assert(checksum_76_1 == checksum_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_72_1 == damping_72_2);
}

int fn_R000590_9013_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000590_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_94 > 18)
  {
    acc = ((acc + (scale_94 * 2)) + 5) & 127;
    aux ^= scale_94 & 15;
  }
  else
  {
    acc = ((acc - scale_94) + 11) & 127;
    aux += 3;
  }
  int checksum_76 = (aux + st.buffer[1]) & 3;
  switch (checksum_76)
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
  int damping_72 = local_arr[aux % 3];
  acc = (acc + (damping_72 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000590_9013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000590_9013_0 st_1 = {0};
  struct MatrixBlock_R000590_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_93_1) & 63;
  aux_2 = (aux_2 + sample_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_18_1 > 11)
  {
    acc_1 = ((acc_1 + (pivot_18_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_18_2 > 11)
  {
    acc_2 = ((acc_2 + (pivot_18_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_61_1)
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

  switch (weight_61_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_93_1 == sample_93_2);
  assert(pivot_18_1 == pivot_18_2);
  assert(weight_61_1 == weight_61_2);
}

int fn_R000590_9013_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000590_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_93) & 63;
  acc ^= aux;
  int pivot_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_18 > 11)
  {
    acc = ((acc + (pivot_18 * 2)) + 5) & 127;
    aux ^= pivot_18 & 15;
  }
  else
  {
    acc = ((acc - pivot_18) + 11) & 127;
    aux += 3;
  }
  int weight_61 = (aux + st.buffer[1]) & 3;
  switch (weight_61)
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

void fn_R000590_9013_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000590_9013_0 st_1 = {0};
  struct MatrixBlock_R000590_9013_0 st_2 = {0};
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
  int pivot_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_76_1)
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

  switch (pivot_76_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_76_1 == pivot_76_2);
}

int fn_R000590_9013_16(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000590_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_76 = (aux + st.buffer[1]) & 3;
  switch (pivot_76)
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

void fn_R000590_9013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st_1 = {0};
  struct EventLog_R000590_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int scale_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_36_1) & 63;
  aux_2 = (aux_2 + scale_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_43_1)
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

  switch (quotient_43_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_36_1 == scale_36_2);
  assert(quotient_43_1 == quotient_43_2);
}

int fn_R000590_9013_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000590_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int scale_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_36) & 63;
  acc ^= aux;
  int quotient_43 = (aux + st.buffer[1]) & 3;
  switch (quotient_43)
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
  int sec_r000590_0_1;
  int sec_r000590_0_2;
  int sec_r000590_1_1;
  int sec_r000590_1_2;
  int sec_r000590_2_1;
  int sec_r000590_2_2;
  int sec_r000590_3_1;
  int sec_r000590_3_2;
  int sec_r000590_4_1;
  int sec_r000590_4_2;
  int sec_r000590_5_1;
  int sec_r000590_5_2;
  int sec_r000590_6_1;
  int sec_r000590_6_2;
  int sec_r000590_7_1;
  int sec_r000590_7_2;
  int sec_r000590_8_1;
  int sec_r000590_8_2;
  int sec_r000590_9_1;
  int sec_r000590_9_2;
  int sec_r000590_10_1;
  int sec_r000590_10_2;
  int sec_r000590_11_1;
  int sec_r000590_11_2;
  int sec_r000590_12_1;
  int sec_r000590_12_2;
  int sec_r000590_13_1;
  int sec_r000590_13_2;
  int sec_r000590_14_1;
  int sec_r000590_14_2;
  int sec_r000590_15_1;
  int sec_r000590_15_2;
  int sec_r000590_16_1;
  int sec_r000590_16_2;
  int sec_r000590_17_1;
  int sec_r000590_17_2;
  int pub_r000590_0_1;
  int pub_r000590_0_2;
  int pub_r000590_1_1;
  int pub_r000590_1_2;
  int pub_r000590_2_1;
  int pub_r000590_2_2;
  int pub_r000590_3_1;
  int pub_r000590_3_2;
  int pub_r000590_4_1;
  int pub_r000590_4_2;
  int pub_r000590_5_1;
  int pub_r000590_5_2;
  int pub_r000590_6_1;
  int pub_r000590_6_2;
  int pub_r000590_7_1;
  int pub_r000590_7_2;
  int pub_r000590_8_1;
  int pub_r000590_8_2;
  int pub_r000590_9_1;
  int pub_r000590_9_2;
  int pub_r000590_10_1;
  int pub_r000590_10_2;
  int pub_r000590_11_1;
  int pub_r000590_11_2;
  int pub_r000590_12_1;
  int pub_r000590_12_2;
  int pub_r000590_13_1;
  int pub_r000590_13_2;
  int pub_r000590_14_1;
  int pub_r000590_14_2;
  int pub_r000590_15_1;
  int pub_r000590_15_2;
  int pub_r000590_16_1;
  int pub_r000590_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000590_0_1 >= (-100)) && (pub_r000590_0_1 <= 100));
  __CPROVER_assume((pub_r000590_0_2 >= (-100)) && (pub_r000590_0_2 <= 100));
  __CPROVER_assume((pub_r000590_1_1 >= (-100)) && (pub_r000590_1_1 <= 100));
  __CPROVER_assume((pub_r000590_1_2 >= (-100)) && (pub_r000590_1_2 <= 100));
  __CPROVER_assume((pub_r000590_2_1 >= (-100)) && (pub_r000590_2_1 <= 100));
  __CPROVER_assume((pub_r000590_2_2 >= (-100)) && (pub_r000590_2_2 <= 100));
  __CPROVER_assume((pub_r000590_3_1 >= (-100)) && (pub_r000590_3_1 <= 100));
  __CPROVER_assume((pub_r000590_3_2 >= (-100)) && (pub_r000590_3_2 <= 100));
  __CPROVER_assume((pub_r000590_4_1 >= (-100)) && (pub_r000590_4_1 <= 100));
  __CPROVER_assume((pub_r000590_4_2 >= (-100)) && (pub_r000590_4_2 <= 100));
  __CPROVER_assume((pub_r000590_5_1 >= (-100)) && (pub_r000590_5_1 <= 100));
  __CPROVER_assume((pub_r000590_5_2 >= (-100)) && (pub_r000590_5_2 <= 100));
  __CPROVER_assume((pub_r000590_6_1 >= (-100)) && (pub_r000590_6_1 <= 100));
  __CPROVER_assume((pub_r000590_6_2 >= (-100)) && (pub_r000590_6_2 <= 100));
  __CPROVER_assume((pub_r000590_7_1 >= (-100)) && (pub_r000590_7_1 <= 100));
  __CPROVER_assume((pub_r000590_7_2 >= (-100)) && (pub_r000590_7_2 <= 100));
  __CPROVER_assume((pub_r000590_8_1 >= (-100)) && (pub_r000590_8_1 <= 100));
  __CPROVER_assume((pub_r000590_8_2 >= (-100)) && (pub_r000590_8_2 <= 100));
  __CPROVER_assume((pub_r000590_9_1 >= (-100)) && (pub_r000590_9_1 <= 100));
  __CPROVER_assume((pub_r000590_9_2 >= (-100)) && (pub_r000590_9_2 <= 100));
  __CPROVER_assume((pub_r000590_10_1 >= (-100)) && (pub_r000590_10_1 <= 100));
  __CPROVER_assume((pub_r000590_10_2 >= (-100)) && (pub_r000590_10_2 <= 100));
  __CPROVER_assume((pub_r000590_11_1 >= (-100)) && (pub_r000590_11_1 <= 100));
  __CPROVER_assume((pub_r000590_11_2 >= (-100)) && (pub_r000590_11_2 <= 100));
  __CPROVER_assume((pub_r000590_12_1 >= (-100)) && (pub_r000590_12_1 <= 100));
  __CPROVER_assume((pub_r000590_12_2 >= (-100)) && (pub_r000590_12_2 <= 100));
  __CPROVER_assume((pub_r000590_13_1 >= (-100)) && (pub_r000590_13_1 <= 100));
  __CPROVER_assume((pub_r000590_13_2 >= (-100)) && (pub_r000590_13_2 <= 100));
  __CPROVER_assume((pub_r000590_14_1 >= (-100)) && (pub_r000590_14_1 <= 100));
  __CPROVER_assume((pub_r000590_14_2 >= (-100)) && (pub_r000590_14_2 <= 100));
  __CPROVER_assume((pub_r000590_15_1 >= (-100)) && (pub_r000590_15_1 <= 100));
  __CPROVER_assume((pub_r000590_15_2 >= (-100)) && (pub_r000590_15_2 <= 100));
  __CPROVER_assume((pub_r000590_16_1 >= (-100)) && (pub_r000590_16_1 <= 100));
  __CPROVER_assume((pub_r000590_16_2 >= (-100)) && (pub_r000590_16_2 <= 100));
  __CPROVER_assume((sec_r000590_0_1 >= 0) && (sec_r000590_0_1 <= 255));
  __CPROVER_assume((sec_r000590_0_2 >= 0) && (sec_r000590_0_2 <= 255));
  __CPROVER_assume((sec_r000590_1_1 >= 0) && (sec_r000590_1_1 <= 255));
  __CPROVER_assume((sec_r000590_1_2 >= 0) && (sec_r000590_1_2 <= 255));
  __CPROVER_assume((sec_r000590_2_1 >= 0) && (sec_r000590_2_1 <= 255));
  __CPROVER_assume((sec_r000590_2_2 >= 0) && (sec_r000590_2_2 <= 255));
  __CPROVER_assume((sec_r000590_3_1 >= 0) && (sec_r000590_3_1 <= 255));
  __CPROVER_assume((sec_r000590_3_2 >= 0) && (sec_r000590_3_2 <= 255));
  __CPROVER_assume((sec_r000590_4_1 >= 0) && (sec_r000590_4_1 <= 255));
  __CPROVER_assume((sec_r000590_4_2 >= 0) && (sec_r000590_4_2 <= 255));
  __CPROVER_assume((sec_r000590_5_1 >= 0) && (sec_r000590_5_1 <= 255));
  __CPROVER_assume((sec_r000590_5_2 >= 0) && (sec_r000590_5_2 <= 255));
  __CPROVER_assume((sec_r000590_6_1 >= 0) && (sec_r000590_6_1 <= 255));
  __CPROVER_assume((sec_r000590_6_2 >= 0) && (sec_r000590_6_2 <= 255));
  __CPROVER_assume((sec_r000590_7_1 >= 0) && (sec_r000590_7_1 <= 255));
  __CPROVER_assume((sec_r000590_7_2 >= 0) && (sec_r000590_7_2 <= 255));
  __CPROVER_assume((sec_r000590_8_1 >= 0) && (sec_r000590_8_1 <= 255));
  __CPROVER_assume((sec_r000590_8_2 >= 0) && (sec_r000590_8_2 <= 255));
  __CPROVER_assume((sec_r000590_9_1 >= 0) && (sec_r000590_9_1 <= 255));
  __CPROVER_assume((sec_r000590_9_2 >= 0) && (sec_r000590_9_2 <= 255));
  __CPROVER_assume((sec_r000590_10_1 >= 0) && (sec_r000590_10_1 <= 255));
  __CPROVER_assume((sec_r000590_10_2 >= 0) && (sec_r000590_10_2 <= 255));
  __CPROVER_assume((sec_r000590_11_1 >= 0) && (sec_r000590_11_1 <= 255));
  __CPROVER_assume((sec_r000590_11_2 >= 0) && (sec_r000590_11_2 <= 255));
  __CPROVER_assume((sec_r000590_12_1 >= 0) && (sec_r000590_12_1 <= 255));
  __CPROVER_assume((sec_r000590_12_2 >= 0) && (sec_r000590_12_2 <= 255));
  __CPROVER_assume((sec_r000590_13_1 >= 0) && (sec_r000590_13_1 <= 255));
  __CPROVER_assume((sec_r000590_13_2 >= 0) && (sec_r000590_13_2 <= 255));
  __CPROVER_assume((sec_r000590_14_1 >= 0) && (sec_r000590_14_1 <= 255));
  __CPROVER_assume((sec_r000590_14_2 >= 0) && (sec_r000590_14_2 <= 255));
  __CPROVER_assume((sec_r000590_15_1 >= 0) && (sec_r000590_15_1 <= 255));
  __CPROVER_assume((sec_r000590_15_2 >= 0) && (sec_r000590_15_2 <= 255));
  __CPROVER_assume((sec_r000590_16_1 >= 0) && (sec_r000590_16_1 <= 255));
  __CPROVER_assume((sec_r000590_16_2 >= 0) && (sec_r000590_16_2 <= 255));
  __CPROVER_assume((sec_r000590_17_1 >= 0) && (sec_r000590_17_1 <= 255));
  __CPROVER_assume((sec_r000590_17_2 >= 0) && (sec_r000590_17_2 <= 255));
  struct MatrixBlock_R000590_9013_0 st_var_0_1 = {0};
  struct MatrixBlock_R000590_9013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000590_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000590_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000590_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000590_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000590_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000590_0_2 + 7) & 15;
  struct EventLog_R000590_9013_1 st_var_1_1 = {0};
  struct EventLog_R000590_9013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000590_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000590_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000590_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000590_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000590_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000590_0_2 + 9) & 15;
  struct Transaction_R000590_9013_2 st_var_2_1 = {0};
  struct Transaction_R000590_9013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000590_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000590_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000590_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000590_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000590_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000590_0_2 + 11) & 15;
  union RegisterBank_R000590_9013_0 u_var_1;
  union RegisterBank_R000590_9013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = (st_var_0_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_0_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 5) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = (st_var_2_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_2_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 30)
    {
      chk_sum_1 ^= stage_v_7_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_7_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 30)
    {
      chk_sum_2 ^= stage_v_7_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 10) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = (st_var_2_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_2_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 26)
    {
      chk_sum_1 ^= stage_v_13_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_13_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 26)
    {
      chk_sum_2 ^= stage_v_13_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 27)
    {
      chk_sum_1 ^= stage_v_14_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_14_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 27)
    {
      chk_sum_2 ^= stage_v_14_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
  int stage_v_18_1 = ((st_var_0_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_0_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 47)
    {
      chk_sum_1 ^= stage_v_18_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_18_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 47)
    {
      chk_sum_2 ^= stage_v_18_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = ((st_var_2_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_2_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 27)
    {
      chk_sum_1 ^= stage_v_20_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_20_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 27)
    {
      chk_sum_2 ^= stage_v_20_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 24) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 29) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 30) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 30) & 15;
  int stage_v_29_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_29_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= stage_v_29_1;
  chk_sum_2 ^= stage_v_29_2;
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_34_1 = ((st_var_1_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_1_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 45)
    {
      chk_sum_1 ^= stage_v_34_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_34_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 45)
    {
      chk_sum_2 ^= stage_v_34_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_35_1 = ((st_var_2_1.buffer[2] * 2) + 112) & 63;
  int stage_v_35_2 = ((st_var_2_2.buffer[2] * 2) + 112) & 63;
  if (stage_v_35_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_35_1) - 5) & 255;
    if (stage_v_35_1 > 54)
    {
      chk_sum_1 ^= stage_v_35_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_35_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_35_2) - 5) & 255;
    if (stage_v_35_2 > 54)
    {
      chk_sum_2 ^= stage_v_35_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 25)
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
  if (stage_v_36_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 25)
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
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 34)
    {
      chk_sum_1 ^= stage_v_38_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_38_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 34)
    {
      chk_sum_2 ^= stage_v_38_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_39_1 = (st_var_0_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_0_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  int stage_v_40_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_40_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
  int stage_v_42_1 = (st_var_0_1.buffer[0] ^ 45) & 3;
  int stage_v_42_2 = (st_var_0_2.buffer[0] ^ 45) & 3;
  switch (stage_v_42_1)
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

  switch (stage_v_42_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = (st_var_2_1.buffer[0] ^ 47) & 3;
  int stage_v_44_2 = (st_var_2_2.buffer[0] ^ 47) & 3;
  switch (stage_v_44_1)
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

  switch (stage_v_44_2)
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

  int stage_v_45_1 = ((st_var_0_1.buffer[0] * 2) + 142) & 63;
  int stage_v_45_2 = ((st_var_0_2.buffer[0] * 2) + 142) & 63;
  if (stage_v_45_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_45_1) - 5) & 255;
    if (stage_v_45_1 > 26)
    {
      chk_sum_1 ^= stage_v_45_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_45_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_45_2) - 5) & 255;
    if (stage_v_45_2 > 26)
    {
      chk_sum_2 ^= stage_v_45_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_50_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_50_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_51_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_51_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 53) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = (st_var_0_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_0_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 56) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  int stage_v_56_1 = (st_var_2_1.buffer[0] ^ 59) & 3;
  int stage_v_56_2 = (st_var_2_2.buffer[0] ^ 59) & 3;
  switch (stage_v_56_1)
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

  switch (stage_v_56_2)
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

  int stage_v_57_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_57_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_58_1 = ((st_var_1_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_1_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 55)
    {
      chk_sum_1 ^= stage_v_58_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_58_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 55)
    {
      chk_sum_2 ^= stage_v_58_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 60) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 60) & 15;
  int stage_v_59_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_59_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= stage_v_59_1;
  chk_sum_2 ^= stage_v_59_2;
  int stage_v_60_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (65 & 31);
  int stage_v_60_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (65 & 31);
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= (stage_v_60_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_60_2 << 1) & 127;
  int stage_v_61_1 = (st_var_1_1.buffer[0] ^ 64) & 3;
  int stage_v_61_2 = (st_var_1_2.buffer[0] ^ 64) & 3;
  switch (stage_v_61_1)
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

  switch (stage_v_61_2)
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

  int stage_v_62_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_62_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 65) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 66) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
  int stage_v_66_1 = (st_var_0_1.buffer[0] ^ 69) & 3;
  int stage_v_66_2 = (st_var_0_2.buffer[0] ^ 69) & 3;
  switch (stage_v_66_1)
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

  switch (stage_v_66_2)
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

  int stage_v_67_1 = (st_var_1_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_1_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 69) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 69) & 15;
  int stage_v_68_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_68_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= stage_v_68_1;
  chk_sum_2 ^= stage_v_68_2;
  int stage_v_69_1 = table_1[1];
  int stage_v_69_2 = table_2[1];
  table_1[1] = (table_1[2] + 139) & 63;
  table_2[1] = (table_2[2] + 139) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((st_var_1_1.buffer[1] * 2) + 217) & 63;
  int stage_v_70_2 = ((st_var_1_2.buffer[1] * 2) + 217) & 63;
  if (stage_v_70_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_70_1) - 5) & 255;
    if (stage_v_70_1 > 30)
    {
      chk_sum_1 ^= stage_v_70_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_70_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_70_2) - 5) & 255;
    if (stage_v_70_2 > 30)
    {
      chk_sum_2 ^= stage_v_70_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 73) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 73) & 15;
  int stage_v_72_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_72_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= stage_v_72_1;
  chk_sum_2 ^= stage_v_72_2;
  int stage_v_73_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (78 & 31);
  int stage_v_73_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (78 & 31);
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= (stage_v_73_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_73_2 << 1) & 127;
  int stage_v_74_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_74_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = table_1[0];
  int stage_v_76_2 = table_2[0];
  table_1[0] = (table_1[1] + 153) & 63;
  table_2[0] = (table_2[1] + 153) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (82 & 31);
  int stage_v_77_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (82 & 31);
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= (stage_v_77_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_77_2 << 1) & 127;
  int stage_v_78_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_78_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_79_1 = table_1[3];
  int stage_v_79_2 = table_2[3];
  table_1[3] = (table_1[0] + 159) & 63;
  table_2[3] = (table_2[0] + 159) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_80_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_80_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_80_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 83) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 83) & 15;
  int stage_v_82_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_82_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= stage_v_82_1;
  chk_sum_2 ^= stage_v_82_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 84) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 84) & 15;
  int stage_v_83_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_83_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= stage_v_83_1;
  chk_sum_2 ^= stage_v_83_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 85) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 85) & 15;
  int stage_v_84_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_84_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  chk_sum_1 ^= stage_v_84_1;
  chk_sum_2 ^= stage_v_84_2;
  int stage_v_85_1 = (st_var_1_1.buffer[0] ^ 88) & 3;
  int stage_v_85_2 = (st_var_1_2.buffer[0] ^ 88) & 3;
  switch (stage_v_85_1)
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

  switch (stage_v_85_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 87) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 87) & 15;
  int stage_v_86_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_86_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= stage_v_86_1;
  chk_sum_2 ^= stage_v_86_2;
  int stage_v_87_1 = table_1[3];
  int stage_v_87_2 = table_2[3];
  table_1[3] = (table_1[0] + 175) & 63;
  table_2[3] = (table_2[0] + 175) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_88_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_88_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_88_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_89_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (94 & 31);
  int stage_v_89_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (94 & 31);
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= (stage_v_89_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_89_2 << 1) & 127;
  int stage_v_90_1 = (st_var_0_1.buffer[0] ^ 93) & 3;
  int stage_v_90_2 = (st_var_0_2.buffer[0] ^ 93) & 3;
  switch (stage_v_90_1)
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

  switch (stage_v_90_2)
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

  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_91_1 = ((stage_v_91_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_91_2 = ((stage_v_91_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((sec_r000590_1_1 ^ 0x2A) + pub_r000590_6_1) & 127;
  int stage_v_92_2 = ((sec_r000590_1_2 ^ 0x2A) + pub_r000590_6_2) & 127;
  if (stage_v_92_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((sec_r000590_6_1 ^ 0x2A) + pub_r000590_3_1) & 127;
  int stage_v_93_2 = ((sec_r000590_6_2 ^ 0x2A) + pub_r000590_3_2) & 127;
  if (stage_v_93_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((stage_v_93_1 ^ 0x2A) + pub_r000590_1_1) & 127;
  int stage_v_94_2 = ((stage_v_93_2 ^ 0x2A) + pub_r000590_1_2) & 127;
  if (stage_v_94_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((stage_v_93_1 ^ 0x2A) + pub_r000590_11_1) & 127;
  int stage_v_95_2 = ((stage_v_93_2 ^ 0x2A) + pub_r000590_11_2) & 127;
  if (stage_v_95_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((sec_r000590_14_1 ^ 0x2A) + pub_r000590_10_1) & 127;
  int stage_v_96_2 = ((sec_r000590_14_2 ^ 0x2A) + pub_r000590_10_2) & 127;
  if (stage_v_96_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((stage_v_92_1 ^ 0x2A) + pub_r000590_2_1) & 127;
  int stage_v_97_2 = ((stage_v_92_2 ^ 0x2A) + pub_r000590_2_2) & 127;
  if (stage_v_97_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((stage_v_94_1 ^ 0x2A) + pub_r000590_7_1) & 127;
  int stage_v_98_2 = ((stage_v_94_2 ^ 0x2A) + pub_r000590_7_2) & 127;
  if (stage_v_98_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((stage_v_97_1 ^ 0x2A) + pub_r000590_16_1) & 127;
  int stage_v_99_2 = ((stage_v_97_2 ^ 0x2A) + pub_r000590_16_2) & 127;
  if (stage_v_99_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((stage_v_98_1 ^ 0x2A) + pub_r000590_12_1) & 127;
  int stage_v_100_2 = ((stage_v_98_2 ^ 0x2A) + pub_r000590_12_2) & 127;
  if (stage_v_100_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((stage_v_97_1 ^ 0x2A) + pub_r000590_11_1) & 127;
  int stage_v_101_2 = ((stage_v_97_2 ^ 0x2A) + pub_r000590_11_2) & 127;
  if (stage_v_101_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((sec_r000590_11_1 ^ 0x2A) + pub_r000590_6_1) & 127;
  int stage_v_102_2 = ((sec_r000590_11_2 ^ 0x2A) + pub_r000590_6_2) & 127;
  if (stage_v_102_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((sec_r000590_17_1 ^ 0x2A) + pub_r000590_11_1) & 127;
  int stage_v_103_2 = ((sec_r000590_17_2 ^ 0x2A) + pub_r000590_11_2) & 127;
  if (stage_v_103_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((stage_v_98_1 ^ 0x2A) + pub_r000590_0_1) & 127;
  int stage_v_104_2 = ((stage_v_98_2 ^ 0x2A) + pub_r000590_0_2) & 127;
  if (stage_v_104_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((stage_v_96_1 ^ 0x2A) + pub_r000590_16_1) & 127;
  int stage_v_105_2 = ((stage_v_96_2 ^ 0x2A) + pub_r000590_16_2) & 127;
  if (stage_v_105_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((stage_v_100_1 ^ 0x2A) + pub_r000590_2_1) & 127;
  int stage_v_106_2 = ((stage_v_100_2 ^ 0x2A) + pub_r000590_2_2) & 127;
  if (stage_v_106_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((stage_v_98_1 ^ 0x2A) + pub_r000590_7_1) & 127;
  int stage_v_107_2 = ((stage_v_98_2 ^ 0x2A) + pub_r000590_7_2) & 127;
  if (stage_v_107_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((stage_v_97_1 ^ 0x2A) + pub_r000590_11_1) & 127;
  int stage_v_108_2 = ((stage_v_97_2 ^ 0x2A) + pub_r000590_11_2) & 127;
  if (stage_v_108_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((sec_r000590_9_1 ^ 0x2A) + pub_r000590_13_1) & 127;
  int stage_v_109_2 = ((sec_r000590_9_2 ^ 0x2A) + pub_r000590_13_2) & 127;
  if (stage_v_109_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((stage_v_107_1 ^ 0x2A) + pub_r000590_14_1) & 127;
  int stage_v_110_2 = ((stage_v_107_2 ^ 0x2A) + pub_r000590_14_2) & 127;
  if (stage_v_110_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((stage_v_109_1 ^ 0x2A) + pub_r000590_10_1) & 127;
  int stage_v_111_2 = ((stage_v_109_2 ^ 0x2A) + pub_r000590_10_2) & 127;
  if (stage_v_111_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((stage_v_107_1 ^ 0x2A) + pub_r000590_11_1) & 127;
  int stage_v_112_2 = ((stage_v_107_2 ^ 0x2A) + pub_r000590_11_2) & 127;
  if (stage_v_112_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((sec_r000590_4_1 ^ 0x2A) + pub_r000590_15_1) & 127;
  int stage_v_113_2 = ((sec_r000590_4_2 ^ 0x2A) + pub_r000590_15_2) & 127;
  if (stage_v_113_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((stage_v_106_1 ^ 0x2A) + pub_r000590_16_1) & 127;
  int stage_v_114_2 = ((stage_v_106_2 ^ 0x2A) + pub_r000590_16_2) & 127;
  if (stage_v_114_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((sec_r000590_17_1 ^ 0x2A) + pub_r000590_7_1) & 127;
  int stage_v_115_2 = ((sec_r000590_17_2 ^ 0x2A) + pub_r000590_7_2) & 127;
  if (stage_v_115_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((stage_v_107_1 ^ 0x2A) + pub_r000590_6_1) & 127;
  int stage_v_116_2 = ((stage_v_107_2 ^ 0x2A) + pub_r000590_6_2) & 127;
  if (stage_v_116_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((stage_v_110_1 ^ 0x2A) + pub_r000590_6_1) & 127;
  int stage_v_117_2 = ((stage_v_110_2 ^ 0x2A) + pub_r000590_6_2) & 127;
  if (stage_v_117_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((stage_v_95_1 ^ 0x2A) + pub_r000590_10_1) & 127;
  int stage_v_118_2 = ((stage_v_95_2 ^ 0x2A) + pub_r000590_10_2) & 127;
  if (stage_v_118_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((stage_v_110_1 ^ 0x2A) + pub_r000590_1_1) & 127;
  int stage_v_119_2 = ((stage_v_110_2 ^ 0x2A) + pub_r000590_1_2) & 127;
  if (stage_v_119_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((sec_r000590_12_1 ^ 0x2A) + pub_r000590_6_1) & 127;
  int stage_v_120_2 = ((sec_r000590_12_2 ^ 0x2A) + pub_r000590_6_2) & 127;
  if (stage_v_120_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((stage_v_100_1 ^ 0x2A) + pub_r000590_0_1) & 127;
  int stage_v_121_2 = ((stage_v_100_2 ^ 0x2A) + pub_r000590_0_2) & 127;
  if (stage_v_121_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((stage_v_101_1 ^ 0x2A) + pub_r000590_4_1) & 127;
  int stage_v_122_2 = ((stage_v_101_2 ^ 0x2A) + pub_r000590_4_2) & 127;
  if (stage_v_122_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((stage_v_98_1 ^ 0x2A) + pub_r000590_1_1) & 127;
  int stage_v_123_2 = ((stage_v_98_2 ^ 0x2A) + pub_r000590_1_2) & 127;
  if (stage_v_123_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((sec_r000590_9_1 ^ 0x2A) + pub_r000590_14_1) & 127;
  int stage_v_124_2 = ((sec_r000590_9_2 ^ 0x2A) + pub_r000590_14_2) & 127;
  if (stage_v_124_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((stage_v_122_1 ^ 0x2A) + pub_r000590_1_1) & 127;
  int stage_v_125_2 = ((stage_v_122_2 ^ 0x2A) + pub_r000590_1_2) & 127;
  if (stage_v_125_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((stage_v_114_1 ^ 0x2A) + pub_r000590_13_1) & 127;
  int stage_v_126_2 = ((stage_v_114_2 ^ 0x2A) + pub_r000590_13_2) & 127;
  if (stage_v_126_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((sec_r000590_13_1 ^ 0x2A) + pub_r000590_15_1) & 127;
  int stage_v_127_2 = ((sec_r000590_13_2 ^ 0x2A) + pub_r000590_15_2) & 127;
  if (stage_v_127_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((stage_v_109_1 ^ 0x2A) + pub_r000590_14_1) & 127;
  int stage_v_128_2 = ((stage_v_109_2 ^ 0x2A) + pub_r000590_14_2) & 127;
  if (stage_v_128_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((sec_r000590_15_1 ^ 0x2A) + pub_r000590_7_1) & 127;
  int stage_v_129_2 = ((sec_r000590_15_2 ^ 0x2A) + pub_r000590_7_2) & 127;
  if (stage_v_129_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((stage_v_127_1 ^ 0x2A) + pub_r000590_12_1) & 127;
  int stage_v_130_2 = ((stage_v_127_2 ^ 0x2A) + pub_r000590_12_2) & 127;
  if (stage_v_130_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((sec_r000590_6_1 ^ 0x2A) + pub_r000590_3_1) & 127;
  int stage_v_131_2 = ((sec_r000590_6_2 ^ 0x2A) + pub_r000590_3_2) & 127;
  if (stage_v_131_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((stage_v_131_1 ^ 0x2A) + pub_r000590_4_1) & 127;
  int stage_v_132_2 = ((stage_v_131_2 ^ 0x2A) + pub_r000590_4_2) & 127;
  if (stage_v_132_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((stage_v_128_1 ^ 0x2A) + pub_r000590_14_1) & 127;
  int stage_v_133_2 = ((stage_v_128_2 ^ 0x2A) + pub_r000590_14_2) & 127;
  if (stage_v_133_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((stage_v_122_1 ^ 0x2A) + pub_r000590_4_1) & 127;
  int stage_v_134_2 = ((stage_v_122_2 ^ 0x2A) + pub_r000590_4_2) & 127;
  if (stage_v_134_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((stage_v_100_1 ^ 0x2A) + pub_r000590_15_1) & 127;
  int stage_v_135_2 = ((stage_v_100_2 ^ 0x2A) + pub_r000590_15_2) & 127;
  if (stage_v_135_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((stage_v_133_1 ^ 0x2A) + pub_r000590_16_1) & 127;
  int stage_v_136_2 = ((stage_v_133_2 ^ 0x2A) + pub_r000590_16_2) & 127;
  if (stage_v_136_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((sec_r000590_0_1 ^ 0x2A) + pub_r000590_7_1) & 127;
  int stage_v_137_2 = ((sec_r000590_0_2 ^ 0x2A) + pub_r000590_7_2) & 127;
  if (stage_v_137_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((stage_v_107_1 ^ 0x2A) + pub_r000590_16_1) & 127;
  int stage_v_138_2 = ((stage_v_107_2 ^ 0x2A) + pub_r000590_16_2) & 127;
  if (stage_v_138_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((stage_v_109_1 ^ 0x2A) + pub_r000590_7_1) & 127;
  int stage_v_139_2 = ((stage_v_109_2 ^ 0x2A) + pub_r000590_7_2) & 127;
  if (stage_v_139_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((stage_v_110_1 ^ 0x2A) + pub_r000590_12_1) & 127;
  int stage_v_140_2 = ((stage_v_110_2 ^ 0x2A) + pub_r000590_12_2) & 127;
  if (stage_v_140_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((sec_r000590_4_1 ^ 0x2A) + pub_r000590_7_1) & 127;
  int stage_v_141_2 = ((sec_r000590_4_2 ^ 0x2A) + pub_r000590_7_2) & 127;
  if (stage_v_141_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((stage_v_140_1 ^ 0x2A) + pub_r000590_13_1) & 127;
  int stage_v_142_2 = ((stage_v_140_2 ^ 0x2A) + pub_r000590_13_2) & 127;
  if (stage_v_142_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((sec_r000590_13_1 ^ 0x2A) + pub_r000590_13_1) & 127;
  int stage_v_143_2 = ((sec_r000590_13_2 ^ 0x2A) + pub_r000590_13_2) & 127;
  if (stage_v_143_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((stage_v_97_1 ^ 0x2A) + pub_r000590_12_1) & 127;
  int stage_v_144_2 = ((stage_v_97_2 ^ 0x2A) + pub_r000590_12_2) & 127;
  if (stage_v_144_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((stage_v_103_1 ^ 0x2A) + pub_r000590_9_1) & 127;
  int stage_v_145_2 = ((stage_v_103_2 ^ 0x2A) + pub_r000590_9_2) & 127;
  if (stage_v_145_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((sec_r000590_14_1 ^ 0x2A) + pub_r000590_10_1) & 127;
  int stage_v_146_2 = ((sec_r000590_14_2 ^ 0x2A) + pub_r000590_10_2) & 127;
  if (stage_v_146_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((sec_r000590_15_1 ^ 0x2A) + pub_r000590_8_1) & 127;
  int stage_v_147_2 = ((sec_r000590_15_2 ^ 0x2A) + pub_r000590_8_2) & 127;
  if (stage_v_147_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((stage_v_118_1 ^ 0x2A) + pub_r000590_10_1) & 127;
  int stage_v_148_2 = ((stage_v_118_2 ^ 0x2A) + pub_r000590_10_2) & 127;
  if (stage_v_148_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((sec_r000590_5_1 ^ 0x2A) + pub_r000590_13_1) & 127;
  int stage_v_149_2 = ((sec_r000590_5_2 ^ 0x2A) + pub_r000590_13_2) & 127;
  if (stage_v_149_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((sec_r000590_15_1 ^ 0x2A) + pub_r000590_7_1) & 127;
  int stage_v_150_2 = ((sec_r000590_15_2 ^ 0x2A) + pub_r000590_7_2) & 127;
  if (stage_v_150_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((stage_v_131_1 ^ 0x2A) + pub_r000590_8_1) & 127;
  int stage_v_151_2 = ((stage_v_131_2 ^ 0x2A) + pub_r000590_8_2) & 127;
  if (stage_v_151_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((stage_v_135_1 ^ 0x2A) + pub_r000590_7_1) & 127;
  int stage_v_152_2 = ((stage_v_135_2 ^ 0x2A) + pub_r000590_7_2) & 127;
  if (stage_v_152_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((stage_v_147_1 ^ 0x2A) + pub_r000590_0_1) & 127;
  int stage_v_153_2 = ((stage_v_147_2 ^ 0x2A) + pub_r000590_0_2) & 127;
  if (stage_v_153_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((stage_v_127_1 ^ 0x2A) + pub_r000590_5_1) & 127;
  int stage_v_154_2 = ((stage_v_127_2 ^ 0x2A) + pub_r000590_5_2) & 127;
  if (stage_v_154_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((sec_r000590_9_1 ^ 0x2A) + pub_r000590_9_1) & 127;
  int stage_v_155_2 = ((sec_r000590_9_2 ^ 0x2A) + pub_r000590_9_2) & 127;
  if (stage_v_155_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((stage_v_133_1 ^ 0x2A) + pub_r000590_7_1) & 127;
  int stage_v_156_2 = ((stage_v_133_2 ^ 0x2A) + pub_r000590_7_2) & 127;
  if (stage_v_156_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((stage_v_112_1 ^ 0x2A) + pub_r000590_15_1) & 127;
  int stage_v_157_2 = ((stage_v_112_2 ^ 0x2A) + pub_r000590_15_2) & 127;
  if (stage_v_157_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((stage_v_103_1 ^ 0x2A) + pub_r000590_6_1) & 127;
  int stage_v_158_2 = ((stage_v_103_2 ^ 0x2A) + pub_r000590_6_2) & 127;
  if (stage_v_158_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((sec_r000590_2_1 ^ 0x2A) + pub_r000590_10_1) & 127;
  int stage_v_159_2 = ((sec_r000590_2_2 ^ 0x2A) + pub_r000590_10_2) & 127;
  if (stage_v_159_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((sec_r000590_16_1 ^ 0x2A) + pub_r000590_6_1) & 127;
  int stage_v_160_2 = ((sec_r000590_16_2 ^ 0x2A) + pub_r000590_6_2) & 127;
  if (stage_v_160_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((stage_v_94_1 ^ 0x2A) + pub_r000590_7_1) & 127;
  int stage_v_161_2 = ((stage_v_94_2 ^ 0x2A) + pub_r000590_7_2) & 127;
  if (stage_v_161_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((stage_v_126_1 ^ 0x2A) + pub_r000590_16_1) & 127;
  int stage_v_162_2 = ((stage_v_126_2 ^ 0x2A) + pub_r000590_16_2) & 127;
  if (stage_v_162_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((stage_v_110_1 ^ 0x2A) + pub_r000590_11_1) & 127;
  int stage_v_163_2 = ((stage_v_110_2 ^ 0x2A) + pub_r000590_11_2) & 127;
  if (stage_v_163_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((sec_r000590_12_1 ^ 0x2A) + pub_r000590_0_1) & 127;
  int stage_v_164_2 = ((sec_r000590_12_2 ^ 0x2A) + pub_r000590_0_2) & 127;
  if (stage_v_164_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((sec_r000590_15_1 ^ 0x2A) + pub_r000590_10_1) & 127;
  int stage_v_165_2 = ((sec_r000590_15_2 ^ 0x2A) + pub_r000590_10_2) & 127;
  if (stage_v_165_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((stage_v_109_1 ^ 0x2A) + pub_r000590_2_1) & 127;
  int stage_v_166_2 = ((stage_v_109_2 ^ 0x2A) + pub_r000590_2_2) & 127;
  if (stage_v_166_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((stage_v_138_1 ^ 0x2A) + pub_r000590_11_1) & 127;
  int stage_v_167_2 = ((stage_v_138_2 ^ 0x2A) + pub_r000590_11_2) & 127;
  if (stage_v_167_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((sec_r000590_13_1 ^ 0x2A) + pub_r000590_7_1) & 127;
  int stage_v_168_2 = ((sec_r000590_13_2 ^ 0x2A) + pub_r000590_7_2) & 127;
  if (stage_v_168_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((stage_v_93_1 ^ 0x2A) + pub_r000590_4_1) & 127;
  int stage_v_169_2 = ((stage_v_93_2 ^ 0x2A) + pub_r000590_4_2) & 127;
  if (stage_v_169_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((stage_v_104_1 ^ 0x2A) + pub_r000590_0_1) & 127;
  int stage_v_170_2 = ((stage_v_104_2 ^ 0x2A) + pub_r000590_0_2) & 127;
  if (stage_v_170_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((stage_v_153_1 ^ 0x2A) + pub_r000590_13_1) & 127;
  int stage_v_171_2 = ((stage_v_153_2 ^ 0x2A) + pub_r000590_13_2) & 127;
  if (stage_v_171_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((stage_v_118_1 ^ 0x2A) + pub_r000590_15_1) & 127;
  int stage_v_172_2 = ((stage_v_118_2 ^ 0x2A) + pub_r000590_15_2) & 127;
  if (stage_v_172_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((stage_v_150_1 ^ 0x2A) + pub_r000590_5_1) & 127;
  int stage_v_173_2 = ((stage_v_150_2 ^ 0x2A) + pub_r000590_5_2) & 127;
  if (stage_v_173_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((stage_v_94_1 ^ 0x2A) + pub_r000590_10_1) & 127;
  int stage_v_174_2 = ((stage_v_94_2 ^ 0x2A) + pub_r000590_10_2) & 127;
  if (stage_v_174_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((stage_v_124_1 ^ 0x2A) + pub_r000590_12_1) & 127;
  int stage_v_175_2 = ((stage_v_124_2 ^ 0x2A) + pub_r000590_12_2) & 127;
  if (stage_v_175_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((sec_r000590_0_1 ^ 0x2A) + pub_r000590_1_1) & 127;
  int stage_v_176_2 = ((sec_r000590_0_2 ^ 0x2A) + pub_r000590_1_2) & 127;
  if (stage_v_176_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((stage_v_137_1 ^ 0x2A) + pub_r000590_5_1) & 127;
  int stage_v_177_2 = ((stage_v_137_2 ^ 0x2A) + pub_r000590_5_2) & 127;
  if (stage_v_177_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((sec_r000590_15_1 ^ 0x2A) + pub_r000590_12_1) & 127;
  int stage_v_178_2 = ((sec_r000590_15_2 ^ 0x2A) + pub_r000590_12_2) & 127;
  if (stage_v_178_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((sec_r000590_16_1 ^ 0x2A) + pub_r000590_13_1) & 127;
  int stage_v_179_2 = ((sec_r000590_16_2 ^ 0x2A) + pub_r000590_13_2) & 127;
  if (stage_v_179_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((stage_v_166_1 ^ 0x2A) + pub_r000590_16_1) & 127;
  int stage_v_180_2 = ((stage_v_166_2 ^ 0x2A) + pub_r000590_16_2) & 127;
  if (stage_v_180_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((stage_v_147_1 ^ 0x2A) + pub_r000590_2_1) & 127;
  int stage_v_181_2 = ((stage_v_147_2 ^ 0x2A) + pub_r000590_2_2) & 127;
  if (stage_v_181_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((stage_v_179_1 ^ 0x2A) + pub_r000590_9_1) & 127;
  int stage_v_182_2 = ((stage_v_179_2 ^ 0x2A) + pub_r000590_9_2) & 127;
  if (stage_v_182_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((stage_v_119_1 ^ 0x2A) + pub_r000590_11_1) & 127;
  int stage_v_183_2 = ((stage_v_119_2 ^ 0x2A) + pub_r000590_11_2) & 127;
  if (stage_v_183_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((sec_r000590_1_1 ^ 0x2A) + pub_r000590_7_1) & 127;
  int stage_v_184_2 = ((sec_r000590_1_2 ^ 0x2A) + pub_r000590_7_2) & 127;
  if (stage_v_184_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((stage_v_99_1 ^ 0x2A) + pub_r000590_8_1) & 127;
  int stage_v_185_2 = ((stage_v_99_2 ^ 0x2A) + pub_r000590_8_2) & 127;
  if (stage_v_185_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((stage_v_178_1 ^ 0x2A) + pub_r000590_12_1) & 127;
  int stage_v_186_2 = ((stage_v_178_2 ^ 0x2A) + pub_r000590_12_2) & 127;
  if (stage_v_186_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((stage_v_177_1 ^ 0x2A) + pub_r000590_15_1) & 127;
  int stage_v_187_2 = ((stage_v_177_2 ^ 0x2A) + pub_r000590_15_2) & 127;
  if (stage_v_187_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((stage_v_103_1 ^ 0x2A) + pub_r000590_0_1) & 127;
  int stage_v_188_2 = ((stage_v_103_2 ^ 0x2A) + pub_r000590_0_2) & 127;
  if (stage_v_188_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((stage_v_175_1 ^ 0x2A) + pub_r000590_0_1) & 127;
  int stage_v_189_2 = ((stage_v_175_2 ^ 0x2A) + pub_r000590_0_2) & 127;
  if (stage_v_189_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((stage_v_124_1 ^ 0x2A) + pub_r000590_5_1) & 127;
  int stage_v_190_2 = ((stage_v_124_2 ^ 0x2A) + pub_r000590_5_2) & 127;
  if (stage_v_190_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((stage_v_186_1 ^ 0x2A) + pub_r000590_10_1) & 127;
  int stage_v_191_2 = ((stage_v_186_2 ^ 0x2A) + pub_r000590_10_2) & 127;
  if (stage_v_191_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((stage_v_183_1 ^ 0x2A) + pub_r000590_1_1) & 127;
  int stage_v_192_2 = ((stage_v_183_2 ^ 0x2A) + pub_r000590_1_2) & 127;
  if (stage_v_192_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((stage_v_182_1 ^ 0x2A) + pub_r000590_8_1) & 127;
  int stage_v_193_2 = ((stage_v_182_2 ^ 0x2A) + pub_r000590_8_2) & 127;
  if (stage_v_193_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((sec_r000590_16_1 ^ 0x2A) + pub_r000590_14_1) & 127;
  int stage_v_194_2 = ((sec_r000590_16_2 ^ 0x2A) + pub_r000590_14_2) & 127;
  if (stage_v_194_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((stage_v_125_1 ^ 0x2A) + pub_r000590_12_1) & 127;
  int stage_v_195_2 = ((stage_v_125_2 ^ 0x2A) + pub_r000590_12_2) & 127;
  if (stage_v_195_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((sec_r000590_8_1 ^ 0x2A) + pub_r000590_8_1) & 127;
  int stage_v_196_2 = ((sec_r000590_8_2 ^ 0x2A) + pub_r000590_8_2) & 127;
  if (stage_v_196_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((sec_r000590_10_1 ^ 0x2A) + pub_r000590_10_1) & 127;
  int stage_v_197_2 = ((sec_r000590_10_2 ^ 0x2A) + pub_r000590_10_2) & 127;
  if (stage_v_197_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((stage_v_153_1 ^ 0x2A) + pub_r000590_14_1) & 127;
  int stage_v_198_2 = ((stage_v_153_2 ^ 0x2A) + pub_r000590_14_2) & 127;
  if (stage_v_198_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((stage_v_173_1 ^ 0x2A) + pub_r000590_9_1) & 127;
  int stage_v_199_2 = ((stage_v_173_2 ^ 0x2A) + pub_r000590_9_2) & 127;
  if (stage_v_199_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((stage_v_113_1 ^ 0x2A) + pub_r000590_10_1) & 127;
  int stage_v_200_2 = ((stage_v_113_2 ^ 0x2A) + pub_r000590_10_2) & 127;
  if (stage_v_200_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((sec_r000590_9_1 ^ 0x2A) + pub_r000590_13_1) & 127;
  int stage_v_201_2 = ((sec_r000590_9_2 ^ 0x2A) + pub_r000590_13_2) & 127;
  if (stage_v_201_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((stage_v_166_1 ^ 0x2A) + pub_r000590_0_1) & 127;
  int stage_v_202_2 = ((stage_v_166_2 ^ 0x2A) + pub_r000590_0_2) & 127;
  if (stage_v_202_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((stage_v_148_1 ^ 0x2A) + pub_r000590_4_1) & 127;
  int stage_v_203_2 = ((stage_v_148_2 ^ 0x2A) + pub_r000590_4_2) & 127;
  if (stage_v_203_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((stage_v_131_1 ^ 0x2A) + pub_r000590_8_1) & 127;
  int stage_v_204_2 = ((stage_v_131_2 ^ 0x2A) + pub_r000590_8_2) & 127;
  if (stage_v_204_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((sec_r000590_3_1 ^ 0x2A) + pub_r000590_15_1) & 127;
  int stage_v_205_2 = ((sec_r000590_3_2 ^ 0x2A) + pub_r000590_15_2) & 127;
  if (stage_v_205_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((sec_r000590_3_1 ^ 0x2A) + pub_r000590_9_1) & 127;
  int stage_v_206_2 = ((sec_r000590_3_2 ^ 0x2A) + pub_r000590_9_2) & 127;
  if (stage_v_206_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((stage_v_167_1 ^ 0x2A) + pub_r000590_11_1) & 127;
  int stage_v_207_2 = ((stage_v_167_2 ^ 0x2A) + pub_r000590_11_2) & 127;
  if (stage_v_207_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((sec_r000590_3_1 ^ 0x2A) + pub_r000590_2_1) & 127;
  int stage_v_208_2 = ((sec_r000590_3_2 ^ 0x2A) + pub_r000590_2_2) & 127;
  if (stage_v_208_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((stage_v_175_1 ^ 0x2A) + pub_r000590_10_1) & 127;
  int stage_v_209_2 = ((stage_v_175_2 ^ 0x2A) + pub_r000590_10_2) & 127;
  if (stage_v_209_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((sec_r000590_15_1 ^ 0x2A) + pub_r000590_3_1) & 127;
  int stage_v_210_2 = ((sec_r000590_15_2 ^ 0x2A) + pub_r000590_3_2) & 127;
  if (stage_v_210_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((stage_v_210_1 ^ 0x2A) + pub_r000590_3_1) & 127;
  int stage_v_211_2 = ((stage_v_210_2 ^ 0x2A) + pub_r000590_3_2) & 127;
  if (stage_v_211_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((stage_v_168_1 ^ 0x2A) + pub_r000590_13_1) & 127;
  int stage_v_212_2 = ((stage_v_168_2 ^ 0x2A) + pub_r000590_13_2) & 127;
  if (stage_v_212_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((sec_r000590_3_1 ^ 0x2A) + pub_r000590_3_1) & 127;
  int stage_v_213_2 = ((sec_r000590_3_2 ^ 0x2A) + pub_r000590_3_2) & 127;
  if (stage_v_213_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((sec_r000590_14_1 ^ 0x2A) + pub_r000590_10_1) & 127;
  int stage_v_214_2 = ((sec_r000590_14_2 ^ 0x2A) + pub_r000590_10_2) & 127;
  if (stage_v_214_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((sec_r000590_15_1 ^ 0x2A) + pub_r000590_4_1) & 127;
  int stage_v_215_2 = ((sec_r000590_15_2 ^ 0x2A) + pub_r000590_4_2) & 127;
  if (stage_v_215_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((stage_v_156_1 ^ 0x2A) + pub_r000590_0_1) & 127;
  int stage_v_216_2 = ((stage_v_156_2 ^ 0x2A) + pub_r000590_0_2) & 127;
  if (stage_v_216_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((sec_r000590_3_1 ^ 0x2A) + pub_r000590_14_1) & 127;
  int stage_v_217_2 = ((sec_r000590_3_2 ^ 0x2A) + pub_r000590_14_2) & 127;
  if (stage_v_217_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((stage_v_132_1 ^ 0x2A) + pub_r000590_8_1) & 127;
  int stage_v_218_2 = ((stage_v_132_2 ^ 0x2A) + pub_r000590_8_2) & 127;
  if (stage_v_218_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((stage_v_118_1 ^ 0x2A) + pub_r000590_12_1) & 127;
  int stage_v_219_2 = ((stage_v_118_2 ^ 0x2A) + pub_r000590_12_2) & 127;
  if (stage_v_219_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((stage_v_177_1 ^ 0x2A) + pub_r000590_2_1) & 127;
  int stage_v_220_2 = ((stage_v_177_2 ^ 0x2A) + pub_r000590_2_2) & 127;
  if (stage_v_220_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((sec_r000590_6_1 ^ 0x2A) + pub_r000590_6_1) & 127;
  int stage_v_221_2 = ((sec_r000590_6_2 ^ 0x2A) + pub_r000590_6_2) & 127;
  if (stage_v_221_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((sec_r000590_6_1 ^ 0x2A) + pub_r000590_3_1) & 127;
  int stage_v_222_2 = ((sec_r000590_6_2 ^ 0x2A) + pub_r000590_3_2) & 127;
  if (stage_v_222_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((stage_v_153_1 ^ 0x2A) + pub_r000590_8_1) & 127;
  int stage_v_223_2 = ((stage_v_153_2 ^ 0x2A) + pub_r000590_8_2) & 127;
  if (stage_v_223_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((stage_v_114_1 ^ 0x2A) + pub_r000590_13_1) & 127;
  int stage_v_224_2 = ((stage_v_114_2 ^ 0x2A) + pub_r000590_13_2) & 127;
  if (stage_v_224_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((stage_v_181_1 ^ 0x2A) + pub_r000590_8_1) & 127;
  int stage_v_225_2 = ((stage_v_181_2 ^ 0x2A) + pub_r000590_8_2) & 127;
  if (stage_v_225_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
  }
  if (stage_v_225_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((stage_v_175_1 ^ 0x2A) + pub_r000590_2_1) & 127;
  int stage_v_226_2 = ((stage_v_175_2 ^ 0x2A) + pub_r000590_2_2) & 127;
  if (stage_v_226_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
  }
  if (stage_v_226_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((stage_v_205_1 ^ 0x2A) + pub_r000590_9_1) & 127;
  int stage_v_227_2 = ((stage_v_205_2 ^ 0x2A) + pub_r000590_9_2) & 127;
  if (stage_v_227_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((stage_v_129_1 ^ 0x2A) + pub_r000590_5_1) & 127;
  int stage_v_228_2 = ((stage_v_129_2 ^ 0x2A) + pub_r000590_5_2) & 127;
  if (stage_v_228_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((stage_v_123_1 ^ 0x2A) + pub_r000590_3_1) & 127;
  int stage_v_229_2 = ((stage_v_123_2 ^ 0x2A) + pub_r000590_3_2) & 127;
  if (stage_v_229_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((sec_r000590_5_1 ^ 0x2A) + pub_r000590_5_1) & 127;
  int stage_v_230_2 = ((sec_r000590_5_2 ^ 0x2A) + pub_r000590_5_2) & 127;
  if (stage_v_230_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((sec_r000590_0_1 ^ 0x2A) + pub_r000590_1_1) & 127;
  int stage_v_231_2 = ((sec_r000590_0_2 ^ 0x2A) + pub_r000590_1_2) & 127;
  if (stage_v_231_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
  }
  if (stage_v_231_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((stage_v_166_1 ^ 0x2A) + pub_r000590_1_1) & 127;
  int stage_v_232_2 = ((stage_v_166_2 ^ 0x2A) + pub_r000590_1_2) & 127;
  if (stage_v_232_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
  }
  if (stage_v_232_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((sec_r000590_14_1 ^ 0x2A) + pub_r000590_4_1) & 127;
  int stage_v_233_2 = ((sec_r000590_14_2 ^ 0x2A) + pub_r000590_4_2) & 127;
  if (stage_v_233_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
  }
  if (stage_v_233_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((stage_v_223_1 ^ 0x2A) + pub_r000590_0_1) & 127;
  int stage_v_234_2 = ((stage_v_223_2 ^ 0x2A) + pub_r000590_0_2) & 127;
  if (stage_v_234_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
  }
  if (stage_v_234_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((sec_r000590_17_1 ^ 0x2A) + pub_r000590_1_1) & 127;
  int stage_v_235_2 = ((sec_r000590_17_2 ^ 0x2A) + pub_r000590_1_2) & 127;
  if (stage_v_235_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
  }
  if (stage_v_235_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((stage_v_152_1 ^ 0x2A) + pub_r000590_9_1) & 127;
  int stage_v_236_2 = ((stage_v_152_2 ^ 0x2A) + pub_r000590_9_2) & 127;
  if (stage_v_236_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
  }
  if (stage_v_236_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((stage_v_101_1 ^ 0x2A) + pub_r000590_4_1) & 127;
  int stage_v_237_2 = ((stage_v_101_2 ^ 0x2A) + pub_r000590_4_2) & 127;
  if (stage_v_237_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
  }
  if (stage_v_237_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((stage_v_181_1 ^ 0x2A) + pub_r000590_4_1) & 127;
  int stage_v_238_2 = ((stage_v_181_2 ^ 0x2A) + pub_r000590_4_2) & 127;
  if (stage_v_238_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
  }
  if (stage_v_238_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000590_10_1 != sec_r000590_10_2);
  __CPROVER_assume(pub_r000590_6_1 == pub_r000590_6_2);
  __CPROVER_assume(sec_r000590_1_1 != sec_r000590_1_2);
  __CPROVER_assume(sec_r000590_2_1 != sec_r000590_2_2);
  __CPROVER_assume(pub_r000590_7_1 == pub_r000590_7_2);
  __CPROVER_assume(pub_r000590_13_1 == pub_r000590_13_2);
  __CPROVER_assume(sec_r000590_16_1 != sec_r000590_16_2);
  __CPROVER_assume(sec_r000590_17_1 != sec_r000590_17_2);
  __CPROVER_assume(pub_r000590_12_1 == pub_r000590_12_2);
  __CPROVER_assume(sec_r000590_7_1 != sec_r000590_7_2);
  __CPROVER_assume(pub_r000590_0_1 == pub_r000590_0_2);
  __CPROVER_assume(sec_r000590_9_1 != sec_r000590_9_2);
  __CPROVER_assume(pub_r000590_11_1 == pub_r000590_11_2);
  __CPROVER_assume(sec_r000590_6_1 != sec_r000590_6_2);
  __CPROVER_assume(sec_r000590_12_1 != sec_r000590_12_2);
  __CPROVER_assume(pub_r000590_15_1 == pub_r000590_15_2);
  __CPROVER_assume(pub_r000590_9_1 == pub_r000590_9_2);
  __CPROVER_assume(pub_r000590_3_1 == pub_r000590_3_2);
  __CPROVER_assume(pub_r000590_1_1 == pub_r000590_1_2);
  __CPROVER_assume(pub_r000590_10_1 == pub_r000590_10_2);
  __CPROVER_assume(pub_r000590_14_1 == pub_r000590_14_2);
  __CPROVER_assume(sec_r000590_14_1 != sec_r000590_14_2);
  __CPROVER_assume(pub_r000590_16_1 == pub_r000590_16_2);
  __CPROVER_assume(pub_r000590_8_1 == pub_r000590_8_2);
  __CPROVER_assume(pub_r000590_4_1 == pub_r000590_4_2);
  __CPROVER_assume(sec_r000590_11_1 != sec_r000590_11_2);
  __CPROVER_assume(sec_r000590_4_1 != sec_r000590_4_2);
  __CPROVER_assume(sec_r000590_13_1 != sec_r000590_13_2);
  __CPROVER_assume(pub_r000590_2_1 == pub_r000590_2_2);
  __CPROVER_assume(sec_r000590_3_1 != sec_r000590_3_2);
  __CPROVER_assume(sec_r000590_0_1 != sec_r000590_0_2);
  __CPROVER_assume(sec_r000590_8_1 != sec_r000590_8_2);
  __CPROVER_assume(sec_r000590_15_1 != sec_r000590_15_2);
  __CPROVER_assume(sec_r000590_5_1 != sec_r000590_5_2);
  __CPROVER_assume(pub_r000590_5_1 == pub_r000590_5_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.density == st_var_0_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.code == st_var_1_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
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
}


