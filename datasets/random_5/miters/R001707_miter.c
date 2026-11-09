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
struct FilterState_R001707_713_0
{
  short gain_db;
  unsigned char damping;
  int prev_in;
  short mode;
  unsigned char cutoff;
  short prev_out;
  int buffer[3];
};
struct DeviceConfig_R001707_713_1
{
  unsigned char stop_bits;
  int baud_rate;
  int timeout;
  int id;
  short port;
  int parity;
  int buffer[3];
};
struct EventLog_R001707_713_2
{
  unsigned char signature;
  int severity;
  unsigned char code;
  short facility;
  unsigned char timestamp;
  int seq;
  int buffer[3];
};
union ColorPixel_R001707_713_0
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
void fn_R001707_713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001707_713_1 st_1 = {0};
  struct DeviceConfig_R001707_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int stride_43_1 = 0;
  int stride_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_43_1 = ((stride_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_43_2 = ((stride_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_43_1) & 127;
    acc_2 = (acc_2 + stride_43_2) & 127;
  }

  int checksum_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_33_1 > 25)
  {
    acc_1 = ((acc_1 + (checksum_33_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_33_2 > 25)
  {
    acc_2 = ((acc_2 + (checksum_33_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_43_1 == stride_43_2);
  assert(checksum_33_1 == checksum_33_2);
}

int fn_R001707_713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001707_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int stride_43 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_43 = ((stride_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_43) & 127;
  }

  int checksum_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_33 > 25)
  {
    acc = ((acc + (checksum_33 * 2)) + 5) & 127;
    aux ^= checksum_33 & 15;
  }
  else
  {
    acc = ((acc - checksum_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001707_713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001707_713_2 st_1 = {0};
  struct EventLog_R001707_713_2 st_2 = {0};
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
  int scale_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_58_1)
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

  switch (scale_58_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_58_1 == scale_58_2);
}

int fn_R001707_713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001707_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_58 = (aux + st.buffer[1]) & 3;
  switch (scale_58)
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

void fn_R001707_713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st_1 = {0};
  struct FilterState_R001707_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_53_1 = local_arr_1[aux_1 % 3];
  int pivot_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_53_2 * 2)) & 127;
  int stride_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_96_1) & 63;
  aux_2 = (aux_2 + stride_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_15_1 > 29)
  {
    acc_1 = ((acc_1 + (threshold_15_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_15_2 > 29)
  {
    acc_2 = ((acc_2 + (threshold_15_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_53_1 == pivot_53_2);
  assert(stride_96_1 == stride_96_2);
  assert(threshold_15_1 == threshold_15_2);
}

int fn_R001707_713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int pivot_53 = local_arr[aux % 3];
  acc = (acc + (pivot_53 * 2)) & 127;
  int stride_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_96) & 63;
  acc ^= aux;
  int threshold_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_15 > 29)
  {
    acc = ((acc + (threshold_15 * 2)) + 5) & 127;
    aux ^= threshold_15 & 15;
  }
  else
  {
    acc = ((acc - threshold_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001707_713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001707_713_1 st_1 = {0};
  struct DeviceConfig_R001707_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int offset_94_1 = 0;
  int offset_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_94_1 = ((offset_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_94_2 = ((offset_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_94_1) & 127;
    acc_2 = (acc_2 + offset_94_2) & 127;
  }

  int window_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_58_1)
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

  switch (window_58_2)
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

  int stride_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_48_1 > 49)
  {
    acc_1 = ((acc_1 + (stride_48_1 * 2)) + 5) & 127;
    aux_1 ^= stride_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_48_2 > 49)
  {
    acc_2 = ((acc_2 + (stride_48_2 * 2)) + 5) & 127;
    aux_2 ^= stride_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_35_1) & 63;
  aux_2 = (aux_2 + window_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_94_1 == offset_94_2);
  assert(window_58_1 == window_58_2);
  assert(stride_48_1 == stride_48_2);
  assert(window_35_1 == window_35_2);
}

int fn_R001707_713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001707_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int offset_94 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_94 = ((offset_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_94) & 127;
  }

  int window_58 = (aux + st.buffer[1]) & 3;
  switch (window_58)
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

  int stride_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_48 > 49)
  {
    acc = ((acc + (stride_48 * 2)) + 5) & 127;
    aux ^= stride_48 & 15;
  }
  else
  {
    acc = ((acc - stride_48) + 11) & 127;
    aux += 3;
  }
  int window_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001707_713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st_1 = {0};
  struct FilterState_R001707_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int cursor_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_20_1)
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

  switch (cursor_20_2)
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
  int window_12_1 = local_arr_1[aux_1 % 3];
  int window_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_20_1 == cursor_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_12_1 == window_12_2);
}

int fn_R001707_713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int cursor_20 = (aux + st.buffer[1]) & 3;
  switch (cursor_20)
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
  int window_12 = local_arr[aux % 3];
  acc = (acc + (window_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001707_713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st_1 = {0};
  struct FilterState_R001707_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int bound_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_95_1) & 63;
  aux_2 = (aux_2 + bound_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_51_1 = local_arr_1[aux_1 % 3];
  int vector_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_95_1 == bound_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_51_1 == vector_51_2);
}

int fn_R001707_713_5(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int bound_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_95) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_51 = local_arr[aux % 3];
  acc = (acc + (vector_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001707_713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001707_713_2 st_1 = {0};
  struct EventLog_R001707_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int factor_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_89_1)
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

  switch (factor_89_2)
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

  int cursor_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_70_1 > 40)
  {
    acc_1 = ((acc_1 + (cursor_70_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_70_2 > 40)
  {
    acc_2 = ((acc_2 + (cursor_70_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_89_1) & 63;
  aux_2 = (aux_2 + accumulator_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_89_1 == factor_89_2);
  assert(cursor_70_1 == cursor_70_2);
  assert(accumulator_89_1 == accumulator_89_2);
}

int fn_R001707_713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001707_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int factor_89 = (aux + st.buffer[1]) & 3;
  switch (factor_89)
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

  int cursor_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_70 > 40)
  {
    acc = ((acc + (cursor_70 * 2)) + 5) & 127;
    aux ^= cursor_70 & 15;
  }
  else
  {
    acc = ((acc - cursor_70) + 11) & 127;
    aux += 3;
  }
  int accumulator_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_89) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001707_713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st_1 = {0};
  struct FilterState_R001707_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int accumulator_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_75_1) & 63;
  aux_2 = (aux_2 + accumulator_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_15_1 > 47)
  {
    acc_1 = ((acc_1 + (quotient_15_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_15_2 > 47)
  {
    acc_2 = ((acc_2 + (quotient_15_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_75_1 == accumulator_75_2);
  assert(quotient_15_1 == quotient_15_2);
}

int fn_R001707_713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int accumulator_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_75) & 63;
  acc ^= aux;
  int quotient_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_15 > 47)
  {
    acc = ((acc + (quotient_15 * 2)) + 5) & 127;
    aux ^= quotient_15 & 15;
  }
  else
  {
    acc = ((acc - quotient_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001707_713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st_1 = {0};
  struct FilterState_R001707_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int sample_54_1 = 0;
  int sample_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_54_1 = ((sample_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_54_2 = ((sample_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_54_1) & 127;
    acc_2 = (acc_2 + sample_54_2) & 127;
  }

  int coefficient_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_24_1 > 14)
  {
    acc_1 = ((acc_1 + (coefficient_24_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_24_2 > 14)
  {
    acc_2 = ((acc_2 + (coefficient_24_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_33_1)
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

  switch (parity_33_2)
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
  int factor_86_1 = local_arr_1[aux_1 % 3];
  int factor_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_54_1 == sample_54_2);
  assert(coefficient_24_1 == coefficient_24_2);
  assert(parity_33_1 == parity_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_86_1 == factor_86_2);
}

int fn_R001707_713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int sample_54 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_54 = ((sample_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_54) & 127;
  }

  int coefficient_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_24 > 14)
  {
    acc = ((acc + (coefficient_24 * 2)) + 5) & 127;
    aux ^= coefficient_24 & 15;
  }
  else
  {
    acc = ((acc - coefficient_24) + 11) & 127;
    aux += 3;
  }
  int parity_33 = (aux + st.buffer[1]) & 3;
  switch (parity_33)
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
  int factor_86 = local_arr[aux % 3];
  acc = (acc + (factor_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001707_713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001707_713_2 st_1 = {0};
  struct EventLog_R001707_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_71_1 = local_arr_1[aux_1 % 3];
  int accumulator_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_71_2 * 2)) & 127;
  int residue_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_40_1)
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

  switch (residue_40_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_71_1 == accumulator_71_2);
  assert(residue_40_1 == residue_40_2);
}

int fn_R001707_713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001707_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int accumulator_71 = local_arr[aux % 3];
  acc = (acc + (accumulator_71 * 2)) & 127;
  int residue_40 = (aux + st.buffer[1]) & 3;
  switch (residue_40)
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

void fn_R001707_713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001707_713_2 st_1 = {0};
  struct EventLog_R001707_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int coefficient_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_72_1 > 11)
  {
    acc_1 = ((acc_1 + (coefficient_72_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_72_2 > 11)
  {
    acc_2 = ((acc_2 + (coefficient_72_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_72_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_82_1)
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

  switch (sample_82_2)
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

  int accumulator_20_1 = 0;
  int accumulator_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_20_1 = ((accumulator_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_20_2 = ((accumulator_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_20_1) & 127;
    acc_2 = (acc_2 + accumulator_20_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_72_1 == coefficient_72_2);
  assert(sample_82_1 == sample_82_2);
  assert(accumulator_20_1 == accumulator_20_2);
}

int fn_R001707_713_10(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001707_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int coefficient_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_72 > 11)
  {
    acc = ((acc + (coefficient_72 * 2)) + 5) & 127;
    aux ^= coefficient_72 & 15;
  }
  else
  {
    acc = ((acc - coefficient_72) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_82 = (aux + st.buffer[1]) & 3;
  switch (sample_82)
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

  int accumulator_20 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_20 = ((accumulator_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_20) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001707_713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001707_713_2 st_1 = {0};
  struct EventLog_R001707_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_49_1 = local_arr_1[aux_1 % 3];
  int margin_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_49_2 * 2)) & 127;
  int segment_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_97_1)
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

  switch (segment_97_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_49_1 == margin_49_2);
  assert(segment_97_1 == segment_97_2);
}

int fn_R001707_713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001707_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int margin_49 = local_arr[aux % 3];
  acc = (acc + (margin_49 * 2)) & 127;
  int segment_97 = (aux + st.buffer[1]) & 3;
  switch (segment_97)
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

void fn_R001707_713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st_1 = {0};
  struct FilterState_R001707_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_28_1 = local_arr_1[aux_1 % 3];
  int offset_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_28_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_26_1)
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

  switch (segment_26_2)
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

  int phase_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_42_1) & 63;
  aux_2 = (aux_2 + phase_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_28_1 == offset_28_2);
  assert(segment_26_1 == segment_26_2);
  assert(phase_42_1 == phase_42_2);
}

int fn_R001707_713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int offset_28 = local_arr[aux % 3];
  acc = (acc + (offset_28 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_26 = (aux + st.buffer[1]) & 3;
  switch (segment_26)
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

  int phase_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_42) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001707_713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st_1 = {0};
  struct FilterState_R001707_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_84_1)
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

  switch (delta_84_2)
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
  int factor_26_1 = local_arr_1[aux_1 % 3];
  int factor_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_26_2 * 2)) & 127;
  int quotient_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_32_1 > 14)
  {
    acc_1 = ((acc_1 + (quotient_32_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_32_2 > 14)
  {
    acc_2 = ((acc_2 + (quotient_32_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_84_1 == delta_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_26_1 == factor_26_2);
  assert(quotient_32_1 == quotient_32_2);
}

int fn_R001707_713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001707_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_84 = (aux + st.buffer[1]) & 3;
  switch (delta_84)
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
  int factor_26 = local_arr[aux % 3];
  acc = (acc + (factor_26 * 2)) & 127;
  int quotient_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_32 > 14)
  {
    acc = ((acc + (quotient_32 * 2)) + 5) & 127;
    aux ^= quotient_32 & 15;
  }
  else
  {
    acc = ((acc - quotient_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001707_713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001707_713_2 st_1 = {0};
  struct EventLog_R001707_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tally_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_25_1)
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

  switch (tally_25_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_66_1 = local_arr_1[aux_1 % 3];
  int sample_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_66_2 * 2)) & 127;
  int pivot_18_1 = 0;
  int pivot_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_18_1 = ((pivot_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_18_2 = ((pivot_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_18_1) & 127;
    acc_2 = (acc_2 + pivot_18_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_25_1 == tally_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_66_1 == sample_66_2);
  assert(pivot_18_1 == pivot_18_2);
}

int fn_R001707_713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001707_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tally_25 = (aux + st.buffer[1]) & 3;
  switch (tally_25)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_66 = local_arr[aux % 3];
  acc = (acc + (sample_66 * 2)) & 127;
  int pivot_18 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_18 = ((pivot_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_18) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001707_713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001707_713_1 st_1 = {0};
  struct DeviceConfig_R001707_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int residue_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_43_1)
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

  switch (residue_43_2)
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

  int margin_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_28_1) & 63;
  aux_2 = (aux_2 + margin_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_43_1 == residue_43_2);
  assert(margin_28_1 == margin_28_2);
}

int fn_R001707_713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001707_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int residue_43 = (aux + st.buffer[1]) & 3;
  switch (residue_43)
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

  int margin_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_28) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001707_0_1;
  int sec_r001707_0_2;
  int sec_r001707_1_1;
  int sec_r001707_1_2;
  int sec_r001707_2_1;
  int sec_r001707_2_2;
  int sec_r001707_3_1;
  int sec_r001707_3_2;
  int sec_r001707_4_1;
  int sec_r001707_4_2;
  int sec_r001707_5_1;
  int sec_r001707_5_2;
  int sec_r001707_6_1;
  int sec_r001707_6_2;
  int sec_r001707_7_1;
  int sec_r001707_7_2;
  int sec_r001707_8_1;
  int sec_r001707_8_2;
  int sec_r001707_9_1;
  int sec_r001707_9_2;
  int sec_r001707_10_1;
  int sec_r001707_10_2;
  int sec_r001707_11_1;
  int sec_r001707_11_2;
  int sec_r001707_12_1;
  int sec_r001707_12_2;
  int sec_r001707_13_1;
  int sec_r001707_13_2;
  int sec_r001707_14_1;
  int sec_r001707_14_2;
  int sec_r001707_15_1;
  int sec_r001707_15_2;
  int sec_r001707_16_1;
  int sec_r001707_16_2;
  int sec_r001707_17_1;
  int sec_r001707_17_2;
  int sec_r001707_18_1;
  int sec_r001707_18_2;
  int sec_r001707_19_1;
  int sec_r001707_19_2;
  int sec_r001707_20_1;
  int sec_r001707_20_2;
  int sec_r001707_21_1;
  int sec_r001707_21_2;
  int sec_r001707_22_1;
  int sec_r001707_22_2;
  int pub_r001707_0_1;
  int pub_r001707_0_2;
  int pub_r001707_1_1;
  int pub_r001707_1_2;
  int pub_r001707_2_1;
  int pub_r001707_2_2;
  int pub_r001707_3_1;
  int pub_r001707_3_2;
  int pub_r001707_4_1;
  int pub_r001707_4_2;
  int pub_r001707_5_1;
  int pub_r001707_5_2;
  int pub_r001707_6_1;
  int pub_r001707_6_2;
  int pub_r001707_7_1;
  int pub_r001707_7_2;
  int pub_r001707_8_1;
  int pub_r001707_8_2;
  int pub_r001707_9_1;
  int pub_r001707_9_2;
  int pub_r001707_10_1;
  int pub_r001707_10_2;
  int pub_r001707_11_1;
  int pub_r001707_11_2;
  int pub_r001707_12_1;
  int pub_r001707_12_2;
  int pub_r001707_13_1;
  int pub_r001707_13_2;
  int pub_r001707_14_1;
  int pub_r001707_14_2;
  int pub_r001707_15_1;
  int pub_r001707_15_2;
  int pub_r001707_16_1;
  int pub_r001707_16_2;
  int pub_r001707_17_1;
  int pub_r001707_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001707_0_1 >= (-100)) && (pub_r001707_0_1 <= 100));
  __CPROVER_assume((pub_r001707_0_2 >= (-100)) && (pub_r001707_0_2 <= 100));
  __CPROVER_assume((pub_r001707_1_1 >= (-100)) && (pub_r001707_1_1 <= 100));
  __CPROVER_assume((pub_r001707_1_2 >= (-100)) && (pub_r001707_1_2 <= 100));
  __CPROVER_assume((pub_r001707_2_1 >= (-100)) && (pub_r001707_2_1 <= 100));
  __CPROVER_assume((pub_r001707_2_2 >= (-100)) && (pub_r001707_2_2 <= 100));
  __CPROVER_assume((pub_r001707_3_1 >= (-100)) && (pub_r001707_3_1 <= 100));
  __CPROVER_assume((pub_r001707_3_2 >= (-100)) && (pub_r001707_3_2 <= 100));
  __CPROVER_assume((pub_r001707_4_1 >= (-100)) && (pub_r001707_4_1 <= 100));
  __CPROVER_assume((pub_r001707_4_2 >= (-100)) && (pub_r001707_4_2 <= 100));
  __CPROVER_assume((pub_r001707_5_1 >= (-100)) && (pub_r001707_5_1 <= 100));
  __CPROVER_assume((pub_r001707_5_2 >= (-100)) && (pub_r001707_5_2 <= 100));
  __CPROVER_assume((pub_r001707_6_1 >= (-100)) && (pub_r001707_6_1 <= 100));
  __CPROVER_assume((pub_r001707_6_2 >= (-100)) && (pub_r001707_6_2 <= 100));
  __CPROVER_assume((pub_r001707_7_1 >= (-100)) && (pub_r001707_7_1 <= 100));
  __CPROVER_assume((pub_r001707_7_2 >= (-100)) && (pub_r001707_7_2 <= 100));
  __CPROVER_assume((pub_r001707_8_1 >= (-100)) && (pub_r001707_8_1 <= 100));
  __CPROVER_assume((pub_r001707_8_2 >= (-100)) && (pub_r001707_8_2 <= 100));
  __CPROVER_assume((pub_r001707_9_1 >= (-100)) && (pub_r001707_9_1 <= 100));
  __CPROVER_assume((pub_r001707_9_2 >= (-100)) && (pub_r001707_9_2 <= 100));
  __CPROVER_assume((pub_r001707_10_1 >= (-100)) && (pub_r001707_10_1 <= 100));
  __CPROVER_assume((pub_r001707_10_2 >= (-100)) && (pub_r001707_10_2 <= 100));
  __CPROVER_assume((pub_r001707_11_1 >= (-100)) && (pub_r001707_11_1 <= 100));
  __CPROVER_assume((pub_r001707_11_2 >= (-100)) && (pub_r001707_11_2 <= 100));
  __CPROVER_assume((pub_r001707_12_1 >= (-100)) && (pub_r001707_12_1 <= 100));
  __CPROVER_assume((pub_r001707_12_2 >= (-100)) && (pub_r001707_12_2 <= 100));
  __CPROVER_assume((pub_r001707_13_1 >= (-100)) && (pub_r001707_13_1 <= 100));
  __CPROVER_assume((pub_r001707_13_2 >= (-100)) && (pub_r001707_13_2 <= 100));
  __CPROVER_assume((pub_r001707_14_1 >= (-100)) && (pub_r001707_14_1 <= 100));
  __CPROVER_assume((pub_r001707_14_2 >= (-100)) && (pub_r001707_14_2 <= 100));
  __CPROVER_assume((pub_r001707_15_1 >= (-100)) && (pub_r001707_15_1 <= 100));
  __CPROVER_assume((pub_r001707_15_2 >= (-100)) && (pub_r001707_15_2 <= 100));
  __CPROVER_assume((pub_r001707_16_1 >= (-100)) && (pub_r001707_16_1 <= 100));
  __CPROVER_assume((pub_r001707_16_2 >= (-100)) && (pub_r001707_16_2 <= 100));
  __CPROVER_assume((pub_r001707_17_1 >= (-100)) && (pub_r001707_17_1 <= 100));
  __CPROVER_assume((pub_r001707_17_2 >= (-100)) && (pub_r001707_17_2 <= 100));
  __CPROVER_assume((sec_r001707_0_1 >= 0) && (sec_r001707_0_1 <= 255));
  __CPROVER_assume((sec_r001707_0_2 >= 0) && (sec_r001707_0_2 <= 255));
  __CPROVER_assume((sec_r001707_1_1 >= 0) && (sec_r001707_1_1 <= 255));
  __CPROVER_assume((sec_r001707_1_2 >= 0) && (sec_r001707_1_2 <= 255));
  __CPROVER_assume((sec_r001707_2_1 >= 0) && (sec_r001707_2_1 <= 255));
  __CPROVER_assume((sec_r001707_2_2 >= 0) && (sec_r001707_2_2 <= 255));
  __CPROVER_assume((sec_r001707_3_1 >= 0) && (sec_r001707_3_1 <= 255));
  __CPROVER_assume((sec_r001707_3_2 >= 0) && (sec_r001707_3_2 <= 255));
  __CPROVER_assume((sec_r001707_4_1 >= 0) && (sec_r001707_4_1 <= 255));
  __CPROVER_assume((sec_r001707_4_2 >= 0) && (sec_r001707_4_2 <= 255));
  __CPROVER_assume((sec_r001707_5_1 >= 0) && (sec_r001707_5_1 <= 255));
  __CPROVER_assume((sec_r001707_5_2 >= 0) && (sec_r001707_5_2 <= 255));
  __CPROVER_assume((sec_r001707_6_1 >= 0) && (sec_r001707_6_1 <= 255));
  __CPROVER_assume((sec_r001707_6_2 >= 0) && (sec_r001707_6_2 <= 255));
  __CPROVER_assume((sec_r001707_7_1 >= 0) && (sec_r001707_7_1 <= 255));
  __CPROVER_assume((sec_r001707_7_2 >= 0) && (sec_r001707_7_2 <= 255));
  __CPROVER_assume((sec_r001707_8_1 >= 0) && (sec_r001707_8_1 <= 255));
  __CPROVER_assume((sec_r001707_8_2 >= 0) && (sec_r001707_8_2 <= 255));
  __CPROVER_assume((sec_r001707_9_1 >= 0) && (sec_r001707_9_1 <= 255));
  __CPROVER_assume((sec_r001707_9_2 >= 0) && (sec_r001707_9_2 <= 255));
  __CPROVER_assume((sec_r001707_10_1 >= 0) && (sec_r001707_10_1 <= 255));
  __CPROVER_assume((sec_r001707_10_2 >= 0) && (sec_r001707_10_2 <= 255));
  __CPROVER_assume((sec_r001707_11_1 >= 0) && (sec_r001707_11_1 <= 255));
  __CPROVER_assume((sec_r001707_11_2 >= 0) && (sec_r001707_11_2 <= 255));
  __CPROVER_assume((sec_r001707_12_1 >= 0) && (sec_r001707_12_1 <= 255));
  __CPROVER_assume((sec_r001707_12_2 >= 0) && (sec_r001707_12_2 <= 255));
  __CPROVER_assume((sec_r001707_13_1 >= 0) && (sec_r001707_13_1 <= 255));
  __CPROVER_assume((sec_r001707_13_2 >= 0) && (sec_r001707_13_2 <= 255));
  __CPROVER_assume((sec_r001707_14_1 >= 0) && (sec_r001707_14_1 <= 255));
  __CPROVER_assume((sec_r001707_14_2 >= 0) && (sec_r001707_14_2 <= 255));
  __CPROVER_assume((sec_r001707_15_1 >= 0) && (sec_r001707_15_1 <= 255));
  __CPROVER_assume((sec_r001707_15_2 >= 0) && (sec_r001707_15_2 <= 255));
  __CPROVER_assume((sec_r001707_16_1 >= 0) && (sec_r001707_16_1 <= 255));
  __CPROVER_assume((sec_r001707_16_2 >= 0) && (sec_r001707_16_2 <= 255));
  __CPROVER_assume((sec_r001707_17_1 >= 0) && (sec_r001707_17_1 <= 255));
  __CPROVER_assume((sec_r001707_17_2 >= 0) && (sec_r001707_17_2 <= 255));
  __CPROVER_assume((sec_r001707_18_1 >= 0) && (sec_r001707_18_1 <= 255));
  __CPROVER_assume((sec_r001707_18_2 >= 0) && (sec_r001707_18_2 <= 255));
  __CPROVER_assume((sec_r001707_19_1 >= 0) && (sec_r001707_19_1 <= 255));
  __CPROVER_assume((sec_r001707_19_2 >= 0) && (sec_r001707_19_2 <= 255));
  __CPROVER_assume((sec_r001707_20_1 >= 0) && (sec_r001707_20_1 <= 255));
  __CPROVER_assume((sec_r001707_20_2 >= 0) && (sec_r001707_20_2 <= 255));
  __CPROVER_assume((sec_r001707_21_1 >= 0) && (sec_r001707_21_1 <= 255));
  __CPROVER_assume((sec_r001707_21_2 >= 0) && (sec_r001707_21_2 <= 255));
  __CPROVER_assume((sec_r001707_22_1 >= 0) && (sec_r001707_22_1 <= 255));
  __CPROVER_assume((sec_r001707_22_2 >= 0) && (sec_r001707_22_2 <= 255));
  struct FilterState_R001707_713_0 st_var_0_1 = {0};
  struct FilterState_R001707_713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001707_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001707_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001707_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001707_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001707_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001707_0_2 + 7) & 15;
  struct DeviceConfig_R001707_713_1 st_var_1_1 = {0};
  struct DeviceConfig_R001707_713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001707_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001707_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001707_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001707_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001707_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001707_0_2 + 9) & 15;
  struct EventLog_R001707_713_2 st_var_2_1 = {0};
  struct EventLog_R001707_713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001707_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001707_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001707_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001707_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001707_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001707_0_2 + 11) & 15;
  union ColorPixel_R001707_713_0 u_var_1;
  union ColorPixel_R001707_713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001707_713_0(sec_r001707_0_1, pub_r001707_1_1, pub_r001707_2_1);
  int helper_flow_0_2 = fn_R001707_713_0(sec_r001707_0_2, pub_r001707_1_2, pub_r001707_2_2);
  fn_R001707_713_0_2(sec_r001707_0_1, pub_r001707_1_1, pub_r001707_2_1, sec_r001707_0_2, pub_r001707_1_2, pub_r001707_2_2);
  int helper_flow_1_1 = fn_R001707_713_1(sec_r001707_1_1, sec_r001707_2_1, pub_r001707_3_1);
  int helper_flow_1_2 = fn_R001707_713_1(sec_r001707_1_2, sec_r001707_2_2, pub_r001707_3_2);
  fn_R001707_713_1_2(sec_r001707_1_1, sec_r001707_2_1, pub_r001707_3_1, sec_r001707_1_2, sec_r001707_2_2, pub_r001707_3_2);
  int helper_flow_2_1 = fn_R001707_713_2(sec_r001707_2_1, sec_r001707_3_1, pub_r001707_4_1, pub_r001707_5_1);
  int helper_flow_2_2 = fn_R001707_713_2(sec_r001707_2_2, sec_r001707_3_2, pub_r001707_4_2, pub_r001707_5_2);
  fn_R001707_713_2_2(sec_r001707_2_1, sec_r001707_3_1, pub_r001707_4_1, pub_r001707_5_1, sec_r001707_2_2, sec_r001707_3_2, pub_r001707_4_2, pub_r001707_5_2);
  int helper_flow_3_1 = fn_R001707_713_3(sec_r001707_3_1, pub_r001707_4_1, pub_r001707_5_1, pub_r001707_6_1, pub_r001707_7_1);
  int helper_flow_3_2 = fn_R001707_713_3(sec_r001707_3_2, pub_r001707_4_2, pub_r001707_5_2, pub_r001707_6_2, pub_r001707_7_2);
  fn_R001707_713_3_2(sec_r001707_3_1, pub_r001707_4_1, pub_r001707_5_1, pub_r001707_6_1, pub_r001707_7_1, sec_r001707_3_2, pub_r001707_4_2, pub_r001707_5_2, pub_r001707_6_2, pub_r001707_7_2);
  int helper_flow_4_1 = fn_R001707_713_4(sec_r001707_4_1, pub_r001707_5_1, pub_r001707_6_1);
  int helper_flow_4_2 = fn_R001707_713_4(sec_r001707_4_2, pub_r001707_5_2, pub_r001707_6_2);
  fn_R001707_713_4_2(sec_r001707_4_1, pub_r001707_5_1, pub_r001707_6_1, sec_r001707_4_2, pub_r001707_5_2, pub_r001707_6_2);
  int helper_flow_5_1 = fn_R001707_713_5(sec_r001707_5_1, sec_r001707_6_1);
  int helper_flow_5_2 = fn_R001707_713_5(sec_r001707_5_2, sec_r001707_6_2);
  fn_R001707_713_5_2(sec_r001707_5_1, sec_r001707_6_1, sec_r001707_5_2, sec_r001707_6_2);
  int helper_flow_6_1 = fn_R001707_713_6(sec_r001707_6_1, pub_r001707_7_1, pub_r001707_8_1, pub_r001707_9_1);
  int helper_flow_6_2 = fn_R001707_713_6(sec_r001707_6_2, pub_r001707_7_2, pub_r001707_8_2, pub_r001707_9_2);
  fn_R001707_713_6_2(sec_r001707_6_1, pub_r001707_7_1, pub_r001707_8_1, pub_r001707_9_1, sec_r001707_6_2, pub_r001707_7_2, pub_r001707_8_2, pub_r001707_9_2);
  int helper_flow_7_1 = fn_R001707_713_7(sec_r001707_7_1, sec_r001707_8_1, pub_r001707_9_1, pub_r001707_10_1);
  int helper_flow_7_2 = fn_R001707_713_7(sec_r001707_7_2, sec_r001707_8_2, pub_r001707_9_2, pub_r001707_10_2);
  fn_R001707_713_7_2(sec_r001707_7_1, sec_r001707_8_1, pub_r001707_9_1, pub_r001707_10_1, sec_r001707_7_2, sec_r001707_8_2, pub_r001707_9_2, pub_r001707_10_2);
  int helper_flow_8_1 = fn_R001707_713_8(sec_r001707_8_1, pub_r001707_9_1, pub_r001707_10_1, pub_r001707_11_1, pub_r001707_12_1);
  int helper_flow_8_2 = fn_R001707_713_8(sec_r001707_8_2, pub_r001707_9_2, pub_r001707_10_2, pub_r001707_11_2, pub_r001707_12_2);
  fn_R001707_713_8_2(sec_r001707_8_1, pub_r001707_9_1, pub_r001707_10_1, pub_r001707_11_1, pub_r001707_12_1, sec_r001707_8_2, pub_r001707_9_2, pub_r001707_10_2, pub_r001707_11_2, pub_r001707_12_2);
  int helper_flow_9_1 = fn_R001707_713_9(sec_r001707_9_1, sec_r001707_10_1, pub_r001707_11_1, pub_r001707_12_1, pub_r001707_13_1);
  int helper_flow_9_2 = fn_R001707_713_9(sec_r001707_9_2, sec_r001707_10_2, pub_r001707_11_2, pub_r001707_12_2, pub_r001707_13_2);
  fn_R001707_713_9_2(sec_r001707_9_1, sec_r001707_10_1, pub_r001707_11_1, pub_r001707_12_1, pub_r001707_13_1, sec_r001707_9_2, sec_r001707_10_2, pub_r001707_11_2, pub_r001707_12_2, pub_r001707_13_2);
  int helper_flow_10_1 = fn_R001707_713_10(sec_r001707_10_1, sec_r001707_11_1);
  int helper_flow_10_2 = fn_R001707_713_10(sec_r001707_10_2, sec_r001707_11_2);
  fn_R001707_713_10_2(sec_r001707_10_1, sec_r001707_11_1, sec_r001707_10_2, sec_r001707_11_2);
  int stage_v_0_1 = ((pub_r001707_3_1 * 2) + 19) & 63;
  int stage_v_0_2 = ((pub_r001707_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (helper_flow_6_1 ^ pub_r001707_15_1) & 63;
  int stage_v_1_2 = (helper_flow_6_2 ^ pub_r001707_15_2) & 63;
  if ((stage_v_1_1 & 1) != 0)
  {
    if ((sec_r001707_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_1_1 * 2)) & 255;
  }
  if ((stage_v_1_2 & 1) != 0)
  {
    if ((sec_r001707_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_1_2 * 2)) & 255;
  }
  int stage_v_2_1 = (helper_flow_9_1 ^ pub_r001707_14_1) & 63;
  int stage_v_2_2 = (helper_flow_9_2 ^ pub_r001707_14_2) & 63;
  if ((stage_v_2_1 & 1) != 0)
  {
    if ((sec_r001707_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_2_1 * 2)) & 255;
  }
  if ((stage_v_2_2 & 1) != 0)
  {
    if ((sec_r001707_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_2_2 * 2)) & 255;
  }
  int stage_v_3_1 = ((pub_r001707_7_1 * 2) + 5) & 63;
  int stage_v_3_2 = ((pub_r001707_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001707_1_1 * 2) + 38) & 63;
  int stage_v_4_2 = ((pub_r001707_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (helper_flow_0_1 ^ pub_r001707_2_1) & 63;
  int stage_v_5_2 = (helper_flow_0_2 ^ pub_r001707_2_2) & 63;
  if ((stage_v_5_1 & 1) != 0)
  {
    if ((sec_r001707_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_5_1 * 2)) & 255;
  }
  if ((stage_v_5_2 & 1) != 0)
  {
    if ((sec_r001707_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_5_2 * 2)) & 255;
  }
  int stage_v_6_1 = (sec_r001707_21_1 ^ pub_r001707_6_1) & 63;
  int stage_v_6_2 = (sec_r001707_21_2 ^ pub_r001707_6_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((sec_r001707_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_6_1 * 2)) & 255;
  }
  if ((stage_v_6_2 & 1) != 0)
  {
    if ((sec_r001707_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_6_2 * 2)) & 255;
  }
  int stage_v_7_1 = (sec_r001707_3_1 ^ pub_r001707_8_1) & 63;
  int stage_v_7_2 = (sec_r001707_3_2 ^ pub_r001707_8_2) & 63;
  if ((stage_v_7_1 & 1) != 0)
  {
    if ((sec_r001707_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_7_1 * 2)) & 255;
  }
  if ((stage_v_7_2 & 1) != 0)
  {
    if ((sec_r001707_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_7_2 * 2)) & 255;
  }
  int stage_v_8_1 = (helper_flow_6_1 ^ pub_r001707_14_1) & 63;
  int stage_v_8_2 = (helper_flow_6_2 ^ pub_r001707_14_2) & 63;
  if ((stage_v_8_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_8_1 * 2)) & 255;
  }
  if ((stage_v_8_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_8_2 * 2)) & 255;
  }
  int stage_v_9_1 = (helper_flow_2_1 ^ pub_r001707_6_1) & 63;
  int stage_v_9_2 = (helper_flow_2_2 ^ pub_r001707_6_2) & 63;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((sec_r001707_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_9_1 * 2)) & 255;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((sec_r001707_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_9_2 * 2)) & 255;
  }
  int stage_v_10_1 = (sec_r001707_18_1 ^ pub_r001707_3_1) & 63;
  int stage_v_10_2 = (sec_r001707_18_2 ^ pub_r001707_3_2) & 63;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((sec_r001707_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_10_1 * 2)) & 255;
  }
  if ((stage_v_10_2 & 1) != 0)
  {
    if ((sec_r001707_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_10_2 * 2)) & 255;
  }
  int stage_v_11_1 = ((pub_r001707_11_1 * 2) + 11) & 63;
  int stage_v_11_2 = ((pub_r001707_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (sec_r001707_1_1 ^ pub_r001707_9_1) & 63;
  int stage_v_12_2 = (sec_r001707_1_2 ^ pub_r001707_9_2) & 63;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((sec_r001707_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_12_1 * 2)) & 255;
  }
  if ((stage_v_12_2 & 1) != 0)
  {
    if ((sec_r001707_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_12_2 * 2)) & 255;
  }
  int stage_v_13_1 = (sec_r001707_3_1 ^ pub_r001707_9_1) & 63;
  int stage_v_13_2 = (sec_r001707_3_2 ^ pub_r001707_9_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r001707_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_13_1 * 2)) & 255;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r001707_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_13_2 * 2)) & 255;
  }
  int stage_v_14_1 = (sec_r001707_8_1 ^ pub_r001707_12_1) & 63;
  int stage_v_14_2 = (sec_r001707_8_2 ^ pub_r001707_12_2) & 63;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_14_1 * 2)) & 255;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_14_2 * 2)) & 255;
  }
  int stage_v_15_1 = ((pub_r001707_16_1 * 2) + 31) & 63;
  int stage_v_15_2 = ((pub_r001707_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (sec_r001707_8_1 ^ pub_r001707_3_1) & 63;
  int stage_v_16_2 = (sec_r001707_8_2 ^ pub_r001707_3_2) & 63;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_16_1 * 2)) & 255;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((stage_v_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_16_2 * 2)) & 255;
  }
  int stage_v_17_1 = (sec_r001707_18_1 ^ pub_r001707_3_1) & 63;
  int stage_v_17_2 = (sec_r001707_18_2 ^ pub_r001707_3_2) & 63;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_17_1 * 2)) & 255;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_17_2 * 2)) & 255;
  }
  int stage_v_18_1 = (helper_flow_0_1 ^ pub_r001707_14_1) & 63;
  int stage_v_18_2 = (helper_flow_0_2 ^ pub_r001707_14_2) & 63;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r001707_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_18_1 * 2)) & 255;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r001707_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_18_2 * 2)) & 255;
  }
  int stage_v_19_1 = ((pub_r001707_12_1 * 2) + 13) & 63;
  int stage_v_19_2 = ((pub_r001707_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (sec_r001707_7_1 ^ pub_r001707_12_1) & 63;
  int stage_v_20_2 = (sec_r001707_7_2 ^ pub_r001707_12_2) & 63;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r001707_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_20_1 * 2)) & 255;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r001707_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_20_2 * 2)) & 255;
  }
  int stage_v_21_1 = ((pub_r001707_3_1 * 2) + 16) & 63;
  int stage_v_21_2 = ((pub_r001707_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001707_8_1 * 2) + 16) & 63;
  int stage_v_22_2 = ((pub_r001707_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (sec_r001707_11_1 ^ pub_r001707_7_1) & 63;
  int stage_v_23_2 = (sec_r001707_11_2 ^ pub_r001707_7_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r001707_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_23_1 * 2)) & 255;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r001707_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_23_2 * 2)) & 255;
  }
  int stage_v_24_1 = (stage_v_17_1 ^ pub_r001707_0_1) & 63;
  int stage_v_24_2 = (stage_v_17_2 ^ pub_r001707_0_2) & 63;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r001707_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_24_1 * 2)) & 255;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r001707_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_24_2 * 2)) & 255;
  }
  int stage_v_25_1 = ((pub_r001707_3_1 * 2) + 46) & 63;
  int stage_v_25_2 = ((pub_r001707_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (sec_r001707_20_1 ^ pub_r001707_17_1) & 63;
  int stage_v_26_2 = (sec_r001707_20_2 ^ pub_r001707_17_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r001707_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_26_1 * 2)) & 255;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r001707_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_26_2 * 2)) & 255;
  }
  int stage_v_27_1 = (sec_r001707_9_1 ^ pub_r001707_13_1) & 63;
  int stage_v_27_2 = (sec_r001707_9_2 ^ pub_r001707_13_2) & 63;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r001707_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_27_1 * 2)) & 255;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r001707_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_27_2 * 2)) & 255;
  }
  int stage_v_28_1 = (sec_r001707_8_1 ^ pub_r001707_15_1) & 63;
  int stage_v_28_2 = (sec_r001707_8_2 ^ pub_r001707_15_2) & 63;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_28_1 * 2)) & 255;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((stage_v_26_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_28_2 * 2)) & 255;
  }
  int stage_v_29_1 = (stage_v_20_1 ^ pub_r001707_12_1) & 63;
  int stage_v_29_2 = (stage_v_20_2 ^ pub_r001707_12_2) & 63;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r001707_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_29_1 * 2)) & 255;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r001707_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_29_2 * 2)) & 255;
  }
  int stage_v_30_1 = ((pub_r001707_10_1 * 2) + 10) & 63;
  int stage_v_30_2 = ((pub_r001707_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001707_13_1 * 2) + 20) & 63;
  int stage_v_31_2 = ((pub_r001707_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (stage_v_29_1 ^ pub_r001707_10_1) & 63;
  int stage_v_32_2 = (stage_v_29_2 ^ pub_r001707_10_2) & 63;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r001707_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_32_1 * 2)) & 255;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r001707_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_32_2 * 2)) & 255;
  }
  int stage_v_33_1 = ((pub_r001707_8_1 * 2) + 32) & 63;
  int stage_v_33_2 = ((pub_r001707_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (sec_r001707_20_1 ^ pub_r001707_4_1) & 63;
  int stage_v_34_2 = (sec_r001707_20_2 ^ pub_r001707_4_2) & 63;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_34_1 * 2)) & 255;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_34_2 * 2)) & 255;
  }
  int stage_v_35_1 = (sec_r001707_18_1 ^ pub_r001707_5_1) & 63;
  int stage_v_35_2 = (sec_r001707_18_2 ^ pub_r001707_5_2) & 63;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_35_1 * 2)) & 255;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((stage_v_32_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_35_2 * 2)) & 255;
  }
  int stage_v_36_1 = ((pub_r001707_10_1 * 2) + 45) & 63;
  int stage_v_36_2 = ((pub_r001707_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (stage_v_29_1 ^ pub_r001707_14_1) & 63;
  int stage_v_37_2 = (stage_v_29_2 ^ pub_r001707_14_2) & 63;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_37_1 * 2)) & 255;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_37_2 * 2)) & 255;
  }
  int stage_v_38_1 = (stage_v_28_1 ^ pub_r001707_9_1) & 63;
  int stage_v_38_2 = (stage_v_28_2 ^ pub_r001707_9_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_38_1 * 2)) & 255;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_38_2 * 2)) & 255;
  }
  int stage_v_39_1 = (stage_v_23_1 ^ pub_r001707_4_1) & 63;
  int stage_v_39_2 = (stage_v_23_2 ^ pub_r001707_4_2) & 63;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_39_1 * 2)) & 255;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((stage_v_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_39_2 * 2)) & 255;
  }
  int stage_v_40_1 = (helper_flow_3_1 ^ pub_r001707_15_1) & 63;
  int stage_v_40_2 = (helper_flow_3_2 ^ pub_r001707_15_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_40_1 * 2)) & 255;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((stage_v_28_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_40_2 * 2)) & 255;
  }
  int stage_v_41_1 = ((pub_r001707_4_1 * 2) + 30) & 63;
  int stage_v_41_2 = ((pub_r001707_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (helper_flow_1_1 ^ pub_r001707_17_1) & 63;
  int stage_v_42_2 = (helper_flow_1_2 ^ pub_r001707_17_2) & 63;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_42_1 * 2)) & 255;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((stage_v_38_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_42_2 * 2)) & 255;
  }
  int stage_v_43_1 = ((pub_r001707_1_1 * 2) + 22) & 63;
  int stage_v_43_2 = ((pub_r001707_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001707_15_1 * 2) + 31) & 63;
  int stage_v_44_2 = ((pub_r001707_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001707_16_1 * 2) + 28) & 63;
  int stage_v_45_2 = ((pub_r001707_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (stage_v_35_1 ^ pub_r001707_7_1) & 63;
  int stage_v_46_2 = (stage_v_35_2 ^ pub_r001707_7_2) & 63;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r001707_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_46_1 * 2)) & 255;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r001707_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_46_2 * 2)) & 255;
  }
  int stage_v_47_1 = ((pub_r001707_13_1 * 2) + 35) & 63;
  int stage_v_47_2 = ((pub_r001707_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (stage_v_13_1 ^ pub_r001707_6_1) & 63;
  int stage_v_48_2 = (stage_v_13_2 ^ pub_r001707_6_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r001707_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_48_1 * 2)) & 255;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r001707_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_48_2 * 2)) & 255;
  }
  int stage_v_49_1 = (helper_flow_4_1 ^ pub_r001707_11_1) & 63;
  int stage_v_49_2 = (helper_flow_4_2 ^ pub_r001707_11_2) & 63;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r001707_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_49_1 * 2)) & 255;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r001707_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_49_2 * 2)) & 255;
  }
  int stage_v_50_1 = ((pub_r001707_15_1 * 2) + 46) & 63;
  int stage_v_50_2 = ((pub_r001707_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (sec_r001707_14_1 ^ pub_r001707_4_1) & 63;
  int stage_v_51_2 = (sec_r001707_14_2 ^ pub_r001707_4_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r001707_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_51_1 * 2)) & 255;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r001707_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_51_2 * 2)) & 255;
  }
  int stage_v_52_1 = (stage_v_17_1 ^ pub_r001707_3_1) & 63;
  int stage_v_52_2 = (stage_v_17_2 ^ pub_r001707_3_2) & 63;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_52_1 * 2)) & 255;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_52_2 * 2)) & 255;
  }
  int stage_v_53_1 = (helper_flow_9_1 ^ pub_r001707_11_1) & 63;
  int stage_v_53_2 = (helper_flow_9_2 ^ pub_r001707_11_2) & 63;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_53_1 * 2)) & 255;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((stage_v_38_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_53_2 * 2)) & 255;
  }
  int stage_v_54_1 = (stage_v_5_1 ^ pub_r001707_2_1) & 63;
  int stage_v_54_2 = (stage_v_5_2 ^ pub_r001707_2_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_54_1 * 2)) & 255;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_54_2 * 2)) & 255;
  }
  int stage_v_55_1 = (helper_flow_8_1 ^ pub_r001707_16_1) & 63;
  int stage_v_55_2 = (helper_flow_8_2 ^ pub_r001707_16_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r001707_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_55_1 * 2)) & 255;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r001707_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_55_2 * 2)) & 255;
  }
  int stage_v_56_1 = (stage_v_52_1 ^ pub_r001707_16_1) & 63;
  int stage_v_56_2 = (stage_v_52_2 ^ pub_r001707_16_2) & 63;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r001707_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_56_1 * 2)) & 255;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r001707_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_56_2 * 2)) & 255;
  }
  int stage_v_57_1 = ((pub_r001707_4_1 * 2) + 40) & 63;
  int stage_v_57_2 = ((pub_r001707_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001707_15_1 * 2) + 23) & 63;
  int stage_v_58_2 = ((pub_r001707_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001707_15_1 * 2) + 46) & 63;
  int stage_v_59_2 = ((pub_r001707_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001707_9_1 * 2) + 16) & 63;
  int stage_v_60_2 = ((pub_r001707_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (helper_flow_9_1 ^ pub_r001707_17_1) & 63;
  int stage_v_61_2 = (helper_flow_9_2 ^ pub_r001707_17_2) & 63;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((stage_v_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  }
  int stage_v_62_1 = (stage_v_14_1 ^ pub_r001707_15_1) & 63;
  int stage_v_62_2 = (stage_v_14_2 ^ pub_r001707_15_2) & 63;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r001707_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_62_1 * 2)) & 255;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r001707_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_62_2 * 2)) & 255;
  }
  int stage_v_63_1 = (stage_v_38_1 ^ pub_r001707_6_1) & 63;
  int stage_v_63_2 = (stage_v_38_2 ^ pub_r001707_6_2) & 63;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r001707_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_63_1 * 2)) & 255;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r001707_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_63_2 * 2)) & 255;
  }
  int stage_v_64_1 = (sec_r001707_6_1 ^ pub_r001707_7_1) & 63;
  int stage_v_64_2 = (sec_r001707_6_2 ^ pub_r001707_7_2) & 63;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_64_1 * 2)) & 255;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((stage_v_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_64_2 * 2)) & 255;
  }
  int stage_v_65_1 = (sec_r001707_14_1 ^ pub_r001707_9_1) & 63;
  int stage_v_65_2 = (sec_r001707_14_2 ^ pub_r001707_9_2) & 63;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_65_1 * 2)) & 255;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_65_2 * 2)) & 255;
  }
  int stage_v_66_1 = (stage_v_35_1 ^ pub_r001707_17_1) & 63;
  int stage_v_66_2 = (stage_v_35_2 ^ pub_r001707_17_2) & 63;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((stage_v_56_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_66_1 * 2)) & 255;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((stage_v_56_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_66_2 * 2)) & 255;
  }
  int stage_v_67_1 = (sec_r001707_16_1 ^ pub_r001707_15_1) & 63;
  int stage_v_67_2 = (sec_r001707_16_2 ^ pub_r001707_15_2) & 63;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_67_1 * 2)) & 255;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_67_2 * 2)) & 255;
  }
  int stage_v_68_1 = (stage_v_24_1 ^ pub_r001707_9_1) & 63;
  int stage_v_68_2 = (stage_v_24_2 ^ pub_r001707_9_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((stage_v_27_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  }
  int stage_v_69_1 = (stage_v_66_1 ^ pub_r001707_16_1) & 63;
  int stage_v_69_2 = (stage_v_66_2 ^ pub_r001707_16_2) & 63;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r001707_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r001707_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  }
  int stage_v_70_1 = (sec_r001707_19_1 ^ pub_r001707_11_1) & 63;
  int stage_v_70_2 = (sec_r001707_19_2 ^ pub_r001707_11_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((stage_v_37_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((stage_v_37_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  }
  int stage_v_71_1 = (stage_v_64_1 ^ pub_r001707_8_1) & 63;
  int stage_v_71_2 = (stage_v_64_2 ^ pub_r001707_8_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((stage_v_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  }
  int stage_v_72_1 = (stage_v_39_1 ^ pub_r001707_7_1) & 63;
  int stage_v_72_2 = (stage_v_39_2 ^ pub_r001707_7_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  }
  int stage_v_73_1 = ((pub_r001707_12_1 * 2) + 47) & 63;
  int stage_v_73_2 = ((pub_r001707_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001707_1_1 * 2) + 46) & 63;
  int stage_v_74_2 = ((pub_r001707_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (stage_v_63_1 ^ pub_r001707_1_1) & 63;
  int stage_v_75_2 = (stage_v_63_2 ^ pub_r001707_1_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((stage_v_70_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((stage_v_70_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  }
  int stage_v_76_1 = (stage_v_2_1 ^ pub_r001707_11_1) & 63;
  int stage_v_76_2 = (stage_v_2_2 ^ pub_r001707_11_2) & 63;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((stage_v_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  }
  int stage_v_77_1 = (helper_flow_3_1 ^ pub_r001707_14_1) & 63;
  int stage_v_77_2 = (helper_flow_3_2 ^ pub_r001707_14_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((stage_v_69_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((stage_v_69_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  }
  int stage_v_78_1 = (sec_r001707_7_1 ^ pub_r001707_4_1) & 63;
  int stage_v_78_2 = (sec_r001707_7_2 ^ pub_r001707_4_2) & 63;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r001707_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r001707_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  }
  int stage_v_79_1 = (sec_r001707_16_1 ^ pub_r001707_8_1) & 63;
  int stage_v_79_2 = (sec_r001707_16_2 ^ pub_r001707_8_2) & 63;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((stage_v_62_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((stage_v_62_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  }
  int stage_v_80_1 = (sec_r001707_13_1 ^ pub_r001707_8_1) & 63;
  int stage_v_80_2 = (sec_r001707_13_2 ^ pub_r001707_8_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((stage_v_46_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((stage_v_46_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  }
  int stage_v_81_1 = ((pub_r001707_17_1 * 2) + 22) & 63;
  int stage_v_81_2 = ((pub_r001707_17_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001707_10_1 * 2) + 39) & 63;
  int stage_v_82_2 = ((pub_r001707_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (helper_flow_3_1 ^ pub_r001707_16_1) & 63;
  int stage_v_83_2 = (helper_flow_3_2 ^ pub_r001707_16_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r001707_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r001707_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  }
  int stage_v_84_1 = ((pub_r001707_2_1 * 2) + 24) & 63;
  int stage_v_84_2 = ((pub_r001707_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (sec_r001707_5_1 ^ pub_r001707_7_1) & 63;
  int stage_v_85_2 = (sec_r001707_5_2 ^ pub_r001707_7_2) & 63;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((stage_v_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((stage_v_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  }
  int stage_v_86_1 = (stage_v_23_1 ^ pub_r001707_16_1) & 63;
  int stage_v_86_2 = (stage_v_23_2 ^ pub_r001707_16_2) & 63;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r001707_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r001707_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  }
  int stage_v_87_1 = (stage_v_68_1 ^ pub_r001707_12_1) & 63;
  int stage_v_87_2 = (stage_v_68_2 ^ pub_r001707_12_2) & 63;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r001707_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r001707_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  }
  int stage_v_88_1 = ((pub_r001707_9_1 * 2) + 27) & 63;
  int stage_v_88_2 = ((pub_r001707_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (sec_r001707_13_1 ^ pub_r001707_4_1) & 63;
  int stage_v_89_2 = (sec_r001707_13_2 ^ pub_r001707_4_2) & 63;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((helper_flow_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  }
  int stage_v_90_1 = (stage_v_86_1 ^ pub_r001707_16_1) & 63;
  int stage_v_90_2 = (stage_v_86_2 ^ pub_r001707_16_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r001707_22_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r001707_22_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  }
  int stage_v_91_1 = ((pub_r001707_15_1 * 2) + 8) & 63;
  int stage_v_91_2 = ((pub_r001707_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (sec_r001707_9_1 ^ pub_r001707_7_1) & 63;
  int stage_v_92_2 = (sec_r001707_9_2 ^ pub_r001707_7_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((helper_flow_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  }
  int stage_v_93_1 = (sec_r001707_12_1 ^ pub_r001707_11_1) & 63;
  int stage_v_93_2 = (sec_r001707_12_2 ^ pub_r001707_11_2) & 63;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r001707_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r001707_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  }
  int stage_v_94_1 = ((pub_r001707_10_1 * 2) + 41) & 63;
  int stage_v_94_2 = ((pub_r001707_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (stage_v_7_1 ^ pub_r001707_1_1) & 63;
  int stage_v_95_2 = (stage_v_7_2 ^ pub_r001707_1_2) & 63;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((stage_v_27_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  }
  int stage_v_96_1 = (sec_r001707_12_1 ^ pub_r001707_15_1) & 63;
  int stage_v_96_2 = (sec_r001707_12_2 ^ pub_r001707_15_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((stage_v_38_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  }
  int stage_v_97_1 = ((pub_r001707_2_1 * 2) + 37) & 63;
  int stage_v_97_2 = ((pub_r001707_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (stage_v_37_1 ^ pub_r001707_0_1) & 63;
  int stage_v_98_2 = (stage_v_37_2 ^ pub_r001707_0_2) & 63;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  }
  int stage_v_99_1 = (stage_v_87_1 ^ pub_r001707_12_1) & 63;
  int stage_v_99_2 = (stage_v_87_2 ^ pub_r001707_12_2) & 63;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((stage_v_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  }
  int stage_v_100_1 = ((pub_r001707_17_1 * 2) + 39) & 63;
  int stage_v_100_2 = ((pub_r001707_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (stage_v_6_1 ^ pub_r001707_6_1) & 63;
  int stage_v_101_2 = (stage_v_6_2 ^ pub_r001707_6_2) & 63;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  }
  int stage_v_102_1 = ((pub_r001707_17_1 * 2) + 18) & 63;
  int stage_v_102_2 = ((pub_r001707_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (stage_v_12_1 ^ pub_r001707_9_1) & 63;
  int stage_v_103_2 = (stage_v_12_2 ^ pub_r001707_9_2) & 63;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  }
  int stage_v_104_1 = ((pub_r001707_3_1 * 2) + 22) & 63;
  int stage_v_104_2 = ((pub_r001707_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (helper_flow_10_1 ^ pub_r001707_11_1) & 63;
  int stage_v_105_2 = (helper_flow_10_2 ^ pub_r001707_11_2) & 63;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r001707_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r001707_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  }
  int stage_v_106_1 = (stage_v_98_1 ^ pub_r001707_15_1) & 63;
  int stage_v_106_2 = (stage_v_98_2 ^ pub_r001707_15_2) & 63;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  }
  int stage_v_107_1 = (stage_v_9_1 ^ pub_r001707_7_1) & 63;
  int stage_v_107_2 = (stage_v_9_2 ^ pub_r001707_7_2) & 63;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((stage_v_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  }
  int stage_v_108_1 = (helper_flow_7_1 ^ pub_r001707_7_1) & 63;
  int stage_v_108_2 = (helper_flow_7_2 ^ pub_r001707_7_2) & 63;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((stage_v_24_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((stage_v_24_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  }
  int stage_v_109_1 = (stage_v_99_1 ^ pub_r001707_2_1) & 63;
  int stage_v_109_2 = (stage_v_99_2 ^ pub_r001707_2_2) & 63;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((stage_v_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((stage_v_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  }
  int stage_v_110_1 = ((pub_r001707_0_1 * 2) + 34) & 63;
  int stage_v_110_2 = ((pub_r001707_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (stage_v_92_1 ^ pub_r001707_8_1) & 63;
  int stage_v_111_2 = (stage_v_92_2 ^ pub_r001707_8_2) & 63;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((stage_v_108_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((stage_v_108_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  }
  int stage_v_112_1 = (stage_v_51_1 ^ pub_r001707_12_1) & 63;
  int stage_v_112_2 = (stage_v_51_2 ^ pub_r001707_12_2) & 63;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  }
  int stage_v_113_1 = (stage_v_34_1 ^ pub_r001707_5_1) & 63;
  int stage_v_113_2 = (stage_v_34_2 ^ pub_r001707_5_2) & 63;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((stage_v_63_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((stage_v_63_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  }
  int stage_v_114_1 = (sec_r001707_3_1 ^ pub_r001707_11_1) & 63;
  int stage_v_114_2 = (sec_r001707_3_2 ^ pub_r001707_11_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r001707_22_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r001707_22_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  }
  int stage_v_115_1 = ((pub_r001707_11_1 * 2) + 39) & 63;
  int stage_v_115_2 = ((pub_r001707_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (stage_v_8_1 ^ pub_r001707_6_1) & 63;
  int stage_v_116_2 = (stage_v_8_2 ^ pub_r001707_6_2) & 63;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  }
  int stage_v_117_1 = ((pub_r001707_0_1 * 2) + 25) & 63;
  int stage_v_117_2 = ((pub_r001707_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001707_8_1 * 2) + 30) & 63;
  int stage_v_118_2 = ((pub_r001707_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001707_9_1 * 2) + 49) & 63;
  int stage_v_119_2 = ((pub_r001707_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001707_1_1 * 2) + 26) & 63;
  int stage_v_120_2 = ((pub_r001707_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001707_2_1 * 2) + 7) & 63;
  int stage_v_121_2 = ((pub_r001707_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (stage_v_111_1 ^ pub_r001707_13_1) & 63;
  int stage_v_122_2 = (stage_v_111_2 ^ pub_r001707_13_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((stage_v_66_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  }
  int stage_v_123_1 = ((pub_r001707_17_1 * 2) + 19) & 63;
  int stage_v_123_2 = ((pub_r001707_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (stage_v_10_1 ^ pub_r001707_17_1) & 63;
  int stage_v_124_2 = (stage_v_10_2 ^ pub_r001707_17_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((stage_v_34_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  }
  int stage_v_125_1 = (sec_r001707_11_1 ^ pub_r001707_0_1) & 63;
  int stage_v_125_2 = (sec_r001707_11_2 ^ pub_r001707_0_2) & 63;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((stage_v_46_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((stage_v_46_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  }
  int stage_v_126_1 = (sec_r001707_13_1 ^ pub_r001707_0_1) & 63;
  int stage_v_126_2 = (sec_r001707_13_2 ^ pub_r001707_0_2) & 63;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  }
  int stage_v_127_1 = ((pub_r001707_14_1 * 2) + 43) & 63;
  int stage_v_127_2 = ((pub_r001707_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (stage_v_95_1 ^ pub_r001707_2_1) & 63;
  int stage_v_128_2 = (stage_v_95_2 ^ pub_r001707_2_2) & 63;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((sec_r001707_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((sec_r001707_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  }
  int stage_v_129_1 = (stage_v_114_1 ^ pub_r001707_11_1) & 63;
  int stage_v_129_2 = (stage_v_114_2 ^ pub_r001707_11_2) & 63;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((sec_r001707_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  }
  if ((stage_v_129_2 & 1) != 0)
  {
    if ((sec_r001707_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  }
  int stage_v_130_1 = ((pub_r001707_5_1 * 2) + 5) & 63;
  int stage_v_130_2 = ((pub_r001707_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001707_17_1 * 2) + 45) & 63;
  int stage_v_131_2 = ((pub_r001707_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001707_10_1 * 2) + 35) & 63;
  int stage_v_132_2 = ((pub_r001707_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001707_6_1 * 2) + 38) & 63;
  int stage_v_133_2 = ((pub_r001707_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001707_13_1 * 2) + 13) & 63;
  int stage_v_134_2 = ((pub_r001707_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (stage_v_101_1 ^ pub_r001707_12_1) & 63;
  int stage_v_135_2 = (stage_v_101_2 ^ pub_r001707_12_2) & 63;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  }
  if ((stage_v_135_2 & 1) != 0)
  {
    if ((stage_v_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  }
  int stage_v_136_1 = (stage_v_64_1 ^ pub_r001707_3_1) & 63;
  int stage_v_136_2 = (stage_v_64_2 ^ pub_r001707_3_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((stage_v_93_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((stage_v_93_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  }
  int stage_v_137_1 = ((pub_r001707_8_1 * 2) + 33) & 63;
  int stage_v_137_2 = ((pub_r001707_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001707_4_1 * 2) + 5) & 63;
  int stage_v_138_2 = ((pub_r001707_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001707_5_1 * 2) + 43) & 63;
  int stage_v_139_2 = ((pub_r001707_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001707_0_1 * 2) + 43) & 63;
  int stage_v_140_2 = ((pub_r001707_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (helper_flow_5_1 ^ pub_r001707_16_1) & 63;
  int stage_v_141_2 = (helper_flow_5_2 ^ pub_r001707_16_2) & 63;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((sec_r001707_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  }
  if ((stage_v_141_2 & 1) != 0)
  {
    if ((sec_r001707_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  }
  int stage_v_142_1 = (stage_v_5_1 ^ pub_r001707_1_1) & 63;
  int stage_v_142_2 = (stage_v_5_2 ^ pub_r001707_1_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  }
  if ((stage_v_142_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  }
  int stage_v_143_1 = ((pub_r001707_13_1 * 2) + 23) & 63;
  int stage_v_143_2 = ((pub_r001707_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (stage_v_77_1 ^ pub_r001707_17_1) & 63;
  int stage_v_144_2 = (stage_v_77_2 ^ pub_r001707_17_2) & 63;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((stage_v_65_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  }
  if ((stage_v_144_2 & 1) != 0)
  {
    if ((stage_v_65_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  }
  int stage_v_145_1 = (stage_v_49_1 ^ pub_r001707_15_1) & 63;
  int stage_v_145_2 = (stage_v_49_2 ^ pub_r001707_15_2) & 63;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((stage_v_114_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((stage_v_114_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  }
  int stage_v_146_1 = (stage_v_92_1 ^ pub_r001707_3_1) & 63;
  int stage_v_146_2 = (stage_v_92_2 ^ pub_r001707_3_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((stage_v_62_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  }
  if ((stage_v_146_2 & 1) != 0)
  {
    if ((stage_v_62_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  }
  int stage_v_147_1 = (stage_v_35_1 ^ pub_r001707_3_1) & 63;
  int stage_v_147_2 = (stage_v_35_2 ^ pub_r001707_3_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  }
  if ((stage_v_147_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  }
  int stage_v_148_1 = (stage_v_70_1 ^ pub_r001707_12_1) & 63;
  int stage_v_148_2 = (stage_v_70_2 ^ pub_r001707_12_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  }
  if ((stage_v_148_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  }
  int stage_v_149_1 = ((pub_r001707_9_1 * 2) + 11) & 63;
  int stage_v_149_2 = ((pub_r001707_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (stage_v_72_1 ^ pub_r001707_11_1) & 63;
  int stage_v_150_2 = (stage_v_72_2 ^ pub_r001707_11_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((sec_r001707_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((sec_r001707_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  }
  int stage_v_151_1 = (stage_v_83_1 ^ pub_r001707_10_1) & 63;
  int stage_v_151_2 = (stage_v_83_2 ^ pub_r001707_10_2) & 63;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((sec_r001707_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  }
  if ((stage_v_151_2 & 1) != 0)
  {
    if ((sec_r001707_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  }
  int stage_v_152_1 = (stage_v_67_1 ^ pub_r001707_6_1) & 63;
  int stage_v_152_2 = (stage_v_67_2 ^ pub_r001707_6_2) & 63;
  if ((stage_v_152_1 & 1) != 0)
  {
    if ((stage_v_128_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  }
  if ((stage_v_152_2 & 1) != 0)
  {
    if ((stage_v_128_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  }
  int stage_v_153_1 = (stage_v_65_1 ^ pub_r001707_3_1) & 63;
  int stage_v_153_2 = (stage_v_65_2 ^ pub_r001707_3_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((stage_v_78_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  }
  if ((stage_v_153_2 & 1) != 0)
  {
    if ((stage_v_78_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  }
  int stage_v_154_1 = (sec_r001707_21_1 ^ pub_r001707_0_1) & 63;
  int stage_v_154_2 = (sec_r001707_21_2 ^ pub_r001707_0_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((stage_v_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  }
  if ((stage_v_154_2 & 1) != 0)
  {
    if ((stage_v_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  }
  int stage_v_155_1 = (stage_v_90_1 ^ pub_r001707_9_1) & 63;
  int stage_v_155_2 = (stage_v_90_2 ^ pub_r001707_9_2) & 63;
  if ((stage_v_155_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  }
  if ((stage_v_155_2 & 1) != 0)
  {
    if ((stage_v_34_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  }
  int stage_v_156_1 = (stage_v_7_1 ^ pub_r001707_0_1) & 63;
  int stage_v_156_2 = (stage_v_7_2 ^ pub_r001707_0_2) & 63;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  }
  if ((stage_v_156_2 & 1) != 0)
  {
    if ((stage_v_80_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  }
  int stage_v_157_1 = (stage_v_93_1 ^ pub_r001707_9_1) & 63;
  int stage_v_157_2 = (stage_v_93_2 ^ pub_r001707_9_2) & 63;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((stage_v_145_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  }
  if ((stage_v_157_2 & 1) != 0)
  {
    if ((stage_v_145_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  }
  int stage_v_158_1 = (stage_v_125_1 ^ pub_r001707_15_1) & 63;
  int stage_v_158_2 = (stage_v_125_2 ^ pub_r001707_15_2) & 63;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((stage_v_29_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  }
  if ((stage_v_158_2 & 1) != 0)
  {
    if ((stage_v_29_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  }
  int stage_v_159_1 = (stage_v_129_1 ^ pub_r001707_5_1) & 63;
  int stage_v_159_2 = (stage_v_129_2 ^ pub_r001707_5_2) & 63;
  if ((stage_v_159_1 & 1) != 0)
  {
    if ((stage_v_79_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_159_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  }
  if ((stage_v_159_2 & 1) != 0)
  {
    if ((stage_v_79_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_159_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  }
  int stage_v_160_1 = ((pub_r001707_12_1 * 2) + 19) & 63;
  int stage_v_160_2 = ((pub_r001707_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001707_12_1 * 2) + 45) & 63;
  int stage_v_161_2 = ((pub_r001707_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001707_14_1 * 2) + 21) & 63;
  int stage_v_162_2 = ((pub_r001707_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (sec_r001707_2_1 ^ pub_r001707_16_1) & 63;
  int stage_v_163_2 = (sec_r001707_2_2 ^ pub_r001707_16_2) & 63;
  if ((stage_v_163_1 & 1) != 0)
  {
    if ((stage_v_85_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  }
  if ((stage_v_163_2 & 1) != 0)
  {
    if ((stage_v_85_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  }
  int stage_v_164_1 = (stage_v_93_1 ^ pub_r001707_8_1) & 63;
  int stage_v_164_2 = (stage_v_93_2 ^ pub_r001707_8_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((sec_r001707_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  }
  if ((stage_v_164_2 & 1) != 0)
  {
    if ((sec_r001707_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  }
  int stage_v_165_1 = (stage_v_93_1 ^ pub_r001707_8_1) & 63;
  int stage_v_165_2 = (stage_v_93_2 ^ pub_r001707_8_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  }
  if ((stage_v_165_2 & 1) != 0)
  {
    if ((stage_v_28_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  }
  int stage_v_166_1 = (stage_v_64_1 ^ pub_r001707_4_1) & 63;
  int stage_v_166_2 = (stage_v_64_2 ^ pub_r001707_4_2) & 63;
  if ((stage_v_166_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_166_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  }
  if ((stage_v_166_2 & 1) != 0)
  {
    if ((stage_v_80_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_166_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  }
  int stage_v_167_1 = (stage_v_111_1 ^ pub_r001707_4_1) & 63;
  int stage_v_167_2 = (stage_v_111_2 ^ pub_r001707_4_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((stage_v_103_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_167_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  }
  if ((stage_v_167_2 & 1) != 0)
  {
    if ((stage_v_103_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_167_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  }
  int stage_v_168_1 = ((pub_r001707_12_1 * 2) + 8) & 63;
  int stage_v_168_2 = ((pub_r001707_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (stage_v_152_1 ^ pub_r001707_0_1) & 63;
  int stage_v_169_2 = (stage_v_152_2 ^ pub_r001707_0_2) & 63;
  if ((stage_v_169_1 & 1) != 0)
  {
    if ((stage_v_150_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  }
  if ((stage_v_169_2 & 1) != 0)
  {
    if ((stage_v_150_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  }
  int stage_v_170_1 = (stage_v_38_1 ^ pub_r001707_3_1) & 63;
  int stage_v_170_2 = (stage_v_38_2 ^ pub_r001707_3_2) & 63;
  if ((stage_v_170_1 & 1) != 0)
  {
    if ((sec_r001707_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_170_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  }
  if ((stage_v_170_2 & 1) != 0)
  {
    if ((sec_r001707_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_170_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  }
  int stage_v_171_1 = (sec_r001707_18_1 ^ pub_r001707_2_1) & 63;
  int stage_v_171_2 = (sec_r001707_18_2 ^ pub_r001707_2_2) & 63;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_171_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  }
  if ((stage_v_171_2 & 1) != 0)
  {
    if ((stage_v_28_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_171_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  }
  int stage_v_172_1 = ((pub_r001707_9_1 * 2) + 14) & 63;
  int stage_v_172_2 = ((pub_r001707_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001707_17_1 * 2) + 29) & 63;
  int stage_v_173_2 = ((pub_r001707_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (stage_v_23_1 ^ pub_r001707_17_1) & 63;
  int stage_v_174_2 = (stage_v_23_2 ^ pub_r001707_17_2) & 63;
  if ((stage_v_174_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_174_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  }
  if ((stage_v_174_2 & 1) != 0)
  {
    if ((helper_flow_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_174_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  }
  int stage_v_175_1 = (helper_flow_10_1 ^ pub_r001707_6_1) & 63;
  int stage_v_175_2 = (helper_flow_10_2 ^ pub_r001707_6_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((stage_v_145_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_175_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  }
  if ((stage_v_175_2 & 1) != 0)
  {
    if ((stage_v_145_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_175_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  }
  int stage_v_176_1 = ((pub_r001707_16_1 * 2) + 15) & 63;
  int stage_v_176_2 = ((pub_r001707_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (stage_v_144_1 ^ pub_r001707_7_1) & 63;
  int stage_v_177_2 = (stage_v_144_2 ^ pub_r001707_7_2) & 63;
  if ((stage_v_177_1 & 1) != 0)
  {
    if ((stage_v_144_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_177_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  }
  if ((stage_v_177_2 & 1) != 0)
  {
    if ((stage_v_144_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_177_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  }
  int stage_v_178_1 = (sec_r001707_8_1 ^ pub_r001707_11_1) & 63;
  int stage_v_178_2 = (sec_r001707_8_2 ^ pub_r001707_11_2) & 63;
  if ((stage_v_178_1 & 1) != 0)
  {
    if ((stage_v_70_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_178_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  }
  if ((stage_v_178_2 & 1) != 0)
  {
    if ((stage_v_70_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_178_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  }
  int stage_v_179_1 = ((pub_r001707_4_1 * 2) + 23) & 63;
  int stage_v_179_2 = ((pub_r001707_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (stage_v_85_1 ^ pub_r001707_3_1) & 63;
  int stage_v_180_2 = (stage_v_85_2 ^ pub_r001707_3_2) & 63;
  if ((stage_v_180_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_180_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  }
  if ((stage_v_180_2 & 1) != 0)
  {
    if ((stage_v_32_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_180_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  }
  int stage_v_181_1 = ((pub_r001707_17_1 * 2) + 6) & 63;
  int stage_v_181_2 = ((pub_r001707_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (stage_v_135_1 ^ pub_r001707_10_1) & 63;
  int stage_v_182_2 = (stage_v_135_2 ^ pub_r001707_10_2) & 63;
  if ((stage_v_182_1 & 1) != 0)
  {
    if ((stage_v_103_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_182_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  }
  if ((stage_v_182_2 & 1) != 0)
  {
    if ((stage_v_103_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_182_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  }
  int stage_v_183_1 = (stage_v_29_1 ^ pub_r001707_15_1) & 63;
  int stage_v_183_2 = (stage_v_29_2 ^ pub_r001707_15_2) & 63;
  if ((stage_v_183_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_183_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  }
  if ((stage_v_183_2 & 1) != 0)
  {
    if ((stage_v_26_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_183_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  }
  int stage_v_184_1 = (stage_v_114_1 ^ pub_r001707_17_1) & 63;
  int stage_v_184_2 = (stage_v_114_2 ^ pub_r001707_17_2) & 63;
  if ((stage_v_184_1 & 1) != 0)
  {
    if ((stage_v_42_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_184_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  }
  if ((stage_v_184_2 & 1) != 0)
  {
    if ((stage_v_42_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_184_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  }
  int stage_v_185_1 = (stage_v_164_1 ^ pub_r001707_5_1) & 63;
  int stage_v_185_2 = (stage_v_164_2 ^ pub_r001707_5_2) & 63;
  if ((stage_v_185_1 & 1) != 0)
  {
    if ((stage_v_170_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_185_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  }
  if ((stage_v_185_2 & 1) != 0)
  {
    if ((stage_v_170_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_185_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  }
  int stage_v_186_1 = (stage_v_146_1 ^ pub_r001707_4_1) & 63;
  int stage_v_186_2 = (stage_v_146_2 ^ pub_r001707_4_2) & 63;
  if ((stage_v_186_1 & 1) != 0)
  {
    if ((stage_v_156_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_186_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  }
  if ((stage_v_186_2 & 1) != 0)
  {
    if ((stage_v_156_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_186_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  }
  int stage_v_187_1 = ((pub_r001707_1_1 * 2) + 23) & 63;
  int stage_v_187_2 = ((pub_r001707_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (helper_flow_6_1 ^ pub_r001707_9_1) & 63;
  int stage_v_188_2 = (helper_flow_6_2 ^ pub_r001707_9_2) & 63;
  if ((stage_v_188_1 & 1) != 0)
  {
    if ((sec_r001707_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_188_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  }
  if ((stage_v_188_2 & 1) != 0)
  {
    if ((sec_r001707_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_188_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  }
  int stage_v_189_1 = ((pub_r001707_13_1 * 2) + 11) & 63;
  int stage_v_189_2 = ((pub_r001707_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (stage_v_10_1 ^ pub_r001707_13_1) & 63;
  int stage_v_190_2 = (stage_v_10_2 ^ pub_r001707_13_2) & 63;
  if ((stage_v_190_1 & 1) != 0)
  {
    if ((stage_v_96_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_190_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  }
  if ((stage_v_190_2 & 1) != 0)
  {
    if ((stage_v_96_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_190_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  }
  int stage_v_191_1 = (stage_v_28_1 ^ pub_r001707_9_1) & 63;
  int stage_v_191_2 = (stage_v_28_2 ^ pub_r001707_9_2) & 63;
  if ((stage_v_191_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_191_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  }
  if ((stage_v_191_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_191_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  }
  int stage_v_192_1 = (stage_v_14_1 ^ pub_r001707_10_1) & 63;
  int stage_v_192_2 = (stage_v_14_2 ^ pub_r001707_10_2) & 63;
  if ((stage_v_192_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_192_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  }
  if ((stage_v_192_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_192_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  }
  int stage_v_193_1 = ((pub_r001707_3_1 * 2) + 8) & 63;
  int stage_v_193_2 = ((pub_r001707_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001707_0_1 * 2) + 10) & 63;
  int stage_v_194_2 = ((pub_r001707_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (stage_v_148_1 ^ pub_r001707_10_1) & 63;
  int stage_v_195_2 = (stage_v_148_2 ^ pub_r001707_10_2) & 63;
  if ((stage_v_195_1 & 1) != 0)
  {
    if ((stage_v_144_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_195_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  }
  if ((stage_v_195_2 & 1) != 0)
  {
    if ((stage_v_144_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_195_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  }
  int stage_v_196_1 = (stage_v_125_1 ^ pub_r001707_11_1) & 63;
  int stage_v_196_2 = (stage_v_125_2 ^ pub_r001707_11_2) & 63;
  if ((stage_v_196_1 & 1) != 0)
  {
    if ((stage_v_165_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_196_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  }
  if ((stage_v_196_2 & 1) != 0)
  {
    if ((stage_v_165_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_196_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  }
  int stage_v_197_1 = (stage_v_124_1 ^ pub_r001707_1_1) & 63;
  int stage_v_197_2 = (stage_v_124_2 ^ pub_r001707_1_2) & 63;
  if ((stage_v_197_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_197_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  }
  if ((stage_v_197_2 & 1) != 0)
  {
    if ((stage_v_72_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_197_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  }
  int stage_v_198_1 = (stage_v_136_1 ^ pub_r001707_12_1) & 63;
  int stage_v_198_2 = (stage_v_136_2 ^ pub_r001707_12_2) & 63;
  if ((stage_v_198_1 & 1) != 0)
  {
    if ((stage_v_51_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_198_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  }
  if ((stage_v_198_2 & 1) != 0)
  {
    if ((stage_v_51_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_198_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  }
  int stage_v_199_1 = (stage_v_62_1 ^ pub_r001707_1_1) & 63;
  int stage_v_199_2 = (stage_v_62_2 ^ pub_r001707_1_2) & 63;
  if ((stage_v_199_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_199_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  }
  if ((stage_v_199_2 & 1) != 0)
  {
    if ((stage_v_34_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_199_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  }
  int stage_v_200_1 = (stage_v_42_1 ^ pub_r001707_13_1) & 63;
  int stage_v_200_2 = (stage_v_42_2 ^ pub_r001707_13_2) & 63;
  if ((stage_v_200_1 & 1) != 0)
  {
    if ((stage_v_101_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_200_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  }
  if ((stage_v_200_2 & 1) != 0)
  {
    if ((stage_v_101_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_200_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  }
  int stage_v_201_1 = ((pub_r001707_1_1 * 2) + 40) & 63;
  int stage_v_201_2 = ((pub_r001707_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (stage_v_9_1 ^ pub_r001707_5_1) & 63;
  int stage_v_202_2 = (stage_v_9_2 ^ pub_r001707_5_2) & 63;
  if ((stage_v_202_1 & 1) != 0)
  {
    if ((stage_v_62_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_202_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  }
  if ((stage_v_202_2 & 1) != 0)
  {
    if ((stage_v_62_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_202_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  }
  int stage_v_203_1 = (stage_v_198_1 ^ pub_r001707_4_1) & 63;
  int stage_v_203_2 = (stage_v_198_2 ^ pub_r001707_4_2) & 63;
  if ((stage_v_203_1 & 1) != 0)
  {
    if ((stage_v_169_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_203_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  }
  if ((stage_v_203_2 & 1) != 0)
  {
    if ((stage_v_169_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_203_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  }
  int stage_v_204_1 = (stage_v_53_1 ^ pub_r001707_3_1) & 63;
  int stage_v_204_2 = (stage_v_53_2 ^ pub_r001707_3_2) & 63;
  if ((stage_v_204_1 & 1) != 0)
  {
    if ((stage_v_68_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_204_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  }
  if ((stage_v_204_2 & 1) != 0)
  {
    if ((stage_v_68_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_204_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  }
  int stage_v_205_1 = ((pub_r001707_3_1 * 2) + 45) & 63;
  int stage_v_205_2 = ((pub_r001707_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = (stage_v_95_1 ^ pub_r001707_2_1) & 63;
  int stage_v_206_2 = (stage_v_95_2 ^ pub_r001707_2_2) & 63;
  if ((stage_v_206_1 & 1) != 0)
  {
    if ((stage_v_151_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_206_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  }
  if ((stage_v_206_2 & 1) != 0)
  {
    if ((stage_v_151_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_206_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  }
  int stage_v_207_1 = (stage_v_64_1 ^ pub_r001707_2_1) & 63;
  int stage_v_207_2 = (stage_v_64_2 ^ pub_r001707_2_2) & 63;
  if ((stage_v_207_1 & 1) != 0)
  {
    if ((stage_v_107_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_207_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  }
  if ((stage_v_207_2 & 1) != 0)
  {
    if ((stage_v_107_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_207_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  }
  int stage_v_208_1 = ((pub_r001707_5_1 * 2) + 10) & 63;
  int stage_v_208_2 = ((pub_r001707_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (sec_r001707_20_1 ^ pub_r001707_10_1) & 63;
  int stage_v_209_2 = (sec_r001707_20_2 ^ pub_r001707_10_2) & 63;
  if ((stage_v_209_1 & 1) != 0)
  {
    if ((stage_v_87_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_209_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  }
  if ((stage_v_209_2 & 1) != 0)
  {
    if ((stage_v_87_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_209_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  }
  int stage_v_210_1 = (stage_v_40_1 ^ pub_r001707_17_1) & 63;
  int stage_v_210_2 = (stage_v_40_2 ^ pub_r001707_17_2) & 63;
  if ((stage_v_210_1 & 1) != 0)
  {
    if ((stage_v_135_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_210_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  }
  if ((stage_v_210_2 & 1) != 0)
  {
    if ((stage_v_135_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_210_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  }
  int stage_v_211_1 = ((pub_r001707_8_1 * 2) + 10) & 63;
  int stage_v_211_2 = ((pub_r001707_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001707_12_1 * 2) + 30) & 63;
  int stage_v_212_2 = ((pub_r001707_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001707_13_1 * 2) + 35) & 63;
  int stage_v_213_2 = ((pub_r001707_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (stage_v_141_1 ^ pub_r001707_7_1) & 63;
  int stage_v_214_2 = (stage_v_141_2 ^ pub_r001707_7_2) & 63;
  if ((stage_v_214_1 & 1) != 0)
  {
    if ((stage_v_150_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_214_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  }
  if ((stage_v_214_2 & 1) != 0)
  {
    if ((stage_v_150_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_214_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001707_15_1 == pub_r001707_15_2);
  __CPROVER_assume(pub_r001707_14_1 == pub_r001707_14_2);
  __CPROVER_assume(sec_r001707_21_1 != sec_r001707_21_2);
  __CPROVER_assume(sec_r001707_6_1 != sec_r001707_6_2);
  __CPROVER_assume(pub_r001707_9_1 == pub_r001707_9_2);
  __CPROVER_assume(pub_r001707_6_1 == pub_r001707_6_2);
  __CPROVER_assume(sec_r001707_20_1 != sec_r001707_20_2);
  __CPROVER_assume(pub_r001707_16_1 == pub_r001707_16_2);
  __CPROVER_assume(sec_r001707_14_1 != sec_r001707_14_2);
  __CPROVER_assume(sec_r001707_5_1 != sec_r001707_5_2);
  __CPROVER_assume(sec_r001707_1_1 != sec_r001707_1_2);
  __CPROVER_assume(pub_r001707_1_1 == pub_r001707_1_2);
  __CPROVER_assume(sec_r001707_17_1 != sec_r001707_17_2);
  __CPROVER_assume(pub_r001707_13_1 == pub_r001707_13_2);
  __CPROVER_assume(pub_r001707_3_1 == pub_r001707_3_2);
  __CPROVER_assume(pub_r001707_11_1 == pub_r001707_11_2);
  __CPROVER_assume(sec_r001707_2_1 != sec_r001707_2_2);
  __CPROVER_assume(sec_r001707_9_1 != sec_r001707_9_2);
  __CPROVER_assume(sec_r001707_7_1 != sec_r001707_7_2);
  __CPROVER_assume(sec_r001707_8_1 != sec_r001707_8_2);
  __CPROVER_assume(pub_r001707_7_1 == pub_r001707_7_2);
  __CPROVER_assume(pub_r001707_10_1 == pub_r001707_10_2);
  __CPROVER_assume(sec_r001707_16_1 != sec_r001707_16_2);
  __CPROVER_assume(pub_r001707_2_1 == pub_r001707_2_2);
  __CPROVER_assume(sec_r001707_22_1 != sec_r001707_22_2);
  __CPROVER_assume(sec_r001707_4_1 != sec_r001707_4_2);
  __CPROVER_assume(sec_r001707_10_1 != sec_r001707_10_2);
  __CPROVER_assume(pub_r001707_5_1 == pub_r001707_5_2);
  __CPROVER_assume(pub_r001707_8_1 == pub_r001707_8_2);
  __CPROVER_assume(pub_r001707_17_1 == pub_r001707_17_2);
  __CPROVER_assume(sec_r001707_3_1 != sec_r001707_3_2);
  __CPROVER_assume(pub_r001707_0_1 == pub_r001707_0_2);
  __CPROVER_assume(sec_r001707_12_1 != sec_r001707_12_2);
  __CPROVER_assume(sec_r001707_18_1 != sec_r001707_18_2);
  __CPROVER_assume(pub_r001707_12_1 == pub_r001707_12_2);
  __CPROVER_assume(sec_r001707_19_1 != sec_r001707_19_2);
  __CPROVER_assume(pub_r001707_4_1 == pub_r001707_4_2);
  __CPROVER_assume(sec_r001707_13_1 != sec_r001707_13_2);
  __CPROVER_assume(sec_r001707_0_1 != sec_r001707_0_2);
  __CPROVER_assume(sec_r001707_11_1 != sec_r001707_11_2);
  __CPROVER_assume(sec_r001707_15_1 != sec_r001707_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.signature == st_var_2_2.signature);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.code == st_var_2_2.code);
  assert(st_var_2_1.facility == st_var_2_2.facility);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.seq == st_var_2_2.seq);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
  assert(helper_flow_10_1 == helper_flow_10_2);
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
}


