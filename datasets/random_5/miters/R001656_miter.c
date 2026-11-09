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
struct SensorNode_R001656_5613_0
{
  short gain;
  int calib;
  short reading;
  int buffer[3];
};
struct CipherContext_R001656_5613_1
{
  int iv;
  int flags;
  short tag;
  int counter;
  int buffer[3];
};
union PacketPayload_R001656_5613_0
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
void fn_R001656_5613_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st_1 = {0};
  struct CipherContext_R001656_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int window_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_18_1) & 63;
  aux_2 = (aux_2 + window_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_16_1 = 0;
  int sample_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_16_1 = ((sample_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_16_2 = ((sample_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_16_1) & 127;
    acc_2 = (acc_2 + sample_16_2) & 127;
  }

  int accumulator_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_90_1)
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

  switch (accumulator_90_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_18_1 == window_18_2);
  assert(sample_16_1 == sample_16_2);
  assert(accumulator_90_1 == accumulator_90_2);
}

int fn_R001656_5613_0(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int window_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_18) & 63;
  acc ^= aux;
  int sample_16 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_16 = ((sample_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_16) & 127;
  }

  int accumulator_90 = (aux + st.buffer[1]) & 3;
  switch (accumulator_90)
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

void fn_R001656_5613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st_1 = {0};
  struct CipherContext_R001656_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_57_1 > 27)
  {
    acc_1 = ((acc_1 + (accumulator_57_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_57_2 > 27)
  {
    acc_2 = ((acc_2 + (accumulator_57_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_57_1) & 63;
  aux_2 = (aux_2 + threshold_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_57_1 == accumulator_57_2);
  assert(threshold_57_1 == threshold_57_2);
}

int fn_R001656_5613_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_57 > 27)
  {
    acc = ((acc + (accumulator_57 * 2)) + 5) & 127;
    aux ^= accumulator_57 & 15;
  }
  else
  {
    acc = ((acc - accumulator_57) + 11) & 127;
    aux += 3;
  }
  int threshold_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001656_5613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st_1 = {0};
  struct CipherContext_R001656_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int metric_83_1 = 0;
  int metric_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_83_1 = ((metric_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_83_2 = ((metric_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_83_1) & 127;
    acc_2 = (acc_2 + metric_83_2) & 127;
  }

  int parity_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_27_1)
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

  switch (parity_27_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_83_1 == metric_83_2);
  assert(parity_27_1 == parity_27_2);
}

int fn_R001656_5613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int metric_83 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_83 = ((metric_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_83) & 127;
  }

  int parity_27 = (aux + st.buffer[1]) & 3;
  switch (parity_27)
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

void fn_R001656_5613_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st_1 = {0};
  struct CipherContext_R001656_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_93_1 > 42)
  {
    acc_1 = ((acc_1 + (segment_93_1 * 2)) + 5) & 127;
    aux_1 ^= segment_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_93_2 > 42)
  {
    acc_2 = ((acc_2 + (segment_93_2 * 2)) + 5) & 127;
    aux_2 ^= segment_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_93_1 == segment_93_2);
}

int fn_R001656_5613_3(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_93 > 42)
  {
    acc = ((acc + (segment_93 * 2)) + 5) & 127;
    aux ^= segment_93 & 15;
  }
  else
  {
    acc = ((acc - segment_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001656_5613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st_1 = {0};
  struct SensorNode_R001656_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int weight_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_75_1) & 63;
  aux_2 = (aux_2 + weight_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_42_1)
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

  switch (metric_42_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_75_1 == weight_75_2);
  assert(metric_42_1 == metric_42_2);
}

int fn_R001656_5613_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int weight_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_75) & 63;
  acc ^= aux;
  int metric_42 = (aux + st.buffer[1]) & 3;
  switch (metric_42)
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

void fn_R001656_5613_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st_1 = {0};
  struct SensorNode_R001656_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int accumulator_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_10_1 > 48)
  {
    acc_1 = ((acc_1 + (accumulator_10_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_10_2 > 48)
  {
    acc_2 = ((acc_2 + (accumulator_10_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_76_1 = local_arr_1[aux_1 % 3];
  int quantum_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_76_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_10_1 == accumulator_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_76_1 == quantum_76_2);
}

int fn_R001656_5613_5(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int accumulator_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_10 > 48)
  {
    acc = ((acc + (accumulator_10 * 2)) + 5) & 127;
    aux ^= accumulator_10 & 15;
  }
  else
  {
    acc = ((acc - accumulator_10) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_76 = local_arr[aux % 3];
  acc = (acc + (quantum_76 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001656_5613_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st_1 = {0};
  struct SensorNode_R001656_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_16_1 = local_arr_1[aux_1 % 3];
  int checksum_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_16_2 * 2)) & 127;
  int segment_71_1 = 0;
  int segment_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_71_1 = ((segment_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_71_2 = ((segment_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_71_1) & 127;
    acc_2 = (acc_2 + segment_71_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_16_1 == checksum_16_2);
  assert(segment_71_1 == segment_71_2);
}

int fn_R001656_5613_6(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int checksum_16 = local_arr[aux % 3];
  acc = (acc + (checksum_16 * 2)) & 127;
  int segment_71 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_71 = ((segment_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_71) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001656_5613_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st_1 = {0};
  struct SensorNode_R001656_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int residue_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_85_1 > 42)
  {
    acc_1 = ((acc_1 + (residue_85_1 * 2)) + 5) & 127;
    aux_1 ^= residue_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_85_2 > 42)
  {
    acc_2 = ((acc_2 + (residue_85_2 * 2)) + 5) & 127;
    aux_2 ^= residue_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_85_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_12_1)
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

  switch (quotient_12_2)
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
  int phase_62_1 = local_arr_1[aux_1 % 3];
  int phase_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_62_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_85_1 == residue_85_2);
  assert(quotient_12_1 == quotient_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_62_1 == phase_62_2);
}

int fn_R001656_5613_7(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int residue_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_85 > 42)
  {
    acc = ((acc + (residue_85 * 2)) + 5) & 127;
    aux ^= residue_85 & 15;
  }
  else
  {
    acc = ((acc - residue_85) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_12 = (aux + st.buffer[1]) & 3;
  switch (quotient_12)
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
  int phase_62 = local_arr[aux % 3];
  acc = (acc + (phase_62 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001656_5613_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st_1 = {0};
  struct CipherContext_R001656_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_72_1 = local_arr_1[aux_1 % 3];
  int bound_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_72_2 * 2)) & 127;
  int quantum_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_85_1 > 15)
  {
    acc_1 = ((acc_1 + (quantum_85_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_85_2 > 15)
  {
    acc_2 = ((acc_2 + (quantum_85_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_85_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_86_1 = 0;
  int pivot_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_86_1 = ((pivot_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_86_2 = ((pivot_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_86_1) & 127;
    acc_2 = (acc_2 + pivot_86_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_72_1 == bound_72_2);
  assert(quantum_85_1 == quantum_85_2);
  assert(pivot_86_1 == pivot_86_2);
}

int fn_R001656_5613_8(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int bound_72 = local_arr[aux % 3];
  acc = (acc + (bound_72 * 2)) & 127;
  int quantum_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_85 > 15)
  {
    acc = ((acc + (quantum_85 * 2)) + 5) & 127;
    aux ^= quantum_85 & 15;
  }
  else
  {
    acc = ((acc - quantum_85) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_86 = ((pivot_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_86) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001656_5613_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st_1 = {0};
  struct SensorNode_R001656_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_93_1 = local_arr_1[aux_1 % 3];
  int sample_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_93_2 * 2)) & 127;
  int index_reg_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_23_1) & 63;
  aux_2 = (aux_2 + index_reg_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_87_1 > 49)
  {
    acc_1 = ((acc_1 + (segment_87_1 * 2)) + 5) & 127;
    aux_1 ^= segment_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_87_2 > 49)
  {
    acc_2 = ((acc_2 + (segment_87_2 * 2)) + 5) & 127;
    aux_2 ^= segment_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_87_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_93_1 == sample_93_2);
  assert(index_reg_23_1 == index_reg_23_2);
  assert(segment_87_1 == segment_87_2);
}

int fn_R001656_5613_9(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int sample_93 = local_arr[aux % 3];
  acc = (acc + (sample_93 * 2)) & 127;
  int index_reg_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_23) & 63;
  acc ^= aux;
  int segment_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_87 > 49)
  {
    acc = ((acc + (segment_87 * 2)) + 5) & 127;
    aux ^= segment_87 & 15;
  }
  else
  {
    acc = ((acc - segment_87) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001656_5613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st_1 = {0};
  struct SensorNode_R001656_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int window_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_40_1)
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

  switch (window_40_2)
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

  int coefficient_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_44_1) & 63;
  aux_2 = (aux_2 + coefficient_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_40_1 == window_40_2);
  assert(coefficient_44_1 == coefficient_44_2);
}

int fn_R001656_5613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int window_40 = (aux + st.buffer[1]) & 3;
  switch (window_40)
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

  int coefficient_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001656_5613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st_1 = {0};
  struct CipherContext_R001656_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int checksum_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_51_1 > 43)
  {
    acc_1 = ((acc_1 + (checksum_51_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_51_2 > 43)
  {
    acc_2 = ((acc_2 + (checksum_51_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_89_1) & 63;
  aux_2 = (aux_2 + delta_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_20_1)
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

  switch (quantum_20_2)
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

  int parity_44_1 = 0;
  int parity_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_44_1 = ((parity_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_44_2 = ((parity_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_44_1) & 127;
    acc_2 = (acc_2 + parity_44_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_51_1 == checksum_51_2);
  assert(delta_89_1 == delta_89_2);
  assert(quantum_20_1 == quantum_20_2);
  assert(parity_44_1 == parity_44_2);
}

int fn_R001656_5613_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int checksum_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_51 > 43)
  {
    acc = ((acc + (checksum_51 * 2)) + 5) & 127;
    aux ^= checksum_51 & 15;
  }
  else
  {
    acc = ((acc - checksum_51) + 11) & 127;
    aux += 3;
  }
  int delta_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_89) & 63;
  acc ^= aux;
  int quantum_20 = (aux + st.buffer[1]) & 3;
  switch (quantum_20)
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

  int parity_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_44 = ((parity_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_44) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001656_5613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st_1 = {0};
  struct SensorNode_R001656_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int anchor_45_1 = 0;
  int anchor_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_45_1 = ((anchor_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_45_2 = ((anchor_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_45_1) & 127;
    acc_2 = (acc_2 + anchor_45_2) & 127;
  }

  int tally_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_83_1 > 15)
  {
    acc_1 = ((acc_1 + (tally_83_1 * 2)) + 5) & 127;
    aux_1 ^= tally_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_83_2 > 15)
  {
    acc_2 = ((acc_2 + (tally_83_2 * 2)) + 5) & 127;
    aux_2 ^= tally_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_83_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_45_1 == anchor_45_2);
  assert(tally_83_1 == tally_83_2);
}

int fn_R001656_5613_12(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001656_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int anchor_45 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_45 = ((anchor_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_45) & 127;
  }

  int tally_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_83 > 15)
  {
    acc = ((acc + (tally_83 * 2)) + 5) & 127;
    aux ^= tally_83 & 15;
  }
  else
  {
    acc = ((acc - tally_83) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001656_5613_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st_1 = {0};
  struct CipherContext_R001656_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int tracker_20_1 = 0;
  int tracker_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_20_1 = ((tracker_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_20_2 = ((tracker_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_20_1) & 127;
    acc_2 = (acc_2 + tracker_20_2) & 127;
  }

  int parity_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_78_1)
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

  switch (parity_78_2)
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

  int vector_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_78_1 > 26)
  {
    acc_1 = ((acc_1 + (vector_78_1 * 2)) + 5) & 127;
    aux_1 ^= vector_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_78_2 > 26)
  {
    acc_2 = ((acc_2 + (vector_78_2 * 2)) + 5) & 127;
    aux_2 ^= vector_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_10_1 = local_arr_1[aux_1 % 3];
  int tally_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_10_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_20_1 == tracker_20_2);
  assert(parity_78_1 == parity_78_2);
  assert(vector_78_1 == vector_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_10_1 == tally_10_2);
}

int fn_R001656_5613_13(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001656_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int tracker_20 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_20 = ((tracker_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_20) & 127;
  }

  int parity_78 = (aux + st.buffer[1]) & 3;
  switch (parity_78)
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

  int vector_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_78 > 26)
  {
    acc = ((acc + (vector_78 * 2)) + 5) & 127;
    aux ^= vector_78 & 15;
  }
  else
  {
    acc = ((acc - vector_78) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_10 = local_arr[aux % 3];
  acc = (acc + (tally_10 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001656_0_1;
  int sec_r001656_0_2;
  int sec_r001656_1_1;
  int sec_r001656_1_2;
  int sec_r001656_2_1;
  int sec_r001656_2_2;
  int sec_r001656_3_1;
  int sec_r001656_3_2;
  int sec_r001656_4_1;
  int sec_r001656_4_2;
  int sec_r001656_5_1;
  int sec_r001656_5_2;
  int sec_r001656_6_1;
  int sec_r001656_6_2;
  int sec_r001656_7_1;
  int sec_r001656_7_2;
  int sec_r001656_8_1;
  int sec_r001656_8_2;
  int sec_r001656_9_1;
  int sec_r001656_9_2;
  int sec_r001656_10_1;
  int sec_r001656_10_2;
  int sec_r001656_11_1;
  int sec_r001656_11_2;
  int sec_r001656_12_1;
  int sec_r001656_12_2;
  int sec_r001656_13_1;
  int sec_r001656_13_2;
  int sec_r001656_14_1;
  int sec_r001656_14_2;
  int sec_r001656_15_1;
  int sec_r001656_15_2;
  int sec_r001656_16_1;
  int sec_r001656_16_2;
  int sec_r001656_17_1;
  int sec_r001656_17_2;
  int sec_r001656_18_1;
  int sec_r001656_18_2;
  int sec_r001656_19_1;
  int sec_r001656_19_2;
  int sec_r001656_20_1;
  int sec_r001656_20_2;
  int pub_r001656_0_1;
  int pub_r001656_0_2;
  int pub_r001656_1_1;
  int pub_r001656_1_2;
  int pub_r001656_2_1;
  int pub_r001656_2_2;
  int pub_r001656_3_1;
  int pub_r001656_3_2;
  int pub_r001656_4_1;
  int pub_r001656_4_2;
  int pub_r001656_5_1;
  int pub_r001656_5_2;
  int pub_r001656_6_1;
  int pub_r001656_6_2;
  int pub_r001656_7_1;
  int pub_r001656_7_2;
  int pub_r001656_8_1;
  int pub_r001656_8_2;
  int pub_r001656_9_1;
  int pub_r001656_9_2;
  int pub_r001656_10_1;
  int pub_r001656_10_2;
  int pub_r001656_11_1;
  int pub_r001656_11_2;
  int pub_r001656_12_1;
  int pub_r001656_12_2;
  int pub_r001656_13_1;
  int pub_r001656_13_2;
  int pub_r001656_14_1;
  int pub_r001656_14_2;
  int pub_r001656_15_1;
  int pub_r001656_15_2;
  int pub_r001656_16_1;
  int pub_r001656_16_2;
  int pub_r001656_17_1;
  int pub_r001656_17_2;
  int pub_r001656_18_1;
  int pub_r001656_18_2;
  int pub_r001656_19_1;
  int pub_r001656_19_2;
  int pub_r001656_20_1;
  int pub_r001656_20_2;
  int pub_r001656_21_1;
  int pub_r001656_21_2;
  int pub_r001656_22_1;
  int pub_r001656_22_2;
  int pub_r001656_23_1;
  int pub_r001656_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001656_0_1 >= (-100)) && (pub_r001656_0_1 <= 100));
  __CPROVER_assume((pub_r001656_0_2 >= (-100)) && (pub_r001656_0_2 <= 100));
  __CPROVER_assume((pub_r001656_1_1 >= (-100)) && (pub_r001656_1_1 <= 100));
  __CPROVER_assume((pub_r001656_1_2 >= (-100)) && (pub_r001656_1_2 <= 100));
  __CPROVER_assume((pub_r001656_2_1 >= (-100)) && (pub_r001656_2_1 <= 100));
  __CPROVER_assume((pub_r001656_2_2 >= (-100)) && (pub_r001656_2_2 <= 100));
  __CPROVER_assume((pub_r001656_3_1 >= (-100)) && (pub_r001656_3_1 <= 100));
  __CPROVER_assume((pub_r001656_3_2 >= (-100)) && (pub_r001656_3_2 <= 100));
  __CPROVER_assume((pub_r001656_4_1 >= (-100)) && (pub_r001656_4_1 <= 100));
  __CPROVER_assume((pub_r001656_4_2 >= (-100)) && (pub_r001656_4_2 <= 100));
  __CPROVER_assume((pub_r001656_5_1 >= (-100)) && (pub_r001656_5_1 <= 100));
  __CPROVER_assume((pub_r001656_5_2 >= (-100)) && (pub_r001656_5_2 <= 100));
  __CPROVER_assume((pub_r001656_6_1 >= (-100)) && (pub_r001656_6_1 <= 100));
  __CPROVER_assume((pub_r001656_6_2 >= (-100)) && (pub_r001656_6_2 <= 100));
  __CPROVER_assume((pub_r001656_7_1 >= (-100)) && (pub_r001656_7_1 <= 100));
  __CPROVER_assume((pub_r001656_7_2 >= (-100)) && (pub_r001656_7_2 <= 100));
  __CPROVER_assume((pub_r001656_8_1 >= (-100)) && (pub_r001656_8_1 <= 100));
  __CPROVER_assume((pub_r001656_8_2 >= (-100)) && (pub_r001656_8_2 <= 100));
  __CPROVER_assume((pub_r001656_9_1 >= (-100)) && (pub_r001656_9_1 <= 100));
  __CPROVER_assume((pub_r001656_9_2 >= (-100)) && (pub_r001656_9_2 <= 100));
  __CPROVER_assume((pub_r001656_10_1 >= (-100)) && (pub_r001656_10_1 <= 100));
  __CPROVER_assume((pub_r001656_10_2 >= (-100)) && (pub_r001656_10_2 <= 100));
  __CPROVER_assume((pub_r001656_11_1 >= (-100)) && (pub_r001656_11_1 <= 100));
  __CPROVER_assume((pub_r001656_11_2 >= (-100)) && (pub_r001656_11_2 <= 100));
  __CPROVER_assume((pub_r001656_12_1 >= (-100)) && (pub_r001656_12_1 <= 100));
  __CPROVER_assume((pub_r001656_12_2 >= (-100)) && (pub_r001656_12_2 <= 100));
  __CPROVER_assume((pub_r001656_13_1 >= (-100)) && (pub_r001656_13_1 <= 100));
  __CPROVER_assume((pub_r001656_13_2 >= (-100)) && (pub_r001656_13_2 <= 100));
  __CPROVER_assume((pub_r001656_14_1 >= (-100)) && (pub_r001656_14_1 <= 100));
  __CPROVER_assume((pub_r001656_14_2 >= (-100)) && (pub_r001656_14_2 <= 100));
  __CPROVER_assume((pub_r001656_15_1 >= (-100)) && (pub_r001656_15_1 <= 100));
  __CPROVER_assume((pub_r001656_15_2 >= (-100)) && (pub_r001656_15_2 <= 100));
  __CPROVER_assume((pub_r001656_16_1 >= (-100)) && (pub_r001656_16_1 <= 100));
  __CPROVER_assume((pub_r001656_16_2 >= (-100)) && (pub_r001656_16_2 <= 100));
  __CPROVER_assume((pub_r001656_17_1 >= (-100)) && (pub_r001656_17_1 <= 100));
  __CPROVER_assume((pub_r001656_17_2 >= (-100)) && (pub_r001656_17_2 <= 100));
  __CPROVER_assume((pub_r001656_18_1 >= (-100)) && (pub_r001656_18_1 <= 100));
  __CPROVER_assume((pub_r001656_18_2 >= (-100)) && (pub_r001656_18_2 <= 100));
  __CPROVER_assume((pub_r001656_19_1 >= (-100)) && (pub_r001656_19_1 <= 100));
  __CPROVER_assume((pub_r001656_19_2 >= (-100)) && (pub_r001656_19_2 <= 100));
  __CPROVER_assume((pub_r001656_20_1 >= (-100)) && (pub_r001656_20_1 <= 100));
  __CPROVER_assume((pub_r001656_20_2 >= (-100)) && (pub_r001656_20_2 <= 100));
  __CPROVER_assume((pub_r001656_21_1 >= (-100)) && (pub_r001656_21_1 <= 100));
  __CPROVER_assume((pub_r001656_21_2 >= (-100)) && (pub_r001656_21_2 <= 100));
  __CPROVER_assume((pub_r001656_22_1 >= (-100)) && (pub_r001656_22_1 <= 100));
  __CPROVER_assume((pub_r001656_22_2 >= (-100)) && (pub_r001656_22_2 <= 100));
  __CPROVER_assume((pub_r001656_23_1 >= (-100)) && (pub_r001656_23_1 <= 100));
  __CPROVER_assume((pub_r001656_23_2 >= (-100)) && (pub_r001656_23_2 <= 100));
  __CPROVER_assume((sec_r001656_0_1 >= 0) && (sec_r001656_0_1 <= 255));
  __CPROVER_assume((sec_r001656_0_2 >= 0) && (sec_r001656_0_2 <= 255));
  __CPROVER_assume((sec_r001656_1_1 >= 0) && (sec_r001656_1_1 <= 255));
  __CPROVER_assume((sec_r001656_1_2 >= 0) && (sec_r001656_1_2 <= 255));
  __CPROVER_assume((sec_r001656_2_1 >= 0) && (sec_r001656_2_1 <= 255));
  __CPROVER_assume((sec_r001656_2_2 >= 0) && (sec_r001656_2_2 <= 255));
  __CPROVER_assume((sec_r001656_3_1 >= 0) && (sec_r001656_3_1 <= 255));
  __CPROVER_assume((sec_r001656_3_2 >= 0) && (sec_r001656_3_2 <= 255));
  __CPROVER_assume((sec_r001656_4_1 >= 0) && (sec_r001656_4_1 <= 255));
  __CPROVER_assume((sec_r001656_4_2 >= 0) && (sec_r001656_4_2 <= 255));
  __CPROVER_assume((sec_r001656_5_1 >= 0) && (sec_r001656_5_1 <= 255));
  __CPROVER_assume((sec_r001656_5_2 >= 0) && (sec_r001656_5_2 <= 255));
  __CPROVER_assume((sec_r001656_6_1 >= 0) && (sec_r001656_6_1 <= 255));
  __CPROVER_assume((sec_r001656_6_2 >= 0) && (sec_r001656_6_2 <= 255));
  __CPROVER_assume((sec_r001656_7_1 >= 0) && (sec_r001656_7_1 <= 255));
  __CPROVER_assume((sec_r001656_7_2 >= 0) && (sec_r001656_7_2 <= 255));
  __CPROVER_assume((sec_r001656_8_1 >= 0) && (sec_r001656_8_1 <= 255));
  __CPROVER_assume((sec_r001656_8_2 >= 0) && (sec_r001656_8_2 <= 255));
  __CPROVER_assume((sec_r001656_9_1 >= 0) && (sec_r001656_9_1 <= 255));
  __CPROVER_assume((sec_r001656_9_2 >= 0) && (sec_r001656_9_2 <= 255));
  __CPROVER_assume((sec_r001656_10_1 >= 0) && (sec_r001656_10_1 <= 255));
  __CPROVER_assume((sec_r001656_10_2 >= 0) && (sec_r001656_10_2 <= 255));
  __CPROVER_assume((sec_r001656_11_1 >= 0) && (sec_r001656_11_1 <= 255));
  __CPROVER_assume((sec_r001656_11_2 >= 0) && (sec_r001656_11_2 <= 255));
  __CPROVER_assume((sec_r001656_12_1 >= 0) && (sec_r001656_12_1 <= 255));
  __CPROVER_assume((sec_r001656_12_2 >= 0) && (sec_r001656_12_2 <= 255));
  __CPROVER_assume((sec_r001656_13_1 >= 0) && (sec_r001656_13_1 <= 255));
  __CPROVER_assume((sec_r001656_13_2 >= 0) && (sec_r001656_13_2 <= 255));
  __CPROVER_assume((sec_r001656_14_1 >= 0) && (sec_r001656_14_1 <= 255));
  __CPROVER_assume((sec_r001656_14_2 >= 0) && (sec_r001656_14_2 <= 255));
  __CPROVER_assume((sec_r001656_15_1 >= 0) && (sec_r001656_15_1 <= 255));
  __CPROVER_assume((sec_r001656_15_2 >= 0) && (sec_r001656_15_2 <= 255));
  __CPROVER_assume((sec_r001656_16_1 >= 0) && (sec_r001656_16_1 <= 255));
  __CPROVER_assume((sec_r001656_16_2 >= 0) && (sec_r001656_16_2 <= 255));
  __CPROVER_assume((sec_r001656_17_1 >= 0) && (sec_r001656_17_1 <= 255));
  __CPROVER_assume((sec_r001656_17_2 >= 0) && (sec_r001656_17_2 <= 255));
  __CPROVER_assume((sec_r001656_18_1 >= 0) && (sec_r001656_18_1 <= 255));
  __CPROVER_assume((sec_r001656_18_2 >= 0) && (sec_r001656_18_2 <= 255));
  __CPROVER_assume((sec_r001656_19_1 >= 0) && (sec_r001656_19_1 <= 255));
  __CPROVER_assume((sec_r001656_19_2 >= 0) && (sec_r001656_19_2 <= 255));
  __CPROVER_assume((sec_r001656_20_1 >= 0) && (sec_r001656_20_1 <= 255));
  __CPROVER_assume((sec_r001656_20_2 >= 0) && (sec_r001656_20_2 <= 255));
  struct SensorNode_R001656_5613_0 st_var_0_1 = {0};
  struct SensorNode_R001656_5613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001656_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001656_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001656_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001656_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001656_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001656_0_2 + 7) & 15;
  struct CipherContext_R001656_5613_1 st_var_1_1 = {0};
  struct CipherContext_R001656_5613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001656_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001656_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001656_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001656_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001656_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001656_0_2 + 9) & 15;
  union PacketPayload_R001656_5613_0 u_var_1;
  union PacketPayload_R001656_5613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001656_5613_0(sec_r001656_0_1, sec_r001656_1_1, pub_r001656_2_1);
  int helper_flow_0_2 = fn_R001656_5613_0(sec_r001656_0_2, sec_r001656_1_2, pub_r001656_2_2);
  fn_R001656_5613_0_2(sec_r001656_0_1, sec_r001656_1_1, pub_r001656_2_1, sec_r001656_0_2, sec_r001656_1_2, pub_r001656_2_2);
  int helper_flow_1_1 = fn_R001656_5613_1(sec_r001656_1_1, pub_r001656_2_1, pub_r001656_3_1, pub_r001656_4_1, pub_r001656_5_1);
  int helper_flow_1_2 = fn_R001656_5613_1(sec_r001656_1_2, pub_r001656_2_2, pub_r001656_3_2, pub_r001656_4_2, pub_r001656_5_2);
  fn_R001656_5613_1_2(sec_r001656_1_1, pub_r001656_2_1, pub_r001656_3_1, pub_r001656_4_1, pub_r001656_5_1, sec_r001656_1_2, pub_r001656_2_2, pub_r001656_3_2, pub_r001656_4_2, pub_r001656_5_2);
  int helper_flow_2_1 = fn_R001656_5613_2(sec_r001656_2_1, pub_r001656_3_1, pub_r001656_4_1, pub_r001656_5_1, pub_r001656_6_1);
  int helper_flow_2_2 = fn_R001656_5613_2(sec_r001656_2_2, pub_r001656_3_2, pub_r001656_4_2, pub_r001656_5_2, pub_r001656_6_2);
  fn_R001656_5613_2_2(sec_r001656_2_1, pub_r001656_3_1, pub_r001656_4_1, pub_r001656_5_1, pub_r001656_6_1, sec_r001656_2_2, pub_r001656_3_2, pub_r001656_4_2, pub_r001656_5_2, pub_r001656_6_2);
  int helper_flow_3_1 = fn_R001656_5613_3(sec_r001656_3_1, sec_r001656_4_1);
  int helper_flow_3_2 = fn_R001656_5613_3(sec_r001656_3_2, sec_r001656_4_2);
  fn_R001656_5613_3_2(sec_r001656_3_1, sec_r001656_4_1, sec_r001656_3_2, sec_r001656_4_2);
  int helper_flow_4_1 = fn_R001656_5613_4(sec_r001656_4_1, pub_r001656_5_1, pub_r001656_6_1, pub_r001656_7_1);
  int helper_flow_4_2 = fn_R001656_5613_4(sec_r001656_4_2, pub_r001656_5_2, pub_r001656_6_2, pub_r001656_7_2);
  fn_R001656_5613_4_2(sec_r001656_4_1, pub_r001656_5_1, pub_r001656_6_1, pub_r001656_7_1, sec_r001656_4_2, pub_r001656_5_2, pub_r001656_6_2, pub_r001656_7_2);
  int helper_flow_5_1 = fn_R001656_5613_5(sec_r001656_5_1, sec_r001656_6_1, pub_r001656_7_1);
  int helper_flow_5_2 = fn_R001656_5613_5(sec_r001656_5_2, sec_r001656_6_2, pub_r001656_7_2);
  fn_R001656_5613_5_2(sec_r001656_5_1, sec_r001656_6_1, pub_r001656_7_1, sec_r001656_5_2, sec_r001656_6_2, pub_r001656_7_2);
  int helper_flow_6_1 = fn_R001656_5613_6(sec_r001656_6_1, sec_r001656_7_1, pub_r001656_8_1);
  int helper_flow_6_2 = fn_R001656_5613_6(sec_r001656_6_2, sec_r001656_7_2, pub_r001656_8_2);
  fn_R001656_5613_6_2(sec_r001656_6_1, sec_r001656_7_1, pub_r001656_8_1, sec_r001656_6_2, sec_r001656_7_2, pub_r001656_8_2);
  int helper_flow_7_1 = fn_R001656_5613_7(sec_r001656_7_1, sec_r001656_8_1);
  int helper_flow_7_2 = fn_R001656_5613_7(sec_r001656_7_2, sec_r001656_8_2);
  fn_R001656_5613_7_2(sec_r001656_7_1, sec_r001656_8_1, sec_r001656_7_2, sec_r001656_8_2);
  int helper_flow_8_1 = fn_R001656_5613_8(sec_r001656_8_1, pub_r001656_9_1, pub_r001656_10_1);
  int helper_flow_8_2 = fn_R001656_5613_8(sec_r001656_8_2, pub_r001656_9_2, pub_r001656_10_2);
  fn_R001656_5613_8_2(sec_r001656_8_1, pub_r001656_9_1, pub_r001656_10_1, sec_r001656_8_2, pub_r001656_9_2, pub_r001656_10_2);
  int stage_v_0_1 = ((sec_r001656_19_1 + (pub_r001656_11_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001656_19_2 + (pub_r001656_11_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((pub_r001656_20_1 * 2) + 46) & 63;
  int stage_v_1_2 = ((pub_r001656_20_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001656_7_1 * 2) + 42) & 63;
  int stage_v_2_2 = ((pub_r001656_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001656_9_1 * 2) + 38) & 63;
  int stage_v_3_2 = ((pub_r001656_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001656_23_1 * 2) + 36) & 63;
  int stage_v_4_2 = ((pub_r001656_23_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((sec_r001656_12_1 + (pub_r001656_7_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001656_12_2 + (pub_r001656_7_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((stage_v_0_1 + (pub_r001656_17_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((stage_v_0_2 + (pub_r001656_17_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((sec_r001656_3_1 + (pub_r001656_20_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001656_3_2 + (pub_r001656_20_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((pub_r001656_20_1 * 2) + 8) & 63;
  int stage_v_8_2 = ((pub_r001656_20_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((sec_r001656_10_1 + (pub_r001656_17_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((sec_r001656_10_2 + (pub_r001656_17_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((helper_flow_6_1 + (pub_r001656_15_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((helper_flow_6_2 + (pub_r001656_15_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((helper_flow_1_1 + (pub_r001656_5_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((helper_flow_1_2 + (pub_r001656_5_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((sec_r001656_2_1 + (pub_r001656_16_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001656_2_2 + (pub_r001656_16_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((helper_flow_7_1 + (pub_r001656_23_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((helper_flow_7_2 + (pub_r001656_23_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((sec_r001656_4_1 + (pub_r001656_13_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001656_4_2 + (pub_r001656_13_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((pub_r001656_19_1 * 2) + 19) & 63;
  int stage_v_15_2 = ((pub_r001656_19_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((sec_r001656_5_1 + (pub_r001656_2_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((sec_r001656_5_2 + (pub_r001656_2_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((pub_r001656_8_1 * 2) + 38) & 63;
  int stage_v_17_2 = ((pub_r001656_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((sec_r001656_6_1 + (pub_r001656_11_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((sec_r001656_6_2 + (pub_r001656_11_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((sec_r001656_0_1 + (pub_r001656_0_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((sec_r001656_0_2 + (pub_r001656_0_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((pub_r001656_1_1 * 2) + 20) & 63;
  int stage_v_20_2 = ((pub_r001656_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((stage_v_7_1 + (pub_r001656_1_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_7_2 + (pub_r001656_1_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((sec_r001656_19_1 + (pub_r001656_3_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((sec_r001656_19_2 + (pub_r001656_3_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((pub_r001656_18_1 * 2) + 31) & 63;
  int stage_v_23_2 = ((pub_r001656_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((sec_r001656_15_1 + (pub_r001656_14_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001656_15_2 + (pub_r001656_14_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((stage_v_7_1 + (pub_r001656_8_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((stage_v_7_2 + (pub_r001656_8_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((helper_flow_0_1 + (pub_r001656_2_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((helper_flow_0_2 + (pub_r001656_2_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((helper_flow_2_1 + (pub_r001656_23_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((helper_flow_2_2 + (pub_r001656_23_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((pub_r001656_19_1 * 2) + 29) & 63;
  int stage_v_28_2 = ((pub_r001656_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001656_4_1 * 2) + 46) & 63;
  int stage_v_29_2 = ((pub_r001656_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((helper_flow_4_1 + (pub_r001656_10_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((helper_flow_4_2 + (pub_r001656_10_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((pub_r001656_7_1 * 2) + 32) & 63;
  int stage_v_31_2 = ((pub_r001656_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((helper_flow_7_1 + (pub_r001656_11_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((helper_flow_7_2 + (pub_r001656_11_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((pub_r001656_23_1 * 2) + 48) & 63;
  int stage_v_33_2 = ((pub_r001656_23_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001656_15_1 * 2) + 42) & 63;
  int stage_v_34_2 = ((pub_r001656_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((stage_v_9_1 + (pub_r001656_13_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((stage_v_9_2 + (pub_r001656_13_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((stage_v_22_1 + (pub_r001656_11_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((stage_v_22_2 + (pub_r001656_11_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((sec_r001656_15_1 + (pub_r001656_5_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((sec_r001656_15_2 + (pub_r001656_5_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((pub_r001656_1_1 * 2) + 49) & 63;
  int stage_v_38_2 = ((pub_r001656_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001656_10_1 * 2) + 6) & 63;
  int stage_v_39_2 = ((pub_r001656_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((sec_r001656_13_1 + (pub_r001656_5_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((sec_r001656_13_2 + (pub_r001656_5_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((sec_r001656_18_1 + (pub_r001656_13_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((sec_r001656_18_2 + (pub_r001656_13_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((helper_flow_1_1 + (pub_r001656_0_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((helper_flow_1_2 + (pub_r001656_0_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((sec_r001656_19_1 + (pub_r001656_11_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((sec_r001656_19_2 + (pub_r001656_11_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((pub_r001656_9_1 * 2) + 10) & 63;
  int stage_v_44_2 = ((pub_r001656_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((stage_v_14_1 + (pub_r001656_23_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((stage_v_14_2 + (pub_r001656_23_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((pub_r001656_14_1 * 2) + 23) & 63;
  int stage_v_46_2 = ((pub_r001656_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((sec_r001656_17_1 + (pub_r001656_19_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((sec_r001656_17_2 + (pub_r001656_19_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((pub_r001656_8_1 * 2) + 8) & 63;
  int stage_v_48_2 = ((pub_r001656_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((helper_flow_7_1 + (pub_r001656_12_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((helper_flow_7_2 + (pub_r001656_12_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((pub_r001656_13_1 * 2) + 6) & 63;
  int stage_v_50_2 = ((pub_r001656_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((sec_r001656_15_1 + (pub_r001656_19_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((sec_r001656_15_2 + (pub_r001656_19_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((pub_r001656_15_1 * 2) + 18) & 63;
  int stage_v_52_2 = ((pub_r001656_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((helper_flow_2_1 + (pub_r001656_1_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((helper_flow_2_2 + (pub_r001656_1_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((pub_r001656_22_1 * 2) + 14) & 63;
  int stage_v_54_2 = ((pub_r001656_22_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((helper_flow_8_1 + (pub_r001656_3_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((helper_flow_8_2 + (pub_r001656_3_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((stage_v_42_1 + (pub_r001656_22_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((stage_v_42_2 + (pub_r001656_22_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((sec_r001656_5_1 + (pub_r001656_5_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((sec_r001656_5_2 + (pub_r001656_5_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((pub_r001656_15_1 * 2) + 14) & 63;
  int stage_v_58_2 = ((pub_r001656_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001656_2_1 * 2) + 5) & 63;
  int stage_v_59_2 = ((pub_r001656_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((sec_r001656_12_1 + (pub_r001656_21_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((sec_r001656_12_2 + (pub_r001656_21_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((pub_r001656_14_1 * 2) + 32) & 63;
  int stage_v_61_2 = ((pub_r001656_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001656_22_1 * 2) + 21) & 63;
  int stage_v_62_2 = ((pub_r001656_22_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((helper_flow_4_1 + (pub_r001656_4_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((helper_flow_4_2 + (pub_r001656_4_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((pub_r001656_12_1 * 2) + 24) & 63;
  int stage_v_64_2 = ((pub_r001656_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((sec_r001656_10_1 + (pub_r001656_7_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((sec_r001656_10_2 + (pub_r001656_7_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((helper_flow_2_1 + (pub_r001656_7_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((helper_flow_2_2 + (pub_r001656_7_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((pub_r001656_6_1 * 2) + 13) & 63;
  int stage_v_67_2 = ((pub_r001656_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((stage_v_43_1 + (pub_r001656_2_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_43_2 + (pub_r001656_2_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((sec_r001656_13_1 + (pub_r001656_6_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((sec_r001656_13_2 + (pub_r001656_6_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((sec_r001656_4_1 + (pub_r001656_11_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((sec_r001656_4_2 + (pub_r001656_11_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((stage_v_10_1 + (pub_r001656_13_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_10_2 + (pub_r001656_13_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((sec_r001656_10_1 + (pub_r001656_15_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((sec_r001656_10_2 + (pub_r001656_15_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_41_1 + (pub_r001656_6_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_41_2 + (pub_r001656_6_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((sec_r001656_14_1 + (pub_r001656_20_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((sec_r001656_14_2 + (pub_r001656_20_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((pub_r001656_9_1 * 2) + 9) & 63;
  int stage_v_75_2 = ((pub_r001656_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((sec_r001656_17_1 + (pub_r001656_11_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((sec_r001656_17_2 + (pub_r001656_11_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((pub_r001656_14_1 * 2) + 10) & 63;
  int stage_v_77_2 = ((pub_r001656_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((stage_v_32_1 + (pub_r001656_11_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_32_2 + (pub_r001656_11_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((stage_v_18_1 + (pub_r001656_17_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_18_2 + (pub_r001656_17_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((sec_r001656_8_1 + (pub_r001656_3_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((sec_r001656_8_2 + (pub_r001656_3_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((stage_v_27_1 + (pub_r001656_14_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_27_2 + (pub_r001656_14_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((pub_r001656_11_1 * 2) + 50) & 63;
  int stage_v_82_2 = ((pub_r001656_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001656_20_1 * 2) + 18) & 63;
  int stage_v_83_2 = ((pub_r001656_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((stage_v_65_1 + (pub_r001656_1_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_65_2 + (pub_r001656_1_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((sec_r001656_13_1 + (pub_r001656_10_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((sec_r001656_13_2 + (pub_r001656_10_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_65_1 + (pub_r001656_21_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_65_2 + (pub_r001656_21_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_72_1 + (pub_r001656_15_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_72_2 + (pub_r001656_15_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((stage_v_9_1 + (pub_r001656_14_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_9_2 + (pub_r001656_14_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((stage_v_76_1 + (pub_r001656_19_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_76_2 + (pub_r001656_19_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((stage_v_6_1 + (pub_r001656_18_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_6_2 + (pub_r001656_18_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((stage_v_26_1 + (pub_r001656_4_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_26_2 + (pub_r001656_4_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((pub_r001656_7_1 * 2) + 38) & 63;
  int stage_v_92_2 = ((pub_r001656_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001656_0_1 * 2) + 45) & 63;
  int stage_v_93_2 = ((pub_r001656_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001656_19_1 * 2) + 22) & 63;
  int stage_v_94_2 = ((pub_r001656_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((helper_flow_6_1 + (pub_r001656_10_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((helper_flow_6_2 + (pub_r001656_10_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((pub_r001656_5_1 * 2) + 46) & 63;
  int stage_v_96_2 = ((pub_r001656_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001656_23_1 * 2) + 49) & 63;
  int stage_v_97_2 = ((pub_r001656_23_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((stage_v_74_1 + (pub_r001656_14_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_74_2 + (pub_r001656_14_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((stage_v_16_1 + (pub_r001656_8_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_16_2 + (pub_r001656_8_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((pub_r001656_9_1 * 2) + 17) & 63;
  int stage_v_100_2 = ((pub_r001656_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001656_16_1 * 2) + 40) & 63;
  int stage_v_101_2 = ((pub_r001656_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((stage_v_41_1 + (pub_r001656_16_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_41_2 + (pub_r001656_16_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((pub_r001656_20_1 * 2) + 41) & 63;
  int stage_v_103_2 = ((pub_r001656_20_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((stage_v_47_1 + (pub_r001656_16_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_47_2 + (pub_r001656_16_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_84_1 + (pub_r001656_7_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_84_2 + (pub_r001656_7_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_68_1 + (pub_r001656_17_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_68_2 + (pub_r001656_17_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((stage_v_6_1 + (pub_r001656_20_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_6_2 + (pub_r001656_20_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((helper_flow_4_1 + (pub_r001656_15_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((helper_flow_4_2 + (pub_r001656_15_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_40_1 + (pub_r001656_7_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_40_2 + (pub_r001656_7_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((pub_r001656_4_1 * 2) + 17) & 63;
  int stage_v_110_2 = ((pub_r001656_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((sec_r001656_12_1 + (pub_r001656_16_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((sec_r001656_12_2 + (pub_r001656_16_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((stage_v_49_1 + (pub_r001656_14_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_49_2 + (pub_r001656_14_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((sec_r001656_8_1 + (pub_r001656_13_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((sec_r001656_8_2 + (pub_r001656_13_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((pub_r001656_6_1 * 2) + 16) & 63;
  int stage_v_114_2 = ((pub_r001656_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((sec_r001656_12_1 + (pub_r001656_2_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((sec_r001656_12_2 + (pub_r001656_2_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((sec_r001656_6_1 + (pub_r001656_15_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((sec_r001656_6_2 + (pub_r001656_15_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((pub_r001656_14_1 * 2) + 25) & 63;
  int stage_v_117_2 = ((pub_r001656_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((stage_v_79_1 + (pub_r001656_11_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_79_2 + (pub_r001656_11_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((sec_r001656_13_1 + (pub_r001656_15_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((sec_r001656_13_2 + (pub_r001656_15_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((stage_v_56_1 + (pub_r001656_5_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_56_2 + (pub_r001656_5_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((sec_r001656_6_1 + (pub_r001656_5_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((sec_r001656_6_2 + (pub_r001656_5_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((pub_r001656_18_1 * 2) + 48) & 63;
  int stage_v_122_2 = ((pub_r001656_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((helper_flow_5_1 + (pub_r001656_6_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((helper_flow_5_2 + (pub_r001656_6_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((stage_v_11_1 + (pub_r001656_3_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((stage_v_11_2 + (pub_r001656_3_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((stage_v_13_1 + (pub_r001656_18_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_13_2 + (pub_r001656_18_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_105_1 + (pub_r001656_19_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_105_2 + (pub_r001656_19_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((stage_v_120_1 + (pub_r001656_17_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_120_2 + (pub_r001656_17_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((stage_v_99_1 + (pub_r001656_19_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_99_2 + (pub_r001656_19_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((pub_r001656_9_1 * 2) + 6) & 63;
  int stage_v_129_2 = ((pub_r001656_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((sec_r001656_3_1 + (pub_r001656_1_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((sec_r001656_3_2 + (pub_r001656_1_2 * 2)) + 395) & 127;
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
  int stage_v_131_1 = ((pub_r001656_8_1 * 2) + 11) & 63;
  int stage_v_131_2 = ((pub_r001656_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001656_0_1 * 2) + 29) & 63;
  int stage_v_132_2 = ((pub_r001656_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001656_20_1 * 2) + 35) & 63;
  int stage_v_133_2 = ((pub_r001656_20_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((sec_r001656_3_1 + (pub_r001656_21_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((sec_r001656_3_2 + (pub_r001656_21_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((stage_v_76_1 + (pub_r001656_5_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_76_2 + (pub_r001656_5_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_14_1 + (pub_r001656_3_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_14_2 + (pub_r001656_3_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_111_1 + (pub_r001656_22_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_111_2 + (pub_r001656_22_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((helper_flow_7_1 + (pub_r001656_16_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((helper_flow_7_2 + (pub_r001656_16_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((pub_r001656_12_1 * 2) + 28) & 63;
  int stage_v_139_2 = ((pub_r001656_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001656_3_1 * 2) + 35) & 63;
  int stage_v_140_2 = ((pub_r001656_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((stage_v_49_1 + (pub_r001656_19_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_49_2 + (pub_r001656_19_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((stage_v_36_1 + (pub_r001656_21_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_36_2 + (pub_r001656_21_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((stage_v_49_1 + (pub_r001656_9_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_49_2 + (pub_r001656_9_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((stage_v_88_1 + (pub_r001656_16_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_88_2 + (pub_r001656_16_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((stage_v_111_1 + (pub_r001656_4_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_111_2 + (pub_r001656_4_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_108_1 + (pub_r001656_20_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_108_2 + (pub_r001656_20_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_144_1 + (pub_r001656_2_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_144_2 + (pub_r001656_2_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_119_1 + (pub_r001656_23_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_119_2 + (pub_r001656_23_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((stage_v_113_1 + (pub_r001656_19_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((stage_v_113_2 + (pub_r001656_19_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((helper_flow_6_1 + (pub_r001656_20_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((helper_flow_6_2 + (pub_r001656_20_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((stage_v_66_1 + (pub_r001656_6_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_66_2 + (pub_r001656_6_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((sec_r001656_18_1 + (pub_r001656_16_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((sec_r001656_18_2 + (pub_r001656_16_2 * 2)) + 461) & 127;
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
  int stage_v_153_1 = ((stage_v_81_1 + (pub_r001656_12_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_81_2 + (pub_r001656_12_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((sec_r001656_10_1 + (pub_r001656_20_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((sec_r001656_10_2 + (pub_r001656_20_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((pub_r001656_6_1 * 2) + 9) & 63;
  int stage_v_155_2 = ((pub_r001656_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001656_19_1 * 2) + 7) & 63;
  int stage_v_156_2 = ((pub_r001656_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((stage_v_25_1 + (pub_r001656_2_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_25_2 + (pub_r001656_2_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((pub_r001656_17_1 * 2) + 15) & 63;
  int stage_v_158_2 = ((pub_r001656_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((helper_flow_3_1 + (pub_r001656_23_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((helper_flow_3_2 + (pub_r001656_23_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_157_1 + (pub_r001656_0_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_157_2 + (pub_r001656_0_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((pub_r001656_11_1 * 2) + 48) & 63;
  int stage_v_161_2 = ((pub_r001656_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((helper_flow_4_1 + (pub_r001656_23_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((helper_flow_4_2 + (pub_r001656_23_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((stage_v_89_1 + (pub_r001656_21_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_89_2 + (pub_r001656_21_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((stage_v_9_1 + (pub_r001656_6_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_9_2 + (pub_r001656_6_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((stage_v_127_1 + (pub_r001656_10_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_127_2 + (pub_r001656_10_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_109_1 + (pub_r001656_2_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_109_2 + (pub_r001656_2_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((stage_v_147_1 + (pub_r001656_0_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_147_2 + (pub_r001656_0_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_35_1 + (pub_r001656_19_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_35_2 + (pub_r001656_19_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_69_1 + (pub_r001656_13_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_69_2 + (pub_r001656_13_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((pub_r001656_11_1 * 2) + 44) & 63;
  int stage_v_170_2 = ((pub_r001656_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001656_18_1 * 2) + 31) & 63;
  int stage_v_171_2 = ((pub_r001656_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((sec_r001656_8_1 + (pub_r001656_21_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((sec_r001656_8_2 + (pub_r001656_21_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((stage_v_166_1 + (pub_r001656_17_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_166_2 + (pub_r001656_17_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_124_1 + (pub_r001656_13_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_124_2 + (pub_r001656_13_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_115_1 + (pub_r001656_10_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_115_2 + (pub_r001656_10_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((pub_r001656_3_1 * 2) + 16) & 63;
  int stage_v_176_2 = ((pub_r001656_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((stage_v_175_1 + (pub_r001656_21_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_175_2 + (pub_r001656_21_2 * 2)) + 536) & 127;
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
  int stage_v_178_1 = ((pub_r001656_7_1 * 2) + 50) & 63;
  int stage_v_178_2 = ((pub_r001656_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((stage_v_57_1 + (pub_r001656_2_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_57_2 + (pub_r001656_2_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((stage_v_179_1 + (pub_r001656_1_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_179_2 + (pub_r001656_1_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((stage_v_7_1 + (pub_r001656_10_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_7_2 + (pub_r001656_10_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((pub_r001656_11_1 * 2) + 27) & 63;
  int stage_v_182_2 = ((pub_r001656_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001656_0_1 * 2) + 47) & 63;
  int stage_v_183_2 = ((pub_r001656_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((stage_v_166_1 + (pub_r001656_20_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_166_2 + (pub_r001656_20_2 * 2)) + 557) & 127;
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
  int stage_v_185_1 = ((pub_r001656_15_1 * 2) + 49) & 63;
  int stage_v_185_2 = ((pub_r001656_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((stage_v_63_1 + (pub_r001656_0_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_63_2 + (pub_r001656_0_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_65_1 + (pub_r001656_3_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_65_2 + (pub_r001656_3_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((stage_v_104_1 + (pub_r001656_7_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((stage_v_104_2 + (pub_r001656_7_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((stage_v_186_1 + (pub_r001656_19_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_186_2 + (pub_r001656_19_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((pub_r001656_8_1 * 2) + 6) & 63;
  int stage_v_190_2 = ((pub_r001656_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((sec_r001656_18_1 + (pub_r001656_1_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((sec_r001656_18_2 + (pub_r001656_1_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((stage_v_85_1 + (pub_r001656_10_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_85_2 + (pub_r001656_10_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((stage_v_78_1 + (pub_r001656_1_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_78_2 + (pub_r001656_1_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((pub_r001656_13_1 * 2) + 48) & 63;
  int stage_v_194_2 = ((pub_r001656_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((sec_r001656_14_1 + (pub_r001656_9_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((sec_r001656_14_2 + (pub_r001656_9_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((sec_r001656_7_1 + (pub_r001656_4_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((sec_r001656_7_2 + (pub_r001656_4_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((sec_r001656_1_1 + (pub_r001656_6_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((sec_r001656_1_2 + (pub_r001656_6_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((pub_r001656_11_1 * 2) + 19) & 63;
  int stage_v_198_2 = ((pub_r001656_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((stage_v_11_1 + (pub_r001656_8_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_11_2 + (pub_r001656_8_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((pub_r001656_6_1 * 2) + 34) & 63;
  int stage_v_200_2 = ((pub_r001656_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((stage_v_111_1 + (pub_r001656_8_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_111_2 + (pub_r001656_8_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_104_1 + (pub_r001656_11_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_104_2 + (pub_r001656_11_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((stage_v_79_1 + (pub_r001656_6_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((stage_v_79_2 + (pub_r001656_6_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((stage_v_130_1 + (pub_r001656_16_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_130_2 + (pub_r001656_16_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((stage_v_165_1 + (pub_r001656_1_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_165_2 + (pub_r001656_1_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((pub_r001656_23_1 * 2) + 18) & 63;
  int stage_v_206_2 = ((pub_r001656_23_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((sec_r001656_1_1 + (pub_r001656_11_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((sec_r001656_1_2 + (pub_r001656_11_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_147_1 + (pub_r001656_22_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_147_2 + (pub_r001656_22_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((pub_r001656_17_1 * 2) + 24) & 63;
  int stage_v_209_2 = ((pub_r001656_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001656_19_1 * 2) + 5) & 63;
  int stage_v_210_2 = ((pub_r001656_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((helper_flow_3_1 + (pub_r001656_11_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((helper_flow_3_2 + (pub_r001656_11_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((sec_r001656_4_1 + (pub_r001656_11_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((sec_r001656_4_2 + (pub_r001656_11_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((stage_v_116_1 + (pub_r001656_4_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_116_2 + (pub_r001656_4_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((stage_v_119_1 + (pub_r001656_17_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_119_2 + (pub_r001656_17_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((stage_v_87_1 + (pub_r001656_3_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((stage_v_87_2 + (pub_r001656_3_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((pub_r001656_8_1 * 2) + 21) & 63;
  int stage_v_216_2 = ((pub_r001656_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((stage_v_169_1 + (pub_r001656_5_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_169_2 + (pub_r001656_5_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_160_1 + (pub_r001656_0_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_160_2 + (pub_r001656_0_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_174_1 + (pub_r001656_10_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_174_2 + (pub_r001656_10_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((pub_r001656_15_1 * 2) + 33) & 63;
  int stage_v_220_2 = ((pub_r001656_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((stage_v_7_1 + (pub_r001656_9_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_7_2 + (pub_r001656_9_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((stage_v_201_1 + (pub_r001656_2_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_201_2 + (pub_r001656_2_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_211_1 + (pub_r001656_16_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_211_2 + (pub_r001656_16_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((stage_v_106_1 + (pub_r001656_16_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_106_2 + (pub_r001656_16_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((stage_v_168_1 + (pub_r001656_7_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_168_2 + (pub_r001656_7_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((helper_flow_8_1 + (pub_r001656_2_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((helper_flow_8_2 + (pub_r001656_2_2 * 2)) + 683) & 127;
  if (stage_v_226_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_226_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_226_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_226_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_227_1 = ((pub_r001656_13_1 * 2) + 18) & 63;
  int stage_v_227_2 = ((pub_r001656_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((sec_r001656_10_1 + (pub_r001656_4_1 * 2)) + 689) & 127;
  int stage_v_228_2 = ((sec_r001656_10_2 + (pub_r001656_4_2 * 2)) + 689) & 127;
  if (stage_v_228_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_228_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_228_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_228_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_229_1 = ((stage_v_160_1 + (pub_r001656_16_1 * 2)) + 692) & 127;
  int stage_v_229_2 = ((stage_v_160_2 + (pub_r001656_16_2 * 2)) + 692) & 127;
  if (stage_v_229_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_229_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_229_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_229_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_230_1 = ((pub_r001656_10_1 * 2) + 40) & 63;
  int stage_v_230_2 = ((pub_r001656_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((sec_r001656_17_1 + (pub_r001656_8_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((sec_r001656_17_2 + (pub_r001656_8_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((pub_r001656_13_1 * 2) + 50) & 63;
  int stage_v_232_2 = ((pub_r001656_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((stage_v_113_1 + (pub_r001656_6_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((stage_v_113_2 + (pub_r001656_6_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((stage_v_37_1 + (pub_r001656_6_1 * 2)) + 707) & 127;
  int stage_v_234_2 = ((stage_v_37_2 + (pub_r001656_6_2 * 2)) + 707) & 127;
  if (stage_v_234_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_234_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_234_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_234_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_235_1 = ((stage_v_16_1 + (pub_r001656_16_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((stage_v_16_2 + (pub_r001656_16_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((helper_flow_0_1 + (pub_r001656_15_1 * 2)) + 713) & 127;
  int stage_v_236_2 = ((helper_flow_0_2 + (pub_r001656_15_2 * 2)) + 713) & 127;
  if (stage_v_236_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_236_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_236_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_236_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_237_1 = ((stage_v_70_1 + (pub_r001656_11_1 * 2)) + 716) & 127;
  int stage_v_237_2 = ((stage_v_70_2 + (pub_r001656_11_2 * 2)) + 716) & 127;
  if (stage_v_237_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_237_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_237_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_237_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_238_1 = ((stage_v_144_1 + (pub_r001656_0_1 * 2)) + 719) & 127;
  int stage_v_238_2 = ((stage_v_144_2 + (pub_r001656_0_2 * 2)) + 719) & 127;
  if (stage_v_238_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_238_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_238_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_238_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_239_1 = ((sec_r001656_17_1 + (pub_r001656_17_1 * 2)) + 722) & 127;
  int stage_v_239_2 = ((sec_r001656_17_2 + (pub_r001656_17_2 * 2)) + 722) & 127;
  if (stage_v_239_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_239_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_239_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_239_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_240_1 = ((sec_r001656_15_1 + (pub_r001656_2_1 * 2)) + 725) & 127;
  int stage_v_240_2 = ((sec_r001656_15_2 + (pub_r001656_2_2 * 2)) + 725) & 127;
  if (stage_v_240_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_240_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_240_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_240_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_241_1 = ((stage_v_13_1 + (pub_r001656_23_1 * 2)) + 728) & 127;
  int stage_v_241_2 = ((stage_v_13_2 + (pub_r001656_23_2 * 2)) + 728) & 127;
  if (stage_v_241_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_241_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_241_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_241_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_242_1 = ((pub_r001656_9_1 * 2) + 38) & 63;
  int stage_v_242_2 = ((pub_r001656_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001656_16_1 * 2) + 47) & 63;
  int stage_v_243_2 = ((pub_r001656_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((stage_v_78_1 + (pub_r001656_6_1 * 2)) + 737) & 127;
  int stage_v_244_2 = ((stage_v_78_2 + (pub_r001656_6_2 * 2)) + 737) & 127;
  if (stage_v_244_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_244_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_244_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_244_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_245_1 = ((stage_v_36_1 + (pub_r001656_7_1 * 2)) + 740) & 127;
  int stage_v_245_2 = ((stage_v_36_2 + (pub_r001656_7_2 * 2)) + 740) & 127;
  if (stage_v_245_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_245_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_245_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_245_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_245_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_245_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_245_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_245_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_246_1 = ((stage_v_229_1 + (pub_r001656_3_1 * 2)) + 743) & 127;
  int stage_v_246_2 = ((stage_v_229_2 + (pub_r001656_3_2 * 2)) + 743) & 127;
  if (stage_v_246_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_246_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_246_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_246_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_247_1 = ((stage_v_204_1 + (pub_r001656_2_1 * 2)) + 746) & 127;
  int stage_v_247_2 = ((stage_v_204_2 + (pub_r001656_2_2 * 2)) + 746) & 127;
  if (stage_v_247_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_247_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_247_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_247_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_247_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_247_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_247_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_247_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_248_1 = ((stage_v_181_1 + (pub_r001656_12_1 * 2)) + 749) & 127;
  int stage_v_248_2 = ((stage_v_181_2 + (pub_r001656_12_2 * 2)) + 749) & 127;
  if (stage_v_248_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_248_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_248_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_248_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_248_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_248_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_248_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_248_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_249_1 = ((stage_v_154_1 + (pub_r001656_14_1 * 2)) + 752) & 127;
  int stage_v_249_2 = ((stage_v_154_2 + (pub_r001656_14_2 * 2)) + 752) & 127;
  if (stage_v_249_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_249_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_249_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_249_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_249_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_249_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_249_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_249_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_250_1 = ((pub_r001656_2_1 * 2) + 5) & 63;
  int stage_v_250_2 = ((pub_r001656_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((stage_v_68_1 + (pub_r001656_13_1 * 2)) + 758) & 127;
  int stage_v_251_2 = ((stage_v_68_2 + (pub_r001656_13_2 * 2)) + 758) & 127;
  if (stage_v_251_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_251_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_251_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_251_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_251_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_251_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_251_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_251_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_252_1 = ((pub_r001656_11_1 * 2) + 20) & 63;
  int stage_v_252_2 = ((pub_r001656_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001656_0_1 * 2) + 44) & 63;
  int stage_v_253_2 = ((pub_r001656_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((pub_r001656_22_1 * 2) + 39) & 63;
  int stage_v_254_2 = ((pub_r001656_22_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((stage_v_66_1 + (pub_r001656_8_1 * 2)) + 770) & 127;
  int stage_v_255_2 = ((stage_v_66_2 + (pub_r001656_8_2 * 2)) + 770) & 127;
  if (stage_v_255_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_255_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_255_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_255_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_255_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_255_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_255_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_255_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_256_1 = ((stage_v_235_1 + (pub_r001656_14_1 * 2)) + 773) & 127;
  int stage_v_256_2 = ((stage_v_235_2 + (pub_r001656_14_2 * 2)) + 773) & 127;
  if (stage_v_256_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_256_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_256_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_256_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_256_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_256_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_256_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_256_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_257_1 = ((pub_r001656_1_1 * 2) + 37) & 63;
  int stage_v_257_2 = ((pub_r001656_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001656_22_1 * 2) + 11) & 63;
  int stage_v_258_2 = ((pub_r001656_22_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001656_12_1 * 2) + 16) & 63;
  int stage_v_259_2 = ((pub_r001656_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((stage_v_18_1 + (pub_r001656_16_1 * 2)) + 785) & 127;
  int stage_v_260_2 = ((stage_v_18_2 + (pub_r001656_16_2 * 2)) + 785) & 127;
  if (stage_v_260_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_260_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_260_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_260_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_260_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_260_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_260_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_260_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_261_1 = ((stage_v_202_1 + (pub_r001656_0_1 * 2)) + 788) & 127;
  int stage_v_261_2 = ((stage_v_202_2 + (pub_r001656_0_2 * 2)) + 788) & 127;
  if (stage_v_261_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_261_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_261_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_261_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_261_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_261_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_261_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_261_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_262_1 = ((stage_v_217_1 + (pub_r001656_1_1 * 2)) + 791) & 127;
  int stage_v_262_2 = ((stage_v_217_2 + (pub_r001656_1_2 * 2)) + 791) & 127;
  if (stage_v_262_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_262_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_262_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_262_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_262_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_262_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_262_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_262_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_263_1 = ((stage_v_157_1 + (pub_r001656_1_1 * 2)) + 794) & 127;
  int stage_v_263_2 = ((stage_v_157_2 + (pub_r001656_1_2 * 2)) + 794) & 127;
  if (stage_v_263_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_263_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_263_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_263_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_263_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_263_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_263_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_263_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_264_1 = ((stage_v_202_1 + (pub_r001656_1_1 * 2)) + 797) & 127;
  int stage_v_264_2 = ((stage_v_202_2 + (pub_r001656_1_2 * 2)) + 797) & 127;
  if (stage_v_264_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_264_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_264_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_264_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_264_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_264_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_264_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_264_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_265_1 = ((stage_v_14_1 + (pub_r001656_3_1 * 2)) + 800) & 127;
  int stage_v_265_2 = ((stage_v_14_2 + (pub_r001656_3_2 * 2)) + 800) & 127;
  if (stage_v_265_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_265_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_265_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_265_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_265_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_265_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_265_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_265_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_266_1 = ((stage_v_88_1 + (pub_r001656_16_1 * 2)) + 803) & 127;
  int stage_v_266_2 = ((stage_v_88_2 + (pub_r001656_16_2 * 2)) + 803) & 127;
  if (stage_v_266_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_266_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_266_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_266_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_266_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_266_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_266_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_266_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_267_1 = ((pub_r001656_20_1 * 2) + 34) & 63;
  int stage_v_267_2 = ((pub_r001656_20_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((stage_v_218_1 + (pub_r001656_15_1 * 2)) + 809) & 127;
  int stage_v_268_2 = ((stage_v_218_2 + (pub_r001656_15_2 * 2)) + 809) & 127;
  if (stage_v_268_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_268_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_268_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_268_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_268_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_268_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_268_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_268_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001656_4_1 != sec_r001656_4_2);
  __CPROVER_assume(pub_r001656_8_1 == pub_r001656_8_2);
  __CPROVER_assume(pub_r001656_18_1 == pub_r001656_18_2);
  __CPROVER_assume(sec_r001656_0_1 != sec_r001656_0_2);
  __CPROVER_assume(sec_r001656_20_1 != sec_r001656_20_2);
  __CPROVER_assume(pub_r001656_20_1 == pub_r001656_20_2);
  __CPROVER_assume(pub_r001656_9_1 == pub_r001656_9_2);
  __CPROVER_assume(pub_r001656_22_1 == pub_r001656_22_2);
  __CPROVER_assume(sec_r001656_16_1 != sec_r001656_16_2);
  __CPROVER_assume(pub_r001656_11_1 == pub_r001656_11_2);
  __CPROVER_assume(pub_r001656_16_1 == pub_r001656_16_2);
  __CPROVER_assume(sec_r001656_17_1 != sec_r001656_17_2);
  __CPROVER_assume(pub_r001656_12_1 == pub_r001656_12_2);
  __CPROVER_assume(sec_r001656_12_1 != sec_r001656_12_2);
  __CPROVER_assume(pub_r001656_13_1 == pub_r001656_13_2);
  __CPROVER_assume(sec_r001656_13_1 != sec_r001656_13_2);
  __CPROVER_assume(pub_r001656_6_1 == pub_r001656_6_2);
  __CPROVER_assume(sec_r001656_3_1 != sec_r001656_3_2);
  __CPROVER_assume(pub_r001656_3_1 == pub_r001656_3_2);
  __CPROVER_assume(sec_r001656_5_1 != sec_r001656_5_2);
  __CPROVER_assume(sec_r001656_9_1 != sec_r001656_9_2);
  __CPROVER_assume(sec_r001656_1_1 != sec_r001656_1_2);
  __CPROVER_assume(sec_r001656_14_1 != sec_r001656_14_2);
  __CPROVER_assume(sec_r001656_6_1 != sec_r001656_6_2);
  __CPROVER_assume(sec_r001656_10_1 != sec_r001656_10_2);
  __CPROVER_assume(pub_r001656_10_1 == pub_r001656_10_2);
  __CPROVER_assume(sec_r001656_8_1 != sec_r001656_8_2);
  __CPROVER_assume(pub_r001656_7_1 == pub_r001656_7_2);
  __CPROVER_assume(pub_r001656_5_1 == pub_r001656_5_2);
  __CPROVER_assume(pub_r001656_19_1 == pub_r001656_19_2);
  __CPROVER_assume(sec_r001656_2_1 != sec_r001656_2_2);
  __CPROVER_assume(sec_r001656_11_1 != sec_r001656_11_2);
  __CPROVER_assume(pub_r001656_14_1 == pub_r001656_14_2);
  __CPROVER_assume(sec_r001656_18_1 != sec_r001656_18_2);
  __CPROVER_assume(pub_r001656_23_1 == pub_r001656_23_2);
  __CPROVER_assume(pub_r001656_17_1 == pub_r001656_17_2);
  __CPROVER_assume(pub_r001656_21_1 == pub_r001656_21_2);
  __CPROVER_assume(pub_r001656_0_1 == pub_r001656_0_2);
  __CPROVER_assume(pub_r001656_2_1 == pub_r001656_2_2);
  __CPROVER_assume(sec_r001656_7_1 != sec_r001656_7_2);
  __CPROVER_assume(pub_r001656_4_1 == pub_r001656_4_2);
  __CPROVER_assume(pub_r001656_1_1 == pub_r001656_1_2);
  __CPROVER_assume(sec_r001656_15_1 != sec_r001656_15_2);
  __CPROVER_assume(sec_r001656_19_1 != sec_r001656_19_2);
  __CPROVER_assume(pub_r001656_15_1 == pub_r001656_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.iv == st_var_1_2.iv);
  assert(st_var_1_1.flags == st_var_1_2.flags);
  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.counter == st_var_1_2.counter);
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
}


