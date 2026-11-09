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
struct AudioFrame_R001334_3413_0
{
  int peak;
  int channels;
  unsigned char envelope;
  int sample_rate;
  short rms;
  int buffer[3];
};
struct StreamBuffer_R001334_3413_1
{
  short head;
  unsigned char checksum;
  int tail;
  unsigned char watermark;
  short state;
  int buffer[3];
};
union TelemetryField_R001334_3413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001334_3413_1
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
void fn_R001334_3413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st_1 = {0};
  struct StreamBuffer_R001334_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int window_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_93_1 > 47)
  {
    acc_1 = ((acc_1 + (window_93_1 * 2)) + 5) & 127;
    aux_1 ^= window_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_93_2 > 47)
  {
    acc_2 = ((acc_2 + (window_93_2 * 2)) + 5) & 127;
    aux_2 ^= window_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_93_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_11_1)
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

  switch (cursor_11_2)
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
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_93_1 == window_93_2);
  assert(cursor_11_1 == cursor_11_2);
}

int fn_R001334_3413_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int window_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_93 > 47)
  {
    acc = ((acc + (window_93 * 2)) + 5) & 127;
    aux ^= window_93 & 15;
  }
  else
  {
    acc = ((acc - window_93) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_11 = (aux + st.buffer[1]) & 3;
  switch (cursor_11)
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

void fn_R001334_3413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st_1 = {0};
  struct StreamBuffer_R001334_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int weight_19_1 = 0;
  int weight_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_19_1 = ((weight_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_19_2 = ((weight_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_19_1) & 127;
    acc_2 = (acc_2 + weight_19_2) & 127;
  }

  int quantum_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_90_1) & 63;
  aux_2 = (aux_2 + quantum_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_29_1 = local_arr_1[aux_1 % 3];
  int residue_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_19_1 == weight_19_2);
  assert(quantum_90_1 == quantum_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_29_1 == residue_29_2);
}

int fn_R001334_3413_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int weight_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_19 = ((weight_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_19) & 127;
  }

  int quantum_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_90) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_29 = local_arr[aux % 3];
  acc = (acc + (residue_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001334_3413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st_1 = {0};
  struct AudioFrame_R001334_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int pivot_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_74_1 > 50)
  {
    acc_1 = ((acc_1 + (pivot_74_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_74_2 > 50)
  {
    acc_2 = ((acc_2 + (pivot_74_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_74_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_26_1) & 63;
  aux_2 = (aux_2 + scale_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_42_1)
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

  switch (scale_42_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_74_1 == pivot_74_2);
  assert(scale_26_1 == scale_26_2);
  assert(scale_42_1 == scale_42_2);
}

int fn_R001334_3413_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int pivot_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_74 > 50)
  {
    acc = ((acc + (pivot_74 * 2)) + 5) & 127;
    aux ^= pivot_74 & 15;
  }
  else
  {
    acc = ((acc - pivot_74) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_26) & 63;
  acc ^= aux;
  int scale_42 = (aux + st.buffer[1]) & 3;
  switch (scale_42)
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

void fn_R001334_3413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st_1 = {0};
  struct AudioFrame_R001334_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_39_1 = 0;
  int vector_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_39_1 = ((vector_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_39_2 = ((vector_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_39_1) & 127;
    acc_2 = (acc_2 + vector_39_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_58_1 = local_arr_1[aux_1 % 3];
  int quantum_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_58_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_39_1 == vector_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_58_1 == quantum_58_2);
}

int fn_R001334_3413_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_39 = ((vector_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_39) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quantum_58 = local_arr[aux % 3];
  acc = (acc + (quantum_58 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001334_3413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st_1 = {0};
  struct StreamBuffer_R001334_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_82_1)
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

  switch (pivot_82_2)
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
  int margin_43_1 = local_arr_1[aux_1 % 3];
  int margin_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_43_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_82_1 == pivot_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_43_1 == margin_43_2);
}

int fn_R001334_3413_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_82 = (aux + st.buffer[1]) & 3;
  switch (pivot_82)
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
  int margin_43 = local_arr[aux % 3];
  acc = (acc + (margin_43 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001334_3413_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st_1 = {0};
  struct AudioFrame_R001334_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int metric_54_1 = 0;
  int metric_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_54_1 = ((metric_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_54_2 = ((metric_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_54_1) & 127;
    acc_2 = (acc_2 + metric_54_2) & 127;
  }

  int damping_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_97_1 > 27)
  {
    acc_1 = ((acc_1 + (damping_97_1 * 2)) + 5) & 127;
    aux_1 ^= damping_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_97_2 > 27)
  {
    acc_2 = ((acc_2 + (damping_97_2 * 2)) + 5) & 127;
    aux_2 ^= damping_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_54_1 == metric_54_2);
  assert(damping_97_1 == damping_97_2);
}

int fn_R001334_3413_5(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int metric_54 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_54 = ((metric_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_54) & 127;
  }

  int damping_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_97 > 27)
  {
    acc = ((acc + (damping_97 * 2)) + 5) & 127;
    aux ^= damping_97 & 15;
  }
  else
  {
    acc = ((acc - damping_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001334_3413_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st_1 = {0};
  struct AudioFrame_R001334_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int margin_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_18_1)
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

  switch (margin_18_2)
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

  int metric_34_1 = 0;
  int metric_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_34_1 = ((metric_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_34_2 = ((metric_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_34_1) & 127;
    acc_2 = (acc_2 + metric_34_2) & 127;
  }

  int quotient_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_96_1 > 18)
  {
    acc_1 = ((acc_1 + (quotient_96_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_96_2 > 18)
  {
    acc_2 = ((acc_2 + (quotient_96_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_96_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_18_1 == margin_18_2);
  assert(metric_34_1 == metric_34_2);
  assert(quotient_96_1 == quotient_96_2);
}

int fn_R001334_3413_6(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int margin_18 = (aux + st.buffer[1]) & 3;
  switch (margin_18)
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

  int metric_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_34 = ((metric_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_34) & 127;
  }

  int quotient_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_96 > 18)
  {
    acc = ((acc + (quotient_96 * 2)) + 5) & 127;
    aux ^= quotient_96 & 15;
  }
  else
  {
    acc = ((acc - quotient_96) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001334_3413_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st_1 = {0};
  struct StreamBuffer_R001334_3413_1 st_2 = {0};
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
  int tracker_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_53_1)
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

  switch (tracker_53_2)
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
  int pivot_72_1 = local_arr_1[aux_1 % 3];
  int pivot_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_72_2 * 2)) & 127;
  int delta_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_43_1 > 26)
  {
    acc_1 = ((acc_1 + (delta_43_1 * 2)) + 5) & 127;
    aux_1 ^= delta_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_43_2 > 26)
  {
    acc_2 = ((acc_2 + (delta_43_2 * 2)) + 5) & 127;
    aux_2 ^= delta_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_43_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_53_1 == tracker_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_72_1 == pivot_72_2);
  assert(delta_43_1 == delta_43_2);
}

int fn_R001334_3413_7(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_53 = (aux + st.buffer[1]) & 3;
  switch (tracker_53)
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
  int pivot_72 = local_arr[aux % 3];
  acc = (acc + (pivot_72 * 2)) & 127;
  int delta_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_43 > 26)
  {
    acc = ((acc + (delta_43 * 2)) + 5) & 127;
    aux ^= delta_43 & 15;
  }
  else
  {
    acc = ((acc - delta_43) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001334_3413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st_1 = {0};
  struct AudioFrame_R001334_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int parity_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_85_1 > 31)
  {
    acc_1 = ((acc_1 + (parity_85_1 * 2)) + 5) & 127;
    aux_1 ^= parity_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_85_2 > 31)
  {
    acc_2 = ((acc_2 + (parity_85_2 * 2)) + 5) & 127;
    aux_2 ^= parity_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_21_1 = local_arr_1[aux_1 % 3];
  int index_reg_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_21_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_85_1 == parity_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_21_1 == index_reg_21_2);
}

int fn_R001334_3413_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int parity_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_85 > 31)
  {
    acc = ((acc + (parity_85 * 2)) + 5) & 127;
    aux ^= parity_85 & 15;
  }
  else
  {
    acc = ((acc - parity_85) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_21 = local_arr[aux % 3];
  acc = (acc + (index_reg_21 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001334_3413_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st_1 = {0};
  struct StreamBuffer_R001334_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int bound_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_51_1 > 24)
  {
    acc_1 = ((acc_1 + (bound_51_1 * 2)) + 5) & 127;
    aux_1 ^= bound_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_51_2 > 24)
  {
    acc_2 = ((acc_2 + (bound_51_2 * 2)) + 5) & 127;
    aux_2 ^= bound_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_61_1 = local_arr_1[aux_1 % 3];
  int phase_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_61_2 * 2)) & 127;
  int pivot_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_99_1) & 63;
  aux_2 = (aux_2 + pivot_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_51_1 == bound_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_61_1 == phase_61_2);
  assert(pivot_99_1 == pivot_99_2);
}

int fn_R001334_3413_9(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int bound_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_51 > 24)
  {
    acc = ((acc + (bound_51 * 2)) + 5) & 127;
    aux ^= bound_51 & 15;
  }
  else
  {
    acc = ((acc - bound_51) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int phase_61 = local_arr[aux % 3];
  acc = (acc + (phase_61 * 2)) & 127;
  int pivot_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001334_3413_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st_1 = {0};
  struct StreamBuffer_R001334_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quantum_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_39_1) & 63;
  aux_2 = (aux_2 + quantum_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_94_1)
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

  switch (anchor_94_2)
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

  int bound_66_1 = 0;
  int bound_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_66_1 = ((bound_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_66_2 = ((bound_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_66_1) & 127;
    acc_2 = (acc_2 + bound_66_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_39_1 == quantum_39_2);
  assert(anchor_94_1 == anchor_94_2);
  assert(bound_66_1 == bound_66_2);
}

int fn_R001334_3413_10(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quantum_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_39) & 63;
  acc ^= aux;
  int anchor_94 = (aux + st.buffer[1]) & 3;
  switch (anchor_94)
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

  int bound_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_66 = ((bound_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_66) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001334_3413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st_1 = {0};
  struct AudioFrame_R001334_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int coefficient_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_62_1)
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

  switch (coefficient_62_2)
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
  int sample_53_1 = local_arr_1[aux_1 % 3];
  int sample_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_53_2 * 2)) & 127;
  int segment_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_81_1 > 40)
  {
    acc_1 = ((acc_1 + (segment_81_1 * 2)) + 5) & 127;
    aux_1 ^= segment_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_81_2 > 40)
  {
    acc_2 = ((acc_2 + (segment_81_2 * 2)) + 5) & 127;
    aux_2 ^= segment_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_62_1 == coefficient_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_53_1 == sample_53_2);
  assert(segment_81_1 == segment_81_2);
}

int fn_R001334_3413_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int coefficient_62 = (aux + st.buffer[1]) & 3;
  switch (coefficient_62)
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
  int sample_53 = local_arr[aux % 3];
  acc = (acc + (sample_53 * 2)) & 127;
  int segment_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_81 > 40)
  {
    acc = ((acc + (segment_81 * 2)) + 5) & 127;
    aux ^= segment_81 & 15;
  }
  else
  {
    acc = ((acc - segment_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001334_3413_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st_1 = {0};
  struct AudioFrame_R001334_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int phase_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_20_1 > 31)
  {
    acc_1 = ((acc_1 + (phase_20_1 * 2)) + 5) & 127;
    aux_1 ^= phase_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_20_2 > 31)
  {
    acc_2 = ((acc_2 + (phase_20_2 * 2)) + 5) & 127;
    aux_2 ^= phase_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_77_1 = local_arr_1[aux_1 % 3];
  int quotient_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_77_2 * 2)) & 127;
  int residue_97_1 = 0;
  int residue_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_97_1 = ((residue_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_97_2 = ((residue_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_97_1) & 127;
    acc_2 = (acc_2 + residue_97_2) & 127;
  }

  int threshold_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_63_1) & 63;
  aux_2 = (aux_2 + threshold_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_20_1 == phase_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_77_1 == quotient_77_2);
  assert(residue_97_1 == residue_97_2);
  assert(threshold_63_1 == threshold_63_2);
}

int fn_R001334_3413_12(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int phase_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_20 > 31)
  {
    acc = ((acc + (phase_20 * 2)) + 5) & 127;
    aux ^= phase_20 & 15;
  }
  else
  {
    acc = ((acc - phase_20) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_77 = local_arr[aux % 3];
  acc = (acc + (quotient_77 * 2)) & 127;
  int residue_97 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_97 = ((residue_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_97) & 127;
  }

  int threshold_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_63) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001334_3413_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st_1 = {0};
  struct AudioFrame_R001334_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_53_1 = local_arr_1[aux_1 % 3];
  int threshold_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_53_2 * 2)) & 127;
  int quantum_99_1 = 0;
  int quantum_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_99_1 = ((quantum_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_99_2 = ((quantum_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_99_1) & 127;
    acc_2 = (acc_2 + quantum_99_2) & 127;
  }

  int margin_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_57_1) & 63;
  aux_2 = (aux_2 + margin_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_18_1 > 47)
  {
    acc_1 = ((acc_1 + (metric_18_1 * 2)) + 5) & 127;
    aux_1 ^= metric_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_18_2 > 47)
  {
    acc_2 = ((acc_2 + (metric_18_2 * 2)) + 5) & 127;
    aux_2 ^= metric_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_18_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_53_1 == threshold_53_2);
  assert(quantum_99_1 == quantum_99_2);
  assert(margin_57_1 == margin_57_2);
  assert(metric_18_1 == metric_18_2);
}

int fn_R001334_3413_13(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int threshold_53 = local_arr[aux % 3];
  acc = (acc + (threshold_53 * 2)) & 127;
  int quantum_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_99 = ((quantum_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_99) & 127;
  }

  int margin_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_57) & 63;
  acc ^= aux;
  int metric_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_18 > 47)
  {
    acc = ((acc + (metric_18 * 2)) + 5) & 127;
    aux ^= metric_18 & 15;
  }
  else
  {
    acc = ((acc - metric_18) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001334_3413_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st_1 = {0};
  struct AudioFrame_R001334_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int tally_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_88_1)
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

  switch (tally_88_2)
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

  int metric_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_74_1 > 34)
  {
    acc_1 = ((acc_1 + (metric_74_1 * 2)) + 5) & 127;
    aux_1 ^= metric_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_74_2 > 34)
  {
    acc_2 = ((acc_2 + (metric_74_2 * 2)) + 5) & 127;
    aux_2 ^= metric_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_19_1 = local_arr_1[aux_1 % 3];
  int cursor_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_88_1 == tally_88_2);
  assert(metric_74_1 == metric_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_19_1 == cursor_19_2);
}

int fn_R001334_3413_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int tally_88 = (aux + st.buffer[1]) & 3;
  switch (tally_88)
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

  int metric_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_74 > 34)
  {
    acc = ((acc + (metric_74 * 2)) + 5) & 127;
    aux ^= metric_74 & 15;
  }
  else
  {
    acc = ((acc - metric_74) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_19 = local_arr[aux % 3];
  acc = (acc + (cursor_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001334_3413_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st_1 = {0};
  struct AudioFrame_R001334_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int margin_36_1 = 0;
  int margin_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_36_1 = ((margin_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_36_2 = ((margin_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_36_1) & 127;
    acc_2 = (acc_2 + margin_36_2) & 127;
  }

  int segment_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_41_1) & 63;
  aux_2 = (aux_2 + segment_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_36_1 == margin_36_2);
  assert(segment_41_1 == segment_41_2);
}

int fn_R001334_3413_15(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int margin_36 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_36 = ((margin_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_36) & 127;
  }

  int segment_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_41) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001334_3413_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st_1 = {0};
  struct AudioFrame_R001334_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_44_1)
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

  switch (residue_44_2)
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

  int checksum_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_35_1 > 31)
  {
    acc_1 = ((acc_1 + (checksum_35_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_35_2 > 31)
  {
    acc_2 = ((acc_2 + (checksum_35_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_44_1 == residue_44_2);
  assert(checksum_35_1 == checksum_35_2);
}

int fn_R001334_3413_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_44 = (aux + st.buffer[1]) & 3;
  switch (residue_44)
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

  int checksum_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_35 > 31)
  {
    acc = ((acc + (checksum_35 * 2)) + 5) & 127;
    aux ^= checksum_35 & 15;
  }
  else
  {
    acc = ((acc - checksum_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001334_3413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st_1 = {0};
  struct AudioFrame_R001334_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int phase_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_95_1 > 45)
  {
    acc_1 = ((acc_1 + (phase_95_1 * 2)) + 5) & 127;
    aux_1 ^= phase_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_95_2 > 45)
  {
    acc_2 = ((acc_2 + (phase_95_2 * 2)) + 5) & 127;
    aux_2 ^= phase_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_31_1 = local_arr_1[aux_1 % 3];
  int segment_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_95_1 == phase_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_31_1 == segment_31_2);
}

int fn_R001334_3413_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int phase_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_95 > 45)
  {
    acc = ((acc + (phase_95 * 2)) + 5) & 127;
    aux ^= phase_95 & 15;
  }
  else
  {
    acc = ((acc - phase_95) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_31 = local_arr[aux % 3];
  acc = (acc + (segment_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001334_3413_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st_1 = {0};
  struct StreamBuffer_R001334_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int stride_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_54_1) & 63;
  aux_2 = (aux_2 + stride_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_54_1 == stride_54_2);
}

int fn_R001334_3413_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int stride_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_54) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001334_3413_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st_1 = {0};
  struct StreamBuffer_R001334_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_51_1 > 42)
  {
    acc_1 = ((acc_1 + (index_reg_51_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_51_2 > 42)
  {
    acc_2 = ((acc_2 + (index_reg_51_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_26_1) & 63;
  aux_2 = (aux_2 + checksum_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_99_1 = 0;
  int index_reg_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_99_1 = ((index_reg_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_99_2 = ((index_reg_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_99_1) & 127;
    acc_2 = (acc_2 + index_reg_99_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_51_1 == index_reg_51_2);
  assert(checksum_26_1 == checksum_26_2);
  assert(index_reg_99_1 == index_reg_99_2);
}

int fn_R001334_3413_19(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001334_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_51 > 42)
  {
    acc = ((acc + (index_reg_51 * 2)) + 5) & 127;
    aux ^= index_reg_51 & 15;
  }
  else
  {
    acc = ((acc - index_reg_51) + 11) & 127;
    aux += 3;
  }
  int checksum_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_26) & 63;
  acc ^= aux;
  int index_reg_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_99 = ((index_reg_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_99) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001334_3413_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st_1 = {0};
  struct AudioFrame_R001334_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int damping_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_78_1)
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

  switch (damping_78_2)
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

  int threshold_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_39_1 > 33)
  {
    acc_1 = ((acc_1 + (threshold_39_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_39_2 > 33)
  {
    acc_2 = ((acc_2 + (threshold_39_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_84_1) & 63;
  aux_2 = (aux_2 + segment_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_78_1 == damping_78_2);
  assert(threshold_39_1 == threshold_39_2);
  assert(segment_84_1 == segment_84_2);
}

int fn_R001334_3413_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001334_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int damping_78 = (aux + st.buffer[1]) & 3;
  switch (damping_78)
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

  int threshold_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_39 > 33)
  {
    acc = ((acc + (threshold_39 * 2)) + 5) & 127;
    aux ^= threshold_39 & 15;
  }
  else
  {
    acc = ((acc - threshold_39) + 11) & 127;
    aux += 3;
  }
  int segment_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_84) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001334_0_1;
  int sec_r001334_0_2;
  int sec_r001334_1_1;
  int sec_r001334_1_2;
  int sec_r001334_2_1;
  int sec_r001334_2_2;
  int sec_r001334_3_1;
  int sec_r001334_3_2;
  int sec_r001334_4_1;
  int sec_r001334_4_2;
  int sec_r001334_5_1;
  int sec_r001334_5_2;
  int sec_r001334_6_1;
  int sec_r001334_6_2;
  int sec_r001334_7_1;
  int sec_r001334_7_2;
  int sec_r001334_8_1;
  int sec_r001334_8_2;
  int sec_r001334_9_1;
  int sec_r001334_9_2;
  int sec_r001334_10_1;
  int sec_r001334_10_2;
  int sec_r001334_11_1;
  int sec_r001334_11_2;
  int sec_r001334_12_1;
  int sec_r001334_12_2;
  int sec_r001334_13_1;
  int sec_r001334_13_2;
  int sec_r001334_14_1;
  int sec_r001334_14_2;
  int sec_r001334_15_1;
  int sec_r001334_15_2;
  int sec_r001334_16_1;
  int sec_r001334_16_2;
  int sec_r001334_17_1;
  int sec_r001334_17_2;
  int sec_r001334_18_1;
  int sec_r001334_18_2;
  int sec_r001334_19_1;
  int sec_r001334_19_2;
  int sec_r001334_20_1;
  int sec_r001334_20_2;
  int pub_r001334_0_1;
  int pub_r001334_0_2;
  int pub_r001334_1_1;
  int pub_r001334_1_2;
  int pub_r001334_2_1;
  int pub_r001334_2_2;
  int pub_r001334_3_1;
  int pub_r001334_3_2;
  int pub_r001334_4_1;
  int pub_r001334_4_2;
  int pub_r001334_5_1;
  int pub_r001334_5_2;
  int pub_r001334_6_1;
  int pub_r001334_6_2;
  int pub_r001334_7_1;
  int pub_r001334_7_2;
  int pub_r001334_8_1;
  int pub_r001334_8_2;
  int pub_r001334_9_1;
  int pub_r001334_9_2;
  int pub_r001334_10_1;
  int pub_r001334_10_2;
  int pub_r001334_11_1;
  int pub_r001334_11_2;
  int pub_r001334_12_1;
  int pub_r001334_12_2;
  int pub_r001334_13_1;
  int pub_r001334_13_2;
  int pub_r001334_14_1;
  int pub_r001334_14_2;
  int pub_r001334_15_1;
  int pub_r001334_15_2;
  int pub_r001334_16_1;
  int pub_r001334_16_2;
  int pub_r001334_17_1;
  int pub_r001334_17_2;
  int pub_r001334_18_1;
  int pub_r001334_18_2;
  int pub_r001334_19_1;
  int pub_r001334_19_2;
  int pub_r001334_20_1;
  int pub_r001334_20_2;
  int pub_r001334_21_1;
  int pub_r001334_21_2;
  int pub_r001334_22_1;
  int pub_r001334_22_2;
  int pub_r001334_23_1;
  int pub_r001334_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001334_0_1 >= (-100)) && (pub_r001334_0_1 <= 100));
  __CPROVER_assume((pub_r001334_0_2 >= (-100)) && (pub_r001334_0_2 <= 100));
  __CPROVER_assume((pub_r001334_1_1 >= (-100)) && (pub_r001334_1_1 <= 100));
  __CPROVER_assume((pub_r001334_1_2 >= (-100)) && (pub_r001334_1_2 <= 100));
  __CPROVER_assume((pub_r001334_2_1 >= (-100)) && (pub_r001334_2_1 <= 100));
  __CPROVER_assume((pub_r001334_2_2 >= (-100)) && (pub_r001334_2_2 <= 100));
  __CPROVER_assume((pub_r001334_3_1 >= (-100)) && (pub_r001334_3_1 <= 100));
  __CPROVER_assume((pub_r001334_3_2 >= (-100)) && (pub_r001334_3_2 <= 100));
  __CPROVER_assume((pub_r001334_4_1 >= (-100)) && (pub_r001334_4_1 <= 100));
  __CPROVER_assume((pub_r001334_4_2 >= (-100)) && (pub_r001334_4_2 <= 100));
  __CPROVER_assume((pub_r001334_5_1 >= (-100)) && (pub_r001334_5_1 <= 100));
  __CPROVER_assume((pub_r001334_5_2 >= (-100)) && (pub_r001334_5_2 <= 100));
  __CPROVER_assume((pub_r001334_6_1 >= (-100)) && (pub_r001334_6_1 <= 100));
  __CPROVER_assume((pub_r001334_6_2 >= (-100)) && (pub_r001334_6_2 <= 100));
  __CPROVER_assume((pub_r001334_7_1 >= (-100)) && (pub_r001334_7_1 <= 100));
  __CPROVER_assume((pub_r001334_7_2 >= (-100)) && (pub_r001334_7_2 <= 100));
  __CPROVER_assume((pub_r001334_8_1 >= (-100)) && (pub_r001334_8_1 <= 100));
  __CPROVER_assume((pub_r001334_8_2 >= (-100)) && (pub_r001334_8_2 <= 100));
  __CPROVER_assume((pub_r001334_9_1 >= (-100)) && (pub_r001334_9_1 <= 100));
  __CPROVER_assume((pub_r001334_9_2 >= (-100)) && (pub_r001334_9_2 <= 100));
  __CPROVER_assume((pub_r001334_10_1 >= (-100)) && (pub_r001334_10_1 <= 100));
  __CPROVER_assume((pub_r001334_10_2 >= (-100)) && (pub_r001334_10_2 <= 100));
  __CPROVER_assume((pub_r001334_11_1 >= (-100)) && (pub_r001334_11_1 <= 100));
  __CPROVER_assume((pub_r001334_11_2 >= (-100)) && (pub_r001334_11_2 <= 100));
  __CPROVER_assume((pub_r001334_12_1 >= (-100)) && (pub_r001334_12_1 <= 100));
  __CPROVER_assume((pub_r001334_12_2 >= (-100)) && (pub_r001334_12_2 <= 100));
  __CPROVER_assume((pub_r001334_13_1 >= (-100)) && (pub_r001334_13_1 <= 100));
  __CPROVER_assume((pub_r001334_13_2 >= (-100)) && (pub_r001334_13_2 <= 100));
  __CPROVER_assume((pub_r001334_14_1 >= (-100)) && (pub_r001334_14_1 <= 100));
  __CPROVER_assume((pub_r001334_14_2 >= (-100)) && (pub_r001334_14_2 <= 100));
  __CPROVER_assume((pub_r001334_15_1 >= (-100)) && (pub_r001334_15_1 <= 100));
  __CPROVER_assume((pub_r001334_15_2 >= (-100)) && (pub_r001334_15_2 <= 100));
  __CPROVER_assume((pub_r001334_16_1 >= (-100)) && (pub_r001334_16_1 <= 100));
  __CPROVER_assume((pub_r001334_16_2 >= (-100)) && (pub_r001334_16_2 <= 100));
  __CPROVER_assume((pub_r001334_17_1 >= (-100)) && (pub_r001334_17_1 <= 100));
  __CPROVER_assume((pub_r001334_17_2 >= (-100)) && (pub_r001334_17_2 <= 100));
  __CPROVER_assume((pub_r001334_18_1 >= (-100)) && (pub_r001334_18_1 <= 100));
  __CPROVER_assume((pub_r001334_18_2 >= (-100)) && (pub_r001334_18_2 <= 100));
  __CPROVER_assume((pub_r001334_19_1 >= (-100)) && (pub_r001334_19_1 <= 100));
  __CPROVER_assume((pub_r001334_19_2 >= (-100)) && (pub_r001334_19_2 <= 100));
  __CPROVER_assume((pub_r001334_20_1 >= (-100)) && (pub_r001334_20_1 <= 100));
  __CPROVER_assume((pub_r001334_20_2 >= (-100)) && (pub_r001334_20_2 <= 100));
  __CPROVER_assume((pub_r001334_21_1 >= (-100)) && (pub_r001334_21_1 <= 100));
  __CPROVER_assume((pub_r001334_21_2 >= (-100)) && (pub_r001334_21_2 <= 100));
  __CPROVER_assume((pub_r001334_22_1 >= (-100)) && (pub_r001334_22_1 <= 100));
  __CPROVER_assume((pub_r001334_22_2 >= (-100)) && (pub_r001334_22_2 <= 100));
  __CPROVER_assume((pub_r001334_23_1 >= (-100)) && (pub_r001334_23_1 <= 100));
  __CPROVER_assume((pub_r001334_23_2 >= (-100)) && (pub_r001334_23_2 <= 100));
  __CPROVER_assume((sec_r001334_0_1 >= 0) && (sec_r001334_0_1 <= 255));
  __CPROVER_assume((sec_r001334_0_2 >= 0) && (sec_r001334_0_2 <= 255));
  __CPROVER_assume((sec_r001334_1_1 >= 0) && (sec_r001334_1_1 <= 255));
  __CPROVER_assume((sec_r001334_1_2 >= 0) && (sec_r001334_1_2 <= 255));
  __CPROVER_assume((sec_r001334_2_1 >= 0) && (sec_r001334_2_1 <= 255));
  __CPROVER_assume((sec_r001334_2_2 >= 0) && (sec_r001334_2_2 <= 255));
  __CPROVER_assume((sec_r001334_3_1 >= 0) && (sec_r001334_3_1 <= 255));
  __CPROVER_assume((sec_r001334_3_2 >= 0) && (sec_r001334_3_2 <= 255));
  __CPROVER_assume((sec_r001334_4_1 >= 0) && (sec_r001334_4_1 <= 255));
  __CPROVER_assume((sec_r001334_4_2 >= 0) && (sec_r001334_4_2 <= 255));
  __CPROVER_assume((sec_r001334_5_1 >= 0) && (sec_r001334_5_1 <= 255));
  __CPROVER_assume((sec_r001334_5_2 >= 0) && (sec_r001334_5_2 <= 255));
  __CPROVER_assume((sec_r001334_6_1 >= 0) && (sec_r001334_6_1 <= 255));
  __CPROVER_assume((sec_r001334_6_2 >= 0) && (sec_r001334_6_2 <= 255));
  __CPROVER_assume((sec_r001334_7_1 >= 0) && (sec_r001334_7_1 <= 255));
  __CPROVER_assume((sec_r001334_7_2 >= 0) && (sec_r001334_7_2 <= 255));
  __CPROVER_assume((sec_r001334_8_1 >= 0) && (sec_r001334_8_1 <= 255));
  __CPROVER_assume((sec_r001334_8_2 >= 0) && (sec_r001334_8_2 <= 255));
  __CPROVER_assume((sec_r001334_9_1 >= 0) && (sec_r001334_9_1 <= 255));
  __CPROVER_assume((sec_r001334_9_2 >= 0) && (sec_r001334_9_2 <= 255));
  __CPROVER_assume((sec_r001334_10_1 >= 0) && (sec_r001334_10_1 <= 255));
  __CPROVER_assume((sec_r001334_10_2 >= 0) && (sec_r001334_10_2 <= 255));
  __CPROVER_assume((sec_r001334_11_1 >= 0) && (sec_r001334_11_1 <= 255));
  __CPROVER_assume((sec_r001334_11_2 >= 0) && (sec_r001334_11_2 <= 255));
  __CPROVER_assume((sec_r001334_12_1 >= 0) && (sec_r001334_12_1 <= 255));
  __CPROVER_assume((sec_r001334_12_2 >= 0) && (sec_r001334_12_2 <= 255));
  __CPROVER_assume((sec_r001334_13_1 >= 0) && (sec_r001334_13_1 <= 255));
  __CPROVER_assume((sec_r001334_13_2 >= 0) && (sec_r001334_13_2 <= 255));
  __CPROVER_assume((sec_r001334_14_1 >= 0) && (sec_r001334_14_1 <= 255));
  __CPROVER_assume((sec_r001334_14_2 >= 0) && (sec_r001334_14_2 <= 255));
  __CPROVER_assume((sec_r001334_15_1 >= 0) && (sec_r001334_15_1 <= 255));
  __CPROVER_assume((sec_r001334_15_2 >= 0) && (sec_r001334_15_2 <= 255));
  __CPROVER_assume((sec_r001334_16_1 >= 0) && (sec_r001334_16_1 <= 255));
  __CPROVER_assume((sec_r001334_16_2 >= 0) && (sec_r001334_16_2 <= 255));
  __CPROVER_assume((sec_r001334_17_1 >= 0) && (sec_r001334_17_1 <= 255));
  __CPROVER_assume((sec_r001334_17_2 >= 0) && (sec_r001334_17_2 <= 255));
  __CPROVER_assume((sec_r001334_18_1 >= 0) && (sec_r001334_18_1 <= 255));
  __CPROVER_assume((sec_r001334_18_2 >= 0) && (sec_r001334_18_2 <= 255));
  __CPROVER_assume((sec_r001334_19_1 >= 0) && (sec_r001334_19_1 <= 255));
  __CPROVER_assume((sec_r001334_19_2 >= 0) && (sec_r001334_19_2 <= 255));
  __CPROVER_assume((sec_r001334_20_1 >= 0) && (sec_r001334_20_1 <= 255));
  __CPROVER_assume((sec_r001334_20_2 >= 0) && (sec_r001334_20_2 <= 255));
  struct AudioFrame_R001334_3413_0 st_var_0_1 = {0};
  struct AudioFrame_R001334_3413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001334_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001334_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001334_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001334_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001334_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001334_0_2 + 7) & 15;
  struct StreamBuffer_R001334_3413_1 st_var_1_1 = {0};
  struct StreamBuffer_R001334_3413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001334_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001334_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001334_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001334_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001334_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001334_0_2 + 9) & 15;
  union TelemetryField_R001334_3413_0 u_var_1;
  union TelemetryField_R001334_3413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001334_3413_0(sec_r001334_0_1, pub_r001334_1_1, pub_r001334_2_1, pub_r001334_3_1, pub_r001334_4_1);
  int helper_flow_0_2 = fn_R001334_3413_0(sec_r001334_0_2, pub_r001334_1_2, pub_r001334_2_2, pub_r001334_3_2, pub_r001334_4_2);
  fn_R001334_3413_0_2(sec_r001334_0_1, pub_r001334_1_1, pub_r001334_2_1, pub_r001334_3_1, pub_r001334_4_1, sec_r001334_0_2, pub_r001334_1_2, pub_r001334_2_2, pub_r001334_3_2, pub_r001334_4_2);
  int helper_flow_1_1 = fn_R001334_3413_1(sec_r001334_1_1, pub_r001334_2_1, pub_r001334_3_1, pub_r001334_4_1);
  int helper_flow_1_2 = fn_R001334_3413_1(sec_r001334_1_2, pub_r001334_2_2, pub_r001334_3_2, pub_r001334_4_2);
  fn_R001334_3413_1_2(sec_r001334_1_1, pub_r001334_2_1, pub_r001334_3_1, pub_r001334_4_1, sec_r001334_1_2, pub_r001334_2_2, pub_r001334_3_2, pub_r001334_4_2);
  int helper_flow_2_1 = fn_R001334_3413_2(sec_r001334_2_1, sec_r001334_3_1, pub_r001334_4_1, pub_r001334_5_1);
  int helper_flow_2_2 = fn_R001334_3413_2(sec_r001334_2_2, sec_r001334_3_2, pub_r001334_4_2, pub_r001334_5_2);
  fn_R001334_3413_2_2(sec_r001334_2_1, sec_r001334_3_1, pub_r001334_4_1, pub_r001334_5_1, sec_r001334_2_2, sec_r001334_3_2, pub_r001334_4_2, pub_r001334_5_2);
  int helper_flow_3_1 = fn_R001334_3413_3(sec_r001334_3_1, pub_r001334_4_1, pub_r001334_5_1, pub_r001334_6_1, pub_r001334_7_1);
  int helper_flow_3_2 = fn_R001334_3413_3(sec_r001334_3_2, pub_r001334_4_2, pub_r001334_5_2, pub_r001334_6_2, pub_r001334_7_2);
  fn_R001334_3413_3_2(sec_r001334_3_1, pub_r001334_4_1, pub_r001334_5_1, pub_r001334_6_1, pub_r001334_7_1, sec_r001334_3_2, pub_r001334_4_2, pub_r001334_5_2, pub_r001334_6_2, pub_r001334_7_2);
  int helper_flow_4_1 = fn_R001334_3413_4(sec_r001334_4_1, sec_r001334_5_1, pub_r001334_6_1, pub_r001334_7_1);
  int helper_flow_4_2 = fn_R001334_3413_4(sec_r001334_4_2, sec_r001334_5_2, pub_r001334_6_2, pub_r001334_7_2);
  fn_R001334_3413_4_2(sec_r001334_4_1, sec_r001334_5_1, pub_r001334_6_1, pub_r001334_7_1, sec_r001334_4_2, sec_r001334_5_2, pub_r001334_6_2, pub_r001334_7_2);
  int helper_flow_5_1 = fn_R001334_3413_5(sec_r001334_5_1, pub_r001334_6_1, pub_r001334_7_1);
  int helper_flow_5_2 = fn_R001334_3413_5(sec_r001334_5_2, pub_r001334_6_2, pub_r001334_7_2);
  fn_R001334_3413_5_2(sec_r001334_5_1, pub_r001334_6_1, pub_r001334_7_1, sec_r001334_5_2, pub_r001334_6_2, pub_r001334_7_2);
  int helper_flow_6_1 = fn_R001334_3413_6(sec_r001334_6_1, sec_r001334_7_1);
  int helper_flow_6_2 = fn_R001334_3413_6(sec_r001334_6_2, sec_r001334_7_2);
  fn_R001334_3413_6_2(sec_r001334_6_1, sec_r001334_7_1, sec_r001334_6_2, sec_r001334_7_2);
  int helper_flow_7_1 = fn_R001334_3413_7(sec_r001334_7_1, pub_r001334_8_1);
  int helper_flow_7_2 = fn_R001334_3413_7(sec_r001334_7_2, pub_r001334_8_2);
  fn_R001334_3413_7_2(sec_r001334_7_1, pub_r001334_8_1, sec_r001334_7_2, pub_r001334_8_2);
  int stage_v_0_1 = ((pub_r001334_0_1 * 2) + 7) & 63;
  int stage_v_0_2 = ((pub_r001334_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001334_21_1 * 2) + 37) & 63;
  int stage_v_1_2 = ((pub_r001334_21_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001334_2_1 * 3) + pub_r001334_11_1) + 19) & 127;
  int stage_v_2_2 = (((sec_r001334_2_2 * 3) + pub_r001334_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = (((sec_r001334_11_1 * 3) + pub_r001334_2_1) + 17) & 127;
  int stage_v_3_2 = (((sec_r001334_11_2 * 3) + pub_r001334_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = ((pub_r001334_2_1 * 2) + 15) & 63;
  int stage_v_4_2 = ((pub_r001334_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((sec_r001334_17_1 * 3) + pub_r001334_21_1) + 11) & 127;
  int stage_v_5_2 = (((sec_r001334_17_2 * 3) + pub_r001334_21_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = (((sec_r001334_0_1 * 3) + pub_r001334_2_1) + 38) & 127;
  int stage_v_6_2 = (((sec_r001334_0_2 * 3) + pub_r001334_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = (((sec_r001334_11_1 * 3) + pub_r001334_15_1) + 25) & 127;
  int stage_v_7_2 = (((sec_r001334_11_2 * 3) + pub_r001334_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001334_15_1 * 2) + 13) & 63;
  int stage_v_8_2 = ((pub_r001334_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (((sec_r001334_0_1 * 3) + pub_r001334_20_1) + 29) & 127;
  int stage_v_9_2 = (((sec_r001334_0_2 * 3) + pub_r001334_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = (((helper_flow_2_1 * 3) + pub_r001334_23_1) + 7) & 127;
  int stage_v_10_2 = (((helper_flow_2_2 * 3) + pub_r001334_23_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = (((helper_flow_4_1 * 3) + pub_r001334_4_1) + 35) & 127;
  int stage_v_11_2 = (((helper_flow_4_2 * 3) + pub_r001334_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = (((sec_r001334_17_1 * 3) + pub_r001334_16_1) + 14) & 127;
  int stage_v_12_2 = (((sec_r001334_17_2 * 3) + pub_r001334_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = (((sec_r001334_5_1 * 3) + pub_r001334_23_1) + 5) & 127;
  int stage_v_13_2 = (((sec_r001334_5_2 * 3) + pub_r001334_23_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = (((helper_flow_0_1 * 3) + pub_r001334_4_1) + 6) & 127;
  int stage_v_14_2 = (((helper_flow_0_2 * 3) + pub_r001334_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((sec_r001334_2_1 * 3) + pub_r001334_4_1) + 12) & 127;
  int stage_v_15_2 = (((sec_r001334_2_2 * 3) + pub_r001334_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = (((helper_flow_0_1 * 3) + pub_r001334_3_1) + 38) & 127;
  int stage_v_16_2 = (((helper_flow_0_2 * 3) + pub_r001334_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((sec_r001334_5_1 * 3) + pub_r001334_19_1) + 31) & 127;
  int stage_v_17_2 = (((sec_r001334_5_2 * 3) + pub_r001334_19_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((stage_v_9_1 * 3) + pub_r001334_19_1) + 10) & 127;
  int stage_v_18_2 = (((stage_v_9_2 * 3) + pub_r001334_19_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = ((pub_r001334_4_1 * 2) + 31) & 63;
  int stage_v_19_2 = ((pub_r001334_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001334_6_1 * 2) + 46) & 63;
  int stage_v_20_2 = ((pub_r001334_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((stage_v_6_1 * 3) + pub_r001334_21_1) + 13) & 127;
  int stage_v_21_2 = (((stage_v_6_2 * 3) + pub_r001334_21_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = ((pub_r001334_17_1 * 2) + 13) & 63;
  int stage_v_22_2 = ((pub_r001334_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001334_5_1 * 2) + 43) & 63;
  int stage_v_23_2 = ((pub_r001334_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001334_3_1 * 2) + 26) & 63;
  int stage_v_24_2 = ((pub_r001334_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001334_18_1 * 2) + 14) & 63;
  int stage_v_25_2 = ((pub_r001334_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((sec_r001334_5_1 * 3) + pub_r001334_22_1) + 38) & 127;
  int stage_v_26_2 = (((sec_r001334_5_2 * 3) + pub_r001334_22_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = ((pub_r001334_13_1 * 2) + 31) & 63;
  int stage_v_27_2 = ((pub_r001334_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((stage_v_17_1 * 3) + pub_r001334_15_1) + 44) & 127;
  int stage_v_28_2 = (((stage_v_17_2 * 3) + pub_r001334_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = ((pub_r001334_4_1 * 2) + 11) & 63;
  int stage_v_29_2 = ((pub_r001334_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((helper_flow_2_1 * 3) + pub_r001334_7_1) + 4) & 127;
  int stage_v_30_2 = (((helper_flow_2_2 * 3) + pub_r001334_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((stage_v_5_1 * 3) + pub_r001334_4_1) + 31) & 127;
  int stage_v_31_2 = (((stage_v_5_2 * 3) + pub_r001334_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = (((stage_v_6_1 * 3) + pub_r001334_10_1) + 11) & 127;
  int stage_v_32_2 = (((stage_v_6_2 * 3) + pub_r001334_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = ((pub_r001334_20_1 * 2) + 31) & 63;
  int stage_v_33_2 = ((pub_r001334_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001334_18_1 * 2) + 15) & 63;
  int stage_v_34_2 = ((pub_r001334_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001334_18_1 * 2) + 49) & 63;
  int stage_v_35_2 = ((pub_r001334_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001334_20_1 * 2) + 28) & 63;
  int stage_v_36_2 = ((pub_r001334_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001334_18_1 * 2) + 24) & 63;
  int stage_v_37_2 = ((pub_r001334_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((stage_v_5_1 * 3) + pub_r001334_5_1) + 41) & 127;
  int stage_v_38_2 = (((stage_v_5_2 * 3) + pub_r001334_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = ((pub_r001334_20_1 * 2) + 6) & 63;
  int stage_v_39_2 = ((pub_r001334_20_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((sec_r001334_19_1 * 3) + pub_r001334_0_1) + 7) & 127;
  int stage_v_40_2 = (((sec_r001334_19_2 * 3) + pub_r001334_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((stage_v_3_1 * 3) + pub_r001334_4_1) + 24) & 127;
  int stage_v_41_2 = (((stage_v_3_2 * 3) + pub_r001334_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = (((sec_r001334_3_1 * 3) + pub_r001334_16_1) + 20) & 127;
  int stage_v_42_2 = (((sec_r001334_3_2 * 3) + pub_r001334_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = (((helper_flow_1_1 * 3) + pub_r001334_17_1) + 17) & 127;
  int stage_v_43_2 = (((helper_flow_1_2 * 3) + pub_r001334_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001334_22_1 * 2) + 28) & 63;
  int stage_v_44_2 = ((pub_r001334_22_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001334_17_1 * 2) + 22) & 63;
  int stage_v_45_2 = ((pub_r001334_17_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((stage_v_12_1 * 3) + pub_r001334_4_1) + 34) & 127;
  int stage_v_46_2 = (((stage_v_12_2 * 3) + pub_r001334_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = (((stage_v_38_1 * 3) + pub_r001334_11_1) + 44) & 127;
  int stage_v_47_2 = (((stage_v_38_2 * 3) + pub_r001334_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = ((pub_r001334_6_1 * 2) + 46) & 63;
  int stage_v_48_2 = ((pub_r001334_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001334_21_1 * 2) + 49) & 63;
  int stage_v_49_2 = ((pub_r001334_21_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((stage_v_41_1 * 3) + pub_r001334_3_1) + 18) & 127;
  int stage_v_50_2 = (((stage_v_41_2 * 3) + pub_r001334_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001334_20_1 * 2) + 8) & 63;
  int stage_v_51_2 = ((pub_r001334_20_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001334_11_1 * 2) + 50) & 63;
  int stage_v_52_2 = ((pub_r001334_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((sec_r001334_0_1 * 3) + pub_r001334_8_1) + 20) & 127;
  int stage_v_53_2 = (((sec_r001334_0_2 * 3) + pub_r001334_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = (((sec_r001334_9_1 * 3) + pub_r001334_9_1) + 21) & 127;
  int stage_v_54_2 = (((sec_r001334_9_2 * 3) + pub_r001334_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((stage_v_12_1 * 3) + pub_r001334_3_1) + 18) & 127;
  int stage_v_55_2 = (((stage_v_12_2 * 3) + pub_r001334_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = ((pub_r001334_0_1 * 2) + 33) & 63;
  int stage_v_56_2 = ((pub_r001334_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((stage_v_30_1 * 3) + pub_r001334_19_1) + 14) & 127;
  int stage_v_57_2 = (((stage_v_30_2 * 3) + pub_r001334_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((sec_r001334_7_1 * 3) + pub_r001334_5_1) + 23) & 127;
  int stage_v_58_2 = (((sec_r001334_7_2 * 3) + pub_r001334_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((stage_v_3_1 * 3) + pub_r001334_2_1) + 38) & 127;
  int stage_v_59_2 = (((stage_v_3_2 * 3) + pub_r001334_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = (((stage_v_9_1 * 3) + pub_r001334_8_1) + 4) & 127;
  int stage_v_60_2 = (((stage_v_9_2 * 3) + pub_r001334_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((stage_v_32_1 * 3) + pub_r001334_11_1) + 26) & 127;
  int stage_v_61_2 = (((stage_v_32_2 * 3) + pub_r001334_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = (((stage_v_15_1 * 3) + pub_r001334_13_1) + 5) & 127;
  int stage_v_62_2 = (((stage_v_15_2 * 3) + pub_r001334_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((stage_v_62_1 * 3) + pub_r001334_11_1) + 12) & 127;
  int stage_v_63_2 = (((stage_v_62_2 * 3) + pub_r001334_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((stage_v_50_1 * 3) + pub_r001334_7_1) + 28) & 127;
  int stage_v_64_2 = (((stage_v_50_2 * 3) + pub_r001334_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((stage_v_17_1 * 3) + pub_r001334_12_1) + 37) & 127;
  int stage_v_65_2 = (((stage_v_17_2 * 3) + pub_r001334_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = (((sec_r001334_16_1 * 3) + pub_r001334_8_1) + 40) & 127;
  int stage_v_66_2 = (((sec_r001334_16_2 * 3) + pub_r001334_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((sec_r001334_9_1 * 3) + pub_r001334_0_1) + 27) & 127;
  int stage_v_67_2 = (((sec_r001334_9_2 * 3) + pub_r001334_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((stage_v_50_1 * 3) + pub_r001334_17_1) + 35) & 127;
  int stage_v_68_2 = (((stage_v_50_2 * 3) + pub_r001334_17_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = ((pub_r001334_3_1 * 2) + 40) & 63;
  int stage_v_69_2 = ((pub_r001334_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001334_2_1 * 2) + 16) & 63;
  int stage_v_70_2 = ((pub_r001334_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001334_22_1 * 2) + 46) & 63;
  int stage_v_71_2 = ((pub_r001334_22_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001334_14_1 * 2) + 43) & 63;
  int stage_v_72_2 = ((pub_r001334_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((sec_r001334_4_1 * 3) + pub_r001334_10_1) + 33) & 127;
  int stage_v_73_2 = (((sec_r001334_4_2 * 3) + pub_r001334_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = (((sec_r001334_1_1 * 3) + pub_r001334_16_1) + 44) & 127;
  int stage_v_74_2 = (((sec_r001334_1_2 * 3) + pub_r001334_16_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = ((pub_r001334_9_1 * 2) + 46) & 63;
  int stage_v_75_2 = ((pub_r001334_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (((stage_v_40_1 * 3) + pub_r001334_22_1) + 21) & 127;
  int stage_v_76_2 = (((stage_v_40_2 * 3) + pub_r001334_22_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = ((pub_r001334_7_1 * 2) + 21) & 63;
  int stage_v_77_2 = ((pub_r001334_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001334_21_1 * 2) + 48) & 63;
  int stage_v_78_2 = ((pub_r001334_21_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001334_18_1 * 2) + 24) & 63;
  int stage_v_79_2 = ((pub_r001334_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((sec_r001334_7_1 * 3) + pub_r001334_21_1) + 5) & 127;
  int stage_v_80_2 = (((sec_r001334_7_2 * 3) + pub_r001334_21_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = ((pub_r001334_0_1 * 2) + 8) & 63;
  int stage_v_81_2 = ((pub_r001334_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((sec_r001334_4_1 * 3) + pub_r001334_1_1) + 7) & 127;
  int stage_v_82_2 = (((sec_r001334_4_2 * 3) + pub_r001334_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001334_12_1 * 2) + 7) & 63;
  int stage_v_83_2 = ((pub_r001334_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001334_16_1 * 2) + 34) & 63;
  int stage_v_84_2 = ((pub_r001334_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (((stage_v_43_1 * 3) + pub_r001334_2_1) + 16) & 127;
  int stage_v_85_2 = (((stage_v_43_2 * 3) + pub_r001334_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001334_22_1 * 2) + 7) & 63;
  int stage_v_86_2 = ((pub_r001334_22_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((sec_r001334_13_1 * 3) + pub_r001334_23_1) + 14) & 127;
  int stage_v_87_2 = (((sec_r001334_13_2 * 3) + pub_r001334_23_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = ((pub_r001334_21_1 * 2) + 20) & 63;
  int stage_v_88_2 = ((pub_r001334_21_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001334_17_1 * 2) + 27) & 63;
  int stage_v_89_2 = ((pub_r001334_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001334_22_1 * 2) + 19) & 63;
  int stage_v_90_2 = ((pub_r001334_22_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001334_6_1 * 2) + 13) & 63;
  int stage_v_91_2 = ((pub_r001334_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_5_1 * 3) + pub_r001334_11_1) + 3) & 127;
  int stage_v_92_2 = (((stage_v_5_2 * 3) + pub_r001334_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = ((pub_r001334_17_1 * 2) + 9) & 63;
  int stage_v_93_2 = ((pub_r001334_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((sec_r001334_10_1 * 3) + pub_r001334_22_1) + 7) & 127;
  int stage_v_94_2 = (((sec_r001334_10_2 * 3) + pub_r001334_22_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((stage_v_38_1 * 3) + pub_r001334_0_1) + 25) & 127;
  int stage_v_95_2 = (((stage_v_38_2 * 3) + pub_r001334_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = (((stage_v_26_1 * 3) + pub_r001334_7_1) + 29) & 127;
  int stage_v_96_2 = (((stage_v_26_2 * 3) + pub_r001334_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001334_21_1 * 2) + 31) & 63;
  int stage_v_97_2 = ((pub_r001334_21_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001334_9_1 * 2) + 46) & 63;
  int stage_v_98_2 = ((pub_r001334_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((stage_v_65_1 * 3) + pub_r001334_8_1) + 25) & 127;
  int stage_v_99_2 = (((stage_v_65_2 * 3) + pub_r001334_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001334_19_1 * 2) + 50) & 63;
  int stage_v_100_2 = ((pub_r001334_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((sec_r001334_1_1 * 3) + pub_r001334_12_1) + 35) & 127;
  int stage_v_101_2 = (((sec_r001334_1_2 * 3) + pub_r001334_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001334_4_1 * 2) + 34) & 63;
  int stage_v_102_2 = ((pub_r001334_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((stage_v_11_1 * 3) + pub_r001334_9_1) + 24) & 127;
  int stage_v_103_2 = (((stage_v_11_2 * 3) + pub_r001334_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = ((pub_r001334_18_1 * 2) + 6) & 63;
  int stage_v_104_2 = ((pub_r001334_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001334_11_1 * 2) + 46) & 63;
  int stage_v_105_2 = ((pub_r001334_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((stage_v_5_1 * 3) + pub_r001334_4_1) + 12) & 127;
  int stage_v_106_2 = (((stage_v_5_2 * 3) + pub_r001334_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = (((helper_flow_1_1 * 3) + pub_r001334_4_1) + 44) & 127;
  int stage_v_107_2 = (((helper_flow_1_2 * 3) + pub_r001334_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = ((pub_r001334_20_1 * 2) + 13) & 63;
  int stage_v_108_2 = ((pub_r001334_20_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001334_9_1 * 2) + 9) & 63;
  int stage_v_109_2 = ((pub_r001334_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((sec_r001334_14_1 * 3) + pub_r001334_19_1) + 44) & 127;
  int stage_v_110_2 = (((sec_r001334_14_2 * 3) + pub_r001334_19_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = (((sec_r001334_11_1 * 3) + pub_r001334_11_1) + 25) & 127;
  int stage_v_111_2 = (((sec_r001334_11_2 * 3) + pub_r001334_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = ((pub_r001334_3_1 * 2) + 41) & 63;
  int stage_v_112_2 = ((pub_r001334_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001334_6_1 * 2) + 38) & 63;
  int stage_v_113_2 = ((pub_r001334_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001334_17_1 * 2) + 11) & 63;
  int stage_v_114_2 = ((pub_r001334_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (((stage_v_106_1 * 3) + pub_r001334_13_1) + 35) & 127;
  int stage_v_115_2 = (((stage_v_106_2 * 3) + pub_r001334_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = ((pub_r001334_14_1 * 2) + 41) & 63;
  int stage_v_116_2 = ((pub_r001334_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001334_5_1 * 2) + 6) & 63;
  int stage_v_117_2 = ((pub_r001334_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001334_1_1 * 2) + 35) & 63;
  int stage_v_118_2 = ((pub_r001334_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((helper_flow_3_1 * 3) + pub_r001334_10_1) + 13) & 127;
  int stage_v_119_2 = (((helper_flow_3_2 * 3) + pub_r001334_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = (((sec_r001334_3_1 * 3) + pub_r001334_3_1) + 32) & 127;
  int stage_v_120_2 = (((sec_r001334_3_2 * 3) + pub_r001334_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001334_7_1 * 2) + 33) & 63;
  int stage_v_121_2 = ((pub_r001334_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001334_17_1 * 2) + 20) & 63;
  int stage_v_122_2 = ((pub_r001334_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001334_11_1 * 2) + 29) & 63;
  int stage_v_123_2 = ((pub_r001334_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((sec_r001334_10_1 * 3) + pub_r001334_11_1) + 21) & 127;
  int stage_v_124_2 = (((sec_r001334_10_2 * 3) + pub_r001334_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((sec_r001334_12_1 * 3) + pub_r001334_23_1) + 5) & 127;
  int stage_v_125_2 = (((sec_r001334_12_2 * 3) + pub_r001334_23_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = ((pub_r001334_14_1 * 2) + 47) & 63;
  int stage_v_126_2 = ((pub_r001334_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (((helper_flow_7_1 * 3) + pub_r001334_16_1) + 38) & 127;
  int stage_v_127_2 = (((helper_flow_7_2 * 3) + pub_r001334_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = ((pub_r001334_9_1 * 2) + 11) & 63;
  int stage_v_128_2 = ((pub_r001334_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((helper_flow_6_1 * 3) + pub_r001334_8_1) + 42) & 127;
  int stage_v_129_2 = (((helper_flow_6_2 * 3) + pub_r001334_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((stage_v_106_1 * 3) + pub_r001334_11_1) + 12) & 127;
  int stage_v_130_2 = (((stage_v_106_2 * 3) + pub_r001334_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001334_21_1 * 2) + 24) & 63;
  int stage_v_131_2 = ((pub_r001334_21_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((stage_v_28_1 * 3) + pub_r001334_1_1) + 4) & 127;
  int stage_v_132_2 = (((stage_v_28_2 * 3) + pub_r001334_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((stage_v_46_1 * 3) + pub_r001334_11_1) + 21) & 127;
  int stage_v_133_2 = (((stage_v_46_2 * 3) + pub_r001334_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_46_1 * 3) + pub_r001334_15_1) + 4) & 127;
  int stage_v_134_2 = (((stage_v_46_2 * 3) + pub_r001334_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((stage_v_28_1 * 3) + pub_r001334_13_1) + 21) & 127;
  int stage_v_135_2 = (((stage_v_28_2 * 3) + pub_r001334_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((stage_v_129_1 * 3) + pub_r001334_22_1) + 5) & 127;
  int stage_v_136_2 = (((stage_v_129_2 * 3) + pub_r001334_22_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = ((pub_r001334_17_1 * 2) + 33) & 63;
  int stage_v_137_2 = ((pub_r001334_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001334_18_1 * 2) + 48) & 63;
  int stage_v_138_2 = ((pub_r001334_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001334_7_1 * 2) + 47) & 63;
  int stage_v_139_2 = ((pub_r001334_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((stage_v_7_1 * 3) + pub_r001334_11_1) + 40) & 127;
  int stage_v_140_2 = (((stage_v_7_2 * 3) + pub_r001334_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = ((pub_r001334_19_1 * 2) + 27) & 63;
  int stage_v_141_2 = ((pub_r001334_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001334_7_1 * 2) + 38) & 63;
  int stage_v_142_2 = ((pub_r001334_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((stage_v_66_1 * 3) + pub_r001334_1_1) + 14) & 127;
  int stage_v_143_2 = (((stage_v_66_2 * 3) + pub_r001334_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = (((stage_v_87_1 * 3) + pub_r001334_4_1) + 45) & 127;
  int stage_v_144_2 = (((stage_v_87_2 * 3) + pub_r001334_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = ((pub_r001334_7_1 * 2) + 8) & 63;
  int stage_v_145_2 = ((pub_r001334_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001334_12_1 * 2) + 38) & 63;
  int stage_v_146_2 = ((pub_r001334_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_58_1 * 3) + pub_r001334_6_1) + 6) & 127;
  int stage_v_147_2 = (((stage_v_58_2 * 3) + pub_r001334_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = ((pub_r001334_7_1 * 2) + 20) & 63;
  int stage_v_148_2 = ((pub_r001334_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((stage_v_147_1 * 3) + pub_r001334_5_1) + 13) & 127;
  int stage_v_149_2 = (((stage_v_147_2 * 3) + pub_r001334_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_119_1 * 3) + pub_r001334_15_1) + 16) & 127;
  int stage_v_150_2 = (((stage_v_119_2 * 3) + pub_r001334_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((stage_v_38_1 * 3) + pub_r001334_9_1) + 39) & 127;
  int stage_v_151_2 = (((stage_v_38_2 * 3) + pub_r001334_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = ((pub_r001334_8_1 * 2) + 12) & 63;
  int stage_v_152_2 = ((pub_r001334_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001334_12_1 * 2) + 39) & 63;
  int stage_v_153_2 = ((pub_r001334_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001334_15_1 * 2) + 22) & 63;
  int stage_v_154_2 = ((pub_r001334_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((stage_v_111_1 * 3) + pub_r001334_6_1) + 32) & 127;
  int stage_v_155_2 = (((stage_v_111_2 * 3) + pub_r001334_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = ((pub_r001334_21_1 * 2) + 7) & 63;
  int stage_v_156_2 = ((pub_r001334_21_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001334_19_1 * 2) + 45) & 63;
  int stage_v_157_2 = ((pub_r001334_19_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001334_14_1 * 2) + 26) & 63;
  int stage_v_158_2 = ((pub_r001334_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((stage_v_14_1 * 3) + pub_r001334_13_1) + 40) & 127;
  int stage_v_159_2 = (((stage_v_14_2 * 3) + pub_r001334_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((stage_v_159_1 * 3) + pub_r001334_14_1) + 38) & 127;
  int stage_v_160_2 = (((stage_v_159_2 * 3) + pub_r001334_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = ((pub_r001334_3_1 * 2) + 37) & 63;
  int stage_v_161_2 = ((pub_r001334_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001334_8_1 * 2) + 32) & 63;
  int stage_v_162_2 = ((pub_r001334_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((stage_v_12_1 * 3) + pub_r001334_6_1) + 17) & 127;
  int stage_v_163_2 = (((stage_v_12_2 * 3) + pub_r001334_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = ((pub_r001334_21_1 * 2) + 33) & 63;
  int stage_v_164_2 = ((pub_r001334_21_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001334_2_1 * 2) + 39) & 63;
  int stage_v_165_2 = ((pub_r001334_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((stage_v_143_1 * 3) + pub_r001334_5_1) + 5) & 127;
  int stage_v_166_2 = (((stage_v_143_2 * 3) + pub_r001334_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = ((pub_r001334_16_1 * 2) + 13) & 63;
  int stage_v_167_2 = ((pub_r001334_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001334_3_1 * 2) + 12) & 63;
  int stage_v_168_2 = ((pub_r001334_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001334_20_1 * 2) + 38) & 63;
  int stage_v_169_2 = ((pub_r001334_20_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((stage_v_43_1 * 3) + pub_r001334_21_1) + 24) & 127;
  int stage_v_170_2 = (((stage_v_43_2 * 3) + pub_r001334_21_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = (((stage_v_64_1 * 3) + pub_r001334_1_1) + 32) & 127;
  int stage_v_171_2 = (((stage_v_64_2 * 3) + pub_r001334_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = ((pub_r001334_0_1 * 2) + 10) & 63;
  int stage_v_172_2 = ((pub_r001334_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((stage_v_31_1 * 3) + pub_r001334_15_1) + 42) & 127;
  int stage_v_173_2 = (((stage_v_31_2 * 3) + pub_r001334_15_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = ((pub_r001334_12_1 * 2) + 33) & 63;
  int stage_v_174_2 = ((pub_r001334_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_3_1 * 3) + pub_r001334_8_1) + 15) & 127;
  int stage_v_175_2 = (((stage_v_3_2 * 3) + pub_r001334_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = ((pub_r001334_19_1 * 2) + 23) & 63;
  int stage_v_176_2 = ((pub_r001334_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001334_16_1 * 2) + 21) & 63;
  int stage_v_177_2 = ((pub_r001334_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((sec_r001334_1_1 * 3) + pub_r001334_18_1) + 21) & 127;
  int stage_v_178_2 = (((sec_r001334_1_2 * 3) + pub_r001334_18_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = ((pub_r001334_10_1 * 2) + 36) & 63;
  int stage_v_179_2 = ((pub_r001334_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_5_1 * 3) + pub_r001334_23_1) + 44) & 127;
  int stage_v_180_2 = (((stage_v_5_2 * 3) + pub_r001334_23_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((stage_v_57_1 * 3) + pub_r001334_0_1) + 29) & 127;
  int stage_v_181_2 = (((stage_v_57_2 * 3) + pub_r001334_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = (((stage_v_21_1 * 3) + pub_r001334_19_1) + 38) & 127;
  int stage_v_182_2 = (((stage_v_21_2 * 3) + pub_r001334_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = ((pub_r001334_13_1 * 2) + 8) & 63;
  int stage_v_183_2 = ((pub_r001334_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001334_16_1 * 2) + 5) & 63;
  int stage_v_184_2 = ((pub_r001334_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_40_1 * 3) + pub_r001334_22_1) + 5) & 127;
  int stage_v_185_2 = (((stage_v_40_2 * 3) + pub_r001334_22_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = ((pub_r001334_9_1 * 2) + 43) & 63;
  int stage_v_186_2 = ((pub_r001334_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001334_19_1 * 2) + 15) & 63;
  int stage_v_187_2 = ((pub_r001334_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001334_16_1 * 2) + 35) & 63;
  int stage_v_188_2 = ((pub_r001334_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((stage_v_13_1 * 3) + pub_r001334_20_1) + 23) & 127;
  int stage_v_189_2 = (((stage_v_13_2 * 3) + pub_r001334_20_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = ((pub_r001334_1_1 * 2) + 8) & 63;
  int stage_v_190_2 = ((pub_r001334_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001334_3_1 * 2) + 5) & 63;
  int stage_v_191_2 = ((pub_r001334_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((stage_v_42_1 * 3) + pub_r001334_14_1) + 5) & 127;
  int stage_v_192_2 = (((stage_v_42_2 * 3) + pub_r001334_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = (((stage_v_192_1 * 3) + pub_r001334_13_1) + 34) & 127;
  int stage_v_193_2 = (((stage_v_192_2 * 3) + pub_r001334_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = (((stage_v_59_1 * 3) + pub_r001334_18_1) + 31) & 127;
  int stage_v_194_2 = (((stage_v_59_2 * 3) + pub_r001334_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((sec_r001334_18_1 * 3) + pub_r001334_1_1) + 41) & 127;
  int stage_v_195_2 = (((sec_r001334_18_2 * 3) + pub_r001334_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = ((pub_r001334_18_1 * 2) + 42) & 63;
  int stage_v_196_2 = ((pub_r001334_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((stage_v_170_1 * 3) + pub_r001334_17_1) + 12) & 127;
  int stage_v_197_2 = (((stage_v_170_2 * 3) + pub_r001334_17_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((sec_r001334_3_1 * 3) + pub_r001334_19_1) + 10) & 127;
  int stage_v_198_2 = (((sec_r001334_3_2 * 3) + pub_r001334_19_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001334_23_1 * 2) + 19) & 63;
  int stage_v_199_2 = ((pub_r001334_23_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_106_1 * 3) + pub_r001334_13_1) + 25) & 127;
  int stage_v_200_2 = (((stage_v_106_2 * 3) + pub_r001334_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = (((stage_v_166_1 * 3) + pub_r001334_5_1) + 11) & 127;
  int stage_v_201_2 = (((stage_v_166_2 * 3) + pub_r001334_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = (((sec_r001334_20_1 * 3) + pub_r001334_6_1) + 20) & 127;
  int stage_v_202_2 = (((sec_r001334_20_2 * 3) + pub_r001334_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = (((stage_v_160_1 * 3) + pub_r001334_17_1) + 14) & 127;
  int stage_v_203_2 = (((stage_v_160_2 * 3) + pub_r001334_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((stage_v_2_1 * 3) + pub_r001334_12_1) + 34) & 127;
  int stage_v_204_2 = (((stage_v_2_2 * 3) + pub_r001334_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = ((pub_r001334_3_1 * 2) + 30) & 63;
  int stage_v_205_2 = ((pub_r001334_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001334_17_1 * 2) + 49) & 63;
  int stage_v_206_2 = ((pub_r001334_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001334_10_1 * 2) + 9) & 63;
  int stage_v_207_2 = ((pub_r001334_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = (((stage_v_115_1 * 3) + pub_r001334_18_1) + 45) & 127;
  int stage_v_208_2 = (((stage_v_115_2 * 3) + pub_r001334_18_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = ((pub_r001334_9_1 * 2) + 18) & 63;
  int stage_v_209_2 = ((pub_r001334_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_63_1 * 3) + pub_r001334_7_1) + 37) & 127;
  int stage_v_210_2 = (((stage_v_63_2 * 3) + pub_r001334_7_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_30_1 * 3) + pub_r001334_8_1) + 23) & 127;
  int stage_v_211_2 = (((stage_v_30_2 * 3) + pub_r001334_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001334_19_1 * 2) + 30) & 63;
  int stage_v_212_2 = ((pub_r001334_19_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_180_1 * 3) + pub_r001334_7_1) + 32) & 127;
  int stage_v_213_2 = (((stage_v_180_2 * 3) + pub_r001334_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001334_15_1 * 2) + 27) & 63;
  int stage_v_214_2 = ((pub_r001334_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001334_17_1 * 2) + 25) & 63;
  int stage_v_215_2 = ((pub_r001334_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = (((stage_v_61_1 * 3) + pub_r001334_13_1) + 7) & 127;
  int stage_v_216_2 = (((stage_v_61_2 * 3) + pub_r001334_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001334_14_1 * 2) + 16) & 63;
  int stage_v_217_2 = ((pub_r001334_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001334_18_1 * 2) + 29) & 63;
  int stage_v_218_2 = ((pub_r001334_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_73_1 * 3) + pub_r001334_13_1) + 3) & 127;
  int stage_v_219_2 = (((stage_v_73_2 * 3) + pub_r001334_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_87_1 * 3) + pub_r001334_12_1) + 23) & 127;
  int stage_v_220_2 = (((stage_v_87_2 * 3) + pub_r001334_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((stage_v_38_1 * 3) + pub_r001334_17_1) + 18) & 127;
  int stage_v_221_2 = (((stage_v_38_2 * 3) + pub_r001334_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((sec_r001334_10_1 * 3) + pub_r001334_8_1) + 11) & 127;
  int stage_v_222_2 = (((sec_r001334_10_2 * 3) + pub_r001334_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = (((sec_r001334_1_1 * 3) + pub_r001334_9_1) + 28) & 127;
  int stage_v_223_2 = (((sec_r001334_1_2 * 3) + pub_r001334_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = (((stage_v_21_1 * 3) + pub_r001334_17_1) + 30) & 127;
  int stage_v_224_2 = (((stage_v_21_2 * 3) + pub_r001334_17_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = (((helper_flow_4_1 * 3) + pub_r001334_7_1) + 18) & 127;
  int stage_v_225_2 = (((helper_flow_4_2 * 3) + pub_r001334_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = ((pub_r001334_11_1 * 2) + 47) & 63;
  int stage_v_226_2 = ((pub_r001334_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001334_19_1 * 2) + 13) & 63;
  int stage_v_227_2 = ((pub_r001334_19_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = (((stage_v_32_1 * 3) + pub_r001334_11_1) + 18) & 127;
  int stage_v_228_2 = (((stage_v_32_2 * 3) + pub_r001334_11_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = ((pub_r001334_14_1 * 2) + 34) & 63;
  int stage_v_229_2 = ((pub_r001334_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001334_21_1 * 2) + 40) & 63;
  int stage_v_230_2 = ((pub_r001334_21_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((sec_r001334_12_1 * 3) + pub_r001334_4_1) + 30) & 127;
  int stage_v_231_2 = (((sec_r001334_12_2 * 3) + pub_r001334_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = (((stage_v_103_1 * 3) + pub_r001334_0_1) + 38) & 127;
  int stage_v_232_2 = (((stage_v_103_2 * 3) + pub_r001334_0_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = ((pub_r001334_19_1 * 2) + 6) & 63;
  int stage_v_233_2 = ((pub_r001334_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001334_21_1 * 2) + 31) & 63;
  int stage_v_234_2 = ((pub_r001334_21_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001334_9_1 * 2) + 22) & 63;
  int stage_v_235_2 = ((pub_r001334_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = (((stage_v_220_1 * 3) + pub_r001334_5_1) + 42) & 127;
  int stage_v_236_2 = (((stage_v_220_2 * 3) + pub_r001334_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = ((pub_r001334_15_1 * 2) + 22) & 63;
  int stage_v_237_2 = ((pub_r001334_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001334_13_1 * 2) + 16) & 63;
  int stage_v_238_2 = ((pub_r001334_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001334_6_1 * 2) + 34) & 63;
  int stage_v_239_2 = ((pub_r001334_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((stage_v_96_1 * 3) + pub_r001334_15_1) + 32) & 127;
  int stage_v_240_2 = (((stage_v_96_2 * 3) + pub_r001334_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = ((pub_r001334_6_1 * 2) + 12) & 63;
  int stage_v_241_2 = ((pub_r001334_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = (((sec_r001334_10_1 * 3) + pub_r001334_2_1) + 33) & 127;
  int stage_v_242_2 = (((sec_r001334_10_2 * 3) + pub_r001334_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001334_16_1 * 2) + 6) & 63;
  int stage_v_243_2 = ((pub_r001334_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((stage_v_223_1 * 3) + pub_r001334_8_1) + 34) & 127;
  int stage_v_244_2 = (((stage_v_223_2 * 3) + pub_r001334_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = ((pub_r001334_8_1 * 2) + 45) & 63;
  int stage_v_245_2 = ((pub_r001334_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = (((stage_v_171_1 * 3) + pub_r001334_23_1) + 37) & 127;
  int stage_v_246_2 = (((stage_v_171_2 * 3) + pub_r001334_23_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = (((helper_flow_4_1 * 3) + pub_r001334_9_1) + 11) & 127;
  int stage_v_247_2 = (((helper_flow_4_2 * 3) + pub_r001334_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = (((stage_v_133_1 * 3) + pub_r001334_4_1) + 44) & 127;
  int stage_v_248_2 = (((stage_v_133_2 * 3) + pub_r001334_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = ((pub_r001334_8_1 * 2) + 33) & 63;
  int stage_v_249_2 = ((pub_r001334_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = (((sec_r001334_5_1 * 3) + pub_r001334_14_1) + 35) & 127;
  int stage_v_250_2 = (((sec_r001334_5_2 * 3) + pub_r001334_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((stage_v_101_1 * 3) + pub_r001334_14_1) + 44) & 127;
  int stage_v_251_2 = (((stage_v_101_2 * 3) + pub_r001334_14_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = ((pub_r001334_19_1 * 2) + 40) & 63;
  int stage_v_252_2 = ((pub_r001334_19_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = (((stage_v_47_1 * 3) + pub_r001334_7_1) + 8) & 127;
  int stage_v_253_2 = (((stage_v_47_2 * 3) + pub_r001334_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = ((pub_r001334_17_1 * 2) + 12) & 63;
  int stage_v_254_2 = ((pub_r001334_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = (((stage_v_151_1 * 3) + pub_r001334_19_1) + 34) & 127;
  int stage_v_255_2 = (((stage_v_151_2 * 3) + pub_r001334_19_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = ((pub_r001334_11_1 * 2) + 20) & 63;
  int stage_v_256_2 = ((pub_r001334_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = (((stage_v_30_1 * 3) + pub_r001334_7_1) + 31) & 127;
  int stage_v_257_2 = (((stage_v_30_2 * 3) + pub_r001334_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = (((stage_v_192_1 * 3) + pub_r001334_17_1) + 40) & 127;
  int stage_v_258_2 = (((stage_v_192_2 * 3) + pub_r001334_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001334_11_1 * 2) + 39) & 63;
  int stage_v_259_2 = ((pub_r001334_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = (((helper_flow_7_1 * 3) + pub_r001334_15_1) + 30) & 127;
  int stage_v_260_2 = (((helper_flow_7_2 * 3) + pub_r001334_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = ((pub_r001334_21_1 * 2) + 36) & 63;
  int stage_v_261_2 = ((pub_r001334_21_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001334_3_1 * 2) + 10) & 63;
  int stage_v_262_2 = ((pub_r001334_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_185_1 * 3) + pub_r001334_4_1) + 14) & 127;
  int stage_v_263_2 = (((stage_v_185_2 * 3) + pub_r001334_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001334_5_1 * 2) + 38) & 63;
  int stage_v_264_2 = ((pub_r001334_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001334_6_1 * 2) + 29) & 63;
  int stage_v_265_2 = ((pub_r001334_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = (((sec_r001334_4_1 * 3) + pub_r001334_17_1) + 18) & 127;
  int stage_v_266_2 = (((sec_r001334_4_2 * 3) + pub_r001334_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((sec_r001334_5_1 * 3) + pub_r001334_2_1) + 9) & 127;
  int stage_v_267_2 = (((sec_r001334_5_2 * 3) + pub_r001334_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = ((pub_r001334_12_1 * 2) + 38) & 63;
  int stage_v_268_2 = ((pub_r001334_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001334_11_1 * 2) + 12) & 63;
  int stage_v_269_2 = ((pub_r001334_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = (((stage_v_31_1 * 3) + pub_r001334_9_1) + 40) & 127;
  int stage_v_270_2 = (((stage_v_31_2 * 3) + pub_r001334_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = ((pub_r001334_0_1 * 2) + 29) & 63;
  int stage_v_271_2 = ((pub_r001334_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001334_4_1 * 2) + 22) & 63;
  int stage_v_272_2 = ((pub_r001334_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = (((stage_v_30_1 * 3) + pub_r001334_4_1) + 22) & 127;
  int stage_v_273_2 = (((stage_v_30_2 * 3) + pub_r001334_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = (((stage_v_129_1 * 3) + pub_r001334_7_1) + 31) & 127;
  int stage_v_274_2 = (((stage_v_129_2 * 3) + pub_r001334_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = (((stage_v_181_1 * 3) + pub_r001334_21_1) + 3) & 127;
  int stage_v_275_2 = (((stage_v_181_2 * 3) + pub_r001334_21_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = ((pub_r001334_7_1 * 2) + 11) & 63;
  int stage_v_276_2 = ((pub_r001334_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((pub_r001334_4_1 * 2) + 29) & 63;
  int stage_v_277_2 = ((pub_r001334_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((pub_r001334_9_1 * 2) + 38) & 63;
  int stage_v_278_2 = ((pub_r001334_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = (((helper_flow_2_1 * 3) + pub_r001334_21_1) + 45) & 127;
  int stage_v_279_2 = (((helper_flow_2_2 * 3) + pub_r001334_21_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = (((stage_v_43_1 * 3) + pub_r001334_21_1) + 4) & 127;
  int stage_v_280_2 = (((stage_v_43_2 * 3) + pub_r001334_21_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_248_1 * 3) + pub_r001334_12_1) + 44) & 127;
  int stage_v_281_2 = (((stage_v_248_2 * 3) + pub_r001334_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = (((stage_v_171_1 * 3) + pub_r001334_9_1) + 33) & 127;
  int stage_v_282_2 = (((stage_v_171_2 * 3) + pub_r001334_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = ((pub_r001334_12_1 * 2) + 40) & 63;
  int stage_v_283_2 = ((pub_r001334_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001334_19_1 * 2) + 7) & 63;
  int stage_v_284_2 = ((pub_r001334_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = (((helper_flow_7_1 * 3) + pub_r001334_7_1) + 7) & 127;
  int stage_v_285_2 = (((helper_flow_7_2 * 3) + pub_r001334_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = ((pub_r001334_16_1 * 2) + 29) & 63;
  int stage_v_286_2 = ((pub_r001334_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = (((stage_v_224_1 * 3) + pub_r001334_4_1) + 22) & 127;
  int stage_v_287_2 = (((stage_v_224_2 * 3) + pub_r001334_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((stage_v_134_1 * 3) + pub_r001334_10_1) + 25) & 127;
  int stage_v_288_2 = (((stage_v_134_2 * 3) + pub_r001334_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = (((stage_v_244_1 * 3) + pub_r001334_19_1) + 26) & 127;
  int stage_v_289_2 = (((stage_v_244_2 * 3) + pub_r001334_19_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((helper_flow_6_1 * 3) + pub_r001334_7_1) + 32) & 127;
  int stage_v_290_2 = (((helper_flow_6_2 * 3) + pub_r001334_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001334_20_1 * 2) + 14) & 63;
  int stage_v_291_2 = ((pub_r001334_20_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((stage_v_290_1 * 3) + pub_r001334_5_1) + 43) & 127;
  int stage_v_292_2 = (((stage_v_290_2 * 3) + pub_r001334_5_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = ((pub_r001334_11_1 * 2) + 13) & 63;
  int stage_v_293_2 = ((pub_r001334_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001334_7_1 * 2) + 20) & 63;
  int stage_v_294_2 = ((pub_r001334_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001334_2_1 * 2) + 8) & 63;
  int stage_v_295_2 = ((pub_r001334_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = (((stage_v_31_1 * 3) + pub_r001334_6_1) + 28) & 127;
  int stage_v_296_2 = (((stage_v_31_2 * 3) + pub_r001334_6_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001334_0_1 * 2) + 12) & 63;
  int stage_v_297_2 = ((pub_r001334_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001334_5_1 * 2) + 8) & 63;
  int stage_v_298_2 = ((pub_r001334_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001334_1_1 * 2) + 47) & 63;
  int stage_v_299_2 = ((pub_r001334_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = (((stage_v_32_1 * 3) + pub_r001334_12_1) + 29) & 127;
  int stage_v_300_2 = (((stage_v_32_2 * 3) + pub_r001334_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = ((pub_r001334_22_1 * 2) + 11) & 63;
  int stage_v_301_2 = ((pub_r001334_22_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001334_12_1 * 2) + 45) & 63;
  int stage_v_302_2 = ((pub_r001334_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_300_1 * 3) + pub_r001334_14_1) + 7) & 127;
  int stage_v_303_2 = (((stage_v_300_2 * 3) + pub_r001334_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001334_14_1 * 2) + 11) & 63;
  int stage_v_304_2 = ((pub_r001334_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = (((stage_v_279_1 * 3) + pub_r001334_3_1) + 10) & 127;
  int stage_v_305_2 = (((stage_v_279_2 * 3) + pub_r001334_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = ((pub_r001334_14_1 * 2) + 13) & 63;
  int stage_v_306_2 = ((pub_r001334_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001334_19_1 * 2) + 10) & 63;
  int stage_v_307_2 = ((pub_r001334_19_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = (((stage_v_2_1 * 3) + pub_r001334_15_1) + 36) & 127;
  int stage_v_308_2 = (((stage_v_2_2 * 3) + pub_r001334_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = ((pub_r001334_0_1 * 2) + 47) & 63;
  int stage_v_309_2 = ((pub_r001334_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = (((sec_r001334_16_1 * 3) + pub_r001334_10_1) + 10) & 127;
  int stage_v_310_2 = (((sec_r001334_16_2 * 3) + pub_r001334_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = ((pub_r001334_17_1 * 2) + 38) & 63;
  int stage_v_311_2 = ((pub_r001334_17_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = (((stage_v_50_1 * 3) + pub_r001334_14_1) + 8) & 127;
  int stage_v_312_2 = (((stage_v_50_2 * 3) + pub_r001334_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = ((pub_r001334_17_1 * 2) + 29) & 63;
  int stage_v_313_2 = ((pub_r001334_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_194_1 * 3) + pub_r001334_22_1) + 5) & 127;
  int stage_v_314_2 = (((stage_v_194_2 * 3) + pub_r001334_22_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = ((pub_r001334_21_1 * 2) + 10) & 63;
  int stage_v_315_2 = ((pub_r001334_21_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001334_17_1 * 2) + 43) & 63;
  int stage_v_316_2 = ((pub_r001334_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = (((stage_v_279_1 * 3) + pub_r001334_2_1) + 38) & 127;
  int stage_v_317_2 = (((stage_v_279_2 * 3) + pub_r001334_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = (((stage_v_166_1 * 3) + pub_r001334_2_1) + 14) & 127;
  int stage_v_318_2 = (((stage_v_166_2 * 3) + pub_r001334_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = ((pub_r001334_6_1 * 2) + 30) & 63;
  int stage_v_319_2 = ((pub_r001334_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((stage_v_129_1 * 3) + pub_r001334_14_1) + 16) & 127;
  int stage_v_320_2 = (((stage_v_129_2 * 3) + pub_r001334_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_16_1 * 3) + pub_r001334_1_1) + 28) & 127;
  int stage_v_321_2 = (((stage_v_16_2 * 3) + pub_r001334_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = ((pub_r001334_13_1 * 2) + 11) & 63;
  int stage_v_322_2 = ((pub_r001334_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001334_0_1 * 2) + 22) & 63;
  int stage_v_323_2 = ((pub_r001334_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((stage_v_200_1 * 3) + pub_r001334_18_1) + 26) & 127;
  int stage_v_324_2 = (((stage_v_200_2 * 3) + pub_r001334_18_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((stage_v_6_1 * 3) + pub_r001334_18_1) + 19) & 127;
  int stage_v_325_2 = (((stage_v_6_2 * 3) + pub_r001334_18_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = ((pub_r001334_5_1 * 2) + 6) & 63;
  int stage_v_326_2 = ((pub_r001334_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001334_7_1 * 2) + 34) & 63;
  int stage_v_327_2 = ((pub_r001334_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((stage_v_106_1 * 3) + pub_r001334_8_1) + 41) & 127;
  int stage_v_328_2 = (((stage_v_106_2 * 3) + pub_r001334_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = ((pub_r001334_16_1 * 2) + 35) & 63;
  int stage_v_329_2 = ((pub_r001334_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = (((stage_v_155_1 * 3) + pub_r001334_17_1) + 36) & 127;
  int stage_v_330_2 = (((stage_v_155_2 * 3) + pub_r001334_17_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = ((pub_r001334_14_1 * 2) + 13) & 63;
  int stage_v_331_2 = ((pub_r001334_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((stage_v_242_1 * 3) + pub_r001334_19_1) + 7) & 127;
  int stage_v_332_2 = (((stage_v_242_2 * 3) + pub_r001334_19_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((stage_v_30_1 * 3) + pub_r001334_1_1) + 10) & 127;
  int stage_v_333_2 = (((stage_v_30_2 * 3) + pub_r001334_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = (((stage_v_80_1 * 3) + pub_r001334_18_1) + 40) & 127;
  int stage_v_334_2 = (((stage_v_80_2 * 3) + pub_r001334_18_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001334_9_1 * 2) + 30) & 63;
  int stage_v_335_2 = ((pub_r001334_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = (((stage_v_273_1 * 3) + pub_r001334_16_1) + 23) & 127;
  int stage_v_336_2 = (((stage_v_273_2 * 3) + pub_r001334_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((helper_flow_2_1 * 3) + pub_r001334_3_1) + 41) & 127;
  int stage_v_337_2 = (((helper_flow_2_2 * 3) + pub_r001334_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((sec_r001334_0_1 * 3) + pub_r001334_20_1) + 37) & 127;
  int stage_v_338_2 = (((sec_r001334_0_2 * 3) + pub_r001334_20_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = (((stage_v_124_1 * 3) + pub_r001334_14_1) + 24) & 127;
  int stage_v_339_2 = (((stage_v_124_2 * 3) + pub_r001334_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = ((pub_r001334_2_1 * 2) + 36) & 63;
  int stage_v_340_2 = ((pub_r001334_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001334_12_1 * 2) + 8) & 63;
  int stage_v_341_2 = ((pub_r001334_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001334_12_1 * 2) + 29) & 63;
  int stage_v_342_2 = ((pub_r001334_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001334_5_1 * 2) + 34) & 63;
  int stage_v_343_2 = ((pub_r001334_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = (((stage_v_202_1 * 3) + pub_r001334_13_1) + 31) & 127;
  int stage_v_344_2 = (((stage_v_202_2 * 3) + pub_r001334_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001334_15_1 * 2) + 15) & 63;
  int stage_v_345_2 = ((pub_r001334_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = (((stage_v_40_1 * 3) + pub_r001334_3_1) + 24) & 127;
  int stage_v_346_2 = (((stage_v_40_2 * 3) + pub_r001334_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = (((stage_v_198_1 * 3) + pub_r001334_20_1) + 6) & 127;
  int stage_v_347_2 = (((stage_v_198_2 * 3) + pub_r001334_20_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_160_1 * 3) + pub_r001334_2_1) + 27) & 127;
  int stage_v_348_2 = (((stage_v_160_2 * 3) + pub_r001334_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_129_1 * 3) + pub_r001334_17_1) + 23) & 127;
  int stage_v_349_2 = (((stage_v_129_2 * 3) + pub_r001334_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_106_1 * 3) + pub_r001334_6_1) + 19) & 127;
  int stage_v_350_2 = (((stage_v_106_2 * 3) + pub_r001334_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001334_3_1 * 2) + 32) & 63;
  int stage_v_351_2 = ((pub_r001334_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001334_3_1 * 2) + 20) & 63;
  int stage_v_352_2 = ((pub_r001334_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = (((stage_v_263_1 * 3) + pub_r001334_7_1) + 20) & 127;
  int stage_v_353_2 = (((stage_v_263_2 * 3) + pub_r001334_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = ((pub_r001334_9_1 * 2) + 35) & 63;
  int stage_v_354_2 = ((pub_r001334_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001334_23_1 * 2) + 6) & 63;
  int stage_v_355_2 = ((pub_r001334_23_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001334_14_1 * 2) + 44) & 63;
  int stage_v_356_2 = ((pub_r001334_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = (((stage_v_195_1 * 3) + pub_r001334_0_1) + 22) & 127;
  int stage_v_357_2 = (((stage_v_195_2 * 3) + pub_r001334_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = ((pub_r001334_16_1 * 2) + 15) & 63;
  int stage_v_358_2 = ((pub_r001334_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((helper_flow_1_1 * 3) + pub_r001334_18_1) + 41) & 127;
  int stage_v_359_2 = (((helper_flow_1_2 * 3) + pub_r001334_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = ((pub_r001334_19_1 * 2) + 29) & 63;
  int stage_v_360_2 = ((pub_r001334_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001334_23_1 * 2) + 5) & 63;
  int stage_v_361_2 = ((pub_r001334_23_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001334_7_1 * 2) + 30) & 63;
  int stage_v_362_2 = ((pub_r001334_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001334_13_1 * 2) + 30) & 63;
  int stage_v_363_2 = ((pub_r001334_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = (((stage_v_13_1 * 3) + pub_r001334_17_1) + 30) & 127;
  int stage_v_364_2 = (((stage_v_13_2 * 3) + pub_r001334_17_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = ((pub_r001334_7_1 * 2) + 7) & 63;
  int stage_v_365_2 = ((pub_r001334_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001334_5_1 * 2) + 42) & 63;
  int stage_v_366_2 = ((pub_r001334_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001334_1_1 * 2) + 13) & 63;
  int stage_v_367_2 = ((pub_r001334_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001334_4_1 * 2) + 22) & 63;
  int stage_v_368_2 = ((pub_r001334_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001334_4_1 * 2) + 20) & 63;
  int stage_v_369_2 = ((pub_r001334_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = (((stage_v_270_1 * 3) + pub_r001334_23_1) + 18) & 127;
  int stage_v_370_2 = (((stage_v_270_2 * 3) + pub_r001334_23_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((stage_v_353_1 * 3) + pub_r001334_16_1) + 13) & 127;
  int stage_v_371_2 = (((stage_v_353_2 * 3) + pub_r001334_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001334_19_1 * 2) + 45) & 63;
  int stage_v_372_2 = ((pub_r001334_19_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001334_17_1 * 2) + 33) & 63;
  int stage_v_373_2 = ((pub_r001334_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((sec_r001334_19_1 * 3) + pub_r001334_10_1) + 12) & 127;
  int stage_v_374_2 = (((sec_r001334_19_2 * 3) + pub_r001334_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_147_1 * 3) + pub_r001334_7_1) + 35) & 127;
  int stage_v_375_2 = (((stage_v_147_2 * 3) + pub_r001334_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001334_23_1 * 2) + 26) & 63;
  int stage_v_376_2 = ((pub_r001334_23_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = (((sec_r001334_20_1 * 3) + pub_r001334_23_1) + 22) & 127;
  int stage_v_377_2 = (((sec_r001334_20_2 * 3) + pub_r001334_23_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((stage_v_253_1 * 3) + pub_r001334_3_1) + 12) & 127;
  int stage_v_378_2 = (((stage_v_253_2 * 3) + pub_r001334_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_175_1 * 3) + pub_r001334_10_1) + 44) & 127;
  int stage_v_379_2 = (((stage_v_175_2 * 3) + pub_r001334_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_296_1 * 3) + pub_r001334_1_1) + 38) & 127;
  int stage_v_380_2 = (((stage_v_296_2 * 3) + pub_r001334_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((stage_v_258_1 * 3) + pub_r001334_1_1) + 31) & 127;
  int stage_v_381_2 = (((stage_v_258_2 * 3) + pub_r001334_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = (((stage_v_290_1 * 3) + pub_r001334_10_1) + 28) & 127;
  int stage_v_382_2 = (((stage_v_290_2 * 3) + pub_r001334_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = (((stage_v_82_1 * 3) + pub_r001334_16_1) + 14) & 127;
  int stage_v_383_2 = (((stage_v_82_2 * 3) + pub_r001334_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = ((pub_r001334_9_1 * 2) + 36) & 63;
  int stage_v_384_2 = ((pub_r001334_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = (((stage_v_76_1 * 3) + pub_r001334_0_1) + 29) & 127;
  int stage_v_385_2 = (((stage_v_76_2 * 3) + pub_r001334_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = (((stage_v_130_1 * 3) + pub_r001334_15_1) + 20) & 127;
  int stage_v_386_2 = (((stage_v_130_2 * 3) + pub_r001334_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = (((stage_v_225_1 * 3) + pub_r001334_22_1) + 44) & 127;
  int stage_v_387_2 = (((stage_v_225_2 * 3) + pub_r001334_22_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001334_17_1 * 2) + 38) & 63;
  int stage_v_388_2 = ((pub_r001334_17_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001334_1_1 * 2) + 21) & 63;
  int stage_v_389_2 = ((pub_r001334_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = (((stage_v_160_1 * 3) + pub_r001334_6_1) + 45) & 127;
  int stage_v_390_2 = (((stage_v_160_2 * 3) + pub_r001334_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = ((pub_r001334_10_1 * 2) + 40) & 63;
  int stage_v_391_2 = ((pub_r001334_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001334_4_1 * 2) + 33) & 63;
  int stage_v_392_2 = ((pub_r001334_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = (((stage_v_317_1 * 3) + pub_r001334_3_1) + 32) & 127;
  int stage_v_393_2 = (((stage_v_317_2 * 3) + pub_r001334_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = (((stage_v_5_1 * 3) + pub_r001334_0_1) + 44) & 127;
  int stage_v_394_2 = (((stage_v_5_2 * 3) + pub_r001334_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = ((pub_r001334_2_1 * 2) + 40) & 63;
  int stage_v_395_2 = ((pub_r001334_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((stage_v_347_1 * 3) + pub_r001334_21_1) + 27) & 127;
  int stage_v_396_2 = (((stage_v_347_2 * 3) + pub_r001334_21_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = (((stage_v_63_1 * 3) + pub_r001334_6_1) + 21) & 127;
  int stage_v_397_2 = (((stage_v_63_2 * 3) + pub_r001334_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = (((stage_v_390_1 * 3) + pub_r001334_13_1) + 45) & 127;
  int stage_v_398_2 = (((stage_v_390_2 * 3) + pub_r001334_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = (((helper_flow_4_1 * 3) + pub_r001334_12_1) + 19) & 127;
  int stage_v_399_2 = (((helper_flow_4_2 * 3) + pub_r001334_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = (((stage_v_130_1 * 3) + pub_r001334_7_1) + 36) & 127;
  int stage_v_400_2 = (((stage_v_130_2 * 3) + pub_r001334_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = ((pub_r001334_10_1 * 2) + 33) & 63;
  int stage_v_401_2 = ((pub_r001334_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = (((stage_v_253_1 * 3) + pub_r001334_10_1) + 33) & 127;
  int stage_v_402_2 = (((stage_v_253_2 * 3) + pub_r001334_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = (((sec_r001334_5_1 * 3) + pub_r001334_9_1) + 33) & 127;
  int stage_v_403_2 = (((sec_r001334_5_2 * 3) + pub_r001334_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = ((pub_r001334_17_1 * 2) + 18) & 63;
  int stage_v_404_2 = ((pub_r001334_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = (((sec_r001334_3_1 * 3) + pub_r001334_17_1) + 4) & 127;
  int stage_v_405_2 = (((sec_r001334_3_2 * 3) + pub_r001334_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = (((stage_v_5_1 * 3) + pub_r001334_0_1) + 25) & 127;
  int stage_v_406_2 = (((stage_v_5_2 * 3) + pub_r001334_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = ((pub_r001334_5_1 * 2) + 49) & 63;
  int stage_v_407_2 = ((pub_r001334_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = (((stage_v_159_1 * 3) + pub_r001334_11_1) + 21) & 127;
  int stage_v_408_2 = (((stage_v_159_2 * 3) + pub_r001334_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = ((pub_r001334_13_1 * 2) + 13) & 63;
  int stage_v_409_2 = ((pub_r001334_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = (((stage_v_242_1 * 3) + pub_r001334_16_1) + 17) & 127;
  int stage_v_410_2 = (((stage_v_242_2 * 3) + pub_r001334_16_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_410_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_410_2 * 2)) & 255;
  int stage_v_411_1 = ((pub_r001334_17_1 * 2) + 12) & 63;
  int stage_v_411_2 = ((pub_r001334_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((pub_r001334_13_1 * 2) + 8) & 63;
  int stage_v_412_2 = ((pub_r001334_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((pub_r001334_16_1 * 2) + 47) & 63;
  int stage_v_413_2 = ((pub_r001334_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001334_16_1 * 2) + 35) & 63;
  int stage_v_414_2 = ((pub_r001334_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = (((stage_v_364_1 * 3) + pub_r001334_9_1) + 16) & 127;
  int stage_v_415_2 = (((stage_v_364_2 * 3) + pub_r001334_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = (((stage_v_6_1 * 3) + pub_r001334_1_1) + 26) & 127;
  int stage_v_416_2 = (((stage_v_6_2 * 3) + pub_r001334_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = (((stage_v_68_1 * 3) + pub_r001334_20_1) + 34) & 127;
  int stage_v_417_2 = (((stage_v_68_2 * 3) + pub_r001334_20_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = (((stage_v_31_1 * 3) + pub_r001334_13_1) + 5) & 127;
  int stage_v_418_2 = (((stage_v_31_2 * 3) + pub_r001334_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_418_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_418_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_418_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_418_2 * 2)) & 255;
  int stage_v_419_1 = ((pub_r001334_7_1 * 2) + 30) & 63;
  int stage_v_419_2 = ((pub_r001334_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = (((stage_v_194_1 * 3) + pub_r001334_22_1) + 45) & 127;
  int stage_v_420_2 = (((stage_v_194_2 * 3) + pub_r001334_22_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = (((stage_v_175_1 * 3) + pub_r001334_20_1) + 29) & 127;
  int stage_v_421_2 = (((stage_v_175_2 * 3) + pub_r001334_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001334_9_1 == pub_r001334_9_2);
  __CPROVER_assume(pub_r001334_18_1 == pub_r001334_18_2);
  __CPROVER_assume(pub_r001334_8_1 == pub_r001334_8_2);
  __CPROVER_assume(sec_r001334_6_1 != sec_r001334_6_2);
  __CPROVER_assume(sec_r001334_12_1 != sec_r001334_12_2);
  __CPROVER_assume(pub_r001334_6_1 == pub_r001334_6_2);
  __CPROVER_assume(sec_r001334_2_1 != sec_r001334_2_2);
  __CPROVER_assume(sec_r001334_20_1 != sec_r001334_20_2);
  __CPROVER_assume(sec_r001334_0_1 != sec_r001334_0_2);
  __CPROVER_assume(pub_r001334_23_1 == pub_r001334_23_2);
  __CPROVER_assume(sec_r001334_11_1 != sec_r001334_11_2);
  __CPROVER_assume(pub_r001334_1_1 == pub_r001334_1_2);
  __CPROVER_assume(pub_r001334_7_1 == pub_r001334_7_2);
  __CPROVER_assume(pub_r001334_2_1 == pub_r001334_2_2);
  __CPROVER_assume(pub_r001334_15_1 == pub_r001334_15_2);
  __CPROVER_assume(sec_r001334_13_1 != sec_r001334_13_2);
  __CPROVER_assume(sec_r001334_3_1 != sec_r001334_3_2);
  __CPROVER_assume(pub_r001334_10_1 == pub_r001334_10_2);
  __CPROVER_assume(sec_r001334_7_1 != sec_r001334_7_2);
  __CPROVER_assume(sec_r001334_8_1 != sec_r001334_8_2);
  __CPROVER_assume(pub_r001334_3_1 == pub_r001334_3_2);
  __CPROVER_assume(pub_r001334_20_1 == pub_r001334_20_2);
  __CPROVER_assume(sec_r001334_9_1 != sec_r001334_9_2);
  __CPROVER_assume(sec_r001334_10_1 != sec_r001334_10_2);
  __CPROVER_assume(pub_r001334_13_1 == pub_r001334_13_2);
  __CPROVER_assume(pub_r001334_14_1 == pub_r001334_14_2);
  __CPROVER_assume(pub_r001334_11_1 == pub_r001334_11_2);
  __CPROVER_assume(pub_r001334_19_1 == pub_r001334_19_2);
  __CPROVER_assume(sec_r001334_5_1 != sec_r001334_5_2);
  __CPROVER_assume(sec_r001334_19_1 != sec_r001334_19_2);
  __CPROVER_assume(sec_r001334_15_1 != sec_r001334_15_2);
  __CPROVER_assume(sec_r001334_16_1 != sec_r001334_16_2);
  __CPROVER_assume(sec_r001334_17_1 != sec_r001334_17_2);
  __CPROVER_assume(sec_r001334_14_1 != sec_r001334_14_2);
  __CPROVER_assume(sec_r001334_18_1 != sec_r001334_18_2);
  __CPROVER_assume(pub_r001334_0_1 == pub_r001334_0_2);
  __CPROVER_assume(sec_r001334_1_1 != sec_r001334_1_2);
  __CPROVER_assume(pub_r001334_21_1 == pub_r001334_21_2);
  __CPROVER_assume(pub_r001334_16_1 == pub_r001334_16_2);
  __CPROVER_assume(sec_r001334_4_1 != sec_r001334_4_2);
  __CPROVER_assume(pub_r001334_4_1 == pub_r001334_4_2);
  __CPROVER_assume(pub_r001334_5_1 == pub_r001334_5_2);
  __CPROVER_assume(pub_r001334_17_1 == pub_r001334_17_2);
  __CPROVER_assume(pub_r001334_22_1 == pub_r001334_22_2);
  __CPROVER_assume(pub_r001334_12_1 == pub_r001334_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
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
  assert(stage_v_337_1 == stage_v_337_2);
  assert(stage_v_338_1 == stage_v_338_2);
  assert(stage_v_339_1 == stage_v_339_2);
  assert(stage_v_340_1 == stage_v_340_2);
  assert(stage_v_341_1 == stage_v_341_2);
  assert(stage_v_342_1 == stage_v_342_2);
  assert(stage_v_343_1 == stage_v_343_2);
  assert(stage_v_344_1 == stage_v_344_2);
  assert(stage_v_345_1 == stage_v_345_2);
  assert(stage_v_346_1 == stage_v_346_2);
  assert(stage_v_347_1 == stage_v_347_2);
  assert(stage_v_348_1 == stage_v_348_2);
  assert(stage_v_349_1 == stage_v_349_2);
  assert(stage_v_350_1 == stage_v_350_2);
  assert(stage_v_351_1 == stage_v_351_2);
  assert(stage_v_352_1 == stage_v_352_2);
  assert(stage_v_353_1 == stage_v_353_2);
  assert(stage_v_354_1 == stage_v_354_2);
  assert(stage_v_355_1 == stage_v_355_2);
  assert(stage_v_356_1 == stage_v_356_2);
  assert(stage_v_357_1 == stage_v_357_2);
  assert(stage_v_358_1 == stage_v_358_2);
  assert(stage_v_359_1 == stage_v_359_2);
  assert(stage_v_360_1 == stage_v_360_2);
  assert(stage_v_361_1 == stage_v_361_2);
  assert(stage_v_362_1 == stage_v_362_2);
  assert(stage_v_363_1 == stage_v_363_2);
  assert(stage_v_364_1 == stage_v_364_2);
  assert(stage_v_365_1 == stage_v_365_2);
  assert(stage_v_366_1 == stage_v_366_2);
  assert(stage_v_367_1 == stage_v_367_2);
  assert(stage_v_368_1 == stage_v_368_2);
  assert(stage_v_369_1 == stage_v_369_2);
  assert(stage_v_370_1 == stage_v_370_2);
  assert(stage_v_371_1 == stage_v_371_2);
  assert(stage_v_372_1 == stage_v_372_2);
  assert(stage_v_373_1 == stage_v_373_2);
  assert(stage_v_374_1 == stage_v_374_2);
  assert(stage_v_375_1 == stage_v_375_2);
  assert(stage_v_376_1 == stage_v_376_2);
  assert(stage_v_377_1 == stage_v_377_2);
  assert(stage_v_378_1 == stage_v_378_2);
  assert(stage_v_379_1 == stage_v_379_2);
  assert(stage_v_380_1 == stage_v_380_2);
  assert(stage_v_381_1 == stage_v_381_2);
  assert(stage_v_382_1 == stage_v_382_2);
  assert(stage_v_383_1 == stage_v_383_2);
  assert(stage_v_384_1 == stage_v_384_2);
  assert(stage_v_385_1 == stage_v_385_2);
  assert(stage_v_386_1 == stage_v_386_2);
  assert(stage_v_387_1 == stage_v_387_2);
  assert(stage_v_388_1 == stage_v_388_2);
  assert(stage_v_389_1 == stage_v_389_2);
  assert(stage_v_390_1 == stage_v_390_2);
  assert(stage_v_391_1 == stage_v_391_2);
  assert(stage_v_392_1 == stage_v_392_2);
  assert(stage_v_393_1 == stage_v_393_2);
  assert(stage_v_394_1 == stage_v_394_2);
  assert(stage_v_395_1 == stage_v_395_2);
  assert(stage_v_396_1 == stage_v_396_2);
  assert(stage_v_397_1 == stage_v_397_2);
  assert(stage_v_398_1 == stage_v_398_2);
  assert(stage_v_399_1 == stage_v_399_2);
  assert(stage_v_400_1 == stage_v_400_2);
  assert(stage_v_401_1 == stage_v_401_2);
  assert(stage_v_402_1 == stage_v_402_2);
  assert(stage_v_403_1 == stage_v_403_2);
  assert(stage_v_404_1 == stage_v_404_2);
  assert(stage_v_405_1 == stage_v_405_2);
  assert(stage_v_406_1 == stage_v_406_2);
  assert(stage_v_407_1 == stage_v_407_2);
  assert(stage_v_408_1 == stage_v_408_2);
  assert(stage_v_409_1 == stage_v_409_2);
  assert(stage_v_410_1 == stage_v_410_2);
  assert(stage_v_411_1 == stage_v_411_2);
  assert(stage_v_412_1 == stage_v_412_2);
  assert(stage_v_413_1 == stage_v_413_2);
  assert(stage_v_414_1 == stage_v_414_2);
  assert(stage_v_415_1 == stage_v_415_2);
  assert(stage_v_416_1 == stage_v_416_2);
  assert(stage_v_417_1 == stage_v_417_2);
  assert(stage_v_418_1 == stage_v_418_2);
  assert(stage_v_419_1 == stage_v_419_2);
  assert(stage_v_420_1 == stage_v_420_2);
  assert(stage_v_421_1 == stage_v_421_2);
}


