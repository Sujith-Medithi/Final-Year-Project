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
struct CipherContext_R000327_2713_0
{
  short tag;
  unsigned char iv;
  int round_key;
  int buffer[3];
};
struct EventLog_R000327_2713_1
{
  int code;
  int facility;
  short signature;
  int buffer[3];
};
struct StreamBuffer_R000327_2713_2
{
  short capacity;
  int state;
  int head;
  unsigned char watermark;
  short tail;
  unsigned char checksum;
  int buffer[3];
};
union ColorPixel_R000327_2713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000327_2713_1
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
void fn_R000327_2713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st_1 = {0};
  struct CipherContext_R000327_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_64_1 = local_arr_1[aux_1 % 3];
  int window_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_64_2 * 2)) & 127;
  int scale_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_86_1)
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

  switch (scale_86_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_88_1) & 63;
  aux_2 = (aux_2 + metric_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_64_1 == window_64_2);
  assert(scale_86_1 == scale_86_2);
  assert(metric_88_1 == metric_88_2);
}

int fn_R000327_2713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int window_64 = local_arr[aux % 3];
  acc = (acc + (window_64 * 2)) & 127;
  int scale_86 = (aux + st.buffer[1]) & 3;
  switch (scale_86)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_88) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000327_2713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st_1 = {0};
  struct StreamBuffer_R000327_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int cursor_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_41_1 > 27)
  {
    acc_1 = ((acc_1 + (cursor_41_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_41_2 > 27)
  {
    acc_2 = ((acc_2 + (cursor_41_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_33_1)
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

  switch (weight_33_2)
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
  int vector_46_1 = local_arr_1[aux_1 % 3];
  int vector_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_41_1 == cursor_41_2);
  assert(weight_33_1 == weight_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_46_1 == vector_46_2);
}

int fn_R000327_2713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int cursor_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_41 > 27)
  {
    acc = ((acc + (cursor_41 * 2)) + 5) & 127;
    aux ^= cursor_41 & 15;
  }
  else
  {
    acc = ((acc - cursor_41) + 11) & 127;
    aux += 3;
  }
  int weight_33 = (aux + st.buffer[1]) & 3;
  switch (weight_33)
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
  int vector_46 = local_arr[aux % 3];
  acc = (acc + (vector_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000327_2713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000327_2713_1 st_1 = {0};
  struct EventLog_R000327_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int bound_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_30_1)
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

  switch (bound_30_2)
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
  int cursor_43_1 = local_arr_1[aux_1 % 3];
  int cursor_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_43_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_30_1 == bound_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_43_1 == cursor_43_2);
}

int fn_R000327_2713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000327_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int bound_30 = (aux + st.buffer[1]) & 3;
  switch (bound_30)
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
  int cursor_43 = local_arr[aux % 3];
  acc = (acc + (cursor_43 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000327_2713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st_1 = {0};
  struct StreamBuffer_R000327_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int window_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_84_1 > 34)
  {
    acc_1 = ((acc_1 + (window_84_1 * 2)) + 5) & 127;
    aux_1 ^= window_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_84_2 > 34)
  {
    acc_2 = ((acc_2 + (window_84_2 * 2)) + 5) & 127;
    aux_2 ^= window_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_84_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_61_1)
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

  switch (tracker_61_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_84_1 == window_84_2);
  assert(tracker_61_1 == tracker_61_2);
}

int fn_R000327_2713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int window_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_84 > 34)
  {
    acc = ((acc + (window_84 * 2)) + 5) & 127;
    aux ^= window_84 & 15;
  }
  else
  {
    acc = ((acc - window_84) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_61 = (aux + st.buffer[1]) & 3;
  switch (tracker_61)
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

void fn_R000327_2713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st_1 = {0};
  struct CipherContext_R000327_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int factor_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_78_1) & 63;
  aux_2 = (aux_2 + factor_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_47_1 = local_arr_1[aux_1 % 3];
  int offset_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_47_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_78_1 == factor_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_47_1 == offset_47_2);
}

int fn_R000327_2713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int factor_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_78) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_47 = local_arr[aux % 3];
  acc = (acc + (offset_47 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000327_2713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000327_2713_1 st_1 = {0};
  struct EventLog_R000327_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int scale_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_98_1) & 63;
  aux_2 = (aux_2 + scale_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_75_1 > 39)
  {
    acc_1 = ((acc_1 + (factor_75_1 * 2)) + 5) & 127;
    aux_1 ^= factor_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_75_2 > 39)
  {
    acc_2 = ((acc_2 + (factor_75_2 * 2)) + 5) & 127;
    aux_2 ^= factor_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_75_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_98_1 == scale_98_2);
  assert(factor_75_1 == factor_75_2);
}

int fn_R000327_2713_5(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000327_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int scale_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_98) & 63;
  acc ^= aux;
  int factor_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_75 > 39)
  {
    acc = ((acc + (factor_75 * 2)) + 5) & 127;
    aux ^= factor_75 & 15;
  }
  else
  {
    acc = ((acc - factor_75) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000327_2713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st_1 = {0};
  struct CipherContext_R000327_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_34_1 = local_arr_1[aux_1 % 3];
  int quotient_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_34_2 * 2)) & 127;
  int accumulator_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_28_1 > 15)
  {
    acc_1 = ((acc_1 + (accumulator_28_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_28_2 > 15)
  {
    acc_2 = ((acc_2 + (accumulator_28_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_28_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_93_1)
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

  switch (tally_93_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_34_1 == quotient_34_2);
  assert(accumulator_28_1 == accumulator_28_2);
  assert(tally_93_1 == tally_93_2);
}

int fn_R000327_2713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_34 = local_arr[aux % 3];
  acc = (acc + (quotient_34 * 2)) & 127;
  int accumulator_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_28 > 15)
  {
    acc = ((acc + (accumulator_28 * 2)) + 5) & 127;
    aux ^= accumulator_28 & 15;
  }
  else
  {
    acc = ((acc - accumulator_28) + 11) & 127;
    aux += 3;
  }
  int tally_93 = (aux + st.buffer[1]) & 3;
  switch (tally_93)
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

void fn_R000327_2713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st_1 = {0};
  struct StreamBuffer_R000327_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_72_1 = local_arr_1[aux_1 % 3];
  int damping_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_72_2 * 2)) & 127;
  int metric_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_46_1) & 63;
  aux_2 = (aux_2 + metric_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_45_1 > 20)
  {
    acc_1 = ((acc_1 + (accumulator_45_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_45_2 > 20)
  {
    acc_2 = ((acc_2 + (accumulator_45_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_72_1 == damping_72_2);
  assert(metric_46_1 == metric_46_2);
  assert(accumulator_45_1 == accumulator_45_2);
}

int fn_R000327_2713_7(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_72 = local_arr[aux % 3];
  acc = (acc + (damping_72 * 2)) & 127;
  int metric_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_46) & 63;
  acc ^= aux;
  int accumulator_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_45 > 20)
  {
    acc = ((acc + (accumulator_45 * 2)) + 5) & 127;
    aux ^= accumulator_45 & 15;
  }
  else
  {
    acc = ((acc - accumulator_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000327_2713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st_1 = {0};
  struct CipherContext_R000327_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int index_reg_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_90_1) & 63;
  aux_2 = (aux_2 + index_reg_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_37_1)
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

  switch (cursor_37_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_90_1 == index_reg_90_2);
  assert(cursor_37_1 == cursor_37_2);
}

int fn_R000327_2713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int index_reg_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_90) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_37 = (aux + st.buffer[1]) & 3;
  switch (cursor_37)
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

void fn_R000327_2713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st_1 = {0};
  struct CipherContext_R000327_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_92_1) & 63;
  aux_2 = (aux_2 + anchor_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_92_1 == anchor_92_2);
}

int fn_R000327_2713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000327_2713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st_1 = {0};
  struct CipherContext_R000327_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int window_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_98_1 > 31)
  {
    acc_1 = ((acc_1 + (window_98_1 * 2)) + 5) & 127;
    aux_1 ^= window_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_98_2 > 31)
  {
    acc_2 = ((acc_2 + (window_98_2 * 2)) + 5) & 127;
    aux_2 ^= window_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_46_1) & 63;
  aux_2 = (aux_2 + accumulator_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_98_1 == window_98_2);
  assert(accumulator_46_1 == accumulator_46_2);
}

int fn_R000327_2713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int window_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_98 > 31)
  {
    acc = ((acc + (window_98 * 2)) + 5) & 127;
    aux ^= window_98 & 15;
  }
  else
  {
    acc = ((acc - window_98) + 11) & 127;
    aux += 3;
  }
  int accumulator_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_46) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000327_2713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st_1 = {0};
  struct StreamBuffer_R000327_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_62_1 = local_arr_1[aux_1 % 3];
  int quantum_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_62_2 * 2)) & 127;
  int checksum_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_89_1)
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

  switch (checksum_89_2)
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

  int threshold_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_90_1 > 14)
  {
    acc_1 = ((acc_1 + (threshold_90_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_90_2 > 14)
  {
    acc_2 = ((acc_2 + (threshold_90_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_90_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_62_1 == quantum_62_2);
  assert(checksum_89_1 == checksum_89_2);
  assert(threshold_90_1 == threshold_90_2);
}

int fn_R000327_2713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int quantum_62 = local_arr[aux % 3];
  acc = (acc + (quantum_62 * 2)) & 127;
  int checksum_89 = (aux + st.buffer[1]) & 3;
  switch (checksum_89)
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

  int threshold_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_90 > 14)
  {
    acc = ((acc + (threshold_90 * 2)) + 5) & 127;
    aux ^= threshold_90 & 15;
  }
  else
  {
    acc = ((acc - threshold_90) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000327_2713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st_1 = {0};
  struct StreamBuffer_R000327_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_72_1 = local_arr_1[aux_1 % 3];
  int window_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_72_2 * 2)) & 127;
  int tally_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_65_1) & 63;
  aux_2 = (aux_2 + tally_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_72_1 == window_72_2);
  assert(tally_65_1 == tally_65_2);
}

int fn_R000327_2713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int window_72 = local_arr[aux % 3];
  acc = (acc + (window_72 * 2)) & 127;
  int tally_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000327_2713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st_1 = {0};
  struct StreamBuffer_R000327_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int margin_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_33_1 > 49)
  {
    acc_1 = ((acc_1 + (margin_33_1 * 2)) + 5) & 127;
    aux_1 ^= margin_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_33_2 > 49)
  {
    acc_2 = ((acc_2 + (margin_33_2 * 2)) + 5) & 127;
    aux_2 ^= margin_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_98_1) & 63;
  aux_2 = (aux_2 + index_reg_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_35_1 = local_arr_1[aux_1 % 3];
  int accumulator_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_33_1 == margin_33_2);
  assert(index_reg_98_1 == index_reg_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_35_1 == accumulator_35_2);
}

int fn_R000327_2713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int margin_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_33 > 49)
  {
    acc = ((acc + (margin_33 * 2)) + 5) & 127;
    aux ^= margin_33 & 15;
  }
  else
  {
    acc = ((acc - margin_33) + 11) & 127;
    aux += 3;
  }
  int index_reg_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_98) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_35 = local_arr[aux % 3];
  acc = (acc + (accumulator_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000327_2713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st_1 = {0};
  struct StreamBuffer_R000327_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int cursor_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_73_1) & 63;
  aux_2 = (aux_2 + cursor_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_53_1 = local_arr_1[aux_1 % 3];
  int margin_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_53_2 * 2)) & 127;
  int offset_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_78_1)
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

  switch (offset_78_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_73_1 == cursor_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_53_1 == margin_53_2);
  assert(offset_78_1 == offset_78_2);
}

int fn_R000327_2713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000327_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int cursor_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_73) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_53 = local_arr[aux % 3];
  acc = (acc + (margin_53 * 2)) & 127;
  int offset_78 = (aux + st.buffer[1]) & 3;
  switch (offset_78)
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

void fn_R000327_2713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st_1 = {0};
  struct CipherContext_R000327_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_36_1 = local_arr_1[aux_1 % 3];
  int accumulator_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_36_2 * 2)) & 127;
  int metric_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_44_1) & 63;
  aux_2 = (aux_2 + metric_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_48_1)
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

  switch (metric_48_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_36_1 == accumulator_36_2);
  assert(metric_44_1 == metric_44_2);
  assert(metric_48_1 == metric_48_2);
}

int fn_R000327_2713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int accumulator_36 = local_arr[aux % 3];
  acc = (acc + (accumulator_36 * 2)) & 127;
  int metric_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_44) & 63;
  acc ^= aux;
  int metric_48 = (aux + st.buffer[1]) & 3;
  switch (metric_48)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000327_2713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st_1 = {0};
  struct CipherContext_R000327_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int index_reg_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_90_1) & 63;
  aux_2 = (aux_2 + index_reg_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_83_1 = local_arr_1[aux_1 % 3];
  int stride_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_83_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_90_1 == index_reg_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_83_1 == stride_83_2);
}

int fn_R000327_2713_16(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int index_reg_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_90) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_83 = local_arr[aux % 3];
  acc = (acc + (stride_83 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000327_2713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st_1 = {0};
  struct CipherContext_R000327_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_83_1 = local_arr_1[aux_1 % 3];
  int quantum_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_83_2 * 2)) & 127;
  int checksum_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_75_1) & 63;
  aux_2 = (aux_2 + checksum_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_83_1 == quantum_83_2);
  assert(checksum_75_1 == checksum_75_2);
}

int fn_R000327_2713_17(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int quantum_83 = local_arr[aux % 3];
  acc = (acc + (quantum_83 * 2)) & 127;
  int checksum_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000327_2713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st_1 = {0};
  struct CipherContext_R000327_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int pivot_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_32_1) & 63;
  aux_2 = (aux_2 + pivot_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_52_1 = local_arr_1[aux_1 % 3];
  int metric_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_52_2 * 2)) & 127;
  int bound_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_55_1 > 17)
  {
    acc_1 = ((acc_1 + (bound_55_1 * 2)) + 5) & 127;
    aux_1 ^= bound_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_55_2 > 17)
  {
    acc_2 = ((acc_2 + (bound_55_2 * 2)) + 5) & 127;
    aux_2 ^= bound_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_55_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_32_1 == pivot_32_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_52_1 == metric_52_2);
  assert(bound_55_1 == bound_55_2);
}

int fn_R000327_2713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int pivot_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_32) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_52 = local_arr[aux % 3];
  acc = (acc + (metric_52 * 2)) & 127;
  int bound_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_55 > 17)
  {
    acc = ((acc + (bound_55 * 2)) + 5) & 127;
    aux ^= bound_55 & 15;
  }
  else
  {
    acc = ((acc - bound_55) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000327_2713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st_1 = {0};
  struct CipherContext_R000327_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int quotient_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_11_1) & 63;
  aux_2 = (aux_2 + quotient_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_18_1)
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

  switch (tracker_18_2)
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
  int checksum_98_1 = local_arr_1[aux_1 % 3];
  int checksum_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_98_2 * 2)) & 127;
  int tracker_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_58_1 > 49)
  {
    acc_1 = ((acc_1 + (tracker_58_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_58_2 > 49)
  {
    acc_2 = ((acc_2 + (tracker_58_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_11_1 == quotient_11_2);
  assert(tracker_18_1 == tracker_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_98_1 == checksum_98_2);
  assert(tracker_58_1 == tracker_58_2);
}

int fn_R000327_2713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000327_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int quotient_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_11) & 63;
  acc ^= aux;
  int tracker_18 = (aux + st.buffer[1]) & 3;
  switch (tracker_18)
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
  int checksum_98 = local_arr[aux % 3];
  acc = (acc + (checksum_98 * 2)) & 127;
  int tracker_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_58 > 49)
  {
    acc = ((acc + (tracker_58 * 2)) + 5) & 127;
    aux ^= tracker_58 & 15;
  }
  else
  {
    acc = ((acc - tracker_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000327_2713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000327_2713_1 st_1 = {0};
  struct EventLog_R000327_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int damping_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_95_1) & 63;
  aux_2 = (aux_2 + damping_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_29_1)
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

  switch (residue_29_2)
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

  int factor_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_57_1 > 37)
  {
    acc_1 = ((acc_1 + (factor_57_1 * 2)) + 5) & 127;
    aux_1 ^= factor_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_57_2 > 37)
  {
    acc_2 = ((acc_2 + (factor_57_2 * 2)) + 5) & 127;
    aux_2 ^= factor_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_92_1 = local_arr_1[aux_1 % 3];
  int segment_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_92_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_95_1 == damping_95_2);
  assert(residue_29_1 == residue_29_2);
  assert(factor_57_1 == factor_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_92_1 == segment_92_2);
}

int fn_R000327_2713_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000327_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int damping_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_95) & 63;
  acc ^= aux;
  int residue_29 = (aux + st.buffer[1]) & 3;
  switch (residue_29)
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

  int factor_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_57 > 37)
  {
    acc = ((acc + (factor_57 * 2)) + 5) & 127;
    aux ^= factor_57 & 15;
  }
  else
  {
    acc = ((acc - factor_57) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_92 = local_arr[aux % 3];
  acc = (acc + (segment_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000327_2713_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000327_2713_1 st_1 = {0};
  struct EventLog_R000327_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int residue_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_47_1) & 63;
  aux_2 = (aux_2 + residue_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_83_1 > 15)
  {
    acc_1 = ((acc_1 + (delta_83_1 * 2)) + 5) & 127;
    aux_1 ^= delta_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_83_2 > 15)
  {
    acc_2 = ((acc_2 + (delta_83_2 * 2)) + 5) & 127;
    aux_2 ^= delta_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_35_1)
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

  switch (window_35_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_47_1 == residue_47_2);
  assert(delta_83_1 == delta_83_2);
  assert(window_35_1 == window_35_2);
}

int fn_R000327_2713_21(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000327_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int residue_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_47) & 63;
  acc ^= aux;
  int delta_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_83 > 15)
  {
    acc = ((acc + (delta_83 * 2)) + 5) & 127;
    aux ^= delta_83 & 15;
  }
  else
  {
    acc = ((acc - delta_83) + 11) & 127;
    aux += 3;
  }
  int window_35 = (aux + st.buffer[1]) & 3;
  switch (window_35)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000327_2713_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000327_2713_1 st_1 = {0};
  struct EventLog_R000327_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int tracker_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_85_1)
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

  switch (tracker_85_2)
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

  int sample_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_37_1 > 28)
  {
    acc_1 = ((acc_1 + (sample_37_1 * 2)) + 5) & 127;
    aux_1 ^= sample_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_37_2 > 28)
  {
    acc_2 = ((acc_2 + (sample_37_2 * 2)) + 5) & 127;
    aux_2 ^= sample_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_31_1) & 63;
  aux_2 = (aux_2 + accumulator_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_40_1 = local_arr_1[aux_1 % 3];
  int vector_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_85_1 == tracker_85_2);
  assert(sample_37_1 == sample_37_2);
  assert(accumulator_31_1 == accumulator_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_40_1 == vector_40_2);
}

int fn_R000327_2713_22(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000327_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int tracker_85 = (aux + st.buffer[1]) & 3;
  switch (tracker_85)
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

  int sample_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_37 > 28)
  {
    acc = ((acc + (sample_37 * 2)) + 5) & 127;
    aux ^= sample_37 & 15;
  }
  else
  {
    acc = ((acc - sample_37) + 11) & 127;
    aux += 3;
  }
  int accumulator_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_31) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_40 = local_arr[aux % 3];
  acc = (acc + (vector_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000327_2713_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000327_2713_1 st_1 = {0};
  struct EventLog_R000327_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_46_1 = local_arr_1[aux_1 % 3];
  int threshold_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_46_2 * 2)) & 127;
  int damping_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_78_1) & 63;
  aux_2 = (aux_2 + damping_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_26_1 > 23)
  {
    acc_1 = ((acc_1 + (pivot_26_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_26_2 > 23)
  {
    acc_2 = ((acc_2 + (pivot_26_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_26_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_46_1 == threshold_46_2);
  assert(damping_78_1 == damping_78_2);
  assert(pivot_26_1 == pivot_26_2);
}

int fn_R000327_2713_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000327_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int threshold_46 = local_arr[aux % 3];
  acc = (acc + (threshold_46 * 2)) & 127;
  int damping_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_78) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_26 > 23)
  {
    acc = ((acc + (pivot_26 * 2)) + 5) & 127;
    aux ^= pivot_26 & 15;
  }
  else
  {
    acc = ((acc - pivot_26) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000327_0_1;
  int sec_r000327_0_2;
  int sec_r000327_1_1;
  int sec_r000327_1_2;
  int sec_r000327_2_1;
  int sec_r000327_2_2;
  int sec_r000327_3_1;
  int sec_r000327_3_2;
  int sec_r000327_4_1;
  int sec_r000327_4_2;
  int sec_r000327_5_1;
  int sec_r000327_5_2;
  int sec_r000327_6_1;
  int sec_r000327_6_2;
  int sec_r000327_7_1;
  int sec_r000327_7_2;
  int sec_r000327_8_1;
  int sec_r000327_8_2;
  int sec_r000327_9_1;
  int sec_r000327_9_2;
  int sec_r000327_10_1;
  int sec_r000327_10_2;
  int sec_r000327_11_1;
  int sec_r000327_11_2;
  int sec_r000327_12_1;
  int sec_r000327_12_2;
  int sec_r000327_13_1;
  int sec_r000327_13_2;
  int sec_r000327_14_1;
  int sec_r000327_14_2;
  int sec_r000327_15_1;
  int sec_r000327_15_2;
  int sec_r000327_16_1;
  int sec_r000327_16_2;
  int sec_r000327_17_1;
  int sec_r000327_17_2;
  int sec_r000327_18_1;
  int sec_r000327_18_2;
  int sec_r000327_19_1;
  int sec_r000327_19_2;
  int pub_r000327_0_1;
  int pub_r000327_0_2;
  int pub_r000327_1_1;
  int pub_r000327_1_2;
  int pub_r000327_2_1;
  int pub_r000327_2_2;
  int pub_r000327_3_1;
  int pub_r000327_3_2;
  int pub_r000327_4_1;
  int pub_r000327_4_2;
  int pub_r000327_5_1;
  int pub_r000327_5_2;
  int pub_r000327_6_1;
  int pub_r000327_6_2;
  int pub_r000327_7_1;
  int pub_r000327_7_2;
  int pub_r000327_8_1;
  int pub_r000327_8_2;
  int pub_r000327_9_1;
  int pub_r000327_9_2;
  int pub_r000327_10_1;
  int pub_r000327_10_2;
  int pub_r000327_11_1;
  int pub_r000327_11_2;
  int pub_r000327_12_1;
  int pub_r000327_12_2;
  int pub_r000327_13_1;
  int pub_r000327_13_2;
  int pub_r000327_14_1;
  int pub_r000327_14_2;
  int pub_r000327_15_1;
  int pub_r000327_15_2;
  int pub_r000327_16_1;
  int pub_r000327_16_2;
  int pub_r000327_17_1;
  int pub_r000327_17_2;
  int pub_r000327_18_1;
  int pub_r000327_18_2;
  int pub_r000327_19_1;
  int pub_r000327_19_2;
  int pub_r000327_20_1;
  int pub_r000327_20_2;
  int pub_r000327_21_1;
  int pub_r000327_21_2;
  int pub_r000327_22_1;
  int pub_r000327_22_2;
  int pub_r000327_23_1;
  int pub_r000327_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000327_0_1 >= (-100)) && (pub_r000327_0_1 <= 100));
  __CPROVER_assume((pub_r000327_0_2 >= (-100)) && (pub_r000327_0_2 <= 100));
  __CPROVER_assume((pub_r000327_1_1 >= (-100)) && (pub_r000327_1_1 <= 100));
  __CPROVER_assume((pub_r000327_1_2 >= (-100)) && (pub_r000327_1_2 <= 100));
  __CPROVER_assume((pub_r000327_2_1 >= (-100)) && (pub_r000327_2_1 <= 100));
  __CPROVER_assume((pub_r000327_2_2 >= (-100)) && (pub_r000327_2_2 <= 100));
  __CPROVER_assume((pub_r000327_3_1 >= (-100)) && (pub_r000327_3_1 <= 100));
  __CPROVER_assume((pub_r000327_3_2 >= (-100)) && (pub_r000327_3_2 <= 100));
  __CPROVER_assume((pub_r000327_4_1 >= (-100)) && (pub_r000327_4_1 <= 100));
  __CPROVER_assume((pub_r000327_4_2 >= (-100)) && (pub_r000327_4_2 <= 100));
  __CPROVER_assume((pub_r000327_5_1 >= (-100)) && (pub_r000327_5_1 <= 100));
  __CPROVER_assume((pub_r000327_5_2 >= (-100)) && (pub_r000327_5_2 <= 100));
  __CPROVER_assume((pub_r000327_6_1 >= (-100)) && (pub_r000327_6_1 <= 100));
  __CPROVER_assume((pub_r000327_6_2 >= (-100)) && (pub_r000327_6_2 <= 100));
  __CPROVER_assume((pub_r000327_7_1 >= (-100)) && (pub_r000327_7_1 <= 100));
  __CPROVER_assume((pub_r000327_7_2 >= (-100)) && (pub_r000327_7_2 <= 100));
  __CPROVER_assume((pub_r000327_8_1 >= (-100)) && (pub_r000327_8_1 <= 100));
  __CPROVER_assume((pub_r000327_8_2 >= (-100)) && (pub_r000327_8_2 <= 100));
  __CPROVER_assume((pub_r000327_9_1 >= (-100)) && (pub_r000327_9_1 <= 100));
  __CPROVER_assume((pub_r000327_9_2 >= (-100)) && (pub_r000327_9_2 <= 100));
  __CPROVER_assume((pub_r000327_10_1 >= (-100)) && (pub_r000327_10_1 <= 100));
  __CPROVER_assume((pub_r000327_10_2 >= (-100)) && (pub_r000327_10_2 <= 100));
  __CPROVER_assume((pub_r000327_11_1 >= (-100)) && (pub_r000327_11_1 <= 100));
  __CPROVER_assume((pub_r000327_11_2 >= (-100)) && (pub_r000327_11_2 <= 100));
  __CPROVER_assume((pub_r000327_12_1 >= (-100)) && (pub_r000327_12_1 <= 100));
  __CPROVER_assume((pub_r000327_12_2 >= (-100)) && (pub_r000327_12_2 <= 100));
  __CPROVER_assume((pub_r000327_13_1 >= (-100)) && (pub_r000327_13_1 <= 100));
  __CPROVER_assume((pub_r000327_13_2 >= (-100)) && (pub_r000327_13_2 <= 100));
  __CPROVER_assume((pub_r000327_14_1 >= (-100)) && (pub_r000327_14_1 <= 100));
  __CPROVER_assume((pub_r000327_14_2 >= (-100)) && (pub_r000327_14_2 <= 100));
  __CPROVER_assume((pub_r000327_15_1 >= (-100)) && (pub_r000327_15_1 <= 100));
  __CPROVER_assume((pub_r000327_15_2 >= (-100)) && (pub_r000327_15_2 <= 100));
  __CPROVER_assume((pub_r000327_16_1 >= (-100)) && (pub_r000327_16_1 <= 100));
  __CPROVER_assume((pub_r000327_16_2 >= (-100)) && (pub_r000327_16_2 <= 100));
  __CPROVER_assume((pub_r000327_17_1 >= (-100)) && (pub_r000327_17_1 <= 100));
  __CPROVER_assume((pub_r000327_17_2 >= (-100)) && (pub_r000327_17_2 <= 100));
  __CPROVER_assume((pub_r000327_18_1 >= (-100)) && (pub_r000327_18_1 <= 100));
  __CPROVER_assume((pub_r000327_18_2 >= (-100)) && (pub_r000327_18_2 <= 100));
  __CPROVER_assume((pub_r000327_19_1 >= (-100)) && (pub_r000327_19_1 <= 100));
  __CPROVER_assume((pub_r000327_19_2 >= (-100)) && (pub_r000327_19_2 <= 100));
  __CPROVER_assume((pub_r000327_20_1 >= (-100)) && (pub_r000327_20_1 <= 100));
  __CPROVER_assume((pub_r000327_20_2 >= (-100)) && (pub_r000327_20_2 <= 100));
  __CPROVER_assume((pub_r000327_21_1 >= (-100)) && (pub_r000327_21_1 <= 100));
  __CPROVER_assume((pub_r000327_21_2 >= (-100)) && (pub_r000327_21_2 <= 100));
  __CPROVER_assume((pub_r000327_22_1 >= (-100)) && (pub_r000327_22_1 <= 100));
  __CPROVER_assume((pub_r000327_22_2 >= (-100)) && (pub_r000327_22_2 <= 100));
  __CPROVER_assume((pub_r000327_23_1 >= (-100)) && (pub_r000327_23_1 <= 100));
  __CPROVER_assume((pub_r000327_23_2 >= (-100)) && (pub_r000327_23_2 <= 100));
  __CPROVER_assume((sec_r000327_0_1 >= 0) && (sec_r000327_0_1 <= 255));
  __CPROVER_assume((sec_r000327_0_2 >= 0) && (sec_r000327_0_2 <= 255));
  __CPROVER_assume((sec_r000327_1_1 >= 0) && (sec_r000327_1_1 <= 255));
  __CPROVER_assume((sec_r000327_1_2 >= 0) && (sec_r000327_1_2 <= 255));
  __CPROVER_assume((sec_r000327_2_1 >= 0) && (sec_r000327_2_1 <= 255));
  __CPROVER_assume((sec_r000327_2_2 >= 0) && (sec_r000327_2_2 <= 255));
  __CPROVER_assume((sec_r000327_3_1 >= 0) && (sec_r000327_3_1 <= 255));
  __CPROVER_assume((sec_r000327_3_2 >= 0) && (sec_r000327_3_2 <= 255));
  __CPROVER_assume((sec_r000327_4_1 >= 0) && (sec_r000327_4_1 <= 255));
  __CPROVER_assume((sec_r000327_4_2 >= 0) && (sec_r000327_4_2 <= 255));
  __CPROVER_assume((sec_r000327_5_1 >= 0) && (sec_r000327_5_1 <= 255));
  __CPROVER_assume((sec_r000327_5_2 >= 0) && (sec_r000327_5_2 <= 255));
  __CPROVER_assume((sec_r000327_6_1 >= 0) && (sec_r000327_6_1 <= 255));
  __CPROVER_assume((sec_r000327_6_2 >= 0) && (sec_r000327_6_2 <= 255));
  __CPROVER_assume((sec_r000327_7_1 >= 0) && (sec_r000327_7_1 <= 255));
  __CPROVER_assume((sec_r000327_7_2 >= 0) && (sec_r000327_7_2 <= 255));
  __CPROVER_assume((sec_r000327_8_1 >= 0) && (sec_r000327_8_1 <= 255));
  __CPROVER_assume((sec_r000327_8_2 >= 0) && (sec_r000327_8_2 <= 255));
  __CPROVER_assume((sec_r000327_9_1 >= 0) && (sec_r000327_9_1 <= 255));
  __CPROVER_assume((sec_r000327_9_2 >= 0) && (sec_r000327_9_2 <= 255));
  __CPROVER_assume((sec_r000327_10_1 >= 0) && (sec_r000327_10_1 <= 255));
  __CPROVER_assume((sec_r000327_10_2 >= 0) && (sec_r000327_10_2 <= 255));
  __CPROVER_assume((sec_r000327_11_1 >= 0) && (sec_r000327_11_1 <= 255));
  __CPROVER_assume((sec_r000327_11_2 >= 0) && (sec_r000327_11_2 <= 255));
  __CPROVER_assume((sec_r000327_12_1 >= 0) && (sec_r000327_12_1 <= 255));
  __CPROVER_assume((sec_r000327_12_2 >= 0) && (sec_r000327_12_2 <= 255));
  __CPROVER_assume((sec_r000327_13_1 >= 0) && (sec_r000327_13_1 <= 255));
  __CPROVER_assume((sec_r000327_13_2 >= 0) && (sec_r000327_13_2 <= 255));
  __CPROVER_assume((sec_r000327_14_1 >= 0) && (sec_r000327_14_1 <= 255));
  __CPROVER_assume((sec_r000327_14_2 >= 0) && (sec_r000327_14_2 <= 255));
  __CPROVER_assume((sec_r000327_15_1 >= 0) && (sec_r000327_15_1 <= 255));
  __CPROVER_assume((sec_r000327_15_2 >= 0) && (sec_r000327_15_2 <= 255));
  __CPROVER_assume((sec_r000327_16_1 >= 0) && (sec_r000327_16_1 <= 255));
  __CPROVER_assume((sec_r000327_16_2 >= 0) && (sec_r000327_16_2 <= 255));
  __CPROVER_assume((sec_r000327_17_1 >= 0) && (sec_r000327_17_1 <= 255));
  __CPROVER_assume((sec_r000327_17_2 >= 0) && (sec_r000327_17_2 <= 255));
  __CPROVER_assume((sec_r000327_18_1 >= 0) && (sec_r000327_18_1 <= 255));
  __CPROVER_assume((sec_r000327_18_2 >= 0) && (sec_r000327_18_2 <= 255));
  __CPROVER_assume((sec_r000327_19_1 >= 0) && (sec_r000327_19_1 <= 255));
  __CPROVER_assume((sec_r000327_19_2 >= 0) && (sec_r000327_19_2 <= 255));
  struct CipherContext_R000327_2713_0 st_var_0_1 = {0};
  struct CipherContext_R000327_2713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000327_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000327_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000327_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000327_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000327_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000327_0_2 + 7) & 15;
  struct EventLog_R000327_2713_1 st_var_1_1 = {0};
  struct EventLog_R000327_2713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000327_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000327_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000327_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000327_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000327_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000327_0_2 + 9) & 15;
  struct StreamBuffer_R000327_2713_2 st_var_2_1 = {0};
  struct StreamBuffer_R000327_2713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000327_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000327_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000327_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000327_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000327_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000327_0_2 + 11) & 15;
  union ColorPixel_R000327_2713_0 u_var_1;
  union ColorPixel_R000327_2713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = ((st_var_0_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_0_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 34)
    {
      chk_sum_1 ^= stage_v_6_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_6_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 34)
    {
      chk_sum_2 ^= stage_v_6_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 16) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((st_var_2_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_2_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 51)
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
  if (stage_v_17_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 51)
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
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((st_var_0_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_0_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 27)
    {
      chk_sum_1 ^= stage_v_21_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_21_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 27)
    {
      chk_sum_2 ^= stage_v_21_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  if ((sec_r000327_1_1 & 1) != 0)
  {
    if ((sec_r000327_14_1 & 2) != 0)
    {
      stage_v_28_1 = (pub_r000327_6_1 + 31) & 127;
    }
    else
    {
      stage_v_28_1 = (pub_r000327_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_1 = (pub_r000327_6_1 + 7) & 127;
  }
  if ((sec_r000327_1_2 & 1) != 0)
  {
    if ((sec_r000327_14_2 & 2) != 0)
    {
      stage_v_28_2 = (pub_r000327_6_2 + 31) & 127;
    }
    else
    {
      stage_v_28_2 = (pub_r000327_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_2 = (pub_r000327_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((sec_r000327_4_1 & 1) != 0)
  {
    if ((sec_r000327_4_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000327_18_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000327_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000327_18_1 + 7) & 127;
  }
  if ((sec_r000327_4_2 & 1) != 0)
  {
    if ((sec_r000327_4_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000327_18_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000327_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000327_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000327_17_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000327_10_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000327_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000327_10_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000327_17_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000327_10_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000327_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000327_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000327_15_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000327_13_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000327_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000327_13_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000327_15_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000327_13_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000327_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000327_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000327_6_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000327_15_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000327_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000327_15_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000327_6_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000327_15_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000327_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000327_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((sec_r000327_7_1 & 1) != 0)
  {
    if ((sec_r000327_4_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000327_4_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000327_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000327_4_1 + 7) & 127;
  }
  if ((sec_r000327_7_2 & 1) != 0)
  {
    if ((sec_r000327_4_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000327_4_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000327_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000327_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((sec_r000327_14_1 & 1) != 0)
  {
    if ((sec_r000327_12_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000327_19_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000327_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000327_19_1 + 7) & 127;
  }
  if ((sec_r000327_14_2 & 1) != 0)
  {
    if ((sec_r000327_12_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000327_19_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000327_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000327_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000327_6_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000327_6_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000327_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000327_6_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000327_6_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000327_6_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000327_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000327_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000327_17_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000327_22_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000327_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000327_22_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000327_17_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000327_22_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000327_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000327_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000327_1_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000327_7_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000327_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000327_7_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000327_1_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000327_7_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000327_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000327_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000327_7_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000327_23_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000327_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000327_23_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000327_7_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000327_23_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000327_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000327_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((sec_r000327_7_1 & 1) != 0)
  {
    if ((sec_r000327_9_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000327_20_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000327_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000327_20_1 + 7) & 127;
  }
  if ((sec_r000327_7_2 & 1) != 0)
  {
    if ((sec_r000327_9_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000327_20_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000327_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000327_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((sec_r000327_15_1 & 1) != 0)
  {
    if ((sec_r000327_3_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000327_21_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000327_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000327_21_1 + 7) & 127;
  }
  if ((sec_r000327_15_2 & 1) != 0)
  {
    if ((sec_r000327_3_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000327_21_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000327_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000327_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((sec_r000327_9_1 & 1) != 0)
  {
    if ((sec_r000327_16_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000327_12_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000327_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000327_12_1 + 7) & 127;
  }
  if ((sec_r000327_9_2 & 1) != 0)
  {
    if ((sec_r000327_16_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000327_12_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000327_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000327_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000327_8_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000327_19_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000327_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000327_19_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000327_8_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000327_19_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000327_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000327_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000327_3_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000327_2_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000327_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000327_2_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000327_3_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000327_2_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000327_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000327_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000327_0_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000327_20_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000327_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000327_20_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000327_0_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000327_20_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000327_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000327_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000327_6_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000327_16_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000327_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000327_16_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000327_6_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000327_16_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000327_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000327_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000327_3_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000327_5_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000327_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000327_5_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000327_3_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000327_5_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000327_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000327_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000327_6_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000327_18_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000327_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000327_18_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000327_6_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000327_18_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000327_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000327_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000327_19_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000327_12_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000327_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000327_12_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000327_19_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000327_12_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000327_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000327_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((sec_r000327_4_1 & 1) != 0)
  {
    if ((sec_r000327_5_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000327_18_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000327_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000327_18_1 + 7) & 127;
  }
  if ((sec_r000327_4_2 & 1) != 0)
  {
    if ((sec_r000327_5_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000327_18_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000327_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000327_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((sec_r000327_2_1 & 1) != 0)
  {
    if ((sec_r000327_17_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000327_22_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000327_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000327_22_1 + 7) & 127;
  }
  if ((sec_r000327_2_2 & 1) != 0)
  {
    if ((sec_r000327_17_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000327_22_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000327_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000327_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000327_8_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000327_2_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000327_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000327_2_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000327_8_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000327_2_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000327_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000327_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000327_0_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000327_2_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000327_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000327_2_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000327_0_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000327_2_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000327_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000327_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000327_13_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000327_7_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000327_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000327_7_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000327_13_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000327_7_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000327_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000327_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000327_15_1 & 1) != 0)
  {
    if ((sec_r000327_9_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000327_13_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000327_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000327_13_1 + 7) & 127;
  }
  if ((sec_r000327_15_2 & 1) != 0)
  {
    if ((sec_r000327_9_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000327_13_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000327_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000327_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000327_12_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000327_13_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000327_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000327_13_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000327_12_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000327_13_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000327_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000327_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((sec_r000327_1_1 & 1) != 0)
  {
    if ((sec_r000327_6_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000327_20_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000327_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000327_20_1 + 7) & 127;
  }
  if ((sec_r000327_1_2 & 1) != 0)
  {
    if ((sec_r000327_6_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000327_20_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000327_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000327_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((sec_r000327_0_1 & 1) != 0)
  {
    if ((sec_r000327_6_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000327_21_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000327_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000327_21_1 + 7) & 127;
  }
  if ((sec_r000327_0_2 & 1) != 0)
  {
    if ((sec_r000327_6_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000327_21_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000327_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000327_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000327_6_1 & 1) != 0)
  {
    if ((sec_r000327_8_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000327_13_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000327_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000327_13_1 + 7) & 127;
  }
  if ((sec_r000327_6_2 & 1) != 0)
  {
    if ((sec_r000327_8_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000327_13_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000327_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000327_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000327_0_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000327_20_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000327_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000327_20_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000327_0_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000327_20_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000327_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000327_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000327_6_1 & 1) != 0)
  {
    if ((sec_r000327_11_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000327_12_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000327_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000327_12_1 + 7) & 127;
  }
  if ((sec_r000327_6_2 & 1) != 0)
  {
    if ((sec_r000327_11_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000327_12_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000327_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000327_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((sec_r000327_11_1 & 1) != 0)
  {
    if ((sec_r000327_2_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000327_18_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000327_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000327_18_1 + 7) & 127;
  }
  if ((sec_r000327_11_2 & 1) != 0)
  {
    if ((sec_r000327_2_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000327_18_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000327_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000327_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000327_7_1 & 1) != 0)
  {
    if ((sec_r000327_17_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000327_21_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000327_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000327_21_1 + 7) & 127;
  }
  if ((sec_r000327_7_2 & 1) != 0)
  {
    if ((sec_r000327_17_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000327_21_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000327_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000327_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000327_6_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000327_17_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000327_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000327_17_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000327_6_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000327_17_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000327_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000327_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000327_8_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000327_21_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000327_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000327_21_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000327_8_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000327_21_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000327_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000327_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000327_2_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000327_16_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000327_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000327_16_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000327_2_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000327_16_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000327_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000327_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000327_0_1 & 1) != 0)
  {
    if ((sec_r000327_0_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000327_23_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000327_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000327_23_1 + 7) & 127;
  }
  if ((sec_r000327_0_2 & 1) != 0)
  {
    if ((sec_r000327_0_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000327_23_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000327_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000327_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000327_12_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000327_9_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000327_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000327_9_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000327_12_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000327_9_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000327_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000327_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000327_18_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000327_22_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000327_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000327_22_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000327_18_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000327_22_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000327_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000327_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000327_7_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000327_16_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000327_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000327_16_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000327_7_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000327_16_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000327_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000327_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000327_0_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000327_8_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000327_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000327_8_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000327_0_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000327_8_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000327_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000327_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000327_16_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000327_18_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000327_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000327_18_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000327_16_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000327_18_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000327_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000327_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000327_6_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000327_16_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000327_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000327_16_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000327_6_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000327_16_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000327_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000327_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000327_3_1 & 1) != 0)
  {
    if ((sec_r000327_13_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000327_12_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000327_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000327_12_1 + 7) & 127;
  }
  if ((sec_r000327_3_2 & 1) != 0)
  {
    if ((sec_r000327_13_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000327_12_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000327_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000327_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000327_14_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000327_22_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000327_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000327_22_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000327_14_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000327_22_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000327_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000327_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000327_15_1 & 1) != 0)
  {
    if ((sec_r000327_7_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000327_4_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000327_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000327_4_1 + 7) & 127;
  }
  if ((sec_r000327_15_2 & 1) != 0)
  {
    if ((sec_r000327_7_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000327_4_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000327_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000327_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000327_1_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000327_5_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000327_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000327_5_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000327_1_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000327_5_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000327_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000327_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000327_18_1 & 1) != 0)
  {
    if ((sec_r000327_1_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000327_7_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000327_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000327_7_1 + 7) & 127;
  }
  if ((sec_r000327_18_2 & 1) != 0)
  {
    if ((sec_r000327_1_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000327_7_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000327_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000327_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000327_19_1 & 1) != 0)
  {
    if ((sec_r000327_15_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000327_0_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000327_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000327_0_1 + 7) & 127;
  }
  if ((sec_r000327_19_2 & 1) != 0)
  {
    if ((sec_r000327_15_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000327_0_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000327_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000327_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000327_7_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000327_22_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000327_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000327_22_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000327_7_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000327_22_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000327_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000327_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000327_2_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000327_7_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000327_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000327_7_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000327_2_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000327_7_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000327_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000327_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000327_11_1 & 1) != 0)
  {
    if ((sec_r000327_18_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000327_3_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000327_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000327_3_1 + 7) & 127;
  }
  if ((sec_r000327_11_2 & 1) != 0)
  {
    if ((sec_r000327_18_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000327_3_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000327_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000327_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000327_2_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000327_20_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000327_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000327_20_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000327_2_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000327_20_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000327_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000327_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000327_14_1 & 1) != 0)
  {
    if ((sec_r000327_14_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000327_11_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000327_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000327_11_1 + 7) & 127;
  }
  if ((sec_r000327_14_2 & 1) != 0)
  {
    if ((sec_r000327_14_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000327_11_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000327_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000327_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000327_17_1 & 1) != 0)
  {
    if ((sec_r000327_5_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000327_2_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000327_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000327_2_1 + 7) & 127;
  }
  if ((sec_r000327_17_2 & 1) != 0)
  {
    if ((sec_r000327_5_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000327_2_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000327_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000327_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000327_3_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000327_19_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000327_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000327_19_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000327_3_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000327_19_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000327_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000327_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000327_13_1 & 1) != 0)
  {
    if ((sec_r000327_4_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000327_4_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000327_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000327_4_1 + 7) & 127;
  }
  if ((sec_r000327_13_2 & 1) != 0)
  {
    if ((sec_r000327_4_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000327_4_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000327_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000327_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000327_2_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000327_4_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000327_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000327_4_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000327_2_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000327_4_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000327_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000327_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000327_8_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000327_19_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000327_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000327_19_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000327_8_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000327_19_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000327_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000327_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000327_2_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000327_18_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000327_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000327_18_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000327_2_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000327_18_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000327_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000327_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000327_9_1 & 1) != 0)
  {
    if ((sec_r000327_15_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000327_1_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000327_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000327_1_1 + 7) & 127;
  }
  if ((sec_r000327_9_2 & 1) != 0)
  {
    if ((sec_r000327_15_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000327_1_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000327_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000327_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000327_7_1 & 1) != 0)
  {
    if ((sec_r000327_11_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000327_3_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000327_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000327_3_1 + 7) & 127;
  }
  if ((sec_r000327_7_2 & 1) != 0)
  {
    if ((sec_r000327_11_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000327_3_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000327_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000327_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000327_11_1 & 1) != 0)
  {
    if ((sec_r000327_5_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000327_22_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000327_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000327_22_1 + 7) & 127;
  }
  if ((sec_r000327_11_2 & 1) != 0)
  {
    if ((sec_r000327_5_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000327_22_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000327_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000327_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000327_15_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000327_19_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000327_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000327_19_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000327_15_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000327_19_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000327_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000327_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000327_18_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000327_1_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000327_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000327_1_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000327_18_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000327_1_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000327_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000327_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000327_0_1 & 1) != 0)
  {
    if ((sec_r000327_17_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000327_0_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000327_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000327_0_1 + 7) & 127;
  }
  if ((sec_r000327_0_2 & 1) != 0)
  {
    if ((sec_r000327_17_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000327_0_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000327_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000327_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000327_13_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000327_10_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000327_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000327_10_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000327_13_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000327_10_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000327_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000327_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000327_16_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000327_4_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000327_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000327_4_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000327_16_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000327_4_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000327_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000327_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000327_4_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000327_1_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000327_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000327_1_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000327_4_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000327_1_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000327_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000327_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000327_4_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000327_14_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000327_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000327_14_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000327_4_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000327_14_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000327_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000327_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000327_2_1 & 1) != 0)
  {
    if ((sec_r000327_19_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000327_23_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000327_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000327_23_1 + 7) & 127;
  }
  if ((sec_r000327_2_2 & 1) != 0)
  {
    if ((sec_r000327_19_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000327_23_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000327_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000327_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000327_17_1 & 1) != 0)
  {
    if ((sec_r000327_5_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000327_13_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000327_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000327_13_1 + 7) & 127;
  }
  if ((sec_r000327_17_2 & 1) != 0)
  {
    if ((sec_r000327_5_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000327_13_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000327_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000327_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000327_12_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000327_15_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000327_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000327_15_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000327_12_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000327_15_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000327_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000327_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000327_3_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000327_18_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000327_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000327_18_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000327_3_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000327_18_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000327_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000327_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000327_17_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000327_20_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000327_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000327_20_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000327_17_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000327_20_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000327_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000327_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000327_16_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000327_3_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000327_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000327_3_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000327_16_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000327_3_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000327_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000327_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000327_5_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000327_14_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000327_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000327_14_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000327_5_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000327_14_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000327_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000327_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000327_19_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000327_11_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000327_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000327_11_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000327_19_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000327_11_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000327_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000327_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000327_5_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000327_0_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000327_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000327_0_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000327_5_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000327_0_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000327_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000327_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000327_16_1 & 1) != 0)
  {
    if ((sec_r000327_19_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000327_16_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000327_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000327_16_1 + 7) & 127;
  }
  if ((sec_r000327_16_2 & 1) != 0)
  {
    if ((sec_r000327_19_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000327_16_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000327_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000327_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000327_4_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000327_2_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000327_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000327_2_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000327_4_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000327_2_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000327_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000327_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000327_11_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000327_5_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000327_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000327_5_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000327_11_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000327_5_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000327_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000327_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000327_1_1 & 1) != 0)
  {
    if ((sec_r000327_3_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000327_2_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000327_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000327_2_1 + 7) & 127;
  }
  if ((sec_r000327_1_2 & 1) != 0)
  {
    if ((sec_r000327_3_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000327_2_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000327_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000327_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000327_9_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000327_13_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000327_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000327_13_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000327_9_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000327_13_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000327_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000327_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000327_19_1 & 1) != 0)
  {
    if ((sec_r000327_12_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000327_5_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000327_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000327_5_1 + 7) & 127;
  }
  if ((sec_r000327_19_2 & 1) != 0)
  {
    if ((sec_r000327_12_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000327_5_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000327_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000327_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000327_12_1 & 1) != 0)
  {
    if ((sec_r000327_10_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000327_5_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000327_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000327_5_1 + 7) & 127;
  }
  if ((sec_r000327_12_2 & 1) != 0)
  {
    if ((sec_r000327_10_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000327_5_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000327_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000327_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000327_1_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000327_2_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000327_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000327_2_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000327_1_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000327_2_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000327_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000327_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000327_11_1 & 1) != 0)
  {
    if ((sec_r000327_19_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000327_5_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000327_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000327_5_1 + 7) & 127;
  }
  if ((sec_r000327_11_2 & 1) != 0)
  {
    if ((sec_r000327_19_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000327_5_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000327_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000327_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000327_6_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000327_18_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000327_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000327_18_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000327_6_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000327_18_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000327_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000327_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000327_14_1 & 1) != 0)
  {
    if ((sec_r000327_3_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000327_16_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000327_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000327_16_1 + 7) & 127;
  }
  if ((sec_r000327_14_2 & 1) != 0)
  {
    if ((sec_r000327_3_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000327_16_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000327_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000327_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000327_8_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000327_4_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000327_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000327_4_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000327_8_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000327_4_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000327_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000327_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000327_5_1 & 1) != 0)
  {
    if ((sec_r000327_16_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000327_22_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000327_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000327_22_1 + 7) & 127;
  }
  if ((sec_r000327_5_2 & 1) != 0)
  {
    if ((sec_r000327_16_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000327_22_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000327_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000327_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000327_4_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000327_13_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000327_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000327_13_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000327_4_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000327_13_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000327_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000327_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000327_4_1 == pub_r000327_4_2);
  __CPROVER_assume(pub_r000327_11_1 == pub_r000327_11_2);
  __CPROVER_assume(sec_r000327_8_1 != sec_r000327_8_2);
  __CPROVER_assume(pub_r000327_22_1 == pub_r000327_22_2);
  __CPROVER_assume(sec_r000327_16_1 != sec_r000327_16_2);
  __CPROVER_assume(sec_r000327_18_1 != sec_r000327_18_2);
  __CPROVER_assume(pub_r000327_12_1 == pub_r000327_12_2);
  __CPROVER_assume(sec_r000327_0_1 != sec_r000327_0_2);
  __CPROVER_assume(sec_r000327_10_1 != sec_r000327_10_2);
  __CPROVER_assume(pub_r000327_15_1 == pub_r000327_15_2);
  __CPROVER_assume(pub_r000327_21_1 == pub_r000327_21_2);
  __CPROVER_assume(pub_r000327_3_1 == pub_r000327_3_2);
  __CPROVER_assume(sec_r000327_11_1 != sec_r000327_11_2);
  __CPROVER_assume(sec_r000327_14_1 != sec_r000327_14_2);
  __CPROVER_assume(sec_r000327_12_1 != sec_r000327_12_2);
  __CPROVER_assume(sec_r000327_3_1 != sec_r000327_3_2);
  __CPROVER_assume(sec_r000327_6_1 != sec_r000327_6_2);
  __CPROVER_assume(pub_r000327_20_1 == pub_r000327_20_2);
  __CPROVER_assume(sec_r000327_17_1 != sec_r000327_17_2);
  __CPROVER_assume(sec_r000327_1_1 != sec_r000327_1_2);
  __CPROVER_assume(sec_r000327_7_1 != sec_r000327_7_2);
  __CPROVER_assume(pub_r000327_8_1 == pub_r000327_8_2);
  __CPROVER_assume(pub_r000327_23_1 == pub_r000327_23_2);
  __CPROVER_assume(pub_r000327_14_1 == pub_r000327_14_2);
  __CPROVER_assume(sec_r000327_13_1 != sec_r000327_13_2);
  __CPROVER_assume(pub_r000327_19_1 == pub_r000327_19_2);
  __CPROVER_assume(pub_r000327_7_1 == pub_r000327_7_2);
  __CPROVER_assume(pub_r000327_1_1 == pub_r000327_1_2);
  __CPROVER_assume(sec_r000327_5_1 != sec_r000327_5_2);
  __CPROVER_assume(pub_r000327_0_1 == pub_r000327_0_2);
  __CPROVER_assume(pub_r000327_13_1 == pub_r000327_13_2);
  __CPROVER_assume(pub_r000327_10_1 == pub_r000327_10_2);
  __CPROVER_assume(sec_r000327_19_1 != sec_r000327_19_2);
  __CPROVER_assume(pub_r000327_9_1 == pub_r000327_9_2);
  __CPROVER_assume(pub_r000327_17_1 == pub_r000327_17_2);
  __CPROVER_assume(sec_r000327_2_1 != sec_r000327_2_2);
  __CPROVER_assume(pub_r000327_5_1 == pub_r000327_5_2);
  __CPROVER_assume(pub_r000327_16_1 == pub_r000327_16_2);
  __CPROVER_assume(sec_r000327_4_1 != sec_r000327_4_2);
  __CPROVER_assume(pub_r000327_18_1 == pub_r000327_18_2);
  __CPROVER_assume(sec_r000327_15_1 != sec_r000327_15_2);
  __CPROVER_assume(pub_r000327_2_1 == pub_r000327_2_2);
  __CPROVER_assume(pub_r000327_6_1 == pub_r000327_6_2);
  __CPROVER_assume(sec_r000327_9_1 != sec_r000327_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
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
}


