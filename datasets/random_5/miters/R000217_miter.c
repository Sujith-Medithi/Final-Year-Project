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
struct DeviceConfig_R000217_1713_0
{
  short port;
  int parity;
  short stop_bits;
  short id;
  unsigned char timeout;
  int buffer[3];
};
struct SensorNode_R000217_1713_1
{
  unsigned char status;
  int threshold;
  int calib;
  int reading;
  int gain;
  unsigned char offset;
  int buffer[3];
};
struct AudioFrame_R000217_1713_2
{
  unsigned char envelope;
  unsigned char rms;
  unsigned char sample_rate;
  int gain;
  int channels;
  int buffer[3];
};
union RegisterBank_R000217_1713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000217_1713_1
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
void fn_R000217_1713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000217_1713_1 st_1 = {0};
  struct SensorNode_R000217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int parity_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_18_1) & 63;
  aux_2 = (aux_2 + parity_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_29_1 > 38)
  {
    acc_1 = ((acc_1 + (mask_29_1 * 2)) + 5) & 127;
    aux_1 ^= mask_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_29_2 > 38)
  {
    acc_2 = ((acc_2 + (mask_29_2 * 2)) + 5) & 127;
    aux_2 ^= mask_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_16_1 = local_arr_1[aux_1 % 3];
  int pivot_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_16_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_18_1 == parity_18_2);
  assert(mask_29_1 == mask_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_16_1 == pivot_16_2);
}

int fn_R000217_1713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int parity_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_18) & 63;
  acc ^= aux;
  int mask_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_29 > 38)
  {
    acc = ((acc + (mask_29 * 2)) + 5) & 127;
    aux ^= mask_29 & 15;
  }
  else
  {
    acc = ((acc - mask_29) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int pivot_16 = local_arr[aux % 3];
  acc = (acc + (pivot_16 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000217_1713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000217_1713_2 st_1 = {0};
  struct AudioFrame_R000217_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int bound_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_45_1)
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

  switch (bound_45_2)
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

  int pivot_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_82_1) & 63;
  aux_2 = (aux_2 + pivot_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_64_1 > 23)
  {
    acc_1 = ((acc_1 + (factor_64_1 * 2)) + 5) & 127;
    aux_1 ^= factor_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_64_2 > 23)
  {
    acc_2 = ((acc_2 + (factor_64_2 * 2)) + 5) & 127;
    aux_2 ^= factor_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_45_1 == bound_45_2);
  assert(pivot_82_1 == pivot_82_2);
  assert(factor_64_1 == factor_64_2);
}

int fn_R000217_1713_1(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000217_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int bound_45 = (aux + st.buffer[1]) & 3;
  switch (bound_45)
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

  int pivot_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_82) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_64 > 23)
  {
    acc = ((acc + (factor_64 * 2)) + 5) & 127;
    aux ^= factor_64 & 15;
  }
  else
  {
    acc = ((acc - factor_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000217_1713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000217_1713_0 st_1 = {0};
  struct DeviceConfig_R000217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int vector_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_52_1 > 34)
  {
    acc_1 = ((acc_1 + (vector_52_1 * 2)) + 5) & 127;
    aux_1 ^= vector_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_52_2 > 34)
  {
    acc_2 = ((acc_2 + (vector_52_2 * 2)) + 5) & 127;
    aux_2 ^= vector_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_38_1 = local_arr_1[aux_1 % 3];
  int offset_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_38_2 * 2)) & 127;
  int threshold_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_76_1)
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

  switch (threshold_76_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_52_1 == vector_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_38_1 == offset_38_2);
  assert(threshold_76_1 == threshold_76_2);
}

int fn_R000217_1713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int vector_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_52 > 34)
  {
    acc = ((acc + (vector_52 * 2)) + 5) & 127;
    aux ^= vector_52 & 15;
  }
  else
  {
    acc = ((acc - vector_52) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_38 = local_arr[aux % 3];
  acc = (acc + (offset_38 * 2)) & 127;
  int threshold_76 = (aux + st.buffer[1]) & 3;
  switch (threshold_76)
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

void fn_R000217_1713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000217_1713_0 st_1 = {0};
  struct DeviceConfig_R000217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_71_1 = local_arr_1[aux_1 % 3];
  int vector_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_71_2 * 2)) & 127;
  int weight_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_89_1 > 43)
  {
    acc_1 = ((acc_1 + (weight_89_1 * 2)) + 5) & 127;
    aux_1 ^= weight_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_89_2 > 43)
  {
    acc_2 = ((acc_2 + (weight_89_2 * 2)) + 5) & 127;
    aux_2 ^= weight_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_93_1) & 63;
  aux_2 = (aux_2 + bound_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_71_1 == vector_71_2);
  assert(weight_89_1 == weight_89_2);
  assert(bound_93_1 == bound_93_2);
}

int fn_R000217_1713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_71 = local_arr[aux % 3];
  acc = (acc + (vector_71 * 2)) & 127;
  int weight_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_89 > 43)
  {
    acc = ((acc + (weight_89 * 2)) + 5) & 127;
    aux ^= weight_89 & 15;
  }
  else
  {
    acc = ((acc - weight_89) + 11) & 127;
    aux += 3;
  }
  int bound_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_93) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000217_1713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000217_1713_1 st_1 = {0};
  struct SensorNode_R000217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int factor_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_62_1)
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

  switch (factor_62_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_26_1) & 63;
  aux_2 = (aux_2 + sample_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_62_1 == factor_62_2);
  assert(sample_26_1 == sample_26_2);
}

int fn_R000217_1713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int factor_62 = (aux + st.buffer[1]) & 3;
  switch (factor_62)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_26) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000217_1713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000217_1713_1 st_1 = {0};
  struct SensorNode_R000217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int vector_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_34_1) & 63;
  aux_2 = (aux_2 + vector_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_98_1)
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

  switch (quotient_98_2)
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
  int factor_24_1 = local_arr_1[aux_1 % 3];
  int factor_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_24_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_34_1 == vector_34_2);
  assert(quotient_98_1 == quotient_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_24_1 == factor_24_2);
}

int fn_R000217_1713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int vector_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_34) & 63;
  acc ^= aux;
  int quotient_98 = (aux + st.buffer[1]) & 3;
  switch (quotient_98)
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
  int factor_24 = local_arr[aux % 3];
  acc = (acc + (factor_24 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000217_1713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000217_1713_1 st_1 = {0};
  struct SensorNode_R000217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_79_1 = local_arr_1[aux_1 % 3];
  int metric_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_79_2 * 2)) & 127;
  int window_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_44_1)
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

  switch (window_44_2)
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

  int parity_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_26_1) & 63;
  aux_2 = (aux_2 + parity_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_79_1 == metric_79_2);
  assert(window_44_1 == window_44_2);
  assert(parity_26_1 == parity_26_2);
}

int fn_R000217_1713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_79 = local_arr[aux % 3];
  acc = (acc + (metric_79 * 2)) & 127;
  int window_44 = (aux + st.buffer[1]) & 3;
  switch (window_44)
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

  int parity_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_26) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000217_1713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000217_1713_2 st_1 = {0};
  struct AudioFrame_R000217_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_22_1 = local_arr_1[aux_1 % 3];
  int tracker_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_22_2 * 2)) & 127;
  int coefficient_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_97_1) & 63;
  aux_2 = (aux_2 + coefficient_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_22_1 == tracker_22_2);
  assert(coefficient_97_1 == coefficient_97_2);
}

int fn_R000217_1713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000217_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int tracker_22 = local_arr[aux % 3];
  acc = (acc + (tracker_22 * 2)) & 127;
  int coefficient_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_97) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000217_1713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000217_1713_1 st_1 = {0};
  struct SensorNode_R000217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int threshold_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_86_1 > 44)
  {
    acc_1 = ((acc_1 + (threshold_86_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_86_2 > 44)
  {
    acc_2 = ((acc_2 + (threshold_86_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_86_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_44_1) & 63;
  aux_2 = (aux_2 + checksum_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_79_1)
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

  switch (margin_79_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_86_1 == threshold_86_2);
  assert(checksum_44_1 == checksum_44_2);
  assert(margin_79_1 == margin_79_2);
}

int fn_R000217_1713_8(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int threshold_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_86 > 44)
  {
    acc = ((acc + (threshold_86 * 2)) + 5) & 127;
    aux ^= threshold_86 & 15;
  }
  else
  {
    acc = ((acc - threshold_86) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_44) & 63;
  acc ^= aux;
  int margin_79 = (aux + st.buffer[1]) & 3;
  switch (margin_79)
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

void fn_R000217_1713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000217_1713_0 st_1 = {0};
  struct DeviceConfig_R000217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_30_1) & 63;
  aux_2 = (aux_2 + pivot_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_30_1 == pivot_30_2);
}

int fn_R000217_1713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000217_1713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000217_1713_2 st_1 = {0};
  struct AudioFrame_R000217_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int accumulator_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_22_1) & 63;
  aux_2 = (aux_2 + accumulator_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_18_1 > 19)
  {
    acc_1 = ((acc_1 + (cursor_18_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_18_2 > 19)
  {
    acc_2 = ((acc_2 + (cursor_18_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_91_1 = local_arr_1[aux_1 % 3];
  int stride_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_91_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_22_1 == accumulator_22_2);
  assert(cursor_18_1 == cursor_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_91_1 == stride_91_2);
}

int fn_R000217_1713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000217_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int accumulator_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_22) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_18 > 19)
  {
    acc = ((acc + (cursor_18 * 2)) + 5) & 127;
    aux ^= cursor_18 & 15;
  }
  else
  {
    acc = ((acc - cursor_18) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_91 = local_arr[aux % 3];
  acc = (acc + (stride_91 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000217_1713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000217_1713_0 st_1 = {0};
  struct DeviceConfig_R000217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_37_1 = local_arr_1[aux_1 % 3];
  int tracker_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_37_2 * 2)) & 127;
  int damping_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_20_1) & 63;
  aux_2 = (aux_2 + damping_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_37_1 == tracker_37_2);
  assert(damping_20_1 == damping_20_2);
}

int fn_R000217_1713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tracker_37 = local_arr[aux % 3];
  acc = (acc + (tracker_37 * 2)) & 127;
  int damping_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_20) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000217_1713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000217_1713_2 st_1 = {0};
  struct AudioFrame_R000217_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_29_1 = local_arr_1[aux_1 % 3];
  int factor_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_29_2 * 2)) & 127;
  int index_reg_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_77_1 > 30)
  {
    acc_1 = ((acc_1 + (index_reg_77_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_77_2 > 30)
  {
    acc_2 = ((acc_2 + (index_reg_77_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_77_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_38_1)
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

  switch (tracker_38_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_29_1 == factor_29_2);
  assert(index_reg_77_1 == index_reg_77_2);
  assert(tracker_38_1 == tracker_38_2);
}

int fn_R000217_1713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000217_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int factor_29 = local_arr[aux % 3];
  acc = (acc + (factor_29 * 2)) & 127;
  int index_reg_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_77 > 30)
  {
    acc = ((acc + (index_reg_77 * 2)) + 5) & 127;
    aux ^= index_reg_77 & 15;
  }
  else
  {
    acc = ((acc - index_reg_77) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_38 = (aux + st.buffer[1]) & 3;
  switch (tracker_38)
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

void fn_R000217_1713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000217_1713_2 st_1 = {0};
  struct AudioFrame_R000217_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int vector_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_46_1 > 19)
  {
    acc_1 = ((acc_1 + (vector_46_1 * 2)) + 5) & 127;
    aux_1 ^= vector_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_46_2 > 19)
  {
    acc_2 = ((acc_2 + (vector_46_2 * 2)) + 5) & 127;
    aux_2 ^= vector_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_40_1) & 63;
  aux_2 = (aux_2 + anchor_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_21_1 = local_arr_1[aux_1 % 3];
  int stride_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_21_2 * 2)) & 127;
  int offset_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_81_1)
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

  switch (offset_81_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_46_1 == vector_46_2);
  assert(anchor_40_1 == anchor_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_21_1 == stride_21_2);
  assert(offset_81_1 == offset_81_2);
}

int fn_R000217_1713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000217_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int vector_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_46 > 19)
  {
    acc = ((acc + (vector_46 * 2)) + 5) & 127;
    aux ^= vector_46 & 15;
  }
  else
  {
    acc = ((acc - vector_46) + 11) & 127;
    aux += 3;
  }
  int anchor_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_40) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_21 = local_arr[aux % 3];
  acc = (acc + (stride_21 * 2)) & 127;
  int offset_81 = (aux + st.buffer[1]) & 3;
  switch (offset_81)
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

void main()
{
  int sec_r000217_0_1;
  int sec_r000217_0_2;
  int sec_r000217_1_1;
  int sec_r000217_1_2;
  int sec_r000217_2_1;
  int sec_r000217_2_2;
  int sec_r000217_3_1;
  int sec_r000217_3_2;
  int sec_r000217_4_1;
  int sec_r000217_4_2;
  int sec_r000217_5_1;
  int sec_r000217_5_2;
  int sec_r000217_6_1;
  int sec_r000217_6_2;
  int sec_r000217_7_1;
  int sec_r000217_7_2;
  int sec_r000217_8_1;
  int sec_r000217_8_2;
  int sec_r000217_9_1;
  int sec_r000217_9_2;
  int sec_r000217_10_1;
  int sec_r000217_10_2;
  int sec_r000217_11_1;
  int sec_r000217_11_2;
  int sec_r000217_12_1;
  int sec_r000217_12_2;
  int sec_r000217_13_1;
  int sec_r000217_13_2;
  int sec_r000217_14_1;
  int sec_r000217_14_2;
  int sec_r000217_15_1;
  int sec_r000217_15_2;
  int sec_r000217_16_1;
  int sec_r000217_16_2;
  int sec_r000217_17_1;
  int sec_r000217_17_2;
  int sec_r000217_18_1;
  int sec_r000217_18_2;
  int sec_r000217_19_1;
  int sec_r000217_19_2;
  int pub_r000217_0_1;
  int pub_r000217_0_2;
  int pub_r000217_1_1;
  int pub_r000217_1_2;
  int pub_r000217_2_1;
  int pub_r000217_2_2;
  int pub_r000217_3_1;
  int pub_r000217_3_2;
  int pub_r000217_4_1;
  int pub_r000217_4_2;
  int pub_r000217_5_1;
  int pub_r000217_5_2;
  int pub_r000217_6_1;
  int pub_r000217_6_2;
  int pub_r000217_7_1;
  int pub_r000217_7_2;
  int pub_r000217_8_1;
  int pub_r000217_8_2;
  int pub_r000217_9_1;
  int pub_r000217_9_2;
  int pub_r000217_10_1;
  int pub_r000217_10_2;
  int pub_r000217_11_1;
  int pub_r000217_11_2;
  int pub_r000217_12_1;
  int pub_r000217_12_2;
  int pub_r000217_13_1;
  int pub_r000217_13_2;
  int pub_r000217_14_1;
  int pub_r000217_14_2;
  int pub_r000217_15_1;
  int pub_r000217_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000217_0_1 >= (-100)) && (pub_r000217_0_1 <= 100));
  __CPROVER_assume((pub_r000217_0_2 >= (-100)) && (pub_r000217_0_2 <= 100));
  __CPROVER_assume((pub_r000217_1_1 >= (-100)) && (pub_r000217_1_1 <= 100));
  __CPROVER_assume((pub_r000217_1_2 >= (-100)) && (pub_r000217_1_2 <= 100));
  __CPROVER_assume((pub_r000217_2_1 >= (-100)) && (pub_r000217_2_1 <= 100));
  __CPROVER_assume((pub_r000217_2_2 >= (-100)) && (pub_r000217_2_2 <= 100));
  __CPROVER_assume((pub_r000217_3_1 >= (-100)) && (pub_r000217_3_1 <= 100));
  __CPROVER_assume((pub_r000217_3_2 >= (-100)) && (pub_r000217_3_2 <= 100));
  __CPROVER_assume((pub_r000217_4_1 >= (-100)) && (pub_r000217_4_1 <= 100));
  __CPROVER_assume((pub_r000217_4_2 >= (-100)) && (pub_r000217_4_2 <= 100));
  __CPROVER_assume((pub_r000217_5_1 >= (-100)) && (pub_r000217_5_1 <= 100));
  __CPROVER_assume((pub_r000217_5_2 >= (-100)) && (pub_r000217_5_2 <= 100));
  __CPROVER_assume((pub_r000217_6_1 >= (-100)) && (pub_r000217_6_1 <= 100));
  __CPROVER_assume((pub_r000217_6_2 >= (-100)) && (pub_r000217_6_2 <= 100));
  __CPROVER_assume((pub_r000217_7_1 >= (-100)) && (pub_r000217_7_1 <= 100));
  __CPROVER_assume((pub_r000217_7_2 >= (-100)) && (pub_r000217_7_2 <= 100));
  __CPROVER_assume((pub_r000217_8_1 >= (-100)) && (pub_r000217_8_1 <= 100));
  __CPROVER_assume((pub_r000217_8_2 >= (-100)) && (pub_r000217_8_2 <= 100));
  __CPROVER_assume((pub_r000217_9_1 >= (-100)) && (pub_r000217_9_1 <= 100));
  __CPROVER_assume((pub_r000217_9_2 >= (-100)) && (pub_r000217_9_2 <= 100));
  __CPROVER_assume((pub_r000217_10_1 >= (-100)) && (pub_r000217_10_1 <= 100));
  __CPROVER_assume((pub_r000217_10_2 >= (-100)) && (pub_r000217_10_2 <= 100));
  __CPROVER_assume((pub_r000217_11_1 >= (-100)) && (pub_r000217_11_1 <= 100));
  __CPROVER_assume((pub_r000217_11_2 >= (-100)) && (pub_r000217_11_2 <= 100));
  __CPROVER_assume((pub_r000217_12_1 >= (-100)) && (pub_r000217_12_1 <= 100));
  __CPROVER_assume((pub_r000217_12_2 >= (-100)) && (pub_r000217_12_2 <= 100));
  __CPROVER_assume((pub_r000217_13_1 >= (-100)) && (pub_r000217_13_1 <= 100));
  __CPROVER_assume((pub_r000217_13_2 >= (-100)) && (pub_r000217_13_2 <= 100));
  __CPROVER_assume((pub_r000217_14_1 >= (-100)) && (pub_r000217_14_1 <= 100));
  __CPROVER_assume((pub_r000217_14_2 >= (-100)) && (pub_r000217_14_2 <= 100));
  __CPROVER_assume((pub_r000217_15_1 >= (-100)) && (pub_r000217_15_1 <= 100));
  __CPROVER_assume((pub_r000217_15_2 >= (-100)) && (pub_r000217_15_2 <= 100));
  __CPROVER_assume((sec_r000217_0_1 >= 0) && (sec_r000217_0_1 <= 255));
  __CPROVER_assume((sec_r000217_0_2 >= 0) && (sec_r000217_0_2 <= 255));
  __CPROVER_assume((sec_r000217_1_1 >= 0) && (sec_r000217_1_1 <= 255));
  __CPROVER_assume((sec_r000217_1_2 >= 0) && (sec_r000217_1_2 <= 255));
  __CPROVER_assume((sec_r000217_2_1 >= 0) && (sec_r000217_2_1 <= 255));
  __CPROVER_assume((sec_r000217_2_2 >= 0) && (sec_r000217_2_2 <= 255));
  __CPROVER_assume((sec_r000217_3_1 >= 0) && (sec_r000217_3_1 <= 255));
  __CPROVER_assume((sec_r000217_3_2 >= 0) && (sec_r000217_3_2 <= 255));
  __CPROVER_assume((sec_r000217_4_1 >= 0) && (sec_r000217_4_1 <= 255));
  __CPROVER_assume((sec_r000217_4_2 >= 0) && (sec_r000217_4_2 <= 255));
  __CPROVER_assume((sec_r000217_5_1 >= 0) && (sec_r000217_5_1 <= 255));
  __CPROVER_assume((sec_r000217_5_2 >= 0) && (sec_r000217_5_2 <= 255));
  __CPROVER_assume((sec_r000217_6_1 >= 0) && (sec_r000217_6_1 <= 255));
  __CPROVER_assume((sec_r000217_6_2 >= 0) && (sec_r000217_6_2 <= 255));
  __CPROVER_assume((sec_r000217_7_1 >= 0) && (sec_r000217_7_1 <= 255));
  __CPROVER_assume((sec_r000217_7_2 >= 0) && (sec_r000217_7_2 <= 255));
  __CPROVER_assume((sec_r000217_8_1 >= 0) && (sec_r000217_8_1 <= 255));
  __CPROVER_assume((sec_r000217_8_2 >= 0) && (sec_r000217_8_2 <= 255));
  __CPROVER_assume((sec_r000217_9_1 >= 0) && (sec_r000217_9_1 <= 255));
  __CPROVER_assume((sec_r000217_9_2 >= 0) && (sec_r000217_9_2 <= 255));
  __CPROVER_assume((sec_r000217_10_1 >= 0) && (sec_r000217_10_1 <= 255));
  __CPROVER_assume((sec_r000217_10_2 >= 0) && (sec_r000217_10_2 <= 255));
  __CPROVER_assume((sec_r000217_11_1 >= 0) && (sec_r000217_11_1 <= 255));
  __CPROVER_assume((sec_r000217_11_2 >= 0) && (sec_r000217_11_2 <= 255));
  __CPROVER_assume((sec_r000217_12_1 >= 0) && (sec_r000217_12_1 <= 255));
  __CPROVER_assume((sec_r000217_12_2 >= 0) && (sec_r000217_12_2 <= 255));
  __CPROVER_assume((sec_r000217_13_1 >= 0) && (sec_r000217_13_1 <= 255));
  __CPROVER_assume((sec_r000217_13_2 >= 0) && (sec_r000217_13_2 <= 255));
  __CPROVER_assume((sec_r000217_14_1 >= 0) && (sec_r000217_14_1 <= 255));
  __CPROVER_assume((sec_r000217_14_2 >= 0) && (sec_r000217_14_2 <= 255));
  __CPROVER_assume((sec_r000217_15_1 >= 0) && (sec_r000217_15_1 <= 255));
  __CPROVER_assume((sec_r000217_15_2 >= 0) && (sec_r000217_15_2 <= 255));
  __CPROVER_assume((sec_r000217_16_1 >= 0) && (sec_r000217_16_1 <= 255));
  __CPROVER_assume((sec_r000217_16_2 >= 0) && (sec_r000217_16_2 <= 255));
  __CPROVER_assume((sec_r000217_17_1 >= 0) && (sec_r000217_17_1 <= 255));
  __CPROVER_assume((sec_r000217_17_2 >= 0) && (sec_r000217_17_2 <= 255));
  __CPROVER_assume((sec_r000217_18_1 >= 0) && (sec_r000217_18_1 <= 255));
  __CPROVER_assume((sec_r000217_18_2 >= 0) && (sec_r000217_18_2 <= 255));
  __CPROVER_assume((sec_r000217_19_1 >= 0) && (sec_r000217_19_1 <= 255));
  __CPROVER_assume((sec_r000217_19_2 >= 0) && (sec_r000217_19_2 <= 255));
  struct DeviceConfig_R000217_1713_0 st_var_0_1 = {0};
  struct DeviceConfig_R000217_1713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000217_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000217_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000217_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000217_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000217_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000217_0_2 + 7) & 15;
  struct SensorNode_R000217_1713_1 st_var_1_1 = {0};
  struct SensorNode_R000217_1713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000217_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000217_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000217_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000217_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000217_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000217_0_2 + 9) & 15;
  struct AudioFrame_R000217_1713_2 st_var_2_1 = {0};
  struct AudioFrame_R000217_1713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000217_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000217_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000217_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000217_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000217_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000217_0_2 + 11) & 15;
  union RegisterBank_R000217_1713_0 u_var_1;
  union RegisterBank_R000217_1713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 46)
    {
      chk_sum_1 ^= stage_v_2_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_2_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 46)
    {
      chk_sum_2 ^= stage_v_2_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_3_1 = (st_var_0_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_0_2.buffer[0] ^ 6) & 3;
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

  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (st_var_2_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_2_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 8) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = (st_var_2_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_2_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 10) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((st_var_2_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_2_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 36)
    {
      chk_sum_1 ^= stage_v_11_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_11_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 36)
    {
      chk_sum_2 ^= stage_v_11_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
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

  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 18) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = ((st_var_0_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_0_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 44)
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
  if (stage_v_18_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 44)
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
  int stage_v_19_1 = ((st_var_1_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_1_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 53)
    {
      chk_sum_1 ^= stage_v_19_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_19_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 53)
    {
      chk_sum_2 ^= stage_v_19_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
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
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
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
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
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
  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = (st_var_2_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_2_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (st_var_1_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_1_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_40_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = ((st_var_2_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_2_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 39)
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
  if (stage_v_44_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 39)
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
  int stage_v_45_1 = ((st_var_0_1.buffer[0] * 2) + 142) & 63;
  int stage_v_45_2 = ((st_var_0_2.buffer[0] * 2) + 142) & 63;
  if (stage_v_45_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_45_1) - 5) & 255;
    if (stage_v_45_1 > 29)
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
  if (stage_v_45_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_45_2) - 5) & 255;
    if (stage_v_45_2 > 29)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 47) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 47) & 15;
  int stage_v_46_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_46_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= stage_v_46_1;
  chk_sum_2 ^= stage_v_46_2;
  int stage_v_47_1 = table_1[3];
  int stage_v_47_2 = table_2[3];
  table_1[3] = (table_1[0] + 95) & 63;
  table_2[3] = (table_2[0] + 95) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((st_var_1_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_1_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 30)
    {
      chk_sum_1 ^= stage_v_52_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_52_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 30)
    {
      chk_sum_2 ^= stage_v_52_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = ((st_var_0_1.buffer[0] * 2) + 169) & 63;
  int stage_v_54_2 = ((st_var_0_2.buffer[0] * 2) + 169) & 63;
  if (stage_v_54_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 28)
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
  if (stage_v_54_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 28)
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
  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = ((st_var_2_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_2_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 45)
    {
      chk_sum_1 ^= stage_v_56_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_56_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 45)
    {
      chk_sum_2 ^= stage_v_56_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_58_1 = (st_var_1_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_1_2.buffer[0] ^ 61) & 3;
  switch (stage_v_58_1)
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

  switch (stage_v_58_2)
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

  int stage_v_59_1 = (st_var_2_1.buffer[0] ^ 62) & 3;
  int stage_v_59_2 = (st_var_2_2.buffer[0] ^ 62) & 3;
  switch (stage_v_59_1)
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

  switch (stage_v_59_2)
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

  int stage_v_60_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_60_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  int stage_v_64_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_64_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (st_var_0_1.buffer[0] ^ 69) & 3;
  int stage_v_66_2 = (st_var_0_2.buffer[0] ^ 69) & 3;
  switch (stage_v_66_1)
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

  switch (stage_v_66_2)
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

  int stage_v_67_1 = table_1[3];
  int stage_v_67_2 = table_2[3];
  table_1[3] = (table_1[0] + 135) & 63;
  table_2[3] = (table_2[0] + 135) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_68_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_69_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (74 & 31);
  int stage_v_69_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (74 & 31);
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= (stage_v_69_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_69_2 << 1) & 127;
  int stage_v_70_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (75 & 31);
  int stage_v_70_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (75 & 31);
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= (stage_v_70_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_70_2 << 1) & 127;
  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (77 & 31);
  int stage_v_72_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (77 & 31);
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= (stage_v_72_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_72_2 << 1) & 127;
  int stage_v_73_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_73_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_74_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_74_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_75_1 = table_1[3];
  int stage_v_75_2 = table_2[3];
  table_1[3] = (table_1[0] + 151) & 63;
  table_2[3] = (table_2[0] + 151) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
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
  int stage_v_77_1 = ((st_var_2_1.buffer[2] * 2) + 238) & 63;
  int stage_v_77_2 = ((st_var_2_2.buffer[2] * 2) + 238) & 63;
  if (stage_v_77_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_77_1) - 5) & 255;
    if (stage_v_77_1 > 41)
    {
      chk_sum_1 ^= stage_v_77_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_77_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_77_2) - 5) & 255;
    if (stage_v_77_2 > 41)
    {
      chk_sum_2 ^= stage_v_77_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 79) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 79) & 15;
  int stage_v_78_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_78_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= stage_v_78_1;
  chk_sum_2 ^= stage_v_78_2;
  int stage_v_79_1 = table_1[3];
  int stage_v_79_2 = table_2[3];
  table_1[3] = (table_1[0] + 159) & 63;
  table_2[3] = (table_2[0] + 159) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 81) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 81) & 15;
  int stage_v_80_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_80_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= stage_v_80_1;
  chk_sum_2 ^= stage_v_80_2;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000217_9_1 & 1) != 0)
  {
    if ((sec_r000217_12_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000217_8_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000217_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000217_8_1 + 7) & 127;
  }
  if ((sec_r000217_9_2 & 1) != 0)
  {
    if ((sec_r000217_12_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000217_8_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000217_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000217_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000217_8_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000217_2_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000217_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000217_2_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000217_8_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000217_2_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000217_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000217_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000217_10_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000217_5_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000217_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000217_5_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000217_10_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000217_5_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000217_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000217_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000217_14_1 & 1) != 0)
  {
    if ((sec_r000217_14_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000217_13_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000217_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000217_13_1 + 7) & 127;
  }
  if ((sec_r000217_14_2 & 1) != 0)
  {
    if ((sec_r000217_14_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000217_13_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000217_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000217_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000217_12_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000217_14_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000217_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000217_14_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000217_12_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000217_14_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000217_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000217_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000217_9_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000217_8_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000217_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000217_8_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000217_9_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000217_8_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000217_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000217_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000217_10_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000217_10_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000217_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000217_10_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000217_10_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000217_10_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000217_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000217_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000217_5_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000217_4_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000217_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000217_4_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000217_5_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000217_4_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000217_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000217_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000217_3_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000217_5_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000217_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000217_5_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000217_3_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000217_5_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000217_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000217_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000217_14_1 & 1) != 0)
  {
    if ((sec_r000217_14_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000217_3_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000217_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000217_3_1 + 7) & 127;
  }
  if ((sec_r000217_14_2 & 1) != 0)
  {
    if ((sec_r000217_14_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000217_3_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000217_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000217_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000217_2_1 & 1) != 0)
  {
    if ((sec_r000217_9_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000217_5_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000217_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000217_5_1 + 7) & 127;
  }
  if ((sec_r000217_2_2 & 1) != 0)
  {
    if ((sec_r000217_9_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000217_5_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000217_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000217_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000217_2_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000217_3_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000217_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000217_3_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000217_2_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000217_3_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000217_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000217_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000217_18_1 & 1) != 0)
  {
    if ((sec_r000217_16_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000217_13_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000217_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000217_13_1 + 7) & 127;
  }
  if ((sec_r000217_18_2 & 1) != 0)
  {
    if ((sec_r000217_16_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000217_13_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000217_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000217_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000217_16_1 & 1) != 0)
  {
    if ((sec_r000217_14_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000217_10_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000217_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000217_10_1 + 7) & 127;
  }
  if ((sec_r000217_16_2 & 1) != 0)
  {
    if ((sec_r000217_14_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000217_10_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000217_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000217_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000217_14_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000217_12_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000217_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000217_12_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000217_14_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000217_12_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000217_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000217_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000217_12_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000217_10_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000217_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000217_10_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000217_12_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000217_10_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000217_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000217_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000217_10_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000217_15_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000217_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000217_15_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000217_10_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000217_15_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000217_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000217_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000217_4_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000217_8_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000217_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000217_8_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000217_4_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000217_8_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000217_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000217_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000217_16_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000217_1_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000217_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000217_1_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000217_16_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000217_1_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000217_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000217_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000217_0_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000217_10_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000217_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000217_10_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000217_0_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000217_10_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000217_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000217_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000217_11_1 & 1) != 0)
  {
    if ((sec_r000217_4_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000217_6_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000217_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000217_6_1 + 7) & 127;
  }
  if ((sec_r000217_11_2 & 1) != 0)
  {
    if ((sec_r000217_4_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000217_6_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000217_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000217_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000217_6_1 & 1) != 0)
  {
    if ((sec_r000217_5_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000217_0_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000217_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000217_0_1 + 7) & 127;
  }
  if ((sec_r000217_6_2 & 1) != 0)
  {
    if ((sec_r000217_5_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000217_0_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000217_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000217_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000217_17_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000217_10_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000217_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000217_10_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000217_17_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000217_10_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000217_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000217_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000217_5_1 & 1) != 0)
  {
    if ((sec_r000217_7_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000217_12_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000217_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000217_12_1 + 7) & 127;
  }
  if ((sec_r000217_5_2 & 1) != 0)
  {
    if ((sec_r000217_7_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000217_12_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000217_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000217_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000217_13_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000217_9_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000217_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000217_9_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000217_13_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000217_9_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000217_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000217_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000217_16_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000217_8_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000217_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000217_8_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000217_16_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000217_8_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000217_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000217_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000217_2_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000217_11_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000217_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000217_11_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000217_2_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000217_11_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000217_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000217_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000217_3_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000217_9_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000217_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000217_9_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000217_3_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000217_9_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000217_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000217_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000217_11_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000217_11_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000217_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000217_11_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000217_11_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000217_11_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000217_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000217_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000217_8_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000217_5_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000217_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000217_5_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000217_8_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000217_5_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000217_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000217_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000217_1_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000217_4_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000217_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000217_4_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000217_1_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000217_4_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000217_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000217_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000217_13_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000217_8_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000217_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000217_8_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000217_13_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000217_8_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000217_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000217_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000217_5_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000217_2_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000217_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000217_2_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000217_5_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000217_2_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000217_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000217_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000217_1_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000217_10_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000217_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000217_10_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000217_1_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000217_10_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000217_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000217_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000217_1_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000217_4_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000217_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000217_4_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000217_1_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000217_4_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000217_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000217_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000217_0_1 & 1) != 0)
  {
    if ((sec_r000217_14_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000217_9_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000217_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000217_9_1 + 7) & 127;
  }
  if ((sec_r000217_0_2 & 1) != 0)
  {
    if ((sec_r000217_14_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000217_9_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000217_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000217_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000217_10_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000217_9_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000217_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000217_9_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000217_10_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000217_9_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000217_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000217_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000217_13_1 & 1) != 0)
  {
    if ((sec_r000217_12_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000217_7_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000217_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000217_7_1 + 7) & 127;
  }
  if ((sec_r000217_13_2 & 1) != 0)
  {
    if ((sec_r000217_12_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000217_7_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000217_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000217_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000217_2_1 & 1) != 0)
  {
    if ((sec_r000217_1_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000217_8_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000217_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000217_8_1 + 7) & 127;
  }
  if ((sec_r000217_2_2 & 1) != 0)
  {
    if ((sec_r000217_1_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000217_8_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000217_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000217_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000217_1_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000217_13_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000217_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000217_13_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000217_1_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000217_13_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000217_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000217_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000217_13_1 & 1) != 0)
  {
    if ((sec_r000217_3_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000217_9_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000217_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000217_9_1 + 7) & 127;
  }
  if ((sec_r000217_13_2 & 1) != 0)
  {
    if ((sec_r000217_3_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000217_9_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000217_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000217_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000217_7_1 & 1) != 0)
  {
    if ((sec_r000217_18_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000217_9_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000217_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000217_9_1 + 7) & 127;
  }
  if ((sec_r000217_7_2 & 1) != 0)
  {
    if ((sec_r000217_18_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000217_9_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000217_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000217_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000217_3_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000217_7_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000217_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000217_7_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000217_3_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000217_7_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000217_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000217_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000217_6_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000217_12_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000217_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000217_12_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000217_6_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000217_12_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000217_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000217_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000217_12_1 & 1) != 0)
  {
    if ((sec_r000217_5_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000217_10_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000217_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000217_10_1 + 7) & 127;
  }
  if ((sec_r000217_12_2 & 1) != 0)
  {
    if ((sec_r000217_5_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000217_10_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000217_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000217_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000217_0_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000217_0_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000217_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000217_0_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000217_0_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000217_0_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000217_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000217_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000217_3_1 & 1) != 0)
  {
    if ((sec_r000217_5_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000217_4_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000217_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000217_4_1 + 7) & 127;
  }
  if ((sec_r000217_3_2 & 1) != 0)
  {
    if ((sec_r000217_5_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000217_4_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000217_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000217_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000217_16_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000217_6_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000217_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000217_6_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000217_16_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000217_6_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000217_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000217_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000217_19_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000217_3_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000217_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000217_3_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000217_19_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000217_3_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000217_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000217_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000217_14_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000217_15_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000217_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000217_15_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000217_14_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000217_15_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000217_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000217_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000217_4_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000217_6_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000217_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000217_6_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000217_4_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000217_6_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000217_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000217_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000217_12_1 & 1) != 0)
  {
    if ((sec_r000217_0_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000217_15_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000217_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000217_15_1 + 7) & 127;
  }
  if ((sec_r000217_12_2 & 1) != 0)
  {
    if ((sec_r000217_0_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000217_15_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000217_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000217_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000217_17_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000217_2_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000217_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000217_2_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000217_17_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000217_2_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000217_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000217_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000217_5_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000217_7_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000217_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000217_7_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000217_5_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000217_7_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000217_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000217_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000217_5_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000217_2_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000217_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000217_2_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000217_5_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000217_2_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000217_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000217_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000217_6_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000217_1_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000217_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000217_1_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000217_6_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000217_1_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000217_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000217_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000217_13_1 & 1) != 0)
  {
    if ((sec_r000217_7_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000217_6_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000217_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000217_6_1 + 7) & 127;
  }
  if ((sec_r000217_13_2 & 1) != 0)
  {
    if ((sec_r000217_7_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000217_6_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000217_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000217_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000217_13_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000217_4_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000217_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000217_4_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000217_13_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000217_4_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000217_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000217_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000217_15_1 & 1) != 0)
  {
    if ((sec_r000217_8_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000217_13_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000217_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000217_13_1 + 7) & 127;
  }
  if ((sec_r000217_15_2 & 1) != 0)
  {
    if ((sec_r000217_8_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000217_13_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000217_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000217_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000217_4_1 & 1) != 0)
  {
    if ((sec_r000217_17_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000217_9_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000217_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000217_9_1 + 7) & 127;
  }
  if ((sec_r000217_4_2 & 1) != 0)
  {
    if ((sec_r000217_17_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000217_9_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000217_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000217_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000217_14_1 & 1) != 0)
  {
    if ((sec_r000217_8_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000217_1_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000217_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000217_1_1 + 7) & 127;
  }
  if ((sec_r000217_14_2 & 1) != 0)
  {
    if ((sec_r000217_8_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000217_1_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000217_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000217_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000217_14_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000217_5_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000217_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000217_5_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000217_14_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000217_5_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000217_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000217_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((sec_r000217_12_1 & 1) != 0)
  {
    if ((sec_r000217_18_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000217_13_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000217_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000217_13_1 + 7) & 127;
  }
  if ((sec_r000217_12_2 & 1) != 0)
  {
    if ((sec_r000217_18_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000217_13_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000217_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000217_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000217_0_1 & 1) != 0)
  {
    if ((sec_r000217_17_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000217_0_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000217_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000217_0_1 + 7) & 127;
  }
  if ((sec_r000217_0_2 & 1) != 0)
  {
    if ((sec_r000217_17_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000217_0_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000217_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000217_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000217_2_1 & 1) != 0)
  {
    if ((sec_r000217_16_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000217_6_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000217_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000217_6_1 + 7) & 127;
  }
  if ((sec_r000217_2_2 & 1) != 0)
  {
    if ((sec_r000217_16_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000217_6_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000217_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000217_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000217_16_1 & 1) != 0)
  {
    if ((sec_r000217_14_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000217_12_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000217_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000217_12_1 + 7) & 127;
  }
  if ((sec_r000217_16_2 & 1) != 0)
  {
    if ((sec_r000217_14_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000217_12_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000217_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000217_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((sec_r000217_8_1 & 1) != 0)
  {
    if ((sec_r000217_5_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000217_5_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000217_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000217_5_1 + 7) & 127;
  }
  if ((sec_r000217_8_2 & 1) != 0)
  {
    if ((sec_r000217_5_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000217_5_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000217_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000217_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000217_2_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000217_15_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000217_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000217_15_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000217_2_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000217_15_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000217_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000217_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000217_19_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000217_4_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000217_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000217_4_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000217_19_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000217_4_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000217_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000217_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((sec_r000217_11_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000217_10_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000217_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000217_10_1 + 7) & 127;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((sec_r000217_11_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000217_10_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000217_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000217_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((sec_r000217_5_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000217_4_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000217_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000217_4_1 + 7) & 127;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((sec_r000217_5_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000217_4_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000217_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000217_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((sec_r000217_1_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000217_2_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000217_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000217_2_1 + 7) & 127;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((sec_r000217_1_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000217_2_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000217_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000217_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((sec_r000217_2_1 & 1) != 0)
  {
    if ((sec_r000217_10_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000217_4_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000217_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000217_4_1 + 7) & 127;
  }
  if ((sec_r000217_2_2 & 1) != 0)
  {
    if ((sec_r000217_10_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000217_4_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000217_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000217_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((sec_r000217_19_1 & 1) != 0)
  {
    if ((sec_r000217_17_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000217_3_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000217_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000217_3_1 + 7) & 127;
  }
  if ((sec_r000217_19_2 & 1) != 0)
  {
    if ((sec_r000217_17_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000217_3_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000217_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000217_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((sec_r000217_9_1 & 1) != 0)
  {
    if ((sec_r000217_10_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000217_11_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000217_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000217_11_1 + 7) & 127;
  }
  if ((sec_r000217_9_2 & 1) != 0)
  {
    if ((sec_r000217_10_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000217_11_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000217_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000217_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000217_5_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000217_13_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000217_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000217_13_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000217_5_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000217_13_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000217_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000217_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000217_3_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000217_11_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000217_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000217_11_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000217_3_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000217_11_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000217_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000217_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000217_17_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000217_7_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000217_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000217_7_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000217_17_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000217_7_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000217_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000217_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((sec_r000217_12_1 & 1) != 0)
  {
    if ((sec_r000217_18_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000217_7_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000217_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000217_7_1 + 7) & 127;
  }
  if ((sec_r000217_12_2 & 1) != 0)
  {
    if ((sec_r000217_18_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000217_7_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000217_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000217_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r000217_15_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000217_7_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000217_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000217_7_1 + 7) & 127;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r000217_15_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000217_7_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000217_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000217_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000217_13_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000217_2_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000217_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000217_2_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000217_13_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000217_2_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000217_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000217_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((sec_r000217_2_1 & 1) != 0)
  {
    if ((sec_r000217_9_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000217_7_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000217_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000217_7_1 + 7) & 127;
  }
  if ((sec_r000217_2_2 & 1) != 0)
  {
    if ((sec_r000217_9_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000217_7_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000217_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000217_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((sec_r000217_16_1 & 1) != 0)
  {
    if ((sec_r000217_0_1 & 2) != 0)
    {
      stage_v_163_1 = (pub_r000217_11_1 + 31) & 127;
    }
    else
    {
      stage_v_163_1 = (pub_r000217_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_1 = (pub_r000217_11_1 + 7) & 127;
  }
  if ((sec_r000217_16_2 & 1) != 0)
  {
    if ((sec_r000217_0_2 & 2) != 0)
    {
      stage_v_163_2 = (pub_r000217_11_2 + 31) & 127;
    }
    else
    {
      stage_v_163_2 = (pub_r000217_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_2 = (pub_r000217_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000217_11_1 & 2) != 0)
    {
      stage_v_164_1 = (pub_r000217_7_1 + 31) & 127;
    }
    else
    {
      stage_v_164_1 = (pub_r000217_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_1 = (pub_r000217_7_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000217_11_2 & 2) != 0)
    {
      stage_v_164_2 = (pub_r000217_7_2 + 31) & 127;
    }
    else
    {
      stage_v_164_2 = (pub_r000217_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_2 = (pub_r000217_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((sec_r000217_9_1 & 1) != 0)
  {
    if ((sec_r000217_19_1 & 2) != 0)
    {
      stage_v_165_1 = (pub_r000217_3_1 + 31) & 127;
    }
    else
    {
      stage_v_165_1 = (pub_r000217_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_1 = (pub_r000217_3_1 + 7) & 127;
  }
  if ((sec_r000217_9_2 & 1) != 0)
  {
    if ((sec_r000217_19_2 & 2) != 0)
    {
      stage_v_165_2 = (pub_r000217_3_2 + 31) & 127;
    }
    else
    {
      stage_v_165_2 = (pub_r000217_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_2 = (pub_r000217_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  if ((sec_r000217_18_1 & 1) != 0)
  {
    if ((sec_r000217_1_1 & 2) != 0)
    {
      stage_v_166_1 = (pub_r000217_7_1 + 31) & 127;
    }
    else
    {
      stage_v_166_1 = (pub_r000217_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_1 = (pub_r000217_7_1 + 7) & 127;
  }
  if ((sec_r000217_18_2 & 1) != 0)
  {
    if ((sec_r000217_1_2 & 2) != 0)
    {
      stage_v_166_2 = (pub_r000217_7_2 + 31) & 127;
    }
    else
    {
      stage_v_166_2 = (pub_r000217_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_2 = (pub_r000217_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  if ((sec_r000217_5_1 & 1) != 0)
  {
    if ((sec_r000217_7_1 & 2) != 0)
    {
      stage_v_167_1 = (pub_r000217_0_1 + 31) & 127;
    }
    else
    {
      stage_v_167_1 = (pub_r000217_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_1 = (pub_r000217_0_1 + 7) & 127;
  }
  if ((sec_r000217_5_2 & 1) != 0)
  {
    if ((sec_r000217_7_2 & 2) != 0)
    {
      stage_v_167_2 = (pub_r000217_0_2 + 31) & 127;
    }
    else
    {
      stage_v_167_2 = (pub_r000217_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_2 = (pub_r000217_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  if ((sec_r000217_18_1 & 1) != 0)
  {
    if ((sec_r000217_14_1 & 2) != 0)
    {
      stage_v_168_1 = (pub_r000217_1_1 + 31) & 127;
    }
    else
    {
      stage_v_168_1 = (pub_r000217_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_168_1 = (pub_r000217_1_1 + 7) & 127;
  }
  if ((sec_r000217_18_2 & 1) != 0)
  {
    if ((sec_r000217_14_2 & 2) != 0)
    {
      stage_v_168_2 = (pub_r000217_1_2 + 31) & 127;
    }
    else
    {
      stage_v_168_2 = (pub_r000217_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_168_2 = (pub_r000217_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000217_19_1 != sec_r000217_19_2);
  __CPROVER_assume(pub_r000217_13_1 == pub_r000217_13_2);
  __CPROVER_assume(pub_r000217_2_1 == pub_r000217_2_2);
  __CPROVER_assume(sec_r000217_3_1 != sec_r000217_3_2);
  __CPROVER_assume(pub_r000217_6_1 == pub_r000217_6_2);
  __CPROVER_assume(sec_r000217_1_1 != sec_r000217_1_2);
  __CPROVER_assume(sec_r000217_15_1 != sec_r000217_15_2);
  __CPROVER_assume(sec_r000217_14_1 != sec_r000217_14_2);
  __CPROVER_assume(sec_r000217_2_1 != sec_r000217_2_2);
  __CPROVER_assume(sec_r000217_13_1 != sec_r000217_13_2);
  __CPROVER_assume(pub_r000217_10_1 == pub_r000217_10_2);
  __CPROVER_assume(pub_r000217_0_1 == pub_r000217_0_2);
  __CPROVER_assume(sec_r000217_7_1 != sec_r000217_7_2);
  __CPROVER_assume(pub_r000217_11_1 == pub_r000217_11_2);
  __CPROVER_assume(sec_r000217_11_1 != sec_r000217_11_2);
  __CPROVER_assume(pub_r000217_1_1 == pub_r000217_1_2);
  __CPROVER_assume(sec_r000217_6_1 != sec_r000217_6_2);
  __CPROVER_assume(pub_r000217_9_1 == pub_r000217_9_2);
  __CPROVER_assume(sec_r000217_10_1 != sec_r000217_10_2);
  __CPROVER_assume(sec_r000217_5_1 != sec_r000217_5_2);
  __CPROVER_assume(sec_r000217_0_1 != sec_r000217_0_2);
  __CPROVER_assume(pub_r000217_7_1 == pub_r000217_7_2);
  __CPROVER_assume(pub_r000217_4_1 == pub_r000217_4_2);
  __CPROVER_assume(sec_r000217_12_1 != sec_r000217_12_2);
  __CPROVER_assume(pub_r000217_8_1 == pub_r000217_8_2);
  __CPROVER_assume(sec_r000217_4_1 != sec_r000217_4_2);
  __CPROVER_assume(sec_r000217_9_1 != sec_r000217_9_2);
  __CPROVER_assume(pub_r000217_3_1 == pub_r000217_3_2);
  __CPROVER_assume(pub_r000217_12_1 == pub_r000217_12_2);
  __CPROVER_assume(sec_r000217_16_1 != sec_r000217_16_2);
  __CPROVER_assume(sec_r000217_17_1 != sec_r000217_17_2);
  __CPROVER_assume(sec_r000217_18_1 != sec_r000217_18_2);
  __CPROVER_assume(pub_r000217_15_1 == pub_r000217_15_2);
  __CPROVER_assume(pub_r000217_5_1 == pub_r000217_5_2);
  __CPROVER_assume(sec_r000217_8_1 != sec_r000217_8_2);
  __CPROVER_assume(pub_r000217_14_1 == pub_r000217_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.envelope == st_var_2_2.envelope);
  assert(st_var_2_1.rms == st_var_2_2.rms);
  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.channels == st_var_2_2.channels);
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
}


