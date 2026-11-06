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
struct DeviceConfig_R000909_913_0
{
  unsigned char stop_bits;
  short parity;
  unsigned char id;
  int timeout;
  int port;
  int baud_rate;
  int buffer[3];
};
struct CipherContext_R000909_913_1
{
  int counter;
  int round_key;
  unsigned char nonce;
  short tag;
  int iv;
  int buffer[3];
};
struct StreamBuffer_R000909_913_2
{
  short tail;
  int capacity;
  short state;
  unsigned char checksum;
  short head;
  short watermark;
  int buffer[3];
};
struct MatrixBlock_R000909_913_3
{
  int stride;
  unsigned char trace;
  short determinant;
  unsigned char dim;
  unsigned char density;
  unsigned char scale;
  int buffer[3];
};
union RegisterBank_R000909_913_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000909_913_1
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
void fn_R000909_913_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st_1 = {0};
  struct StreamBuffer_R000909_913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int window_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_37_1 > 49)
  {
    acc_1 = ((acc_1 + (window_37_1 * 2)) + 5) & 127;
    aux_1 ^= window_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_37_2 > 49)
  {
    acc_2 = ((acc_2 + (window_37_2 * 2)) + 5) & 127;
    aux_2 ^= window_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_63_1 = local_arr_1[aux_1 % 3];
  int margin_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_63_2 * 2)) & 127;
  int vector_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_75_1)
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

  switch (vector_75_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_37_1 == window_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_63_1 == margin_63_2);
  assert(vector_75_1 == vector_75_2);
}

int fn_R000909_913_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int window_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_37 > 49)
  {
    acc = ((acc + (window_37 * 2)) + 5) & 127;
    aux ^= window_37 & 15;
  }
  else
  {
    acc = ((acc - window_37) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_63 = local_arr[aux % 3];
  acc = (acc + (margin_63 * 2)) & 127;
  int vector_75 = (aux + st.buffer[1]) & 3;
  switch (vector_75)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000909_913_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st_1 = {0};
  struct StreamBuffer_R000909_913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_28_1 = local_arr_1[aux_1 % 3];
  int cursor_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_28_2 * 2)) & 127;
  int stride_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_97_1 > 50)
  {
    acc_1 = ((acc_1 + (stride_97_1 * 2)) + 5) & 127;
    aux_1 ^= stride_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_97_2 > 50)
  {
    acc_2 = ((acc_2 + (stride_97_2 * 2)) + 5) & 127;
    aux_2 ^= stride_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_10_1) & 63;
  aux_2 = (aux_2 + accumulator_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_28_1 == cursor_28_2);
  assert(stride_97_1 == stride_97_2);
  assert(accumulator_10_1 == accumulator_10_2);
}

int fn_R000909_913_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int cursor_28 = local_arr[aux % 3];
  acc = (acc + (cursor_28 * 2)) & 127;
  int stride_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_97 > 50)
  {
    acc = ((acc + (stride_97 * 2)) + 5) & 127;
    aux ^= stride_97 & 15;
  }
  else
  {
    acc = ((acc - stride_97) + 11) & 127;
    aux += 3;
  }
  int accumulator_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_10) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000909_913_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st_1 = {0};
  struct MatrixBlock_R000909_913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int parity_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_80_1)
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

  switch (parity_80_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_80_1 == parity_80_2);
}

int fn_R000909_913_2(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int parity_80 = (aux + st.buffer[1]) & 3;
  switch (parity_80)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000909_913_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st_1 = {0};
  struct StreamBuffer_R000909_913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int offset_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_45_1)
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

  switch (offset_45_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_34_1 = local_arr_1[aux_1 % 3];
  int scale_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_34_2 * 2)) & 127;
  int damping_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_70_1 > 10)
  {
    acc_1 = ((acc_1 + (damping_70_1 * 2)) + 5) & 127;
    aux_1 ^= damping_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_70_2 > 10)
  {
    acc_2 = ((acc_2 + (damping_70_2 * 2)) + 5) & 127;
    aux_2 ^= damping_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_45_1 == offset_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_34_1 == scale_34_2);
  assert(damping_70_1 == damping_70_2);
}

int fn_R000909_913_3(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int offset_45 = (aux + st.buffer[1]) & 3;
  switch (offset_45)
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

  int local_arr[3] = {4, 9, 15};
  int scale_34 = local_arr[aux % 3];
  acc = (acc + (scale_34 * 2)) & 127;
  int damping_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_70 > 10)
  {
    acc = ((acc + (damping_70 * 2)) + 5) & 127;
    aux ^= damping_70 & 15;
  }
  else
  {
    acc = ((acc - damping_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000909_913_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st_1 = {0};
  struct MatrixBlock_R000909_913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int tally_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_65_1)
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

  switch (tally_65_2)
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
  int coefficient_12_1 = local_arr_1[aux_1 % 3];
  int coefficient_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_12_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_65_1 == tally_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_12_1 == coefficient_12_2);
}

int fn_R000909_913_4(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int tally_65 = (aux + st.buffer[1]) & 3;
  switch (tally_65)
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
  int coefficient_12 = local_arr[aux % 3];
  acc = (acc + (coefficient_12 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000909_913_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000909_913_0 st_1 = {0};
  struct DeviceConfig_R000909_913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_57_1 = local_arr_1[aux_1 % 3];
  int stride_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_57_2 * 2)) & 127;
  int index_reg_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_71_1 > 33)
  {
    acc_1 = ((acc_1 + (index_reg_71_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_71_2 > 33)
  {
    acc_2 = ((acc_2 + (index_reg_71_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_71_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_57_1 == stride_57_2);
  assert(index_reg_71_1 == index_reg_71_2);
}

int fn_R000909_913_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000909_913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int stride_57 = local_arr[aux % 3];
  acc = (acc + (stride_57 * 2)) & 127;
  int index_reg_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_71 > 33)
  {
    acc = ((acc + (index_reg_71 * 2)) + 5) & 127;
    aux ^= index_reg_71 & 15;
  }
  else
  {
    acc = ((acc - index_reg_71) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000909_913_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000909_913_1 st_1 = {0};
  struct CipherContext_R000909_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int parity_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_88_1) & 63;
  aux_2 = (aux_2 + parity_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_24_1)
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

  switch (phase_24_2)
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
  int weight_62_1 = local_arr_1[aux_1 % 3];
  int weight_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_62_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_88_1 == parity_88_2);
  assert(phase_24_1 == phase_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_62_1 == weight_62_2);
}

int fn_R000909_913_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000909_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int parity_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_88) & 63;
  acc ^= aux;
  int phase_24 = (aux + st.buffer[1]) & 3;
  switch (phase_24)
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
  int weight_62 = local_arr[aux % 3];
  acc = (acc + (weight_62 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000909_913_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st_1 = {0};
  struct StreamBuffer_R000909_913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_23_1 = local_arr_1[aux_1 % 3];
  int tally_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_23_2 * 2)) & 127;
  int pivot_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_33_1 > 40)
  {
    acc_1 = ((acc_1 + (pivot_33_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_33_2 > 40)
  {
    acc_2 = ((acc_2 + (pivot_33_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_33_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_23_1 == tally_23_2);
  assert(pivot_33_1 == pivot_33_2);
}

int fn_R000909_913_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int tally_23 = local_arr[aux % 3];
  acc = (acc + (tally_23 * 2)) & 127;
  int pivot_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_33 > 40)
  {
    acc = ((acc + (pivot_33 * 2)) + 5) & 127;
    aux ^= pivot_33 & 15;
  }
  else
  {
    acc = ((acc - pivot_33) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000909_913_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st_1 = {0};
  struct MatrixBlock_R000909_913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int window_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_58_1) & 63;
  aux_2 = (aux_2 + window_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_10_1)
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

  switch (offset_10_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_58_1 == window_58_2);
  assert(offset_10_1 == offset_10_2);
}

int fn_R000909_913_8(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int window_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_58) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_10 = (aux + st.buffer[1]) & 3;
  switch (offset_10)
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

void fn_R000909_913_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000909_913_0 st_1 = {0};
  struct DeviceConfig_R000909_913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int anchor_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_98_1 > 23)
  {
    acc_1 = ((acc_1 + (anchor_98_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_98_2 > 23)
  {
    acc_2 = ((acc_2 + (anchor_98_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_47_1) & 63;
  aux_2 = (aux_2 + sample_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_77_1 = local_arr_1[aux_1 % 3];
  int threshold_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_98_1 == anchor_98_2);
  assert(sample_47_1 == sample_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_77_1 == threshold_77_2);
}

int fn_R000909_913_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000909_913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int anchor_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_98 > 23)
  {
    acc = ((acc + (anchor_98 * 2)) + 5) & 127;
    aux ^= anchor_98 & 15;
  }
  else
  {
    acc = ((acc - anchor_98) + 11) & 127;
    aux += 3;
  }
  int sample_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_47) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_77 = local_arr[aux % 3];
  acc = (acc + (threshold_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000909_913_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st_1 = {0};
  struct StreamBuffer_R000909_913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int offset_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_51_1)
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

  switch (offset_51_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_64_1) & 63;
  aux_2 = (aux_2 + damping_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_95_1 = local_arr_1[aux_1 % 3];
  int segment_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_51_1 == offset_51_2);
  assert(damping_64_1 == damping_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_95_1 == segment_95_2);
}

int fn_R000909_913_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int offset_51 = (aux + st.buffer[1]) & 3;
  switch (offset_51)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_64) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_95 = local_arr[aux % 3];
  acc = (acc + (segment_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000909_913_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st_1 = {0};
  struct StreamBuffer_R000909_913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int checksum_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_35_1 > 29)
  {
    acc_1 = ((acc_1 + (checksum_35_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_35_2 > 29)
  {
    acc_2 = ((acc_2 + (checksum_35_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_35_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_35_1 == checksum_35_2);
}

int fn_R000909_913_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int checksum_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_35 > 29)
  {
    acc = ((acc + (checksum_35 * 2)) + 5) & 127;
    aux ^= checksum_35 & 15;
  }
  else
  {
    acc = ((acc - checksum_35) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000909_913_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000909_913_1 st_1 = {0};
  struct CipherContext_R000909_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int damping_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_11_1 > 31)
  {
    acc_1 = ((acc_1 + (damping_11_1 * 2)) + 5) & 127;
    aux_1 ^= damping_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_11_2 > 31)
  {
    acc_2 = ((acc_2 + (damping_11_2 * 2)) + 5) & 127;
    aux_2 ^= damping_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_98_1)
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

  switch (delta_98_2)
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

  int accumulator_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_62_1) & 63;
  aux_2 = (aux_2 + accumulator_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_75_1 = local_arr_1[aux_1 % 3];
  int residue_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_75_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_11_1 == damping_11_2);
  assert(delta_98_1 == delta_98_2);
  assert(accumulator_62_1 == accumulator_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_75_1 == residue_75_2);
}

int fn_R000909_913_12(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000909_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int damping_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_11 > 31)
  {
    acc = ((acc + (damping_11 * 2)) + 5) & 127;
    aux ^= damping_11 & 15;
  }
  else
  {
    acc = ((acc - damping_11) + 11) & 127;
    aux += 3;
  }
  int delta_98 = (aux + st.buffer[1]) & 3;
  switch (delta_98)
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

  int accumulator_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_62) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_75 = local_arr[aux % 3];
  acc = (acc + (residue_75 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000909_913_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st_1 = {0};
  struct MatrixBlock_R000909_913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int segment_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_30_1) & 63;
  aux_2 = (aux_2 + segment_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_10_1)
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

  switch (phase_10_2)
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

  int threshold_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_89_1 > 22)
  {
    acc_1 = ((acc_1 + (threshold_89_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_89_2 > 22)
  {
    acc_2 = ((acc_2 + (threshold_89_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_41_1 = local_arr_1[aux_1 % 3];
  int quantum_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_41_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_30_1 == segment_30_2);
  assert(phase_10_1 == phase_10_2);
  assert(threshold_89_1 == threshold_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_41_1 == quantum_41_2);
}

int fn_R000909_913_13(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int segment_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_30) & 63;
  acc ^= aux;
  int phase_10 = (aux + st.buffer[1]) & 3;
  switch (phase_10)
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

  int threshold_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_89 > 22)
  {
    acc = ((acc + (threshold_89 * 2)) + 5) & 127;
    aux ^= threshold_89 & 15;
  }
  else
  {
    acc = ((acc - threshold_89) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_41 = local_arr[aux % 3];
  acc = (acc + (quantum_41 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000909_913_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000909_913_1 st_1 = {0};
  struct CipherContext_R000909_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quantum_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_42_1)
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

  switch (quantum_42_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_93_1 = local_arr_1[aux_1 % 3];
  int coefficient_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_93_2 * 2)) & 127;
  int factor_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_42_1 > 20)
  {
    acc_1 = ((acc_1 + (factor_42_1 * 2)) + 5) & 127;
    aux_1 ^= factor_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_42_2 > 20)
  {
    acc_2 = ((acc_2 + (factor_42_2 * 2)) + 5) & 127;
    aux_2 ^= factor_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_42_1 == quantum_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_93_1 == coefficient_93_2);
  assert(factor_42_1 == factor_42_2);
}

int fn_R000909_913_14(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000909_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quantum_42 = (aux + st.buffer[1]) & 3;
  switch (quantum_42)
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

  int local_arr[3] = {4, 9, 15};
  int coefficient_93 = local_arr[aux % 3];
  acc = (acc + (coefficient_93 * 2)) & 127;
  int factor_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_42 > 20)
  {
    acc = ((acc + (factor_42 * 2)) + 5) & 127;
    aux ^= factor_42 & 15;
  }
  else
  {
    acc = ((acc - factor_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000909_913_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st_1 = {0};
  struct MatrixBlock_R000909_913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_18_1 = local_arr_1[aux_1 % 3];
  int margin_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_18_2 * 2)) & 127;
  int index_reg_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_75_1 > 18)
  {
    acc_1 = ((acc_1 + (index_reg_75_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_75_2 > 18)
  {
    acc_2 = ((acc_2 + (index_reg_75_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_12_1)
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

  switch (margin_12_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_18_1 == margin_18_2);
  assert(index_reg_75_1 == index_reg_75_2);
  assert(margin_12_1 == margin_12_2);
}

int fn_R000909_913_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int margin_18 = local_arr[aux % 3];
  acc = (acc + (margin_18 * 2)) & 127;
  int index_reg_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_75 > 18)
  {
    acc = ((acc + (index_reg_75 * 2)) + 5) & 127;
    aux ^= index_reg_75 & 15;
  }
  else
  {
    acc = ((acc - index_reg_75) + 11) & 127;
    aux += 3;
  }
  int margin_12 = (aux + st.buffer[1]) & 3;
  switch (margin_12)
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

void fn_R000909_913_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st_1 = {0};
  struct MatrixBlock_R000909_913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_37_1 = local_arr_1[aux_1 % 3];
  int segment_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_37_2 * 2)) & 127;
  int weight_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_94_1) & 63;
  aux_2 = (aux_2 + weight_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_37_1 == segment_37_2);
  assert(weight_94_1 == weight_94_2);
}

int fn_R000909_913_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int segment_37 = local_arr[aux % 3];
  acc = (acc + (segment_37 * 2)) & 127;
  int weight_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_94) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000909_913_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000909_913_1 st_1 = {0};
  struct CipherContext_R000909_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int tracker_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_64_1 > 16)
  {
    acc_1 = ((acc_1 + (tracker_64_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_64_2 > 16)
  {
    acc_2 = ((acc_2 + (tracker_64_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_23_1) & 63;
  aux_2 = (aux_2 + offset_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_65_1 = local_arr_1[aux_1 % 3];
  int parity_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_65_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_64_1 == tracker_64_2);
  assert(offset_23_1 == offset_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_65_1 == parity_65_2);
}

int fn_R000909_913_17(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000909_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int tracker_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_64 > 16)
  {
    acc = ((acc + (tracker_64 * 2)) + 5) & 127;
    aux ^= tracker_64 & 15;
  }
  else
  {
    acc = ((acc - tracker_64) + 11) & 127;
    aux += 3;
  }
  int offset_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_23) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_65 = local_arr[aux % 3];
  acc = (acc + (parity_65 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000909_913_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000909_913_1 st_1 = {0};
  struct CipherContext_R000909_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int margin_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_55_1 > 24)
  {
    acc_1 = ((acc_1 + (margin_55_1 * 2)) + 5) & 127;
    aux_1 ^= margin_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_55_2 > 24)
  {
    acc_2 = ((acc_2 + (margin_55_2 * 2)) + 5) & 127;
    aux_2 ^= margin_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_95_1)
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

  switch (quotient_95_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_55_1 == margin_55_2);
  assert(quotient_95_1 == quotient_95_2);
}

int fn_R000909_913_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000909_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int margin_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_55 > 24)
  {
    acc = ((acc + (margin_55 * 2)) + 5) & 127;
    aux ^= margin_55 & 15;
  }
  else
  {
    acc = ((acc - margin_55) + 11) & 127;
    aux += 3;
  }
  int quotient_95 = (aux + st.buffer[1]) & 3;
  switch (quotient_95)
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

  return (acc + aux) & 255;
}

void fn_R000909_913_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st_1 = {0};
  struct StreamBuffer_R000909_913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_11_1)
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

  switch (damping_11_2)
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

  int anchor_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_22_1 > 14)
  {
    acc_1 = ((acc_1 + (anchor_22_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_22_2 > 14)
  {
    acc_2 = ((acc_2 + (anchor_22_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_14_1) & 63;
  aux_2 = (aux_2 + weight_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_11_1 == damping_11_2);
  assert(anchor_22_1 == anchor_22_2);
  assert(weight_14_1 == weight_14_2);
}

int fn_R000909_913_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_11 = (aux + st.buffer[1]) & 3;
  switch (damping_11)
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

  int anchor_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_22 > 14)
  {
    acc = ((acc + (anchor_22 * 2)) + 5) & 127;
    aux ^= anchor_22 & 15;
  }
  else
  {
    acc = ((acc - anchor_22) + 11) & 127;
    aux += 3;
  }
  int weight_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_14) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000909_913_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st_1 = {0};
  struct MatrixBlock_R000909_913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int bound_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_63_1)
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

  switch (bound_63_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_63_1 == bound_63_2);
}

int fn_R000909_913_20(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000909_913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int bound_63 = (aux + st.buffer[1]) & 3;
  switch (bound_63)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000909_913_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000909_913_0 st_1 = {0};
  struct DeviceConfig_R000909_913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_48_1 = local_arr_1[aux_1 % 3];
  int stride_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_48_2 * 2)) & 127;
  int tally_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_10_1) & 63;
  aux_2 = (aux_2 + tally_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_48_1 == stride_48_2);
  assert(tally_10_1 == tally_10_2);
}

int fn_R000909_913_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000909_913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int stride_48 = local_arr[aux % 3];
  acc = (acc + (stride_48 * 2)) & 127;
  int tally_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_10) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000909_913_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st_1 = {0};
  struct StreamBuffer_R000909_913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
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
  int cursor_89_1 = local_arr_1[aux_1 % 3];
  int cursor_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_89_2 * 2)) & 127;
  int accumulator_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_95_1)
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

  switch (accumulator_95_2)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_25_1 == checksum_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_89_1 == cursor_89_2);
  assert(accumulator_95_1 == accumulator_95_2);
}

int fn_R000909_913_22(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000909_913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int checksum_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_25) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int cursor_89 = local_arr[aux % 3];
  acc = (acc + (cursor_89 * 2)) & 127;
  int accumulator_95 = (aux + st.buffer[1]) & 3;
  switch (accumulator_95)
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

void fn_R000909_913_23_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000909_913_0 st_1 = {0};
  struct DeviceConfig_R000909_913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int quotient_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_54_1) & 63;
  aux_2 = (aux_2 + quotient_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_54_1 == quotient_54_2);
}

int fn_R000909_913_23(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000909_913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int quotient_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_54) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000909_0_1;
  int sec_r000909_0_2;
  int sec_r000909_1_1;
  int sec_r000909_1_2;
  int sec_r000909_2_1;
  int sec_r000909_2_2;
  int sec_r000909_3_1;
  int sec_r000909_3_2;
  int sec_r000909_4_1;
  int sec_r000909_4_2;
  int sec_r000909_5_1;
  int sec_r000909_5_2;
  int sec_r000909_6_1;
  int sec_r000909_6_2;
  int sec_r000909_7_1;
  int sec_r000909_7_2;
  int sec_r000909_8_1;
  int sec_r000909_8_2;
  int sec_r000909_9_1;
  int sec_r000909_9_2;
  int sec_r000909_10_1;
  int sec_r000909_10_2;
  int sec_r000909_11_1;
  int sec_r000909_11_2;
  int sec_r000909_12_1;
  int sec_r000909_12_2;
  int sec_r000909_13_1;
  int sec_r000909_13_2;
  int sec_r000909_14_1;
  int sec_r000909_14_2;
  int sec_r000909_15_1;
  int sec_r000909_15_2;
  int sec_r000909_16_1;
  int sec_r000909_16_2;
  int sec_r000909_17_1;
  int sec_r000909_17_2;
  int sec_r000909_18_1;
  int sec_r000909_18_2;
  int sec_r000909_19_1;
  int sec_r000909_19_2;
  int sec_r000909_20_1;
  int sec_r000909_20_2;
  int pub_r000909_0_1;
  int pub_r000909_0_2;
  int pub_r000909_1_1;
  int pub_r000909_1_2;
  int pub_r000909_2_1;
  int pub_r000909_2_2;
  int pub_r000909_3_1;
  int pub_r000909_3_2;
  int pub_r000909_4_1;
  int pub_r000909_4_2;
  int pub_r000909_5_1;
  int pub_r000909_5_2;
  int pub_r000909_6_1;
  int pub_r000909_6_2;
  int pub_r000909_7_1;
  int pub_r000909_7_2;
  int pub_r000909_8_1;
  int pub_r000909_8_2;
  int pub_r000909_9_1;
  int pub_r000909_9_2;
  int pub_r000909_10_1;
  int pub_r000909_10_2;
  int pub_r000909_11_1;
  int pub_r000909_11_2;
  int pub_r000909_12_1;
  int pub_r000909_12_2;
  int pub_r000909_13_1;
  int pub_r000909_13_2;
  int pub_r000909_14_1;
  int pub_r000909_14_2;
  int pub_r000909_15_1;
  int pub_r000909_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000909_0_1 >= (-100)) && (pub_r000909_0_1 <= 100));
  __CPROVER_assume((pub_r000909_0_2 >= (-100)) && (pub_r000909_0_2 <= 100));
  __CPROVER_assume((pub_r000909_1_1 >= (-100)) && (pub_r000909_1_1 <= 100));
  __CPROVER_assume((pub_r000909_1_2 >= (-100)) && (pub_r000909_1_2 <= 100));
  __CPROVER_assume((pub_r000909_2_1 >= (-100)) && (pub_r000909_2_1 <= 100));
  __CPROVER_assume((pub_r000909_2_2 >= (-100)) && (pub_r000909_2_2 <= 100));
  __CPROVER_assume((pub_r000909_3_1 >= (-100)) && (pub_r000909_3_1 <= 100));
  __CPROVER_assume((pub_r000909_3_2 >= (-100)) && (pub_r000909_3_2 <= 100));
  __CPROVER_assume((pub_r000909_4_1 >= (-100)) && (pub_r000909_4_1 <= 100));
  __CPROVER_assume((pub_r000909_4_2 >= (-100)) && (pub_r000909_4_2 <= 100));
  __CPROVER_assume((pub_r000909_5_1 >= (-100)) && (pub_r000909_5_1 <= 100));
  __CPROVER_assume((pub_r000909_5_2 >= (-100)) && (pub_r000909_5_2 <= 100));
  __CPROVER_assume((pub_r000909_6_1 >= (-100)) && (pub_r000909_6_1 <= 100));
  __CPROVER_assume((pub_r000909_6_2 >= (-100)) && (pub_r000909_6_2 <= 100));
  __CPROVER_assume((pub_r000909_7_1 >= (-100)) && (pub_r000909_7_1 <= 100));
  __CPROVER_assume((pub_r000909_7_2 >= (-100)) && (pub_r000909_7_2 <= 100));
  __CPROVER_assume((pub_r000909_8_1 >= (-100)) && (pub_r000909_8_1 <= 100));
  __CPROVER_assume((pub_r000909_8_2 >= (-100)) && (pub_r000909_8_2 <= 100));
  __CPROVER_assume((pub_r000909_9_1 >= (-100)) && (pub_r000909_9_1 <= 100));
  __CPROVER_assume((pub_r000909_9_2 >= (-100)) && (pub_r000909_9_2 <= 100));
  __CPROVER_assume((pub_r000909_10_1 >= (-100)) && (pub_r000909_10_1 <= 100));
  __CPROVER_assume((pub_r000909_10_2 >= (-100)) && (pub_r000909_10_2 <= 100));
  __CPROVER_assume((pub_r000909_11_1 >= (-100)) && (pub_r000909_11_1 <= 100));
  __CPROVER_assume((pub_r000909_11_2 >= (-100)) && (pub_r000909_11_2 <= 100));
  __CPROVER_assume((pub_r000909_12_1 >= (-100)) && (pub_r000909_12_1 <= 100));
  __CPROVER_assume((pub_r000909_12_2 >= (-100)) && (pub_r000909_12_2 <= 100));
  __CPROVER_assume((pub_r000909_13_1 >= (-100)) && (pub_r000909_13_1 <= 100));
  __CPROVER_assume((pub_r000909_13_2 >= (-100)) && (pub_r000909_13_2 <= 100));
  __CPROVER_assume((pub_r000909_14_1 >= (-100)) && (pub_r000909_14_1 <= 100));
  __CPROVER_assume((pub_r000909_14_2 >= (-100)) && (pub_r000909_14_2 <= 100));
  __CPROVER_assume((pub_r000909_15_1 >= (-100)) && (pub_r000909_15_1 <= 100));
  __CPROVER_assume((pub_r000909_15_2 >= (-100)) && (pub_r000909_15_2 <= 100));
  __CPROVER_assume((sec_r000909_0_1 >= 0) && (sec_r000909_0_1 <= 255));
  __CPROVER_assume((sec_r000909_0_2 >= 0) && (sec_r000909_0_2 <= 255));
  __CPROVER_assume((sec_r000909_1_1 >= 0) && (sec_r000909_1_1 <= 255));
  __CPROVER_assume((sec_r000909_1_2 >= 0) && (sec_r000909_1_2 <= 255));
  __CPROVER_assume((sec_r000909_2_1 >= 0) && (sec_r000909_2_1 <= 255));
  __CPROVER_assume((sec_r000909_2_2 >= 0) && (sec_r000909_2_2 <= 255));
  __CPROVER_assume((sec_r000909_3_1 >= 0) && (sec_r000909_3_1 <= 255));
  __CPROVER_assume((sec_r000909_3_2 >= 0) && (sec_r000909_3_2 <= 255));
  __CPROVER_assume((sec_r000909_4_1 >= 0) && (sec_r000909_4_1 <= 255));
  __CPROVER_assume((sec_r000909_4_2 >= 0) && (sec_r000909_4_2 <= 255));
  __CPROVER_assume((sec_r000909_5_1 >= 0) && (sec_r000909_5_1 <= 255));
  __CPROVER_assume((sec_r000909_5_2 >= 0) && (sec_r000909_5_2 <= 255));
  __CPROVER_assume((sec_r000909_6_1 >= 0) && (sec_r000909_6_1 <= 255));
  __CPROVER_assume((sec_r000909_6_2 >= 0) && (sec_r000909_6_2 <= 255));
  __CPROVER_assume((sec_r000909_7_1 >= 0) && (sec_r000909_7_1 <= 255));
  __CPROVER_assume((sec_r000909_7_2 >= 0) && (sec_r000909_7_2 <= 255));
  __CPROVER_assume((sec_r000909_8_1 >= 0) && (sec_r000909_8_1 <= 255));
  __CPROVER_assume((sec_r000909_8_2 >= 0) && (sec_r000909_8_2 <= 255));
  __CPROVER_assume((sec_r000909_9_1 >= 0) && (sec_r000909_9_1 <= 255));
  __CPROVER_assume((sec_r000909_9_2 >= 0) && (sec_r000909_9_2 <= 255));
  __CPROVER_assume((sec_r000909_10_1 >= 0) && (sec_r000909_10_1 <= 255));
  __CPROVER_assume((sec_r000909_10_2 >= 0) && (sec_r000909_10_2 <= 255));
  __CPROVER_assume((sec_r000909_11_1 >= 0) && (sec_r000909_11_1 <= 255));
  __CPROVER_assume((sec_r000909_11_2 >= 0) && (sec_r000909_11_2 <= 255));
  __CPROVER_assume((sec_r000909_12_1 >= 0) && (sec_r000909_12_1 <= 255));
  __CPROVER_assume((sec_r000909_12_2 >= 0) && (sec_r000909_12_2 <= 255));
  __CPROVER_assume((sec_r000909_13_1 >= 0) && (sec_r000909_13_1 <= 255));
  __CPROVER_assume((sec_r000909_13_2 >= 0) && (sec_r000909_13_2 <= 255));
  __CPROVER_assume((sec_r000909_14_1 >= 0) && (sec_r000909_14_1 <= 255));
  __CPROVER_assume((sec_r000909_14_2 >= 0) && (sec_r000909_14_2 <= 255));
  __CPROVER_assume((sec_r000909_15_1 >= 0) && (sec_r000909_15_1 <= 255));
  __CPROVER_assume((sec_r000909_15_2 >= 0) && (sec_r000909_15_2 <= 255));
  __CPROVER_assume((sec_r000909_16_1 >= 0) && (sec_r000909_16_1 <= 255));
  __CPROVER_assume((sec_r000909_16_2 >= 0) && (sec_r000909_16_2 <= 255));
  __CPROVER_assume((sec_r000909_17_1 >= 0) && (sec_r000909_17_1 <= 255));
  __CPROVER_assume((sec_r000909_17_2 >= 0) && (sec_r000909_17_2 <= 255));
  __CPROVER_assume((sec_r000909_18_1 >= 0) && (sec_r000909_18_1 <= 255));
  __CPROVER_assume((sec_r000909_18_2 >= 0) && (sec_r000909_18_2 <= 255));
  __CPROVER_assume((sec_r000909_19_1 >= 0) && (sec_r000909_19_1 <= 255));
  __CPROVER_assume((sec_r000909_19_2 >= 0) && (sec_r000909_19_2 <= 255));
  __CPROVER_assume((sec_r000909_20_1 >= 0) && (sec_r000909_20_1 <= 255));
  __CPROVER_assume((sec_r000909_20_2 >= 0) && (sec_r000909_20_2 <= 255));
  struct DeviceConfig_R000909_913_0 st_var_0_1 = {0};
  struct DeviceConfig_R000909_913_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000909_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000909_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000909_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000909_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000909_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000909_0_2 + 7) & 15;
  struct CipherContext_R000909_913_1 st_var_1_1 = {0};
  struct CipherContext_R000909_913_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000909_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000909_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000909_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000909_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000909_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000909_0_2 + 9) & 15;
  struct StreamBuffer_R000909_913_2 st_var_2_1 = {0};
  struct StreamBuffer_R000909_913_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000909_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000909_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000909_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000909_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000909_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000909_0_2 + 11) & 15;
  struct MatrixBlock_R000909_913_3 st_var_3_1 = {0};
  struct MatrixBlock_R000909_913_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000909_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000909_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000909_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000909_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000909_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000909_0_2 + 13) & 15;
  union RegisterBank_R000909_913_0 u_var_1;
  union RegisterBank_R000909_913_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_0_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_0_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_0_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_6_1 = (st_var_2_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_2_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 45)
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
  if (stage_v_8_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 45)
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
  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 40)
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
  if (stage_v_9_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 40)
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
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 11) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = ((st_var_3_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_3_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 29)
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
  if (stage_v_11_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 29)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  int stage_v_17_1 = ((st_var_1_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_1_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 31)
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
  if (stage_v_17_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 31)
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
  int stage_v_18_1 = ((st_var_2_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_2_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 47)
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
  if (stage_v_18_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 47)
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
  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 23) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
  int stage_v_23_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_23_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 38)
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
  if (stage_v_25_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 38)
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
  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 54)
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
  if (stage_v_26_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 54)
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
  int stage_v_27_1 = (st_var_3_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_3_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = (st_var_0_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_0_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = (st_var_1_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_1_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 31) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 32) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
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
  int s_idx_33_1 = sec_r000909_7_1 & 3;
  int s_idx_33_2 = sec_r000909_7_2 & 3;
  int stage_v_33_1 = (table_1[s_idx_33_1] + pub_r000909_13_1) & 127;
  int stage_v_33_2 = (table_2[s_idx_33_2] + pub_r000909_13_2) & 127;
  table_1[s_idx_33_1] = (stage_v_33_1 + 7) & 63;
  table_2[s_idx_33_2] = (stage_v_33_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int s_idx_34_1 = sec_r000909_9_1 & 3;
  int s_idx_34_2 = sec_r000909_9_2 & 3;
  int stage_v_34_1 = (table_1[s_idx_34_1] + pub_r000909_0_1) & 127;
  int stage_v_34_2 = (table_2[s_idx_34_2] + pub_r000909_0_2) & 127;
  table_1[s_idx_34_1] = (stage_v_34_1 + 7) & 63;
  table_2[s_idx_34_2] = (stage_v_34_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int s_idx_35_1 = stage_v_34_1 & 3;
  int s_idx_35_2 = stage_v_34_2 & 3;
  int stage_v_35_1 = (table_1[s_idx_35_1] + pub_r000909_10_1) & 127;
  int stage_v_35_2 = (table_2[s_idx_35_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_35_1] = (stage_v_35_1 + 7) & 63;
  table_2[s_idx_35_2] = (stage_v_35_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int s_idx_36_1 = stage_v_34_1 & 3;
  int s_idx_36_2 = stage_v_34_2 & 3;
  int stage_v_36_1 = (table_1[s_idx_36_1] + pub_r000909_1_1) & 127;
  int stage_v_36_2 = (table_2[s_idx_36_2] + pub_r000909_1_2) & 127;
  table_1[s_idx_36_1] = (stage_v_36_1 + 7) & 63;
  table_2[s_idx_36_2] = (stage_v_36_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int s_idx_37_1 = stage_v_36_1 & 3;
  int s_idx_37_2 = stage_v_36_2 & 3;
  int stage_v_37_1 = (table_1[s_idx_37_1] + pub_r000909_3_1) & 127;
  int stage_v_37_2 = (table_2[s_idx_37_2] + pub_r000909_3_2) & 127;
  table_1[s_idx_37_1] = (stage_v_37_1 + 7) & 63;
  table_2[s_idx_37_2] = (stage_v_37_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int s_idx_38_1 = sec_r000909_0_1 & 3;
  int s_idx_38_2 = sec_r000909_0_2 & 3;
  int stage_v_38_1 = (table_1[s_idx_38_1] + pub_r000909_4_1) & 127;
  int stage_v_38_2 = (table_2[s_idx_38_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_38_1] = (stage_v_38_1 + 7) & 63;
  table_2[s_idx_38_2] = (stage_v_38_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int s_idx_39_1 = sec_r000909_7_1 & 3;
  int s_idx_39_2 = sec_r000909_7_2 & 3;
  int stage_v_39_1 = (table_1[s_idx_39_1] + pub_r000909_10_1) & 127;
  int stage_v_39_2 = (table_2[s_idx_39_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_39_1] = (stage_v_39_1 + 7) & 63;
  table_2[s_idx_39_2] = (stage_v_39_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int s_idx_40_1 = sec_r000909_20_1 & 3;
  int s_idx_40_2 = sec_r000909_20_2 & 3;
  int stage_v_40_1 = (table_1[s_idx_40_1] + pub_r000909_5_1) & 127;
  int stage_v_40_2 = (table_2[s_idx_40_2] + pub_r000909_5_2) & 127;
  table_1[s_idx_40_1] = (stage_v_40_1 + 7) & 63;
  table_2[s_idx_40_2] = (stage_v_40_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int s_idx_41_1 = sec_r000909_3_1 & 3;
  int s_idx_41_2 = sec_r000909_3_2 & 3;
  int stage_v_41_1 = (table_1[s_idx_41_1] + pub_r000909_4_1) & 127;
  int stage_v_41_2 = (table_2[s_idx_41_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_41_1] = (stage_v_41_1 + 7) & 63;
  table_2[s_idx_41_2] = (stage_v_41_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int s_idx_42_1 = stage_v_38_1 & 3;
  int s_idx_42_2 = stage_v_38_2 & 3;
  int stage_v_42_1 = (table_1[s_idx_42_1] + pub_r000909_12_1) & 127;
  int stage_v_42_2 = (table_2[s_idx_42_2] + pub_r000909_12_2) & 127;
  table_1[s_idx_42_1] = (stage_v_42_1 + 7) & 63;
  table_2[s_idx_42_2] = (stage_v_42_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int s_idx_43_1 = stage_v_34_1 & 3;
  int s_idx_43_2 = stage_v_34_2 & 3;
  int stage_v_43_1 = (table_1[s_idx_43_1] + pub_r000909_9_1) & 127;
  int stage_v_43_2 = (table_2[s_idx_43_2] + pub_r000909_9_2) & 127;
  table_1[s_idx_43_1] = (stage_v_43_1 + 7) & 63;
  table_2[s_idx_43_2] = (stage_v_43_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int s_idx_44_1 = sec_r000909_16_1 & 3;
  int s_idx_44_2 = sec_r000909_16_2 & 3;
  int stage_v_44_1 = (table_1[s_idx_44_1] + pub_r000909_5_1) & 127;
  int stage_v_44_2 = (table_2[s_idx_44_2] + pub_r000909_5_2) & 127;
  table_1[s_idx_44_1] = (stage_v_44_1 + 7) & 63;
  table_2[s_idx_44_2] = (stage_v_44_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int s_idx_45_1 = sec_r000909_13_1 & 3;
  int s_idx_45_2 = sec_r000909_13_2 & 3;
  int stage_v_45_1 = (table_1[s_idx_45_1] + pub_r000909_13_1) & 127;
  int stage_v_45_2 = (table_2[s_idx_45_2] + pub_r000909_13_2) & 127;
  table_1[s_idx_45_1] = (stage_v_45_1 + 7) & 63;
  table_2[s_idx_45_2] = (stage_v_45_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int s_idx_46_1 = sec_r000909_1_1 & 3;
  int s_idx_46_2 = sec_r000909_1_2 & 3;
  int stage_v_46_1 = (table_1[s_idx_46_1] + pub_r000909_11_1) & 127;
  int stage_v_46_2 = (table_2[s_idx_46_2] + pub_r000909_11_2) & 127;
  table_1[s_idx_46_1] = (stage_v_46_1 + 7) & 63;
  table_2[s_idx_46_2] = (stage_v_46_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int s_idx_47_1 = sec_r000909_6_1 & 3;
  int s_idx_47_2 = sec_r000909_6_2 & 3;
  int stage_v_47_1 = (table_1[s_idx_47_1] + pub_r000909_2_1) & 127;
  int stage_v_47_2 = (table_2[s_idx_47_2] + pub_r000909_2_2) & 127;
  table_1[s_idx_47_1] = (stage_v_47_1 + 7) & 63;
  table_2[s_idx_47_2] = (stage_v_47_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int s_idx_48_1 = stage_v_38_1 & 3;
  int s_idx_48_2 = stage_v_38_2 & 3;
  int stage_v_48_1 = (table_1[s_idx_48_1] + pub_r000909_6_1) & 127;
  int stage_v_48_2 = (table_2[s_idx_48_2] + pub_r000909_6_2) & 127;
  table_1[s_idx_48_1] = (stage_v_48_1 + 7) & 63;
  table_2[s_idx_48_2] = (stage_v_48_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int s_idx_49_1 = sec_r000909_3_1 & 3;
  int s_idx_49_2 = sec_r000909_3_2 & 3;
  int stage_v_49_1 = (table_1[s_idx_49_1] + pub_r000909_10_1) & 127;
  int stage_v_49_2 = (table_2[s_idx_49_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_49_1] = (stage_v_49_1 + 7) & 63;
  table_2[s_idx_49_2] = (stage_v_49_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int s_idx_50_1 = stage_v_46_1 & 3;
  int s_idx_50_2 = stage_v_46_2 & 3;
  int stage_v_50_1 = (table_1[s_idx_50_1] + pub_r000909_3_1) & 127;
  int stage_v_50_2 = (table_2[s_idx_50_2] + pub_r000909_3_2) & 127;
  table_1[s_idx_50_1] = (stage_v_50_1 + 7) & 63;
  table_2[s_idx_50_2] = (stage_v_50_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int s_idx_51_1 = sec_r000909_10_1 & 3;
  int s_idx_51_2 = sec_r000909_10_2 & 3;
  int stage_v_51_1 = (table_1[s_idx_51_1] + pub_r000909_3_1) & 127;
  int stage_v_51_2 = (table_2[s_idx_51_2] + pub_r000909_3_2) & 127;
  table_1[s_idx_51_1] = (stage_v_51_1 + 7) & 63;
  table_2[s_idx_51_2] = (stage_v_51_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int s_idx_52_1 = stage_v_46_1 & 3;
  int s_idx_52_2 = stage_v_46_2 & 3;
  int stage_v_52_1 = (table_1[s_idx_52_1] + pub_r000909_5_1) & 127;
  int stage_v_52_2 = (table_2[s_idx_52_2] + pub_r000909_5_2) & 127;
  table_1[s_idx_52_1] = (stage_v_52_1 + 7) & 63;
  table_2[s_idx_52_2] = (stage_v_52_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int s_idx_53_1 = sec_r000909_5_1 & 3;
  int s_idx_53_2 = sec_r000909_5_2 & 3;
  int stage_v_53_1 = (table_1[s_idx_53_1] + pub_r000909_7_1) & 127;
  int stage_v_53_2 = (table_2[s_idx_53_2] + pub_r000909_7_2) & 127;
  table_1[s_idx_53_1] = (stage_v_53_1 + 7) & 63;
  table_2[s_idx_53_2] = (stage_v_53_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int s_idx_54_1 = sec_r000909_9_1 & 3;
  int s_idx_54_2 = sec_r000909_9_2 & 3;
  int stage_v_54_1 = (table_1[s_idx_54_1] + pub_r000909_1_1) & 127;
  int stage_v_54_2 = (table_2[s_idx_54_2] + pub_r000909_1_2) & 127;
  table_1[s_idx_54_1] = (stage_v_54_1 + 7) & 63;
  table_2[s_idx_54_2] = (stage_v_54_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int s_idx_55_1 = stage_v_45_1 & 3;
  int s_idx_55_2 = stage_v_45_2 & 3;
  int stage_v_55_1 = (table_1[s_idx_55_1] + pub_r000909_1_1) & 127;
  int stage_v_55_2 = (table_2[s_idx_55_2] + pub_r000909_1_2) & 127;
  table_1[s_idx_55_1] = (stage_v_55_1 + 7) & 63;
  table_2[s_idx_55_2] = (stage_v_55_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int s_idx_56_1 = stage_v_52_1 & 3;
  int s_idx_56_2 = stage_v_52_2 & 3;
  int stage_v_56_1 = (table_1[s_idx_56_1] + pub_r000909_8_1) & 127;
  int stage_v_56_2 = (table_2[s_idx_56_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_56_1] = (stage_v_56_1 + 7) & 63;
  table_2[s_idx_56_2] = (stage_v_56_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int s_idx_57_1 = stage_v_54_1 & 3;
  int s_idx_57_2 = stage_v_54_2 & 3;
  int stage_v_57_1 = (table_1[s_idx_57_1] + pub_r000909_8_1) & 127;
  int stage_v_57_2 = (table_2[s_idx_57_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_57_1] = (stage_v_57_1 + 7) & 63;
  table_2[s_idx_57_2] = (stage_v_57_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int s_idx_58_1 = sec_r000909_19_1 & 3;
  int s_idx_58_2 = sec_r000909_19_2 & 3;
  int stage_v_58_1 = (table_1[s_idx_58_1] + pub_r000909_8_1) & 127;
  int stage_v_58_2 = (table_2[s_idx_58_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_58_1] = (stage_v_58_1 + 7) & 63;
  table_2[s_idx_58_2] = (stage_v_58_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int s_idx_59_1 = stage_v_55_1 & 3;
  int s_idx_59_2 = stage_v_55_2 & 3;
  int stage_v_59_1 = (table_1[s_idx_59_1] + pub_r000909_6_1) & 127;
  int stage_v_59_2 = (table_2[s_idx_59_2] + pub_r000909_6_2) & 127;
  table_1[s_idx_59_1] = (stage_v_59_1 + 7) & 63;
  table_2[s_idx_59_2] = (stage_v_59_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int s_idx_60_1 = sec_r000909_16_1 & 3;
  int s_idx_60_2 = sec_r000909_16_2 & 3;
  int stage_v_60_1 = (table_1[s_idx_60_1] + pub_r000909_5_1) & 127;
  int stage_v_60_2 = (table_2[s_idx_60_2] + pub_r000909_5_2) & 127;
  table_1[s_idx_60_1] = (stage_v_60_1 + 7) & 63;
  table_2[s_idx_60_2] = (stage_v_60_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int s_idx_61_1 = stage_v_58_1 & 3;
  int s_idx_61_2 = stage_v_58_2 & 3;
  int stage_v_61_1 = (table_1[s_idx_61_1] + pub_r000909_7_1) & 127;
  int stage_v_61_2 = (table_2[s_idx_61_2] + pub_r000909_7_2) & 127;
  table_1[s_idx_61_1] = (stage_v_61_1 + 7) & 63;
  table_2[s_idx_61_2] = (stage_v_61_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int s_idx_62_1 = sec_r000909_13_1 & 3;
  int s_idx_62_2 = sec_r000909_13_2 & 3;
  int stage_v_62_1 = (table_1[s_idx_62_1] + pub_r000909_7_1) & 127;
  int stage_v_62_2 = (table_2[s_idx_62_2] + pub_r000909_7_2) & 127;
  table_1[s_idx_62_1] = (stage_v_62_1 + 7) & 63;
  table_2[s_idx_62_2] = (stage_v_62_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int s_idx_63_1 = stage_v_35_1 & 3;
  int s_idx_63_2 = stage_v_35_2 & 3;
  int stage_v_63_1 = (table_1[s_idx_63_1] + pub_r000909_15_1) & 127;
  int stage_v_63_2 = (table_2[s_idx_63_2] + pub_r000909_15_2) & 127;
  table_1[s_idx_63_1] = (stage_v_63_1 + 7) & 63;
  table_2[s_idx_63_2] = (stage_v_63_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int s_idx_64_1 = stage_v_45_1 & 3;
  int s_idx_64_2 = stage_v_45_2 & 3;
  int stage_v_64_1 = (table_1[s_idx_64_1] + pub_r000909_10_1) & 127;
  int stage_v_64_2 = (table_2[s_idx_64_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_64_1] = (stage_v_64_1 + 7) & 63;
  table_2[s_idx_64_2] = (stage_v_64_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int s_idx_65_1 = sec_r000909_1_1 & 3;
  int s_idx_65_2 = sec_r000909_1_2 & 3;
  int stage_v_65_1 = (table_1[s_idx_65_1] + pub_r000909_6_1) & 127;
  int stage_v_65_2 = (table_2[s_idx_65_2] + pub_r000909_6_2) & 127;
  table_1[s_idx_65_1] = (stage_v_65_1 + 7) & 63;
  table_2[s_idx_65_2] = (stage_v_65_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int s_idx_66_1 = stage_v_44_1 & 3;
  int s_idx_66_2 = stage_v_44_2 & 3;
  int stage_v_66_1 = (table_1[s_idx_66_1] + pub_r000909_6_1) & 127;
  int stage_v_66_2 = (table_2[s_idx_66_2] + pub_r000909_6_2) & 127;
  table_1[s_idx_66_1] = (stage_v_66_1 + 7) & 63;
  table_2[s_idx_66_2] = (stage_v_66_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int s_idx_67_1 = stage_v_57_1 & 3;
  int s_idx_67_2 = stage_v_57_2 & 3;
  int stage_v_67_1 = (table_1[s_idx_67_1] + pub_r000909_7_1) & 127;
  int stage_v_67_2 = (table_2[s_idx_67_2] + pub_r000909_7_2) & 127;
  table_1[s_idx_67_1] = (stage_v_67_1 + 7) & 63;
  table_2[s_idx_67_2] = (stage_v_67_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int s_idx_68_1 = stage_v_64_1 & 3;
  int s_idx_68_2 = stage_v_64_2 & 3;
  int stage_v_68_1 = (table_1[s_idx_68_1] + pub_r000909_5_1) & 127;
  int stage_v_68_2 = (table_2[s_idx_68_2] + pub_r000909_5_2) & 127;
  table_1[s_idx_68_1] = (stage_v_68_1 + 7) & 63;
  table_2[s_idx_68_2] = (stage_v_68_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int s_idx_69_1 = stage_v_60_1 & 3;
  int s_idx_69_2 = stage_v_60_2 & 3;
  int stage_v_69_1 = (table_1[s_idx_69_1] + pub_r000909_5_1) & 127;
  int stage_v_69_2 = (table_2[s_idx_69_2] + pub_r000909_5_2) & 127;
  table_1[s_idx_69_1] = (stage_v_69_1 + 7) & 63;
  table_2[s_idx_69_2] = (stage_v_69_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int s_idx_70_1 = sec_r000909_15_1 & 3;
  int s_idx_70_2 = sec_r000909_15_2 & 3;
  int stage_v_70_1 = (table_1[s_idx_70_1] + pub_r000909_1_1) & 127;
  int stage_v_70_2 = (table_2[s_idx_70_2] + pub_r000909_1_2) & 127;
  table_1[s_idx_70_1] = (stage_v_70_1 + 7) & 63;
  table_2[s_idx_70_2] = (stage_v_70_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int s_idx_71_1 = stage_v_53_1 & 3;
  int s_idx_71_2 = stage_v_53_2 & 3;
  int stage_v_71_1 = (table_1[s_idx_71_1] + pub_r000909_8_1) & 127;
  int stage_v_71_2 = (table_2[s_idx_71_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_71_1] = (stage_v_71_1 + 7) & 63;
  table_2[s_idx_71_2] = (stage_v_71_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int s_idx_72_1 = stage_v_47_1 & 3;
  int s_idx_72_2 = stage_v_47_2 & 3;
  int stage_v_72_1 = (table_1[s_idx_72_1] + pub_r000909_11_1) & 127;
  int stage_v_72_2 = (table_2[s_idx_72_2] + pub_r000909_11_2) & 127;
  table_1[s_idx_72_1] = (stage_v_72_1 + 7) & 63;
  table_2[s_idx_72_2] = (stage_v_72_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int s_idx_73_1 = sec_r000909_3_1 & 3;
  int s_idx_73_2 = sec_r000909_3_2 & 3;
  int stage_v_73_1 = (table_1[s_idx_73_1] + pub_r000909_15_1) & 127;
  int stage_v_73_2 = (table_2[s_idx_73_2] + pub_r000909_15_2) & 127;
  table_1[s_idx_73_1] = (stage_v_73_1 + 7) & 63;
  table_2[s_idx_73_2] = (stage_v_73_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int s_idx_74_1 = sec_r000909_15_1 & 3;
  int s_idx_74_2 = sec_r000909_15_2 & 3;
  int stage_v_74_1 = (table_1[s_idx_74_1] + pub_r000909_12_1) & 127;
  int stage_v_74_2 = (table_2[s_idx_74_2] + pub_r000909_12_2) & 127;
  table_1[s_idx_74_1] = (stage_v_74_1 + 7) & 63;
  table_2[s_idx_74_2] = (stage_v_74_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int s_idx_75_1 = stage_v_56_1 & 3;
  int s_idx_75_2 = stage_v_56_2 & 3;
  int stage_v_75_1 = (table_1[s_idx_75_1] + pub_r000909_9_1) & 127;
  int stage_v_75_2 = (table_2[s_idx_75_2] + pub_r000909_9_2) & 127;
  table_1[s_idx_75_1] = (stage_v_75_1 + 7) & 63;
  table_2[s_idx_75_2] = (stage_v_75_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int s_idx_76_1 = stage_v_38_1 & 3;
  int s_idx_76_2 = stage_v_38_2 & 3;
  int stage_v_76_1 = (table_1[s_idx_76_1] + pub_r000909_4_1) & 127;
  int stage_v_76_2 = (table_2[s_idx_76_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_76_1] = (stage_v_76_1 + 7) & 63;
  table_2[s_idx_76_2] = (stage_v_76_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int s_idx_77_1 = sec_r000909_11_1 & 3;
  int s_idx_77_2 = sec_r000909_11_2 & 3;
  int stage_v_77_1 = (table_1[s_idx_77_1] + pub_r000909_14_1) & 127;
  int stage_v_77_2 = (table_2[s_idx_77_2] + pub_r000909_14_2) & 127;
  table_1[s_idx_77_1] = (stage_v_77_1 + 7) & 63;
  table_2[s_idx_77_2] = (stage_v_77_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int s_idx_78_1 = stage_v_41_1 & 3;
  int s_idx_78_2 = stage_v_41_2 & 3;
  int stage_v_78_1 = (table_1[s_idx_78_1] + pub_r000909_1_1) & 127;
  int stage_v_78_2 = (table_2[s_idx_78_2] + pub_r000909_1_2) & 127;
  table_1[s_idx_78_1] = (stage_v_78_1 + 7) & 63;
  table_2[s_idx_78_2] = (stage_v_78_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int s_idx_79_1 = stage_v_76_1 & 3;
  int s_idx_79_2 = stage_v_76_2 & 3;
  int stage_v_79_1 = (table_1[s_idx_79_1] + pub_r000909_5_1) & 127;
  int stage_v_79_2 = (table_2[s_idx_79_2] + pub_r000909_5_2) & 127;
  table_1[s_idx_79_1] = (stage_v_79_1 + 7) & 63;
  table_2[s_idx_79_2] = (stage_v_79_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int s_idx_80_1 = stage_v_36_1 & 3;
  int s_idx_80_2 = stage_v_36_2 & 3;
  int stage_v_80_1 = (table_1[s_idx_80_1] + pub_r000909_11_1) & 127;
  int stage_v_80_2 = (table_2[s_idx_80_2] + pub_r000909_11_2) & 127;
  table_1[s_idx_80_1] = (stage_v_80_1 + 7) & 63;
  table_2[s_idx_80_2] = (stage_v_80_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int s_idx_81_1 = stage_v_64_1 & 3;
  int s_idx_81_2 = stage_v_64_2 & 3;
  int stage_v_81_1 = (table_1[s_idx_81_1] + pub_r000909_14_1) & 127;
  int stage_v_81_2 = (table_2[s_idx_81_2] + pub_r000909_14_2) & 127;
  table_1[s_idx_81_1] = (stage_v_81_1 + 7) & 63;
  table_2[s_idx_81_2] = (stage_v_81_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int s_idx_82_1 = sec_r000909_16_1 & 3;
  int s_idx_82_2 = sec_r000909_16_2 & 3;
  int stage_v_82_1 = (table_1[s_idx_82_1] + pub_r000909_5_1) & 127;
  int stage_v_82_2 = (table_2[s_idx_82_2] + pub_r000909_5_2) & 127;
  table_1[s_idx_82_1] = (stage_v_82_1 + 7) & 63;
  table_2[s_idx_82_2] = (stage_v_82_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int s_idx_83_1 = stage_v_57_1 & 3;
  int s_idx_83_2 = stage_v_57_2 & 3;
  int stage_v_83_1 = (table_1[s_idx_83_1] + pub_r000909_0_1) & 127;
  int stage_v_83_2 = (table_2[s_idx_83_2] + pub_r000909_0_2) & 127;
  table_1[s_idx_83_1] = (stage_v_83_1 + 7) & 63;
  table_2[s_idx_83_2] = (stage_v_83_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int s_idx_84_1 = stage_v_83_1 & 3;
  int s_idx_84_2 = stage_v_83_2 & 3;
  int stage_v_84_1 = (table_1[s_idx_84_1] + pub_r000909_3_1) & 127;
  int stage_v_84_2 = (table_2[s_idx_84_2] + pub_r000909_3_2) & 127;
  table_1[s_idx_84_1] = (stage_v_84_1 + 7) & 63;
  table_2[s_idx_84_2] = (stage_v_84_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int s_idx_85_1 = stage_v_52_1 & 3;
  int s_idx_85_2 = stage_v_52_2 & 3;
  int stage_v_85_1 = (table_1[s_idx_85_1] + pub_r000909_10_1) & 127;
  int stage_v_85_2 = (table_2[s_idx_85_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_85_1] = (stage_v_85_1 + 7) & 63;
  table_2[s_idx_85_2] = (stage_v_85_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int s_idx_86_1 = stage_v_85_1 & 3;
  int s_idx_86_2 = stage_v_85_2 & 3;
  int stage_v_86_1 = (table_1[s_idx_86_1] + pub_r000909_15_1) & 127;
  int stage_v_86_2 = (table_2[s_idx_86_2] + pub_r000909_15_2) & 127;
  table_1[s_idx_86_1] = (stage_v_86_1 + 7) & 63;
  table_2[s_idx_86_2] = (stage_v_86_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int s_idx_87_1 = sec_r000909_9_1 & 3;
  int s_idx_87_2 = sec_r000909_9_2 & 3;
  int stage_v_87_1 = (table_1[s_idx_87_1] + pub_r000909_12_1) & 127;
  int stage_v_87_2 = (table_2[s_idx_87_2] + pub_r000909_12_2) & 127;
  table_1[s_idx_87_1] = (stage_v_87_1 + 7) & 63;
  table_2[s_idx_87_2] = (stage_v_87_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int s_idx_88_1 = sec_r000909_16_1 & 3;
  int s_idx_88_2 = sec_r000909_16_2 & 3;
  int stage_v_88_1 = (table_1[s_idx_88_1] + pub_r000909_7_1) & 127;
  int stage_v_88_2 = (table_2[s_idx_88_2] + pub_r000909_7_2) & 127;
  table_1[s_idx_88_1] = (stage_v_88_1 + 7) & 63;
  table_2[s_idx_88_2] = (stage_v_88_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int s_idx_89_1 = sec_r000909_12_1 & 3;
  int s_idx_89_2 = sec_r000909_12_2 & 3;
  int stage_v_89_1 = (table_1[s_idx_89_1] + pub_r000909_12_1) & 127;
  int stage_v_89_2 = (table_2[s_idx_89_2] + pub_r000909_12_2) & 127;
  table_1[s_idx_89_1] = (stage_v_89_1 + 7) & 63;
  table_2[s_idx_89_2] = (stage_v_89_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int s_idx_90_1 = stage_v_37_1 & 3;
  int s_idx_90_2 = stage_v_37_2 & 3;
  int stage_v_90_1 = (table_1[s_idx_90_1] + pub_r000909_1_1) & 127;
  int stage_v_90_2 = (table_2[s_idx_90_2] + pub_r000909_1_2) & 127;
  table_1[s_idx_90_1] = (stage_v_90_1 + 7) & 63;
  table_2[s_idx_90_2] = (stage_v_90_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int s_idx_91_1 = stage_v_89_1 & 3;
  int s_idx_91_2 = stage_v_89_2 & 3;
  int stage_v_91_1 = (table_1[s_idx_91_1] + pub_r000909_2_1) & 127;
  int stage_v_91_2 = (table_2[s_idx_91_2] + pub_r000909_2_2) & 127;
  table_1[s_idx_91_1] = (stage_v_91_1 + 7) & 63;
  table_2[s_idx_91_2] = (stage_v_91_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int s_idx_92_1 = sec_r000909_2_1 & 3;
  int s_idx_92_2 = sec_r000909_2_2 & 3;
  int stage_v_92_1 = (table_1[s_idx_92_1] + pub_r000909_8_1) & 127;
  int stage_v_92_2 = (table_2[s_idx_92_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_92_1] = (stage_v_92_1 + 7) & 63;
  table_2[s_idx_92_2] = (stage_v_92_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int s_idx_93_1 = sec_r000909_11_1 & 3;
  int s_idx_93_2 = sec_r000909_11_2 & 3;
  int stage_v_93_1 = (table_1[s_idx_93_1] + pub_r000909_8_1) & 127;
  int stage_v_93_2 = (table_2[s_idx_93_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_93_1] = (stage_v_93_1 + 7) & 63;
  table_2[s_idx_93_2] = (stage_v_93_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int s_idx_94_1 = stage_v_37_1 & 3;
  int s_idx_94_2 = stage_v_37_2 & 3;
  int stage_v_94_1 = (table_1[s_idx_94_1] + pub_r000909_13_1) & 127;
  int stage_v_94_2 = (table_2[s_idx_94_2] + pub_r000909_13_2) & 127;
  table_1[s_idx_94_1] = (stage_v_94_1 + 7) & 63;
  table_2[s_idx_94_2] = (stage_v_94_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int s_idx_95_1 = stage_v_65_1 & 3;
  int s_idx_95_2 = stage_v_65_2 & 3;
  int stage_v_95_1 = (table_1[s_idx_95_1] + pub_r000909_10_1) & 127;
  int stage_v_95_2 = (table_2[s_idx_95_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_95_1] = (stage_v_95_1 + 7) & 63;
  table_2[s_idx_95_2] = (stage_v_95_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int s_idx_96_1 = stage_v_67_1 & 3;
  int s_idx_96_2 = stage_v_67_2 & 3;
  int stage_v_96_1 = (table_1[s_idx_96_1] + pub_r000909_15_1) & 127;
  int stage_v_96_2 = (table_2[s_idx_96_2] + pub_r000909_15_2) & 127;
  table_1[s_idx_96_1] = (stage_v_96_1 + 7) & 63;
  table_2[s_idx_96_2] = (stage_v_96_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int s_idx_97_1 = stage_v_95_1 & 3;
  int s_idx_97_2 = stage_v_95_2 & 3;
  int stage_v_97_1 = (table_1[s_idx_97_1] + pub_r000909_2_1) & 127;
  int stage_v_97_2 = (table_2[s_idx_97_2] + pub_r000909_2_2) & 127;
  table_1[s_idx_97_1] = (stage_v_97_1 + 7) & 63;
  table_2[s_idx_97_2] = (stage_v_97_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int s_idx_98_1 = sec_r000909_12_1 & 3;
  int s_idx_98_2 = sec_r000909_12_2 & 3;
  int stage_v_98_1 = (table_1[s_idx_98_1] + pub_r000909_5_1) & 127;
  int stage_v_98_2 = (table_2[s_idx_98_2] + pub_r000909_5_2) & 127;
  table_1[s_idx_98_1] = (stage_v_98_1 + 7) & 63;
  table_2[s_idx_98_2] = (stage_v_98_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int s_idx_99_1 = stage_v_69_1 & 3;
  int s_idx_99_2 = stage_v_69_2 & 3;
  int stage_v_99_1 = (table_1[s_idx_99_1] + pub_r000909_15_1) & 127;
  int stage_v_99_2 = (table_2[s_idx_99_2] + pub_r000909_15_2) & 127;
  table_1[s_idx_99_1] = (stage_v_99_1 + 7) & 63;
  table_2[s_idx_99_2] = (stage_v_99_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int s_idx_100_1 = sec_r000909_1_1 & 3;
  int s_idx_100_2 = sec_r000909_1_2 & 3;
  int stage_v_100_1 = (table_1[s_idx_100_1] + pub_r000909_2_1) & 127;
  int stage_v_100_2 = (table_2[s_idx_100_2] + pub_r000909_2_2) & 127;
  table_1[s_idx_100_1] = (stage_v_100_1 + 7) & 63;
  table_2[s_idx_100_2] = (stage_v_100_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int s_idx_101_1 = stage_v_46_1 & 3;
  int s_idx_101_2 = stage_v_46_2 & 3;
  int stage_v_101_1 = (table_1[s_idx_101_1] + pub_r000909_10_1) & 127;
  int stage_v_101_2 = (table_2[s_idx_101_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_101_1] = (stage_v_101_1 + 7) & 63;
  table_2[s_idx_101_2] = (stage_v_101_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int s_idx_102_1 = stage_v_95_1 & 3;
  int s_idx_102_2 = stage_v_95_2 & 3;
  int stage_v_102_1 = (table_1[s_idx_102_1] + pub_r000909_5_1) & 127;
  int stage_v_102_2 = (table_2[s_idx_102_2] + pub_r000909_5_2) & 127;
  table_1[s_idx_102_1] = (stage_v_102_1 + 7) & 63;
  table_2[s_idx_102_2] = (stage_v_102_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int s_idx_103_1 = stage_v_55_1 & 3;
  int s_idx_103_2 = stage_v_55_2 & 3;
  int stage_v_103_1 = (table_1[s_idx_103_1] + pub_r000909_3_1) & 127;
  int stage_v_103_2 = (table_2[s_idx_103_2] + pub_r000909_3_2) & 127;
  table_1[s_idx_103_1] = (stage_v_103_1 + 7) & 63;
  table_2[s_idx_103_2] = (stage_v_103_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int s_idx_104_1 = stage_v_103_1 & 3;
  int s_idx_104_2 = stage_v_103_2 & 3;
  int stage_v_104_1 = (table_1[s_idx_104_1] + pub_r000909_8_1) & 127;
  int stage_v_104_2 = (table_2[s_idx_104_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_104_1] = (stage_v_104_1 + 7) & 63;
  table_2[s_idx_104_2] = (stage_v_104_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int s_idx_105_1 = stage_v_66_1 & 3;
  int s_idx_105_2 = stage_v_66_2 & 3;
  int stage_v_105_1 = (table_1[s_idx_105_1] + pub_r000909_8_1) & 127;
  int stage_v_105_2 = (table_2[s_idx_105_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_105_1] = (stage_v_105_1 + 7) & 63;
  table_2[s_idx_105_2] = (stage_v_105_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int s_idx_106_1 = stage_v_102_1 & 3;
  int s_idx_106_2 = stage_v_102_2 & 3;
  int stage_v_106_1 = (table_1[s_idx_106_1] + pub_r000909_1_1) & 127;
  int stage_v_106_2 = (table_2[s_idx_106_2] + pub_r000909_1_2) & 127;
  table_1[s_idx_106_1] = (stage_v_106_1 + 7) & 63;
  table_2[s_idx_106_2] = (stage_v_106_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int s_idx_107_1 = stage_v_60_1 & 3;
  int s_idx_107_2 = stage_v_60_2 & 3;
  int stage_v_107_1 = (table_1[s_idx_107_1] + pub_r000909_12_1) & 127;
  int stage_v_107_2 = (table_2[s_idx_107_2] + pub_r000909_12_2) & 127;
  table_1[s_idx_107_1] = (stage_v_107_1 + 7) & 63;
  table_2[s_idx_107_2] = (stage_v_107_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int s_idx_108_1 = stage_v_76_1 & 3;
  int s_idx_108_2 = stage_v_76_2 & 3;
  int stage_v_108_1 = (table_1[s_idx_108_1] + pub_r000909_14_1) & 127;
  int stage_v_108_2 = (table_2[s_idx_108_2] + pub_r000909_14_2) & 127;
  table_1[s_idx_108_1] = (stage_v_108_1 + 7) & 63;
  table_2[s_idx_108_2] = (stage_v_108_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int s_idx_109_1 = sec_r000909_11_1 & 3;
  int s_idx_109_2 = sec_r000909_11_2 & 3;
  int stage_v_109_1 = (table_1[s_idx_109_1] + pub_r000909_1_1) & 127;
  int stage_v_109_2 = (table_2[s_idx_109_2] + pub_r000909_1_2) & 127;
  table_1[s_idx_109_1] = (stage_v_109_1 + 7) & 63;
  table_2[s_idx_109_2] = (stage_v_109_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int s_idx_110_1 = sec_r000909_20_1 & 3;
  int s_idx_110_2 = sec_r000909_20_2 & 3;
  int stage_v_110_1 = (table_1[s_idx_110_1] + pub_r000909_10_1) & 127;
  int stage_v_110_2 = (table_2[s_idx_110_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_110_1] = (stage_v_110_1 + 7) & 63;
  table_2[s_idx_110_2] = (stage_v_110_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int s_idx_111_1 = stage_v_90_1 & 3;
  int s_idx_111_2 = stage_v_90_2 & 3;
  int stage_v_111_1 = (table_1[s_idx_111_1] + pub_r000909_8_1) & 127;
  int stage_v_111_2 = (table_2[s_idx_111_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_111_1] = (stage_v_111_1 + 7) & 63;
  table_2[s_idx_111_2] = (stage_v_111_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int s_idx_112_1 = sec_r000909_17_1 & 3;
  int s_idx_112_2 = sec_r000909_17_2 & 3;
  int stage_v_112_1 = (table_1[s_idx_112_1] + pub_r000909_0_1) & 127;
  int stage_v_112_2 = (table_2[s_idx_112_2] + pub_r000909_0_2) & 127;
  table_1[s_idx_112_1] = (stage_v_112_1 + 7) & 63;
  table_2[s_idx_112_2] = (stage_v_112_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int s_idx_113_1 = sec_r000909_16_1 & 3;
  int s_idx_113_2 = sec_r000909_16_2 & 3;
  int stage_v_113_1 = (table_1[s_idx_113_1] + pub_r000909_12_1) & 127;
  int stage_v_113_2 = (table_2[s_idx_113_2] + pub_r000909_12_2) & 127;
  table_1[s_idx_113_1] = (stage_v_113_1 + 7) & 63;
  table_2[s_idx_113_2] = (stage_v_113_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int s_idx_114_1 = stage_v_62_1 & 3;
  int s_idx_114_2 = stage_v_62_2 & 3;
  int stage_v_114_1 = (table_1[s_idx_114_1] + pub_r000909_6_1) & 127;
  int stage_v_114_2 = (table_2[s_idx_114_2] + pub_r000909_6_2) & 127;
  table_1[s_idx_114_1] = (stage_v_114_1 + 7) & 63;
  table_2[s_idx_114_2] = (stage_v_114_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int s_idx_115_1 = stage_v_51_1 & 3;
  int s_idx_115_2 = stage_v_51_2 & 3;
  int stage_v_115_1 = (table_1[s_idx_115_1] + pub_r000909_5_1) & 127;
  int stage_v_115_2 = (table_2[s_idx_115_2] + pub_r000909_5_2) & 127;
  table_1[s_idx_115_1] = (stage_v_115_1 + 7) & 63;
  table_2[s_idx_115_2] = (stage_v_115_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int s_idx_116_1 = stage_v_90_1 & 3;
  int s_idx_116_2 = stage_v_90_2 & 3;
  int stage_v_116_1 = (table_1[s_idx_116_1] + pub_r000909_15_1) & 127;
  int stage_v_116_2 = (table_2[s_idx_116_2] + pub_r000909_15_2) & 127;
  table_1[s_idx_116_1] = (stage_v_116_1 + 7) & 63;
  table_2[s_idx_116_2] = (stage_v_116_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int s_idx_117_1 = sec_r000909_5_1 & 3;
  int s_idx_117_2 = sec_r000909_5_2 & 3;
  int stage_v_117_1 = (table_1[s_idx_117_1] + pub_r000909_4_1) & 127;
  int stage_v_117_2 = (table_2[s_idx_117_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_117_1] = (stage_v_117_1 + 7) & 63;
  table_2[s_idx_117_2] = (stage_v_117_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int s_idx_118_1 = stage_v_114_1 & 3;
  int s_idx_118_2 = stage_v_114_2 & 3;
  int stage_v_118_1 = (table_1[s_idx_118_1] + pub_r000909_11_1) & 127;
  int stage_v_118_2 = (table_2[s_idx_118_2] + pub_r000909_11_2) & 127;
  table_1[s_idx_118_1] = (stage_v_118_1 + 7) & 63;
  table_2[s_idx_118_2] = (stage_v_118_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int s_idx_119_1 = stage_v_107_1 & 3;
  int s_idx_119_2 = stage_v_107_2 & 3;
  int stage_v_119_1 = (table_1[s_idx_119_1] + pub_r000909_3_1) & 127;
  int stage_v_119_2 = (table_2[s_idx_119_2] + pub_r000909_3_2) & 127;
  table_1[s_idx_119_1] = (stage_v_119_1 + 7) & 63;
  table_2[s_idx_119_2] = (stage_v_119_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int s_idx_120_1 = stage_v_106_1 & 3;
  int s_idx_120_2 = stage_v_106_2 & 3;
  int stage_v_120_1 = (table_1[s_idx_120_1] + pub_r000909_0_1) & 127;
  int stage_v_120_2 = (table_2[s_idx_120_2] + pub_r000909_0_2) & 127;
  table_1[s_idx_120_1] = (stage_v_120_1 + 7) & 63;
  table_2[s_idx_120_2] = (stage_v_120_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int s_idx_121_1 = stage_v_115_1 & 3;
  int s_idx_121_2 = stage_v_115_2 & 3;
  int stage_v_121_1 = (table_1[s_idx_121_1] + pub_r000909_11_1) & 127;
  int stage_v_121_2 = (table_2[s_idx_121_2] + pub_r000909_11_2) & 127;
  table_1[s_idx_121_1] = (stage_v_121_1 + 7) & 63;
  table_2[s_idx_121_2] = (stage_v_121_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int s_idx_122_1 = stage_v_79_1 & 3;
  int s_idx_122_2 = stage_v_79_2 & 3;
  int stage_v_122_1 = (table_1[s_idx_122_1] + pub_r000909_4_1) & 127;
  int stage_v_122_2 = (table_2[s_idx_122_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_122_1] = (stage_v_122_1 + 7) & 63;
  table_2[s_idx_122_2] = (stage_v_122_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int s_idx_123_1 = stage_v_87_1 & 3;
  int s_idx_123_2 = stage_v_87_2 & 3;
  int stage_v_123_1 = (table_1[s_idx_123_1] + pub_r000909_9_1) & 127;
  int stage_v_123_2 = (table_2[s_idx_123_2] + pub_r000909_9_2) & 127;
  table_1[s_idx_123_1] = (stage_v_123_1 + 7) & 63;
  table_2[s_idx_123_2] = (stage_v_123_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int s_idx_124_1 = sec_r000909_18_1 & 3;
  int s_idx_124_2 = sec_r000909_18_2 & 3;
  int stage_v_124_1 = (table_1[s_idx_124_1] + pub_r000909_14_1) & 127;
  int stage_v_124_2 = (table_2[s_idx_124_2] + pub_r000909_14_2) & 127;
  table_1[s_idx_124_1] = (stage_v_124_1 + 7) & 63;
  table_2[s_idx_124_2] = (stage_v_124_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int s_idx_125_1 = stage_v_38_1 & 3;
  int s_idx_125_2 = stage_v_38_2 & 3;
  int stage_v_125_1 = (table_1[s_idx_125_1] + pub_r000909_9_1) & 127;
  int stage_v_125_2 = (table_2[s_idx_125_2] + pub_r000909_9_2) & 127;
  table_1[s_idx_125_1] = (stage_v_125_1 + 7) & 63;
  table_2[s_idx_125_2] = (stage_v_125_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int s_idx_126_1 = sec_r000909_20_1 & 3;
  int s_idx_126_2 = sec_r000909_20_2 & 3;
  int stage_v_126_1 = (table_1[s_idx_126_1] + pub_r000909_8_1) & 127;
  int stage_v_126_2 = (table_2[s_idx_126_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_126_1] = (stage_v_126_1 + 7) & 63;
  table_2[s_idx_126_2] = (stage_v_126_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int s_idx_127_1 = sec_r000909_15_1 & 3;
  int s_idx_127_2 = sec_r000909_15_2 & 3;
  int stage_v_127_1 = (table_1[s_idx_127_1] + pub_r000909_13_1) & 127;
  int stage_v_127_2 = (table_2[s_idx_127_2] + pub_r000909_13_2) & 127;
  table_1[s_idx_127_1] = (stage_v_127_1 + 7) & 63;
  table_2[s_idx_127_2] = (stage_v_127_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int s_idx_128_1 = stage_v_124_1 & 3;
  int s_idx_128_2 = stage_v_124_2 & 3;
  int stage_v_128_1 = (table_1[s_idx_128_1] + pub_r000909_15_1) & 127;
  int stage_v_128_2 = (table_2[s_idx_128_2] + pub_r000909_15_2) & 127;
  table_1[s_idx_128_1] = (stage_v_128_1 + 7) & 63;
  table_2[s_idx_128_2] = (stage_v_128_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int s_idx_129_1 = stage_v_85_1 & 3;
  int s_idx_129_2 = stage_v_85_2 & 3;
  int stage_v_129_1 = (table_1[s_idx_129_1] + pub_r000909_2_1) & 127;
  int stage_v_129_2 = (table_2[s_idx_129_2] + pub_r000909_2_2) & 127;
  table_1[s_idx_129_1] = (stage_v_129_1 + 7) & 63;
  table_2[s_idx_129_2] = (stage_v_129_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int s_idx_130_1 = sec_r000909_14_1 & 3;
  int s_idx_130_2 = sec_r000909_14_2 & 3;
  int stage_v_130_1 = (table_1[s_idx_130_1] + pub_r000909_8_1) & 127;
  int stage_v_130_2 = (table_2[s_idx_130_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_130_1] = (stage_v_130_1 + 7) & 63;
  table_2[s_idx_130_2] = (stage_v_130_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int s_idx_131_1 = sec_r000909_15_1 & 3;
  int s_idx_131_2 = sec_r000909_15_2 & 3;
  int stage_v_131_1 = (table_1[s_idx_131_1] + pub_r000909_4_1) & 127;
  int stage_v_131_2 = (table_2[s_idx_131_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_131_1] = (stage_v_131_1 + 7) & 63;
  table_2[s_idx_131_2] = (stage_v_131_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int s_idx_132_1 = stage_v_115_1 & 3;
  int s_idx_132_2 = stage_v_115_2 & 3;
  int stage_v_132_1 = (table_1[s_idx_132_1] + pub_r000909_13_1) & 127;
  int stage_v_132_2 = (table_2[s_idx_132_2] + pub_r000909_13_2) & 127;
  table_1[s_idx_132_1] = (stage_v_132_1 + 7) & 63;
  table_2[s_idx_132_2] = (stage_v_132_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int s_idx_133_1 = stage_v_75_1 & 3;
  int s_idx_133_2 = stage_v_75_2 & 3;
  int stage_v_133_1 = (table_1[s_idx_133_1] + pub_r000909_9_1) & 127;
  int stage_v_133_2 = (table_2[s_idx_133_2] + pub_r000909_9_2) & 127;
  table_1[s_idx_133_1] = (stage_v_133_1 + 7) & 63;
  table_2[s_idx_133_2] = (stage_v_133_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int s_idx_134_1 = sec_r000909_10_1 & 3;
  int s_idx_134_2 = sec_r000909_10_2 & 3;
  int stage_v_134_1 = (table_1[s_idx_134_1] + pub_r000909_9_1) & 127;
  int stage_v_134_2 = (table_2[s_idx_134_2] + pub_r000909_9_2) & 127;
  table_1[s_idx_134_1] = (stage_v_134_1 + 7) & 63;
  table_2[s_idx_134_2] = (stage_v_134_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int s_idx_135_1 = stage_v_103_1 & 3;
  int s_idx_135_2 = stage_v_103_2 & 3;
  int stage_v_135_1 = (table_1[s_idx_135_1] + pub_r000909_4_1) & 127;
  int stage_v_135_2 = (table_2[s_idx_135_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_135_1] = (stage_v_135_1 + 7) & 63;
  table_2[s_idx_135_2] = (stage_v_135_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int s_idx_136_1 = stage_v_98_1 & 3;
  int s_idx_136_2 = stage_v_98_2 & 3;
  int stage_v_136_1 = (table_1[s_idx_136_1] + pub_r000909_8_1) & 127;
  int stage_v_136_2 = (table_2[s_idx_136_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_136_1] = (stage_v_136_1 + 7) & 63;
  table_2[s_idx_136_2] = (stage_v_136_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int s_idx_137_1 = sec_r000909_19_1 & 3;
  int s_idx_137_2 = sec_r000909_19_2 & 3;
  int stage_v_137_1 = (table_1[s_idx_137_1] + pub_r000909_5_1) & 127;
  int stage_v_137_2 = (table_2[s_idx_137_2] + pub_r000909_5_2) & 127;
  table_1[s_idx_137_1] = (stage_v_137_1 + 7) & 63;
  table_2[s_idx_137_2] = (stage_v_137_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int s_idx_138_1 = sec_r000909_8_1 & 3;
  int s_idx_138_2 = sec_r000909_8_2 & 3;
  int stage_v_138_1 = (table_1[s_idx_138_1] + pub_r000909_4_1) & 127;
  int stage_v_138_2 = (table_2[s_idx_138_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_138_1] = (stage_v_138_1 + 7) & 63;
  table_2[s_idx_138_2] = (stage_v_138_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int s_idx_139_1 = sec_r000909_15_1 & 3;
  int s_idx_139_2 = sec_r000909_15_2 & 3;
  int stage_v_139_1 = (table_1[s_idx_139_1] + pub_r000909_15_1) & 127;
  int stage_v_139_2 = (table_2[s_idx_139_2] + pub_r000909_15_2) & 127;
  table_1[s_idx_139_1] = (stage_v_139_1 + 7) & 63;
  table_2[s_idx_139_2] = (stage_v_139_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int s_idx_140_1 = stage_v_131_1 & 3;
  int s_idx_140_2 = stage_v_131_2 & 3;
  int stage_v_140_1 = (table_1[s_idx_140_1] + pub_r000909_2_1) & 127;
  int stage_v_140_2 = (table_2[s_idx_140_2] + pub_r000909_2_2) & 127;
  table_1[s_idx_140_1] = (stage_v_140_1 + 7) & 63;
  table_2[s_idx_140_2] = (stage_v_140_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int s_idx_141_1 = stage_v_84_1 & 3;
  int s_idx_141_2 = stage_v_84_2 & 3;
  int stage_v_141_1 = (table_1[s_idx_141_1] + pub_r000909_11_1) & 127;
  int stage_v_141_2 = (table_2[s_idx_141_2] + pub_r000909_11_2) & 127;
  table_1[s_idx_141_1] = (stage_v_141_1 + 7) & 63;
  table_2[s_idx_141_2] = (stage_v_141_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int s_idx_142_1 = stage_v_112_1 & 3;
  int s_idx_142_2 = stage_v_112_2 & 3;
  int stage_v_142_1 = (table_1[s_idx_142_1] + pub_r000909_15_1) & 127;
  int stage_v_142_2 = (table_2[s_idx_142_2] + pub_r000909_15_2) & 127;
  table_1[s_idx_142_1] = (stage_v_142_1 + 7) & 63;
  table_2[s_idx_142_2] = (stage_v_142_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int s_idx_143_1 = stage_v_47_1 & 3;
  int s_idx_143_2 = stage_v_47_2 & 3;
  int stage_v_143_1 = (table_1[s_idx_143_1] + pub_r000909_0_1) & 127;
  int stage_v_143_2 = (table_2[s_idx_143_2] + pub_r000909_0_2) & 127;
  table_1[s_idx_143_1] = (stage_v_143_1 + 7) & 63;
  table_2[s_idx_143_2] = (stage_v_143_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int s_idx_144_1 = stage_v_55_1 & 3;
  int s_idx_144_2 = stage_v_55_2 & 3;
  int stage_v_144_1 = (table_1[s_idx_144_1] + pub_r000909_13_1) & 127;
  int stage_v_144_2 = (table_2[s_idx_144_2] + pub_r000909_13_2) & 127;
  table_1[s_idx_144_1] = (stage_v_144_1 + 7) & 63;
  table_2[s_idx_144_2] = (stage_v_144_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int s_idx_145_1 = stage_v_86_1 & 3;
  int s_idx_145_2 = stage_v_86_2 & 3;
  int stage_v_145_1 = (table_1[s_idx_145_1] + pub_r000909_10_1) & 127;
  int stage_v_145_2 = (table_2[s_idx_145_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_145_1] = (stage_v_145_1 + 7) & 63;
  table_2[s_idx_145_2] = (stage_v_145_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int s_idx_146_1 = stage_v_94_1 & 3;
  int s_idx_146_2 = stage_v_94_2 & 3;
  int stage_v_146_1 = (table_1[s_idx_146_1] + pub_r000909_8_1) & 127;
  int stage_v_146_2 = (table_2[s_idx_146_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_146_1] = (stage_v_146_1 + 7) & 63;
  table_2[s_idx_146_2] = (stage_v_146_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int s_idx_147_1 = stage_v_61_1 & 3;
  int s_idx_147_2 = stage_v_61_2 & 3;
  int stage_v_147_1 = (table_1[s_idx_147_1] + pub_r000909_15_1) & 127;
  int stage_v_147_2 = (table_2[s_idx_147_2] + pub_r000909_15_2) & 127;
  table_1[s_idx_147_1] = (stage_v_147_1 + 7) & 63;
  table_2[s_idx_147_2] = (stage_v_147_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int s_idx_148_1 = stage_v_68_1 & 3;
  int s_idx_148_2 = stage_v_68_2 & 3;
  int stage_v_148_1 = (table_1[s_idx_148_1] + pub_r000909_4_1) & 127;
  int stage_v_148_2 = (table_2[s_idx_148_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_148_1] = (stage_v_148_1 + 7) & 63;
  table_2[s_idx_148_2] = (stage_v_148_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int s_idx_149_1 = sec_r000909_9_1 & 3;
  int s_idx_149_2 = sec_r000909_9_2 & 3;
  int stage_v_149_1 = (table_1[s_idx_149_1] + pub_r000909_12_1) & 127;
  int stage_v_149_2 = (table_2[s_idx_149_2] + pub_r000909_12_2) & 127;
  table_1[s_idx_149_1] = (stage_v_149_1 + 7) & 63;
  table_2[s_idx_149_2] = (stage_v_149_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int s_idx_150_1 = stage_v_38_1 & 3;
  int s_idx_150_2 = stage_v_38_2 & 3;
  int stage_v_150_1 = (table_1[s_idx_150_1] + pub_r000909_14_1) & 127;
  int stage_v_150_2 = (table_2[s_idx_150_2] + pub_r000909_14_2) & 127;
  table_1[s_idx_150_1] = (stage_v_150_1 + 7) & 63;
  table_2[s_idx_150_2] = (stage_v_150_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int s_idx_151_1 = stage_v_140_1 & 3;
  int s_idx_151_2 = stage_v_140_2 & 3;
  int stage_v_151_1 = (table_1[s_idx_151_1] + pub_r000909_9_1) & 127;
  int stage_v_151_2 = (table_2[s_idx_151_2] + pub_r000909_9_2) & 127;
  table_1[s_idx_151_1] = (stage_v_151_1 + 7) & 63;
  table_2[s_idx_151_2] = (stage_v_151_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int s_idx_152_1 = sec_r000909_10_1 & 3;
  int s_idx_152_2 = sec_r000909_10_2 & 3;
  int stage_v_152_1 = (table_1[s_idx_152_1] + pub_r000909_3_1) & 127;
  int stage_v_152_2 = (table_2[s_idx_152_2] + pub_r000909_3_2) & 127;
  table_1[s_idx_152_1] = (stage_v_152_1 + 7) & 63;
  table_2[s_idx_152_2] = (stage_v_152_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int s_idx_153_1 = stage_v_132_1 & 3;
  int s_idx_153_2 = stage_v_132_2 & 3;
  int stage_v_153_1 = (table_1[s_idx_153_1] + pub_r000909_1_1) & 127;
  int stage_v_153_2 = (table_2[s_idx_153_2] + pub_r000909_1_2) & 127;
  table_1[s_idx_153_1] = (stage_v_153_1 + 7) & 63;
  table_2[s_idx_153_2] = (stage_v_153_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int s_idx_154_1 = stage_v_131_1 & 3;
  int s_idx_154_2 = stage_v_131_2 & 3;
  int stage_v_154_1 = (table_1[s_idx_154_1] + pub_r000909_3_1) & 127;
  int stage_v_154_2 = (table_2[s_idx_154_2] + pub_r000909_3_2) & 127;
  table_1[s_idx_154_1] = (stage_v_154_1 + 7) & 63;
  table_2[s_idx_154_2] = (stage_v_154_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int s_idx_155_1 = sec_r000909_12_1 & 3;
  int s_idx_155_2 = sec_r000909_12_2 & 3;
  int stage_v_155_1 = (table_1[s_idx_155_1] + pub_r000909_10_1) & 127;
  int stage_v_155_2 = (table_2[s_idx_155_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_155_1] = (stage_v_155_1 + 7) & 63;
  table_2[s_idx_155_2] = (stage_v_155_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int s_idx_156_1 = sec_r000909_20_1 & 3;
  int s_idx_156_2 = sec_r000909_20_2 & 3;
  int stage_v_156_1 = (table_1[s_idx_156_1] + pub_r000909_10_1) & 127;
  int stage_v_156_2 = (table_2[s_idx_156_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_156_1] = (stage_v_156_1 + 7) & 63;
  table_2[s_idx_156_2] = (stage_v_156_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int s_idx_157_1 = sec_r000909_16_1 & 3;
  int s_idx_157_2 = sec_r000909_16_2 & 3;
  int stage_v_157_1 = (table_1[s_idx_157_1] + pub_r000909_6_1) & 127;
  int stage_v_157_2 = (table_2[s_idx_157_2] + pub_r000909_6_2) & 127;
  table_1[s_idx_157_1] = (stage_v_157_1 + 7) & 63;
  table_2[s_idx_157_2] = (stage_v_157_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int s_idx_158_1 = sec_r000909_14_1 & 3;
  int s_idx_158_2 = sec_r000909_14_2 & 3;
  int stage_v_158_1 = (table_1[s_idx_158_1] + pub_r000909_0_1) & 127;
  int stage_v_158_2 = (table_2[s_idx_158_2] + pub_r000909_0_2) & 127;
  table_1[s_idx_158_1] = (stage_v_158_1 + 7) & 63;
  table_2[s_idx_158_2] = (stage_v_158_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int s_idx_159_1 = stage_v_138_1 & 3;
  int s_idx_159_2 = stage_v_138_2 & 3;
  int stage_v_159_1 = (table_1[s_idx_159_1] + pub_r000909_0_1) & 127;
  int stage_v_159_2 = (table_2[s_idx_159_2] + pub_r000909_0_2) & 127;
  table_1[s_idx_159_1] = (stage_v_159_1 + 7) & 63;
  table_2[s_idx_159_2] = (stage_v_159_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int s_idx_160_1 = sec_r000909_17_1 & 3;
  int s_idx_160_2 = sec_r000909_17_2 & 3;
  int stage_v_160_1 = (table_1[s_idx_160_1] + pub_r000909_8_1) & 127;
  int stage_v_160_2 = (table_2[s_idx_160_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_160_1] = (stage_v_160_1 + 7) & 63;
  table_2[s_idx_160_2] = (stage_v_160_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int s_idx_161_1 = stage_v_87_1 & 3;
  int s_idx_161_2 = stage_v_87_2 & 3;
  int stage_v_161_1 = (table_1[s_idx_161_1] + pub_r000909_8_1) & 127;
  int stage_v_161_2 = (table_2[s_idx_161_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_161_1] = (stage_v_161_1 + 7) & 63;
  table_2[s_idx_161_2] = (stage_v_161_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int s_idx_162_1 = stage_v_41_1 & 3;
  int s_idx_162_2 = stage_v_41_2 & 3;
  int stage_v_162_1 = (table_1[s_idx_162_1] + pub_r000909_7_1) & 127;
  int stage_v_162_2 = (table_2[s_idx_162_2] + pub_r000909_7_2) & 127;
  table_1[s_idx_162_1] = (stage_v_162_1 + 7) & 63;
  table_2[s_idx_162_2] = (stage_v_162_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int s_idx_163_1 = stage_v_156_1 & 3;
  int s_idx_163_2 = stage_v_156_2 & 3;
  int stage_v_163_1 = (table_1[s_idx_163_1] + pub_r000909_3_1) & 127;
  int stage_v_163_2 = (table_2[s_idx_163_2] + pub_r000909_3_2) & 127;
  table_1[s_idx_163_1] = (stage_v_163_1 + 7) & 63;
  table_2[s_idx_163_2] = (stage_v_163_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int s_idx_164_1 = stage_v_163_1 & 3;
  int s_idx_164_2 = stage_v_163_2 & 3;
  int stage_v_164_1 = (table_1[s_idx_164_1] + pub_r000909_0_1) & 127;
  int stage_v_164_2 = (table_2[s_idx_164_2] + pub_r000909_0_2) & 127;
  table_1[s_idx_164_1] = (stage_v_164_1 + 7) & 63;
  table_2[s_idx_164_2] = (stage_v_164_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int s_idx_165_1 = stage_v_51_1 & 3;
  int s_idx_165_2 = stage_v_51_2 & 3;
  int stage_v_165_1 = (table_1[s_idx_165_1] + pub_r000909_11_1) & 127;
  int stage_v_165_2 = (table_2[s_idx_165_2] + pub_r000909_11_2) & 127;
  table_1[s_idx_165_1] = (stage_v_165_1 + 7) & 63;
  table_2[s_idx_165_2] = (stage_v_165_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int s_idx_166_1 = sec_r000909_14_1 & 3;
  int s_idx_166_2 = sec_r000909_14_2 & 3;
  int stage_v_166_1 = (table_1[s_idx_166_1] + pub_r000909_6_1) & 127;
  int stage_v_166_2 = (table_2[s_idx_166_2] + pub_r000909_6_2) & 127;
  table_1[s_idx_166_1] = (stage_v_166_1 + 7) & 63;
  table_2[s_idx_166_2] = (stage_v_166_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int s_idx_167_1 = stage_v_94_1 & 3;
  int s_idx_167_2 = stage_v_94_2 & 3;
  int stage_v_167_1 = (table_1[s_idx_167_1] + pub_r000909_0_1) & 127;
  int stage_v_167_2 = (table_2[s_idx_167_2] + pub_r000909_0_2) & 127;
  table_1[s_idx_167_1] = (stage_v_167_1 + 7) & 63;
  table_2[s_idx_167_2] = (stage_v_167_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int s_idx_168_1 = stage_v_59_1 & 3;
  int s_idx_168_2 = stage_v_59_2 & 3;
  int stage_v_168_1 = (table_1[s_idx_168_1] + pub_r000909_6_1) & 127;
  int stage_v_168_2 = (table_2[s_idx_168_2] + pub_r000909_6_2) & 127;
  table_1[s_idx_168_1] = (stage_v_168_1 + 7) & 63;
  table_2[s_idx_168_2] = (stage_v_168_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int s_idx_169_1 = stage_v_105_1 & 3;
  int s_idx_169_2 = stage_v_105_2 & 3;
  int stage_v_169_1 = (table_1[s_idx_169_1] + pub_r000909_15_1) & 127;
  int stage_v_169_2 = (table_2[s_idx_169_2] + pub_r000909_15_2) & 127;
  table_1[s_idx_169_1] = (stage_v_169_1 + 7) & 63;
  table_2[s_idx_169_2] = (stage_v_169_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int s_idx_170_1 = sec_r000909_13_1 & 3;
  int s_idx_170_2 = sec_r000909_13_2 & 3;
  int stage_v_170_1 = (table_1[s_idx_170_1] + pub_r000909_13_1) & 127;
  int stage_v_170_2 = (table_2[s_idx_170_2] + pub_r000909_13_2) & 127;
  table_1[s_idx_170_1] = (stage_v_170_1 + 7) & 63;
  table_2[s_idx_170_2] = (stage_v_170_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int s_idx_171_1 = stage_v_81_1 & 3;
  int s_idx_171_2 = stage_v_81_2 & 3;
  int stage_v_171_1 = (table_1[s_idx_171_1] + pub_r000909_0_1) & 127;
  int stage_v_171_2 = (table_2[s_idx_171_2] + pub_r000909_0_2) & 127;
  table_1[s_idx_171_1] = (stage_v_171_1 + 7) & 63;
  table_2[s_idx_171_2] = (stage_v_171_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int s_idx_172_1 = sec_r000909_19_1 & 3;
  int s_idx_172_2 = sec_r000909_19_2 & 3;
  int stage_v_172_1 = (table_1[s_idx_172_1] + pub_r000909_4_1) & 127;
  int stage_v_172_2 = (table_2[s_idx_172_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_172_1] = (stage_v_172_1 + 7) & 63;
  table_2[s_idx_172_2] = (stage_v_172_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int s_idx_173_1 = stage_v_113_1 & 3;
  int s_idx_173_2 = stage_v_113_2 & 3;
  int stage_v_173_1 = (table_1[s_idx_173_1] + pub_r000909_12_1) & 127;
  int stage_v_173_2 = (table_2[s_idx_173_2] + pub_r000909_12_2) & 127;
  table_1[s_idx_173_1] = (stage_v_173_1 + 7) & 63;
  table_2[s_idx_173_2] = (stage_v_173_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int s_idx_174_1 = stage_v_44_1 & 3;
  int s_idx_174_2 = stage_v_44_2 & 3;
  int stage_v_174_1 = (table_1[s_idx_174_1] + pub_r000909_13_1) & 127;
  int stage_v_174_2 = (table_2[s_idx_174_2] + pub_r000909_13_2) & 127;
  table_1[s_idx_174_1] = (stage_v_174_1 + 7) & 63;
  table_2[s_idx_174_2] = (stage_v_174_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int s_idx_175_1 = sec_r000909_14_1 & 3;
  int s_idx_175_2 = sec_r000909_14_2 & 3;
  int stage_v_175_1 = (table_1[s_idx_175_1] + pub_r000909_11_1) & 127;
  int stage_v_175_2 = (table_2[s_idx_175_2] + pub_r000909_11_2) & 127;
  table_1[s_idx_175_1] = (stage_v_175_1 + 7) & 63;
  table_2[s_idx_175_2] = (stage_v_175_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int s_idx_176_1 = stage_v_71_1 & 3;
  int s_idx_176_2 = stage_v_71_2 & 3;
  int stage_v_176_1 = (table_1[s_idx_176_1] + pub_r000909_4_1) & 127;
  int stage_v_176_2 = (table_2[s_idx_176_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_176_1] = (stage_v_176_1 + 7) & 63;
  table_2[s_idx_176_2] = (stage_v_176_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int s_idx_177_1 = stage_v_162_1 & 3;
  int s_idx_177_2 = stage_v_162_2 & 3;
  int stage_v_177_1 = (table_1[s_idx_177_1] + pub_r000909_1_1) & 127;
  int stage_v_177_2 = (table_2[s_idx_177_2] + pub_r000909_1_2) & 127;
  table_1[s_idx_177_1] = (stage_v_177_1 + 7) & 63;
  table_2[s_idx_177_2] = (stage_v_177_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int s_idx_178_1 = stage_v_101_1 & 3;
  int s_idx_178_2 = stage_v_101_2 & 3;
  int stage_v_178_1 = (table_1[s_idx_178_1] + pub_r000909_2_1) & 127;
  int stage_v_178_2 = (table_2[s_idx_178_2] + pub_r000909_2_2) & 127;
  table_1[s_idx_178_1] = (stage_v_178_1 + 7) & 63;
  table_2[s_idx_178_2] = (stage_v_178_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int s_idx_179_1 = stage_v_115_1 & 3;
  int s_idx_179_2 = stage_v_115_2 & 3;
  int stage_v_179_1 = (table_1[s_idx_179_1] + pub_r000909_11_1) & 127;
  int stage_v_179_2 = (table_2[s_idx_179_2] + pub_r000909_11_2) & 127;
  table_1[s_idx_179_1] = (stage_v_179_1 + 7) & 63;
  table_2[s_idx_179_2] = (stage_v_179_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int s_idx_180_1 = sec_r000909_20_1 & 3;
  int s_idx_180_2 = sec_r000909_20_2 & 3;
  int stage_v_180_1 = (table_1[s_idx_180_1] + pub_r000909_4_1) & 127;
  int stage_v_180_2 = (table_2[s_idx_180_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_180_1] = (stage_v_180_1 + 7) & 63;
  table_2[s_idx_180_2] = (stage_v_180_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int s_idx_181_1 = sec_r000909_6_1 & 3;
  int s_idx_181_2 = sec_r000909_6_2 & 3;
  int stage_v_181_1 = (table_1[s_idx_181_1] + pub_r000909_1_1) & 127;
  int stage_v_181_2 = (table_2[s_idx_181_2] + pub_r000909_1_2) & 127;
  table_1[s_idx_181_1] = (stage_v_181_1 + 7) & 63;
  table_2[s_idx_181_2] = (stage_v_181_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int s_idx_182_1 = stage_v_143_1 & 3;
  int s_idx_182_2 = stage_v_143_2 & 3;
  int stage_v_182_1 = (table_1[s_idx_182_1] + pub_r000909_9_1) & 127;
  int stage_v_182_2 = (table_2[s_idx_182_2] + pub_r000909_9_2) & 127;
  table_1[s_idx_182_1] = (stage_v_182_1 + 7) & 63;
  table_2[s_idx_182_2] = (stage_v_182_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int s_idx_183_1 = stage_v_116_1 & 3;
  int s_idx_183_2 = stage_v_116_2 & 3;
  int stage_v_183_1 = (table_1[s_idx_183_1] + pub_r000909_11_1) & 127;
  int stage_v_183_2 = (table_2[s_idx_183_2] + pub_r000909_11_2) & 127;
  table_1[s_idx_183_1] = (stage_v_183_1 + 7) & 63;
  table_2[s_idx_183_2] = (stage_v_183_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int s_idx_184_1 = stage_v_124_1 & 3;
  int s_idx_184_2 = stage_v_124_2 & 3;
  int stage_v_184_1 = (table_1[s_idx_184_1] + pub_r000909_13_1) & 127;
  int stage_v_184_2 = (table_2[s_idx_184_2] + pub_r000909_13_2) & 127;
  table_1[s_idx_184_1] = (stage_v_184_1 + 7) & 63;
  table_2[s_idx_184_2] = (stage_v_184_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int s_idx_185_1 = stage_v_114_1 & 3;
  int s_idx_185_2 = stage_v_114_2 & 3;
  int stage_v_185_1 = (table_1[s_idx_185_1] + pub_r000909_8_1) & 127;
  int stage_v_185_2 = (table_2[s_idx_185_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_185_1] = (stage_v_185_1 + 7) & 63;
  table_2[s_idx_185_2] = (stage_v_185_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int s_idx_186_1 = stage_v_106_1 & 3;
  int s_idx_186_2 = stage_v_106_2 & 3;
  int stage_v_186_1 = (table_1[s_idx_186_1] + pub_r000909_6_1) & 127;
  int stage_v_186_2 = (table_2[s_idx_186_2] + pub_r000909_6_2) & 127;
  table_1[s_idx_186_1] = (stage_v_186_1 + 7) & 63;
  table_2[s_idx_186_2] = (stage_v_186_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int s_idx_187_1 = stage_v_59_1 & 3;
  int s_idx_187_2 = stage_v_59_2 & 3;
  int stage_v_187_1 = (table_1[s_idx_187_1] + pub_r000909_7_1) & 127;
  int stage_v_187_2 = (table_2[s_idx_187_2] + pub_r000909_7_2) & 127;
  table_1[s_idx_187_1] = (stage_v_187_1 + 7) & 63;
  table_2[s_idx_187_2] = (stage_v_187_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int s_idx_188_1 = stage_v_174_1 & 3;
  int s_idx_188_2 = stage_v_174_2 & 3;
  int stage_v_188_1 = (table_1[s_idx_188_1] + pub_r000909_13_1) & 127;
  int stage_v_188_2 = (table_2[s_idx_188_2] + pub_r000909_13_2) & 127;
  table_1[s_idx_188_1] = (stage_v_188_1 + 7) & 63;
  table_2[s_idx_188_2] = (stage_v_188_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int s_idx_189_1 = stage_v_172_1 & 3;
  int s_idx_189_2 = stage_v_172_2 & 3;
  int stage_v_189_1 = (table_1[s_idx_189_1] + pub_r000909_2_1) & 127;
  int stage_v_189_2 = (table_2[s_idx_189_2] + pub_r000909_2_2) & 127;
  table_1[s_idx_189_1] = (stage_v_189_1 + 7) & 63;
  table_2[s_idx_189_2] = (stage_v_189_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int s_idx_190_1 = sec_r000909_13_1 & 3;
  int s_idx_190_2 = sec_r000909_13_2 & 3;
  int stage_v_190_1 = (table_1[s_idx_190_1] + pub_r000909_8_1) & 127;
  int stage_v_190_2 = (table_2[s_idx_190_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_190_1] = (stage_v_190_1 + 7) & 63;
  table_2[s_idx_190_2] = (stage_v_190_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int s_idx_191_1 = stage_v_91_1 & 3;
  int s_idx_191_2 = stage_v_91_2 & 3;
  int stage_v_191_1 = (table_1[s_idx_191_1] + pub_r000909_10_1) & 127;
  int stage_v_191_2 = (table_2[s_idx_191_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_191_1] = (stage_v_191_1 + 7) & 63;
  table_2[s_idx_191_2] = (stage_v_191_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int s_idx_192_1 = stage_v_158_1 & 3;
  int s_idx_192_2 = stage_v_158_2 & 3;
  int stage_v_192_1 = (table_1[s_idx_192_1] + pub_r000909_1_1) & 127;
  int stage_v_192_2 = (table_2[s_idx_192_2] + pub_r000909_1_2) & 127;
  table_1[s_idx_192_1] = (stage_v_192_1 + 7) & 63;
  table_2[s_idx_192_2] = (stage_v_192_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int s_idx_193_1 = stage_v_76_1 & 3;
  int s_idx_193_2 = stage_v_76_2 & 3;
  int stage_v_193_1 = (table_1[s_idx_193_1] + pub_r000909_11_1) & 127;
  int stage_v_193_2 = (table_2[s_idx_193_2] + pub_r000909_11_2) & 127;
  table_1[s_idx_193_1] = (stage_v_193_1 + 7) & 63;
  table_2[s_idx_193_2] = (stage_v_193_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int s_idx_194_1 = stage_v_94_1 & 3;
  int s_idx_194_2 = stage_v_94_2 & 3;
  int stage_v_194_1 = (table_1[s_idx_194_1] + pub_r000909_8_1) & 127;
  int stage_v_194_2 = (table_2[s_idx_194_2] + pub_r000909_8_2) & 127;
  table_1[s_idx_194_1] = (stage_v_194_1 + 7) & 63;
  table_2[s_idx_194_2] = (stage_v_194_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int s_idx_195_1 = stage_v_112_1 & 3;
  int s_idx_195_2 = stage_v_112_2 & 3;
  int stage_v_195_1 = (table_1[s_idx_195_1] + pub_r000909_10_1) & 127;
  int stage_v_195_2 = (table_2[s_idx_195_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_195_1] = (stage_v_195_1 + 7) & 63;
  table_2[s_idx_195_2] = (stage_v_195_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int s_idx_196_1 = stage_v_134_1 & 3;
  int s_idx_196_2 = stage_v_134_2 & 3;
  int stage_v_196_1 = (table_1[s_idx_196_1] + pub_r000909_6_1) & 127;
  int stage_v_196_2 = (table_2[s_idx_196_2] + pub_r000909_6_2) & 127;
  table_1[s_idx_196_1] = (stage_v_196_1 + 7) & 63;
  table_2[s_idx_196_2] = (stage_v_196_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int s_idx_197_1 = stage_v_71_1 & 3;
  int s_idx_197_2 = stage_v_71_2 & 3;
  int stage_v_197_1 = (table_1[s_idx_197_1] + pub_r000909_11_1) & 127;
  int stage_v_197_2 = (table_2[s_idx_197_2] + pub_r000909_11_2) & 127;
  table_1[s_idx_197_1] = (stage_v_197_1 + 7) & 63;
  table_2[s_idx_197_2] = (stage_v_197_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int s_idx_198_1 = stage_v_70_1 & 3;
  int s_idx_198_2 = stage_v_70_2 & 3;
  int stage_v_198_1 = (table_1[s_idx_198_1] + pub_r000909_1_1) & 127;
  int stage_v_198_2 = (table_2[s_idx_198_2] + pub_r000909_1_2) & 127;
  table_1[s_idx_198_1] = (stage_v_198_1 + 7) & 63;
  table_2[s_idx_198_2] = (stage_v_198_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int s_idx_199_1 = sec_r000909_12_1 & 3;
  int s_idx_199_2 = sec_r000909_12_2 & 3;
  int stage_v_199_1 = (table_1[s_idx_199_1] + pub_r000909_11_1) & 127;
  int stage_v_199_2 = (table_2[s_idx_199_2] + pub_r000909_11_2) & 127;
  table_1[s_idx_199_1] = (stage_v_199_1 + 7) & 63;
  table_2[s_idx_199_2] = (stage_v_199_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int s_idx_200_1 = sec_r000909_7_1 & 3;
  int s_idx_200_2 = sec_r000909_7_2 & 3;
  int stage_v_200_1 = (table_1[s_idx_200_1] + pub_r000909_6_1) & 127;
  int stage_v_200_2 = (table_2[s_idx_200_2] + pub_r000909_6_2) & 127;
  table_1[s_idx_200_1] = (stage_v_200_1 + 7) & 63;
  table_2[s_idx_200_2] = (stage_v_200_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int s_idx_201_1 = stage_v_109_1 & 3;
  int s_idx_201_2 = stage_v_109_2 & 3;
  int stage_v_201_1 = (table_1[s_idx_201_1] + pub_r000909_9_1) & 127;
  int stage_v_201_2 = (table_2[s_idx_201_2] + pub_r000909_9_2) & 127;
  table_1[s_idx_201_1] = (stage_v_201_1 + 7) & 63;
  table_2[s_idx_201_2] = (stage_v_201_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int s_idx_202_1 = stage_v_99_1 & 3;
  int s_idx_202_2 = stage_v_99_2 & 3;
  int stage_v_202_1 = (table_1[s_idx_202_1] + pub_r000909_3_1) & 127;
  int stage_v_202_2 = (table_2[s_idx_202_2] + pub_r000909_3_2) & 127;
  table_1[s_idx_202_1] = (stage_v_202_1 + 7) & 63;
  table_2[s_idx_202_2] = (stage_v_202_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int s_idx_203_1 = sec_r000909_10_1 & 3;
  int s_idx_203_2 = sec_r000909_10_2 & 3;
  int stage_v_203_1 = (table_1[s_idx_203_1] + pub_r000909_4_1) & 127;
  int stage_v_203_2 = (table_2[s_idx_203_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_203_1] = (stage_v_203_1 + 7) & 63;
  table_2[s_idx_203_2] = (stage_v_203_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int s_idx_204_1 = stage_v_105_1 & 3;
  int s_idx_204_2 = stage_v_105_2 & 3;
  int stage_v_204_1 = (table_1[s_idx_204_1] + pub_r000909_4_1) & 127;
  int stage_v_204_2 = (table_2[s_idx_204_2] + pub_r000909_4_2) & 127;
  table_1[s_idx_204_1] = (stage_v_204_1 + 7) & 63;
  table_2[s_idx_204_2] = (stage_v_204_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int s_idx_205_1 = stage_v_159_1 & 3;
  int s_idx_205_2 = stage_v_159_2 & 3;
  int stage_v_205_1 = (table_1[s_idx_205_1] + pub_r000909_0_1) & 127;
  int stage_v_205_2 = (table_2[s_idx_205_2] + pub_r000909_0_2) & 127;
  table_1[s_idx_205_1] = (stage_v_205_1 + 7) & 63;
  table_2[s_idx_205_2] = (stage_v_205_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int s_idx_206_1 = stage_v_182_1 & 3;
  int s_idx_206_2 = stage_v_182_2 & 3;
  int stage_v_206_1 = (table_1[s_idx_206_1] + pub_r000909_3_1) & 127;
  int stage_v_206_2 = (table_2[s_idx_206_2] + pub_r000909_3_2) & 127;
  table_1[s_idx_206_1] = (stage_v_206_1 + 7) & 63;
  table_2[s_idx_206_2] = (stage_v_206_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int s_idx_207_1 = stage_v_203_1 & 3;
  int s_idx_207_2 = stage_v_203_2 & 3;
  int stage_v_207_1 = (table_1[s_idx_207_1] + pub_r000909_9_1) & 127;
  int stage_v_207_2 = (table_2[s_idx_207_2] + pub_r000909_9_2) & 127;
  table_1[s_idx_207_1] = (stage_v_207_1 + 7) & 63;
  table_2[s_idx_207_2] = (stage_v_207_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int s_idx_208_1 = stage_v_55_1 & 3;
  int s_idx_208_2 = stage_v_55_2 & 3;
  int stage_v_208_1 = (table_1[s_idx_208_1] + pub_r000909_15_1) & 127;
  int stage_v_208_2 = (table_2[s_idx_208_2] + pub_r000909_15_2) & 127;
  table_1[s_idx_208_1] = (stage_v_208_1 + 7) & 63;
  table_2[s_idx_208_2] = (stage_v_208_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int s_idx_209_1 = stage_v_99_1 & 3;
  int s_idx_209_2 = stage_v_99_2 & 3;
  int stage_v_209_1 = (table_1[s_idx_209_1] + pub_r000909_9_1) & 127;
  int stage_v_209_2 = (table_2[s_idx_209_2] + pub_r000909_9_2) & 127;
  table_1[s_idx_209_1] = (stage_v_209_1 + 7) & 63;
  table_2[s_idx_209_2] = (stage_v_209_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int s_idx_210_1 = stage_v_169_1 & 3;
  int s_idx_210_2 = stage_v_169_2 & 3;
  int stage_v_210_1 = (table_1[s_idx_210_1] + pub_r000909_10_1) & 127;
  int stage_v_210_2 = (table_2[s_idx_210_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_210_1] = (stage_v_210_1 + 7) & 63;
  table_2[s_idx_210_2] = (stage_v_210_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int s_idx_211_1 = stage_v_179_1 & 3;
  int s_idx_211_2 = stage_v_179_2 & 3;
  int stage_v_211_1 = (table_1[s_idx_211_1] + pub_r000909_2_1) & 127;
  int stage_v_211_2 = (table_2[s_idx_211_2] + pub_r000909_2_2) & 127;
  table_1[s_idx_211_1] = (stage_v_211_1 + 7) & 63;
  table_2[s_idx_211_2] = (stage_v_211_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int s_idx_212_1 = sec_r000909_19_1 & 3;
  int s_idx_212_2 = sec_r000909_19_2 & 3;
  int stage_v_212_1 = (table_1[s_idx_212_1] + pub_r000909_13_1) & 127;
  int stage_v_212_2 = (table_2[s_idx_212_2] + pub_r000909_13_2) & 127;
  table_1[s_idx_212_1] = (stage_v_212_1 + 7) & 63;
  table_2[s_idx_212_2] = (stage_v_212_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int s_idx_213_1 = sec_r000909_0_1 & 3;
  int s_idx_213_2 = sec_r000909_0_2 & 3;
  int stage_v_213_1 = (table_1[s_idx_213_1] + pub_r000909_6_1) & 127;
  int stage_v_213_2 = (table_2[s_idx_213_2] + pub_r000909_6_2) & 127;
  table_1[s_idx_213_1] = (stage_v_213_1 + 7) & 63;
  table_2[s_idx_213_2] = (stage_v_213_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int s_idx_214_1 = stage_v_77_1 & 3;
  int s_idx_214_2 = stage_v_77_2 & 3;
  int stage_v_214_1 = (table_1[s_idx_214_1] + pub_r000909_10_1) & 127;
  int stage_v_214_2 = (table_2[s_idx_214_2] + pub_r000909_10_2) & 127;
  table_1[s_idx_214_1] = (stage_v_214_1 + 7) & 63;
  table_2[s_idx_214_2] = (stage_v_214_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000909_9_1 != sec_r000909_9_2);
  __CPROVER_assume(pub_r000909_7_1 == pub_r000909_7_2);
  __CPROVER_assume(pub_r000909_0_1 == pub_r000909_0_2);
  __CPROVER_assume(pub_r000909_3_1 == pub_r000909_3_2);
  __CPROVER_assume(pub_r000909_13_1 == pub_r000909_13_2);
  __CPROVER_assume(sec_r000909_5_1 != sec_r000909_5_2);
  __CPROVER_assume(pub_r000909_2_1 == pub_r000909_2_2);
  __CPROVER_assume(sec_r000909_11_1 != sec_r000909_11_2);
  __CPROVER_assume(sec_r000909_18_1 != sec_r000909_18_2);
  __CPROVER_assume(sec_r000909_10_1 != sec_r000909_10_2);
  __CPROVER_assume(sec_r000909_20_1 != sec_r000909_20_2);
  __CPROVER_assume(pub_r000909_14_1 == pub_r000909_14_2);
  __CPROVER_assume(sec_r000909_3_1 != sec_r000909_3_2);
  __CPROVER_assume(sec_r000909_8_1 != sec_r000909_8_2);
  __CPROVER_assume(sec_r000909_6_1 != sec_r000909_6_2);
  __CPROVER_assume(sec_r000909_17_1 != sec_r000909_17_2);
  __CPROVER_assume(pub_r000909_1_1 == pub_r000909_1_2);
  __CPROVER_assume(pub_r000909_6_1 == pub_r000909_6_2);
  __CPROVER_assume(pub_r000909_5_1 == pub_r000909_5_2);
  __CPROVER_assume(sec_r000909_4_1 != sec_r000909_4_2);
  __CPROVER_assume(sec_r000909_19_1 != sec_r000909_19_2);
  __CPROVER_assume(pub_r000909_12_1 == pub_r000909_12_2);
  __CPROVER_assume(pub_r000909_9_1 == pub_r000909_9_2);
  __CPROVER_assume(sec_r000909_16_1 != sec_r000909_16_2);
  __CPROVER_assume(pub_r000909_11_1 == pub_r000909_11_2);
  __CPROVER_assume(sec_r000909_14_1 != sec_r000909_14_2);
  __CPROVER_assume(sec_r000909_13_1 != sec_r000909_13_2);
  __CPROVER_assume(pub_r000909_10_1 == pub_r000909_10_2);
  __CPROVER_assume(pub_r000909_4_1 == pub_r000909_4_2);
  __CPROVER_assume(pub_r000909_15_1 == pub_r000909_15_2);
  __CPROVER_assume(sec_r000909_12_1 != sec_r000909_12_2);
  __CPROVER_assume(sec_r000909_1_1 != sec_r000909_1_2);
  __CPROVER_assume(sec_r000909_0_1 != sec_r000909_0_2);
  __CPROVER_assume(sec_r000909_15_1 != sec_r000909_15_2);
  __CPROVER_assume(sec_r000909_7_1 != sec_r000909_7_2);
  __CPROVER_assume(pub_r000909_8_1 == pub_r000909_8_2);
  __CPROVER_assume(sec_r000909_2_1 != sec_r000909_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.stride == st_var_3_2.stride);
  assert(st_var_3_1.trace == st_var_3_2.trace);
  assert(st_var_3_1.determinant == st_var_3_2.determinant);
  assert(st_var_3_1.dim == st_var_3_2.dim);
  assert(st_var_3_1.density == st_var_3_2.density);
  assert(st_var_3_1.scale == st_var_3_2.scale);
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
  assert(s_idx_33_1 == s_idx_33_2);
  assert(stage_v_33_1 == stage_v_33_2);
  assert(s_idx_34_1 == s_idx_34_2);
  assert(stage_v_34_1 == stage_v_34_2);
  assert(s_idx_35_1 == s_idx_35_2);
  assert(stage_v_35_1 == stage_v_35_2);
  assert(s_idx_36_1 == s_idx_36_2);
  assert(stage_v_36_1 == stage_v_36_2);
  assert(s_idx_37_1 == s_idx_37_2);
  assert(stage_v_37_1 == stage_v_37_2);
  assert(s_idx_38_1 == s_idx_38_2);
  assert(stage_v_38_1 == stage_v_38_2);
  assert(s_idx_39_1 == s_idx_39_2);
  assert(stage_v_39_1 == stage_v_39_2);
  assert(s_idx_40_1 == s_idx_40_2);
  assert(stage_v_40_1 == stage_v_40_2);
  assert(s_idx_41_1 == s_idx_41_2);
  assert(stage_v_41_1 == stage_v_41_2);
  assert(s_idx_42_1 == s_idx_42_2);
  assert(stage_v_42_1 == stage_v_42_2);
  assert(s_idx_43_1 == s_idx_43_2);
  assert(stage_v_43_1 == stage_v_43_2);
  assert(s_idx_44_1 == s_idx_44_2);
  assert(stage_v_44_1 == stage_v_44_2);
  assert(s_idx_45_1 == s_idx_45_2);
  assert(stage_v_45_1 == stage_v_45_2);
  assert(s_idx_46_1 == s_idx_46_2);
  assert(stage_v_46_1 == stage_v_46_2);
  assert(s_idx_47_1 == s_idx_47_2);
  assert(stage_v_47_1 == stage_v_47_2);
  assert(s_idx_48_1 == s_idx_48_2);
  assert(stage_v_48_1 == stage_v_48_2);
  assert(s_idx_49_1 == s_idx_49_2);
  assert(stage_v_49_1 == stage_v_49_2);
  assert(s_idx_50_1 == s_idx_50_2);
  assert(stage_v_50_1 == stage_v_50_2);
  assert(s_idx_51_1 == s_idx_51_2);
  assert(stage_v_51_1 == stage_v_51_2);
  assert(s_idx_52_1 == s_idx_52_2);
  assert(stage_v_52_1 == stage_v_52_2);
  assert(s_idx_53_1 == s_idx_53_2);
  assert(stage_v_53_1 == stage_v_53_2);
  assert(s_idx_54_1 == s_idx_54_2);
  assert(stage_v_54_1 == stage_v_54_2);
  assert(s_idx_55_1 == s_idx_55_2);
  assert(stage_v_55_1 == stage_v_55_2);
  assert(s_idx_56_1 == s_idx_56_2);
  assert(stage_v_56_1 == stage_v_56_2);
  assert(s_idx_57_1 == s_idx_57_2);
  assert(stage_v_57_1 == stage_v_57_2);
  assert(s_idx_58_1 == s_idx_58_2);
  assert(stage_v_58_1 == stage_v_58_2);
  assert(s_idx_59_1 == s_idx_59_2);
  assert(stage_v_59_1 == stage_v_59_2);
  assert(s_idx_60_1 == s_idx_60_2);
  assert(stage_v_60_1 == stage_v_60_2);
  assert(s_idx_61_1 == s_idx_61_2);
  assert(stage_v_61_1 == stage_v_61_2);
  assert(s_idx_62_1 == s_idx_62_2);
  assert(stage_v_62_1 == stage_v_62_2);
  assert(s_idx_63_1 == s_idx_63_2);
  assert(stage_v_63_1 == stage_v_63_2);
  assert(s_idx_64_1 == s_idx_64_2);
  assert(stage_v_64_1 == stage_v_64_2);
  assert(s_idx_65_1 == s_idx_65_2);
  assert(stage_v_65_1 == stage_v_65_2);
  assert(s_idx_66_1 == s_idx_66_2);
  assert(stage_v_66_1 == stage_v_66_2);
  assert(s_idx_67_1 == s_idx_67_2);
  assert(stage_v_67_1 == stage_v_67_2);
  assert(s_idx_68_1 == s_idx_68_2);
  assert(stage_v_68_1 == stage_v_68_2);
  assert(s_idx_69_1 == s_idx_69_2);
  assert(stage_v_69_1 == stage_v_69_2);
  assert(s_idx_70_1 == s_idx_70_2);
  assert(stage_v_70_1 == stage_v_70_2);
  assert(s_idx_71_1 == s_idx_71_2);
  assert(stage_v_71_1 == stage_v_71_2);
  assert(s_idx_72_1 == s_idx_72_2);
  assert(stage_v_72_1 == stage_v_72_2);
  assert(s_idx_73_1 == s_idx_73_2);
  assert(stage_v_73_1 == stage_v_73_2);
  assert(s_idx_74_1 == s_idx_74_2);
  assert(stage_v_74_1 == stage_v_74_2);
  assert(s_idx_75_1 == s_idx_75_2);
  assert(stage_v_75_1 == stage_v_75_2);
  assert(s_idx_76_1 == s_idx_76_2);
  assert(stage_v_76_1 == stage_v_76_2);
  assert(s_idx_77_1 == s_idx_77_2);
  assert(stage_v_77_1 == stage_v_77_2);
  assert(s_idx_78_1 == s_idx_78_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(s_idx_79_1 == s_idx_79_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(s_idx_80_1 == s_idx_80_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(s_idx_81_1 == s_idx_81_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(s_idx_82_1 == s_idx_82_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(s_idx_83_1 == s_idx_83_2);
  assert(stage_v_83_1 == stage_v_83_2);
  assert(s_idx_84_1 == s_idx_84_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(s_idx_85_1 == s_idx_85_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(s_idx_86_1 == s_idx_86_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(s_idx_87_1 == s_idx_87_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(s_idx_88_1 == s_idx_88_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(s_idx_89_1 == s_idx_89_2);
  assert(stage_v_89_1 == stage_v_89_2);
  assert(s_idx_90_1 == s_idx_90_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(s_idx_91_1 == s_idx_91_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(s_idx_92_1 == s_idx_92_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(s_idx_93_1 == s_idx_93_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(s_idx_94_1 == s_idx_94_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(s_idx_95_1 == s_idx_95_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(s_idx_96_1 == s_idx_96_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(s_idx_97_1 == s_idx_97_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(s_idx_98_1 == s_idx_98_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(s_idx_99_1 == s_idx_99_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(s_idx_100_1 == s_idx_100_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(s_idx_101_1 == s_idx_101_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(s_idx_102_1 == s_idx_102_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(s_idx_103_1 == s_idx_103_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(s_idx_104_1 == s_idx_104_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(s_idx_105_1 == s_idx_105_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(s_idx_106_1 == s_idx_106_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(s_idx_107_1 == s_idx_107_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(s_idx_108_1 == s_idx_108_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(s_idx_109_1 == s_idx_109_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(s_idx_110_1 == s_idx_110_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(s_idx_111_1 == s_idx_111_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(s_idx_112_1 == s_idx_112_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(s_idx_113_1 == s_idx_113_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(s_idx_114_1 == s_idx_114_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(s_idx_115_1 == s_idx_115_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(s_idx_116_1 == s_idx_116_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(s_idx_117_1 == s_idx_117_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(s_idx_118_1 == s_idx_118_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(s_idx_119_1 == s_idx_119_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(s_idx_120_1 == s_idx_120_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(s_idx_121_1 == s_idx_121_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(s_idx_122_1 == s_idx_122_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(s_idx_123_1 == s_idx_123_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(s_idx_124_1 == s_idx_124_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(s_idx_125_1 == s_idx_125_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(s_idx_126_1 == s_idx_126_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(s_idx_127_1 == s_idx_127_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(s_idx_128_1 == s_idx_128_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(s_idx_129_1 == s_idx_129_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(s_idx_130_1 == s_idx_130_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(s_idx_131_1 == s_idx_131_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(s_idx_132_1 == s_idx_132_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(s_idx_133_1 == s_idx_133_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(s_idx_134_1 == s_idx_134_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(s_idx_135_1 == s_idx_135_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(s_idx_136_1 == s_idx_136_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(s_idx_137_1 == s_idx_137_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(s_idx_138_1 == s_idx_138_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(s_idx_139_1 == s_idx_139_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(s_idx_140_1 == s_idx_140_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(s_idx_141_1 == s_idx_141_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(s_idx_142_1 == s_idx_142_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(s_idx_143_1 == s_idx_143_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(s_idx_144_1 == s_idx_144_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(s_idx_145_1 == s_idx_145_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(s_idx_146_1 == s_idx_146_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(s_idx_147_1 == s_idx_147_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(s_idx_148_1 == s_idx_148_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(s_idx_149_1 == s_idx_149_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(s_idx_150_1 == s_idx_150_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(s_idx_151_1 == s_idx_151_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(s_idx_152_1 == s_idx_152_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(s_idx_153_1 == s_idx_153_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(s_idx_154_1 == s_idx_154_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(s_idx_155_1 == s_idx_155_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(s_idx_156_1 == s_idx_156_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(s_idx_157_1 == s_idx_157_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(s_idx_158_1 == s_idx_158_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(s_idx_159_1 == s_idx_159_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(s_idx_160_1 == s_idx_160_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(s_idx_161_1 == s_idx_161_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(s_idx_162_1 == s_idx_162_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(s_idx_163_1 == s_idx_163_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(s_idx_164_1 == s_idx_164_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(s_idx_165_1 == s_idx_165_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(s_idx_166_1 == s_idx_166_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(s_idx_167_1 == s_idx_167_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(s_idx_168_1 == s_idx_168_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(s_idx_169_1 == s_idx_169_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(s_idx_170_1 == s_idx_170_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(s_idx_171_1 == s_idx_171_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(s_idx_172_1 == s_idx_172_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(s_idx_173_1 == s_idx_173_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(s_idx_174_1 == s_idx_174_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(s_idx_175_1 == s_idx_175_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(s_idx_176_1 == s_idx_176_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(s_idx_177_1 == s_idx_177_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(s_idx_178_1 == s_idx_178_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(s_idx_179_1 == s_idx_179_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(s_idx_180_1 == s_idx_180_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(s_idx_181_1 == s_idx_181_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(s_idx_182_1 == s_idx_182_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(s_idx_183_1 == s_idx_183_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(s_idx_184_1 == s_idx_184_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(s_idx_185_1 == s_idx_185_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(s_idx_186_1 == s_idx_186_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(s_idx_187_1 == s_idx_187_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(s_idx_188_1 == s_idx_188_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(s_idx_189_1 == s_idx_189_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(s_idx_190_1 == s_idx_190_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(s_idx_191_1 == s_idx_191_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(s_idx_192_1 == s_idx_192_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(s_idx_193_1 == s_idx_193_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(s_idx_194_1 == s_idx_194_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(s_idx_195_1 == s_idx_195_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(s_idx_196_1 == s_idx_196_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(s_idx_197_1 == s_idx_197_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(s_idx_198_1 == s_idx_198_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(s_idx_199_1 == s_idx_199_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(s_idx_200_1 == s_idx_200_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(s_idx_201_1 == s_idx_201_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(s_idx_202_1 == s_idx_202_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(s_idx_203_1 == s_idx_203_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(s_idx_204_1 == s_idx_204_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(s_idx_205_1 == s_idx_205_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(s_idx_206_1 == s_idx_206_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(s_idx_207_1 == s_idx_207_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(s_idx_208_1 == s_idx_208_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(s_idx_209_1 == s_idx_209_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(s_idx_210_1 == s_idx_210_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(s_idx_211_1 == s_idx_211_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(s_idx_212_1 == s_idx_212_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(s_idx_213_1 == s_idx_213_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(s_idx_214_1 == s_idx_214_2);
  assert(stage_v_214_1 == stage_v_214_2);
}


