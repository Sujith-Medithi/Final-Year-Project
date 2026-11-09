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
struct MatrixBlock_R001664_6413_0
{
  short density;
  int trace;
  int dim;
  int buffer[3];
};
struct Transaction_R001664_6413_1
{
  short rate;
  int balance;
  short auth_code;
  unsigned char status;
  short account_id;
  int buffer[3];
};
union TelemetryField_R001664_6413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001664_6413_1
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
void fn_R001664_6413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st_1 = {0};
  struct MatrixBlock_R001664_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_94_1)
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

  switch (tracker_94_2)
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

  int metric_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_80_1) & 63;
  aux_2 = (aux_2 + metric_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_31_1 > 27)
  {
    acc_1 = ((acc_1 + (tracker_31_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_31_2 > 27)
  {
    acc_2 = ((acc_2 + (tracker_31_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_31_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_94_1 == tracker_94_2);
  assert(metric_80_1 == metric_80_2);
  assert(tracker_31_1 == tracker_31_2);
}

int fn_R001664_6413_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_94 = (aux + st.buffer[1]) & 3;
  switch (tracker_94)
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

  int metric_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_80) & 63;
  acc ^= aux;
  int tracker_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_31 > 27)
  {
    acc = ((acc + (tracker_31 * 2)) + 5) & 127;
    aux ^= tracker_31 & 15;
  }
  else
  {
    acc = ((acc - tracker_31) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001664_6413_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st_1 = {0};
  struct MatrixBlock_R001664_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_32_1 = local_arr_1[aux_1 % 3];
  int damping_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_32_2 * 2)) & 127;
  int index_reg_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_71_1) & 63;
  aux_2 = (aux_2 + index_reg_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
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

  assert(damping_32_1 == damping_32_2);
  assert(index_reg_71_1 == index_reg_71_2);
}

int fn_R001664_6413_1(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int damping_32 = local_arr[aux % 3];
  acc = (acc + (damping_32 * 2)) & 127;
  int index_reg_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_71) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001664_6413_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st_1 = {0};
  struct MatrixBlock_R001664_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int offset_31_1 = 0;
  int offset_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_31_1 = ((offset_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_31_2 = ((offset_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_31_1) & 127;
    acc_2 = (acc_2 + offset_31_2) & 127;
  }

  int accumulator_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_32_1)
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

  switch (accumulator_32_2)
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

  int cursor_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_97_1 > 36)
  {
    acc_1 = ((acc_1 + (cursor_97_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_97_2 > 36)
  {
    acc_2 = ((acc_2 + (cursor_97_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_31_1 == offset_31_2);
  assert(accumulator_32_1 == accumulator_32_2);
  assert(cursor_97_1 == cursor_97_2);
}

int fn_R001664_6413_2(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int offset_31 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_31 = ((offset_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_31) & 127;
  }

  int accumulator_32 = (aux + st.buffer[1]) & 3;
  switch (accumulator_32)
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

  int cursor_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_97 > 36)
  {
    acc = ((acc + (cursor_97 * 2)) + 5) & 127;
    aux ^= cursor_97 & 15;
  }
  else
  {
    acc = ((acc - cursor_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001664_6413_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st_1 = {0};
  struct Transaction_R001664_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tally_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_61_1 > 42)
  {
    acc_1 = ((acc_1 + (tally_61_1 * 2)) + 5) & 127;
    aux_1 ^= tally_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_61_2 > 42)
  {
    acc_2 = ((acc_2 + (tally_61_2 * 2)) + 5) & 127;
    aux_2 ^= tally_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_95_1 = 0;
  int factor_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_95_1 = ((factor_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_95_2 = ((factor_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_95_1) & 127;
    acc_2 = (acc_2 + factor_95_2) & 127;
  }

  int offset_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_13_1)
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

  switch (offset_13_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_61_1 == tally_61_2);
  assert(factor_95_1 == factor_95_2);
  assert(offset_13_1 == offset_13_2);
}

int fn_R001664_6413_3(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tally_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_61 > 42)
  {
    acc = ((acc + (tally_61 * 2)) + 5) & 127;
    aux ^= tally_61 & 15;
  }
  else
  {
    acc = ((acc - tally_61) + 11) & 127;
    aux += 3;
  }
  int factor_95 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_95 = ((factor_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_95) & 127;
  }

  int offset_13 = (aux + st.buffer[1]) & 3;
  switch (offset_13)
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

void fn_R001664_6413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st_1 = {0};
  struct MatrixBlock_R001664_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int cursor_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_16_1) & 63;
  aux_2 = (aux_2 + cursor_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_61_1 = local_arr_1[aux_1 % 3];
  int pivot_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_61_2 * 2)) & 127;
  int threshold_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_89_1 > 40)
  {
    acc_1 = ((acc_1 + (threshold_89_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_89_2 > 40)
  {
    acc_2 = ((acc_2 + (threshold_89_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_34_1 = 0;
  int damping_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_34_1 = ((damping_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_34_2 = ((damping_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_34_1) & 127;
    acc_2 = (acc_2 + damping_34_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_16_1 == cursor_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_61_1 == pivot_61_2);
  assert(threshold_89_1 == threshold_89_2);
  assert(damping_34_1 == damping_34_2);
}

int fn_R001664_6413_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int cursor_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_16) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_61 = local_arr[aux % 3];
  acc = (acc + (pivot_61 * 2)) & 127;
  int threshold_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_89 > 40)
  {
    acc = ((acc + (threshold_89 * 2)) + 5) & 127;
    aux ^= threshold_89 & 15;
  }
  else
  {
    acc = ((acc - threshold_89) + 11) & 127;
    aux += 3;
  }
  int damping_34 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_34 = ((damping_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_34) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001664_6413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st_1 = {0};
  struct Transaction_R001664_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int anchor_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_56_1)
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

  switch (anchor_56_2)
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

  int segment_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_43_1 > 15)
  {
    acc_1 = ((acc_1 + (segment_43_1 * 2)) + 5) & 127;
    aux_1 ^= segment_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_43_2 > 15)
  {
    acc_2 = ((acc_2 + (segment_43_2 * 2)) + 5) & 127;
    aux_2 ^= segment_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_43_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_56_1 == anchor_56_2);
  assert(segment_43_1 == segment_43_2);
}

int fn_R001664_6413_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int anchor_56 = (aux + st.buffer[1]) & 3;
  switch (anchor_56)
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

  int segment_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_43 > 15)
  {
    acc = ((acc + (segment_43 * 2)) + 5) & 127;
    aux ^= segment_43 & 15;
  }
  else
  {
    acc = ((acc - segment_43) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001664_6413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st_1 = {0};
  struct Transaction_R001664_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int phase_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_18_1)
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

  switch (phase_18_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_14_1 = local_arr_1[aux_1 % 3];
  int phase_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_14_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_18_1 == phase_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_14_1 == phase_14_2);
}

int fn_R001664_6413_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int phase_18 = (aux + st.buffer[1]) & 3;
  switch (phase_18)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_14 = local_arr[aux % 3];
  acc = (acc + (phase_14 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001664_6413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st_1 = {0};
  struct MatrixBlock_R001664_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int accumulator_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_75_1)
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

  switch (accumulator_75_2)
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

  int quotient_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_25_1 > 10)
  {
    acc_1 = ((acc_1 + (quotient_25_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_25_2 > 10)
  {
    acc_2 = ((acc_2 + (quotient_25_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_55_1 = 0;
  int damping_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_55_1 = ((damping_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_55_2 = ((damping_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_55_1) & 127;
    acc_2 = (acc_2 + damping_55_2) & 127;
  }

  int sample_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_75_1) & 63;
  aux_2 = (aux_2 + sample_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_75_1 == accumulator_75_2);
  assert(quotient_25_1 == quotient_25_2);
  assert(damping_55_1 == damping_55_2);
  assert(sample_75_1 == sample_75_2);
}

int fn_R001664_6413_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int accumulator_75 = (aux + st.buffer[1]) & 3;
  switch (accumulator_75)
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

  int quotient_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_25 > 10)
  {
    acc = ((acc + (quotient_25 * 2)) + 5) & 127;
    aux ^= quotient_25 & 15;
  }
  else
  {
    acc = ((acc - quotient_25) + 11) & 127;
    aux += 3;
  }
  int damping_55 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_55 = ((damping_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_55) & 127;
  }

  int sample_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001664_6413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st_1 = {0};
  struct MatrixBlock_R001664_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_98_1 = local_arr_1[aux_1 % 3];
  int margin_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_98_2 * 2)) & 127;
  int mask_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_45_1 > 18)
  {
    acc_1 = ((acc_1 + (mask_45_1 * 2)) + 5) & 127;
    aux_1 ^= mask_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_45_2 > 18)
  {
    acc_2 = ((acc_2 + (mask_45_2 * 2)) + 5) & 127;
    aux_2 ^= mask_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
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

  assert(margin_98_1 == margin_98_2);
  assert(mask_45_1 == mask_45_2);
}

int fn_R001664_6413_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int margin_98 = local_arr[aux % 3];
  acc = (acc + (margin_98 * 2)) & 127;
  int mask_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_45 > 18)
  {
    acc = ((acc + (mask_45 * 2)) + 5) & 127;
    aux ^= mask_45 & 15;
  }
  else
  {
    acc = ((acc - mask_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001664_6413_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st_1 = {0};
  struct Transaction_R001664_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int factor_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_64_1) & 63;
  aux_2 = (aux_2 + factor_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_58_1 = 0;
  int offset_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_58_1 = ((offset_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_58_2 = ((offset_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_58_1) & 127;
    acc_2 = (acc_2 + offset_58_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_74_1 = local_arr_1[aux_1 % 3];
  int parity_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_74_2 * 2)) & 127;
  int tracker_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_50_1 > 18)
  {
    acc_1 = ((acc_1 + (tracker_50_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_50_2 > 18)
  {
    acc_2 = ((acc_2 + (tracker_50_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_50_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_64_1 == factor_64_2);
  assert(offset_58_1 == offset_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_74_1 == parity_74_2);
  assert(tracker_50_1 == tracker_50_2);
}

int fn_R001664_6413_9(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int factor_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_64) & 63;
  acc ^= aux;
  int offset_58 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_58 = ((offset_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_58) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int parity_74 = local_arr[aux % 3];
  acc = (acc + (parity_74 * 2)) & 127;
  int tracker_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_50 > 18)
  {
    acc = ((acc + (tracker_50 * 2)) + 5) & 127;
    aux ^= tracker_50 & 15;
  }
  else
  {
    acc = ((acc - tracker_50) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001664_6413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st_1 = {0};
  struct MatrixBlock_R001664_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_13_1)
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

  switch (cursor_13_2)
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
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_13_1 == cursor_13_2);
}

int fn_R001664_6413_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_13 = (aux + st.buffer[1]) & 3;
  switch (cursor_13)
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

void fn_R001664_6413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st_1 = {0};
  struct Transaction_R001664_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int segment_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_92_1 > 17)
  {
    acc_1 = ((acc_1 + (segment_92_1 * 2)) + 5) & 127;
    aux_1 ^= segment_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_92_2 > 17)
  {
    acc_2 = ((acc_2 + (segment_92_2 * 2)) + 5) & 127;
    aux_2 ^= segment_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_38_1 = local_arr_1[aux_1 % 3];
  int bound_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_38_2 * 2)) & 127;
  int stride_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_28_1)
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

  switch (stride_28_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_92_1 == segment_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_38_1 == bound_38_2);
  assert(stride_28_1 == stride_28_2);
}

int fn_R001664_6413_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int segment_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_92 > 17)
  {
    acc = ((acc + (segment_92 * 2)) + 5) & 127;
    aux ^= segment_92 & 15;
  }
  else
  {
    acc = ((acc - segment_92) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_38 = local_arr[aux % 3];
  acc = (acc + (bound_38 * 2)) & 127;
  int stride_28 = (aux + st.buffer[1]) & 3;
  switch (stride_28)
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

void fn_R001664_6413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st_1 = {0};
  struct Transaction_R001664_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int cursor_10_1 = 0;
  int cursor_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_10_1 = ((cursor_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_10_2 = ((cursor_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_10_1) & 127;
    acc_2 = (acc_2 + cursor_10_2) & 127;
  }

  int pivot_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_24_1 > 35)
  {
    acc_1 = ((acc_1 + (pivot_24_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_24_2 > 35)
  {
    acc_2 = ((acc_2 + (pivot_24_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_71_1)
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

  switch (window_71_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_10_1 == cursor_10_2);
  assert(pivot_24_1 == pivot_24_2);
  assert(window_71_1 == window_71_2);
}

int fn_R001664_6413_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int cursor_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_10 = ((cursor_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_10) & 127;
  }

  int pivot_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_24 > 35)
  {
    acc = ((acc + (pivot_24 * 2)) + 5) & 127;
    aux ^= pivot_24 & 15;
  }
  else
  {
    acc = ((acc - pivot_24) + 11) & 127;
    aux += 3;
  }
  int window_71 = (aux + st.buffer[1]) & 3;
  switch (window_71)
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
  return (acc + aux) & 255;
}

void fn_R001664_6413_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st_1 = {0};
  struct MatrixBlock_R001664_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int sample_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_41_1 > 49)
  {
    acc_1 = ((acc_1 + (sample_41_1 * 2)) + 5) & 127;
    aux_1 ^= sample_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_41_2 > 49)
  {
    acc_2 = ((acc_2 + (sample_41_2 * 2)) + 5) & 127;
    aux_2 ^= sample_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_12_1)
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

  switch (coefficient_12_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_41_1 == sample_41_2);
  assert(coefficient_12_1 == coefficient_12_2);
}

int fn_R001664_6413_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int sample_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_41 > 49)
  {
    acc = ((acc + (sample_41 * 2)) + 5) & 127;
    aux ^= sample_41 & 15;
  }
  else
  {
    acc = ((acc - sample_41) + 11) & 127;
    aux += 3;
  }
  int coefficient_12 = (aux + st.buffer[1]) & 3;
  switch (coefficient_12)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001664_6413_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st_1 = {0};
  struct MatrixBlock_R001664_6413_0 st_2 = {0};
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
  int delta_90_1 = 0;
  int delta_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_90_1 = ((delta_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_90_2 = ((delta_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_90_1) & 127;
    acc_2 = (acc_2 + delta_90_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_90_1 == delta_90_2);
}

int fn_R001664_6413_14(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_90 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_90 = ((delta_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_90) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001664_6413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st_1 = {0};
  struct Transaction_R001664_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int quotient_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_78_1) & 63;
  aux_2 = (aux_2 + quotient_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_99_1 > 32)
  {
    acc_1 = ((acc_1 + (factor_99_1 * 2)) + 5) & 127;
    aux_1 ^= factor_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_99_2 > 32)
  {
    acc_2 = ((acc_2 + (factor_99_2 * 2)) + 5) & 127;
    aux_2 ^= factor_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_99_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_78_1 == quotient_78_2);
  assert(factor_99_1 == factor_99_2);
}

int fn_R001664_6413_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int quotient_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_78) & 63;
  acc ^= aux;
  int factor_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_99 > 32)
  {
    acc = ((acc + (factor_99 * 2)) + 5) & 127;
    aux ^= factor_99 & 15;
  }
  else
  {
    acc = ((acc - factor_99) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001664_6413_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st_1 = {0};
  struct Transaction_R001664_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int stride_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_83_1) & 63;
  aux_2 = (aux_2 + stride_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_15_1)
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

  switch (pivot_15_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_83_1 == stride_83_2);
  assert(pivot_15_1 == pivot_15_2);
}

int fn_R001664_6413_16(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int stride_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_83) & 63;
  acc ^= aux;
  int pivot_15 = (aux + st.buffer[1]) & 3;
  switch (pivot_15)
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

void fn_R001664_6413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st_1 = {0};
  struct MatrixBlock_R001664_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int parity_37_1 = 0;
  int parity_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_37_1 = ((parity_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_37_2 = ((parity_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_37_1) & 127;
    acc_2 = (acc_2 + parity_37_2) & 127;
  }

  int anchor_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_31_1 > 41)
  {
    acc_1 = ((acc_1 + (anchor_31_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_31_2 > 41)
  {
    acc_2 = ((acc_2 + (anchor_31_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_31_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_45_1 = local_arr_1[aux_1 % 3];
  int tracker_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_37_1 == parity_37_2);
  assert(anchor_31_1 == anchor_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_45_1 == tracker_45_2);
}

int fn_R001664_6413_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int parity_37 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_37 = ((parity_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_37) & 127;
  }

  int anchor_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_31 > 41)
  {
    acc = ((acc + (anchor_31 * 2)) + 5) & 127;
    aux ^= anchor_31 & 15;
  }
  else
  {
    acc = ((acc - anchor_31) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tracker_45 = local_arr[aux % 3];
  acc = (acc + (tracker_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001664_6413_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st_1 = {0};
  struct MatrixBlock_R001664_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_41_1 = local_arr_1[aux_1 % 3];
  int sample_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_41_2 * 2)) & 127;
  int cursor_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_99_1)
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

  switch (cursor_99_2)
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

  int coefficient_59_1 = 0;
  int coefficient_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_59_1 = ((coefficient_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_59_2 = ((coefficient_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_59_1) & 127;
    acc_2 = (acc_2 + coefficient_59_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
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

  assert(sample_41_1 == sample_41_2);
  assert(cursor_99_1 == cursor_99_2);
  assert(coefficient_59_1 == coefficient_59_2);
}

int fn_R001664_6413_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int sample_41 = local_arr[aux % 3];
  acc = (acc + (sample_41 * 2)) & 127;
  int cursor_99 = (aux + st.buffer[1]) & 3;
  switch (cursor_99)
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

  int coefficient_59 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_59 = ((coefficient_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_59) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001664_6413_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st_1 = {0};
  struct MatrixBlock_R001664_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int tracker_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_70_1) & 63;
  aux_2 = (aux_2 + tracker_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_35_1)
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

  switch (threshold_35_2)
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

  int phase_64_1 = 0;
  int phase_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_64_1 = ((phase_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_64_2 = ((phase_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_64_1) & 127;
    acc_2 = (acc_2 + phase_64_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_70_1 == tracker_70_2);
  assert(threshold_35_1 == threshold_35_2);
  assert(phase_64_1 == phase_64_2);
}

int fn_R001664_6413_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001664_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int tracker_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_70) & 63;
  acc ^= aux;
  int threshold_35 = (aux + st.buffer[1]) & 3;
  switch (threshold_35)
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

  int phase_64 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_64 = ((phase_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_64) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001664_6413_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st_1 = {0};
  struct Transaction_R001664_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int bound_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_52_1 > 36)
  {
    acc_1 = ((acc_1 + (bound_52_1 * 2)) + 5) & 127;
    aux_1 ^= bound_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_52_2 > 36)
  {
    acc_2 = ((acc_2 + (bound_52_2 * 2)) + 5) & 127;
    aux_2 ^= bound_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_15_1 = local_arr_1[aux_1 % 3];
  int tracker_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_15_2 * 2)) & 127;
  int parity_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_25_1)
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

  switch (parity_25_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_52_1 == bound_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_15_1 == tracker_15_2);
  assert(parity_25_1 == parity_25_2);
}

int fn_R001664_6413_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001664_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int bound_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_52 > 36)
  {
    acc = ((acc + (bound_52 * 2)) + 5) & 127;
    aux ^= bound_52 & 15;
  }
  else
  {
    acc = ((acc - bound_52) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tracker_15 = local_arr[aux % 3];
  acc = (acc + (tracker_15 * 2)) & 127;
  int parity_25 = (aux + st.buffer[1]) & 3;
  switch (parity_25)
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

void main()
{
  int sec_r001664_0_1;
  int sec_r001664_0_2;
  int sec_r001664_1_1;
  int sec_r001664_1_2;
  int sec_r001664_2_1;
  int sec_r001664_2_2;
  int sec_r001664_3_1;
  int sec_r001664_3_2;
  int sec_r001664_4_1;
  int sec_r001664_4_2;
  int sec_r001664_5_1;
  int sec_r001664_5_2;
  int sec_r001664_6_1;
  int sec_r001664_6_2;
  int sec_r001664_7_1;
  int sec_r001664_7_2;
  int sec_r001664_8_1;
  int sec_r001664_8_2;
  int sec_r001664_9_1;
  int sec_r001664_9_2;
  int sec_r001664_10_1;
  int sec_r001664_10_2;
  int sec_r001664_11_1;
  int sec_r001664_11_2;
  int sec_r001664_12_1;
  int sec_r001664_12_2;
  int sec_r001664_13_1;
  int sec_r001664_13_2;
  int sec_r001664_14_1;
  int sec_r001664_14_2;
  int sec_r001664_15_1;
  int sec_r001664_15_2;
  int sec_r001664_16_1;
  int sec_r001664_16_2;
  int pub_r001664_0_1;
  int pub_r001664_0_2;
  int pub_r001664_1_1;
  int pub_r001664_1_2;
  int pub_r001664_2_1;
  int pub_r001664_2_2;
  int pub_r001664_3_1;
  int pub_r001664_3_2;
  int pub_r001664_4_1;
  int pub_r001664_4_2;
  int pub_r001664_5_1;
  int pub_r001664_5_2;
  int pub_r001664_6_1;
  int pub_r001664_6_2;
  int pub_r001664_7_1;
  int pub_r001664_7_2;
  int pub_r001664_8_1;
  int pub_r001664_8_2;
  int pub_r001664_9_1;
  int pub_r001664_9_2;
  int pub_r001664_10_1;
  int pub_r001664_10_2;
  int pub_r001664_11_1;
  int pub_r001664_11_2;
  int pub_r001664_12_1;
  int pub_r001664_12_2;
  int pub_r001664_13_1;
  int pub_r001664_13_2;
  int pub_r001664_14_1;
  int pub_r001664_14_2;
  int pub_r001664_15_1;
  int pub_r001664_15_2;
  int pub_r001664_16_1;
  int pub_r001664_16_2;
  int pub_r001664_17_1;
  int pub_r001664_17_2;
  int pub_r001664_18_1;
  int pub_r001664_18_2;
  int pub_r001664_19_1;
  int pub_r001664_19_2;
  int pub_r001664_20_1;
  int pub_r001664_20_2;
  int pub_r001664_21_1;
  int pub_r001664_21_2;
  int pub_r001664_22_1;
  int pub_r001664_22_2;
  int pub_r001664_23_1;
  int pub_r001664_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001664_0_1 >= (-100)) && (pub_r001664_0_1 <= 100));
  __CPROVER_assume((pub_r001664_0_2 >= (-100)) && (pub_r001664_0_2 <= 100));
  __CPROVER_assume((pub_r001664_1_1 >= (-100)) && (pub_r001664_1_1 <= 100));
  __CPROVER_assume((pub_r001664_1_2 >= (-100)) && (pub_r001664_1_2 <= 100));
  __CPROVER_assume((pub_r001664_2_1 >= (-100)) && (pub_r001664_2_1 <= 100));
  __CPROVER_assume((pub_r001664_2_2 >= (-100)) && (pub_r001664_2_2 <= 100));
  __CPROVER_assume((pub_r001664_3_1 >= (-100)) && (pub_r001664_3_1 <= 100));
  __CPROVER_assume((pub_r001664_3_2 >= (-100)) && (pub_r001664_3_2 <= 100));
  __CPROVER_assume((pub_r001664_4_1 >= (-100)) && (pub_r001664_4_1 <= 100));
  __CPROVER_assume((pub_r001664_4_2 >= (-100)) && (pub_r001664_4_2 <= 100));
  __CPROVER_assume((pub_r001664_5_1 >= (-100)) && (pub_r001664_5_1 <= 100));
  __CPROVER_assume((pub_r001664_5_2 >= (-100)) && (pub_r001664_5_2 <= 100));
  __CPROVER_assume((pub_r001664_6_1 >= (-100)) && (pub_r001664_6_1 <= 100));
  __CPROVER_assume((pub_r001664_6_2 >= (-100)) && (pub_r001664_6_2 <= 100));
  __CPROVER_assume((pub_r001664_7_1 >= (-100)) && (pub_r001664_7_1 <= 100));
  __CPROVER_assume((pub_r001664_7_2 >= (-100)) && (pub_r001664_7_2 <= 100));
  __CPROVER_assume((pub_r001664_8_1 >= (-100)) && (pub_r001664_8_1 <= 100));
  __CPROVER_assume((pub_r001664_8_2 >= (-100)) && (pub_r001664_8_2 <= 100));
  __CPROVER_assume((pub_r001664_9_1 >= (-100)) && (pub_r001664_9_1 <= 100));
  __CPROVER_assume((pub_r001664_9_2 >= (-100)) && (pub_r001664_9_2 <= 100));
  __CPROVER_assume((pub_r001664_10_1 >= (-100)) && (pub_r001664_10_1 <= 100));
  __CPROVER_assume((pub_r001664_10_2 >= (-100)) && (pub_r001664_10_2 <= 100));
  __CPROVER_assume((pub_r001664_11_1 >= (-100)) && (pub_r001664_11_1 <= 100));
  __CPROVER_assume((pub_r001664_11_2 >= (-100)) && (pub_r001664_11_2 <= 100));
  __CPROVER_assume((pub_r001664_12_1 >= (-100)) && (pub_r001664_12_1 <= 100));
  __CPROVER_assume((pub_r001664_12_2 >= (-100)) && (pub_r001664_12_2 <= 100));
  __CPROVER_assume((pub_r001664_13_1 >= (-100)) && (pub_r001664_13_1 <= 100));
  __CPROVER_assume((pub_r001664_13_2 >= (-100)) && (pub_r001664_13_2 <= 100));
  __CPROVER_assume((pub_r001664_14_1 >= (-100)) && (pub_r001664_14_1 <= 100));
  __CPROVER_assume((pub_r001664_14_2 >= (-100)) && (pub_r001664_14_2 <= 100));
  __CPROVER_assume((pub_r001664_15_1 >= (-100)) && (pub_r001664_15_1 <= 100));
  __CPROVER_assume((pub_r001664_15_2 >= (-100)) && (pub_r001664_15_2 <= 100));
  __CPROVER_assume((pub_r001664_16_1 >= (-100)) && (pub_r001664_16_1 <= 100));
  __CPROVER_assume((pub_r001664_16_2 >= (-100)) && (pub_r001664_16_2 <= 100));
  __CPROVER_assume((pub_r001664_17_1 >= (-100)) && (pub_r001664_17_1 <= 100));
  __CPROVER_assume((pub_r001664_17_2 >= (-100)) && (pub_r001664_17_2 <= 100));
  __CPROVER_assume((pub_r001664_18_1 >= (-100)) && (pub_r001664_18_1 <= 100));
  __CPROVER_assume((pub_r001664_18_2 >= (-100)) && (pub_r001664_18_2 <= 100));
  __CPROVER_assume((pub_r001664_19_1 >= (-100)) && (pub_r001664_19_1 <= 100));
  __CPROVER_assume((pub_r001664_19_2 >= (-100)) && (pub_r001664_19_2 <= 100));
  __CPROVER_assume((pub_r001664_20_1 >= (-100)) && (pub_r001664_20_1 <= 100));
  __CPROVER_assume((pub_r001664_20_2 >= (-100)) && (pub_r001664_20_2 <= 100));
  __CPROVER_assume((pub_r001664_21_1 >= (-100)) && (pub_r001664_21_1 <= 100));
  __CPROVER_assume((pub_r001664_21_2 >= (-100)) && (pub_r001664_21_2 <= 100));
  __CPROVER_assume((pub_r001664_22_1 >= (-100)) && (pub_r001664_22_1 <= 100));
  __CPROVER_assume((pub_r001664_22_2 >= (-100)) && (pub_r001664_22_2 <= 100));
  __CPROVER_assume((pub_r001664_23_1 >= (-100)) && (pub_r001664_23_1 <= 100));
  __CPROVER_assume((pub_r001664_23_2 >= (-100)) && (pub_r001664_23_2 <= 100));
  __CPROVER_assume((sec_r001664_0_1 >= 0) && (sec_r001664_0_1 <= 255));
  __CPROVER_assume((sec_r001664_0_2 >= 0) && (sec_r001664_0_2 <= 255));
  __CPROVER_assume((sec_r001664_1_1 >= 0) && (sec_r001664_1_1 <= 255));
  __CPROVER_assume((sec_r001664_1_2 >= 0) && (sec_r001664_1_2 <= 255));
  __CPROVER_assume((sec_r001664_2_1 >= 0) && (sec_r001664_2_1 <= 255));
  __CPROVER_assume((sec_r001664_2_2 >= 0) && (sec_r001664_2_2 <= 255));
  __CPROVER_assume((sec_r001664_3_1 >= 0) && (sec_r001664_3_1 <= 255));
  __CPROVER_assume((sec_r001664_3_2 >= 0) && (sec_r001664_3_2 <= 255));
  __CPROVER_assume((sec_r001664_4_1 >= 0) && (sec_r001664_4_1 <= 255));
  __CPROVER_assume((sec_r001664_4_2 >= 0) && (sec_r001664_4_2 <= 255));
  __CPROVER_assume((sec_r001664_5_1 >= 0) && (sec_r001664_5_1 <= 255));
  __CPROVER_assume((sec_r001664_5_2 >= 0) && (sec_r001664_5_2 <= 255));
  __CPROVER_assume((sec_r001664_6_1 >= 0) && (sec_r001664_6_1 <= 255));
  __CPROVER_assume((sec_r001664_6_2 >= 0) && (sec_r001664_6_2 <= 255));
  __CPROVER_assume((sec_r001664_7_1 >= 0) && (sec_r001664_7_1 <= 255));
  __CPROVER_assume((sec_r001664_7_2 >= 0) && (sec_r001664_7_2 <= 255));
  __CPROVER_assume((sec_r001664_8_1 >= 0) && (sec_r001664_8_1 <= 255));
  __CPROVER_assume((sec_r001664_8_2 >= 0) && (sec_r001664_8_2 <= 255));
  __CPROVER_assume((sec_r001664_9_1 >= 0) && (sec_r001664_9_1 <= 255));
  __CPROVER_assume((sec_r001664_9_2 >= 0) && (sec_r001664_9_2 <= 255));
  __CPROVER_assume((sec_r001664_10_1 >= 0) && (sec_r001664_10_1 <= 255));
  __CPROVER_assume((sec_r001664_10_2 >= 0) && (sec_r001664_10_2 <= 255));
  __CPROVER_assume((sec_r001664_11_1 >= 0) && (sec_r001664_11_1 <= 255));
  __CPROVER_assume((sec_r001664_11_2 >= 0) && (sec_r001664_11_2 <= 255));
  __CPROVER_assume((sec_r001664_12_1 >= 0) && (sec_r001664_12_1 <= 255));
  __CPROVER_assume((sec_r001664_12_2 >= 0) && (sec_r001664_12_2 <= 255));
  __CPROVER_assume((sec_r001664_13_1 >= 0) && (sec_r001664_13_1 <= 255));
  __CPROVER_assume((sec_r001664_13_2 >= 0) && (sec_r001664_13_2 <= 255));
  __CPROVER_assume((sec_r001664_14_1 >= 0) && (sec_r001664_14_1 <= 255));
  __CPROVER_assume((sec_r001664_14_2 >= 0) && (sec_r001664_14_2 <= 255));
  __CPROVER_assume((sec_r001664_15_1 >= 0) && (sec_r001664_15_1 <= 255));
  __CPROVER_assume((sec_r001664_15_2 >= 0) && (sec_r001664_15_2 <= 255));
  __CPROVER_assume((sec_r001664_16_1 >= 0) && (sec_r001664_16_1 <= 255));
  __CPROVER_assume((sec_r001664_16_2 >= 0) && (sec_r001664_16_2 <= 255));
  struct MatrixBlock_R001664_6413_0 st_var_0_1 = {0};
  struct MatrixBlock_R001664_6413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001664_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001664_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001664_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001664_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001664_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001664_0_2 + 7) & 15;
  struct Transaction_R001664_6413_1 st_var_1_1 = {0};
  struct Transaction_R001664_6413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001664_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001664_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001664_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001664_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001664_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001664_0_2 + 9) & 15;
  union TelemetryField_R001664_6413_0 u_var_1;
  union TelemetryField_R001664_6413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001664_6413_0(sec_r001664_0_1, sec_r001664_1_1, pub_r001664_2_1, pub_r001664_3_1);
  int helper_flow_0_2 = fn_R001664_6413_0(sec_r001664_0_2, sec_r001664_1_2, pub_r001664_2_2, pub_r001664_3_2);
  fn_R001664_6413_0_2(sec_r001664_0_1, sec_r001664_1_1, pub_r001664_2_1, pub_r001664_3_1, sec_r001664_0_2, sec_r001664_1_2, pub_r001664_2_2, pub_r001664_3_2);
  int helper_flow_1_1 = fn_R001664_6413_1(sec_r001664_1_1, pub_r001664_2_1, pub_r001664_3_1);
  int helper_flow_1_2 = fn_R001664_6413_1(sec_r001664_1_2, pub_r001664_2_2, pub_r001664_3_2);
  fn_R001664_6413_1_2(sec_r001664_1_1, pub_r001664_2_1, pub_r001664_3_1, sec_r001664_1_2, pub_r001664_2_2, pub_r001664_3_2);
  int helper_flow_2_1 = fn_R001664_6413_2(sec_r001664_2_1, sec_r001664_3_1, pub_r001664_4_1);
  int helper_flow_2_2 = fn_R001664_6413_2(sec_r001664_2_2, sec_r001664_3_2, pub_r001664_4_2);
  fn_R001664_6413_2_2(sec_r001664_2_1, sec_r001664_3_1, pub_r001664_4_1, sec_r001664_2_2, sec_r001664_3_2, pub_r001664_4_2);
  int helper_flow_3_1 = fn_R001664_6413_3(sec_r001664_3_1, pub_r001664_4_1);
  int helper_flow_3_2 = fn_R001664_6413_3(sec_r001664_3_2, pub_r001664_4_2);
  fn_R001664_6413_3_2(sec_r001664_3_1, pub_r001664_4_1, sec_r001664_3_2, pub_r001664_4_2);
  int helper_flow_4_1 = fn_R001664_6413_4(sec_r001664_4_1, sec_r001664_5_1, pub_r001664_6_1, pub_r001664_7_1, pub_r001664_8_1);
  int helper_flow_4_2 = fn_R001664_6413_4(sec_r001664_4_2, sec_r001664_5_2, pub_r001664_6_2, pub_r001664_7_2, pub_r001664_8_2);
  fn_R001664_6413_4_2(sec_r001664_4_1, sec_r001664_5_1, pub_r001664_6_1, pub_r001664_7_1, pub_r001664_8_1, sec_r001664_4_2, sec_r001664_5_2, pub_r001664_6_2, pub_r001664_7_2, pub_r001664_8_2);
  int helper_flow_5_1 = fn_R001664_6413_5(sec_r001664_5_1, pub_r001664_6_1, pub_r001664_7_1, pub_r001664_8_1, pub_r001664_9_1);
  int helper_flow_5_2 = fn_R001664_6413_5(sec_r001664_5_2, pub_r001664_6_2, pub_r001664_7_2, pub_r001664_8_2, pub_r001664_9_2);
  fn_R001664_6413_5_2(sec_r001664_5_1, pub_r001664_6_1, pub_r001664_7_1, pub_r001664_8_1, pub_r001664_9_1, sec_r001664_5_2, pub_r001664_6_2, pub_r001664_7_2, pub_r001664_8_2, pub_r001664_9_2);
  int stage_v_0_1 = ((pub_r001664_6_1 * 2) + 10) & 63;
  int stage_v_0_2 = ((pub_r001664_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001664_16_1 * 3) + pub_r001664_2_1) + 26) & 127;
  int stage_v_1_2 = (((sec_r001664_16_2 * 3) + pub_r001664_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = (((sec_r001664_16_1 * 3) + pub_r001664_12_1) + 20) & 127;
  int stage_v_2_2 = (((sec_r001664_16_2 * 3) + pub_r001664_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = (((sec_r001664_2_1 * 3) + pub_r001664_21_1) + 14) & 127;
  int stage_v_3_2 = (((sec_r001664_2_2 * 3) + pub_r001664_21_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = ((pub_r001664_10_1 * 2) + 18) & 63;
  int stage_v_4_2 = ((pub_r001664_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((helper_flow_2_1 * 3) + pub_r001664_6_1) + 40) & 127;
  int stage_v_5_2 = (((helper_flow_2_2 * 3) + pub_r001664_6_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = (((stage_v_1_1 * 3) + pub_r001664_21_1) + 42) & 127;
  int stage_v_6_2 = (((stage_v_1_2 * 3) + pub_r001664_21_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = (((sec_r001664_2_1 * 3) + pub_r001664_7_1) + 38) & 127;
  int stage_v_7_2 = (((sec_r001664_2_2 * 3) + pub_r001664_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001664_15_1 * 2) + 41) & 63;
  int stage_v_8_2 = ((pub_r001664_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (((sec_r001664_10_1 * 3) + pub_r001664_0_1) + 7) & 127;
  int stage_v_9_2 = (((sec_r001664_10_2 * 3) + pub_r001664_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = (((sec_r001664_11_1 * 3) + pub_r001664_16_1) + 9) & 127;
  int stage_v_10_2 = (((sec_r001664_11_2 * 3) + pub_r001664_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001664_19_1 * 2) + 14) & 63;
  int stage_v_11_2 = ((pub_r001664_19_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((sec_r001664_3_1 * 3) + pub_r001664_7_1) + 25) & 127;
  int stage_v_12_2 = (((sec_r001664_3_2 * 3) + pub_r001664_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = ((pub_r001664_8_1 * 2) + 10) & 63;
  int stage_v_13_2 = ((pub_r001664_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((sec_r001664_5_1 * 3) + pub_r001664_3_1) + 16) & 127;
  int stage_v_14_2 = (((sec_r001664_5_2 * 3) + pub_r001664_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = ((pub_r001664_21_1 * 2) + 48) & 63;
  int stage_v_15_2 = ((pub_r001664_21_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((sec_r001664_8_1 * 3) + pub_r001664_6_1) + 17) & 127;
  int stage_v_16_2 = (((sec_r001664_8_2 * 3) + pub_r001664_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = ((pub_r001664_18_1 * 2) + 48) & 63;
  int stage_v_17_2 = ((pub_r001664_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001664_6_1 * 2) + 49) & 63;
  int stage_v_18_2 = ((pub_r001664_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001664_15_1 * 3) + pub_r001664_3_1) + 9) & 127;
  int stage_v_19_2 = (((sec_r001664_15_2 * 3) + pub_r001664_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001664_23_1 * 2) + 24) & 63;
  int stage_v_20_2 = ((pub_r001664_23_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001664_15_1 * 2) + 17) & 63;
  int stage_v_21_2 = ((pub_r001664_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((sec_r001664_7_1 * 3) + pub_r001664_3_1) + 7) & 127;
  int stage_v_22_2 = (((sec_r001664_7_2 * 3) + pub_r001664_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = (((sec_r001664_0_1 * 3) + pub_r001664_22_1) + 31) & 127;
  int stage_v_23_2 = (((sec_r001664_0_2 * 3) + pub_r001664_22_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((sec_r001664_7_1 * 3) + pub_r001664_0_1) + 5) & 127;
  int stage_v_24_2 = (((sec_r001664_7_2 * 3) + pub_r001664_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001664_19_1 * 2) + 49) & 63;
  int stage_v_25_2 = ((pub_r001664_19_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001664_4_1 * 2) + 32) & 63;
  int stage_v_26_2 = ((pub_r001664_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = (((sec_r001664_11_1 * 3) + pub_r001664_10_1) + 34) & 127;
  int stage_v_27_2 = (((sec_r001664_11_2 * 3) + pub_r001664_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = ((pub_r001664_11_1 * 2) + 27) & 63;
  int stage_v_28_2 = ((pub_r001664_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001664_10_1 * 2) + 48) & 63;
  int stage_v_29_2 = ((pub_r001664_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001664_20_1 * 2) + 22) & 63;
  int stage_v_30_2 = ((pub_r001664_20_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((stage_v_24_1 * 3) + pub_r001664_0_1) + 29) & 127;
  int stage_v_31_2 = (((stage_v_24_2 * 3) + pub_r001664_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = (((sec_r001664_7_1 * 3) + pub_r001664_5_1) + 34) & 127;
  int stage_v_32_2 = (((sec_r001664_7_2 * 3) + pub_r001664_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = (((stage_v_32_1 * 3) + pub_r001664_15_1) + 19) & 127;
  int stage_v_33_2 = (((stage_v_32_2 * 3) + pub_r001664_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((sec_r001664_4_1 * 3) + pub_r001664_20_1) + 28) & 127;
  int stage_v_34_2 = (((sec_r001664_4_2 * 3) + pub_r001664_20_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001664_9_1 * 2) + 5) & 63;
  int stage_v_35_2 = ((pub_r001664_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((sec_r001664_15_1 * 3) + pub_r001664_8_1) + 23) & 127;
  int stage_v_36_2 = (((sec_r001664_15_2 * 3) + pub_r001664_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = ((pub_r001664_2_1 * 2) + 31) & 63;
  int stage_v_37_2 = ((pub_r001664_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001664_3_1 * 2) + 20) & 63;
  int stage_v_38_2 = ((pub_r001664_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001664_11_1 * 2) + 32) & 63;
  int stage_v_39_2 = ((pub_r001664_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((stage_v_34_1 * 3) + pub_r001664_9_1) + 42) & 127;
  int stage_v_40_2 = (((stage_v_34_2 * 3) + pub_r001664_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = ((pub_r001664_0_1 * 2) + 27) & 63;
  int stage_v_41_2 = ((pub_r001664_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001664_4_1 * 2) + 37) & 63;
  int stage_v_42_2 = ((pub_r001664_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((sec_r001664_12_1 * 3) + pub_r001664_4_1) + 20) & 127;
  int stage_v_43_2 = (((sec_r001664_12_2 * 3) + pub_r001664_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = (((stage_v_32_1 * 3) + pub_r001664_23_1) + 29) & 127;
  int stage_v_44_2 = (((stage_v_32_2 * 3) + pub_r001664_23_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = ((pub_r001664_22_1 * 2) + 44) & 63;
  int stage_v_45_2 = ((pub_r001664_22_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((stage_v_33_1 * 3) + pub_r001664_8_1) + 42) & 127;
  int stage_v_46_2 = (((stage_v_33_2 * 3) + pub_r001664_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001664_3_1 * 2) + 15) & 63;
  int stage_v_47_2 = ((pub_r001664_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((helper_flow_0_1 * 3) + pub_r001664_11_1) + 33) & 127;
  int stage_v_48_2 = (((helper_flow_0_2 * 3) + pub_r001664_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = ((pub_r001664_22_1 * 2) + 34) & 63;
  int stage_v_49_2 = ((pub_r001664_22_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001664_19_1 * 2) + 27) & 63;
  int stage_v_50_2 = ((pub_r001664_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((helper_flow_2_1 * 3) + pub_r001664_10_1) + 29) & 127;
  int stage_v_51_2 = (((helper_flow_2_2 * 3) + pub_r001664_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = ((pub_r001664_10_1 * 2) + 15) & 63;
  int stage_v_52_2 = ((pub_r001664_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((stage_v_23_1 * 3) + pub_r001664_9_1) + 21) & 127;
  int stage_v_53_2 = (((stage_v_23_2 * 3) + pub_r001664_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = ((pub_r001664_12_1 * 2) + 49) & 63;
  int stage_v_54_2 = ((pub_r001664_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((stage_v_23_1 * 3) + pub_r001664_10_1) + 27) & 127;
  int stage_v_55_2 = (((stage_v_23_2 * 3) + pub_r001664_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = (((stage_v_14_1 * 3) + pub_r001664_17_1) + 40) & 127;
  int stage_v_56_2 = (((stage_v_14_2 * 3) + pub_r001664_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((stage_v_14_1 * 3) + pub_r001664_19_1) + 14) & 127;
  int stage_v_57_2 = (((stage_v_14_2 * 3) + pub_r001664_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((stage_v_53_1 * 3) + pub_r001664_18_1) + 7) & 127;
  int stage_v_58_2 = (((stage_v_53_2 * 3) + pub_r001664_18_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((stage_v_48_1 * 3) + pub_r001664_12_1) + 34) & 127;
  int stage_v_59_2 = (((stage_v_48_2 * 3) + pub_r001664_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = (((sec_r001664_12_1 * 3) + pub_r001664_11_1) + 11) & 127;
  int stage_v_60_2 = (((sec_r001664_12_2 * 3) + pub_r001664_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = ((pub_r001664_10_1 * 2) + 30) & 63;
  int stage_v_61_2 = ((pub_r001664_10_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (((stage_v_23_1 * 3) + pub_r001664_20_1) + 20) & 127;
  int stage_v_62_2 = (((stage_v_23_2 * 3) + pub_r001664_20_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((sec_r001664_16_1 * 3) + pub_r001664_21_1) + 29) & 127;
  int stage_v_63_2 = (((sec_r001664_16_2 * 3) + pub_r001664_21_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((stage_v_43_1 * 3) + pub_r001664_1_1) + 45) & 127;
  int stage_v_64_2 = (((stage_v_43_2 * 3) + pub_r001664_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((stage_v_12_1 * 3) + pub_r001664_5_1) + 40) & 127;
  int stage_v_65_2 = (((stage_v_12_2 * 3) + pub_r001664_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = ((pub_r001664_19_1 * 2) + 5) & 63;
  int stage_v_66_2 = ((pub_r001664_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((helper_flow_4_1 * 3) + pub_r001664_10_1) + 31) & 127;
  int stage_v_67_2 = (((helper_flow_4_2 * 3) + pub_r001664_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((helper_flow_3_1 * 3) + pub_r001664_0_1) + 31) & 127;
  int stage_v_68_2 = (((helper_flow_3_2 * 3) + pub_r001664_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = (((sec_r001664_4_1 * 3) + pub_r001664_17_1) + 18) & 127;
  int stage_v_69_2 = (((sec_r001664_4_2 * 3) + pub_r001664_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = (((stage_v_59_1 * 3) + pub_r001664_11_1) + 40) & 127;
  int stage_v_70_2 = (((stage_v_59_2 * 3) + pub_r001664_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = ((pub_r001664_1_1 * 2) + 42) & 63;
  int stage_v_71_2 = ((pub_r001664_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001664_8_1 * 2) + 17) & 63;
  int stage_v_72_2 = ((pub_r001664_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((helper_flow_1_1 * 3) + pub_r001664_18_1) + 10) & 127;
  int stage_v_73_2 = (((helper_flow_1_2 * 3) + pub_r001664_18_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = (((stage_v_64_1 * 3) + pub_r001664_2_1) + 19) & 127;
  int stage_v_74_2 = (((stage_v_64_2 * 3) + pub_r001664_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = ((pub_r001664_12_1 * 2) + 15) & 63;
  int stage_v_75_2 = ((pub_r001664_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (((stage_v_5_1 * 3) + pub_r001664_10_1) + 19) & 127;
  int stage_v_76_2 = (((stage_v_5_2 * 3) + pub_r001664_10_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = (((stage_v_40_1 * 3) + pub_r001664_3_1) + 39) & 127;
  int stage_v_77_2 = (((stage_v_40_2 * 3) + pub_r001664_3_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = (((sec_r001664_14_1 * 3) + pub_r001664_17_1) + 36) & 127;
  int stage_v_78_2 = (((sec_r001664_14_2 * 3) + pub_r001664_17_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = (((stage_v_78_1 * 3) + pub_r001664_20_1) + 4) & 127;
  int stage_v_79_2 = (((stage_v_78_2 * 3) + pub_r001664_20_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001664_8_1 * 2) + 40) & 63;
  int stage_v_80_2 = ((pub_r001664_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001664_10_1 * 2) + 13) & 63;
  int stage_v_81_2 = ((pub_r001664_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((stage_v_10_1 * 3) + pub_r001664_6_1) + 23) & 127;
  int stage_v_82_2 = (((stage_v_10_2 * 3) + pub_r001664_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001664_13_1 * 2) + 41) & 63;
  int stage_v_83_2 = ((pub_r001664_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001664_0_1 * 2) + 43) & 63;
  int stage_v_84_2 = ((pub_r001664_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (((stage_v_32_1 * 3) + pub_r001664_7_1) + 33) & 127;
  int stage_v_85_2 = (((stage_v_32_2 * 3) + pub_r001664_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001664_2_1 * 2) + 8) & 63;
  int stage_v_86_2 = ((pub_r001664_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_33_1 * 3) + pub_r001664_8_1) + 26) & 127;
  int stage_v_87_2 = (((stage_v_33_2 * 3) + pub_r001664_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = ((pub_r001664_17_1 * 2) + 40) & 63;
  int stage_v_88_2 = ((pub_r001664_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((stage_v_55_1 * 3) + pub_r001664_17_1) + 20) & 127;
  int stage_v_89_2 = (((stage_v_55_2 * 3) + pub_r001664_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = ((pub_r001664_6_1 * 2) + 7) & 63;
  int stage_v_90_2 = ((pub_r001664_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001664_19_1 * 2) + 13) & 63;
  int stage_v_91_2 = ((pub_r001664_19_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_46_1 * 3) + pub_r001664_4_1) + 11) & 127;
  int stage_v_92_2 = (((stage_v_46_2 * 3) + pub_r001664_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = ((pub_r001664_5_1 * 2) + 30) & 63;
  int stage_v_93_2 = ((pub_r001664_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001664_4_1 * 2) + 8) & 63;
  int stage_v_94_2 = ((pub_r001664_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((stage_v_23_1 * 3) + pub_r001664_5_1) + 41) & 127;
  int stage_v_95_2 = (((stage_v_23_2 * 3) + pub_r001664_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = (((stage_v_85_1 * 3) + pub_r001664_9_1) + 36) & 127;
  int stage_v_96_2 = (((stage_v_85_2 * 3) + pub_r001664_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001664_18_1 * 2) + 11) & 63;
  int stage_v_97_2 = ((pub_r001664_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_67_1 * 3) + pub_r001664_14_1) + 21) & 127;
  int stage_v_98_2 = (((stage_v_67_2 * 3) + pub_r001664_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = ((pub_r001664_13_1 * 2) + 11) & 63;
  int stage_v_99_2 = ((pub_r001664_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001664_6_1 * 2) + 22) & 63;
  int stage_v_100_2 = ((pub_r001664_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001664_13_1 * 2) + 7) & 63;
  int stage_v_101_2 = ((pub_r001664_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001664_3_1 * 2) + 34) & 63;
  int stage_v_102_2 = ((pub_r001664_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((stage_v_85_1 * 3) + pub_r001664_10_1) + 8) & 127;
  int stage_v_103_2 = (((stage_v_85_2 * 3) + pub_r001664_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = (((stage_v_3_1 * 3) + pub_r001664_10_1) + 21) & 127;
  int stage_v_104_2 = (((stage_v_3_2 * 3) + pub_r001664_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001664_9_1 * 2) + 24) & 63;
  int stage_v_105_2 = ((pub_r001664_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((sec_r001664_8_1 * 3) + pub_r001664_21_1) + 15) & 127;
  int stage_v_106_2 = (((sec_r001664_8_2 * 3) + pub_r001664_21_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = ((pub_r001664_4_1 * 2) + 49) & 63;
  int stage_v_107_2 = ((pub_r001664_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001664_21_1 * 2) + 36) & 63;
  int stage_v_108_2 = ((pub_r001664_21_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((stage_v_65_1 * 3) + pub_r001664_6_1) + 36) & 127;
  int stage_v_109_2 = (((stage_v_65_2 * 3) + pub_r001664_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((stage_v_1_1 * 3) + pub_r001664_17_1) + 22) & 127;
  int stage_v_110_2 = (((stage_v_1_2 * 3) + pub_r001664_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = (((stage_v_96_1 * 3) + pub_r001664_21_1) + 19) & 127;
  int stage_v_111_2 = (((stage_v_96_2 * 3) + pub_r001664_21_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = ((pub_r001664_19_1 * 2) + 35) & 63;
  int stage_v_112_2 = ((pub_r001664_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001664_9_1 * 2) + 18) & 63;
  int stage_v_113_2 = ((pub_r001664_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_69_1 * 3) + pub_r001664_22_1) + 31) & 127;
  int stage_v_114_2 = (((stage_v_69_2 * 3) + pub_r001664_22_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = (((stage_v_6_1 * 3) + pub_r001664_5_1) + 21) & 127;
  int stage_v_115_2 = (((stage_v_6_2 * 3) + pub_r001664_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = (((stage_v_14_1 * 3) + pub_r001664_14_1) + 11) & 127;
  int stage_v_116_2 = (((stage_v_14_2 * 3) + pub_r001664_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = ((pub_r001664_9_1 * 2) + 23) & 63;
  int stage_v_117_2 = ((pub_r001664_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((sec_r001664_16_1 * 3) + pub_r001664_18_1) + 39) & 127;
  int stage_v_118_2 = (((sec_r001664_16_2 * 3) + pub_r001664_18_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = (((stage_v_115_1 * 3) + pub_r001664_8_1) + 36) & 127;
  int stage_v_119_2 = (((stage_v_115_2 * 3) + pub_r001664_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = (((helper_flow_2_1 * 3) + pub_r001664_19_1) + 11) & 127;
  int stage_v_120_2 = (((helper_flow_2_2 * 3) + pub_r001664_19_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001664_3_1 * 2) + 44) & 63;
  int stage_v_121_2 = ((pub_r001664_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((sec_r001664_4_1 * 3) + pub_r001664_9_1) + 35) & 127;
  int stage_v_122_2 = (((sec_r001664_4_2 * 3) + pub_r001664_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = (((stage_v_33_1 * 3) + pub_r001664_13_1) + 30) & 127;
  int stage_v_123_2 = (((stage_v_33_2 * 3) + pub_r001664_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = ((pub_r001664_8_1 * 2) + 33) & 63;
  int stage_v_124_2 = ((pub_r001664_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001664_8_1 * 2) + 34) & 63;
  int stage_v_125_2 = ((pub_r001664_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_33_1 * 3) + pub_r001664_19_1) + 44) & 127;
  int stage_v_126_2 = (((stage_v_33_2 * 3) + pub_r001664_19_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = ((pub_r001664_9_1 * 2) + 19) & 63;
  int stage_v_127_2 = ((pub_r001664_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001664_12_1 * 2) + 26) & 63;
  int stage_v_128_2 = ((pub_r001664_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_23_1 * 3) + pub_r001664_16_1) + 18) & 127;
  int stage_v_129_2 = (((stage_v_23_2 * 3) + pub_r001664_16_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((stage_v_98_1 * 3) + pub_r001664_7_1) + 36) & 127;
  int stage_v_130_2 = (((stage_v_98_2 * 3) + pub_r001664_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001664_6_1 * 2) + 26) & 63;
  int stage_v_131_2 = ((pub_r001664_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001664_15_1 * 2) + 33) & 63;
  int stage_v_132_2 = ((pub_r001664_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001664_21_1 * 2) + 35) & 63;
  int stage_v_133_2 = ((pub_r001664_21_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001664_7_1 * 2) + 9) & 63;
  int stage_v_134_2 = ((pub_r001664_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001664_15_1 * 2) + 26) & 63;
  int stage_v_135_2 = ((pub_r001664_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_57_1 * 3) + pub_r001664_3_1) + 39) & 127;
  int stage_v_136_2 = (((stage_v_57_2 * 3) + pub_r001664_3_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = (((stage_v_40_1 * 3) + pub_r001664_1_1) + 18) & 127;
  int stage_v_137_2 = (((stage_v_40_2 * 3) + pub_r001664_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = ((pub_r001664_4_1 * 2) + 22) & 63;
  int stage_v_138_2 = ((pub_r001664_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((stage_v_87_1 * 3) + pub_r001664_0_1) + 28) & 127;
  int stage_v_139_2 = (((stage_v_87_2 * 3) + pub_r001664_0_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((stage_v_46_1 * 3) + pub_r001664_11_1) + 33) & 127;
  int stage_v_140_2 = (((stage_v_46_2 * 3) + pub_r001664_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = ((pub_r001664_15_1 * 2) + 7) & 63;
  int stage_v_141_2 = ((pub_r001664_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((stage_v_96_1 * 3) + pub_r001664_21_1) + 27) & 127;
  int stage_v_142_2 = (((stage_v_96_2 * 3) + pub_r001664_21_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = (((stage_v_78_1 * 3) + pub_r001664_20_1) + 32) & 127;
  int stage_v_143_2 = (((stage_v_78_2 * 3) + pub_r001664_20_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = ((pub_r001664_7_1 * 2) + 28) & 63;
  int stage_v_144_2 = ((pub_r001664_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001664_20_1 * 2) + 44) & 63;
  int stage_v_145_2 = ((pub_r001664_20_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001664_3_1 * 2) + 13) & 63;
  int stage_v_146_2 = ((pub_r001664_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001664_5_1 * 2) + 31) & 63;
  int stage_v_147_2 = ((pub_r001664_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_32_1 * 3) + pub_r001664_1_1) + 10) & 127;
  int stage_v_148_2 = (((stage_v_32_2 * 3) + pub_r001664_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((stage_v_118_1 * 3) + pub_r001664_15_1) + 42) & 127;
  int stage_v_149_2 = (((stage_v_118_2 * 3) + pub_r001664_15_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_19_1 * 3) + pub_r001664_18_1) + 13) & 127;
  int stage_v_150_2 = (((stage_v_19_2 * 3) + pub_r001664_18_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = ((pub_r001664_5_1 * 2) + 28) & 63;
  int stage_v_151_2 = ((pub_r001664_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_95_1 * 3) + pub_r001664_16_1) + 36) & 127;
  int stage_v_152_2 = (((stage_v_95_2 * 3) + pub_r001664_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = (((sec_r001664_15_1 * 3) + pub_r001664_6_1) + 21) & 127;
  int stage_v_153_2 = (((sec_r001664_15_2 * 3) + pub_r001664_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = (((stage_v_6_1 * 3) + pub_r001664_11_1) + 21) & 127;
  int stage_v_154_2 = (((stage_v_6_2 * 3) + pub_r001664_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = (((stage_v_60_1 * 3) + pub_r001664_20_1) + 24) & 127;
  int stage_v_155_2 = (((stage_v_60_2 * 3) + pub_r001664_20_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = ((pub_r001664_16_1 * 2) + 36) & 63;
  int stage_v_156_2 = ((pub_r001664_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001664_12_1 * 2) + 24) & 63;
  int stage_v_157_2 = ((pub_r001664_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (((stage_v_33_1 * 3) + pub_r001664_21_1) + 17) & 127;
  int stage_v_158_2 = (((stage_v_33_2 * 3) + pub_r001664_21_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((stage_v_116_1 * 3) + pub_r001664_12_1) + 3) & 127;
  int stage_v_159_2 = (((stage_v_116_2 * 3) + pub_r001664_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((stage_v_109_1 * 3) + pub_r001664_1_1) + 33) & 127;
  int stage_v_160_2 = (((stage_v_109_2 * 3) + pub_r001664_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = (((stage_v_57_1 * 3) + pub_r001664_5_1) + 39) & 127;
  int stage_v_161_2 = (((stage_v_57_2 * 3) + pub_r001664_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((sec_r001664_4_1 * 3) + pub_r001664_23_1) + 33) & 127;
  int stage_v_162_2 = (((sec_r001664_4_2 * 3) + pub_r001664_23_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = ((pub_r001664_9_1 * 2) + 29) & 63;
  int stage_v_163_2 = ((pub_r001664_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((stage_v_82_1 * 3) + pub_r001664_12_1) + 21) & 127;
  int stage_v_164_2 = (((stage_v_82_2 * 3) + pub_r001664_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = ((pub_r001664_2_1 * 2) + 18) & 63;
  int stage_v_165_2 = ((pub_r001664_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((stage_v_57_1 * 3) + pub_r001664_12_1) + 38) & 127;
  int stage_v_166_2 = (((stage_v_57_2 * 3) + pub_r001664_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = (((stage_v_154_1 * 3) + pub_r001664_12_1) + 21) & 127;
  int stage_v_167_2 = (((stage_v_154_2 * 3) + pub_r001664_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001664_12_1 * 2) + 22) & 63;
  int stage_v_168_2 = ((pub_r001664_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001664_5_1 * 2) + 23) & 63;
  int stage_v_169_2 = ((pub_r001664_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001664_19_1 * 2) + 34) & 63;
  int stage_v_170_2 = ((pub_r001664_19_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (((stage_v_12_1 * 3) + pub_r001664_2_1) + 6) & 127;
  int stage_v_171_2 = (((stage_v_12_2 * 3) + pub_r001664_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = ((pub_r001664_23_1 * 2) + 13) & 63;
  int stage_v_172_2 = ((pub_r001664_23_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((stage_v_123_1 * 3) + pub_r001664_0_1) + 17) & 127;
  int stage_v_173_2 = (((stage_v_123_2 * 3) + pub_r001664_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = (((stage_v_58_1 * 3) + pub_r001664_18_1) + 27) & 127;
  int stage_v_174_2 = (((stage_v_58_2 * 3) + pub_r001664_18_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = (((stage_v_103_1 * 3) + pub_r001664_23_1) + 10) & 127;
  int stage_v_175_2 = (((stage_v_103_2 * 3) + pub_r001664_23_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = ((pub_r001664_12_1 * 2) + 20) & 63;
  int stage_v_176_2 = ((pub_r001664_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((stage_v_174_1 * 3) + pub_r001664_9_1) + 21) & 127;
  int stage_v_177_2 = (((stage_v_174_2 * 3) + pub_r001664_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = (((stage_v_3_1 * 3) + pub_r001664_17_1) + 12) & 127;
  int stage_v_178_2 = (((stage_v_3_2 * 3) + pub_r001664_17_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = (((stage_v_6_1 * 3) + pub_r001664_21_1) + 35) & 127;
  int stage_v_179_2 = (((stage_v_6_2 * 3) + pub_r001664_21_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = (((stage_v_59_1 * 3) + pub_r001664_4_1) + 42) & 127;
  int stage_v_180_2 = (((stage_v_59_2 * 3) + pub_r001664_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((stage_v_7_1 * 3) + pub_r001664_11_1) + 38) & 127;
  int stage_v_181_2 = (((stage_v_7_2 * 3) + pub_r001664_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = ((pub_r001664_23_1 * 2) + 44) & 63;
  int stage_v_182_2 = ((pub_r001664_23_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001664_6_1 * 2) + 40) & 63;
  int stage_v_183_2 = ((pub_r001664_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_143_1 * 3) + pub_r001664_10_1) + 12) & 127;
  int stage_v_184_2 = (((stage_v_143_2 * 3) + pub_r001664_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = ((pub_r001664_7_1 * 2) + 40) & 63;
  int stage_v_185_2 = ((pub_r001664_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001664_1_1 * 2) + 15) & 63;
  int stage_v_186_2 = ((pub_r001664_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001664_5_1 * 2) + 35) & 63;
  int stage_v_187_2 = ((pub_r001664_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((helper_flow_4_1 * 3) + pub_r001664_11_1) + 24) & 127;
  int stage_v_188_2 = (((helper_flow_4_2 * 3) + pub_r001664_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001664_9_1 * 2) + 35) & 63;
  int stage_v_189_2 = ((pub_r001664_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001664_17_1 * 2) + 27) & 63;
  int stage_v_190_2 = ((pub_r001664_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_59_1 * 3) + pub_r001664_11_1) + 17) & 127;
  int stage_v_191_2 = (((stage_v_59_2 * 3) + pub_r001664_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((stage_v_162_1 * 3) + pub_r001664_0_1) + 36) & 127;
  int stage_v_192_2 = (((stage_v_162_2 * 3) + pub_r001664_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = (((sec_r001664_10_1 * 3) + pub_r001664_6_1) + 11) & 127;
  int stage_v_193_2 = (((sec_r001664_10_2 * 3) + pub_r001664_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001664_22_1 * 2) + 8) & 63;
  int stage_v_194_2 = ((pub_r001664_22_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (((stage_v_115_1 * 3) + pub_r001664_10_1) + 25) & 127;
  int stage_v_195_2 = (((stage_v_115_2 * 3) + pub_r001664_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = ((pub_r001664_1_1 * 2) + 35) & 63;
  int stage_v_196_2 = ((pub_r001664_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((stage_v_78_1 * 3) + pub_r001664_13_1) + 7) & 127;
  int stage_v_197_2 = (((stage_v_78_2 * 3) + pub_r001664_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((stage_v_92_1 * 3) + pub_r001664_15_1) + 23) & 127;
  int stage_v_198_2 = (((stage_v_92_2 * 3) + pub_r001664_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((stage_v_188_1 * 3) + pub_r001664_17_1) + 23) & 127;
  int stage_v_199_2 = (((stage_v_188_2 * 3) + pub_r001664_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001664_12_1 * 2) + 36) & 63;
  int stage_v_200_2 = ((pub_r001664_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001664_16_1 * 2) + 17) & 63;
  int stage_v_201_2 = ((pub_r001664_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001664_20_1 * 2) + 33) & 63;
  int stage_v_202_2 = ((pub_r001664_20_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001664_23_1 * 2) + 42) & 63;
  int stage_v_203_2 = ((pub_r001664_23_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((stage_v_73_1 * 3) + pub_r001664_2_1) + 41) & 127;
  int stage_v_204_2 = (((stage_v_73_2 * 3) + pub_r001664_2_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = ((pub_r001664_14_1 * 2) + 17) & 63;
  int stage_v_205_2 = ((pub_r001664_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001664_7_1 * 2) + 10) & 63;
  int stage_v_206_2 = ((pub_r001664_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001664_17_1 * 2) + 10) & 63;
  int stage_v_207_2 = ((pub_r001664_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001664_15_1 * 2) + 17) & 63;
  int stage_v_208_2 = ((pub_r001664_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001664_6_1 * 2) + 25) & 63;
  int stage_v_209_2 = ((pub_r001664_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_173_1 * 3) + pub_r001664_8_1) + 37) & 127;
  int stage_v_210_2 = (((stage_v_173_2 * 3) + pub_r001664_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_109_1 * 3) + pub_r001664_8_1) + 26) & 127;
  int stage_v_211_2 = (((stage_v_109_2 * 3) + pub_r001664_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001664_9_1 * 2) + 13) & 63;
  int stage_v_212_2 = ((pub_r001664_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_137_1 * 3) + pub_r001664_0_1) + 32) & 127;
  int stage_v_213_2 = (((stage_v_137_2 * 3) + pub_r001664_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001664_11_1 * 2) + 19) & 63;
  int stage_v_214_2 = ((pub_r001664_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001664_3_1 * 2) + 9) & 63;
  int stage_v_215_2 = ((pub_r001664_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001664_12_1 * 2) + 15) & 63;
  int stage_v_216_2 = ((pub_r001664_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001664_14_1 * 2) + 12) & 63;
  int stage_v_217_2 = ((pub_r001664_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = (((stage_v_123_1 * 3) + pub_r001664_20_1) + 4) & 127;
  int stage_v_218_2 = (((stage_v_123_2 * 3) + pub_r001664_20_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = (((stage_v_137_1 * 3) + pub_r001664_17_1) + 44) & 127;
  int stage_v_219_2 = (((stage_v_137_2 * 3) + pub_r001664_17_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = ((pub_r001664_23_1 * 2) + 8) & 63;
  int stage_v_220_2 = ((pub_r001664_23_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001664_18_1 * 2) + 6) & 63;
  int stage_v_221_2 = ((pub_r001664_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_96_1 * 3) + pub_r001664_21_1) + 3) & 127;
  int stage_v_222_2 = (((stage_v_96_2 * 3) + pub_r001664_21_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001664_9_1 * 2) + 40) & 63;
  int stage_v_223_2 = ((pub_r001664_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001664_8_1 * 2) + 44) & 63;
  int stage_v_224_2 = ((pub_r001664_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_56_1 * 3) + pub_r001664_23_1) + 41) & 127;
  int stage_v_225_2 = (((stage_v_56_2 * 3) + pub_r001664_23_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = ((pub_r001664_19_1 * 2) + 49) & 63;
  int stage_v_226_2 = ((pub_r001664_19_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((stage_v_89_1 * 3) + pub_r001664_0_1) + 22) & 127;
  int stage_v_227_2 = (((stage_v_89_2 * 3) + pub_r001664_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = (((stage_v_57_1 * 3) + pub_r001664_2_1) + 24) & 127;
  int stage_v_228_2 = (((stage_v_57_2 * 3) + pub_r001664_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = ((pub_r001664_13_1 * 2) + 43) & 63;
  int stage_v_229_2 = ((pub_r001664_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001664_8_1 * 2) + 23) & 63;
  int stage_v_230_2 = ((pub_r001664_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((stage_v_23_1 * 3) + pub_r001664_19_1) + 40) & 127;
  int stage_v_231_2 = (((stage_v_23_2 * 3) + pub_r001664_19_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = (((sec_r001664_6_1 * 3) + pub_r001664_7_1) + 9) & 127;
  int stage_v_232_2 = (((sec_r001664_6_2 * 3) + pub_r001664_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = (((stage_v_78_1 * 3) + pub_r001664_7_1) + 26) & 127;
  int stage_v_233_2 = (((stage_v_78_2 * 3) + pub_r001664_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = ((pub_r001664_20_1 * 2) + 6) & 63;
  int stage_v_234_2 = ((pub_r001664_20_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001664_9_1 * 2) + 34) & 63;
  int stage_v_235_2 = ((pub_r001664_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001664_9_1 * 2) + 36) & 63;
  int stage_v_236_2 = ((pub_r001664_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001664_11_1 * 2) + 31) & 63;
  int stage_v_237_2 = ((pub_r001664_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001664_7_1 * 2) + 36) & 63;
  int stage_v_238_2 = ((pub_r001664_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = (((sec_r001664_2_1 * 3) + pub_r001664_7_1) + 9) & 127;
  int stage_v_239_2 = (((sec_r001664_2_2 * 3) + pub_r001664_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = ((pub_r001664_19_1 * 2) + 34) & 63;
  int stage_v_240_2 = ((pub_r001664_19_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = (((stage_v_74_1 * 3) + pub_r001664_20_1) + 20) & 127;
  int stage_v_241_2 = (((stage_v_74_2 * 3) + pub_r001664_20_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = ((pub_r001664_22_1 * 2) + 47) & 63;
  int stage_v_242_2 = ((pub_r001664_22_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = (((stage_v_152_1 * 3) + pub_r001664_20_1) + 21) & 127;
  int stage_v_243_2 = (((stage_v_152_2 * 3) + pub_r001664_20_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_23_1 * 3) + pub_r001664_10_1) + 41) & 127;
  int stage_v_244_2 = (((stage_v_23_2 * 3) + pub_r001664_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((sec_r001664_0_1 * 3) + pub_r001664_20_1) + 41) & 127;
  int stage_v_245_2 = (((sec_r001664_0_2 * 3) + pub_r001664_20_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001664_20_1 * 2) + 49) & 63;
  int stage_v_246_2 = ((pub_r001664_20_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001664_18_1 * 2) + 36) & 63;
  int stage_v_247_2 = ((pub_r001664_18_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((stage_v_44_1 * 3) + pub_r001664_1_1) + 18) & 127;
  int stage_v_248_2 = (((stage_v_44_2 * 3) + pub_r001664_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((stage_v_137_1 * 3) + pub_r001664_19_1) + 24) & 127;
  int stage_v_249_2 = (((stage_v_137_2 * 3) + pub_r001664_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_31_1 * 3) + pub_r001664_5_1) + 10) & 127;
  int stage_v_250_2 = (((stage_v_31_2 * 3) + pub_r001664_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((stage_v_174_1 * 3) + pub_r001664_12_1) + 38) & 127;
  int stage_v_251_2 = (((stage_v_174_2 * 3) + pub_r001664_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = ((pub_r001664_5_1 * 2) + 24) & 63;
  int stage_v_252_2 = ((pub_r001664_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = (((stage_v_53_1 * 3) + pub_r001664_3_1) + 30) & 127;
  int stage_v_253_2 = (((stage_v_53_2 * 3) + pub_r001664_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = ((pub_r001664_4_1 * 2) + 20) & 63;
  int stage_v_254_2 = ((pub_r001664_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001664_15_1 * 2) + 10) & 63;
  int stage_v_255_2 = ((pub_r001664_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001664_0_1 * 2) + 8) & 63;
  int stage_v_256_2 = ((pub_r001664_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = (((stage_v_159_1 * 3) + pub_r001664_9_1) + 8) & 127;
  int stage_v_257_2 = (((stage_v_159_2 * 3) + pub_r001664_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = ((pub_r001664_0_1 * 2) + 40) & 63;
  int stage_v_258_2 = ((pub_r001664_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = (((stage_v_60_1 * 3) + pub_r001664_21_1) + 15) & 127;
  int stage_v_259_2 = (((stage_v_60_2 * 3) + pub_r001664_21_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = ((pub_r001664_16_1 * 2) + 31) & 63;
  int stage_v_260_2 = ((pub_r001664_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_89_1 * 3) + pub_r001664_14_1) + 30) & 127;
  int stage_v_261_2 = (((stage_v_89_2 * 3) + pub_r001664_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = (((stage_v_177_1 * 3) + pub_r001664_8_1) + 33) & 127;
  int stage_v_262_2 = (((stage_v_177_2 * 3) + pub_r001664_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = (((stage_v_56_1 * 3) + pub_r001664_11_1) + 40) & 127;
  int stage_v_263_2 = (((stage_v_56_2 * 3) + pub_r001664_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001664_3_1 * 2) + 24) & 63;
  int stage_v_264_2 = ((pub_r001664_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001664_0_1 * 2) + 14) & 63;
  int stage_v_265_2 = ((pub_r001664_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001664_2_1 * 2) + 40) & 63;
  int stage_v_266_2 = ((pub_r001664_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001664_11_1 * 2) + 24) & 63;
  int stage_v_267_2 = ((pub_r001664_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001664_13_1 * 2) + 38) & 63;
  int stage_v_268_2 = ((pub_r001664_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001664_3_1 * 2) + 19) & 63;
  int stage_v_269_2 = ((pub_r001664_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = (((helper_flow_0_1 * 3) + pub_r001664_7_1) + 45) & 127;
  int stage_v_270_2 = (((helper_flow_0_2 * 3) + pub_r001664_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = ((pub_r001664_19_1 * 2) + 47) & 63;
  int stage_v_271_2 = ((pub_r001664_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_270_1 * 3) + pub_r001664_17_1) + 26) & 127;
  int stage_v_272_2 = (((stage_v_270_2 * 3) + pub_r001664_17_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((stage_v_77_1 * 3) + pub_r001664_1_1) + 36) & 127;
  int stage_v_273_2 = (((stage_v_77_2 * 3) + pub_r001664_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001664_16_1 * 2) + 29) & 63;
  int stage_v_274_2 = ((pub_r001664_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = (((stage_v_180_1 * 3) + pub_r001664_23_1) + 31) & 127;
  int stage_v_275_2 = (((stage_v_180_2 * 3) + pub_r001664_23_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = ((pub_r001664_13_1 * 2) + 18) & 63;
  int stage_v_276_2 = ((pub_r001664_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = (((sec_r001664_9_1 * 3) + pub_r001664_18_1) + 30) & 127;
  int stage_v_277_2 = (((sec_r001664_9_2 * 3) + pub_r001664_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = ((pub_r001664_3_1 * 2) + 13) & 63;
  int stage_v_278_2 = ((pub_r001664_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = (((stage_v_155_1 * 3) + pub_r001664_3_1) + 23) & 127;
  int stage_v_279_2 = (((stage_v_155_2 * 3) + pub_r001664_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = ((pub_r001664_10_1 * 2) + 28) & 63;
  int stage_v_280_2 = ((pub_r001664_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001664_17_1 * 2) + 8) & 63;
  int stage_v_281_2 = ((pub_r001664_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((stage_v_181_1 * 3) + pub_r001664_0_1) + 8) & 127;
  int stage_v_282_2 = (((stage_v_181_2 * 3) + pub_r001664_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = (((sec_r001664_7_1 * 3) + pub_r001664_4_1) + 3) & 127;
  int stage_v_283_2 = (((sec_r001664_7_2 * 3) + pub_r001664_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = ((pub_r001664_2_1 * 2) + 17) & 63;
  int stage_v_284_2 = ((pub_r001664_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001664_23_1 * 2) + 44) & 63;
  int stage_v_285_2 = ((pub_r001664_23_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001664_4_1 * 2) + 41) & 63;
  int stage_v_286_2 = ((pub_r001664_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = (((stage_v_69_1 * 3) + pub_r001664_3_1) + 3) & 127;
  int stage_v_287_2 = (((stage_v_69_2 * 3) + pub_r001664_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((stage_v_57_1 * 3) + pub_r001664_12_1) + 27) & 127;
  int stage_v_288_2 = (((stage_v_57_2 * 3) + pub_r001664_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = ((pub_r001664_7_1 * 2) + 22) & 63;
  int stage_v_289_2 = ((pub_r001664_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = (((stage_v_27_1 * 3) + pub_r001664_8_1) + 20) & 127;
  int stage_v_290_2 = (((stage_v_27_2 * 3) + pub_r001664_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = (((stage_v_3_1 * 3) + pub_r001664_2_1) + 40) & 127;
  int stage_v_291_2 = (((stage_v_3_2 * 3) + pub_r001664_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001664_1_1 * 2) + 33) & 63;
  int stage_v_292_2 = ((pub_r001664_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001664_16_1 * 2) + 10) & 63;
  int stage_v_293_2 = ((pub_r001664_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = (((stage_v_62_1 * 3) + pub_r001664_8_1) + 38) & 127;
  int stage_v_294_2 = (((stage_v_62_2 * 3) + pub_r001664_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = ((pub_r001664_9_1 * 2) + 40) & 63;
  int stage_v_295_2 = ((pub_r001664_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((pub_r001664_5_1 * 2) + 22) & 63;
  int stage_v_296_2 = ((pub_r001664_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001664_16_1 * 2) + 33) & 63;
  int stage_v_297_2 = ((pub_r001664_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((stage_v_148_1 * 3) + pub_r001664_13_1) + 35) & 127;
  int stage_v_298_2 = (((stage_v_148_2 * 3) + pub_r001664_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = (((stage_v_65_1 * 3) + pub_r001664_1_1) + 36) & 127;
  int stage_v_299_2 = (((stage_v_65_2 * 3) + pub_r001664_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = ((pub_r001664_17_1 * 2) + 42) & 63;
  int stage_v_300_2 = ((pub_r001664_17_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001664_6_1 * 2) + 45) & 63;
  int stage_v_301_2 = ((pub_r001664_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001664_0_1 * 2) + 24) & 63;
  int stage_v_302_2 = ((pub_r001664_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001664_7_1 * 2) + 27) & 63;
  int stage_v_303_2 = ((pub_r001664_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = (((stage_v_188_1 * 3) + pub_r001664_7_1) + 30) & 127;
  int stage_v_304_2 = (((stage_v_188_2 * 3) + pub_r001664_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001664_12_1 * 2) + 40) & 63;
  int stage_v_305_2 = ((pub_r001664_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_175_1 * 3) + pub_r001664_22_1) + 15) & 127;
  int stage_v_306_2 = (((stage_v_175_2 * 3) + pub_r001664_22_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = ((pub_r001664_13_1 * 2) + 36) & 63;
  int stage_v_307_2 = ((pub_r001664_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = (((helper_flow_1_1 * 3) + pub_r001664_14_1) + 45) & 127;
  int stage_v_308_2 = (((helper_flow_1_2 * 3) + pub_r001664_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = ((pub_r001664_7_1 * 2) + 47) & 63;
  int stage_v_309_2 = ((pub_r001664_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = (((stage_v_166_1 * 3) + pub_r001664_6_1) + 3) & 127;
  int stage_v_310_2 = (((stage_v_166_2 * 3) + pub_r001664_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = ((pub_r001664_8_1 * 2) + 38) & 63;
  int stage_v_311_2 = ((pub_r001664_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = (((stage_v_34_1 * 3) + pub_r001664_2_1) + 15) & 127;
  int stage_v_312_2 = (((stage_v_34_2 * 3) + pub_r001664_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = ((pub_r001664_22_1 * 2) + 29) & 63;
  int stage_v_313_2 = ((pub_r001664_22_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_55_1 * 3) + pub_r001664_2_1) + 30) & 127;
  int stage_v_314_2 = (((stage_v_55_2 * 3) + pub_r001664_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = (((stage_v_5_1 * 3) + pub_r001664_5_1) + 9) & 127;
  int stage_v_315_2 = (((stage_v_5_2 * 3) + pub_r001664_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_139_1 * 3) + pub_r001664_17_1) + 18) & 127;
  int stage_v_316_2 = (((stage_v_139_2 * 3) + pub_r001664_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((stage_v_162_1 * 3) + pub_r001664_8_1) + 33) & 127;
  int stage_v_317_2 = (((stage_v_162_2 * 3) + pub_r001664_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = ((pub_r001664_22_1 * 2) + 25) & 63;
  int stage_v_318_2 = ((pub_r001664_22_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001664_11_1 * 2) + 7) & 63;
  int stage_v_319_2 = ((pub_r001664_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001664_18_1 * 2) + 18) & 63;
  int stage_v_320_2 = ((pub_r001664_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((pub_r001664_17_1 * 2) + 46) & 63;
  int stage_v_321_2 = ((pub_r001664_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = (((stage_v_148_1 * 3) + pub_r001664_22_1) + 32) & 127;
  int stage_v_322_2 = (((stage_v_148_2 * 3) + pub_r001664_22_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = (((stage_v_231_1 * 3) + pub_r001664_4_1) + 21) & 127;
  int stage_v_323_2 = (((stage_v_231_2 * 3) + pub_r001664_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = ((pub_r001664_18_1 * 2) + 13) & 63;
  int stage_v_324_2 = ((pub_r001664_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((pub_r001664_11_1 * 2) + 50) & 63;
  int stage_v_325_2 = ((pub_r001664_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001664_20_1 * 2) + 23) & 63;
  int stage_v_326_2 = ((pub_r001664_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = (((stage_v_76_1 * 3) + pub_r001664_4_1) + 24) & 127;
  int stage_v_327_2 = (((stage_v_76_2 * 3) + pub_r001664_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = ((pub_r001664_11_1 * 2) + 37) & 63;
  int stage_v_328_2 = ((pub_r001664_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = (((stage_v_180_1 * 3) + pub_r001664_22_1) + 7) & 127;
  int stage_v_329_2 = (((stage_v_180_2 * 3) + pub_r001664_22_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = (((stage_v_304_1 * 3) + pub_r001664_5_1) + 27) & 127;
  int stage_v_330_2 = (((stage_v_304_2 * 3) + pub_r001664_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = ((pub_r001664_9_1 * 2) + 16) & 63;
  int stage_v_331_2 = ((pub_r001664_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001664_6_1 * 2) + 23) & 63;
  int stage_v_332_2 = ((pub_r001664_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = (((stage_v_222_1 * 3) + pub_r001664_15_1) + 45) & 127;
  int stage_v_333_2 = (((stage_v_222_2 * 3) + pub_r001664_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = (((stage_v_327_1 * 3) + pub_r001664_17_1) + 25) & 127;
  int stage_v_334_2 = (((stage_v_327_2 * 3) + pub_r001664_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001664_19_1 * 2) + 31) & 63;
  int stage_v_335_2 = ((pub_r001664_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001664_6_1 * 2) + 21) & 63;
  int stage_v_336_2 = ((pub_r001664_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = (((stage_v_109_1 * 3) + pub_r001664_14_1) + 33) & 127;
  int stage_v_337_2 = (((stage_v_109_2 * 3) + pub_r001664_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = ((pub_r001664_5_1 * 2) + 5) & 63;
  int stage_v_338_2 = ((pub_r001664_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001664_4_1 * 2) + 49) & 63;
  int stage_v_339_2 = ((pub_r001664_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001664_10_1 * 2) + 45) & 63;
  int stage_v_340_2 = ((pub_r001664_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001664_9_1 * 2) + 17) & 63;
  int stage_v_341_2 = ((pub_r001664_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = (((stage_v_60_1 * 3) + pub_r001664_8_1) + 10) & 127;
  int stage_v_342_2 = (((stage_v_60_2 * 3) + pub_r001664_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = ((pub_r001664_15_1 * 2) + 47) & 63;
  int stage_v_343_2 = ((pub_r001664_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001664_15_1 * 2) + 27) & 63;
  int stage_v_344_2 = ((pub_r001664_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((pub_r001664_23_1 * 2) + 15) & 63;
  int stage_v_345_2 = ((pub_r001664_23_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = (((stage_v_46_1 * 3) + pub_r001664_10_1) + 38) & 127;
  int stage_v_346_2 = (((stage_v_46_2 * 3) + pub_r001664_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001664_22_1 * 2) + 14) & 63;
  int stage_v_347_2 = ((pub_r001664_22_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((stage_v_10_1 * 3) + pub_r001664_10_1) + 28) & 127;
  int stage_v_348_2 = (((stage_v_10_2 * 3) + pub_r001664_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_129_1 * 3) + pub_r001664_9_1) + 19) & 127;
  int stage_v_349_2 = (((stage_v_129_2 * 3) + pub_r001664_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_19_1 * 3) + pub_r001664_17_1) + 7) & 127;
  int stage_v_350_2 = (((stage_v_19_2 * 3) + pub_r001664_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001664_15_1 * 2) + 12) & 63;
  int stage_v_351_2 = ((pub_r001664_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = (((stage_v_60_1 * 3) + pub_r001664_15_1) + 19) & 127;
  int stage_v_352_2 = (((stage_v_60_2 * 3) + pub_r001664_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = (((stage_v_279_1 * 3) + pub_r001664_6_1) + 38) & 127;
  int stage_v_353_2 = (((stage_v_279_2 * 3) + pub_r001664_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = ((pub_r001664_16_1 * 2) + 31) & 63;
  int stage_v_354_2 = ((pub_r001664_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001664_8_1 * 2) + 22) & 63;
  int stage_v_355_2 = ((pub_r001664_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001664_16_1 * 2) + 28) & 63;
  int stage_v_356_2 = ((pub_r001664_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = (((stage_v_310_1 * 3) + pub_r001664_21_1) + 37) & 127;
  int stage_v_357_2 = (((stage_v_310_2 * 3) + pub_r001664_21_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = (((helper_flow_4_1 * 3) + pub_r001664_18_1) + 44) & 127;
  int stage_v_358_2 = (((helper_flow_4_2 * 3) + pub_r001664_18_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = (((stage_v_177_1 * 3) + pub_r001664_6_1) + 34) & 127;
  int stage_v_359_2 = (((stage_v_177_2 * 3) + pub_r001664_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = (((stage_v_85_1 * 3) + pub_r001664_6_1) + 41) & 127;
  int stage_v_360_2 = (((stage_v_85_2 * 3) + pub_r001664_6_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = ((pub_r001664_10_1 * 2) + 40) & 63;
  int stage_v_361_2 = ((pub_r001664_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = (((stage_v_103_1 * 3) + pub_r001664_11_1) + 28) & 127;
  int stage_v_362_2 = (((stage_v_103_2 * 3) + pub_r001664_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = ((pub_r001664_16_1 * 2) + 5) & 63;
  int stage_v_363_2 = ((pub_r001664_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001664_20_1 * 2) + 34) & 63;
  int stage_v_364_2 = ((pub_r001664_20_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001664_7_1 * 2) + 46) & 63;
  int stage_v_365_2 = ((pub_r001664_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001664_2_1 * 2) + 41) & 63;
  int stage_v_366_2 = ((pub_r001664_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((stage_v_44_1 * 3) + pub_r001664_12_1) + 3) & 127;
  int stage_v_367_2 = (((stage_v_44_2 * 3) + pub_r001664_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001664_3_1 * 2) + 31) & 63;
  int stage_v_368_2 = ((pub_r001664_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001664_20_1 * 2) + 14) & 63;
  int stage_v_369_2 = ((pub_r001664_20_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001664_11_1 * 2) + 17) & 63;
  int stage_v_370_2 = ((pub_r001664_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = (((stage_v_227_1 * 3) + pub_r001664_3_1) + 21) & 127;
  int stage_v_371_2 = (((stage_v_227_2 * 3) + pub_r001664_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001664_14_1 * 2) + 13) & 63;
  int stage_v_372_2 = ((pub_r001664_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001664_23_1 * 2) + 33) & 63;
  int stage_v_373_2 = ((pub_r001664_23_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((stage_v_197_1 * 3) + pub_r001664_22_1) + 15) & 127;
  int stage_v_374_2 = (((stage_v_197_2 * 3) + pub_r001664_22_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_114_1 * 3) + pub_r001664_18_1) + 32) & 127;
  int stage_v_375_2 = (((stage_v_114_2 * 3) + pub_r001664_18_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_67_1 * 3) + pub_r001664_10_1) + 13) & 127;
  int stage_v_376_2 = (((stage_v_67_2 * 3) + pub_r001664_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = (((stage_v_77_1 * 3) + pub_r001664_16_1) + 13) & 127;
  int stage_v_377_2 = (((stage_v_77_2 * 3) + pub_r001664_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((stage_v_195_1 * 3) + pub_r001664_16_1) + 19) & 127;
  int stage_v_378_2 = (((stage_v_195_2 * 3) + pub_r001664_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = ((pub_r001664_13_1 * 2) + 46) & 63;
  int stage_v_379_2 = ((pub_r001664_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((pub_r001664_18_1 * 2) + 39) & 63;
  int stage_v_380_2 = ((pub_r001664_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001664_12_1 * 2) + 50) & 63;
  int stage_v_381_2 = ((pub_r001664_12_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((stage_v_129_1 * 3) + pub_r001664_23_1) + 41) & 127;
  int stage_v_382_2 = (((stage_v_129_2 * 3) + pub_r001664_23_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = (((stage_v_322_1 * 3) + pub_r001664_19_1) + 12) & 127;
  int stage_v_383_2 = (((stage_v_322_2 * 3) + pub_r001664_19_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = ((pub_r001664_16_1 * 2) + 32) & 63;
  int stage_v_384_2 = ((pub_r001664_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001664_12_1 * 2) + 23) & 63;
  int stage_v_385_2 = ((pub_r001664_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = (((stage_v_161_1 * 3) + pub_r001664_5_1) + 9) & 127;
  int stage_v_386_2 = (((stage_v_161_2 * 3) + pub_r001664_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = (((stage_v_243_1 * 3) + pub_r001664_22_1) + 27) & 127;
  int stage_v_387_2 = (((stage_v_243_2 * 3) + pub_r001664_22_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = (((stage_v_219_1 * 3) + pub_r001664_8_1) + 23) & 127;
  int stage_v_388_2 = (((stage_v_219_2 * 3) + pub_r001664_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = (((stage_v_197_1 * 3) + pub_r001664_21_1) + 22) & 127;
  int stage_v_389_2 = (((stage_v_197_2 * 3) + pub_r001664_21_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = (((helper_flow_3_1 * 3) + pub_r001664_2_1) + 42) & 127;
  int stage_v_390_2 = (((helper_flow_3_2 * 3) + pub_r001664_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = (((stage_v_179_1 * 3) + pub_r001664_15_1) + 35) & 127;
  int stage_v_391_2 = (((stage_v_179_2 * 3) + pub_r001664_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_241_1 * 3) + pub_r001664_2_1) + 10) & 127;
  int stage_v_392_2 = (((stage_v_241_2 * 3) + pub_r001664_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = (((stage_v_388_1 * 3) + pub_r001664_22_1) + 21) & 127;
  int stage_v_393_2 = (((stage_v_388_2 * 3) + pub_r001664_22_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = ((pub_r001664_17_1 * 2) + 11) & 63;
  int stage_v_394_2 = ((pub_r001664_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = (((stage_v_227_1 * 3) + pub_r001664_9_1) + 25) & 127;
  int stage_v_395_2 = (((stage_v_227_2 * 3) + pub_r001664_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = ((pub_r001664_1_1 * 2) + 47) & 63;
  int stage_v_396_2 = ((pub_r001664_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001664_16_1 == pub_r001664_16_2);
  __CPROVER_assume(sec_r001664_7_1 != sec_r001664_7_2);
  __CPROVER_assume(pub_r001664_5_1 == pub_r001664_5_2);
  __CPROVER_assume(pub_r001664_9_1 == pub_r001664_9_2);
  __CPROVER_assume(sec_r001664_8_1 != sec_r001664_8_2);
  __CPROVER_assume(pub_r001664_18_1 == pub_r001664_18_2);
  __CPROVER_assume(pub_r001664_21_1 == pub_r001664_21_2);
  __CPROVER_assume(sec_r001664_9_1 != sec_r001664_9_2);
  __CPROVER_assume(sec_r001664_2_1 != sec_r001664_2_2);
  __CPROVER_assume(pub_r001664_12_1 == pub_r001664_12_2);
  __CPROVER_assume(sec_r001664_5_1 != sec_r001664_5_2);
  __CPROVER_assume(pub_r001664_19_1 == pub_r001664_19_2);
  __CPROVER_assume(sec_r001664_1_1 != sec_r001664_1_2);
  __CPROVER_assume(pub_r001664_2_1 == pub_r001664_2_2);
  __CPROVER_assume(sec_r001664_13_1 != sec_r001664_13_2);
  __CPROVER_assume(pub_r001664_20_1 == pub_r001664_20_2);
  __CPROVER_assume(pub_r001664_3_1 == pub_r001664_3_2);
  __CPROVER_assume(sec_r001664_0_1 != sec_r001664_0_2);
  __CPROVER_assume(pub_r001664_10_1 == pub_r001664_10_2);
  __CPROVER_assume(pub_r001664_6_1 == pub_r001664_6_2);
  __CPROVER_assume(sec_r001664_10_1 != sec_r001664_10_2);
  __CPROVER_assume(pub_r001664_4_1 == pub_r001664_4_2);
  __CPROVER_assume(pub_r001664_11_1 == pub_r001664_11_2);
  __CPROVER_assume(pub_r001664_15_1 == pub_r001664_15_2);
  __CPROVER_assume(pub_r001664_13_1 == pub_r001664_13_2);
  __CPROVER_assume(sec_r001664_6_1 != sec_r001664_6_2);
  __CPROVER_assume(pub_r001664_17_1 == pub_r001664_17_2);
  __CPROVER_assume(pub_r001664_22_1 == pub_r001664_22_2);
  __CPROVER_assume(sec_r001664_12_1 != sec_r001664_12_2);
  __CPROVER_assume(pub_r001664_7_1 == pub_r001664_7_2);
  __CPROVER_assume(pub_r001664_14_1 == pub_r001664_14_2);
  __CPROVER_assume(pub_r001664_0_1 == pub_r001664_0_2);
  __CPROVER_assume(sec_r001664_16_1 != sec_r001664_16_2);
  __CPROVER_assume(sec_r001664_4_1 != sec_r001664_4_2);
  __CPROVER_assume(sec_r001664_15_1 != sec_r001664_15_2);
  __CPROVER_assume(pub_r001664_1_1 == pub_r001664_1_2);
  __CPROVER_assume(pub_r001664_23_1 == pub_r001664_23_2);
  __CPROVER_assume(sec_r001664_3_1 != sec_r001664_3_2);
  __CPROVER_assume(pub_r001664_8_1 == pub_r001664_8_2);
  __CPROVER_assume(sec_r001664_11_1 != sec_r001664_11_2);
  __CPROVER_assume(sec_r001664_14_1 != sec_r001664_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
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
}


