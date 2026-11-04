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
struct MatrixBlock_R000692_9213_0
{
  unsigned char trace;
  int determinant;
  int dim;
  int buffer[3];
};
struct Transaction_R000692_9213_1
{
  short rate;
  short auth_code;
  short fee;
  int buffer[3];
};
union ColorPixel_R000692_9213_0
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
void fn_R000692_9213_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000692_9213_0 st_1 = {0};
  struct MatrixBlock_R000692_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_47_1 = 0;
  int tally_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_47_1 = ((tally_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_47_2 = ((tally_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_47_1) & 127;
    acc_2 = (acc_2 + tally_47_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_73_1 = local_arr_1[aux_1 % 3];
  int accumulator_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_47_1 == tally_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_73_1 == accumulator_73_2);
}

int fn_R000692_9213_0(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000692_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_47 = ((tally_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_47) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int accumulator_73 = local_arr[aux % 3];
  acc = (acc + (accumulator_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000692_9213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st_1 = {0};
  struct Transaction_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tracker_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_40_1)
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

  switch (tracker_40_2)
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
  int pivot_95_1 = local_arr_1[aux_1 % 3];
  int pivot_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_95_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_40_1 == tracker_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_95_1 == pivot_95_2);
}

int fn_R000692_9213_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tracker_40 = (aux + st.buffer[1]) & 3;
  switch (tracker_40)
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
  int pivot_95 = local_arr[aux % 3];
  acc = (acc + (pivot_95 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000692_9213_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st_1 = {0};
  struct Transaction_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int margin_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_96_1)
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

  switch (margin_96_2)
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

  int quotient_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_24_1) & 63;
  aux_2 = (aux_2 + quotient_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_71_1 = local_arr_1[aux_1 % 3];
  int damping_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_96_1 == margin_96_2);
  assert(quotient_24_1 == quotient_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_71_1 == damping_71_2);
}

int fn_R000692_9213_2(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int margin_96 = (aux + st.buffer[1]) & 3;
  switch (margin_96)
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

  int quotient_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_24) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int damping_71 = local_arr[aux % 3];
  acc = (acc + (damping_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000692_9213_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st_1 = {0};
  struct Transaction_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int pivot_81_1 = 0;
  int pivot_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_81_1 = ((pivot_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_81_2 = ((pivot_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_81_1) & 127;
    acc_2 = (acc_2 + pivot_81_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_29_1) & 63;
  aux_2 = (aux_2 + factor_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_81_1 == pivot_81_2);
  assert(factor_29_1 == factor_29_2);
}

int fn_R000692_9213_3(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int pivot_81 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_81 = ((pivot_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_81) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_29) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000692_9213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st_1 = {0};
  struct Transaction_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_41_1 > 24)
  {
    acc_1 = ((acc_1 + (sample_41_1 * 2)) + 5) & 127;
    aux_1 ^= sample_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_41_2 > 24)
  {
    acc_2 = ((acc_2 + (sample_41_2 * 2)) + 5) & 127;
    aux_2 ^= sample_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_62_1)
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

  switch (index_reg_62_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_41_1 == sample_41_2);
  assert(index_reg_62_1 == index_reg_62_2);
}

int fn_R000692_9213_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_41 > 24)
  {
    acc = ((acc + (sample_41 * 2)) + 5) & 127;
    aux ^= sample_41 & 15;
  }
  else
  {
    acc = ((acc - sample_41) + 11) & 127;
    aux += 3;
  }
  int index_reg_62 = (aux + st.buffer[1]) & 3;
  switch (index_reg_62)
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

void fn_R000692_9213_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st_1 = {0};
  struct Transaction_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int mask_50_1 = 0;
  int mask_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_50_1 = ((mask_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_50_2 = ((mask_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_50_1) & 127;
    acc_2 = (acc_2 + mask_50_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_35_1)
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

  switch (quotient_35_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_50_1 == mask_50_2);
  assert(quotient_35_1 == quotient_35_2);
}

int fn_R000692_9213_5(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int mask_50 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_50 = ((mask_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_50) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_35 = (aux + st.buffer[1]) & 3;
  switch (quotient_35)
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

void fn_R000692_9213_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st_1 = {0};
  struct Transaction_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int tracker_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_81_1)
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

  switch (tracker_81_2)
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

  int vector_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_67_1) & 63;
  aux_2 = (aux_2 + vector_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_65_1 = local_arr_1[aux_1 % 3];
  int phase_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_65_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_81_1 == tracker_81_2);
  assert(vector_67_1 == vector_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_65_1 == phase_65_2);
}

int fn_R000692_9213_6(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int tracker_81 = (aux + st.buffer[1]) & 3;
  switch (tracker_81)
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

  int vector_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_65 = local_arr[aux % 3];
  acc = (acc + (phase_65 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000692_9213_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st_1 = {0};
  struct Transaction_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int stride_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_73_1) & 63;
  aux_2 = (aux_2 + stride_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_85_1 = local_arr_1[aux_1 % 3];
  int sample_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_85_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_73_1 == stride_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_85_1 == sample_85_2);
}

int fn_R000692_9213_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int stride_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_73) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_85 = local_arr[aux % 3];
  acc = (acc + (sample_85 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000692_9213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st_1 = {0};
  struct Transaction_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int pivot_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_36_1)
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

  switch (pivot_36_2)
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
  int threshold_94_1 = local_arr_1[aux_1 % 3];
  int threshold_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_94_2 * 2)) & 127;
  int threshold_82_1 = 0;
  int threshold_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_82_1 = ((threshold_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_82_2 = ((threshold_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_82_1) & 127;
    acc_2 = (acc_2 + threshold_82_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_36_1 == pivot_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_94_1 == threshold_94_2);
  assert(threshold_82_1 == threshold_82_2);
}

int fn_R000692_9213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int pivot_36 = (aux + st.buffer[1]) & 3;
  switch (pivot_36)
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
  int threshold_94 = local_arr[aux % 3];
  acc = (acc + (threshold_94 * 2)) & 127;
  int threshold_82 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_82 = ((threshold_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_82) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000692_9213_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000692_9213_0 st_1 = {0};
  struct MatrixBlock_R000692_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int accumulator_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_67_1 > 17)
  {
    acc_1 = ((acc_1 + (accumulator_67_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_67_2 > 17)
  {
    acc_2 = ((acc_2 + (accumulator_67_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_88_1)
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

  switch (parity_88_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_67_1 == accumulator_67_2);
  assert(parity_88_1 == parity_88_2);
}

int fn_R000692_9213_9(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000692_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int accumulator_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_67 > 17)
  {
    acc = ((acc + (accumulator_67 * 2)) + 5) & 127;
    aux ^= accumulator_67 & 15;
  }
  else
  {
    acc = ((acc - accumulator_67) + 11) & 127;
    aux += 3;
  }
  int parity_88 = (aux + st.buffer[1]) & 3;
  switch (parity_88)
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

void fn_R000692_9213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st_1 = {0};
  struct Transaction_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_96_1)
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

  switch (phase_96_2)
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

  int damping_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_44_1) & 63;
  aux_2 = (aux_2 + damping_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_63_1 > 34)
  {
    acc_1 = ((acc_1 + (accumulator_63_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_63_2 > 34)
  {
    acc_2 = ((acc_2 + (accumulator_63_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_63_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_96_1 == phase_96_2);
  assert(damping_44_1 == damping_44_2);
  assert(accumulator_63_1 == accumulator_63_2);
}

int fn_R000692_9213_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_96 = (aux + st.buffer[1]) & 3;
  switch (phase_96)
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

  int damping_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_44) & 63;
  acc ^= aux;
  int accumulator_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_63 > 34)
  {
    acc = ((acc + (accumulator_63 * 2)) + 5) & 127;
    aux ^= accumulator_63 & 15;
  }
  else
  {
    acc = ((acc - accumulator_63) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000692_9213_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st_1 = {0};
  struct Transaction_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int phase_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_85_1) & 63;
  aux_2 = (aux_2 + phase_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_24_1 = local_arr_1[aux_1 % 3];
  int margin_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_24_2 * 2)) & 127;
  int window_38_1 = 0;
  int window_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_38_1 = ((window_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_38_2 = ((window_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_38_1) & 127;
    acc_2 = (acc_2 + window_38_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_85_1 == phase_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_24_1 == margin_24_2);
  assert(window_38_1 == window_38_2);
}

int fn_R000692_9213_11(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int phase_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_85) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_24 = local_arr[aux % 3];
  acc = (acc + (margin_24 * 2)) & 127;
  int window_38 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_38 = ((window_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_38) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000692_9213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000692_9213_0 st_1 = {0};
  struct MatrixBlock_R000692_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int anchor_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_55_1 > 31)
  {
    acc_1 = ((acc_1 + (anchor_55_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_55_2 > 31)
  {
    acc_2 = ((acc_2 + (anchor_55_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_97_1) & 63;
  aux_2 = (aux_2 + quotient_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_55_1 == anchor_55_2);
  assert(quotient_97_1 == quotient_97_2);
}

int fn_R000692_9213_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000692_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int anchor_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_55 > 31)
  {
    acc = ((acc + (anchor_55 * 2)) + 5) & 127;
    aux ^= anchor_55 & 15;
  }
  else
  {
    acc = ((acc - anchor_55) + 11) & 127;
    aux += 3;
  }
  int quotient_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000692_9213_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st_1 = {0};
  struct Transaction_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_10_1 = local_arr_1[aux_1 % 3];
  int weight_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_10_2 * 2)) & 127;
  int coefficient_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_42_1 > 48)
  {
    acc_1 = ((acc_1 + (coefficient_42_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_42_2 > 48)
  {
    acc_2 = ((acc_2 + (coefficient_42_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_42_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_81_1)
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

  switch (metric_81_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_10_1 == weight_10_2);
  assert(coefficient_42_1 == coefficient_42_2);
  assert(metric_81_1 == metric_81_2);
}

int fn_R000692_9213_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int weight_10 = local_arr[aux % 3];
  acc = (acc + (weight_10 * 2)) & 127;
  int coefficient_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_42 > 48)
  {
    acc = ((acc + (coefficient_42 * 2)) + 5) & 127;
    aux ^= coefficient_42 & 15;
  }
  else
  {
    acc = ((acc - coefficient_42) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_81 = (aux + st.buffer[1]) & 3;
  switch (metric_81)
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

void main()
{
  int sec_r000692_0_1;
  int sec_r000692_0_2;
  int sec_r000692_1_1;
  int sec_r000692_1_2;
  int sec_r000692_2_1;
  int sec_r000692_2_2;
  int sec_r000692_3_1;
  int sec_r000692_3_2;
  int sec_r000692_4_1;
  int sec_r000692_4_2;
  int sec_r000692_5_1;
  int sec_r000692_5_2;
  int sec_r000692_6_1;
  int sec_r000692_6_2;
  int sec_r000692_7_1;
  int sec_r000692_7_2;
  int sec_r000692_8_1;
  int sec_r000692_8_2;
  int sec_r000692_9_1;
  int sec_r000692_9_2;
  int sec_r000692_10_1;
  int sec_r000692_10_2;
  int sec_r000692_11_1;
  int sec_r000692_11_2;
  int sec_r000692_12_1;
  int sec_r000692_12_2;
  int sec_r000692_13_1;
  int sec_r000692_13_2;
  int sec_r000692_14_1;
  int sec_r000692_14_2;
  int sec_r000692_15_1;
  int sec_r000692_15_2;
  int pub_r000692_0_1;
  int pub_r000692_0_2;
  int pub_r000692_1_1;
  int pub_r000692_1_2;
  int pub_r000692_2_1;
  int pub_r000692_2_2;
  int pub_r000692_3_1;
  int pub_r000692_3_2;
  int pub_r000692_4_1;
  int pub_r000692_4_2;
  int pub_r000692_5_1;
  int pub_r000692_5_2;
  int pub_r000692_6_1;
  int pub_r000692_6_2;
  int pub_r000692_7_1;
  int pub_r000692_7_2;
  int pub_r000692_8_1;
  int pub_r000692_8_2;
  int pub_r000692_9_1;
  int pub_r000692_9_2;
  int pub_r000692_10_1;
  int pub_r000692_10_2;
  int pub_r000692_11_1;
  int pub_r000692_11_2;
  int pub_r000692_12_1;
  int pub_r000692_12_2;
  int pub_r000692_13_1;
  int pub_r000692_13_2;
  int pub_r000692_14_1;
  int pub_r000692_14_2;
  int pub_r000692_15_1;
  int pub_r000692_15_2;
  int pub_r000692_16_1;
  int pub_r000692_16_2;
  int pub_r000692_17_1;
  int pub_r000692_17_2;
  int pub_r000692_18_1;
  int pub_r000692_18_2;
  int pub_r000692_19_1;
  int pub_r000692_19_2;
  int pub_r000692_20_1;
  int pub_r000692_20_2;
  int pub_r000692_21_1;
  int pub_r000692_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000692_0_1 >= (-100)) && (pub_r000692_0_1 <= 100));
  __CPROVER_assume((pub_r000692_0_2 >= (-100)) && (pub_r000692_0_2 <= 100));
  __CPROVER_assume((pub_r000692_1_1 >= (-100)) && (pub_r000692_1_1 <= 100));
  __CPROVER_assume((pub_r000692_1_2 >= (-100)) && (pub_r000692_1_2 <= 100));
  __CPROVER_assume((pub_r000692_2_1 >= (-100)) && (pub_r000692_2_1 <= 100));
  __CPROVER_assume((pub_r000692_2_2 >= (-100)) && (pub_r000692_2_2 <= 100));
  __CPROVER_assume((pub_r000692_3_1 >= (-100)) && (pub_r000692_3_1 <= 100));
  __CPROVER_assume((pub_r000692_3_2 >= (-100)) && (pub_r000692_3_2 <= 100));
  __CPROVER_assume((pub_r000692_4_1 >= (-100)) && (pub_r000692_4_1 <= 100));
  __CPROVER_assume((pub_r000692_4_2 >= (-100)) && (pub_r000692_4_2 <= 100));
  __CPROVER_assume((pub_r000692_5_1 >= (-100)) && (pub_r000692_5_1 <= 100));
  __CPROVER_assume((pub_r000692_5_2 >= (-100)) && (pub_r000692_5_2 <= 100));
  __CPROVER_assume((pub_r000692_6_1 >= (-100)) && (pub_r000692_6_1 <= 100));
  __CPROVER_assume((pub_r000692_6_2 >= (-100)) && (pub_r000692_6_2 <= 100));
  __CPROVER_assume((pub_r000692_7_1 >= (-100)) && (pub_r000692_7_1 <= 100));
  __CPROVER_assume((pub_r000692_7_2 >= (-100)) && (pub_r000692_7_2 <= 100));
  __CPROVER_assume((pub_r000692_8_1 >= (-100)) && (pub_r000692_8_1 <= 100));
  __CPROVER_assume((pub_r000692_8_2 >= (-100)) && (pub_r000692_8_2 <= 100));
  __CPROVER_assume((pub_r000692_9_1 >= (-100)) && (pub_r000692_9_1 <= 100));
  __CPROVER_assume((pub_r000692_9_2 >= (-100)) && (pub_r000692_9_2 <= 100));
  __CPROVER_assume((pub_r000692_10_1 >= (-100)) && (pub_r000692_10_1 <= 100));
  __CPROVER_assume((pub_r000692_10_2 >= (-100)) && (pub_r000692_10_2 <= 100));
  __CPROVER_assume((pub_r000692_11_1 >= (-100)) && (pub_r000692_11_1 <= 100));
  __CPROVER_assume((pub_r000692_11_2 >= (-100)) && (pub_r000692_11_2 <= 100));
  __CPROVER_assume((pub_r000692_12_1 >= (-100)) && (pub_r000692_12_1 <= 100));
  __CPROVER_assume((pub_r000692_12_2 >= (-100)) && (pub_r000692_12_2 <= 100));
  __CPROVER_assume((pub_r000692_13_1 >= (-100)) && (pub_r000692_13_1 <= 100));
  __CPROVER_assume((pub_r000692_13_2 >= (-100)) && (pub_r000692_13_2 <= 100));
  __CPROVER_assume((pub_r000692_14_1 >= (-100)) && (pub_r000692_14_1 <= 100));
  __CPROVER_assume((pub_r000692_14_2 >= (-100)) && (pub_r000692_14_2 <= 100));
  __CPROVER_assume((pub_r000692_15_1 >= (-100)) && (pub_r000692_15_1 <= 100));
  __CPROVER_assume((pub_r000692_15_2 >= (-100)) && (pub_r000692_15_2 <= 100));
  __CPROVER_assume((pub_r000692_16_1 >= (-100)) && (pub_r000692_16_1 <= 100));
  __CPROVER_assume((pub_r000692_16_2 >= (-100)) && (pub_r000692_16_2 <= 100));
  __CPROVER_assume((pub_r000692_17_1 >= (-100)) && (pub_r000692_17_1 <= 100));
  __CPROVER_assume((pub_r000692_17_2 >= (-100)) && (pub_r000692_17_2 <= 100));
  __CPROVER_assume((pub_r000692_18_1 >= (-100)) && (pub_r000692_18_1 <= 100));
  __CPROVER_assume((pub_r000692_18_2 >= (-100)) && (pub_r000692_18_2 <= 100));
  __CPROVER_assume((pub_r000692_19_1 >= (-100)) && (pub_r000692_19_1 <= 100));
  __CPROVER_assume((pub_r000692_19_2 >= (-100)) && (pub_r000692_19_2 <= 100));
  __CPROVER_assume((pub_r000692_20_1 >= (-100)) && (pub_r000692_20_1 <= 100));
  __CPROVER_assume((pub_r000692_20_2 >= (-100)) && (pub_r000692_20_2 <= 100));
  __CPROVER_assume((pub_r000692_21_1 >= (-100)) && (pub_r000692_21_1 <= 100));
  __CPROVER_assume((pub_r000692_21_2 >= (-100)) && (pub_r000692_21_2 <= 100));
  __CPROVER_assume((sec_r000692_0_1 >= 0) && (sec_r000692_0_1 <= 255));
  __CPROVER_assume((sec_r000692_0_2 >= 0) && (sec_r000692_0_2 <= 255));
  __CPROVER_assume((sec_r000692_1_1 >= 0) && (sec_r000692_1_1 <= 255));
  __CPROVER_assume((sec_r000692_1_2 >= 0) && (sec_r000692_1_2 <= 255));
  __CPROVER_assume((sec_r000692_2_1 >= 0) && (sec_r000692_2_1 <= 255));
  __CPROVER_assume((sec_r000692_2_2 >= 0) && (sec_r000692_2_2 <= 255));
  __CPROVER_assume((sec_r000692_3_1 >= 0) && (sec_r000692_3_1 <= 255));
  __CPROVER_assume((sec_r000692_3_2 >= 0) && (sec_r000692_3_2 <= 255));
  __CPROVER_assume((sec_r000692_4_1 >= 0) && (sec_r000692_4_1 <= 255));
  __CPROVER_assume((sec_r000692_4_2 >= 0) && (sec_r000692_4_2 <= 255));
  __CPROVER_assume((sec_r000692_5_1 >= 0) && (sec_r000692_5_1 <= 255));
  __CPROVER_assume((sec_r000692_5_2 >= 0) && (sec_r000692_5_2 <= 255));
  __CPROVER_assume((sec_r000692_6_1 >= 0) && (sec_r000692_6_1 <= 255));
  __CPROVER_assume((sec_r000692_6_2 >= 0) && (sec_r000692_6_2 <= 255));
  __CPROVER_assume((sec_r000692_7_1 >= 0) && (sec_r000692_7_1 <= 255));
  __CPROVER_assume((sec_r000692_7_2 >= 0) && (sec_r000692_7_2 <= 255));
  __CPROVER_assume((sec_r000692_8_1 >= 0) && (sec_r000692_8_1 <= 255));
  __CPROVER_assume((sec_r000692_8_2 >= 0) && (sec_r000692_8_2 <= 255));
  __CPROVER_assume((sec_r000692_9_1 >= 0) && (sec_r000692_9_1 <= 255));
  __CPROVER_assume((sec_r000692_9_2 >= 0) && (sec_r000692_9_2 <= 255));
  __CPROVER_assume((sec_r000692_10_1 >= 0) && (sec_r000692_10_1 <= 255));
  __CPROVER_assume((sec_r000692_10_2 >= 0) && (sec_r000692_10_2 <= 255));
  __CPROVER_assume((sec_r000692_11_1 >= 0) && (sec_r000692_11_1 <= 255));
  __CPROVER_assume((sec_r000692_11_2 >= 0) && (sec_r000692_11_2 <= 255));
  __CPROVER_assume((sec_r000692_12_1 >= 0) && (sec_r000692_12_1 <= 255));
  __CPROVER_assume((sec_r000692_12_2 >= 0) && (sec_r000692_12_2 <= 255));
  __CPROVER_assume((sec_r000692_13_1 >= 0) && (sec_r000692_13_1 <= 255));
  __CPROVER_assume((sec_r000692_13_2 >= 0) && (sec_r000692_13_2 <= 255));
  __CPROVER_assume((sec_r000692_14_1 >= 0) && (sec_r000692_14_1 <= 255));
  __CPROVER_assume((sec_r000692_14_2 >= 0) && (sec_r000692_14_2 <= 255));
  __CPROVER_assume((sec_r000692_15_1 >= 0) && (sec_r000692_15_1 <= 255));
  __CPROVER_assume((sec_r000692_15_2 >= 0) && (sec_r000692_15_2 <= 255));
  struct MatrixBlock_R000692_9213_0 st_var_0_1 = {0};
  struct MatrixBlock_R000692_9213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000692_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000692_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000692_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000692_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000692_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000692_0_2 + 7) & 15;
  struct Transaction_R000692_9213_1 st_var_1_1 = {0};
  struct Transaction_R000692_9213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000692_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000692_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000692_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000692_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000692_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000692_0_2 + 9) & 15;
  union ColorPixel_R000692_9213_0 u_var_1;
  union ColorPixel_R000692_9213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 48)
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
  if (stage_v_4_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 48)
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
  int stage_v_5_1 = (st_var_1_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_1_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = (st_var_0_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_0_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 41)
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
  if (stage_v_8_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 41)
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
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = (st_var_1_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_1_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = ((st_var_1_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_1_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 38)
    {
      chk_sum_1 ^= stage_v_15_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_15_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 38)
    {
      chk_sum_2 ^= stage_v_15_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
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
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = ((st_var_1_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_1_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 44)
    {
      chk_sum_1 ^= stage_v_23_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_23_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 44)
    {
      chk_sum_2 ^= stage_v_23_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 40)
    {
      chk_sum_1 ^= stage_v_24_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_24_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 40)
    {
      chk_sum_2 ^= stage_v_24_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = (st_var_0_1.buffer[0] ^ 29) & 3;
  int stage_v_26_2 = (st_var_0_2.buffer[0] ^ 29) & 3;
  switch (stage_v_26_1)
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

  switch (stage_v_26_2)
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

  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (st_var_0_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_0_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 32) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_1_2.buffer[1] * 3) & 63;
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
  int stage_v_33_1 = (st_var_1_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_1_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 35) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = ((st_var_1_1.buffer[2] * 2) + 112) & 63;
  int stage_v_35_2 = ((st_var_1_2.buffer[2] * 2) + 112) & 63;
  if (stage_v_35_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_35_1) - 5) & 255;
    if (stage_v_35_1 > 41)
    {
      chk_sum_1 ^= stage_v_35_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_35_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_35_2) - 5) & 255;
    if (stage_v_35_2 > 41)
    {
      chk_sum_2 ^= stage_v_35_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 37) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 37) & 15;
  int stage_v_36_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_36_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= stage_v_36_1;
  chk_sum_2 ^= stage_v_36_2;
  int stage_v_37_1 = table_1[1];
  int stage_v_37_2 = table_2[1];
  table_1[1] = (table_1[2] + 75) & 63;
  table_2[1] = (table_2[2] + 75) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
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
  int stage_v_39_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_39_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 43) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  int stage_v_43_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_43_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = ((st_var_0_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_0_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 41)
    {
      chk_sum_1 ^= stage_v_46_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_46_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 41)
    {
      chk_sum_2 ^= stage_v_46_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_47_1 = table_1[3];
  int stage_v_47_2 = table_2[3];
  table_1[3] = (table_1[0] + 95) & 63;
  table_2[3] = (table_2[0] + 95) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 53) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_53_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 56) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  int stage_v_56_1 = ((st_var_0_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_0_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 55)
    {
      chk_sum_1 ^= stage_v_56_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_56_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 55)
    {
      chk_sum_2 ^= stage_v_56_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_58_1 = ((stage_v_58_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_58_2 = ((stage_v_58_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 60) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 60) & 15;
  int stage_v_59_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_59_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= stage_v_59_1;
  chk_sum_2 ^= stage_v_59_2;
  int stage_v_60_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_60_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_61_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_61_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_62_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_62_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_63_1 = ((st_var_1_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_1_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 53)
    {
      chk_sum_1 ^= stage_v_63_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_63_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 53)
    {
      chk_sum_2 ^= stage_v_63_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_64_1 = table_1[0];
  int stage_v_64_2 = table_2[0];
  table_1[0] = (table_1[1] + 129) & 63;
  table_2[0] = (table_2[1] + 129) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
  int stage_v_66_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_66_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_67_1 = table_1[3];
  int stage_v_67_2 = table_2[3];
  table_1[3] = (table_1[0] + 135) & 63;
  table_2[3] = (table_2[0] + 135) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (73 & 31);
  int stage_v_68_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (73 & 31);
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= (stage_v_68_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_68_2 << 1) & 127;
  int stage_v_69_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (74 & 31);
  int stage_v_69_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (74 & 31);
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= (stage_v_69_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_69_2 << 1) & 127;
  int stage_v_70_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_70_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_71_1 = table_1[3];
  int stage_v_71_2 = table_2[3];
  table_1[3] = (table_1[0] + 143) & 63;
  table_2[3] = (table_2[0] + 143) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = table_1[0];
  int stage_v_72_2 = table_2[0];
  table_1[0] = (table_1[1] + 145) & 63;
  table_2[0] = (table_2[1] + 145) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (st_var_1_1.buffer[0] ^ 78) & 3;
  int stage_v_75_2 = (st_var_1_2.buffer[0] ^ 78) & 3;
  switch (stage_v_75_1)
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

  switch (stage_v_75_2)
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

  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 78) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= stage_v_77_1;
  chk_sum_2 ^= stage_v_77_2;
  int stage_v_78_1 = (st_var_0_1.buffer[0] ^ 81) & 3;
  int stage_v_78_2 = (st_var_0_2.buffer[0] ^ 81) & 3;
  switch (stage_v_78_1)
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

  switch (stage_v_78_2)
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

  int stage_v_79_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_79_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_79_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_79_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_80_1 = ((st_var_0_1.buffer[2] * 2) + 247) & 63;
  int stage_v_80_2 = ((st_var_0_2.buffer[2] * 2) + 247) & 63;
  if (stage_v_80_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_80_1) - 5) & 255;
    if (stage_v_80_1 > 26)
    {
      chk_sum_1 ^= stage_v_80_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_80_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_80_2) - 5) & 255;
    if (stage_v_80_2 > 26)
    {
      chk_sum_2 ^= stage_v_80_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_81_1 = table_1[1];
  int stage_v_81_2 = table_2[1];
  table_1[1] = (table_1[2] + 163) & 63;
  table_2[1] = (table_2[2] + 163) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (87 & 31);
  int stage_v_82_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (87 & 31);
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= (stage_v_82_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_82_2 << 1) & 127;
  int stage_v_83_1 = (st_var_1_1.buffer[0] ^ 86) & 3;
  int stage_v_83_2 = (st_var_1_2.buffer[0] ^ 86) & 3;
  switch (stage_v_83_1)
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

  switch (stage_v_83_2)
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

  int stage_v_84_1 = table_1[0];
  int stage_v_84_2 = table_2[0];
  table_1[0] = (table_1[1] + 169) & 63;
  table_2[0] = (table_2[1] + 169) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((st_var_0_1.buffer[2] * 2) + 265) & 63;
  int stage_v_86_2 = ((st_var_0_2.buffer[2] * 2) + 265) & 63;
  if (stage_v_86_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_86_1) - 5) & 255;
    if (stage_v_86_1 > 34)
    {
      chk_sum_1 ^= stage_v_86_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_86_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_86_2) - 5) & 255;
    if (stage_v_86_2 > 34)
    {
      chk_sum_2 ^= stage_v_86_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_87_1 = (st_var_1_1.buffer[0] ^ 90) & 3;
  int stage_v_87_2 = (st_var_1_2.buffer[0] ^ 90) & 3;
  switch (stage_v_87_1)
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

  switch (stage_v_87_2)
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

  int stage_v_88_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (93 & 31);
  int stage_v_88_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (93 & 31);
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= (stage_v_88_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_88_2 << 1) & 127;
  int stage_v_89_1 = ((st_var_1_1.buffer[2] * 2) + 274) & 63;
  int stage_v_89_2 = ((st_var_1_2.buffer[2] * 2) + 274) & 63;
  if (stage_v_89_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_89_1) - 5) & 255;
    if (stage_v_89_1 > 38)
    {
      chk_sum_1 ^= stage_v_89_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_89_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_89_2) - 5) & 255;
    if (stage_v_89_2 > 38)
    {
      chk_sum_2 ^= stage_v_89_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_90_1 = table_1[2];
  int stage_v_90_2 = table_2[2];
  table_1[2] = (table_1[3] + 181) & 63;
  table_2[2] = (table_2[3] + 181) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 92) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 92) & 15;
  int stage_v_91_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_91_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= stage_v_91_1;
  chk_sum_2 ^= stage_v_91_2;
  int stage_v_92_1 = (st_var_0_1.buffer[0] ^ 95) & 3;
  int stage_v_92_2 = (st_var_0_2.buffer[0] ^ 95) & 3;
  switch (stage_v_92_1)
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

  switch (stage_v_92_2)
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

  int stage_v_93_1 = ((st_var_1_1.buffer[0] * 2) + 286) & 63;
  int stage_v_93_2 = ((st_var_1_2.buffer[0] * 2) + 286) & 63;
  if (stage_v_93_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_93_1) - 5) & 255;
    if (stage_v_93_1 > 31)
    {
      chk_sum_1 ^= stage_v_93_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_93_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_93_2) - 5) & 255;
    if (stage_v_93_2 > 31)
    {
      chk_sum_2 ^= stage_v_93_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_94_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_94_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_94_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_94_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_95_1 = (st_var_1_1.buffer[0] ^ 98) & 3;
  int stage_v_95_2 = (st_var_1_2.buffer[0] ^ 98) & 3;
  switch (stage_v_95_1)
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

  switch (stage_v_95_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 97) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 97) & 15;
  int stage_v_96_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_96_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  chk_sum_1 ^= stage_v_96_1;
  chk_sum_2 ^= stage_v_96_2;
  int stage_v_97_1 = table_1[1];
  int stage_v_97_2 = table_2[1];
  table_1[1] = (table_1[2] + 195) & 63;
  table_2[1] = (table_2[2] + 195) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = table_1[2];
  int stage_v_98_2 = table_2[2];
  table_1[2] = (table_1[3] + 197) & 63;
  table_2[2] = (table_2[3] + 197) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (104 & 31);
  int stage_v_99_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (104 & 31);
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  chk_sum_1 ^= (stage_v_99_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_99_2 << 1) & 127;
  int stage_v_100_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (105 & 31);
  int stage_v_100_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (105 & 31);
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= (stage_v_100_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_100_2 << 1) & 127;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_101_1 = ((stage_v_101_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_101_2 = ((stage_v_101_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_102_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_102_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_102_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_103_1 = ((st_var_1_1.buffer[1] * 2) + 316) & 63;
  int stage_v_103_2 = ((st_var_1_2.buffer[1] * 2) + 316) & 63;
  if (stage_v_103_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_103_1) - 5) & 255;
    if (stage_v_103_1 > 33)
    {
      chk_sum_1 ^= stage_v_103_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_103_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_103_2) - 5) & 255;
    if (stage_v_103_2 > 33)
    {
      chk_sum_2 ^= stage_v_103_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_104_1 = (st_var_0_1.buffer[0] ^ 107) & 3;
  int stage_v_104_2 = (st_var_0_2.buffer[0] ^ 107) & 3;
  switch (stage_v_104_1)
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

  switch (stage_v_104_2)
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

  int stage_v_105_1 = (st_var_1_1.buffer[0] ^ 108) & 3;
  int stage_v_105_2 = (st_var_1_2.buffer[0] ^ 108) & 3;
  switch (stage_v_105_1)
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

  switch (stage_v_105_2)
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

  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_106_1 = ((stage_v_106_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_106_2 = ((stage_v_106_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (st_var_1_1.buffer[0] ^ 110) & 3;
  int stage_v_107_2 = (st_var_1_2.buffer[0] ^ 110) & 3;
  switch (stage_v_107_1)
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

  switch (stage_v_107_2)
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

  int stage_v_108_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (113 & 31);
  int stage_v_108_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (113 & 31);
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  chk_sum_1 ^= (stage_v_108_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_108_2 << 1) & 127;
  int stage_v_109_1 = (st_var_1_1.buffer[0] ^ 112) & 3;
  int stage_v_109_2 = (st_var_1_2.buffer[0] ^ 112) & 3;
  switch (stage_v_109_1)
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

  switch (stage_v_109_2)
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

  int stage_v_110_1 = ((st_var_0_1.buffer[2] * 2) + 337) & 63;
  int stage_v_110_2 = ((st_var_0_2.buffer[2] * 2) + 337) & 63;
  if (stage_v_110_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_110_1) - 5) & 255;
    if (stage_v_110_1 > 42)
    {
      chk_sum_1 ^= stage_v_110_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_110_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_110_2) - 5) & 255;
    if (stage_v_110_2 > 42)
    {
      chk_sum_2 ^= stage_v_110_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_111_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_111_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_112_1 = (st_var_0_1.buffer[0] ^ 115) & 3;
  int stage_v_112_2 = (st_var_0_2.buffer[0] ^ 115) & 3;
  switch (stage_v_112_1)
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

  switch (stage_v_112_2)
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

  int stage_v_113_1 = table_1[1];
  int stage_v_113_2 = table_2[1];
  table_1[1] = (table_1[2] + 227) & 63;
  table_2[1] = (table_2[2] + 227) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_114_1 = ((stage_v_114_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_114_2 = ((stage_v_114_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  }

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
  int stage_v_116_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_116_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_116_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_116_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_117_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (122 & 31);
  int stage_v_117_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (122 & 31);
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  chk_sum_1 ^= (stage_v_117_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_117_2 << 1) & 127;
  int stage_v_118_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_118_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_118_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_118_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_119_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (124 & 31);
  int stage_v_119_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (124 & 31);
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  chk_sum_1 ^= (stage_v_119_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_119_2 << 1) & 127;
  int stage_v_120_1 = table_1[0];
  int stage_v_120_2 = table_2[0];
  table_1[0] = (table_1[1] + 241) & 63;
  table_2[0] = (table_2[1] + 241) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (st_var_1_1.buffer[0] ^ 124) & 3;
  int stage_v_121_2 = (st_var_1_2.buffer[0] ^ 124) & 3;
  switch (stage_v_121_1)
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

  switch (stage_v_121_2)
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

  int stage_v_122_1 = (st_var_0_1.buffer[0] ^ 125) & 3;
  int stage_v_122_2 = (st_var_0_2.buffer[0] ^ 125) & 3;
  switch (stage_v_122_1)
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

  switch (stage_v_122_2)
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

  int stage_v_123_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (128 & 31);
  int stage_v_123_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (128 & 31);
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= (stage_v_123_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_123_2 << 1) & 127;
  int stage_v_124_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (129 & 31);
  int stage_v_124_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (129 & 31);
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  chk_sum_1 ^= (stage_v_124_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_124_2 << 1) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 126) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 126) & 15;
  int stage_v_125_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_125_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  chk_sum_1 ^= stage_v_125_1;
  chk_sum_2 ^= stage_v_125_2;
  int stage_v_126_1 = ((st_var_0_1.buffer[0] * 2) + 385) & 63;
  int stage_v_126_2 = ((st_var_0_2.buffer[0] * 2) + 385) & 63;
  if (stage_v_126_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_126_1) - 5) & 255;
    if (stage_v_126_1 > 32)
    {
      chk_sum_1 ^= stage_v_126_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_126_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_126_2) - 5) & 255;
    if (stage_v_126_2 > 32)
    {
      chk_sum_2 ^= stage_v_126_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_127_1 = (st_var_1_1.buffer[0] ^ 130) & 3;
  int stage_v_127_2 = (st_var_1_2.buffer[0] ^ 130) & 3;
  switch (stage_v_127_1)
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

  switch (stage_v_127_2)
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

  int stage_v_128_1 = ((st_var_0_1.buffer[2] * 2) + 391) & 63;
  int stage_v_128_2 = ((st_var_0_2.buffer[2] * 2) + 391) & 63;
  if (stage_v_128_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_128_1) - 5) & 255;
    if (stage_v_128_1 > 30)
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
  if (stage_v_128_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_128_2) - 5) & 255;
    if (stage_v_128_2 > 30)
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
  int stage_v_129_1 = (st_var_1_1.buffer[0] ^ 132) & 3;
  int stage_v_129_2 = (st_var_1_2.buffer[0] ^ 132) & 3;
  switch (stage_v_129_1)
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

  switch (stage_v_129_2)
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

  int stage_v_130_1 = (st_var_0_1.buffer[0] ^ 133) & 3;
  int stage_v_130_2 = (st_var_0_2.buffer[0] ^ 133) & 3;
  switch (stage_v_130_1)
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

  switch (stage_v_130_2)
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

  int stage_v_131_1 = (st_var_1_1.buffer[0] ^ 134) & 3;
  int stage_v_131_2 = (st_var_1_2.buffer[0] ^ 134) & 3;
  switch (stage_v_131_1)
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

  switch (stage_v_131_2)
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

  int stage_v_132_1 = (st_var_0_1.buffer[0] ^ 135) & 3;
  int stage_v_132_2 = (st_var_0_2.buffer[0] ^ 135) & 3;
  switch (stage_v_132_1)
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

  switch (stage_v_132_2)
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

  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_133_1 = ((stage_v_133_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_133_2 = ((stage_v_133_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (139 & 31);
  int stage_v_134_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (139 & 31);
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= (stage_v_134_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_134_2 << 1) & 127;
  int stage_v_135_1 = (st_var_1_1.buffer[0] ^ 138) & 3;
  int stage_v_135_2 = (st_var_1_2.buffer[0] ^ 138) & 3;
  switch (stage_v_135_1)
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

  switch (stage_v_135_2)
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

  int stage_v_136_1 = ((st_var_0_1.buffer[1] * 2) + 415) & 63;
  int stage_v_136_2 = ((st_var_0_2.buffer[1] * 2) + 415) & 63;
  if (stage_v_136_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_136_1) - 5) & 255;
    if (stage_v_136_1 > 45)
    {
      chk_sum_1 ^= stage_v_136_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_136_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_136_2) - 5) & 255;
    if (stage_v_136_2 > 45)
    {
      chk_sum_2 ^= stage_v_136_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_137_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_137_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (st_var_1_1.buffer[0] ^ 142) & 3;
  int stage_v_139_2 = (st_var_1_2.buffer[0] ^ 142) & 3;
  switch (stage_v_139_1)
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

  switch (stage_v_139_2)
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

  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_140_1 = ((stage_v_140_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_140_2 = ((stage_v_140_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_141_1 = ((stage_v_141_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_141_2 = ((stage_v_141_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (st_var_0_1.buffer[0] ^ 145) & 3;
  int stage_v_142_2 = (st_var_0_2.buffer[0] ^ 145) & 3;
  switch (stage_v_142_1)
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

  switch (stage_v_142_2)
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

  int stage_v_143_1 = (st_var_1_1.buffer[0] ^ 146) & 3;
  int stage_v_143_2 = (st_var_1_2.buffer[0] ^ 146) & 3;
  switch (stage_v_143_1)
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

  switch (stage_v_143_2)
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

  int stage_v_144_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_144_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_145_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_145_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_145_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_145_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_146_1 = (st_var_0_1.buffer[0] ^ 149) & 3;
  int stage_v_146_2 = (st_var_0_2.buffer[0] ^ 149) & 3;
  switch (stage_v_146_1)
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

  switch (stage_v_146_2)
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

  int stage_v_147_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (152 & 31);
  int stage_v_147_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (152 & 31);
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  chk_sum_1 ^= (stage_v_147_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_147_2 << 1) & 127;
  int stage_v_148_1 = table_1[0];
  int stage_v_148_2 = table_2[0];
  table_1[0] = (table_1[1] + 297) & 63;
  table_2[0] = (table_2[1] + 297) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_149_1 = ((stage_v_149_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_149_2 = ((stage_v_149_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_150_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_150_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_150_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_151_1 = ((stage_v_151_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_151_2 = ((stage_v_151_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = table_1[0];
  int stage_v_152_2 = table_2[0];
  table_1[0] = (table_1[1] + 305) & 63;
  table_2[0] = (table_2[1] + 305) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((st_var_1_1.buffer[0] * 2) + 466) & 63;
  int stage_v_153_2 = ((st_var_1_2.buffer[0] * 2) + 466) & 63;
  if (stage_v_153_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_153_1) - 5) & 255;
    if (stage_v_153_1 > 54)
    {
      chk_sum_1 ^= stage_v_153_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_153_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_153_2) - 5) & 255;
    if (stage_v_153_2 > 54)
    {
      chk_sum_2 ^= stage_v_153_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_154_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (159 & 31);
  int stage_v_154_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (159 & 31);
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  chk_sum_1 ^= (stage_v_154_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_154_2 << 1) & 127;
  int stage_v_155_1 = table_1[3];
  int stage_v_155_2 = table_2[3];
  table_1[3] = (table_1[0] + 311) & 63;
  table_2[3] = (table_2[0] + 311) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (st_var_0_1.buffer[0] ^ 159) & 3;
  int stage_v_156_2 = (st_var_0_2.buffer[0] ^ 159) & 3;
  switch (stage_v_156_1)
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

  switch (stage_v_156_2)
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

  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_157_1 = ((stage_v_157_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_157_2 = ((stage_v_157_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_158_1 = ((stage_v_158_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_158_2 = ((stage_v_158_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (st_var_1_1.buffer[0] ^ 162) & 3;
  int stage_v_159_2 = (st_var_1_2.buffer[0] ^ 162) & 3;
  switch (stage_v_159_1)
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

  switch (stage_v_159_2)
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

  int stage_v_160_1 = (st_var_0_1.buffer[0] ^ 163) & 3;
  int stage_v_160_2 = (st_var_0_2.buffer[0] ^ 163) & 3;
  switch (stage_v_160_1)
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

  switch (stage_v_160_2)
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

  int stage_v_161_1 = table_1[1];
  int stage_v_161_2 = table_2[1];
  table_1[1] = (table_1[2] + 323) & 63;
  table_2[1] = (table_2[2] + 323) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 163) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 163) & 15;
  int stage_v_162_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_162_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  chk_sum_1 ^= stage_v_162_1;
  chk_sum_2 ^= stage_v_162_2;
  int stage_v_163_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_163_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_164_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (169 & 31);
  int stage_v_164_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (169 & 31);
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  chk_sum_1 ^= (stage_v_164_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_164_2 << 1) & 127;
  int stage_v_165_1 = ((st_var_1_1.buffer[0] * 2) + 502) & 63;
  int stage_v_165_2 = ((st_var_1_2.buffer[0] * 2) + 502) & 63;
  if (stage_v_165_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_165_1) - 5) & 255;
    if (stage_v_165_1 > 41)
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
  if (stage_v_165_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_165_2) - 5) & 255;
    if (stage_v_165_2 > 41)
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
  int stage_v_166_1 = (st_var_0_1.buffer[0] ^ 169) & 3;
  int stage_v_166_2 = (st_var_0_2.buffer[0] ^ 169) & 3;
  switch (stage_v_166_1)
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

  switch (stage_v_166_2)
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

  int stage_v_167_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_167_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_167_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_167_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_168_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (173 & 31);
  int stage_v_168_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (173 & 31);
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  chk_sum_1 ^= (stage_v_168_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_168_2 << 1) & 127;
  int stage_v_169_1 = table_1[1];
  int stage_v_169_2 = table_2[1];
  table_1[1] = (table_1[2] + 339) & 63;
  table_2[1] = (table_2[2] + 339) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = table_1[2];
  int stage_v_170_2 = table_2[2];
  table_1[2] = (table_1[3] + 341) & 63;
  table_2[2] = (table_2[3] + 341) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 172) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 172) & 15;
  int stage_v_171_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_171_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  chk_sum_1 ^= stage_v_171_1;
  chk_sum_2 ^= stage_v_171_2;
  int stage_v_172_1 = ((st_var_0_1.buffer[1] * 2) + 523) & 63;
  int stage_v_172_2 = ((st_var_0_2.buffer[1] * 2) + 523) & 63;
  if (stage_v_172_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_172_1) - 5) & 255;
    if (stage_v_172_1 > 31)
    {
      chk_sum_1 ^= stage_v_172_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_172_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_172_2) - 5) & 255;
    if (stage_v_172_2 > 31)
    {
      chk_sum_2 ^= stage_v_172_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_173_1 = ((st_var_1_1.buffer[2] * 2) + 526) & 63;
  int stage_v_173_2 = ((st_var_1_2.buffer[2] * 2) + 526) & 63;
  if (stage_v_173_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_173_1) - 5) & 255;
    if (stage_v_173_1 > 55)
    {
      chk_sum_1 ^= stage_v_173_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_173_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_173_2) - 5) & 255;
    if (stage_v_173_2 > 55)
    {
      chk_sum_2 ^= stage_v_173_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 175) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 175) & 15;
  int stage_v_174_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_174_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  chk_sum_1 ^= stage_v_174_1;
  chk_sum_2 ^= stage_v_174_2;
  int stage_v_175_1 = table_1[3];
  int stage_v_175_2 = table_2[3];
  table_1[3] = (table_1[0] + 351) & 63;
  table_2[3] = (table_2[0] + 351) & 63;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((st_var_0_1.buffer[2] * 2) + 535) & 63;
  int stage_v_176_2 = ((st_var_0_2.buffer[2] * 2) + 535) & 63;
  if (stage_v_176_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_176_1) - 5) & 255;
    if (stage_v_176_1 > 51)
    {
      chk_sum_1 ^= stage_v_176_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_176_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_176_2) - 5) & 255;
    if (stage_v_176_2 > 51)
    {
      chk_sum_2 ^= stage_v_176_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_177_1 = 0;
  int stage_v_177_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_177_1 = ((stage_v_177_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_177_2 = ((stage_v_177_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (183 & 31);
  int stage_v_178_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (183 & 31);
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  chk_sum_1 ^= (stage_v_178_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_178_2 << 1) & 127;
  int stage_v_179_1 = 0;
  int stage_v_179_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_179_1 = ((stage_v_179_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_179_2 = ((stage_v_179_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 181) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 181) & 15;
  int stage_v_180_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_180_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  chk_sum_1 ^= stage_v_180_1;
  chk_sum_2 ^= stage_v_180_2;
  int stage_v_181_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_181_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_181_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_181_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_182_1 = ((st_var_0_1.buffer[2] * 2) + 553) & 63;
  int stage_v_182_2 = ((st_var_0_2.buffer[2] * 2) + 553) & 63;
  if (stage_v_182_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_182_1) - 5) & 255;
    if (stage_v_182_1 > 29)
    {
      chk_sum_1 ^= stage_v_182_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_182_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_182_2) - 5) & 255;
    if (stage_v_182_2 > 29)
    {
      chk_sum_2 ^= stage_v_182_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_183_1 = 0;
  int stage_v_183_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_183_1 = ((stage_v_183_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_183_2 = ((stage_v_183_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_184_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_184_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_184_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_185_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_185_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_185_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_185_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_186_1 = (st_var_0_1.buffer[0] ^ 189) & 3;
  int stage_v_186_2 = (st_var_0_2.buffer[0] ^ 189) & 3;
  switch (stage_v_186_1)
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

  switch (stage_v_186_2)
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

  int stage_v_187_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (192 & 31);
  int stage_v_187_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (192 & 31);
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  chk_sum_1 ^= (stage_v_187_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_187_2 << 1) & 127;
  int stage_v_188_1 = ((st_var_0_1.buffer[2] * 2) + 571) & 63;
  int stage_v_188_2 = ((st_var_0_2.buffer[2] * 2) + 571) & 63;
  if (stage_v_188_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_188_1) - 5) & 255;
    if (stage_v_188_1 > 31)
    {
      chk_sum_1 ^= stage_v_188_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_188_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_188_2) - 5) & 255;
    if (stage_v_188_2 > 31)
    {
      chk_sum_2 ^= stage_v_188_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_189_1 = ((st_var_1_1.buffer[0] * 2) + 574) & 63;
  int stage_v_189_2 = ((st_var_1_2.buffer[0] * 2) + 574) & 63;
  if (stage_v_189_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_189_1) - 5) & 255;
    if (stage_v_189_1 > 32)
    {
      chk_sum_1 ^= stage_v_189_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_189_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_189_2) - 5) & 255;
    if (stage_v_189_2 > 32)
    {
      chk_sum_2 ^= stage_v_189_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_190_1 = ((st_var_0_1.buffer[1] * 2) + 577) & 63;
  int stage_v_190_2 = ((st_var_0_2.buffer[1] * 2) + 577) & 63;
  if (stage_v_190_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_190_1) - 5) & 255;
    if (stage_v_190_1 > 49)
    {
      chk_sum_1 ^= stage_v_190_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_190_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_190_2) - 5) & 255;
    if (stage_v_190_2 > 49)
    {
      chk_sum_2 ^= stage_v_190_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 192) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 192) & 15;
  int stage_v_191_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_191_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  chk_sum_1 ^= stage_v_191_1;
  chk_sum_2 ^= stage_v_191_2;
  int stage_v_192_1 = (st_var_0_1.buffer[0] ^ 195) & 3;
  int stage_v_192_2 = (st_var_0_2.buffer[0] ^ 195) & 3;
  switch (stage_v_192_1)
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

  switch (stage_v_192_2)
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

  int stage_v_193_1 = ((st_var_1_1.buffer[1] * 2) + 586) & 63;
  int stage_v_193_2 = ((st_var_1_2.buffer[1] * 2) + 586) & 63;
  if (stage_v_193_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_193_1) - 5) & 255;
    if (stage_v_193_1 > 52)
    {
      chk_sum_1 ^= stage_v_193_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_193_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_193_2) - 5) & 255;
    if (stage_v_193_2 > 52)
    {
      chk_sum_2 ^= stage_v_193_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_194_1 = (st_var_0_1.buffer[0] ^ 197) & 3;
  int stage_v_194_2 = (st_var_0_2.buffer[0] ^ 197) & 3;
  switch (stage_v_194_1)
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

  switch (stage_v_194_2)
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

  int stage_v_195_1 = (st_var_1_1.buffer[0] ^ 198) & 3;
  int stage_v_195_2 = (st_var_1_2.buffer[0] ^ 198) & 3;
  switch (stage_v_195_1)
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

  switch (stage_v_195_2)
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

  int stage_v_196_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (201 & 31);
  int stage_v_196_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (201 & 31);
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  chk_sum_1 ^= (stage_v_196_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_196_2 << 1) & 127;
  int stage_v_197_1 = 0;
  int stage_v_197_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_197_1 = ((stage_v_197_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_197_2 = ((stage_v_197_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 199) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 199) & 15;
  int stage_v_198_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_198_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  chk_sum_1 ^= stage_v_198_1;
  chk_sum_2 ^= stage_v_198_2;
  int stage_v_199_1 = 0;
  int stage_v_199_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_199_1 = ((stage_v_199_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_199_2 = ((stage_v_199_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 201) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 201) & 15;
  int stage_v_200_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_200_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  chk_sum_1 ^= stage_v_200_1;
  chk_sum_2 ^= stage_v_200_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 202) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 202) & 15;
  int stage_v_201_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_201_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  chk_sum_1 ^= stage_v_201_1;
  chk_sum_2 ^= stage_v_201_2;
  int stage_v_202_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (207 & 31);
  int stage_v_202_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (207 & 31);
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  chk_sum_1 ^= (stage_v_202_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_202_2 << 1) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 204) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 204) & 15;
  int stage_v_203_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_203_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  chk_sum_1 ^= stage_v_203_1;
  chk_sum_2 ^= stage_v_203_2;
  if ((sec_r000692_5_1 & 1) != 0)
  {
    if ((sec_r000692_12_1 & 2) != 0)
    {
      out_sink_1 += 45;
    }
    else
    {
      out_sink_1 += 27;
    }
  }
  else
  {
    if ((sec_r000692_13_1 & 4) != 0)
    {
      out_sink_1 -= 21;
    }
    else
    {
      out_sink_1 -= 60;
    }
  }
  if ((sec_r000692_5_2 & 1) != 0)
  {
    if ((sec_r000692_12_2 & 2) != 0)
    {
      out_sink_2 += 45;
    }
    else
    {
      out_sink_2 += 27;
    }
  }
  else
  {
    if ((sec_r000692_13_2 & 4) != 0)
    {
      out_sink_2 -= 21;
    }
    else
    {
      out_sink_2 -= 60;
    }
  }
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000692_1_1 == pub_r000692_1_2);
  __CPROVER_assume(sec_r000692_15_1 != sec_r000692_15_2);
  __CPROVER_assume(sec_r000692_3_1 != sec_r000692_3_2);
  __CPROVER_assume(pub_r000692_10_1 == pub_r000692_10_2);
  __CPROVER_assume(sec_r000692_13_1 != sec_r000692_13_2);
  __CPROVER_assume(pub_r000692_5_1 == pub_r000692_5_2);
  __CPROVER_assume(pub_r000692_18_1 == pub_r000692_18_2);
  __CPROVER_assume(sec_r000692_14_1 != sec_r000692_14_2);
  __CPROVER_assume(sec_r000692_1_1 != sec_r000692_1_2);
  __CPROVER_assume(sec_r000692_6_1 != sec_r000692_6_2);
  __CPROVER_assume(pub_r000692_4_1 == pub_r000692_4_2);
  __CPROVER_assume(pub_r000692_6_1 == pub_r000692_6_2);
  __CPROVER_assume(sec_r000692_8_1 != sec_r000692_8_2);
  __CPROVER_assume(pub_r000692_0_1 == pub_r000692_0_2);
  __CPROVER_assume(pub_r000692_21_1 == pub_r000692_21_2);
  __CPROVER_assume(sec_r000692_12_1 != sec_r000692_12_2);
  __CPROVER_assume(sec_r000692_2_1 != sec_r000692_2_2);
  __CPROVER_assume(pub_r000692_7_1 == pub_r000692_7_2);
  __CPROVER_assume(pub_r000692_19_1 == pub_r000692_19_2);
  __CPROVER_assume(sec_r000692_9_1 != sec_r000692_9_2);
  __CPROVER_assume(pub_r000692_2_1 == pub_r000692_2_2);
  __CPROVER_assume(sec_r000692_5_1 != sec_r000692_5_2);
  __CPROVER_assume(pub_r000692_11_1 == pub_r000692_11_2);
  __CPROVER_assume(pub_r000692_12_1 == pub_r000692_12_2);
  __CPROVER_assume(sec_r000692_4_1 != sec_r000692_4_2);
  __CPROVER_assume(pub_r000692_8_1 == pub_r000692_8_2);
  __CPROVER_assume(pub_r000692_20_1 == pub_r000692_20_2);
  __CPROVER_assume(pub_r000692_15_1 == pub_r000692_15_2);
  __CPROVER_assume(pub_r000692_3_1 == pub_r000692_3_2);
  __CPROVER_assume(sec_r000692_7_1 != sec_r000692_7_2);
  __CPROVER_assume(sec_r000692_11_1 != sec_r000692_11_2);
  __CPROVER_assume(pub_r000692_13_1 == pub_r000692_13_2);
  __CPROVER_assume(sec_r000692_10_1 != sec_r000692_10_2);
  __CPROVER_assume(pub_r000692_14_1 == pub_r000692_14_2);
  __CPROVER_assume(pub_r000692_16_1 == pub_r000692_16_2);
  __CPROVER_assume(pub_r000692_9_1 == pub_r000692_9_2);
  __CPROVER_assume(pub_r000692_17_1 == pub_r000692_17_2);
  __CPROVER_assume(sec_r000692_0_1 != sec_r000692_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.fee == st_var_1_2.fee);
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
}


