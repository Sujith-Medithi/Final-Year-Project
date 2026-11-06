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
struct DeviceConfig_R000424_2413_0
{
  short timeout;
  short port;
  int parity;
  unsigned char id;
  int baud_rate;
  int stop_bits;
  int buffer[3];
};
struct EventLog_R000424_2413_1
{
  int severity;
  unsigned char seq;
  unsigned char timestamp;
  int buffer[3];
};
union RegisterBank_R000424_2413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000424_2413_1
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
void fn_R000424_2413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st_1 = {0};
  struct EventLog_R000424_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int scale_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_78_1 > 21)
  {
    acc_1 = ((acc_1 + (scale_78_1 * 2)) + 5) & 127;
    aux_1 ^= scale_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_78_2 > 21)
  {
    acc_2 = ((acc_2 + (scale_78_2 * 2)) + 5) & 127;
    aux_2 ^= scale_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_43_1 = local_arr_1[aux_1 % 3];
  int coefficient_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_43_2 * 2)) & 127;
  int sample_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_33_1) & 63;
  aux_2 = (aux_2 + sample_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_98_1)
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

  switch (quotient_98_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_78_1 == scale_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_43_1 == coefficient_43_2);
  assert(sample_33_1 == sample_33_2);
  assert(quotient_98_1 == quotient_98_2);
}

int fn_R000424_2413_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int scale_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_78 > 21)
  {
    acc = ((acc + (scale_78 * 2)) + 5) & 127;
    aux ^= scale_78 & 15;
  }
  else
  {
    acc = ((acc - scale_78) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_43 = local_arr[aux % 3];
  acc = (acc + (coefficient_43 * 2)) & 127;
  int sample_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_33) & 63;
  acc ^= aux;
  int quotient_98 = (aux + st.buffer[1]) & 3;
  switch (quotient_98)
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

void fn_R000424_2413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st_1 = {0};
  struct DeviceConfig_R000424_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_47_1 > 41)
  {
    acc_1 = ((acc_1 + (scale_47_1 * 2)) + 5) & 127;
    aux_1 ^= scale_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_47_2 > 41)
  {
    acc_2 = ((acc_2 + (scale_47_2 * 2)) + 5) & 127;
    aux_2 ^= scale_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_65_1)
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

  switch (mask_65_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_47_1 == scale_47_2);
  assert(mask_65_1 == mask_65_2);
}

int fn_R000424_2413_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_47 > 41)
  {
    acc = ((acc + (scale_47 * 2)) + 5) & 127;
    aux ^= scale_47 & 15;
  }
  else
  {
    acc = ((acc - scale_47) + 11) & 127;
    aux += 3;
  }
  int mask_65 = (aux + st.buffer[1]) & 3;
  switch (mask_65)
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

void fn_R000424_2413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st_1 = {0};
  struct EventLog_R000424_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_86_1 = local_arr_1[aux_1 % 3];
  int cursor_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_86_1 == cursor_86_2);
}

int fn_R000424_2413_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int cursor_86 = local_arr[aux % 3];
  acc = (acc + (cursor_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000424_2413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st_1 = {0};
  struct EventLog_R000424_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int margin_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_27_1 > 48)
  {
    acc_1 = ((acc_1 + (margin_27_1 * 2)) + 5) & 127;
    aux_1 ^= margin_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_27_2 > 48)
  {
    acc_2 = ((acc_2 + (margin_27_2 * 2)) + 5) & 127;
    aux_2 ^= margin_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_62_1 = local_arr_1[aux_1 % 3];
  int bound_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_62_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_27_1 == margin_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_62_1 == bound_62_2);
}

int fn_R000424_2413_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int margin_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_27 > 48)
  {
    acc = ((acc + (margin_27 * 2)) + 5) & 127;
    aux ^= margin_27 & 15;
  }
  else
  {
    acc = ((acc - margin_27) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_62 = local_arr[aux % 3];
  acc = (acc + (bound_62 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000424_2413_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st_1 = {0};
  struct EventLog_R000424_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_50_1 = local_arr_1[aux_1 % 3];
  int metric_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_50_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_95_1 > 20)
  {
    acc_1 = ((acc_1 + (weight_95_1 * 2)) + 5) & 127;
    aux_1 ^= weight_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_95_2 > 20)
  {
    acc_2 = ((acc_2 + (weight_95_2 * 2)) + 5) & 127;
    aux_2 ^= weight_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_95_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_50_1 == metric_50_2);
  assert(weight_95_1 == weight_95_2);
}

int fn_R000424_2413_4(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int metric_50 = local_arr[aux % 3];
  acc = (acc + (metric_50 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_95 > 20)
  {
    acc = ((acc + (weight_95 * 2)) + 5) & 127;
    aux ^= weight_95 & 15;
  }
  else
  {
    acc = ((acc - weight_95) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000424_2413_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st_1 = {0};
  struct DeviceConfig_R000424_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int checksum_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_99_1)
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

  switch (checksum_99_2)
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

  int offset_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_66_1 > 32)
  {
    acc_1 = ((acc_1 + (offset_66_1 * 2)) + 5) & 127;
    aux_1 ^= offset_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_66_2 > 32)
  {
    acc_2 = ((acc_2 + (offset_66_2 * 2)) + 5) & 127;
    aux_2 ^= offset_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_99_1 == checksum_99_2);
  assert(offset_66_1 == offset_66_2);
}

int fn_R000424_2413_5(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int checksum_99 = (aux + st.buffer[1]) & 3;
  switch (checksum_99)
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

  int offset_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_66 > 32)
  {
    acc = ((acc + (offset_66 * 2)) + 5) & 127;
    aux ^= offset_66 & 15;
  }
  else
  {
    acc = ((acc - offset_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000424_2413_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st_1 = {0};
  struct DeviceConfig_R000424_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int offset_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_40_1 > 24)
  {
    acc_1 = ((acc_1 + (offset_40_1 * 2)) + 5) & 127;
    aux_1 ^= offset_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_40_2 > 24)
  {
    acc_2 = ((acc_2 + (offset_40_2 * 2)) + 5) & 127;
    aux_2 ^= offset_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_40_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_40_1 == offset_40_2);
}

int fn_R000424_2413_6(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int offset_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_40 > 24)
  {
    acc = ((acc + (offset_40 * 2)) + 5) & 127;
    aux ^= offset_40 & 15;
  }
  else
  {
    acc = ((acc - offset_40) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000424_2413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st_1 = {0};
  struct EventLog_R000424_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_94_1 = local_arr_1[aux_1 % 3];
  int scale_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_94_2 * 2)) & 127;
  int bound_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_42_1)
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

  switch (bound_42_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_32_1) & 63;
  aux_2 = (aux_2 + vector_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_94_1 == scale_94_2);
  assert(bound_42_1 == bound_42_2);
  assert(vector_32_1 == vector_32_2);
}

int fn_R000424_2413_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int scale_94 = local_arr[aux % 3];
  acc = (acc + (scale_94 * 2)) & 127;
  int bound_42 = (aux + st.buffer[1]) & 3;
  switch (bound_42)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_32) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000424_2413_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st_1 = {0};
  struct DeviceConfig_R000424_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int threshold_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_78_1 > 45)
  {
    acc_1 = ((acc_1 + (threshold_78_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_78_2 > 45)
  {
    acc_2 = ((acc_2 + (threshold_78_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_51_1) & 63;
  aux_2 = (aux_2 + quotient_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_54_1)
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

  switch (offset_54_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_78_1 == threshold_78_2);
  assert(quotient_51_1 == quotient_51_2);
  assert(offset_54_1 == offset_54_2);
}

int fn_R000424_2413_8(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int threshold_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_78 > 45)
  {
    acc = ((acc + (threshold_78 * 2)) + 5) & 127;
    aux ^= threshold_78 & 15;
  }
  else
  {
    acc = ((acc - threshold_78) + 11) & 127;
    aux += 3;
  }
  int quotient_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_51) & 63;
  acc ^= aux;
  int offset_54 = (aux + st.buffer[1]) & 3;
  switch (offset_54)
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

void fn_R000424_2413_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st_1 = {0};
  struct DeviceConfig_R000424_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int tracker_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_28_1 > 36)
  {
    acc_1 = ((acc_1 + (tracker_28_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_28_2 > 36)
  {
    acc_2 = ((acc_2 + (tracker_28_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_28_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_52_1) & 63;
  aux_2 = (aux_2 + factor_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_23_1)
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

  switch (coefficient_23_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_28_1 == tracker_28_2);
  assert(factor_52_1 == factor_52_2);
  assert(coefficient_23_1 == coefficient_23_2);
}

int fn_R000424_2413_9(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int tracker_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_28 > 36)
  {
    acc = ((acc + (tracker_28 * 2)) + 5) & 127;
    aux ^= tracker_28 & 15;
  }
  else
  {
    acc = ((acc - tracker_28) + 11) & 127;
    aux += 3;
  }
  int factor_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_52) & 63;
  acc ^= aux;
  int coefficient_23 = (aux + st.buffer[1]) & 3;
  switch (coefficient_23)
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

void fn_R000424_2413_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st_1 = {0};
  struct EventLog_R000424_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int accumulator_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_62_1 > 50)
  {
    acc_1 = ((acc_1 + (accumulator_62_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_62_2 > 50)
  {
    acc_2 = ((acc_2 + (accumulator_62_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_45_1 = local_arr_1[aux_1 % 3];
  int quantum_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_45_2 * 2)) & 127;
  int residue_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_51_1)
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

  switch (residue_51_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_62_1 == accumulator_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_45_1 == quantum_45_2);
  assert(residue_51_1 == residue_51_2);
}

int fn_R000424_2413_10(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int accumulator_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_62 > 50)
  {
    acc = ((acc + (accumulator_62 * 2)) + 5) & 127;
    aux ^= accumulator_62 & 15;
  }
  else
  {
    acc = ((acc - accumulator_62) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_45 = local_arr[aux % 3];
  acc = (acc + (quantum_45 * 2)) & 127;
  int residue_51 = (aux + st.buffer[1]) & 3;
  switch (residue_51)
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

void fn_R000424_2413_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st_1 = {0};
  struct DeviceConfig_R000424_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int residue_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_31_1) & 63;
  aux_2 = (aux_2 + residue_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_78_1)
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

  switch (coefficient_78_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_51_1 = local_arr_1[aux_1 % 3];
  int vector_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_31_1 == residue_31_2);
  assert(coefficient_78_1 == coefficient_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_51_1 == vector_51_2);
}

int fn_R000424_2413_11(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int residue_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_31) & 63;
  acc ^= aux;
  int coefficient_78 = (aux + st.buffer[1]) & 3;
  switch (coefficient_78)
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
  int local_arr[3] = {4, 9, 15};
  int vector_51 = local_arr[aux % 3];
  acc = (acc + (vector_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000424_2413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st_1 = {0};
  struct DeviceConfig_R000424_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_89_1 = local_arr_1[aux_1 % 3];
  int parity_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_89_2 * 2)) & 127;
  int parity_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_49_1) & 63;
  aux_2 = (aux_2 + parity_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_44_1)
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

  switch (factor_44_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_89_1 == parity_89_2);
  assert(parity_49_1 == parity_49_2);
  assert(factor_44_1 == factor_44_2);
}

int fn_R000424_2413_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_89 = local_arr[aux % 3];
  acc = (acc + (parity_89 * 2)) & 127;
  int parity_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_49) & 63;
  acc ^= aux;
  int factor_44 = (aux + st.buffer[1]) & 3;
  switch (factor_44)
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

void fn_R000424_2413_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st_1 = {0};
  struct EventLog_R000424_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_10_1 = local_arr_1[aux_1 % 3];
  int residue_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_10_2 * 2)) & 127;
  int index_reg_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_13_1) & 63;
  aux_2 = (aux_2 + index_reg_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_10_1 == residue_10_2);
  assert(index_reg_13_1 == index_reg_13_2);
}

int fn_R000424_2413_13(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_10 = local_arr[aux % 3];
  acc = (acc + (residue_10 * 2)) & 127;
  int index_reg_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000424_2413_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st_1 = {0};
  struct EventLog_R000424_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int mask_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_56_1) & 63;
  aux_2 = (aux_2 + mask_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_38_1 > 30)
  {
    acc_1 = ((acc_1 + (residue_38_1 * 2)) + 5) & 127;
    aux_1 ^= residue_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_38_2 > 30)
  {
    acc_2 = ((acc_2 + (residue_38_2 * 2)) + 5) & 127;
    aux_2 ^= residue_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_60_1)
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

  switch (margin_60_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_56_1 == mask_56_2);
  assert(residue_38_1 == residue_38_2);
  assert(margin_60_1 == margin_60_2);
}

int fn_R000424_2413_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int mask_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_56) & 63;
  acc ^= aux;
  int residue_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_38 > 30)
  {
    acc = ((acc + (residue_38 * 2)) + 5) & 127;
    aux ^= residue_38 & 15;
  }
  else
  {
    acc = ((acc - residue_38) + 11) & 127;
    aux += 3;
  }
  int margin_60 = (aux + st.buffer[1]) & 3;
  switch (margin_60)
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

void fn_R000424_2413_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st_1 = {0};
  struct DeviceConfig_R000424_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int pivot_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_96_1)
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

  switch (pivot_96_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_96_1 == pivot_96_2);
}

int fn_R000424_2413_15(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int pivot_96 = (aux + st.buffer[1]) & 3;
  switch (pivot_96)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000424_2413_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st_1 = {0};
  struct EventLog_R000424_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int damping_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_18_1) & 63;
  aux_2 = (aux_2 + damping_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_19_1 > 16)
  {
    acc_1 = ((acc_1 + (index_reg_19_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_19_2 > 16)
  {
    acc_2 = ((acc_2 + (index_reg_19_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_24_1 = local_arr_1[aux_1 % 3];
  int mask_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_24_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_18_1 == damping_18_2);
  assert(index_reg_19_1 == index_reg_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_24_1 == mask_24_2);
}

int fn_R000424_2413_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int damping_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_18) & 63;
  acc ^= aux;
  int index_reg_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_19 > 16)
  {
    acc = ((acc + (index_reg_19 * 2)) + 5) & 127;
    aux ^= index_reg_19 & 15;
  }
  else
  {
    acc = ((acc - index_reg_19) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_24 = local_arr[aux % 3];
  acc = (acc + (mask_24 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000424_2413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st_1 = {0};
  struct EventLog_R000424_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int parity_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_27_1)
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

  switch (parity_27_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_27_1 == parity_27_2);
}

int fn_R000424_2413_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int parity_27 = (aux + st.buffer[1]) & 3;
  switch (parity_27)
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

void fn_R000424_2413_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st_1 = {0};
  struct DeviceConfig_R000424_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int weight_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_67_1) & 63;
  aux_2 = (aux_2 + weight_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_68_1 = local_arr_1[aux_1 % 3];
  int index_reg_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_67_1 == weight_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_68_1 == index_reg_68_2);
}

int fn_R000424_2413_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int weight_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_68 = local_arr[aux % 3];
  acc = (acc + (index_reg_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000424_2413_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st_1 = {0};
  struct EventLog_R000424_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_55_1 = local_arr_1[aux_1 % 3];
  int pivot_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_55_2 * 2)) & 127;
  int phase_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_36_1) & 63;
  aux_2 = (aux_2 + phase_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_12_1)
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

  switch (vector_12_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_55_1 == pivot_55_2);
  assert(phase_36_1 == phase_36_2);
  assert(vector_12_1 == vector_12_2);
}

int fn_R000424_2413_19(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int pivot_55 = local_arr[aux % 3];
  acc = (acc + (pivot_55 * 2)) & 127;
  int phase_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_36) & 63;
  acc ^= aux;
  int vector_12 = (aux + st.buffer[1]) & 3;
  switch (vector_12)
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

void fn_R000424_2413_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st_1 = {0};
  struct DeviceConfig_R000424_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int checksum_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_89_1) & 63;
  aux_2 = (aux_2 + checksum_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_16_1 = local_arr_1[aux_1 % 3];
  int stride_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_16_2 * 2)) & 127;
  int index_reg_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_70_1 > 13)
  {
    acc_1 = ((acc_1 + (index_reg_70_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_70_2 > 13)
  {
    acc_2 = ((acc_2 + (index_reg_70_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_62_1)
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

  switch (segment_62_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_89_1 == checksum_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_16_1 == stride_16_2);
  assert(index_reg_70_1 == index_reg_70_2);
  assert(segment_62_1 == segment_62_2);
}

int fn_R000424_2413_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000424_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int checksum_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_89) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_16 = local_arr[aux % 3];
  acc = (acc + (stride_16 * 2)) & 127;
  int index_reg_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_70 > 13)
  {
    acc = ((acc + (index_reg_70 * 2)) + 5) & 127;
    aux ^= index_reg_70 & 15;
  }
  else
  {
    acc = ((acc - index_reg_70) + 11) & 127;
    aux += 3;
  }
  int segment_62 = (aux + st.buffer[1]) & 3;
  switch (segment_62)
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

void fn_R000424_2413_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st_1 = {0};
  struct EventLog_R000424_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_34_1 = local_arr_1[aux_1 % 3];
  int vector_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_34_2 * 2)) & 127;
  int vector_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_69_1 > 42)
  {
    acc_1 = ((acc_1 + (vector_69_1 * 2)) + 5) & 127;
    aux_1 ^= vector_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_69_2 > 42)
  {
    acc_2 = ((acc_2 + (vector_69_2 * 2)) + 5) & 127;
    aux_2 ^= vector_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_32_1) & 63;
  aux_2 = (aux_2 + vector_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_34_1 == vector_34_2);
  assert(vector_69_1 == vector_69_2);
  assert(vector_32_1 == vector_32_2);
}

int fn_R000424_2413_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000424_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_34 = local_arr[aux % 3];
  acc = (acc + (vector_34 * 2)) & 127;
  int vector_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_69 > 42)
  {
    acc = ((acc + (vector_69 * 2)) + 5) & 127;
    aux ^= vector_69 & 15;
  }
  else
  {
    acc = ((acc - vector_69) + 11) & 127;
    aux += 3;
  }
  int vector_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_32) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000424_0_1;
  int sec_r000424_0_2;
  int sec_r000424_1_1;
  int sec_r000424_1_2;
  int sec_r000424_2_1;
  int sec_r000424_2_2;
  int sec_r000424_3_1;
  int sec_r000424_3_2;
  int sec_r000424_4_1;
  int sec_r000424_4_2;
  int sec_r000424_5_1;
  int sec_r000424_5_2;
  int sec_r000424_6_1;
  int sec_r000424_6_2;
  int sec_r000424_7_1;
  int sec_r000424_7_2;
  int sec_r000424_8_1;
  int sec_r000424_8_2;
  int sec_r000424_9_1;
  int sec_r000424_9_2;
  int sec_r000424_10_1;
  int sec_r000424_10_2;
  int sec_r000424_11_1;
  int sec_r000424_11_2;
  int sec_r000424_12_1;
  int sec_r000424_12_2;
  int sec_r000424_13_1;
  int sec_r000424_13_2;
  int sec_r000424_14_1;
  int sec_r000424_14_2;
  int sec_r000424_15_1;
  int sec_r000424_15_2;
  int sec_r000424_16_1;
  int sec_r000424_16_2;
  int sec_r000424_17_1;
  int sec_r000424_17_2;
  int sec_r000424_18_1;
  int sec_r000424_18_2;
  int sec_r000424_19_1;
  int sec_r000424_19_2;
  int sec_r000424_20_1;
  int sec_r000424_20_2;
  int pub_r000424_0_1;
  int pub_r000424_0_2;
  int pub_r000424_1_1;
  int pub_r000424_1_2;
  int pub_r000424_2_1;
  int pub_r000424_2_2;
  int pub_r000424_3_1;
  int pub_r000424_3_2;
  int pub_r000424_4_1;
  int pub_r000424_4_2;
  int pub_r000424_5_1;
  int pub_r000424_5_2;
  int pub_r000424_6_1;
  int pub_r000424_6_2;
  int pub_r000424_7_1;
  int pub_r000424_7_2;
  int pub_r000424_8_1;
  int pub_r000424_8_2;
  int pub_r000424_9_1;
  int pub_r000424_9_2;
  int pub_r000424_10_1;
  int pub_r000424_10_2;
  int pub_r000424_11_1;
  int pub_r000424_11_2;
  int pub_r000424_12_1;
  int pub_r000424_12_2;
  int pub_r000424_13_1;
  int pub_r000424_13_2;
  int pub_r000424_14_1;
  int pub_r000424_14_2;
  int pub_r000424_15_1;
  int pub_r000424_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000424_0_1 >= (-100)) && (pub_r000424_0_1 <= 100));
  __CPROVER_assume((pub_r000424_0_2 >= (-100)) && (pub_r000424_0_2 <= 100));
  __CPROVER_assume((pub_r000424_1_1 >= (-100)) && (pub_r000424_1_1 <= 100));
  __CPROVER_assume((pub_r000424_1_2 >= (-100)) && (pub_r000424_1_2 <= 100));
  __CPROVER_assume((pub_r000424_2_1 >= (-100)) && (pub_r000424_2_1 <= 100));
  __CPROVER_assume((pub_r000424_2_2 >= (-100)) && (pub_r000424_2_2 <= 100));
  __CPROVER_assume((pub_r000424_3_1 >= (-100)) && (pub_r000424_3_1 <= 100));
  __CPROVER_assume((pub_r000424_3_2 >= (-100)) && (pub_r000424_3_2 <= 100));
  __CPROVER_assume((pub_r000424_4_1 >= (-100)) && (pub_r000424_4_1 <= 100));
  __CPROVER_assume((pub_r000424_4_2 >= (-100)) && (pub_r000424_4_2 <= 100));
  __CPROVER_assume((pub_r000424_5_1 >= (-100)) && (pub_r000424_5_1 <= 100));
  __CPROVER_assume((pub_r000424_5_2 >= (-100)) && (pub_r000424_5_2 <= 100));
  __CPROVER_assume((pub_r000424_6_1 >= (-100)) && (pub_r000424_6_1 <= 100));
  __CPROVER_assume((pub_r000424_6_2 >= (-100)) && (pub_r000424_6_2 <= 100));
  __CPROVER_assume((pub_r000424_7_1 >= (-100)) && (pub_r000424_7_1 <= 100));
  __CPROVER_assume((pub_r000424_7_2 >= (-100)) && (pub_r000424_7_2 <= 100));
  __CPROVER_assume((pub_r000424_8_1 >= (-100)) && (pub_r000424_8_1 <= 100));
  __CPROVER_assume((pub_r000424_8_2 >= (-100)) && (pub_r000424_8_2 <= 100));
  __CPROVER_assume((pub_r000424_9_1 >= (-100)) && (pub_r000424_9_1 <= 100));
  __CPROVER_assume((pub_r000424_9_2 >= (-100)) && (pub_r000424_9_2 <= 100));
  __CPROVER_assume((pub_r000424_10_1 >= (-100)) && (pub_r000424_10_1 <= 100));
  __CPROVER_assume((pub_r000424_10_2 >= (-100)) && (pub_r000424_10_2 <= 100));
  __CPROVER_assume((pub_r000424_11_1 >= (-100)) && (pub_r000424_11_1 <= 100));
  __CPROVER_assume((pub_r000424_11_2 >= (-100)) && (pub_r000424_11_2 <= 100));
  __CPROVER_assume((pub_r000424_12_1 >= (-100)) && (pub_r000424_12_1 <= 100));
  __CPROVER_assume((pub_r000424_12_2 >= (-100)) && (pub_r000424_12_2 <= 100));
  __CPROVER_assume((pub_r000424_13_1 >= (-100)) && (pub_r000424_13_1 <= 100));
  __CPROVER_assume((pub_r000424_13_2 >= (-100)) && (pub_r000424_13_2 <= 100));
  __CPROVER_assume((pub_r000424_14_1 >= (-100)) && (pub_r000424_14_1 <= 100));
  __CPROVER_assume((pub_r000424_14_2 >= (-100)) && (pub_r000424_14_2 <= 100));
  __CPROVER_assume((pub_r000424_15_1 >= (-100)) && (pub_r000424_15_1 <= 100));
  __CPROVER_assume((pub_r000424_15_2 >= (-100)) && (pub_r000424_15_2 <= 100));
  __CPROVER_assume((sec_r000424_0_1 >= 0) && (sec_r000424_0_1 <= 255));
  __CPROVER_assume((sec_r000424_0_2 >= 0) && (sec_r000424_0_2 <= 255));
  __CPROVER_assume((sec_r000424_1_1 >= 0) && (sec_r000424_1_1 <= 255));
  __CPROVER_assume((sec_r000424_1_2 >= 0) && (sec_r000424_1_2 <= 255));
  __CPROVER_assume((sec_r000424_2_1 >= 0) && (sec_r000424_2_1 <= 255));
  __CPROVER_assume((sec_r000424_2_2 >= 0) && (sec_r000424_2_2 <= 255));
  __CPROVER_assume((sec_r000424_3_1 >= 0) && (sec_r000424_3_1 <= 255));
  __CPROVER_assume((sec_r000424_3_2 >= 0) && (sec_r000424_3_2 <= 255));
  __CPROVER_assume((sec_r000424_4_1 >= 0) && (sec_r000424_4_1 <= 255));
  __CPROVER_assume((sec_r000424_4_2 >= 0) && (sec_r000424_4_2 <= 255));
  __CPROVER_assume((sec_r000424_5_1 >= 0) && (sec_r000424_5_1 <= 255));
  __CPROVER_assume((sec_r000424_5_2 >= 0) && (sec_r000424_5_2 <= 255));
  __CPROVER_assume((sec_r000424_6_1 >= 0) && (sec_r000424_6_1 <= 255));
  __CPROVER_assume((sec_r000424_6_2 >= 0) && (sec_r000424_6_2 <= 255));
  __CPROVER_assume((sec_r000424_7_1 >= 0) && (sec_r000424_7_1 <= 255));
  __CPROVER_assume((sec_r000424_7_2 >= 0) && (sec_r000424_7_2 <= 255));
  __CPROVER_assume((sec_r000424_8_1 >= 0) && (sec_r000424_8_1 <= 255));
  __CPROVER_assume((sec_r000424_8_2 >= 0) && (sec_r000424_8_2 <= 255));
  __CPROVER_assume((sec_r000424_9_1 >= 0) && (sec_r000424_9_1 <= 255));
  __CPROVER_assume((sec_r000424_9_2 >= 0) && (sec_r000424_9_2 <= 255));
  __CPROVER_assume((sec_r000424_10_1 >= 0) && (sec_r000424_10_1 <= 255));
  __CPROVER_assume((sec_r000424_10_2 >= 0) && (sec_r000424_10_2 <= 255));
  __CPROVER_assume((sec_r000424_11_1 >= 0) && (sec_r000424_11_1 <= 255));
  __CPROVER_assume((sec_r000424_11_2 >= 0) && (sec_r000424_11_2 <= 255));
  __CPROVER_assume((sec_r000424_12_1 >= 0) && (sec_r000424_12_1 <= 255));
  __CPROVER_assume((sec_r000424_12_2 >= 0) && (sec_r000424_12_2 <= 255));
  __CPROVER_assume((sec_r000424_13_1 >= 0) && (sec_r000424_13_1 <= 255));
  __CPROVER_assume((sec_r000424_13_2 >= 0) && (sec_r000424_13_2 <= 255));
  __CPROVER_assume((sec_r000424_14_1 >= 0) && (sec_r000424_14_1 <= 255));
  __CPROVER_assume((sec_r000424_14_2 >= 0) && (sec_r000424_14_2 <= 255));
  __CPROVER_assume((sec_r000424_15_1 >= 0) && (sec_r000424_15_1 <= 255));
  __CPROVER_assume((sec_r000424_15_2 >= 0) && (sec_r000424_15_2 <= 255));
  __CPROVER_assume((sec_r000424_16_1 >= 0) && (sec_r000424_16_1 <= 255));
  __CPROVER_assume((sec_r000424_16_2 >= 0) && (sec_r000424_16_2 <= 255));
  __CPROVER_assume((sec_r000424_17_1 >= 0) && (sec_r000424_17_1 <= 255));
  __CPROVER_assume((sec_r000424_17_2 >= 0) && (sec_r000424_17_2 <= 255));
  __CPROVER_assume((sec_r000424_18_1 >= 0) && (sec_r000424_18_1 <= 255));
  __CPROVER_assume((sec_r000424_18_2 >= 0) && (sec_r000424_18_2 <= 255));
  __CPROVER_assume((sec_r000424_19_1 >= 0) && (sec_r000424_19_1 <= 255));
  __CPROVER_assume((sec_r000424_19_2 >= 0) && (sec_r000424_19_2 <= 255));
  __CPROVER_assume((sec_r000424_20_1 >= 0) && (sec_r000424_20_1 <= 255));
  __CPROVER_assume((sec_r000424_20_2 >= 0) && (sec_r000424_20_2 <= 255));
  struct DeviceConfig_R000424_2413_0 st_var_0_1 = {0};
  struct DeviceConfig_R000424_2413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000424_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000424_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000424_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000424_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000424_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000424_0_2 + 7) & 15;
  struct EventLog_R000424_2413_1 st_var_1_1 = {0};
  struct EventLog_R000424_2413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000424_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000424_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000424_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000424_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000424_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000424_0_2 + 9) & 15;
  union RegisterBank_R000424_2413_0 u_var_1;
  union RegisterBank_R000424_2413_0 u_var_2;
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
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_4_1 = (st_var_0_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_0_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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

  int stage_v_5_1 = ((st_var_1_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_1_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 29)
    {
      chk_sum_1 ^= stage_v_5_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_5_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 29)
    {
      chk_sum_2 ^= stage_v_5_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = (st_var_0_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_0_2.buffer[0] ^ 13) & 3;
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

  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = ((st_var_0_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_0_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 33)
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
  if (stage_v_20_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 33)
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
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  int stage_v_22_1 = ((st_var_0_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_0_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 30)
    {
      chk_sum_1 ^= stage_v_22_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_22_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 30)
    {
      chk_sum_2 ^= stage_v_22_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 24) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 37)
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
  if (stage_v_25_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 37)
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
  int stage_v_26_1 = ((st_var_0_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_0_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 50)
    {
      chk_sum_1 ^= stage_v_26_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_26_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 50)
    {
      chk_sum_2 ^= stage_v_26_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 41)
    {
      chk_sum_1 ^= stage_v_29_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_29_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 41)
    {
      chk_sum_2 ^= stage_v_29_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_31_1 = ((st_var_1_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_1_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 40)
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
  if (stage_v_31_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 40)
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
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (st_var_1_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_1_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_35_1 = (st_var_1_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_1_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 45)
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
  if (stage_v_36_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 45)
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
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 38)
    {
      chk_sum_1 ^= stage_v_37_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_37_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 38)
    {
      chk_sum_2 ^= stage_v_37_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_38_1 = ((st_var_0_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_0_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 55)
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
  if (stage_v_38_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 55)
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
  int stage_v_39_1 = (st_var_1_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_1_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 41)
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
  if (stage_v_41_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 41)
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
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((((sec_r000424_10_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_3_1) + 12) & 127;
  int stage_v_45_2 = ((((sec_r000424_10_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_45_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_45_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((((sec_r000424_20_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_15_1) + 21) & 127;
  int stage_v_46_2 = ((((sec_r000424_20_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_46_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_46_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((((stage_v_45_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_1_1) + 32) & 127;
  int stage_v_47_2 = ((((stage_v_45_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_47_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_47_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((((stage_v_45_1 * 3) + (sec_r000424_3_1 * 2)) - pub_r000424_7_1) + 27) & 127;
  int stage_v_48_2 = ((((stage_v_45_2 * 3) + (sec_r000424_3_2 * 2)) - pub_r000424_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_48_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_48_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((((stage_v_46_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_2_1) + 9) & 127;
  int stage_v_49_2 = ((((stage_v_46_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_49_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_49_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((((sec_r000424_8_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_1_1) + 31) & 127;
  int stage_v_50_2 = ((((sec_r000424_8_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_50_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_50_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((((stage_v_48_1 * 3) + (sec_r000424_15_1 * 2)) - pub_r000424_7_1) + 7) & 127;
  int stage_v_51_2 = ((((stage_v_48_2 * 3) + (sec_r000424_15_2 * 2)) - pub_r000424_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_51_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_51_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((((stage_v_47_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_5_1) + 14) & 127;
  int stage_v_52_2 = ((((stage_v_47_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_52_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_52_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((((sec_r000424_10_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_8_1) + 13) & 127;
  int stage_v_53_2 = ((((sec_r000424_10_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_53_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_53_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((((stage_v_47_1 * 3) + (sec_r000424_19_1 * 2)) - pub_r000424_10_1) + 9) & 127;
  int stage_v_54_2 = ((((stage_v_47_2 * 3) + (sec_r000424_19_2 * 2)) - pub_r000424_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_54_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_54_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((((stage_v_54_1 * 3) + (sec_r000424_11_1 * 2)) - pub_r000424_13_1) + 28) & 127;
  int stage_v_55_2 = ((((stage_v_54_2 * 3) + (sec_r000424_11_2 * 2)) - pub_r000424_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_55_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_55_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((((stage_v_49_1 * 3) + (sec_r000424_19_1 * 2)) - pub_r000424_10_1) + 20) & 127;
  int stage_v_56_2 = ((((stage_v_49_2 * 3) + (sec_r000424_19_2 * 2)) - pub_r000424_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_56_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_56_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((((stage_v_52_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_2_1) + 15) & 127;
  int stage_v_57_2 = ((((stage_v_52_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_57_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_57_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((((stage_v_48_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_2_1) + 37) & 127;
  int stage_v_58_2 = ((((stage_v_48_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_58_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_58_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((((stage_v_56_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_13_1) + 17) & 127;
  int stage_v_59_2 = ((((stage_v_56_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_59_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_59_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((((stage_v_57_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_2_1) + 23) & 127;
  int stage_v_60_2 = ((((stage_v_57_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((((sec_r000424_18_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_10_1) + 27) & 127;
  int stage_v_61_2 = ((((sec_r000424_18_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((((stage_v_56_1 * 3) + (sec_r000424_9_1 * 2)) - pub_r000424_12_1) + 14) & 127;
  int stage_v_62_2 = ((((stage_v_56_2 * 3) + (sec_r000424_9_2 * 2)) - pub_r000424_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_62_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_62_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((((stage_v_48_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_10_1) + 33) & 127;
  int stage_v_63_2 = ((((stage_v_48_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_63_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_63_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((((sec_r000424_12_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_5_1) + 13) & 127;
  int stage_v_64_2 = ((((sec_r000424_12_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_64_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_64_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((((sec_r000424_0_1 * 3) + (sec_r000424_0_1 * 2)) - pub_r000424_12_1) + 26) & 127;
  int stage_v_65_2 = ((((sec_r000424_0_2 * 3) + (sec_r000424_0_2 * 2)) - pub_r000424_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_65_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_65_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((((stage_v_51_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_9_1) + 14) & 127;
  int stage_v_66_2 = ((((stage_v_51_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_66_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_66_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((((stage_v_62_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_4_1) + 31) & 127;
  int stage_v_67_2 = ((((stage_v_62_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_67_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_67_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((((stage_v_62_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_11_1) + 28) & 127;
  int stage_v_68_2 = ((((stage_v_62_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((((stage_v_65_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_2_1) + 8) & 127;
  int stage_v_69_2 = ((((stage_v_65_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((((stage_v_64_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_13_1) + 32) & 127;
  int stage_v_70_2 = ((((stage_v_64_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((((stage_v_69_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_11_1) + 32) & 127;
  int stage_v_71_2 = ((((stage_v_69_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((((stage_v_54_1 * 3) + (sec_r000424_3_1 * 2)) - pub_r000424_7_1) + 7) & 127;
  int stage_v_72_2 = ((((stage_v_54_2 * 3) + (sec_r000424_3_2 * 2)) - pub_r000424_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((((stage_v_48_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_7_1) + 6) & 127;
  int stage_v_73_2 = ((((stage_v_48_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((((stage_v_52_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_14_1) + 15) & 127;
  int stage_v_74_2 = ((((stage_v_52_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((((stage_v_52_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_0_1) + 22) & 127;
  int stage_v_75_2 = ((((stage_v_52_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((((stage_v_65_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_4_1) + 29) & 127;
  int stage_v_76_2 = ((((stage_v_65_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((((stage_v_73_1 * 3) + (sec_r000424_5_1 * 2)) - pub_r000424_12_1) + 7) & 127;
  int stage_v_77_2 = ((((stage_v_73_2 * 3) + (sec_r000424_5_2 * 2)) - pub_r000424_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((((sec_r000424_7_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_10_1) + 18) & 127;
  int stage_v_78_2 = ((((sec_r000424_7_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((((stage_v_54_1 * 3) + (sec_r000424_3_1 * 2)) - pub_r000424_8_1) + 8) & 127;
  int stage_v_79_2 = ((((stage_v_54_2 * 3) + (sec_r000424_3_2 * 2)) - pub_r000424_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((((stage_v_73_1 * 3) + (sec_r000424_3_1 * 2)) - pub_r000424_3_1) + 16) & 127;
  int stage_v_80_2 = ((((stage_v_73_2 * 3) + (sec_r000424_3_2 * 2)) - pub_r000424_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((((sec_r000424_17_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_15_1) + 13) & 127;
  int stage_v_81_2 = ((((sec_r000424_17_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_15_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((((sec_r000424_18_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_8_1) + 26) & 127;
  int stage_v_82_2 = ((((sec_r000424_18_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((((stage_v_45_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_0_1) + 10) & 127;
  int stage_v_83_2 = ((((stage_v_45_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((((sec_r000424_5_1 * 3) + (sec_r000424_5_1 * 2)) - pub_r000424_14_1) + 3) & 127;
  int stage_v_84_2 = ((((sec_r000424_5_2 * 3) + (sec_r000424_5_2 * 2)) - pub_r000424_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((((sec_r000424_17_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_9_1) + 16) & 127;
  int stage_v_85_2 = ((((sec_r000424_17_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((((stage_v_80_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_11_1) + 20) & 127;
  int stage_v_86_2 = ((((stage_v_80_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((((stage_v_67_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_0_1) + 28) & 127;
  int stage_v_87_2 = ((((stage_v_67_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_0_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((((stage_v_52_1 * 3) + (sec_r000424_15_1 * 2)) - pub_r000424_2_1) + 29) & 127;
  int stage_v_88_2 = ((((stage_v_52_2 * 3) + (sec_r000424_15_2 * 2)) - pub_r000424_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((((sec_r000424_1_1 * 3) + (sec_r000424_1_1 * 2)) - pub_r000424_0_1) + 14) & 127;
  int stage_v_89_2 = ((((sec_r000424_1_2 * 3) + (sec_r000424_1_2 * 2)) - pub_r000424_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((((stage_v_79_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_11_1) + 14) & 127;
  int stage_v_90_2 = ((((stage_v_79_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((((stage_v_83_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_0_1) + 20) & 127;
  int stage_v_91_2 = ((((stage_v_83_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((((stage_v_70_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_7_1) + 26) & 127;
  int stage_v_92_2 = ((((stage_v_70_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((((stage_v_48_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_0_1) + 17) & 127;
  int stage_v_93_2 = ((((stage_v_48_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((((stage_v_45_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_0_1) + 11) & 127;
  int stage_v_94_2 = ((((stage_v_45_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((((sec_r000424_9_1 * 3) + (sec_r000424_9_1 * 2)) - pub_r000424_7_1) + 23) & 127;
  int stage_v_95_2 = ((((sec_r000424_9_2 * 3) + (sec_r000424_9_2 * 2)) - pub_r000424_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((((sec_r000424_4_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_4_1) + 36) & 127;
  int stage_v_96_2 = ((((sec_r000424_4_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((((stage_v_88_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_1_1) + 22) & 127;
  int stage_v_97_2 = ((((stage_v_88_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((((sec_r000424_14_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_12_1) + 37) & 127;
  int stage_v_98_2 = ((((sec_r000424_14_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((((stage_v_48_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_7_1) + 37) & 127;
  int stage_v_99_2 = ((((stage_v_48_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_7_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((((stage_v_93_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_13_1) + 34) & 127;
  int stage_v_100_2 = ((((stage_v_93_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((((stage_v_51_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_4_1) + 6) & 127;
  int stage_v_101_2 = ((((stage_v_51_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((((stage_v_64_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_5_1) + 24) & 127;
  int stage_v_102_2 = ((((stage_v_64_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((((sec_r000424_14_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_9_1) + 36) & 127;
  int stage_v_103_2 = ((((sec_r000424_14_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((((stage_v_82_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_11_1) + 6) & 127;
  int stage_v_104_2 = ((((stage_v_82_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((((stage_v_100_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_12_1) + 30) & 127;
  int stage_v_105_2 = ((((stage_v_100_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((((stage_v_97_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_5_1) + 29) & 127;
  int stage_v_106_2 = ((((stage_v_97_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((((stage_v_101_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_3_1) + 35) & 127;
  int stage_v_107_2 = ((((stage_v_101_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((((sec_r000424_13_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_2_1) + 37) & 127;
  int stage_v_108_2 = ((((sec_r000424_13_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((((stage_v_50_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_3_1) + 17) & 127;
  int stage_v_109_2 = ((((stage_v_50_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((((stage_v_92_1 * 3) + (sec_r000424_1_1 * 2)) - pub_r000424_1_1) + 21) & 127;
  int stage_v_110_2 = ((((stage_v_92_2 * 3) + (sec_r000424_1_2 * 2)) - pub_r000424_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((((sec_r000424_16_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_0_1) + 26) & 127;
  int stage_v_111_2 = ((((sec_r000424_16_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((((stage_v_100_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_0_1) + 4) & 127;
  int stage_v_112_2 = ((((stage_v_100_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((((stage_v_71_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_4_1) + 33) & 127;
  int stage_v_113_2 = ((((stage_v_71_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((((sec_r000424_12_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_3_1) + 25) & 127;
  int stage_v_114_2 = ((((sec_r000424_12_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((((sec_r000424_13_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_12_1) + 10) & 127;
  int stage_v_115_2 = ((((sec_r000424_13_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((((sec_r000424_18_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_14_1) + 26) & 127;
  int stage_v_116_2 = ((((sec_r000424_18_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((((sec_r000424_20_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_8_1) + 21) & 127;
  int stage_v_117_2 = ((((sec_r000424_20_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((((stage_v_52_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_6_1) + 19) & 127;
  int stage_v_118_2 = ((((stage_v_52_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((((stage_v_54_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_1_1) + 32) & 127;
  int stage_v_119_2 = ((((stage_v_54_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((((stage_v_64_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_6_1) + 32) & 127;
  int stage_v_120_2 = ((((stage_v_64_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((((stage_v_53_1 * 3) + (sec_r000424_3_1 * 2)) - pub_r000424_0_1) + 16) & 127;
  int stage_v_121_2 = ((((stage_v_53_2 * 3) + (sec_r000424_3_2 * 2)) - pub_r000424_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((((stage_v_105_1 * 3) + (sec_r000424_1_1 * 2)) - pub_r000424_5_1) + 15) & 127;
  int stage_v_122_2 = ((((stage_v_105_2 * 3) + (sec_r000424_1_2 * 2)) - pub_r000424_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((((sec_r000424_2_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_8_1) + 6) & 127;
  int stage_v_123_2 = ((((sec_r000424_2_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((((sec_r000424_14_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_15_1) + 34) & 127;
  int stage_v_124_2 = ((((sec_r000424_14_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((((stage_v_55_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_11_1) + 20) & 127;
  int stage_v_125_2 = ((((stage_v_55_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((((stage_v_110_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_13_1) + 14) & 127;
  int stage_v_126_2 = ((((stage_v_110_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((((stage_v_80_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_10_1) + 5) & 127;
  int stage_v_127_2 = ((((stage_v_80_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((((stage_v_61_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_12_1) + 27) & 127;
  int stage_v_128_2 = ((((stage_v_61_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((((stage_v_105_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_5_1) + 21) & 127;
  int stage_v_129_2 = ((((stage_v_105_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((((sec_r000424_6_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_12_1) + 19) & 127;
  int stage_v_130_2 = ((((sec_r000424_6_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((((stage_v_76_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_9_1) + 10) & 127;
  int stage_v_131_2 = ((((stage_v_76_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((((stage_v_99_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_6_1) + 12) & 127;
  int stage_v_132_2 = ((((stage_v_99_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((((stage_v_85_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_4_1) + 22) & 127;
  int stage_v_133_2 = ((((stage_v_85_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((((stage_v_106_1 * 3) + (sec_r000424_1_1 * 2)) - pub_r000424_4_1) + 7) & 127;
  int stage_v_134_2 = ((((stage_v_106_2 * 3) + (sec_r000424_1_2 * 2)) - pub_r000424_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((((stage_v_55_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_2_1) + 13) & 127;
  int stage_v_135_2 = ((((stage_v_55_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((((sec_r000424_6_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_11_1) + 24) & 127;
  int stage_v_136_2 = ((((sec_r000424_6_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((((stage_v_118_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_5_1) + 32) & 127;
  int stage_v_137_2 = ((((stage_v_118_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((((stage_v_84_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_14_1) + 17) & 127;
  int stage_v_138_2 = ((((stage_v_84_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((((stage_v_63_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_15_1) + 9) & 127;
  int stage_v_139_2 = ((((stage_v_63_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((((stage_v_61_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_10_1) + 18) & 127;
  int stage_v_140_2 = ((((stage_v_61_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((((sec_r000424_3_1 * 3) + (sec_r000424_3_1 * 2)) - pub_r000424_4_1) + 29) & 127;
  int stage_v_141_2 = ((((sec_r000424_3_2 * 3) + (sec_r000424_3_2 * 2)) - pub_r000424_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((((stage_v_67_1 * 3) + (sec_r000424_0_1 * 2)) - pub_r000424_1_1) + 8) & 127;
  int stage_v_142_2 = ((((stage_v_67_2 * 3) + (sec_r000424_0_2 * 2)) - pub_r000424_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((((stage_v_113_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_6_1) + 22) & 127;
  int stage_v_143_2 = ((((stage_v_113_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((((stage_v_57_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_0_1) + 26) & 127;
  int stage_v_144_2 = ((((stage_v_57_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((((stage_v_126_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_7_1) + 13) & 127;
  int stage_v_145_2 = ((((stage_v_126_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((((stage_v_104_1 * 3) + (sec_r000424_1_1 * 2)) - pub_r000424_7_1) + 30) & 127;
  int stage_v_146_2 = ((((stage_v_104_2 * 3) + (sec_r000424_1_2 * 2)) - pub_r000424_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((((sec_r000424_4_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_11_1) + 26) & 127;
  int stage_v_147_2 = ((((sec_r000424_4_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((((stage_v_147_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_1_1) + 9) & 127;
  int stage_v_148_2 = ((((stage_v_147_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((((stage_v_102_1 * 3) + (sec_r000424_3_1 * 2)) - pub_r000424_2_1) + 22) & 127;
  int stage_v_149_2 = ((((stage_v_102_2 * 3) + (sec_r000424_3_2 * 2)) - pub_r000424_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((((stage_v_82_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_10_1) + 9) & 127;
  int stage_v_150_2 = ((((stage_v_82_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((((stage_v_141_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_12_1) + 8) & 127;
  int stage_v_151_2 = ((((stage_v_141_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((((sec_r000424_9_1 * 3) + (sec_r000424_9_1 * 2)) - pub_r000424_7_1) + 16) & 127;
  int stage_v_152_2 = ((((sec_r000424_9_2 * 3) + (sec_r000424_9_2 * 2)) - pub_r000424_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((((sec_r000424_8_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_8_1) + 13) & 127;
  int stage_v_153_2 = ((((sec_r000424_8_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((((stage_v_136_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_14_1) + 24) & 127;
  int stage_v_154_2 = ((((stage_v_136_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((((stage_v_108_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_13_1) + 9) & 127;
  int stage_v_155_2 = ((((stage_v_108_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((((stage_v_116_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_8_1) + 18) & 127;
  int stage_v_156_2 = ((((stage_v_116_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((((stage_v_98_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_4_1) + 12) & 127;
  int stage_v_157_2 = ((((stage_v_98_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((((sec_r000424_13_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_7_1) + 29) & 127;
  int stage_v_158_2 = ((((sec_r000424_13_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((((stage_v_106_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_4_1) + 6) & 127;
  int stage_v_159_2 = ((((stage_v_106_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((((stage_v_68_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_15_1) + 4) & 127;
  int stage_v_160_2 = ((((stage_v_68_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((((stage_v_69_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_14_1) + 21) & 127;
  int stage_v_161_2 = ((((stage_v_69_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((((sec_r000424_16_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_1_1) + 33) & 127;
  int stage_v_162_2 = ((((sec_r000424_16_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((((sec_r000424_13_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_6_1) + 34) & 127;
  int stage_v_163_2 = ((((sec_r000424_13_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((((stage_v_92_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_0_1) + 30) & 127;
  int stage_v_164_2 = ((((stage_v_92_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((((stage_v_64_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_5_1) + 31) & 127;
  int stage_v_165_2 = ((((stage_v_64_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((((sec_r000424_17_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_3_1) + 22) & 127;
  int stage_v_166_2 = ((((sec_r000424_17_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((((stage_v_116_1 * 3) + (sec_r000424_19_1 * 2)) - pub_r000424_13_1) + 28) & 127;
  int stage_v_167_2 = ((((stage_v_116_2 * 3) + (sec_r000424_19_2 * 2)) - pub_r000424_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((((stage_v_94_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_1_1) + 18) & 127;
  int stage_v_168_2 = ((((stage_v_94_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((((stage_v_120_1 * 3) + (sec_r000424_11_1 * 2)) - pub_r000424_5_1) + 34) & 127;
  int stage_v_169_2 = ((((stage_v_120_2 * 3) + (sec_r000424_11_2 * 2)) - pub_r000424_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((((stage_v_106_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_2_1) + 7) & 127;
  int stage_v_170_2 = ((((stage_v_106_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((((stage_v_96_1 * 3) + (sec_r000424_15_1 * 2)) - pub_r000424_3_1) + 29) & 127;
  int stage_v_171_2 = ((((stage_v_96_2 * 3) + (sec_r000424_15_2 * 2)) - pub_r000424_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((((sec_r000424_5_1 * 3) + (sec_r000424_5_1 * 2)) - pub_r000424_8_1) + 26) & 127;
  int stage_v_172_2 = ((((sec_r000424_5_2 * 3) + (sec_r000424_5_2 * 2)) - pub_r000424_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((((stage_v_56_1 * 3) + (sec_r000424_19_1 * 2)) - pub_r000424_3_1) + 33) & 127;
  int stage_v_173_2 = ((((stage_v_56_2 * 3) + (sec_r000424_19_2 * 2)) - pub_r000424_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((((stage_v_66_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_10_1) + 12) & 127;
  int stage_v_174_2 = ((((stage_v_66_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((((sec_r000424_1_1 * 3) + (sec_r000424_1_1 * 2)) - pub_r000424_7_1) + 8) & 127;
  int stage_v_175_2 = ((((sec_r000424_1_2 * 3) + (sec_r000424_1_2 * 2)) - pub_r000424_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((((sec_r000424_16_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_13_1) + 4) & 127;
  int stage_v_176_2 = ((((sec_r000424_16_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((((sec_r000424_13_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_4_1) + 3) & 127;
  int stage_v_177_2 = ((((sec_r000424_13_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((((sec_r000424_13_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_8_1) + 19) & 127;
  int stage_v_178_2 = ((((sec_r000424_13_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((((stage_v_170_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_7_1) + 4) & 127;
  int stage_v_179_2 = ((((stage_v_170_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((((stage_v_118_1 * 3) + (sec_r000424_9_1 * 2)) - pub_r000424_4_1) + 7) & 127;
  int stage_v_180_2 = ((((stage_v_118_2 * 3) + (sec_r000424_9_2 * 2)) - pub_r000424_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((((stage_v_114_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_2_1) + 18) & 127;
  int stage_v_181_2 = ((((stage_v_114_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((((stage_v_103_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_14_1) + 15) & 127;
  int stage_v_182_2 = ((((stage_v_103_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((((stage_v_171_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_2_1) + 37) & 127;
  int stage_v_183_2 = ((((stage_v_171_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((((stage_v_54_1 * 3) + (sec_r000424_19_1 * 2)) - pub_r000424_15_1) + 20) & 127;
  int stage_v_184_2 = ((((stage_v_54_2 * 3) + (sec_r000424_19_2 * 2)) - pub_r000424_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((((sec_r000424_1_1 * 3) + (sec_r000424_1_1 * 2)) - pub_r000424_8_1) + 35) & 127;
  int stage_v_185_2 = ((((sec_r000424_1_2 * 3) + (sec_r000424_1_2 * 2)) - pub_r000424_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((((sec_r000424_18_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_12_1) + 21) & 127;
  int stage_v_186_2 = ((((sec_r000424_18_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((((stage_v_48_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_13_1) + 23) & 127;
  int stage_v_187_2 = ((((stage_v_48_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((((stage_v_147_1 * 3) + (sec_r000424_11_1 * 2)) - pub_r000424_1_1) + 14) & 127;
  int stage_v_188_2 = ((((stage_v_147_2 * 3) + (sec_r000424_11_2 * 2)) - pub_r000424_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((((stage_v_141_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_8_1) + 11) & 127;
  int stage_v_189_2 = ((((stage_v_141_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((((sec_r000424_12_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_6_1) + 20) & 127;
  int stage_v_190_2 = ((((sec_r000424_12_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((((sec_r000424_14_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_0_1) + 24) & 127;
  int stage_v_191_2 = ((((sec_r000424_14_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((((stage_v_135_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_14_1) + 9) & 127;
  int stage_v_192_2 = ((((stage_v_135_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((((stage_v_70_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_2_1) + 36) & 127;
  int stage_v_193_2 = ((((stage_v_70_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((((stage_v_120_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_13_1) + 10) & 127;
  int stage_v_194_2 = ((((stage_v_120_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((((stage_v_90_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_0_1) + 28) & 127;
  int stage_v_195_2 = ((((stage_v_90_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_0_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((((stage_v_131_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_5_1) + 31) & 127;
  int stage_v_196_2 = ((((stage_v_131_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((((sec_r000424_9_1 * 3) + (sec_r000424_9_1 * 2)) - pub_r000424_8_1) + 19) & 127;
  int stage_v_197_2 = ((((sec_r000424_9_2 * 3) + (sec_r000424_9_2 * 2)) - pub_r000424_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((((stage_v_67_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_5_1) + 5) & 127;
  int stage_v_198_2 = ((((stage_v_67_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((((stage_v_49_1 * 3) + (sec_r000424_5_1 * 2)) - pub_r000424_13_1) + 34) & 127;
  int stage_v_199_2 = ((((stage_v_49_2 * 3) + (sec_r000424_5_2 * 2)) - pub_r000424_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((((stage_v_108_1 * 3) + (sec_r000424_19_1 * 2)) - pub_r000424_1_1) + 14) & 127;
  int stage_v_200_2 = ((((stage_v_108_2 * 3) + (sec_r000424_19_2 * 2)) - pub_r000424_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((((stage_v_117_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_13_1) + 11) & 127;
  int stage_v_201_2 = ((((stage_v_117_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((((stage_v_62_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_6_1) + 3) & 127;
  int stage_v_202_2 = ((((stage_v_62_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((((sec_r000424_15_1 * 3) + (sec_r000424_15_1 * 2)) - pub_r000424_3_1) + 24) & 127;
  int stage_v_203_2 = ((((sec_r000424_15_2 * 3) + (sec_r000424_15_2 * 2)) - pub_r000424_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((((stage_v_174_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_10_1) + 10) & 127;
  int stage_v_204_2 = ((((stage_v_174_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((((stage_v_188_1 * 3) + (sec_r000424_5_1 * 2)) - pub_r000424_6_1) + 21) & 127;
  int stage_v_205_2 = ((((stage_v_188_2 * 3) + (sec_r000424_5_2 * 2)) - pub_r000424_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((((sec_r000424_14_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_6_1) + 5) & 127;
  int stage_v_206_2 = ((((sec_r000424_14_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((((stage_v_82_1 * 3) + (sec_r000424_0_1 * 2)) - pub_r000424_14_1) + 29) & 127;
  int stage_v_207_2 = ((((stage_v_82_2 * 3) + (sec_r000424_0_2 * 2)) - pub_r000424_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((((sec_r000424_0_1 * 3) + (sec_r000424_0_1 * 2)) - pub_r000424_4_1) + 4) & 127;
  int stage_v_208_2 = ((((sec_r000424_0_2 * 3) + (sec_r000424_0_2 * 2)) - pub_r000424_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((((stage_v_173_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_4_1) + 28) & 127;
  int stage_v_209_2 = ((((stage_v_173_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((((sec_r000424_13_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_6_1) + 24) & 127;
  int stage_v_210_2 = ((((sec_r000424_13_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((((stage_v_76_1 * 3) + (sec_r000424_11_1 * 2)) - pub_r000424_4_1) + 14) & 127;
  int stage_v_211_2 = ((((stage_v_76_2 * 3) + (sec_r000424_11_2 * 2)) - pub_r000424_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((((stage_v_133_1 * 3) + (sec_r000424_0_1 * 2)) - pub_r000424_7_1) + 29) & 127;
  int stage_v_212_2 = ((((stage_v_133_2 * 3) + (sec_r000424_0_2 * 2)) - pub_r000424_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((((stage_v_212_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_1_1) + 10) & 127;
  int stage_v_213_2 = ((((stage_v_212_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_213_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_213_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((((sec_r000424_14_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_4_1) + 28) & 127;
  int stage_v_214_2 = ((((sec_r000424_14_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((((sec_r000424_1_1 * 3) + (sec_r000424_1_1 * 2)) - pub_r000424_2_1) + 19) & 127;
  int stage_v_215_2 = ((((sec_r000424_1_2 * 3) + (sec_r000424_1_2 * 2)) - pub_r000424_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_215_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_215_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((((stage_v_185_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_3_1) + 33) & 127;
  int stage_v_216_2 = ((((stage_v_185_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_216_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_216_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((((stage_v_163_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_6_1) + 30) & 127;
  int stage_v_217_2 = ((((stage_v_163_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_217_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_217_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((((stage_v_141_1 * 3) + (sec_r000424_9_1 * 2)) - pub_r000424_2_1) + 21) & 127;
  int stage_v_218_2 = ((((stage_v_141_2 * 3) + (sec_r000424_9_2 * 2)) - pub_r000424_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_218_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_218_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((((stage_v_102_1 * 3) + (sec_r000424_15_1 * 2)) - pub_r000424_9_1) + 6) & 127;
  int stage_v_219_2 = ((((stage_v_102_2 * 3) + (sec_r000424_15_2 * 2)) - pub_r000424_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_219_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_219_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((((stage_v_117_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_14_1) + 32) & 127;
  int stage_v_220_2 = ((((stage_v_117_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_220_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_220_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((((stage_v_133_1 * 3) + (sec_r000424_3_1 * 2)) - pub_r000424_4_1) + 13) & 127;
  int stage_v_221_2 = ((((stage_v_133_2 * 3) + (sec_r000424_3_2 * 2)) - pub_r000424_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_221_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_221_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((((stage_v_200_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_2_1) + 8) & 127;
  int stage_v_222_2 = ((((stage_v_200_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_222_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_222_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((((sec_r000424_20_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_14_1) + 24) & 127;
  int stage_v_223_2 = ((((sec_r000424_20_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_223_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_223_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((((stage_v_144_1 * 3) + (sec_r000424_0_1 * 2)) - pub_r000424_0_1) + 20) & 127;
  int stage_v_224_2 = ((((stage_v_144_2 * 3) + (sec_r000424_0_2 * 2)) - pub_r000424_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_224_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_224_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((((stage_v_122_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_9_1) + 11) & 127;
  int stage_v_225_2 = ((((stage_v_122_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_225_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_225_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((((stage_v_135_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_1_1) + 4) & 127;
  int stage_v_226_2 = ((((stage_v_135_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_226_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_226_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((((stage_v_139_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_1_1) + 22) & 127;
  int stage_v_227_2 = ((((stage_v_139_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_227_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_227_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((((stage_v_155_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_3_1) + 20) & 127;
  int stage_v_228_2 = ((((stage_v_155_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_228_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_228_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((((sec_r000424_11_1 * 3) + (sec_r000424_11_1 * 2)) - pub_r000424_5_1) + 17) & 127;
  int stage_v_229_2 = ((((sec_r000424_11_2 * 3) + (sec_r000424_11_2 * 2)) - pub_r000424_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_229_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_229_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((((sec_r000424_15_1 * 3) + (sec_r000424_15_1 * 2)) - pub_r000424_4_1) + 12) & 127;
  int stage_v_230_2 = ((((sec_r000424_15_2 * 3) + (sec_r000424_15_2 * 2)) - pub_r000424_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_230_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_230_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((((sec_r000424_6_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_9_1) + 24) & 127;
  int stage_v_231_2 = ((((sec_r000424_6_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_231_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_231_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((((stage_v_59_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_8_1) + 27) & 127;
  int stage_v_232_2 = ((((stage_v_59_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_232_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_232_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((((sec_r000424_18_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_11_1) + 19) & 127;
  int stage_v_233_2 = ((((sec_r000424_18_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_233_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_233_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((((stage_v_142_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_8_1) + 11) & 127;
  int stage_v_234_2 = ((((stage_v_142_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_234_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_234_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((((stage_v_93_1 * 3) + (sec_r000424_15_1 * 2)) - pub_r000424_4_1) + 34) & 127;
  int stage_v_235_2 = ((((stage_v_93_2 * 3) + (sec_r000424_15_2 * 2)) - pub_r000424_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_235_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_235_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((((stage_v_183_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_1_1) + 4) & 127;
  int stage_v_236_2 = ((((stage_v_183_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_236_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_236_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((((stage_v_139_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_4_1) + 24) & 127;
  int stage_v_237_2 = ((((stage_v_139_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_237_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_237_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((((sec_r000424_1_1 * 3) + (sec_r000424_1_1 * 2)) - pub_r000424_8_1) + 36) & 127;
  int stage_v_238_2 = ((((sec_r000424_1_2 * 3) + (sec_r000424_1_2 * 2)) - pub_r000424_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_238_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_238_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((((stage_v_138_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_11_1) + 8) & 127;
  int stage_v_239_2 = ((((stage_v_138_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_239_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_239_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((((sec_r000424_4_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_3_1) + 13) & 127;
  int stage_v_240_2 = ((((sec_r000424_4_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_240_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_240_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((((stage_v_99_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_14_1) + 24) & 127;
  int stage_v_241_2 = ((((stage_v_99_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_241_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_241_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((((stage_v_156_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_3_1) + 24) & 127;
  int stage_v_242_2 = ((((stage_v_156_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_242_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_242_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((((stage_v_81_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_12_1) + 23) & 127;
  int stage_v_243_2 = ((((stage_v_81_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_243_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_243_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((((stage_v_213_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_6_1) + 32) & 127;
  int stage_v_244_2 = ((((stage_v_213_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_244_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_244_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((((stage_v_91_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_2_1) + 9) & 127;
  int stage_v_245_2 = ((((stage_v_91_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_245_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_245_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((((stage_v_84_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_4_1) + 7) & 127;
  int stage_v_246_2 = ((((stage_v_84_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_246_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_246_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((((stage_v_90_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_3_1) + 36) & 127;
  int stage_v_247_2 = ((((stage_v_90_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_247_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_247_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((((stage_v_101_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_0_1) + 26) & 127;
  int stage_v_248_2 = ((((stage_v_101_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_248_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_248_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((((stage_v_172_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_2_1) + 31) & 127;
  int stage_v_249_2 = ((((stage_v_172_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_249_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_249_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((((stage_v_114_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_4_1) + 10) & 127;
  int stage_v_250_2 = ((((stage_v_114_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_250_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_250_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((((stage_v_55_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_7_1) + 12) & 127;
  int stage_v_251_2 = ((((stage_v_55_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_251_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_251_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((((stage_v_242_1 * 3) + (sec_r000424_0_1 * 2)) - pub_r000424_3_1) + 27) & 127;
  int stage_v_252_2 = ((((stage_v_242_2 * 3) + (sec_r000424_0_2 * 2)) - pub_r000424_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_252_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_252_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((((stage_v_243_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_8_1) + 16) & 127;
  int stage_v_253_2 = ((((stage_v_243_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_253_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_253_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((((sec_r000424_4_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_15_1) + 24) & 127;
  int stage_v_254_2 = ((((sec_r000424_4_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_254_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_254_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((((stage_v_72_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_0_1) + 18) & 127;
  int stage_v_255_2 = ((((stage_v_72_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_255_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_255_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((((sec_r000424_6_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_0_1) + 24) & 127;
  int stage_v_256_2 = ((((sec_r000424_6_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_256_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_256_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((((stage_v_191_1 * 3) + (sec_r000424_9_1 * 2)) - pub_r000424_0_1) + 10) & 127;
  int stage_v_257_2 = ((((stage_v_191_2 * 3) + (sec_r000424_9_2 * 2)) - pub_r000424_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_257_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_257_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((((sec_r000424_8_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_12_1) + 20) & 127;
  int stage_v_258_2 = ((((sec_r000424_8_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_258_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_258_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((((stage_v_103_1 * 3) + (sec_r000424_9_1 * 2)) - pub_r000424_10_1) + 25) & 127;
  int stage_v_259_2 = ((((stage_v_103_2 * 3) + (sec_r000424_9_2 * 2)) - pub_r000424_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_259_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_259_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((((sec_r000424_0_1 * 3) + (sec_r000424_0_1 * 2)) - pub_r000424_12_1) + 23) & 127;
  int stage_v_260_2 = ((((sec_r000424_0_2 * 3) + (sec_r000424_0_2 * 2)) - pub_r000424_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_260_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_260_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((((stage_v_105_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_3_1) + 13) & 127;
  int stage_v_261_2 = ((((stage_v_105_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_261_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_261_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((((stage_v_82_1 * 3) + (sec_r000424_0_1 * 2)) - pub_r000424_13_1) + 6) & 127;
  int stage_v_262_2 = ((((stage_v_82_2 * 3) + (sec_r000424_0_2 * 2)) - pub_r000424_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_262_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_262_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((((stage_v_171_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_6_1) + 24) & 127;
  int stage_v_263_2 = ((((stage_v_171_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_263_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_263_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((((sec_r000424_8_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_13_1) + 23) & 127;
  int stage_v_264_2 = ((((sec_r000424_8_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_264_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_264_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((((stage_v_111_1 * 3) + (sec_r000424_0_1 * 2)) - pub_r000424_12_1) + 16) & 127;
  int stage_v_265_2 = ((((stage_v_111_2 * 3) + (sec_r000424_0_2 * 2)) - pub_r000424_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_265_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_265_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((((stage_v_240_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_9_1) + 3) & 127;
  int stage_v_266_2 = ((((stage_v_240_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_266_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_266_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((((stage_v_48_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_7_1) + 31) & 127;
  int stage_v_267_2 = ((((stage_v_48_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_267_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_267_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((((stage_v_139_1 * 3) + (sec_r000424_1_1 * 2)) - pub_r000424_13_1) + 29) & 127;
  int stage_v_268_2 = ((((stage_v_139_2 * 3) + (sec_r000424_1_2 * 2)) - pub_r000424_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_268_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_268_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((((sec_r000424_10_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_5_1) + 30) & 127;
  int stage_v_269_2 = ((((sec_r000424_10_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_269_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_269_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((((stage_v_126_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_12_1) + 28) & 127;
  int stage_v_270_2 = ((((stage_v_126_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_270_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_270_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((((stage_v_50_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_3_1) + 33) & 127;
  int stage_v_271_2 = ((((stage_v_50_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_271_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_271_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((((stage_v_223_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_3_1) + 36) & 127;
  int stage_v_272_2 = ((((stage_v_223_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_272_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_272_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((((stage_v_115_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_7_1) + 8) & 127;
  int stage_v_273_2 = ((((stage_v_115_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_273_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_273_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((((stage_v_261_1 * 3) + (sec_r000424_0_1 * 2)) - pub_r000424_11_1) + 31) & 127;
  int stage_v_274_2 = ((((stage_v_261_2 * 3) + (sec_r000424_0_2 * 2)) - pub_r000424_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_274_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_274_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((((stage_v_60_1 * 3) + (sec_r000424_1_1 * 2)) - pub_r000424_10_1) + 4) & 127;
  int stage_v_275_2 = ((((stage_v_60_2 * 3) + (sec_r000424_1_2 * 2)) - pub_r000424_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_275_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_275_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((((sec_r000424_4_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_4_1) + 27) & 127;
  int stage_v_276_2 = ((((sec_r000424_4_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_276_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_276_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((((stage_v_101_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_10_1) + 32) & 127;
  int stage_v_277_2 = ((((stage_v_101_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_277_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_277_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((((stage_v_119_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_0_1) + 30) & 127;
  int stage_v_278_2 = ((((stage_v_119_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_278_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_278_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((((stage_v_75_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_0_1) + 4) & 127;
  int stage_v_279_2 = ((((stage_v_75_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_279_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_279_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((((stage_v_65_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_9_1) + 35) & 127;
  int stage_v_280_2 = ((((stage_v_65_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_280_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_280_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((((stage_v_130_1 * 3) + (sec_r000424_15_1 * 2)) - pub_r000424_5_1) + 6) & 127;
  int stage_v_281_2 = ((((stage_v_130_2 * 3) + (sec_r000424_15_2 * 2)) - pub_r000424_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_281_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_281_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((((stage_v_85_1 * 3) + (sec_r000424_9_1 * 2)) - pub_r000424_14_1) + 12) & 127;
  int stage_v_282_2 = ((((stage_v_85_2 * 3) + (sec_r000424_9_2 * 2)) - pub_r000424_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_282_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_282_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((((stage_v_149_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_12_1) + 33) & 127;
  int stage_v_283_2 = ((((stage_v_149_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_283_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_283_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((((sec_r000424_6_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_6_1) + 23) & 127;
  int stage_v_284_2 = ((((sec_r000424_6_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_284_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_284_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((((stage_v_164_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_7_1) + 6) & 127;
  int stage_v_285_2 = ((((stage_v_164_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_285_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_285_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((((stage_v_113_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_10_1) + 36) & 127;
  int stage_v_286_2 = ((((stage_v_113_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_286_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_286_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((((stage_v_142_1 * 3) + (sec_r000424_3_1 * 2)) - pub_r000424_12_1) + 27) & 127;
  int stage_v_287_2 = ((((stage_v_142_2 * 3) + (sec_r000424_3_2 * 2)) - pub_r000424_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_287_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_287_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((((stage_v_274_1 * 3) + (sec_r000424_15_1 * 2)) - pub_r000424_3_1) + 36) & 127;
  int stage_v_288_2 = ((((stage_v_274_2 * 3) + (sec_r000424_15_2 * 2)) - pub_r000424_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_288_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_288_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((((stage_v_113_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_13_1) + 23) & 127;
  int stage_v_289_2 = ((((stage_v_113_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_289_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_289_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((((sec_r000424_2_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_10_1) + 15) & 127;
  int stage_v_290_2 = ((((sec_r000424_2_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_290_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_290_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((((stage_v_45_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_8_1) + 25) & 127;
  int stage_v_291_2 = ((((stage_v_45_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_291_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_291_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((((stage_v_244_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_13_1) + 4) & 127;
  int stage_v_292_2 = ((((stage_v_244_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_292_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_292_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((((stage_v_128_1 * 3) + (sec_r000424_14_1 * 2)) - pub_r000424_0_1) + 33) & 127;
  int stage_v_293_2 = ((((stage_v_128_2 * 3) + (sec_r000424_14_2 * 2)) - pub_r000424_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_293_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_293_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((((stage_v_146_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_10_1) + 24) & 127;
  int stage_v_294_2 = ((((stage_v_146_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_294_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_294_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((((sec_r000424_20_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_15_1) + 29) & 127;
  int stage_v_295_2 = ((((sec_r000424_20_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_295_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_295_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((((sec_r000424_9_1 * 3) + (sec_r000424_9_1 * 2)) - pub_r000424_14_1) + 3) & 127;
  int stage_v_296_2 = ((((sec_r000424_9_2 * 3) + (sec_r000424_9_2 * 2)) - pub_r000424_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_296_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_296_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((((stage_v_111_1 * 3) + (sec_r000424_3_1 * 2)) - pub_r000424_12_1) + 33) & 127;
  int stage_v_297_2 = ((((stage_v_111_2 * 3) + (sec_r000424_3_2 * 2)) - pub_r000424_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_297_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_297_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((((sec_r000424_12_1 * 3) + (sec_r000424_12_1 * 2)) - pub_r000424_10_1) + 9) & 127;
  int stage_v_298_2 = ((((sec_r000424_12_2 * 3) + (sec_r000424_12_2 * 2)) - pub_r000424_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_298_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_298_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((((stage_v_62_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_6_1) + 35) & 127;
  int stage_v_299_2 = ((((stage_v_62_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_299_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_299_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((((sec_r000424_7_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_11_1) + 35) & 127;
  int stage_v_300_2 = ((((sec_r000424_7_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_300_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_300_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((((sec_r000424_5_1 * 3) + (sec_r000424_5_1 * 2)) - pub_r000424_14_1) + 29) & 127;
  int stage_v_301_2 = ((((sec_r000424_5_2 * 3) + (sec_r000424_5_2 * 2)) - pub_r000424_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_301_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_301_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((((stage_v_248_1 * 3) + (sec_r000424_0_1 * 2)) - pub_r000424_8_1) + 15) & 127;
  int stage_v_302_2 = ((((stage_v_248_2 * 3) + (sec_r000424_0_2 * 2)) - pub_r000424_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_302_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_302_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((((sec_r000424_16_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_5_1) + 13) & 127;
  int stage_v_303_2 = ((((sec_r000424_16_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_303_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_303_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((((sec_r000424_10_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_15_1) + 23) & 127;
  int stage_v_304_2 = ((((sec_r000424_10_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_304_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_304_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((((stage_v_214_1 * 3) + (sec_r000424_20_1 * 2)) - pub_r000424_7_1) + 30) & 127;
  int stage_v_305_2 = ((((stage_v_214_2 * 3) + (sec_r000424_20_2 * 2)) - pub_r000424_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_305_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_305_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((((stage_v_215_1 * 3) + (sec_r000424_8_1 * 2)) - pub_r000424_6_1) + 21) & 127;
  int stage_v_306_2 = ((((stage_v_215_2 * 3) + (sec_r000424_8_2 * 2)) - pub_r000424_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_306_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_306_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((((stage_v_155_1 * 3) + (sec_r000424_15_1 * 2)) - pub_r000424_13_1) + 5) & 127;
  int stage_v_307_2 = ((((stage_v_155_2 * 3) + (sec_r000424_15_2 * 2)) - pub_r000424_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_307_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_307_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((((sec_r000424_18_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_5_1) + 15) & 127;
  int stage_v_308_2 = ((((sec_r000424_18_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_308_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_308_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((((sec_r000424_5_1 * 3) + (sec_r000424_5_1 * 2)) - pub_r000424_4_1) + 7) & 127;
  int stage_v_309_2 = ((((sec_r000424_5_2 * 3) + (sec_r000424_5_2 * 2)) - pub_r000424_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_309_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_309_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((((sec_r000424_4_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_5_1) + 10) & 127;
  int stage_v_310_2 = ((((sec_r000424_4_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_310_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_310_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((((stage_v_223_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_10_1) + 25) & 127;
  int stage_v_311_2 = ((((stage_v_223_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_311_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_311_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((((stage_v_86_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_3_1) + 19) & 127;
  int stage_v_312_2 = ((((stage_v_86_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_312_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_312_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((((stage_v_268_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_14_1) + 26) & 127;
  int stage_v_313_2 = ((((stage_v_268_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_313_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_313_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((((stage_v_80_1 * 3) + (sec_r000424_16_1 * 2)) - pub_r000424_11_1) + 33) & 127;
  int stage_v_314_2 = ((((stage_v_80_2 * 3) + (sec_r000424_16_2 * 2)) - pub_r000424_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_314_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_314_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((((sec_r000424_1_1 * 3) + (sec_r000424_1_1 * 2)) - pub_r000424_4_1) + 23) & 127;
  int stage_v_315_2 = ((((sec_r000424_1_2 * 3) + (sec_r000424_1_2 * 2)) - pub_r000424_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_315_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_315_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((((stage_v_140_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_10_1) + 30) & 127;
  int stage_v_316_2 = ((((stage_v_140_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_316_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_316_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((((sec_r000424_18_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_12_1) + 21) & 127;
  int stage_v_317_2 = ((((sec_r000424_18_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_317_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_317_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((((sec_r000424_13_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_12_1) + 22) & 127;
  int stage_v_318_2 = ((((sec_r000424_13_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_318_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_318_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((((stage_v_94_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_0_1) + 33) & 127;
  int stage_v_319_2 = ((((stage_v_94_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_319_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_319_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((((stage_v_206_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_6_1) + 24) & 127;
  int stage_v_320_2 = ((((stage_v_206_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_320_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_320_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((((sec_r000424_0_1 * 3) + (sec_r000424_0_1 * 2)) - pub_r000424_8_1) + 19) & 127;
  int stage_v_321_2 = ((((sec_r000424_0_2 * 3) + (sec_r000424_0_2 * 2)) - pub_r000424_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_321_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_321_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int stage_v_322_1 = ((((stage_v_307_1 * 3) + (sec_r000424_4_1 * 2)) - pub_r000424_2_1) + 5) & 127;
  int stage_v_322_2 = ((((stage_v_307_2 * 3) + (sec_r000424_4_2 * 2)) - pub_r000424_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_322_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_322_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int stage_v_323_1 = ((((stage_v_249_1 * 3) + (sec_r000424_10_1 * 2)) - pub_r000424_1_1) + 8) & 127;
  int stage_v_323_2 = ((((stage_v_249_2 * 3) + (sec_r000424_10_2 * 2)) - pub_r000424_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_323_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_323_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int stage_v_324_1 = ((((sec_r000424_7_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_0_1) + 26) & 127;
  int stage_v_324_2 = ((((sec_r000424_7_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_324_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_324_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int stage_v_325_1 = ((((sec_r000424_9_1 * 3) + (sec_r000424_9_1 * 2)) - pub_r000424_1_1) + 14) & 127;
  int stage_v_325_2 = ((((sec_r000424_9_2 * 3) + (sec_r000424_9_2 * 2)) - pub_r000424_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_325_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_325_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  int stage_v_326_1 = ((((stage_v_158_1 * 3) + (sec_r000424_5_1 * 2)) - pub_r000424_7_1) + 9) & 127;
  int stage_v_326_2 = ((((stage_v_158_2 * 3) + (sec_r000424_5_2 * 2)) - pub_r000424_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_326_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_326_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_326_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_326_2) & 255;
  int stage_v_327_1 = ((((stage_v_246_1 * 3) + (sec_r000424_17_1 * 2)) - pub_r000424_12_1) + 22) & 127;
  int stage_v_327_2 = ((((stage_v_246_2 * 3) + (sec_r000424_17_2 * 2)) - pub_r000424_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_327_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_327_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_327_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_327_2) & 255;
  int stage_v_328_1 = ((((sec_r000424_7_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_1_1) + 30) & 127;
  int stage_v_328_2 = ((((sec_r000424_7_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_328_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_328_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_328_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_328_2) & 255;
  int stage_v_329_1 = ((((stage_v_61_1 * 3) + (sec_r000424_6_1 * 2)) - pub_r000424_14_1) + 32) & 127;
  int stage_v_329_2 = ((((stage_v_61_2 * 3) + (sec_r000424_6_2 * 2)) - pub_r000424_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_329_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_329_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_329_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_329_2) & 255;
  int stage_v_330_1 = ((((stage_v_51_1 * 3) + (sec_r000424_5_1 * 2)) - pub_r000424_4_1) + 9) & 127;
  int stage_v_330_2 = ((((stage_v_51_2 * 3) + (sec_r000424_5_2 * 2)) - pub_r000424_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_330_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_330_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_330_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_330_2) & 255;
  int stage_v_331_1 = ((((stage_v_327_1 * 3) + (sec_r000424_7_1 * 2)) - pub_r000424_4_1) + 19) & 127;
  int stage_v_331_2 = ((((stage_v_327_2 * 3) + (sec_r000424_7_2 * 2)) - pub_r000424_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_331_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_331_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_331_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_331_2) & 255;
  int stage_v_332_1 = ((((stage_v_255_1 * 3) + (sec_r000424_2_1 * 2)) - pub_r000424_0_1) + 9) & 127;
  int stage_v_332_2 = ((((stage_v_255_2 * 3) + (sec_r000424_2_2 * 2)) - pub_r000424_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_332_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_332_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_332_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_332_2) & 255;
  int stage_v_333_1 = ((((sec_r000424_15_1 * 3) + (sec_r000424_15_1 * 2)) - pub_r000424_2_1) + 28) & 127;
  int stage_v_333_2 = ((((sec_r000424_15_2 * 3) + (sec_r000424_15_2 * 2)) - pub_r000424_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_333_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_333_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_333_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_333_2) & 255;
  int stage_v_334_1 = ((((stage_v_290_1 * 3) + (sec_r000424_15_1 * 2)) - pub_r000424_8_1) + 30) & 127;
  int stage_v_334_2 = ((((stage_v_290_2 * 3) + (sec_r000424_15_2 * 2)) - pub_r000424_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_334_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_334_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_334_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_334_2) & 255;
  int stage_v_335_1 = ((((stage_v_223_1 * 3) + (sec_r000424_18_1 * 2)) - pub_r000424_6_1) + 22) & 127;
  int stage_v_335_2 = ((((stage_v_223_2 * 3) + (sec_r000424_18_2 * 2)) - pub_r000424_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_335_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_335_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_335_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_335_2) & 255;
  int stage_v_336_1 = ((((stage_v_205_1 * 3) + (sec_r000424_13_1 * 2)) - pub_r000424_3_1) + 36) & 127;
  int stage_v_336_2 = ((((stage_v_205_2 * 3) + (sec_r000424_13_2 * 2)) - pub_r000424_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_336_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_336_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_336_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_336_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000424_11_1 == pub_r000424_11_2);
  __CPROVER_assume(sec_r000424_2_1 != sec_r000424_2_2);
  __CPROVER_assume(sec_r000424_11_1 != sec_r000424_11_2);
  __CPROVER_assume(sec_r000424_17_1 != sec_r000424_17_2);
  __CPROVER_assume(sec_r000424_0_1 != sec_r000424_0_2);
  __CPROVER_assume(sec_r000424_20_1 != sec_r000424_20_2);
  __CPROVER_assume(pub_r000424_5_1 == pub_r000424_5_2);
  __CPROVER_assume(pub_r000424_6_1 == pub_r000424_6_2);
  __CPROVER_assume(pub_r000424_12_1 == pub_r000424_12_2);
  __CPROVER_assume(sec_r000424_12_1 != sec_r000424_12_2);
  __CPROVER_assume(sec_r000424_7_1 != sec_r000424_7_2);
  __CPROVER_assume(pub_r000424_0_1 == pub_r000424_0_2);
  __CPROVER_assume(sec_r000424_18_1 != sec_r000424_18_2);
  __CPROVER_assume(pub_r000424_15_1 == pub_r000424_15_2);
  __CPROVER_assume(pub_r000424_9_1 == pub_r000424_9_2);
  __CPROVER_assume(sec_r000424_9_1 != sec_r000424_9_2);
  __CPROVER_assume(pub_r000424_7_1 == pub_r000424_7_2);
  __CPROVER_assume(pub_r000424_1_1 == pub_r000424_1_2);
  __CPROVER_assume(pub_r000424_2_1 == pub_r000424_2_2);
  __CPROVER_assume(pub_r000424_3_1 == pub_r000424_3_2);
  __CPROVER_assume(pub_r000424_13_1 == pub_r000424_13_2);
  __CPROVER_assume(pub_r000424_8_1 == pub_r000424_8_2);
  __CPROVER_assume(sec_r000424_1_1 != sec_r000424_1_2);
  __CPROVER_assume(sec_r000424_6_1 != sec_r000424_6_2);
  __CPROVER_assume(sec_r000424_15_1 != sec_r000424_15_2);
  __CPROVER_assume(sec_r000424_14_1 != sec_r000424_14_2);
  __CPROVER_assume(sec_r000424_3_1 != sec_r000424_3_2);
  __CPROVER_assume(sec_r000424_4_1 != sec_r000424_4_2);
  __CPROVER_assume(sec_r000424_16_1 != sec_r000424_16_2);
  __CPROVER_assume(pub_r000424_14_1 == pub_r000424_14_2);
  __CPROVER_assume(sec_r000424_5_1 != sec_r000424_5_2);
  __CPROVER_assume(sec_r000424_19_1 != sec_r000424_19_2);
  __CPROVER_assume(sec_r000424_10_1 != sec_r000424_10_2);
  __CPROVER_assume(pub_r000424_10_1 == pub_r000424_10_2);
  __CPROVER_assume(pub_r000424_4_1 == pub_r000424_4_2);
  __CPROVER_assume(sec_r000424_8_1 != sec_r000424_8_2);
  __CPROVER_assume(sec_r000424_13_1 != sec_r000424_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
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
}


