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
struct MatrixBlock_R000827_2713_0
{
  unsigned char density;
  unsigned char dim;
  unsigned char trace;
  int stride;
  short scale;
  int determinant;
  int buffer[3];
};
struct Transaction_R000827_2713_1
{
  short balance;
  int fee;
  int status;
  int auth_code;
  int buffer[3];
};
union ColorPixel_R000827_2713_0
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
void fn_R000827_2713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int damping_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_63_1 > 25)
  {
    acc_1 = ((acc_1 + (damping_63_1 * 2)) + 5) & 127;
    aux_1 ^= damping_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_63_2 > 25)
  {
    acc_2 = ((acc_2 + (damping_63_2 * 2)) + 5) & 127;
    aux_2 ^= damping_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_85_1 = local_arr_1[aux_1 % 3];
  int margin_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_85_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_63_1 == damping_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_85_1 == margin_85_2);
}

int fn_R000827_2713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int damping_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_63 > 25)
  {
    acc = ((acc + (damping_63 * 2)) + 5) & 127;
    aux ^= damping_63 & 15;
  }
  else
  {
    acc = ((acc - damping_63) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_85 = local_arr[aux % 3];
  acc = (acc + (margin_85 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000827_2713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int accumulator_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_73_1)
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

  switch (accumulator_73_2)
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
  int margin_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_10_1 > 36)
  {
    acc_1 = ((acc_1 + (margin_10_1 * 2)) + 5) & 127;
    aux_1 ^= margin_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_10_2 > 36)
  {
    acc_2 = ((acc_2 + (margin_10_2 * 2)) + 5) & 127;
    aux_2 ^= margin_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_73_1 == accumulator_73_2);
  assert(margin_10_1 == margin_10_2);
}

int fn_R000827_2713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int accumulator_73 = (aux + st.buffer[1]) & 3;
  switch (accumulator_73)
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
  int margin_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_10 > 36)
  {
    acc = ((acc + (margin_10 * 2)) + 5) & 127;
    aux ^= margin_10 & 15;
  }
  else
  {
    acc = ((acc - margin_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000827_2713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int phase_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_97_1)
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

  switch (phase_97_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_63_1 > 43)
  {
    acc_1 = ((acc_1 + (bound_63_1 * 2)) + 5) & 127;
    aux_1 ^= bound_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_63_2 > 43)
  {
    acc_2 = ((acc_2 + (bound_63_2 * 2)) + 5) & 127;
    aux_2 ^= bound_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_63_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_97_1 == phase_97_2);
  assert(bound_63_1 == bound_63_2);
}

int fn_R000827_2713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int phase_97 = (aux + st.buffer[1]) & 3;
  switch (phase_97)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_63 > 43)
  {
    acc = ((acc + (bound_63 * 2)) + 5) & 127;
    aux ^= bound_63 & 15;
  }
  else
  {
    acc = ((acc - bound_63) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000827_2713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_11_1 > 19)
  {
    acc_1 = ((acc_1 + (sample_11_1 * 2)) + 5) & 127;
    aux_1 ^= sample_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_11_2 > 19)
  {
    acc_2 = ((acc_2 + (sample_11_2 * 2)) + 5) & 127;
    aux_2 ^= sample_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_11_1 == sample_11_2);
}

int fn_R000827_2713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_11 > 19)
  {
    acc = ((acc + (sample_11 * 2)) + 5) & 127;
    aux ^= sample_11 & 15;
  }
  else
  {
    acc = ((acc - sample_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000827_2713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st_1 = {0};
  struct Transaction_R000827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_94_1 = local_arr_1[aux_1 % 3];
  int parity_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_94_2 * 2)) & 127;
  int checksum_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_42_1)
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

  switch (checksum_42_2)
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
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_94_1 == parity_94_2);
  assert(checksum_42_1 == checksum_42_2);
}

int fn_R000827_2713_4(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_94 = local_arr[aux % 3];
  acc = (acc + (parity_94 * 2)) & 127;
  int checksum_42 = (aux + st.buffer[1]) & 3;
  switch (checksum_42)
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

void fn_R000827_2713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_98_1 = local_arr_1[aux_1 % 3];
  int sample_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_98_2 * 2)) & 127;
  int delta_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_53_1 > 16)
  {
    acc_1 = ((acc_1 + (delta_53_1 * 2)) + 5) & 127;
    aux_1 ^= delta_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_53_2 > 16)
  {
    acc_2 = ((acc_2 + (delta_53_2 * 2)) + 5) & 127;
    aux_2 ^= delta_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_98_1 == sample_98_2);
  assert(delta_53_1 == delta_53_2);
}

int fn_R000827_2713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int sample_98 = local_arr[aux % 3];
  acc = (acc + (sample_98 * 2)) & 127;
  int delta_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_53 > 16)
  {
    acc = ((acc + (delta_53 * 2)) + 5) & 127;
    aux ^= delta_53 & 15;
  }
  else
  {
    acc = ((acc - delta_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000827_2713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st_1 = {0};
  struct Transaction_R000827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_54_1 = local_arr_1[aux_1 % 3];
  int factor_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_54_2 * 2)) & 127;
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

  int factor_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_86_1) & 63;
  aux_2 = (aux_2 + factor_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_54_1 == factor_54_2);
  assert(offset_84_1 == offset_84_2);
  assert(factor_86_1 == factor_86_2);
}

int fn_R000827_2713_6(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int factor_54 = local_arr[aux % 3];
  acc = (acc + (factor_54 * 2)) & 127;
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

  int factor_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000827_2713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_25_1 > 22)
  {
    acc_1 = ((acc_1 + (quantum_25_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_25_2 > 22)
  {
    acc_2 = ((acc_2 + (quantum_25_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_18_1)
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

  switch (sample_18_2)
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
  int accumulator_16_1 = local_arr_1[aux_1 % 3];
  int accumulator_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_16_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_25_1 == quantum_25_2);
  assert(sample_18_1 == sample_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_16_1 == accumulator_16_2);
}

int fn_R000827_2713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_25 > 22)
  {
    acc = ((acc + (quantum_25 * 2)) + 5) & 127;
    aux ^= quantum_25 & 15;
  }
  else
  {
    acc = ((acc - quantum_25) + 11) & 127;
    aux += 3;
  }
  int sample_18 = (aux + st.buffer[1]) & 3;
  switch (sample_18)
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
  int accumulator_16 = local_arr[aux % 3];
  acc = (acc + (accumulator_16 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000827_2713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int residue_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_60_1)
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

  switch (residue_60_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_33_1 > 29)
  {
    acc_1 = ((acc_1 + (mask_33_1 * 2)) + 5) & 127;
    aux_1 ^= mask_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_33_2 > 29)
  {
    acc_2 = ((acc_2 + (mask_33_2 * 2)) + 5) & 127;
    aux_2 ^= mask_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_83_1) & 63;
  aux_2 = (aux_2 + delta_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_60_1 == residue_60_2);
  assert(mask_33_1 == mask_33_2);
  assert(delta_83_1 == delta_83_2);
}

int fn_R000827_2713_8(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int residue_60 = (aux + st.buffer[1]) & 3;
  switch (residue_60)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_33 > 29)
  {
    acc = ((acc + (mask_33 * 2)) + 5) & 127;
    aux ^= mask_33 & 15;
  }
  else
  {
    acc = ((acc - mask_33) + 11) & 127;
    aux += 3;
  }
  int delta_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_83) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000827_2713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int sample_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_62_1) & 63;
  aux_2 = (aux_2 + sample_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_48_1)
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

  switch (tracker_48_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_69_1 > 44)
  {
    acc_1 = ((acc_1 + (factor_69_1 * 2)) + 5) & 127;
    aux_1 ^= factor_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_69_2 > 44)
  {
    acc_2 = ((acc_2 + (factor_69_2 * 2)) + 5) & 127;
    aux_2 ^= factor_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_62_1 == sample_62_2);
  assert(tracker_48_1 == tracker_48_2);
  assert(factor_69_1 == factor_69_2);
}

int fn_R000827_2713_9(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int sample_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_62) & 63;
  acc ^= aux;
  int tracker_48 = (aux + st.buffer[1]) & 3;
  switch (tracker_48)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_69 > 44)
  {
    acc = ((acc + (factor_69 * 2)) + 5) & 127;
    aux ^= factor_69 & 15;
  }
  else
  {
    acc = ((acc - factor_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000827_2713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_40_1 > 13)
  {
    acc_1 = ((acc_1 + (checksum_40_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_40_2 > 13)
  {
    acc_2 = ((acc_2 + (checksum_40_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_63_1)
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

  switch (stride_63_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_40_1 == checksum_40_2);
  assert(stride_63_1 == stride_63_2);
}

int fn_R000827_2713_10(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_40 > 13)
  {
    acc = ((acc + (checksum_40 * 2)) + 5) & 127;
    aux ^= checksum_40 & 15;
  }
  else
  {
    acc = ((acc - checksum_40) + 11) & 127;
    aux += 3;
  }
  int stride_63 = (aux + st.buffer[1]) & 3;
  switch (stride_63)
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

void fn_R000827_2713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st_1 = {0};
  struct Transaction_R000827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int phase_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_21_1) & 63;
  aux_2 = (aux_2 + phase_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_81_1)
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

  switch (cursor_81_2)
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
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_21_1 == phase_21_2);
  assert(cursor_81_1 == cursor_81_2);
}

int fn_R000827_2713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int phase_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_21) & 63;
  acc ^= aux;
  int cursor_81 = (aux + st.buffer[1]) & 3;
  switch (cursor_81)
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

void fn_R000827_2713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st_1 = {0};
  struct Transaction_R000827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int margin_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_91_1) & 63;
  aux_2 = (aux_2 + margin_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_47_1 > 16)
  {
    acc_1 = ((acc_1 + (bound_47_1 * 2)) + 5) & 127;
    aux_1 ^= bound_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_47_2 > 16)
  {
    acc_2 = ((acc_2 + (bound_47_2 * 2)) + 5) & 127;
    aux_2 ^= bound_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_47_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_91_1 = local_arr_1[aux_1 % 3];
  int sample_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_91_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_91_1 == margin_91_2);
  assert(bound_47_1 == bound_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_91_1 == sample_91_2);
}

int fn_R000827_2713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int margin_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_91) & 63;
  acc ^= aux;
  int bound_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_47 > 16)
  {
    acc = ((acc + (bound_47 * 2)) + 5) & 127;
    aux ^= bound_47 & 15;
  }
  else
  {
    acc = ((acc - bound_47) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_91 = local_arr[aux % 3];
  acc = (acc + (sample_91 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000827_2713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st_1 = {0};
  struct Transaction_R000827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int quantum_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_55_1) & 63;
  aux_2 = (aux_2 + quantum_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_64_1 = local_arr_1[aux_1 % 3];
  int window_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_55_1 == quantum_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_64_1 == window_64_2);
}

int fn_R000827_2713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int quantum_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_55) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_64 = local_arr[aux % 3];
  acc = (acc + (window_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000827_2713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st_1 = {0};
  struct Transaction_R000827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int coefficient_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_43_1)
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

  switch (coefficient_43_2)
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

  int accumulator_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_32_1 > 43)
  {
    acc_1 = ((acc_1 + (accumulator_32_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_32_2 > 43)
  {
    acc_2 = ((acc_2 + (accumulator_32_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_20_1) & 63;
  aux_2 = (aux_2 + phase_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_43_1 == coefficient_43_2);
  assert(accumulator_32_1 == accumulator_32_2);
  assert(phase_20_1 == phase_20_2);
}

int fn_R000827_2713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int coefficient_43 = (aux + st.buffer[1]) & 3;
  switch (coefficient_43)
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

  int accumulator_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_32 > 43)
  {
    acc = ((acc + (accumulator_32 * 2)) + 5) & 127;
    aux ^= accumulator_32 & 15;
  }
  else
  {
    acc = ((acc - accumulator_32) + 11) & 127;
    aux += 3;
  }
  int phase_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_20) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000827_2713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_63_1 = local_arr_1[aux_1 % 3];
  int bound_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_63_2 * 2)) & 127;
  int offset_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_25_1)
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

  switch (offset_25_2)
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

  int delta_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_87_1 > 17)
  {
    acc_1 = ((acc_1 + (delta_87_1 * 2)) + 5) & 127;
    aux_1 ^= delta_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_87_2 > 17)
  {
    acc_2 = ((acc_2 + (delta_87_2 * 2)) + 5) & 127;
    aux_2 ^= delta_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_87_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_63_1 == bound_63_2);
  assert(offset_25_1 == offset_25_2);
  assert(delta_87_1 == delta_87_2);
}

int fn_R000827_2713_15(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int bound_63 = local_arr[aux % 3];
  acc = (acc + (bound_63 * 2)) & 127;
  int offset_25 = (aux + st.buffer[1]) & 3;
  switch (offset_25)
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

  int delta_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_87 > 17)
  {
    acc = ((acc + (delta_87 * 2)) + 5) & 127;
    aux ^= delta_87 & 15;
  }
  else
  {
    acc = ((acc - delta_87) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000827_2713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int threshold_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_43_1) & 63;
  aux_2 = (aux_2 + threshold_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_98_1 > 19)
  {
    acc_1 = ((acc_1 + (anchor_98_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_98_2 > 19)
  {
    acc_2 = ((acc_2 + (anchor_98_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_71_1)
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

  switch (accumulator_71_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_43_1 == threshold_43_2);
  assert(anchor_98_1 == anchor_98_2);
  assert(accumulator_71_1 == accumulator_71_2);
}

int fn_R000827_2713_16(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int threshold_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_43) & 63;
  acc ^= aux;
  int anchor_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_98 > 19)
  {
    acc = ((acc + (anchor_98 * 2)) + 5) & 127;
    aux ^= anchor_98 & 15;
  }
  else
  {
    acc = ((acc - anchor_98) + 11) & 127;
    aux += 3;
  }
  int accumulator_71 = (aux + st.buffer[1]) & 3;
  switch (accumulator_71)
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

void fn_R000827_2713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int weight_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_94_1)
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

  switch (weight_94_2)
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
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_94_1 == weight_94_2);
}

int fn_R000827_2713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int weight_94 = (aux + st.buffer[1]) & 3;
  switch (weight_94)
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

void fn_R000827_2713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st_1 = {0};
  struct Transaction_R000827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_38_1)
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

  switch (cursor_38_2)
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

  int bound_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_43_1) & 63;
  aux_2 = (aux_2 + bound_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_38_1 == cursor_38_2);
  assert(bound_43_1 == bound_43_2);
}

int fn_R000827_2713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_38 = (aux + st.buffer[1]) & 3;
  switch (cursor_38)
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

  int bound_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_43) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000827_2713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st_1 = {0};
  struct Transaction_R000827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int sample_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_52_1 > 13)
  {
    acc_1 = ((acc_1 + (sample_52_1 * 2)) + 5) & 127;
    aux_1 ^= sample_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_52_2 > 13)
  {
    acc_2 = ((acc_2 + (sample_52_2 * 2)) + 5) & 127;
    aux_2 ^= sample_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_52_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_52_1 == sample_52_2);
}

int fn_R000827_2713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int sample_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_52 > 13)
  {
    acc = ((acc + (sample_52 * 2)) + 5) & 127;
    aux ^= sample_52 & 15;
  }
  else
  {
    acc = ((acc - sample_52) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000827_2713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int threshold_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_59_1)
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

  switch (threshold_59_2)
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

  int pivot_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_86_1) & 63;
  aux_2 = (aux_2 + pivot_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_59_1 == threshold_59_2);
  assert(pivot_86_1 == pivot_86_2);
}

int fn_R000827_2713_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int threshold_59 = (aux + st.buffer[1]) & 3;
  switch (threshold_59)
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

  int pivot_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_86) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000827_0_1;
  int sec_r000827_0_2;
  int sec_r000827_1_1;
  int sec_r000827_1_2;
  int sec_r000827_2_1;
  int sec_r000827_2_2;
  int sec_r000827_3_1;
  int sec_r000827_3_2;
  int sec_r000827_4_1;
  int sec_r000827_4_2;
  int sec_r000827_5_1;
  int sec_r000827_5_2;
  int sec_r000827_6_1;
  int sec_r000827_6_2;
  int sec_r000827_7_1;
  int sec_r000827_7_2;
  int sec_r000827_8_1;
  int sec_r000827_8_2;
  int sec_r000827_9_1;
  int sec_r000827_9_2;
  int sec_r000827_10_1;
  int sec_r000827_10_2;
  int sec_r000827_11_1;
  int sec_r000827_11_2;
  int sec_r000827_12_1;
  int sec_r000827_12_2;
  int sec_r000827_13_1;
  int sec_r000827_13_2;
  int sec_r000827_14_1;
  int sec_r000827_14_2;
  int sec_r000827_15_1;
  int sec_r000827_15_2;
  int sec_r000827_16_1;
  int sec_r000827_16_2;
  int sec_r000827_17_1;
  int sec_r000827_17_2;
  int sec_r000827_18_1;
  int sec_r000827_18_2;
  int sec_r000827_19_1;
  int sec_r000827_19_2;
  int sec_r000827_20_1;
  int sec_r000827_20_2;
  int sec_r000827_21_1;
  int sec_r000827_21_2;
  int pub_r000827_0_1;
  int pub_r000827_0_2;
  int pub_r000827_1_1;
  int pub_r000827_1_2;
  int pub_r000827_2_1;
  int pub_r000827_2_2;
  int pub_r000827_3_1;
  int pub_r000827_3_2;
  int pub_r000827_4_1;
  int pub_r000827_4_2;
  int pub_r000827_5_1;
  int pub_r000827_5_2;
  int pub_r000827_6_1;
  int pub_r000827_6_2;
  int pub_r000827_7_1;
  int pub_r000827_7_2;
  int pub_r000827_8_1;
  int pub_r000827_8_2;
  int pub_r000827_9_1;
  int pub_r000827_9_2;
  int pub_r000827_10_1;
  int pub_r000827_10_2;
  int pub_r000827_11_1;
  int pub_r000827_11_2;
  int pub_r000827_12_1;
  int pub_r000827_12_2;
  int pub_r000827_13_1;
  int pub_r000827_13_2;
  int pub_r000827_14_1;
  int pub_r000827_14_2;
  int pub_r000827_15_1;
  int pub_r000827_15_2;
  int pub_r000827_16_1;
  int pub_r000827_16_2;
  int pub_r000827_17_1;
  int pub_r000827_17_2;
  int pub_r000827_18_1;
  int pub_r000827_18_2;
  int pub_r000827_19_1;
  int pub_r000827_19_2;
  int pub_r000827_20_1;
  int pub_r000827_20_2;
  int pub_r000827_21_1;
  int pub_r000827_21_2;
  int pub_r000827_22_1;
  int pub_r000827_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000827_0_1 >= (-100)) && (pub_r000827_0_1 <= 100));
  __CPROVER_assume((pub_r000827_0_2 >= (-100)) && (pub_r000827_0_2 <= 100));
  __CPROVER_assume((pub_r000827_1_1 >= (-100)) && (pub_r000827_1_1 <= 100));
  __CPROVER_assume((pub_r000827_1_2 >= (-100)) && (pub_r000827_1_2 <= 100));
  __CPROVER_assume((pub_r000827_2_1 >= (-100)) && (pub_r000827_2_1 <= 100));
  __CPROVER_assume((pub_r000827_2_2 >= (-100)) && (pub_r000827_2_2 <= 100));
  __CPROVER_assume((pub_r000827_3_1 >= (-100)) && (pub_r000827_3_1 <= 100));
  __CPROVER_assume((pub_r000827_3_2 >= (-100)) && (pub_r000827_3_2 <= 100));
  __CPROVER_assume((pub_r000827_4_1 >= (-100)) && (pub_r000827_4_1 <= 100));
  __CPROVER_assume((pub_r000827_4_2 >= (-100)) && (pub_r000827_4_2 <= 100));
  __CPROVER_assume((pub_r000827_5_1 >= (-100)) && (pub_r000827_5_1 <= 100));
  __CPROVER_assume((pub_r000827_5_2 >= (-100)) && (pub_r000827_5_2 <= 100));
  __CPROVER_assume((pub_r000827_6_1 >= (-100)) && (pub_r000827_6_1 <= 100));
  __CPROVER_assume((pub_r000827_6_2 >= (-100)) && (pub_r000827_6_2 <= 100));
  __CPROVER_assume((pub_r000827_7_1 >= (-100)) && (pub_r000827_7_1 <= 100));
  __CPROVER_assume((pub_r000827_7_2 >= (-100)) && (pub_r000827_7_2 <= 100));
  __CPROVER_assume((pub_r000827_8_1 >= (-100)) && (pub_r000827_8_1 <= 100));
  __CPROVER_assume((pub_r000827_8_2 >= (-100)) && (pub_r000827_8_2 <= 100));
  __CPROVER_assume((pub_r000827_9_1 >= (-100)) && (pub_r000827_9_1 <= 100));
  __CPROVER_assume((pub_r000827_9_2 >= (-100)) && (pub_r000827_9_2 <= 100));
  __CPROVER_assume((pub_r000827_10_1 >= (-100)) && (pub_r000827_10_1 <= 100));
  __CPROVER_assume((pub_r000827_10_2 >= (-100)) && (pub_r000827_10_2 <= 100));
  __CPROVER_assume((pub_r000827_11_1 >= (-100)) && (pub_r000827_11_1 <= 100));
  __CPROVER_assume((pub_r000827_11_2 >= (-100)) && (pub_r000827_11_2 <= 100));
  __CPROVER_assume((pub_r000827_12_1 >= (-100)) && (pub_r000827_12_1 <= 100));
  __CPROVER_assume((pub_r000827_12_2 >= (-100)) && (pub_r000827_12_2 <= 100));
  __CPROVER_assume((pub_r000827_13_1 >= (-100)) && (pub_r000827_13_1 <= 100));
  __CPROVER_assume((pub_r000827_13_2 >= (-100)) && (pub_r000827_13_2 <= 100));
  __CPROVER_assume((pub_r000827_14_1 >= (-100)) && (pub_r000827_14_1 <= 100));
  __CPROVER_assume((pub_r000827_14_2 >= (-100)) && (pub_r000827_14_2 <= 100));
  __CPROVER_assume((pub_r000827_15_1 >= (-100)) && (pub_r000827_15_1 <= 100));
  __CPROVER_assume((pub_r000827_15_2 >= (-100)) && (pub_r000827_15_2 <= 100));
  __CPROVER_assume((pub_r000827_16_1 >= (-100)) && (pub_r000827_16_1 <= 100));
  __CPROVER_assume((pub_r000827_16_2 >= (-100)) && (pub_r000827_16_2 <= 100));
  __CPROVER_assume((pub_r000827_17_1 >= (-100)) && (pub_r000827_17_1 <= 100));
  __CPROVER_assume((pub_r000827_17_2 >= (-100)) && (pub_r000827_17_2 <= 100));
  __CPROVER_assume((pub_r000827_18_1 >= (-100)) && (pub_r000827_18_1 <= 100));
  __CPROVER_assume((pub_r000827_18_2 >= (-100)) && (pub_r000827_18_2 <= 100));
  __CPROVER_assume((pub_r000827_19_1 >= (-100)) && (pub_r000827_19_1 <= 100));
  __CPROVER_assume((pub_r000827_19_2 >= (-100)) && (pub_r000827_19_2 <= 100));
  __CPROVER_assume((pub_r000827_20_1 >= (-100)) && (pub_r000827_20_1 <= 100));
  __CPROVER_assume((pub_r000827_20_2 >= (-100)) && (pub_r000827_20_2 <= 100));
  __CPROVER_assume((pub_r000827_21_1 >= (-100)) && (pub_r000827_21_1 <= 100));
  __CPROVER_assume((pub_r000827_21_2 >= (-100)) && (pub_r000827_21_2 <= 100));
  __CPROVER_assume((pub_r000827_22_1 >= (-100)) && (pub_r000827_22_1 <= 100));
  __CPROVER_assume((pub_r000827_22_2 >= (-100)) && (pub_r000827_22_2 <= 100));
  __CPROVER_assume((sec_r000827_0_1 >= 0) && (sec_r000827_0_1 <= 255));
  __CPROVER_assume((sec_r000827_0_2 >= 0) && (sec_r000827_0_2 <= 255));
  __CPROVER_assume((sec_r000827_1_1 >= 0) && (sec_r000827_1_1 <= 255));
  __CPROVER_assume((sec_r000827_1_2 >= 0) && (sec_r000827_1_2 <= 255));
  __CPROVER_assume((sec_r000827_2_1 >= 0) && (sec_r000827_2_1 <= 255));
  __CPROVER_assume((sec_r000827_2_2 >= 0) && (sec_r000827_2_2 <= 255));
  __CPROVER_assume((sec_r000827_3_1 >= 0) && (sec_r000827_3_1 <= 255));
  __CPROVER_assume((sec_r000827_3_2 >= 0) && (sec_r000827_3_2 <= 255));
  __CPROVER_assume((sec_r000827_4_1 >= 0) && (sec_r000827_4_1 <= 255));
  __CPROVER_assume((sec_r000827_4_2 >= 0) && (sec_r000827_4_2 <= 255));
  __CPROVER_assume((sec_r000827_5_1 >= 0) && (sec_r000827_5_1 <= 255));
  __CPROVER_assume((sec_r000827_5_2 >= 0) && (sec_r000827_5_2 <= 255));
  __CPROVER_assume((sec_r000827_6_1 >= 0) && (sec_r000827_6_1 <= 255));
  __CPROVER_assume((sec_r000827_6_2 >= 0) && (sec_r000827_6_2 <= 255));
  __CPROVER_assume((sec_r000827_7_1 >= 0) && (sec_r000827_7_1 <= 255));
  __CPROVER_assume((sec_r000827_7_2 >= 0) && (sec_r000827_7_2 <= 255));
  __CPROVER_assume((sec_r000827_8_1 >= 0) && (sec_r000827_8_1 <= 255));
  __CPROVER_assume((sec_r000827_8_2 >= 0) && (sec_r000827_8_2 <= 255));
  __CPROVER_assume((sec_r000827_9_1 >= 0) && (sec_r000827_9_1 <= 255));
  __CPROVER_assume((sec_r000827_9_2 >= 0) && (sec_r000827_9_2 <= 255));
  __CPROVER_assume((sec_r000827_10_1 >= 0) && (sec_r000827_10_1 <= 255));
  __CPROVER_assume((sec_r000827_10_2 >= 0) && (sec_r000827_10_2 <= 255));
  __CPROVER_assume((sec_r000827_11_1 >= 0) && (sec_r000827_11_1 <= 255));
  __CPROVER_assume((sec_r000827_11_2 >= 0) && (sec_r000827_11_2 <= 255));
  __CPROVER_assume((sec_r000827_12_1 >= 0) && (sec_r000827_12_1 <= 255));
  __CPROVER_assume((sec_r000827_12_2 >= 0) && (sec_r000827_12_2 <= 255));
  __CPROVER_assume((sec_r000827_13_1 >= 0) && (sec_r000827_13_1 <= 255));
  __CPROVER_assume((sec_r000827_13_2 >= 0) && (sec_r000827_13_2 <= 255));
  __CPROVER_assume((sec_r000827_14_1 >= 0) && (sec_r000827_14_1 <= 255));
  __CPROVER_assume((sec_r000827_14_2 >= 0) && (sec_r000827_14_2 <= 255));
  __CPROVER_assume((sec_r000827_15_1 >= 0) && (sec_r000827_15_1 <= 255));
  __CPROVER_assume((sec_r000827_15_2 >= 0) && (sec_r000827_15_2 <= 255));
  __CPROVER_assume((sec_r000827_16_1 >= 0) && (sec_r000827_16_1 <= 255));
  __CPROVER_assume((sec_r000827_16_2 >= 0) && (sec_r000827_16_2 <= 255));
  __CPROVER_assume((sec_r000827_17_1 >= 0) && (sec_r000827_17_1 <= 255));
  __CPROVER_assume((sec_r000827_17_2 >= 0) && (sec_r000827_17_2 <= 255));
  __CPROVER_assume((sec_r000827_18_1 >= 0) && (sec_r000827_18_1 <= 255));
  __CPROVER_assume((sec_r000827_18_2 >= 0) && (sec_r000827_18_2 <= 255));
  __CPROVER_assume((sec_r000827_19_1 >= 0) && (sec_r000827_19_1 <= 255));
  __CPROVER_assume((sec_r000827_19_2 >= 0) && (sec_r000827_19_2 <= 255));
  __CPROVER_assume((sec_r000827_20_1 >= 0) && (sec_r000827_20_1 <= 255));
  __CPROVER_assume((sec_r000827_20_2 >= 0) && (sec_r000827_20_2 <= 255));
  __CPROVER_assume((sec_r000827_21_1 >= 0) && (sec_r000827_21_1 <= 255));
  __CPROVER_assume((sec_r000827_21_2 >= 0) && (sec_r000827_21_2 <= 255));
  struct MatrixBlock_R000827_2713_0 st_var_0_1 = {0};
  struct MatrixBlock_R000827_2713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000827_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000827_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000827_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000827_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000827_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000827_0_2 + 7) & 15;
  struct Transaction_R000827_2713_1 st_var_1_1 = {0};
  struct Transaction_R000827_2713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000827_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000827_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000827_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000827_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000827_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000827_0_2 + 9) & 15;
  union ColorPixel_R000827_2713_0 u_var_1;
  union ColorPixel_R000827_2713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 1) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 1) & 15;
  int stage_v_0_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_0_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= stage_v_0_1;
  chk_sum_2 ^= stage_v_0_2;
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 50)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 50)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  int stage_v_3_1 = (st_var_1_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_1_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  }

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
  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = ((st_var_1_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_1_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 33)
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
  if (stage_v_11_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 33)
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
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 55)
    {
      chk_sum_1 ^= stage_v_12_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_12_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 55)
    {
      chk_sum_2 ^= stage_v_12_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 26)
    {
      chk_sum_1 ^= stage_v_13_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_13_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 26)
    {
      chk_sum_2 ^= stage_v_13_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
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
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((st_var_0_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_0_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 26)
    {
      chk_sum_1 ^= stage_v_20_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_20_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 26)
    {
      chk_sum_2 ^= stage_v_20_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = (st_var_0_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_0_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = ((st_var_1_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_1_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 46)
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
  if (stage_v_23_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 46)
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
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
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
  int stage_v_29_1 = table_1[1];
  int stage_v_29_2 = table_2[1];
  table_1[1] = (table_1[2] + 59) & 63;
  table_2[1] = (table_2[2] + 59) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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

  switch (stage_v_33_2)
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

  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 36) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 47)
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
  if (stage_v_36_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 47)
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
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_37_1 = ((stage_v_37_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_37_2 = ((stage_v_37_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 40) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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
  if (stage_v_46_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 34)
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
  if (stage_v_46_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 34)
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
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 48) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 48) & 15;
  int stage_v_47_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_47_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= stage_v_47_1;
  chk_sum_2 ^= stage_v_47_2;
  int stage_v_48_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_48_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 50) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 50) & 15;
  int stage_v_49_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_49_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= stage_v_49_1;
  chk_sum_2 ^= stage_v_49_2;
  int stage_v_50_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_50_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_51_1 = ((st_var_1_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_1_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 45)
    {
      chk_sum_1 ^= stage_v_51_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_51_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 45)
    {
      chk_sum_2 ^= stage_v_51_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 53) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = (st_var_1_1.buffer[0] ^ 56) & 3;
  int stage_v_53_2 = (st_var_1_2.buffer[0] ^ 56) & 3;
  switch (stage_v_53_1)
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

  switch (stage_v_53_2)
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

  int stage_v_54_1 = (st_var_0_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_0_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  int stage_v_55_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (60 & 31);
  int stage_v_55_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (60 & 31);
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= (stage_v_55_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_55_2 << 1) & 127;
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = ((st_var_1_1.buffer[0] * 2) + 178) & 63;
  int stage_v_57_2 = ((st_var_1_2.buffer[0] * 2) + 178) & 63;
  if (stage_v_57_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 49)
    {
      chk_sum_1 ^= stage_v_57_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_57_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 49)
    {
      chk_sum_2 ^= stage_v_57_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 61) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 61) & 15;
  int stage_v_60_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_60_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= stage_v_60_1;
  chk_sum_2 ^= stage_v_60_2;
  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_62_1 = ((stage_v_62_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_62_2 = ((stage_v_62_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 64) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 64) & 15;
  int stage_v_63_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_63_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= stage_v_63_1;
  chk_sum_2 ^= stage_v_63_2;
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
  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((st_var_0_1.buffer[0] * 2) + 205) & 63;
  int stage_v_66_2 = ((st_var_0_2.buffer[0] * 2) + 205) & 63;
  if (stage_v_66_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_66_1) - 5) & 255;
    if (stage_v_66_1 > 47)
    {
      chk_sum_1 ^= stage_v_66_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_66_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_66_2) - 5) & 255;
    if (stage_v_66_2 > 47)
    {
      chk_sum_2 ^= stage_v_66_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 68) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 68) & 15;
  int stage_v_67_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_67_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= stage_v_67_1;
  chk_sum_2 ^= stage_v_67_2;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((st_var_1_1.buffer[0] * 2) + 214) & 63;
  int stage_v_69_2 = ((st_var_1_2.buffer[0] * 2) + 214) & 63;
  if (stage_v_69_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_69_1) - 5) & 255;
    if (stage_v_69_1 > 45)
    {
      chk_sum_1 ^= stage_v_69_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_69_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_69_2) - 5) & 255;
    if (stage_v_69_2 > 45)
    {
      chk_sum_2 ^= stage_v_69_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (76 & 31);
  int stage_v_71_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (76 & 31);
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= (stage_v_71_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_71_2 << 1) & 127;
  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_73_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (78 & 31);
  int stage_v_73_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (78 & 31);
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= (stage_v_73_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_73_2 << 1) & 127;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000827_20_1 & 1) != 0)
  {
    if ((sec_r000827_5_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000827_17_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000827_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000827_17_1 + 7) & 127;
  }
  if ((sec_r000827_20_2 & 1) != 0)
  {
    if ((sec_r000827_5_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000827_17_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000827_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000827_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000827_16_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000827_16_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000827_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000827_16_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000827_16_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000827_16_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000827_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000827_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000827_20_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000827_15_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000827_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000827_15_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000827_20_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000827_15_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000827_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000827_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000827_12_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000827_0_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000827_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000827_0_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000827_12_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000827_0_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000827_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000827_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000827_13_1 & 1) != 0)
  {
    if ((sec_r000827_21_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000827_2_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000827_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000827_2_1 + 7) & 127;
  }
  if ((sec_r000827_13_2 & 1) != 0)
  {
    if ((sec_r000827_21_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000827_2_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000827_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000827_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000827_2_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000827_14_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000827_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000827_14_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000827_2_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000827_14_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000827_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000827_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000827_21_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000827_3_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000827_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000827_3_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000827_21_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000827_3_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000827_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000827_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000827_14_1 & 1) != 0)
  {
    if ((sec_r000827_15_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000827_7_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000827_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000827_7_1 + 7) & 127;
  }
  if ((sec_r000827_14_2 & 1) != 0)
  {
    if ((sec_r000827_15_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000827_7_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000827_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000827_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000827_16_1 & 1) != 0)
  {
    if ((sec_r000827_20_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000827_16_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000827_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000827_16_1 + 7) & 127;
  }
  if ((sec_r000827_16_2 & 1) != 0)
  {
    if ((sec_r000827_20_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000827_16_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000827_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000827_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000827_3_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000827_16_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000827_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000827_16_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000827_3_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000827_16_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000827_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000827_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000827_0_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000827_21_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000827_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000827_21_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000827_0_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000827_21_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000827_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000827_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000827_2_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000827_8_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000827_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000827_8_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000827_2_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000827_8_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000827_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000827_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000827_1_1 & 1) != 0)
  {
    if ((sec_r000827_7_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000827_7_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000827_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000827_7_1 + 7) & 127;
  }
  if ((sec_r000827_1_2 & 1) != 0)
  {
    if ((sec_r000827_7_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000827_7_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000827_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000827_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000827_18_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000827_17_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000827_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000827_17_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000827_18_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000827_17_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000827_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000827_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000827_7_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000827_1_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000827_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000827_1_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000827_7_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000827_1_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000827_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000827_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000827_14_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000827_18_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000827_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000827_18_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000827_14_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000827_18_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000827_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000827_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000827_2_1 & 1) != 0)
  {
    if ((sec_r000827_12_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000827_8_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000827_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000827_8_1 + 7) & 127;
  }
  if ((sec_r000827_2_2 & 1) != 0)
  {
    if ((sec_r000827_12_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000827_8_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000827_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000827_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000827_12_1 & 1) != 0)
  {
    if ((sec_r000827_20_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000827_10_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000827_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000827_10_1 + 7) & 127;
  }
  if ((sec_r000827_12_2 & 1) != 0)
  {
    if ((sec_r000827_20_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000827_10_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000827_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000827_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000827_6_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000827_14_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000827_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000827_14_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000827_6_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000827_14_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000827_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000827_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000827_20_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000827_0_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000827_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000827_0_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000827_20_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000827_0_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000827_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000827_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000827_4_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000827_1_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000827_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000827_1_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000827_4_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000827_1_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000827_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000827_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000827_13_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000827_22_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000827_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000827_22_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000827_13_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000827_22_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000827_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000827_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000827_5_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000827_1_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000827_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000827_1_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000827_5_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000827_1_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000827_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000827_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000827_1_1 & 1) != 0)
  {
    if ((sec_r000827_2_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000827_21_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000827_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000827_21_1 + 7) & 127;
  }
  if ((sec_r000827_1_2 & 1) != 0)
  {
    if ((sec_r000827_2_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000827_21_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000827_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000827_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000827_14_1 & 1) != 0)
  {
    if ((sec_r000827_13_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000827_22_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000827_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000827_22_1 + 7) & 127;
  }
  if ((sec_r000827_14_2 & 1) != 0)
  {
    if ((sec_r000827_13_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000827_22_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000827_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000827_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000827_6_1 & 1) != 0)
  {
    if ((sec_r000827_16_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000827_16_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000827_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000827_16_1 + 7) & 127;
  }
  if ((sec_r000827_6_2 & 1) != 0)
  {
    if ((sec_r000827_16_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000827_16_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000827_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000827_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000827_8_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000827_11_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000827_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000827_11_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000827_8_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000827_11_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000827_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000827_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000827_11_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000827_6_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000827_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000827_6_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000827_11_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000827_6_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000827_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000827_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000827_3_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000827_14_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000827_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000827_14_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000827_3_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000827_14_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000827_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000827_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000827_10_1 & 1) != 0)
  {
    if ((sec_r000827_19_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000827_2_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000827_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000827_2_1 + 7) & 127;
  }
  if ((sec_r000827_10_2 & 1) != 0)
  {
    if ((sec_r000827_19_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000827_2_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000827_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000827_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000827_11_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000827_19_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000827_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000827_19_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000827_11_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000827_19_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000827_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000827_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000827_0_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000827_22_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000827_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000827_22_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000827_0_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000827_22_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000827_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000827_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000827_12_1 & 1) != 0)
  {
    if ((sec_r000827_20_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000827_7_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000827_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000827_7_1 + 7) & 127;
  }
  if ((sec_r000827_12_2 & 1) != 0)
  {
    if ((sec_r000827_20_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000827_7_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000827_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000827_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000827_14_1 & 1) != 0)
  {
    if ((sec_r000827_19_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000827_13_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000827_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000827_13_1 + 7) & 127;
  }
  if ((sec_r000827_14_2 & 1) != 0)
  {
    if ((sec_r000827_19_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000827_13_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000827_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000827_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000827_7_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000827_6_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000827_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000827_6_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000827_7_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000827_6_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000827_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000827_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000827_6_1 & 1) != 0)
  {
    if ((sec_r000827_4_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000827_0_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000827_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000827_0_1 + 7) & 127;
  }
  if ((sec_r000827_6_2 & 1) != 0)
  {
    if ((sec_r000827_4_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000827_0_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000827_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000827_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000827_19_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000827_20_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000827_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000827_20_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000827_19_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000827_20_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000827_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000827_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000827_5_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000827_13_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000827_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000827_13_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000827_5_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000827_13_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000827_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000827_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000827_12_1 & 1) != 0)
  {
    if ((sec_r000827_13_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000827_6_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000827_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000827_6_1 + 7) & 127;
  }
  if ((sec_r000827_12_2 & 1) != 0)
  {
    if ((sec_r000827_13_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000827_6_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000827_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000827_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000827_9_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000827_13_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000827_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000827_13_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000827_9_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000827_13_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000827_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000827_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000827_11_1 & 1) != 0)
  {
    if ((sec_r000827_17_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000827_6_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000827_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000827_6_1 + 7) & 127;
  }
  if ((sec_r000827_11_2 & 1) != 0)
  {
    if ((sec_r000827_17_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000827_6_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000827_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000827_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000827_17_1 & 1) != 0)
  {
    if ((sec_r000827_8_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000827_22_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000827_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000827_22_1 + 7) & 127;
  }
  if ((sec_r000827_17_2 & 1) != 0)
  {
    if ((sec_r000827_8_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000827_22_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000827_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000827_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000827_12_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000827_15_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000827_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000827_15_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000827_12_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000827_15_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000827_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000827_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000827_1_1 & 1) != 0)
  {
    if ((sec_r000827_7_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000827_0_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000827_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000827_0_1 + 7) & 127;
  }
  if ((sec_r000827_1_2 & 1) != 0)
  {
    if ((sec_r000827_7_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000827_0_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000827_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000827_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000827_9_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000827_1_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000827_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000827_1_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000827_9_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000827_1_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000827_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000827_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000827_19_1 & 1) != 0)
  {
    if ((sec_r000827_0_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000827_13_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000827_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000827_13_1 + 7) & 127;
  }
  if ((sec_r000827_19_2 & 1) != 0)
  {
    if ((sec_r000827_0_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000827_13_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000827_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000827_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000827_6_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000827_9_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000827_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000827_9_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000827_6_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000827_9_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000827_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000827_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000827_8_1 & 1) != 0)
  {
    if ((sec_r000827_6_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000827_18_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000827_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000827_18_1 + 7) & 127;
  }
  if ((sec_r000827_8_2 & 1) != 0)
  {
    if ((sec_r000827_6_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000827_18_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000827_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000827_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000827_10_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000827_15_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000827_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000827_15_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000827_10_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000827_15_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000827_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000827_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000827_13_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000827_18_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000827_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000827_18_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000827_13_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000827_18_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000827_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000827_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000827_16_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000827_0_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000827_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000827_0_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000827_16_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000827_0_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000827_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000827_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000827_7_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000827_18_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000827_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000827_18_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000827_7_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000827_18_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000827_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000827_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000827_2_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000827_11_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000827_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000827_11_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000827_2_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000827_11_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000827_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000827_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000827_21_1 & 1) != 0)
  {
    if ((sec_r000827_0_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000827_21_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000827_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000827_21_1 + 7) & 127;
  }
  if ((sec_r000827_21_2 & 1) != 0)
  {
    if ((sec_r000827_0_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000827_21_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000827_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000827_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000827_1_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000827_8_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000827_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000827_8_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000827_1_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000827_8_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000827_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000827_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000827_8_1 & 1) != 0)
  {
    if ((sec_r000827_14_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000827_3_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000827_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000827_3_1 + 7) & 127;
  }
  if ((sec_r000827_8_2 & 1) != 0)
  {
    if ((sec_r000827_14_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000827_3_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000827_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000827_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000827_18_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000827_16_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000827_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000827_16_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000827_18_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000827_16_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000827_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000827_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000827_5_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000827_0_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000827_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000827_0_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000827_5_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000827_0_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000827_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000827_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000827_1_1 & 1) != 0)
  {
    if ((sec_r000827_13_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000827_11_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000827_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000827_11_1 + 7) & 127;
  }
  if ((sec_r000827_1_2 & 1) != 0)
  {
    if ((sec_r000827_13_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000827_11_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000827_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000827_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000827_15_1 & 1) != 0)
  {
    if ((sec_r000827_21_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000827_21_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000827_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000827_21_1 + 7) & 127;
  }
  if ((sec_r000827_15_2 & 1) != 0)
  {
    if ((sec_r000827_21_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000827_21_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000827_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000827_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000827_15_1 & 1) != 0)
  {
    if ((sec_r000827_9_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000827_12_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000827_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000827_12_1 + 7) & 127;
  }
  if ((sec_r000827_15_2 & 1) != 0)
  {
    if ((sec_r000827_9_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000827_12_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000827_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000827_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000827_14_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000827_7_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000827_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000827_7_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000827_14_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000827_7_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000827_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000827_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000827_17_1 & 1) != 0)
  {
    if ((sec_r000827_10_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000827_19_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000827_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000827_19_1 + 7) & 127;
  }
  if ((sec_r000827_17_2 & 1) != 0)
  {
    if ((sec_r000827_10_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000827_19_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000827_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000827_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000827_10_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000827_9_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000827_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000827_9_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000827_10_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000827_9_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000827_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000827_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000827_21_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000827_20_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000827_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000827_20_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000827_21_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000827_20_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000827_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000827_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000827_20_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000827_9_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000827_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000827_9_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000827_20_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000827_9_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000827_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000827_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000827_1_1 & 1) != 0)
  {
    if ((sec_r000827_7_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000827_20_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000827_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000827_20_1 + 7) & 127;
  }
  if ((sec_r000827_1_2 & 1) != 0)
  {
    if ((sec_r000827_7_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000827_20_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000827_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000827_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000827_17_1 & 1) != 0)
  {
    if ((sec_r000827_5_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000827_12_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000827_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000827_12_1 + 7) & 127;
  }
  if ((sec_r000827_17_2 & 1) != 0)
  {
    if ((sec_r000827_5_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000827_12_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000827_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000827_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000827_20_1 != sec_r000827_20_2);
  __CPROVER_assume(pub_r000827_20_1 == pub_r000827_20_2);
  __CPROVER_assume(pub_r000827_13_1 == pub_r000827_13_2);
  __CPROVER_assume(sec_r000827_0_1 != sec_r000827_0_2);
  __CPROVER_assume(sec_r000827_3_1 != sec_r000827_3_2);
  __CPROVER_assume(pub_r000827_0_1 == pub_r000827_0_2);
  __CPROVER_assume(pub_r000827_5_1 == pub_r000827_5_2);
  __CPROVER_assume(sec_r000827_15_1 != sec_r000827_15_2);
  __CPROVER_assume(pub_r000827_16_1 == pub_r000827_16_2);
  __CPROVER_assume(sec_r000827_19_1 != sec_r000827_19_2);
  __CPROVER_assume(pub_r000827_17_1 == pub_r000827_17_2);
  __CPROVER_assume(pub_r000827_3_1 == pub_r000827_3_2);
  __CPROVER_assume(sec_r000827_5_1 != sec_r000827_5_2);
  __CPROVER_assume(sec_r000827_4_1 != sec_r000827_4_2);
  __CPROVER_assume(sec_r000827_14_1 != sec_r000827_14_2);
  __CPROVER_assume(pub_r000827_8_1 == pub_r000827_8_2);
  __CPROVER_assume(pub_r000827_11_1 == pub_r000827_11_2);
  __CPROVER_assume(sec_r000827_8_1 != sec_r000827_8_2);
  __CPROVER_assume(sec_r000827_16_1 != sec_r000827_16_2);
  __CPROVER_assume(sec_r000827_21_1 != sec_r000827_21_2);
  __CPROVER_assume(sec_r000827_9_1 != sec_r000827_9_2);
  __CPROVER_assume(sec_r000827_2_1 != sec_r000827_2_2);
  __CPROVER_assume(pub_r000827_12_1 == pub_r000827_12_2);
  __CPROVER_assume(pub_r000827_21_1 == pub_r000827_21_2);
  __CPROVER_assume(sec_r000827_7_1 != sec_r000827_7_2);
  __CPROVER_assume(pub_r000827_4_1 == pub_r000827_4_2);
  __CPROVER_assume(pub_r000827_10_1 == pub_r000827_10_2);
  __CPROVER_assume(pub_r000827_9_1 == pub_r000827_9_2);
  __CPROVER_assume(sec_r000827_18_1 != sec_r000827_18_2);
  __CPROVER_assume(sec_r000827_1_1 != sec_r000827_1_2);
  __CPROVER_assume(pub_r000827_1_1 == pub_r000827_1_2);
  __CPROVER_assume(pub_r000827_2_1 == pub_r000827_2_2);
  __CPROVER_assume(pub_r000827_22_1 == pub_r000827_22_2);
  __CPROVER_assume(pub_r000827_18_1 == pub_r000827_18_2);
  __CPROVER_assume(sec_r000827_6_1 != sec_r000827_6_2);
  __CPROVER_assume(sec_r000827_12_1 != sec_r000827_12_2);
  __CPROVER_assume(pub_r000827_6_1 == pub_r000827_6_2);
  __CPROVER_assume(pub_r000827_7_1 == pub_r000827_7_2);
  __CPROVER_assume(pub_r000827_19_1 == pub_r000827_19_2);
  __CPROVER_assume(sec_r000827_10_1 != sec_r000827_10_2);
  __CPROVER_assume(sec_r000827_11_1 != sec_r000827_11_2);
  __CPROVER_assume(sec_r000827_13_1 != sec_r000827_13_2);
  __CPROVER_assume(sec_r000827_17_1 != sec_r000827_17_2);
  __CPROVER_assume(pub_r000827_15_1 == pub_r000827_15_2);
  __CPROVER_assume(pub_r000827_14_1 == pub_r000827_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.balance == st_var_1_2.balance);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
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
}


