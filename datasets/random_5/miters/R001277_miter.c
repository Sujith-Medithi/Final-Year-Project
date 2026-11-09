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
struct MatrixBlock_R001277_7713_0
{
  int stride;
  short scale;
  short density;
  short trace;
  unsigned char determinant;
  int buffer[3];
};
struct StreamBuffer_R001277_7713_1
{
  unsigned char checksum;
  int tail;
  short watermark;
  unsigned char head;
  int buffer[3];
};
union ColorPixel_R001277_7713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001277_7713_1
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
void fn_R001277_7713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st_1 = {0};
  struct StreamBuffer_R001277_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int index_reg_21_1 = 0;
  int index_reg_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_21_1 = ((index_reg_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_21_2 = ((index_reg_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_21_1) & 127;
    acc_2 = (acc_2 + index_reg_21_2) & 127;
  }

  int offset_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_41_1)
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

  switch (offset_41_2)
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

  int stride_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_70_1 > 11)
  {
    acc_1 = ((acc_1 + (stride_70_1 * 2)) + 5) & 127;
    aux_1 ^= stride_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_70_2 > 11)
  {
    acc_2 = ((acc_2 + (stride_70_2 * 2)) + 5) & 127;
    aux_2 ^= stride_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_11_1 = local_arr_1[aux_1 % 3];
  int phase_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_21_1 == index_reg_21_2);
  assert(offset_41_1 == offset_41_2);
  assert(stride_70_1 == stride_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_11_1 == phase_11_2);
}

int fn_R001277_7713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int index_reg_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_21 = ((index_reg_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_21) & 127;
  }

  int offset_41 = (aux + st.buffer[1]) & 3;
  switch (offset_41)
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

  int stride_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_70 > 11)
  {
    acc = ((acc + (stride_70 * 2)) + 5) & 127;
    aux ^= stride_70 & 15;
  }
  else
  {
    acc = ((acc - stride_70) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int phase_11 = local_arr[aux % 3];
  acc = (acc + (phase_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001277_7713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_77_1 = local_arr_1[aux_1 % 3];
  int pivot_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_77_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_77_1 == pivot_77_2);
}

int fn_R001277_7713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int pivot_77 = local_arr[aux % 3];
  acc = (acc + (pivot_77 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001277_7713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_41_1 = local_arr_1[aux_1 % 3];
  int offset_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_41_2 * 2)) & 127;
  int tally_34_1 = 0;
  int tally_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_34_1 = ((tally_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_34_2 = ((tally_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_34_1) & 127;
    acc_2 = (acc_2 + tally_34_2) & 127;
  }

  int margin_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_33_1)
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

  switch (margin_33_2)
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

  int index_reg_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_98_1 > 29)
  {
    acc_1 = ((acc_1 + (index_reg_98_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_98_2 > 29)
  {
    acc_2 = ((acc_2 + (index_reg_98_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_41_1 == offset_41_2);
  assert(tally_34_1 == tally_34_2);
  assert(margin_33_1 == margin_33_2);
  assert(index_reg_98_1 == index_reg_98_2);
}

int fn_R001277_7713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int offset_41 = local_arr[aux % 3];
  acc = (acc + (offset_41 * 2)) & 127;
  int tally_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_34 = ((tally_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_34) & 127;
  }

  int margin_33 = (aux + st.buffer[1]) & 3;
  switch (margin_33)
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

  int index_reg_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_98 > 29)
  {
    acc = ((acc + (index_reg_98 * 2)) + 5) & 127;
    aux ^= index_reg_98 & 15;
  }
  else
  {
    acc = ((acc - index_reg_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001277_7713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st_1 = {0};
  struct StreamBuffer_R001277_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_28_1)
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

  switch (weight_28_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_28_1 == weight_28_2);
}

int fn_R001277_7713_3(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_28 = (aux + st.buffer[1]) & 3;
  switch (weight_28)
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

void fn_R001277_7713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_48_1 = 0;
  int factor_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_48_1 = ((factor_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_48_2 = ((factor_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_48_1) & 127;
    acc_2 = (acc_2 + factor_48_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_79_1 = local_arr_1[aux_1 % 3];
  int coefficient_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_79_2 * 2)) & 127;
  int stride_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_59_1)
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

  switch (stride_59_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_48_1 == factor_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_79_1 == coefficient_79_2);
  assert(stride_59_1 == stride_59_2);
}

int fn_R001277_7713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_48 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_48 = ((factor_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_48) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int coefficient_79 = local_arr[aux % 3];
  acc = (acc + (coefficient_79 * 2)) & 127;
  int stride_59 = (aux + st.buffer[1]) & 3;
  switch (stride_59)
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

void fn_R001277_7713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st_1 = {0};
  struct StreamBuffer_R001277_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_33_1 = local_arr_1[aux_1 % 3];
  int margin_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_33_2 * 2)) & 127;
  int index_reg_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_52_1 > 12)
  {
    acc_1 = ((acc_1 + (index_reg_52_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_52_2 > 12)
  {
    acc_2 = ((acc_2 + (index_reg_52_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_52_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_33_1 == margin_33_2);
  assert(index_reg_52_1 == index_reg_52_2);
}

int fn_R001277_7713_5(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_33 = local_arr[aux % 3];
  acc = (acc + (margin_33 * 2)) & 127;
  int index_reg_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_52 > 12)
  {
    acc = ((acc + (index_reg_52 * 2)) + 5) & 127;
    aux ^= index_reg_52 & 15;
  }
  else
  {
    acc = ((acc - index_reg_52) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001277_7713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int margin_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_70_1 > 39)
  {
    acc_1 = ((acc_1 + (margin_70_1 * 2)) + 5) & 127;
    aux_1 ^= margin_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_70_2 > 39)
  {
    acc_2 = ((acc_2 + (margin_70_2 * 2)) + 5) & 127;
    aux_2 ^= margin_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_93_1 = local_arr_1[aux_1 % 3];
  int mask_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_93_2 * 2)) & 127;
  int scale_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_21_1)
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

  switch (scale_21_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_70_1 == margin_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_93_1 == mask_93_2);
  assert(scale_21_1 == scale_21_2);
}

int fn_R001277_7713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int margin_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_70 > 39)
  {
    acc = ((acc + (margin_70 * 2)) + 5) & 127;
    aux ^= margin_70 & 15;
  }
  else
  {
    acc = ((acc - margin_70) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_93 = local_arr[aux % 3];
  acc = (acc + (mask_93 * 2)) & 127;
  int scale_21 = (aux + st.buffer[1]) & 3;
  switch (scale_21)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001277_7713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st_1 = {0};
  struct StreamBuffer_R001277_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int parity_26_1 = 0;
  int parity_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_26_1 = ((parity_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_26_2 = ((parity_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_26_1) & 127;
    acc_2 = (acc_2 + parity_26_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_26_1 = local_arr_1[aux_1 % 3];
  int metric_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_26_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_66_1)
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

  switch (accumulator_66_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_26_1 == parity_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_26_1 == metric_26_2);
  assert(accumulator_66_1 == accumulator_66_2);
}

int fn_R001277_7713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int parity_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_26 = ((parity_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_26) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int metric_26 = local_arr[aux % 3];
  acc = (acc + (metric_26 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_66 = (aux + st.buffer[1]) & 3;
  switch (accumulator_66)
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

void fn_R001277_7713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int coefficient_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_32_1) & 63;
  aux_2 = (aux_2 + coefficient_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_79_1)
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

  switch (weight_79_2)
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

  int weight_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_41_1 > 12)
  {
    acc_1 = ((acc_1 + (weight_41_1 * 2)) + 5) & 127;
    aux_1 ^= weight_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_41_2 > 12)
  {
    acc_2 = ((acc_2 + (weight_41_2 * 2)) + 5) & 127;
    aux_2 ^= weight_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_41_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_32_1 == coefficient_32_2);
  assert(weight_79_1 == weight_79_2);
  assert(weight_41_1 == weight_41_2);
}

int fn_R001277_7713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int coefficient_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_32) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_79 = (aux + st.buffer[1]) & 3;
  switch (weight_79)
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

  int weight_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_41 > 12)
  {
    acc = ((acc + (weight_41 * 2)) + 5) & 127;
    aux ^= weight_41 & 15;
  }
  else
  {
    acc = ((acc - weight_41) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001277_7713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st_1 = {0};
  struct StreamBuffer_R001277_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int weight_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_34_1) & 63;
  aux_2 = (aux_2 + weight_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_90_1 = 0;
  int checksum_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_90_1 = ((checksum_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_90_2 = ((checksum_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_90_1) & 127;
    acc_2 = (acc_2 + checksum_90_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_34_1 == weight_34_2);
  assert(checksum_90_1 == checksum_90_2);
}

int fn_R001277_7713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int weight_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_34) & 63;
  acc ^= aux;
  int checksum_90 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_90 = ((checksum_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_90) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001277_7713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int tracker_71_1 = 0;
  int tracker_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_71_1 = ((tracker_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_71_2 = ((tracker_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_71_1) & 127;
    acc_2 = (acc_2 + tracker_71_2) & 127;
  }

  int cursor_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_86_1) & 63;
  aux_2 = (aux_2 + cursor_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_46_1 = local_arr_1[aux_1 % 3];
  int phase_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_46_2 * 2)) & 127;
  int sample_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_63_1)
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

  switch (sample_63_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_71_1 == tracker_71_2);
  assert(cursor_86_1 == cursor_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_46_1 == phase_46_2);
  assert(sample_63_1 == sample_63_2);
}

int fn_R001277_7713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int tracker_71 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_71 = ((tracker_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_71) & 127;
  }

  int cursor_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_86) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_46 = local_arr[aux % 3];
  acc = (acc + (phase_46 * 2)) & 127;
  int sample_63 = (aux + st.buffer[1]) & 3;
  switch (sample_63)
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

void fn_R001277_7713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st_1 = {0};
  struct StreamBuffer_R001277_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_13_1 = local_arr_1[aux_1 % 3];
  int anchor_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_13_2 * 2)) & 127;
  int quotient_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_38_1) & 63;
  aux_2 = (aux_2 + quotient_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_13_1 == anchor_13_2);
  assert(quotient_38_1 == quotient_38_2);
}

int fn_R001277_7713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int anchor_13 = local_arr[aux % 3];
  acc = (acc + (anchor_13 * 2)) & 127;
  int quotient_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001277_7713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int metric_81_1 = 0;
  int metric_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_81_1 = ((metric_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_81_2 = ((metric_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_81_1) & 127;
    acc_2 = (acc_2 + metric_81_2) & 127;
  }

  int stride_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_68_1 > 36)
  {
    acc_1 = ((acc_1 + (stride_68_1 * 2)) + 5) & 127;
    aux_1 ^= stride_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_68_2 > 36)
  {
    acc_2 = ((acc_2 + (stride_68_2 * 2)) + 5) & 127;
    aux_2 ^= stride_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_81_1 == metric_81_2);
  assert(stride_68_1 == stride_68_2);
}

int fn_R001277_7713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int metric_81 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_81 = ((metric_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_81) & 127;
  }

  int stride_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_68 > 36)
  {
    acc = ((acc + (stride_68 * 2)) + 5) & 127;
    aux ^= stride_68 & 15;
  }
  else
  {
    acc = ((acc - stride_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001277_7713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int vector_18_1 = 0;
  int vector_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_18_1 = ((vector_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_18_2 = ((vector_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_18_1) & 127;
    acc_2 = (acc_2 + vector_18_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_18_1 == vector_18_2);
}

int fn_R001277_7713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int vector_18 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_18 = ((vector_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_18) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001277_7713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int tally_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_47_1)
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

  switch (tally_47_2)
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

  int threshold_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_20_1) & 63;
  aux_2 = (aux_2 + threshold_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_65_1 = 0;
  int stride_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_65_1 = ((stride_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_65_2 = ((stride_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_65_1) & 127;
    acc_2 = (acc_2 + stride_65_2) & 127;
  }

  int threshold_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_84_1 > 20)
  {
    acc_1 = ((acc_1 + (threshold_84_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_84_2 > 20)
  {
    acc_2 = ((acc_2 + (threshold_84_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_47_1 == tally_47_2);
  assert(threshold_20_1 == threshold_20_2);
  assert(stride_65_1 == stride_65_2);
  assert(threshold_84_1 == threshold_84_2);
}

int fn_R001277_7713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int tally_47 = (aux + st.buffer[1]) & 3;
  switch (tally_47)
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

  int threshold_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_20) & 63;
  acc ^= aux;
  int stride_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_65 = ((stride_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_65) & 127;
  }

  int threshold_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_84 > 20)
  {
    acc = ((acc + (threshold_84 * 2)) + 5) & 127;
    aux ^= threshold_84 & 15;
  }
  else
  {
    acc = ((acc - threshold_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001277_7713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_81_1 = local_arr_1[aux_1 % 3];
  int window_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_81_2 * 2)) & 127;
  int vector_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_96_1)
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

  switch (vector_96_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_81_1 == window_81_2);
  assert(vector_96_1 == vector_96_2);
}

int fn_R001277_7713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int window_81 = local_arr[aux % 3];
  acc = (acc + (window_81 * 2)) & 127;
  int vector_96 = (aux + st.buffer[1]) & 3;
  switch (vector_96)
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

void fn_R001277_7713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st_1 = {0};
  struct StreamBuffer_R001277_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int window_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_48_1 > 35)
  {
    acc_1 = ((acc_1 + (window_48_1 * 2)) + 5) & 127;
    aux_1 ^= window_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_48_2 > 35)
  {
    acc_2 = ((acc_2 + (window_48_2 * 2)) + 5) & 127;
    aux_2 ^= window_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_67_1)
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

  switch (threshold_67_2)
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

  int coefficient_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_18_1) & 63;
  aux_2 = (aux_2 + coefficient_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_52_1 = 0;
  int scale_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_52_1 = ((scale_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_52_2 = ((scale_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_52_1) & 127;
    acc_2 = (acc_2 + scale_52_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_48_1 == window_48_2);
  assert(threshold_67_1 == threshold_67_2);
  assert(coefficient_18_1 == coefficient_18_2);
  assert(scale_52_1 == scale_52_2);
}

int fn_R001277_7713_16(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int window_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_48 > 35)
  {
    acc = ((acc + (window_48 * 2)) + 5) & 127;
    aux ^= window_48 & 15;
  }
  else
  {
    acc = ((acc - window_48) + 11) & 127;
    aux += 3;
  }
  int threshold_67 = (aux + st.buffer[1]) & 3;
  switch (threshold_67)
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

  int coefficient_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_18) & 63;
  acc ^= aux;
  int scale_52 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_52 = ((scale_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_52) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001277_7713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int threshold_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_78_1)
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

  switch (threshold_78_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_78_1 == threshold_78_2);
}

int fn_R001277_7713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int threshold_78 = (aux + st.buffer[1]) & 3;
  switch (threshold_78)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001277_7713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int accumulator_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_97_1)
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

  switch (accumulator_97_2)
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

  int margin_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_48_1 > 34)
  {
    acc_1 = ((acc_1 + (margin_48_1 * 2)) + 5) & 127;
    aux_1 ^= margin_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_48_2 > 34)
  {
    acc_2 = ((acc_2 + (margin_48_2 * 2)) + 5) & 127;
    aux_2 ^= margin_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_57_1 = local_arr_1[aux_1 % 3];
  int window_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_57_2 * 2)) & 127;
  int stride_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_21_1) & 63;
  aux_2 = (aux_2 + stride_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_97_1 == accumulator_97_2);
  assert(margin_48_1 == margin_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_57_1 == window_57_2);
  assert(stride_21_1 == stride_21_2);
}

int fn_R001277_7713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int accumulator_97 = (aux + st.buffer[1]) & 3;
  switch (accumulator_97)
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

  int margin_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_48 > 34)
  {
    acc = ((acc + (margin_48 * 2)) + 5) & 127;
    aux ^= margin_48 & 15;
  }
  else
  {
    acc = ((acc - margin_48) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_57 = local_arr[aux % 3];
  acc = (acc + (window_57 * 2)) & 127;
  int stride_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001277_7713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st_1 = {0};
  struct StreamBuffer_R001277_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_23_1 = 0;
  int weight_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_23_1 = ((weight_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_23_2 = ((weight_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_23_1) & 127;
    acc_2 = (acc_2 + weight_23_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_23_1 == weight_23_2);
}

int fn_R001277_7713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_23 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_23 = ((weight_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_23) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001277_7713_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_70_1 = local_arr_1[aux_1 % 3];
  int pivot_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_70_2 * 2)) & 127;
  int checksum_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_74_1)
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

  switch (checksum_74_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_21_1 = 0;
  int stride_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_21_1 = ((stride_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_21_2 = ((stride_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_21_1) & 127;
    acc_2 = (acc_2 + stride_21_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_70_1 == pivot_70_2);
  assert(checksum_74_1 == checksum_74_2);
  assert(stride_21_1 == stride_21_2);
}

int fn_R001277_7713_20(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001277_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int pivot_70 = local_arr[aux % 3];
  acc = (acc + (pivot_70 * 2)) & 127;
  int checksum_74 = (aux + st.buffer[1]) & 3;
  switch (checksum_74)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_21 = ((stride_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_21) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001277_7713_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st_1 = {0};
  struct StreamBuffer_R001277_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int quantum_57_1 = 0;
  int quantum_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_57_1 = ((quantum_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_57_2 = ((quantum_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_57_1) & 127;
    acc_2 = (acc_2 + quantum_57_2) & 127;
  }

  int checksum_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_72_1)
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

  switch (checksum_72_2)
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
  int metric_32_1 = local_arr_1[aux_1 % 3];
  int metric_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_32_2 * 2)) & 127;
  int mask_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_25_1 > 24)
  {
    acc_1 = ((acc_1 + (mask_25_1 * 2)) + 5) & 127;
    aux_1 ^= mask_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_25_2 > 24)
  {
    acc_2 = ((acc_2 + (mask_25_2 * 2)) + 5) & 127;
    aux_2 ^= mask_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_57_1 == quantum_57_2);
  assert(checksum_72_1 == checksum_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_32_1 == metric_32_2);
  assert(mask_25_1 == mask_25_2);
}

int fn_R001277_7713_21(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int quantum_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_57 = ((quantum_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_57) & 127;
  }

  int checksum_72 = (aux + st.buffer[1]) & 3;
  switch (checksum_72)
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
  int metric_32 = local_arr[aux % 3];
  acc = (acc + (metric_32 * 2)) & 127;
  int mask_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_25 > 24)
  {
    acc = ((acc + (mask_25 * 2)) + 5) & 127;
    aux ^= mask_25 & 15;
  }
  else
  {
    acc = ((acc - mask_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001277_7713_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st_1 = {0};
  struct StreamBuffer_R001277_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_62_1 = local_arr_1[aux_1 % 3];
  int weight_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_62_2 * 2)) & 127;
  int anchor_45_1 = 0;
  int anchor_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_45_1 = ((anchor_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_45_2 = ((anchor_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_45_1) & 127;
    acc_2 = (acc_2 + anchor_45_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_62_1 == weight_62_2);
  assert(anchor_45_1 == anchor_45_2);
}

int fn_R001277_7713_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001277_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_62 = local_arr[aux % 3];
  acc = (acc + (weight_62 * 2)) & 127;
  int anchor_45 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_45 = ((anchor_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_45) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001277_0_1;
  int sec_r001277_0_2;
  int sec_r001277_1_1;
  int sec_r001277_1_2;
  int sec_r001277_2_1;
  int sec_r001277_2_2;
  int sec_r001277_3_1;
  int sec_r001277_3_2;
  int sec_r001277_4_1;
  int sec_r001277_4_2;
  int sec_r001277_5_1;
  int sec_r001277_5_2;
  int sec_r001277_6_1;
  int sec_r001277_6_2;
  int sec_r001277_7_1;
  int sec_r001277_7_2;
  int sec_r001277_8_1;
  int sec_r001277_8_2;
  int sec_r001277_9_1;
  int sec_r001277_9_2;
  int sec_r001277_10_1;
  int sec_r001277_10_2;
  int sec_r001277_11_1;
  int sec_r001277_11_2;
  int sec_r001277_12_1;
  int sec_r001277_12_2;
  int sec_r001277_13_1;
  int sec_r001277_13_2;
  int sec_r001277_14_1;
  int sec_r001277_14_2;
  int sec_r001277_15_1;
  int sec_r001277_15_2;
  int sec_r001277_16_1;
  int sec_r001277_16_2;
  int sec_r001277_17_1;
  int sec_r001277_17_2;
  int sec_r001277_18_1;
  int sec_r001277_18_2;
  int pub_r001277_0_1;
  int pub_r001277_0_2;
  int pub_r001277_1_1;
  int pub_r001277_1_2;
  int pub_r001277_2_1;
  int pub_r001277_2_2;
  int pub_r001277_3_1;
  int pub_r001277_3_2;
  int pub_r001277_4_1;
  int pub_r001277_4_2;
  int pub_r001277_5_1;
  int pub_r001277_5_2;
  int pub_r001277_6_1;
  int pub_r001277_6_2;
  int pub_r001277_7_1;
  int pub_r001277_7_2;
  int pub_r001277_8_1;
  int pub_r001277_8_2;
  int pub_r001277_9_1;
  int pub_r001277_9_2;
  int pub_r001277_10_1;
  int pub_r001277_10_2;
  int pub_r001277_11_1;
  int pub_r001277_11_2;
  int pub_r001277_12_1;
  int pub_r001277_12_2;
  int pub_r001277_13_1;
  int pub_r001277_13_2;
  int pub_r001277_14_1;
  int pub_r001277_14_2;
  int pub_r001277_15_1;
  int pub_r001277_15_2;
  int pub_r001277_16_1;
  int pub_r001277_16_2;
  int pub_r001277_17_1;
  int pub_r001277_17_2;
  int pub_r001277_18_1;
  int pub_r001277_18_2;
  int pub_r001277_19_1;
  int pub_r001277_19_2;
  int pub_r001277_20_1;
  int pub_r001277_20_2;
  int pub_r001277_21_1;
  int pub_r001277_21_2;
  int pub_r001277_22_1;
  int pub_r001277_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001277_0_1 >= (-100)) && (pub_r001277_0_1 <= 100));
  __CPROVER_assume((pub_r001277_0_2 >= (-100)) && (pub_r001277_0_2 <= 100));
  __CPROVER_assume((pub_r001277_1_1 >= (-100)) && (pub_r001277_1_1 <= 100));
  __CPROVER_assume((pub_r001277_1_2 >= (-100)) && (pub_r001277_1_2 <= 100));
  __CPROVER_assume((pub_r001277_2_1 >= (-100)) && (pub_r001277_2_1 <= 100));
  __CPROVER_assume((pub_r001277_2_2 >= (-100)) && (pub_r001277_2_2 <= 100));
  __CPROVER_assume((pub_r001277_3_1 >= (-100)) && (pub_r001277_3_1 <= 100));
  __CPROVER_assume((pub_r001277_3_2 >= (-100)) && (pub_r001277_3_2 <= 100));
  __CPROVER_assume((pub_r001277_4_1 >= (-100)) && (pub_r001277_4_1 <= 100));
  __CPROVER_assume((pub_r001277_4_2 >= (-100)) && (pub_r001277_4_2 <= 100));
  __CPROVER_assume((pub_r001277_5_1 >= (-100)) && (pub_r001277_5_1 <= 100));
  __CPROVER_assume((pub_r001277_5_2 >= (-100)) && (pub_r001277_5_2 <= 100));
  __CPROVER_assume((pub_r001277_6_1 >= (-100)) && (pub_r001277_6_1 <= 100));
  __CPROVER_assume((pub_r001277_6_2 >= (-100)) && (pub_r001277_6_2 <= 100));
  __CPROVER_assume((pub_r001277_7_1 >= (-100)) && (pub_r001277_7_1 <= 100));
  __CPROVER_assume((pub_r001277_7_2 >= (-100)) && (pub_r001277_7_2 <= 100));
  __CPROVER_assume((pub_r001277_8_1 >= (-100)) && (pub_r001277_8_1 <= 100));
  __CPROVER_assume((pub_r001277_8_2 >= (-100)) && (pub_r001277_8_2 <= 100));
  __CPROVER_assume((pub_r001277_9_1 >= (-100)) && (pub_r001277_9_1 <= 100));
  __CPROVER_assume((pub_r001277_9_2 >= (-100)) && (pub_r001277_9_2 <= 100));
  __CPROVER_assume((pub_r001277_10_1 >= (-100)) && (pub_r001277_10_1 <= 100));
  __CPROVER_assume((pub_r001277_10_2 >= (-100)) && (pub_r001277_10_2 <= 100));
  __CPROVER_assume((pub_r001277_11_1 >= (-100)) && (pub_r001277_11_1 <= 100));
  __CPROVER_assume((pub_r001277_11_2 >= (-100)) && (pub_r001277_11_2 <= 100));
  __CPROVER_assume((pub_r001277_12_1 >= (-100)) && (pub_r001277_12_1 <= 100));
  __CPROVER_assume((pub_r001277_12_2 >= (-100)) && (pub_r001277_12_2 <= 100));
  __CPROVER_assume((pub_r001277_13_1 >= (-100)) && (pub_r001277_13_1 <= 100));
  __CPROVER_assume((pub_r001277_13_2 >= (-100)) && (pub_r001277_13_2 <= 100));
  __CPROVER_assume((pub_r001277_14_1 >= (-100)) && (pub_r001277_14_1 <= 100));
  __CPROVER_assume((pub_r001277_14_2 >= (-100)) && (pub_r001277_14_2 <= 100));
  __CPROVER_assume((pub_r001277_15_1 >= (-100)) && (pub_r001277_15_1 <= 100));
  __CPROVER_assume((pub_r001277_15_2 >= (-100)) && (pub_r001277_15_2 <= 100));
  __CPROVER_assume((pub_r001277_16_1 >= (-100)) && (pub_r001277_16_1 <= 100));
  __CPROVER_assume((pub_r001277_16_2 >= (-100)) && (pub_r001277_16_2 <= 100));
  __CPROVER_assume((pub_r001277_17_1 >= (-100)) && (pub_r001277_17_1 <= 100));
  __CPROVER_assume((pub_r001277_17_2 >= (-100)) && (pub_r001277_17_2 <= 100));
  __CPROVER_assume((pub_r001277_18_1 >= (-100)) && (pub_r001277_18_1 <= 100));
  __CPROVER_assume((pub_r001277_18_2 >= (-100)) && (pub_r001277_18_2 <= 100));
  __CPROVER_assume((pub_r001277_19_1 >= (-100)) && (pub_r001277_19_1 <= 100));
  __CPROVER_assume((pub_r001277_19_2 >= (-100)) && (pub_r001277_19_2 <= 100));
  __CPROVER_assume((pub_r001277_20_1 >= (-100)) && (pub_r001277_20_1 <= 100));
  __CPROVER_assume((pub_r001277_20_2 >= (-100)) && (pub_r001277_20_2 <= 100));
  __CPROVER_assume((pub_r001277_21_1 >= (-100)) && (pub_r001277_21_1 <= 100));
  __CPROVER_assume((pub_r001277_21_2 >= (-100)) && (pub_r001277_21_2 <= 100));
  __CPROVER_assume((pub_r001277_22_1 >= (-100)) && (pub_r001277_22_1 <= 100));
  __CPROVER_assume((pub_r001277_22_2 >= (-100)) && (pub_r001277_22_2 <= 100));
  __CPROVER_assume((sec_r001277_0_1 >= 0) && (sec_r001277_0_1 <= 255));
  __CPROVER_assume((sec_r001277_0_2 >= 0) && (sec_r001277_0_2 <= 255));
  __CPROVER_assume((sec_r001277_1_1 >= 0) && (sec_r001277_1_1 <= 255));
  __CPROVER_assume((sec_r001277_1_2 >= 0) && (sec_r001277_1_2 <= 255));
  __CPROVER_assume((sec_r001277_2_1 >= 0) && (sec_r001277_2_1 <= 255));
  __CPROVER_assume((sec_r001277_2_2 >= 0) && (sec_r001277_2_2 <= 255));
  __CPROVER_assume((sec_r001277_3_1 >= 0) && (sec_r001277_3_1 <= 255));
  __CPROVER_assume((sec_r001277_3_2 >= 0) && (sec_r001277_3_2 <= 255));
  __CPROVER_assume((sec_r001277_4_1 >= 0) && (sec_r001277_4_1 <= 255));
  __CPROVER_assume((sec_r001277_4_2 >= 0) && (sec_r001277_4_2 <= 255));
  __CPROVER_assume((sec_r001277_5_1 >= 0) && (sec_r001277_5_1 <= 255));
  __CPROVER_assume((sec_r001277_5_2 >= 0) && (sec_r001277_5_2 <= 255));
  __CPROVER_assume((sec_r001277_6_1 >= 0) && (sec_r001277_6_1 <= 255));
  __CPROVER_assume((sec_r001277_6_2 >= 0) && (sec_r001277_6_2 <= 255));
  __CPROVER_assume((sec_r001277_7_1 >= 0) && (sec_r001277_7_1 <= 255));
  __CPROVER_assume((sec_r001277_7_2 >= 0) && (sec_r001277_7_2 <= 255));
  __CPROVER_assume((sec_r001277_8_1 >= 0) && (sec_r001277_8_1 <= 255));
  __CPROVER_assume((sec_r001277_8_2 >= 0) && (sec_r001277_8_2 <= 255));
  __CPROVER_assume((sec_r001277_9_1 >= 0) && (sec_r001277_9_1 <= 255));
  __CPROVER_assume((sec_r001277_9_2 >= 0) && (sec_r001277_9_2 <= 255));
  __CPROVER_assume((sec_r001277_10_1 >= 0) && (sec_r001277_10_1 <= 255));
  __CPROVER_assume((sec_r001277_10_2 >= 0) && (sec_r001277_10_2 <= 255));
  __CPROVER_assume((sec_r001277_11_1 >= 0) && (sec_r001277_11_1 <= 255));
  __CPROVER_assume((sec_r001277_11_2 >= 0) && (sec_r001277_11_2 <= 255));
  __CPROVER_assume((sec_r001277_12_1 >= 0) && (sec_r001277_12_1 <= 255));
  __CPROVER_assume((sec_r001277_12_2 >= 0) && (sec_r001277_12_2 <= 255));
  __CPROVER_assume((sec_r001277_13_1 >= 0) && (sec_r001277_13_1 <= 255));
  __CPROVER_assume((sec_r001277_13_2 >= 0) && (sec_r001277_13_2 <= 255));
  __CPROVER_assume((sec_r001277_14_1 >= 0) && (sec_r001277_14_1 <= 255));
  __CPROVER_assume((sec_r001277_14_2 >= 0) && (sec_r001277_14_2 <= 255));
  __CPROVER_assume((sec_r001277_15_1 >= 0) && (sec_r001277_15_1 <= 255));
  __CPROVER_assume((sec_r001277_15_2 >= 0) && (sec_r001277_15_2 <= 255));
  __CPROVER_assume((sec_r001277_16_1 >= 0) && (sec_r001277_16_1 <= 255));
  __CPROVER_assume((sec_r001277_16_2 >= 0) && (sec_r001277_16_2 <= 255));
  __CPROVER_assume((sec_r001277_17_1 >= 0) && (sec_r001277_17_1 <= 255));
  __CPROVER_assume((sec_r001277_17_2 >= 0) && (sec_r001277_17_2 <= 255));
  __CPROVER_assume((sec_r001277_18_1 >= 0) && (sec_r001277_18_1 <= 255));
  __CPROVER_assume((sec_r001277_18_2 >= 0) && (sec_r001277_18_2 <= 255));
  struct MatrixBlock_R001277_7713_0 st_var_0_1 = {0};
  struct MatrixBlock_R001277_7713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001277_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001277_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001277_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001277_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001277_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001277_0_2 + 7) & 15;
  struct StreamBuffer_R001277_7713_1 st_var_1_1 = {0};
  struct StreamBuffer_R001277_7713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001277_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001277_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001277_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001277_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001277_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001277_0_2 + 9) & 15;
  union ColorPixel_R001277_7713_0 u_var_1;
  union ColorPixel_R001277_7713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001277_7713_0(sec_r001277_0_1, sec_r001277_1_1, pub_r001277_2_1, pub_r001277_3_1);
  int helper_flow_0_2 = fn_R001277_7713_0(sec_r001277_0_2, sec_r001277_1_2, pub_r001277_2_2, pub_r001277_3_2);
  fn_R001277_7713_0_2(sec_r001277_0_1, sec_r001277_1_1, pub_r001277_2_1, pub_r001277_3_1, sec_r001277_0_2, sec_r001277_1_2, pub_r001277_2_2, pub_r001277_3_2);
  int helper_flow_1_1 = fn_R001277_7713_1(sec_r001277_1_1, pub_r001277_2_1, pub_r001277_3_1, pub_r001277_4_1, pub_r001277_5_1);
  int helper_flow_1_2 = fn_R001277_7713_1(sec_r001277_1_2, pub_r001277_2_2, pub_r001277_3_2, pub_r001277_4_2, pub_r001277_5_2);
  fn_R001277_7713_1_2(sec_r001277_1_1, pub_r001277_2_1, pub_r001277_3_1, pub_r001277_4_1, pub_r001277_5_1, sec_r001277_1_2, pub_r001277_2_2, pub_r001277_3_2, pub_r001277_4_2, pub_r001277_5_2);
  int helper_flow_2_1 = fn_R001277_7713_2(sec_r001277_2_1, sec_r001277_3_1, pub_r001277_4_1, pub_r001277_5_1);
  int helper_flow_2_2 = fn_R001277_7713_2(sec_r001277_2_2, sec_r001277_3_2, pub_r001277_4_2, pub_r001277_5_2);
  fn_R001277_7713_2_2(sec_r001277_2_1, sec_r001277_3_1, pub_r001277_4_1, pub_r001277_5_1, sec_r001277_2_2, sec_r001277_3_2, pub_r001277_4_2, pub_r001277_5_2);
  int helper_flow_3_1 = fn_R001277_7713_3(sec_r001277_3_1, pub_r001277_4_1);
  int helper_flow_3_2 = fn_R001277_7713_3(sec_r001277_3_2, pub_r001277_4_2);
  fn_R001277_7713_3_2(sec_r001277_3_1, pub_r001277_4_1, sec_r001277_3_2, pub_r001277_4_2);
  int helper_flow_4_1 = fn_R001277_7713_4(sec_r001277_4_1, sec_r001277_5_1, pub_r001277_6_1);
  int helper_flow_4_2 = fn_R001277_7713_4(sec_r001277_4_2, sec_r001277_5_2, pub_r001277_6_2);
  fn_R001277_7713_4_2(sec_r001277_4_1, sec_r001277_5_1, pub_r001277_6_1, sec_r001277_4_2, sec_r001277_5_2, pub_r001277_6_2);
  int helper_flow_5_1 = fn_R001277_7713_5(sec_r001277_5_1, pub_r001277_6_1);
  int helper_flow_5_2 = fn_R001277_7713_5(sec_r001277_5_2, pub_r001277_6_2);
  fn_R001277_7713_5_2(sec_r001277_5_1, pub_r001277_6_1, sec_r001277_5_2, pub_r001277_6_2);
  int helper_flow_6_1 = fn_R001277_7713_6(sec_r001277_6_1, sec_r001277_7_1, pub_r001277_8_1);
  int helper_flow_6_2 = fn_R001277_7713_6(sec_r001277_6_2, sec_r001277_7_2, pub_r001277_8_2);
  fn_R001277_7713_6_2(sec_r001277_6_1, sec_r001277_7_1, pub_r001277_8_1, sec_r001277_6_2, sec_r001277_7_2, pub_r001277_8_2);
  int helper_flow_7_1 = fn_R001277_7713_7(sec_r001277_7_1, pub_r001277_8_1, pub_r001277_9_1);
  int helper_flow_7_2 = fn_R001277_7713_7(sec_r001277_7_2, pub_r001277_8_2, pub_r001277_9_2);
  fn_R001277_7713_7_2(sec_r001277_7_1, pub_r001277_8_1, pub_r001277_9_1, sec_r001277_7_2, pub_r001277_8_2, pub_r001277_9_2);
  int helper_flow_8_1 = fn_R001277_7713_8(sec_r001277_8_1, sec_r001277_9_1, pub_r001277_10_1, pub_r001277_11_1, pub_r001277_12_1);
  int helper_flow_8_2 = fn_R001277_7713_8(sec_r001277_8_2, sec_r001277_9_2, pub_r001277_10_2, pub_r001277_11_2, pub_r001277_12_2);
  fn_R001277_7713_8_2(sec_r001277_8_1, sec_r001277_9_1, pub_r001277_10_1, pub_r001277_11_1, pub_r001277_12_1, sec_r001277_8_2, sec_r001277_9_2, pub_r001277_10_2, pub_r001277_11_2, pub_r001277_12_2);
  int helper_flow_9_1 = fn_R001277_7713_9(sec_r001277_9_1, sec_r001277_10_1, pub_r001277_11_1, pub_r001277_12_1, pub_r001277_13_1);
  int helper_flow_9_2 = fn_R001277_7713_9(sec_r001277_9_2, sec_r001277_10_2, pub_r001277_11_2, pub_r001277_12_2, pub_r001277_13_2);
  fn_R001277_7713_9_2(sec_r001277_9_1, sec_r001277_10_1, pub_r001277_11_1, pub_r001277_12_1, pub_r001277_13_1, sec_r001277_9_2, sec_r001277_10_2, pub_r001277_11_2, pub_r001277_12_2, pub_r001277_13_2);
  int helper_flow_10_1 = fn_R001277_7713_10(sec_r001277_10_1, pub_r001277_11_1, pub_r001277_12_1, pub_r001277_13_1);
  int helper_flow_10_2 = fn_R001277_7713_10(sec_r001277_10_2, pub_r001277_11_2, pub_r001277_12_2, pub_r001277_13_2);
  fn_R001277_7713_10_2(sec_r001277_10_1, pub_r001277_11_1, pub_r001277_12_1, pub_r001277_13_1, sec_r001277_10_2, pub_r001277_11_2, pub_r001277_12_2, pub_r001277_13_2);
  int stage_v_0_1 = (helper_flow_4_1 ^ pub_r001277_18_1) & 63;
  int stage_v_0_2 = (helper_flow_4_2 ^ pub_r001277_18_2) & 63;
  if ((stage_v_0_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_0_1 * 2)) & 255;
  }
  if ((stage_v_0_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_0_2 * 2)) & 255;
  }
  int stage_v_1_1 = ((pub_r001277_10_1 * 2) + 35) & 63;
  int stage_v_1_2 = ((pub_r001277_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (sec_r001277_11_1 ^ pub_r001277_11_1) & 63;
  int stage_v_2_2 = (sec_r001277_11_2 ^ pub_r001277_11_2) & 63;
  if ((stage_v_2_1 & 1) != 0)
  {
    if ((sec_r001277_16_1 & 2) != 0)
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
    if ((sec_r001277_16_2 & 2) != 0)
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
  int stage_v_3_1 = ((pub_r001277_18_1 * 2) + 18) & 63;
  int stage_v_3_2 = ((pub_r001277_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (helper_flow_3_1 ^ pub_r001277_15_1) & 63;
  int stage_v_4_2 = (helper_flow_3_2 ^ pub_r001277_15_2) & 63;
  if ((stage_v_4_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_4_1 * 2)) & 255;
  }
  if ((stage_v_4_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_4_2 * 2)) & 255;
  }
  int stage_v_5_1 = ((pub_r001277_0_1 * 2) + 28) & 63;
  int stage_v_5_2 = ((pub_r001277_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001277_1_1 * 2) + 11) & 63;
  int stage_v_6_2 = ((pub_r001277_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (sec_r001277_11_1 ^ pub_r001277_19_1) & 63;
  int stage_v_7_2 = (sec_r001277_11_2 ^ pub_r001277_19_2) & 63;
  if ((stage_v_7_1 & 1) != 0)
  {
    if ((helper_flow_10_1 & 2) != 0)
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
    if ((helper_flow_10_2 & 2) != 0)
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
  int stage_v_8_1 = ((pub_r001277_4_1 * 2) + 21) & 63;
  int stage_v_8_2 = ((pub_r001277_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001277_6_1 * 2) + 24) & 63;
  int stage_v_9_2 = ((pub_r001277_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (stage_v_0_1 ^ pub_r001277_16_1) & 63;
  int stage_v_10_2 = (stage_v_0_2 ^ pub_r001277_16_2) & 63;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((sec_r001277_13_1 & 2) != 0)
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
    if ((sec_r001277_13_2 & 2) != 0)
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
  int stage_v_11_1 = (helper_flow_3_1 ^ pub_r001277_2_1) & 63;
  int stage_v_11_2 = (helper_flow_3_2 ^ pub_r001277_2_2) & 63;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((sec_r001277_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_11_1 * 2)) & 255;
  }
  if ((stage_v_11_2 & 1) != 0)
  {
    if ((sec_r001277_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_11_2 * 2)) & 255;
  }
  int stage_v_12_1 = (sec_r001277_16_1 ^ pub_r001277_7_1) & 63;
  int stage_v_12_2 = (sec_r001277_16_2 ^ pub_r001277_7_2) & 63;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
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
    if ((stage_v_7_2 & 2) != 0)
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
  int stage_v_13_1 = (sec_r001277_3_1 ^ pub_r001277_11_1) & 63;
  int stage_v_13_2 = (sec_r001277_3_2 ^ pub_r001277_11_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r001277_10_1 & 2) != 0)
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
    if ((sec_r001277_10_2 & 2) != 0)
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
  int stage_v_14_1 = (helper_flow_8_1 ^ pub_r001277_11_1) & 63;
  int stage_v_14_2 = (helper_flow_8_2 ^ pub_r001277_11_2) & 63;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r001277_5_1 & 2) != 0)
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
    if ((sec_r001277_5_2 & 2) != 0)
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
  int stage_v_15_1 = (helper_flow_9_1 ^ pub_r001277_14_1) & 63;
  int stage_v_15_2 = (helper_flow_9_2 ^ pub_r001277_14_2) & 63;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_15_1 * 2)) & 255;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_15_2 * 2)) & 255;
  }
  int stage_v_16_1 = (sec_r001277_14_1 ^ pub_r001277_3_1) & 63;
  int stage_v_16_2 = (sec_r001277_14_2 ^ pub_r001277_3_2) & 63;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r001277_18_1 & 2) != 0)
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
    if ((sec_r001277_18_2 & 2) != 0)
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
  int stage_v_17_1 = ((pub_r001277_18_1 * 2) + 16) & 63;
  int stage_v_17_2 = ((pub_r001277_18_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (sec_r001277_0_1 ^ pub_r001277_13_1) & 63;
  int stage_v_18_2 = (sec_r001277_0_2 ^ pub_r001277_13_2) & 63;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r001277_4_1 & 2) != 0)
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
    if ((sec_r001277_4_2 & 2) != 0)
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
  int stage_v_19_1 = ((pub_r001277_10_1 * 2) + 45) & 63;
  int stage_v_19_2 = ((pub_r001277_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (stage_v_4_1 ^ pub_r001277_2_1) & 63;
  int stage_v_20_2 = (stage_v_4_2 ^ pub_r001277_2_2) & 63;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r001277_4_1 & 2) != 0)
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
    if ((sec_r001277_4_2 & 2) != 0)
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
  int stage_v_21_1 = ((pub_r001277_19_1 * 2) + 50) & 63;
  int stage_v_21_2 = ((pub_r001277_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (sec_r001277_17_1 ^ pub_r001277_6_1) & 63;
  int stage_v_22_2 = (sec_r001277_17_2 ^ pub_r001277_6_2) & 63;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r001277_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_22_1 * 2)) & 255;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r001277_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_22_2 * 2)) & 255;
  }
  int stage_v_23_1 = (helper_flow_1_1 ^ pub_r001277_11_1) & 63;
  int stage_v_23_2 = (helper_flow_1_2 ^ pub_r001277_11_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
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
    if ((stage_v_14_2 & 2) != 0)
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
  int stage_v_24_1 = ((pub_r001277_11_1 * 2) + 40) & 63;
  int stage_v_24_2 = ((pub_r001277_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (sec_r001277_7_1 ^ pub_r001277_7_1) & 63;
  int stage_v_25_2 = (sec_r001277_7_2 ^ pub_r001277_7_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((stage_v_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_25_1 * 2)) & 255;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((stage_v_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_25_2 * 2)) & 255;
  }
  int stage_v_26_1 = ((pub_r001277_9_1 * 2) + 13) & 63;
  int stage_v_26_2 = ((pub_r001277_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001277_4_1 * 2) + 8) & 63;
  int stage_v_27_2 = ((pub_r001277_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (sec_r001277_1_1 ^ pub_r001277_16_1) & 63;
  int stage_v_28_2 = (sec_r001277_1_2 ^ pub_r001277_16_2) & 63;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((helper_flow_10_1 & 2) != 0)
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
    if ((helper_flow_10_2 & 2) != 0)
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
  int stage_v_29_1 = ((pub_r001277_19_1 * 2) + 41) & 63;
  int stage_v_29_2 = ((pub_r001277_19_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (helper_flow_3_1 ^ pub_r001277_11_1) & 63;
  int stage_v_30_2 = (helper_flow_3_2 ^ pub_r001277_11_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((stage_v_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_30_1 * 2)) & 255;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((stage_v_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_30_2 * 2)) & 255;
  }
  int stage_v_31_1 = (sec_r001277_4_1 ^ pub_r001277_0_1) & 63;
  int stage_v_31_2 = (sec_r001277_4_2 ^ pub_r001277_0_2) & 63;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_31_1 * 2)) & 255;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_31_2 * 2)) & 255;
  }
  int stage_v_32_1 = ((pub_r001277_19_1 * 2) + 17) & 63;
  int stage_v_32_2 = ((pub_r001277_19_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (sec_r001277_2_1 ^ pub_r001277_18_1) & 63;
  int stage_v_33_2 = (sec_r001277_2_2 ^ pub_r001277_18_2) & 63;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_33_1 * 2)) & 255;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_33_2 * 2)) & 255;
  }
  int stage_v_34_1 = (sec_r001277_15_1 ^ pub_r001277_4_1) & 63;
  int stage_v_34_2 = (sec_r001277_15_2 ^ pub_r001277_4_2) & 63;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r001277_0_1 & 2) != 0)
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
    if ((sec_r001277_0_2 & 2) != 0)
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
  int stage_v_35_1 = ((pub_r001277_13_1 * 2) + 41) & 63;
  int stage_v_35_2 = ((pub_r001277_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001277_9_1 * 2) + 49) & 63;
  int stage_v_36_2 = ((pub_r001277_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001277_0_1 * 2) + 43) & 63;
  int stage_v_37_2 = ((pub_r001277_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (sec_r001277_11_1 ^ pub_r001277_11_1) & 63;
  int stage_v_38_2 = (sec_r001277_11_2 ^ pub_r001277_11_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
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
    if ((stage_v_10_2 & 2) != 0)
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
  int stage_v_39_1 = ((pub_r001277_12_1 * 2) + 33) & 63;
  int stage_v_39_2 = ((pub_r001277_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (stage_v_38_1 ^ pub_r001277_12_1) & 63;
  int stage_v_40_2 = (stage_v_38_2 ^ pub_r001277_12_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
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
    if ((stage_v_25_2 & 2) != 0)
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
  int stage_v_41_1 = ((pub_r001277_14_1 * 2) + 8) & 63;
  int stage_v_41_2 = ((pub_r001277_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (helper_flow_0_1 ^ pub_r001277_14_1) & 63;
  int stage_v_42_2 = (helper_flow_0_2 ^ pub_r001277_14_2) & 63;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r001277_12_1 & 2) != 0)
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
    if ((sec_r001277_12_2 & 2) != 0)
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
  int stage_v_43_1 = ((pub_r001277_2_1 * 2) + 30) & 63;
  int stage_v_43_2 = ((pub_r001277_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (helper_flow_1_1 ^ pub_r001277_9_1) & 63;
  int stage_v_44_2 = (helper_flow_1_2 ^ pub_r001277_9_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_44_1 * 2)) & 255;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_44_2 * 2)) & 255;
  }
  int stage_v_45_1 = (stage_v_4_1 ^ pub_r001277_2_1) & 63;
  int stage_v_45_2 = (stage_v_4_2 ^ pub_r001277_2_2) & 63;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r001277_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_45_1 * 2)) & 255;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r001277_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_45_2 * 2)) & 255;
  }
  int stage_v_46_1 = ((pub_r001277_18_1 * 2) + 12) & 63;
  int stage_v_46_2 = ((pub_r001277_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001277_16_1 * 2) + 29) & 63;
  int stage_v_47_2 = ((pub_r001277_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (stage_v_22_1 ^ pub_r001277_3_1) & 63;
  int stage_v_48_2 = (stage_v_22_2 ^ pub_r001277_3_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((stage_v_11_1 & 2) != 0)
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
    if ((stage_v_11_2 & 2) != 0)
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
  int stage_v_49_1 = ((pub_r001277_13_1 * 2) + 25) & 63;
  int stage_v_49_2 = ((pub_r001277_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (helper_flow_4_1 ^ pub_r001277_4_1) & 63;
  int stage_v_50_2 = (helper_flow_4_2 ^ pub_r001277_4_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r001277_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_50_1 * 2)) & 255;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r001277_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_50_2 * 2)) & 255;
  }
  int stage_v_51_1 = (helper_flow_6_1 ^ pub_r001277_3_1) & 63;
  int stage_v_51_2 = (helper_flow_6_2 ^ pub_r001277_3_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
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
    if ((stage_v_44_2 & 2) != 0)
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
  int stage_v_52_1 = ((pub_r001277_22_1 * 2) + 15) & 63;
  int stage_v_52_2 = ((pub_r001277_22_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (sec_r001277_15_1 ^ pub_r001277_10_1) & 63;
  int stage_v_53_2 = (sec_r001277_15_2 ^ pub_r001277_10_2) & 63;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
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
    if ((helper_flow_8_2 & 2) != 0)
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
  int stage_v_54_1 = ((pub_r001277_17_1 * 2) + 32) & 63;
  int stage_v_54_2 = ((pub_r001277_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (stage_v_33_1 ^ pub_r001277_21_1) & 63;
  int stage_v_55_2 = (stage_v_33_2 ^ pub_r001277_21_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
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
    if ((stage_v_40_2 & 2) != 0)
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
  int stage_v_56_1 = (sec_r001277_9_1 ^ pub_r001277_17_1) & 63;
  int stage_v_56_2 = (sec_r001277_9_2 ^ pub_r001277_17_2) & 63;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r001277_1_1 & 2) != 0)
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
    if ((sec_r001277_1_2 & 2) != 0)
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
  int stage_v_57_1 = ((pub_r001277_6_1 * 2) + 31) & 63;
  int stage_v_57_2 = ((pub_r001277_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (stage_v_11_1 ^ pub_r001277_0_1) & 63;
  int stage_v_58_2 = (stage_v_11_2 ^ pub_r001277_0_2) & 63;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_58_1 * 2)) & 255;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_58_2 * 2)) & 255;
  }
  int stage_v_59_1 = ((pub_r001277_11_1 * 2) + 38) & 63;
  int stage_v_59_2 = ((pub_r001277_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (stage_v_53_1 ^ pub_r001277_16_1) & 63;
  int stage_v_60_2 = (stage_v_53_2 ^ pub_r001277_16_2) & 63;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r001277_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r001277_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  }
  int stage_v_61_1 = (stage_v_33_1 ^ pub_r001277_13_1) & 63;
  int stage_v_61_2 = (stage_v_33_2 ^ pub_r001277_13_2) & 63;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((helper_flow_10_1 & 2) != 0)
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
    if ((helper_flow_10_2 & 2) != 0)
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
  int stage_v_62_1 = ((pub_r001277_9_1 * 2) + 29) & 63;
  int stage_v_62_2 = ((pub_r001277_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001277_9_1 * 2) + 27) & 63;
  int stage_v_63_2 = ((pub_r001277_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (sec_r001277_16_1 ^ pub_r001277_6_1) & 63;
  int stage_v_64_2 = (sec_r001277_16_2 ^ pub_r001277_6_2) & 63;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
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
    if ((stage_v_14_2 & 2) != 0)
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
  int stage_v_65_1 = (stage_v_0_1 ^ pub_r001277_3_1) & 63;
  int stage_v_65_2 = (stage_v_0_2 ^ pub_r001277_3_2) & 63;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r001277_5_1 & 2) != 0)
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
    if ((sec_r001277_5_2 & 2) != 0)
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
  int stage_v_66_1 = (sec_r001277_4_1 ^ pub_r001277_17_1) & 63;
  int stage_v_66_2 = (sec_r001277_4_2 ^ pub_r001277_17_2) & 63;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
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
    if ((stage_v_10_2 & 2) != 0)
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
  int stage_v_67_1 = ((pub_r001277_18_1 * 2) + 17) & 63;
  int stage_v_67_2 = ((pub_r001277_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (sec_r001277_10_1 ^ pub_r001277_20_1) & 63;
  int stage_v_68_2 = (sec_r001277_10_2 ^ pub_r001277_20_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r001277_1_1 & 2) != 0)
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
    if ((sec_r001277_1_2 & 2) != 0)
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
  int stage_v_69_1 = (stage_v_44_1 ^ pub_r001277_15_1) & 63;
  int stage_v_69_2 = (stage_v_44_2 ^ pub_r001277_15_2) & 63;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
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
    if ((helper_flow_2_2 & 2) != 0)
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
  int stage_v_70_1 = ((pub_r001277_12_1 * 2) + 33) & 63;
  int stage_v_70_2 = ((pub_r001277_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001277_20_1 * 2) + 23) & 63;
  int stage_v_71_2 = ((pub_r001277_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (stage_v_11_1 ^ pub_r001277_18_1) & 63;
  int stage_v_72_2 = (stage_v_11_2 ^ pub_r001277_18_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((stage_v_16_1 & 2) != 0)
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
    if ((stage_v_16_2 & 2) != 0)
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
  int stage_v_73_1 = (stage_v_12_1 ^ pub_r001277_15_1) & 63;
  int stage_v_73_2 = (stage_v_12_2 ^ pub_r001277_15_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  }
  int stage_v_74_1 = (helper_flow_8_1 ^ pub_r001277_18_1) & 63;
  int stage_v_74_2 = (helper_flow_8_2 ^ pub_r001277_18_2) & 63;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((stage_v_48_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  }
  int stage_v_75_1 = (sec_r001277_3_1 ^ pub_r001277_5_1) & 63;
  int stage_v_75_2 = (sec_r001277_3_2 ^ pub_r001277_5_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_76_1 = (stage_v_48_1 ^ pub_r001277_5_1) & 63;
  int stage_v_76_2 = (stage_v_48_2 ^ pub_r001277_5_2) & 63;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r001277_17_1 & 2) != 0)
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
    if ((sec_r001277_17_2 & 2) != 0)
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
  int stage_v_77_1 = (stage_v_4_1 ^ pub_r001277_4_1) & 63;
  int stage_v_77_2 = (stage_v_4_2 ^ pub_r001277_4_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((stage_v_65_1 & 2) != 0)
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
    if ((stage_v_65_2 & 2) != 0)
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
  int stage_v_78_1 = (helper_flow_8_1 ^ pub_r001277_6_1) & 63;
  int stage_v_78_2 = (helper_flow_8_2 ^ pub_r001277_6_2) & 63;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
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
    if ((stage_v_18_2 & 2) != 0)
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
  int stage_v_79_1 = ((pub_r001277_22_1 * 2) + 45) & 63;
  int stage_v_79_2 = ((pub_r001277_22_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (helper_flow_3_1 ^ pub_r001277_14_1) & 63;
  int stage_v_80_2 = (helper_flow_3_2 ^ pub_r001277_14_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
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
    if ((stage_v_66_2 & 2) != 0)
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
  int stage_v_81_1 = (sec_r001277_13_1 ^ pub_r001277_17_1) & 63;
  int stage_v_81_2 = (sec_r001277_13_2 ^ pub_r001277_17_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r001277_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r001277_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  }
  int stage_v_82_1 = ((pub_r001277_2_1 * 2) + 44) & 63;
  int stage_v_82_2 = ((pub_r001277_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (stage_v_58_1 ^ pub_r001277_17_1) & 63;
  int stage_v_83_2 = (stage_v_58_2 ^ pub_r001277_17_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
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
    if ((stage_v_44_2 & 2) != 0)
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
  int stage_v_84_1 = (stage_v_18_1 ^ pub_r001277_17_1) & 63;
  int stage_v_84_2 = (stage_v_18_2 ^ pub_r001277_17_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((stage_v_42_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((stage_v_42_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  }
  int stage_v_85_1 = ((pub_r001277_20_1 * 2) + 35) & 63;
  int stage_v_85_2 = ((pub_r001277_20_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001277_9_1 * 2) + 33) & 63;
  int stage_v_86_2 = ((pub_r001277_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (stage_v_12_1 ^ pub_r001277_20_1) & 63;
  int stage_v_87_2 = (stage_v_12_2 ^ pub_r001277_20_2) & 63;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((stage_v_11_1 & 2) != 0)
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
    if ((stage_v_11_2 & 2) != 0)
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
  int stage_v_88_1 = ((pub_r001277_13_1 * 2) + 44) & 63;
  int stage_v_88_2 = ((pub_r001277_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (stage_v_87_1 ^ pub_r001277_0_1) & 63;
  int stage_v_89_2 = (stage_v_87_2 ^ pub_r001277_0_2) & 63;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
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
    if ((stage_v_66_2 & 2) != 0)
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
  int stage_v_90_1 = ((pub_r001277_17_1 * 2) + 21) & 63;
  int stage_v_90_2 = ((pub_r001277_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001277_21_1 * 2) + 25) & 63;
  int stage_v_91_2 = ((pub_r001277_21_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (stage_v_25_1 ^ pub_r001277_14_1) & 63;
  int stage_v_92_2 = (stage_v_25_2 ^ pub_r001277_14_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
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
    if ((stage_v_18_2 & 2) != 0)
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
  int stage_v_93_1 = ((pub_r001277_7_1 * 2) + 36) & 63;
  int stage_v_93_2 = ((pub_r001277_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (stage_v_84_1 ^ pub_r001277_3_1) & 63;
  int stage_v_94_2 = (stage_v_84_2 ^ pub_r001277_3_2) & 63;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((stage_v_30_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  }
  int stage_v_95_1 = (stage_v_84_1 ^ pub_r001277_0_1) & 63;
  int stage_v_95_2 = (stage_v_84_2 ^ pub_r001277_0_2) & 63;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_96_1 = (stage_v_33_1 ^ pub_r001277_10_1) & 63;
  int stage_v_96_2 = (stage_v_33_2 ^ pub_r001277_10_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
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
    if ((stage_v_23_2 & 2) != 0)
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
  int stage_v_97_1 = ((pub_r001277_21_1 * 2) + 34) & 63;
  int stage_v_97_2 = ((pub_r001277_21_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001277_16_1 * 2) + 7) & 63;
  int stage_v_98_2 = ((pub_r001277_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (sec_r001277_1_1 ^ pub_r001277_10_1) & 63;
  int stage_v_99_2 = (sec_r001277_1_2 ^ pub_r001277_10_2) & 63;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((stage_v_78_1 & 2) != 0)
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
    if ((stage_v_78_2 & 2) != 0)
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
  int stage_v_100_1 = ((pub_r001277_17_1 * 2) + 14) & 63;
  int stage_v_100_2 = ((pub_r001277_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (stage_v_96_1 ^ pub_r001277_19_1) & 63;
  int stage_v_101_2 = (stage_v_96_2 ^ pub_r001277_19_2) & 63;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((stage_v_73_1 & 2) != 0)
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
    if ((stage_v_73_2 & 2) != 0)
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
  int stage_v_102_1 = (sec_r001277_9_1 ^ pub_r001277_14_1) & 63;
  int stage_v_102_2 = (sec_r001277_9_2 ^ pub_r001277_14_2) & 63;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((stage_v_53_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((stage_v_53_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  }
  int stage_v_103_1 = (sec_r001277_14_1 ^ pub_r001277_2_1) & 63;
  int stage_v_103_2 = (sec_r001277_14_2 ^ pub_r001277_2_2) & 63;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
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
    if ((helper_flow_6_2 & 2) != 0)
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
  int stage_v_104_1 = (stage_v_16_1 ^ pub_r001277_2_1) & 63;
  int stage_v_104_2 = (stage_v_16_2 ^ pub_r001277_2_2) & 63;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  }
  int stage_v_105_1 = ((pub_r001277_3_1 * 2) + 40) & 63;
  int stage_v_105_2 = ((pub_r001277_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001277_14_1 * 2) + 42) & 63;
  int stage_v_106_2 = ((pub_r001277_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (stage_v_16_1 ^ pub_r001277_0_1) & 63;
  int stage_v_107_2 = (stage_v_16_2 ^ pub_r001277_0_2) & 63;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((stage_v_58_1 & 2) != 0)
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
    if ((stage_v_58_2 & 2) != 0)
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
  int stage_v_108_1 = (stage_v_99_1 ^ pub_r001277_17_1) & 63;
  int stage_v_108_2 = (stage_v_99_2 ^ pub_r001277_17_2) & 63;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r001277_18_1 & 2) != 0)
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
    if ((sec_r001277_18_2 & 2) != 0)
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
  int stage_v_109_1 = (stage_v_50_1 ^ pub_r001277_7_1) & 63;
  int stage_v_109_2 = (stage_v_50_2 ^ pub_r001277_7_2) & 63;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((stage_v_45_1 & 2) != 0)
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
    if ((stage_v_45_2 & 2) != 0)
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
  int stage_v_110_1 = ((pub_r001277_13_1 * 2) + 44) & 63;
  int stage_v_110_2 = ((pub_r001277_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001277_20_1 * 2) + 5) & 63;
  int stage_v_111_2 = ((pub_r001277_20_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (helper_flow_3_1 ^ pub_r001277_6_1) & 63;
  int stage_v_112_2 = (helper_flow_3_2 ^ pub_r001277_6_2) & 63;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((stage_v_104_1 & 2) != 0)
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
    if ((stage_v_104_2 & 2) != 0)
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
  int stage_v_113_1 = ((pub_r001277_7_1 * 2) + 35) & 63;
  int stage_v_113_2 = ((pub_r001277_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001277_18_1 * 2) + 26) & 63;
  int stage_v_114_2 = ((pub_r001277_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (helper_flow_6_1 ^ pub_r001277_14_1) & 63;
  int stage_v_115_2 = (helper_flow_6_2 ^ pub_r001277_14_2) & 63;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((stage_v_89_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((stage_v_89_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  }
  int stage_v_116_1 = (stage_v_77_1 ^ pub_r001277_6_1) & 63;
  int stage_v_116_2 = (stage_v_77_2 ^ pub_r001277_6_2) & 63;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((stage_v_76_1 & 2) != 0)
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
    if ((stage_v_76_2 & 2) != 0)
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
  int stage_v_117_1 = (stage_v_64_1 ^ pub_r001277_14_1) & 63;
  int stage_v_117_2 = (stage_v_64_2 ^ pub_r001277_14_2) & 63;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((stage_v_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((stage_v_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  }
  int stage_v_118_1 = ((pub_r001277_4_1 * 2) + 45) & 63;
  int stage_v_118_2 = ((pub_r001277_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (stage_v_102_1 ^ pub_r001277_9_1) & 63;
  int stage_v_119_2 = (stage_v_102_2 ^ pub_r001277_9_2) & 63;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  }
  int stage_v_120_1 = (sec_r001277_1_1 ^ pub_r001277_18_1) & 63;
  int stage_v_120_2 = (sec_r001277_1_2 ^ pub_r001277_18_2) & 63;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((stage_v_104_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((stage_v_104_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  }
  int stage_v_121_1 = (stage_v_77_1 ^ pub_r001277_18_1) & 63;
  int stage_v_121_2 = (stage_v_77_2 ^ pub_r001277_18_2) & 63;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r001277_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r001277_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  }
  int stage_v_122_1 = (stage_v_66_1 ^ pub_r001277_5_1) & 63;
  int stage_v_122_2 = (stage_v_66_2 ^ pub_r001277_5_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
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
    if ((stage_v_2_2 & 2) != 0)
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
  int stage_v_123_1 = (stage_v_96_1 ^ pub_r001277_14_1) & 63;
  int stage_v_123_2 = (stage_v_96_2 ^ pub_r001277_14_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((stage_v_58_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((stage_v_58_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  }
  int stage_v_124_1 = (helper_flow_2_1 ^ pub_r001277_0_1) & 63;
  int stage_v_124_2 = (helper_flow_2_2 ^ pub_r001277_0_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r001277_3_1 & 2) != 0)
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
    if ((sec_r001277_3_2 & 2) != 0)
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
  int stage_v_125_1 = ((pub_r001277_14_1 * 2) + 33) & 63;
  int stage_v_125_2 = ((pub_r001277_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (stage_v_10_1 ^ pub_r001277_12_1) & 63;
  int stage_v_126_2 = (stage_v_10_2 ^ pub_r001277_12_2) & 63;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((stage_v_104_1 & 2) != 0)
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
    if ((stage_v_104_2 & 2) != 0)
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
  int stage_v_127_1 = (stage_v_64_1 ^ pub_r001277_2_1) & 63;
  int stage_v_127_2 = (stage_v_64_2 ^ pub_r001277_2_2) & 63;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((stage_v_64_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((stage_v_64_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  }
  int stage_v_128_1 = ((pub_r001277_4_1 * 2) + 43) & 63;
  int stage_v_128_2 = ((pub_r001277_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (stage_v_76_1 ^ pub_r001277_6_1) & 63;
  int stage_v_129_2 = (stage_v_76_2 ^ pub_r001277_6_2) & 63;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((stage_v_89_1 & 2) != 0)
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
    if ((stage_v_89_2 & 2) != 0)
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
  int stage_v_130_1 = (stage_v_87_1 ^ pub_r001277_14_1) & 63;
  int stage_v_130_2 = (stage_v_87_2 ^ pub_r001277_14_2) & 63;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((stage_v_22_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((stage_v_22_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  }
  int stage_v_131_1 = ((pub_r001277_7_1 * 2) + 44) & 63;
  int stage_v_131_2 = ((pub_r001277_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (helper_flow_6_1 ^ pub_r001277_7_1) & 63;
  int stage_v_132_2 = (helper_flow_6_2 ^ pub_r001277_7_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((stage_v_129_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((stage_v_129_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  }
  int stage_v_133_1 = (stage_v_89_1 ^ pub_r001277_4_1) & 63;
  int stage_v_133_2 = (stage_v_89_2 ^ pub_r001277_4_2) & 63;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((stage_v_92_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((stage_v_92_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  }
  int stage_v_134_1 = ((pub_r001277_21_1 * 2) + 5) & 63;
  int stage_v_134_2 = ((pub_r001277_21_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (sec_r001277_1_1 ^ pub_r001277_5_1) & 63;
  int stage_v_135_2 = (sec_r001277_1_2 ^ pub_r001277_5_2) & 63;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
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
    if ((stage_v_30_2 & 2) != 0)
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
  int stage_v_136_1 = (stage_v_13_1 ^ pub_r001277_16_1) & 63;
  int stage_v_136_2 = (stage_v_13_2 ^ pub_r001277_16_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r001277_17_1 & 2) != 0)
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
    if ((sec_r001277_17_2 & 2) != 0)
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
  int stage_v_137_1 = ((pub_r001277_0_1 * 2) + 34) & 63;
  int stage_v_137_2 = ((pub_r001277_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001277_8_1 * 2) + 14) & 63;
  int stage_v_138_2 = ((pub_r001277_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (sec_r001277_1_1 ^ pub_r001277_4_1) & 63;
  int stage_v_139_2 = (sec_r001277_1_2 ^ pub_r001277_4_2) & 63;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((stage_v_50_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  }
  if ((stage_v_139_2 & 1) != 0)
  {
    if ((stage_v_50_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  }
  int stage_v_140_1 = ((pub_r001277_19_1 * 2) + 23) & 63;
  int stage_v_140_2 = ((pub_r001277_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001277_1_1 * 2) + 43) & 63;
  int stage_v_141_2 = ((pub_r001277_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (sec_r001277_7_1 ^ pub_r001277_7_1) & 63;
  int stage_v_142_2 = (sec_r001277_7_2 ^ pub_r001277_7_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((stage_v_112_1 & 2) != 0)
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
    if ((stage_v_112_2 & 2) != 0)
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
  int stage_v_143_1 = ((pub_r001277_3_1 * 2) + 26) & 63;
  int stage_v_143_2 = ((pub_r001277_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (stage_v_64_1 ^ pub_r001277_8_1) & 63;
  int stage_v_144_2 = (stage_v_64_2 ^ pub_r001277_8_2) & 63;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((sec_r001277_3_1 & 2) != 0)
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
    if ((sec_r001277_3_2 & 2) != 0)
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
  int stage_v_145_1 = ((pub_r001277_5_1 * 2) + 12) & 63;
  int stage_v_145_2 = ((pub_r001277_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (stage_v_22_1 ^ pub_r001277_10_1) & 63;
  int stage_v_146_2 = (stage_v_22_2 ^ pub_r001277_10_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((stage_v_102_1 & 2) != 0)
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
    if ((stage_v_102_2 & 2) != 0)
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
  int stage_v_147_1 = (stage_v_38_1 ^ pub_r001277_7_1) & 63;
  int stage_v_147_2 = (stage_v_38_2 ^ pub_r001277_7_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
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
    if ((stage_v_44_2 & 2) != 0)
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
  int stage_v_148_1 = (stage_v_119_1 ^ pub_r001277_13_1) & 63;
  int stage_v_148_2 = (stage_v_119_2 ^ pub_r001277_13_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
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
    if ((stage_v_14_2 & 2) != 0)
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
  int stage_v_149_1 = (stage_v_72_1 ^ pub_r001277_22_1) & 63;
  int stage_v_149_2 = (stage_v_72_2 ^ pub_r001277_22_2) & 63;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((stage_v_87_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  }
  if ((stage_v_149_2 & 1) != 0)
  {
    if ((stage_v_87_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  }
  int stage_v_150_1 = (stage_v_75_1 ^ pub_r001277_9_1) & 63;
  int stage_v_150_2 = (stage_v_75_2 ^ pub_r001277_9_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((stage_v_126_1 & 2) != 0)
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
    if ((stage_v_126_2 & 2) != 0)
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
  int stage_v_151_1 = (stage_v_129_1 ^ pub_r001277_16_1) & 63;
  int stage_v_151_2 = (stage_v_129_2 ^ pub_r001277_16_2) & 63;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
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
    if ((stage_v_44_2 & 2) != 0)
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
  int stage_v_152_1 = ((pub_r001277_11_1 * 2) + 49) & 63;
  int stage_v_152_2 = ((pub_r001277_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (stage_v_30_1 ^ pub_r001277_19_1) & 63;
  int stage_v_153_2 = (stage_v_30_2 ^ pub_r001277_19_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((sec_r001277_4_1 & 2) != 0)
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
    if ((sec_r001277_4_2 & 2) != 0)
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
  int stage_v_154_1 = (stage_v_44_1 ^ pub_r001277_6_1) & 63;
  int stage_v_154_2 = (stage_v_44_2 ^ pub_r001277_6_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((sec_r001277_4_1 & 2) != 0)
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
    if ((sec_r001277_4_2 & 2) != 0)
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
  int stage_v_155_1 = (stage_v_84_1 ^ pub_r001277_17_1) & 63;
  int stage_v_155_2 = (stage_v_84_2 ^ pub_r001277_17_2) & 63;
  if ((stage_v_155_1 & 1) != 0)
  {
    if ((stage_v_132_1 & 2) != 0)
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
    if ((stage_v_132_2 & 2) != 0)
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
  int stage_v_156_1 = (stage_v_127_1 ^ pub_r001277_16_1) & 63;
  int stage_v_156_2 = (stage_v_127_2 ^ pub_r001277_16_2) & 63;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((stage_v_117_1 & 2) != 0)
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
    if ((stage_v_117_2 & 2) != 0)
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
  int stage_v_157_1 = (stage_v_7_1 ^ pub_r001277_18_1) & 63;
  int stage_v_157_2 = (stage_v_7_2 ^ pub_r001277_18_2) & 63;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
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
    if ((stage_v_23_2 & 2) != 0)
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
  int stage_v_158_1 = (stage_v_69_1 ^ pub_r001277_15_1) & 63;
  int stage_v_158_2 = (stage_v_69_2 ^ pub_r001277_15_2) & 63;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((sec_r001277_9_1 & 2) != 0)
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
    if ((sec_r001277_9_2 & 2) != 0)
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
  int stage_v_159_1 = ((pub_r001277_0_1 * 2) + 15) & 63;
  int stage_v_159_2 = ((pub_r001277_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001277_0_1 * 2) + 5) & 63;
  int stage_v_160_2 = ((pub_r001277_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (stage_v_61_1 ^ pub_r001277_17_1) & 63;
  int stage_v_161_2 = (stage_v_61_2 ^ pub_r001277_17_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((stage_v_45_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  }
  if ((stage_v_161_2 & 1) != 0)
  {
    if ((stage_v_45_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  }
  int stage_v_162_1 = ((pub_r001277_11_1 * 2) + 25) & 63;
  int stage_v_162_2 = ((pub_r001277_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (stage_v_66_1 ^ pub_r001277_4_1) & 63;
  int stage_v_163_2 = (stage_v_66_2 ^ pub_r001277_4_2) & 63;
  if ((stage_v_163_1 & 1) != 0)
  {
    if ((stage_v_154_1 & 2) != 0)
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
    if ((stage_v_154_2 & 2) != 0)
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
  int stage_v_164_1 = (stage_v_123_1 ^ pub_r001277_8_1) & 63;
  int stage_v_164_2 = (stage_v_123_2 ^ pub_r001277_8_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((stage_v_109_1 & 2) != 0)
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
    if ((stage_v_109_2 & 2) != 0)
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
  int stage_v_165_1 = (helper_flow_7_1 ^ pub_r001277_4_1) & 63;
  int stage_v_165_2 = (helper_flow_7_2 ^ pub_r001277_4_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_129_1 & 2) != 0)
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
    if ((stage_v_129_2 & 2) != 0)
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
  int stage_v_166_1 = ((pub_r001277_1_1 * 2) + 26) & 63;
  int stage_v_166_2 = ((pub_r001277_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (stage_v_156_1 ^ pub_r001277_17_1) & 63;
  int stage_v_167_2 = (stage_v_156_2 ^ pub_r001277_17_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((stage_v_51_1 & 2) != 0)
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
    if ((stage_v_51_2 & 2) != 0)
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
  int stage_v_168_1 = (stage_v_61_1 ^ pub_r001277_17_1) & 63;
  int stage_v_168_2 = (stage_v_61_2 ^ pub_r001277_17_2) & 63;
  if ((stage_v_168_1 & 1) != 0)
  {
    if ((stage_v_144_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_168_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  }
  if ((stage_v_168_2 & 1) != 0)
  {
    if ((stage_v_144_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_168_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  }
  int stage_v_169_1 = (helper_flow_10_1 ^ pub_r001277_0_1) & 63;
  int stage_v_169_2 = (helper_flow_10_2 ^ pub_r001277_0_2) & 63;
  if ((stage_v_169_1 & 1) != 0)
  {
    if ((stage_v_42_1 & 2) != 0)
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
    if ((stage_v_42_2 & 2) != 0)
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
  int stage_v_170_1 = (stage_v_38_1 ^ pub_r001277_19_1) & 63;
  int stage_v_170_2 = (stage_v_38_2 ^ pub_r001277_19_2) & 63;
  if ((stage_v_170_1 & 1) != 0)
  {
    if ((sec_r001277_14_1 & 2) != 0)
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
    if ((sec_r001277_14_2 & 2) != 0)
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
  int stage_v_171_1 = (sec_r001277_2_1 ^ pub_r001277_12_1) & 63;
  int stage_v_171_2 = (sec_r001277_2_2 ^ pub_r001277_12_2) & 63;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((stage_v_165_1 & 2) != 0)
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
    if ((stage_v_165_2 & 2) != 0)
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
  int stage_v_172_1 = (helper_flow_0_1 ^ pub_r001277_8_1) & 63;
  int stage_v_172_2 = (helper_flow_0_2 ^ pub_r001277_8_2) & 63;
  if ((stage_v_172_1 & 1) != 0)
  {
    if ((stage_v_129_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  }
  if ((stage_v_172_2 & 1) != 0)
  {
    if ((stage_v_129_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  }
  int stage_v_173_1 = ((pub_r001277_16_1 * 2) + 11) & 63;
  int stage_v_173_2 = ((pub_r001277_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (stage_v_153_1 ^ pub_r001277_21_1) & 63;
  int stage_v_174_2 = (stage_v_153_2 ^ pub_r001277_21_2) & 63;
  if ((stage_v_174_1 & 1) != 0)
  {
    if ((sec_r001277_8_1 & 2) != 0)
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
    if ((sec_r001277_8_2 & 2) != 0)
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
  int stage_v_175_1 = (stage_v_81_1 ^ pub_r001277_19_1) & 63;
  int stage_v_175_2 = (stage_v_81_2 ^ pub_r001277_19_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((stage_v_115_1 & 2) != 0)
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
    if ((stage_v_115_2 & 2) != 0)
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
  int stage_v_176_1 = (stage_v_80_1 ^ pub_r001277_15_1) & 63;
  int stage_v_176_2 = (stage_v_80_2 ^ pub_r001277_15_2) & 63;
  if ((stage_v_176_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  }
  if ((stage_v_176_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  }
  int stage_v_177_1 = (stage_v_147_1 ^ pub_r001277_12_1) & 63;
  int stage_v_177_2 = (stage_v_147_2 ^ pub_r001277_12_2) & 63;
  if ((stage_v_177_1 & 1) != 0)
  {
    if ((sec_r001277_8_1 & 2) != 0)
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
    if ((sec_r001277_8_2 & 2) != 0)
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
  int stage_v_178_1 = ((pub_r001277_6_1 * 2) + 42) & 63;
  int stage_v_178_2 = ((pub_r001277_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (sec_r001277_10_1 ^ pub_r001277_19_1) & 63;
  int stage_v_179_2 = (sec_r001277_10_2 ^ pub_r001277_19_2) & 63;
  if ((stage_v_179_1 & 1) != 0)
  {
    if ((stage_v_139_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_179_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  }
  if ((stage_v_179_2 & 1) != 0)
  {
    if ((stage_v_139_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_179_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  }
  int stage_v_180_1 = ((pub_r001277_12_1 * 2) + 43) & 63;
  int stage_v_180_2 = ((pub_r001277_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001277_19_1 * 2) + 15) & 63;
  int stage_v_181_2 = ((pub_r001277_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001277_2_1 * 2) + 7) & 63;
  int stage_v_182_2 = ((pub_r001277_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001277_7_1 != sec_r001277_7_2);
  __CPROVER_assume(sec_r001277_3_1 != sec_r001277_3_2);
  __CPROVER_assume(sec_r001277_17_1 != sec_r001277_17_2);
  __CPROVER_assume(pub_r001277_22_1 == pub_r001277_22_2);
  __CPROVER_assume(sec_r001277_0_1 != sec_r001277_0_2);
  __CPROVER_assume(pub_r001277_9_1 == pub_r001277_9_2);
  __CPROVER_assume(sec_r001277_10_1 != sec_r001277_10_2);
  __CPROVER_assume(pub_r001277_14_1 == pub_r001277_14_2);
  __CPROVER_assume(pub_r001277_16_1 == pub_r001277_16_2);
  __CPROVER_assume(sec_r001277_15_1 != sec_r001277_15_2);
  __CPROVER_assume(pub_r001277_13_1 == pub_r001277_13_2);
  __CPROVER_assume(sec_r001277_9_1 != sec_r001277_9_2);
  __CPROVER_assume(pub_r001277_8_1 == pub_r001277_8_2);
  __CPROVER_assume(pub_r001277_4_1 == pub_r001277_4_2);
  __CPROVER_assume(pub_r001277_19_1 == pub_r001277_19_2);
  __CPROVER_assume(sec_r001277_12_1 != sec_r001277_12_2);
  __CPROVER_assume(pub_r001277_11_1 == pub_r001277_11_2);
  __CPROVER_assume(sec_r001277_11_1 != sec_r001277_11_2);
  __CPROVER_assume(sec_r001277_1_1 != sec_r001277_1_2);
  __CPROVER_assume(sec_r001277_18_1 != sec_r001277_18_2);
  __CPROVER_assume(pub_r001277_2_1 == pub_r001277_2_2);
  __CPROVER_assume(pub_r001277_17_1 == pub_r001277_17_2);
  __CPROVER_assume(pub_r001277_12_1 == pub_r001277_12_2);
  __CPROVER_assume(sec_r001277_8_1 != sec_r001277_8_2);
  __CPROVER_assume(sec_r001277_13_1 != sec_r001277_13_2);
  __CPROVER_assume(pub_r001277_0_1 == pub_r001277_0_2);
  __CPROVER_assume(sec_r001277_2_1 != sec_r001277_2_2);
  __CPROVER_assume(sec_r001277_6_1 != sec_r001277_6_2);
  __CPROVER_assume(pub_r001277_3_1 == pub_r001277_3_2);
  __CPROVER_assume(pub_r001277_7_1 == pub_r001277_7_2);
  __CPROVER_assume(pub_r001277_15_1 == pub_r001277_15_2);
  __CPROVER_assume(sec_r001277_4_1 != sec_r001277_4_2);
  __CPROVER_assume(sec_r001277_14_1 != sec_r001277_14_2);
  __CPROVER_assume(pub_r001277_6_1 == pub_r001277_6_2);
  __CPROVER_assume(pub_r001277_20_1 == pub_r001277_20_2);
  __CPROVER_assume(sec_r001277_5_1 != sec_r001277_5_2);
  __CPROVER_assume(pub_r001277_10_1 == pub_r001277_10_2);
  __CPROVER_assume(pub_r001277_21_1 == pub_r001277_21_2);
  __CPROVER_assume(pub_r001277_1_1 == pub_r001277_1_2);
  __CPROVER_assume(pub_r001277_5_1 == pub_r001277_5_2);
  __CPROVER_assume(pub_r001277_18_1 == pub_r001277_18_2);
  __CPROVER_assume(sec_r001277_16_1 != sec_r001277_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.head == st_var_1_2.head);
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
}


