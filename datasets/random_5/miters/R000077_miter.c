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
struct AudioFrame_R000077_7713_0
{
  short envelope;
  unsigned char gain;
  int peak;
  int channels;
  int rms;
  int sample_rate;
  int buffer[3];
};
struct StreamBuffer_R000077_7713_1
{
  int watermark;
  short tail;
  unsigned char checksum;
  int head;
  int capacity;
  short state;
  int buffer[3];
};
union TelemetryField_R000077_7713_0
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
void fn_R000077_7713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st_1 = {0};
  struct AudioFrame_R000077_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_37_1 = local_arr_1[aux_1 % 3];
  int mask_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_37_2 * 2)) & 127;
  int vector_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_47_1 > 40)
  {
    acc_1 = ((acc_1 + (vector_47_1 * 2)) + 5) & 127;
    aux_1 ^= vector_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_47_2 > 40)
  {
    acc_2 = ((acc_2 + (vector_47_2 * 2)) + 5) & 127;
    aux_2 ^= vector_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_47_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_37_1 == mask_37_2);
  assert(vector_47_1 == vector_47_2);
}

int fn_R000077_7713_0(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int mask_37 = local_arr[aux % 3];
  acc = (acc + (mask_37 * 2)) & 127;
  int vector_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_47 > 40)
  {
    acc = ((acc + (vector_47 * 2)) + 5) & 127;
    aux ^= vector_47 & 15;
  }
  else
  {
    acc = ((acc - vector_47) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000077_7713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st_1 = {0};
  struct StreamBuffer_R000077_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_87_1 = local_arr_1[aux_1 % 3];
  int quantum_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_87_2 * 2)) & 127;
  int bound_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_93_1 > 24)
  {
    acc_1 = ((acc_1 + (bound_93_1 * 2)) + 5) & 127;
    aux_1 ^= bound_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_93_2 > 24)
  {
    acc_2 = ((acc_2 + (bound_93_2 * 2)) + 5) & 127;
    aux_2 ^= bound_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_87_1 == quantum_87_2);
  assert(bound_93_1 == bound_93_2);
}

int fn_R000077_7713_1(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int quantum_87 = local_arr[aux % 3];
  acc = (acc + (quantum_87 * 2)) & 127;
  int bound_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_93 > 24)
  {
    acc = ((acc + (bound_93 * 2)) + 5) & 127;
    aux ^= bound_93 & 15;
  }
  else
  {
    acc = ((acc - bound_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000077_7713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st_1 = {0};
  struct StreamBuffer_R000077_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int pivot_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_59_1 > 42)
  {
    acc_1 = ((acc_1 + (pivot_59_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_59_2 > 42)
  {
    acc_2 = ((acc_2 + (pivot_59_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_78_1)
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

  switch (accumulator_78_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_59_1 == pivot_59_2);
  assert(accumulator_78_1 == accumulator_78_2);
}

int fn_R000077_7713_2(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int pivot_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_59 > 42)
  {
    acc = ((acc + (pivot_59 * 2)) + 5) & 127;
    aux ^= pivot_59 & 15;
  }
  else
  {
    acc = ((acc - pivot_59) + 11) & 127;
    aux += 3;
  }
  int accumulator_78 = (aux + st.buffer[1]) & 3;
  switch (accumulator_78)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000077_7713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st_1 = {0};
  struct StreamBuffer_R000077_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_97_1 = local_arr_1[aux_1 % 3];
  int sample_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_97_2 * 2)) & 127;
  int factor_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_37_1) & 63;
  aux_2 = (aux_2 + factor_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_79_1 > 18)
  {
    acc_1 = ((acc_1 + (bound_79_1 * 2)) + 5) & 127;
    aux_1 ^= bound_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_79_2 > 18)
  {
    acc_2 = ((acc_2 + (bound_79_2 * 2)) + 5) & 127;
    aux_2 ^= bound_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_22_1)
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

  switch (scale_22_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_97_1 == sample_97_2);
  assert(factor_37_1 == factor_37_2);
  assert(bound_79_1 == bound_79_2);
  assert(scale_22_1 == scale_22_2);
}

int fn_R000077_7713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int sample_97 = local_arr[aux % 3];
  acc = (acc + (sample_97 * 2)) & 127;
  int factor_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_37) & 63;
  acc ^= aux;
  int bound_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_79 > 18)
  {
    acc = ((acc + (bound_79 * 2)) + 5) & 127;
    aux ^= bound_79 & 15;
  }
  else
  {
    acc = ((acc - bound_79) + 11) & 127;
    aux += 3;
  }
  int scale_22 = (aux + st.buffer[1]) & 3;
  switch (scale_22)
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

void fn_R000077_7713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st_1 = {0};
  struct AudioFrame_R000077_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int residue_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_75_1) & 63;
  aux_2 = (aux_2 + residue_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_48_1 > 40)
  {
    acc_1 = ((acc_1 + (accumulator_48_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_48_2 > 40)
  {
    acc_2 = ((acc_2 + (accumulator_48_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_50_1 = local_arr_1[aux_1 % 3];
  int coefficient_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_50_2 * 2)) & 127;
  int pivot_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_47_1)
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

  switch (pivot_47_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_75_1 == residue_75_2);
  assert(accumulator_48_1 == accumulator_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_50_1 == coefficient_50_2);
  assert(pivot_47_1 == pivot_47_2);
}

int fn_R000077_7713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int residue_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_75) & 63;
  acc ^= aux;
  int accumulator_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_48 > 40)
  {
    acc = ((acc + (accumulator_48 * 2)) + 5) & 127;
    aux ^= accumulator_48 & 15;
  }
  else
  {
    acc = ((acc - accumulator_48) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_50 = local_arr[aux % 3];
  acc = (acc + (coefficient_50 * 2)) & 127;
  int pivot_47 = (aux + st.buffer[1]) & 3;
  switch (pivot_47)
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

void fn_R000077_7713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st_1 = {0};
  struct AudioFrame_R000077_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int parity_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_53_1)
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

  switch (parity_53_2)
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
  int delta_52_1 = local_arr_1[aux_1 % 3];
  int delta_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_53_1 == parity_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_52_1 == delta_52_2);
}

int fn_R000077_7713_5(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int parity_53 = (aux + st.buffer[1]) & 3;
  switch (parity_53)
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
  int delta_52 = local_arr[aux % 3];
  acc = (acc + (delta_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000077_7713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st_1 = {0};
  struct StreamBuffer_R000077_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int metric_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_48_1) & 63;
  aux_2 = (aux_2 + metric_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_51_1)
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

  switch (bound_51_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_48_1 == metric_48_2);
  assert(bound_51_1 == bound_51_2);
}

int fn_R000077_7713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int metric_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_48) & 63;
  acc ^= aux;
  int bound_51 = (aux + st.buffer[1]) & 3;
  switch (bound_51)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000077_7713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st_1 = {0};
  struct AudioFrame_R000077_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int checksum_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_96_1) & 63;
  aux_2 = (aux_2 + checksum_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_25_1)
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

  switch (accumulator_25_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_96_1 == checksum_96_2);
  assert(accumulator_25_1 == accumulator_25_2);
}

int fn_R000077_7713_7(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int checksum_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_96) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_25 = (aux + st.buffer[1]) & 3;
  switch (accumulator_25)
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

void fn_R000077_7713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st_1 = {0};
  struct StreamBuffer_R000077_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int segment_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_44_1 > 48)
  {
    acc_1 = ((acc_1 + (segment_44_1 * 2)) + 5) & 127;
    aux_1 ^= segment_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_44_2 > 48)
  {
    acc_2 = ((acc_2 + (segment_44_2 * 2)) + 5) & 127;
    aux_2 ^= segment_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_83_1)
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

  switch (sample_83_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_44_1 == segment_44_2);
  assert(sample_83_1 == sample_83_2);
}

int fn_R000077_7713_8(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int segment_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_44 > 48)
  {
    acc = ((acc + (segment_44 * 2)) + 5) & 127;
    aux ^= segment_44 & 15;
  }
  else
  {
    acc = ((acc - segment_44) + 11) & 127;
    aux += 3;
  }
  int sample_83 = (aux + st.buffer[1]) & 3;
  switch (sample_83)
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

void fn_R000077_7713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st_1 = {0};
  struct AudioFrame_R000077_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int quotient_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_41_1 > 32)
  {
    acc_1 = ((acc_1 + (quotient_41_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_41_2 > 32)
  {
    acc_2 = ((acc_2 + (quotient_41_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_62_1 = local_arr_1[aux_1 % 3];
  int pivot_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_62_2 * 2)) & 127;
  int weight_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_62_1)
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

  switch (weight_62_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_41_1 == quotient_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_62_1 == pivot_62_2);
  assert(weight_62_1 == weight_62_2);
}

int fn_R000077_7713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int quotient_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_41 > 32)
  {
    acc = ((acc + (quotient_41 * 2)) + 5) & 127;
    aux ^= quotient_41 & 15;
  }
  else
  {
    acc = ((acc - quotient_41) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int pivot_62 = local_arr[aux % 3];
  acc = (acc + (pivot_62 * 2)) & 127;
  int weight_62 = (aux + st.buffer[1]) & 3;
  switch (weight_62)
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

void fn_R000077_7713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st_1 = {0};
  struct StreamBuffer_R000077_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int sample_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_48_1)
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

  switch (sample_48_2)
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

  int bound_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_70_1) & 63;
  aux_2 = (aux_2 + bound_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_15_1 = local_arr_1[aux_1 % 3];
  int coefficient_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_15_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_48_1 == sample_48_2);
  assert(bound_70_1 == bound_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_15_1 == coefficient_15_2);
}

int fn_R000077_7713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int sample_48 = (aux + st.buffer[1]) & 3;
  switch (sample_48)
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

  int bound_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_70) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_15 = local_arr[aux % 3];
  acc = (acc + (coefficient_15 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000077_7713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st_1 = {0};
  struct StreamBuffer_R000077_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int residue_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_98_1)
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

  switch (residue_98_2)
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
  int parity_92_1 = local_arr_1[aux_1 % 3];
  int parity_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_92_2 * 2)) & 127;
  int stride_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_48_1 > 28)
  {
    acc_1 = ((acc_1 + (stride_48_1 * 2)) + 5) & 127;
    aux_1 ^= stride_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_48_2 > 28)
  {
    acc_2 = ((acc_2 + (stride_48_2 * 2)) + 5) & 127;
    aux_2 ^= stride_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_34_1) & 63;
  aux_2 = (aux_2 + damping_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_98_1 == residue_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_92_1 == parity_92_2);
  assert(stride_48_1 == stride_48_2);
  assert(damping_34_1 == damping_34_2);
}

int fn_R000077_7713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int residue_98 = (aux + st.buffer[1]) & 3;
  switch (residue_98)
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
  int parity_92 = local_arr[aux % 3];
  acc = (acc + (parity_92 * 2)) & 127;
  int stride_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_48 > 28)
  {
    acc = ((acc + (stride_48 * 2)) + 5) & 127;
    aux ^= stride_48 & 15;
  }
  else
  {
    acc = ((acc - stride_48) + 11) & 127;
    aux += 3;
  }
  int damping_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000077_7713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st_1 = {0};
  struct AudioFrame_R000077_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_23_1 = local_arr_1[aux_1 % 3];
  int anchor_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_23_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_64_1) & 63;
  aux_2 = (aux_2 + window_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_23_1 == anchor_23_2);
  assert(window_64_1 == window_64_2);
}

int fn_R000077_7713_12(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int anchor_23 = local_arr[aux % 3];
  acc = (acc + (anchor_23 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000077_7713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st_1 = {0};
  struct StreamBuffer_R000077_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int accumulator_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_49_1 > 16)
  {
    acc_1 = ((acc_1 + (accumulator_49_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_49_2 > 16)
  {
    acc_2 = ((acc_2 + (accumulator_49_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_49_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_70_1 = local_arr_1[aux_1 % 3];
  int pivot_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_70_2 * 2)) & 127;
  int index_reg_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_10_1) & 63;
  aux_2 = (aux_2 + index_reg_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_49_1 == accumulator_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_70_1 == pivot_70_2);
  assert(index_reg_10_1 == index_reg_10_2);
}

int fn_R000077_7713_13(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int accumulator_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_49 > 16)
  {
    acc = ((acc + (accumulator_49 * 2)) + 5) & 127;
    aux ^= accumulator_49 & 15;
  }
  else
  {
    acc = ((acc - accumulator_49) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int pivot_70 = local_arr[aux % 3];
  acc = (acc + (pivot_70 * 2)) & 127;
  int index_reg_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_10) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000077_7713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st_1 = {0};
  struct AudioFrame_R000077_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_69_1 = local_arr_1[aux_1 % 3];
  int parity_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_69_2 * 2)) & 127;
  int tracker_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_92_1)
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

  switch (tracker_92_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_96_1) & 63;
  aux_2 = (aux_2 + margin_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_69_1 == parity_69_2);
  assert(tracker_92_1 == tracker_92_2);
  assert(margin_96_1 == margin_96_2);
}

int fn_R000077_7713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int parity_69 = local_arr[aux % 3];
  acc = (acc + (parity_69 * 2)) & 127;
  int tracker_92 = (aux + st.buffer[1]) & 3;
  switch (tracker_92)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000077_7713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st_1 = {0};
  struct StreamBuffer_R000077_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_30_1 > 32)
  {
    acc_1 = ((acc_1 + (vector_30_1 * 2)) + 5) & 127;
    aux_1 ^= vector_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_30_2 > 32)
  {
    acc_2 = ((acc_2 + (vector_30_2 * 2)) + 5) & 127;
    aux_2 ^= vector_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_30_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_30_1 == vector_30_2);
}

int fn_R000077_7713_15(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_30 > 32)
  {
    acc = ((acc + (vector_30 * 2)) + 5) & 127;
    aux ^= vector_30 & 15;
  }
  else
  {
    acc = ((acc - vector_30) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000077_7713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st_1 = {0};
  struct AudioFrame_R000077_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int cursor_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_41_1) & 63;
  aux_2 = (aux_2 + cursor_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_40_1 = local_arr_1[aux_1 % 3];
  int coefficient_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_40_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_69_1 > 12)
  {
    acc_1 = ((acc_1 + (sample_69_1 * 2)) + 5) & 127;
    aux_1 ^= sample_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_69_2 > 12)
  {
    acc_2 = ((acc_2 + (sample_69_2 * 2)) + 5) & 127;
    aux_2 ^= sample_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_41_1 == cursor_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_40_1 == coefficient_40_2);
  assert(sample_69_1 == sample_69_2);
}

int fn_R000077_7713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int cursor_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_41) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_40 = local_arr[aux % 3];
  acc = (acc + (coefficient_40 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_69 > 12)
  {
    acc = ((acc + (sample_69 * 2)) + 5) & 127;
    aux ^= sample_69 & 15;
  }
  else
  {
    acc = ((acc - sample_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000077_7713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st_1 = {0};
  struct AudioFrame_R000077_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int damping_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_15_1)
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

  switch (damping_15_2)
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

  int margin_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_61_1) & 63;
  aux_2 = (aux_2 + margin_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_40_1 = local_arr_1[aux_1 % 3];
  int tally_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_15_1 == damping_15_2);
  assert(margin_61_1 == margin_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_40_1 == tally_40_2);
}

int fn_R000077_7713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int damping_15 = (aux + st.buffer[1]) & 3;
  switch (damping_15)
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

  int margin_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_61) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_40 = local_arr[aux % 3];
  acc = (acc + (tally_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000077_7713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st_1 = {0};
  struct AudioFrame_R000077_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int bound_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_36_1)
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

  switch (bound_36_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_32_1 = local_arr_1[aux_1 % 3];
  int damping_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_36_1 == bound_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_32_1 == damping_32_2);
}

int fn_R000077_7713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int bound_36 = (aux + st.buffer[1]) & 3;
  switch (bound_36)
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
  int local_arr[3] = {4, 9, 15};
  int damping_32 = local_arr[aux % 3];
  acc = (acc + (damping_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000077_7713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st_1 = {0};
  struct AudioFrame_R000077_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_35_1)
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

  switch (margin_35_2)
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
  int quotient_16_1 = local_arr_1[aux_1 % 3];
  int quotient_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_16_2 * 2)) & 127;
  int sample_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_13_1 > 48)
  {
    acc_1 = ((acc_1 + (sample_13_1 * 2)) + 5) & 127;
    aux_1 ^= sample_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_13_2 > 48)
  {
    acc_2 = ((acc_2 + (sample_13_2 * 2)) + 5) & 127;
    aux_2 ^= sample_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_13_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_35_1 == margin_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_16_1 == quotient_16_2);
  assert(sample_13_1 == sample_13_2);
}

int fn_R000077_7713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000077_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_35 = (aux + st.buffer[1]) & 3;
  switch (margin_35)
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
  int quotient_16 = local_arr[aux % 3];
  acc = (acc + (quotient_16 * 2)) & 127;
  int sample_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_13 > 48)
  {
    acc = ((acc + (sample_13 * 2)) + 5) & 127;
    aux ^= sample_13 & 15;
  }
  else
  {
    acc = ((acc - sample_13) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000077_7713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st_1 = {0};
  struct StreamBuffer_R000077_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_37_1 = local_arr_1[aux_1 % 3];
  int vector_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_37_2 * 2)) & 127;
  int window_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_60_1) & 63;
  aux_2 = (aux_2 + window_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_37_1 == vector_37_2);
  assert(window_60_1 == window_60_2);
}

int fn_R000077_7713_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000077_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int vector_37 = local_arr[aux % 3];
  acc = (acc + (vector_37 * 2)) & 127;
  int window_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_60) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000077_0_1;
  int sec_r000077_0_2;
  int sec_r000077_1_1;
  int sec_r000077_1_2;
  int sec_r000077_2_1;
  int sec_r000077_2_2;
  int sec_r000077_3_1;
  int sec_r000077_3_2;
  int sec_r000077_4_1;
  int sec_r000077_4_2;
  int sec_r000077_5_1;
  int sec_r000077_5_2;
  int sec_r000077_6_1;
  int sec_r000077_6_2;
  int sec_r000077_7_1;
  int sec_r000077_7_2;
  int sec_r000077_8_1;
  int sec_r000077_8_2;
  int sec_r000077_9_1;
  int sec_r000077_9_2;
  int sec_r000077_10_1;
  int sec_r000077_10_2;
  int sec_r000077_11_1;
  int sec_r000077_11_2;
  int sec_r000077_12_1;
  int sec_r000077_12_2;
  int sec_r000077_13_1;
  int sec_r000077_13_2;
  int sec_r000077_14_1;
  int sec_r000077_14_2;
  int sec_r000077_15_1;
  int sec_r000077_15_2;
  int sec_r000077_16_1;
  int sec_r000077_16_2;
  int sec_r000077_17_1;
  int sec_r000077_17_2;
  int pub_r000077_0_1;
  int pub_r000077_0_2;
  int pub_r000077_1_1;
  int pub_r000077_1_2;
  int pub_r000077_2_1;
  int pub_r000077_2_2;
  int pub_r000077_3_1;
  int pub_r000077_3_2;
  int pub_r000077_4_1;
  int pub_r000077_4_2;
  int pub_r000077_5_1;
  int pub_r000077_5_2;
  int pub_r000077_6_1;
  int pub_r000077_6_2;
  int pub_r000077_7_1;
  int pub_r000077_7_2;
  int pub_r000077_8_1;
  int pub_r000077_8_2;
  int pub_r000077_9_1;
  int pub_r000077_9_2;
  int pub_r000077_10_1;
  int pub_r000077_10_2;
  int pub_r000077_11_1;
  int pub_r000077_11_2;
  int pub_r000077_12_1;
  int pub_r000077_12_2;
  int pub_r000077_13_1;
  int pub_r000077_13_2;
  int pub_r000077_14_1;
  int pub_r000077_14_2;
  int pub_r000077_15_1;
  int pub_r000077_15_2;
  int pub_r000077_16_1;
  int pub_r000077_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000077_0_1 >= (-100)) && (pub_r000077_0_1 <= 100));
  __CPROVER_assume((pub_r000077_0_2 >= (-100)) && (pub_r000077_0_2 <= 100));
  __CPROVER_assume((pub_r000077_1_1 >= (-100)) && (pub_r000077_1_1 <= 100));
  __CPROVER_assume((pub_r000077_1_2 >= (-100)) && (pub_r000077_1_2 <= 100));
  __CPROVER_assume((pub_r000077_2_1 >= (-100)) && (pub_r000077_2_1 <= 100));
  __CPROVER_assume((pub_r000077_2_2 >= (-100)) && (pub_r000077_2_2 <= 100));
  __CPROVER_assume((pub_r000077_3_1 >= (-100)) && (pub_r000077_3_1 <= 100));
  __CPROVER_assume((pub_r000077_3_2 >= (-100)) && (pub_r000077_3_2 <= 100));
  __CPROVER_assume((pub_r000077_4_1 >= (-100)) && (pub_r000077_4_1 <= 100));
  __CPROVER_assume((pub_r000077_4_2 >= (-100)) && (pub_r000077_4_2 <= 100));
  __CPROVER_assume((pub_r000077_5_1 >= (-100)) && (pub_r000077_5_1 <= 100));
  __CPROVER_assume((pub_r000077_5_2 >= (-100)) && (pub_r000077_5_2 <= 100));
  __CPROVER_assume((pub_r000077_6_1 >= (-100)) && (pub_r000077_6_1 <= 100));
  __CPROVER_assume((pub_r000077_6_2 >= (-100)) && (pub_r000077_6_2 <= 100));
  __CPROVER_assume((pub_r000077_7_1 >= (-100)) && (pub_r000077_7_1 <= 100));
  __CPROVER_assume((pub_r000077_7_2 >= (-100)) && (pub_r000077_7_2 <= 100));
  __CPROVER_assume((pub_r000077_8_1 >= (-100)) && (pub_r000077_8_1 <= 100));
  __CPROVER_assume((pub_r000077_8_2 >= (-100)) && (pub_r000077_8_2 <= 100));
  __CPROVER_assume((pub_r000077_9_1 >= (-100)) && (pub_r000077_9_1 <= 100));
  __CPROVER_assume((pub_r000077_9_2 >= (-100)) && (pub_r000077_9_2 <= 100));
  __CPROVER_assume((pub_r000077_10_1 >= (-100)) && (pub_r000077_10_1 <= 100));
  __CPROVER_assume((pub_r000077_10_2 >= (-100)) && (pub_r000077_10_2 <= 100));
  __CPROVER_assume((pub_r000077_11_1 >= (-100)) && (pub_r000077_11_1 <= 100));
  __CPROVER_assume((pub_r000077_11_2 >= (-100)) && (pub_r000077_11_2 <= 100));
  __CPROVER_assume((pub_r000077_12_1 >= (-100)) && (pub_r000077_12_1 <= 100));
  __CPROVER_assume((pub_r000077_12_2 >= (-100)) && (pub_r000077_12_2 <= 100));
  __CPROVER_assume((pub_r000077_13_1 >= (-100)) && (pub_r000077_13_1 <= 100));
  __CPROVER_assume((pub_r000077_13_2 >= (-100)) && (pub_r000077_13_2 <= 100));
  __CPROVER_assume((pub_r000077_14_1 >= (-100)) && (pub_r000077_14_1 <= 100));
  __CPROVER_assume((pub_r000077_14_2 >= (-100)) && (pub_r000077_14_2 <= 100));
  __CPROVER_assume((pub_r000077_15_1 >= (-100)) && (pub_r000077_15_1 <= 100));
  __CPROVER_assume((pub_r000077_15_2 >= (-100)) && (pub_r000077_15_2 <= 100));
  __CPROVER_assume((pub_r000077_16_1 >= (-100)) && (pub_r000077_16_1 <= 100));
  __CPROVER_assume((pub_r000077_16_2 >= (-100)) && (pub_r000077_16_2 <= 100));
  __CPROVER_assume((sec_r000077_0_1 >= 0) && (sec_r000077_0_1 <= 255));
  __CPROVER_assume((sec_r000077_0_2 >= 0) && (sec_r000077_0_2 <= 255));
  __CPROVER_assume((sec_r000077_1_1 >= 0) && (sec_r000077_1_1 <= 255));
  __CPROVER_assume((sec_r000077_1_2 >= 0) && (sec_r000077_1_2 <= 255));
  __CPROVER_assume((sec_r000077_2_1 >= 0) && (sec_r000077_2_1 <= 255));
  __CPROVER_assume((sec_r000077_2_2 >= 0) && (sec_r000077_2_2 <= 255));
  __CPROVER_assume((sec_r000077_3_1 >= 0) && (sec_r000077_3_1 <= 255));
  __CPROVER_assume((sec_r000077_3_2 >= 0) && (sec_r000077_3_2 <= 255));
  __CPROVER_assume((sec_r000077_4_1 >= 0) && (sec_r000077_4_1 <= 255));
  __CPROVER_assume((sec_r000077_4_2 >= 0) && (sec_r000077_4_2 <= 255));
  __CPROVER_assume((sec_r000077_5_1 >= 0) && (sec_r000077_5_1 <= 255));
  __CPROVER_assume((sec_r000077_5_2 >= 0) && (sec_r000077_5_2 <= 255));
  __CPROVER_assume((sec_r000077_6_1 >= 0) && (sec_r000077_6_1 <= 255));
  __CPROVER_assume((sec_r000077_6_2 >= 0) && (sec_r000077_6_2 <= 255));
  __CPROVER_assume((sec_r000077_7_1 >= 0) && (sec_r000077_7_1 <= 255));
  __CPROVER_assume((sec_r000077_7_2 >= 0) && (sec_r000077_7_2 <= 255));
  __CPROVER_assume((sec_r000077_8_1 >= 0) && (sec_r000077_8_1 <= 255));
  __CPROVER_assume((sec_r000077_8_2 >= 0) && (sec_r000077_8_2 <= 255));
  __CPROVER_assume((sec_r000077_9_1 >= 0) && (sec_r000077_9_1 <= 255));
  __CPROVER_assume((sec_r000077_9_2 >= 0) && (sec_r000077_9_2 <= 255));
  __CPROVER_assume((sec_r000077_10_1 >= 0) && (sec_r000077_10_1 <= 255));
  __CPROVER_assume((sec_r000077_10_2 >= 0) && (sec_r000077_10_2 <= 255));
  __CPROVER_assume((sec_r000077_11_1 >= 0) && (sec_r000077_11_1 <= 255));
  __CPROVER_assume((sec_r000077_11_2 >= 0) && (sec_r000077_11_2 <= 255));
  __CPROVER_assume((sec_r000077_12_1 >= 0) && (sec_r000077_12_1 <= 255));
  __CPROVER_assume((sec_r000077_12_2 >= 0) && (sec_r000077_12_2 <= 255));
  __CPROVER_assume((sec_r000077_13_1 >= 0) && (sec_r000077_13_1 <= 255));
  __CPROVER_assume((sec_r000077_13_2 >= 0) && (sec_r000077_13_2 <= 255));
  __CPROVER_assume((sec_r000077_14_1 >= 0) && (sec_r000077_14_1 <= 255));
  __CPROVER_assume((sec_r000077_14_2 >= 0) && (sec_r000077_14_2 <= 255));
  __CPROVER_assume((sec_r000077_15_1 >= 0) && (sec_r000077_15_1 <= 255));
  __CPROVER_assume((sec_r000077_15_2 >= 0) && (sec_r000077_15_2 <= 255));
  __CPROVER_assume((sec_r000077_16_1 >= 0) && (sec_r000077_16_1 <= 255));
  __CPROVER_assume((sec_r000077_16_2 >= 0) && (sec_r000077_16_2 <= 255));
  __CPROVER_assume((sec_r000077_17_1 >= 0) && (sec_r000077_17_1 <= 255));
  __CPROVER_assume((sec_r000077_17_2 >= 0) && (sec_r000077_17_2 <= 255));
  struct AudioFrame_R000077_7713_0 st_var_0_1 = {0};
  struct AudioFrame_R000077_7713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000077_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000077_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000077_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000077_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000077_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000077_0_2 + 7) & 15;
  struct StreamBuffer_R000077_7713_1 st_var_1_1 = {0};
  struct StreamBuffer_R000077_7713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000077_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000077_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000077_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000077_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000077_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000077_0_2 + 9) & 15;
  union TelemetryField_R000077_7713_0 u_var_1;
  union TelemetryField_R000077_7713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = table_1[0];
  int stage_v_0_2 = table_2[0];
  table_1[0] = (table_1[1] + 1) & 63;
  table_2[0] = (table_2[1] + 1) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (st_var_1_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_1_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = (st_var_0_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_0_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 33)
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
  if (stage_v_7_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 33)
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
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = (st_var_0_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_0_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = (st_var_1_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_1_2.buffer[0] ^ 14) & 3;
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

  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_15_1 = (st_var_1_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_1_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 21) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = (st_var_0_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_0_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = (st_var_1_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_1_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = table_1[1];
  int stage_v_25_2 = table_2[1];
  table_1[1] = (table_1[2] + 51) & 63;
  table_2[1] = (table_2[2] + 51) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 27) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((st_var_0_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_0_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 39)
    {
      chk_sum_1 ^= stage_v_28_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_28_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 39)
    {
      chk_sum_2 ^= stage_v_28_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  int stage_v_30_1 = (st_var_0_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_0_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_32_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_33_1 = table_1[1];
  int stage_v_33_2 = table_2[1];
  table_1[1] = (table_1[2] + 67) & 63;
  table_2[1] = (table_2[2] + 67) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (st_var_0_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_0_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  int stage_v_35_1 = ((st_var_1_1.buffer[2] * 2) + 112) & 63;
  int stage_v_35_2 = ((st_var_1_2.buffer[2] * 2) + 112) & 63;
  if (stage_v_35_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_35_1) - 5) & 255;
    if (stage_v_35_1 > 53)
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
  if (stage_v_35_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_35_2) - 5) & 255;
    if (stage_v_35_2 > 53)
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
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((sec_r000077_1_1 & 1) != 0)
  {
    if ((sec_r000077_4_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000077_13_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000077_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000077_13_1 + 7) & 127;
  }
  if ((sec_r000077_1_2 & 1) != 0)
  {
    if ((sec_r000077_4_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000077_13_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000077_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000077_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000077_6_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000077_4_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000077_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000077_4_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000077_6_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000077_4_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000077_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000077_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((sec_r000077_11_1 & 1) != 0)
  {
    if ((sec_r000077_2_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000077_6_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000077_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000077_6_1 + 7) & 127;
  }
  if ((sec_r000077_11_2 & 1) != 0)
  {
    if ((sec_r000077_2_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000077_6_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000077_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000077_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000077_5_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000077_11_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000077_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000077_11_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000077_5_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000077_11_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000077_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000077_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((sec_r000077_1_1 & 1) != 0)
  {
    if ((sec_r000077_8_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000077_0_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000077_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000077_0_1 + 7) & 127;
  }
  if ((sec_r000077_1_2 & 1) != 0)
  {
    if ((sec_r000077_8_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000077_0_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000077_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000077_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((sec_r000077_6_1 & 1) != 0)
  {
    if ((sec_r000077_1_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000077_4_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000077_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000077_4_1 + 7) & 127;
  }
  if ((sec_r000077_6_2 & 1) != 0)
  {
    if ((sec_r000077_1_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000077_4_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000077_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000077_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((sec_r000077_10_1 & 1) != 0)
  {
    if ((sec_r000077_16_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000077_1_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000077_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000077_1_1 + 7) & 127;
  }
  if ((sec_r000077_10_2 & 1) != 0)
  {
    if ((sec_r000077_16_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000077_1_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000077_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000077_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000077_15_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000077_4_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000077_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000077_4_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000077_15_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000077_4_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000077_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000077_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((sec_r000077_12_1 & 1) != 0)
  {
    if ((sec_r000077_10_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000077_12_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000077_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000077_12_1 + 7) & 127;
  }
  if ((sec_r000077_12_2 & 1) != 0)
  {
    if ((sec_r000077_10_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000077_12_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000077_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000077_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((sec_r000077_0_1 & 1) != 0)
  {
    if ((sec_r000077_17_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000077_1_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000077_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000077_1_1 + 7) & 127;
  }
  if ((sec_r000077_0_2 & 1) != 0)
  {
    if ((sec_r000077_17_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000077_1_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000077_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000077_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((sec_r000077_5_1 & 1) != 0)
  {
    if ((sec_r000077_10_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000077_10_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000077_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000077_10_1 + 7) & 127;
  }
  if ((sec_r000077_5_2 & 1) != 0)
  {
    if ((sec_r000077_10_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000077_10_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000077_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000077_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((sec_r000077_15_1 & 1) != 0)
  {
    if ((sec_r000077_11_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000077_12_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000077_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000077_12_1 + 7) & 127;
  }
  if ((sec_r000077_15_2 & 1) != 0)
  {
    if ((sec_r000077_11_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000077_12_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000077_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000077_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((sec_r000077_17_1 & 1) != 0)
  {
    if ((sec_r000077_1_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000077_16_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000077_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000077_16_1 + 7) & 127;
  }
  if ((sec_r000077_17_2 & 1) != 0)
  {
    if ((sec_r000077_1_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000077_16_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000077_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000077_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000077_17_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000077_9_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000077_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000077_9_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000077_17_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000077_9_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000077_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000077_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((sec_r000077_17_1 & 1) != 0)
  {
    if ((sec_r000077_6_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000077_5_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000077_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000077_5_1 + 7) & 127;
  }
  if ((sec_r000077_17_2 & 1) != 0)
  {
    if ((sec_r000077_6_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000077_5_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000077_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000077_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000077_6_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000077_3_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000077_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000077_3_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000077_6_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000077_3_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000077_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000077_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000077_8_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000077_1_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000077_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000077_1_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000077_8_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000077_1_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000077_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000077_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000077_0_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000077_15_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000077_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000077_15_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000077_0_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000077_15_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000077_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000077_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000077_5_1 & 1) != 0)
  {
    if ((sec_r000077_0_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000077_8_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000077_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000077_8_1 + 7) & 127;
  }
  if ((sec_r000077_5_2 & 1) != 0)
  {
    if ((sec_r000077_0_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000077_8_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000077_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000077_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000077_5_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000077_15_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000077_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000077_15_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000077_5_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000077_15_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000077_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000077_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((sec_r000077_17_1 & 1) != 0)
  {
    if ((sec_r000077_2_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000077_8_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000077_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000077_8_1 + 7) & 127;
  }
  if ((sec_r000077_17_2 & 1) != 0)
  {
    if ((sec_r000077_2_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000077_8_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000077_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000077_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((sec_r000077_10_1 & 1) != 0)
  {
    if ((sec_r000077_10_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000077_0_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000077_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000077_0_1 + 7) & 127;
  }
  if ((sec_r000077_10_2 & 1) != 0)
  {
    if ((sec_r000077_10_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000077_0_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000077_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000077_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000077_5_1 & 1) != 0)
  {
    if ((sec_r000077_3_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000077_0_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000077_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000077_0_1 + 7) & 127;
  }
  if ((sec_r000077_5_2 & 1) != 0)
  {
    if ((sec_r000077_3_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000077_0_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000077_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000077_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000077_13_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000077_8_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000077_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000077_8_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000077_13_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000077_8_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000077_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000077_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000077_6_1 & 1) != 0)
  {
    if ((sec_r000077_9_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000077_8_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000077_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000077_8_1 + 7) & 127;
  }
  if ((sec_r000077_6_2 & 1) != 0)
  {
    if ((sec_r000077_9_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000077_8_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000077_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000077_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000077_10_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000077_14_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000077_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000077_14_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000077_10_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000077_14_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000077_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000077_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000077_7_1 & 1) != 0)
  {
    if ((sec_r000077_1_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000077_8_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000077_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000077_8_1 + 7) & 127;
  }
  if ((sec_r000077_7_2 & 1) != 0)
  {
    if ((sec_r000077_1_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000077_8_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000077_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000077_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((sec_r000077_17_1 & 1) != 0)
  {
    if ((sec_r000077_3_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000077_15_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000077_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000077_15_1 + 7) & 127;
  }
  if ((sec_r000077_17_2 & 1) != 0)
  {
    if ((sec_r000077_3_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000077_15_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000077_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000077_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000077_5_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000077_2_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000077_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000077_2_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000077_5_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000077_2_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000077_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000077_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000077_4_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000077_15_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000077_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000077_15_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000077_4_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000077_15_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000077_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000077_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000077_7_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000077_1_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000077_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000077_1_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000077_7_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000077_1_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000077_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000077_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000077_2_1 & 1) != 0)
  {
    if ((sec_r000077_7_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000077_1_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000077_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000077_1_1 + 7) & 127;
  }
  if ((sec_r000077_2_2 & 1) != 0)
  {
    if ((sec_r000077_7_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000077_1_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000077_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000077_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000077_10_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000077_11_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000077_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000077_11_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000077_10_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000077_11_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000077_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000077_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000077_2_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000077_14_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000077_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000077_14_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000077_2_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000077_14_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000077_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000077_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000077_14_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000077_2_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000077_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000077_2_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000077_14_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000077_2_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000077_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000077_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000077_8_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000077_8_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000077_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000077_8_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000077_8_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000077_8_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000077_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000077_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000077_17_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000077_8_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000077_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000077_8_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000077_17_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000077_8_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000077_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000077_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000077_7_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000077_6_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000077_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000077_6_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000077_7_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000077_6_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000077_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000077_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000077_14_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000077_2_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000077_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000077_2_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000077_14_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000077_2_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000077_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000077_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000077_15_1 & 1) != 0)
  {
    if ((sec_r000077_5_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000077_13_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000077_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000077_13_1 + 7) & 127;
  }
  if ((sec_r000077_15_2 & 1) != 0)
  {
    if ((sec_r000077_5_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000077_13_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000077_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000077_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000077_5_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000077_12_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000077_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000077_12_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000077_5_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000077_12_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000077_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000077_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000077_11_1 & 1) != 0)
  {
    if ((sec_r000077_15_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000077_8_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000077_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000077_8_1 + 7) & 127;
  }
  if ((sec_r000077_11_2 & 1) != 0)
  {
    if ((sec_r000077_15_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000077_8_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000077_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000077_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000077_5_1 & 1) != 0)
  {
    if ((sec_r000077_2_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000077_3_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000077_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000077_3_1 + 7) & 127;
  }
  if ((sec_r000077_5_2 & 1) != 0)
  {
    if ((sec_r000077_2_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000077_3_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000077_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000077_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000077_6_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000077_12_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000077_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000077_12_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000077_6_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000077_12_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000077_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000077_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000077_1_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000077_6_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000077_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000077_6_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000077_1_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000077_6_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000077_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000077_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000077_7_1 & 1) != 0)
  {
    if ((sec_r000077_6_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000077_12_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000077_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000077_12_1 + 7) & 127;
  }
  if ((sec_r000077_7_2 & 1) != 0)
  {
    if ((sec_r000077_6_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000077_12_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000077_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000077_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000077_3_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000077_9_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000077_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000077_9_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000077_3_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000077_9_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000077_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000077_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000077_7_1 & 1) != 0)
  {
    if ((sec_r000077_14_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000077_1_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000077_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000077_1_1 + 7) & 127;
  }
  if ((sec_r000077_7_2 & 1) != 0)
  {
    if ((sec_r000077_14_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000077_1_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000077_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000077_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000077_3_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000077_15_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000077_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000077_15_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000077_3_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000077_15_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000077_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000077_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000077_13_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000077_10_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000077_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000077_10_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000077_13_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000077_10_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000077_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000077_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000077_17_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000077_16_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000077_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000077_16_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000077_17_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000077_16_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000077_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000077_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000077_9_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000077_11_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000077_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000077_11_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000077_9_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000077_11_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000077_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000077_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000077_15_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000077_11_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000077_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000077_11_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000077_15_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000077_11_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000077_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000077_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000077_10_1 & 1) != 0)
  {
    if ((sec_r000077_13_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000077_13_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000077_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000077_13_1 + 7) & 127;
  }
  if ((sec_r000077_10_2 & 1) != 0)
  {
    if ((sec_r000077_13_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000077_13_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000077_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000077_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000077_5_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000077_8_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000077_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000077_8_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000077_5_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000077_8_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000077_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000077_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000077_0_1 & 1) != 0)
  {
    if ((sec_r000077_0_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000077_2_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000077_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000077_2_1 + 7) & 127;
  }
  if ((sec_r000077_0_2 & 1) != 0)
  {
    if ((sec_r000077_0_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000077_2_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000077_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000077_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000077_7_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000077_1_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000077_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000077_1_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000077_7_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000077_1_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000077_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000077_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000077_12_1 & 1) != 0)
  {
    if ((sec_r000077_15_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000077_10_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000077_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000077_10_1 + 7) & 127;
  }
  if ((sec_r000077_12_2 & 1) != 0)
  {
    if ((sec_r000077_15_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000077_10_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000077_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000077_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000077_12_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000077_16_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000077_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000077_16_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000077_12_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000077_16_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000077_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000077_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000077_0_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000077_13_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000077_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000077_13_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000077_0_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000077_13_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000077_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000077_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000077_1_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000077_12_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000077_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000077_12_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000077_1_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000077_12_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000077_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000077_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000077_11_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000077_1_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000077_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000077_1_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000077_11_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000077_1_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000077_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000077_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000077_8_1 & 1) != 0)
  {
    if ((sec_r000077_1_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000077_2_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000077_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000077_2_1 + 7) & 127;
  }
  if ((sec_r000077_8_2 & 1) != 0)
  {
    if ((sec_r000077_1_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000077_2_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000077_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000077_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000077_2_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000077_4_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000077_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000077_4_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000077_2_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000077_4_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000077_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000077_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000077_5_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000077_6_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000077_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000077_6_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000077_5_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000077_6_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000077_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000077_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000077_17_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000077_1_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000077_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000077_1_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000077_17_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000077_1_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000077_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000077_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000077_1_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000077_1_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000077_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000077_1_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000077_1_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000077_1_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000077_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000077_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000077_6_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000077_16_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000077_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000077_16_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000077_6_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000077_16_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000077_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000077_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000077_12_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000077_14_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000077_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000077_14_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000077_12_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000077_14_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000077_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000077_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000077_15_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000077_13_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000077_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000077_13_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000077_15_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000077_13_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000077_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000077_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000077_7_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000077_4_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000077_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000077_4_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000077_7_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000077_4_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000077_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000077_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000077_7_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000077_9_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000077_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000077_9_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000077_7_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000077_9_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000077_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000077_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000077_11_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000077_10_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000077_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000077_10_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000077_11_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000077_10_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000077_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000077_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000077_14_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000077_7_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000077_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000077_7_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000077_14_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000077_7_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000077_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000077_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000077_15_1 & 1) != 0)
  {
    if ((sec_r000077_12_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000077_6_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000077_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000077_6_1 + 7) & 127;
  }
  if ((sec_r000077_15_2 & 1) != 0)
  {
    if ((sec_r000077_12_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000077_6_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000077_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000077_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000077_7_1 & 1) != 0)
  {
    if ((sec_r000077_1_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000077_12_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000077_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000077_12_1 + 7) & 127;
  }
  if ((sec_r000077_7_2 & 1) != 0)
  {
    if ((sec_r000077_1_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000077_12_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000077_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000077_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000077_8_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000077_8_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000077_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000077_8_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000077_8_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000077_8_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000077_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000077_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000077_15_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000077_8_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000077_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000077_8_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000077_15_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000077_8_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000077_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000077_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000077_12_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000077_5_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000077_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000077_5_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000077_12_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000077_5_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000077_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000077_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000077_14_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000077_12_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000077_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000077_12_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000077_14_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000077_12_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000077_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000077_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000077_16_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000077_5_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000077_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000077_5_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000077_16_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000077_5_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000077_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000077_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000077_1_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000077_11_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000077_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000077_11_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000077_1_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000077_11_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000077_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000077_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000077_10_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000077_10_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000077_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000077_10_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000077_10_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000077_10_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000077_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000077_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000077_2_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000077_14_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000077_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000077_14_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000077_2_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000077_14_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000077_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000077_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000077_12_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000077_8_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000077_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000077_8_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000077_12_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000077_8_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000077_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000077_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000077_17_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000077_11_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000077_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000077_11_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000077_17_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000077_11_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000077_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000077_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000077_3_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000077_12_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000077_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000077_12_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000077_3_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000077_12_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000077_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000077_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000077_3_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000077_12_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000077_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000077_12_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000077_3_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000077_12_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000077_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000077_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000077_16_1 & 1) != 0)
  {
    if ((sec_r000077_7_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000077_7_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000077_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000077_7_1 + 7) & 127;
  }
  if ((sec_r000077_16_2 & 1) != 0)
  {
    if ((sec_r000077_7_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000077_7_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000077_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000077_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000077_6_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000077_11_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000077_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000077_11_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000077_6_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000077_11_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000077_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000077_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000077_14_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000077_11_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000077_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000077_11_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000077_14_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000077_11_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000077_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000077_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((sec_r000077_7_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000077_6_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000077_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000077_6_1 + 7) & 127;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((sec_r000077_7_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000077_6_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000077_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000077_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000077_12_1 & 1) != 0)
  {
    if ((sec_r000077_12_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000077_5_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000077_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000077_5_1 + 7) & 127;
  }
  if ((sec_r000077_12_2 & 1) != 0)
  {
    if ((sec_r000077_12_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000077_5_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000077_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000077_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000077_5_1 != sec_r000077_5_2);
  __CPROVER_assume(sec_r000077_1_1 != sec_r000077_1_2);
  __CPROVER_assume(sec_r000077_13_1 != sec_r000077_13_2);
  __CPROVER_assume(sec_r000077_7_1 != sec_r000077_7_2);
  __CPROVER_assume(pub_r000077_12_1 == pub_r000077_12_2);
  __CPROVER_assume(pub_r000077_9_1 == pub_r000077_9_2);
  __CPROVER_assume(sec_r000077_3_1 != sec_r000077_3_2);
  __CPROVER_assume(pub_r000077_16_1 == pub_r000077_16_2);
  __CPROVER_assume(pub_r000077_15_1 == pub_r000077_15_2);
  __CPROVER_assume(pub_r000077_4_1 == pub_r000077_4_2);
  __CPROVER_assume(sec_r000077_0_1 != sec_r000077_0_2);
  __CPROVER_assume(pub_r000077_1_1 == pub_r000077_1_2);
  __CPROVER_assume(sec_r000077_2_1 != sec_r000077_2_2);
  __CPROVER_assume(pub_r000077_6_1 == pub_r000077_6_2);
  __CPROVER_assume(pub_r000077_7_1 == pub_r000077_7_2);
  __CPROVER_assume(sec_r000077_16_1 != sec_r000077_16_2);
  __CPROVER_assume(sec_r000077_10_1 != sec_r000077_10_2);
  __CPROVER_assume(pub_r000077_10_1 == pub_r000077_10_2);
  __CPROVER_assume(sec_r000077_14_1 != sec_r000077_14_2);
  __CPROVER_assume(sec_r000077_4_1 != sec_r000077_4_2);
  __CPROVER_assume(sec_r000077_17_1 != sec_r000077_17_2);
  __CPROVER_assume(sec_r000077_9_1 != sec_r000077_9_2);
  __CPROVER_assume(pub_r000077_13_1 == pub_r000077_13_2);
  __CPROVER_assume(sec_r000077_15_1 != sec_r000077_15_2);
  __CPROVER_assume(pub_r000077_2_1 == pub_r000077_2_2);
  __CPROVER_assume(pub_r000077_0_1 == pub_r000077_0_2);
  __CPROVER_assume(pub_r000077_5_1 == pub_r000077_5_2);
  __CPROVER_assume(pub_r000077_8_1 == pub_r000077_8_2);
  __CPROVER_assume(pub_r000077_14_1 == pub_r000077_14_2);
  __CPROVER_assume(pub_r000077_3_1 == pub_r000077_3_2);
  __CPROVER_assume(sec_r000077_12_1 != sec_r000077_12_2);
  __CPROVER_assume(sec_r000077_11_1 != sec_r000077_11_2);
  __CPROVER_assume(sec_r000077_6_1 != sec_r000077_6_2);
  __CPROVER_assume(sec_r000077_8_1 != sec_r000077_8_2);
  __CPROVER_assume(pub_r000077_11_1 == pub_r000077_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.state == st_var_1_2.state);
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
}


