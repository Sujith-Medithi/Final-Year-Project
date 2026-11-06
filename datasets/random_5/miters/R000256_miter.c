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
struct CipherContext_R000256_5613_0
{
  unsigned char tag;
  short nonce;
  short iv;
  short flags;
  int buffer[3];
};
struct Vector3D_R000256_5613_1
{
  short coord_z;
  short coord_x;
  unsigned char coord_y;
  unsigned char norm_sq;
  int buffer[3];
};
struct StreamBuffer_R000256_5613_2
{
  int watermark;
  int state;
  int checksum;
  int capacity;
  int head;
  int tail;
  int buffer[3];
};
struct MatrixBlock_R000256_5613_3
{
  int density;
  unsigned char determinant;
  int stride;
  int scale;
  short trace;
  int dim;
  int buffer[3];
};
union ColorPixel_R000256_5613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000256_5613_1
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
void fn_R000256_5613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000256_5613_2 st_1 = {0};
  struct StreamBuffer_R000256_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_56_1 > 21)
  {
    acc_1 = ((acc_1 + (tally_56_1 * 2)) + 5) & 127;
    aux_1 ^= tally_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_56_2 > 21)
  {
    acc_2 = ((acc_2 + (tally_56_2 * 2)) + 5) & 127;
    aux_2 ^= tally_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_56_1 == tally_56_2);
}

int fn_R000256_5613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000256_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_56 > 21)
  {
    acc = ((acc + (tally_56 * 2)) + 5) & 127;
    aux ^= tally_56 & 15;
  }
  else
  {
    acc = ((acc - tally_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000256_5613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000256_5613_3 st_1 = {0};
  struct MatrixBlock_R000256_5613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_17_1 = local_arr_1[aux_1 % 3];
  int damping_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_17_2 * 2)) & 127;
  int metric_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_39_1) & 63;
  aux_2 = (aux_2 + metric_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_20_1 > 32)
  {
    acc_1 = ((acc_1 + (vector_20_1 * 2)) + 5) & 127;
    aux_1 ^= vector_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_20_2 > 32)
  {
    acc_2 = ((acc_2 + (vector_20_2 * 2)) + 5) & 127;
    aux_2 ^= vector_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_17_1 == damping_17_2);
  assert(metric_39_1 == metric_39_2);
  assert(vector_20_1 == vector_20_2);
}

int fn_R000256_5613_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000256_5613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int damping_17 = local_arr[aux % 3];
  acc = (acc + (damping_17 * 2)) & 127;
  int metric_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_39) & 63;
  acc ^= aux;
  int vector_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_20 > 32)
  {
    acc = ((acc + (vector_20 * 2)) + 5) & 127;
    aux ^= vector_20 & 15;
  }
  else
  {
    acc = ((acc - vector_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000256_5613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000256_5613_3 st_1 = {0};
  struct MatrixBlock_R000256_5613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int scale_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_46_1) & 63;
  aux_2 = (aux_2 + scale_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_55_1 > 17)
  {
    acc_1 = ((acc_1 + (threshold_55_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_55_2 > 17)
  {
    acc_2 = ((acc_2 + (threshold_55_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_55_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_46_1 == scale_46_2);
  assert(threshold_55_1 == threshold_55_2);
}

int fn_R000256_5613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000256_5613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int scale_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_46) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_55 > 17)
  {
    acc = ((acc + (threshold_55 * 2)) + 5) & 127;
    aux ^= threshold_55 & 15;
  }
  else
  {
    acc = ((acc - threshold_55) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000256_5613_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000256_5613_3 st_1 = {0};
  struct MatrixBlock_R000256_5613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int parity_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_89_1)
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

  switch (parity_89_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_43_1 = local_arr_1[aux_1 % 3];
  int pivot_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_43_2 * 2)) & 127;
  int cursor_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_24_1 > 45)
  {
    acc_1 = ((acc_1 + (cursor_24_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_24_2 > 45)
  {
    acc_2 = ((acc_2 + (cursor_24_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_89_1 == parity_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_43_1 == pivot_43_2);
  assert(cursor_24_1 == cursor_24_2);
}

int fn_R000256_5613_3(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000256_5613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int parity_89 = (aux + st.buffer[1]) & 3;
  switch (parity_89)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_43 = local_arr[aux % 3];
  acc = (acc + (pivot_43 * 2)) & 127;
  int cursor_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_24 > 45)
  {
    acc = ((acc + (cursor_24 * 2)) + 5) & 127;
    aux ^= cursor_24 & 15;
  }
  else
  {
    acc = ((acc - cursor_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000256_5613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st_1 = {0};
  struct CipherContext_R000256_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_95_1 = local_arr_1[aux_1 % 3];
  int pivot_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_95_2 * 2)) & 127;
  int pivot_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_79_1)
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

  switch (pivot_79_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_95_1 == pivot_95_2);
  assert(pivot_79_1 == pivot_79_2);
}

int fn_R000256_5613_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int pivot_95 = local_arr[aux % 3];
  acc = (acc + (pivot_95 * 2)) & 127;
  int pivot_79 = (aux + st.buffer[1]) & 3;
  switch (pivot_79)
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

void fn_R000256_5613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000256_5613_2 st_1 = {0};
  struct StreamBuffer_R000256_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int mask_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_31_1)
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

  switch (mask_31_2)
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
  int residue_98_1 = local_arr_1[aux_1 % 3];
  int residue_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_98_2 * 2)) & 127;
  int weight_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_59_1 > 10)
  {
    acc_1 = ((acc_1 + (weight_59_1 * 2)) + 5) & 127;
    aux_1 ^= weight_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_59_2 > 10)
  {
    acc_2 = ((acc_2 + (weight_59_2 * 2)) + 5) & 127;
    aux_2 ^= weight_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_59_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_31_1 == mask_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_98_1 == residue_98_2);
  assert(weight_59_1 == weight_59_2);
}

int fn_R000256_5613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000256_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int mask_31 = (aux + st.buffer[1]) & 3;
  switch (mask_31)
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
  int residue_98 = local_arr[aux % 3];
  acc = (acc + (residue_98 * 2)) & 127;
  int weight_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_59 > 10)
  {
    acc = ((acc + (weight_59 * 2)) + 5) & 127;
    aux ^= weight_59 & 15;
  }
  else
  {
    acc = ((acc - weight_59) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000256_5613_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000256_5613_1 st_1 = {0};
  struct Vector3D_R000256_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_53_1 = local_arr_1[aux_1 % 3];
  int accumulator_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_53_2 * 2)) & 127;
  int weight_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_77_1) & 63;
  aux_2 = (aux_2 + weight_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_20_1 > 34)
  {
    acc_1 = ((acc_1 + (parity_20_1 * 2)) + 5) & 127;
    aux_1 ^= parity_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_20_2 > 34)
  {
    acc_2 = ((acc_2 + (parity_20_2 * 2)) + 5) & 127;
    aux_2 ^= parity_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_43_1)
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

  switch (offset_43_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_53_1 == accumulator_53_2);
  assert(weight_77_1 == weight_77_2);
  assert(parity_20_1 == parity_20_2);
  assert(offset_43_1 == offset_43_2);
}

int fn_R000256_5613_6(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000256_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int accumulator_53 = local_arr[aux % 3];
  acc = (acc + (accumulator_53 * 2)) & 127;
  int weight_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_77) & 63;
  acc ^= aux;
  int parity_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_20 > 34)
  {
    acc = ((acc + (parity_20 * 2)) + 5) & 127;
    aux ^= parity_20 & 15;
  }
  else
  {
    acc = ((acc - parity_20) + 11) & 127;
    aux += 3;
  }
  int offset_43 = (aux + st.buffer[1]) & 3;
  switch (offset_43)
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

void fn_R000256_5613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st_1 = {0};
  struct CipherContext_R000256_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_98_1 = local_arr_1[aux_1 % 3];
  int phase_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_98_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_98_1 == phase_98_2);
}

int fn_R000256_5613_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_98 = local_arr[aux % 3];
  acc = (acc + (phase_98 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000256_5613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000256_5613_2 st_1 = {0};
  struct StreamBuffer_R000256_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_33_1 = local_arr_1[aux_1 % 3];
  int phase_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_33_2 * 2)) & 127;
  int vector_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_56_1 > 38)
  {
    acc_1 = ((acc_1 + (vector_56_1 * 2)) + 5) & 127;
    aux_1 ^= vector_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_56_2 > 38)
  {
    acc_2 = ((acc_2 + (vector_56_2 * 2)) + 5) & 127;
    aux_2 ^= vector_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_33_1 == phase_33_2);
  assert(vector_56_1 == vector_56_2);
}

int fn_R000256_5613_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000256_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_33 = local_arr[aux % 3];
  acc = (acc + (phase_33 * 2)) & 127;
  int vector_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_56 > 38)
  {
    acc = ((acc + (vector_56 * 2)) + 5) & 127;
    aux ^= vector_56 & 15;
  }
  else
  {
    acc = ((acc - vector_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000256_5613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000256_5613_2 st_1 = {0};
  struct StreamBuffer_R000256_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int stride_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_64_1)
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

  switch (stride_64_2)
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

  int accumulator_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_48_1 > 35)
  {
    acc_1 = ((acc_1 + (accumulator_48_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_48_2 > 35)
  {
    acc_2 = ((acc_2 + (accumulator_48_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_34_1 = local_arr_1[aux_1 % 3];
  int segment_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_34_2 * 2)) & 127;
  int residue_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_97_1) & 63;
  aux_2 = (aux_2 + residue_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_64_1 == stride_64_2);
  assert(accumulator_48_1 == accumulator_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_34_1 == segment_34_2);
  assert(residue_97_1 == residue_97_2);
}

int fn_R000256_5613_9(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000256_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int stride_64 = (aux + st.buffer[1]) & 3;
  switch (stride_64)
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

  int accumulator_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_48 > 35)
  {
    acc = ((acc + (accumulator_48 * 2)) + 5) & 127;
    aux ^= accumulator_48 & 15;
  }
  else
  {
    acc = ((acc - accumulator_48) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_34 = local_arr[aux % 3];
  acc = (acc + (segment_34 * 2)) & 127;
  int residue_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000256_5613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000256_5613_3 st_1 = {0};
  struct MatrixBlock_R000256_5613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int phase_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_36_1) & 63;
  aux_2 = (aux_2 + phase_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_61_1 = local_arr_1[aux_1 % 3];
  int cursor_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_61_2 * 2)) & 127;
  int pivot_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_12_1 > 29)
  {
    acc_1 = ((acc_1 + (pivot_12_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_12_2 > 29)
  {
    acc_2 = ((acc_2 + (pivot_12_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_36_1 == phase_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_61_1 == cursor_61_2);
  assert(pivot_12_1 == pivot_12_2);
}

int fn_R000256_5613_10(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000256_5613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int phase_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_36) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_61 = local_arr[aux % 3];
  acc = (acc + (cursor_61 * 2)) & 127;
  int pivot_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_12 > 29)
  {
    acc = ((acc + (pivot_12 * 2)) + 5) & 127;
    aux ^= pivot_12 & 15;
  }
  else
  {
    acc = ((acc - pivot_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000256_5613_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st_1 = {0};
  struct CipherContext_R000256_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int checksum_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_25_1) & 63;
  aux_2 = (aux_2 + checksum_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_89_1 = local_arr_1[aux_1 % 3];
  int margin_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_89_2 * 2)) & 127;
  int anchor_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_58_1 > 38)
  {
    acc_1 = ((acc_1 + (anchor_58_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_58_2 > 38)
  {
    acc_2 = ((acc_2 + (anchor_58_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_25_1 == checksum_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_89_1 == margin_89_2);
  assert(anchor_58_1 == anchor_58_2);
}

int fn_R000256_5613_11(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int checksum_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_25) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_89 = local_arr[aux % 3];
  acc = (acc + (margin_89 * 2)) & 127;
  int anchor_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_58 > 38)
  {
    acc = ((acc + (anchor_58 * 2)) + 5) & 127;
    aux ^= anchor_58 & 15;
  }
  else
  {
    acc = ((acc - anchor_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000256_5613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000256_5613_1 st_1 = {0};
  struct Vector3D_R000256_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int accumulator_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_74_1 > 44)
  {
    acc_1 = ((acc_1 + (accumulator_74_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_74_2 > 44)
  {
    acc_2 = ((acc_2 + (accumulator_74_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_38_1) & 63;
  aux_2 = (aux_2 + quantum_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_74_1 == accumulator_74_2);
  assert(quantum_38_1 == quantum_38_2);
}

int fn_R000256_5613_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000256_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int accumulator_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_74 > 44)
  {
    acc = ((acc + (accumulator_74 * 2)) + 5) & 127;
    aux ^= accumulator_74 & 15;
  }
  else
  {
    acc = ((acc - accumulator_74) + 11) & 127;
    aux += 3;
  }
  int quantum_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000256_5613_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st_1 = {0};
  struct CipherContext_R000256_5613_0 st_2 = {0};
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
  int parity_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_80_1) & 63;
  aux_2 = (aux_2 + parity_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_84_1)
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

  switch (pivot_84_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_80_1 == parity_80_2);
  assert(pivot_84_1 == pivot_84_2);
}

int fn_R000256_5613_13(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_80) & 63;
  acc ^= aux;
  int pivot_84 = (aux + st.buffer[1]) & 3;
  switch (pivot_84)
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

void fn_R000256_5613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st_1 = {0};
  struct CipherContext_R000256_5613_0 st_2 = {0};
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
  int bound_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_44_1)
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

  switch (bound_44_2)
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

  int residue_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_43_1 > 48)
  {
    acc_1 = ((acc_1 + (residue_43_1 * 2)) + 5) & 127;
    aux_1 ^= residue_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_43_2 > 48)
  {
    acc_2 = ((acc_2 + (residue_43_2 * 2)) + 5) & 127;
    aux_2 ^= residue_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_14_1 = local_arr_1[aux_1 % 3];
  int metric_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_14_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_44_1 == bound_44_2);
  assert(residue_43_1 == residue_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_14_1 == metric_14_2);
}

int fn_R000256_5613_14(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_44 = (aux + st.buffer[1]) & 3;
  switch (bound_44)
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

  int residue_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_43 > 48)
  {
    acc = ((acc + (residue_43 * 2)) + 5) & 127;
    aux ^= residue_43 & 15;
  }
  else
  {
    acc = ((acc - residue_43) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_14 = local_arr[aux % 3];
  acc = (acc + (metric_14 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000256_5613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st_1 = {0};
  struct CipherContext_R000256_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int bound_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_69_1 > 17)
  {
    acc_1 = ((acc_1 + (bound_69_1 * 2)) + 5) & 127;
    aux_1 ^= bound_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_69_2 > 17)
  {
    acc_2 = ((acc_2 + (bound_69_2 * 2)) + 5) & 127;
    aux_2 ^= bound_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_69_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_69_1 == bound_69_2);
}

int fn_R000256_5613_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int bound_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_69 > 17)
  {
    acc = ((acc + (bound_69 * 2)) + 5) & 127;
    aux ^= bound_69 & 15;
  }
  else
  {
    acc = ((acc - bound_69) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000256_5613_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000256_5613_3 st_1 = {0};
  struct MatrixBlock_R000256_5613_3 st_2 = {0};
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
  int offset_81_1 = local_arr_1[aux_1 % 3];
  int offset_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_81_1 == offset_81_2);
}

int fn_R000256_5613_16(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000256_5613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_81 = local_arr[aux % 3];
  acc = (acc + (offset_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000256_5613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st_1 = {0};
  struct CipherContext_R000256_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_99_1 = local_arr_1[aux_1 % 3];
  int accumulator_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_99_2 * 2)) & 127;
  int mask_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_33_1)
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

  switch (mask_33_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_99_1 == accumulator_99_2);
  assert(mask_33_1 == mask_33_2);
}

int fn_R000256_5613_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000256_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int accumulator_99 = local_arr[aux % 3];
  acc = (acc + (accumulator_99 * 2)) & 127;
  int mask_33 = (aux + st.buffer[1]) & 3;
  switch (mask_33)
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

void fn_R000256_5613_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000256_5613_1 st_1 = {0};
  struct Vector3D_R000256_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int factor_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_75_1)
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

  switch (factor_75_2)
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

  int margin_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_94_1 > 44)
  {
    acc_1 = ((acc_1 + (margin_94_1 * 2)) + 5) & 127;
    aux_1 ^= margin_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_94_2 > 44)
  {
    acc_2 = ((acc_2 + (margin_94_2 * 2)) + 5) & 127;
    aux_2 ^= margin_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_48_1 = local_arr_1[aux_1 % 3];
  int offset_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_48_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_75_1 == factor_75_2);
  assert(margin_94_1 == margin_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_48_1 == offset_48_2);
}

int fn_R000256_5613_18(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000256_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int factor_75 = (aux + st.buffer[1]) & 3;
  switch (factor_75)
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

  int margin_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_94 > 44)
  {
    acc = ((acc + (margin_94 * 2)) + 5) & 127;
    aux ^= margin_94 & 15;
  }
  else
  {
    acc = ((acc - margin_94) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_48 = local_arr[aux % 3];
  acc = (acc + (offset_48 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000256_5613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000256_5613_2 st_1 = {0};
  struct StreamBuffer_R000256_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int damping_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_70_1)
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

  switch (damping_70_2)
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
  int mask_38_1 = local_arr_1[aux_1 % 3];
  int mask_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_38_2 * 2)) & 127;
  int threshold_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_33_1) & 63;
  aux_2 = (aux_2 + threshold_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_70_1 == damping_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_38_1 == mask_38_2);
  assert(threshold_33_1 == threshold_33_2);
}

int fn_R000256_5613_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000256_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int damping_70 = (aux + st.buffer[1]) & 3;
  switch (damping_70)
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
  int mask_38 = local_arr[aux % 3];
  acc = (acc + (mask_38 * 2)) & 127;
  int threshold_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_33) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000256_5613_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000256_5613_2 st_1 = {0};
  struct StreamBuffer_R000256_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int phase_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_85_1 > 20)
  {
    acc_1 = ((acc_1 + (phase_85_1 * 2)) + 5) & 127;
    aux_1 ^= phase_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_85_2 > 20)
  {
    acc_2 = ((acc_2 + (phase_85_2 * 2)) + 5) & 127;
    aux_2 ^= phase_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_62_1)
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

  switch (quotient_62_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_85_1 == phase_85_2);
  assert(quotient_62_1 == quotient_62_2);
}

int fn_R000256_5613_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000256_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int phase_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_85 > 20)
  {
    acc = ((acc + (phase_85 * 2)) + 5) & 127;
    aux ^= phase_85 & 15;
  }
  else
  {
    acc = ((acc - phase_85) + 11) & 127;
    aux += 3;
  }
  int quotient_62 = (aux + st.buffer[1]) & 3;
  switch (quotient_62)
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

void main()
{
  int sec_r000256_0_1;
  int sec_r000256_0_2;
  int sec_r000256_1_1;
  int sec_r000256_1_2;
  int sec_r000256_2_1;
  int sec_r000256_2_2;
  int sec_r000256_3_1;
  int sec_r000256_3_2;
  int sec_r000256_4_1;
  int sec_r000256_4_2;
  int sec_r000256_5_1;
  int sec_r000256_5_2;
  int sec_r000256_6_1;
  int sec_r000256_6_2;
  int sec_r000256_7_1;
  int sec_r000256_7_2;
  int sec_r000256_8_1;
  int sec_r000256_8_2;
  int sec_r000256_9_1;
  int sec_r000256_9_2;
  int sec_r000256_10_1;
  int sec_r000256_10_2;
  int sec_r000256_11_1;
  int sec_r000256_11_2;
  int sec_r000256_12_1;
  int sec_r000256_12_2;
  int sec_r000256_13_1;
  int sec_r000256_13_2;
  int sec_r000256_14_1;
  int sec_r000256_14_2;
  int sec_r000256_15_1;
  int sec_r000256_15_2;
  int sec_r000256_16_1;
  int sec_r000256_16_2;
  int sec_r000256_17_1;
  int sec_r000256_17_2;
  int pub_r000256_0_1;
  int pub_r000256_0_2;
  int pub_r000256_1_1;
  int pub_r000256_1_2;
  int pub_r000256_2_1;
  int pub_r000256_2_2;
  int pub_r000256_3_1;
  int pub_r000256_3_2;
  int pub_r000256_4_1;
  int pub_r000256_4_2;
  int pub_r000256_5_1;
  int pub_r000256_5_2;
  int pub_r000256_6_1;
  int pub_r000256_6_2;
  int pub_r000256_7_1;
  int pub_r000256_7_2;
  int pub_r000256_8_1;
  int pub_r000256_8_2;
  int pub_r000256_9_1;
  int pub_r000256_9_2;
  int pub_r000256_10_1;
  int pub_r000256_10_2;
  int pub_r000256_11_1;
  int pub_r000256_11_2;
  int pub_r000256_12_1;
  int pub_r000256_12_2;
  int pub_r000256_13_1;
  int pub_r000256_13_2;
  int pub_r000256_14_1;
  int pub_r000256_14_2;
  int pub_r000256_15_1;
  int pub_r000256_15_2;
  int pub_r000256_16_1;
  int pub_r000256_16_2;
  int pub_r000256_17_1;
  int pub_r000256_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000256_0_1 >= (-100)) && (pub_r000256_0_1 <= 100));
  __CPROVER_assume((pub_r000256_0_2 >= (-100)) && (pub_r000256_0_2 <= 100));
  __CPROVER_assume((pub_r000256_1_1 >= (-100)) && (pub_r000256_1_1 <= 100));
  __CPROVER_assume((pub_r000256_1_2 >= (-100)) && (pub_r000256_1_2 <= 100));
  __CPROVER_assume((pub_r000256_2_1 >= (-100)) && (pub_r000256_2_1 <= 100));
  __CPROVER_assume((pub_r000256_2_2 >= (-100)) && (pub_r000256_2_2 <= 100));
  __CPROVER_assume((pub_r000256_3_1 >= (-100)) && (pub_r000256_3_1 <= 100));
  __CPROVER_assume((pub_r000256_3_2 >= (-100)) && (pub_r000256_3_2 <= 100));
  __CPROVER_assume((pub_r000256_4_1 >= (-100)) && (pub_r000256_4_1 <= 100));
  __CPROVER_assume((pub_r000256_4_2 >= (-100)) && (pub_r000256_4_2 <= 100));
  __CPROVER_assume((pub_r000256_5_1 >= (-100)) && (pub_r000256_5_1 <= 100));
  __CPROVER_assume((pub_r000256_5_2 >= (-100)) && (pub_r000256_5_2 <= 100));
  __CPROVER_assume((pub_r000256_6_1 >= (-100)) && (pub_r000256_6_1 <= 100));
  __CPROVER_assume((pub_r000256_6_2 >= (-100)) && (pub_r000256_6_2 <= 100));
  __CPROVER_assume((pub_r000256_7_1 >= (-100)) && (pub_r000256_7_1 <= 100));
  __CPROVER_assume((pub_r000256_7_2 >= (-100)) && (pub_r000256_7_2 <= 100));
  __CPROVER_assume((pub_r000256_8_1 >= (-100)) && (pub_r000256_8_1 <= 100));
  __CPROVER_assume((pub_r000256_8_2 >= (-100)) && (pub_r000256_8_2 <= 100));
  __CPROVER_assume((pub_r000256_9_1 >= (-100)) && (pub_r000256_9_1 <= 100));
  __CPROVER_assume((pub_r000256_9_2 >= (-100)) && (pub_r000256_9_2 <= 100));
  __CPROVER_assume((pub_r000256_10_1 >= (-100)) && (pub_r000256_10_1 <= 100));
  __CPROVER_assume((pub_r000256_10_2 >= (-100)) && (pub_r000256_10_2 <= 100));
  __CPROVER_assume((pub_r000256_11_1 >= (-100)) && (pub_r000256_11_1 <= 100));
  __CPROVER_assume((pub_r000256_11_2 >= (-100)) && (pub_r000256_11_2 <= 100));
  __CPROVER_assume((pub_r000256_12_1 >= (-100)) && (pub_r000256_12_1 <= 100));
  __CPROVER_assume((pub_r000256_12_2 >= (-100)) && (pub_r000256_12_2 <= 100));
  __CPROVER_assume((pub_r000256_13_1 >= (-100)) && (pub_r000256_13_1 <= 100));
  __CPROVER_assume((pub_r000256_13_2 >= (-100)) && (pub_r000256_13_2 <= 100));
  __CPROVER_assume((pub_r000256_14_1 >= (-100)) && (pub_r000256_14_1 <= 100));
  __CPROVER_assume((pub_r000256_14_2 >= (-100)) && (pub_r000256_14_2 <= 100));
  __CPROVER_assume((pub_r000256_15_1 >= (-100)) && (pub_r000256_15_1 <= 100));
  __CPROVER_assume((pub_r000256_15_2 >= (-100)) && (pub_r000256_15_2 <= 100));
  __CPROVER_assume((pub_r000256_16_1 >= (-100)) && (pub_r000256_16_1 <= 100));
  __CPROVER_assume((pub_r000256_16_2 >= (-100)) && (pub_r000256_16_2 <= 100));
  __CPROVER_assume((pub_r000256_17_1 >= (-100)) && (pub_r000256_17_1 <= 100));
  __CPROVER_assume((pub_r000256_17_2 >= (-100)) && (pub_r000256_17_2 <= 100));
  __CPROVER_assume((sec_r000256_0_1 >= 0) && (sec_r000256_0_1 <= 255));
  __CPROVER_assume((sec_r000256_0_2 >= 0) && (sec_r000256_0_2 <= 255));
  __CPROVER_assume((sec_r000256_1_1 >= 0) && (sec_r000256_1_1 <= 255));
  __CPROVER_assume((sec_r000256_1_2 >= 0) && (sec_r000256_1_2 <= 255));
  __CPROVER_assume((sec_r000256_2_1 >= 0) && (sec_r000256_2_1 <= 255));
  __CPROVER_assume((sec_r000256_2_2 >= 0) && (sec_r000256_2_2 <= 255));
  __CPROVER_assume((sec_r000256_3_1 >= 0) && (sec_r000256_3_1 <= 255));
  __CPROVER_assume((sec_r000256_3_2 >= 0) && (sec_r000256_3_2 <= 255));
  __CPROVER_assume((sec_r000256_4_1 >= 0) && (sec_r000256_4_1 <= 255));
  __CPROVER_assume((sec_r000256_4_2 >= 0) && (sec_r000256_4_2 <= 255));
  __CPROVER_assume((sec_r000256_5_1 >= 0) && (sec_r000256_5_1 <= 255));
  __CPROVER_assume((sec_r000256_5_2 >= 0) && (sec_r000256_5_2 <= 255));
  __CPROVER_assume((sec_r000256_6_1 >= 0) && (sec_r000256_6_1 <= 255));
  __CPROVER_assume((sec_r000256_6_2 >= 0) && (sec_r000256_6_2 <= 255));
  __CPROVER_assume((sec_r000256_7_1 >= 0) && (sec_r000256_7_1 <= 255));
  __CPROVER_assume((sec_r000256_7_2 >= 0) && (sec_r000256_7_2 <= 255));
  __CPROVER_assume((sec_r000256_8_1 >= 0) && (sec_r000256_8_1 <= 255));
  __CPROVER_assume((sec_r000256_8_2 >= 0) && (sec_r000256_8_2 <= 255));
  __CPROVER_assume((sec_r000256_9_1 >= 0) && (sec_r000256_9_1 <= 255));
  __CPROVER_assume((sec_r000256_9_2 >= 0) && (sec_r000256_9_2 <= 255));
  __CPROVER_assume((sec_r000256_10_1 >= 0) && (sec_r000256_10_1 <= 255));
  __CPROVER_assume((sec_r000256_10_2 >= 0) && (sec_r000256_10_2 <= 255));
  __CPROVER_assume((sec_r000256_11_1 >= 0) && (sec_r000256_11_1 <= 255));
  __CPROVER_assume((sec_r000256_11_2 >= 0) && (sec_r000256_11_2 <= 255));
  __CPROVER_assume((sec_r000256_12_1 >= 0) && (sec_r000256_12_1 <= 255));
  __CPROVER_assume((sec_r000256_12_2 >= 0) && (sec_r000256_12_2 <= 255));
  __CPROVER_assume((sec_r000256_13_1 >= 0) && (sec_r000256_13_1 <= 255));
  __CPROVER_assume((sec_r000256_13_2 >= 0) && (sec_r000256_13_2 <= 255));
  __CPROVER_assume((sec_r000256_14_1 >= 0) && (sec_r000256_14_1 <= 255));
  __CPROVER_assume((sec_r000256_14_2 >= 0) && (sec_r000256_14_2 <= 255));
  __CPROVER_assume((sec_r000256_15_1 >= 0) && (sec_r000256_15_1 <= 255));
  __CPROVER_assume((sec_r000256_15_2 >= 0) && (sec_r000256_15_2 <= 255));
  __CPROVER_assume((sec_r000256_16_1 >= 0) && (sec_r000256_16_1 <= 255));
  __CPROVER_assume((sec_r000256_16_2 >= 0) && (sec_r000256_16_2 <= 255));
  __CPROVER_assume((sec_r000256_17_1 >= 0) && (sec_r000256_17_1 <= 255));
  __CPROVER_assume((sec_r000256_17_2 >= 0) && (sec_r000256_17_2 <= 255));
  struct CipherContext_R000256_5613_0 st_var_0_1 = {0};
  struct CipherContext_R000256_5613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000256_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000256_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000256_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000256_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000256_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000256_0_2 + 7) & 15;
  struct Vector3D_R000256_5613_1 st_var_1_1 = {0};
  struct Vector3D_R000256_5613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000256_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000256_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000256_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000256_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000256_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000256_0_2 + 9) & 15;
  struct StreamBuffer_R000256_5613_2 st_var_2_1 = {0};
  struct StreamBuffer_R000256_5613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000256_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000256_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000256_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000256_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000256_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000256_0_2 + 11) & 15;
  struct MatrixBlock_R000256_5613_3 st_var_3_1 = {0};
  struct MatrixBlock_R000256_5613_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000256_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000256_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000256_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000256_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000256_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000256_0_2 + 13) & 15;
  union ColorPixel_R000256_5613_0 u_var_1;
  union ColorPixel_R000256_5613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = ((st_var_3_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_3_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 32)
    {
      chk_sum_1 ^= stage_v_3_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_3_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 32)
    {
      chk_sum_2 ^= stage_v_3_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 47)
    {
      chk_sum_1 ^= stage_v_8_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_8_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 47)
    {
      chk_sum_2 ^= stage_v_8_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 12) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 32)
    {
      chk_sum_1 ^= stage_v_14_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_14_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 32)
    {
      chk_sum_2 ^= stage_v_14_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = ((st_var_2_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_2_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 37)
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
  if (stage_v_18_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 37)
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
  int stage_v_19_1 = (st_var_3_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_3_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  if ((sec_r000256_6_1 & 63) > 31)
  {
    stage_v_20_1 = ((pub_r000256_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  }
  else
  {
    stage_v_20_1 = ((pub_r000256_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
  }
  if ((sec_r000256_6_2 & 63) > 31)
  {
    stage_v_20_2 = ((pub_r000256_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  }
  else
  {
    stage_v_20_2 = ((pub_r000256_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  if ((stage_v_20_1 & 63) > 21)
  {
    stage_v_21_1 = ((pub_r000256_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  }
  else
  {
    stage_v_21_1 = ((pub_r000256_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
  }
  if ((stage_v_20_2 & 63) > 21)
  {
    stage_v_21_2 = ((pub_r000256_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  }
  else
  {
    stage_v_21_2 = ((pub_r000256_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  if ((sec_r000256_2_1 & 63) > 32)
  {
    stage_v_22_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  }
  else
  {
    stage_v_22_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
  }
  if ((sec_r000256_2_2 & 63) > 32)
  {
    stage_v_22_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  }
  else
  {
    stage_v_22_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  if ((stage_v_20_1 & 63) > 36)
  {
    stage_v_23_1 = ((pub_r000256_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  }
  else
  {
    stage_v_23_1 = ((pub_r000256_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
  }
  if ((stage_v_20_2 & 63) > 36)
  {
    stage_v_23_2 = ((pub_r000256_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  }
  else
  {
    stage_v_23_2 = ((pub_r000256_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  if ((stage_v_21_1 & 63) > 58)
  {
    stage_v_24_1 = ((pub_r000256_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  }
  else
  {
    stage_v_24_1 = ((pub_r000256_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
  }
  if ((stage_v_21_2 & 63) > 58)
  {
    stage_v_24_2 = ((pub_r000256_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  }
  else
  {
    stage_v_24_2 = ((pub_r000256_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((stage_v_24_1 & 63) > 58)
  {
    stage_v_25_1 = ((pub_r000256_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  }
  else
  {
    stage_v_25_1 = ((pub_r000256_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
  }
  if ((stage_v_24_2 & 63) > 58)
  {
    stage_v_25_2 = ((pub_r000256_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  }
  else
  {
    stage_v_25_2 = ((pub_r000256_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((stage_v_22_1 & 63) > 27)
  {
    stage_v_26_1 = ((pub_r000256_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  }
  else
  {
    stage_v_26_1 = ((pub_r000256_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
  }
  if ((stage_v_22_2 & 63) > 27)
  {
    stage_v_26_2 = ((pub_r000256_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  }
  else
  {
    stage_v_26_2 = ((pub_r000256_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((stage_v_23_1 & 63) > 25)
  {
    stage_v_27_1 = ((pub_r000256_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  }
  else
  {
    stage_v_27_1 = ((pub_r000256_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
  }
  if ((stage_v_23_2 & 63) > 25)
  {
    stage_v_27_2 = ((pub_r000256_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  }
  else
  {
    stage_v_27_2 = ((pub_r000256_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((stage_v_23_1 & 63) > 55)
  {
    stage_v_28_1 = ((pub_r000256_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  }
  else
  {
    stage_v_28_1 = ((pub_r000256_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
  }
  if ((stage_v_23_2 & 63) > 55)
  {
    stage_v_28_2 = ((pub_r000256_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  }
  else
  {
    stage_v_28_2 = ((pub_r000256_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((sec_r000256_9_1 & 63) > 34)
  {
    stage_v_29_1 = ((pub_r000256_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  }
  else
  {
    stage_v_29_1 = ((pub_r000256_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
  }
  if ((sec_r000256_9_2 & 63) > 34)
  {
    stage_v_29_2 = ((pub_r000256_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  }
  else
  {
    stage_v_29_2 = ((pub_r000256_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((stage_v_27_1 & 63) > 29)
  {
    stage_v_30_1 = ((pub_r000256_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  }
  else
  {
    stage_v_30_1 = ((pub_r000256_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
  }
  if ((stage_v_27_2 & 63) > 29)
  {
    stage_v_30_2 = ((pub_r000256_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  }
  else
  {
    stage_v_30_2 = ((pub_r000256_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((stage_v_25_1 & 63) > 37)
  {
    stage_v_31_1 = ((pub_r000256_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  }
  else
  {
    stage_v_31_1 = ((pub_r000256_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
  }
  if ((stage_v_25_2 & 63) > 37)
  {
    stage_v_31_2 = ((pub_r000256_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  }
  else
  {
    stage_v_31_2 = ((pub_r000256_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((stage_v_31_1 & 63) > 58)
  {
    stage_v_32_1 = ((pub_r000256_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  }
  else
  {
    stage_v_32_1 = ((pub_r000256_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
  }
  if ((stage_v_31_2 & 63) > 58)
  {
    stage_v_32_2 = ((pub_r000256_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  }
  else
  {
    stage_v_32_2 = ((pub_r000256_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((stage_v_27_1 & 63) > 18)
  {
    stage_v_33_1 = ((pub_r000256_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  }
  else
  {
    stage_v_33_1 = ((pub_r000256_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
  }
  if ((stage_v_27_2 & 63) > 18)
  {
    stage_v_33_2 = ((pub_r000256_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  }
  else
  {
    stage_v_33_2 = ((pub_r000256_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((stage_v_27_1 & 63) > 38)
  {
    stage_v_34_1 = ((pub_r000256_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  }
  else
  {
    stage_v_34_1 = ((pub_r000256_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
  }
  if ((stage_v_27_2 & 63) > 38)
  {
    stage_v_34_2 = ((pub_r000256_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  }
  else
  {
    stage_v_34_2 = ((pub_r000256_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((stage_v_22_1 & 63) > 45)
  {
    stage_v_35_1 = ((pub_r000256_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  }
  else
  {
    stage_v_35_1 = ((pub_r000256_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
  }
  if ((stage_v_22_2 & 63) > 45)
  {
    stage_v_35_2 = ((pub_r000256_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  }
  else
  {
    stage_v_35_2 = ((pub_r000256_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_35_1 & 63) > 22)
  {
    stage_v_36_1 = ((pub_r000256_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  }
  else
  {
    stage_v_36_1 = ((pub_r000256_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
  }
  if ((stage_v_35_2 & 63) > 22)
  {
    stage_v_36_2 = ((pub_r000256_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  }
  else
  {
    stage_v_36_2 = ((pub_r000256_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((sec_r000256_4_1 & 63) > 53)
  {
    stage_v_37_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  }
  else
  {
    stage_v_37_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
  }
  if ((sec_r000256_4_2 & 63) > 53)
  {
    stage_v_37_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  }
  else
  {
    stage_v_37_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((stage_v_37_1 & 63) > 30)
  {
    stage_v_38_1 = ((pub_r000256_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  }
  else
  {
    stage_v_38_1 = ((pub_r000256_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
  }
  if ((stage_v_37_2 & 63) > 30)
  {
    stage_v_38_2 = ((pub_r000256_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  }
  else
  {
    stage_v_38_2 = ((pub_r000256_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_25_1 & 63) > 50)
  {
    stage_v_39_1 = ((pub_r000256_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  }
  else
  {
    stage_v_39_1 = ((pub_r000256_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
  }
  if ((stage_v_25_2 & 63) > 50)
  {
    stage_v_39_2 = ((pub_r000256_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  }
  else
  {
    stage_v_39_2 = ((pub_r000256_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_27_1 & 63) > 37)
  {
    stage_v_40_1 = ((pub_r000256_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  }
  else
  {
    stage_v_40_1 = ((pub_r000256_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
  }
  if ((stage_v_27_2 & 63) > 37)
  {
    stage_v_40_2 = ((pub_r000256_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  }
  else
  {
    stage_v_40_2 = ((pub_r000256_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_26_1 & 63) > 55)
  {
    stage_v_41_1 = ((pub_r000256_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  }
  else
  {
    stage_v_41_1 = ((pub_r000256_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
  }
  if ((stage_v_26_2 & 63) > 55)
  {
    stage_v_41_2 = ((pub_r000256_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  }
  else
  {
    stage_v_41_2 = ((pub_r000256_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((sec_r000256_1_1 & 63) > 45)
  {
    stage_v_42_1 = ((pub_r000256_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  }
  else
  {
    stage_v_42_1 = ((pub_r000256_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
  }
  if ((sec_r000256_1_2 & 63) > 45)
  {
    stage_v_42_2 = ((pub_r000256_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  }
  else
  {
    stage_v_42_2 = ((pub_r000256_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_24_1 & 63) > 29)
  {
    stage_v_43_1 = ((pub_r000256_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  }
  else
  {
    stage_v_43_1 = ((pub_r000256_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
  }
  if ((stage_v_24_2 & 63) > 29)
  {
    stage_v_43_2 = ((pub_r000256_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  }
  else
  {
    stage_v_43_2 = ((pub_r000256_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_31_1 & 63) > 43)
  {
    stage_v_44_1 = ((pub_r000256_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  }
  else
  {
    stage_v_44_1 = ((pub_r000256_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
  }
  if ((stage_v_31_2 & 63) > 43)
  {
    stage_v_44_2 = ((pub_r000256_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  }
  else
  {
    stage_v_44_2 = ((pub_r000256_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_33_1 & 63) > 40)
  {
    stage_v_45_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  }
  else
  {
    stage_v_45_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
  }
  if ((stage_v_33_2 & 63) > 40)
  {
    stage_v_45_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  }
  else
  {
    stage_v_45_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((sec_r000256_6_1 & 63) > 47)
  {
    stage_v_46_1 = ((pub_r000256_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  }
  else
  {
    stage_v_46_1 = ((pub_r000256_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
  }
  if ((sec_r000256_6_2 & 63) > 47)
  {
    stage_v_46_2 = ((pub_r000256_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  }
  else
  {
    stage_v_46_2 = ((pub_r000256_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_33_1 & 63) > 24)
  {
    stage_v_47_1 = ((pub_r000256_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  }
  else
  {
    stage_v_47_1 = ((pub_r000256_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
  }
  if ((stage_v_33_2 & 63) > 24)
  {
    stage_v_47_2 = ((pub_r000256_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  }
  else
  {
    stage_v_47_2 = ((pub_r000256_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_28_1 & 63) > 32)
  {
    stage_v_48_1 = ((pub_r000256_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  }
  else
  {
    stage_v_48_1 = ((pub_r000256_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
  }
  if ((stage_v_28_2 & 63) > 32)
  {
    stage_v_48_2 = ((pub_r000256_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  }
  else
  {
    stage_v_48_2 = ((pub_r000256_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_48_1 & 63) > 58)
  {
    stage_v_49_1 = ((pub_r000256_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  }
  else
  {
    stage_v_49_1 = ((pub_r000256_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
  }
  if ((stage_v_48_2 & 63) > 58)
  {
    stage_v_49_2 = ((pub_r000256_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  }
  else
  {
    stage_v_49_2 = ((pub_r000256_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((sec_r000256_13_1 & 63) > 34)
  {
    stage_v_50_1 = ((pub_r000256_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  }
  else
  {
    stage_v_50_1 = ((pub_r000256_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
  }
  if ((sec_r000256_13_2 & 63) > 34)
  {
    stage_v_50_2 = ((pub_r000256_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  }
  else
  {
    stage_v_50_2 = ((pub_r000256_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_31_1 & 63) > 17)
  {
    stage_v_51_1 = ((pub_r000256_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  }
  else
  {
    stage_v_51_1 = ((pub_r000256_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
  }
  if ((stage_v_31_2 & 63) > 17)
  {
    stage_v_51_2 = ((pub_r000256_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  }
  else
  {
    stage_v_51_2 = ((pub_r000256_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_47_1 & 63) > 15)
  {
    stage_v_52_1 = ((pub_r000256_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  }
  else
  {
    stage_v_52_1 = ((pub_r000256_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
  }
  if ((stage_v_47_2 & 63) > 15)
  {
    stage_v_52_2 = ((pub_r000256_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  }
  else
  {
    stage_v_52_2 = ((pub_r000256_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((sec_r000256_9_1 & 63) > 51)
  {
    stage_v_53_1 = ((pub_r000256_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  }
  else
  {
    stage_v_53_1 = ((pub_r000256_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
  }
  if ((sec_r000256_9_2 & 63) > 51)
  {
    stage_v_53_2 = ((pub_r000256_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  }
  else
  {
    stage_v_53_2 = ((pub_r000256_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_51_1 & 63) > 17)
  {
    stage_v_54_1 = ((pub_r000256_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  }
  else
  {
    stage_v_54_1 = ((pub_r000256_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
  }
  if ((stage_v_51_2 & 63) > 17)
  {
    stage_v_54_2 = ((pub_r000256_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  }
  else
  {
    stage_v_54_2 = ((pub_r000256_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((sec_r000256_11_1 & 63) > 40)
  {
    stage_v_55_1 = ((pub_r000256_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  }
  else
  {
    stage_v_55_1 = ((pub_r000256_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
  }
  if ((sec_r000256_11_2 & 63) > 40)
  {
    stage_v_55_2 = ((pub_r000256_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  }
  else
  {
    stage_v_55_2 = ((pub_r000256_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((sec_r000256_16_1 & 63) > 48)
  {
    stage_v_56_1 = ((pub_r000256_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  }
  else
  {
    stage_v_56_1 = ((pub_r000256_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
  }
  if ((sec_r000256_16_2 & 63) > 48)
  {
    stage_v_56_2 = ((pub_r000256_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  }
  else
  {
    stage_v_56_2 = ((pub_r000256_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_49_1 & 63) > 22)
  {
    stage_v_57_1 = ((pub_r000256_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  }
  else
  {
    stage_v_57_1 = ((pub_r000256_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
  }
  if ((stage_v_49_2 & 63) > 22)
  {
    stage_v_57_2 = ((pub_r000256_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  }
  else
  {
    stage_v_57_2 = ((pub_r000256_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_32_1 & 63) > 48)
  {
    stage_v_58_1 = ((pub_r000256_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  }
  else
  {
    stage_v_58_1 = ((pub_r000256_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
  }
  if ((stage_v_32_2 & 63) > 48)
  {
    stage_v_58_2 = ((pub_r000256_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  }
  else
  {
    stage_v_58_2 = ((pub_r000256_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_43_1 & 63) > 56)
  {
    stage_v_59_1 = ((pub_r000256_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  }
  else
  {
    stage_v_59_1 = ((pub_r000256_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
  }
  if ((stage_v_43_2 & 63) > 56)
  {
    stage_v_59_2 = ((pub_r000256_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  }
  else
  {
    stage_v_59_2 = ((pub_r000256_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000256_2_1 & 63) > 47)
  {
    stage_v_60_1 = ((pub_r000256_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  }
  else
  {
    stage_v_60_1 = ((pub_r000256_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
  }
  if ((sec_r000256_2_2 & 63) > 47)
  {
    stage_v_60_2 = ((pub_r000256_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  }
  else
  {
    stage_v_60_2 = ((pub_r000256_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((sec_r000256_12_1 & 63) > 45)
  {
    stage_v_61_1 = ((pub_r000256_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  }
  else
  {
    stage_v_61_1 = ((pub_r000256_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
  }
  if ((sec_r000256_12_2 & 63) > 45)
  {
    stage_v_61_2 = ((pub_r000256_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  }
  else
  {
    stage_v_61_2 = ((pub_r000256_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_55_1 & 63) > 35)
  {
    stage_v_62_1 = ((pub_r000256_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  }
  else
  {
    stage_v_62_1 = ((pub_r000256_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
  }
  if ((stage_v_55_2 & 63) > 35)
  {
    stage_v_62_2 = ((pub_r000256_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  }
  else
  {
    stage_v_62_2 = ((pub_r000256_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_22_1 & 63) > 55)
  {
    stage_v_63_1 = ((pub_r000256_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  }
  else
  {
    stage_v_63_1 = ((pub_r000256_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
  }
  if ((stage_v_22_2 & 63) > 55)
  {
    stage_v_63_2 = ((pub_r000256_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  }
  else
  {
    stage_v_63_2 = ((pub_r000256_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_40_1 & 63) > 25)
  {
    stage_v_64_1 = ((pub_r000256_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  }
  else
  {
    stage_v_64_1 = ((pub_r000256_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
  }
  if ((stage_v_40_2 & 63) > 25)
  {
    stage_v_64_2 = ((pub_r000256_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  }
  else
  {
    stage_v_64_2 = ((pub_r000256_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_46_1 & 63) > 42)
  {
    stage_v_65_1 = ((pub_r000256_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  }
  else
  {
    stage_v_65_1 = ((pub_r000256_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
  }
  if ((stage_v_46_2 & 63) > 42)
  {
    stage_v_65_2 = ((pub_r000256_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  }
  else
  {
    stage_v_65_2 = ((pub_r000256_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_42_1 & 63) > 54)
  {
    stage_v_66_1 = ((pub_r000256_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  }
  else
  {
    stage_v_66_1 = ((pub_r000256_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
  }
  if ((stage_v_42_2 & 63) > 54)
  {
    stage_v_66_2 = ((pub_r000256_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  }
  else
  {
    stage_v_66_2 = ((pub_r000256_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_23_1 & 63) > 52)
  {
    stage_v_67_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  }
  else
  {
    stage_v_67_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
  }
  if ((stage_v_23_2 & 63) > 52)
  {
    stage_v_67_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  }
  else
  {
    stage_v_67_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_52_1 & 63) > 44)
  {
    stage_v_68_1 = ((pub_r000256_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  }
  else
  {
    stage_v_68_1 = ((pub_r000256_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
  }
  if ((stage_v_52_2 & 63) > 44)
  {
    stage_v_68_2 = ((pub_r000256_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  }
  else
  {
    stage_v_68_2 = ((pub_r000256_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000256_14_1 & 63) > 29)
  {
    stage_v_69_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  }
  else
  {
    stage_v_69_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
  }
  if ((sec_r000256_14_2 & 63) > 29)
  {
    stage_v_69_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  }
  else
  {
    stage_v_69_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_20_1 & 63) > 30)
  {
    stage_v_70_1 = ((pub_r000256_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  }
  else
  {
    stage_v_70_1 = ((pub_r000256_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
  }
  if ((stage_v_20_2 & 63) > 30)
  {
    stage_v_70_2 = ((pub_r000256_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  }
  else
  {
    stage_v_70_2 = ((pub_r000256_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000256_12_1 & 63) > 16)
  {
    stage_v_71_1 = ((pub_r000256_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  }
  else
  {
    stage_v_71_1 = ((pub_r000256_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
  }
  if ((sec_r000256_12_2 & 63) > 16)
  {
    stage_v_71_2 = ((pub_r000256_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  }
  else
  {
    stage_v_71_2 = ((pub_r000256_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_30_1 & 63) > 24)
  {
    stage_v_72_1 = ((pub_r000256_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  }
  else
  {
    stage_v_72_1 = ((pub_r000256_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
  }
  if ((stage_v_30_2 & 63) > 24)
  {
    stage_v_72_2 = ((pub_r000256_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  }
  else
  {
    stage_v_72_2 = ((pub_r000256_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_56_1 & 63) > 17)
  {
    stage_v_73_1 = ((pub_r000256_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  }
  else
  {
    stage_v_73_1 = ((pub_r000256_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
  }
  if ((stage_v_56_2 & 63) > 17)
  {
    stage_v_73_2 = ((pub_r000256_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  }
  else
  {
    stage_v_73_2 = ((pub_r000256_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_72_1 & 63) > 20)
  {
    stage_v_74_1 = ((pub_r000256_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  }
  else
  {
    stage_v_74_1 = ((pub_r000256_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
  }
  if ((stage_v_72_2 & 63) > 20)
  {
    stage_v_74_2 = ((pub_r000256_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  }
  else
  {
    stage_v_74_2 = ((pub_r000256_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000256_11_1 & 63) > 17)
  {
    stage_v_75_1 = ((pub_r000256_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  }
  else
  {
    stage_v_75_1 = ((pub_r000256_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
  }
  if ((sec_r000256_11_2 & 63) > 17)
  {
    stage_v_75_2 = ((pub_r000256_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  }
  else
  {
    stage_v_75_2 = ((pub_r000256_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_68_1 & 63) > 20)
  {
    stage_v_76_1 = ((pub_r000256_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  }
  else
  {
    stage_v_76_1 = ((pub_r000256_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
  }
  if ((stage_v_68_2 & 63) > 20)
  {
    stage_v_76_2 = ((pub_r000256_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  }
  else
  {
    stage_v_76_2 = ((pub_r000256_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_55_1 & 63) > 33)
  {
    stage_v_77_1 = ((pub_r000256_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  }
  else
  {
    stage_v_77_1 = ((pub_r000256_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
  }
  if ((stage_v_55_2 & 63) > 33)
  {
    stage_v_77_2 = ((pub_r000256_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  }
  else
  {
    stage_v_77_2 = ((pub_r000256_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_47_1 & 63) > 25)
  {
    stage_v_78_1 = ((pub_r000256_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  }
  else
  {
    stage_v_78_1 = ((pub_r000256_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
  }
  if ((stage_v_47_2 & 63) > 25)
  {
    stage_v_78_2 = ((pub_r000256_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  }
  else
  {
    stage_v_78_2 = ((pub_r000256_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_38_1 & 63) > 57)
  {
    stage_v_79_1 = ((pub_r000256_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  }
  else
  {
    stage_v_79_1 = ((pub_r000256_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
  }
  if ((stage_v_38_2 & 63) > 57)
  {
    stage_v_79_2 = ((pub_r000256_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  }
  else
  {
    stage_v_79_2 = ((pub_r000256_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_36_1 & 63) > 26)
  {
    stage_v_80_1 = ((pub_r000256_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  }
  else
  {
    stage_v_80_1 = ((pub_r000256_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
  }
  if ((stage_v_36_2 & 63) > 26)
  {
    stage_v_80_2 = ((pub_r000256_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  }
  else
  {
    stage_v_80_2 = ((pub_r000256_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_74_1 & 63) > 19)
  {
    stage_v_81_1 = ((pub_r000256_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  }
  else
  {
    stage_v_81_1 = ((pub_r000256_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
  }
  if ((stage_v_74_2 & 63) > 19)
  {
    stage_v_81_2 = ((pub_r000256_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  }
  else
  {
    stage_v_81_2 = ((pub_r000256_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_24_1 & 63) > 45)
  {
    stage_v_82_1 = ((pub_r000256_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  }
  else
  {
    stage_v_82_1 = ((pub_r000256_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
  }
  if ((stage_v_24_2 & 63) > 45)
  {
    stage_v_82_2 = ((pub_r000256_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  }
  else
  {
    stage_v_82_2 = ((pub_r000256_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_24_1 & 63) > 33)
  {
    stage_v_83_1 = ((pub_r000256_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  }
  else
  {
    stage_v_83_1 = ((pub_r000256_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
  }
  if ((stage_v_24_2 & 63) > 33)
  {
    stage_v_83_2 = ((pub_r000256_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  }
  else
  {
    stage_v_83_2 = ((pub_r000256_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000256_4_1 & 63) > 55)
  {
    stage_v_84_1 = ((pub_r000256_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  }
  else
  {
    stage_v_84_1 = ((pub_r000256_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
  }
  if ((sec_r000256_4_2 & 63) > 55)
  {
    stage_v_84_2 = ((pub_r000256_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  }
  else
  {
    stage_v_84_2 = ((pub_r000256_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_53_1 & 63) > 38)
  {
    stage_v_85_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  }
  else
  {
    stage_v_85_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
  }
  if ((stage_v_53_2 & 63) > 38)
  {
    stage_v_85_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  }
  else
  {
    stage_v_85_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_49_1 & 63) > 46)
  {
    stage_v_86_1 = ((pub_r000256_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  }
  else
  {
    stage_v_86_1 = ((pub_r000256_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
  }
  if ((stage_v_49_2 & 63) > 46)
  {
    stage_v_86_2 = ((pub_r000256_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  }
  else
  {
    stage_v_86_2 = ((pub_r000256_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_55_1 & 63) > 41)
  {
    stage_v_87_1 = ((pub_r000256_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  }
  else
  {
    stage_v_87_1 = ((pub_r000256_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
  }
  if ((stage_v_55_2 & 63) > 41)
  {
    stage_v_87_2 = ((pub_r000256_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  }
  else
  {
    stage_v_87_2 = ((pub_r000256_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_79_1 & 63) > 29)
  {
    stage_v_88_1 = ((pub_r000256_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  }
  else
  {
    stage_v_88_1 = ((pub_r000256_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
  }
  if ((stage_v_79_2 & 63) > 29)
  {
    stage_v_88_2 = ((pub_r000256_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  }
  else
  {
    stage_v_88_2 = ((pub_r000256_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_46_1 & 63) > 55)
  {
    stage_v_89_1 = ((pub_r000256_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  }
  else
  {
    stage_v_89_1 = ((pub_r000256_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
  }
  if ((stage_v_46_2 & 63) > 55)
  {
    stage_v_89_2 = ((pub_r000256_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  }
  else
  {
    stage_v_89_2 = ((pub_r000256_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000256_6_1 & 63) > 37)
  {
    stage_v_90_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  }
  else
  {
    stage_v_90_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
  }
  if ((sec_r000256_6_2 & 63) > 37)
  {
    stage_v_90_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  }
  else
  {
    stage_v_90_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_43_1 & 63) > 54)
  {
    stage_v_91_1 = ((pub_r000256_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  }
  else
  {
    stage_v_91_1 = ((pub_r000256_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
  }
  if ((stage_v_43_2 & 63) > 54)
  {
    stage_v_91_2 = ((pub_r000256_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  }
  else
  {
    stage_v_91_2 = ((pub_r000256_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000256_13_1 & 63) > 39)
  {
    stage_v_92_1 = ((pub_r000256_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  }
  else
  {
    stage_v_92_1 = ((pub_r000256_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
  }
  if ((sec_r000256_13_2 & 63) > 39)
  {
    stage_v_92_2 = ((pub_r000256_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  }
  else
  {
    stage_v_92_2 = ((pub_r000256_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000256_1_1 & 63) > 34)
  {
    stage_v_93_1 = ((pub_r000256_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  }
  else
  {
    stage_v_93_1 = ((pub_r000256_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
  }
  if ((sec_r000256_1_2 & 63) > 34)
  {
    stage_v_93_2 = ((pub_r000256_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  }
  else
  {
    stage_v_93_2 = ((pub_r000256_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000256_7_1 & 63) > 60)
  {
    stage_v_94_1 = ((pub_r000256_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  }
  else
  {
    stage_v_94_1 = ((pub_r000256_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
  }
  if ((sec_r000256_7_2 & 63) > 60)
  {
    stage_v_94_2 = ((pub_r000256_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  }
  else
  {
    stage_v_94_2 = ((pub_r000256_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_33_1 & 63) > 19)
  {
    stage_v_95_1 = ((pub_r000256_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  }
  else
  {
    stage_v_95_1 = ((pub_r000256_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
  }
  if ((stage_v_33_2 & 63) > 19)
  {
    stage_v_95_2 = ((pub_r000256_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  }
  else
  {
    stage_v_95_2 = ((pub_r000256_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000256_0_1 & 63) > 34)
  {
    stage_v_96_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  }
  else
  {
    stage_v_96_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
  }
  if ((sec_r000256_0_2 & 63) > 34)
  {
    stage_v_96_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  }
  else
  {
    stage_v_96_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_89_1 & 63) > 60)
  {
    stage_v_97_1 = ((pub_r000256_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  }
  else
  {
    stage_v_97_1 = ((pub_r000256_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
  }
  if ((stage_v_89_2 & 63) > 60)
  {
    stage_v_97_2 = ((pub_r000256_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  }
  else
  {
    stage_v_97_2 = ((pub_r000256_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000256_7_1 & 63) > 25)
  {
    stage_v_98_1 = ((pub_r000256_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  }
  else
  {
    stage_v_98_1 = ((pub_r000256_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
  }
  if ((sec_r000256_7_2 & 63) > 25)
  {
    stage_v_98_2 = ((pub_r000256_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  }
  else
  {
    stage_v_98_2 = ((pub_r000256_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000256_17_1 & 63) > 30)
  {
    stage_v_99_1 = ((pub_r000256_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  }
  else
  {
    stage_v_99_1 = ((pub_r000256_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
  }
  if ((sec_r000256_17_2 & 63) > 30)
  {
    stage_v_99_2 = ((pub_r000256_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  }
  else
  {
    stage_v_99_2 = ((pub_r000256_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000256_12_1 & 63) > 53)
  {
    stage_v_100_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  }
  else
  {
    stage_v_100_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
  }
  if ((sec_r000256_12_2 & 63) > 53)
  {
    stage_v_100_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  }
  else
  {
    stage_v_100_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_89_1 & 63) > 56)
  {
    stage_v_101_1 = ((pub_r000256_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  }
  else
  {
    stage_v_101_1 = ((pub_r000256_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
  }
  if ((stage_v_89_2 & 63) > 56)
  {
    stage_v_101_2 = ((pub_r000256_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  }
  else
  {
    stage_v_101_2 = ((pub_r000256_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_75_1 & 63) > 46)
  {
    stage_v_102_1 = ((pub_r000256_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  }
  else
  {
    stage_v_102_1 = ((pub_r000256_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
  }
  if ((stage_v_75_2 & 63) > 46)
  {
    stage_v_102_2 = ((pub_r000256_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  }
  else
  {
    stage_v_102_2 = ((pub_r000256_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_48_1 & 63) > 20)
  {
    stage_v_103_1 = ((pub_r000256_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  }
  else
  {
    stage_v_103_1 = ((pub_r000256_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
  }
  if ((stage_v_48_2 & 63) > 20)
  {
    stage_v_103_2 = ((pub_r000256_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  }
  else
  {
    stage_v_103_2 = ((pub_r000256_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000256_3_1 & 63) > 60)
  {
    stage_v_104_1 = ((pub_r000256_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  }
  else
  {
    stage_v_104_1 = ((pub_r000256_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
  }
  if ((sec_r000256_3_2 & 63) > 60)
  {
    stage_v_104_2 = ((pub_r000256_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  }
  else
  {
    stage_v_104_2 = ((pub_r000256_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000256_4_1 & 63) > 53)
  {
    stage_v_105_1 = ((pub_r000256_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  }
  else
  {
    stage_v_105_1 = ((pub_r000256_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
  }
  if ((sec_r000256_4_2 & 63) > 53)
  {
    stage_v_105_2 = ((pub_r000256_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  }
  else
  {
    stage_v_105_2 = ((pub_r000256_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_47_1 & 63) > 40)
  {
    stage_v_106_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  }
  else
  {
    stage_v_106_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
  }
  if ((stage_v_47_2 & 63) > 40)
  {
    stage_v_106_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  }
  else
  {
    stage_v_106_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_47_1 & 63) > 26)
  {
    stage_v_107_1 = ((pub_r000256_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  }
  else
  {
    stage_v_107_1 = ((pub_r000256_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
  }
  if ((stage_v_47_2 & 63) > 26)
  {
    stage_v_107_2 = ((pub_r000256_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  }
  else
  {
    stage_v_107_2 = ((pub_r000256_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_100_1 & 63) > 49)
  {
    stage_v_108_1 = ((pub_r000256_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  }
  else
  {
    stage_v_108_1 = ((pub_r000256_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
  }
  if ((stage_v_100_2 & 63) > 49)
  {
    stage_v_108_2 = ((pub_r000256_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  }
  else
  {
    stage_v_108_2 = ((pub_r000256_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000256_14_1 & 63) > 53)
  {
    stage_v_109_1 = ((pub_r000256_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  }
  else
  {
    stage_v_109_1 = ((pub_r000256_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
  }
  if ((sec_r000256_14_2 & 63) > 53)
  {
    stage_v_109_2 = ((pub_r000256_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  }
  else
  {
    stage_v_109_2 = ((pub_r000256_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_48_1 & 63) > 36)
  {
    stage_v_110_1 = ((pub_r000256_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  }
  else
  {
    stage_v_110_1 = ((pub_r000256_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
  }
  if ((stage_v_48_2 & 63) > 36)
  {
    stage_v_110_2 = ((pub_r000256_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  }
  else
  {
    stage_v_110_2 = ((pub_r000256_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000256_2_1 & 63) > 25)
  {
    stage_v_111_1 = ((pub_r000256_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  }
  else
  {
    stage_v_111_1 = ((pub_r000256_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
  }
  if ((sec_r000256_2_2 & 63) > 25)
  {
    stage_v_111_2 = ((pub_r000256_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  }
  else
  {
    stage_v_111_2 = ((pub_r000256_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_46_1 & 63) > 60)
  {
    stage_v_112_1 = ((pub_r000256_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  }
  else
  {
    stage_v_112_1 = ((pub_r000256_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
  }
  if ((stage_v_46_2 & 63) > 60)
  {
    stage_v_112_2 = ((pub_r000256_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  }
  else
  {
    stage_v_112_2 = ((pub_r000256_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000256_14_1 & 63) > 48)
  {
    stage_v_113_1 = ((pub_r000256_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  }
  else
  {
    stage_v_113_1 = ((pub_r000256_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
  }
  if ((sec_r000256_14_2 & 63) > 48)
  {
    stage_v_113_2 = ((pub_r000256_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  }
  else
  {
    stage_v_113_2 = ((pub_r000256_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_56_1 & 63) > 38)
  {
    stage_v_114_1 = ((pub_r000256_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  }
  else
  {
    stage_v_114_1 = ((pub_r000256_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
  }
  if ((stage_v_56_2 & 63) > 38)
  {
    stage_v_114_2 = ((pub_r000256_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  }
  else
  {
    stage_v_114_2 = ((pub_r000256_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_95_1 & 63) > 44)
  {
    stage_v_115_1 = ((pub_r000256_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  }
  else
  {
    stage_v_115_1 = ((pub_r000256_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
  }
  if ((stage_v_95_2 & 63) > 44)
  {
    stage_v_115_2 = ((pub_r000256_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  }
  else
  {
    stage_v_115_2 = ((pub_r000256_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000256_10_1 & 63) > 56)
  {
    stage_v_116_1 = ((pub_r000256_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  }
  else
  {
    stage_v_116_1 = ((pub_r000256_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
  }
  if ((sec_r000256_10_2 & 63) > 56)
  {
    stage_v_116_2 = ((pub_r000256_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  }
  else
  {
    stage_v_116_2 = ((pub_r000256_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_22_1 & 63) > 18)
  {
    stage_v_117_1 = ((pub_r000256_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  }
  else
  {
    stage_v_117_1 = ((pub_r000256_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
  }
  if ((stage_v_22_2 & 63) > 18)
  {
    stage_v_117_2 = ((pub_r000256_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  }
  else
  {
    stage_v_117_2 = ((pub_r000256_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_66_1 & 63) > 52)
  {
    stage_v_118_1 = ((pub_r000256_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  }
  else
  {
    stage_v_118_1 = ((pub_r000256_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
  }
  if ((stage_v_66_2 & 63) > 52)
  {
    stage_v_118_2 = ((pub_r000256_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  }
  else
  {
    stage_v_118_2 = ((pub_r000256_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_20_1 & 63) > 59)
  {
    stage_v_119_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  }
  else
  {
    stage_v_119_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
  }
  if ((stage_v_20_2 & 63) > 59)
  {
    stage_v_119_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  }
  else
  {
    stage_v_119_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_25_1 & 63) > 25)
  {
    stage_v_120_1 = ((pub_r000256_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  }
  else
  {
    stage_v_120_1 = ((pub_r000256_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
  }
  if ((stage_v_25_2 & 63) > 25)
  {
    stage_v_120_2 = ((pub_r000256_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  }
  else
  {
    stage_v_120_2 = ((pub_r000256_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_92_1 & 63) > 49)
  {
    stage_v_121_1 = ((pub_r000256_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  }
  else
  {
    stage_v_121_1 = ((pub_r000256_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
  }
  if ((stage_v_92_2 & 63) > 49)
  {
    stage_v_121_2 = ((pub_r000256_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  }
  else
  {
    stage_v_121_2 = ((pub_r000256_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_90_1 & 63) > 31)
  {
    stage_v_122_1 = ((pub_r000256_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  }
  else
  {
    stage_v_122_1 = ((pub_r000256_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
  }
  if ((stage_v_90_2 & 63) > 31)
  {
    stage_v_122_2 = ((pub_r000256_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  }
  else
  {
    stage_v_122_2 = ((pub_r000256_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_59_1 & 63) > 25)
  {
    stage_v_123_1 = ((pub_r000256_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  }
  else
  {
    stage_v_123_1 = ((pub_r000256_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
  }
  if ((stage_v_59_2 & 63) > 25)
  {
    stage_v_123_2 = ((pub_r000256_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  }
  else
  {
    stage_v_123_2 = ((pub_r000256_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000256_15_1 & 63) > 37)
  {
    stage_v_124_1 = ((pub_r000256_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  }
  else
  {
    stage_v_124_1 = ((pub_r000256_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
  }
  if ((sec_r000256_15_2 & 63) > 37)
  {
    stage_v_124_2 = ((pub_r000256_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  }
  else
  {
    stage_v_124_2 = ((pub_r000256_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_79_1 & 63) > 47)
  {
    stage_v_125_1 = ((pub_r000256_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  }
  else
  {
    stage_v_125_1 = ((pub_r000256_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
  }
  if ((stage_v_79_2 & 63) > 47)
  {
    stage_v_125_2 = ((pub_r000256_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  }
  else
  {
    stage_v_125_2 = ((pub_r000256_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_24_1 & 63) > 36)
  {
    stage_v_126_1 = ((pub_r000256_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  }
  else
  {
    stage_v_126_1 = ((pub_r000256_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
  }
  if ((stage_v_24_2 & 63) > 36)
  {
    stage_v_126_2 = ((pub_r000256_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  }
  else
  {
    stage_v_126_2 = ((pub_r000256_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000256_15_1 & 63) > 20)
  {
    stage_v_127_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  }
  else
  {
    stage_v_127_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
  }
  if ((sec_r000256_15_2 & 63) > 20)
  {
    stage_v_127_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  }
  else
  {
    stage_v_127_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000256_7_1 & 63) > 19)
  {
    stage_v_128_1 = ((pub_r000256_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  }
  else
  {
    stage_v_128_1 = ((pub_r000256_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
  }
  if ((sec_r000256_7_2 & 63) > 19)
  {
    stage_v_128_2 = ((pub_r000256_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  }
  else
  {
    stage_v_128_2 = ((pub_r000256_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_22_1 & 63) > 31)
  {
    stage_v_129_1 = ((pub_r000256_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  }
  else
  {
    stage_v_129_1 = ((pub_r000256_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
  }
  if ((stage_v_22_2 & 63) > 31)
  {
    stage_v_129_2 = ((pub_r000256_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  }
  else
  {
    stage_v_129_2 = ((pub_r000256_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_24_1 & 63) > 49)
  {
    stage_v_130_1 = ((pub_r000256_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  }
  else
  {
    stage_v_130_1 = ((pub_r000256_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
  }
  if ((stage_v_24_2 & 63) > 49)
  {
    stage_v_130_2 = ((pub_r000256_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  }
  else
  {
    stage_v_130_2 = ((pub_r000256_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_63_1 & 63) > 15)
  {
    stage_v_131_1 = ((pub_r000256_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  }
  else
  {
    stage_v_131_1 = ((pub_r000256_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
  }
  if ((stage_v_63_2 & 63) > 15)
  {
    stage_v_131_2 = ((pub_r000256_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  }
  else
  {
    stage_v_131_2 = ((pub_r000256_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000256_6_1 & 63) > 44)
  {
    stage_v_132_1 = ((pub_r000256_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  }
  else
  {
    stage_v_132_1 = ((pub_r000256_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
  }
  if ((sec_r000256_6_2 & 63) > 44)
  {
    stage_v_132_2 = ((pub_r000256_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  }
  else
  {
    stage_v_132_2 = ((pub_r000256_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_70_1 & 63) > 53)
  {
    stage_v_133_1 = ((pub_r000256_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  }
  else
  {
    stage_v_133_1 = ((pub_r000256_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
  }
  if ((stage_v_70_2 & 63) > 53)
  {
    stage_v_133_2 = ((pub_r000256_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  }
  else
  {
    stage_v_133_2 = ((pub_r000256_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000256_17_1 & 63) > 51)
  {
    stage_v_134_1 = ((pub_r000256_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  }
  else
  {
    stage_v_134_1 = ((pub_r000256_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
  }
  if ((sec_r000256_17_2 & 63) > 51)
  {
    stage_v_134_2 = ((pub_r000256_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  }
  else
  {
    stage_v_134_2 = ((pub_r000256_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_118_1 & 63) > 60)
  {
    stage_v_135_1 = ((pub_r000256_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  }
  else
  {
    stage_v_135_1 = ((pub_r000256_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
  }
  if ((stage_v_118_2 & 63) > 60)
  {
    stage_v_135_2 = ((pub_r000256_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  }
  else
  {
    stage_v_135_2 = ((pub_r000256_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_72_1 & 63) > 34)
  {
    stage_v_136_1 = ((pub_r000256_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  }
  else
  {
    stage_v_136_1 = ((pub_r000256_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
  }
  if ((stage_v_72_2 & 63) > 34)
  {
    stage_v_136_2 = ((pub_r000256_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  }
  else
  {
    stage_v_136_2 = ((pub_r000256_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_84_1 & 63) > 52)
  {
    stage_v_137_1 = ((pub_r000256_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  }
  else
  {
    stage_v_137_1 = ((pub_r000256_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
  }
  if ((stage_v_84_2 & 63) > 52)
  {
    stage_v_137_2 = ((pub_r000256_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  }
  else
  {
    stage_v_137_2 = ((pub_r000256_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000256_16_1 & 63) > 50)
  {
    stage_v_138_1 = ((pub_r000256_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  }
  else
  {
    stage_v_138_1 = ((pub_r000256_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
  }
  if ((sec_r000256_16_2 & 63) > 50)
  {
    stage_v_138_2 = ((pub_r000256_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  }
  else
  {
    stage_v_138_2 = ((pub_r000256_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000256_1_1 & 63) > 53)
  {
    stage_v_139_1 = ((pub_r000256_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  }
  else
  {
    stage_v_139_1 = ((pub_r000256_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
  }
  if ((sec_r000256_1_2 & 63) > 53)
  {
    stage_v_139_2 = ((pub_r000256_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  }
  else
  {
    stage_v_139_2 = ((pub_r000256_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_51_1 & 63) > 50)
  {
    stage_v_140_1 = ((pub_r000256_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  }
  else
  {
    stage_v_140_1 = ((pub_r000256_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
  }
  if ((stage_v_51_2 & 63) > 50)
  {
    stage_v_140_2 = ((pub_r000256_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  }
  else
  {
    stage_v_140_2 = ((pub_r000256_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000256_9_1 & 63) > 38)
  {
    stage_v_141_1 = ((pub_r000256_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  }
  else
  {
    stage_v_141_1 = ((pub_r000256_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
  }
  if ((sec_r000256_9_2 & 63) > 38)
  {
    stage_v_141_2 = ((pub_r000256_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  }
  else
  {
    stage_v_141_2 = ((pub_r000256_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_125_1 & 63) > 55)
  {
    stage_v_142_1 = ((pub_r000256_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  }
  else
  {
    stage_v_142_1 = ((pub_r000256_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
  }
  if ((stage_v_125_2 & 63) > 55)
  {
    stage_v_142_2 = ((pub_r000256_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  }
  else
  {
    stage_v_142_2 = ((pub_r000256_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_44_1 & 63) > 51)
  {
    stage_v_143_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  }
  else
  {
    stage_v_143_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
  }
  if ((stage_v_44_2 & 63) > 51)
  {
    stage_v_143_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  }
  else
  {
    stage_v_143_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_98_1 & 63) > 60)
  {
    stage_v_144_1 = ((pub_r000256_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  }
  else
  {
    stage_v_144_1 = ((pub_r000256_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
  }
  if ((stage_v_98_2 & 63) > 60)
  {
    stage_v_144_2 = ((pub_r000256_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  }
  else
  {
    stage_v_144_2 = ((pub_r000256_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_21_1 & 63) > 52)
  {
    stage_v_145_1 = ((pub_r000256_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  }
  else
  {
    stage_v_145_1 = ((pub_r000256_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
  }
  if ((stage_v_21_2 & 63) > 52)
  {
    stage_v_145_2 = ((pub_r000256_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  }
  else
  {
    stage_v_145_2 = ((pub_r000256_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000256_1_1 & 63) > 54)
  {
    stage_v_146_1 = ((pub_r000256_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  }
  else
  {
    stage_v_146_1 = ((pub_r000256_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
  }
  if ((sec_r000256_1_2 & 63) > 54)
  {
    stage_v_146_2 = ((pub_r000256_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  }
  else
  {
    stage_v_146_2 = ((pub_r000256_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_34_1 & 63) > 38)
  {
    stage_v_147_1 = ((pub_r000256_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  }
  else
  {
    stage_v_147_1 = ((pub_r000256_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
  }
  if ((stage_v_34_2 & 63) > 38)
  {
    stage_v_147_2 = ((pub_r000256_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  }
  else
  {
    stage_v_147_2 = ((pub_r000256_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000256_16_1 & 63) > 16)
  {
    stage_v_148_1 = ((pub_r000256_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  }
  else
  {
    stage_v_148_1 = ((pub_r000256_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
  }
  if ((sec_r000256_16_2 & 63) > 16)
  {
    stage_v_148_2 = ((pub_r000256_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  }
  else
  {
    stage_v_148_2 = ((pub_r000256_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_114_1 & 63) > 44)
  {
    stage_v_149_1 = ((pub_r000256_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  }
  else
  {
    stage_v_149_1 = ((pub_r000256_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
  }
  if ((stage_v_114_2 & 63) > 44)
  {
    stage_v_149_2 = ((pub_r000256_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  }
  else
  {
    stage_v_149_2 = ((pub_r000256_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((sec_r000256_0_1 & 63) > 26)
  {
    stage_v_150_1 = ((pub_r000256_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  }
  else
  {
    stage_v_150_1 = ((pub_r000256_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
  }
  if ((sec_r000256_0_2 & 63) > 26)
  {
    stage_v_150_2 = ((pub_r000256_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  }
  else
  {
    stage_v_150_2 = ((pub_r000256_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000256_14_1 & 63) > 47)
  {
    stage_v_151_1 = ((pub_r000256_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  }
  else
  {
    stage_v_151_1 = ((pub_r000256_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
  }
  if ((sec_r000256_14_2 & 63) > 47)
  {
    stage_v_151_2 = ((pub_r000256_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  }
  else
  {
    stage_v_151_2 = ((pub_r000256_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_72_1 & 63) > 52)
  {
    stage_v_152_1 = ((pub_r000256_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  }
  else
  {
    stage_v_152_1 = ((pub_r000256_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
  }
  if ((stage_v_72_2 & 63) > 52)
  {
    stage_v_152_2 = ((pub_r000256_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  }
  else
  {
    stage_v_152_2 = ((pub_r000256_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_140_1 & 63) > 24)
  {
    stage_v_153_1 = ((pub_r000256_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  }
  else
  {
    stage_v_153_1 = ((pub_r000256_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
  }
  if ((stage_v_140_2 & 63) > 24)
  {
    stage_v_153_2 = ((pub_r000256_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  }
  else
  {
    stage_v_153_2 = ((pub_r000256_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000256_1_1 != sec_r000256_1_2);
  __CPROVER_assume(sec_r000256_8_1 != sec_r000256_8_2);
  __CPROVER_assume(sec_r000256_0_1 != sec_r000256_0_2);
  __CPROVER_assume(sec_r000256_9_1 != sec_r000256_9_2);
  __CPROVER_assume(pub_r000256_9_1 == pub_r000256_9_2);
  __CPROVER_assume(sec_r000256_13_1 != sec_r000256_13_2);
  __CPROVER_assume(sec_r000256_2_1 != sec_r000256_2_2);
  __CPROVER_assume(sec_r000256_14_1 != sec_r000256_14_2);
  __CPROVER_assume(sec_r000256_10_1 != sec_r000256_10_2);
  __CPROVER_assume(pub_r000256_5_1 == pub_r000256_5_2);
  __CPROVER_assume(sec_r000256_17_1 != sec_r000256_17_2);
  __CPROVER_assume(pub_r000256_3_1 == pub_r000256_3_2);
  __CPROVER_assume(pub_r000256_12_1 == pub_r000256_12_2);
  __CPROVER_assume(sec_r000256_12_1 != sec_r000256_12_2);
  __CPROVER_assume(pub_r000256_4_1 == pub_r000256_4_2);
  __CPROVER_assume(sec_r000256_16_1 != sec_r000256_16_2);
  __CPROVER_assume(sec_r000256_5_1 != sec_r000256_5_2);
  __CPROVER_assume(sec_r000256_3_1 != sec_r000256_3_2);
  __CPROVER_assume(pub_r000256_14_1 == pub_r000256_14_2);
  __CPROVER_assume(sec_r000256_7_1 != sec_r000256_7_2);
  __CPROVER_assume(sec_r000256_11_1 != sec_r000256_11_2);
  __CPROVER_assume(pub_r000256_16_1 == pub_r000256_16_2);
  __CPROVER_assume(pub_r000256_6_1 == pub_r000256_6_2);
  __CPROVER_assume(sec_r000256_6_1 != sec_r000256_6_2);
  __CPROVER_assume(sec_r000256_15_1 != sec_r000256_15_2);
  __CPROVER_assume(pub_r000256_1_1 == pub_r000256_1_2);
  __CPROVER_assume(pub_r000256_10_1 == pub_r000256_10_2);
  __CPROVER_assume(pub_r000256_11_1 == pub_r000256_11_2);
  __CPROVER_assume(pub_r000256_13_1 == pub_r000256_13_2);
  __CPROVER_assume(sec_r000256_4_1 != sec_r000256_4_2);
  __CPROVER_assume(pub_r000256_8_1 == pub_r000256_8_2);
  __CPROVER_assume(pub_r000256_7_1 == pub_r000256_7_2);
  __CPROVER_assume(pub_r000256_15_1 == pub_r000256_15_2);
  __CPROVER_assume(pub_r000256_17_1 == pub_r000256_17_2);
  __CPROVER_assume(pub_r000256_0_1 == pub_r000256_0_2);
  __CPROVER_assume(pub_r000256_2_1 == pub_r000256_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.tail == st_var_2_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.density == st_var_3_2.density);
  assert(st_var_3_1.determinant == st_var_3_2.determinant);
  assert(st_var_3_1.stride == st_var_3_2.stride);
  assert(st_var_3_1.scale == st_var_3_2.scale);
  assert(st_var_3_1.trace == st_var_3_2.trace);
  assert(st_var_3_1.dim == st_var_3_2.dim);
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
}


