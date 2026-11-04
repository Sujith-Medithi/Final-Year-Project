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
struct StreamBuffer_R000682_8213_0
{
  short tail;
  int checksum;
  int capacity;
  int watermark;
  int head;
  int buffer[3];
};
struct CipherContext_R000682_8213_1
{
  short tag;
  int counter;
  short nonce;
  int round_key;
  short flags;
  short iv;
  int buffer[3];
};
struct EventLog_R000682_8213_2
{
  int severity;
  unsigned char facility;
  unsigned char signature;
  short timestamp;
  short seq;
  unsigned char code;
  int buffer[3];
};
struct MatrixBlock_R000682_8213_3
{
  short determinant;
  int dim;
  int scale;
  short stride;
  int buffer[3];
};
union ColorPixel_R000682_8213_0
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
void fn_R000682_8213_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000682_8213_2 st_1 = {0};
  struct EventLog_R000682_8213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_23_1 = local_arr_1[aux_1 % 3];
  int bound_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_23_2 * 2)) & 127;
  int window_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_17_1) & 63;
  aux_2 = (aux_2 + window_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_30_1)
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

  switch (tracker_30_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_23_1 == bound_23_2);
  assert(window_17_1 == window_17_2);
  assert(tracker_30_1 == tracker_30_2);
}

int fn_R000682_8213_0(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000682_8213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int bound_23 = local_arr[aux % 3];
  acc = (acc + (bound_23 * 2)) & 127;
  int window_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_17) & 63;
  acc ^= aux;
  int tracker_30 = (aux + st.buffer[1]) & 3;
  switch (tracker_30)
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

void fn_R000682_8213_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st_1 = {0};
  struct MatrixBlock_R000682_8213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_82_1 = local_arr_1[aux_1 % 3];
  int damping_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_82_2 * 2)) & 127;
  int quantum_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_54_1) & 63;
  aux_2 = (aux_2 + quantum_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_82_1 == damping_82_2);
  assert(quantum_54_1 == quantum_54_2);
}

int fn_R000682_8213_1(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int damping_82 = local_arr[aux % 3];
  acc = (acc + (damping_82 * 2)) & 127;
  int quantum_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000682_8213_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st_1 = {0};
  struct MatrixBlock_R000682_8213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int phase_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_88_1)
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

  switch (phase_88_2)
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

  int delta_40_1 = 0;
  int delta_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_40_1 = ((delta_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_40_2 = ((delta_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_40_1) & 127;
    acc_2 = (acc_2 + delta_40_2) & 127;
  }

  int sample_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_75_1) & 63;
  aux_2 = (aux_2 + sample_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_88_1 == phase_88_2);
  assert(delta_40_1 == delta_40_2);
  assert(sample_75_1 == sample_75_2);
}

int fn_R000682_8213_2(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int phase_88 = (aux + st.buffer[1]) & 3;
  switch (phase_88)
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

  int delta_40 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_40 = ((delta_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_40) & 127;
  }

  int sample_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_75) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000682_8213_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st_1 = {0};
  struct MatrixBlock_R000682_8213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int mask_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_64_1) & 63;
  aux_2 = (aux_2 + mask_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_72_1)
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

  switch (margin_72_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_43_1 = local_arr_1[aux_1 % 3];
  int delta_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_43_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_64_1 == mask_64_2);
  assert(margin_72_1 == margin_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_43_1 == delta_43_2);
}

int fn_R000682_8213_3(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int mask_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_64) & 63;
  acc ^= aux;
  int margin_72 = (aux + st.buffer[1]) & 3;
  switch (margin_72)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_43 = local_arr[aux % 3];
  acc = (acc + (delta_43 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000682_8213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st_1 = {0};
  struct MatrixBlock_R000682_8213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_38_1 > 13)
  {
    acc_1 = ((acc_1 + (window_38_1 * 2)) + 5) & 127;
    aux_1 ^= window_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_38_2 > 13)
  {
    acc_2 = ((acc_2 + (window_38_2 * 2)) + 5) & 127;
    aux_2 ^= window_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_38_1 == window_38_2);
}

int fn_R000682_8213_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_38 > 13)
  {
    acc = ((acc + (window_38 * 2)) + 5) & 127;
    aux ^= window_38 & 15;
  }
  else
  {
    acc = ((acc - window_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000682_8213_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000682_8213_2 st_1 = {0};
  struct EventLog_R000682_8213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int offset_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_84_1)
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

  switch (offset_84_2)
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
  int window_74_1 = local_arr_1[aux_1 % 3];
  int window_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_74_2 * 2)) & 127;
  int weight_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_84_1 > 41)
  {
    acc_1 = ((acc_1 + (weight_84_1 * 2)) + 5) & 127;
    aux_1 ^= weight_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_84_2 > 41)
  {
    acc_2 = ((acc_2 + (weight_84_2 * 2)) + 5) & 127;
    aux_2 ^= weight_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_98_1) & 63;
  aux_2 = (aux_2 + margin_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_84_1 == offset_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_74_1 == window_74_2);
  assert(weight_84_1 == weight_84_2);
  assert(margin_98_1 == margin_98_2);
}

int fn_R000682_8213_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000682_8213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int offset_84 = (aux + st.buffer[1]) & 3;
  switch (offset_84)
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
  int window_74 = local_arr[aux % 3];
  acc = (acc + (window_74 * 2)) & 127;
  int weight_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_84 > 41)
  {
    acc = ((acc + (weight_84 * 2)) + 5) & 127;
    aux ^= weight_84 & 15;
  }
  else
  {
    acc = ((acc - weight_84) + 11) & 127;
    aux += 3;
  }
  int margin_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_98) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000682_8213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000682_8213_1 st_1 = {0};
  struct CipherContext_R000682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_98_1)
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

  switch (bound_98_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_98_1 == bound_98_2);
}

int fn_R000682_8213_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_98 = (aux + st.buffer[1]) & 3;
  switch (bound_98)
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

void fn_R000682_8213_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000682_8213_0 st_1 = {0};
  struct StreamBuffer_R000682_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int residue_59_1 = 0;
  int residue_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_59_1 = ((residue_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_59_2 = ((residue_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_59_1) & 127;
    acc_2 = (acc_2 + residue_59_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_93_1 > 17)
  {
    acc_1 = ((acc_1 + (cursor_93_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_93_2 > 17)
  {
    acc_2 = ((acc_2 + (cursor_93_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_70_1 = local_arr_1[aux_1 % 3];
  int parity_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_59_1 == residue_59_2);
  assert(cursor_93_1 == cursor_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_70_1 == parity_70_2);
}

int fn_R000682_8213_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000682_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int residue_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_59 = ((residue_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_59) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_93 > 17)
  {
    acc = ((acc + (cursor_93 * 2)) + 5) & 127;
    aux ^= cursor_93 & 15;
  }
  else
  {
    acc = ((acc - cursor_93) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_70 = local_arr[aux % 3];
  acc = (acc + (parity_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000682_8213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st_1 = {0};
  struct MatrixBlock_R000682_8213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_71_1 = local_arr_1[aux_1 % 3];
  int metric_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_71_2 * 2)) & 127;
  int stride_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_29_1 > 19)
  {
    acc_1 = ((acc_1 + (stride_29_1 * 2)) + 5) & 127;
    aux_1 ^= stride_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_29_2 > 19)
  {
    acc_2 = ((acc_2 + (stride_29_2 * 2)) + 5) & 127;
    aux_2 ^= stride_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_71_1 == metric_71_2);
  assert(stride_29_1 == stride_29_2);
}

int fn_R000682_8213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_71 = local_arr[aux % 3];
  acc = (acc + (metric_71 * 2)) & 127;
  int stride_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_29 > 19)
  {
    acc = ((acc + (stride_29 * 2)) + 5) & 127;
    aux ^= stride_29 & 15;
  }
  else
  {
    acc = ((acc - stride_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000682_8213_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st_1 = {0};
  struct MatrixBlock_R000682_8213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quotient_35_1 = 0;
  int quotient_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_35_1 = ((quotient_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_35_2 = ((quotient_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_35_1) & 127;
    acc_2 = (acc_2 + quotient_35_2) & 127;
  }

  int damping_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_23_1)
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

  switch (damping_23_2)
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

  int stride_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_87_1) & 63;
  aux_2 = (aux_2 + stride_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_84_1 = local_arr_1[aux_1 % 3];
  int coefficient_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_84_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_35_1 == quotient_35_2);
  assert(damping_23_1 == damping_23_2);
  assert(stride_87_1 == stride_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_84_1 == coefficient_84_2);
}

int fn_R000682_8213_9(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quotient_35 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_35 = ((quotient_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_35) & 127;
  }

  int damping_23 = (aux + st.buffer[1]) & 3;
  switch (damping_23)
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

  int stride_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_87) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_84 = local_arr[aux % 3];
  acc = (acc + (coefficient_84 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000682_8213_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000682_8213_1 st_1 = {0};
  struct CipherContext_R000682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_58_1 = 0;
  int stride_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_58_1 = ((stride_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_58_2 = ((stride_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_58_1) & 127;
    acc_2 = (acc_2 + stride_58_2) & 127;
  }

  int damping_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_68_1 > 11)
  {
    acc_1 = ((acc_1 + (damping_68_1 * 2)) + 5) & 127;
    aux_1 ^= damping_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_68_2 > 11)
  {
    acc_2 = ((acc_2 + (damping_68_2 * 2)) + 5) & 127;
    aux_2 ^= damping_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_67_1)
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

  switch (index_reg_67_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_58_1 == stride_58_2);
  assert(damping_68_1 == damping_68_2);
  assert(index_reg_67_1 == index_reg_67_2);
}

int fn_R000682_8213_10(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_58 = ((stride_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_58) & 127;
  }

  int damping_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_68 > 11)
  {
    acc = ((acc + (damping_68 * 2)) + 5) & 127;
    aux ^= damping_68 & 15;
  }
  else
  {
    acc = ((acc - damping_68) + 11) & 127;
    aux += 3;
  }
  int index_reg_67 = (aux + st.buffer[1]) & 3;
  switch (index_reg_67)
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

void fn_R000682_8213_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000682_8213_0 st_1 = {0};
  struct StreamBuffer_R000682_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int cursor_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_18_1) & 63;
  aux_2 = (aux_2 + cursor_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_51_1 = local_arr_1[aux_1 % 3];
  int factor_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_18_1 == cursor_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_51_1 == factor_51_2);
}

int fn_R000682_8213_11(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000682_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int cursor_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_18) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_51 = local_arr[aux % 3];
  acc = (acc + (factor_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000682_8213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st_1 = {0};
  struct MatrixBlock_R000682_8213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tally_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_64_1 > 50)
  {
    acc_1 = ((acc_1 + (tally_64_1 * 2)) + 5) & 127;
    aux_1 ^= tally_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_64_2 > 50)
  {
    acc_2 = ((acc_2 + (tally_64_2 * 2)) + 5) & 127;
    aux_2 ^= tally_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_73_1 = local_arr_1[aux_1 % 3];
  int stride_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_73_2 * 2)) & 127;
  int parity_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_91_1)
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

  switch (parity_91_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_64_1 == tally_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_73_1 == stride_73_2);
  assert(parity_91_1 == parity_91_2);
}

int fn_R000682_8213_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tally_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_64 > 50)
  {
    acc = ((acc + (tally_64 * 2)) + 5) & 127;
    aux ^= tally_64 & 15;
  }
  else
  {
    acc = ((acc - tally_64) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_73 = local_arr[aux % 3];
  acc = (acc + (stride_73 * 2)) & 127;
  int parity_91 = (aux + st.buffer[1]) & 3;
  switch (parity_91)
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

void fn_R000682_8213_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st_1 = {0};
  struct MatrixBlock_R000682_8213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_43_1 = local_arr_1[aux_1 % 3];
  int bound_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_43_2 * 2)) & 127;
  int damping_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_88_1 > 24)
  {
    acc_1 = ((acc_1 + (damping_88_1 * 2)) + 5) & 127;
    aux_1 ^= damping_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_88_2 > 24)
  {
    acc_2 = ((acc_2 + (damping_88_2 * 2)) + 5) & 127;
    aux_2 ^= damping_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_88_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_50_1 = 0;
  int delta_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_50_1 = ((delta_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_50_2 = ((delta_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_50_1) & 127;
    acc_2 = (acc_2 + delta_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_43_1 == bound_43_2);
  assert(damping_88_1 == damping_88_2);
  assert(delta_50_1 == delta_50_2);
}

int fn_R000682_8213_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int bound_43 = local_arr[aux % 3];
  acc = (acc + (bound_43 * 2)) & 127;
  int damping_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_88 > 24)
  {
    acc = ((acc + (damping_88 * 2)) + 5) & 127;
    aux ^= damping_88 & 15;
  }
  else
  {
    acc = ((acc - damping_88) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_50 = ((delta_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_50) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000682_8213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000682_8213_1 st_1 = {0};
  struct CipherContext_R000682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_35_1 = local_arr_1[aux_1 % 3];
  int sample_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_35_2 * 2)) & 127;
  int mask_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_40_1) & 63;
  aux_2 = (aux_2 + mask_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_69_1)
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

  switch (quotient_69_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_35_1 == sample_35_2);
  assert(mask_40_1 == mask_40_2);
  assert(quotient_69_1 == quotient_69_2);
}

int fn_R000682_8213_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int sample_35 = local_arr[aux % 3];
  acc = (acc + (sample_35 * 2)) & 127;
  int mask_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_40) & 63;
  acc ^= aux;
  int quotient_69 = (aux + st.buffer[1]) & 3;
  switch (quotient_69)
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

void fn_R000682_8213_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000682_8213_2 st_1 = {0};
  struct EventLog_R000682_8213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_23_1 = local_arr_1[aux_1 % 3];
  int segment_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_23_2 * 2)) & 127;
  int factor_86_1 = 0;
  int factor_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_86_1 = ((factor_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_86_2 = ((factor_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_86_1) & 127;
    acc_2 = (acc_2 + factor_86_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_12_1) & 63;
  aux_2 = (aux_2 + mask_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_23_1 == segment_23_2);
  assert(factor_86_1 == factor_86_2);
  assert(mask_12_1 == mask_12_2);
}

int fn_R000682_8213_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000682_8213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int segment_23 = local_arr[aux % 3];
  acc = (acc + (segment_23 * 2)) & 127;
  int factor_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_86 = ((factor_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_86) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_12) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000682_8213_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000682_8213_0 st_1 = {0};
  struct StreamBuffer_R000682_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_21_1 > 30)
  {
    acc_1 = ((acc_1 + (threshold_21_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_21_2 > 30)
  {
    acc_2 = ((acc_2 + (threshold_21_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_57_1)
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

  switch (weight_57_2)
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

  int window_21_1 = 0;
  int window_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_21_1 = ((window_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_21_2 = ((window_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_21_1) & 127;
    acc_2 = (acc_2 + window_21_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_21_1 == threshold_21_2);
  assert(weight_57_1 == weight_57_2);
  assert(window_21_1 == window_21_2);
}

int fn_R000682_8213_16(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000682_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_21 > 30)
  {
    acc = ((acc + (threshold_21 * 2)) + 5) & 127;
    aux ^= threshold_21 & 15;
  }
  else
  {
    acc = ((acc - threshold_21) + 11) & 127;
    aux += 3;
  }
  int weight_57 = (aux + st.buffer[1]) & 3;
  switch (weight_57)
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

  int window_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_21 = ((window_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_21) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000682_8213_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000682_8213_2 st_1 = {0};
  struct EventLog_R000682_8213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int metric_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_19_1 > 15)
  {
    acc_1 = ((acc_1 + (metric_19_1 * 2)) + 5) & 127;
    aux_1 ^= metric_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_19_2 > 15)
  {
    acc_2 = ((acc_2 + (metric_19_2 * 2)) + 5) & 127;
    aux_2 ^= metric_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_19_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_93_1 = 0;
  int anchor_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_93_1 = ((anchor_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_93_2 = ((anchor_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_93_1) & 127;
    acc_2 = (acc_2 + anchor_93_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_19_1 == metric_19_2);
  assert(anchor_93_1 == anchor_93_2);
}

int fn_R000682_8213_17(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000682_8213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int metric_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_19 > 15)
  {
    acc = ((acc + (metric_19 * 2)) + 5) & 127;
    aux ^= metric_19 & 15;
  }
  else
  {
    acc = ((acc - metric_19) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_93 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_93 = ((anchor_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_93) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000682_8213_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000682_8213_1 st_1 = {0};
  struct CipherContext_R000682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_72_1 > 17)
  {
    acc_1 = ((acc_1 + (index_reg_72_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_72_2 > 17)
  {
    acc_2 = ((acc_2 + (index_reg_72_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_97_1) & 63;
  aux_2 = (aux_2 + delta_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_72_1 == index_reg_72_2);
  assert(delta_97_1 == delta_97_2);
}

int fn_R000682_8213_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_72 > 17)
  {
    acc = ((acc + (index_reg_72 * 2)) + 5) & 127;
    aux ^= index_reg_72 & 15;
  }
  else
  {
    acc = ((acc - index_reg_72) + 11) & 127;
    aux += 3;
  }
  int delta_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000682_8213_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000682_8213_0 st_1 = {0};
  struct StreamBuffer_R000682_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tracker_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_28_1)
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

  switch (tracker_28_2)
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

  int cursor_70_1 = 0;
  int cursor_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_70_1 = ((cursor_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_70_2 = ((cursor_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_70_1) & 127;
    acc_2 = (acc_2 + cursor_70_2) & 127;
  }

  int segment_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_34_1) & 63;
  aux_2 = (aux_2 + segment_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_28_1 == tracker_28_2);
  assert(cursor_70_1 == cursor_70_2);
  assert(segment_34_1 == segment_34_2);
}

int fn_R000682_8213_19(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000682_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tracker_28 = (aux + st.buffer[1]) & 3;
  switch (tracker_28)
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

  int cursor_70 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_70 = ((cursor_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_70) & 127;
  }

  int segment_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000682_8213_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st_1 = {0};
  struct MatrixBlock_R000682_8213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_98_1 = local_arr_1[aux_1 % 3];
  int metric_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_98_2 * 2)) & 127;
  int phase_40_1 = 0;
  int phase_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_40_1 = ((phase_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_40_2 = ((phase_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_40_1) & 127;
    acc_2 = (acc_2 + phase_40_2) & 127;
  }

  int parity_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_72_1) & 63;
  aux_2 = (aux_2 + parity_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_98_1 == metric_98_2);
  assert(phase_40_1 == phase_40_2);
  assert(parity_72_1 == parity_72_2);
}

int fn_R000682_8213_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int metric_98 = local_arr[aux % 3];
  acc = (acc + (metric_98 * 2)) & 127;
  int phase_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_40 = ((phase_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_40) & 127;
  }

  int parity_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_72) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000682_8213_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000682_8213_0 st_1 = {0};
  struct StreamBuffer_R000682_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int factor_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_20_1) & 63;
  aux_2 = (aux_2 + factor_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_16_1 = 0;
  int quantum_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_16_1 = ((quantum_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_16_2 = ((quantum_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_16_1) & 127;
    acc_2 = (acc_2 + quantum_16_2) & 127;
  }

  int bound_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_26_1 > 26)
  {
    acc_1 = ((acc_1 + (bound_26_1 * 2)) + 5) & 127;
    aux_1 ^= bound_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_26_2 > 26)
  {
    acc_2 = ((acc_2 + (bound_26_2 * 2)) + 5) & 127;
    aux_2 ^= bound_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_26_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_20_1 == factor_20_2);
  assert(quantum_16_1 == quantum_16_2);
  assert(bound_26_1 == bound_26_2);
}

int fn_R000682_8213_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000682_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int factor_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_20) & 63;
  acc ^= aux;
  int quantum_16 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_16 = ((quantum_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_16) & 127;
  }

  int bound_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_26 > 26)
  {
    acc = ((acc + (bound_26 * 2)) + 5) & 127;
    aux ^= bound_26 & 15;
  }
  else
  {
    acc = ((acc - bound_26) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000682_8213_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000682_8213_1 st_1 = {0};
  struct CipherContext_R000682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_46_1 = local_arr_1[aux_1 % 3];
  int segment_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_46_2 * 2)) & 127;
  int tracker_71_1 = 0;
  int tracker_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_71_1 = ((tracker_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_71_2 = ((tracker_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_71_1) & 127;
    acc_2 = (acc_2 + tracker_71_2) & 127;
  }

  int phase_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_55_1 > 38)
  {
    acc_1 = ((acc_1 + (phase_55_1 * 2)) + 5) & 127;
    aux_1 ^= phase_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_55_2 > 38)
  {
    acc_2 = ((acc_2 + (phase_55_2 * 2)) + 5) & 127;
    aux_2 ^= phase_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_37_1) & 63;
  aux_2 = (aux_2 + scale_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_46_1 == segment_46_2);
  assert(tracker_71_1 == tracker_71_2);
  assert(phase_55_1 == phase_55_2);
  assert(scale_37_1 == scale_37_2);
}

int fn_R000682_8213_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int segment_46 = local_arr[aux % 3];
  acc = (acc + (segment_46 * 2)) & 127;
  int tracker_71 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_71 = ((tracker_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_71) & 127;
  }

  int phase_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_55 > 38)
  {
    acc = ((acc + (phase_55 * 2)) + 5) & 127;
    aux ^= phase_55 & 15;
  }
  else
  {
    acc = ((acc - phase_55) + 11) & 127;
    aux += 3;
  }
  int scale_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_37) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000682_8213_23_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st_1 = {0};
  struct MatrixBlock_R000682_8213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_68_1 = local_arr_1[aux_1 % 3];
  int quotient_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_68_2 * 2)) & 127;
  int threshold_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_55_1)
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

  switch (threshold_55_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_68_1 == quotient_68_2);
  assert(threshold_55_1 == threshold_55_2);
}

int fn_R000682_8213_23(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_68 = local_arr[aux % 3];
  acc = (acc + (quotient_68 * 2)) & 127;
  int threshold_55 = (aux + st.buffer[1]) & 3;
  switch (threshold_55)
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

void fn_R000682_8213_24_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st_1 = {0};
  struct MatrixBlock_R000682_8213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int damping_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_37_1)
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

  switch (damping_37_2)
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

  int quotient_26_1 = 0;
  int quotient_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_26_1 = ((quotient_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_26_2 = ((quotient_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_26_1) & 127;
    acc_2 = (acc_2 + quotient_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_37_1 == damping_37_2);
  assert(quotient_26_1 == quotient_26_2);
}

int fn_R000682_8213_24(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000682_8213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int damping_37 = (aux + st.buffer[1]) & 3;
  switch (damping_37)
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

  int quotient_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_26 = ((quotient_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_26) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r000682_0_1;
  int sec_r000682_0_2;
  int sec_r000682_1_1;
  int sec_r000682_1_2;
  int sec_r000682_2_1;
  int sec_r000682_2_2;
  int sec_r000682_3_1;
  int sec_r000682_3_2;
  int sec_r000682_4_1;
  int sec_r000682_4_2;
  int sec_r000682_5_1;
  int sec_r000682_5_2;
  int sec_r000682_6_1;
  int sec_r000682_6_2;
  int sec_r000682_7_1;
  int sec_r000682_7_2;
  int sec_r000682_8_1;
  int sec_r000682_8_2;
  int sec_r000682_9_1;
  int sec_r000682_9_2;
  int sec_r000682_10_1;
  int sec_r000682_10_2;
  int sec_r000682_11_1;
  int sec_r000682_11_2;
  int sec_r000682_12_1;
  int sec_r000682_12_2;
  int sec_r000682_13_1;
  int sec_r000682_13_2;
  int sec_r000682_14_1;
  int sec_r000682_14_2;
  int sec_r000682_15_1;
  int sec_r000682_15_2;
  int sec_r000682_16_1;
  int sec_r000682_16_2;
  int sec_r000682_17_1;
  int sec_r000682_17_2;
  int sec_r000682_18_1;
  int sec_r000682_18_2;
  int pub_r000682_0_1;
  int pub_r000682_0_2;
  int pub_r000682_1_1;
  int pub_r000682_1_2;
  int pub_r000682_2_1;
  int pub_r000682_2_2;
  int pub_r000682_3_1;
  int pub_r000682_3_2;
  int pub_r000682_4_1;
  int pub_r000682_4_2;
  int pub_r000682_5_1;
  int pub_r000682_5_2;
  int pub_r000682_6_1;
  int pub_r000682_6_2;
  int pub_r000682_7_1;
  int pub_r000682_7_2;
  int pub_r000682_8_1;
  int pub_r000682_8_2;
  int pub_r000682_9_1;
  int pub_r000682_9_2;
  int pub_r000682_10_1;
  int pub_r000682_10_2;
  int pub_r000682_11_1;
  int pub_r000682_11_2;
  int pub_r000682_12_1;
  int pub_r000682_12_2;
  int pub_r000682_13_1;
  int pub_r000682_13_2;
  int pub_r000682_14_1;
  int pub_r000682_14_2;
  int pub_r000682_15_1;
  int pub_r000682_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000682_0_1 >= (-100)) && (pub_r000682_0_1 <= 100));
  __CPROVER_assume((pub_r000682_0_2 >= (-100)) && (pub_r000682_0_2 <= 100));
  __CPROVER_assume((pub_r000682_1_1 >= (-100)) && (pub_r000682_1_1 <= 100));
  __CPROVER_assume((pub_r000682_1_2 >= (-100)) && (pub_r000682_1_2 <= 100));
  __CPROVER_assume((pub_r000682_2_1 >= (-100)) && (pub_r000682_2_1 <= 100));
  __CPROVER_assume((pub_r000682_2_2 >= (-100)) && (pub_r000682_2_2 <= 100));
  __CPROVER_assume((pub_r000682_3_1 >= (-100)) && (pub_r000682_3_1 <= 100));
  __CPROVER_assume((pub_r000682_3_2 >= (-100)) && (pub_r000682_3_2 <= 100));
  __CPROVER_assume((pub_r000682_4_1 >= (-100)) && (pub_r000682_4_1 <= 100));
  __CPROVER_assume((pub_r000682_4_2 >= (-100)) && (pub_r000682_4_2 <= 100));
  __CPROVER_assume((pub_r000682_5_1 >= (-100)) && (pub_r000682_5_1 <= 100));
  __CPROVER_assume((pub_r000682_5_2 >= (-100)) && (pub_r000682_5_2 <= 100));
  __CPROVER_assume((pub_r000682_6_1 >= (-100)) && (pub_r000682_6_1 <= 100));
  __CPROVER_assume((pub_r000682_6_2 >= (-100)) && (pub_r000682_6_2 <= 100));
  __CPROVER_assume((pub_r000682_7_1 >= (-100)) && (pub_r000682_7_1 <= 100));
  __CPROVER_assume((pub_r000682_7_2 >= (-100)) && (pub_r000682_7_2 <= 100));
  __CPROVER_assume((pub_r000682_8_1 >= (-100)) && (pub_r000682_8_1 <= 100));
  __CPROVER_assume((pub_r000682_8_2 >= (-100)) && (pub_r000682_8_2 <= 100));
  __CPROVER_assume((pub_r000682_9_1 >= (-100)) && (pub_r000682_9_1 <= 100));
  __CPROVER_assume((pub_r000682_9_2 >= (-100)) && (pub_r000682_9_2 <= 100));
  __CPROVER_assume((pub_r000682_10_1 >= (-100)) && (pub_r000682_10_1 <= 100));
  __CPROVER_assume((pub_r000682_10_2 >= (-100)) && (pub_r000682_10_2 <= 100));
  __CPROVER_assume((pub_r000682_11_1 >= (-100)) && (pub_r000682_11_1 <= 100));
  __CPROVER_assume((pub_r000682_11_2 >= (-100)) && (pub_r000682_11_2 <= 100));
  __CPROVER_assume((pub_r000682_12_1 >= (-100)) && (pub_r000682_12_1 <= 100));
  __CPROVER_assume((pub_r000682_12_2 >= (-100)) && (pub_r000682_12_2 <= 100));
  __CPROVER_assume((pub_r000682_13_1 >= (-100)) && (pub_r000682_13_1 <= 100));
  __CPROVER_assume((pub_r000682_13_2 >= (-100)) && (pub_r000682_13_2 <= 100));
  __CPROVER_assume((pub_r000682_14_1 >= (-100)) && (pub_r000682_14_1 <= 100));
  __CPROVER_assume((pub_r000682_14_2 >= (-100)) && (pub_r000682_14_2 <= 100));
  __CPROVER_assume((pub_r000682_15_1 >= (-100)) && (pub_r000682_15_1 <= 100));
  __CPROVER_assume((pub_r000682_15_2 >= (-100)) && (pub_r000682_15_2 <= 100));
  __CPROVER_assume((sec_r000682_0_1 >= 0) && (sec_r000682_0_1 <= 255));
  __CPROVER_assume((sec_r000682_0_2 >= 0) && (sec_r000682_0_2 <= 255));
  __CPROVER_assume((sec_r000682_1_1 >= 0) && (sec_r000682_1_1 <= 255));
  __CPROVER_assume((sec_r000682_1_2 >= 0) && (sec_r000682_1_2 <= 255));
  __CPROVER_assume((sec_r000682_2_1 >= 0) && (sec_r000682_2_1 <= 255));
  __CPROVER_assume((sec_r000682_2_2 >= 0) && (sec_r000682_2_2 <= 255));
  __CPROVER_assume((sec_r000682_3_1 >= 0) && (sec_r000682_3_1 <= 255));
  __CPROVER_assume((sec_r000682_3_2 >= 0) && (sec_r000682_3_2 <= 255));
  __CPROVER_assume((sec_r000682_4_1 >= 0) && (sec_r000682_4_1 <= 255));
  __CPROVER_assume((sec_r000682_4_2 >= 0) && (sec_r000682_4_2 <= 255));
  __CPROVER_assume((sec_r000682_5_1 >= 0) && (sec_r000682_5_1 <= 255));
  __CPROVER_assume((sec_r000682_5_2 >= 0) && (sec_r000682_5_2 <= 255));
  __CPROVER_assume((sec_r000682_6_1 >= 0) && (sec_r000682_6_1 <= 255));
  __CPROVER_assume((sec_r000682_6_2 >= 0) && (sec_r000682_6_2 <= 255));
  __CPROVER_assume((sec_r000682_7_1 >= 0) && (sec_r000682_7_1 <= 255));
  __CPROVER_assume((sec_r000682_7_2 >= 0) && (sec_r000682_7_2 <= 255));
  __CPROVER_assume((sec_r000682_8_1 >= 0) && (sec_r000682_8_1 <= 255));
  __CPROVER_assume((sec_r000682_8_2 >= 0) && (sec_r000682_8_2 <= 255));
  __CPROVER_assume((sec_r000682_9_1 >= 0) && (sec_r000682_9_1 <= 255));
  __CPROVER_assume((sec_r000682_9_2 >= 0) && (sec_r000682_9_2 <= 255));
  __CPROVER_assume((sec_r000682_10_1 >= 0) && (sec_r000682_10_1 <= 255));
  __CPROVER_assume((sec_r000682_10_2 >= 0) && (sec_r000682_10_2 <= 255));
  __CPROVER_assume((sec_r000682_11_1 >= 0) && (sec_r000682_11_1 <= 255));
  __CPROVER_assume((sec_r000682_11_2 >= 0) && (sec_r000682_11_2 <= 255));
  __CPROVER_assume((sec_r000682_12_1 >= 0) && (sec_r000682_12_1 <= 255));
  __CPROVER_assume((sec_r000682_12_2 >= 0) && (sec_r000682_12_2 <= 255));
  __CPROVER_assume((sec_r000682_13_1 >= 0) && (sec_r000682_13_1 <= 255));
  __CPROVER_assume((sec_r000682_13_2 >= 0) && (sec_r000682_13_2 <= 255));
  __CPROVER_assume((sec_r000682_14_1 >= 0) && (sec_r000682_14_1 <= 255));
  __CPROVER_assume((sec_r000682_14_2 >= 0) && (sec_r000682_14_2 <= 255));
  __CPROVER_assume((sec_r000682_15_1 >= 0) && (sec_r000682_15_1 <= 255));
  __CPROVER_assume((sec_r000682_15_2 >= 0) && (sec_r000682_15_2 <= 255));
  __CPROVER_assume((sec_r000682_16_1 >= 0) && (sec_r000682_16_1 <= 255));
  __CPROVER_assume((sec_r000682_16_2 >= 0) && (sec_r000682_16_2 <= 255));
  __CPROVER_assume((sec_r000682_17_1 >= 0) && (sec_r000682_17_1 <= 255));
  __CPROVER_assume((sec_r000682_17_2 >= 0) && (sec_r000682_17_2 <= 255));
  __CPROVER_assume((sec_r000682_18_1 >= 0) && (sec_r000682_18_1 <= 255));
  __CPROVER_assume((sec_r000682_18_2 >= 0) && (sec_r000682_18_2 <= 255));
  struct StreamBuffer_R000682_8213_0 st_var_0_1 = {0};
  struct StreamBuffer_R000682_8213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000682_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000682_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000682_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000682_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000682_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000682_0_2 + 7) & 15;
  struct CipherContext_R000682_8213_1 st_var_1_1 = {0};
  struct CipherContext_R000682_8213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000682_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000682_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000682_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000682_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000682_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000682_0_2 + 9) & 15;
  struct EventLog_R000682_8213_2 st_var_2_1 = {0};
  struct EventLog_R000682_8213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000682_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000682_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000682_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000682_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000682_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000682_0_2 + 11) & 15;
  struct MatrixBlock_R000682_8213_3 st_var_3_1 = {0};
  struct MatrixBlock_R000682_8213_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000682_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000682_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000682_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000682_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000682_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000682_0_2 + 13) & 15;
  union ColorPixel_R000682_8213_0 u_var_1;
  union ColorPixel_R000682_8213_0 u_var_2;
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
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 43)
    {
      chk_sum_1 ^= stage_v_4_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_4_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 43)
    {
      chk_sum_2 ^= stage_v_4_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = ((st_var_2_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_2_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 26)
    {
      chk_sum_1 ^= stage_v_10_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_10_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 26)
    {
      chk_sum_2 ^= stage_v_10_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 12) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (st_var_3_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_3_2.buffer[0] ^ 18) & 3;
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

  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (st_var_1_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_1_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = (st_var_2_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_2_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 22) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
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
  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 38)
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
  if (stage_v_26_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 38)
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
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 30) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 30) & 15;
  int stage_v_29_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_29_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= stage_v_29_1;
  chk_sum_2 ^= stage_v_29_2;
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
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
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 34) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  int stage_v_35_1 = (st_var_3_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_3_2.buffer[0] ^ 38) & 3;
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

  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 39)
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
  if (stage_v_36_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 39)
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
  int stage_v_37_1 = (st_var_1_1.buffer[0] ^ 40) & 3;
  int stage_v_37_2 = (st_var_1_2.buffer[0] ^ 40) & 3;
  switch (stage_v_37_1)
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

  switch (stage_v_37_2)
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

  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
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
  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_43_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = ((st_var_3_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_3_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 50)
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
  if (stage_v_47_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 50)
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
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 42)
    {
      chk_sum_1 ^= stage_v_49_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_49_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 42)
    {
      chk_sum_2 ^= stage_v_49_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (56 & 31);
  int stage_v_51_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (56 & 31);
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= (stage_v_51_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_51_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 53) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((st_var_2_1.buffer[0] * 2) + 169) & 63;
  int stage_v_54_2 = ((st_var_2_2.buffer[0] * 2) + 169) & 63;
  if (stage_v_54_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 25)
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
  if (stage_v_54_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 25)
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
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_57_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_58_1 = (st_var_2_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_2_2.buffer[0] ^ 61) & 3;
  switch (stage_v_58_1)
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

  switch (stage_v_58_2)
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

  int stage_v_59_1 = ((st_var_3_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_3_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 49)
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
  if (stage_v_59_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 49)
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
  int stage_v_60_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (65 & 31);
  int stage_v_60_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (65 & 31);
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= (stage_v_60_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_60_2 << 1) & 127;
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
  int stage_v_63_1 = table_1[3];
  int stage_v_63_2 = table_2[3];
  table_1[3] = (table_1[0] + 127) & 63;
  table_2[3] = (table_2[0] + 127) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 65) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
  int stage_v_66_1 = (st_var_2_1.buffer[0] ^ 69) & 3;
  int stage_v_66_2 = (st_var_2_2.buffer[0] ^ 69) & 3;
  switch (stage_v_66_1)
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

  switch (stage_v_66_2)
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

  int stage_v_67_1 = (st_var_3_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_3_2.buffer[0] ^ 70) & 3;
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
  int stage_v_69_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_69_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_70_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_70_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 74) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 74) & 15;
  int stage_v_73_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_73_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= stage_v_73_1;
  chk_sum_2 ^= stage_v_73_2;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 76) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 76) & 15;
  int stage_v_75_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_75_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  chk_sum_1 ^= stage_v_75_1;
  chk_sum_2 ^= stage_v_75_2;
  int stage_v_76_1 = (st_var_0_1.buffer[0] ^ 79) & 3;
  int stage_v_76_2 = (st_var_0_2.buffer[0] ^ 79) & 3;
  switch (stage_v_76_1)
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

  switch (stage_v_76_2)
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

  int stage_v_77_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (82 & 31);
  int stage_v_77_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (82 & 31);
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= (stage_v_77_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_77_2 << 1) & 127;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_78_1 = ((stage_v_78_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_78_2 = ((stage_v_78_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 81) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 81) & 15;
  int stage_v_80_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_80_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= stage_v_80_1;
  chk_sum_2 ^= stage_v_80_2;
  int stage_v_81_1 = ((st_var_1_1.buffer[0] * 2) + 250) & 63;
  int stage_v_81_2 = ((st_var_1_2.buffer[0] * 2) + 250) & 63;
  if (stage_v_81_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_81_1) - 5) & 255;
    if (stage_v_81_1 > 50)
    {
      chk_sum_1 ^= stage_v_81_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_81_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_81_2) - 5) & 255;
    if (stage_v_81_2 > 50)
    {
      chk_sum_2 ^= stage_v_81_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_83_1 = ((stage_v_83_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_83_2 = ((stage_v_83_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 85) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 85) & 15;
  int stage_v_84_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_84_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  chk_sum_1 ^= stage_v_84_1;
  chk_sum_2 ^= stage_v_84_2;
  int stage_v_85_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_85_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_85_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_85_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_86_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (91 & 31);
  int stage_v_86_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (91 & 31);
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= (stage_v_86_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_86_2 << 1) & 127;
  int stage_v_87_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (92 & 31);
  int stage_v_87_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (92 & 31);
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  chk_sum_1 ^= (stage_v_87_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_87_2 << 1) & 127;
  int stage_v_88_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (93 & 31);
  int stage_v_88_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (93 & 31);
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= (stage_v_88_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_88_2 << 1) & 127;
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
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 91) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 91) & 15;
  int stage_v_90_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_90_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= stage_v_90_1;
  chk_sum_2 ^= stage_v_90_2;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_91_1 = ((stage_v_91_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_91_2 = ((stage_v_91_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (st_var_0_1.buffer[0] ^ 95) & 3;
  int stage_v_92_2 = (st_var_0_2.buffer[0] ^ 95) & 3;
  switch (stage_v_92_1)
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

  switch (stage_v_92_2)
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

  int stage_v_93_1 = table_1[1];
  int stage_v_93_2 = table_2[1];
  table_1[1] = (table_1[2] + 187) & 63;
  table_2[1] = (table_2[2] + 187) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_94_1 = ((stage_v_94_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_94_2 = ((stage_v_94_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (st_var_3_1.buffer[0] ^ 98) & 3;
  int stage_v_95_2 = (st_var_3_2.buffer[0] ^ 98) & 3;
  switch (stage_v_95_1)
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

  switch (stage_v_95_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 97) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 97) & 15;
  int stage_v_96_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_96_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  chk_sum_1 ^= stage_v_96_1;
  chk_sum_2 ^= stage_v_96_2;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_97_1 = ((stage_v_97_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_97_2 = ((stage_v_97_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (st_var_2_1.buffer[0] ^ 101) & 3;
  int stage_v_98_2 = (st_var_2_2.buffer[0] ^ 101) & 3;
  switch (stage_v_98_1)
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

  switch (stage_v_98_2)
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

  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_99_1 = ((stage_v_99_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_99_2 = ((stage_v_99_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
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
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 103) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 103) & 15;
  int stage_v_102_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_102_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  chk_sum_1 ^= stage_v_102_1;
  chk_sum_2 ^= stage_v_102_2;
  int stage_v_103_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (108 & 31);
  int stage_v_103_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (108 & 31);
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  chk_sum_1 ^= (stage_v_103_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_103_2 << 1) & 127;
  int stage_v_104_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_104_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_104_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_104_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_105_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (110 & 31);
  int stage_v_105_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (110 & 31);
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= (stage_v_105_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_105_2 << 1) & 127;
  int stage_v_106_1 = (st_var_2_1.buffer[0] ^ 109) & 3;
  int stage_v_106_2 = (st_var_2_2.buffer[0] ^ 109) & 3;
  switch (stage_v_106_1)
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

  switch (stage_v_106_2)
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

  int stage_v_107_1 = table_1[3];
  int stage_v_107_2 = table_2[3];
  table_1[3] = (table_1[0] + 215) & 63;
  table_2[3] = (table_2[0] + 215) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((st_var_0_1.buffer[0] * 2) + 331) & 63;
  int stage_v_108_2 = ((st_var_0_2.buffer[0] * 2) + 331) & 63;
  if (stage_v_108_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_108_1) - 5) & 255;
    if (stage_v_108_1 > 37)
    {
      chk_sum_1 ^= stage_v_108_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_108_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_108_2) - 5) & 255;
    if (stage_v_108_2 > 37)
    {
      chk_sum_2 ^= stage_v_108_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_109_1 = ((stage_v_109_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_109_2 = ((stage_v_109_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = table_1[2];
  int stage_v_110_2 = table_2[2];
  table_1[2] = (table_1[3] + 221) & 63;
  table_2[2] = (table_2[3] + 221) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (116 & 31);
  int stage_v_111_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (116 & 31);
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  chk_sum_1 ^= (stage_v_111_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_111_2 << 1) & 127;
  int stage_v_112_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (117 & 31);
  int stage_v_112_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (117 & 31);
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  chk_sum_1 ^= (stage_v_112_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_112_2 << 1) & 127;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_113_1 = ((stage_v_113_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_113_2 = ((stage_v_113_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = table_1[2];
  int stage_v_114_2 = table_2[2];
  table_1[2] = (table_1[3] + 229) & 63;
  table_2[2] = (table_2[3] + 229) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (st_var_0_1.buffer[0] ^ 119) & 3;
  int stage_v_116_2 = (st_var_0_2.buffer[0] ^ 119) & 3;
  switch (stage_v_116_1)
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

  switch (stage_v_116_2)
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

  int stage_v_117_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (122 & 31);
  int stage_v_117_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (122 & 31);
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  chk_sum_1 ^= (stage_v_117_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_117_2 << 1) & 127;
  int stage_v_118_1 = table_1[2];
  int stage_v_118_2 = table_2[2];
  table_1[2] = (table_1[3] + 237) & 63;
  table_2[2] = (table_2[3] + 237) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (124 & 31);
  int stage_v_119_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (124 & 31);
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  chk_sum_1 ^= (stage_v_119_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_119_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 121) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 121) & 15;
  int stage_v_120_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_120_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  chk_sum_1 ^= stage_v_120_1;
  chk_sum_2 ^= stage_v_120_2;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_121_1 = ((stage_v_121_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_121_2 = ((stage_v_121_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_122_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_122_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_122_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_123_1 = table_1[3];
  int stage_v_123_2 = table_2[3];
  table_1[3] = (table_1[0] + 247) & 63;
  table_2[3] = (table_2[0] + 247) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (129 & 31);
  int stage_v_124_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (129 & 31);
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  chk_sum_1 ^= (stage_v_124_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_124_2 << 1) & 127;
  int stage_v_125_1 = ((st_var_1_1.buffer[2] * 2) + 382) & 63;
  int stage_v_125_2 = ((st_var_1_2.buffer[2] * 2) + 382) & 63;
  if (stage_v_125_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_125_1) - 5) & 255;
    if (stage_v_125_1 > 52)
    {
      chk_sum_1 ^= stage_v_125_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_125_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_125_2) - 5) & 255;
    if (stage_v_125_2 > 52)
    {
      chk_sum_2 ^= stage_v_125_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 127) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 127) & 15;
  int stage_v_126_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_126_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  chk_sum_1 ^= stage_v_126_1;
  chk_sum_2 ^= stage_v_126_2;
  int stage_v_127_1 = (st_var_3_1.buffer[0] ^ 130) & 3;
  int stage_v_127_2 = (st_var_3_2.buffer[0] ^ 130) & 3;
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

  int stage_v_128_1 = ((st_var_0_1.buffer[2] * 2) + 391) & 63;
  int stage_v_128_2 = ((st_var_0_2.buffer[2] * 2) + 391) & 63;
  if (stage_v_128_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_128_1) - 5) & 255;
    if (stage_v_128_1 > 50)
    {
      chk_sum_1 ^= stage_v_128_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_128_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_128_2) - 5) & 255;
    if (stage_v_128_2 > 50)
    {
      chk_sum_2 ^= stage_v_128_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_129_1 = ((st_var_1_1.buffer[0] * 2) + 394) & 63;
  int stage_v_129_2 = ((st_var_1_2.buffer[0] * 2) + 394) & 63;
  if (stage_v_129_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_129_1) - 5) & 255;
    if (stage_v_129_1 > 46)
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
  if (stage_v_129_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_129_2) - 5) & 255;
    if (stage_v_129_2 > 46)
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
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 131) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 131) & 15;
  int stage_v_130_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_130_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= stage_v_130_1;
  chk_sum_2 ^= stage_v_130_2;
  int stage_v_131_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_131_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_131_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_131_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_132_1 = (st_var_0_1.buffer[0] ^ 135) & 3;
  int stage_v_132_2 = (st_var_0_2.buffer[0] ^ 135) & 3;
  switch (stage_v_132_1)
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

  switch (stage_v_132_2)
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

  int stage_v_133_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (138 & 31);
  int stage_v_133_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (138 & 31);
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  chk_sum_1 ^= (stage_v_133_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_133_2 << 1) & 127;
  int stage_v_134_1 = (st_var_2_1.buffer[0] ^ 137) & 3;
  int stage_v_134_2 = (st_var_2_2.buffer[0] ^ 137) & 3;
  switch (stage_v_134_1)
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

  switch (stage_v_134_2)
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

  int stage_v_135_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_135_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 137) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 137) & 15;
  int stage_v_136_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_136_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  chk_sum_1 ^= stage_v_136_1;
  chk_sum_2 ^= stage_v_136_2;
  int stage_v_137_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (142 & 31);
  int stage_v_137_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (142 & 31);
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  chk_sum_1 ^= (stage_v_137_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_137_2 << 1) & 127;
  int stage_v_138_1 = (st_var_2_1.buffer[0] ^ 141) & 3;
  int stage_v_138_2 = (st_var_2_2.buffer[0] ^ 141) & 3;
  switch (stage_v_138_1)
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

  switch (stage_v_138_2)
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

  int stage_v_139_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (144 & 31);
  int stage_v_139_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (144 & 31);
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  chk_sum_1 ^= (stage_v_139_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_139_2 << 1) & 127;
  int stage_v_140_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_140_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_140_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_140_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_141_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (146 & 31);
  int stage_v_141_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (146 & 31);
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= (stage_v_141_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_141_2 << 1) & 127;
  int stage_v_142_1 = (st_var_2_1.buffer[0] ^ 145) & 3;
  int stage_v_142_2 = (st_var_2_2.buffer[0] ^ 145) & 3;
  switch (stage_v_142_1)
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

  switch (stage_v_142_2)
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

  int stage_v_143_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (148 & 31);
  int stage_v_143_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (148 & 31);
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  chk_sum_1 ^= (stage_v_143_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_143_2 << 1) & 127;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_144_1 = ((stage_v_144_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (st_var_1_1.buffer[0] ^ 148) & 3;
  int stage_v_145_2 = (st_var_1_2.buffer[0] ^ 148) & 3;
  switch (stage_v_145_1)
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

  switch (stage_v_145_2)
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

  int stage_v_146_1 = ((st_var_2_1.buffer[2] * 2) + 445) & 63;
  int stage_v_146_2 = ((st_var_2_2.buffer[2] * 2) + 445) & 63;
  if (stage_v_146_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_146_1) - 5) & 255;
    if (stage_v_146_1 > 33)
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
  if (stage_v_146_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_146_2) - 5) & 255;
    if (stage_v_146_2 > 33)
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
  int stage_v_147_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_147_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_147_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_147_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_148_1 = (st_var_0_1.buffer[0] ^ 151) & 3;
  int stage_v_148_2 = (st_var_0_2.buffer[0] ^ 151) & 3;
  switch (stage_v_148_1)
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

  switch (stage_v_148_2)
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

  int stage_v_149_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_149_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_149_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_149_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_150_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_150_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_150_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_150_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 152) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 152) & 15;
  int stage_v_151_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_151_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  chk_sum_1 ^= stage_v_151_1;
  chk_sum_2 ^= stage_v_151_2;
  int stage_v_152_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_152_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 154) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 154) & 15;
  int stage_v_153_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_153_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  chk_sum_1 ^= stage_v_153_1;
  chk_sum_2 ^= stage_v_153_2;
  int stage_v_154_1 = table_1[2];
  int stage_v_154_2 = table_2[2];
  table_1[2] = (table_1[3] + 309) & 63;
  table_2[2] = (table_2[3] + 309) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (160 & 31);
  int stage_v_155_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (160 & 31);
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= (stage_v_155_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_155_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 157) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 157) & 15;
  int stage_v_156_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_156_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  chk_sum_1 ^= stage_v_156_1;
  chk_sum_2 ^= stage_v_156_2;
  int stage_v_157_1 = ((st_var_1_1.buffer[1] * 2) + 478) & 63;
  int stage_v_157_2 = ((st_var_1_2.buffer[1] * 2) + 478) & 63;
  if (stage_v_157_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_157_1) - 5) & 255;
    if (stage_v_157_1 > 54)
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
  if (stage_v_157_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_157_2) - 5) & 255;
    if (stage_v_157_2 > 54)
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
  int stage_v_158_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (163 & 31);
  int stage_v_158_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (163 & 31);
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  chk_sum_1 ^= (stage_v_158_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_158_2 << 1) & 127;
  int stage_v_159_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (164 & 31);
  int stage_v_159_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (164 & 31);
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  chk_sum_1 ^= (stage_v_159_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_159_2 << 1) & 127;
  int stage_v_160_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (165 & 31);
  int stage_v_160_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (165 & 31);
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  chk_sum_1 ^= (stage_v_160_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_160_2 << 1) & 127;
  int stage_v_161_1 = ((st_var_1_1.buffer[2] * 2) + 490) & 63;
  int stage_v_161_2 = ((st_var_1_2.buffer[2] * 2) + 490) & 63;
  if (stage_v_161_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_161_1) - 5) & 255;
    if (stage_v_161_1 > 33)
    {
      chk_sum_1 ^= stage_v_161_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_161_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_161_2) - 5) & 255;
    if (stage_v_161_2 > 33)
    {
      chk_sum_2 ^= stage_v_161_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_162_1 = table_1[2];
  int stage_v_162_2 = table_2[2];
  table_1[2] = (table_1[3] + 325) & 63;
  table_2[2] = (table_2[3] + 325) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 164) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 164) & 15;
  int stage_v_163_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_163_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  chk_sum_1 ^= stage_v_163_1;
  chk_sum_2 ^= stage_v_163_2;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_164_1 = ((stage_v_164_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_164_2 = ((stage_v_164_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((st_var_1_1.buffer[0] * 2) + 502) & 63;
  int stage_v_165_2 = ((st_var_1_2.buffer[0] * 2) + 502) & 63;
  if (stage_v_165_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_165_1) - 5) & 255;
    if (stage_v_165_1 > 38)
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
  if (stage_v_165_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_165_2) - 5) & 255;
    if (stage_v_165_2 > 38)
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
  if ((sec_r000682_18_1 & 1) != 0)
  {
    if ((sec_r000682_7_1 & 2) != 0)
    {
      out_sink_1 += 32;
    }
    else
    {
      out_sink_1 += 20;
    }
  }
  else
  {
    if ((sec_r000682_6_1 & 4) != 0)
    {
      out_sink_1 -= 19;
    }
    else
    {
      out_sink_1 -= 33;
    }
  }
  if ((sec_r000682_18_2 & 1) != 0)
  {
    if ((sec_r000682_7_2 & 2) != 0)
    {
      out_sink_2 += 32;
    }
    else
    {
      out_sink_2 += 20;
    }
  }
  else
  {
    if ((sec_r000682_6_2 & 4) != 0)
    {
      out_sink_2 -= 19;
    }
    else
    {
      out_sink_2 -= 33;
    }
  }
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000682_0_1 == pub_r000682_0_2);
  __CPROVER_assume(pub_r000682_12_1 == pub_r000682_12_2);
  __CPROVER_assume(sec_r000682_18_1 != sec_r000682_18_2);
  __CPROVER_assume(pub_r000682_3_1 == pub_r000682_3_2);
  __CPROVER_assume(pub_r000682_7_1 == pub_r000682_7_2);
  __CPROVER_assume(sec_r000682_16_1 != sec_r000682_16_2);
  __CPROVER_assume(sec_r000682_13_1 != sec_r000682_13_2);
  __CPROVER_assume(pub_r000682_8_1 == pub_r000682_8_2);
  __CPROVER_assume(sec_r000682_4_1 != sec_r000682_4_2);
  __CPROVER_assume(sec_r000682_9_1 != sec_r000682_9_2);
  __CPROVER_assume(sec_r000682_2_1 != sec_r000682_2_2);
  __CPROVER_assume(pub_r000682_13_1 == pub_r000682_13_2);
  __CPROVER_assume(sec_r000682_14_1 != sec_r000682_14_2);
  __CPROVER_assume(pub_r000682_6_1 == pub_r000682_6_2);
  __CPROVER_assume(sec_r000682_8_1 != sec_r000682_8_2);
  __CPROVER_assume(sec_r000682_10_1 != sec_r000682_10_2);
  __CPROVER_assume(sec_r000682_5_1 != sec_r000682_5_2);
  __CPROVER_assume(pub_r000682_5_1 == pub_r000682_5_2);
  __CPROVER_assume(sec_r000682_6_1 != sec_r000682_6_2);
  __CPROVER_assume(pub_r000682_11_1 == pub_r000682_11_2);
  __CPROVER_assume(pub_r000682_15_1 == pub_r000682_15_2);
  __CPROVER_assume(sec_r000682_12_1 != sec_r000682_12_2);
  __CPROVER_assume(pub_r000682_2_1 == pub_r000682_2_2);
  __CPROVER_assume(pub_r000682_1_1 == pub_r000682_1_2);
  __CPROVER_assume(pub_r000682_9_1 == pub_r000682_9_2);
  __CPROVER_assume(sec_r000682_1_1 != sec_r000682_1_2);
  __CPROVER_assume(sec_r000682_3_1 != sec_r000682_3_2);
  __CPROVER_assume(sec_r000682_11_1 != sec_r000682_11_2);
  __CPROVER_assume(pub_r000682_14_1 == pub_r000682_14_2);
  __CPROVER_assume(sec_r000682_7_1 != sec_r000682_7_2);
  __CPROVER_assume(sec_r000682_0_1 != sec_r000682_0_2);
  __CPROVER_assume(sec_r000682_17_1 != sec_r000682_17_2);
  __CPROVER_assume(sec_r000682_15_1 != sec_r000682_15_2);
  __CPROVER_assume(pub_r000682_4_1 == pub_r000682_4_2);
  __CPROVER_assume(pub_r000682_10_1 == pub_r000682_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.head == st_var_0_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.flags == st_var_1_2.flags);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.facility == st_var_2_2.facility);
  assert(st_var_2_1.signature == st_var_2_2.signature);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.code == st_var_2_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.determinant == st_var_3_2.determinant);
  assert(st_var_3_1.dim == st_var_3_2.dim);
  assert(st_var_3_1.scale == st_var_3_2.scale);
  assert(st_var_3_1.stride == st_var_3_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_3_1.buffer[i_buffer] == st_var_3_2.buffer[i_buffer]);
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
}


