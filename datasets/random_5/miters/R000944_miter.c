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
struct SensorNode_R000944_4413_0
{
  int threshold;
  short reading;
  unsigned char offset;
  int status;
  unsigned char gain;
  int buffer[3];
};
struct DeviceConfig_R000944_4413_1
{
  short baud_rate;
  short port;
  short timeout;
  int buffer[3];
};
union PacketPayload_R000944_4413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000944_4413_1
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
void fn_R000944_4413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st_1 = {0};
  struct SensorNode_R000944_4413_0 st_2 = {0};
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
  int sample_29_1 = local_arr_1[aux_1 % 3];
  int sample_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_29_2 * 2)) & 127;
  int metric_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_67_1) & 63;
  aux_2 = (aux_2 + metric_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_89_1 > 11)
  {
    acc_1 = ((acc_1 + (window_89_1 * 2)) + 5) & 127;
    aux_1 ^= window_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_89_2 > 11)
  {
    acc_2 = ((acc_2 + (window_89_2 * 2)) + 5) & 127;
    aux_2 ^= window_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_29_1 == sample_29_2);
  assert(metric_67_1 == metric_67_2);
  assert(window_89_1 == window_89_2);
}

int fn_R000944_4413_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_29 = local_arr[aux % 3];
  acc = (acc + (sample_29 * 2)) & 127;
  int metric_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_67) & 63;
  acc ^= aux;
  int window_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_89 > 11)
  {
    acc = ((acc + (window_89 * 2)) + 5) & 127;
    aux ^= window_89 & 15;
  }
  else
  {
    acc = ((acc - window_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000944_4413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st_1 = {0};
  struct SensorNode_R000944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_13_1 = local_arr_1[aux_1 % 3];
  int scale_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_13_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_37_1 > 43)
  {
    acc_1 = ((acc_1 + (pivot_37_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_37_2 > 43)
  {
    acc_2 = ((acc_2 + (pivot_37_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_69_1)
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

  switch (cursor_69_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_13_1 == scale_13_2);
  assert(pivot_37_1 == pivot_37_2);
  assert(cursor_69_1 == cursor_69_2);
}

int fn_R000944_4413_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int scale_13 = local_arr[aux % 3];
  acc = (acc + (scale_13 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_37 > 43)
  {
    acc = ((acc + (pivot_37 * 2)) + 5) & 127;
    aux ^= pivot_37 & 15;
  }
  else
  {
    acc = ((acc - pivot_37) + 11) & 127;
    aux += 3;
  }
  int cursor_69 = (aux + st.buffer[1]) & 3;
  switch (cursor_69)
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

void fn_R000944_4413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st_1 = {0};
  struct SensorNode_R000944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int quotient_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_45_1)
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

  switch (quotient_45_2)
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

  int margin_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_60_1) & 63;
  aux_2 = (aux_2 + margin_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_55_1 = local_arr_1[aux_1 % 3];
  int segment_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_45_1 == quotient_45_2);
  assert(margin_60_1 == margin_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_55_1 == segment_55_2);
}

int fn_R000944_4413_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int quotient_45 = (aux + st.buffer[1]) & 3;
  switch (quotient_45)
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

  int margin_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_60) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_55 = local_arr[aux % 3];
  acc = (acc + (segment_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000944_4413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st_1 = {0};
  struct DeviceConfig_R000944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int index_reg_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_69_1)
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

  switch (index_reg_69_2)
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

  int window_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_47_1) & 63;
  aux_2 = (aux_2 + window_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_69_1 == index_reg_69_2);
  assert(window_47_1 == window_47_2);
}

int fn_R000944_4413_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int index_reg_69 = (aux + st.buffer[1]) & 3;
  switch (index_reg_69)
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

  int window_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000944_4413_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st_1 = {0};
  struct DeviceConfig_R000944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int threshold_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_67_1)
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

  switch (threshold_67_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_67_1 == threshold_67_2);
}

int fn_R000944_4413_4(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int threshold_67 = (aux + st.buffer[1]) & 3;
  switch (threshold_67)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000944_4413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st_1 = {0};
  struct DeviceConfig_R000944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int offset_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_34_1 > 36)
  {
    acc_1 = ((acc_1 + (offset_34_1 * 2)) + 5) & 127;
    aux_1 ^= offset_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_34_2 > 36)
  {
    acc_2 = ((acc_2 + (offset_34_2 * 2)) + 5) & 127;
    aux_2 ^= offset_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_44_1 = local_arr_1[aux_1 % 3];
  int stride_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_44_2 * 2)) & 127;
  int quotient_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_59_1)
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

  switch (quotient_59_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_34_1 == offset_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_44_1 == stride_44_2);
  assert(quotient_59_1 == quotient_59_2);
}

int fn_R000944_4413_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int offset_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_34 > 36)
  {
    acc = ((acc + (offset_34 * 2)) + 5) & 127;
    aux ^= offset_34 & 15;
  }
  else
  {
    acc = ((acc - offset_34) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_44 = local_arr[aux % 3];
  acc = (acc + (stride_44 * 2)) & 127;
  int quotient_59 = (aux + st.buffer[1]) & 3;
  switch (quotient_59)
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

void fn_R000944_4413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st_1 = {0};
  struct DeviceConfig_R000944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_82_1 = local_arr_1[aux_1 % 3];
  int residue_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_82_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_33_1)
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

  switch (quantum_33_2)
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

  int pivot_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_41_1 > 30)
  {
    acc_1 = ((acc_1 + (pivot_41_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_41_2 > 30)
  {
    acc_2 = ((acc_2 + (pivot_41_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_41_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_82_1 == residue_82_2);
  assert(quantum_33_1 == quantum_33_2);
  assert(pivot_41_1 == pivot_41_2);
}

int fn_R000944_4413_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int residue_82 = local_arr[aux % 3];
  acc = (acc + (residue_82 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_33 = (aux + st.buffer[1]) & 3;
  switch (quantum_33)
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

  int pivot_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_41 > 30)
  {
    acc = ((acc + (pivot_41 * 2)) + 5) & 127;
    aux ^= pivot_41 & 15;
  }
  else
  {
    acc = ((acc - pivot_41) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000944_4413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st_1 = {0};
  struct DeviceConfig_R000944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_39_1)
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

  switch (mask_39_2)
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

  int bound_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_74_1 > 10)
  {
    acc_1 = ((acc_1 + (bound_74_1 * 2)) + 5) & 127;
    aux_1 ^= bound_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_74_2 > 10)
  {
    acc_2 = ((acc_2 + (bound_74_2 * 2)) + 5) & 127;
    aux_2 ^= bound_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_74_2) + 11) & 127;
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_39_1 == mask_39_2);
  assert(bound_74_1 == bound_74_2);
  assert(weight_64_1 == weight_64_2);
}

int fn_R000944_4413_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_39 = (aux + st.buffer[1]) & 3;
  switch (mask_39)
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

  int bound_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_74 > 10)
  {
    acc = ((acc + (bound_74 * 2)) + 5) & 127;
    aux ^= bound_74 & 15;
  }
  else
  {
    acc = ((acc - bound_74) + 11) & 127;
    aux += 3;
  }
  int weight_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000944_4413_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st_1 = {0};
  struct DeviceConfig_R000944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int phase_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_65_1)
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

  switch (phase_65_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_65_1 == phase_65_2);
}

int fn_R000944_4413_8(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int phase_65 = (aux + st.buffer[1]) & 3;
  switch (phase_65)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000944_4413_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st_1 = {0};
  struct SensorNode_R000944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_49_1 = local_arr_1[aux_1 % 3];
  int quotient_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_49_2 * 2)) & 127;
  int vector_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_25_1 > 43)
  {
    acc_1 = ((acc_1 + (vector_25_1 * 2)) + 5) & 127;
    aux_1 ^= vector_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_25_2 > 43)
  {
    acc_2 = ((acc_2 + (vector_25_2 * 2)) + 5) & 127;
    aux_2 ^= vector_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_49_1 == quotient_49_2);
  assert(vector_25_1 == vector_25_2);
}

int fn_R000944_4413_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_49 = local_arr[aux % 3];
  acc = (acc + (quotient_49 * 2)) & 127;
  int vector_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_25 > 43)
  {
    acc = ((acc + (vector_25 * 2)) + 5) & 127;
    aux ^= vector_25 & 15;
  }
  else
  {
    acc = ((acc - vector_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000944_4413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st_1 = {0};
  struct SensorNode_R000944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_55_1 = local_arr_1[aux_1 % 3];
  int residue_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_55_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_75_1) & 63;
  aux_2 = (aux_2 + tracker_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_55_1 == residue_55_2);
  assert(tracker_75_1 == tracker_75_2);
}

int fn_R000944_4413_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int residue_55 = local_arr[aux % 3];
  acc = (acc + (residue_55 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000944_4413_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st_1 = {0};
  struct DeviceConfig_R000944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_96_1 > 11)
  {
    acc_1 = ((acc_1 + (parity_96_1 * 2)) + 5) & 127;
    aux_1 ^= parity_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_96_2 > 11)
  {
    acc_2 = ((acc_2 + (parity_96_2 * 2)) + 5) & 127;
    aux_2 ^= parity_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_30_1) & 63;
  aux_2 = (aux_2 + delta_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_96_1 == parity_96_2);
  assert(delta_30_1 == delta_30_2);
}

int fn_R000944_4413_11(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_96 > 11)
  {
    acc = ((acc + (parity_96 * 2)) + 5) & 127;
    aux ^= parity_96 & 15;
  }
  else
  {
    acc = ((acc - parity_96) + 11) & 127;
    aux += 3;
  }
  int delta_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000944_4413_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st_1 = {0};
  struct SensorNode_R000944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int damping_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_35_1 > 36)
  {
    acc_1 = ((acc_1 + (damping_35_1 * 2)) + 5) & 127;
    aux_1 ^= damping_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_35_2 > 36)
  {
    acc_2 = ((acc_2 + (damping_35_2 * 2)) + 5) & 127;
    aux_2 ^= damping_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_35_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_35_1 == damping_35_2);
}

int fn_R000944_4413_12(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int damping_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_35 > 36)
  {
    acc = ((acc + (damping_35 * 2)) + 5) & 127;
    aux ^= damping_35 & 15;
  }
  else
  {
    acc = ((acc - damping_35) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000944_4413_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st_1 = {0};
  struct DeviceConfig_R000944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int parity_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_31_1 > 10)
  {
    acc_1 = ((acc_1 + (parity_31_1 * 2)) + 5) & 127;
    aux_1 ^= parity_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_31_2 > 10)
  {
    acc_2 = ((acc_2 + (parity_31_2 * 2)) + 5) & 127;
    aux_2 ^= parity_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_85_1)
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

  switch (anchor_85_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_31_1 == parity_31_2);
  assert(anchor_85_1 == anchor_85_2);
}

int fn_R000944_4413_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int parity_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_31 > 10)
  {
    acc = ((acc + (parity_31 * 2)) + 5) & 127;
    aux ^= parity_31 & 15;
  }
  else
  {
    acc = ((acc - parity_31) + 11) & 127;
    aux += 3;
  }
  int anchor_85 = (aux + st.buffer[1]) & 3;
  switch (anchor_85)
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

void fn_R000944_4413_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st_1 = {0};
  struct SensorNode_R000944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int phase_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_59_1 > 26)
  {
    acc_1 = ((acc_1 + (phase_59_1 * 2)) + 5) & 127;
    aux_1 ^= phase_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_59_2 > 26)
  {
    acc_2 = ((acc_2 + (phase_59_2 * 2)) + 5) & 127;
    aux_2 ^= phase_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_44_1)
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

  switch (factor_44_2)
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

  int weight_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_47_1) & 63;
  aux_2 = (aux_2 + weight_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_59_1 == phase_59_2);
  assert(factor_44_1 == factor_44_2);
  assert(weight_47_1 == weight_47_2);
}

int fn_R000944_4413_14(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int phase_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_59 > 26)
  {
    acc = ((acc + (phase_59 * 2)) + 5) & 127;
    aux ^= phase_59 & 15;
  }
  else
  {
    acc = ((acc - phase_59) + 11) & 127;
    aux += 3;
  }
  int factor_44 = (aux + st.buffer[1]) & 3;
  switch (factor_44)
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

  int weight_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000944_4413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st_1 = {0};
  struct DeviceConfig_R000944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int mask_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_36_1) & 63;
  aux_2 = (aux_2 + mask_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_10_1)
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

  switch (delta_10_2)
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
  int quotient_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_98_1 > 16)
  {
    acc_1 = ((acc_1 + (quotient_98_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_98_2 > 16)
  {
    acc_2 = ((acc_2 + (quotient_98_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_36_1 == mask_36_2);
  assert(delta_10_1 == delta_10_2);
  assert(quotient_98_1 == quotient_98_2);
}

int fn_R000944_4413_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int mask_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_36) & 63;
  acc ^= aux;
  int delta_10 = (aux + st.buffer[1]) & 3;
  switch (delta_10)
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
  int quotient_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_98 > 16)
  {
    acc = ((acc + (quotient_98 * 2)) + 5) & 127;
    aux ^= quotient_98 & 15;
  }
  else
  {
    acc = ((acc - quotient_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000944_4413_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st_1 = {0};
  struct DeviceConfig_R000944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int phase_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_85_1)
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

  switch (phase_85_2)
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

  int delta_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_99_1 > 27)
  {
    acc_1 = ((acc_1 + (delta_99_1 * 2)) + 5) & 127;
    aux_1 ^= delta_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_99_2 > 27)
  {
    acc_2 = ((acc_2 + (delta_99_2 * 2)) + 5) & 127;
    aux_2 ^= delta_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_99_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_89_1 = local_arr_1[aux_1 % 3];
  int window_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_85_1 == phase_85_2);
  assert(delta_99_1 == delta_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_89_1 == window_89_2);
}

int fn_R000944_4413_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int phase_85 = (aux + st.buffer[1]) & 3;
  switch (phase_85)
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

  int delta_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_99 > 27)
  {
    acc = ((acc + (delta_99 * 2)) + 5) & 127;
    aux ^= delta_99 & 15;
  }
  else
  {
    acc = ((acc - delta_99) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int window_89 = local_arr[aux % 3];
  acc = (acc + (window_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000944_4413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st_1 = {0};
  struct SensorNode_R000944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int delta_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_66_1 > 44)
  {
    acc_1 = ((acc_1 + (delta_66_1 * 2)) + 5) & 127;
    aux_1 ^= delta_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_66_2 > 44)
  {
    acc_2 = ((acc_2 + (delta_66_2 * 2)) + 5) & 127;
    aux_2 ^= delta_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_66_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_10_1)
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

  switch (cursor_10_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_66_1 == delta_66_2);
  assert(cursor_10_1 == cursor_10_2);
}

int fn_R000944_4413_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int delta_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_66 > 44)
  {
    acc = ((acc + (delta_66 * 2)) + 5) & 127;
    aux ^= delta_66 & 15;
  }
  else
  {
    acc = ((acc - delta_66) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_10 = (aux + st.buffer[1]) & 3;
  switch (cursor_10)
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

void fn_R000944_4413_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st_1 = {0};
  struct SensorNode_R000944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int index_reg_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_86_1) & 63;
  aux_2 = (aux_2 + index_reg_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_32_1)
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

  switch (checksum_32_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_86_1 == index_reg_86_2);
  assert(checksum_32_1 == checksum_32_2);
}

int fn_R000944_4413_18(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int index_reg_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_86) & 63;
  acc ^= aux;
  int checksum_32 = (aux + st.buffer[1]) & 3;
  switch (checksum_32)
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

void fn_R000944_4413_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st_1 = {0};
  struct SensorNode_R000944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_16_1)
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

  switch (cursor_16_2)
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

  int offset_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_38_1 > 28)
  {
    acc_1 = ((acc_1 + (offset_38_1 * 2)) + 5) & 127;
    aux_1 ^= offset_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_38_2 > 28)
  {
    acc_2 = ((acc_2 + (offset_38_2 * 2)) + 5) & 127;
    aux_2 ^= offset_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_16_1 == cursor_16_2);
  assert(offset_38_1 == offset_38_2);
}

int fn_R000944_4413_19(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_16 = (aux + st.buffer[1]) & 3;
  switch (cursor_16)
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

  int offset_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_38 > 28)
  {
    acc = ((acc + (offset_38 * 2)) + 5) & 127;
    aux ^= offset_38 & 15;
  }
  else
  {
    acc = ((acc - offset_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000944_4413_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st_1 = {0};
  struct DeviceConfig_R000944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int weight_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_61_1 > 18)
  {
    acc_1 = ((acc_1 + (weight_61_1 * 2)) + 5) & 127;
    aux_1 ^= weight_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_61_2 > 18)
  {
    acc_2 = ((acc_2 + (weight_61_2 * 2)) + 5) & 127;
    aux_2 ^= weight_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_78_1) & 63;
  aux_2 = (aux_2 + index_reg_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_45_1)
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

  switch (index_reg_45_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_61_1 == weight_61_2);
  assert(index_reg_78_1 == index_reg_78_2);
  assert(index_reg_45_1 == index_reg_45_2);
}

int fn_R000944_4413_20(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int weight_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_61 > 18)
  {
    acc = ((acc + (weight_61 * 2)) + 5) & 127;
    aux ^= weight_61 & 15;
  }
  else
  {
    acc = ((acc - weight_61) + 11) & 127;
    aux += 3;
  }
  int index_reg_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_78) & 63;
  acc ^= aux;
  int index_reg_45 = (aux + st.buffer[1]) & 3;
  switch (index_reg_45)
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

void fn_R000944_4413_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st_1 = {0};
  struct SensorNode_R000944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int margin_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_73_1)
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

  switch (margin_73_2)
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

  int threshold_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_56_1 > 24)
  {
    acc_1 = ((acc_1 + (threshold_56_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_56_2 > 24)
  {
    acc_2 = ((acc_2 + (threshold_56_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_93_1 = local_arr_1[aux_1 % 3];
  int sample_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_93_2 * 2)) & 127;
  int factor_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_69_1) & 63;
  aux_2 = (aux_2 + factor_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_73_1 == margin_73_2);
  assert(threshold_56_1 == threshold_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_93_1 == sample_93_2);
  assert(factor_69_1 == factor_69_2);
}

int fn_R000944_4413_21(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int margin_73 = (aux + st.buffer[1]) & 3;
  switch (margin_73)
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

  int threshold_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_56 > 24)
  {
    acc = ((acc + (threshold_56 * 2)) + 5) & 127;
    aux ^= threshold_56 & 15;
  }
  else
  {
    acc = ((acc - threshold_56) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_93 = local_arr[aux % 3];
  acc = (acc + (sample_93 * 2)) & 127;
  int factor_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000944_0_1;
  int sec_r000944_0_2;
  int sec_r000944_1_1;
  int sec_r000944_1_2;
  int sec_r000944_2_1;
  int sec_r000944_2_2;
  int sec_r000944_3_1;
  int sec_r000944_3_2;
  int sec_r000944_4_1;
  int sec_r000944_4_2;
  int sec_r000944_5_1;
  int sec_r000944_5_2;
  int sec_r000944_6_1;
  int sec_r000944_6_2;
  int sec_r000944_7_1;
  int sec_r000944_7_2;
  int sec_r000944_8_1;
  int sec_r000944_8_2;
  int sec_r000944_9_1;
  int sec_r000944_9_2;
  int sec_r000944_10_1;
  int sec_r000944_10_2;
  int sec_r000944_11_1;
  int sec_r000944_11_2;
  int sec_r000944_12_1;
  int sec_r000944_12_2;
  int sec_r000944_13_1;
  int sec_r000944_13_2;
  int sec_r000944_14_1;
  int sec_r000944_14_2;
  int sec_r000944_15_1;
  int sec_r000944_15_2;
  int pub_r000944_0_1;
  int pub_r000944_0_2;
  int pub_r000944_1_1;
  int pub_r000944_1_2;
  int pub_r000944_2_1;
  int pub_r000944_2_2;
  int pub_r000944_3_1;
  int pub_r000944_3_2;
  int pub_r000944_4_1;
  int pub_r000944_4_2;
  int pub_r000944_5_1;
  int pub_r000944_5_2;
  int pub_r000944_6_1;
  int pub_r000944_6_2;
  int pub_r000944_7_1;
  int pub_r000944_7_2;
  int pub_r000944_8_1;
  int pub_r000944_8_2;
  int pub_r000944_9_1;
  int pub_r000944_9_2;
  int pub_r000944_10_1;
  int pub_r000944_10_2;
  int pub_r000944_11_1;
  int pub_r000944_11_2;
  int pub_r000944_12_1;
  int pub_r000944_12_2;
  int pub_r000944_13_1;
  int pub_r000944_13_2;
  int pub_r000944_14_1;
  int pub_r000944_14_2;
  int pub_r000944_15_1;
  int pub_r000944_15_2;
  int pub_r000944_16_1;
  int pub_r000944_16_2;
  int pub_r000944_17_1;
  int pub_r000944_17_2;
  int pub_r000944_18_1;
  int pub_r000944_18_2;
  int pub_r000944_19_1;
  int pub_r000944_19_2;
  int pub_r000944_20_1;
  int pub_r000944_20_2;
  int pub_r000944_21_1;
  int pub_r000944_21_2;
  int pub_r000944_22_1;
  int pub_r000944_22_2;
  int pub_r000944_23_1;
  int pub_r000944_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000944_0_1 >= (-100)) && (pub_r000944_0_1 <= 100));
  __CPROVER_assume((pub_r000944_0_2 >= (-100)) && (pub_r000944_0_2 <= 100));
  __CPROVER_assume((pub_r000944_1_1 >= (-100)) && (pub_r000944_1_1 <= 100));
  __CPROVER_assume((pub_r000944_1_2 >= (-100)) && (pub_r000944_1_2 <= 100));
  __CPROVER_assume((pub_r000944_2_1 >= (-100)) && (pub_r000944_2_1 <= 100));
  __CPROVER_assume((pub_r000944_2_2 >= (-100)) && (pub_r000944_2_2 <= 100));
  __CPROVER_assume((pub_r000944_3_1 >= (-100)) && (pub_r000944_3_1 <= 100));
  __CPROVER_assume((pub_r000944_3_2 >= (-100)) && (pub_r000944_3_2 <= 100));
  __CPROVER_assume((pub_r000944_4_1 >= (-100)) && (pub_r000944_4_1 <= 100));
  __CPROVER_assume((pub_r000944_4_2 >= (-100)) && (pub_r000944_4_2 <= 100));
  __CPROVER_assume((pub_r000944_5_1 >= (-100)) && (pub_r000944_5_1 <= 100));
  __CPROVER_assume((pub_r000944_5_2 >= (-100)) && (pub_r000944_5_2 <= 100));
  __CPROVER_assume((pub_r000944_6_1 >= (-100)) && (pub_r000944_6_1 <= 100));
  __CPROVER_assume((pub_r000944_6_2 >= (-100)) && (pub_r000944_6_2 <= 100));
  __CPROVER_assume((pub_r000944_7_1 >= (-100)) && (pub_r000944_7_1 <= 100));
  __CPROVER_assume((pub_r000944_7_2 >= (-100)) && (pub_r000944_7_2 <= 100));
  __CPROVER_assume((pub_r000944_8_1 >= (-100)) && (pub_r000944_8_1 <= 100));
  __CPROVER_assume((pub_r000944_8_2 >= (-100)) && (pub_r000944_8_2 <= 100));
  __CPROVER_assume((pub_r000944_9_1 >= (-100)) && (pub_r000944_9_1 <= 100));
  __CPROVER_assume((pub_r000944_9_2 >= (-100)) && (pub_r000944_9_2 <= 100));
  __CPROVER_assume((pub_r000944_10_1 >= (-100)) && (pub_r000944_10_1 <= 100));
  __CPROVER_assume((pub_r000944_10_2 >= (-100)) && (pub_r000944_10_2 <= 100));
  __CPROVER_assume((pub_r000944_11_1 >= (-100)) && (pub_r000944_11_1 <= 100));
  __CPROVER_assume((pub_r000944_11_2 >= (-100)) && (pub_r000944_11_2 <= 100));
  __CPROVER_assume((pub_r000944_12_1 >= (-100)) && (pub_r000944_12_1 <= 100));
  __CPROVER_assume((pub_r000944_12_2 >= (-100)) && (pub_r000944_12_2 <= 100));
  __CPROVER_assume((pub_r000944_13_1 >= (-100)) && (pub_r000944_13_1 <= 100));
  __CPROVER_assume((pub_r000944_13_2 >= (-100)) && (pub_r000944_13_2 <= 100));
  __CPROVER_assume((pub_r000944_14_1 >= (-100)) && (pub_r000944_14_1 <= 100));
  __CPROVER_assume((pub_r000944_14_2 >= (-100)) && (pub_r000944_14_2 <= 100));
  __CPROVER_assume((pub_r000944_15_1 >= (-100)) && (pub_r000944_15_1 <= 100));
  __CPROVER_assume((pub_r000944_15_2 >= (-100)) && (pub_r000944_15_2 <= 100));
  __CPROVER_assume((pub_r000944_16_1 >= (-100)) && (pub_r000944_16_1 <= 100));
  __CPROVER_assume((pub_r000944_16_2 >= (-100)) && (pub_r000944_16_2 <= 100));
  __CPROVER_assume((pub_r000944_17_1 >= (-100)) && (pub_r000944_17_1 <= 100));
  __CPROVER_assume((pub_r000944_17_2 >= (-100)) && (pub_r000944_17_2 <= 100));
  __CPROVER_assume((pub_r000944_18_1 >= (-100)) && (pub_r000944_18_1 <= 100));
  __CPROVER_assume((pub_r000944_18_2 >= (-100)) && (pub_r000944_18_2 <= 100));
  __CPROVER_assume((pub_r000944_19_1 >= (-100)) && (pub_r000944_19_1 <= 100));
  __CPROVER_assume((pub_r000944_19_2 >= (-100)) && (pub_r000944_19_2 <= 100));
  __CPROVER_assume((pub_r000944_20_1 >= (-100)) && (pub_r000944_20_1 <= 100));
  __CPROVER_assume((pub_r000944_20_2 >= (-100)) && (pub_r000944_20_2 <= 100));
  __CPROVER_assume((pub_r000944_21_1 >= (-100)) && (pub_r000944_21_1 <= 100));
  __CPROVER_assume((pub_r000944_21_2 >= (-100)) && (pub_r000944_21_2 <= 100));
  __CPROVER_assume((pub_r000944_22_1 >= (-100)) && (pub_r000944_22_1 <= 100));
  __CPROVER_assume((pub_r000944_22_2 >= (-100)) && (pub_r000944_22_2 <= 100));
  __CPROVER_assume((pub_r000944_23_1 >= (-100)) && (pub_r000944_23_1 <= 100));
  __CPROVER_assume((pub_r000944_23_2 >= (-100)) && (pub_r000944_23_2 <= 100));
  __CPROVER_assume((sec_r000944_0_1 >= 0) && (sec_r000944_0_1 <= 255));
  __CPROVER_assume((sec_r000944_0_2 >= 0) && (sec_r000944_0_2 <= 255));
  __CPROVER_assume((sec_r000944_1_1 >= 0) && (sec_r000944_1_1 <= 255));
  __CPROVER_assume((sec_r000944_1_2 >= 0) && (sec_r000944_1_2 <= 255));
  __CPROVER_assume((sec_r000944_2_1 >= 0) && (sec_r000944_2_1 <= 255));
  __CPROVER_assume((sec_r000944_2_2 >= 0) && (sec_r000944_2_2 <= 255));
  __CPROVER_assume((sec_r000944_3_1 >= 0) && (sec_r000944_3_1 <= 255));
  __CPROVER_assume((sec_r000944_3_2 >= 0) && (sec_r000944_3_2 <= 255));
  __CPROVER_assume((sec_r000944_4_1 >= 0) && (sec_r000944_4_1 <= 255));
  __CPROVER_assume((sec_r000944_4_2 >= 0) && (sec_r000944_4_2 <= 255));
  __CPROVER_assume((sec_r000944_5_1 >= 0) && (sec_r000944_5_1 <= 255));
  __CPROVER_assume((sec_r000944_5_2 >= 0) && (sec_r000944_5_2 <= 255));
  __CPROVER_assume((sec_r000944_6_1 >= 0) && (sec_r000944_6_1 <= 255));
  __CPROVER_assume((sec_r000944_6_2 >= 0) && (sec_r000944_6_2 <= 255));
  __CPROVER_assume((sec_r000944_7_1 >= 0) && (sec_r000944_7_1 <= 255));
  __CPROVER_assume((sec_r000944_7_2 >= 0) && (sec_r000944_7_2 <= 255));
  __CPROVER_assume((sec_r000944_8_1 >= 0) && (sec_r000944_8_1 <= 255));
  __CPROVER_assume((sec_r000944_8_2 >= 0) && (sec_r000944_8_2 <= 255));
  __CPROVER_assume((sec_r000944_9_1 >= 0) && (sec_r000944_9_1 <= 255));
  __CPROVER_assume((sec_r000944_9_2 >= 0) && (sec_r000944_9_2 <= 255));
  __CPROVER_assume((sec_r000944_10_1 >= 0) && (sec_r000944_10_1 <= 255));
  __CPROVER_assume((sec_r000944_10_2 >= 0) && (sec_r000944_10_2 <= 255));
  __CPROVER_assume((sec_r000944_11_1 >= 0) && (sec_r000944_11_1 <= 255));
  __CPROVER_assume((sec_r000944_11_2 >= 0) && (sec_r000944_11_2 <= 255));
  __CPROVER_assume((sec_r000944_12_1 >= 0) && (sec_r000944_12_1 <= 255));
  __CPROVER_assume((sec_r000944_12_2 >= 0) && (sec_r000944_12_2 <= 255));
  __CPROVER_assume((sec_r000944_13_1 >= 0) && (sec_r000944_13_1 <= 255));
  __CPROVER_assume((sec_r000944_13_2 >= 0) && (sec_r000944_13_2 <= 255));
  __CPROVER_assume((sec_r000944_14_1 >= 0) && (sec_r000944_14_1 <= 255));
  __CPROVER_assume((sec_r000944_14_2 >= 0) && (sec_r000944_14_2 <= 255));
  __CPROVER_assume((sec_r000944_15_1 >= 0) && (sec_r000944_15_1 <= 255));
  __CPROVER_assume((sec_r000944_15_2 >= 0) && (sec_r000944_15_2 <= 255));
  struct SensorNode_R000944_4413_0 st_var_0_1 = {0};
  struct SensorNode_R000944_4413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000944_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000944_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000944_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000944_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000944_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000944_0_2 + 7) & 15;
  struct DeviceConfig_R000944_4413_1 st_var_1_1 = {0};
  struct DeviceConfig_R000944_4413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000944_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000944_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000944_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000944_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000944_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000944_0_2 + 9) & 15;
  union PacketPayload_R000944_4413_0 u_var_1;
  union PacketPayload_R000944_4413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 52)
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
  if (stage_v_1_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 52)
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
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 4) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = (st_var_1_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_1_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 12) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
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
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = (st_var_1_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_1_2.buffer[0] ^ 18) & 3;
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

  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = ((st_var_0_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_0_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 43)
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
  if (stage_v_18_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 43)
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
  if (stage_v_19_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 25)
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
  if (stage_v_19_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 25)
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
  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 22) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = (st_var_0_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_0_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = (st_var_0_1.buffer[0] ^ 29) & 3;
  int stage_v_26_2 = (st_var_0_2.buffer[0] ^ 29) & 3;
  switch (stage_v_26_1)
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

  switch (stage_v_26_2)
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

  int stage_v_27_1 = (st_var_1_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_1_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = table_1[1];
  int stage_v_29_2 = table_2[1];
  table_1[1] = (table_1[2] + 59) & 63;
  table_2[1] = (table_2[2] + 59) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (st_var_0_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_0_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  switch (stage_v_34_2)
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

  int stage_v_35_1 = (st_var_1_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_1_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  int stage_v_36_1 = table_1[0];
  int stage_v_36_2 = table_2[0];
  table_1[0] = (table_1[1] + 73) & 63;
  table_2[0] = (table_2[1] + 73) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
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
  int stage_v_38_1 = (st_var_0_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_0_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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

  int stage_v_39_1 = (st_var_1_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_1_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  int stage_v_40_1 = ((st_var_0_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_0_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 52)
    {
      chk_sum_1 ^= stage_v_40_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_40_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 52)
    {
      chk_sum_2 ^= stage_v_40_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 42) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 42) & 15;
  int stage_v_41_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_41_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= stage_v_41_1;
  chk_sum_2 ^= stage_v_41_2;
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((st_var_1_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_1_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 31)
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
  if (stage_v_43_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 31)
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
  int stage_v_45_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (50 & 31);
  int stage_v_45_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (50 & 31);
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= (stage_v_45_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_45_2 << 1) & 127;
  int stage_v_46_1 = table_1[2];
  int stage_v_46_2 = table_2[2];
  table_1[2] = (table_1[3] + 93) & 63;
  table_2[2] = (table_2[3] + 93) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_47_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((st_var_1_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_1_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 28)
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
  if (stage_v_51_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 28)
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
  int stage_v_52_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_52_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_53_1 = (st_var_1_1.buffer[0] ^ 56) & 3;
  int stage_v_53_2 = (st_var_1_2.buffer[0] ^ 56) & 3;
  switch (stage_v_53_1)
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

  switch (stage_v_53_2)
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

  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((st_var_1_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_1_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 50)
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
  if (stage_v_55_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 50)
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
  int stage_v_56_1 = ((st_var_0_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_0_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 38)
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
  if (stage_v_56_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 38)
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
  int stage_v_57_1 = (st_var_1_1.buffer[0] ^ 60) & 3;
  int stage_v_57_2 = (st_var_1_2.buffer[0] ^ 60) & 3;
  switch (stage_v_57_1)
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

  switch (stage_v_57_2)
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
  int stage_v_59_1 = ((st_var_1_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_1_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 27)
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
  if (stage_v_59_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 27)
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
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = table_1[2];
  int stage_v_62_2 = table_2[2];
  table_1[2] = (table_1[3] + 125) & 63;
  table_2[2] = (table_2[3] + 125) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_64_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (69 & 31);
  int stage_v_64_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (69 & 31);
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= (stage_v_64_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_64_2 << 1) & 127;
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
  int stage_v_66_1 = ((st_var_0_1.buffer[0] * 2) + 205) & 63;
  int stage_v_66_2 = ((st_var_0_2.buffer[0] * 2) + 205) & 63;
  if (stage_v_66_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_66_1) - 5) & 255;
    if (stage_v_66_1 > 46)
    {
      chk_sum_1 ^= stage_v_66_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_66_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_66_2) - 5) & 255;
    if (stage_v_66_2 > 46)
    {
      chk_sum_2 ^= stage_v_66_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_67_1 = (st_var_1_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_1_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 69) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 69) & 15;
  int stage_v_68_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_68_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= stage_v_68_1;
  chk_sum_2 ^= stage_v_68_2;
  int stage_v_69_1 = (st_var_1_1.buffer[0] ^ 72) & 3;
  int stage_v_69_2 = (st_var_1_2.buffer[0] ^ 72) & 3;
  switch (stage_v_69_1)
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

  switch (stage_v_69_2)
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

  int stage_v_70_1 = ((((sec_r000944_12_1 * 3) + (sec_r000944_12_1 * 2)) - pub_r000944_5_1) + 19) & 127;
  int stage_v_70_2 = ((((sec_r000944_12_2 * 3) + (sec_r000944_12_2 * 2)) - pub_r000944_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((((stage_v_70_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_17_1) + 17) & 127;
  int stage_v_71_2 = ((((stage_v_70_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((((stage_v_70_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_22_1) + 26) & 127;
  int stage_v_72_2 = ((((stage_v_70_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_22_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((((sec_r000944_15_1 * 3) + (sec_r000944_15_1 * 2)) - pub_r000944_19_1) + 14) & 127;
  int stage_v_73_2 = ((((sec_r000944_15_2 * 3) + (sec_r000944_15_2 * 2)) - pub_r000944_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((((stage_v_73_1 * 3) + (sec_r000944_3_1 * 2)) - pub_r000944_12_1) + 24) & 127;
  int stage_v_74_2 = ((((stage_v_73_2 * 3) + (sec_r000944_3_2 * 2)) - pub_r000944_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((((stage_v_70_1 * 3) + (sec_r000944_6_1 * 2)) - pub_r000944_23_1) + 27) & 127;
  int stage_v_75_2 = ((((stage_v_70_2 * 3) + (sec_r000944_6_2 * 2)) - pub_r000944_23_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((((stage_v_70_1 * 3) + (sec_r000944_2_1 * 2)) - pub_r000944_1_1) + 36) & 127;
  int stage_v_76_2 = ((((stage_v_70_2 * 3) + (sec_r000944_2_2 * 2)) - pub_r000944_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((((stage_v_73_1 * 3) + (sec_r000944_12_1 * 2)) - pub_r000944_20_1) + 20) & 127;
  int stage_v_77_2 = ((((stage_v_73_2 * 3) + (sec_r000944_12_2 * 2)) - pub_r000944_20_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((((stage_v_77_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_15_1) + 36) & 127;
  int stage_v_78_2 = ((((stage_v_77_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((((stage_v_72_1 * 3) + (sec_r000944_15_1 * 2)) - pub_r000944_10_1) + 24) & 127;
  int stage_v_79_2 = ((((stage_v_72_2 * 3) + (sec_r000944_15_2 * 2)) - pub_r000944_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((((stage_v_70_1 * 3) + (sec_r000944_3_1 * 2)) - pub_r000944_3_1) + 14) & 127;
  int stage_v_80_2 = ((((stage_v_70_2 * 3) + (sec_r000944_3_2 * 2)) - pub_r000944_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((((sec_r000944_11_1 * 3) + (sec_r000944_11_1 * 2)) - pub_r000944_4_1) + 8) & 127;
  int stage_v_81_2 = ((((sec_r000944_11_2 * 3) + (sec_r000944_11_2 * 2)) - pub_r000944_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((((stage_v_73_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_14_1) + 33) & 127;
  int stage_v_82_2 = ((((stage_v_73_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((((stage_v_71_1 * 3) + (sec_r000944_1_1 * 2)) - pub_r000944_18_1) + 5) & 127;
  int stage_v_83_2 = ((((stage_v_71_2 * 3) + (sec_r000944_1_2 * 2)) - pub_r000944_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((((stage_v_73_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_21_1) + 32) & 127;
  int stage_v_84_2 = ((((stage_v_73_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_21_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((((stage_v_75_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_10_1) + 34) & 127;
  int stage_v_85_2 = ((((stage_v_75_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((((stage_v_74_1 * 3) + (sec_r000944_1_1 * 2)) - pub_r000944_10_1) + 36) & 127;
  int stage_v_86_2 = ((((stage_v_74_2 * 3) + (sec_r000944_1_2 * 2)) - pub_r000944_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((((sec_r000944_9_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_15_1) + 20) & 127;
  int stage_v_87_2 = ((((sec_r000944_9_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((((sec_r000944_9_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_15_1) + 5) & 127;
  int stage_v_88_2 = ((((sec_r000944_9_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((((stage_v_70_1 * 3) + (sec_r000944_8_1 * 2)) - pub_r000944_13_1) + 11) & 127;
  int stage_v_89_2 = ((((stage_v_70_2 * 3) + (sec_r000944_8_2 * 2)) - pub_r000944_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((((sec_r000944_8_1 * 3) + (sec_r000944_8_1 * 2)) - pub_r000944_10_1) + 36) & 127;
  int stage_v_90_2 = ((((sec_r000944_8_2 * 3) + (sec_r000944_8_2 * 2)) - pub_r000944_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((((sec_r000944_2_1 * 3) + (sec_r000944_2_1 * 2)) - pub_r000944_4_1) + 16) & 127;
  int stage_v_91_2 = ((((sec_r000944_2_2 * 3) + (sec_r000944_2_2 * 2)) - pub_r000944_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((((stage_v_73_1 * 3) + (sec_r000944_2_1 * 2)) - pub_r000944_9_1) + 32) & 127;
  int stage_v_92_2 = ((((stage_v_73_2 * 3) + (sec_r000944_2_2 * 2)) - pub_r000944_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((((stage_v_76_1 * 3) + (sec_r000944_10_1 * 2)) - pub_r000944_7_1) + 29) & 127;
  int stage_v_93_2 = ((((stage_v_76_2 * 3) + (sec_r000944_10_2 * 2)) - pub_r000944_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((((stage_v_78_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_14_1) + 6) & 127;
  int stage_v_94_2 = ((((stage_v_78_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((((stage_v_92_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_1_1) + 21) & 127;
  int stage_v_95_2 = ((((stage_v_92_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((((sec_r000944_12_1 * 3) + (sec_r000944_12_1 * 2)) - pub_r000944_2_1) + 15) & 127;
  int stage_v_96_2 = ((((sec_r000944_12_2 * 3) + (sec_r000944_12_2 * 2)) - pub_r000944_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((((stage_v_96_1 * 3) + (sec_r000944_3_1 * 2)) - pub_r000944_2_1) + 22) & 127;
  int stage_v_97_2 = ((((stage_v_96_2 * 3) + (sec_r000944_3_2 * 2)) - pub_r000944_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((((sec_r000944_0_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_23_1) + 15) & 127;
  int stage_v_98_2 = ((((sec_r000944_0_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_23_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((((stage_v_94_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_19_1) + 10) & 127;
  int stage_v_99_2 = ((((stage_v_94_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_19_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((((stage_v_95_1 * 3) + (sec_r000944_15_1 * 2)) - pub_r000944_11_1) + 11) & 127;
  int stage_v_100_2 = ((((stage_v_95_2 * 3) + (sec_r000944_15_2 * 2)) - pub_r000944_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((((stage_v_74_1 * 3) + (sec_r000944_12_1 * 2)) - pub_r000944_9_1) + 3) & 127;
  int stage_v_101_2 = ((((stage_v_74_2 * 3) + (sec_r000944_12_2 * 2)) - pub_r000944_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((((stage_v_97_1 * 3) + (sec_r000944_11_1 * 2)) - pub_r000944_4_1) + 36) & 127;
  int stage_v_102_2 = ((((stage_v_97_2 * 3) + (sec_r000944_11_2 * 2)) - pub_r000944_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((((stage_v_89_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_0_1) + 31) & 127;
  int stage_v_103_2 = ((((stage_v_89_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((((stage_v_86_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_16_1) + 5) & 127;
  int stage_v_104_2 = ((((stage_v_86_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_16_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((((stage_v_103_1 * 3) + (sec_r000944_10_1 * 2)) - pub_r000944_15_1) + 13) & 127;
  int stage_v_105_2 = ((((stage_v_103_2 * 3) + (sec_r000944_10_2 * 2)) - pub_r000944_15_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((((sec_r000944_1_1 * 3) + (sec_r000944_1_1 * 2)) - pub_r000944_21_1) + 22) & 127;
  int stage_v_106_2 = ((((sec_r000944_1_2 * 3) + (sec_r000944_1_2 * 2)) - pub_r000944_21_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((((sec_r000944_1_1 * 3) + (sec_r000944_1_1 * 2)) - pub_r000944_20_1) + 27) & 127;
  int stage_v_107_2 = ((((sec_r000944_1_2 * 3) + (sec_r000944_1_2 * 2)) - pub_r000944_20_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((((stage_v_72_1 * 3) + (sec_r000944_6_1 * 2)) - pub_r000944_2_1) + 7) & 127;
  int stage_v_108_2 = ((((stage_v_72_2 * 3) + (sec_r000944_6_2 * 2)) - pub_r000944_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((((stage_v_70_1 * 3) + (sec_r000944_8_1 * 2)) - pub_r000944_20_1) + 22) & 127;
  int stage_v_109_2 = ((((stage_v_70_2 * 3) + (sec_r000944_8_2 * 2)) - pub_r000944_20_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((((stage_v_106_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_2_1) + 8) & 127;
  int stage_v_110_2 = ((((stage_v_106_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((((sec_r000944_0_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_17_1) + 27) & 127;
  int stage_v_111_2 = ((((sec_r000944_0_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((((sec_r000944_4_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_10_1) + 6) & 127;
  int stage_v_112_2 = ((((sec_r000944_4_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((((sec_r000944_13_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_11_1) + 16) & 127;
  int stage_v_113_2 = ((((sec_r000944_13_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((((stage_v_79_1 * 3) + (sec_r000944_11_1 * 2)) - pub_r000944_12_1) + 34) & 127;
  int stage_v_114_2 = ((((stage_v_79_2 * 3) + (sec_r000944_11_2 * 2)) - pub_r000944_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((((stage_v_105_1 * 3) + (sec_r000944_12_1 * 2)) - pub_r000944_8_1) + 36) & 127;
  int stage_v_115_2 = ((((stage_v_105_2 * 3) + (sec_r000944_12_2 * 2)) - pub_r000944_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((((stage_v_84_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_23_1) + 16) & 127;
  int stage_v_116_2 = ((((stage_v_84_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_23_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((((stage_v_74_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_7_1) + 31) & 127;
  int stage_v_117_2 = ((((stage_v_74_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((((sec_r000944_12_1 * 3) + (sec_r000944_12_1 * 2)) - pub_r000944_9_1) + 14) & 127;
  int stage_v_118_2 = ((((sec_r000944_12_2 * 3) + (sec_r000944_12_2 * 2)) - pub_r000944_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((((sec_r000944_15_1 * 3) + (sec_r000944_15_1 * 2)) - pub_r000944_3_1) + 26) & 127;
  int stage_v_119_2 = ((((sec_r000944_15_2 * 3) + (sec_r000944_15_2 * 2)) - pub_r000944_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((((stage_v_97_1 * 3) + (sec_r000944_6_1 * 2)) - pub_r000944_12_1) + 34) & 127;
  int stage_v_120_2 = ((((stage_v_97_2 * 3) + (sec_r000944_6_2 * 2)) - pub_r000944_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((((stage_v_75_1 * 3) + (sec_r000944_8_1 * 2)) - pub_r000944_16_1) + 21) & 127;
  int stage_v_121_2 = ((((stage_v_75_2 * 3) + (sec_r000944_8_2 * 2)) - pub_r000944_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((((stage_v_103_1 * 3) + (sec_r000944_14_1 * 2)) - pub_r000944_21_1) + 21) & 127;
  int stage_v_122_2 = ((((stage_v_103_2 * 3) + (sec_r000944_14_2 * 2)) - pub_r000944_21_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((((sec_r000944_8_1 * 3) + (sec_r000944_8_1 * 2)) - pub_r000944_17_1) + 29) & 127;
  int stage_v_123_2 = ((((sec_r000944_8_2 * 3) + (sec_r000944_8_2 * 2)) - pub_r000944_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((((stage_v_95_1 * 3) + (sec_r000944_2_1 * 2)) - pub_r000944_17_1) + 22) & 127;
  int stage_v_124_2 = ((((stage_v_95_2 * 3) + (sec_r000944_2_2 * 2)) - pub_r000944_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((((stage_v_109_1 * 3) + (sec_r000944_3_1 * 2)) - pub_r000944_17_1) + 5) & 127;
  int stage_v_125_2 = ((((stage_v_109_2 * 3) + (sec_r000944_3_2 * 2)) - pub_r000944_17_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((((stage_v_119_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_11_1) + 28) & 127;
  int stage_v_126_2 = ((((stage_v_119_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((((stage_v_80_1 * 3) + (sec_r000944_1_1 * 2)) - pub_r000944_10_1) + 6) & 127;
  int stage_v_127_2 = ((((stage_v_80_2 * 3) + (sec_r000944_1_2 * 2)) - pub_r000944_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((((sec_r000944_5_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_3_1) + 6) & 127;
  int stage_v_128_2 = ((((sec_r000944_5_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((((stage_v_72_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_1_1) + 37) & 127;
  int stage_v_129_2 = ((((stage_v_72_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((((stage_v_117_1 * 3) + (sec_r000944_3_1 * 2)) - pub_r000944_22_1) + 30) & 127;
  int stage_v_130_2 = ((((stage_v_117_2 * 3) + (sec_r000944_3_2 * 2)) - pub_r000944_22_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((((stage_v_99_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_15_1) + 8) & 127;
  int stage_v_131_2 = ((((stage_v_99_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((((stage_v_123_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_17_1) + 7) & 127;
  int stage_v_132_2 = ((((stage_v_123_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((((stage_v_116_1 * 3) + (sec_r000944_2_1 * 2)) - pub_r000944_13_1) + 20) & 127;
  int stage_v_133_2 = ((((stage_v_116_2 * 3) + (sec_r000944_2_2 * 2)) - pub_r000944_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((((sec_r000944_8_1 * 3) + (sec_r000944_8_1 * 2)) - pub_r000944_4_1) + 35) & 127;
  int stage_v_134_2 = ((((sec_r000944_8_2 * 3) + (sec_r000944_8_2 * 2)) - pub_r000944_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((((stage_v_124_1 * 3) + (sec_r000944_10_1 * 2)) - pub_r000944_9_1) + 36) & 127;
  int stage_v_135_2 = ((((stage_v_124_2 * 3) + (sec_r000944_10_2 * 2)) - pub_r000944_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((((stage_v_70_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_8_1) + 14) & 127;
  int stage_v_136_2 = ((((stage_v_70_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((((stage_v_98_1 * 3) + (sec_r000944_11_1 * 2)) - pub_r000944_0_1) + 25) & 127;
  int stage_v_137_2 = ((((stage_v_98_2 * 3) + (sec_r000944_11_2 * 2)) - pub_r000944_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((((stage_v_109_1 * 3) + (sec_r000944_2_1 * 2)) - pub_r000944_6_1) + 9) & 127;
  int stage_v_138_2 = ((((stage_v_109_2 * 3) + (sec_r000944_2_2 * 2)) - pub_r000944_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((((sec_r000944_5_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_4_1) + 10) & 127;
  int stage_v_139_2 = ((((sec_r000944_5_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((((stage_v_93_1 * 3) + (sec_r000944_10_1 * 2)) - pub_r000944_11_1) + 18) & 127;
  int stage_v_140_2 = ((((stage_v_93_2 * 3) + (sec_r000944_10_2 * 2)) - pub_r000944_11_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((((stage_v_77_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_10_1) + 6) & 127;
  int stage_v_141_2 = ((((stage_v_77_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((((stage_v_114_1 * 3) + (sec_r000944_6_1 * 2)) - pub_r000944_23_1) + 25) & 127;
  int stage_v_142_2 = ((((stage_v_114_2 * 3) + (sec_r000944_6_2 * 2)) - pub_r000944_23_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((((sec_r000944_0_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_2_1) + 36) & 127;
  int stage_v_143_2 = ((((sec_r000944_0_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((((stage_v_101_1 * 3) + (sec_r000944_7_1 * 2)) - pub_r000944_4_1) + 16) & 127;
  int stage_v_144_2 = ((((stage_v_101_2 * 3) + (sec_r000944_7_2 * 2)) - pub_r000944_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((((stage_v_131_1 * 3) + (sec_r000944_14_1 * 2)) - pub_r000944_13_1) + 31) & 127;
  int stage_v_145_2 = ((((stage_v_131_2 * 3) + (sec_r000944_14_2 * 2)) - pub_r000944_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((((sec_r000944_5_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_12_1) + 14) & 127;
  int stage_v_146_2 = ((((sec_r000944_5_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((((stage_v_122_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_12_1) + 19) & 127;
  int stage_v_147_2 = ((((stage_v_122_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((((sec_r000944_3_1 * 3) + (sec_r000944_3_1 * 2)) - pub_r000944_17_1) + 5) & 127;
  int stage_v_148_2 = ((((sec_r000944_3_2 * 3) + (sec_r000944_3_2 * 2)) - pub_r000944_17_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((((sec_r000944_7_1 * 3) + (sec_r000944_7_1 * 2)) - pub_r000944_22_1) + 3) & 127;
  int stage_v_149_2 = ((((sec_r000944_7_2 * 3) + (sec_r000944_7_2 * 2)) - pub_r000944_22_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((((stage_v_97_1 * 3) + (sec_r000944_2_1 * 2)) - pub_r000944_15_1) + 27) & 127;
  int stage_v_150_2 = ((((stage_v_97_2 * 3) + (sec_r000944_2_2 * 2)) - pub_r000944_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((((sec_r000944_1_1 * 3) + (sec_r000944_1_1 * 2)) - pub_r000944_13_1) + 12) & 127;
  int stage_v_151_2 = ((((sec_r000944_1_2 * 3) + (sec_r000944_1_2 * 2)) - pub_r000944_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((((sec_r000944_13_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_17_1) + 5) & 127;
  int stage_v_152_2 = ((((sec_r000944_13_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_17_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((((stage_v_135_1 * 3) + (sec_r000944_12_1 * 2)) - pub_r000944_18_1) + 32) & 127;
  int stage_v_153_2 = ((((stage_v_135_2 * 3) + (sec_r000944_12_2 * 2)) - pub_r000944_18_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((((stage_v_142_1 * 3) + (sec_r000944_7_1 * 2)) - pub_r000944_23_1) + 36) & 127;
  int stage_v_154_2 = ((((stage_v_142_2 * 3) + (sec_r000944_7_2 * 2)) - pub_r000944_23_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((((stage_v_80_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_23_1) + 30) & 127;
  int stage_v_155_2 = ((((stage_v_80_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_23_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((((stage_v_112_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_23_1) + 27) & 127;
  int stage_v_156_2 = ((((stage_v_112_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_23_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((((stage_v_74_1 * 3) + (sec_r000944_7_1 * 2)) - pub_r000944_4_1) + 37) & 127;
  int stage_v_157_2 = ((((stage_v_74_2 * 3) + (sec_r000944_7_2 * 2)) - pub_r000944_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((((stage_v_144_1 * 3) + (sec_r000944_11_1 * 2)) - pub_r000944_9_1) + 37) & 127;
  int stage_v_158_2 = ((((stage_v_144_2 * 3) + (sec_r000944_11_2 * 2)) - pub_r000944_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((((sec_r000944_6_1 * 3) + (sec_r000944_6_1 * 2)) - pub_r000944_20_1) + 31) & 127;
  int stage_v_159_2 = ((((sec_r000944_6_2 * 3) + (sec_r000944_6_2 * 2)) - pub_r000944_20_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((((sec_r000944_10_1 * 3) + (sec_r000944_10_1 * 2)) - pub_r000944_14_1) + 13) & 127;
  int stage_v_160_2 = ((((sec_r000944_10_2 * 3) + (sec_r000944_10_2 * 2)) - pub_r000944_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((((stage_v_148_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_20_1) + 24) & 127;
  int stage_v_161_2 = ((((stage_v_148_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_20_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((((stage_v_142_1 * 3) + (sec_r000944_8_1 * 2)) - pub_r000944_11_1) + 6) & 127;
  int stage_v_162_2 = ((((stage_v_142_2 * 3) + (sec_r000944_8_2 * 2)) - pub_r000944_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((((stage_v_124_1 * 3) + (sec_r000944_2_1 * 2)) - pub_r000944_8_1) + 35) & 127;
  int stage_v_163_2 = ((((stage_v_124_2 * 3) + (sec_r000944_2_2 * 2)) - pub_r000944_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((((sec_r000944_4_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_4_1) + 14) & 127;
  int stage_v_164_2 = ((((sec_r000944_4_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((((stage_v_106_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_14_1) + 7) & 127;
  int stage_v_165_2 = ((((stage_v_106_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((((stage_v_82_1 * 3) + (sec_r000944_1_1 * 2)) - pub_r000944_5_1) + 9) & 127;
  int stage_v_166_2 = ((((stage_v_82_2 * 3) + (sec_r000944_1_2 * 2)) - pub_r000944_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((((stage_v_147_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_15_1) + 30) & 127;
  int stage_v_167_2 = ((((stage_v_147_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((((sec_r000944_12_1 * 3) + (sec_r000944_12_1 * 2)) - pub_r000944_16_1) + 5) & 127;
  int stage_v_168_2 = ((((sec_r000944_12_2 * 3) + (sec_r000944_12_2 * 2)) - pub_r000944_16_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((((stage_v_96_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_10_1) + 10) & 127;
  int stage_v_169_2 = ((((stage_v_96_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((((sec_r000944_12_1 * 3) + (sec_r000944_12_1 * 2)) - pub_r000944_21_1) + 29) & 127;
  int stage_v_170_2 = ((((sec_r000944_12_2 * 3) + (sec_r000944_12_2 * 2)) - pub_r000944_21_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((((stage_v_167_1 * 3) + (sec_r000944_12_1 * 2)) - pub_r000944_15_1) + 32) & 127;
  int stage_v_171_2 = ((((stage_v_167_2 * 3) + (sec_r000944_12_2 * 2)) - pub_r000944_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((((stage_v_136_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_8_1) + 25) & 127;
  int stage_v_172_2 = ((((stage_v_136_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((((stage_v_158_1 * 3) + (sec_r000944_1_1 * 2)) - pub_r000944_1_1) + 6) & 127;
  int stage_v_173_2 = ((((stage_v_158_2 * 3) + (sec_r000944_1_2 * 2)) - pub_r000944_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((((stage_v_80_1 * 3) + (sec_r000944_10_1 * 2)) - pub_r000944_3_1) + 22) & 127;
  int stage_v_174_2 = ((((stage_v_80_2 * 3) + (sec_r000944_10_2 * 2)) - pub_r000944_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((((sec_r000944_4_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_8_1) + 23) & 127;
  int stage_v_175_2 = ((((sec_r000944_4_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((((stage_v_127_1 * 3) + (sec_r000944_7_1 * 2)) - pub_r000944_6_1) + 23) & 127;
  int stage_v_176_2 = ((((stage_v_127_2 * 3) + (sec_r000944_7_2 * 2)) - pub_r000944_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((((stage_v_150_1 * 3) + (sec_r000944_12_1 * 2)) - pub_r000944_3_1) + 27) & 127;
  int stage_v_177_2 = ((((stage_v_150_2 * 3) + (sec_r000944_12_2 * 2)) - pub_r000944_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((((stage_v_121_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_14_1) + 28) & 127;
  int stage_v_178_2 = ((((stage_v_121_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((((stage_v_133_1 * 3) + (sec_r000944_14_1 * 2)) - pub_r000944_17_1) + 35) & 127;
  int stage_v_179_2 = ((((stage_v_133_2 * 3) + (sec_r000944_14_2 * 2)) - pub_r000944_17_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((((stage_v_144_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_7_1) + 14) & 127;
  int stage_v_180_2 = ((((stage_v_144_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((((sec_r000944_14_1 * 3) + (sec_r000944_14_1 * 2)) - pub_r000944_16_1) + 33) & 127;
  int stage_v_181_2 = ((((sec_r000944_14_2 * 3) + (sec_r000944_14_2 * 2)) - pub_r000944_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((((stage_v_104_1 * 3) + (sec_r000944_6_1 * 2)) - pub_r000944_22_1) + 19) & 127;
  int stage_v_182_2 = ((((stage_v_104_2 * 3) + (sec_r000944_6_2 * 2)) - pub_r000944_22_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((((stage_v_109_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_5_1) + 10) & 127;
  int stage_v_183_2 = ((((stage_v_109_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((((stage_v_116_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_12_1) + 10) & 127;
  int stage_v_184_2 = ((((stage_v_116_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((((sec_r000944_0_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_11_1) + 18) & 127;
  int stage_v_185_2 = ((((sec_r000944_0_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_11_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((((stage_v_97_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_16_1) + 5) & 127;
  int stage_v_186_2 = ((((stage_v_97_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_16_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((((sec_r000944_10_1 * 3) + (sec_r000944_10_1 * 2)) - pub_r000944_9_1) + 36) & 127;
  int stage_v_187_2 = ((((sec_r000944_10_2 * 3) + (sec_r000944_10_2 * 2)) - pub_r000944_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((((stage_v_156_1 * 3) + (sec_r000944_8_1 * 2)) - pub_r000944_8_1) + 12) & 127;
  int stage_v_188_2 = ((((stage_v_156_2 * 3) + (sec_r000944_8_2 * 2)) - pub_r000944_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((((stage_v_181_1 * 3) + (sec_r000944_10_1 * 2)) - pub_r000944_23_1) + 13) & 127;
  int stage_v_189_2 = ((((stage_v_181_2 * 3) + (sec_r000944_10_2 * 2)) - pub_r000944_23_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((((stage_v_144_1 * 3) + (sec_r000944_3_1 * 2)) - pub_r000944_14_1) + 9) & 127;
  int stage_v_190_2 = ((((stage_v_144_2 * 3) + (sec_r000944_3_2 * 2)) - pub_r000944_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((((stage_v_107_1 * 3) + (sec_r000944_1_1 * 2)) - pub_r000944_7_1) + 13) & 127;
  int stage_v_191_2 = ((((stage_v_107_2 * 3) + (sec_r000944_1_2 * 2)) - pub_r000944_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((((stage_v_191_1 * 3) + (sec_r000944_10_1 * 2)) - pub_r000944_14_1) + 18) & 127;
  int stage_v_192_2 = ((((stage_v_191_2 * 3) + (sec_r000944_10_2 * 2)) - pub_r000944_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((((stage_v_100_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_8_1) + 22) & 127;
  int stage_v_193_2 = ((((stage_v_100_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((((sec_r000944_15_1 * 3) + (sec_r000944_15_1 * 2)) - pub_r000944_16_1) + 37) & 127;
  int stage_v_194_2 = ((((sec_r000944_15_2 * 3) + (sec_r000944_15_2 * 2)) - pub_r000944_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((((stage_v_194_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_6_1) + 16) & 127;
  int stage_v_195_2 = ((((stage_v_194_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((((stage_v_168_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_2_1) + 26) & 127;
  int stage_v_196_2 = ((((stage_v_168_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((((sec_r000944_3_1 * 3) + (sec_r000944_3_1 * 2)) - pub_r000944_14_1) + 5) & 127;
  int stage_v_197_2 = ((((sec_r000944_3_2 * 3) + (sec_r000944_3_2 * 2)) - pub_r000944_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((((stage_v_140_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_8_1) + 7) & 127;
  int stage_v_198_2 = ((((stage_v_140_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((((sec_r000944_2_1 * 3) + (sec_r000944_2_1 * 2)) - pub_r000944_2_1) + 13) & 127;
  int stage_v_199_2 = ((((sec_r000944_2_2 * 3) + (sec_r000944_2_2 * 2)) - pub_r000944_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((((stage_v_187_1 * 3) + (sec_r000944_8_1 * 2)) - pub_r000944_18_1) + 16) & 127;
  int stage_v_200_2 = ((((stage_v_187_2 * 3) + (sec_r000944_8_2 * 2)) - pub_r000944_18_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((((stage_v_82_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_10_1) + 29) & 127;
  int stage_v_201_2 = ((((stage_v_82_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((((stage_v_177_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_4_1) + 6) & 127;
  int stage_v_202_2 = ((((stage_v_177_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((((sec_r000944_11_1 * 3) + (sec_r000944_11_1 * 2)) - pub_r000944_2_1) + 12) & 127;
  int stage_v_203_2 = ((((sec_r000944_11_2 * 3) + (sec_r000944_11_2 * 2)) - pub_r000944_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((((stage_v_127_1 * 3) + (sec_r000944_3_1 * 2)) - pub_r000944_3_1) + 19) & 127;
  int stage_v_204_2 = ((((stage_v_127_2 * 3) + (sec_r000944_3_2 * 2)) - pub_r000944_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((((stage_v_169_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_3_1) + 6) & 127;
  int stage_v_205_2 = ((((stage_v_169_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((((sec_r000944_5_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_8_1) + 6) & 127;
  int stage_v_206_2 = ((((sec_r000944_5_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((((sec_r000944_4_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_14_1) + 11) & 127;
  int stage_v_207_2 = ((((sec_r000944_4_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((((stage_v_169_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_2_1) + 4) & 127;
  int stage_v_208_2 = ((((stage_v_169_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((((stage_v_115_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_19_1) + 35) & 127;
  int stage_v_209_2 = ((((stage_v_115_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_19_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((((stage_v_104_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_1_1) + 32) & 127;
  int stage_v_210_2 = ((((stage_v_104_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((((sec_r000944_2_1 * 3) + (sec_r000944_2_1 * 2)) - pub_r000944_14_1) + 30) & 127;
  int stage_v_211_2 = ((((sec_r000944_2_2 * 3) + (sec_r000944_2_2 * 2)) - pub_r000944_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((((stage_v_194_1 * 3) + (sec_r000944_3_1 * 2)) - pub_r000944_12_1) + 16) & 127;
  int stage_v_212_2 = ((((stage_v_194_2 * 3) + (sec_r000944_3_2 * 2)) - pub_r000944_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((((sec_r000944_9_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_18_1) + 8) & 127;
  int stage_v_213_2 = ((((sec_r000944_9_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_18_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_213_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_213_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((((stage_v_117_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_8_1) + 17) & 127;
  int stage_v_214_2 = ((((stage_v_117_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((((stage_v_122_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_12_1) + 25) & 127;
  int stage_v_215_2 = ((((stage_v_122_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_215_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_215_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((((sec_r000944_5_1 * 3) + (sec_r000944_5_1 * 2)) - pub_r000944_2_1) + 4) & 127;
  int stage_v_216_2 = ((((sec_r000944_5_2 * 3) + (sec_r000944_5_2 * 2)) - pub_r000944_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_216_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_216_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((((stage_v_110_1 * 3) + (sec_r000944_3_1 * 2)) - pub_r000944_18_1) + 25) & 127;
  int stage_v_217_2 = ((((stage_v_110_2 * 3) + (sec_r000944_3_2 * 2)) - pub_r000944_18_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_217_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_217_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((((sec_r000944_4_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_23_1) + 10) & 127;
  int stage_v_218_2 = ((((sec_r000944_4_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_23_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_218_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_218_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((((sec_r000944_1_1 * 3) + (sec_r000944_1_1 * 2)) - pub_r000944_14_1) + 22) & 127;
  int stage_v_219_2 = ((((sec_r000944_1_2 * 3) + (sec_r000944_1_2 * 2)) - pub_r000944_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_219_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_219_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((((stage_v_176_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_8_1) + 32) & 127;
  int stage_v_220_2 = ((((stage_v_176_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_220_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_220_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((((stage_v_162_1 * 3) + (sec_r000944_7_1 * 2)) - pub_r000944_2_1) + 7) & 127;
  int stage_v_221_2 = ((((stage_v_162_2 * 3) + (sec_r000944_7_2 * 2)) - pub_r000944_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_221_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_221_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((((stage_v_102_1 * 3) + (sec_r000944_7_1 * 2)) - pub_r000944_0_1) + 36) & 127;
  int stage_v_222_2 = ((((stage_v_102_2 * 3) + (sec_r000944_7_2 * 2)) - pub_r000944_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_222_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_222_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((((stage_v_127_1 * 3) + (sec_r000944_14_1 * 2)) - pub_r000944_2_1) + 25) & 127;
  int stage_v_223_2 = ((((stage_v_127_2 * 3) + (sec_r000944_14_2 * 2)) - pub_r000944_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_223_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_223_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((((stage_v_123_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_5_1) + 31) & 127;
  int stage_v_224_2 = ((((stage_v_123_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_224_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_224_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((((stage_v_172_1 * 3) + (sec_r000944_15_1 * 2)) - pub_r000944_8_1) + 15) & 127;
  int stage_v_225_2 = ((((stage_v_172_2 * 3) + (sec_r000944_15_2 * 2)) - pub_r000944_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_225_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_225_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((((stage_v_127_1 * 3) + (sec_r000944_14_1 * 2)) - pub_r000944_12_1) + 19) & 127;
  int stage_v_226_2 = ((((stage_v_127_2 * 3) + (sec_r000944_14_2 * 2)) - pub_r000944_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_226_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_226_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((((sec_r000944_1_1 * 3) + (sec_r000944_1_1 * 2)) - pub_r000944_10_1) + 30) & 127;
  int stage_v_227_2 = ((((sec_r000944_1_2 * 3) + (sec_r000944_1_2 * 2)) - pub_r000944_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_227_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_227_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((((stage_v_72_1 * 3) + (sec_r000944_9_1 * 2)) - pub_r000944_20_1) + 13) & 127;
  int stage_v_228_2 = ((((stage_v_72_2 * 3) + (sec_r000944_9_2 * 2)) - pub_r000944_20_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_228_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_228_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((((stage_v_211_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_16_1) + 32) & 127;
  int stage_v_229_2 = ((((stage_v_211_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_229_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_229_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((((stage_v_225_1 * 3) + (sec_r000944_6_1 * 2)) - pub_r000944_2_1) + 28) & 127;
  int stage_v_230_2 = ((((stage_v_225_2 * 3) + (sec_r000944_6_2 * 2)) - pub_r000944_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_230_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_230_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((((stage_v_82_1 * 3) + (sec_r000944_14_1 * 2)) - pub_r000944_14_1) + 36) & 127;
  int stage_v_231_2 = ((((stage_v_82_2 * 3) + (sec_r000944_14_2 * 2)) - pub_r000944_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_231_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_231_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((((sec_r000944_7_1 * 3) + (sec_r000944_7_1 * 2)) - pub_r000944_10_1) + 33) & 127;
  int stage_v_232_2 = ((((sec_r000944_7_2 * 3) + (sec_r000944_7_2 * 2)) - pub_r000944_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_232_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_232_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((((sec_r000944_3_1 * 3) + (sec_r000944_3_1 * 2)) - pub_r000944_21_1) + 17) & 127;
  int stage_v_233_2 = ((((sec_r000944_3_2 * 3) + (sec_r000944_3_2 * 2)) - pub_r000944_21_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_233_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_233_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((((stage_v_145_1 * 3) + (sec_r000944_8_1 * 2)) - pub_r000944_20_1) + 7) & 127;
  int stage_v_234_2 = ((((stage_v_145_2 * 3) + (sec_r000944_8_2 * 2)) - pub_r000944_20_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_234_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_234_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((((sec_r000944_13_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_9_1) + 13) & 127;
  int stage_v_235_2 = ((((sec_r000944_13_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_235_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_235_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((((sec_r000944_6_1 * 3) + (sec_r000944_6_1 * 2)) - pub_r000944_19_1) + 20) & 127;
  int stage_v_236_2 = ((((sec_r000944_6_2 * 3) + (sec_r000944_6_2 * 2)) - pub_r000944_19_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_236_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_236_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((((stage_v_199_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_1_1) + 25) & 127;
  int stage_v_237_2 = ((((stage_v_199_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_237_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_237_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((((stage_v_139_1 * 3) + (sec_r000944_2_1 * 2)) - pub_r000944_1_1) + 16) & 127;
  int stage_v_238_2 = ((((stage_v_139_2 * 3) + (sec_r000944_2_2 * 2)) - pub_r000944_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_238_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_238_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((((stage_v_141_1 * 3) + (sec_r000944_4_1 * 2)) - pub_r000944_17_1) + 37) & 127;
  int stage_v_239_2 = ((((stage_v_141_2 * 3) + (sec_r000944_4_2 * 2)) - pub_r000944_17_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_239_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_239_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((((stage_v_172_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_8_1) + 35) & 127;
  int stage_v_240_2 = ((((stage_v_172_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_240_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_240_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((((sec_r000944_0_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_16_1) + 3) & 127;
  int stage_v_241_2 = ((((sec_r000944_0_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_16_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_241_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_241_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((((stage_v_191_1 * 3) + (sec_r000944_6_1 * 2)) - pub_r000944_0_1) + 19) & 127;
  int stage_v_242_2 = ((((stage_v_191_2 * 3) + (sec_r000944_6_2 * 2)) - pub_r000944_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_242_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_242_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((((stage_v_162_1 * 3) + (sec_r000944_3_1 * 2)) - pub_r000944_15_1) + 17) & 127;
  int stage_v_243_2 = ((((stage_v_162_2 * 3) + (sec_r000944_3_2 * 2)) - pub_r000944_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_243_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_243_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((((stage_v_237_1 * 3) + (sec_r000944_13_1 * 2)) - pub_r000944_10_1) + 12) & 127;
  int stage_v_244_2 = ((((stage_v_237_2 * 3) + (sec_r000944_13_2 * 2)) - pub_r000944_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_244_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_244_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((((stage_v_126_1 * 3) + (sec_r000944_14_1 * 2)) - pub_r000944_18_1) + 22) & 127;
  int stage_v_245_2 = ((((stage_v_126_2 * 3) + (sec_r000944_14_2 * 2)) - pub_r000944_18_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_245_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_245_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((((stage_v_165_1 * 3) + (sec_r000944_15_1 * 2)) - pub_r000944_23_1) + 7) & 127;
  int stage_v_246_2 = ((((stage_v_165_2 * 3) + (sec_r000944_15_2 * 2)) - pub_r000944_23_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_246_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_246_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((((stage_v_150_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_3_1) + 10) & 127;
  int stage_v_247_2 = ((((stage_v_150_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_247_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_247_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((((stage_v_98_1 * 3) + (sec_r000944_6_1 * 2)) - pub_r000944_13_1) + 12) & 127;
  int stage_v_248_2 = ((((stage_v_98_2 * 3) + (sec_r000944_6_2 * 2)) - pub_r000944_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_248_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_248_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((((sec_r000944_11_1 * 3) + (sec_r000944_11_1 * 2)) - pub_r000944_1_1) + 12) & 127;
  int stage_v_249_2 = ((((sec_r000944_11_2 * 3) + (sec_r000944_11_2 * 2)) - pub_r000944_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_249_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_249_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((((stage_v_145_1 * 3) + (sec_r000944_11_1 * 2)) - pub_r000944_0_1) + 37) & 127;
  int stage_v_250_2 = ((((stage_v_145_2 * 3) + (sec_r000944_11_2 * 2)) - pub_r000944_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_250_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_250_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((((stage_v_247_1 * 3) + (sec_r000944_7_1 * 2)) - pub_r000944_16_1) + 29) & 127;
  int stage_v_251_2 = ((((stage_v_247_2 * 3) + (sec_r000944_7_2 * 2)) - pub_r000944_16_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_251_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_251_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((((stage_v_124_1 * 3) + (sec_r000944_14_1 * 2)) - pub_r000944_19_1) + 32) & 127;
  int stage_v_252_2 = ((((stage_v_124_2 * 3) + (sec_r000944_14_2 * 2)) - pub_r000944_19_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_252_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_252_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((((stage_v_135_1 * 3) + (sec_r000944_11_1 * 2)) - pub_r000944_9_1) + 26) & 127;
  int stage_v_253_2 = ((((stage_v_135_2 * 3) + (sec_r000944_11_2 * 2)) - pub_r000944_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_253_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_253_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((((sec_r000944_0_1 * 3) + (sec_r000944_0_1 * 2)) - pub_r000944_21_1) + 23) & 127;
  int stage_v_254_2 = ((((sec_r000944_0_2 * 3) + (sec_r000944_0_2 * 2)) - pub_r000944_21_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_254_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_254_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((((stage_v_239_1 * 3) + (sec_r000944_6_1 * 2)) - pub_r000944_11_1) + 9) & 127;
  int stage_v_255_2 = ((((stage_v_239_2 * 3) + (sec_r000944_6_2 * 2)) - pub_r000944_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_255_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_255_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((((sec_r000944_10_1 * 3) + (sec_r000944_10_1 * 2)) - pub_r000944_10_1) + 28) & 127;
  int stage_v_256_2 = ((((sec_r000944_10_2 * 3) + (sec_r000944_10_2 * 2)) - pub_r000944_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_256_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_256_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000944_3_1 == pub_r000944_3_2);
  __CPROVER_assume(pub_r000944_2_1 == pub_r000944_2_2);
  __CPROVER_assume(sec_r000944_6_1 != sec_r000944_6_2);
  __CPROVER_assume(pub_r000944_0_1 == pub_r000944_0_2);
  __CPROVER_assume(pub_r000944_11_1 == pub_r000944_11_2);
  __CPROVER_assume(pub_r000944_4_1 == pub_r000944_4_2);
  __CPROVER_assume(pub_r000944_6_1 == pub_r000944_6_2);
  __CPROVER_assume(sec_r000944_4_1 != sec_r000944_4_2);
  __CPROVER_assume(pub_r000944_17_1 == pub_r000944_17_2);
  __CPROVER_assume(sec_r000944_2_1 != sec_r000944_2_2);
  __CPROVER_assume(pub_r000944_12_1 == pub_r000944_12_2);
  __CPROVER_assume(pub_r000944_20_1 == pub_r000944_20_2);
  __CPROVER_assume(pub_r000944_18_1 == pub_r000944_18_2);
  __CPROVER_assume(pub_r000944_21_1 == pub_r000944_21_2);
  __CPROVER_assume(pub_r000944_15_1 == pub_r000944_15_2);
  __CPROVER_assume(sec_r000944_5_1 != sec_r000944_5_2);
  __CPROVER_assume(sec_r000944_14_1 != sec_r000944_14_2);
  __CPROVER_assume(sec_r000944_1_1 != sec_r000944_1_2);
  __CPROVER_assume(pub_r000944_5_1 == pub_r000944_5_2);
  __CPROVER_assume(sec_r000944_13_1 != sec_r000944_13_2);
  __CPROVER_assume(sec_r000944_10_1 != sec_r000944_10_2);
  __CPROVER_assume(sec_r000944_12_1 != sec_r000944_12_2);
  __CPROVER_assume(sec_r000944_15_1 != sec_r000944_15_2);
  __CPROVER_assume(pub_r000944_22_1 == pub_r000944_22_2);
  __CPROVER_assume(sec_r000944_8_1 != sec_r000944_8_2);
  __CPROVER_assume(sec_r000944_9_1 != sec_r000944_9_2);
  __CPROVER_assume(sec_r000944_7_1 != sec_r000944_7_2);
  __CPROVER_assume(sec_r000944_11_1 != sec_r000944_11_2);
  __CPROVER_assume(pub_r000944_14_1 == pub_r000944_14_2);
  __CPROVER_assume(pub_r000944_10_1 == pub_r000944_10_2);
  __CPROVER_assume(pub_r000944_1_1 == pub_r000944_1_2);
  __CPROVER_assume(pub_r000944_23_1 == pub_r000944_23_2);
  __CPROVER_assume(pub_r000944_19_1 == pub_r000944_19_2);
  __CPROVER_assume(pub_r000944_8_1 == pub_r000944_8_2);
  __CPROVER_assume(pub_r000944_13_1 == pub_r000944_13_2);
  __CPROVER_assume(sec_r000944_3_1 != sec_r000944_3_2);
  __CPROVER_assume(pub_r000944_9_1 == pub_r000944_9_2);
  __CPROVER_assume(sec_r000944_0_1 != sec_r000944_0_2);
  __CPROVER_assume(pub_r000944_7_1 == pub_r000944_7_2);
  __CPROVER_assume(pub_r000944_16_1 == pub_r000944_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
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
}


