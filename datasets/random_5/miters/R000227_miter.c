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
struct Transaction_R000227_2713_0
{
  int fee;
  int balance;
  int rate;
  int buffer[3];
};
struct SensorNode_R000227_2713_1
{
  int offset;
  unsigned char gain;
  unsigned char reading;
  unsigned char calib;
  int status;
  int buffer[3];
};
struct MatrixBlock_R000227_2713_2
{
  int scale;
  int dim;
  int stride;
  int density;
  unsigned char determinant;
  short trace;
  int buffer[3];
};
union ColorPixel_R000227_2713_0
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
void fn_R000227_2713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st_1 = {0};
  struct Transaction_R000227_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int delta_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_97_1)
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

  switch (delta_97_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_36_1) & 63;
  aux_2 = (aux_2 + coefficient_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_42_1 = local_arr_1[aux_1 % 3];
  int scale_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_42_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_97_1 == delta_97_2);
  assert(coefficient_36_1 == coefficient_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_42_1 == scale_42_2);
}

int fn_R000227_2713_0(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int delta_97 = (aux + st.buffer[1]) & 3;
  switch (delta_97)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_36) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_42 = local_arr[aux % 3];
  acc = (acc + (scale_42 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000227_2713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st_1 = {0};
  struct MatrixBlock_R000227_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int vector_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_45_1) & 63;
  aux_2 = (aux_2 + vector_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_36_1 = local_arr_1[aux_1 % 3];
  int delta_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_45_1 == vector_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_36_1 == delta_36_2);
}

int fn_R000227_2713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int vector_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_45) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_36 = local_arr[aux % 3];
  acc = (acc + (delta_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000227_2713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st_1 = {0};
  struct MatrixBlock_R000227_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_38_1 = local_arr_1[aux_1 % 3];
  int quotient_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_38_2 * 2)) & 127;
  int cursor_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_79_1 > 11)
  {
    acc_1 = ((acc_1 + (cursor_79_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_79_2 > 11)
  {
    acc_2 = ((acc_2 + (cursor_79_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_89_1)
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

  switch (margin_89_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_38_1 == quotient_38_2);
  assert(cursor_79_1 == cursor_79_2);
  assert(margin_89_1 == margin_89_2);
}

int fn_R000227_2713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int quotient_38 = local_arr[aux % 3];
  acc = (acc + (quotient_38 * 2)) & 127;
  int cursor_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_79 > 11)
  {
    acc = ((acc + (cursor_79 * 2)) + 5) & 127;
    aux ^= cursor_79 & 15;
  }
  else
  {
    acc = ((acc - cursor_79) + 11) & 127;
    aux += 3;
  }
  int margin_89 = (aux + st.buffer[1]) & 3;
  switch (margin_89)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000227_2713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st_1 = {0};
  struct Transaction_R000227_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_66_1 = local_arr_1[aux_1 % 3];
  int mask_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_66_2 * 2)) & 127;
  int index_reg_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_36_1 > 17)
  {
    acc_1 = ((acc_1 + (index_reg_36_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_36_2 > 17)
  {
    acc_2 = ((acc_2 + (index_reg_36_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_36_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_66_1 == mask_66_2);
  assert(index_reg_36_1 == index_reg_36_2);
}

int fn_R000227_2713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int mask_66 = local_arr[aux % 3];
  acc = (acc + (mask_66 * 2)) & 127;
  int index_reg_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_36 > 17)
  {
    acc = ((acc + (index_reg_36 * 2)) + 5) & 127;
    aux ^= index_reg_36 & 15;
  }
  else
  {
    acc = ((acc - index_reg_36) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000227_2713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st_1 = {0};
  struct Transaction_R000227_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_69_1 = local_arr_1[aux_1 % 3];
  int tracker_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_69_2 * 2)) & 127;
  int accumulator_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_53_1)
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

  switch (accumulator_53_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_69_1 == tracker_69_2);
  assert(accumulator_53_1 == accumulator_53_2);
}

int fn_R000227_2713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int tracker_69 = local_arr[aux % 3];
  acc = (acc + (tracker_69 * 2)) & 127;
  int accumulator_53 = (aux + st.buffer[1]) & 3;
  switch (accumulator_53)
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

void fn_R000227_2713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st_1 = {0};
  struct Transaction_R000227_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int sample_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_60_1 > 31)
  {
    acc_1 = ((acc_1 + (sample_60_1 * 2)) + 5) & 127;
    aux_1 ^= sample_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_60_2 > 31)
  {
    acc_2 = ((acc_2 + (sample_60_2 * 2)) + 5) & 127;
    aux_2 ^= sample_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_60_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_23_1 = local_arr_1[aux_1 % 3];
  int vector_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_23_2 * 2)) & 127;
  int damping_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_37_1)
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

  switch (damping_37_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_60_1 == sample_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_23_1 == vector_23_2);
  assert(damping_37_1 == damping_37_2);
}

int fn_R000227_2713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int sample_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_60 > 31)
  {
    acc = ((acc + (sample_60 * 2)) + 5) & 127;
    aux ^= sample_60 & 15;
  }
  else
  {
    acc = ((acc - sample_60) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_23 = local_arr[aux % 3];
  acc = (acc + (vector_23 * 2)) & 127;
  int damping_37 = (aux + st.buffer[1]) & 3;
  switch (damping_37)
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

void fn_R000227_2713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st_1 = {0};
  struct MatrixBlock_R000227_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_95_1 = local_arr_1[aux_1 % 3];
  int stride_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_95_2 * 2)) & 127;
  int accumulator_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_18_1 > 23)
  {
    acc_1 = ((acc_1 + (accumulator_18_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_18_2 > 23)
  {
    acc_2 = ((acc_2 + (accumulator_18_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_16_1) & 63;
  aux_2 = (aux_2 + pivot_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_95_1 == stride_95_2);
  assert(accumulator_18_1 == accumulator_18_2);
  assert(pivot_16_1 == pivot_16_2);
}

int fn_R000227_2713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int stride_95 = local_arr[aux % 3];
  acc = (acc + (stride_95 * 2)) & 127;
  int accumulator_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_18 > 23)
  {
    acc = ((acc + (accumulator_18 * 2)) + 5) & 127;
    aux ^= accumulator_18 & 15;
  }
  else
  {
    acc = ((acc - accumulator_18) + 11) & 127;
    aux += 3;
  }
  int pivot_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000227_2713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st_1 = {0};
  struct MatrixBlock_R000227_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int pivot_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_67_1)
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

  switch (pivot_67_2)
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
  int checksum_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_82_1) & 63;
  aux_2 = (aux_2 + checksum_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_32_1 > 29)
  {
    acc_1 = ((acc_1 + (delta_32_1 * 2)) + 5) & 127;
    aux_1 ^= delta_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_32_2 > 29)
  {
    acc_2 = ((acc_2 + (delta_32_2 * 2)) + 5) & 127;
    aux_2 ^= delta_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_67_1 == pivot_67_2);
  assert(checksum_82_1 == checksum_82_2);
  assert(delta_32_1 == delta_32_2);
}

int fn_R000227_2713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int pivot_67 = (aux + st.buffer[1]) & 3;
  switch (pivot_67)
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
  int checksum_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_82) & 63;
  acc ^= aux;
  int delta_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_32 > 29)
  {
    acc = ((acc + (delta_32 * 2)) + 5) & 127;
    aux ^= delta_32 & 15;
  }
  else
  {
    acc = ((acc - delta_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000227_2713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st_1 = {0};
  struct MatrixBlock_R000227_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int checksum_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_36_1) & 63;
  aux_2 = (aux_2 + checksum_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_59_1 > 46)
  {
    acc_1 = ((acc_1 + (offset_59_1 * 2)) + 5) & 127;
    aux_1 ^= offset_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_59_2 > 46)
  {
    acc_2 = ((acc_2 + (offset_59_2 * 2)) + 5) & 127;
    aux_2 ^= offset_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_36_1 == checksum_36_2);
  assert(offset_59_1 == offset_59_2);
}

int fn_R000227_2713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int checksum_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_36) & 63;
  acc ^= aux;
  int offset_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_59 > 46)
  {
    acc = ((acc + (offset_59 * 2)) + 5) & 127;
    aux ^= offset_59 & 15;
  }
  else
  {
    acc = ((acc - offset_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000227_2713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st_1 = {0};
  struct Transaction_R000227_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_87_1 = local_arr_1[aux_1 % 3];
  int factor_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_87_2 * 2)) & 127;
  int pivot_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_38_1)
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

  switch (pivot_38_2)
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

  int scale_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_97_1) & 63;
  aux_2 = (aux_2 + scale_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_73_1 > 33)
  {
    acc_1 = ((acc_1 + (index_reg_73_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_73_2 > 33)
  {
    acc_2 = ((acc_2 + (index_reg_73_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_87_1 == factor_87_2);
  assert(pivot_38_1 == pivot_38_2);
  assert(scale_97_1 == scale_97_2);
  assert(index_reg_73_1 == index_reg_73_2);
}

int fn_R000227_2713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int factor_87 = local_arr[aux % 3];
  acc = (acc + (factor_87 * 2)) & 127;
  int pivot_38 = (aux + st.buffer[1]) & 3;
  switch (pivot_38)
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

  int scale_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_97) & 63;
  acc ^= aux;
  int index_reg_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_73 > 33)
  {
    acc = ((acc + (index_reg_73 * 2)) + 5) & 127;
    aux ^= index_reg_73 & 15;
  }
  else
  {
    acc = ((acc - index_reg_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000227_2713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st_1 = {0};
  struct Transaction_R000227_2713_0 st_2 = {0};
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
  int quotient_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_69_1)
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

  switch (quotient_69_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_69_1 == quotient_69_2);
}

int fn_R000227_2713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_69 = (aux + st.buffer[1]) & 3;
  switch (quotient_69)
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

void fn_R000227_2713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st_1 = {0};
  struct MatrixBlock_R000227_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_89_1)
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

  switch (tracker_89_2)
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

  int factor_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_52_1) & 63;
  aux_2 = (aux_2 + factor_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_71_1 > 29)
  {
    acc_1 = ((acc_1 + (bound_71_1 * 2)) + 5) & 127;
    aux_1 ^= bound_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_71_2 > 29)
  {
    acc_2 = ((acc_2 + (bound_71_2 * 2)) + 5) & 127;
    aux_2 ^= bound_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_71_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_89_1 == tracker_89_2);
  assert(factor_52_1 == factor_52_2);
  assert(bound_71_1 == bound_71_2);
}

int fn_R000227_2713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_89 = (aux + st.buffer[1]) & 3;
  switch (tracker_89)
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

  int factor_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_52) & 63;
  acc ^= aux;
  int bound_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_71 > 29)
  {
    acc = ((acc + (bound_71 * 2)) + 5) & 127;
    aux ^= bound_71 & 15;
  }
  else
  {
    acc = ((acc - bound_71) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000227_2713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st_1 = {0};
  struct MatrixBlock_R000227_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int window_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_40_1 > 36)
  {
    acc_1 = ((acc_1 + (window_40_1 * 2)) + 5) & 127;
    aux_1 ^= window_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_40_2 > 36)
  {
    acc_2 = ((acc_2 + (window_40_2 * 2)) + 5) & 127;
    aux_2 ^= window_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_40_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_62_1) & 63;
  aux_2 = (aux_2 + tally_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_40_1 == window_40_2);
  assert(tally_62_1 == tally_62_2);
}

int fn_R000227_2713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int window_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_40 > 36)
  {
    acc = ((acc + (window_40 * 2)) + 5) & 127;
    aux ^= window_40 & 15;
  }
  else
  {
    acc = ((acc - window_40) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000227_2713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000227_2713_1 st_1 = {0};
  struct SensorNode_R000227_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int scale_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_69_1)
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

  switch (scale_69_2)
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

  int offset_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_54_1) & 63;
  aux_2 = (aux_2 + offset_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_69_1 == scale_69_2);
  assert(offset_54_1 == offset_54_2);
}

int fn_R000227_2713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000227_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int scale_69 = (aux + st.buffer[1]) & 3;
  switch (scale_69)
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

  int offset_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000227_2713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000227_2713_1 st_1 = {0};
  struct SensorNode_R000227_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_27_1 = local_arr_1[aux_1 % 3];
  int pivot_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_27_2 * 2)) & 127;
  int tally_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_43_1) & 63;
  aux_2 = (aux_2 + tally_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_27_1 == pivot_27_2);
  assert(tally_43_1 == tally_43_2);
}

int fn_R000227_2713_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000227_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int pivot_27 = local_arr[aux % 3];
  acc = (acc + (pivot_27 * 2)) & 127;
  int tally_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_43) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000227_2713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st_1 = {0};
  struct Transaction_R000227_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int cursor_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_85_1)
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

  switch (cursor_85_2)
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
  int quotient_45_1 = local_arr_1[aux_1 % 3];
  int quotient_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_85_1 == cursor_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_45_1 == quotient_45_2);
}

int fn_R000227_2713_15(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000227_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int cursor_85 = (aux + st.buffer[1]) & 3;
  switch (cursor_85)
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
  int quotient_45 = local_arr[aux % 3];
  acc = (acc + (quotient_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000227_2713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st_1 = {0};
  struct MatrixBlock_R000227_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int delta_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_97_1 > 28)
  {
    acc_1 = ((acc_1 + (delta_97_1 * 2)) + 5) & 127;
    aux_1 ^= delta_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_97_2 > 28)
  {
    acc_2 = ((acc_2 + (delta_97_2 * 2)) + 5) & 127;
    aux_2 ^= delta_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_65_1) & 63;
  aux_2 = (aux_2 + window_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_30_1)
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

  switch (tally_30_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_97_1 == delta_97_2);
  assert(window_65_1 == window_65_2);
  assert(tally_30_1 == tally_30_2);
}

int fn_R000227_2713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int delta_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_97 > 28)
  {
    acc = ((acc + (delta_97 * 2)) + 5) & 127;
    aux ^= delta_97 & 15;
  }
  else
  {
    acc = ((acc - delta_97) + 11) & 127;
    aux += 3;
  }
  int window_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_65) & 63;
  acc ^= aux;
  int tally_30 = (aux + st.buffer[1]) & 3;
  switch (tally_30)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000227_2713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st_1 = {0};
  struct MatrixBlock_R000227_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int window_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_15_1)
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

  switch (window_15_2)
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

  int accumulator_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_97_1 > 49)
  {
    acc_1 = ((acc_1 + (accumulator_97_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_97_2 > 49)
  {
    acc_2 = ((acc_2 + (accumulator_97_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_15_1 == window_15_2);
  assert(accumulator_97_1 == accumulator_97_2);
}

int fn_R000227_2713_17(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int window_15 = (aux + st.buffer[1]) & 3;
  switch (window_15)
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

  int accumulator_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_97 > 49)
  {
    acc = ((acc + (accumulator_97 * 2)) + 5) & 127;
    aux ^= accumulator_97 & 15;
  }
  else
  {
    acc = ((acc - accumulator_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000227_2713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st_1 = {0};
  struct MatrixBlock_R000227_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int factor_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_21_1 > 36)
  {
    acc_1 = ((acc_1 + (factor_21_1 * 2)) + 5) & 127;
    aux_1 ^= factor_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_21_2 > 36)
  {
    acc_2 = ((acc_2 + (factor_21_2 * 2)) + 5) & 127;
    aux_2 ^= factor_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_21_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_18_1) & 63;
  aux_2 = (aux_2 + parity_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_35_1 = local_arr_1[aux_1 % 3];
  int weight_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_21_1 == factor_21_2);
  assert(parity_18_1 == parity_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_35_1 == weight_35_2);
}

int fn_R000227_2713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int factor_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_21 > 36)
  {
    acc = ((acc + (factor_21 * 2)) + 5) & 127;
    aux ^= factor_21 & 15;
  }
  else
  {
    acc = ((acc - factor_21) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_18) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_35 = local_arr[aux % 3];
  acc = (acc + (weight_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000227_2713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000227_2713_1 st_1 = {0};
  struct SensorNode_R000227_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int tracker_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_59_1 > 43)
  {
    acc_1 = ((acc_1 + (tracker_59_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_59_2 > 43)
  {
    acc_2 = ((acc_2 + (tracker_59_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_74_1) & 63;
  aux_2 = (aux_2 + damping_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_59_1 == tracker_59_2);
  assert(damping_74_1 == damping_74_2);
}

int fn_R000227_2713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000227_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int tracker_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_59 > 43)
  {
    acc = ((acc + (tracker_59 * 2)) + 5) & 127;
    aux ^= tracker_59 & 15;
  }
  else
  {
    acc = ((acc - tracker_59) + 11) & 127;
    aux += 3;
  }
  int damping_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_74) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000227_2713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000227_2713_1 st_1 = {0};
  struct SensorNode_R000227_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_25_1 = local_arr_1[aux_1 % 3];
  int window_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_25_2 * 2)) & 127;
  int mask_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_86_1)
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

  switch (mask_86_2)
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

  int factor_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_72_1) & 63;
  aux_2 = (aux_2 + factor_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_65_1 > 38)
  {
    acc_1 = ((acc_1 + (accumulator_65_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_65_2 > 38)
  {
    acc_2 = ((acc_2 + (accumulator_65_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_65_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_25_1 == window_25_2);
  assert(mask_86_1 == mask_86_2);
  assert(factor_72_1 == factor_72_2);
  assert(accumulator_65_1 == accumulator_65_2);
}

int fn_R000227_2713_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000227_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int window_25 = local_arr[aux % 3];
  acc = (acc + (window_25 * 2)) & 127;
  int mask_86 = (aux + st.buffer[1]) & 3;
  switch (mask_86)
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

  int factor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_72) & 63;
  acc ^= aux;
  int accumulator_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_65 > 38)
  {
    acc = ((acc + (accumulator_65 * 2)) + 5) & 127;
    aux ^= accumulator_65 & 15;
  }
  else
  {
    acc = ((acc - accumulator_65) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000227_2713_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st_1 = {0};
  struct MatrixBlock_R000227_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int vector_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_86_1)
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

  switch (vector_86_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_86_1 == vector_86_2);
}

int fn_R000227_2713_21(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000227_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int vector_86 = (aux + st.buffer[1]) & 3;
  switch (vector_86)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000227_2713_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000227_2713_1 st_1 = {0};
  struct SensorNode_R000227_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_93_1 = local_arr_1[aux_1 % 3];
  int threshold_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_93_2 * 2)) & 127;
  int delta_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_35_1) & 63;
  aux_2 = (aux_2 + delta_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_55_1)
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

  switch (scale_55_2)
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

  int window_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_92_1 > 30)
  {
    acc_1 = ((acc_1 + (window_92_1 * 2)) + 5) & 127;
    aux_1 ^= window_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_92_2 > 30)
  {
    acc_2 = ((acc_2 + (window_92_2 * 2)) + 5) & 127;
    aux_2 ^= window_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_93_1 == threshold_93_2);
  assert(delta_35_1 == delta_35_2);
  assert(scale_55_1 == scale_55_2);
  assert(window_92_1 == window_92_2);
}

int fn_R000227_2713_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000227_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int threshold_93 = local_arr[aux % 3];
  acc = (acc + (threshold_93 * 2)) & 127;
  int delta_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_35) & 63;
  acc ^= aux;
  int scale_55 = (aux + st.buffer[1]) & 3;
  switch (scale_55)
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

  int window_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_92 > 30)
  {
    acc = ((acc + (window_92 * 2)) + 5) & 127;
    aux ^= window_92 & 15;
  }
  else
  {
    acc = ((acc - window_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000227_0_1;
  int sec_r000227_0_2;
  int sec_r000227_1_1;
  int sec_r000227_1_2;
  int sec_r000227_2_1;
  int sec_r000227_2_2;
  int sec_r000227_3_1;
  int sec_r000227_3_2;
  int sec_r000227_4_1;
  int sec_r000227_4_2;
  int sec_r000227_5_1;
  int sec_r000227_5_2;
  int sec_r000227_6_1;
  int sec_r000227_6_2;
  int sec_r000227_7_1;
  int sec_r000227_7_2;
  int sec_r000227_8_1;
  int sec_r000227_8_2;
  int sec_r000227_9_1;
  int sec_r000227_9_2;
  int sec_r000227_10_1;
  int sec_r000227_10_2;
  int sec_r000227_11_1;
  int sec_r000227_11_2;
  int sec_r000227_12_1;
  int sec_r000227_12_2;
  int sec_r000227_13_1;
  int sec_r000227_13_2;
  int sec_r000227_14_1;
  int sec_r000227_14_2;
  int sec_r000227_15_1;
  int sec_r000227_15_2;
  int sec_r000227_16_1;
  int sec_r000227_16_2;
  int sec_r000227_17_1;
  int sec_r000227_17_2;
  int sec_r000227_18_1;
  int sec_r000227_18_2;
  int sec_r000227_19_1;
  int sec_r000227_19_2;
  int pub_r000227_0_1;
  int pub_r000227_0_2;
  int pub_r000227_1_1;
  int pub_r000227_1_2;
  int pub_r000227_2_1;
  int pub_r000227_2_2;
  int pub_r000227_3_1;
  int pub_r000227_3_2;
  int pub_r000227_4_1;
  int pub_r000227_4_2;
  int pub_r000227_5_1;
  int pub_r000227_5_2;
  int pub_r000227_6_1;
  int pub_r000227_6_2;
  int pub_r000227_7_1;
  int pub_r000227_7_2;
  int pub_r000227_8_1;
  int pub_r000227_8_2;
  int pub_r000227_9_1;
  int pub_r000227_9_2;
  int pub_r000227_10_1;
  int pub_r000227_10_2;
  int pub_r000227_11_1;
  int pub_r000227_11_2;
  int pub_r000227_12_1;
  int pub_r000227_12_2;
  int pub_r000227_13_1;
  int pub_r000227_13_2;
  int pub_r000227_14_1;
  int pub_r000227_14_2;
  int pub_r000227_15_1;
  int pub_r000227_15_2;
  int pub_r000227_16_1;
  int pub_r000227_16_2;
  int pub_r000227_17_1;
  int pub_r000227_17_2;
  int pub_r000227_18_1;
  int pub_r000227_18_2;
  int pub_r000227_19_1;
  int pub_r000227_19_2;
  int pub_r000227_20_1;
  int pub_r000227_20_2;
  int pub_r000227_21_1;
  int pub_r000227_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000227_0_1 >= (-100)) && (pub_r000227_0_1 <= 100));
  __CPROVER_assume((pub_r000227_0_2 >= (-100)) && (pub_r000227_0_2 <= 100));
  __CPROVER_assume((pub_r000227_1_1 >= (-100)) && (pub_r000227_1_1 <= 100));
  __CPROVER_assume((pub_r000227_1_2 >= (-100)) && (pub_r000227_1_2 <= 100));
  __CPROVER_assume((pub_r000227_2_1 >= (-100)) && (pub_r000227_2_1 <= 100));
  __CPROVER_assume((pub_r000227_2_2 >= (-100)) && (pub_r000227_2_2 <= 100));
  __CPROVER_assume((pub_r000227_3_1 >= (-100)) && (pub_r000227_3_1 <= 100));
  __CPROVER_assume((pub_r000227_3_2 >= (-100)) && (pub_r000227_3_2 <= 100));
  __CPROVER_assume((pub_r000227_4_1 >= (-100)) && (pub_r000227_4_1 <= 100));
  __CPROVER_assume((pub_r000227_4_2 >= (-100)) && (pub_r000227_4_2 <= 100));
  __CPROVER_assume((pub_r000227_5_1 >= (-100)) && (pub_r000227_5_1 <= 100));
  __CPROVER_assume((pub_r000227_5_2 >= (-100)) && (pub_r000227_5_2 <= 100));
  __CPROVER_assume((pub_r000227_6_1 >= (-100)) && (pub_r000227_6_1 <= 100));
  __CPROVER_assume((pub_r000227_6_2 >= (-100)) && (pub_r000227_6_2 <= 100));
  __CPROVER_assume((pub_r000227_7_1 >= (-100)) && (pub_r000227_7_1 <= 100));
  __CPROVER_assume((pub_r000227_7_2 >= (-100)) && (pub_r000227_7_2 <= 100));
  __CPROVER_assume((pub_r000227_8_1 >= (-100)) && (pub_r000227_8_1 <= 100));
  __CPROVER_assume((pub_r000227_8_2 >= (-100)) && (pub_r000227_8_2 <= 100));
  __CPROVER_assume((pub_r000227_9_1 >= (-100)) && (pub_r000227_9_1 <= 100));
  __CPROVER_assume((pub_r000227_9_2 >= (-100)) && (pub_r000227_9_2 <= 100));
  __CPROVER_assume((pub_r000227_10_1 >= (-100)) && (pub_r000227_10_1 <= 100));
  __CPROVER_assume((pub_r000227_10_2 >= (-100)) && (pub_r000227_10_2 <= 100));
  __CPROVER_assume((pub_r000227_11_1 >= (-100)) && (pub_r000227_11_1 <= 100));
  __CPROVER_assume((pub_r000227_11_2 >= (-100)) && (pub_r000227_11_2 <= 100));
  __CPROVER_assume((pub_r000227_12_1 >= (-100)) && (pub_r000227_12_1 <= 100));
  __CPROVER_assume((pub_r000227_12_2 >= (-100)) && (pub_r000227_12_2 <= 100));
  __CPROVER_assume((pub_r000227_13_1 >= (-100)) && (pub_r000227_13_1 <= 100));
  __CPROVER_assume((pub_r000227_13_2 >= (-100)) && (pub_r000227_13_2 <= 100));
  __CPROVER_assume((pub_r000227_14_1 >= (-100)) && (pub_r000227_14_1 <= 100));
  __CPROVER_assume((pub_r000227_14_2 >= (-100)) && (pub_r000227_14_2 <= 100));
  __CPROVER_assume((pub_r000227_15_1 >= (-100)) && (pub_r000227_15_1 <= 100));
  __CPROVER_assume((pub_r000227_15_2 >= (-100)) && (pub_r000227_15_2 <= 100));
  __CPROVER_assume((pub_r000227_16_1 >= (-100)) && (pub_r000227_16_1 <= 100));
  __CPROVER_assume((pub_r000227_16_2 >= (-100)) && (pub_r000227_16_2 <= 100));
  __CPROVER_assume((pub_r000227_17_1 >= (-100)) && (pub_r000227_17_1 <= 100));
  __CPROVER_assume((pub_r000227_17_2 >= (-100)) && (pub_r000227_17_2 <= 100));
  __CPROVER_assume((pub_r000227_18_1 >= (-100)) && (pub_r000227_18_1 <= 100));
  __CPROVER_assume((pub_r000227_18_2 >= (-100)) && (pub_r000227_18_2 <= 100));
  __CPROVER_assume((pub_r000227_19_1 >= (-100)) && (pub_r000227_19_1 <= 100));
  __CPROVER_assume((pub_r000227_19_2 >= (-100)) && (pub_r000227_19_2 <= 100));
  __CPROVER_assume((pub_r000227_20_1 >= (-100)) && (pub_r000227_20_1 <= 100));
  __CPROVER_assume((pub_r000227_20_2 >= (-100)) && (pub_r000227_20_2 <= 100));
  __CPROVER_assume((pub_r000227_21_1 >= (-100)) && (pub_r000227_21_1 <= 100));
  __CPROVER_assume((pub_r000227_21_2 >= (-100)) && (pub_r000227_21_2 <= 100));
  __CPROVER_assume((sec_r000227_0_1 >= 0) && (sec_r000227_0_1 <= 255));
  __CPROVER_assume((sec_r000227_0_2 >= 0) && (sec_r000227_0_2 <= 255));
  __CPROVER_assume((sec_r000227_1_1 >= 0) && (sec_r000227_1_1 <= 255));
  __CPROVER_assume((sec_r000227_1_2 >= 0) && (sec_r000227_1_2 <= 255));
  __CPROVER_assume((sec_r000227_2_1 >= 0) && (sec_r000227_2_1 <= 255));
  __CPROVER_assume((sec_r000227_2_2 >= 0) && (sec_r000227_2_2 <= 255));
  __CPROVER_assume((sec_r000227_3_1 >= 0) && (sec_r000227_3_1 <= 255));
  __CPROVER_assume((sec_r000227_3_2 >= 0) && (sec_r000227_3_2 <= 255));
  __CPROVER_assume((sec_r000227_4_1 >= 0) && (sec_r000227_4_1 <= 255));
  __CPROVER_assume((sec_r000227_4_2 >= 0) && (sec_r000227_4_2 <= 255));
  __CPROVER_assume((sec_r000227_5_1 >= 0) && (sec_r000227_5_1 <= 255));
  __CPROVER_assume((sec_r000227_5_2 >= 0) && (sec_r000227_5_2 <= 255));
  __CPROVER_assume((sec_r000227_6_1 >= 0) && (sec_r000227_6_1 <= 255));
  __CPROVER_assume((sec_r000227_6_2 >= 0) && (sec_r000227_6_2 <= 255));
  __CPROVER_assume((sec_r000227_7_1 >= 0) && (sec_r000227_7_1 <= 255));
  __CPROVER_assume((sec_r000227_7_2 >= 0) && (sec_r000227_7_2 <= 255));
  __CPROVER_assume((sec_r000227_8_1 >= 0) && (sec_r000227_8_1 <= 255));
  __CPROVER_assume((sec_r000227_8_2 >= 0) && (sec_r000227_8_2 <= 255));
  __CPROVER_assume((sec_r000227_9_1 >= 0) && (sec_r000227_9_1 <= 255));
  __CPROVER_assume((sec_r000227_9_2 >= 0) && (sec_r000227_9_2 <= 255));
  __CPROVER_assume((sec_r000227_10_1 >= 0) && (sec_r000227_10_1 <= 255));
  __CPROVER_assume((sec_r000227_10_2 >= 0) && (sec_r000227_10_2 <= 255));
  __CPROVER_assume((sec_r000227_11_1 >= 0) && (sec_r000227_11_1 <= 255));
  __CPROVER_assume((sec_r000227_11_2 >= 0) && (sec_r000227_11_2 <= 255));
  __CPROVER_assume((sec_r000227_12_1 >= 0) && (sec_r000227_12_1 <= 255));
  __CPROVER_assume((sec_r000227_12_2 >= 0) && (sec_r000227_12_2 <= 255));
  __CPROVER_assume((sec_r000227_13_1 >= 0) && (sec_r000227_13_1 <= 255));
  __CPROVER_assume((sec_r000227_13_2 >= 0) && (sec_r000227_13_2 <= 255));
  __CPROVER_assume((sec_r000227_14_1 >= 0) && (sec_r000227_14_1 <= 255));
  __CPROVER_assume((sec_r000227_14_2 >= 0) && (sec_r000227_14_2 <= 255));
  __CPROVER_assume((sec_r000227_15_1 >= 0) && (sec_r000227_15_1 <= 255));
  __CPROVER_assume((sec_r000227_15_2 >= 0) && (sec_r000227_15_2 <= 255));
  __CPROVER_assume((sec_r000227_16_1 >= 0) && (sec_r000227_16_1 <= 255));
  __CPROVER_assume((sec_r000227_16_2 >= 0) && (sec_r000227_16_2 <= 255));
  __CPROVER_assume((sec_r000227_17_1 >= 0) && (sec_r000227_17_1 <= 255));
  __CPROVER_assume((sec_r000227_17_2 >= 0) && (sec_r000227_17_2 <= 255));
  __CPROVER_assume((sec_r000227_18_1 >= 0) && (sec_r000227_18_1 <= 255));
  __CPROVER_assume((sec_r000227_18_2 >= 0) && (sec_r000227_18_2 <= 255));
  __CPROVER_assume((sec_r000227_19_1 >= 0) && (sec_r000227_19_1 <= 255));
  __CPROVER_assume((sec_r000227_19_2 >= 0) && (sec_r000227_19_2 <= 255));
  struct Transaction_R000227_2713_0 st_var_0_1 = {0};
  struct Transaction_R000227_2713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000227_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000227_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000227_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000227_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000227_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000227_0_2 + 7) & 15;
  struct SensorNode_R000227_2713_1 st_var_1_1 = {0};
  struct SensorNode_R000227_2713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000227_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000227_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000227_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000227_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000227_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000227_0_2 + 9) & 15;
  struct MatrixBlock_R000227_2713_2 st_var_2_1 = {0};
  struct MatrixBlock_R000227_2713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000227_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000227_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000227_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000227_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000227_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000227_0_2 + 11) & 15;
  union ColorPixel_R000227_2713_0 u_var_1;
  union ColorPixel_R000227_2713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 31)
    {
      chk_sum_1 ^= stage_v_2_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_2_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 31)
    {
      chk_sum_2 ^= stage_v_2_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
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
  int stage_v_5_1 = ((st_var_2_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_2_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 46)
    {
      chk_sum_1 ^= stage_v_5_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_5_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 46)
    {
      chk_sum_2 ^= stage_v_5_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = ((st_var_2_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_2_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 50)
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
  if (stage_v_8_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 50)
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
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  if ((sec_r000227_3_1 & 1) != 0)
  {
    if ((sec_r000227_5_1 & 2) != 0)
    {
      stage_v_9_1 = (pub_r000227_5_1 + 31) & 127;
    }
    else
    {
      stage_v_9_1 = (pub_r000227_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_9_1 = (pub_r000227_5_1 + 7) & 127;
  }
  if ((sec_r000227_3_2 & 1) != 0)
  {
    if ((sec_r000227_5_2 & 2) != 0)
    {
      stage_v_9_2 = (pub_r000227_5_2 + 31) & 127;
    }
    else
    {
      stage_v_9_2 = (pub_r000227_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_9_2 = (pub_r000227_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((sec_r000227_13_1 & 2) != 0)
    {
      stage_v_10_1 = (pub_r000227_16_1 + 31) & 127;
    }
    else
    {
      stage_v_10_1 = (pub_r000227_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_10_1 = (pub_r000227_16_1 + 7) & 127;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((sec_r000227_13_2 & 2) != 0)
    {
      stage_v_10_2 = (pub_r000227_16_2 + 31) & 127;
    }
    else
    {
      stage_v_10_2 = (pub_r000227_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_10_2 = (pub_r000227_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((sec_r000227_1_1 & 2) != 0)
    {
      stage_v_11_1 = (pub_r000227_2_1 + 31) & 127;
    }
    else
    {
      stage_v_11_1 = (pub_r000227_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_11_1 = (pub_r000227_2_1 + 7) & 127;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((sec_r000227_1_2 & 2) != 0)
    {
      stage_v_11_2 = (pub_r000227_2_2 + 31) & 127;
    }
    else
    {
      stage_v_11_2 = (pub_r000227_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_11_2 = (pub_r000227_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  if ((sec_r000227_2_1 & 1) != 0)
  {
    if ((sec_r000227_4_1 & 2) != 0)
    {
      stage_v_12_1 = (pub_r000227_14_1 + 31) & 127;
    }
    else
    {
      stage_v_12_1 = (pub_r000227_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_12_1 = (pub_r000227_14_1 + 7) & 127;
  }
  if ((sec_r000227_2_2 & 1) != 0)
  {
    if ((sec_r000227_4_2 & 2) != 0)
    {
      stage_v_12_2 = (pub_r000227_14_2 + 31) & 127;
    }
    else
    {
      stage_v_12_2 = (pub_r000227_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_12_2 = (pub_r000227_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((sec_r000227_2_1 & 2) != 0)
    {
      stage_v_13_1 = (pub_r000227_2_1 + 31) & 127;
    }
    else
    {
      stage_v_13_1 = (pub_r000227_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_13_1 = (pub_r000227_2_1 + 7) & 127;
  }
  if ((stage_v_10_2 & 1) != 0)
  {
    if ((sec_r000227_2_2 & 2) != 0)
    {
      stage_v_13_2 = (pub_r000227_2_2 + 31) & 127;
    }
    else
    {
      stage_v_13_2 = (pub_r000227_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_13_2 = (pub_r000227_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  if ((sec_r000227_6_1 & 1) != 0)
  {
    if ((sec_r000227_13_1 & 2) != 0)
    {
      stage_v_14_1 = (pub_r000227_6_1 + 31) & 127;
    }
    else
    {
      stage_v_14_1 = (pub_r000227_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_14_1 = (pub_r000227_6_1 + 7) & 127;
  }
  if ((sec_r000227_6_2 & 1) != 0)
  {
    if ((sec_r000227_13_2 & 2) != 0)
    {
      stage_v_14_2 = (pub_r000227_6_2 + 31) & 127;
    }
    else
    {
      stage_v_14_2 = (pub_r000227_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_14_2 = (pub_r000227_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r000227_0_1 & 2) != 0)
    {
      stage_v_15_1 = (pub_r000227_3_1 + 31) & 127;
    }
    else
    {
      stage_v_15_1 = (pub_r000227_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_15_1 = (pub_r000227_3_1 + 7) & 127;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((sec_r000227_0_2 & 2) != 0)
    {
      stage_v_15_2 = (pub_r000227_3_2 + 31) & 127;
    }
    else
    {
      stage_v_15_2 = (pub_r000227_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_15_2 = (pub_r000227_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((sec_r000227_5_1 & 2) != 0)
    {
      stage_v_16_1 = (pub_r000227_3_1 + 31) & 127;
    }
    else
    {
      stage_v_16_1 = (pub_r000227_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_16_1 = (pub_r000227_3_1 + 7) & 127;
  }
  if ((stage_v_11_2 & 1) != 0)
  {
    if ((sec_r000227_5_2 & 2) != 0)
    {
      stage_v_16_2 = (pub_r000227_3_2 + 31) & 127;
    }
    else
    {
      stage_v_16_2 = (pub_r000227_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_16_2 = (pub_r000227_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  if ((sec_r000227_15_1 & 1) != 0)
  {
    if ((sec_r000227_2_1 & 2) != 0)
    {
      stage_v_17_1 = (pub_r000227_17_1 + 31) & 127;
    }
    else
    {
      stage_v_17_1 = (pub_r000227_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_17_1 = (pub_r000227_17_1 + 7) & 127;
  }
  if ((sec_r000227_15_2 & 1) != 0)
  {
    if ((sec_r000227_2_2 & 2) != 0)
    {
      stage_v_17_2 = (pub_r000227_17_2 + 31) & 127;
    }
    else
    {
      stage_v_17_2 = (pub_r000227_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_17_2 = (pub_r000227_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  if ((sec_r000227_6_1 & 1) != 0)
  {
    if ((sec_r000227_5_1 & 2) != 0)
    {
      stage_v_18_1 = (pub_r000227_10_1 + 31) & 127;
    }
    else
    {
      stage_v_18_1 = (pub_r000227_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_18_1 = (pub_r000227_10_1 + 7) & 127;
  }
  if ((sec_r000227_6_2 & 1) != 0)
  {
    if ((sec_r000227_5_2 & 2) != 0)
    {
      stage_v_18_2 = (pub_r000227_10_2 + 31) & 127;
    }
    else
    {
      stage_v_18_2 = (pub_r000227_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_18_2 = (pub_r000227_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((sec_r000227_13_1 & 2) != 0)
    {
      stage_v_19_1 = (pub_r000227_10_1 + 31) & 127;
    }
    else
    {
      stage_v_19_1 = (pub_r000227_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_1 = (pub_r000227_10_1 + 7) & 127;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((sec_r000227_13_2 & 2) != 0)
    {
      stage_v_19_2 = (pub_r000227_10_2 + 31) & 127;
    }
    else
    {
      stage_v_19_2 = (pub_r000227_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_2 = (pub_r000227_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  if ((sec_r000227_13_1 & 1) != 0)
  {
    if ((sec_r000227_9_1 & 2) != 0)
    {
      stage_v_20_1 = (pub_r000227_16_1 + 31) & 127;
    }
    else
    {
      stage_v_20_1 = (pub_r000227_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_1 = (pub_r000227_16_1 + 7) & 127;
  }
  if ((sec_r000227_13_2 & 1) != 0)
  {
    if ((sec_r000227_9_2 & 2) != 0)
    {
      stage_v_20_2 = (pub_r000227_16_2 + 31) & 127;
    }
    else
    {
      stage_v_20_2 = (pub_r000227_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_2 = (pub_r000227_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000227_18_1 & 2) != 0)
    {
      stage_v_21_1 = (pub_r000227_5_1 + 31) & 127;
    }
    else
    {
      stage_v_21_1 = (pub_r000227_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_1 = (pub_r000227_5_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000227_18_2 & 2) != 0)
    {
      stage_v_21_2 = (pub_r000227_5_2 + 31) & 127;
    }
    else
    {
      stage_v_21_2 = (pub_r000227_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_2 = (pub_r000227_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000227_5_1 & 2) != 0)
    {
      stage_v_22_1 = (pub_r000227_19_1 + 31) & 127;
    }
    else
    {
      stage_v_22_1 = (pub_r000227_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_1 = (pub_r000227_19_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000227_5_2 & 2) != 0)
    {
      stage_v_22_2 = (pub_r000227_19_2 + 31) & 127;
    }
    else
    {
      stage_v_22_2 = (pub_r000227_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_2 = (pub_r000227_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  if ((sec_r000227_8_1 & 1) != 0)
  {
    if ((sec_r000227_16_1 & 2) != 0)
    {
      stage_v_23_1 = (pub_r000227_2_1 + 31) & 127;
    }
    else
    {
      stage_v_23_1 = (pub_r000227_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_1 = (pub_r000227_2_1 + 7) & 127;
  }
  if ((sec_r000227_8_2 & 1) != 0)
  {
    if ((sec_r000227_16_2 & 2) != 0)
    {
      stage_v_23_2 = (pub_r000227_2_2 + 31) & 127;
    }
    else
    {
      stage_v_23_2 = (pub_r000227_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_2 = (pub_r000227_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000227_14_1 & 2) != 0)
    {
      stage_v_24_1 = (pub_r000227_7_1 + 31) & 127;
    }
    else
    {
      stage_v_24_1 = (pub_r000227_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_1 = (pub_r000227_7_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000227_14_2 & 2) != 0)
    {
      stage_v_24_2 = (pub_r000227_7_2 + 31) & 127;
    }
    else
    {
      stage_v_24_2 = (pub_r000227_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_2 = (pub_r000227_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((sec_r000227_5_1 & 2) != 0)
    {
      stage_v_25_1 = (pub_r000227_12_1 + 31) & 127;
    }
    else
    {
      stage_v_25_1 = (pub_r000227_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_1 = (pub_r000227_12_1 + 7) & 127;
  }
  if ((stage_v_12_2 & 1) != 0)
  {
    if ((sec_r000227_5_2 & 2) != 0)
    {
      stage_v_25_2 = (pub_r000227_12_2 + 31) & 127;
    }
    else
    {
      stage_v_25_2 = (pub_r000227_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_2 = (pub_r000227_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((sec_r000227_9_1 & 1) != 0)
  {
    if ((sec_r000227_6_1 & 2) != 0)
    {
      stage_v_26_1 = (pub_r000227_18_1 + 31) & 127;
    }
    else
    {
      stage_v_26_1 = (pub_r000227_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_1 = (pub_r000227_18_1 + 7) & 127;
  }
  if ((sec_r000227_9_2 & 1) != 0)
  {
    if ((sec_r000227_6_2 & 2) != 0)
    {
      stage_v_26_2 = (pub_r000227_18_2 + 31) & 127;
    }
    else
    {
      stage_v_26_2 = (pub_r000227_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_2 = (pub_r000227_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000227_6_1 & 2) != 0)
    {
      stage_v_27_1 = (pub_r000227_15_1 + 31) & 127;
    }
    else
    {
      stage_v_27_1 = (pub_r000227_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_1 = (pub_r000227_15_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000227_6_2 & 2) != 0)
    {
      stage_v_27_2 = (pub_r000227_15_2 + 31) & 127;
    }
    else
    {
      stage_v_27_2 = (pub_r000227_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_2 = (pub_r000227_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000227_12_1 & 2) != 0)
    {
      stage_v_28_1 = (pub_r000227_9_1 + 31) & 127;
    }
    else
    {
      stage_v_28_1 = (pub_r000227_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_1 = (pub_r000227_9_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000227_12_2 & 2) != 0)
    {
      stage_v_28_2 = (pub_r000227_9_2 + 31) & 127;
    }
    else
    {
      stage_v_28_2 = (pub_r000227_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_2 = (pub_r000227_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((sec_r000227_10_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000227_17_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000227_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000227_17_1 + 7) & 127;
  }
  if ((stage_v_11_2 & 1) != 0)
  {
    if ((sec_r000227_10_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000227_17_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000227_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000227_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((sec_r000227_11_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000227_10_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000227_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000227_10_1 + 7) & 127;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((sec_r000227_11_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000227_10_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000227_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000227_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000227_15_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000227_5_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000227_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000227_5_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000227_15_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000227_5_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000227_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000227_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000227_14_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000227_10_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000227_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000227_10_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000227_14_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000227_10_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000227_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000227_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000227_1_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000227_7_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000227_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000227_7_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000227_1_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000227_7_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000227_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000227_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000227_14_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000227_13_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000227_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000227_13_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000227_14_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000227_13_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000227_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000227_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((sec_r000227_4_1 & 1) != 0)
  {
    if ((sec_r000227_14_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000227_16_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000227_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000227_16_1 + 7) & 127;
  }
  if ((sec_r000227_4_2 & 1) != 0)
  {
    if ((sec_r000227_14_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000227_16_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000227_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000227_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r000227_9_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000227_15_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000227_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000227_15_1 + 7) & 127;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r000227_9_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000227_15_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000227_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000227_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((sec_r000227_5_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000227_1_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000227_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000227_1_1 + 7) & 127;
  }
  if ((stage_v_10_2 & 1) != 0)
  {
    if ((sec_r000227_5_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000227_1_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000227_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000227_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000227_12_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000227_12_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000227_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000227_12_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000227_12_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000227_12_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000227_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000227_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((sec_r000227_9_1 & 1) != 0)
  {
    if ((sec_r000227_0_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000227_18_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000227_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000227_18_1 + 7) & 127;
  }
  if ((sec_r000227_9_2 & 1) != 0)
  {
    if ((sec_r000227_0_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000227_18_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000227_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000227_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000227_13_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000227_4_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000227_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000227_4_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000227_13_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000227_4_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000227_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000227_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((sec_r000227_7_1 & 1) != 0)
  {
    if ((sec_r000227_13_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000227_21_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000227_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000227_21_1 + 7) & 127;
  }
  if ((sec_r000227_7_2 & 1) != 0)
  {
    if ((sec_r000227_13_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000227_21_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000227_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000227_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000227_13_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000227_0_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000227_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000227_0_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000227_13_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000227_0_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000227_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000227_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000227_6_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000227_3_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000227_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000227_3_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000227_6_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000227_3_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000227_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000227_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((sec_r000227_16_1 & 1) != 0)
  {
    if ((sec_r000227_17_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000227_18_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000227_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000227_18_1 + 7) & 127;
  }
  if ((sec_r000227_16_2 & 1) != 0)
  {
    if ((sec_r000227_17_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000227_18_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000227_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000227_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000227_11_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000227_5_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000227_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000227_5_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000227_11_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000227_5_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000227_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000227_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000227_11_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000227_2_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000227_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000227_2_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000227_11_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000227_2_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000227_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000227_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((sec_r000227_10_1 & 1) != 0)
  {
    if ((sec_r000227_16_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000227_12_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000227_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000227_12_1 + 7) & 127;
  }
  if ((sec_r000227_10_2 & 1) != 0)
  {
    if ((sec_r000227_16_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000227_12_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000227_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000227_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((sec_r000227_16_1 & 1) != 0)
  {
    if ((sec_r000227_8_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000227_18_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000227_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000227_18_1 + 7) & 127;
  }
  if ((sec_r000227_16_2 & 1) != 0)
  {
    if ((sec_r000227_8_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000227_18_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000227_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000227_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((sec_r000227_2_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000227_9_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000227_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000227_9_1 + 7) & 127;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((sec_r000227_2_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000227_9_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000227_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000227_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((sec_r000227_8_1 & 1) != 0)
  {
    if ((sec_r000227_15_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000227_19_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000227_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000227_19_1 + 7) & 127;
  }
  if ((sec_r000227_8_2 & 1) != 0)
  {
    if ((sec_r000227_15_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000227_19_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000227_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000227_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((sec_r000227_3_1 & 1) != 0)
  {
    if ((sec_r000227_0_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000227_14_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000227_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000227_14_1 + 7) & 127;
  }
  if ((sec_r000227_3_2 & 1) != 0)
  {
    if ((sec_r000227_0_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000227_14_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000227_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000227_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000227_18_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000227_0_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000227_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000227_0_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000227_18_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000227_0_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000227_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000227_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000227_19_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000227_1_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000227_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000227_1_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000227_19_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000227_1_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000227_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000227_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000227_11_1 & 1) != 0)
  {
    if ((sec_r000227_9_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000227_0_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000227_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000227_0_1 + 7) & 127;
  }
  if ((sec_r000227_11_2 & 1) != 0)
  {
    if ((sec_r000227_9_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000227_0_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000227_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000227_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((sec_r000227_11_1 & 1) != 0)
  {
    if ((sec_r000227_5_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000227_2_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000227_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000227_2_1 + 7) & 127;
  }
  if ((sec_r000227_11_2 & 1) != 0)
  {
    if ((sec_r000227_5_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000227_2_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000227_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000227_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000227_12_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000227_21_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000227_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000227_21_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000227_12_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000227_21_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000227_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000227_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((sec_r000227_4_1 & 1) != 0)
  {
    if ((sec_r000227_3_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000227_4_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000227_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000227_4_1 + 7) & 127;
  }
  if ((sec_r000227_4_2 & 1) != 0)
  {
    if ((sec_r000227_3_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000227_4_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000227_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000227_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000227_18_1 & 1) != 0)
  {
    if ((sec_r000227_7_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000227_12_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000227_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000227_12_1 + 7) & 127;
  }
  if ((sec_r000227_18_2 & 1) != 0)
  {
    if ((sec_r000227_7_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000227_12_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000227_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000227_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((sec_r000227_12_1 & 1) != 0)
  {
    if ((sec_r000227_7_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000227_12_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000227_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000227_12_1 + 7) & 127;
  }
  if ((sec_r000227_12_2 & 1) != 0)
  {
    if ((sec_r000227_7_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000227_12_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000227_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000227_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000227_6_1 & 1) != 0)
  {
    if ((sec_r000227_17_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000227_5_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000227_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000227_5_1 + 7) & 127;
  }
  if ((sec_r000227_6_2 & 1) != 0)
  {
    if ((sec_r000227_17_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000227_5_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000227_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000227_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((sec_r000227_14_1 & 1) != 0)
  {
    if ((sec_r000227_14_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000227_13_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000227_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000227_13_1 + 7) & 127;
  }
  if ((sec_r000227_14_2 & 1) != 0)
  {
    if ((sec_r000227_14_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000227_13_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000227_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000227_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000227_15_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000227_9_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000227_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000227_9_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000227_15_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000227_9_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000227_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000227_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000227_6_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000227_6_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000227_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000227_6_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000227_6_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000227_6_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000227_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000227_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r000227_4_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000227_6_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000227_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000227_6_1 + 7) & 127;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r000227_4_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000227_6_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000227_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000227_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000227_16_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000227_12_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000227_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000227_12_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000227_16_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000227_12_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000227_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000227_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000227_12_1 & 1) != 0)
  {
    if ((sec_r000227_10_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000227_21_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000227_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000227_21_1 + 7) & 127;
  }
  if ((sec_r000227_12_2 & 1) != 0)
  {
    if ((sec_r000227_10_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000227_21_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000227_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000227_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000227_9_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000227_15_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000227_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000227_15_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000227_9_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000227_15_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000227_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000227_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((sec_r000227_14_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000227_17_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000227_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000227_17_1 + 7) & 127;
  }
  if ((stage_v_12_2 & 1) != 0)
  {
    if ((sec_r000227_14_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000227_17_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000227_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000227_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000227_11_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000227_12_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000227_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000227_12_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000227_11_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000227_12_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000227_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000227_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000227_15_1 & 1) != 0)
  {
    if ((sec_r000227_0_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000227_1_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000227_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000227_1_1 + 7) & 127;
  }
  if ((sec_r000227_15_2 & 1) != 0)
  {
    if ((sec_r000227_0_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000227_1_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000227_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000227_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000227_9_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000227_10_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000227_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000227_10_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000227_9_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000227_10_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000227_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000227_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((sec_r000227_1_1 & 1) != 0)
  {
    if ((sec_r000227_4_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000227_11_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000227_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000227_11_1 + 7) & 127;
  }
  if ((sec_r000227_1_2 & 1) != 0)
  {
    if ((sec_r000227_4_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000227_11_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000227_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000227_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000227_14_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000227_16_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000227_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000227_16_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000227_14_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000227_16_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000227_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000227_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000227_6_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000227_15_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000227_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000227_15_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000227_6_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000227_15_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000227_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000227_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000227_2_1 & 1) != 0)
  {
    if ((sec_r000227_8_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000227_15_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000227_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000227_15_1 + 7) & 127;
  }
  if ((sec_r000227_2_2 & 1) != 0)
  {
    if ((sec_r000227_8_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000227_15_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000227_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000227_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000227_17_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000227_15_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000227_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000227_15_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000227_17_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000227_15_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000227_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000227_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000227_13_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000227_1_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000227_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000227_1_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000227_13_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000227_1_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000227_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000227_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000227_4_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000227_14_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000227_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000227_14_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000227_4_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000227_14_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000227_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000227_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000227_13_1 & 1) != 0)
  {
    if ((sec_r000227_9_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000227_5_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000227_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000227_5_1 + 7) & 127;
  }
  if ((sec_r000227_13_2 & 1) != 0)
  {
    if ((sec_r000227_9_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000227_5_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000227_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000227_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r000227_2_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000227_3_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000227_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000227_3_1 + 7) & 127;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r000227_2_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000227_3_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000227_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000227_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000227_7_1 & 1) != 0)
  {
    if ((sec_r000227_11_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000227_20_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000227_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000227_20_1 + 7) & 127;
  }
  if ((sec_r000227_7_2 & 1) != 0)
  {
    if ((sec_r000227_11_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000227_20_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000227_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000227_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000227_7_1 & 1) != 0)
  {
    if ((sec_r000227_7_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000227_5_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000227_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000227_5_1 + 7) & 127;
  }
  if ((sec_r000227_7_2 & 1) != 0)
  {
    if ((sec_r000227_7_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000227_5_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000227_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000227_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000227_14_1 & 1) != 0)
  {
    if ((sec_r000227_5_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000227_17_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000227_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000227_17_1 + 7) & 127;
  }
  if ((sec_r000227_14_2 & 1) != 0)
  {
    if ((sec_r000227_5_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000227_17_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000227_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000227_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r000227_6_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000227_19_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000227_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000227_19_1 + 7) & 127;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((sec_r000227_6_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000227_19_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000227_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000227_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000227_4_1 & 1) != 0)
  {
    if ((sec_r000227_10_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000227_10_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000227_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000227_10_1 + 7) & 127;
  }
  if ((sec_r000227_4_2 & 1) != 0)
  {
    if ((sec_r000227_10_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000227_10_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000227_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000227_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000227_4_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000227_16_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000227_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000227_16_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000227_4_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000227_16_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000227_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000227_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000227_14_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000227_19_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000227_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000227_19_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000227_14_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000227_19_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000227_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000227_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r000227_7_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000227_6_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000227_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000227_6_1 + 7) & 127;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r000227_7_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000227_6_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000227_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000227_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000227_4_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000227_10_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000227_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000227_10_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000227_4_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000227_10_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000227_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000227_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000227_2_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000227_7_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000227_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000227_7_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000227_2_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000227_7_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000227_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000227_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000227_2_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000227_1_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000227_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000227_1_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000227_2_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000227_1_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000227_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000227_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000227_11_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000227_14_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000227_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000227_14_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000227_11_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000227_14_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000227_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000227_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000227_17_1 & 1) != 0)
  {
    if ((sec_r000227_13_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000227_10_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000227_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000227_10_1 + 7) & 127;
  }
  if ((sec_r000227_17_2 & 1) != 0)
  {
    if ((sec_r000227_13_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000227_10_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000227_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000227_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000227_1_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000227_11_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000227_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000227_11_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000227_1_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000227_11_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000227_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000227_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000227_19_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000227_0_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000227_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000227_0_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000227_19_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000227_0_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000227_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000227_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000227_18_1 & 1) != 0)
  {
    if ((sec_r000227_10_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000227_4_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000227_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000227_4_1 + 7) & 127;
  }
  if ((sec_r000227_18_2 & 1) != 0)
  {
    if ((sec_r000227_10_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000227_4_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000227_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000227_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000227_6_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000227_7_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000227_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000227_7_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000227_6_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000227_7_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000227_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000227_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000227_14_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000227_16_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000227_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000227_16_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000227_14_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000227_16_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000227_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000227_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000227_14_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000227_16_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000227_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000227_16_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000227_14_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000227_16_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000227_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000227_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000227_1_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000227_4_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000227_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000227_4_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000227_1_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000227_4_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000227_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000227_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000227_15_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000227_6_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000227_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000227_6_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000227_15_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000227_6_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000227_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000227_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000227_3_1 & 1) != 0)
  {
    if ((sec_r000227_0_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000227_3_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000227_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000227_3_1 + 7) & 127;
  }
  if ((sec_r000227_3_2 & 1) != 0)
  {
    if ((sec_r000227_0_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000227_3_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000227_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000227_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000227_8_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000227_4_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000227_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000227_4_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000227_8_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000227_4_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000227_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000227_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000227_2_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000227_21_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000227_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000227_21_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000227_2_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000227_21_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000227_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000227_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000227_18_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000227_4_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000227_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000227_4_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000227_18_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000227_4_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000227_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000227_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000227_14_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000227_16_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000227_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000227_16_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000227_14_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000227_16_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000227_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000227_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000227_12_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000227_8_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000227_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000227_8_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000227_12_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000227_8_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000227_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000227_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000227_15_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000227_10_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000227_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000227_10_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000227_15_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000227_10_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000227_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000227_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000227_9_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000227_3_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000227_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000227_3_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000227_9_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000227_3_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000227_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000227_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000227_11_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000227_13_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000227_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000227_13_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000227_11_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000227_13_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000227_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000227_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000227_1_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000227_16_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000227_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000227_16_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000227_1_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000227_16_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000227_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000227_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000227_12_1 & 1) != 0)
  {
    if ((sec_r000227_4_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000227_7_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000227_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000227_7_1 + 7) & 127;
  }
  if ((sec_r000227_12_2 & 1) != 0)
  {
    if ((sec_r000227_4_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000227_7_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000227_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000227_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000227_14_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000227_1_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000227_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000227_1_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000227_14_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000227_1_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000227_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000227_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000227_8_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000227_0_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000227_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000227_0_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000227_8_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000227_0_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000227_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000227_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000227_5_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000227_21_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000227_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000227_21_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000227_5_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000227_21_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000227_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000227_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000227_11_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000227_7_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000227_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000227_7_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000227_11_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000227_7_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000227_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000227_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000227_3_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000227_13_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000227_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000227_13_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000227_3_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000227_13_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000227_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000227_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000227_10_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000227_16_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000227_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000227_16_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000227_10_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000227_16_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000227_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000227_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000227_17_1 & 1) != 0)
  {
    if ((sec_r000227_17_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000227_11_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000227_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000227_11_1 + 7) & 127;
  }
  if ((sec_r000227_17_2 & 1) != 0)
  {
    if ((sec_r000227_17_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000227_11_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000227_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000227_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000227_14_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000227_21_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000227_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000227_21_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000227_14_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000227_21_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000227_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000227_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r000227_19_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000227_10_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000227_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000227_10_1 + 7) & 127;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r000227_19_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000227_10_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000227_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000227_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000227_6_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000227_17_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000227_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000227_17_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000227_6_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000227_17_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000227_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000227_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000227_0_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000227_1_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000227_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000227_1_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000227_0_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000227_1_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000227_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000227_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000227_10_1 & 1) != 0)
  {
    if ((sec_r000227_3_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000227_4_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000227_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000227_4_1 + 7) & 127;
  }
  if ((sec_r000227_10_2 & 1) != 0)
  {
    if ((sec_r000227_3_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000227_4_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000227_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000227_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000227_0_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000227_3_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000227_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000227_3_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000227_0_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000227_3_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000227_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000227_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000227_5_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000227_13_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000227_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000227_13_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000227_5_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000227_13_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000227_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000227_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000227_17_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000227_7_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000227_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000227_7_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000227_17_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000227_7_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000227_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000227_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((sec_r000227_12_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000227_4_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000227_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000227_4_1 + 7) & 127;
  }
  if ((stage_v_11_2 & 1) != 0)
  {
    if ((sec_r000227_12_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000227_4_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000227_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000227_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000227_15_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000227_21_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000227_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000227_21_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000227_15_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000227_21_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000227_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000227_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000227_1_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000227_4_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000227_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000227_4_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000227_1_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000227_4_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000227_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000227_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000227_19_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000227_5_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000227_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000227_5_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000227_19_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000227_5_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000227_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000227_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000227_8_1 & 1) != 0)
  {
    if ((sec_r000227_13_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000227_21_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000227_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000227_21_1 + 7) & 127;
  }
  if ((sec_r000227_8_2 & 1) != 0)
  {
    if ((sec_r000227_13_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000227_21_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000227_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000227_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000227_16_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000227_11_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000227_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000227_11_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000227_16_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000227_11_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000227_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000227_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000227_10_1 & 1) != 0)
  {
    if ((sec_r000227_0_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000227_12_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000227_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000227_12_1 + 7) & 127;
  }
  if ((sec_r000227_10_2 & 1) != 0)
  {
    if ((sec_r000227_0_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000227_12_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000227_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000227_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000227_13_1 != sec_r000227_13_2);
  __CPROVER_assume(pub_r000227_11_1 == pub_r000227_11_2);
  __CPROVER_assume(sec_r000227_14_1 != sec_r000227_14_2);
  __CPROVER_assume(pub_r000227_17_1 == pub_r000227_17_2);
  __CPROVER_assume(sec_r000227_16_1 != sec_r000227_16_2);
  __CPROVER_assume(pub_r000227_1_1 == pub_r000227_1_2);
  __CPROVER_assume(sec_r000227_19_1 != sec_r000227_19_2);
  __CPROVER_assume(sec_r000227_9_1 != sec_r000227_9_2);
  __CPROVER_assume(sec_r000227_6_1 != sec_r000227_6_2);
  __CPROVER_assume(sec_r000227_8_1 != sec_r000227_8_2);
  __CPROVER_assume(pub_r000227_18_1 == pub_r000227_18_2);
  __CPROVER_assume(pub_r000227_19_1 == pub_r000227_19_2);
  __CPROVER_assume(pub_r000227_12_1 == pub_r000227_12_2);
  __CPROVER_assume(pub_r000227_0_1 == pub_r000227_0_2);
  __CPROVER_assume(pub_r000227_21_1 == pub_r000227_21_2);
  __CPROVER_assume(pub_r000227_4_1 == pub_r000227_4_2);
  __CPROVER_assume(sec_r000227_10_1 != sec_r000227_10_2);
  __CPROVER_assume(pub_r000227_9_1 == pub_r000227_9_2);
  __CPROVER_assume(sec_r000227_12_1 != sec_r000227_12_2);
  __CPROVER_assume(pub_r000227_8_1 == pub_r000227_8_2);
  __CPROVER_assume(pub_r000227_16_1 == pub_r000227_16_2);
  __CPROVER_assume(pub_r000227_7_1 == pub_r000227_7_2);
  __CPROVER_assume(sec_r000227_1_1 != sec_r000227_1_2);
  __CPROVER_assume(sec_r000227_5_1 != sec_r000227_5_2);
  __CPROVER_assume(pub_r000227_15_1 == pub_r000227_15_2);
  __CPROVER_assume(sec_r000227_11_1 != sec_r000227_11_2);
  __CPROVER_assume(pub_r000227_14_1 == pub_r000227_14_2);
  __CPROVER_assume(pub_r000227_20_1 == pub_r000227_20_2);
  __CPROVER_assume(pub_r000227_2_1 == pub_r000227_2_2);
  __CPROVER_assume(sec_r000227_4_1 != sec_r000227_4_2);
  __CPROVER_assume(sec_r000227_3_1 != sec_r000227_3_2);
  __CPROVER_assume(pub_r000227_13_1 == pub_r000227_13_2);
  __CPROVER_assume(sec_r000227_7_1 != sec_r000227_7_2);
  __CPROVER_assume(pub_r000227_10_1 == pub_r000227_10_2);
  __CPROVER_assume(sec_r000227_15_1 != sec_r000227_15_2);
  __CPROVER_assume(sec_r000227_18_1 != sec_r000227_18_2);
  __CPROVER_assume(pub_r000227_3_1 == pub_r000227_3_2);
  __CPROVER_assume(pub_r000227_6_1 == pub_r000227_6_2);
  __CPROVER_assume(pub_r000227_5_1 == pub_r000227_5_2);
  __CPROVER_assume(sec_r000227_17_1 != sec_r000227_17_2);
  __CPROVER_assume(sec_r000227_2_1 != sec_r000227_2_2);
  __CPROVER_assume(sec_r000227_0_1 != sec_r000227_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.status == st_var_1_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  assert(st_var_2_1.trace == st_var_2_2.trace);
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
}


