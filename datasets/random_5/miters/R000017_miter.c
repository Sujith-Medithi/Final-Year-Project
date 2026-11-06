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
struct Vector3D_R000017_1713_0
{
  short coord_z;
  int coord_x;
  unsigned char pitch;
  unsigned char heading;
  int norm_sq;
  int buffer[3];
};
struct StreamBuffer_R000017_1713_1
{
  short state;
  int head;
  int tail;
  int buffer[3];
};
union RegisterBank_R000017_1713_0
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
void fn_R000017_1713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000017_1713_1 st_1 = {0};
  struct StreamBuffer_R000017_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_18_1 = local_arr_1[aux_1 % 3];
  int window_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_18_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_32_1 > 34)
  {
    acc_1 = ((acc_1 + (mask_32_1 * 2)) + 5) & 127;
    aux_1 ^= mask_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_32_2 > 34)
  {
    acc_2 = ((acc_2 + (mask_32_2 * 2)) + 5) & 127;
    aux_2 ^= mask_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_49_1) & 63;
  aux_2 = (aux_2 + bound_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
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

  assert(window_18_1 == window_18_2);
  assert(mask_32_1 == mask_32_2);
  assert(bound_49_1 == bound_49_2);
}

int fn_R000017_1713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000017_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int window_18 = local_arr[aux % 3];
  acc = (acc + (window_18 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_32 > 34)
  {
    acc = ((acc + (mask_32 * 2)) + 5) & 127;
    aux ^= mask_32 & 15;
  }
  else
  {
    acc = ((acc - mask_32) + 11) & 127;
    aux += 3;
  }
  int bound_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_49) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000017_1713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000017_1713_1 st_1 = {0};
  struct StreamBuffer_R000017_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int cursor_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_87_1) & 63;
  aux_2 = (aux_2 + cursor_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_53_1 > 18)
  {
    acc_1 = ((acc_1 + (threshold_53_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_53_2 > 18)
  {
    acc_2 = ((acc_2 + (threshold_53_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_58_1 = local_arr_1[aux_1 % 3];
  int quantum_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_58_2 * 2)) & 127;
  int threshold_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_22_1)
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

  switch (threshold_22_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_87_1 == cursor_87_2);
  assert(threshold_53_1 == threshold_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_58_1 == quantum_58_2);
  assert(threshold_22_1 == threshold_22_2);
}

int fn_R000017_1713_1(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000017_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int cursor_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_87) & 63;
  acc ^= aux;
  int threshold_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_53 > 18)
  {
    acc = ((acc + (threshold_53 * 2)) + 5) & 127;
    aux ^= threshold_53 & 15;
  }
  else
  {
    acc = ((acc - threshold_53) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_58 = local_arr[aux % 3];
  acc = (acc + (quantum_58 * 2)) & 127;
  int threshold_22 = (aux + st.buffer[1]) & 3;
  switch (threshold_22)
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

void fn_R000017_1713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st_1 = {0};
  struct Vector3D_R000017_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_27_1 = local_arr_1[aux_1 % 3];
  int sample_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_27_2 * 2)) & 127;
  int cursor_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_26_1) & 63;
  aux_2 = (aux_2 + cursor_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_96_1)
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

  switch (pivot_96_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_27_1 == sample_27_2);
  assert(cursor_26_1 == cursor_26_2);
  assert(pivot_96_1 == pivot_96_2);
}

int fn_R000017_1713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int sample_27 = local_arr[aux % 3];
  acc = (acc + (sample_27 * 2)) & 127;
  int cursor_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_26) & 63;
  acc ^= aux;
  int pivot_96 = (aux + st.buffer[1]) & 3;
  switch (pivot_96)
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

void fn_R000017_1713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000017_1713_1 st_1 = {0};
  struct StreamBuffer_R000017_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int stride_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_40_1) & 63;
  aux_2 = (aux_2 + stride_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_82_1 = local_arr_1[aux_1 % 3];
  int offset_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_82_2 * 2)) & 127;
  int scale_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_56_1 > 41)
  {
    acc_1 = ((acc_1 + (scale_56_1 * 2)) + 5) & 127;
    aux_1 ^= scale_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_56_2 > 41)
  {
    acc_2 = ((acc_2 + (scale_56_2 * 2)) + 5) & 127;
    aux_2 ^= scale_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_20_1)
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

  switch (weight_20_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_40_1 == stride_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_82_1 == offset_82_2);
  assert(scale_56_1 == scale_56_2);
  assert(weight_20_1 == weight_20_2);
}

int fn_R000017_1713_3(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000017_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int stride_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_40) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_82 = local_arr[aux % 3];
  acc = (acc + (offset_82 * 2)) & 127;
  int scale_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_56 > 41)
  {
    acc = ((acc + (scale_56 * 2)) + 5) & 127;
    aux ^= scale_56 & 15;
  }
  else
  {
    acc = ((acc - scale_56) + 11) & 127;
    aux += 3;
  }
  int weight_20 = (aux + st.buffer[1]) & 3;
  switch (weight_20)
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

void fn_R000017_1713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st_1 = {0};
  struct Vector3D_R000017_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int parity_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_99_1)
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

  switch (parity_99_2)
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

  int residue_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_95_1) & 63;
  aux_2 = (aux_2 + residue_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_99_1 == parity_99_2);
  assert(residue_95_1 == residue_95_2);
}

int fn_R000017_1713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int parity_99 = (aux + st.buffer[1]) & 3;
  switch (parity_99)
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

  int residue_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_95) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000017_1713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st_1 = {0};
  struct Vector3D_R000017_1713_0 st_2 = {0};
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
  int sample_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_70_1) & 63;
  aux_2 = (aux_2 + sample_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_56_1)
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

  switch (index_reg_56_2)
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

  int residue_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_24_1 > 45)
  {
    acc_1 = ((acc_1 + (residue_24_1 * 2)) + 5) & 127;
    aux_1 ^= residue_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_24_2 > 45)
  {
    acc_2 = ((acc_2 + (residue_24_2 * 2)) + 5) & 127;
    aux_2 ^= residue_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_70_1 == sample_70_2);
  assert(index_reg_56_1 == index_reg_56_2);
  assert(residue_24_1 == residue_24_2);
}

int fn_R000017_1713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_70) & 63;
  acc ^= aux;
  int index_reg_56 = (aux + st.buffer[1]) & 3;
  switch (index_reg_56)
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

  int residue_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_24 > 45)
  {
    acc = ((acc + (residue_24 * 2)) + 5) & 127;
    aux ^= residue_24 & 15;
  }
  else
  {
    acc = ((acc - residue_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000017_1713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st_1 = {0};
  struct Vector3D_R000017_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int tracker_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_51_1)
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

  switch (tracker_51_2)
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

  int checksum_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_52_1) & 63;
  aux_2 = (aux_2 + checksum_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_51_1 == tracker_51_2);
  assert(checksum_52_1 == checksum_52_2);
}

int fn_R000017_1713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int tracker_51 = (aux + st.buffer[1]) & 3;
  switch (tracker_51)
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

  int checksum_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_52) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000017_1713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000017_1713_1 st_1 = {0};
  struct StreamBuffer_R000017_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int damping_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_43_1 > 46)
  {
    acc_1 = ((acc_1 + (damping_43_1 * 2)) + 5) & 127;
    aux_1 ^= damping_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_43_2 > 46)
  {
    acc_2 = ((acc_2 + (damping_43_2 * 2)) + 5) & 127;
    aux_2 ^= damping_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_43_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_19_1)
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

  switch (pivot_19_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_43_1 == damping_43_2);
  assert(pivot_19_1 == pivot_19_2);
}

int fn_R000017_1713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000017_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int damping_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_43 > 46)
  {
    acc = ((acc + (damping_43 * 2)) + 5) & 127;
    aux ^= damping_43 & 15;
  }
  else
  {
    acc = ((acc - damping_43) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_19 = (aux + st.buffer[1]) & 3;
  switch (pivot_19)
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

void fn_R000017_1713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st_1 = {0};
  struct Vector3D_R000017_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int phase_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_30_1) & 63;
  aux_2 = (aux_2 + phase_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_16_1 = local_arr_1[aux_1 % 3];
  int sample_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_16_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_30_1 == phase_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_16_1 == sample_16_2);
}

int fn_R000017_1713_8(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int phase_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_30) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_16 = local_arr[aux % 3];
  acc = (acc + (sample_16 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000017_1713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st_1 = {0};
  struct Vector3D_R000017_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int margin_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_48_1) & 63;
  aux_2 = (aux_2 + margin_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_56_1 > 36)
  {
    acc_1 = ((acc_1 + (pivot_56_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_56_2 > 36)
  {
    acc_2 = ((acc_2 + (pivot_56_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_81_1)
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

  switch (sample_81_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_48_1 == margin_48_2);
  assert(pivot_56_1 == pivot_56_2);
  assert(sample_81_1 == sample_81_2);
}

int fn_R000017_1713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int margin_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_48) & 63;
  acc ^= aux;
  int pivot_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_56 > 36)
  {
    acc = ((acc + (pivot_56 * 2)) + 5) & 127;
    aux ^= pivot_56 & 15;
  }
  else
  {
    acc = ((acc - pivot_56) + 11) & 127;
    aux += 3;
  }
  int sample_81 = (aux + st.buffer[1]) & 3;
  switch (sample_81)
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

void fn_R000017_1713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000017_1713_1 st_1 = {0};
  struct StreamBuffer_R000017_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int pivot_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_18_1) & 63;
  aux_2 = (aux_2 + pivot_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_91_1 > 34)
  {
    acc_1 = ((acc_1 + (metric_91_1 * 2)) + 5) & 127;
    aux_1 ^= metric_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_91_2 > 34)
  {
    acc_2 = ((acc_2 + (metric_91_2 * 2)) + 5) & 127;
    aux_2 ^= metric_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_91_2) + 11) & 127;
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
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_18_1 == pivot_18_2);
  assert(metric_91_1 == metric_91_2);
  assert(segment_62_1 == segment_62_2);
}

int fn_R000017_1713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000017_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int pivot_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_18) & 63;
  acc ^= aux;
  int metric_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_91 > 34)
  {
    acc = ((acc + (metric_91 * 2)) + 5) & 127;
    aux ^= metric_91 & 15;
  }
  else
  {
    acc = ((acc - metric_91) + 11) & 127;
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

void fn_R000017_1713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000017_1713_1 st_1 = {0};
  struct StreamBuffer_R000017_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int stride_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_81_1)
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

  switch (stride_81_2)
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

  int weight_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_52_1 > 11)
  {
    acc_1 = ((acc_1 + (weight_52_1 * 2)) + 5) & 127;
    aux_1 ^= weight_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_52_2 > 11)
  {
    acc_2 = ((acc_2 + (weight_52_2 * 2)) + 5) & 127;
    aux_2 ^= weight_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_13_1) & 63;
  aux_2 = (aux_2 + damping_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_81_1 == stride_81_2);
  assert(weight_52_1 == weight_52_2);
  assert(damping_13_1 == damping_13_2);
}

int fn_R000017_1713_11(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000017_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int stride_81 = (aux + st.buffer[1]) & 3;
  switch (stride_81)
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

  int weight_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_52 > 11)
  {
    acc = ((acc + (weight_52 * 2)) + 5) & 127;
    aux ^= weight_52 & 15;
  }
  else
  {
    acc = ((acc - weight_52) + 11) & 127;
    aux += 3;
  }
  int damping_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_13) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000017_1713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st_1 = {0};
  struct Vector3D_R000017_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int factor_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_37_1 > 38)
  {
    acc_1 = ((acc_1 + (factor_37_1 * 2)) + 5) & 127;
    aux_1 ^= factor_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_37_2 > 38)
  {
    acc_2 = ((acc_2 + (factor_37_2 * 2)) + 5) & 127;
    aux_2 ^= factor_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_37_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_89_1) & 63;
  aux_2 = (aux_2 + tracker_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_97_1 = local_arr_1[aux_1 % 3];
  int parity_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_37_1 == factor_37_2);
  assert(tracker_89_1 == tracker_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_97_1 == parity_97_2);
}

int fn_R000017_1713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int factor_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_37 > 38)
  {
    acc = ((acc + (factor_37 * 2)) + 5) & 127;
    aux ^= factor_37 & 15;
  }
  else
  {
    acc = ((acc - factor_37) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_89) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_97 = local_arr[aux % 3];
  acc = (acc + (parity_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000017_1713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st_1 = {0};
  struct Vector3D_R000017_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int delta_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_51_1)
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

  switch (delta_51_2)
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
  int scale_66_1 = local_arr_1[aux_1 % 3];
  int scale_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_66_2 * 2)) & 127;
  int sample_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_65_1) & 63;
  aux_2 = (aux_2 + sample_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_51_1 == delta_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_66_1 == scale_66_2);
  assert(sample_65_1 == sample_65_2);
}

int fn_R000017_1713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int delta_51 = (aux + st.buffer[1]) & 3;
  switch (delta_51)
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
  int scale_66 = local_arr[aux % 3];
  acc = (acc + (scale_66 * 2)) & 127;
  int sample_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000017_1713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st_1 = {0};
  struct Vector3D_R000017_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int stride_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_41_1 > 11)
  {
    acc_1 = ((acc_1 + (stride_41_1 * 2)) + 5) & 127;
    aux_1 ^= stride_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_41_2 > 11)
  {
    acc_2 = ((acc_2 + (stride_41_2 * 2)) + 5) & 127;
    aux_2 ^= stride_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_41_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_19_1) & 63;
  aux_2 = (aux_2 + window_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_15_1)
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

  switch (sample_15_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_41_1 == stride_41_2);
  assert(window_19_1 == window_19_2);
  assert(sample_15_1 == sample_15_2);
}

int fn_R000017_1713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int stride_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_41 > 11)
  {
    acc = ((acc + (stride_41 * 2)) + 5) & 127;
    aux ^= stride_41 & 15;
  }
  else
  {
    acc = ((acc - stride_41) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_19) & 63;
  acc ^= aux;
  int sample_15 = (aux + st.buffer[1]) & 3;
  switch (sample_15)
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

void fn_R000017_1713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st_1 = {0};
  struct Vector3D_R000017_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int tracker_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_47_1 > 16)
  {
    acc_1 = ((acc_1 + (tracker_47_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_47_2 > 16)
  {
    acc_2 = ((acc_2 + (tracker_47_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_75_1)
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

  switch (quantum_75_2)
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

  int accumulator_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_46_1) & 63;
  aux_2 = (aux_2 + accumulator_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_47_1 == tracker_47_2);
  assert(quantum_75_1 == quantum_75_2);
  assert(accumulator_46_1 == accumulator_46_2);
}

int fn_R000017_1713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000017_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int tracker_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_47 > 16)
  {
    acc = ((acc + (tracker_47 * 2)) + 5) & 127;
    aux ^= tracker_47 & 15;
  }
  else
  {
    acc = ((acc - tracker_47) + 11) & 127;
    aux += 3;
  }
  int quantum_75 = (aux + st.buffer[1]) & 3;
  switch (quantum_75)
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

  int accumulator_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_46) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000017_0_1;
  int sec_r000017_0_2;
  int sec_r000017_1_1;
  int sec_r000017_1_2;
  int sec_r000017_2_1;
  int sec_r000017_2_2;
  int sec_r000017_3_1;
  int sec_r000017_3_2;
  int sec_r000017_4_1;
  int sec_r000017_4_2;
  int sec_r000017_5_1;
  int sec_r000017_5_2;
  int sec_r000017_6_1;
  int sec_r000017_6_2;
  int sec_r000017_7_1;
  int sec_r000017_7_2;
  int sec_r000017_8_1;
  int sec_r000017_8_2;
  int sec_r000017_9_1;
  int sec_r000017_9_2;
  int sec_r000017_10_1;
  int sec_r000017_10_2;
  int sec_r000017_11_1;
  int sec_r000017_11_2;
  int sec_r000017_12_1;
  int sec_r000017_12_2;
  int sec_r000017_13_1;
  int sec_r000017_13_2;
  int sec_r000017_14_1;
  int sec_r000017_14_2;
  int sec_r000017_15_1;
  int sec_r000017_15_2;
  int sec_r000017_16_1;
  int sec_r000017_16_2;
  int sec_r000017_17_1;
  int sec_r000017_17_2;
  int sec_r000017_18_1;
  int sec_r000017_18_2;
  int sec_r000017_19_1;
  int sec_r000017_19_2;
  int sec_r000017_20_1;
  int sec_r000017_20_2;
  int pub_r000017_0_1;
  int pub_r000017_0_2;
  int pub_r000017_1_1;
  int pub_r000017_1_2;
  int pub_r000017_2_1;
  int pub_r000017_2_2;
  int pub_r000017_3_1;
  int pub_r000017_3_2;
  int pub_r000017_4_1;
  int pub_r000017_4_2;
  int pub_r000017_5_1;
  int pub_r000017_5_2;
  int pub_r000017_6_1;
  int pub_r000017_6_2;
  int pub_r000017_7_1;
  int pub_r000017_7_2;
  int pub_r000017_8_1;
  int pub_r000017_8_2;
  int pub_r000017_9_1;
  int pub_r000017_9_2;
  int pub_r000017_10_1;
  int pub_r000017_10_2;
  int pub_r000017_11_1;
  int pub_r000017_11_2;
  int pub_r000017_12_1;
  int pub_r000017_12_2;
  int pub_r000017_13_1;
  int pub_r000017_13_2;
  int pub_r000017_14_1;
  int pub_r000017_14_2;
  int pub_r000017_15_1;
  int pub_r000017_15_2;
  int pub_r000017_16_1;
  int pub_r000017_16_2;
  int pub_r000017_17_1;
  int pub_r000017_17_2;
  int pub_r000017_18_1;
  int pub_r000017_18_2;
  int pub_r000017_19_1;
  int pub_r000017_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000017_0_1 >= (-100)) && (pub_r000017_0_1 <= 100));
  __CPROVER_assume((pub_r000017_0_2 >= (-100)) && (pub_r000017_0_2 <= 100));
  __CPROVER_assume((pub_r000017_1_1 >= (-100)) && (pub_r000017_1_1 <= 100));
  __CPROVER_assume((pub_r000017_1_2 >= (-100)) && (pub_r000017_1_2 <= 100));
  __CPROVER_assume((pub_r000017_2_1 >= (-100)) && (pub_r000017_2_1 <= 100));
  __CPROVER_assume((pub_r000017_2_2 >= (-100)) && (pub_r000017_2_2 <= 100));
  __CPROVER_assume((pub_r000017_3_1 >= (-100)) && (pub_r000017_3_1 <= 100));
  __CPROVER_assume((pub_r000017_3_2 >= (-100)) && (pub_r000017_3_2 <= 100));
  __CPROVER_assume((pub_r000017_4_1 >= (-100)) && (pub_r000017_4_1 <= 100));
  __CPROVER_assume((pub_r000017_4_2 >= (-100)) && (pub_r000017_4_2 <= 100));
  __CPROVER_assume((pub_r000017_5_1 >= (-100)) && (pub_r000017_5_1 <= 100));
  __CPROVER_assume((pub_r000017_5_2 >= (-100)) && (pub_r000017_5_2 <= 100));
  __CPROVER_assume((pub_r000017_6_1 >= (-100)) && (pub_r000017_6_1 <= 100));
  __CPROVER_assume((pub_r000017_6_2 >= (-100)) && (pub_r000017_6_2 <= 100));
  __CPROVER_assume((pub_r000017_7_1 >= (-100)) && (pub_r000017_7_1 <= 100));
  __CPROVER_assume((pub_r000017_7_2 >= (-100)) && (pub_r000017_7_2 <= 100));
  __CPROVER_assume((pub_r000017_8_1 >= (-100)) && (pub_r000017_8_1 <= 100));
  __CPROVER_assume((pub_r000017_8_2 >= (-100)) && (pub_r000017_8_2 <= 100));
  __CPROVER_assume((pub_r000017_9_1 >= (-100)) && (pub_r000017_9_1 <= 100));
  __CPROVER_assume((pub_r000017_9_2 >= (-100)) && (pub_r000017_9_2 <= 100));
  __CPROVER_assume((pub_r000017_10_1 >= (-100)) && (pub_r000017_10_1 <= 100));
  __CPROVER_assume((pub_r000017_10_2 >= (-100)) && (pub_r000017_10_2 <= 100));
  __CPROVER_assume((pub_r000017_11_1 >= (-100)) && (pub_r000017_11_1 <= 100));
  __CPROVER_assume((pub_r000017_11_2 >= (-100)) && (pub_r000017_11_2 <= 100));
  __CPROVER_assume((pub_r000017_12_1 >= (-100)) && (pub_r000017_12_1 <= 100));
  __CPROVER_assume((pub_r000017_12_2 >= (-100)) && (pub_r000017_12_2 <= 100));
  __CPROVER_assume((pub_r000017_13_1 >= (-100)) && (pub_r000017_13_1 <= 100));
  __CPROVER_assume((pub_r000017_13_2 >= (-100)) && (pub_r000017_13_2 <= 100));
  __CPROVER_assume((pub_r000017_14_1 >= (-100)) && (pub_r000017_14_1 <= 100));
  __CPROVER_assume((pub_r000017_14_2 >= (-100)) && (pub_r000017_14_2 <= 100));
  __CPROVER_assume((pub_r000017_15_1 >= (-100)) && (pub_r000017_15_1 <= 100));
  __CPROVER_assume((pub_r000017_15_2 >= (-100)) && (pub_r000017_15_2 <= 100));
  __CPROVER_assume((pub_r000017_16_1 >= (-100)) && (pub_r000017_16_1 <= 100));
  __CPROVER_assume((pub_r000017_16_2 >= (-100)) && (pub_r000017_16_2 <= 100));
  __CPROVER_assume((pub_r000017_17_1 >= (-100)) && (pub_r000017_17_1 <= 100));
  __CPROVER_assume((pub_r000017_17_2 >= (-100)) && (pub_r000017_17_2 <= 100));
  __CPROVER_assume((pub_r000017_18_1 >= (-100)) && (pub_r000017_18_1 <= 100));
  __CPROVER_assume((pub_r000017_18_2 >= (-100)) && (pub_r000017_18_2 <= 100));
  __CPROVER_assume((pub_r000017_19_1 >= (-100)) && (pub_r000017_19_1 <= 100));
  __CPROVER_assume((pub_r000017_19_2 >= (-100)) && (pub_r000017_19_2 <= 100));
  __CPROVER_assume((sec_r000017_0_1 >= 0) && (sec_r000017_0_1 <= 255));
  __CPROVER_assume((sec_r000017_0_2 >= 0) && (sec_r000017_0_2 <= 255));
  __CPROVER_assume((sec_r000017_1_1 >= 0) && (sec_r000017_1_1 <= 255));
  __CPROVER_assume((sec_r000017_1_2 >= 0) && (sec_r000017_1_2 <= 255));
  __CPROVER_assume((sec_r000017_2_1 >= 0) && (sec_r000017_2_1 <= 255));
  __CPROVER_assume((sec_r000017_2_2 >= 0) && (sec_r000017_2_2 <= 255));
  __CPROVER_assume((sec_r000017_3_1 >= 0) && (sec_r000017_3_1 <= 255));
  __CPROVER_assume((sec_r000017_3_2 >= 0) && (sec_r000017_3_2 <= 255));
  __CPROVER_assume((sec_r000017_4_1 >= 0) && (sec_r000017_4_1 <= 255));
  __CPROVER_assume((sec_r000017_4_2 >= 0) && (sec_r000017_4_2 <= 255));
  __CPROVER_assume((sec_r000017_5_1 >= 0) && (sec_r000017_5_1 <= 255));
  __CPROVER_assume((sec_r000017_5_2 >= 0) && (sec_r000017_5_2 <= 255));
  __CPROVER_assume((sec_r000017_6_1 >= 0) && (sec_r000017_6_1 <= 255));
  __CPROVER_assume((sec_r000017_6_2 >= 0) && (sec_r000017_6_2 <= 255));
  __CPROVER_assume((sec_r000017_7_1 >= 0) && (sec_r000017_7_1 <= 255));
  __CPROVER_assume((sec_r000017_7_2 >= 0) && (sec_r000017_7_2 <= 255));
  __CPROVER_assume((sec_r000017_8_1 >= 0) && (sec_r000017_8_1 <= 255));
  __CPROVER_assume((sec_r000017_8_2 >= 0) && (sec_r000017_8_2 <= 255));
  __CPROVER_assume((sec_r000017_9_1 >= 0) && (sec_r000017_9_1 <= 255));
  __CPROVER_assume((sec_r000017_9_2 >= 0) && (sec_r000017_9_2 <= 255));
  __CPROVER_assume((sec_r000017_10_1 >= 0) && (sec_r000017_10_1 <= 255));
  __CPROVER_assume((sec_r000017_10_2 >= 0) && (sec_r000017_10_2 <= 255));
  __CPROVER_assume((sec_r000017_11_1 >= 0) && (sec_r000017_11_1 <= 255));
  __CPROVER_assume((sec_r000017_11_2 >= 0) && (sec_r000017_11_2 <= 255));
  __CPROVER_assume((sec_r000017_12_1 >= 0) && (sec_r000017_12_1 <= 255));
  __CPROVER_assume((sec_r000017_12_2 >= 0) && (sec_r000017_12_2 <= 255));
  __CPROVER_assume((sec_r000017_13_1 >= 0) && (sec_r000017_13_1 <= 255));
  __CPROVER_assume((sec_r000017_13_2 >= 0) && (sec_r000017_13_2 <= 255));
  __CPROVER_assume((sec_r000017_14_1 >= 0) && (sec_r000017_14_1 <= 255));
  __CPROVER_assume((sec_r000017_14_2 >= 0) && (sec_r000017_14_2 <= 255));
  __CPROVER_assume((sec_r000017_15_1 >= 0) && (sec_r000017_15_1 <= 255));
  __CPROVER_assume((sec_r000017_15_2 >= 0) && (sec_r000017_15_2 <= 255));
  __CPROVER_assume((sec_r000017_16_1 >= 0) && (sec_r000017_16_1 <= 255));
  __CPROVER_assume((sec_r000017_16_2 >= 0) && (sec_r000017_16_2 <= 255));
  __CPROVER_assume((sec_r000017_17_1 >= 0) && (sec_r000017_17_1 <= 255));
  __CPROVER_assume((sec_r000017_17_2 >= 0) && (sec_r000017_17_2 <= 255));
  __CPROVER_assume((sec_r000017_18_1 >= 0) && (sec_r000017_18_1 <= 255));
  __CPROVER_assume((sec_r000017_18_2 >= 0) && (sec_r000017_18_2 <= 255));
  __CPROVER_assume((sec_r000017_19_1 >= 0) && (sec_r000017_19_1 <= 255));
  __CPROVER_assume((sec_r000017_19_2 >= 0) && (sec_r000017_19_2 <= 255));
  __CPROVER_assume((sec_r000017_20_1 >= 0) && (sec_r000017_20_1 <= 255));
  __CPROVER_assume((sec_r000017_20_2 >= 0) && (sec_r000017_20_2 <= 255));
  struct Vector3D_R000017_1713_0 st_var_0_1 = {0};
  struct Vector3D_R000017_1713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000017_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000017_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000017_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000017_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000017_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000017_0_2 + 7) & 15;
  struct StreamBuffer_R000017_1713_1 st_var_1_1 = {0};
  struct StreamBuffer_R000017_1713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000017_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000017_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000017_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000017_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000017_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000017_0_2 + 9) & 15;
  union RegisterBank_R000017_1713_0 u_var_1;
  union RegisterBank_R000017_1713_0 u_var_2;
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
  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = ((st_var_1_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_1_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 36)
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
  if (stage_v_3_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 36)
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
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 49)
    {
      chk_sum_1 ^= stage_v_7_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_7_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 49)
    {
      chk_sum_2 ^= stage_v_7_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 11) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = ((st_var_1_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_1_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 44)
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
  if (stage_v_11_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 44)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 16) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = (st_var_0_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_0_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = ((st_var_1_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_1_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 51)
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
  if (stage_v_21_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 51)
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
  int stage_v_22_1 = (st_var_0_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_0_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = (st_var_1_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_1_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = ((st_var_0_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_0_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 34)
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
  if (stage_v_26_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 34)
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
  int stage_v_28_1 = ((st_var_0_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_0_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 43)
    {
      chk_sum_1 ^= stage_v_28_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_28_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 43)
    {
      chk_sum_2 ^= stage_v_28_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_29_1 = (st_var_1_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_1_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 31) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 33) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
  int stage_v_33_1 = table_1[1];
  int stage_v_33_2 = table_2[1];
  table_1[1] = (table_1[2] + 67) & 63;
  table_2[1] = (table_2[2] + 67) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

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
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 33)
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
  if (stage_v_37_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 33)
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
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = table_1[3];
  int stage_v_39_2 = table_2[3];
  table_1[3] = (table_1[0] + 79) & 63;
  table_2[3] = (table_2[0] + 79) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
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
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 54)
    {
      chk_sum_1 ^= stage_v_48_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_48_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 54)
    {
      chk_sum_2 ^= stage_v_48_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (st_var_0_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_0_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = (st_var_1_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_1_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  int stage_v_52_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_52_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_53_1 = ((st_var_1_1.buffer[2] * 2) + 166) & 63;
  int stage_v_53_2 = ((st_var_1_2.buffer[2] * 2) + 166) & 63;
  if (stage_v_53_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_53_1) - 5) & 255;
    if (stage_v_53_1 > 34)
    {
      chk_sum_1 ^= stage_v_53_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_53_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_53_2) - 5) & 255;
    if (stage_v_53_2 > 34)
    {
      chk_sum_2 ^= stage_v_53_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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
  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 58) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  int stage_v_58_1 = ((st_var_0_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_0_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 53)
    {
      chk_sum_1 ^= stage_v_58_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_58_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 53)
    {
      chk_sum_2 ^= stage_v_58_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
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
  int stage_v_61_1 = table_1[1];
  int stage_v_61_2 = table_2[1];
  table_1[1] = (table_1[2] + 123) & 63;
  table_2[1] = (table_2[2] + 123) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (st_var_0_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_0_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
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
  int stage_v_66_1 = table_1[2];
  int stage_v_66_2 = table_2[2];
  table_1[2] = (table_1[3] + 133) & 63;
  table_2[2] = (table_2[3] + 133) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
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

  int stage_v_68_1 = (st_var_0_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_0_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = table_1[1];
  int stage_v_69_2 = table_2[1];
  table_1[1] = (table_1[2] + 139) & 63;
  table_2[1] = (table_2[2] + 139) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000017_12_1 & 1) != 0)
  {
    if ((sec_r000017_10_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000017_11_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000017_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000017_11_1 + 7) & 127;
  }
  if ((sec_r000017_12_2 & 1) != 0)
  {
    if ((sec_r000017_10_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000017_11_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000017_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000017_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000017_17_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000017_10_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000017_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000017_10_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000017_17_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000017_10_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000017_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000017_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000017_12_1 & 1) != 0)
  {
    if ((sec_r000017_7_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000017_15_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000017_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000017_15_1 + 7) & 127;
  }
  if ((sec_r000017_12_2 & 1) != 0)
  {
    if ((sec_r000017_7_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000017_15_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000017_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000017_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000017_8_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000017_5_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000017_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000017_5_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000017_8_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000017_5_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000017_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000017_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000017_12_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000017_11_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000017_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000017_11_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000017_12_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000017_11_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000017_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000017_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000017_19_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000017_14_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000017_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000017_14_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000017_19_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000017_14_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000017_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000017_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000017_13_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000017_6_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000017_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000017_6_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000017_13_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000017_6_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000017_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000017_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000017_20_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000017_16_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000017_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000017_16_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000017_20_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000017_16_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000017_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000017_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000017_11_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000017_15_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000017_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000017_15_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000017_11_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000017_15_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000017_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000017_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000017_3_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000017_10_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000017_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000017_10_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000017_3_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000017_10_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000017_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000017_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000017_8_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000017_2_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000017_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000017_2_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000017_8_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000017_2_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000017_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000017_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000017_6_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000017_15_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000017_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000017_15_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000017_6_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000017_15_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000017_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000017_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000017_7_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000017_13_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000017_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000017_13_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000017_7_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000017_13_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000017_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000017_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000017_1_1 & 1) != 0)
  {
    if ((sec_r000017_11_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000017_6_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000017_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000017_6_1 + 7) & 127;
  }
  if ((sec_r000017_1_2 & 1) != 0)
  {
    if ((sec_r000017_11_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000017_6_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000017_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000017_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000017_13_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000017_10_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000017_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000017_10_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000017_13_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000017_10_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000017_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000017_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000017_6_1 & 1) != 0)
  {
    if ((sec_r000017_3_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000017_5_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000017_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000017_5_1 + 7) & 127;
  }
  if ((sec_r000017_6_2 & 1) != 0)
  {
    if ((sec_r000017_3_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000017_5_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000017_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000017_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000017_8_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000017_15_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000017_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000017_15_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000017_8_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000017_15_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000017_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000017_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000017_14_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000017_5_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000017_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000017_5_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000017_14_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000017_5_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000017_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000017_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000017_13_1 & 1) != 0)
  {
    if ((sec_r000017_15_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000017_9_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000017_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000017_9_1 + 7) & 127;
  }
  if ((sec_r000017_13_2 & 1) != 0)
  {
    if ((sec_r000017_15_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000017_9_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000017_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000017_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000017_10_1 & 1) != 0)
  {
    if ((sec_r000017_6_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000017_2_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000017_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000017_2_1 + 7) & 127;
  }
  if ((sec_r000017_10_2 & 1) != 0)
  {
    if ((sec_r000017_6_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000017_2_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000017_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000017_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000017_1_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000017_9_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000017_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000017_9_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000017_1_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000017_9_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000017_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000017_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000017_10_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000017_14_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000017_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000017_14_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000017_10_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000017_14_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000017_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000017_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000017_12_1 & 1) != 0)
  {
    if ((sec_r000017_10_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000017_12_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000017_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000017_12_1 + 7) & 127;
  }
  if ((sec_r000017_12_2 & 1) != 0)
  {
    if ((sec_r000017_10_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000017_12_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000017_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000017_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000017_5_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000017_12_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000017_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000017_12_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000017_5_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000017_12_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000017_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000017_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000017_4_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000017_7_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000017_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000017_7_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000017_4_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000017_7_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000017_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000017_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000017_13_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000017_1_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000017_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000017_1_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000017_13_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000017_1_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000017_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000017_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000017_4_1 & 1) != 0)
  {
    if ((sec_r000017_15_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000017_17_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000017_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000017_17_1 + 7) & 127;
  }
  if ((sec_r000017_4_2 & 1) != 0)
  {
    if ((sec_r000017_15_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000017_17_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000017_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000017_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000017_1_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000017_3_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000017_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000017_3_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000017_1_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000017_3_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000017_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000017_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000017_20_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000017_9_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000017_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000017_9_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000017_20_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000017_9_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000017_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000017_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000017_4_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000017_16_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000017_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000017_16_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000017_4_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000017_16_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000017_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000017_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000017_1_1 & 1) != 0)
  {
    if ((sec_r000017_14_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000017_18_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000017_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000017_18_1 + 7) & 127;
  }
  if ((sec_r000017_1_2 & 1) != 0)
  {
    if ((sec_r000017_14_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000017_18_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000017_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000017_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000017_0_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000017_8_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000017_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000017_8_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000017_0_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000017_8_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000017_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000017_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000017_3_1 & 1) != 0)
  {
    if ((sec_r000017_18_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000017_2_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000017_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000017_2_1 + 7) & 127;
  }
  if ((sec_r000017_3_2 & 1) != 0)
  {
    if ((sec_r000017_18_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000017_2_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000017_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000017_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000017_13_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000017_9_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000017_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000017_9_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000017_13_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000017_9_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000017_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000017_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000017_3_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000017_3_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000017_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000017_3_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000017_3_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000017_3_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000017_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000017_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000017_13_1 & 1) != 0)
  {
    if ((sec_r000017_12_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000017_17_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000017_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000017_17_1 + 7) & 127;
  }
  if ((sec_r000017_13_2 & 1) != 0)
  {
    if ((sec_r000017_12_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000017_17_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000017_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000017_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000017_11_1 & 1) != 0)
  {
    if ((sec_r000017_19_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000017_0_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000017_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000017_0_1 + 7) & 127;
  }
  if ((sec_r000017_11_2 & 1) != 0)
  {
    if ((sec_r000017_19_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000017_0_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000017_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000017_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000017_7_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000017_10_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000017_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000017_10_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000017_7_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000017_10_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000017_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000017_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000017_7_1 & 1) != 0)
  {
    if ((sec_r000017_10_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000017_13_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000017_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000017_13_1 + 7) & 127;
  }
  if ((sec_r000017_7_2 & 1) != 0)
  {
    if ((sec_r000017_10_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000017_13_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000017_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000017_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000017_7_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000017_14_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000017_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000017_14_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000017_7_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000017_14_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000017_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000017_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000017_2_1 & 1) != 0)
  {
    if ((sec_r000017_20_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000017_3_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000017_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000017_3_1 + 7) & 127;
  }
  if ((sec_r000017_2_2 & 1) != 0)
  {
    if ((sec_r000017_20_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000017_3_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000017_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000017_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000017_7_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000017_8_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000017_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000017_8_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000017_7_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000017_8_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000017_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000017_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r000017_7_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000017_9_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000017_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000017_9_1 + 7) & 127;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((sec_r000017_7_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000017_9_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000017_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000017_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000017_8_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000017_4_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000017_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000017_4_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000017_8_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000017_4_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000017_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000017_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000017_5_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000017_9_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000017_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000017_9_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000017_5_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000017_9_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000017_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000017_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000017_15_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000017_18_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000017_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000017_18_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000017_15_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000017_18_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000017_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000017_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000017_6_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000017_18_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000017_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000017_18_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000017_6_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000017_18_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000017_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000017_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000017_16_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000017_15_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000017_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000017_15_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000017_16_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000017_15_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000017_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000017_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000017_16_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000017_3_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000017_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000017_3_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000017_16_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000017_3_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000017_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000017_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000017_12_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000017_5_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000017_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000017_5_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000017_12_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000017_5_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000017_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000017_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000017_10_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000017_7_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000017_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000017_7_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000017_10_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000017_7_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000017_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000017_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000017_14_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000017_2_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000017_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000017_2_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000017_14_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000017_2_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000017_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000017_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000017_19_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000017_12_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000017_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000017_12_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000017_19_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000017_12_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000017_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000017_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000017_19_1 & 1) != 0)
  {
    if ((sec_r000017_17_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000017_17_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000017_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000017_17_1 + 7) & 127;
  }
  if ((sec_r000017_19_2 & 1) != 0)
  {
    if ((sec_r000017_17_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000017_17_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000017_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000017_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000017_2_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000017_16_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000017_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000017_16_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000017_2_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000017_16_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000017_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000017_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000017_0_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000017_14_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000017_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000017_14_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000017_0_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000017_14_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000017_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000017_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000017_13_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000017_17_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000017_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000017_17_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000017_13_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000017_17_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000017_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000017_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000017_11_1 & 1) != 0)
  {
    if ((sec_r000017_15_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000017_18_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000017_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000017_18_1 + 7) & 127;
  }
  if ((sec_r000017_11_2 & 1) != 0)
  {
    if ((sec_r000017_15_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000017_18_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000017_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000017_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000017_3_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000017_17_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000017_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000017_17_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000017_3_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000017_17_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000017_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000017_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000017_17_1 & 1) != 0)
  {
    if ((sec_r000017_5_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000017_3_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000017_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000017_3_1 + 7) & 127;
  }
  if ((sec_r000017_17_2 & 1) != 0)
  {
    if ((sec_r000017_5_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000017_3_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000017_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000017_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000017_7_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000017_3_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000017_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000017_3_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000017_7_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000017_3_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000017_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000017_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000017_10_1 & 1) != 0)
  {
    if ((sec_r000017_7_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000017_5_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000017_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000017_5_1 + 7) & 127;
  }
  if ((sec_r000017_10_2 & 1) != 0)
  {
    if ((sec_r000017_7_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000017_5_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000017_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000017_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000017_14_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000017_1_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000017_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000017_1_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000017_14_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000017_1_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000017_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000017_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000017_19_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000017_2_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000017_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000017_2_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000017_19_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000017_2_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000017_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000017_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000017_13_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000017_7_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000017_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000017_7_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000017_13_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000017_7_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000017_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000017_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000017_1_1 & 1) != 0)
  {
    if ((sec_r000017_9_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000017_16_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000017_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000017_16_1 + 7) & 127;
  }
  if ((sec_r000017_1_2 & 1) != 0)
  {
    if ((sec_r000017_9_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000017_16_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000017_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000017_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000017_14_1 & 1) != 0)
  {
    if ((sec_r000017_7_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000017_5_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000017_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000017_5_1 + 7) & 127;
  }
  if ((sec_r000017_14_2 & 1) != 0)
  {
    if ((sec_r000017_7_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000017_5_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000017_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000017_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((sec_r000017_2_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000017_8_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000017_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000017_8_1 + 7) & 127;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((sec_r000017_2_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000017_8_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000017_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000017_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000017_20_1 & 1) != 0)
  {
    if ((sec_r000017_20_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000017_16_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000017_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000017_16_1 + 7) & 127;
  }
  if ((sec_r000017_20_2 & 1) != 0)
  {
    if ((sec_r000017_20_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000017_16_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000017_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000017_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000017_16_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000017_7_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000017_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000017_7_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000017_16_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000017_7_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000017_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000017_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000017_13_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000017_11_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000017_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000017_11_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000017_13_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000017_11_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000017_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000017_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000017_14_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000017_8_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000017_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000017_8_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000017_14_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000017_8_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000017_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000017_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((sec_r000017_18_1 & 1) != 0)
  {
    if ((sec_r000017_12_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000017_7_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000017_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000017_7_1 + 7) & 127;
  }
  if ((sec_r000017_18_2 & 1) != 0)
  {
    if ((sec_r000017_12_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000017_7_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000017_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000017_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000017_13_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000017_7_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000017_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000017_7_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000017_13_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000017_7_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000017_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000017_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000017_5_1 & 1) != 0)
  {
    if ((sec_r000017_8_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000017_14_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000017_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000017_14_1 + 7) & 127;
  }
  if ((sec_r000017_5_2 & 1) != 0)
  {
    if ((sec_r000017_8_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000017_14_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000017_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000017_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000017_13_1 & 1) != 0)
  {
    if ((sec_r000017_5_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000017_14_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000017_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000017_14_1 + 7) & 127;
  }
  if ((sec_r000017_13_2 & 1) != 0)
  {
    if ((sec_r000017_5_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000017_14_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000017_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000017_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000017_7_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000017_6_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000017_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000017_6_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000017_7_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000017_6_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000017_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000017_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000017_10_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000017_19_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000017_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000017_19_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000017_10_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000017_19_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000017_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000017_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000017_5_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000017_2_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000017_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000017_2_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000017_5_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000017_2_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000017_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000017_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((sec_r000017_5_1 & 1) != 0)
  {
    if ((sec_r000017_13_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000017_18_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000017_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000017_18_1 + 7) & 127;
  }
  if ((sec_r000017_5_2 & 1) != 0)
  {
    if ((sec_r000017_13_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000017_18_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000017_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000017_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000017_16_1 & 1) != 0)
  {
    if ((sec_r000017_12_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000017_14_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000017_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000017_14_1 + 7) & 127;
  }
  if ((sec_r000017_16_2 & 1) != 0)
  {
    if ((sec_r000017_12_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000017_14_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000017_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000017_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000017_9_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000017_12_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000017_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000017_12_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000017_9_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000017_12_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000017_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000017_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000017_1_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000017_10_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000017_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000017_10_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000017_1_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000017_10_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000017_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000017_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000017_11_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000017_1_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000017_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000017_1_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000017_11_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000017_1_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000017_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000017_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((sec_r000017_9_1 & 1) != 0)
  {
    if ((sec_r000017_14_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000017_6_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000017_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000017_6_1 + 7) & 127;
  }
  if ((sec_r000017_9_2 & 1) != 0)
  {
    if ((sec_r000017_14_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000017_6_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000017_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000017_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((sec_r000017_18_1 & 1) != 0)
  {
    if ((sec_r000017_19_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000017_8_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000017_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000017_8_1 + 7) & 127;
  }
  if ((sec_r000017_18_2 & 1) != 0)
  {
    if ((sec_r000017_19_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000017_8_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000017_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000017_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((sec_r000017_8_1 & 1) != 0)
  {
    if ((sec_r000017_6_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000017_10_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000017_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000017_10_1 + 7) & 127;
  }
  if ((sec_r000017_8_2 & 1) != 0)
  {
    if ((sec_r000017_6_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000017_10_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000017_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000017_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((sec_r000017_16_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000017_18_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000017_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000017_18_1 + 7) & 127;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((sec_r000017_16_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000017_18_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000017_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000017_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000017_7_1 == pub_r000017_7_2);
  __CPROVER_assume(sec_r000017_15_1 != sec_r000017_15_2);
  __CPROVER_assume(pub_r000017_2_1 == pub_r000017_2_2);
  __CPROVER_assume(sec_r000017_2_1 != sec_r000017_2_2);
  __CPROVER_assume(pub_r000017_3_1 == pub_r000017_3_2);
  __CPROVER_assume(pub_r000017_10_1 == pub_r000017_10_2);
  __CPROVER_assume(sec_r000017_4_1 != sec_r000017_4_2);
  __CPROVER_assume(pub_r000017_6_1 == pub_r000017_6_2);
  __CPROVER_assume(pub_r000017_14_1 == pub_r000017_14_2);
  __CPROVER_assume(sec_r000017_3_1 != sec_r000017_3_2);
  __CPROVER_assume(pub_r000017_16_1 == pub_r000017_16_2);
  __CPROVER_assume(sec_r000017_0_1 != sec_r000017_0_2);
  __CPROVER_assume(sec_r000017_1_1 != sec_r000017_1_2);
  __CPROVER_assume(sec_r000017_10_1 != sec_r000017_10_2);
  __CPROVER_assume(sec_r000017_12_1 != sec_r000017_12_2);
  __CPROVER_assume(sec_r000017_19_1 != sec_r000017_19_2);
  __CPROVER_assume(sec_r000017_16_1 != sec_r000017_16_2);
  __CPROVER_assume(sec_r000017_18_1 != sec_r000017_18_2);
  __CPROVER_assume(pub_r000017_13_1 == pub_r000017_13_2);
  __CPROVER_assume(pub_r000017_15_1 == pub_r000017_15_2);
  __CPROVER_assume(pub_r000017_1_1 == pub_r000017_1_2);
  __CPROVER_assume(pub_r000017_4_1 == pub_r000017_4_2);
  __CPROVER_assume(sec_r000017_8_1 != sec_r000017_8_2);
  __CPROVER_assume(sec_r000017_17_1 != sec_r000017_17_2);
  __CPROVER_assume(pub_r000017_8_1 == pub_r000017_8_2);
  __CPROVER_assume(sec_r000017_6_1 != sec_r000017_6_2);
  __CPROVER_assume(pub_r000017_12_1 == pub_r000017_12_2);
  __CPROVER_assume(pub_r000017_9_1 == pub_r000017_9_2);
  __CPROVER_assume(sec_r000017_11_1 != sec_r000017_11_2);
  __CPROVER_assume(pub_r000017_11_1 == pub_r000017_11_2);
  __CPROVER_assume(sec_r000017_9_1 != sec_r000017_9_2);
  __CPROVER_assume(pub_r000017_19_1 == pub_r000017_19_2);
  __CPROVER_assume(pub_r000017_0_1 == pub_r000017_0_2);
  __CPROVER_assume(pub_r000017_5_1 == pub_r000017_5_2);
  __CPROVER_assume(sec_r000017_14_1 != sec_r000017_14_2);
  __CPROVER_assume(sec_r000017_20_1 != sec_r000017_20_2);
  __CPROVER_assume(pub_r000017_18_1 == pub_r000017_18_2);
  __CPROVER_assume(pub_r000017_17_1 == pub_r000017_17_2);
  __CPROVER_assume(sec_r000017_5_1 != sec_r000017_5_2);
  __CPROVER_assume(sec_r000017_7_1 != sec_r000017_7_2);
  __CPROVER_assume(sec_r000017_13_1 != sec_r000017_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.tail == st_var_1_2.tail);
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
}


