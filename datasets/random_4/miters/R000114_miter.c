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
struct StreamBuffer_R000114_1413_0
{
  int checksum;
  int head;
  int watermark;
  short state;
  int capacity;
  int tail;
  int buffer[3];
};
struct SensorNode_R000114_1413_1
{
  short calib;
  int reading;
  int offset;
  int threshold;
  int status;
  int buffer[3];
};
struct DeviceConfig_R000114_1413_2
{
  int stop_bits;
  unsigned char parity;
  int port;
  int timeout;
  int buffer[3];
};
union TelemetryField_R000114_1413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000114_1413_1
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
void fn_R000114_1413_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st_1 = {0};
  struct DeviceConfig_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int sample_61_1 = 0;
  int sample_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_61_1 = ((sample_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_61_2 = ((sample_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_61_1) & 127;
    acc_2 = (acc_2 + sample_61_2) & 127;
  }

  int scale_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_24_1 > 30)
  {
    acc_1 = ((acc_1 + (scale_24_1 * 2)) + 5) & 127;
    aux_1 ^= scale_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_24_2 > 30)
  {
    acc_2 = ((acc_2 + (scale_24_2 * 2)) + 5) & 127;
    aux_2 ^= scale_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_61_1 == sample_61_2);
  assert(scale_24_1 == scale_24_2);
}

int fn_R000114_1413_0(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int sample_61 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_61 = ((sample_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_61) & 127;
  }

  int scale_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_24 > 30)
  {
    acc = ((acc + (scale_24 * 2)) + 5) & 127;
    aux ^= scale_24 & 15;
  }
  else
  {
    acc = ((acc - scale_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000114_1413_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st_1 = {0};
  struct DeviceConfig_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quantum_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_84_1 > 45)
  {
    acc_1 = ((acc_1 + (quantum_84_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_84_2 > 45)
  {
    acc_2 = ((acc_2 + (quantum_84_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_96_1 = 0;
  int vector_96_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_96_1 = ((vector_96_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_96_2 = ((vector_96_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_96_1) & 127;
    acc_2 = (acc_2 + vector_96_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_84_1 == quantum_84_2);
  assert(vector_96_1 == vector_96_2);
}

int fn_R000114_1413_1(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quantum_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_84 > 45)
  {
    acc = ((acc + (quantum_84 * 2)) + 5) & 127;
    aux ^= quantum_84 & 15;
  }
  else
  {
    acc = ((acc - quantum_84) + 11) & 127;
    aux += 3;
  }
  int vector_96 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_96 = ((vector_96 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_96) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000114_1413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st_1 = {0};
  struct SensorNode_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int window_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_80_1 > 19)
  {
    acc_1 = ((acc_1 + (window_80_1 * 2)) + 5) & 127;
    aux_1 ^= window_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_80_2 > 19)
  {
    acc_2 = ((acc_2 + (window_80_2 * 2)) + 5) & 127;
    aux_2 ^= window_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_80_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_80_1 == window_80_2);
}

int fn_R000114_1413_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int window_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_80 > 19)
  {
    acc = ((acc + (window_80 * 2)) + 5) & 127;
    aux ^= window_80 & 15;
  }
  else
  {
    acc = ((acc - window_80) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st_1 = {0};
  struct DeviceConfig_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_56_1 = 0;
  int sample_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_56_1 = ((sample_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_56_2 = ((sample_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_56_1) & 127;
    acc_2 = (acc_2 + sample_56_2) & 127;
  }

  int factor_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_66_1)
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

  switch (factor_66_2)
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

  int tally_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_23_1) & 63;
  aux_2 = (aux_2 + tally_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_56_1 == sample_56_2);
  assert(factor_66_1 == factor_66_2);
  assert(tally_23_1 == tally_23_2);
}

int fn_R000114_1413_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_56 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_56 = ((sample_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_56) & 127;
  }

  int factor_66 = (aux + st.buffer[1]) & 3;
  switch (factor_66)
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

  int tally_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_23) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000114_1413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st_1 = {0};
  struct StreamBuffer_R000114_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int tally_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_28_1)
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

  switch (tally_28_2)
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

  int threshold_14_1 = 0;
  int threshold_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_14_1 = ((threshold_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_14_2 = ((threshold_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_14_1) & 127;
    acc_2 = (acc_2 + threshold_14_2) & 127;
  }

  int pivot_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_64_1 > 38)
  {
    acc_1 = ((acc_1 + (pivot_64_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_64_2 > 38)
  {
    acc_2 = ((acc_2 + (pivot_64_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_28_1 == tally_28_2);
  assert(threshold_14_1 == threshold_14_2);
  assert(pivot_64_1 == pivot_64_2);
}

int fn_R000114_1413_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int tally_28 = (aux + st.buffer[1]) & 3;
  switch (tally_28)
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

  int threshold_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_14 = ((threshold_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_14) & 127;
  }

  int pivot_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_64 > 38)
  {
    acc = ((acc + (pivot_64 * 2)) + 5) & 127;
    aux ^= pivot_64 & 15;
  }
  else
  {
    acc = ((acc - pivot_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000114_1413_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st_1 = {0};
  struct DeviceConfig_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int factor_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_72_1) & 63;
  aux_2 = (aux_2 + factor_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_17_1 = local_arr_1[aux_1 % 3];
  int bound_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_17_2 * 2)) & 127;
  int index_reg_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_99_1 > 48)
  {
    acc_1 = ((acc_1 + (index_reg_99_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_99_2 > 48)
  {
    acc_2 = ((acc_2 + (index_reg_99_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_72_1 == factor_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_17_1 == bound_17_2);
  assert(index_reg_99_1 == index_reg_99_2);
}

int fn_R000114_1413_5(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int factor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_72) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_17 = local_arr[aux % 3];
  acc = (acc + (bound_17 * 2)) & 127;
  int index_reg_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_99 > 48)
  {
    acc = ((acc + (index_reg_99 * 2)) + 5) & 127;
    aux ^= index_reg_99 & 15;
  }
  else
  {
    acc = ((acc - index_reg_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000114_1413_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st_1 = {0};
  struct StreamBuffer_R000114_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_67_1) & 63;
  aux_2 = (aux_2 + margin_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_15_1 = local_arr_1[aux_1 % 3];
  int tally_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_15_2 * 2)) & 127;
  int sample_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_82_1 > 28)
  {
    acc_1 = ((acc_1 + (sample_82_1 * 2)) + 5) & 127;
    aux_1 ^= sample_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_82_2 > 28)
  {
    acc_2 = ((acc_2 + (sample_82_2 * 2)) + 5) & 127;
    aux_2 ^= sample_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_67_1 == margin_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_15_1 == tally_15_2);
  assert(sample_82_1 == sample_82_2);
}

int fn_R000114_1413_6(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_15 = local_arr[aux % 3];
  acc = (acc + (tally_15 * 2)) & 127;
  int sample_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_82 > 28)
  {
    acc = ((acc + (sample_82 * 2)) + 5) & 127;
    aux ^= sample_82 & 15;
  }
  else
  {
    acc = ((acc - sample_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000114_1413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st_1 = {0};
  struct StreamBuffer_R000114_1413_0 st_2 = {0};
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
  int quantum_92_1 = 0;
  int quantum_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_92_1 = ((quantum_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_92_2 = ((quantum_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_92_1) & 127;
    acc_2 = (acc_2 + quantum_92_2) & 127;
  }

  int stride_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_71_1) & 63;
  aux_2 = (aux_2 + stride_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_92_1 == quantum_92_2);
  assert(stride_71_1 == stride_71_2);
}

int fn_R000114_1413_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_92 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_92 = ((quantum_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_92) & 127;
  }

  int stride_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_71) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000114_1413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st_1 = {0};
  struct StreamBuffer_R000114_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_83_1 = local_arr_1[aux_1 % 3];
  int index_reg_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_83_2 * 2)) & 127;
  int mask_37_1 = 0;
  int mask_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_37_1 = ((mask_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_37_2 = ((mask_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_37_1) & 127;
    acc_2 = (acc_2 + mask_37_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_83_1 == index_reg_83_2);
  assert(mask_37_1 == mask_37_2);
}

int fn_R000114_1413_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int index_reg_83 = local_arr[aux % 3];
  acc = (acc + (index_reg_83 * 2)) & 127;
  int mask_37 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_37 = ((mask_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_37) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st_1 = {0};
  struct SensorNode_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_83_1 = local_arr_1[aux_1 % 3];
  int tally_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_83_2 * 2)) & 127;
  int segment_25_1 = 0;
  int segment_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_25_1 = ((segment_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_25_2 = ((segment_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_25_1) & 127;
    acc_2 = (acc_2 + segment_25_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_76_1 > 36)
  {
    acc_1 = ((acc_1 + (anchor_76_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_76_2 > 36)
  {
    acc_2 = ((acc_2 + (anchor_76_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_76_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_83_1 == tally_83_2);
  assert(segment_25_1 == segment_25_2);
  assert(anchor_76_1 == anchor_76_2);
}

int fn_R000114_1413_9(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int tally_83 = local_arr[aux % 3];
  acc = (acc + (tally_83 * 2)) & 127;
  int segment_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_25 = ((segment_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_25) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_76 > 36)
  {
    acc = ((acc + (anchor_76 * 2)) + 5) & 127;
    aux ^= anchor_76 & 15;
  }
  else
  {
    acc = ((acc - anchor_76) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000114_1413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st_1 = {0};
  struct SensorNode_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int coefficient_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_41_1)
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

  switch (coefficient_41_2)
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
  int bound_40_1 = local_arr_1[aux_1 % 3];
  int bound_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_40_2 * 2)) & 127;
  int index_reg_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_26_1 > 18)
  {
    acc_1 = ((acc_1 + (index_reg_26_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_26_2 > 18)
  {
    acc_2 = ((acc_2 + (index_reg_26_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_26_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_41_1 == coefficient_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_40_1 == bound_40_2);
  assert(index_reg_26_1 == index_reg_26_2);
}

int fn_R000114_1413_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int coefficient_41 = (aux + st.buffer[1]) & 3;
  switch (coefficient_41)
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
  int bound_40 = local_arr[aux % 3];
  acc = (acc + (bound_40 * 2)) & 127;
  int index_reg_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_26 > 18)
  {
    acc = ((acc + (index_reg_26 * 2)) + 5) & 127;
    aux ^= index_reg_26 & 15;
  }
  else
  {
    acc = ((acc - index_reg_26) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st_1 = {0};
  struct SensorNode_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_46_1 = 0;
  int scale_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_46_1 = ((scale_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_46_2 = ((scale_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_46_1) & 127;
    acc_2 = (acc_2 + scale_46_2) & 127;
  }

  int quantum_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_40_1)
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

  switch (quantum_40_2)
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
  int delta_66_1 = local_arr_1[aux_1 % 3];
  int delta_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_46_1 == scale_46_2);
  assert(quantum_40_1 == quantum_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_66_1 == delta_66_2);
}

int fn_R000114_1413_11(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_46 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_46 = ((scale_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_46) & 127;
  }

  int quantum_40 = (aux + st.buffer[1]) & 3;
  switch (quantum_40)
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
  int delta_66 = local_arr[aux % 3];
  acc = (acc + (delta_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st_1 = {0};
  struct SensorNode_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int delta_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_16_1 > 24)
  {
    acc_1 = ((acc_1 + (delta_16_1 * 2)) + 5) & 127;
    aux_1 ^= delta_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_16_2 > 24)
  {
    acc_2 = ((acc_2 + (delta_16_2 * 2)) + 5) & 127;
    aux_2 ^= delta_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_42_1 = local_arr_1[aux_1 % 3];
  int scale_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_42_2 * 2)) & 127;
  int mask_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_15_1) & 63;
  aux_2 = (aux_2 + mask_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_33_1 = 0;
  int cursor_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_33_1 = ((cursor_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_33_2 = ((cursor_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_33_1) & 127;
    acc_2 = (acc_2 + cursor_33_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_16_1 == delta_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_42_1 == scale_42_2);
  assert(mask_15_1 == mask_15_2);
  assert(cursor_33_1 == cursor_33_2);
}

int fn_R000114_1413_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int delta_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_16 > 24)
  {
    acc = ((acc + (delta_16 * 2)) + 5) & 127;
    aux ^= delta_16 & 15;
  }
  else
  {
    acc = ((acc - delta_16) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int scale_42 = local_arr[aux % 3];
  acc = (acc + (scale_42 * 2)) & 127;
  int mask_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_15) & 63;
  acc ^= aux;
  int cursor_33 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_33 = ((cursor_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_33) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000114_1413_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st_1 = {0};
  struct DeviceConfig_R000114_1413_2 st_2 = {0};
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
  int metric_64_1 = 0;
  int metric_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_64_1 = ((metric_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_64_2 = ((metric_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_64_1) & 127;
    acc_2 = (acc_2 + metric_64_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_55_1 = local_arr_1[aux_1 % 3];
  int pivot_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_55_2 * 2)) & 127;
  int coefficient_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_82_1 > 24)
  {
    acc_1 = ((acc_1 + (coefficient_82_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_82_2 > 24)
  {
    acc_2 = ((acc_2 + (coefficient_82_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_64_1 == metric_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_55_1 == pivot_55_2);
  assert(coefficient_82_1 == coefficient_82_2);
}

int fn_R000114_1413_13(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_64 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_64 = ((metric_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_64) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_55 = local_arr[aux % 3];
  acc = (acc + (pivot_55 * 2)) & 127;
  int coefficient_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_82 > 24)
  {
    acc = ((acc + (coefficient_82 * 2)) + 5) & 127;
    aux ^= coefficient_82 & 15;
  }
  else
  {
    acc = ((acc - coefficient_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000114_1413_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st_1 = {0};
  struct SensorNode_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int weight_98_1 = 0;
  int weight_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_98_1 = ((weight_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_98_2 = ((weight_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_98_1) & 127;
    acc_2 = (acc_2 + weight_98_2) & 127;
  }

  int bound_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_55_1) & 63;
  aux_2 = (aux_2 + bound_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_98_1 == weight_98_2);
  assert(bound_55_1 == bound_55_2);
}

int fn_R000114_1413_14(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int weight_98 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_98 = ((weight_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_98) & 127;
  }

  int bound_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_55) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st_1 = {0};
  struct StreamBuffer_R000114_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_38_1 = local_arr_1[aux_1 % 3];
  int parity_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_38_2 * 2)) & 127;
  int vector_10_1 = 0;
  int vector_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_10_1 = ((vector_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_10_2 = ((vector_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_10_1) & 127;
    acc_2 = (acc_2 + vector_10_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_38_1 == parity_38_2);
  assert(vector_10_1 == vector_10_2);
}

int fn_R000114_1413_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int parity_38 = local_arr[aux % 3];
  acc = (acc + (parity_38 * 2)) & 127;
  int vector_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_10 = ((vector_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_10) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000114_1413_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st_1 = {0};
  struct DeviceConfig_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int window_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_20_1)
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

  switch (window_20_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_20_1 == window_20_2);
}

int fn_R000114_1413_16(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int window_20 = (aux + st.buffer[1]) & 3;
  switch (window_20)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st_1 = {0};
  struct StreamBuffer_R000114_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_36_1 = local_arr_1[aux_1 % 3];
  int tally_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_36_2 * 2)) & 127;
  int vector_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_35_1) & 63;
  aux_2 = (aux_2 + vector_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_59_1 > 39)
  {
    acc_1 = ((acc_1 + (accumulator_59_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_59_2 > 39)
  {
    acc_2 = ((acc_2 + (accumulator_59_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_36_1 == tally_36_2);
  assert(vector_35_1 == vector_35_2);
  assert(accumulator_59_1 == accumulator_59_2);
}

int fn_R000114_1413_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int tally_36 = local_arr[aux % 3];
  acc = (acc + (tally_36 * 2)) & 127;
  int vector_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_35) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_59 > 39)
  {
    acc = ((acc + (accumulator_59 * 2)) + 5) & 127;
    aux ^= accumulator_59 & 15;
  }
  else
  {
    acc = ((acc - accumulator_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000114_1413_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st_1 = {0};
  struct SensorNode_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int mask_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_91_1 > 50)
  {
    acc_1 = ((acc_1 + (mask_91_1 * 2)) + 5) & 127;
    aux_1 ^= mask_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_91_2 > 50)
  {
    acc_2 = ((acc_2 + (mask_91_2 * 2)) + 5) & 127;
    aux_2 ^= mask_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_57_1 = 0;
  int accumulator_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_57_1 = ((accumulator_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_57_2 = ((accumulator_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_57_1) & 127;
    acc_2 = (acc_2 + accumulator_57_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_91_1 == mask_91_2);
  assert(accumulator_57_1 == accumulator_57_2);
}

int fn_R000114_1413_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int mask_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_91 > 50)
  {
    acc = ((acc + (mask_91 * 2)) + 5) & 127;
    aux ^= mask_91 & 15;
  }
  else
  {
    acc = ((acc - mask_91) + 11) & 127;
    aux += 3;
  }
  int accumulator_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_57 = ((accumulator_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_57) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000114_1413_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st_1 = {0};
  struct DeviceConfig_R000114_1413_2 st_2 = {0};
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
  int anchor_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_21_1 > 40)
  {
    acc_1 = ((acc_1 + (anchor_21_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_21_2 > 40)
  {
    acc_2 = ((acc_2 + (anchor_21_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_22_1 = 0;
  int segment_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_22_1 = ((segment_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_22_2 = ((segment_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_22_1) & 127;
    acc_2 = (acc_2 + segment_22_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_21_1 == anchor_21_2);
  assert(segment_22_1 == segment_22_2);
}

int fn_R000114_1413_19(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_21 > 40)
  {
    acc = ((acc + (anchor_21 * 2)) + 5) & 127;
    aux ^= anchor_21 & 15;
  }
  else
  {
    acc = ((acc - anchor_21) + 11) & 127;
    aux += 3;
  }
  int segment_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_22 = ((segment_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_22) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000114_1413_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st_1 = {0};
  struct SensorNode_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int quantum_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_20_1 > 15)
  {
    acc_1 = ((acc_1 + (quantum_20_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_20_2 > 15)
  {
    acc_2 = ((acc_2 + (quantum_20_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_75_1)
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

  switch (margin_75_2)
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

  int pivot_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_66_1) & 63;
  aux_2 = (aux_2 + pivot_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_20_1 == quantum_20_2);
  assert(margin_75_1 == margin_75_2);
  assert(pivot_66_1 == pivot_66_2);
}

int fn_R000114_1413_20(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int quantum_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_20 > 15)
  {
    acc = ((acc + (quantum_20 * 2)) + 5) & 127;
    aux ^= quantum_20 & 15;
  }
  else
  {
    acc = ((acc - quantum_20) + 11) & 127;
    aux += 3;
  }
  int margin_75 = (aux + st.buffer[1]) & 3;
  switch (margin_75)
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

  int pivot_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_66) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000114_1413_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st_1 = {0};
  struct DeviceConfig_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int sample_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_30_1 > 22)
  {
    acc_1 = ((acc_1 + (sample_30_1 * 2)) + 5) & 127;
    aux_1 ^= sample_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_30_2 > 22)
  {
    acc_2 = ((acc_2 + (sample_30_2 * 2)) + 5) & 127;
    aux_2 ^= sample_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_14_1 = local_arr_1[aux_1 % 3];
  int parity_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_14_2 * 2)) & 127;
  int threshold_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_62_1) & 63;
  aux_2 = (aux_2 + threshold_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_30_1 == sample_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_14_1 == parity_14_2);
  assert(threshold_62_1 == threshold_62_2);
}

int fn_R000114_1413_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int sample_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_30 > 22)
  {
    acc = ((acc + (sample_30 * 2)) + 5) & 127;
    aux ^= sample_30 & 15;
  }
  else
  {
    acc = ((acc - sample_30) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_14 = local_arr[aux % 3];
  acc = (acc + (parity_14 * 2)) & 127;
  int threshold_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000114_1413_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st_1 = {0};
  struct StreamBuffer_R000114_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int accumulator_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_81_1) & 63;
  aux_2 = (aux_2 + accumulator_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_89_1 > 19)
  {
    acc_1 = ((acc_1 + (offset_89_1 * 2)) + 5) & 127;
    aux_1 ^= offset_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_89_2 > 19)
  {
    acc_2 = ((acc_2 + (offset_89_2 * 2)) + 5) & 127;
    aux_2 ^= offset_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_81_1 == accumulator_81_2);
  assert(offset_89_1 == offset_89_2);
}

int fn_R000114_1413_22(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int accumulator_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_81) & 63;
  acc ^= aux;
  int offset_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_89 > 19)
  {
    acc = ((acc + (offset_89 * 2)) + 5) & 127;
    aux ^= offset_89 & 15;
  }
  else
  {
    acc = ((acc - offset_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000114_1413_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st_1 = {0};
  struct DeviceConfig_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int sample_25_1 = 0;
  int sample_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_25_1 = ((sample_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_25_2 = ((sample_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_25_1) & 127;
    acc_2 = (acc_2 + sample_25_2) & 127;
  }

  int delta_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_13_1 > 11)
  {
    acc_1 = ((acc_1 + (delta_13_1 * 2)) + 5) & 127;
    aux_1 ^= delta_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_13_2 > 11)
  {
    acc_2 = ((acc_2 + (delta_13_2 * 2)) + 5) & 127;
    aux_2 ^= delta_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_96_1 = local_arr_1[aux_1 % 3];
  int vector_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_96_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_25_1 == sample_25_2);
  assert(delta_13_1 == delta_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_96_1 == vector_96_2);
}

int fn_R000114_1413_23(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int sample_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_25 = ((sample_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_25) & 127;
  }

  int delta_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_13 > 11)
  {
    acc = ((acc + (delta_13 * 2)) + 5) & 127;
    aux ^= delta_13 & 15;
  }
  else
  {
    acc = ((acc - delta_13) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_96 = local_arr[aux % 3];
  acc = (acc + (vector_96 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_24_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st_1 = {0};
  struct StreamBuffer_R000114_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int residue_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_85_1) & 63;
  aux_2 = (aux_2 + residue_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_84_1)
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

  switch (index_reg_84_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_85_1 == residue_85_2);
  assert(index_reg_84_1 == index_reg_84_2);
}

int fn_R000114_1413_24(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int residue_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_85) & 63;
  acc ^= aux;
  int index_reg_84 = (aux + st.buffer[1]) & 3;
  switch (index_reg_84)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000114_0_1;
  int sec_r000114_0_2;
  int sec_r000114_1_1;
  int sec_r000114_1_2;
  int sec_r000114_2_1;
  int sec_r000114_2_2;
  int sec_r000114_3_1;
  int sec_r000114_3_2;
  int sec_r000114_4_1;
  int sec_r000114_4_2;
  int sec_r000114_5_1;
  int sec_r000114_5_2;
  int sec_r000114_6_1;
  int sec_r000114_6_2;
  int sec_r000114_7_1;
  int sec_r000114_7_2;
  int sec_r000114_8_1;
  int sec_r000114_8_2;
  int sec_r000114_9_1;
  int sec_r000114_9_2;
  int sec_r000114_10_1;
  int sec_r000114_10_2;
  int sec_r000114_11_1;
  int sec_r000114_11_2;
  int sec_r000114_12_1;
  int sec_r000114_12_2;
  int sec_r000114_13_1;
  int sec_r000114_13_2;
  int sec_r000114_14_1;
  int sec_r000114_14_2;
  int sec_r000114_15_1;
  int sec_r000114_15_2;
  int sec_r000114_16_1;
  int sec_r000114_16_2;
  int sec_r000114_17_1;
  int sec_r000114_17_2;
  int sec_r000114_18_1;
  int sec_r000114_18_2;
  int sec_r000114_19_1;
  int sec_r000114_19_2;
  int sec_r000114_20_1;
  int sec_r000114_20_2;
  int sec_r000114_21_1;
  int sec_r000114_21_2;
  int pub_r000114_0_1;
  int pub_r000114_0_2;
  int pub_r000114_1_1;
  int pub_r000114_1_2;
  int pub_r000114_2_1;
  int pub_r000114_2_2;
  int pub_r000114_3_1;
  int pub_r000114_3_2;
  int pub_r000114_4_1;
  int pub_r000114_4_2;
  int pub_r000114_5_1;
  int pub_r000114_5_2;
  int pub_r000114_6_1;
  int pub_r000114_6_2;
  int pub_r000114_7_1;
  int pub_r000114_7_2;
  int pub_r000114_8_1;
  int pub_r000114_8_2;
  int pub_r000114_9_1;
  int pub_r000114_9_2;
  int pub_r000114_10_1;
  int pub_r000114_10_2;
  int pub_r000114_11_1;
  int pub_r000114_11_2;
  int pub_r000114_12_1;
  int pub_r000114_12_2;
  int pub_r000114_13_1;
  int pub_r000114_13_2;
  int pub_r000114_14_1;
  int pub_r000114_14_2;
  int pub_r000114_15_1;
  int pub_r000114_15_2;
  int pub_r000114_16_1;
  int pub_r000114_16_2;
  int pub_r000114_17_1;
  int pub_r000114_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000114_0_1 >= (-100)) && (pub_r000114_0_1 <= 100));
  __CPROVER_assume((pub_r000114_0_2 >= (-100)) && (pub_r000114_0_2 <= 100));
  __CPROVER_assume((pub_r000114_1_1 >= (-100)) && (pub_r000114_1_1 <= 100));
  __CPROVER_assume((pub_r000114_1_2 >= (-100)) && (pub_r000114_1_2 <= 100));
  __CPROVER_assume((pub_r000114_2_1 >= (-100)) && (pub_r000114_2_1 <= 100));
  __CPROVER_assume((pub_r000114_2_2 >= (-100)) && (pub_r000114_2_2 <= 100));
  __CPROVER_assume((pub_r000114_3_1 >= (-100)) && (pub_r000114_3_1 <= 100));
  __CPROVER_assume((pub_r000114_3_2 >= (-100)) && (pub_r000114_3_2 <= 100));
  __CPROVER_assume((pub_r000114_4_1 >= (-100)) && (pub_r000114_4_1 <= 100));
  __CPROVER_assume((pub_r000114_4_2 >= (-100)) && (pub_r000114_4_2 <= 100));
  __CPROVER_assume((pub_r000114_5_1 >= (-100)) && (pub_r000114_5_1 <= 100));
  __CPROVER_assume((pub_r000114_5_2 >= (-100)) && (pub_r000114_5_2 <= 100));
  __CPROVER_assume((pub_r000114_6_1 >= (-100)) && (pub_r000114_6_1 <= 100));
  __CPROVER_assume((pub_r000114_6_2 >= (-100)) && (pub_r000114_6_2 <= 100));
  __CPROVER_assume((pub_r000114_7_1 >= (-100)) && (pub_r000114_7_1 <= 100));
  __CPROVER_assume((pub_r000114_7_2 >= (-100)) && (pub_r000114_7_2 <= 100));
  __CPROVER_assume((pub_r000114_8_1 >= (-100)) && (pub_r000114_8_1 <= 100));
  __CPROVER_assume((pub_r000114_8_2 >= (-100)) && (pub_r000114_8_2 <= 100));
  __CPROVER_assume((pub_r000114_9_1 >= (-100)) && (pub_r000114_9_1 <= 100));
  __CPROVER_assume((pub_r000114_9_2 >= (-100)) && (pub_r000114_9_2 <= 100));
  __CPROVER_assume((pub_r000114_10_1 >= (-100)) && (pub_r000114_10_1 <= 100));
  __CPROVER_assume((pub_r000114_10_2 >= (-100)) && (pub_r000114_10_2 <= 100));
  __CPROVER_assume((pub_r000114_11_1 >= (-100)) && (pub_r000114_11_1 <= 100));
  __CPROVER_assume((pub_r000114_11_2 >= (-100)) && (pub_r000114_11_2 <= 100));
  __CPROVER_assume((pub_r000114_12_1 >= (-100)) && (pub_r000114_12_1 <= 100));
  __CPROVER_assume((pub_r000114_12_2 >= (-100)) && (pub_r000114_12_2 <= 100));
  __CPROVER_assume((pub_r000114_13_1 >= (-100)) && (pub_r000114_13_1 <= 100));
  __CPROVER_assume((pub_r000114_13_2 >= (-100)) && (pub_r000114_13_2 <= 100));
  __CPROVER_assume((pub_r000114_14_1 >= (-100)) && (pub_r000114_14_1 <= 100));
  __CPROVER_assume((pub_r000114_14_2 >= (-100)) && (pub_r000114_14_2 <= 100));
  __CPROVER_assume((pub_r000114_15_1 >= (-100)) && (pub_r000114_15_1 <= 100));
  __CPROVER_assume((pub_r000114_15_2 >= (-100)) && (pub_r000114_15_2 <= 100));
  __CPROVER_assume((pub_r000114_16_1 >= (-100)) && (pub_r000114_16_1 <= 100));
  __CPROVER_assume((pub_r000114_16_2 >= (-100)) && (pub_r000114_16_2 <= 100));
  __CPROVER_assume((pub_r000114_17_1 >= (-100)) && (pub_r000114_17_1 <= 100));
  __CPROVER_assume((pub_r000114_17_2 >= (-100)) && (pub_r000114_17_2 <= 100));
  __CPROVER_assume((sec_r000114_0_1 >= 0) && (sec_r000114_0_1 <= 255));
  __CPROVER_assume((sec_r000114_0_2 >= 0) && (sec_r000114_0_2 <= 255));
  __CPROVER_assume((sec_r000114_1_1 >= 0) && (sec_r000114_1_1 <= 255));
  __CPROVER_assume((sec_r000114_1_2 >= 0) && (sec_r000114_1_2 <= 255));
  __CPROVER_assume((sec_r000114_2_1 >= 0) && (sec_r000114_2_1 <= 255));
  __CPROVER_assume((sec_r000114_2_2 >= 0) && (sec_r000114_2_2 <= 255));
  __CPROVER_assume((sec_r000114_3_1 >= 0) && (sec_r000114_3_1 <= 255));
  __CPROVER_assume((sec_r000114_3_2 >= 0) && (sec_r000114_3_2 <= 255));
  __CPROVER_assume((sec_r000114_4_1 >= 0) && (sec_r000114_4_1 <= 255));
  __CPROVER_assume((sec_r000114_4_2 >= 0) && (sec_r000114_4_2 <= 255));
  __CPROVER_assume((sec_r000114_5_1 >= 0) && (sec_r000114_5_1 <= 255));
  __CPROVER_assume((sec_r000114_5_2 >= 0) && (sec_r000114_5_2 <= 255));
  __CPROVER_assume((sec_r000114_6_1 >= 0) && (sec_r000114_6_1 <= 255));
  __CPROVER_assume((sec_r000114_6_2 >= 0) && (sec_r000114_6_2 <= 255));
  __CPROVER_assume((sec_r000114_7_1 >= 0) && (sec_r000114_7_1 <= 255));
  __CPROVER_assume((sec_r000114_7_2 >= 0) && (sec_r000114_7_2 <= 255));
  __CPROVER_assume((sec_r000114_8_1 >= 0) && (sec_r000114_8_1 <= 255));
  __CPROVER_assume((sec_r000114_8_2 >= 0) && (sec_r000114_8_2 <= 255));
  __CPROVER_assume((sec_r000114_9_1 >= 0) && (sec_r000114_9_1 <= 255));
  __CPROVER_assume((sec_r000114_9_2 >= 0) && (sec_r000114_9_2 <= 255));
  __CPROVER_assume((sec_r000114_10_1 >= 0) && (sec_r000114_10_1 <= 255));
  __CPROVER_assume((sec_r000114_10_2 >= 0) && (sec_r000114_10_2 <= 255));
  __CPROVER_assume((sec_r000114_11_1 >= 0) && (sec_r000114_11_1 <= 255));
  __CPROVER_assume((sec_r000114_11_2 >= 0) && (sec_r000114_11_2 <= 255));
  __CPROVER_assume((sec_r000114_12_1 >= 0) && (sec_r000114_12_1 <= 255));
  __CPROVER_assume((sec_r000114_12_2 >= 0) && (sec_r000114_12_2 <= 255));
  __CPROVER_assume((sec_r000114_13_1 >= 0) && (sec_r000114_13_1 <= 255));
  __CPROVER_assume((sec_r000114_13_2 >= 0) && (sec_r000114_13_2 <= 255));
  __CPROVER_assume((sec_r000114_14_1 >= 0) && (sec_r000114_14_1 <= 255));
  __CPROVER_assume((sec_r000114_14_2 >= 0) && (sec_r000114_14_2 <= 255));
  __CPROVER_assume((sec_r000114_15_1 >= 0) && (sec_r000114_15_1 <= 255));
  __CPROVER_assume((sec_r000114_15_2 >= 0) && (sec_r000114_15_2 <= 255));
  __CPROVER_assume((sec_r000114_16_1 >= 0) && (sec_r000114_16_1 <= 255));
  __CPROVER_assume((sec_r000114_16_2 >= 0) && (sec_r000114_16_2 <= 255));
  __CPROVER_assume((sec_r000114_17_1 >= 0) && (sec_r000114_17_1 <= 255));
  __CPROVER_assume((sec_r000114_17_2 >= 0) && (sec_r000114_17_2 <= 255));
  __CPROVER_assume((sec_r000114_18_1 >= 0) && (sec_r000114_18_1 <= 255));
  __CPROVER_assume((sec_r000114_18_2 >= 0) && (sec_r000114_18_2 <= 255));
  __CPROVER_assume((sec_r000114_19_1 >= 0) && (sec_r000114_19_1 <= 255));
  __CPROVER_assume((sec_r000114_19_2 >= 0) && (sec_r000114_19_2 <= 255));
  __CPROVER_assume((sec_r000114_20_1 >= 0) && (sec_r000114_20_1 <= 255));
  __CPROVER_assume((sec_r000114_20_2 >= 0) && (sec_r000114_20_2 <= 255));
  __CPROVER_assume((sec_r000114_21_1 >= 0) && (sec_r000114_21_1 <= 255));
  __CPROVER_assume((sec_r000114_21_2 >= 0) && (sec_r000114_21_2 <= 255));
  struct StreamBuffer_R000114_1413_0 st_var_0_1 = {0};
  struct StreamBuffer_R000114_1413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000114_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000114_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000114_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000114_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000114_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000114_0_2 + 7) & 15;
  struct SensorNode_R000114_1413_1 st_var_1_1 = {0};
  struct SensorNode_R000114_1413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000114_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000114_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000114_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000114_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000114_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000114_0_2 + 9) & 15;
  struct DeviceConfig_R000114_1413_2 st_var_2_1 = {0};
  struct DeviceConfig_R000114_1413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000114_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000114_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000114_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000114_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000114_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000114_0_2 + 11) & 15;
  union TelemetryField_R000114_1413_0 u_var_1;
  union TelemetryField_R000114_1413_0 u_var_2;
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
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 34)
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
  if (stage_v_1_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 34)
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
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = (st_var_0_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_0_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = (st_var_2_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_2_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (st_var_1_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_1_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 33)
    {
      chk_sum_1 ^= stage_v_12_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_12_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 33)
    {
      chk_sum_2 ^= stage_v_12_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 15) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((st_var_2_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_2_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 39)
    {
      chk_sum_1 ^= stage_v_17_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_17_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 39)
    {
      chk_sum_2 ^= stage_v_17_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
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
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = (st_var_0_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_0_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_23_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

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
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = ((st_var_2_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_2_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 51)
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
  if (stage_v_32_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 51)
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
  int stage_v_33_1 = ((st_var_0_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_0_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 44)
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
  if (stage_v_33_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 44)
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
  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 36) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 40) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_40_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_41_1 = ((st_var_2_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_2_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 25)
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
  if (stage_v_41_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 25)
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
  if (stage_v_43_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 50)
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
  if (stage_v_43_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 50)
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
  int stage_v_44_1 = table_1[0];
  int stage_v_44_2 = table_2[0];
  table_1[0] = (table_1[1] + 89) & 63;
  table_2[0] = (table_2[1] + 89) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((st_var_1_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_1_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 33)
    {
      chk_sum_1 ^= stage_v_46_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_46_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 33)
    {
      chk_sum_2 ^= stage_v_46_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_47_1 = ((st_var_2_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_2_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 30)
    {
      chk_sum_1 ^= stage_v_47_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_47_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 30)
    {
      chk_sum_2 ^= stage_v_47_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 54)
    {
      chk_sum_1 ^= stage_v_50_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_50_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 54)
    {
      chk_sum_2 ^= stage_v_50_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (59 & 31);
  int stage_v_54_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (59 & 31);
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= (stage_v_54_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_54_2 << 1) & 127;
  int stage_v_55_1 = ((st_var_1_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_1_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 45)
    {
      chk_sum_1 ^= stage_v_55_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_55_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 45)
    {
      chk_sum_2 ^= stage_v_55_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_58_1 = ((stage_v_58_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_58_2 = ((stage_v_58_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((st_var_2_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_2_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 50)
    {
      chk_sum_1 ^= stage_v_59_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_59_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 50)
    {
      chk_sum_2 ^= stage_v_59_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_60_1 = (st_var_0_1.buffer[0] ^ 63) & 3;
  int stage_v_60_2 = (st_var_0_2.buffer[0] ^ 63) & 3;
  switch (stage_v_60_1)
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

  switch (stage_v_60_2)
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

  int stage_v_61_1 = ((st_var_1_1.buffer[1] * 2) + 190) & 63;
  int stage_v_61_2 = ((st_var_1_2.buffer[1] * 2) + 190) & 63;
  if (stage_v_61_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 50)
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
  if (stage_v_61_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 50)
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
  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (st_var_2_1.buffer[0] ^ 68) & 3;
  int stage_v_65_2 = (st_var_2_2.buffer[0] ^ 68) & 3;
  switch (stage_v_65_1)
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

  switch (stage_v_65_2)
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
  int stage_v_68_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (73 & 31);
  int stage_v_68_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (73 & 31);
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= (stage_v_68_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_68_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 70) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
  int stage_v_70_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (75 & 31);
  int stage_v_70_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (75 & 31);
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= (stage_v_70_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_70_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 72) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  int stage_v_72_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (77 & 31);
  int stage_v_72_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (77 & 31);
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= (stage_v_72_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_72_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 74) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 74) & 15;
  int stage_v_73_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_73_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= stage_v_73_1;
  chk_sum_2 ^= stage_v_73_2;
  int stage_v_74_1 = table_1[2];
  int stage_v_74_2 = table_2[2];
  table_1[2] = (table_1[3] + 149) & 63;
  table_2[2] = (table_2[3] + 149) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_75_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = table_1[2];
  int stage_v_78_2 = table_2[2];
  table_1[2] = (table_1[3] + 157) & 63;
  table_2[2] = (table_2[3] + 157) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 80) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 80) & 15;
  int stage_v_79_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_79_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  chk_sum_1 ^= stage_v_79_1;
  chk_sum_2 ^= stage_v_79_2;
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
  int stage_v_81_1 = table_1[1];
  int stage_v_81_2 = table_2[1];
  table_1[1] = (table_1[2] + 163) & 63;
  table_2[1] = (table_2[2] + 163) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((st_var_2_1.buffer[2] * 2) + 256) & 63;
  int stage_v_83_2 = ((st_var_2_2.buffer[2] * 2) + 256) & 63;
  if (stage_v_83_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_83_1) - 5) & 255;
    if (stage_v_83_1 > 46)
    {
      chk_sum_1 ^= stage_v_83_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_83_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_83_2) - 5) & 255;
    if (stage_v_83_2 > 46)
    {
      chk_sum_2 ^= stage_v_83_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 85) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 85) & 15;
  int stage_v_84_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_84_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  chk_sum_1 ^= stage_v_84_1;
  chk_sum_2 ^= stage_v_84_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 86) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 86) & 15;
  int stage_v_85_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_85_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= stage_v_85_1;
  chk_sum_2 ^= stage_v_85_2;
  int stage_v_86_1 = table_1[2];
  int stage_v_86_2 = table_2[2];
  table_1[2] = (table_1[3] + 173) & 63;
  table_2[2] = (table_2[3] + 173) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (st_var_0_1.buffer[0] ^ 90) & 3;
  int stage_v_87_2 = (st_var_0_2.buffer[0] ^ 90) & 3;
  switch (stage_v_87_1)
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

  switch (stage_v_87_2)
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

  int stage_v_88_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_88_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_88_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_88_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_89_1 = (st_var_2_1.buffer[0] ^ 92) & 3;
  int stage_v_89_2 = (st_var_2_2.buffer[0] ^ 92) & 3;
  switch (stage_v_89_1)
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

  switch (stage_v_89_2)
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

  int stage_v_90_1 = (st_var_0_1.buffer[0] ^ 93) & 3;
  int stage_v_90_2 = (st_var_0_2.buffer[0] ^ 93) & 3;
  switch (stage_v_90_1)
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

  switch (stage_v_90_2)
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

  int stage_v_91_1 = table_1[3];
  int stage_v_91_2 = table_2[3];
  table_1[3] = (table_1[0] + 183) & 63;
  table_2[3] = (table_2[0] + 183) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((st_var_2_1.buffer[2] * 2) + 283) & 63;
  int stage_v_92_2 = ((st_var_2_2.buffer[2] * 2) + 283) & 63;
  if (stage_v_92_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_92_1) - 5) & 255;
    if (stage_v_92_1 > 55)
    {
      chk_sum_1 ^= stage_v_92_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_92_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_92_2) - 5) & 255;
    if (stage_v_92_2 > 55)
    {
      chk_sum_2 ^= stage_v_92_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_93_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_93_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_93_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_93_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_94_1 = ((st_var_1_1.buffer[1] * 2) + 289) & 63;
  int stage_v_94_2 = ((st_var_1_2.buffer[1] * 2) + 289) & 63;
  if (stage_v_94_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_94_1) - 5) & 255;
    if (stage_v_94_1 > 38)
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
  if (stage_v_94_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_94_2) - 5) & 255;
    if (stage_v_94_2 > 38)
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
  int stage_v_96_1 = ((st_var_0_1.buffer[0] * 2) + 295) & 63;
  int stage_v_96_2 = ((st_var_0_2.buffer[0] * 2) + 295) & 63;
  if (stage_v_96_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_96_1) - 5) & 255;
    if (stage_v_96_1 > 42)
    {
      chk_sum_1 ^= stage_v_96_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_96_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_96_2) - 5) & 255;
    if (stage_v_96_2 > 42)
    {
      chk_sum_2 ^= stage_v_96_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_97_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (102 & 31);
  int stage_v_97_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (102 & 31);
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= (stage_v_97_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_97_2 << 1) & 127;
  int stage_v_98_1 = ((st_var_2_1.buffer[2] * 2) + 301) & 63;
  int stage_v_98_2 = ((st_var_2_2.buffer[2] * 2) + 301) & 63;
  if (stage_v_98_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_98_1) - 5) & 255;
    if (stage_v_98_1 > 27)
    {
      chk_sum_1 ^= stage_v_98_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_98_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_98_2) - 5) & 255;
    if (stage_v_98_2 > 27)
    {
      chk_sum_2 ^= stage_v_98_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_99_1 = ((st_var_0_1.buffer[0] * 2) + 304) & 63;
  int stage_v_99_2 = ((st_var_0_2.buffer[0] * 2) + 304) & 63;
  if (stage_v_99_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_99_1) - 5) & 255;
    if (stage_v_99_1 > 34)
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
  if (stage_v_99_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_99_2) - 5) & 255;
    if (stage_v_99_2 > 34)
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
  int stage_v_100_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (105 & 31);
  int stage_v_100_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (105 & 31);
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= (stage_v_100_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_100_2 << 1) & 127;
  int stage_v_101_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (106 & 31);
  int stage_v_101_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (106 & 31);
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= (stage_v_101_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_101_2 << 1) & 127;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_102_1 = ((stage_v_102_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_102_2 = ((stage_v_102_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = table_1[3];
  int stage_v_103_2 = table_2[3];
  table_1[3] = (table_1[0] + 207) & 63;
  table_2[3] = (table_2[0] + 207) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = table_1[0];
  int stage_v_104_2 = table_2[0];
  table_1[0] = (table_1[1] + 209) & 63;
  table_2[0] = (table_2[1] + 209) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_105_1 = ((stage_v_105_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_105_2 = ((stage_v_105_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = table_1[2];
  int stage_v_106_2 = table_2[2];
  table_1[2] = (table_1[3] + 213) & 63;
  table_2[2] = (table_2[3] + 213) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_107_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_108_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (113 & 31);
  int stage_v_108_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (113 & 31);
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  chk_sum_1 ^= (stage_v_108_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_108_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 110) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 110) & 15;
  int stage_v_109_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_109_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  chk_sum_1 ^= stage_v_109_1;
  chk_sum_2 ^= stage_v_109_2;
  int stage_v_110_1 = table_1[2];
  int stage_v_110_2 = table_2[2];
  table_1[2] = (table_1[3] + 221) & 63;
  table_2[2] = (table_2[3] + 221) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_111_1 = ((stage_v_111_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_111_2 = ((stage_v_111_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_112_1 = ((stage_v_112_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_112_2 = ((stage_v_112_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((st_var_2_1.buffer[2] * 2) + 346) & 63;
  int stage_v_113_2 = ((st_var_2_2.buffer[2] * 2) + 346) & 63;
  if (stage_v_113_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_113_1) - 5) & 255;
    if (stage_v_113_1 > 54)
    {
      chk_sum_1 ^= stage_v_113_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_113_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_113_2) - 5) & 255;
    if (stage_v_113_2 > 54)
    {
      chk_sum_2 ^= stage_v_113_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 115) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 115) & 15;
  int stage_v_114_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_114_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= stage_v_114_1;
  chk_sum_2 ^= stage_v_114_2;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 117) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 117) & 15;
  int stage_v_116_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_116_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= stage_v_116_1;
  chk_sum_2 ^= stage_v_116_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 118) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 118) & 15;
  int stage_v_117_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_117_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  chk_sum_1 ^= stage_v_117_1;
  chk_sum_2 ^= stage_v_117_2;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_118_1 = ((stage_v_118_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_118_2 = ((stage_v_118_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (st_var_2_1.buffer[0] ^ 122) & 3;
  int stage_v_119_2 = (st_var_2_2.buffer[0] ^ 122) & 3;
  switch (stage_v_119_1)
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

  switch (stage_v_119_2)
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

  int stage_v_120_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_120_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_120_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_120_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_121_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_121_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_122_1 = ((stage_v_122_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_122_2 = ((stage_v_122_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (128 & 31);
  int stage_v_123_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (128 & 31);
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= (stage_v_123_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_123_2 << 1) & 127;
  int stage_v_124_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_124_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_124_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_124_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_125_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (130 & 31);
  int stage_v_125_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (130 & 31);
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  chk_sum_1 ^= (stage_v_125_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_125_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 127) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 127) & 15;
  int stage_v_126_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_126_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  chk_sum_1 ^= stage_v_126_1;
  chk_sum_2 ^= stage_v_126_2;
  int stage_v_127_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (132 & 31);
  int stage_v_127_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (132 & 31);
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  chk_sum_1 ^= (stage_v_127_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_127_2 << 1) & 127;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_128_1 = ((stage_v_128_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_128_2 = ((stage_v_128_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((st_var_0_1.buffer[0] * 2) + 394) & 63;
  int stage_v_129_2 = ((st_var_0_2.buffer[0] * 2) + 394) & 63;
  if (stage_v_129_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_129_1) - 5) & 255;
    if (stage_v_129_1 > 26)
    {
      chk_sum_1 ^= stage_v_129_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_129_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_129_2) - 5) & 255;
    if (stage_v_129_2 > 26)
    {
      chk_sum_2 ^= stage_v_129_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_130_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (135 & 31);
  int stage_v_130_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (135 & 31);
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= (stage_v_130_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_130_2 << 1) & 127;
  int stage_v_131_1 = (st_var_2_1.buffer[0] ^ 134) & 3;
  int stage_v_131_2 = (st_var_2_2.buffer[0] ^ 134) & 3;
  switch (stage_v_131_1)
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

  switch (stage_v_131_2)
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

  int stage_v_132_1 = table_1[0];
  int stage_v_132_2 = table_2[0];
  table_1[0] = (table_1[1] + 265) & 63;
  table_2[0] = (table_2[1] + 265) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_133_1 = ((stage_v_133_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_133_2 = ((stage_v_133_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = table_1[2];
  int stage_v_134_2 = table_2[2];
  table_1[2] = (table_1[3] + 269) & 63;
  table_2[2] = (table_2[3] + 269) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 136) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 136) & 15;
  int stage_v_135_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_135_2 = (st_var_0_2.buffer[0] * 3) & 63;
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
  int stage_v_137_1 = (st_var_2_1.buffer[0] ^ 140) & 3;
  int stage_v_137_2 = (st_var_2_2.buffer[0] ^ 140) & 3;
  switch (stage_v_137_1)
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

  switch (stage_v_137_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 139) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 139) & 15;
  int stage_v_138_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_138_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  chk_sum_1 ^= stage_v_138_1;
  chk_sum_2 ^= stage_v_138_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 140) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 140) & 15;
  int stage_v_139_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_139_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  chk_sum_1 ^= stage_v_139_1;
  chk_sum_2 ^= stage_v_139_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 141) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 141) & 15;
  int stage_v_140_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_140_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  chk_sum_1 ^= stage_v_140_1;
  chk_sum_2 ^= stage_v_140_2;
  int stage_v_141_1 = ((st_var_0_1.buffer[0] * 2) + 430) & 63;
  int stage_v_141_2 = ((st_var_0_2.buffer[0] * 2) + 430) & 63;
  if (stage_v_141_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_141_1) - 5) & 255;
    if (stage_v_141_1 > 47)
    {
      chk_sum_1 ^= stage_v_141_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_141_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_141_2) - 5) & 255;
    if (stage_v_141_2 > 47)
    {
      chk_sum_2 ^= stage_v_141_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 143) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 143) & 15;
  int stage_v_142_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_142_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= stage_v_142_1;
  chk_sum_2 ^= stage_v_142_2;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_144_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_145_1 = ((st_var_1_1.buffer[1] * 2) + 442) & 63;
  int stage_v_145_2 = ((st_var_1_2.buffer[1] * 2) + 442) & 63;
  if (stage_v_145_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_145_1) - 5) & 255;
    if (stage_v_145_1 > 25)
    {
      chk_sum_1 ^= stage_v_145_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_145_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_145_2) - 5) & 255;
    if (stage_v_145_2 > 25)
    {
      chk_sum_2 ^= stage_v_145_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_146_1 = table_1[2];
  int stage_v_146_2 = table_2[2];
  table_1[2] = (table_1[3] + 293) & 63;
  table_2[2] = (table_2[3] + 293) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (st_var_0_1.buffer[0] ^ 150) & 3;
  int stage_v_147_2 = (st_var_0_2.buffer[0] ^ 150) & 3;
  switch (stage_v_147_1)
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

  switch (stage_v_147_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 149) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 149) & 15;
  int stage_v_148_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_148_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  chk_sum_1 ^= stage_v_148_1;
  chk_sum_2 ^= stage_v_148_2;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_149_1 = ((stage_v_149_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_149_2 = ((stage_v_149_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 151) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 151) & 15;
  int stage_v_150_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_150_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  chk_sum_1 ^= stage_v_150_1;
  chk_sum_2 ^= stage_v_150_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 152) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 152) & 15;
  int stage_v_151_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_151_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  chk_sum_1 ^= stage_v_151_1;
  chk_sum_2 ^= stage_v_151_2;
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
  int stage_v_153_1 = (st_var_0_1.buffer[0] ^ 156) & 3;
  int stage_v_153_2 = (st_var_0_2.buffer[0] ^ 156) & 3;
  switch (stage_v_153_1)
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

  switch (stage_v_153_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 155) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 155) & 15;
  int stage_v_154_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_154_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  chk_sum_1 ^= stage_v_154_1;
  chk_sum_2 ^= stage_v_154_2;
  int stage_v_155_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (160 & 31);
  int stage_v_155_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (160 & 31);
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= (stage_v_155_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_155_2 << 1) & 127;
  int stage_v_156_1 = ((st_var_0_1.buffer[0] * 2) + 475) & 63;
  int stage_v_156_2 = ((st_var_0_2.buffer[0] * 2) + 475) & 63;
  if (stage_v_156_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_156_1) - 5) & 255;
    if (stage_v_156_1 > 42)
    {
      chk_sum_1 ^= stage_v_156_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_156_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_156_2) - 5) & 255;
    if (stage_v_156_2 > 42)
    {
      chk_sum_2 ^= stage_v_156_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 158) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 158) & 15;
  int stage_v_157_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_157_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  chk_sum_1 ^= stage_v_157_1;
  chk_sum_2 ^= stage_v_157_2;
  int stage_v_158_1 = (st_var_2_1.buffer[0] ^ 161) & 3;
  int stage_v_158_2 = (st_var_2_2.buffer[0] ^ 161) & 3;
  switch (stage_v_158_1)
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

  switch (stage_v_158_2)
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

  int stage_v_159_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (164 & 31);
  int stage_v_159_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (164 & 31);
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  chk_sum_1 ^= (stage_v_159_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_159_2 << 1) & 127;
  int stage_v_160_1 = table_1[0];
  int stage_v_160_2 = table_2[0];
  table_1[0] = (table_1[1] + 321) & 63;
  table_2[0] = (table_2[1] + 321) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  out_sink_1 += ((sec_r000114_6_1 * 3) + (sec_r000114_18_1 * 1)) & 255;
  out_sink_2 += ((sec_r000114_6_2 * 3) + (sec_r000114_18_2 * 1)) & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000114_4_1 == pub_r000114_4_2);
  __CPROVER_assume(pub_r000114_1_1 == pub_r000114_1_2);
  __CPROVER_assume(pub_r000114_8_1 == pub_r000114_8_2);
  __CPROVER_assume(sec_r000114_19_1 != sec_r000114_19_2);
  __CPROVER_assume(pub_r000114_0_1 == pub_r000114_0_2);
  __CPROVER_assume(sec_r000114_4_1 != sec_r000114_4_2);
  __CPROVER_assume(pub_r000114_11_1 == pub_r000114_11_2);
  __CPROVER_assume(sec_r000114_0_1 != sec_r000114_0_2);
  __CPROVER_assume(sec_r000114_12_1 != sec_r000114_12_2);
  __CPROVER_assume(pub_r000114_6_1 == pub_r000114_6_2);
  __CPROVER_assume(pub_r000114_5_1 == pub_r000114_5_2);
  __CPROVER_assume(sec_r000114_2_1 != sec_r000114_2_2);
  __CPROVER_assume(pub_r000114_17_1 == pub_r000114_17_2);
  __CPROVER_assume(pub_r000114_10_1 == pub_r000114_10_2);
  __CPROVER_assume(sec_r000114_18_1 != sec_r000114_18_2);
  __CPROVER_assume(sec_r000114_5_1 != sec_r000114_5_2);
  __CPROVER_assume(pub_r000114_9_1 == pub_r000114_9_2);
  __CPROVER_assume(sec_r000114_11_1 != sec_r000114_11_2);
  __CPROVER_assume(pub_r000114_15_1 == pub_r000114_15_2);
  __CPROVER_assume(sec_r000114_10_1 != sec_r000114_10_2);
  __CPROVER_assume(pub_r000114_2_1 == pub_r000114_2_2);
  __CPROVER_assume(pub_r000114_3_1 == pub_r000114_3_2);
  __CPROVER_assume(pub_r000114_12_1 == pub_r000114_12_2);
  __CPROVER_assume(sec_r000114_8_1 != sec_r000114_8_2);
  __CPROVER_assume(pub_r000114_13_1 == pub_r000114_13_2);
  __CPROVER_assume(sec_r000114_14_1 != sec_r000114_14_2);
  __CPROVER_assume(sec_r000114_6_1 != sec_r000114_6_2);
  __CPROVER_assume(sec_r000114_16_1 != sec_r000114_16_2);
  __CPROVER_assume(pub_r000114_16_1 == pub_r000114_16_2);
  __CPROVER_assume(sec_r000114_7_1 != sec_r000114_7_2);
  __CPROVER_assume(sec_r000114_3_1 != sec_r000114_3_2);
  __CPROVER_assume(sec_r000114_9_1 != sec_r000114_9_2);
  __CPROVER_assume(sec_r000114_13_1 != sec_r000114_13_2);
  __CPROVER_assume(sec_r000114_15_1 != sec_r000114_15_2);
  __CPROVER_assume(sec_r000114_21_1 != sec_r000114_21_2);
  __CPROVER_assume(pub_r000114_7_1 == pub_r000114_7_2);
  __CPROVER_assume(pub_r000114_14_1 == pub_r000114_14_2);
  __CPROVER_assume(sec_r000114_20_1 != sec_r000114_20_2);
  __CPROVER_assume(sec_r000114_17_1 != sec_r000114_17_2);
  __CPROVER_assume(sec_r000114_1_1 != sec_r000114_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.head == st_var_0_2.head);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.state == st_var_0_2.state);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.status == st_var_1_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.port == st_var_2_2.port);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
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
}


