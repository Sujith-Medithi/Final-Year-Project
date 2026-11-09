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
struct StreamBuffer_R001776_7613_0
{
  int capacity;
  unsigned char head;
  short checksum;
  unsigned char watermark;
  int buffer[3];
};
struct AudioFrame_R001776_7613_1
{
  int gain;
  unsigned char rms;
  short sample_rate;
  int buffer[3];
};
struct DeviceConfig_R001776_7613_2
{
  int id;
  int timeout;
  int baud_rate;
  int port;
  int buffer[3];
};
union TelemetryField_R001776_7613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001776_7613_1
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
void fn_R001776_7613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001776_7613_1 st_1 = {0};
  struct AudioFrame_R001776_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_21_1 > 32)
  {
    acc_1 = ((acc_1 + (offset_21_1 * 2)) + 5) & 127;
    aux_1 ^= offset_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_21_2 > 32)
  {
    acc_2 = ((acc_2 + (offset_21_2 * 2)) + 5) & 127;
    aux_2 ^= offset_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_46_1)
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

  switch (cursor_46_2)
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

  int offset_19_1 = 0;
  int offset_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_19_1 = ((offset_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_19_2 = ((offset_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_19_1) & 127;
    acc_2 = (acc_2 + offset_19_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_21_1 == offset_21_2);
  assert(cursor_46_1 == cursor_46_2);
  assert(offset_19_1 == offset_19_2);
}

int fn_R001776_7613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001776_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_21 > 32)
  {
    acc = ((acc + (offset_21 * 2)) + 5) & 127;
    aux ^= offset_21 & 15;
  }
  else
  {
    acc = ((acc - offset_21) + 11) & 127;
    aux += 3;
  }
  int cursor_46 = (aux + st.buffer[1]) & 3;
  switch (cursor_46)
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

  int offset_19 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_19 = ((offset_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_19) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001776_7613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st_1 = {0};
  struct DeviceConfig_R001776_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int cursor_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_61_1)
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

  switch (cursor_61_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_61_1 == cursor_61_2);
}

int fn_R001776_7613_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int cursor_61 = (aux + st.buffer[1]) & 3;
  switch (cursor_61)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001776_7613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st_1 = {0};
  struct StreamBuffer_R001776_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_88_1 = local_arr_1[aux_1 % 3];
  int coefficient_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_88_2 * 2)) & 127;
  int quotient_20_1 = 0;
  int quotient_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_20_1 = ((quotient_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_20_2 = ((quotient_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_20_1) & 127;
    acc_2 = (acc_2 + quotient_20_2) & 127;
  }

  int stride_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_47_1 > 46)
  {
    acc_1 = ((acc_1 + (stride_47_1 * 2)) + 5) & 127;
    aux_1 ^= stride_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_47_2 > 46)
  {
    acc_2 = ((acc_2 + (stride_47_2 * 2)) + 5) & 127;
    aux_2 ^= stride_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_46_1)
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

  switch (pivot_46_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_88_1 == coefficient_88_2);
  assert(quotient_20_1 == quotient_20_2);
  assert(stride_47_1 == stride_47_2);
  assert(pivot_46_1 == pivot_46_2);
}

int fn_R001776_7613_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int coefficient_88 = local_arr[aux % 3];
  acc = (acc + (coefficient_88 * 2)) & 127;
  int quotient_20 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_20 = ((quotient_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_20) & 127;
  }

  int stride_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_47 > 46)
  {
    acc = ((acc + (stride_47 * 2)) + 5) & 127;
    aux ^= stride_47 & 15;
  }
  else
  {
    acc = ((acc - stride_47) + 11) & 127;
    aux += 3;
  }
  int pivot_46 = (aux + st.buffer[1]) & 3;
  switch (pivot_46)
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

void fn_R001776_7613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001776_7613_1 st_1 = {0};
  struct AudioFrame_R001776_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int pivot_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_54_1) & 63;
  aux_2 = (aux_2 + pivot_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_75_1 > 26)
  {
    acc_1 = ((acc_1 + (quotient_75_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_75_2 > 26)
  {
    acc_2 = ((acc_2 + (quotient_75_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_75_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_54_1 == pivot_54_2);
  assert(quotient_75_1 == quotient_75_2);
}

int fn_R001776_7613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001776_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int pivot_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_54) & 63;
  acc ^= aux;
  int quotient_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_75 > 26)
  {
    acc = ((acc + (quotient_75 * 2)) + 5) & 127;
    aux ^= quotient_75 & 15;
  }
  else
  {
    acc = ((acc - quotient_75) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001776_7613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st_1 = {0};
  struct StreamBuffer_R001776_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_44_1 = local_arr_1[aux_1 % 3];
  int tracker_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_44_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_44_1 == tracker_44_2);
}

int fn_R001776_7613_4(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int tracker_44 = local_arr[aux % 3];
  acc = (acc + (tracker_44 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001776_7613_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st_1 = {0};
  struct DeviceConfig_R001776_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int vector_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_58_1) & 63;
  aux_2 = (aux_2 + vector_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_12_1 = local_arr_1[aux_1 % 3];
  int coefficient_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_58_1 == vector_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_12_1 == coefficient_12_2);
}

int fn_R001776_7613_5(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int vector_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_58) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_12 = local_arr[aux % 3];
  acc = (acc + (coefficient_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001776_7613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001776_7613_1 st_1 = {0};
  struct AudioFrame_R001776_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tally_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_11_1)
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

  switch (tally_11_2)
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

  int index_reg_87_1 = 0;
  int index_reg_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_87_1 = ((index_reg_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_87_2 = ((index_reg_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_87_1) & 127;
    acc_2 = (acc_2 + index_reg_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_11_1 == tally_11_2);
  assert(index_reg_87_1 == index_reg_87_2);
}

int fn_R001776_7613_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001776_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tally_11 = (aux + st.buffer[1]) & 3;
  switch (tally_11)
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

  int index_reg_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_87 = ((index_reg_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001776_7613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001776_7613_1 st_1 = {0};
  struct AudioFrame_R001776_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int bound_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_63_1)
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

  switch (bound_63_2)
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

  int margin_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_43_1) & 63;
  aux_2 = (aux_2 + margin_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_19_1 = local_arr_1[aux_1 % 3];
  int accumulator_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_63_1 == bound_63_2);
  assert(margin_43_1 == margin_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_19_1 == accumulator_19_2);
}

int fn_R001776_7613_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001776_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int bound_63 = (aux + st.buffer[1]) & 3;
  switch (bound_63)
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

  int margin_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_43) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_19 = local_arr[aux % 3];
  acc = (acc + (accumulator_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001776_7613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st_1 = {0};
  struct StreamBuffer_R001776_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int cursor_24_1 = 0;
  int cursor_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_24_1 = ((cursor_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_24_2 = ((cursor_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_24_1) & 127;
    acc_2 = (acc_2 + cursor_24_2) & 127;
  }

  int coefficient_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_74_1 > 28)
  {
    acc_1 = ((acc_1 + (coefficient_74_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_74_2 > 28)
  {
    acc_2 = ((acc_2 + (coefficient_74_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_74_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_24_1 == cursor_24_2);
  assert(coefficient_74_1 == coefficient_74_2);
}

int fn_R001776_7613_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int cursor_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_24 = ((cursor_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_24) & 127;
  }

  int coefficient_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_74 > 28)
  {
    acc = ((acc + (coefficient_74 * 2)) + 5) & 127;
    aux ^= coefficient_74 & 15;
  }
  else
  {
    acc = ((acc - coefficient_74) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001776_7613_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st_1 = {0};
  struct DeviceConfig_R001776_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int tracker_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_72_1 > 12)
  {
    acc_1 = ((acc_1 + (tracker_72_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_72_2 > 12)
  {
    acc_2 = ((acc_2 + (tracker_72_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_18_1) & 63;
  aux_2 = (aux_2 + parity_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_72_1 == tracker_72_2);
  assert(parity_18_1 == parity_18_2);
}

int fn_R001776_7613_9(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int tracker_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_72 > 12)
  {
    acc = ((acc + (tracker_72 * 2)) + 5) & 127;
    aux ^= tracker_72 & 15;
  }
  else
  {
    acc = ((acc - tracker_72) + 11) & 127;
    aux += 3;
  }
  int parity_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_18) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001776_7613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st_1 = {0};
  struct StreamBuffer_R001776_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int stride_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_11_1 > 50)
  {
    acc_1 = ((acc_1 + (stride_11_1 * 2)) + 5) & 127;
    aux_1 ^= stride_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_11_2 > 50)
  {
    acc_2 = ((acc_2 + (stride_11_2 * 2)) + 5) & 127;
    aux_2 ^= stride_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_11_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_11_1 == stride_11_2);
}

int fn_R001776_7613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int stride_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_11 > 50)
  {
    acc = ((acc + (stride_11 * 2)) + 5) & 127;
    aux ^= stride_11 & 15;
  }
  else
  {
    acc = ((acc - stride_11) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001776_7613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st_1 = {0};
  struct StreamBuffer_R001776_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_83_1 > 13)
  {
    acc_1 = ((acc_1 + (coefficient_83_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_83_2 > 13)
  {
    acc_2 = ((acc_2 + (coefficient_83_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_83_1 == coefficient_83_2);
}

int fn_R001776_7613_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_83 > 13)
  {
    acc = ((acc + (coefficient_83 * 2)) + 5) & 127;
    aux ^= coefficient_83 & 15;
  }
  else
  {
    acc = ((acc - coefficient_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001776_7613_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st_1 = {0};
  struct DeviceConfig_R001776_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int checksum_42_1 = 0;
  int checksum_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_42_1 = ((checksum_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_42_2 = ((checksum_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_42_1) & 127;
    acc_2 = (acc_2 + checksum_42_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_67_1 = local_arr_1[aux_1 % 3];
  int index_reg_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_67_2 * 2)) & 127;
  int coefficient_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_51_1) & 63;
  aux_2 = (aux_2 + coefficient_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_42_1 == checksum_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_67_1 == index_reg_67_2);
  assert(coefficient_51_1 == coefficient_51_2);
}

int fn_R001776_7613_12(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int checksum_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_42 = ((checksum_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_42) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int index_reg_67 = local_arr[aux % 3];
  acc = (acc + (index_reg_67 * 2)) & 127;
  int coefficient_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_51) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001776_7613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st_1 = {0};
  struct DeviceConfig_R001776_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_62_1 = local_arr_1[aux_1 % 3];
  int metric_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_62_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_26_1 = 0;
  int window_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_26_1 = ((window_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_26_2 = ((window_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_26_1) & 127;
    acc_2 = (acc_2 + window_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_62_1 == metric_62_2);
  assert(window_26_1 == window_26_2);
}

int fn_R001776_7613_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int metric_62 = local_arr[aux % 3];
  acc = (acc + (metric_62 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_26 = ((window_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_26) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001776_7613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st_1 = {0};
  struct StreamBuffer_R001776_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int index_reg_75_1 = 0;
  int index_reg_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_75_1 = ((index_reg_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_75_2 = ((index_reg_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_75_1) & 127;
    acc_2 = (acc_2 + index_reg_75_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_75_1 == index_reg_75_2);
}

int fn_R001776_7613_14(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int index_reg_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_75 = ((index_reg_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_75) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001776_7613_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st_1 = {0};
  struct DeviceConfig_R001776_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int phase_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_71_1)
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

  switch (phase_71_2)
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

  int segment_54_1 = 0;
  int segment_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_54_1 = ((segment_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_54_2 = ((segment_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_54_1) & 127;
    acc_2 = (acc_2 + segment_54_2) & 127;
  }

  int quotient_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_51_1) & 63;
  aux_2 = (aux_2 + quotient_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_71_1 == phase_71_2);
  assert(segment_54_1 == segment_54_2);
  assert(quotient_51_1 == quotient_51_2);
}

int fn_R001776_7613_15(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int phase_71 = (aux + st.buffer[1]) & 3;
  switch (phase_71)
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

  int segment_54 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_54 = ((segment_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_54) & 127;
  }

  int quotient_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_51) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001776_7613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st_1 = {0};
  struct StreamBuffer_R001776_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_98_1 = local_arr_1[aux_1 % 3];
  int mask_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_98_2 * 2)) & 127;
  int offset_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_20_1 > 36)
  {
    acc_1 = ((acc_1 + (offset_20_1 * 2)) + 5) & 127;
    aux_1 ^= offset_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_20_2 > 36)
  {
    acc_2 = ((acc_2 + (offset_20_2 * 2)) + 5) & 127;
    aux_2 ^= offset_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_98_1 == mask_98_2);
  assert(offset_20_1 == offset_20_2);
}

int fn_R001776_7613_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_98 = local_arr[aux % 3];
  acc = (acc + (mask_98 * 2)) & 127;
  int offset_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_20 > 36)
  {
    acc = ((acc + (offset_20 * 2)) + 5) & 127;
    aux ^= offset_20 & 15;
  }
  else
  {
    acc = ((acc - offset_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001776_7613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001776_7613_1 st_1 = {0};
  struct AudioFrame_R001776_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_66_1 = local_arr_1[aux_1 % 3];
  int checksum_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_66_2 * 2)) & 127;
  int anchor_80_1 = 0;
  int anchor_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_80_1 = ((anchor_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_80_2 = ((anchor_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_80_1) & 127;
    acc_2 = (acc_2 + anchor_80_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
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

  assert(checksum_66_1 == checksum_66_2);
  assert(anchor_80_1 == anchor_80_2);
}

int fn_R001776_7613_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001776_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int checksum_66 = local_arr[aux % 3];
  acc = (acc + (checksum_66 * 2)) & 127;
  int anchor_80 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_80 = ((anchor_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_80) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001776_7613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001776_7613_1 st_1 = {0};
  struct AudioFrame_R001776_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_64_1)
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

  switch (offset_64_2)
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

  int bound_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_24_1) & 63;
  aux_2 = (aux_2 + bound_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_64_1 == offset_64_2);
  assert(bound_24_1 == bound_24_2);
}

int fn_R001776_7613_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001776_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_64 = (aux + st.buffer[1]) & 3;
  switch (offset_64)
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

  int bound_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_24) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001776_7613_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st_1 = {0};
  struct StreamBuffer_R001776_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int offset_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_38_1)
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

  switch (offset_38_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_96_1 = local_arr_1[aux_1 % 3];
  int metric_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_96_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_38_1 == offset_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_96_1 == metric_96_2);
}

int fn_R001776_7613_19(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int offset_38 = (aux + st.buffer[1]) & 3;
  switch (offset_38)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_96 = local_arr[aux % 3];
  acc = (acc + (metric_96 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001776_7613_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st_1 = {0};
  struct StreamBuffer_R001776_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int mask_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_52_1)
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

  switch (mask_52_2)
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
  int phase_39_1 = local_arr_1[aux_1 % 3];
  int phase_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_39_2 * 2)) & 127;
  int weight_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_85_1) & 63;
  aux_2 = (aux_2 + weight_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_15_1 = 0;
  int weight_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_15_1 = ((weight_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_15_2 = ((weight_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_15_1) & 127;
    acc_2 = (acc_2 + weight_15_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_52_1 == mask_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_39_1 == phase_39_2);
  assert(weight_85_1 == weight_85_2);
  assert(weight_15_1 == weight_15_2);
}

int fn_R001776_7613_20(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int mask_52 = (aux + st.buffer[1]) & 3;
  switch (mask_52)
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
  int phase_39 = local_arr[aux % 3];
  acc = (acc + (phase_39 * 2)) & 127;
  int weight_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_85) & 63;
  acc ^= aux;
  int weight_15 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_15 = ((weight_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_15) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001776_7613_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st_1 = {0};
  struct DeviceConfig_R001776_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int quantum_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_90_1)
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

  switch (quantum_90_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_90_1 == quantum_90_2);
}

int fn_R001776_7613_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001776_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int quantum_90 = (aux + st.buffer[1]) & 3;
  switch (quantum_90)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001776_7613_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st_1 = {0};
  struct StreamBuffer_R001776_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int index_reg_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_91_1) & 63;
  aux_2 = (aux_2 + index_reg_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_83_1 > 38)
  {
    acc_1 = ((acc_1 + (mask_83_1 * 2)) + 5) & 127;
    aux_1 ^= mask_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_83_2 > 38)
  {
    acc_2 = ((acc_2 + (mask_83_2 * 2)) + 5) & 127;
    aux_2 ^= mask_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_87_1 = 0;
  int tally_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_87_1 = ((tally_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_87_2 = ((tally_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_87_1) & 127;
    acc_2 = (acc_2 + tally_87_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_90_1 = local_arr_1[aux_1 % 3];
  int tracker_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_91_1 == index_reg_91_2);
  assert(mask_83_1 == mask_83_2);
  assert(tally_87_1 == tally_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_90_1 == tracker_90_2);
}

int fn_R001776_7613_22(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001776_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int index_reg_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_91) & 63;
  acc ^= aux;
  int mask_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_83 > 38)
  {
    acc = ((acc + (mask_83 * 2)) + 5) & 127;
    aux ^= mask_83 & 15;
  }
  else
  {
    acc = ((acc - mask_83) + 11) & 127;
    aux += 3;
  }
  int tally_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_87 = ((tally_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_87) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tracker_90 = local_arr[aux % 3];
  acc = (acc + (tracker_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001776_0_1;
  int sec_r001776_0_2;
  int sec_r001776_1_1;
  int sec_r001776_1_2;
  int sec_r001776_2_1;
  int sec_r001776_2_2;
  int sec_r001776_3_1;
  int sec_r001776_3_2;
  int sec_r001776_4_1;
  int sec_r001776_4_2;
  int sec_r001776_5_1;
  int sec_r001776_5_2;
  int sec_r001776_6_1;
  int sec_r001776_6_2;
  int sec_r001776_7_1;
  int sec_r001776_7_2;
  int sec_r001776_8_1;
  int sec_r001776_8_2;
  int sec_r001776_9_1;
  int sec_r001776_9_2;
  int sec_r001776_10_1;
  int sec_r001776_10_2;
  int sec_r001776_11_1;
  int sec_r001776_11_2;
  int sec_r001776_12_1;
  int sec_r001776_12_2;
  int sec_r001776_13_1;
  int sec_r001776_13_2;
  int sec_r001776_14_1;
  int sec_r001776_14_2;
  int sec_r001776_15_1;
  int sec_r001776_15_2;
  int pub_r001776_0_1;
  int pub_r001776_0_2;
  int pub_r001776_1_1;
  int pub_r001776_1_2;
  int pub_r001776_2_1;
  int pub_r001776_2_2;
  int pub_r001776_3_1;
  int pub_r001776_3_2;
  int pub_r001776_4_1;
  int pub_r001776_4_2;
  int pub_r001776_5_1;
  int pub_r001776_5_2;
  int pub_r001776_6_1;
  int pub_r001776_6_2;
  int pub_r001776_7_1;
  int pub_r001776_7_2;
  int pub_r001776_8_1;
  int pub_r001776_8_2;
  int pub_r001776_9_1;
  int pub_r001776_9_2;
  int pub_r001776_10_1;
  int pub_r001776_10_2;
  int pub_r001776_11_1;
  int pub_r001776_11_2;
  int pub_r001776_12_1;
  int pub_r001776_12_2;
  int pub_r001776_13_1;
  int pub_r001776_13_2;
  int pub_r001776_14_1;
  int pub_r001776_14_2;
  int pub_r001776_15_1;
  int pub_r001776_15_2;
  int pub_r001776_16_1;
  int pub_r001776_16_2;
  int pub_r001776_17_1;
  int pub_r001776_17_2;
  int pub_r001776_18_1;
  int pub_r001776_18_2;
  int pub_r001776_19_1;
  int pub_r001776_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001776_0_1 >= (-100)) && (pub_r001776_0_1 <= 100));
  __CPROVER_assume((pub_r001776_0_2 >= (-100)) && (pub_r001776_0_2 <= 100));
  __CPROVER_assume((pub_r001776_1_1 >= (-100)) && (pub_r001776_1_1 <= 100));
  __CPROVER_assume((pub_r001776_1_2 >= (-100)) && (pub_r001776_1_2 <= 100));
  __CPROVER_assume((pub_r001776_2_1 >= (-100)) && (pub_r001776_2_1 <= 100));
  __CPROVER_assume((pub_r001776_2_2 >= (-100)) && (pub_r001776_2_2 <= 100));
  __CPROVER_assume((pub_r001776_3_1 >= (-100)) && (pub_r001776_3_1 <= 100));
  __CPROVER_assume((pub_r001776_3_2 >= (-100)) && (pub_r001776_3_2 <= 100));
  __CPROVER_assume((pub_r001776_4_1 >= (-100)) && (pub_r001776_4_1 <= 100));
  __CPROVER_assume((pub_r001776_4_2 >= (-100)) && (pub_r001776_4_2 <= 100));
  __CPROVER_assume((pub_r001776_5_1 >= (-100)) && (pub_r001776_5_1 <= 100));
  __CPROVER_assume((pub_r001776_5_2 >= (-100)) && (pub_r001776_5_2 <= 100));
  __CPROVER_assume((pub_r001776_6_1 >= (-100)) && (pub_r001776_6_1 <= 100));
  __CPROVER_assume((pub_r001776_6_2 >= (-100)) && (pub_r001776_6_2 <= 100));
  __CPROVER_assume((pub_r001776_7_1 >= (-100)) && (pub_r001776_7_1 <= 100));
  __CPROVER_assume((pub_r001776_7_2 >= (-100)) && (pub_r001776_7_2 <= 100));
  __CPROVER_assume((pub_r001776_8_1 >= (-100)) && (pub_r001776_8_1 <= 100));
  __CPROVER_assume((pub_r001776_8_2 >= (-100)) && (pub_r001776_8_2 <= 100));
  __CPROVER_assume((pub_r001776_9_1 >= (-100)) && (pub_r001776_9_1 <= 100));
  __CPROVER_assume((pub_r001776_9_2 >= (-100)) && (pub_r001776_9_2 <= 100));
  __CPROVER_assume((pub_r001776_10_1 >= (-100)) && (pub_r001776_10_1 <= 100));
  __CPROVER_assume((pub_r001776_10_2 >= (-100)) && (pub_r001776_10_2 <= 100));
  __CPROVER_assume((pub_r001776_11_1 >= (-100)) && (pub_r001776_11_1 <= 100));
  __CPROVER_assume((pub_r001776_11_2 >= (-100)) && (pub_r001776_11_2 <= 100));
  __CPROVER_assume((pub_r001776_12_1 >= (-100)) && (pub_r001776_12_1 <= 100));
  __CPROVER_assume((pub_r001776_12_2 >= (-100)) && (pub_r001776_12_2 <= 100));
  __CPROVER_assume((pub_r001776_13_1 >= (-100)) && (pub_r001776_13_1 <= 100));
  __CPROVER_assume((pub_r001776_13_2 >= (-100)) && (pub_r001776_13_2 <= 100));
  __CPROVER_assume((pub_r001776_14_1 >= (-100)) && (pub_r001776_14_1 <= 100));
  __CPROVER_assume((pub_r001776_14_2 >= (-100)) && (pub_r001776_14_2 <= 100));
  __CPROVER_assume((pub_r001776_15_1 >= (-100)) && (pub_r001776_15_1 <= 100));
  __CPROVER_assume((pub_r001776_15_2 >= (-100)) && (pub_r001776_15_2 <= 100));
  __CPROVER_assume((pub_r001776_16_1 >= (-100)) && (pub_r001776_16_1 <= 100));
  __CPROVER_assume((pub_r001776_16_2 >= (-100)) && (pub_r001776_16_2 <= 100));
  __CPROVER_assume((pub_r001776_17_1 >= (-100)) && (pub_r001776_17_1 <= 100));
  __CPROVER_assume((pub_r001776_17_2 >= (-100)) && (pub_r001776_17_2 <= 100));
  __CPROVER_assume((pub_r001776_18_1 >= (-100)) && (pub_r001776_18_1 <= 100));
  __CPROVER_assume((pub_r001776_18_2 >= (-100)) && (pub_r001776_18_2 <= 100));
  __CPROVER_assume((pub_r001776_19_1 >= (-100)) && (pub_r001776_19_1 <= 100));
  __CPROVER_assume((pub_r001776_19_2 >= (-100)) && (pub_r001776_19_2 <= 100));
  __CPROVER_assume((sec_r001776_0_1 >= 0) && (sec_r001776_0_1 <= 255));
  __CPROVER_assume((sec_r001776_0_2 >= 0) && (sec_r001776_0_2 <= 255));
  __CPROVER_assume((sec_r001776_1_1 >= 0) && (sec_r001776_1_1 <= 255));
  __CPROVER_assume((sec_r001776_1_2 >= 0) && (sec_r001776_1_2 <= 255));
  __CPROVER_assume((sec_r001776_2_1 >= 0) && (sec_r001776_2_1 <= 255));
  __CPROVER_assume((sec_r001776_2_2 >= 0) && (sec_r001776_2_2 <= 255));
  __CPROVER_assume((sec_r001776_3_1 >= 0) && (sec_r001776_3_1 <= 255));
  __CPROVER_assume((sec_r001776_3_2 >= 0) && (sec_r001776_3_2 <= 255));
  __CPROVER_assume((sec_r001776_4_1 >= 0) && (sec_r001776_4_1 <= 255));
  __CPROVER_assume((sec_r001776_4_2 >= 0) && (sec_r001776_4_2 <= 255));
  __CPROVER_assume((sec_r001776_5_1 >= 0) && (sec_r001776_5_1 <= 255));
  __CPROVER_assume((sec_r001776_5_2 >= 0) && (sec_r001776_5_2 <= 255));
  __CPROVER_assume((sec_r001776_6_1 >= 0) && (sec_r001776_6_1 <= 255));
  __CPROVER_assume((sec_r001776_6_2 >= 0) && (sec_r001776_6_2 <= 255));
  __CPROVER_assume((sec_r001776_7_1 >= 0) && (sec_r001776_7_1 <= 255));
  __CPROVER_assume((sec_r001776_7_2 >= 0) && (sec_r001776_7_2 <= 255));
  __CPROVER_assume((sec_r001776_8_1 >= 0) && (sec_r001776_8_1 <= 255));
  __CPROVER_assume((sec_r001776_8_2 >= 0) && (sec_r001776_8_2 <= 255));
  __CPROVER_assume((sec_r001776_9_1 >= 0) && (sec_r001776_9_1 <= 255));
  __CPROVER_assume((sec_r001776_9_2 >= 0) && (sec_r001776_9_2 <= 255));
  __CPROVER_assume((sec_r001776_10_1 >= 0) && (sec_r001776_10_1 <= 255));
  __CPROVER_assume((sec_r001776_10_2 >= 0) && (sec_r001776_10_2 <= 255));
  __CPROVER_assume((sec_r001776_11_1 >= 0) && (sec_r001776_11_1 <= 255));
  __CPROVER_assume((sec_r001776_11_2 >= 0) && (sec_r001776_11_2 <= 255));
  __CPROVER_assume((sec_r001776_12_1 >= 0) && (sec_r001776_12_1 <= 255));
  __CPROVER_assume((sec_r001776_12_2 >= 0) && (sec_r001776_12_2 <= 255));
  __CPROVER_assume((sec_r001776_13_1 >= 0) && (sec_r001776_13_1 <= 255));
  __CPROVER_assume((sec_r001776_13_2 >= 0) && (sec_r001776_13_2 <= 255));
  __CPROVER_assume((sec_r001776_14_1 >= 0) && (sec_r001776_14_1 <= 255));
  __CPROVER_assume((sec_r001776_14_2 >= 0) && (sec_r001776_14_2 <= 255));
  __CPROVER_assume((sec_r001776_15_1 >= 0) && (sec_r001776_15_1 <= 255));
  __CPROVER_assume((sec_r001776_15_2 >= 0) && (sec_r001776_15_2 <= 255));
  struct StreamBuffer_R001776_7613_0 st_var_0_1 = {0};
  struct StreamBuffer_R001776_7613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001776_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001776_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001776_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001776_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001776_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001776_0_2 + 7) & 15;
  struct AudioFrame_R001776_7613_1 st_var_1_1 = {0};
  struct AudioFrame_R001776_7613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001776_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001776_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001776_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001776_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001776_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001776_0_2 + 9) & 15;
  struct DeviceConfig_R001776_7613_2 st_var_2_1 = {0};
  struct DeviceConfig_R001776_7613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001776_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001776_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001776_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001776_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001776_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001776_0_2 + 11) & 15;
  union TelemetryField_R001776_7613_0 u_var_1;
  union TelemetryField_R001776_7613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001776_7613_0(sec_r001776_0_1, sec_r001776_1_1, pub_r001776_2_1, pub_r001776_3_1);
  int helper_flow_0_2 = fn_R001776_7613_0(sec_r001776_0_2, sec_r001776_1_2, pub_r001776_2_2, pub_r001776_3_2);
  fn_R001776_7613_0_2(sec_r001776_0_1, sec_r001776_1_1, pub_r001776_2_1, pub_r001776_3_1, sec_r001776_0_2, sec_r001776_1_2, pub_r001776_2_2, pub_r001776_3_2);
  int helper_flow_1_1 = fn_R001776_7613_1(sec_r001776_1_1, sec_r001776_2_1, pub_r001776_3_1, pub_r001776_4_1);
  int helper_flow_1_2 = fn_R001776_7613_1(sec_r001776_1_2, sec_r001776_2_2, pub_r001776_3_2, pub_r001776_4_2);
  fn_R001776_7613_1_2(sec_r001776_1_1, sec_r001776_2_1, pub_r001776_3_1, pub_r001776_4_1, sec_r001776_1_2, sec_r001776_2_2, pub_r001776_3_2, pub_r001776_4_2);
  int helper_flow_2_1 = fn_R001776_7613_2(sec_r001776_2_1, sec_r001776_3_1, pub_r001776_4_1, pub_r001776_5_1);
  int helper_flow_2_2 = fn_R001776_7613_2(sec_r001776_2_2, sec_r001776_3_2, pub_r001776_4_2, pub_r001776_5_2);
  fn_R001776_7613_2_2(sec_r001776_2_1, sec_r001776_3_1, pub_r001776_4_1, pub_r001776_5_1, sec_r001776_2_2, sec_r001776_3_2, pub_r001776_4_2, pub_r001776_5_2);
  int helper_flow_3_1 = fn_R001776_7613_3(sec_r001776_3_1, sec_r001776_4_1, pub_r001776_5_1, pub_r001776_6_1);
  int helper_flow_3_2 = fn_R001776_7613_3(sec_r001776_3_2, sec_r001776_4_2, pub_r001776_5_2, pub_r001776_6_2);
  fn_R001776_7613_3_2(sec_r001776_3_1, sec_r001776_4_1, pub_r001776_5_1, pub_r001776_6_1, sec_r001776_3_2, sec_r001776_4_2, pub_r001776_5_2, pub_r001776_6_2);
  int helper_flow_4_1 = fn_R001776_7613_4(sec_r001776_4_1, pub_r001776_5_1);
  int helper_flow_4_2 = fn_R001776_7613_4(sec_r001776_4_2, pub_r001776_5_2);
  fn_R001776_7613_4_2(sec_r001776_4_1, pub_r001776_5_1, sec_r001776_4_2, pub_r001776_5_2);
  int helper_flow_5_1 = fn_R001776_7613_5(sec_r001776_5_1, sec_r001776_6_1, pub_r001776_7_1);
  int helper_flow_5_2 = fn_R001776_7613_5(sec_r001776_5_2, sec_r001776_6_2, pub_r001776_7_2);
  fn_R001776_7613_5_2(sec_r001776_5_1, sec_r001776_6_1, pub_r001776_7_1, sec_r001776_5_2, sec_r001776_6_2, pub_r001776_7_2);
  int helper_flow_6_1 = fn_R001776_7613_6(sec_r001776_6_1, pub_r001776_7_1, pub_r001776_8_1, pub_r001776_9_1);
  int helper_flow_6_2 = fn_R001776_7613_6(sec_r001776_6_2, pub_r001776_7_2, pub_r001776_8_2, pub_r001776_9_2);
  fn_R001776_7613_6_2(sec_r001776_6_1, pub_r001776_7_1, pub_r001776_8_1, pub_r001776_9_1, sec_r001776_6_2, pub_r001776_7_2, pub_r001776_8_2, pub_r001776_9_2);
  int stage_v_0_1 = ((helper_flow_3_1 + (pub_r001776_17_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_3_2 + (pub_r001776_17_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((sec_r001776_7_1 + (pub_r001776_8_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001776_7_2 + (pub_r001776_8_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((pub_r001776_7_1 * 2) + 32) & 63;
  int stage_v_2_2 = ((pub_r001776_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((sec_r001776_4_1 + (pub_r001776_7_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001776_4_2 + (pub_r001776_7_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001776_2_1 * 2) + 40) & 63;
  int stage_v_4_2 = ((pub_r001776_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((sec_r001776_14_1 + (pub_r001776_8_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001776_14_2 + (pub_r001776_8_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((pub_r001776_19_1 * 2) + 46) & 63;
  int stage_v_6_2 = ((pub_r001776_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((sec_r001776_4_1 + (pub_r001776_11_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001776_4_2 + (pub_r001776_11_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((helper_flow_6_1 + (pub_r001776_3_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((helper_flow_6_2 + (pub_r001776_3_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((pub_r001776_2_1 * 2) + 38) & 63;
  int stage_v_9_2 = ((pub_r001776_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001776_1_1 * 2) + 10) & 63;
  int stage_v_10_2 = ((pub_r001776_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((helper_flow_4_1 + (pub_r001776_2_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((helper_flow_4_2 + (pub_r001776_2_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((pub_r001776_17_1 * 2) + 31) & 63;
  int stage_v_12_2 = ((pub_r001776_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((sec_r001776_14_1 + (pub_r001776_10_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001776_14_2 + (pub_r001776_10_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((helper_flow_4_1 + (pub_r001776_6_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((helper_flow_4_2 + (pub_r001776_6_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((sec_r001776_7_1 + (pub_r001776_15_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((sec_r001776_7_2 + (pub_r001776_15_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((sec_r001776_6_1 + (pub_r001776_1_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((sec_r001776_6_2 + (pub_r001776_1_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((sec_r001776_3_1 + (pub_r001776_3_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001776_3_2 + (pub_r001776_3_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((pub_r001776_2_1 * 2) + 18) & 63;
  int stage_v_18_2 = ((pub_r001776_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((stage_v_5_1 + (pub_r001776_6_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((stage_v_5_2 + (pub_r001776_6_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((stage_v_3_1 + (pub_r001776_12_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((stage_v_3_2 + (pub_r001776_12_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((stage_v_19_1 + (pub_r001776_17_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_19_2 + (pub_r001776_17_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((sec_r001776_12_1 + (pub_r001776_1_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((sec_r001776_12_2 + (pub_r001776_1_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((pub_r001776_16_1 * 2) + 19) & 63;
  int stage_v_23_2 = ((pub_r001776_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((sec_r001776_9_1 + (pub_r001776_12_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001776_9_2 + (pub_r001776_12_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((pub_r001776_13_1 * 2) + 38) & 63;
  int stage_v_25_2 = ((pub_r001776_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((stage_v_8_1 + (pub_r001776_17_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((stage_v_8_2 + (pub_r001776_17_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((sec_r001776_2_1 + (pub_r001776_6_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((sec_r001776_2_2 + (pub_r001776_6_2 * 2)) + 86) & 127;
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
  int stage_v_28_1 = ((sec_r001776_11_1 + (pub_r001776_16_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((sec_r001776_11_2 + (pub_r001776_16_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((pub_r001776_0_1 * 2) + 43) & 63;
  int stage_v_29_2 = ((pub_r001776_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001776_6_1 * 2) + 15) & 63;
  int stage_v_30_2 = ((pub_r001776_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((sec_r001776_8_1 + (pub_r001776_18_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((sec_r001776_8_2 + (pub_r001776_18_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((stage_v_5_1 + (pub_r001776_12_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_5_2 + (pub_r001776_12_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((sec_r001776_6_1 + (pub_r001776_18_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((sec_r001776_6_2 + (pub_r001776_18_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((helper_flow_4_1 + (pub_r001776_5_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((helper_flow_4_2 + (pub_r001776_5_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((stage_v_21_1 + (pub_r001776_19_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((stage_v_21_2 + (pub_r001776_19_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((sec_r001776_2_1 + (pub_r001776_13_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((sec_r001776_2_2 + (pub_r001776_13_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((sec_r001776_8_1 + (pub_r001776_13_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((sec_r001776_8_2 + (pub_r001776_13_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((pub_r001776_16_1 * 2) + 23) & 63;
  int stage_v_38_2 = ((pub_r001776_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((sec_r001776_0_1 + (pub_r001776_2_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((sec_r001776_0_2 + (pub_r001776_2_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((stage_v_20_1 + (pub_r001776_10_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_20_2 + (pub_r001776_10_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((pub_r001776_7_1 * 2) + 15) & 63;
  int stage_v_41_2 = ((pub_r001776_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001776_4_1 * 2) + 12) & 63;
  int stage_v_42_2 = ((pub_r001776_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((stage_v_40_1 + (pub_r001776_16_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((stage_v_40_2 + (pub_r001776_16_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((stage_v_19_1 + (pub_r001776_3_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((stage_v_19_2 + (pub_r001776_3_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((sec_r001776_1_1 + (pub_r001776_1_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((sec_r001776_1_2 + (pub_r001776_1_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((stage_v_35_1 + (pub_r001776_7_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_35_2 + (pub_r001776_7_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((pub_r001776_3_1 * 2) + 23) & 63;
  int stage_v_47_2 = ((pub_r001776_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((stage_v_44_1 + (pub_r001776_5_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_44_2 + (pub_r001776_5_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((stage_v_44_1 + (pub_r001776_14_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_44_2 + (pub_r001776_14_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((pub_r001776_5_1 * 2) + 16) & 63;
  int stage_v_50_2 = ((pub_r001776_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((sec_r001776_3_1 + (pub_r001776_18_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((sec_r001776_3_2 + (pub_r001776_18_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((stage_v_17_1 + (pub_r001776_14_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((stage_v_17_2 + (pub_r001776_14_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((stage_v_17_1 + (pub_r001776_4_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((stage_v_17_2 + (pub_r001776_4_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((stage_v_19_1 + (pub_r001776_12_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((stage_v_19_2 + (pub_r001776_12_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((helper_flow_3_1 + (pub_r001776_2_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((helper_flow_3_2 + (pub_r001776_2_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001776_15_1 * 2) + 14) & 63;
  int stage_v_56_2 = ((pub_r001776_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001776_14_1 * 2) + 11) & 63;
  int stage_v_57_2 = ((pub_r001776_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((stage_v_1_1 + (pub_r001776_7_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_1_2 + (pub_r001776_7_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((pub_r001776_4_1 * 2) + 7) & 63;
  int stage_v_59_2 = ((pub_r001776_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((helper_flow_1_1 + (pub_r001776_17_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((helper_flow_1_2 + (pub_r001776_17_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((stage_v_27_1 + (pub_r001776_5_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_27_2 + (pub_r001776_5_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((sec_r001776_3_1 + (pub_r001776_14_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((sec_r001776_3_2 + (pub_r001776_14_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((helper_flow_2_1 + (pub_r001776_8_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((helper_flow_2_2 + (pub_r001776_8_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((stage_v_8_1 + (pub_r001776_0_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_8_2 + (pub_r001776_0_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_48_1 + (pub_r001776_15_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_48_2 + (pub_r001776_15_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((stage_v_48_1 + (pub_r001776_18_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((stage_v_48_2 + (pub_r001776_18_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((stage_v_44_1 + (pub_r001776_15_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_44_2 + (pub_r001776_15_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((pub_r001776_4_1 * 2) + 39) & 63;
  int stage_v_68_2 = ((pub_r001776_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((sec_r001776_6_1 + (pub_r001776_15_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((sec_r001776_6_2 + (pub_r001776_15_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((pub_r001776_14_1 * 2) + 38) & 63;
  int stage_v_70_2 = ((pub_r001776_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001776_0_1 * 2) + 31) & 63;
  int stage_v_71_2 = ((pub_r001776_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((stage_v_11_1 + (pub_r001776_4_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_11_2 + (pub_r001776_4_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_34_1 + (pub_r001776_19_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_34_2 + (pub_r001776_19_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((stage_v_20_1 + (pub_r001776_19_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_20_2 + (pub_r001776_19_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((pub_r001776_2_1 * 2) + 39) & 63;
  int stage_v_75_2 = ((pub_r001776_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001776_0_1 * 2) + 36) & 63;
  int stage_v_76_2 = ((pub_r001776_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001776_15_1 * 2) + 12) & 63;
  int stage_v_77_2 = ((pub_r001776_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001776_1_1 * 2) + 31) & 63;
  int stage_v_78_2 = ((pub_r001776_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((stage_v_51_1 + (pub_r001776_12_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_51_2 + (pub_r001776_12_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((sec_r001776_12_1 + (pub_r001776_9_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((sec_r001776_12_2 + (pub_r001776_9_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((pub_r001776_14_1 * 2) + 27) & 63;
  int stage_v_81_2 = ((pub_r001776_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_7_1 + (pub_r001776_17_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_7_2 + (pub_r001776_17_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((stage_v_36_1 + (pub_r001776_15_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_36_2 + (pub_r001776_15_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((pub_r001776_7_1 * 2) + 34) & 63;
  int stage_v_84_2 = ((pub_r001776_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((stage_v_52_1 + (pub_r001776_11_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_52_2 + (pub_r001776_11_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((pub_r001776_12_1 * 2) + 11) & 63;
  int stage_v_86_2 = ((pub_r001776_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((stage_v_11_1 + (pub_r001776_0_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_11_2 + (pub_r001776_0_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((stage_v_34_1 + (pub_r001776_17_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_34_2 + (pub_r001776_17_2 * 2)) + 269) & 127;
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
  int stage_v_89_1 = ((stage_v_73_1 + (pub_r001776_19_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_73_2 + (pub_r001776_19_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((pub_r001776_10_1 * 2) + 31) & 63;
  int stage_v_90_2 = ((pub_r001776_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((stage_v_58_1 + (pub_r001776_2_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_58_2 + (pub_r001776_2_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((pub_r001776_17_1 * 2) + 42) & 63;
  int stage_v_92_2 = ((pub_r001776_17_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((stage_v_49_1 + (pub_r001776_1_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_49_2 + (pub_r001776_1_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((sec_r001776_0_1 + (pub_r001776_6_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((sec_r001776_0_2 + (pub_r001776_6_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((sec_r001776_10_1 + (pub_r001776_3_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((sec_r001776_10_2 + (pub_r001776_3_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((stage_v_40_1 + (pub_r001776_9_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_40_2 + (pub_r001776_9_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((stage_v_39_1 + (pub_r001776_6_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_39_2 + (pub_r001776_6_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((pub_r001776_11_1 * 2) + 14) & 63;
  int stage_v_98_2 = ((pub_r001776_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((stage_v_3_1 + (pub_r001776_9_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_3_2 + (pub_r001776_9_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_16_1 + (pub_r001776_7_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_16_2 + (pub_r001776_7_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((pub_r001776_8_1 * 2) + 25) & 63;
  int stage_v_101_2 = ((pub_r001776_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((stage_v_61_1 + (pub_r001776_10_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_61_2 + (pub_r001776_10_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((pub_r001776_11_1 * 2) + 38) & 63;
  int stage_v_103_2 = ((pub_r001776_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((stage_v_22_1 + (pub_r001776_8_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_22_2 + (pub_r001776_8_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_40_1 + (pub_r001776_9_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_40_2 + (pub_r001776_9_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_93_1 + (pub_r001776_16_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_93_2 + (pub_r001776_16_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((stage_v_69_1 + (pub_r001776_9_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_69_2 + (pub_r001776_9_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((pub_r001776_9_1 * 2) + 8) & 63;
  int stage_v_108_2 = ((pub_r001776_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_51_1 + (pub_r001776_16_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_51_2 + (pub_r001776_16_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((helper_flow_6_1 + (pub_r001776_4_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((helper_flow_6_2 + (pub_r001776_4_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((sec_r001776_7_1 + (pub_r001776_7_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((sec_r001776_7_2 + (pub_r001776_7_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((stage_v_89_1 + (pub_r001776_16_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_89_2 + (pub_r001776_16_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((stage_v_31_1 + (pub_r001776_9_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_31_2 + (pub_r001776_9_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((stage_v_58_1 + (pub_r001776_10_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_58_2 + (pub_r001776_10_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((stage_v_109_1 + (pub_r001776_5_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_109_2 + (pub_r001776_5_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((pub_r001776_0_1 * 2) + 36) & 63;
  int stage_v_116_2 = ((pub_r001776_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001776_9_1 * 2) + 39) & 63;
  int stage_v_117_2 = ((pub_r001776_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((stage_v_31_1 + (pub_r001776_8_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_31_2 + (pub_r001776_8_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_99_1 + (pub_r001776_10_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_99_2 + (pub_r001776_10_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((stage_v_96_1 + (pub_r001776_19_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_96_2 + (pub_r001776_19_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((stage_v_94_1 + (pub_r001776_3_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_94_2 + (pub_r001776_3_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_111_1 + (pub_r001776_10_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_111_2 + (pub_r001776_10_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_46_1 + (pub_r001776_5_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_46_2 + (pub_r001776_5_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((helper_flow_5_1 + (pub_r001776_7_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((helper_flow_5_2 + (pub_r001776_7_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((pub_r001776_6_1 * 2) + 11) & 63;
  int stage_v_125_2 = ((pub_r001776_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((stage_v_24_1 + (pub_r001776_17_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_24_2 + (pub_r001776_17_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((stage_v_21_1 + (pub_r001776_19_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_21_2 + (pub_r001776_19_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((helper_flow_3_1 + (pub_r001776_15_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((helper_flow_3_2 + (pub_r001776_15_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((pub_r001776_0_1 * 2) + 40) & 63;
  int stage_v_129_2 = ((pub_r001776_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((sec_r001776_12_1 + (pub_r001776_19_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((sec_r001776_12_2 + (pub_r001776_19_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((pub_r001776_6_1 * 2) + 45) & 63;
  int stage_v_131_2 = ((pub_r001776_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_22_1 + (pub_r001776_16_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_22_2 + (pub_r001776_16_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((stage_v_128_1 + (pub_r001776_17_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_128_2 + (pub_r001776_17_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((pub_r001776_15_1 * 2) + 29) & 63;
  int stage_v_134_2 = ((pub_r001776_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001776_1_1 * 2) + 15) & 63;
  int stage_v_135_2 = ((pub_r001776_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((helper_flow_2_1 + (pub_r001776_5_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((helper_flow_2_2 + (pub_r001776_5_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_99_1 + (pub_r001776_12_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_99_2 + (pub_r001776_12_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((stage_v_118_1 + (pub_r001776_14_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_118_2 + (pub_r001776_14_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((pub_r001776_5_1 * 2) + 37) & 63;
  int stage_v_139_2 = ((pub_r001776_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((stage_v_123_1 + (pub_r001776_19_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_123_2 + (pub_r001776_19_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((pub_r001776_10_1 * 2) + 21) & 63;
  int stage_v_141_2 = ((pub_r001776_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((sec_r001776_13_1 + (pub_r001776_18_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((sec_r001776_13_2 + (pub_r001776_18_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((stage_v_74_1 + (pub_r001776_3_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_74_2 + (pub_r001776_3_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((stage_v_17_1 + (pub_r001776_0_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_17_2 + (pub_r001776_0_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((stage_v_65_1 + (pub_r001776_12_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_65_2 + (pub_r001776_12_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_34_1 + (pub_r001776_1_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_34_2 + (pub_r001776_1_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_85_1 + (pub_r001776_7_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_85_2 + (pub_r001776_7_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_37_1 + (pub_r001776_2_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_37_2 + (pub_r001776_2_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((sec_r001776_3_1 + (pub_r001776_11_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((sec_r001776_3_2 + (pub_r001776_11_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((pub_r001776_2_1 * 2) + 10) & 63;
  int stage_v_150_2 = ((pub_r001776_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((stage_v_133_1 + (pub_r001776_17_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_133_2 + (pub_r001776_17_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_11_1 + (pub_r001776_10_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_11_2 + (pub_r001776_10_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_34_1 + (pub_r001776_19_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_34_2 + (pub_r001776_19_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((pub_r001776_19_1 * 2) + 36) & 63;
  int stage_v_154_2 = ((pub_r001776_19_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_126_1 + (pub_r001776_10_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_126_2 + (pub_r001776_10_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((pub_r001776_12_1 * 2) + 20) & 63;
  int stage_v_156_2 = ((pub_r001776_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((stage_v_152_1 + (pub_r001776_19_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_152_2 + (pub_r001776_19_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_20_1 + (pub_r001776_11_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_20_2 + (pub_r001776_11_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((pub_r001776_12_1 * 2) + 43) & 63;
  int stage_v_159_2 = ((pub_r001776_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((stage_v_83_1 + (pub_r001776_1_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_83_2 + (pub_r001776_1_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((pub_r001776_13_1 * 2) + 15) & 63;
  int stage_v_161_2 = ((pub_r001776_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001776_7_1 * 2) + 31) & 63;
  int stage_v_162_2 = ((pub_r001776_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001776_17_1 * 2) + 34) & 63;
  int stage_v_163_2 = ((pub_r001776_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_65_1 + (pub_r001776_9_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_65_2 + (pub_r001776_9_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((stage_v_67_1 + (pub_r001776_9_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_67_2 + (pub_r001776_9_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((pub_r001776_5_1 * 2) + 38) & 63;
  int stage_v_166_2 = ((pub_r001776_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001776_13_1 * 2) + 32) & 63;
  int stage_v_167_2 = ((pub_r001776_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((stage_v_34_1 + (pub_r001776_15_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_34_2 + (pub_r001776_15_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_123_1 + (pub_r001776_0_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_123_2 + (pub_r001776_0_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((pub_r001776_10_1 * 2) + 7) & 63;
  int stage_v_170_2 = ((pub_r001776_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((stage_v_110_1 + (pub_r001776_16_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_110_2 + (pub_r001776_16_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((pub_r001776_12_1 * 2) + 50) & 63;
  int stage_v_172_2 = ((pub_r001776_12_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((stage_v_121_1 + (pub_r001776_12_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_121_2 + (pub_r001776_12_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((pub_r001776_1_1 * 2) + 31) & 63;
  int stage_v_174_2 = ((pub_r001776_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((stage_v_137_1 + (pub_r001776_1_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_137_2 + (pub_r001776_1_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_111_1 + (pub_r001776_10_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_111_2 + (pub_r001776_10_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((stage_v_122_1 + (pub_r001776_10_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_122_2 + (pub_r001776_10_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((stage_v_133_1 + (pub_r001776_4_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_133_2 + (pub_r001776_4_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((stage_v_178_1 + (pub_r001776_17_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_178_2 + (pub_r001776_17_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((sec_r001776_9_1 + (pub_r001776_9_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((sec_r001776_9_2 + (pub_r001776_9_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((sec_r001776_8_1 + (pub_r001776_12_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((sec_r001776_8_2 + (pub_r001776_12_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((stage_v_102_1 + (pub_r001776_18_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_102_2 + (pub_r001776_18_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_165_1 + (pub_r001776_5_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_165_2 + (pub_r001776_5_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((pub_r001776_10_1 * 2) + 29) & 63;
  int stage_v_184_2 = ((pub_r001776_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((stage_v_32_1 + (pub_r001776_1_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_32_2 + (pub_r001776_1_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((pub_r001776_13_1 * 2) + 23) & 63;
  int stage_v_186_2 = ((pub_r001776_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((sec_r001776_5_1 + (pub_r001776_0_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((sec_r001776_5_2 + (pub_r001776_0_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((helper_flow_5_1 + (pub_r001776_5_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((helper_flow_5_2 + (pub_r001776_5_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((stage_v_82_1 + (pub_r001776_8_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_82_2 + (pub_r001776_8_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((pub_r001776_15_1 * 2) + 32) & 63;
  int stage_v_190_2 = ((pub_r001776_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001776_8_1 * 2) + 32) & 63;
  int stage_v_191_2 = ((pub_r001776_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001776_18_1 * 2) + 42) & 63;
  int stage_v_192_2 = ((pub_r001776_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001776_11_1 * 2) + 14) & 63;
  int stage_v_193_2 = ((pub_r001776_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((sec_r001776_3_1 + (pub_r001776_17_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((sec_r001776_3_2 + (pub_r001776_17_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_185_1 + (pub_r001776_14_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_185_2 + (pub_r001776_14_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((sec_r001776_2_1 + (pub_r001776_7_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((sec_r001776_2_2 + (pub_r001776_7_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((pub_r001776_9_1 * 2) + 23) & 63;
  int stage_v_197_2 = ((pub_r001776_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001776_7_1 * 2) + 30) & 63;
  int stage_v_198_2 = ((pub_r001776_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((stage_v_80_1 + (pub_r001776_12_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_80_2 + (pub_r001776_12_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((pub_r001776_13_1 * 2) + 36) & 63;
  int stage_v_200_2 = ((pub_r001776_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((stage_v_96_1 + (pub_r001776_4_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_96_2 + (pub_r001776_4_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_35_1 + (pub_r001776_13_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_35_2 + (pub_r001776_13_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((stage_v_107_1 + (pub_r001776_1_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((stage_v_107_2 + (pub_r001776_1_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((pub_r001776_12_1 * 2) + 36) & 63;
  int stage_v_204_2 = ((pub_r001776_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((stage_v_113_1 + (pub_r001776_19_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_113_2 + (pub_r001776_19_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((pub_r001776_4_1 * 2) + 30) & 63;
  int stage_v_206_2 = ((pub_r001776_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((sec_r001776_7_1 + (pub_r001776_9_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((sec_r001776_7_2 + (pub_r001776_9_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((helper_flow_3_1 + (pub_r001776_2_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((helper_flow_3_2 + (pub_r001776_2_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_85_1 + (pub_r001776_19_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_85_2 + (pub_r001776_19_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((pub_r001776_11_1 * 2) + 17) & 63;
  int stage_v_210_2 = ((pub_r001776_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001776_1_1 != sec_r001776_1_2);
  __CPROVER_assume(sec_r001776_3_1 != sec_r001776_3_2);
  __CPROVER_assume(sec_r001776_8_1 != sec_r001776_8_2);
  __CPROVER_assume(pub_r001776_1_1 == pub_r001776_1_2);
  __CPROVER_assume(pub_r001776_4_1 == pub_r001776_4_2);
  __CPROVER_assume(pub_r001776_6_1 == pub_r001776_6_2);
  __CPROVER_assume(pub_r001776_18_1 == pub_r001776_18_2);
  __CPROVER_assume(pub_r001776_11_1 == pub_r001776_11_2);
  __CPROVER_assume(sec_r001776_2_1 != sec_r001776_2_2);
  __CPROVER_assume(sec_r001776_6_1 != sec_r001776_6_2);
  __CPROVER_assume(sec_r001776_9_1 != sec_r001776_9_2);
  __CPROVER_assume(pub_r001776_5_1 == pub_r001776_5_2);
  __CPROVER_assume(sec_r001776_7_1 != sec_r001776_7_2);
  __CPROVER_assume(pub_r001776_2_1 == pub_r001776_2_2);
  __CPROVER_assume(sec_r001776_12_1 != sec_r001776_12_2);
  __CPROVER_assume(sec_r001776_10_1 != sec_r001776_10_2);
  __CPROVER_assume(sec_r001776_13_1 != sec_r001776_13_2);
  __CPROVER_assume(pub_r001776_12_1 == pub_r001776_12_2);
  __CPROVER_assume(sec_r001776_4_1 != sec_r001776_4_2);
  __CPROVER_assume(pub_r001776_7_1 == pub_r001776_7_2);
  __CPROVER_assume(pub_r001776_13_1 == pub_r001776_13_2);
  __CPROVER_assume(sec_r001776_5_1 != sec_r001776_5_2);
  __CPROVER_assume(sec_r001776_15_1 != sec_r001776_15_2);
  __CPROVER_assume(pub_r001776_16_1 == pub_r001776_16_2);
  __CPROVER_assume(sec_r001776_14_1 != sec_r001776_14_2);
  __CPROVER_assume(pub_r001776_0_1 == pub_r001776_0_2);
  __CPROVER_assume(sec_r001776_11_1 != sec_r001776_11_2);
  __CPROVER_assume(pub_r001776_15_1 == pub_r001776_15_2);
  __CPROVER_assume(pub_r001776_8_1 == pub_r001776_8_2);
  __CPROVER_assume(pub_r001776_3_1 == pub_r001776_3_2);
  __CPROVER_assume(pub_r001776_19_1 == pub_r001776_19_2);
  __CPROVER_assume(pub_r001776_17_1 == pub_r001776_17_2);
  __CPROVER_assume(pub_r001776_14_1 == pub_r001776_14_2);
  __CPROVER_assume(pub_r001776_10_1 == pub_r001776_10_2);
  __CPROVER_assume(sec_r001776_0_1 != sec_r001776_0_2);
  __CPROVER_assume(pub_r001776_9_1 == pub_r001776_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.head == st_var_0_2.head);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.id == st_var_2_2.id);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.port == st_var_2_2.port);
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
}


