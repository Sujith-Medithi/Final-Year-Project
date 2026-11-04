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
struct EventLog_R000473_7313_0
{
  unsigned char seq;
  short facility;
  unsigned char signature;
  int code;
  int severity;
  int buffer[3];
};
struct SensorNode_R000473_7313_1
{
  int offset;
  int status;
  short threshold;
  int gain;
  unsigned char reading;
  int buffer[3];
};
union ColorPixel_R000473_7313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000473_7313_1
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
void fn_R000473_7313_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st_1 = {0};
  struct EventLog_R000473_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_52_1)
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

  switch (accumulator_52_2)
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

  int sample_24_1 = 0;
  int sample_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_24_1 = ((sample_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_24_2 = ((sample_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_24_1) & 127;
    acc_2 = (acc_2 + sample_24_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_10_1 = local_arr_1[aux_1 % 3];
  int phase_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_10_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_52_1 == accumulator_52_2);
  assert(sample_24_1 == sample_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_10_1 == phase_10_2);
}

int fn_R000473_7313_0(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_52 = (aux + st.buffer[1]) & 3;
  switch (accumulator_52)
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

  int sample_24 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_24 = ((sample_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_24) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_10 = local_arr[aux % 3];
  acc = (acc + (phase_10 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000473_7313_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st_1 = {0};
  struct SensorNode_R000473_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_38_1 = local_arr_1[aux_1 % 3];
  int metric_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_38_2 * 2)) & 127;
  int stride_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_27_1)
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

  switch (stride_27_2)
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

  int accumulator_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_44_1 > 14)
  {
    acc_1 = ((acc_1 + (accumulator_44_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_44_2 > 14)
  {
    acc_2 = ((acc_2 + (accumulator_44_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_99_1) & 63;
  aux_2 = (aux_2 + threshold_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_38_1 == metric_38_2);
  assert(stride_27_1 == stride_27_2);
  assert(accumulator_44_1 == accumulator_44_2);
  assert(threshold_99_1 == threshold_99_2);
}

int fn_R000473_7313_1(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int metric_38 = local_arr[aux % 3];
  acc = (acc + (metric_38 * 2)) & 127;
  int stride_27 = (aux + st.buffer[1]) & 3;
  switch (stride_27)
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

  int accumulator_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_44 > 14)
  {
    acc = ((acc + (accumulator_44 * 2)) + 5) & 127;
    aux ^= accumulator_44 & 15;
  }
  else
  {
    acc = ((acc - accumulator_44) + 11) & 127;
    aux += 3;
  }
  int threshold_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000473_7313_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st_1 = {0};
  struct SensorNode_R000473_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quantum_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_69_1)
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

  switch (quantum_69_2)
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

  int metric_43_1 = 0;
  int metric_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_43_1 = ((metric_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_43_2 = ((metric_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_43_1) & 127;
    acc_2 = (acc_2 + metric_43_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_69_1 == quantum_69_2);
  assert(metric_43_1 == metric_43_2);
}

int fn_R000473_7313_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quantum_69 = (aux + st.buffer[1]) & 3;
  switch (quantum_69)
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

  int metric_43 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_43 = ((metric_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_43) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000473_7313_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st_1 = {0};
  struct SensorNode_R000473_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quotient_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_50_1) & 63;
  aux_2 = (aux_2 + quotient_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_26_1)
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

  switch (index_reg_26_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_50_1 == quotient_50_2);
  assert(index_reg_26_1 == index_reg_26_2);
}

int fn_R000473_7313_3(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quotient_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_50) & 63;
  acc ^= aux;
  int index_reg_26 = (aux + st.buffer[1]) & 3;
  switch (index_reg_26)
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

void fn_R000473_7313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st_1 = {0};
  struct EventLog_R000473_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int checksum_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_88_1) & 63;
  aux_2 = (aux_2 + checksum_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_79_1 = 0;
  int cursor_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_79_1 = ((cursor_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_79_2 = ((cursor_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_79_1) & 127;
    acc_2 = (acc_2 + cursor_79_2) & 127;
  }

  int scale_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_14_1 > 42)
  {
    acc_1 = ((acc_1 + (scale_14_1 * 2)) + 5) & 127;
    aux_1 ^= scale_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_14_2 > 42)
  {
    acc_2 = ((acc_2 + (scale_14_2 * 2)) + 5) & 127;
    aux_2 ^= scale_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_14_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_88_1 == checksum_88_2);
  assert(cursor_79_1 == cursor_79_2);
  assert(scale_14_1 == scale_14_2);
}

int fn_R000473_7313_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int checksum_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_88) & 63;
  acc ^= aux;
  int cursor_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_79 = ((cursor_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_79) & 127;
  }

  int scale_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_14 > 42)
  {
    acc = ((acc + (scale_14 * 2)) + 5) & 127;
    aux ^= scale_14 & 15;
  }
  else
  {
    acc = ((acc - scale_14) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000473_7313_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st_1 = {0};
  struct SensorNode_R000473_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_63_1)
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

  switch (offset_63_2)
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

  int bound_40_1 = 0;
  int bound_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_40_1 = ((bound_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_40_2 = ((bound_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_40_1) & 127;
    acc_2 = (acc_2 + bound_40_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_63_1 == offset_63_2);
  assert(bound_40_1 == bound_40_2);
}

int fn_R000473_7313_5(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_63 = (aux + st.buffer[1]) & 3;
  switch (offset_63)
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

  int bound_40 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_40 = ((bound_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_40) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000473_7313_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st_1 = {0};
  struct EventLog_R000473_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int window_87_1 = 0;
  int window_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_87_1 = ((window_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_87_2 = ((window_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_87_1) & 127;
    acc_2 = (acc_2 + window_87_2) & 127;
  }

  int sample_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_32_1)
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

  switch (sample_32_2)
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
  int stride_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_43_1) & 63;
  aux_2 = (aux_2 + stride_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_87_1 == window_87_2);
  assert(sample_32_1 == sample_32_2);
  assert(stride_43_1 == stride_43_2);
}

int fn_R000473_7313_6(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int window_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_87 = ((window_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_87) & 127;
  }

  int sample_32 = (aux + st.buffer[1]) & 3;
  switch (sample_32)
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
  int stride_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_43) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000473_7313_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st_1 = {0};
  struct SensorNode_R000473_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int offset_39_1 = 0;
  int offset_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_39_1 = ((offset_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_39_2 = ((offset_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_39_1) & 127;
    acc_2 = (acc_2 + offset_39_2) & 127;
  }

  int window_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_90_1) & 63;
  aux_2 = (aux_2 + window_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_39_1 == offset_39_2);
  assert(window_90_1 == window_90_2);
}

int fn_R000473_7313_7(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int offset_39 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_39 = ((offset_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_39) & 127;
  }

  int window_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_90) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000473_7313_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st_1 = {0};
  struct EventLog_R000473_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_21_1 = local_arr_1[aux_1 % 3];
  int mask_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_21_2 * 2)) & 127;
  int metric_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_28_1)
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

  switch (metric_28_2)
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

  int damping_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_62_1 > 25)
  {
    acc_1 = ((acc_1 + (damping_62_1 * 2)) + 5) & 127;
    aux_1 ^= damping_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_62_2 > 25)
  {
    acc_2 = ((acc_2 + (damping_62_2 * 2)) + 5) & 127;
    aux_2 ^= damping_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_62_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_21_1 == mask_21_2);
  assert(metric_28_1 == metric_28_2);
  assert(damping_62_1 == damping_62_2);
}

int fn_R000473_7313_8(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int mask_21 = local_arr[aux % 3];
  acc = (acc + (mask_21 * 2)) & 127;
  int metric_28 = (aux + st.buffer[1]) & 3;
  switch (metric_28)
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

  int damping_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_62 > 25)
  {
    acc = ((acc + (damping_62 * 2)) + 5) & 127;
    aux ^= damping_62 & 15;
  }
  else
  {
    acc = ((acc - damping_62) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000473_7313_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st_1 = {0};
  struct SensorNode_R000473_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_75_1 = local_arr_1[aux_1 % 3];
  int metric_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_75_2 * 2)) & 127;
  int scale_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_21_1)
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

  switch (scale_21_2)
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

  int index_reg_66_1 = 0;
  int index_reg_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_66_1 = ((index_reg_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_66_2 = ((index_reg_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_66_1) & 127;
    acc_2 = (acc_2 + index_reg_66_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_75_1 == metric_75_2);
  assert(scale_21_1 == scale_21_2);
  assert(index_reg_66_1 == index_reg_66_2);
}

int fn_R000473_7313_9(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int metric_75 = local_arr[aux % 3];
  acc = (acc + (metric_75 * 2)) & 127;
  int scale_21 = (aux + st.buffer[1]) & 3;
  switch (scale_21)
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

  int index_reg_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_66 = ((index_reg_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_66) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000473_7313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st_1 = {0};
  struct EventLog_R000473_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int parity_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_23_1) & 63;
  aux_2 = (aux_2 + parity_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_36_1)
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

  switch (offset_36_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_34_1 = local_arr_1[aux_1 % 3];
  int offset_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_34_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_23_1 == parity_23_2);
  assert(offset_36_1 == offset_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_34_1 == offset_34_2);
}

int fn_R000473_7313_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int parity_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_23) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_36 = (aux + st.buffer[1]) & 3;
  switch (offset_36)
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

  int local_arr[3] = {4, 9, 15};
  int offset_34 = local_arr[aux % 3];
  acc = (acc + (offset_34 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000473_7313_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st_1 = {0};
  struct EventLog_R000473_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int phase_39_1 = 0;
  int phase_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_39_1 = ((phase_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_39_2 = ((phase_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_39_1) & 127;
    acc_2 = (acc_2 + phase_39_2) & 127;
  }

  int cursor_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_91_1) & 63;
  aux_2 = (aux_2 + cursor_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_61_1 = local_arr_1[aux_1 % 3];
  int bound_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_61_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_39_1 == phase_39_2);
  assert(cursor_91_1 == cursor_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_61_1 == bound_61_2);
}

int fn_R000473_7313_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int phase_39 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_39 = ((phase_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_39) & 127;
  }

  int cursor_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_91) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_61 = local_arr[aux % 3];
  acc = (acc + (bound_61 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000473_7313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st_1 = {0};
  struct SensorNode_R000473_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int weight_90_1 = 0;
  int weight_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_90_1 = ((weight_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_90_2 = ((weight_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_90_1) & 127;
    acc_2 = (acc_2 + weight_90_2) & 127;
  }

  int margin_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_92_1)
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

  switch (margin_92_2)
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

  int residue_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_21_1) & 63;
  aux_2 = (aux_2 + residue_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_90_1 == weight_90_2);
  assert(margin_92_1 == margin_92_2);
  assert(residue_21_1 == residue_21_2);
}

int fn_R000473_7313_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int weight_90 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_90 = ((weight_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_90) & 127;
  }

  int margin_92 = (aux + st.buffer[1]) & 3;
  switch (margin_92)
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

  int residue_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_21) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000473_7313_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st_1 = {0};
  struct EventLog_R000473_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tally_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_55_1) & 63;
  aux_2 = (aux_2 + tally_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_26_1 = 0;
  int quotient_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_26_1 = ((quotient_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_26_2 = ((quotient_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_26_1) & 127;
    acc_2 = (acc_2 + quotient_26_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_55_1 == tally_55_2);
  assert(quotient_26_1 == quotient_26_2);
}

int fn_R000473_7313_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tally_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_55) & 63;
  acc ^= aux;
  int quotient_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_26 = ((quotient_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_26) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000473_7313_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st_1 = {0};
  struct SensorNode_R000473_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_21_1 = local_arr_1[aux_1 % 3];
  int index_reg_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_21_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_30_1)
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

  switch (residue_30_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_21_1 == index_reg_21_2);
  assert(residue_30_1 == residue_30_2);
}

int fn_R000473_7313_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000473_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int index_reg_21 = local_arr[aux % 3];
  acc = (acc + (index_reg_21 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_30 = (aux + st.buffer[1]) & 3;
  switch (residue_30)
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

void fn_R000473_7313_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st_1 = {0};
  struct EventLog_R000473_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int residue_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_47_1 > 17)
  {
    acc_1 = ((acc_1 + (residue_47_1 * 2)) + 5) & 127;
    aux_1 ^= residue_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_47_2 > 17)
  {
    acc_2 = ((acc_2 + (residue_47_2 * 2)) + 5) & 127;
    aux_2 ^= residue_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_49_1 = 0;
  int sample_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_49_1 = ((sample_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_49_2 = ((sample_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_49_1) & 127;
    acc_2 = (acc_2 + sample_49_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_47_1 == residue_47_2);
  assert(sample_49_1 == sample_49_2);
}

int fn_R000473_7313_15(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int residue_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_47 > 17)
  {
    acc = ((acc + (residue_47 * 2)) + 5) & 127;
    aux ^= residue_47 & 15;
  }
  else
  {
    acc = ((acc - residue_47) + 11) & 127;
    aux += 3;
  }
  int sample_49 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_49 = ((sample_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_49) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000473_7313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st_1 = {0};
  struct EventLog_R000473_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int factor_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_63_1) & 63;
  aux_2 = (aux_2 + factor_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_59_1 = 0;
  int parity_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_59_1 = ((parity_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_59_2 = ((parity_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_59_1) & 127;
    acc_2 = (acc_2 + parity_59_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_63_1 == factor_63_2);
  assert(parity_59_1 == parity_59_2);
}

int fn_R000473_7313_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000473_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int factor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_63) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_59 = ((parity_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_59) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r000473_0_1;
  int sec_r000473_0_2;
  int sec_r000473_1_1;
  int sec_r000473_1_2;
  int sec_r000473_2_1;
  int sec_r000473_2_2;
  int sec_r000473_3_1;
  int sec_r000473_3_2;
  int sec_r000473_4_1;
  int sec_r000473_4_2;
  int sec_r000473_5_1;
  int sec_r000473_5_2;
  int sec_r000473_6_1;
  int sec_r000473_6_2;
  int sec_r000473_7_1;
  int sec_r000473_7_2;
  int sec_r000473_8_1;
  int sec_r000473_8_2;
  int sec_r000473_9_1;
  int sec_r000473_9_2;
  int sec_r000473_10_1;
  int sec_r000473_10_2;
  int sec_r000473_11_1;
  int sec_r000473_11_2;
  int sec_r000473_12_1;
  int sec_r000473_12_2;
  int sec_r000473_13_1;
  int sec_r000473_13_2;
  int sec_r000473_14_1;
  int sec_r000473_14_2;
  int sec_r000473_15_1;
  int sec_r000473_15_2;
  int sec_r000473_16_1;
  int sec_r000473_16_2;
  int sec_r000473_17_1;
  int sec_r000473_17_2;
  int sec_r000473_18_1;
  int sec_r000473_18_2;
  int pub_r000473_0_1;
  int pub_r000473_0_2;
  int pub_r000473_1_1;
  int pub_r000473_1_2;
  int pub_r000473_2_1;
  int pub_r000473_2_2;
  int pub_r000473_3_1;
  int pub_r000473_3_2;
  int pub_r000473_4_1;
  int pub_r000473_4_2;
  int pub_r000473_5_1;
  int pub_r000473_5_2;
  int pub_r000473_6_1;
  int pub_r000473_6_2;
  int pub_r000473_7_1;
  int pub_r000473_7_2;
  int pub_r000473_8_1;
  int pub_r000473_8_2;
  int pub_r000473_9_1;
  int pub_r000473_9_2;
  int pub_r000473_10_1;
  int pub_r000473_10_2;
  int pub_r000473_11_1;
  int pub_r000473_11_2;
  int pub_r000473_12_1;
  int pub_r000473_12_2;
  int pub_r000473_13_1;
  int pub_r000473_13_2;
  int pub_r000473_14_1;
  int pub_r000473_14_2;
  int pub_r000473_15_1;
  int pub_r000473_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000473_0_1 >= (-100)) && (pub_r000473_0_1 <= 100));
  __CPROVER_assume((pub_r000473_0_2 >= (-100)) && (pub_r000473_0_2 <= 100));
  __CPROVER_assume((pub_r000473_1_1 >= (-100)) && (pub_r000473_1_1 <= 100));
  __CPROVER_assume((pub_r000473_1_2 >= (-100)) && (pub_r000473_1_2 <= 100));
  __CPROVER_assume((pub_r000473_2_1 >= (-100)) && (pub_r000473_2_1 <= 100));
  __CPROVER_assume((pub_r000473_2_2 >= (-100)) && (pub_r000473_2_2 <= 100));
  __CPROVER_assume((pub_r000473_3_1 >= (-100)) && (pub_r000473_3_1 <= 100));
  __CPROVER_assume((pub_r000473_3_2 >= (-100)) && (pub_r000473_3_2 <= 100));
  __CPROVER_assume((pub_r000473_4_1 >= (-100)) && (pub_r000473_4_1 <= 100));
  __CPROVER_assume((pub_r000473_4_2 >= (-100)) && (pub_r000473_4_2 <= 100));
  __CPROVER_assume((pub_r000473_5_1 >= (-100)) && (pub_r000473_5_1 <= 100));
  __CPROVER_assume((pub_r000473_5_2 >= (-100)) && (pub_r000473_5_2 <= 100));
  __CPROVER_assume((pub_r000473_6_1 >= (-100)) && (pub_r000473_6_1 <= 100));
  __CPROVER_assume((pub_r000473_6_2 >= (-100)) && (pub_r000473_6_2 <= 100));
  __CPROVER_assume((pub_r000473_7_1 >= (-100)) && (pub_r000473_7_1 <= 100));
  __CPROVER_assume((pub_r000473_7_2 >= (-100)) && (pub_r000473_7_2 <= 100));
  __CPROVER_assume((pub_r000473_8_1 >= (-100)) && (pub_r000473_8_1 <= 100));
  __CPROVER_assume((pub_r000473_8_2 >= (-100)) && (pub_r000473_8_2 <= 100));
  __CPROVER_assume((pub_r000473_9_1 >= (-100)) && (pub_r000473_9_1 <= 100));
  __CPROVER_assume((pub_r000473_9_2 >= (-100)) && (pub_r000473_9_2 <= 100));
  __CPROVER_assume((pub_r000473_10_1 >= (-100)) && (pub_r000473_10_1 <= 100));
  __CPROVER_assume((pub_r000473_10_2 >= (-100)) && (pub_r000473_10_2 <= 100));
  __CPROVER_assume((pub_r000473_11_1 >= (-100)) && (pub_r000473_11_1 <= 100));
  __CPROVER_assume((pub_r000473_11_2 >= (-100)) && (pub_r000473_11_2 <= 100));
  __CPROVER_assume((pub_r000473_12_1 >= (-100)) && (pub_r000473_12_1 <= 100));
  __CPROVER_assume((pub_r000473_12_2 >= (-100)) && (pub_r000473_12_2 <= 100));
  __CPROVER_assume((pub_r000473_13_1 >= (-100)) && (pub_r000473_13_1 <= 100));
  __CPROVER_assume((pub_r000473_13_2 >= (-100)) && (pub_r000473_13_2 <= 100));
  __CPROVER_assume((pub_r000473_14_1 >= (-100)) && (pub_r000473_14_1 <= 100));
  __CPROVER_assume((pub_r000473_14_2 >= (-100)) && (pub_r000473_14_2 <= 100));
  __CPROVER_assume((pub_r000473_15_1 >= (-100)) && (pub_r000473_15_1 <= 100));
  __CPROVER_assume((pub_r000473_15_2 >= (-100)) && (pub_r000473_15_2 <= 100));
  __CPROVER_assume((sec_r000473_0_1 >= 0) && (sec_r000473_0_1 <= 255));
  __CPROVER_assume((sec_r000473_0_2 >= 0) && (sec_r000473_0_2 <= 255));
  __CPROVER_assume((sec_r000473_1_1 >= 0) && (sec_r000473_1_1 <= 255));
  __CPROVER_assume((sec_r000473_1_2 >= 0) && (sec_r000473_1_2 <= 255));
  __CPROVER_assume((sec_r000473_2_1 >= 0) && (sec_r000473_2_1 <= 255));
  __CPROVER_assume((sec_r000473_2_2 >= 0) && (sec_r000473_2_2 <= 255));
  __CPROVER_assume((sec_r000473_3_1 >= 0) && (sec_r000473_3_1 <= 255));
  __CPROVER_assume((sec_r000473_3_2 >= 0) && (sec_r000473_3_2 <= 255));
  __CPROVER_assume((sec_r000473_4_1 >= 0) && (sec_r000473_4_1 <= 255));
  __CPROVER_assume((sec_r000473_4_2 >= 0) && (sec_r000473_4_2 <= 255));
  __CPROVER_assume((sec_r000473_5_1 >= 0) && (sec_r000473_5_1 <= 255));
  __CPROVER_assume((sec_r000473_5_2 >= 0) && (sec_r000473_5_2 <= 255));
  __CPROVER_assume((sec_r000473_6_1 >= 0) && (sec_r000473_6_1 <= 255));
  __CPROVER_assume((sec_r000473_6_2 >= 0) && (sec_r000473_6_2 <= 255));
  __CPROVER_assume((sec_r000473_7_1 >= 0) && (sec_r000473_7_1 <= 255));
  __CPROVER_assume((sec_r000473_7_2 >= 0) && (sec_r000473_7_2 <= 255));
  __CPROVER_assume((sec_r000473_8_1 >= 0) && (sec_r000473_8_1 <= 255));
  __CPROVER_assume((sec_r000473_8_2 >= 0) && (sec_r000473_8_2 <= 255));
  __CPROVER_assume((sec_r000473_9_1 >= 0) && (sec_r000473_9_1 <= 255));
  __CPROVER_assume((sec_r000473_9_2 >= 0) && (sec_r000473_9_2 <= 255));
  __CPROVER_assume((sec_r000473_10_1 >= 0) && (sec_r000473_10_1 <= 255));
  __CPROVER_assume((sec_r000473_10_2 >= 0) && (sec_r000473_10_2 <= 255));
  __CPROVER_assume((sec_r000473_11_1 >= 0) && (sec_r000473_11_1 <= 255));
  __CPROVER_assume((sec_r000473_11_2 >= 0) && (sec_r000473_11_2 <= 255));
  __CPROVER_assume((sec_r000473_12_1 >= 0) && (sec_r000473_12_1 <= 255));
  __CPROVER_assume((sec_r000473_12_2 >= 0) && (sec_r000473_12_2 <= 255));
  __CPROVER_assume((sec_r000473_13_1 >= 0) && (sec_r000473_13_1 <= 255));
  __CPROVER_assume((sec_r000473_13_2 >= 0) && (sec_r000473_13_2 <= 255));
  __CPROVER_assume((sec_r000473_14_1 >= 0) && (sec_r000473_14_1 <= 255));
  __CPROVER_assume((sec_r000473_14_2 >= 0) && (sec_r000473_14_2 <= 255));
  __CPROVER_assume((sec_r000473_15_1 >= 0) && (sec_r000473_15_1 <= 255));
  __CPROVER_assume((sec_r000473_15_2 >= 0) && (sec_r000473_15_2 <= 255));
  __CPROVER_assume((sec_r000473_16_1 >= 0) && (sec_r000473_16_1 <= 255));
  __CPROVER_assume((sec_r000473_16_2 >= 0) && (sec_r000473_16_2 <= 255));
  __CPROVER_assume((sec_r000473_17_1 >= 0) && (sec_r000473_17_1 <= 255));
  __CPROVER_assume((sec_r000473_17_2 >= 0) && (sec_r000473_17_2 <= 255));
  __CPROVER_assume((sec_r000473_18_1 >= 0) && (sec_r000473_18_1 <= 255));
  __CPROVER_assume((sec_r000473_18_2 >= 0) && (sec_r000473_18_2 <= 255));
  struct EventLog_R000473_7313_0 st_var_0_1 = {0};
  struct EventLog_R000473_7313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000473_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000473_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000473_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000473_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000473_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000473_0_2 + 7) & 15;
  struct SensorNode_R000473_7313_1 st_var_1_1 = {0};
  struct SensorNode_R000473_7313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000473_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000473_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000473_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000473_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000473_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000473_0_2 + 9) & 15;
  union ColorPixel_R000473_7313_0 u_var_1;
  union ColorPixel_R000473_7313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 46)
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
  if (stage_v_0_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 46)
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 3) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_5_1 = (st_var_1_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_1_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 44)
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
  if (stage_v_7_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 44)
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 10) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 24) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  int stage_v_26_1 = (st_var_0_1.buffer[0] ^ 29) & 3;
  int stage_v_26_2 = (st_var_0_2.buffer[0] ^ 29) & 3;
  switch (stage_v_26_1)
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

  switch (stage_v_26_2)
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

  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = (st_var_0_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_0_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 31) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((st_var_0_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_0_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 55)
    {
      chk_sum_1 ^= stage_v_32_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_32_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 55)
    {
      chk_sum_2 ^= stage_v_32_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_33_1 = ((st_var_1_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_1_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 52)
    {
      chk_sum_1 ^= stage_v_33_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_33_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 52)
    {
      chk_sum_2 ^= stage_v_33_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 36) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_37_1 = ((stage_v_37_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_37_2 = ((stage_v_37_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((st_var_1_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_1_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 43)
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
  if (stage_v_39_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 43)
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
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 30)
    {
      chk_sum_1 ^= stage_v_41_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_41_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 30)
    {
      chk_sum_2 ^= stage_v_41_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((st_var_1_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_1_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 51)
    {
      chk_sum_1 ^= stage_v_43_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_43_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 51)
    {
      chk_sum_2 ^= stage_v_43_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_44_1 = (st_var_0_1.buffer[0] ^ 47) & 3;
  int stage_v_44_2 = (st_var_0_2.buffer[0] ^ 47) & 3;
  switch (stage_v_44_1)
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

  switch (stage_v_44_2)
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

  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 47) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 47) & 15;
  int stage_v_46_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_46_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= stage_v_46_1;
  chk_sum_2 ^= stage_v_46_2;
  int stage_v_47_1 = (st_var_1_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_1_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 49) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 49) & 15;
  int stage_v_48_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_48_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= stage_v_48_1;
  chk_sum_2 ^= stage_v_48_2;
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_50_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_51_1 = ((st_var_1_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_1_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 25)
    {
      chk_sum_1 ^= stage_v_51_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_51_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 25)
    {
      chk_sum_2 ^= stage_v_51_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_52_1 = (st_var_0_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_0_2.buffer[0] ^ 55) & 3;
  switch (stage_v_52_1)
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

  switch (stage_v_52_2)
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

  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = ((st_var_0_1.buffer[0] * 2) + 169) & 63;
  int stage_v_54_2 = ((st_var_0_2.buffer[0] * 2) + 169) & 63;
  if (stage_v_54_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 27)
    {
      chk_sum_1 ^= stage_v_54_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_54_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 27)
    {
      chk_sum_2 ^= stage_v_54_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 56) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 57) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = ((st_var_0_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_0_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 29)
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
  if (stage_v_58_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 29)
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
  int stage_v_59_1 = table_1[3];
  int stage_v_59_2 = table_2[3];
  table_1[3] = (table_1[0] + 119) & 63;
  table_2[3] = (table_2[0] + 119) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((st_var_1_1.buffer[1] * 2) + 190) & 63;
  int stage_v_61_2 = ((st_var_1_2.buffer[1] * 2) + 190) & 63;
  if (stage_v_61_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 45)
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
  if (stage_v_61_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 45)
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
  int stage_v_62_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (67 & 31);
  int stage_v_62_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (67 & 31);
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= (stage_v_62_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_62_2 << 1) & 127;
  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_64_1 = (st_var_0_1.buffer[0] ^ 67) & 3;
  int stage_v_64_2 = (st_var_0_2.buffer[0] ^ 67) & 3;
  switch (stage_v_64_1)
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

  switch (stage_v_64_2)
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

  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = table_1[2];
  int stage_v_66_2 = table_2[2];
  table_1[2] = (table_1[3] + 133) & 63;
  table_2[2] = (table_2[3] + 133) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (72 & 31);
  int stage_v_67_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (72 & 31);
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= (stage_v_67_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_67_2 << 1) & 127;
  int stage_v_68_1 = (st_var_0_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_0_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = table_1[1];
  int stage_v_69_2 = table_2[1];
  table_1[1] = (table_1[2] + 139) & 63;
  table_2[1] = (table_2[2] + 139) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((st_var_0_1.buffer[1] * 2) + 217) & 63;
  int stage_v_70_2 = ((st_var_0_2.buffer[1] * 2) + 217) & 63;
  if (stage_v_70_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_70_1) - 5) & 255;
    if (stage_v_70_1 > 50)
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
  if (stage_v_70_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_70_2) - 5) & 255;
    if (stage_v_70_2 > 50)
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
  int stage_v_71_1 = ((st_var_1_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_1_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 43)
    {
      chk_sum_1 ^= stage_v_71_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_71_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 43)
    {
      chk_sum_2 ^= stage_v_71_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_72_1 = table_1[0];
  int stage_v_72_2 = table_2[0];
  table_1[0] = (table_1[1] + 145) & 63;
  table_2[0] = (table_2[1] + 145) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_73_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_74_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (79 & 31);
  int stage_v_74_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (79 & 31);
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= (stage_v_74_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_74_2 << 1) & 127;
  int stage_v_75_1 = (st_var_1_1.buffer[0] ^ 78) & 3;
  int stage_v_75_2 = (st_var_1_2.buffer[0] ^ 78) & 3;
  switch (stage_v_75_1)
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

  switch (stage_v_75_2)
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

  int stage_v_76_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_76_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_80_1 = ((stage_v_80_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_80_2 = ((stage_v_80_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (st_var_1_1.buffer[0] ^ 84) & 3;
  int stage_v_81_2 = (st_var_1_2.buffer[0] ^ 84) & 3;
  switch (stage_v_81_1)
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

  switch (stage_v_81_2)
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

  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = table_1[3];
  int stage_v_83_2 = table_2[3];
  table_1[3] = (table_1[0] + 167) & 63;
  table_2[3] = (table_2[0] + 167) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_84_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_85_1 = (st_var_1_1.buffer[0] ^ 88) & 3;
  int stage_v_85_2 = (st_var_1_2.buffer[0] ^ 88) & 3;
  switch (stage_v_85_1)
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

  switch (stage_v_85_2)
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

  int stage_v_86_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_86_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_87_1 = (st_var_1_1.buffer[0] ^ 90) & 3;
  int stage_v_87_2 = (st_var_1_2.buffer[0] ^ 90) & 3;
  switch (stage_v_87_1)
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

  switch (stage_v_87_2)
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

  int stage_v_88_1 = (st_var_0_1.buffer[0] ^ 91) & 3;
  int stage_v_88_2 = (st_var_0_2.buffer[0] ^ 91) & 3;
  switch (stage_v_88_1)
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

  switch (stage_v_88_2)
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

  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_89_1 = ((stage_v_89_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_90_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 92) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 92) & 15;
  int stage_v_91_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_91_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= stage_v_91_1;
  chk_sum_2 ^= stage_v_91_2;
  int stage_v_92_1 = (st_var_0_1.buffer[0] ^ 95) & 3;
  int stage_v_92_2 = (st_var_0_2.buffer[0] ^ 95) & 3;
  switch (stage_v_92_1)
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

  switch (stage_v_92_2)
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

  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_93_1 = ((stage_v_93_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_93_2 = ((stage_v_93_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((st_var_0_1.buffer[1] * 2) + 289) & 63;
  int stage_v_94_2 = ((st_var_0_2.buffer[1] * 2) + 289) & 63;
  if (stage_v_94_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_94_1) - 5) & 255;
    if (stage_v_94_1 > 50)
    {
      chk_sum_1 ^= stage_v_94_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_94_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_94_2) - 5) & 255;
    if (stage_v_94_2 > 50)
    {
      chk_sum_2 ^= stage_v_94_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_95_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_95_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_95_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_95_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_96_1 = table_1[0];
  int stage_v_96_2 = table_2[0];
  table_1[0] = (table_1[1] + 193) & 63;
  table_2[0] = (table_2[1] + 193) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (st_var_1_1.buffer[0] ^ 100) & 3;
  int stage_v_97_2 = (st_var_1_2.buffer[0] ^ 100) & 3;
  switch (stage_v_97_1)
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

  switch (stage_v_97_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 99) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 99) & 15;
  int stage_v_98_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_98_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  chk_sum_1 ^= stage_v_98_1;
  chk_sum_2 ^= stage_v_98_2;
  int stage_v_99_1 = ((st_var_1_1.buffer[0] * 2) + 304) & 63;
  int stage_v_99_2 = ((st_var_1_2.buffer[0] * 2) + 304) & 63;
  if (stage_v_99_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_99_1) - 5) & 255;
    if (stage_v_99_1 > 37)
    {
      chk_sum_1 ^= stage_v_99_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_99_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_99_2) - 5) & 255;
    if (stage_v_99_2 > 37)
    {
      chk_sum_2 ^= stage_v_99_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_100_1 = (st_var_0_1.buffer[0] ^ 103) & 3;
  int stage_v_100_2 = (st_var_0_2.buffer[0] ^ 103) & 3;
  switch (stage_v_100_1)
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

  switch (stage_v_100_2)
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

  int stage_v_101_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_101_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_101_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_101_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_102_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_102_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_102_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_102_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 104) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 104) & 15;
  int stage_v_103_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_103_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  chk_sum_1 ^= stage_v_103_1;
  chk_sum_2 ^= stage_v_103_2;
  int stage_v_104_1 = table_1[0];
  int stage_v_104_2 = table_2[0];
  table_1[0] = (table_1[1] + 209) & 63;
  table_2[0] = (table_2[1] + 209) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (110 & 31);
  int stage_v_105_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (110 & 31);
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= (stage_v_105_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_105_2 << 1) & 127;
  int stage_v_106_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_106_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_106_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_106_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 108) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 108) & 15;
  int stage_v_107_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_107_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  chk_sum_1 ^= stage_v_107_1;
  chk_sum_2 ^= stage_v_107_2;
  int stage_v_108_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_108_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_108_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_108_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_109_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_109_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_109_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_109_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_110_1 = table_1[2];
  int stage_v_110_2 = table_2[2];
  table_1[2] = (table_1[3] + 221) & 63;
  table_2[2] = (table_2[3] + 221) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 112) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 112) & 15;
  int stage_v_111_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_111_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  chk_sum_1 ^= stage_v_111_1;
  chk_sum_2 ^= stage_v_111_2;
  int stage_v_112_1 = table_1[0];
  int stage_v_112_2 = table_2[0];
  table_1[0] = (table_1[1] + 225) & 63;
  table_2[0] = (table_2[1] + 225) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = table_1[1];
  int stage_v_113_2 = table_2[1];
  table_1[1] = (table_1[2] + 227) & 63;
  table_2[1] = (table_2[2] + 227) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (st_var_0_1.buffer[0] ^ 117) & 3;
  int stage_v_114_2 = (st_var_0_2.buffer[0] ^ 117) & 3;
  switch (stage_v_114_1)
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

  switch (stage_v_114_2)
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

  int stage_v_115_1 = (st_var_1_1.buffer[0] ^ 118) & 3;
  int stage_v_115_2 = (st_var_1_2.buffer[0] ^ 118) & 3;
  switch (stage_v_115_1)
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

  switch (stage_v_115_2)
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

  int stage_v_116_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_116_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_116_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_116_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_117_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (122 & 31);
  int stage_v_117_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (122 & 31);
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  chk_sum_1 ^= (stage_v_117_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_117_2 << 1) & 127;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_118_1 = ((stage_v_118_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_118_2 = ((stage_v_118_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = table_1[3];
  int stage_v_119_2 = table_2[3];
  table_1[3] = (table_1[0] + 239) & 63;
  table_2[3] = (table_2[0] + 239) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = table_1[0];
  int stage_v_120_2 = table_2[0];
  table_1[0] = (table_1[1] + 241) & 63;
  table_2[0] = (table_2[1] + 241) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (126 & 31);
  int stage_v_121_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (126 & 31);
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  chk_sum_1 ^= (stage_v_121_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_121_2 << 1) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 123) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 123) & 15;
  int stage_v_122_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_122_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  chk_sum_1 ^= stage_v_122_1;
  chk_sum_2 ^= stage_v_122_2;
  int stage_v_123_1 = (st_var_1_1.buffer[0] ^ 126) & 3;
  int stage_v_123_2 = (st_var_1_2.buffer[0] ^ 126) & 3;
  switch (stage_v_123_1)
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

  switch (stage_v_123_2)
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

  int stage_v_124_1 = table_1[0];
  int stage_v_124_2 = table_2[0];
  table_1[0] = (table_1[1] + 249) & 63;
  table_2[0] = (table_2[1] + 249) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_125_1 = ((stage_v_125_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = table_1[2];
  int stage_v_126_2 = table_2[2];
  table_1[2] = (table_1[3] + 253) & 63;
  table_2[2] = (table_2[3] + 253) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (st_var_1_1.buffer[0] ^ 130) & 3;
  int stage_v_127_2 = (st_var_1_2.buffer[0] ^ 130) & 3;
  switch (stage_v_127_1)
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

  switch (stage_v_127_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 129) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 129) & 15;
  int stage_v_128_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_128_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  chk_sum_1 ^= stage_v_128_1;
  chk_sum_2 ^= stage_v_128_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 130) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 130) & 15;
  int stage_v_129_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_129_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  chk_sum_1 ^= stage_v_129_1;
  chk_sum_2 ^= stage_v_129_2;
  int stage_v_130_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_130_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 132) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 132) & 15;
  int stage_v_131_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_131_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  chk_sum_1 ^= stage_v_131_1;
  chk_sum_2 ^= stage_v_131_2;
  int stage_v_132_1 = ((st_var_0_1.buffer[0] * 2) + 403) & 63;
  int stage_v_132_2 = ((st_var_0_2.buffer[0] * 2) + 403) & 63;
  if (stage_v_132_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_132_1) - 5) & 255;
    if (stage_v_132_1 > 51)
    {
      chk_sum_1 ^= stage_v_132_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_132_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_132_2) - 5) & 255;
    if (stage_v_132_2 > 51)
    {
      chk_sum_2 ^= stage_v_132_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_133_1 = table_1[1];
  int stage_v_133_2 = table_2[1];
  table_1[1] = (table_1[2] + 267) & 63;
  table_2[1] = (table_2[2] + 267) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 135) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 135) & 15;
  int stage_v_134_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_134_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= stage_v_134_1;
  chk_sum_2 ^= stage_v_134_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 136) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 136) & 15;
  int stage_v_135_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_135_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  chk_sum_1 ^= stage_v_135_1;
  chk_sum_2 ^= stage_v_135_2;
  int stage_v_136_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_136_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_136_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_136_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_137_1 = table_1[1];
  int stage_v_137_2 = table_2[1];
  table_1[1] = (table_1[2] + 275) & 63;
  table_2[1] = (table_2[2] + 275) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (143 & 31);
  int stage_v_138_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (143 & 31);
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  chk_sum_1 ^= (stage_v_138_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_138_2 << 1) & 127;
  int stage_v_139_1 = table_1[3];
  int stage_v_139_2 = table_2[3];
  table_1[3] = (table_1[0] + 279) & 63;
  table_2[3] = (table_2[0] + 279) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = table_1[0];
  int stage_v_140_2 = table_2[0];
  table_1[0] = (table_1[1] + 281) & 63;
  table_2[0] = (table_2[1] + 281) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 142) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 142) & 15;
  int stage_v_141_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_141_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= stage_v_141_1;
  chk_sum_2 ^= stage_v_141_2;
  int stage_v_142_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (147 & 31);
  int stage_v_142_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (147 & 31);
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= (stage_v_142_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_142_2 << 1) & 127;
  int stage_v_143_1 = (st_var_1_1.buffer[0] ^ 146) & 3;
  int stage_v_143_2 = (st_var_1_2.buffer[0] ^ 146) & 3;
  switch (stage_v_143_1)
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

  switch (stage_v_143_2)
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

  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_144_1 = ((stage_v_144_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 146) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 146) & 15;
  int stage_v_145_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_145_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  chk_sum_1 ^= stage_v_145_1;
  chk_sum_2 ^= stage_v_145_2;
  int stage_v_146_1 = ((st_var_0_1.buffer[2] * 2) + 445) & 63;
  int stage_v_146_2 = ((st_var_0_2.buffer[2] * 2) + 445) & 63;
  if (stage_v_146_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_146_1) - 5) & 255;
    if (stage_v_146_1 > 55)
    {
      chk_sum_1 ^= stage_v_146_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_146_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_146_2) - 5) & 255;
    if (stage_v_146_2 > 55)
    {
      chk_sum_2 ^= stage_v_146_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_147_1 = (st_var_1_1.buffer[0] ^ 150) & 3;
  int stage_v_147_2 = (st_var_1_2.buffer[0] ^ 150) & 3;
  switch (stage_v_147_1)
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

  switch (stage_v_147_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 149) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 149) & 15;
  int stage_v_148_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_148_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  chk_sum_1 ^= stage_v_148_1;
  chk_sum_2 ^= stage_v_148_2;
  int stage_v_149_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (154 & 31);
  int stage_v_149_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (154 & 31);
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  chk_sum_1 ^= (stage_v_149_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_149_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 151) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 151) & 15;
  int stage_v_150_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_150_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  chk_sum_1 ^= stage_v_150_1;
  chk_sum_2 ^= stage_v_150_2;
  int stage_v_151_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_151_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_151_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_151_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_152_1 = ((stage_v_152_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_152_2 = ((stage_v_152_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_153_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_153_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_153_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_154_1 = ((st_var_0_1.buffer[1] * 2) + 469) & 63;
  int stage_v_154_2 = ((st_var_0_2.buffer[1] * 2) + 469) & 63;
  if (stage_v_154_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_154_1) - 5) & 255;
    if (stage_v_154_1 > 32)
    {
      chk_sum_1 ^= stage_v_154_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_154_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_154_2) - 5) & 255;
    if (stage_v_154_2 > 32)
    {
      chk_sum_2 ^= stage_v_154_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_155_1 = (st_var_1_1.buffer[0] ^ 158) & 3;
  int stage_v_155_2 = (st_var_1_2.buffer[0] ^ 158) & 3;
  switch (stage_v_155_1)
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

  switch (stage_v_155_2)
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

  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_156_1 = ((stage_v_156_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_156_2 = ((stage_v_156_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((st_var_1_1.buffer[1] * 2) + 478) & 63;
  int stage_v_157_2 = ((st_var_1_2.buffer[1] * 2) + 478) & 63;
  if (stage_v_157_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_157_1) - 5) & 255;
    if (stage_v_157_1 > 36)
    {
      chk_sum_1 ^= stage_v_157_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_157_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_157_2) - 5) & 255;
    if (stage_v_157_2 > 36)
    {
      chk_sum_2 ^= stage_v_157_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 159) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 159) & 15;
  int stage_v_158_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_158_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  chk_sum_1 ^= stage_v_158_1;
  chk_sum_2 ^= stage_v_158_2;
  int stage_v_159_1 = table_1[3];
  int stage_v_159_2 = table_2[3];
  table_1[3] = (table_1[0] + 319) & 63;
  table_2[3] = (table_2[0] + 319) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 161) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 161) & 15;
  int stage_v_160_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_160_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  chk_sum_1 ^= stage_v_160_1;
  chk_sum_2 ^= stage_v_160_2;
  int stage_v_161_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_161_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_161_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_161_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 163) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 163) & 15;
  int stage_v_162_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_162_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  chk_sum_1 ^= stage_v_162_1;
  chk_sum_2 ^= stage_v_162_2;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_163_1 = ((stage_v_163_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_163_2 = ((stage_v_163_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (st_var_0_1.buffer[0] ^ 167) & 3;
  int stage_v_164_2 = (st_var_0_2.buffer[0] ^ 167) & 3;
  switch (stage_v_164_1)
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

  switch (stage_v_164_2)
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

  int stage_v_165_1 = ((st_var_1_1.buffer[0] * 2) + 502) & 63;
  int stage_v_165_2 = ((st_var_1_2.buffer[0] * 2) + 502) & 63;
  if (stage_v_165_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_165_1) - 5) & 255;
    if (stage_v_165_1 > 29)
    {
      chk_sum_1 ^= stage_v_165_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_165_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_165_2) - 5) & 255;
    if (stage_v_165_2 > 29)
    {
      chk_sum_2 ^= stage_v_165_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_166_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_166_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_167_1 = ((stage_v_167_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_167_2 = ((stage_v_167_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_168_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_168_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_168_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_169_1 = table_1[1];
  int stage_v_169_2 = table_2[1];
  table_1[1] = (table_1[2] + 339) & 63;
  table_2[1] = (table_2[2] + 339) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_170_1 = ((stage_v_170_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_170_2 = ((stage_v_170_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (st_var_1_1.buffer[0] ^ 174) & 3;
  int stage_v_171_2 = (st_var_1_2.buffer[0] ^ 174) & 3;
  switch (stage_v_171_1)
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

  switch (stage_v_171_2)
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

  int stage_v_172_1 = ((st_var_0_1.buffer[1] * 2) + 523) & 63;
  int stage_v_172_2 = ((st_var_0_2.buffer[1] * 2) + 523) & 63;
  if (stage_v_172_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_172_1) - 5) & 255;
    if (stage_v_172_1 > 32)
    {
      chk_sum_1 ^= stage_v_172_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_172_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_172_2) - 5) & 255;
    if (stage_v_172_2 > 32)
    {
      chk_sum_2 ^= stage_v_172_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_173_1 = table_1[1];
  int stage_v_173_2 = table_2[1];
  table_1[1] = (table_1[2] + 347) & 63;
  table_2[1] = (table_2[2] + 347) & 63;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((st_var_0_1.buffer[0] * 2) + 529) & 63;
  int stage_v_174_2 = ((st_var_0_2.buffer[0] * 2) + 529) & 63;
  if (stage_v_174_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_174_1) - 5) & 255;
    if (stage_v_174_1 > 38)
    {
      chk_sum_1 ^= stage_v_174_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_174_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_174_2) - 5) & 255;
    if (stage_v_174_2 > 38)
    {
      chk_sum_2 ^= stage_v_174_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_175_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (180 & 31);
  int stage_v_175_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (180 & 31);
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  chk_sum_1 ^= (stage_v_175_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_175_2 << 1) & 127;
  int stage_v_176_1 = ((st_var_0_1.buffer[2] * 2) + 535) & 63;
  int stage_v_176_2 = ((st_var_0_2.buffer[2] * 2) + 535) & 63;
  if (stage_v_176_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_176_1) - 5) & 255;
    if (stage_v_176_1 > 43)
    {
      chk_sum_1 ^= stage_v_176_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_176_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_176_2) - 5) & 255;
    if (stage_v_176_2 > 43)
    {
      chk_sum_2 ^= stage_v_176_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_177_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (182 & 31);
  int stage_v_177_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (182 & 31);
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  chk_sum_1 ^= (stage_v_177_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_177_2 << 1) & 127;
  int stage_v_178_1 = 0;
  int stage_v_178_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_178_1 = ((stage_v_178_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_178_2 = ((stage_v_178_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = table_1[3];
  int stage_v_179_2 = table_2[3];
  table_1[3] = (table_1[0] + 359) & 63;
  table_2[3] = (table_2[0] + 359) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (st_var_0_1.buffer[0] ^ 183) & 3;
  int stage_v_180_2 = (st_var_0_2.buffer[0] ^ 183) & 3;
  switch (stage_v_180_1)
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

  switch (stage_v_180_2)
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

  int stage_v_181_1 = 0;
  int stage_v_181_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_181_1 = ((stage_v_181_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_181_2 = ((stage_v_181_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = 0;
  int stage_v_182_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_182_1 = ((stage_v_182_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_182_2 = ((stage_v_182_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 184) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 184) & 15;
  int stage_v_183_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_183_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  chk_sum_1 ^= stage_v_183_1;
  chk_sum_2 ^= stage_v_183_2;
  int stage_v_184_1 = 0;
  int stage_v_184_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_184_1 = ((stage_v_184_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_184_2 = ((stage_v_184_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (st_var_1_1.buffer[0] ^ 188) & 3;
  int stage_v_185_2 = (st_var_1_2.buffer[0] ^ 188) & 3;
  switch (stage_v_185_1)
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

  switch (stage_v_185_2)
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

  int stage_v_186_1 = table_1[2];
  int stage_v_186_2 = table_2[2];
  table_1[2] = (table_1[3] + 373) & 63;
  table_2[2] = (table_2[3] + 373) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = 0;
  int stage_v_187_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_187_1 = ((stage_v_187_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_187_2 = ((stage_v_187_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = table_1[0];
  int stage_v_188_2 = table_2[0];
  table_1[0] = (table_1[1] + 377) & 63;
  table_2[0] = (table_2[1] + 377) & 63;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((st_var_1_1.buffer[0] * 2) + 574) & 63;
  int stage_v_189_2 = ((st_var_1_2.buffer[0] * 2) + 574) & 63;
  if (stage_v_189_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_189_1) - 5) & 255;
    if (stage_v_189_1 > 44)
    {
      chk_sum_1 ^= stage_v_189_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_189_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_189_2) - 5) & 255;
    if (stage_v_189_2 > 44)
    {
      chk_sum_2 ^= stage_v_189_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 191) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 191) & 15;
  int stage_v_190_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_190_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  chk_sum_1 ^= stage_v_190_1;
  chk_sum_2 ^= stage_v_190_2;
  int stage_v_191_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (196 & 31);
  int stage_v_191_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (196 & 31);
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  chk_sum_1 ^= (stage_v_191_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_191_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 193) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 193) & 15;
  int stage_v_192_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_192_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  chk_sum_1 ^= stage_v_192_1;
  chk_sum_2 ^= stage_v_192_2;
  int stage_v_193_1 = ((st_var_1_1.buffer[1] * 2) + 586) & 63;
  int stage_v_193_2 = ((st_var_1_2.buffer[1] * 2) + 586) & 63;
  if (stage_v_193_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_193_1) - 5) & 255;
    if (stage_v_193_1 > 43)
    {
      chk_sum_1 ^= stage_v_193_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_193_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_193_2) - 5) & 255;
    if (stage_v_193_2 > 43)
    {
      chk_sum_2 ^= stage_v_193_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_194_1 = table_1[2];
  int stage_v_194_2 = table_2[2];
  table_1[2] = (table_1[3] + 389) & 63;
  table_2[2] = (table_2[3] + 389) & 63;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 196) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 196) & 15;
  int stage_v_195_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_195_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  chk_sum_1 ^= stage_v_195_1;
  chk_sum_2 ^= stage_v_195_2;
  int stage_v_196_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_196_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_196_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_196_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 198) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 198) & 15;
  int stage_v_197_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_197_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  chk_sum_1 ^= stage_v_197_1;
  chk_sum_2 ^= stage_v_197_2;
  int stage_v_198_1 = table_1[2];
  int stage_v_198_2 = table_2[2];
  table_1[2] = (table_1[3] + 397) & 63;
  table_2[2] = (table_2[3] + 397) & 63;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = 0;
  int stage_v_199_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_199_1 = ((stage_v_199_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_199_2 = ((stage_v_199_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = 0;
  int stage_v_200_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_200_1 = ((stage_v_200_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_200_2 = ((stage_v_200_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 202) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 202) & 15;
  int stage_v_201_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_201_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  chk_sum_1 ^= stage_v_201_1;
  chk_sum_2 ^= stage_v_201_2;
  int stage_v_202_1 = ((st_var_0_1.buffer[1] * 2) + 613) & 63;
  int stage_v_202_2 = ((st_var_0_2.buffer[1] * 2) + 613) & 63;
  if (stage_v_202_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_202_1) - 5) & 255;
    if (stage_v_202_1 > 29)
    {
      chk_sum_1 ^= stage_v_202_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_202_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_202_2) - 5) & 255;
    if (stage_v_202_2 > 29)
    {
      chk_sum_2 ^= stage_v_202_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_203_1 = 0;
  int stage_v_203_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_203_1 = ((stage_v_203_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_203_2 = ((stage_v_203_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((st_var_0_1.buffer[0] * 2) + 619) & 63;
  int stage_v_204_2 = ((st_var_0_2.buffer[0] * 2) + 619) & 63;
  if (stage_v_204_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_204_1) - 5) & 255;
    if (stage_v_204_1 > 34)
    {
      chk_sum_1 ^= stage_v_204_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_204_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_204_2) - 5) & 255;
    if (stage_v_204_2 > 34)
    {
      chk_sum_2 ^= stage_v_204_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_205_1 = table_1[1];
  int stage_v_205_2 = table_2[1];
  table_1[1] = (table_1[2] + 411) & 63;
  table_2[1] = (table_2[2] + 411) & 63;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = 0;
  int stage_v_206_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_206_1 = ((stage_v_206_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_206_2 = ((stage_v_206_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 208) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 208) & 15;
  int stage_v_207_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_207_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  chk_sum_1 ^= stage_v_207_1;
  chk_sum_2 ^= stage_v_207_2;
  int stage_v_208_1 = 0;
  int stage_v_208_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_208_1 = ((stage_v_208_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_208_2 = ((stage_v_208_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_209_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_209_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_209_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_210_1 = (st_var_0_1.buffer[0] ^ 213) & 3;
  int stage_v_210_2 = (st_var_0_2.buffer[0] ^ 213) & 3;
  switch (stage_v_210_1)
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

  switch (stage_v_210_2)
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

  int stage_v_211_1 = (st_var_1_1.buffer[0] ^ 214) & 3;
  int stage_v_211_2 = (st_var_1_2.buffer[0] ^ 214) & 3;
  switch (stage_v_211_1)
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

  switch (stage_v_211_2)
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

  int stage_v_212_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (217 & 31);
  int stage_v_212_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (217 & 31);
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  chk_sum_1 ^= (stage_v_212_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_212_2 << 1) & 127;
  int stage_v_213_1 = (st_var_1_1.buffer[0] ^ 216) & 3;
  int stage_v_213_2 = (st_var_1_2.buffer[0] ^ 216) & 3;
  switch (stage_v_213_1)
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

  switch (stage_v_213_2)
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

  int b_w0_1 = (sec_r000473_1_1 ^ 0x5A) & 63;
  int b_w0_2 = (sec_r000473_1_2 ^ 0x5A) & 63;
  int b_w1_1 = ((b_w0_1 << 1) ^ (sec_r000473_16_1 >> 1)) & 63;
  int b_w1_2 = ((b_w0_2 << 1) ^ (sec_r000473_16_2 >> 1)) & 63;
  int b_w2_1 = ((b_w1_1 << 2) ^ (sec_r000473_1_1 >> 2)) & 63;
  int b_w2_2 = ((b_w1_2 << 2) ^ (sec_r000473_1_2 >> 2)) & 63;
  int b_w3_1 = ((b_w2_1 << 2) | (sec_r000473_16_1 >> 2)) & 63;
  int b_w3_2 = ((b_w2_2 << 2) | (sec_r000473_16_2 >> 2)) & 63;
  out_sink_1 += b_w3_1 & 63;
  out_sink_2 += b_w3_2 & 63;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000473_4_1 != sec_r000473_4_2);
  __CPROVER_assume(sec_r000473_14_1 != sec_r000473_14_2);
  __CPROVER_assume(sec_r000473_5_1 != sec_r000473_5_2);
  __CPROVER_assume(sec_r000473_16_1 != sec_r000473_16_2);
  __CPROVER_assume(sec_r000473_7_1 != sec_r000473_7_2);
  __CPROVER_assume(sec_r000473_15_1 != sec_r000473_15_2);
  __CPROVER_assume(sec_r000473_1_1 != sec_r000473_1_2);
  __CPROVER_assume(pub_r000473_13_1 == pub_r000473_13_2);
  __CPROVER_assume(sec_r000473_3_1 != sec_r000473_3_2);
  __CPROVER_assume(sec_r000473_8_1 != sec_r000473_8_2);
  __CPROVER_assume(sec_r000473_10_1 != sec_r000473_10_2);
  __CPROVER_assume(pub_r000473_14_1 == pub_r000473_14_2);
  __CPROVER_assume(sec_r000473_6_1 != sec_r000473_6_2);
  __CPROVER_assume(pub_r000473_15_1 == pub_r000473_15_2);
  __CPROVER_assume(pub_r000473_8_1 == pub_r000473_8_2);
  __CPROVER_assume(pub_r000473_7_1 == pub_r000473_7_2);
  __CPROVER_assume(sec_r000473_12_1 != sec_r000473_12_2);
  __CPROVER_assume(sec_r000473_11_1 != sec_r000473_11_2);
  __CPROVER_assume(sec_r000473_9_1 != sec_r000473_9_2);
  __CPROVER_assume(pub_r000473_10_1 == pub_r000473_10_2);
  __CPROVER_assume(pub_r000473_9_1 == pub_r000473_9_2);
  __CPROVER_assume(pub_r000473_0_1 == pub_r000473_0_2);
  __CPROVER_assume(sec_r000473_18_1 != sec_r000473_18_2);
  __CPROVER_assume(sec_r000473_0_1 != sec_r000473_0_2);
  __CPROVER_assume(sec_r000473_13_1 != sec_r000473_13_2);
  __CPROVER_assume(pub_r000473_6_1 == pub_r000473_6_2);
  __CPROVER_assume(pub_r000473_5_1 == pub_r000473_5_2);
  __CPROVER_assume(pub_r000473_4_1 == pub_r000473_4_2);
  __CPROVER_assume(pub_r000473_1_1 == pub_r000473_1_2);
  __CPROVER_assume(pub_r000473_3_1 == pub_r000473_3_2);
  __CPROVER_assume(sec_r000473_2_1 != sec_r000473_2_2);
  __CPROVER_assume(pub_r000473_11_1 == pub_r000473_11_2);
  __CPROVER_assume(sec_r000473_17_1 != sec_r000473_17_2);
  __CPROVER_assume(pub_r000473_12_1 == pub_r000473_12_2);
  __CPROVER_assume(pub_r000473_2_1 == pub_r000473_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.reading == st_var_1_2.reading);
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
  assert(b_w0_1 == b_w0_2);
  assert(b_w1_1 == b_w1_2);
  assert(b_w2_1 == b_w2_2);
  assert(b_w3_1 == b_w3_2);
}


