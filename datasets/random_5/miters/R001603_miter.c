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
struct Transaction_R001603_313_0
{
  int account_id;
  int auth_code;
  short balance;
  int status;
  int buffer[3];
};
struct Vector3D_R001603_313_1
{
  unsigned char coord_z;
  unsigned char norm_sq;
  short pitch;
  unsigned char coord_y;
  int heading;
  int buffer[3];
};
struct MatrixBlock_R001603_313_2
{
  int density;
  int determinant;
  int trace;
  int buffer[3];
};
union RegisterBank_R001603_313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001603_313_1
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
void fn_R001603_313_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st_1 = {0};
  struct Vector3D_R001603_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int mask_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_49_1)
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

  switch (mask_49_2)
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

  int index_reg_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_24_1) & 63;
  aux_2 = (aux_2 + index_reg_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_21_1 > 49)
  {
    acc_1 = ((acc_1 + (parity_21_1 * 2)) + 5) & 127;
    aux_1 ^= parity_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_21_2 > 49)
  {
    acc_2 = ((acc_2 + (parity_21_2 * 2)) + 5) & 127;
    aux_2 ^= parity_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_21_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_49_1 == mask_49_2);
  assert(index_reg_24_1 == index_reg_24_2);
  assert(parity_21_1 == parity_21_2);
}

int fn_R001603_313_0(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int mask_49 = (aux + st.buffer[1]) & 3;
  switch (mask_49)
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

  int index_reg_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_24) & 63;
  acc ^= aux;
  int parity_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_21 > 49)
  {
    acc = ((acc + (parity_21 * 2)) + 5) & 127;
    aux ^= parity_21 & 15;
  }
  else
  {
    acc = ((acc - parity_21) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001603_313_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st_1 = {0};
  struct Vector3D_R001603_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int phase_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_95_1) & 63;
  aux_2 = (aux_2 + phase_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_78_1 > 12)
  {
    acc_1 = ((acc_1 + (window_78_1 * 2)) + 5) & 127;
    aux_1 ^= window_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_78_2 > 12)
  {
    acc_2 = ((acc_2 + (window_78_2 * 2)) + 5) & 127;
    aux_2 ^= window_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_78_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_95_1 == phase_95_2);
  assert(window_78_1 == window_78_2);
}

int fn_R001603_313_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int phase_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_95) & 63;
  acc ^= aux;
  int window_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_78 > 12)
  {
    acc = ((acc + (window_78 * 2)) + 5) & 127;
    aux ^= window_78 & 15;
  }
  else
  {
    acc = ((acc - window_78) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001603_313_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001603_313_2 st_1 = {0};
  struct MatrixBlock_R001603_313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int metric_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_14_1)
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

  switch (metric_14_2)
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

  int quotient_26_1 = 0;
  int quotient_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_26_1 = ((quotient_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_26_2 = ((quotient_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_26_1) & 127;
    acc_2 = (acc_2 + quotient_26_2) & 127;
  }

  int tracker_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_97_1) & 63;
  aux_2 = (aux_2 + tracker_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_14_1 == metric_14_2);
  assert(quotient_26_1 == quotient_26_2);
  assert(tracker_97_1 == tracker_97_2);
}

int fn_R001603_313_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001603_313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int metric_14 = (aux + st.buffer[1]) & 3;
  switch (metric_14)
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

  int quotient_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_26 = ((quotient_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_26) & 127;
  }

  int tracker_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001603_313_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st_1 = {0};
  struct Transaction_R001603_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int pivot_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_53_1)
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

  switch (pivot_53_2)
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
  int accumulator_30_1 = local_arr_1[aux_1 % 3];
  int accumulator_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_30_2 * 2)) & 127;
  int factor_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_87_1) & 63;
  aux_2 = (aux_2 + factor_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_53_1 == pivot_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_30_1 == accumulator_30_2);
  assert(factor_87_1 == factor_87_2);
}

int fn_R001603_313_3(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int pivot_53 = (aux + st.buffer[1]) & 3;
  switch (pivot_53)
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
  int accumulator_30 = local_arr[aux % 3];
  acc = (acc + (accumulator_30 * 2)) & 127;
  int factor_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_87) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001603_313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st_1 = {0};
  struct Vector3D_R001603_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int offset_28_1 = 0;
  int offset_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_28_1 = ((offset_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_28_2 = ((offset_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_28_1) & 127;
    acc_2 = (acc_2 + offset_28_2) & 127;
  }

  int damping_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_42_1)
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

  switch (damping_42_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_28_1 == offset_28_2);
  assert(damping_42_1 == damping_42_2);
}

int fn_R001603_313_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int offset_28 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_28 = ((offset_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_28) & 127;
  }

  int damping_42 = (aux + st.buffer[1]) & 3;
  switch (damping_42)
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

void fn_R001603_313_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001603_313_2 st_1 = {0};
  struct MatrixBlock_R001603_313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_42_1) & 63;
  aux_2 = (aux_2 + tracker_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_74_1 = local_arr_1[aux_1 % 3];
  int threshold_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_42_1 == tracker_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_74_1 == threshold_74_2);
}

int fn_R001603_313_5(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001603_313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_42) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_74 = local_arr[aux % 3];
  acc = (acc + (threshold_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001603_313_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st_1 = {0};
  struct Transaction_R001603_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int phase_84_1 = 0;
  int phase_84_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_84_1 = ((phase_84_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_84_2 = ((phase_84_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_84_1) & 127;
    acc_2 = (acc_2 + phase_84_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_79_1)
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

  switch (segment_79_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_84_1 == phase_84_2);
  assert(segment_79_1 == segment_79_2);
}

int fn_R001603_313_6(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int phase_84 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_84 = ((phase_84 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_84) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_79 = (aux + st.buffer[1]) & 3;
  switch (segment_79)
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

void fn_R001603_313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001603_313_2 st_1 = {0};
  struct MatrixBlock_R001603_313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_71_1 = 0;
  int quotient_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_71_1 = ((quotient_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_71_2 = ((quotient_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_71_1) & 127;
    acc_2 = (acc_2 + quotient_71_2) & 127;
  }

  int checksum_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_12_1)
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

  switch (checksum_12_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_71_1 == quotient_71_2);
  assert(checksum_12_1 == checksum_12_2);
}

int fn_R001603_313_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001603_313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_71 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_71 = ((quotient_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_71) & 127;
  }

  int checksum_12 = (aux + st.buffer[1]) & 3;
  switch (checksum_12)
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

void fn_R001603_313_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001603_313_2 st_1 = {0};
  struct MatrixBlock_R001603_313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int coefficient_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_35_1 > 40)
  {
    acc_1 = ((acc_1 + (coefficient_35_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_35_2 > 40)
  {
    acc_2 = ((acc_2 + (coefficient_35_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_57_1)
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

  switch (bound_57_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_35_1 == coefficient_35_2);
  assert(bound_57_1 == bound_57_2);
}

int fn_R001603_313_8(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001603_313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int coefficient_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_35 > 40)
  {
    acc = ((acc + (coefficient_35 * 2)) + 5) & 127;
    aux ^= coefficient_35 & 15;
  }
  else
  {
    acc = ((acc - coefficient_35) + 11) & 127;
    aux += 3;
  }
  int bound_57 = (aux + st.buffer[1]) & 3;
  switch (bound_57)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001603_313_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st_1 = {0};
  struct Transaction_R001603_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int damping_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_99_1) & 63;
  aux_2 = (aux_2 + damping_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_46_1 = 0;
  int checksum_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_46_1 = ((checksum_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_46_2 = ((checksum_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_46_1) & 127;
    acc_2 = (acc_2 + checksum_46_2) & 127;
  }

  int bound_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_33_1)
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

  switch (bound_33_2)
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
  int metric_98_1 = local_arr_1[aux_1 % 3];
  int metric_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_98_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_99_1 == damping_99_2);
  assert(checksum_46_1 == checksum_46_2);
  assert(bound_33_1 == bound_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_98_1 == metric_98_2);
}

int fn_R001603_313_9(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int damping_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_99) & 63;
  acc ^= aux;
  int checksum_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_46 = ((checksum_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_46) & 127;
  }

  int bound_33 = (aux + st.buffer[1]) & 3;
  switch (bound_33)
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
  int metric_98 = local_arr[aux % 3];
  acc = (acc + (metric_98 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001603_313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st_1 = {0};
  struct Vector3D_R001603_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int coefficient_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_61_1) & 63;
  aux_2 = (aux_2 + coefficient_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_71_1 = local_arr_1[aux_1 % 3];
  int margin_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_61_1 == coefficient_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_71_1 == margin_71_2);
}

int fn_R001603_313_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int coefficient_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_61) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_71 = local_arr[aux % 3];
  acc = (acc + (margin_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001603_313_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001603_313_2 st_1 = {0};
  struct MatrixBlock_R001603_313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_84_1)
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

  switch (pivot_84_2)
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
  int damping_22_1 = local_arr_1[aux_1 % 3];
  int damping_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_22_2 * 2)) & 127;
  int accumulator_11_1 = 0;
  int accumulator_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_11_1 = ((accumulator_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_11_2 = ((accumulator_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_11_1) & 127;
    acc_2 = (acc_2 + accumulator_11_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_84_1 == pivot_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_22_1 == damping_22_2);
  assert(accumulator_11_1 == accumulator_11_2);
}

int fn_R001603_313_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001603_313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_84 = (aux + st.buffer[1]) & 3;
  switch (pivot_84)
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
  int damping_22 = local_arr[aux % 3];
  acc = (acc + (damping_22 * 2)) & 127;
  int accumulator_11 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_11 = ((accumulator_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_11) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001603_313_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st_1 = {0};
  struct Transaction_R001603_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int residue_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_50_1) & 63;
  aux_2 = (aux_2 + residue_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_79_1)
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

  switch (checksum_79_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_50_1 == residue_50_2);
  assert(checksum_79_1 == checksum_79_2);
}

int fn_R001603_313_12(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int residue_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_50) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_79 = (aux + st.buffer[1]) & 3;
  switch (checksum_79)
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

void fn_R001603_313_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001603_313_2 st_1 = {0};
  struct MatrixBlock_R001603_313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_34_1 = local_arr_1[aux_1 % 3];
  int pivot_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_34_2 * 2)) & 127;
  int coefficient_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_93_1 > 26)
  {
    acc_1 = ((acc_1 + (coefficient_93_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_93_2 > 26)
  {
    acc_2 = ((acc_2 + (coefficient_93_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
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

  assert(pivot_34_1 == pivot_34_2);
  assert(coefficient_93_1 == coefficient_93_2);
}

int fn_R001603_313_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001603_313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int pivot_34 = local_arr[aux % 3];
  acc = (acc + (pivot_34 * 2)) & 127;
  int coefficient_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_93 > 26)
  {
    acc = ((acc + (coefficient_93 * 2)) + 5) & 127;
    aux ^= coefficient_93 & 15;
  }
  else
  {
    acc = ((acc - coefficient_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001603_313_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st_1 = {0};
  struct Vector3D_R001603_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int stride_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_39_1)
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

  switch (stride_39_2)
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

  int tracker_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_68_1) & 63;
  aux_2 = (aux_2 + tracker_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_61_1 = local_arr_1[aux_1 % 3];
  int scale_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_39_1 == stride_39_2);
  assert(tracker_68_1 == tracker_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_61_1 == scale_61_2);
}

int fn_R001603_313_14(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int stride_39 = (aux + st.buffer[1]) & 3;
  switch (stride_39)
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

  int tracker_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_68) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_61 = local_arr[aux % 3];
  acc = (acc + (scale_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001603_313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st_1 = {0};
  struct Transaction_R001603_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_38_1 = local_arr_1[aux_1 % 3];
  int quantum_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_38_2 * 2)) & 127;
  int cursor_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_49_1 > 41)
  {
    acc_1 = ((acc_1 + (cursor_49_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_49_2 > 41)
  {
    acc_2 = ((acc_2 + (cursor_49_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_49_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_78_1)
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

  switch (segment_78_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_38_1 == quantum_38_2);
  assert(cursor_49_1 == cursor_49_2);
  assert(segment_78_1 == segment_78_2);
}

int fn_R001603_313_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int quantum_38 = local_arr[aux % 3];
  acc = (acc + (quantum_38 * 2)) & 127;
  int cursor_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_49 > 41)
  {
    acc = ((acc + (cursor_49 * 2)) + 5) & 127;
    aux ^= cursor_49 & 15;
  }
  else
  {
    acc = ((acc - cursor_49) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_78 = (aux + st.buffer[1]) & 3;
  switch (segment_78)
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

void fn_R001603_313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st_1 = {0};
  struct Transaction_R001603_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int bound_33_1 = 0;
  int bound_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_33_1 = ((bound_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_33_2 = ((bound_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_33_1) & 127;
    acc_2 = (acc_2 + bound_33_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_41_1 = local_arr_1[aux_1 % 3];
  int scale_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_41_2 * 2)) & 127;
  int scale_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_46_1)
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

  switch (scale_46_2)
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

  int residue_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_64_1 > 34)
  {
    acc_1 = ((acc_1 + (residue_64_1 * 2)) + 5) & 127;
    aux_1 ^= residue_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_64_2 > 34)
  {
    acc_2 = ((acc_2 + (residue_64_2 * 2)) + 5) & 127;
    aux_2 ^= residue_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_33_1 == bound_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_41_1 == scale_41_2);
  assert(scale_46_1 == scale_46_2);
  assert(residue_64_1 == residue_64_2);
}

int fn_R001603_313_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int bound_33 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_33 = ((bound_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_33) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int scale_41 = local_arr[aux % 3];
  acc = (acc + (scale_41 * 2)) & 127;
  int scale_46 = (aux + st.buffer[1]) & 3;
  switch (scale_46)
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

  int residue_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_64 > 34)
  {
    acc = ((acc + (residue_64 * 2)) + 5) & 127;
    aux ^= residue_64 & 15;
  }
  else
  {
    acc = ((acc - residue_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001603_313_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st_1 = {0};
  struct Vector3D_R001603_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int vector_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_13_1)
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

  switch (vector_13_2)
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
  int window_29_1 = local_arr_1[aux_1 % 3];
  int window_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_29_2 * 2)) & 127;
  int factor_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_46_1 > 45)
  {
    acc_1 = ((acc_1 + (factor_46_1 * 2)) + 5) & 127;
    aux_1 ^= factor_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_46_2 > 45)
  {
    acc_2 = ((acc_2 + (factor_46_2 * 2)) + 5) & 127;
    aux_2 ^= factor_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_13_1 == vector_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_29_1 == window_29_2);
  assert(factor_46_1 == factor_46_2);
}

int fn_R001603_313_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int vector_13 = (aux + st.buffer[1]) & 3;
  switch (vector_13)
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
  int window_29 = local_arr[aux % 3];
  acc = (acc + (window_29 * 2)) & 127;
  int factor_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_46 > 45)
  {
    acc = ((acc + (factor_46 * 2)) + 5) & 127;
    aux ^= factor_46 & 15;
  }
  else
  {
    acc = ((acc - factor_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001603_313_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st_1 = {0};
  struct Transaction_R001603_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int pivot_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_82_1 > 31)
  {
    acc_1 = ((acc_1 + (pivot_82_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_82_2 > 31)
  {
    acc_2 = ((acc_2 + (pivot_82_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_87_1) & 63;
  aux_2 = (aux_2 + anchor_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_82_1 == pivot_82_2);
  assert(anchor_87_1 == anchor_87_2);
}

int fn_R001603_313_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001603_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int pivot_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_82 > 31)
  {
    acc = ((acc + (pivot_82 * 2)) + 5) & 127;
    aux ^= pivot_82 & 15;
  }
  else
  {
    acc = ((acc - pivot_82) + 11) & 127;
    aux += 3;
  }
  int anchor_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_87) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001603_313_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st_1 = {0};
  struct Vector3D_R001603_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int bound_54_1 = 0;
  int bound_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_54_1 = ((bound_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_54_2 = ((bound_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_54_1) & 127;
    acc_2 = (acc_2 + bound_54_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_54_1 == bound_54_2);
}

int fn_R001603_313_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int bound_54 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_54 = ((bound_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_54) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001603_313_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st_1 = {0};
  struct Vector3D_R001603_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int residue_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_63_1)
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

  switch (residue_63_2)
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
  int scale_53_1 = local_arr_1[aux_1 % 3];
  int scale_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_53_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_68_1) & 63;
  aux_2 = (aux_2 + checksum_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_63_1 == residue_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_53_1 == scale_53_2);
  assert(checksum_68_1 == checksum_68_2);
}

int fn_R001603_313_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int residue_63 = (aux + st.buffer[1]) & 3;
  switch (residue_63)
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
  int scale_53 = local_arr[aux % 3];
  acc = (acc + (scale_53 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001603_313_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st_1 = {0};
  struct Vector3D_R001603_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_39_1)
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

  switch (delta_39_2)
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

  int vector_62_1 = 0;
  int vector_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_62_1 = ((vector_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_62_2 = ((vector_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_62_1) & 127;
    acc_2 = (acc_2 + vector_62_2) & 127;
  }

  int margin_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_68_1) & 63;
  aux_2 = (aux_2 + margin_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_39_1 == delta_39_2);
  assert(vector_62_1 == vector_62_2);
  assert(margin_68_1 == margin_68_2);
}

int fn_R001603_313_21(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001603_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_39 = (aux + st.buffer[1]) & 3;
  switch (delta_39)
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

  int vector_62 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_62 = ((vector_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_62) & 127;
  }

  int margin_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001603_0_1;
  int sec_r001603_0_2;
  int sec_r001603_1_1;
  int sec_r001603_1_2;
  int sec_r001603_2_1;
  int sec_r001603_2_2;
  int sec_r001603_3_1;
  int sec_r001603_3_2;
  int sec_r001603_4_1;
  int sec_r001603_4_2;
  int sec_r001603_5_1;
  int sec_r001603_5_2;
  int sec_r001603_6_1;
  int sec_r001603_6_2;
  int sec_r001603_7_1;
  int sec_r001603_7_2;
  int sec_r001603_8_1;
  int sec_r001603_8_2;
  int sec_r001603_9_1;
  int sec_r001603_9_2;
  int sec_r001603_10_1;
  int sec_r001603_10_2;
  int sec_r001603_11_1;
  int sec_r001603_11_2;
  int sec_r001603_12_1;
  int sec_r001603_12_2;
  int sec_r001603_13_1;
  int sec_r001603_13_2;
  int sec_r001603_14_1;
  int sec_r001603_14_2;
  int sec_r001603_15_1;
  int sec_r001603_15_2;
  int sec_r001603_16_1;
  int sec_r001603_16_2;
  int sec_r001603_17_1;
  int sec_r001603_17_2;
  int sec_r001603_18_1;
  int sec_r001603_18_2;
  int sec_r001603_19_1;
  int sec_r001603_19_2;
  int sec_r001603_20_1;
  int sec_r001603_20_2;
  int pub_r001603_0_1;
  int pub_r001603_0_2;
  int pub_r001603_1_1;
  int pub_r001603_1_2;
  int pub_r001603_2_1;
  int pub_r001603_2_2;
  int pub_r001603_3_1;
  int pub_r001603_3_2;
  int pub_r001603_4_1;
  int pub_r001603_4_2;
  int pub_r001603_5_1;
  int pub_r001603_5_2;
  int pub_r001603_6_1;
  int pub_r001603_6_2;
  int pub_r001603_7_1;
  int pub_r001603_7_2;
  int pub_r001603_8_1;
  int pub_r001603_8_2;
  int pub_r001603_9_1;
  int pub_r001603_9_2;
  int pub_r001603_10_1;
  int pub_r001603_10_2;
  int pub_r001603_11_1;
  int pub_r001603_11_2;
  int pub_r001603_12_1;
  int pub_r001603_12_2;
  int pub_r001603_13_1;
  int pub_r001603_13_2;
  int pub_r001603_14_1;
  int pub_r001603_14_2;
  int pub_r001603_15_1;
  int pub_r001603_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001603_0_1 >= (-100)) && (pub_r001603_0_1 <= 100));
  __CPROVER_assume((pub_r001603_0_2 >= (-100)) && (pub_r001603_0_2 <= 100));
  __CPROVER_assume((pub_r001603_1_1 >= (-100)) && (pub_r001603_1_1 <= 100));
  __CPROVER_assume((pub_r001603_1_2 >= (-100)) && (pub_r001603_1_2 <= 100));
  __CPROVER_assume((pub_r001603_2_1 >= (-100)) && (pub_r001603_2_1 <= 100));
  __CPROVER_assume((pub_r001603_2_2 >= (-100)) && (pub_r001603_2_2 <= 100));
  __CPROVER_assume((pub_r001603_3_1 >= (-100)) && (pub_r001603_3_1 <= 100));
  __CPROVER_assume((pub_r001603_3_2 >= (-100)) && (pub_r001603_3_2 <= 100));
  __CPROVER_assume((pub_r001603_4_1 >= (-100)) && (pub_r001603_4_1 <= 100));
  __CPROVER_assume((pub_r001603_4_2 >= (-100)) && (pub_r001603_4_2 <= 100));
  __CPROVER_assume((pub_r001603_5_1 >= (-100)) && (pub_r001603_5_1 <= 100));
  __CPROVER_assume((pub_r001603_5_2 >= (-100)) && (pub_r001603_5_2 <= 100));
  __CPROVER_assume((pub_r001603_6_1 >= (-100)) && (pub_r001603_6_1 <= 100));
  __CPROVER_assume((pub_r001603_6_2 >= (-100)) && (pub_r001603_6_2 <= 100));
  __CPROVER_assume((pub_r001603_7_1 >= (-100)) && (pub_r001603_7_1 <= 100));
  __CPROVER_assume((pub_r001603_7_2 >= (-100)) && (pub_r001603_7_2 <= 100));
  __CPROVER_assume((pub_r001603_8_1 >= (-100)) && (pub_r001603_8_1 <= 100));
  __CPROVER_assume((pub_r001603_8_2 >= (-100)) && (pub_r001603_8_2 <= 100));
  __CPROVER_assume((pub_r001603_9_1 >= (-100)) && (pub_r001603_9_1 <= 100));
  __CPROVER_assume((pub_r001603_9_2 >= (-100)) && (pub_r001603_9_2 <= 100));
  __CPROVER_assume((pub_r001603_10_1 >= (-100)) && (pub_r001603_10_1 <= 100));
  __CPROVER_assume((pub_r001603_10_2 >= (-100)) && (pub_r001603_10_2 <= 100));
  __CPROVER_assume((pub_r001603_11_1 >= (-100)) && (pub_r001603_11_1 <= 100));
  __CPROVER_assume((pub_r001603_11_2 >= (-100)) && (pub_r001603_11_2 <= 100));
  __CPROVER_assume((pub_r001603_12_1 >= (-100)) && (pub_r001603_12_1 <= 100));
  __CPROVER_assume((pub_r001603_12_2 >= (-100)) && (pub_r001603_12_2 <= 100));
  __CPROVER_assume((pub_r001603_13_1 >= (-100)) && (pub_r001603_13_1 <= 100));
  __CPROVER_assume((pub_r001603_13_2 >= (-100)) && (pub_r001603_13_2 <= 100));
  __CPROVER_assume((pub_r001603_14_1 >= (-100)) && (pub_r001603_14_1 <= 100));
  __CPROVER_assume((pub_r001603_14_2 >= (-100)) && (pub_r001603_14_2 <= 100));
  __CPROVER_assume((pub_r001603_15_1 >= (-100)) && (pub_r001603_15_1 <= 100));
  __CPROVER_assume((pub_r001603_15_2 >= (-100)) && (pub_r001603_15_2 <= 100));
  __CPROVER_assume((sec_r001603_0_1 >= 0) && (sec_r001603_0_1 <= 255));
  __CPROVER_assume((sec_r001603_0_2 >= 0) && (sec_r001603_0_2 <= 255));
  __CPROVER_assume((sec_r001603_1_1 >= 0) && (sec_r001603_1_1 <= 255));
  __CPROVER_assume((sec_r001603_1_2 >= 0) && (sec_r001603_1_2 <= 255));
  __CPROVER_assume((sec_r001603_2_1 >= 0) && (sec_r001603_2_1 <= 255));
  __CPROVER_assume((sec_r001603_2_2 >= 0) && (sec_r001603_2_2 <= 255));
  __CPROVER_assume((sec_r001603_3_1 >= 0) && (sec_r001603_3_1 <= 255));
  __CPROVER_assume((sec_r001603_3_2 >= 0) && (sec_r001603_3_2 <= 255));
  __CPROVER_assume((sec_r001603_4_1 >= 0) && (sec_r001603_4_1 <= 255));
  __CPROVER_assume((sec_r001603_4_2 >= 0) && (sec_r001603_4_2 <= 255));
  __CPROVER_assume((sec_r001603_5_1 >= 0) && (sec_r001603_5_1 <= 255));
  __CPROVER_assume((sec_r001603_5_2 >= 0) && (sec_r001603_5_2 <= 255));
  __CPROVER_assume((sec_r001603_6_1 >= 0) && (sec_r001603_6_1 <= 255));
  __CPROVER_assume((sec_r001603_6_2 >= 0) && (sec_r001603_6_2 <= 255));
  __CPROVER_assume((sec_r001603_7_1 >= 0) && (sec_r001603_7_1 <= 255));
  __CPROVER_assume((sec_r001603_7_2 >= 0) && (sec_r001603_7_2 <= 255));
  __CPROVER_assume((sec_r001603_8_1 >= 0) && (sec_r001603_8_1 <= 255));
  __CPROVER_assume((sec_r001603_8_2 >= 0) && (sec_r001603_8_2 <= 255));
  __CPROVER_assume((sec_r001603_9_1 >= 0) && (sec_r001603_9_1 <= 255));
  __CPROVER_assume((sec_r001603_9_2 >= 0) && (sec_r001603_9_2 <= 255));
  __CPROVER_assume((sec_r001603_10_1 >= 0) && (sec_r001603_10_1 <= 255));
  __CPROVER_assume((sec_r001603_10_2 >= 0) && (sec_r001603_10_2 <= 255));
  __CPROVER_assume((sec_r001603_11_1 >= 0) && (sec_r001603_11_1 <= 255));
  __CPROVER_assume((sec_r001603_11_2 >= 0) && (sec_r001603_11_2 <= 255));
  __CPROVER_assume((sec_r001603_12_1 >= 0) && (sec_r001603_12_1 <= 255));
  __CPROVER_assume((sec_r001603_12_2 >= 0) && (sec_r001603_12_2 <= 255));
  __CPROVER_assume((sec_r001603_13_1 >= 0) && (sec_r001603_13_1 <= 255));
  __CPROVER_assume((sec_r001603_13_2 >= 0) && (sec_r001603_13_2 <= 255));
  __CPROVER_assume((sec_r001603_14_1 >= 0) && (sec_r001603_14_1 <= 255));
  __CPROVER_assume((sec_r001603_14_2 >= 0) && (sec_r001603_14_2 <= 255));
  __CPROVER_assume((sec_r001603_15_1 >= 0) && (sec_r001603_15_1 <= 255));
  __CPROVER_assume((sec_r001603_15_2 >= 0) && (sec_r001603_15_2 <= 255));
  __CPROVER_assume((sec_r001603_16_1 >= 0) && (sec_r001603_16_1 <= 255));
  __CPROVER_assume((sec_r001603_16_2 >= 0) && (sec_r001603_16_2 <= 255));
  __CPROVER_assume((sec_r001603_17_1 >= 0) && (sec_r001603_17_1 <= 255));
  __CPROVER_assume((sec_r001603_17_2 >= 0) && (sec_r001603_17_2 <= 255));
  __CPROVER_assume((sec_r001603_18_1 >= 0) && (sec_r001603_18_1 <= 255));
  __CPROVER_assume((sec_r001603_18_2 >= 0) && (sec_r001603_18_2 <= 255));
  __CPROVER_assume((sec_r001603_19_1 >= 0) && (sec_r001603_19_1 <= 255));
  __CPROVER_assume((sec_r001603_19_2 >= 0) && (sec_r001603_19_2 <= 255));
  __CPROVER_assume((sec_r001603_20_1 >= 0) && (sec_r001603_20_1 <= 255));
  __CPROVER_assume((sec_r001603_20_2 >= 0) && (sec_r001603_20_2 <= 255));
  struct Transaction_R001603_313_0 st_var_0_1 = {0};
  struct Transaction_R001603_313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001603_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001603_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001603_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001603_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001603_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001603_0_2 + 7) & 15;
  struct Vector3D_R001603_313_1 st_var_1_1 = {0};
  struct Vector3D_R001603_313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001603_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001603_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001603_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001603_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001603_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001603_0_2 + 9) & 15;
  struct MatrixBlock_R001603_313_2 st_var_2_1 = {0};
  struct MatrixBlock_R001603_313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001603_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001603_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001603_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001603_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001603_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001603_0_2 + 11) & 15;
  union RegisterBank_R001603_313_0 u_var_1;
  union RegisterBank_R001603_313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001603_313_0(sec_r001603_0_1, pub_r001603_1_1, pub_r001603_2_1);
  int helper_flow_0_2 = fn_R001603_313_0(sec_r001603_0_2, pub_r001603_1_2, pub_r001603_2_2);
  fn_R001603_313_0_2(sec_r001603_0_1, pub_r001603_1_1, pub_r001603_2_1, sec_r001603_0_2, pub_r001603_1_2, pub_r001603_2_2);
  int helper_flow_1_1 = fn_R001603_313_1(sec_r001603_1_1, pub_r001603_2_1, pub_r001603_3_1, pub_r001603_4_1, pub_r001603_5_1);
  int helper_flow_1_2 = fn_R001603_313_1(sec_r001603_1_2, pub_r001603_2_2, pub_r001603_3_2, pub_r001603_4_2, pub_r001603_5_2);
  fn_R001603_313_1_2(sec_r001603_1_1, pub_r001603_2_1, pub_r001603_3_1, pub_r001603_4_1, pub_r001603_5_1, sec_r001603_1_2, pub_r001603_2_2, pub_r001603_3_2, pub_r001603_4_2, pub_r001603_5_2);
  int helper_flow_2_1 = fn_R001603_313_2(sec_r001603_2_1, pub_r001603_3_1, pub_r001603_4_1, pub_r001603_5_1, pub_r001603_6_1);
  int helper_flow_2_2 = fn_R001603_313_2(sec_r001603_2_2, pub_r001603_3_2, pub_r001603_4_2, pub_r001603_5_2, pub_r001603_6_2);
  fn_R001603_313_2_2(sec_r001603_2_1, pub_r001603_3_1, pub_r001603_4_1, pub_r001603_5_1, pub_r001603_6_1, sec_r001603_2_2, pub_r001603_3_2, pub_r001603_4_2, pub_r001603_5_2, pub_r001603_6_2);
  int helper_flow_3_1 = fn_R001603_313_3(sec_r001603_3_1, pub_r001603_4_1);
  int helper_flow_3_2 = fn_R001603_313_3(sec_r001603_3_2, pub_r001603_4_2);
  fn_R001603_313_3_2(sec_r001603_3_1, pub_r001603_4_1, sec_r001603_3_2, pub_r001603_4_2);
  int helper_flow_4_1 = fn_R001603_313_4(sec_r001603_4_1, sec_r001603_5_1, pub_r001603_6_1, pub_r001603_7_1, pub_r001603_8_1);
  int helper_flow_4_2 = fn_R001603_313_4(sec_r001603_4_2, sec_r001603_5_2, pub_r001603_6_2, pub_r001603_7_2, pub_r001603_8_2);
  fn_R001603_313_4_2(sec_r001603_4_1, sec_r001603_5_1, pub_r001603_6_1, pub_r001603_7_1, pub_r001603_8_1, sec_r001603_4_2, sec_r001603_5_2, pub_r001603_6_2, pub_r001603_7_2, pub_r001603_8_2);
  int stage_v_0_1 = (((sec_r001603_17_1 * 3) + pub_r001603_8_1) + 20) & 127;
  int stage_v_0_2 = (((sec_r001603_17_2 * 3) + pub_r001603_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = (((sec_r001603_18_1 * 3) + pub_r001603_15_1) + 6) & 127;
  int stage_v_1_2 = (((sec_r001603_18_2 * 3) + pub_r001603_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = (((sec_r001603_13_1 * 3) + pub_r001603_13_1) + 20) & 127;
  int stage_v_2_2 = (((sec_r001603_13_2 * 3) + pub_r001603_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = ((pub_r001603_10_1 * 2) + 34) & 63;
  int stage_v_3_2 = ((pub_r001603_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001603_12_1 * 2) + 16) & 63;
  int stage_v_4_2 = ((pub_r001603_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((helper_flow_1_1 * 3) + pub_r001603_14_1) + 44) & 127;
  int stage_v_5_2 = (((helper_flow_1_2 * 3) + pub_r001603_14_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = ((pub_r001603_10_1 * 2) + 11) & 63;
  int stage_v_6_2 = ((pub_r001603_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001603_14_1 * 2) + 21) & 63;
  int stage_v_7_2 = ((pub_r001603_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001603_4_1 * 3) + pub_r001603_8_1) + 7) & 127;
  int stage_v_8_2 = (((sec_r001603_4_2 * 3) + pub_r001603_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = (((sec_r001603_17_1 * 3) + pub_r001603_5_1) + 26) & 127;
  int stage_v_9_2 = (((sec_r001603_17_2 * 3) + pub_r001603_5_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = (((sec_r001603_5_1 * 3) + pub_r001603_4_1) + 39) & 127;
  int stage_v_10_2 = (((sec_r001603_5_2 * 3) + pub_r001603_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001603_14_1 * 2) + 49) & 63;
  int stage_v_11_2 = ((pub_r001603_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001603_8_1 * 2) + 48) & 63;
  int stage_v_12_2 = ((pub_r001603_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001603_0_1 * 2) + 5) & 63;
  int stage_v_13_2 = ((pub_r001603_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((sec_r001603_14_1 * 3) + pub_r001603_6_1) + 4) & 127;
  int stage_v_14_2 = (((sec_r001603_14_2 * 3) + pub_r001603_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((sec_r001603_0_1 * 3) + pub_r001603_13_1) + 35) & 127;
  int stage_v_15_2 = (((sec_r001603_0_2 * 3) + pub_r001603_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001603_1_1 * 2) + 40) & 63;
  int stage_v_16_2 = ((pub_r001603_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001603_5_1 * 2) + 46) & 63;
  int stage_v_17_2 = ((pub_r001603_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (((helper_flow_3_1 * 3) + pub_r001603_6_1) + 26) & 127;
  int stage_v_18_2 = (((helper_flow_3_2 * 3) + pub_r001603_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = ((pub_r001603_14_1 * 2) + 34) & 63;
  int stage_v_19_2 = ((pub_r001603_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001603_10_1 * 2) + 11) & 63;
  int stage_v_20_2 = ((pub_r001603_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((sec_r001603_20_1 * 3) + pub_r001603_6_1) + 44) & 127;
  int stage_v_21_2 = (((sec_r001603_20_2 * 3) + pub_r001603_6_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = ((pub_r001603_12_1 * 2) + 42) & 63;
  int stage_v_22_2 = ((pub_r001603_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((helper_flow_1_1 * 3) + pub_r001603_9_1) + 6) & 127;
  int stage_v_23_2 = (((helper_flow_1_2 * 3) + pub_r001603_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((sec_r001603_9_1 * 3) + pub_r001603_0_1) + 6) & 127;
  int stage_v_24_2 = (((sec_r001603_9_2 * 3) + pub_r001603_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((sec_r001603_3_1 * 3) + pub_r001603_4_1) + 28) & 127;
  int stage_v_25_2 = (((sec_r001603_3_2 * 3) + pub_r001603_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((helper_flow_4_1 * 3) + pub_r001603_10_1) + 36) & 127;
  int stage_v_26_2 = (((helper_flow_4_2 * 3) + pub_r001603_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = ((pub_r001603_10_1 * 2) + 24) & 63;
  int stage_v_27_2 = ((pub_r001603_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((sec_r001603_17_1 * 3) + pub_r001603_1_1) + 41) & 127;
  int stage_v_28_2 = (((sec_r001603_17_2 * 3) + pub_r001603_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = ((pub_r001603_6_1 * 2) + 22) & 63;
  int stage_v_29_2 = ((pub_r001603_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((sec_r001603_13_1 * 3) + pub_r001603_2_1) + 37) & 127;
  int stage_v_30_2 = (((sec_r001603_13_2 * 3) + pub_r001603_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((stage_v_18_1 * 3) + pub_r001603_3_1) + 14) & 127;
  int stage_v_31_2 = (((stage_v_18_2 * 3) + pub_r001603_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = ((pub_r001603_11_1 * 2) + 33) & 63;
  int stage_v_32_2 = ((pub_r001603_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((stage_v_10_1 * 3) + pub_r001603_0_1) + 11) & 127;
  int stage_v_33_2 = (((stage_v_10_2 * 3) + pub_r001603_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((sec_r001603_3_1 * 3) + pub_r001603_4_1) + 12) & 127;
  int stage_v_34_2 = (((sec_r001603_3_2 * 3) + pub_r001603_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = (((sec_r001603_0_1 * 3) + pub_r001603_4_1) + 36) & 127;
  int stage_v_35_2 = (((sec_r001603_0_2 * 3) + pub_r001603_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = (((stage_v_25_1 * 3) + pub_r001603_7_1) + 7) & 127;
  int stage_v_36_2 = (((stage_v_25_2 * 3) + pub_r001603_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = ((pub_r001603_7_1 * 2) + 35) & 63;
  int stage_v_37_2 = ((pub_r001603_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((stage_v_2_1 * 3) + pub_r001603_12_1) + 3) & 127;
  int stage_v_38_2 = (((stage_v_2_2 * 3) + pub_r001603_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = ((pub_r001603_1_1 * 2) + 40) & 63;
  int stage_v_39_2 = ((pub_r001603_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001603_4_1 * 2) + 22) & 63;
  int stage_v_40_2 = ((pub_r001603_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((helper_flow_0_1 * 3) + pub_r001603_1_1) + 36) & 127;
  int stage_v_41_2 = (((helper_flow_0_2 * 3) + pub_r001603_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = (((stage_v_34_1 * 3) + pub_r001603_0_1) + 37) & 127;
  int stage_v_42_2 = (((stage_v_34_2 * 3) + pub_r001603_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = (((stage_v_15_1 * 3) + pub_r001603_9_1) + 30) & 127;
  int stage_v_43_2 = (((stage_v_15_2 * 3) + pub_r001603_9_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001603_15_1 * 2) + 25) & 63;
  int stage_v_44_2 = ((pub_r001603_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((stage_v_26_1 * 3) + pub_r001603_2_1) + 33) & 127;
  int stage_v_45_2 = (((stage_v_26_2 * 3) + pub_r001603_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((helper_flow_3_1 * 3) + pub_r001603_10_1) + 4) & 127;
  int stage_v_46_2 = (((helper_flow_3_2 * 3) + pub_r001603_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001603_5_1 * 2) + 33) & 63;
  int stage_v_47_2 = ((pub_r001603_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001603_15_1 * 2) + 15) & 63;
  int stage_v_48_2 = ((pub_r001603_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((stage_v_8_1 * 3) + pub_r001603_4_1) + 30) & 127;
  int stage_v_49_2 = (((stage_v_8_2 * 3) + pub_r001603_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((sec_r001603_14_1 * 3) + pub_r001603_4_1) + 3) & 127;
  int stage_v_50_2 = (((sec_r001603_14_2 * 3) + pub_r001603_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = (((sec_r001603_9_1 * 3) + pub_r001603_0_1) + 27) & 127;
  int stage_v_51_2 = (((sec_r001603_9_2 * 3) + pub_r001603_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = (((sec_r001603_3_1 * 3) + pub_r001603_2_1) + 26) & 127;
  int stage_v_52_2 = (((sec_r001603_3_2 * 3) + pub_r001603_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001603_15_1 * 2) + 30) & 63;
  int stage_v_53_2 = ((pub_r001603_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((sec_r001603_17_1 * 3) + pub_r001603_15_1) + 27) & 127;
  int stage_v_54_2 = (((sec_r001603_17_2 * 3) + pub_r001603_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = ((pub_r001603_8_1 * 2) + 20) & 63;
  int stage_v_55_2 = ((pub_r001603_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((sec_r001603_14_1 * 3) + pub_r001603_1_1) + 24) & 127;
  int stage_v_56_2 = (((sec_r001603_14_2 * 3) + pub_r001603_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((stage_v_34_1 * 3) + pub_r001603_1_1) + 36) & 127;
  int stage_v_57_2 = (((stage_v_34_2 * 3) + pub_r001603_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((helper_flow_4_1 * 3) + pub_r001603_3_1) + 13) & 127;
  int stage_v_58_2 = (((helper_flow_4_2 * 3) + pub_r001603_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = ((pub_r001603_14_1 * 2) + 38) & 63;
  int stage_v_59_2 = ((pub_r001603_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((helper_flow_1_1 * 3) + pub_r001603_10_1) + 15) & 127;
  int stage_v_60_2 = (((helper_flow_1_2 * 3) + pub_r001603_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = ((pub_r001603_5_1 * 2) + 47) & 63;
  int stage_v_61_2 = ((pub_r001603_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001603_11_1 * 2) + 42) & 63;
  int stage_v_62_2 = ((pub_r001603_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((stage_v_60_1 * 3) + pub_r001603_2_1) + 11) & 127;
  int stage_v_63_2 = (((stage_v_60_2 * 3) + pub_r001603_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((stage_v_10_1 * 3) + pub_r001603_2_1) + 14) & 127;
  int stage_v_64_2 = (((stage_v_10_2 * 3) + pub_r001603_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = ((pub_r001603_8_1 * 2) + 21) & 63;
  int stage_v_65_2 = ((pub_r001603_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((stage_v_21_1 * 3) + pub_r001603_0_1) + 9) & 127;
  int stage_v_66_2 = (((stage_v_21_2 * 3) + pub_r001603_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((stage_v_23_1 * 3) + pub_r001603_1_1) + 36) & 127;
  int stage_v_67_2 = (((stage_v_23_2 * 3) + pub_r001603_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((stage_v_42_1 * 3) + pub_r001603_10_1) + 18) & 127;
  int stage_v_68_2 = (((stage_v_42_2 * 3) + pub_r001603_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = (((stage_v_36_1 * 3) + pub_r001603_3_1) + 41) & 127;
  int stage_v_69_2 = (((stage_v_36_2 * 3) + pub_r001603_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = (((stage_v_56_1 * 3) + pub_r001603_5_1) + 23) & 127;
  int stage_v_70_2 = (((stage_v_56_2 * 3) + pub_r001603_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = (((helper_flow_2_1 * 3) + pub_r001603_11_1) + 23) & 127;
  int stage_v_71_2 = (((helper_flow_2_2 * 3) + pub_r001603_11_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = (((stage_v_25_1 * 3) + pub_r001603_3_1) + 29) & 127;
  int stage_v_72_2 = (((stage_v_25_2 * 3) + pub_r001603_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001603_0_1 * 2) + 45) & 63;
  int stage_v_73_2 = ((pub_r001603_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001603_3_1 * 2) + 22) & 63;
  int stage_v_74_2 = ((pub_r001603_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001603_8_1 * 2) + 8) & 63;
  int stage_v_75_2 = ((pub_r001603_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001603_11_1 * 2) + 24) & 63;
  int stage_v_76_2 = ((pub_r001603_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((stage_v_35_1 * 3) + pub_r001603_3_1) + 38) & 127;
  int stage_v_77_2 = (((stage_v_35_2 * 3) + pub_r001603_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = (((helper_flow_2_1 * 3) + pub_r001603_3_1) + 37) & 127;
  int stage_v_78_2 = (((helper_flow_2_2 * 3) + pub_r001603_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = ((pub_r001603_5_1 * 2) + 7) & 63;
  int stage_v_79_2 = ((pub_r001603_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((stage_v_70_1 * 3) + pub_r001603_2_1) + 31) & 127;
  int stage_v_80_2 = (((stage_v_70_2 * 3) + pub_r001603_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = (((stage_v_51_1 * 3) + pub_r001603_2_1) + 35) & 127;
  int stage_v_81_2 = (((stage_v_51_2 * 3) + pub_r001603_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((stage_v_43_1 * 3) + pub_r001603_12_1) + 27) & 127;
  int stage_v_82_2 = (((stage_v_43_2 * 3) + pub_r001603_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001603_14_1 * 2) + 33) & 63;
  int stage_v_83_2 = ((pub_r001603_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001603_14_1 * 2) + 29) & 63;
  int stage_v_84_2 = ((pub_r001603_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001603_11_1 * 2) + 19) & 63;
  int stage_v_85_2 = ((pub_r001603_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001603_5_1 * 2) + 11) & 63;
  int stage_v_86_2 = ((pub_r001603_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001603_1_1 * 2) + 13) & 63;
  int stage_v_87_2 = ((pub_r001603_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_56_1 * 3) + pub_r001603_11_1) + 31) & 127;
  int stage_v_88_2 = (((stage_v_56_2 * 3) + pub_r001603_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = (((sec_r001603_13_1 * 3) + pub_r001603_3_1) + 3) & 127;
  int stage_v_89_2 = (((sec_r001603_13_2 * 3) + pub_r001603_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((sec_r001603_19_1 * 3) + pub_r001603_6_1) + 42) & 127;
  int stage_v_90_2 = (((sec_r001603_19_2 * 3) + pub_r001603_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((stage_v_72_1 * 3) + pub_r001603_0_1) + 26) & 127;
  int stage_v_91_2 = (((stage_v_72_2 * 3) + pub_r001603_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = ((pub_r001603_13_1 * 2) + 44) & 63;
  int stage_v_92_2 = ((pub_r001603_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001603_15_1 * 2) + 22) & 63;
  int stage_v_93_2 = ((pub_r001603_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001603_4_1 * 2) + 7) & 63;
  int stage_v_94_2 = ((pub_r001603_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001603_7_1 * 2) + 5) & 63;
  int stage_v_95_2 = ((pub_r001603_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((sec_r001603_9_1 * 3) + pub_r001603_14_1) + 43) & 127;
  int stage_v_96_2 = (((sec_r001603_9_2 * 3) + pub_r001603_14_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001603_7_1 * 2) + 44) & 63;
  int stage_v_97_2 = ((pub_r001603_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001603_7_1 * 2) + 49) & 63;
  int stage_v_98_2 = ((pub_r001603_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((stage_v_30_1 * 3) + pub_r001603_10_1) + 12) & 127;
  int stage_v_99_2 = (((stage_v_30_2 * 3) + pub_r001603_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = (((stage_v_64_1 * 3) + pub_r001603_1_1) + 6) & 127;
  int stage_v_100_2 = (((stage_v_64_2 * 3) + pub_r001603_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = ((pub_r001603_15_1 * 2) + 19) & 63;
  int stage_v_101_2 = ((pub_r001603_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((sec_r001603_15_1 * 3) + pub_r001603_4_1) + 4) & 127;
  int stage_v_102_2 = (((sec_r001603_15_2 * 3) + pub_r001603_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = ((pub_r001603_14_1 * 2) + 36) & 63;
  int stage_v_103_2 = ((pub_r001603_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001603_11_1 * 2) + 24) & 63;
  int stage_v_104_2 = ((pub_r001603_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((helper_flow_4_1 * 3) + pub_r001603_4_1) + 8) & 127;
  int stage_v_105_2 = (((helper_flow_4_2 * 3) + pub_r001603_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = (((sec_r001603_3_1 * 3) + pub_r001603_15_1) + 18) & 127;
  int stage_v_106_2 = (((sec_r001603_3_2 * 3) + pub_r001603_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = ((pub_r001603_11_1 * 2) + 8) & 63;
  int stage_v_107_2 = ((pub_r001603_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001603_5_1 * 2) + 44) & 63;
  int stage_v_108_2 = ((pub_r001603_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((stage_v_1_1 * 3) + pub_r001603_5_1) + 17) & 127;
  int stage_v_109_2 = (((stage_v_1_2 * 3) + pub_r001603_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((stage_v_50_1 * 3) + pub_r001603_13_1) + 12) & 127;
  int stage_v_110_2 = (((stage_v_50_2 * 3) + pub_r001603_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = (((stage_v_52_1 * 3) + pub_r001603_12_1) + 18) & 127;
  int stage_v_111_2 = (((stage_v_52_2 * 3) + pub_r001603_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = (((stage_v_0_1 * 3) + pub_r001603_2_1) + 43) & 127;
  int stage_v_112_2 = (((stage_v_0_2 * 3) + pub_r001603_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = (((stage_v_43_1 * 3) + pub_r001603_10_1) + 40) & 127;
  int stage_v_113_2 = (((stage_v_43_2 * 3) + pub_r001603_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001603_10_1 * 2) + 23) & 63;
  int stage_v_114_2 = ((pub_r001603_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (((sec_r001603_10_1 * 3) + pub_r001603_6_1) + 35) & 127;
  int stage_v_115_2 = (((sec_r001603_10_2 * 3) + pub_r001603_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = ((pub_r001603_11_1 * 2) + 10) & 63;
  int stage_v_116_2 = ((pub_r001603_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001603_11_1 * 2) + 33) & 63;
  int stage_v_117_2 = ((pub_r001603_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001603_8_1 * 2) + 17) & 63;
  int stage_v_118_2 = ((pub_r001603_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((sec_r001603_18_1 * 3) + pub_r001603_14_1) + 38) & 127;
  int stage_v_119_2 = (((sec_r001603_18_2 * 3) + pub_r001603_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = ((pub_r001603_11_1 * 2) + 34) & 63;
  int stage_v_120_2 = ((pub_r001603_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (((helper_flow_2_1 * 3) + pub_r001603_8_1) + 32) & 127;
  int stage_v_121_2 = (((helper_flow_2_2 * 3) + pub_r001603_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = (((stage_v_102_1 * 3) + pub_r001603_11_1) + 31) & 127;
  int stage_v_122_2 = (((stage_v_102_2 * 3) + pub_r001603_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = ((pub_r001603_14_1 * 2) + 43) & 63;
  int stage_v_123_2 = ((pub_r001603_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001603_10_1 * 2) + 18) & 63;
  int stage_v_124_2 = ((pub_r001603_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001603_13_1 * 2) + 23) & 63;
  int stage_v_125_2 = ((pub_r001603_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_91_1 * 3) + pub_r001603_6_1) + 10) & 127;
  int stage_v_126_2 = (((stage_v_91_2 * 3) + pub_r001603_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((stage_v_0_1 * 3) + pub_r001603_6_1) + 34) & 127;
  int stage_v_127_2 = (((stage_v_0_2 * 3) + pub_r001603_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((stage_v_21_1 * 3) + pub_r001603_13_1) + 23) & 127;
  int stage_v_128_2 = (((stage_v_21_2 * 3) + pub_r001603_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((stage_v_82_1 * 3) + pub_r001603_14_1) + 5) & 127;
  int stage_v_129_2 = (((stage_v_82_2 * 3) + pub_r001603_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((sec_r001603_11_1 * 3) + pub_r001603_4_1) + 11) & 127;
  int stage_v_130_2 = (((sec_r001603_11_2 * 3) + pub_r001603_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = (((stage_v_58_1 * 3) + pub_r001603_6_1) + 13) & 127;
  int stage_v_131_2 = (((stage_v_58_2 * 3) + pub_r001603_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = ((pub_r001603_10_1 * 2) + 41) & 63;
  int stage_v_132_2 = ((pub_r001603_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((sec_r001603_12_1 * 3) + pub_r001603_9_1) + 40) & 127;
  int stage_v_133_2 = (((sec_r001603_12_2 * 3) + pub_r001603_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_15_1 * 3) + pub_r001603_9_1) + 38) & 127;
  int stage_v_134_2 = (((stage_v_15_2 * 3) + pub_r001603_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((stage_v_130_1 * 3) + pub_r001603_7_1) + 23) & 127;
  int stage_v_135_2 = (((stage_v_130_2 * 3) + pub_r001603_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = ((pub_r001603_5_1 * 2) + 50) & 63;
  int stage_v_136_2 = ((pub_r001603_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001603_12_1 * 2) + 15) & 63;
  int stage_v_137_2 = ((pub_r001603_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((stage_v_77_1 * 3) + pub_r001603_2_1) + 26) & 127;
  int stage_v_138_2 = (((stage_v_77_2 * 3) + pub_r001603_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = (((stage_v_24_1 * 3) + pub_r001603_1_1) + 28) & 127;
  int stage_v_139_2 = (((stage_v_24_2 * 3) + pub_r001603_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((stage_v_63_1 * 3) + pub_r001603_11_1) + 3) & 127;
  int stage_v_140_2 = (((stage_v_63_2 * 3) + pub_r001603_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = (((stage_v_106_1 * 3) + pub_r001603_4_1) + 27) & 127;
  int stage_v_141_2 = (((stage_v_106_2 * 3) + pub_r001603_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((stage_v_72_1 * 3) + pub_r001603_3_1) + 11) & 127;
  int stage_v_142_2 = (((stage_v_72_2 * 3) + pub_r001603_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = ((pub_r001603_13_1 * 2) + 12) & 63;
  int stage_v_143_2 = ((pub_r001603_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001603_10_1 * 2) + 10) & 63;
  int stage_v_144_2 = ((pub_r001603_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((stage_v_57_1 * 3) + pub_r001603_13_1) + 26) & 127;
  int stage_v_145_2 = (((stage_v_57_2 * 3) + pub_r001603_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001603_9_1 * 2) + 39) & 63;
  int stage_v_146_2 = ((pub_r001603_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_64_1 * 3) + pub_r001603_0_1) + 7) & 127;
  int stage_v_147_2 = (((stage_v_64_2 * 3) + pub_r001603_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = ((pub_r001603_4_1 * 2) + 12) & 63;
  int stage_v_148_2 = ((pub_r001603_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((helper_flow_1_1 * 3) + pub_r001603_1_1) + 14) & 127;
  int stage_v_149_2 = (((helper_flow_1_2 * 3) + pub_r001603_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_138_1 * 3) + pub_r001603_4_1) + 45) & 127;
  int stage_v_150_2 = (((stage_v_138_2 * 3) + pub_r001603_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = ((pub_r001603_4_1 * 2) + 15) & 63;
  int stage_v_151_2 = ((pub_r001603_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_133_1 * 3) + pub_r001603_3_1) + 43) & 127;
  int stage_v_152_2 = (((stage_v_133_2 * 3) + pub_r001603_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = (((stage_v_141_1 * 3) + pub_r001603_5_1) + 5) & 127;
  int stage_v_153_2 = (((stage_v_141_2 * 3) + pub_r001603_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = (((stage_v_133_1 * 3) + pub_r001603_11_1) + 27) & 127;
  int stage_v_154_2 = (((stage_v_133_2 * 3) + pub_r001603_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = (((stage_v_135_1 * 3) + pub_r001603_10_1) + 19) & 127;
  int stage_v_155_2 = (((stage_v_135_2 * 3) + pub_r001603_10_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((stage_v_10_1 * 3) + pub_r001603_1_1) + 14) & 127;
  int stage_v_156_2 = (((stage_v_10_2 * 3) + pub_r001603_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((stage_v_5_1 * 3) + pub_r001603_14_1) + 17) & 127;
  int stage_v_157_2 = (((stage_v_5_2 * 3) + pub_r001603_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((stage_v_34_1 * 3) + pub_r001603_2_1) + 22) & 127;
  int stage_v_158_2 = (((stage_v_34_2 * 3) + pub_r001603_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((stage_v_2_1 * 3) + pub_r001603_9_1) + 38) & 127;
  int stage_v_159_2 = (((stage_v_2_2 * 3) + pub_r001603_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((stage_v_140_1 * 3) + pub_r001603_3_1) + 12) & 127;
  int stage_v_160_2 = (((stage_v_140_2 * 3) + pub_r001603_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = ((pub_r001603_9_1 * 2) + 8) & 63;
  int stage_v_161_2 = ((pub_r001603_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001603_10_1 * 2) + 34) & 63;
  int stage_v_162_2 = ((pub_r001603_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((sec_r001603_3_1 * 3) + pub_r001603_0_1) + 22) & 127;
  int stage_v_163_2 = (((sec_r001603_3_2 * 3) + pub_r001603_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = ((pub_r001603_7_1 * 2) + 46) & 63;
  int stage_v_164_2 = ((pub_r001603_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_25_1 * 3) + pub_r001603_7_1) + 16) & 127;
  int stage_v_165_2 = (((stage_v_25_2 * 3) + pub_r001603_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = (((stage_v_128_1 * 3) + pub_r001603_1_1) + 26) & 127;
  int stage_v_166_2 = (((stage_v_128_2 * 3) + pub_r001603_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = ((pub_r001603_9_1 * 2) + 28) & 63;
  int stage_v_167_2 = ((pub_r001603_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((sec_r001603_18_1 * 3) + pub_r001603_2_1) + 32) & 127;
  int stage_v_168_2 = (((sec_r001603_18_2 * 3) + pub_r001603_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = ((pub_r001603_10_1 * 2) + 10) & 63;
  int stage_v_169_2 = ((pub_r001603_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((sec_r001603_15_1 * 3) + pub_r001603_9_1) + 12) & 127;
  int stage_v_170_2 = (((sec_r001603_15_2 * 3) + pub_r001603_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001603_11_1 * 2) + 49) & 63;
  int stage_v_171_2 = ((pub_r001603_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001603_0_1 * 2) + 35) & 63;
  int stage_v_172_2 = ((pub_r001603_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001603_6_1 * 2) + 12) & 63;
  int stage_v_173_2 = ((pub_r001603_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001603_2_1 * 2) + 29) & 63;
  int stage_v_174_2 = ((pub_r001603_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001603_15_1 * 2) + 35) & 63;
  int stage_v_175_2 = ((pub_r001603_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_46_1 * 3) + pub_r001603_11_1) + 38) & 127;
  int stage_v_176_2 = (((stage_v_46_2 * 3) + pub_r001603_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = ((pub_r001603_13_1 * 2) + 37) & 63;
  int stage_v_177_2 = ((pub_r001603_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001603_3_1 * 2) + 44) & 63;
  int stage_v_178_2 = ((pub_r001603_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001603_11_1 * 2) + 24) & 63;
  int stage_v_179_2 = ((pub_r001603_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001603_4_1 * 2) + 11) & 63;
  int stage_v_180_2 = ((pub_r001603_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_130_1 * 3) + pub_r001603_8_1) + 8) & 127;
  int stage_v_181_2 = (((stage_v_130_2 * 3) + pub_r001603_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = ((pub_r001603_2_1 * 2) + 40) & 63;
  int stage_v_182_2 = ((pub_r001603_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_106_1 * 3) + pub_r001603_5_1) + 11) & 127;
  int stage_v_183_2 = (((stage_v_106_2 * 3) + pub_r001603_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((stage_v_88_1 * 3) + pub_r001603_4_1) + 36) & 127;
  int stage_v_184_2 = (((stage_v_88_2 * 3) + pub_r001603_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = ((pub_r001603_5_1 * 2) + 49) & 63;
  int stage_v_185_2 = ((pub_r001603_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_5_1 * 3) + pub_r001603_12_1) + 30) & 127;
  int stage_v_186_2 = (((stage_v_5_2 * 3) + pub_r001603_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = (((stage_v_52_1 * 3) + pub_r001603_5_1) + 30) & 127;
  int stage_v_187_2 = (((stage_v_52_2 * 3) + pub_r001603_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = (((stage_v_69_1 * 3) + pub_r001603_13_1) + 23) & 127;
  int stage_v_188_2 = (((stage_v_69_2 * 3) + pub_r001603_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001603_12_1 * 2) + 10) & 63;
  int stage_v_189_2 = ((pub_r001603_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_9_1 * 3) + pub_r001603_9_1) + 43) & 127;
  int stage_v_190_2 = (((stage_v_9_2 * 3) + pub_r001603_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((stage_v_42_1 * 3) + pub_r001603_4_1) + 16) & 127;
  int stage_v_191_2 = (((stage_v_42_2 * 3) + pub_r001603_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((stage_v_188_1 * 3) + pub_r001603_6_1) + 3) & 127;
  int stage_v_192_2 = (((stage_v_188_2 * 3) + pub_r001603_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = ((pub_r001603_15_1 * 2) + 15) & 63;
  int stage_v_193_2 = ((pub_r001603_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((stage_v_42_1 * 3) + pub_r001603_7_1) + 35) & 127;
  int stage_v_194_2 = (((stage_v_42_2 * 3) + pub_r001603_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = ((pub_r001603_3_1 * 2) + 27) & 63;
  int stage_v_195_2 = ((pub_r001603_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001603_4_1 * 2) + 44) & 63;
  int stage_v_196_2 = ((pub_r001603_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((sec_r001603_4_1 * 3) + pub_r001603_0_1) + 17) & 127;
  int stage_v_197_2 = (((sec_r001603_4_2 * 3) + pub_r001603_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((stage_v_165_1 * 3) + pub_r001603_2_1) + 17) & 127;
  int stage_v_198_2 = (((stage_v_165_2 * 3) + pub_r001603_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001603_10_1 * 2) + 34) & 63;
  int stage_v_199_2 = ((pub_r001603_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001603_4_1 * 2) + 42) & 63;
  int stage_v_200_2 = ((pub_r001603_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001603_3_1 * 2) + 43) & 63;
  int stage_v_201_2 = ((pub_r001603_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001603_11_1 * 2) + 23) & 63;
  int stage_v_202_2 = ((pub_r001603_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((sec_r001603_11_1 * 3) + pub_r001603_8_1) + 21) & 127;
  int stage_v_203_2 = (((sec_r001603_11_2 * 3) + pub_r001603_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((stage_v_170_1 * 3) + pub_r001603_12_1) + 9) & 127;
  int stage_v_204_2 = (((stage_v_170_2 * 3) + pub_r001603_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_188_1 * 3) + pub_r001603_3_1) + 26) & 127;
  int stage_v_205_2 = (((stage_v_188_2 * 3) + pub_r001603_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001603_8_1 * 2) + 14) & 63;
  int stage_v_206_2 = ((pub_r001603_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_113_1 * 3) + pub_r001603_7_1) + 23) & 127;
  int stage_v_207_2 = (((stage_v_113_2 * 3) + pub_r001603_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = (((stage_v_49_1 * 3) + pub_r001603_6_1) + 41) & 127;
  int stage_v_208_2 = (((stage_v_49_2 * 3) + pub_r001603_6_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = (((stage_v_77_1 * 3) + pub_r001603_5_1) + 4) & 127;
  int stage_v_209_2 = (((stage_v_77_2 * 3) + pub_r001603_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = (((stage_v_187_1 * 3) + pub_r001603_6_1) + 18) & 127;
  int stage_v_210_2 = (((stage_v_187_2 * 3) + pub_r001603_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = ((pub_r001603_5_1 * 2) + 8) & 63;
  int stage_v_211_2 = ((pub_r001603_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001603_2_1 * 2) + 47) & 63;
  int stage_v_212_2 = ((pub_r001603_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001603_13_1 * 2) + 14) & 63;
  int stage_v_213_2 = ((pub_r001603_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001603_7_1 * 2) + 45) & 63;
  int stage_v_214_2 = ((pub_r001603_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001603_5_1 * 2) + 44) & 63;
  int stage_v_215_2 = ((pub_r001603_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001603_10_1 * 2) + 27) & 63;
  int stage_v_216_2 = ((pub_r001603_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_190_1 * 3) + pub_r001603_10_1) + 14) & 127;
  int stage_v_217_2 = (((stage_v_190_2 * 3) + pub_r001603_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = (((stage_v_165_1 * 3) + pub_r001603_3_1) + 30) & 127;
  int stage_v_218_2 = (((stage_v_165_2 * 3) + pub_r001603_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = ((pub_r001603_14_1 * 2) + 38) & 63;
  int stage_v_219_2 = ((pub_r001603_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((stage_v_198_1 * 3) + pub_r001603_4_1) + 15) & 127;
  int stage_v_220_2 = (((stage_v_198_2 * 3) + pub_r001603_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((stage_v_51_1 * 3) + pub_r001603_4_1) + 26) & 127;
  int stage_v_221_2 = (((stage_v_51_2 * 3) + pub_r001603_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((stage_v_82_1 * 3) + pub_r001603_7_1) + 36) & 127;
  int stage_v_222_2 = (((stage_v_82_2 * 3) + pub_r001603_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = (((stage_v_149_1 * 3) + pub_r001603_13_1) + 9) & 127;
  int stage_v_223_2 = (((stage_v_149_2 * 3) + pub_r001603_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = (((stage_v_158_1 * 3) + pub_r001603_5_1) + 29) & 127;
  int stage_v_224_2 = (((stage_v_158_2 * 3) + pub_r001603_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = (((stage_v_24_1 * 3) + pub_r001603_11_1) + 9) & 127;
  int stage_v_225_2 = (((stage_v_24_2 * 3) + pub_r001603_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((stage_v_100_1 * 3) + pub_r001603_9_1) + 14) & 127;
  int stage_v_226_2 = (((stage_v_100_2 * 3) + pub_r001603_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((stage_v_131_1 * 3) + pub_r001603_2_1) + 31) & 127;
  int stage_v_227_2 = (((stage_v_131_2 * 3) + pub_r001603_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = (((stage_v_145_1 * 3) + pub_r001603_2_1) + 19) & 127;
  int stage_v_228_2 = (((stage_v_145_2 * 3) + pub_r001603_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = ((pub_r001603_7_1 * 2) + 5) & 63;
  int stage_v_229_2 = ((pub_r001603_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001603_2_1 * 2) + 16) & 63;
  int stage_v_230_2 = ((pub_r001603_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((stage_v_205_1 * 3) + pub_r001603_3_1) + 38) & 127;
  int stage_v_231_2 = (((stage_v_205_2 * 3) + pub_r001603_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = ((pub_r001603_14_1 * 2) + 30) & 63;
  int stage_v_232_2 = ((pub_r001603_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = (((stage_v_15_1 * 3) + pub_r001603_14_1) + 43) & 127;
  int stage_v_233_2 = (((stage_v_15_2 * 3) + pub_r001603_14_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = ((pub_r001603_10_1 * 2) + 29) & 63;
  int stage_v_234_2 = ((pub_r001603_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = (((stage_v_121_1 * 3) + pub_r001603_8_1) + 8) & 127;
  int stage_v_235_2 = (((stage_v_121_2 * 3) + pub_r001603_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = ((pub_r001603_1_1 * 2) + 16) & 63;
  int stage_v_236_2 = ((pub_r001603_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = (((stage_v_233_1 * 3) + pub_r001603_14_1) + 4) & 127;
  int stage_v_237_2 = (((stage_v_233_2 * 3) + pub_r001603_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = ((pub_r001603_14_1 * 2) + 36) & 63;
  int stage_v_238_2 = ((pub_r001603_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = (((stage_v_163_1 * 3) + pub_r001603_7_1) + 17) & 127;
  int stage_v_239_2 = (((stage_v_163_2 * 3) + pub_r001603_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = ((pub_r001603_15_1 * 2) + 43) & 63;
  int stage_v_240_2 = ((pub_r001603_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = (((stage_v_45_1 * 3) + pub_r001603_13_1) + 25) & 127;
  int stage_v_241_2 = (((stage_v_45_2 * 3) + pub_r001603_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = ((pub_r001603_8_1 * 2) + 48) & 63;
  int stage_v_242_2 = ((pub_r001603_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = (((helper_flow_4_1 * 3) + pub_r001603_6_1) + 22) & 127;
  int stage_v_243_2 = (((helper_flow_4_2 * 3) + pub_r001603_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_113_1 * 3) + pub_r001603_1_1) + 8) & 127;
  int stage_v_244_2 = (((stage_v_113_2 * 3) + pub_r001603_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((sec_r001603_16_1 * 3) + pub_r001603_14_1) + 10) & 127;
  int stage_v_245_2 = (((sec_r001603_16_2 * 3) + pub_r001603_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001603_4_1 * 2) + 35) & 63;
  int stage_v_246_2 = ((pub_r001603_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001603_4_1 * 2) + 25) & 63;
  int stage_v_247_2 = ((pub_r001603_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((stage_v_217_1 * 3) + pub_r001603_5_1) + 45) & 127;
  int stage_v_248_2 = (((stage_v_217_2 * 3) + pub_r001603_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((stage_v_45_1 * 3) + pub_r001603_8_1) + 17) & 127;
  int stage_v_249_2 = (((stage_v_45_2 * 3) + pub_r001603_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_71_1 * 3) + pub_r001603_13_1) + 10) & 127;
  int stage_v_250_2 = (((stage_v_71_2 * 3) + pub_r001603_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((stage_v_68_1 * 3) + pub_r001603_6_1) + 40) & 127;
  int stage_v_251_2 = (((stage_v_68_2 * 3) + pub_r001603_6_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = ((pub_r001603_15_1 * 2) + 42) & 63;
  int stage_v_252_2 = ((pub_r001603_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = (((sec_r001603_9_1 * 3) + pub_r001603_4_1) + 25) & 127;
  int stage_v_253_2 = (((sec_r001603_9_2 * 3) + pub_r001603_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = ((pub_r001603_10_1 * 2) + 26) & 63;
  int stage_v_254_2 = ((pub_r001603_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001603_7_1 * 2) + 38) & 63;
  int stage_v_255_2 = ((pub_r001603_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001603_10_1 * 2) + 25) & 63;
  int stage_v_256_2 = ((pub_r001603_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001603_7_1 * 2) + 24) & 63;
  int stage_v_257_2 = ((pub_r001603_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_198_1 * 3) + pub_r001603_2_1) + 15) & 127;
  int stage_v_258_2 = (((stage_v_198_2 * 3) + pub_r001603_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001603_1_1 * 2) + 49) & 63;
  int stage_v_259_2 = ((pub_r001603_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001603_4_1 * 2) + 26) & 63;
  int stage_v_260_2 = ((pub_r001603_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001603_11_1 * 2) + 49) & 63;
  int stage_v_261_2 = ((pub_r001603_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = (((stage_v_218_1 * 3) + pub_r001603_13_1) + 15) & 127;
  int stage_v_262_2 = (((stage_v_218_2 * 3) + pub_r001603_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = (((stage_v_112_1 * 3) + pub_r001603_4_1) + 14) & 127;
  int stage_v_263_2 = (((stage_v_112_2 * 3) + pub_r001603_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001603_2_1 * 2) + 42) & 63;
  int stage_v_264_2 = ((pub_r001603_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((sec_r001603_6_1 * 3) + pub_r001603_15_1) + 30) & 127;
  int stage_v_265_2 = (((sec_r001603_6_2 * 3) + pub_r001603_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_67_1 * 3) + pub_r001603_6_1) + 5) & 127;
  int stage_v_266_2 = (((stage_v_67_2 * 3) + pub_r001603_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((stage_v_70_1 * 3) + pub_r001603_14_1) + 43) & 127;
  int stage_v_267_2 = (((stage_v_70_2 * 3) + pub_r001603_14_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = ((pub_r001603_4_1 * 2) + 37) & 63;
  int stage_v_268_2 = ((pub_r001603_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001603_7_1 * 2) + 12) & 63;
  int stage_v_269_2 = ((pub_r001603_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = (((stage_v_158_1 * 3) + pub_r001603_1_1) + 42) & 127;
  int stage_v_270_2 = (((stage_v_158_2 * 3) + pub_r001603_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = ((pub_r001603_13_1 * 2) + 16) & 63;
  int stage_v_271_2 = ((pub_r001603_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001603_9_1 * 2) + 37) & 63;
  int stage_v_272_2 = ((pub_r001603_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001603_3_1 * 2) + 16) & 63;
  int stage_v_273_2 = ((pub_r001603_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001603_12_1 * 2) + 19) & 63;
  int stage_v_274_2 = ((pub_r001603_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = (((stage_v_69_1 * 3) + pub_r001603_0_1) + 31) & 127;
  int stage_v_275_2 = (((stage_v_69_2 * 3) + pub_r001603_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = (((stage_v_67_1 * 3) + pub_r001603_14_1) + 31) & 127;
  int stage_v_276_2 = (((stage_v_67_2 * 3) + pub_r001603_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = ((pub_r001603_12_1 * 2) + 5) & 63;
  int stage_v_277_2 = ((pub_r001603_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((stage_v_239_1 * 3) + pub_r001603_1_1) + 43) & 127;
  int stage_v_278_2 = (((stage_v_239_2 * 3) + pub_r001603_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001603_2_1 * 2) + 37) & 63;
  int stage_v_279_2 = ((pub_r001603_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = (((stage_v_248_1 * 3) + pub_r001603_8_1) + 6) & 127;
  int stage_v_280_2 = (((stage_v_248_2 * 3) + pub_r001603_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = ((pub_r001603_15_1 * 2) + 25) & 63;
  int stage_v_281_2 = ((pub_r001603_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001603_6_1 * 2) + 10) & 63;
  int stage_v_282_2 = ((pub_r001603_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001603_14_1 * 2) + 18) & 63;
  int stage_v_283_2 = ((pub_r001603_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = (((stage_v_220_1 * 3) + pub_r001603_5_1) + 19) & 127;
  int stage_v_284_2 = (((stage_v_220_2 * 3) + pub_r001603_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = (((stage_v_186_1 * 3) + pub_r001603_5_1) + 44) & 127;
  int stage_v_285_2 = (((stage_v_186_2 * 3) + pub_r001603_5_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = ((pub_r001603_8_1 * 2) + 19) & 63;
  int stage_v_286_2 = ((pub_r001603_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = (((stage_v_266_1 * 3) + pub_r001603_12_1) + 43) & 127;
  int stage_v_287_2 = (((stage_v_266_2 * 3) + pub_r001603_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((sec_r001603_4_1 * 3) + pub_r001603_5_1) + 35) & 127;
  int stage_v_288_2 = (((sec_r001603_4_2 * 3) + pub_r001603_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = (((stage_v_88_1 * 3) + pub_r001603_12_1) + 44) & 127;
  int stage_v_289_2 = (((stage_v_88_2 * 3) + pub_r001603_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = ((pub_r001603_0_1 * 2) + 39) & 63;
  int stage_v_290_2 = ((pub_r001603_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = (((stage_v_105_1 * 3) + pub_r001603_6_1) + 31) & 127;
  int stage_v_291_2 = (((stage_v_105_2 * 3) + pub_r001603_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001603_15_1 * 2) + 31) & 63;
  int stage_v_292_2 = ((pub_r001603_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = (((stage_v_91_1 * 3) + pub_r001603_11_1) + 38) & 127;
  int stage_v_293_2 = (((stage_v_91_2 * 3) + pub_r001603_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = (((stage_v_57_1 * 3) + pub_r001603_13_1) + 45) & 127;
  int stage_v_294_2 = (((stage_v_57_2 * 3) + pub_r001603_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = (((stage_v_69_1 * 3) + pub_r001603_7_1) + 37) & 127;
  int stage_v_295_2 = (((stage_v_69_2 * 3) + pub_r001603_7_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001603_7_1 * 2) + 7) & 63;
  int stage_v_296_2 = ((pub_r001603_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = (((stage_v_168_1 * 3) + pub_r001603_8_1) + 7) & 127;
  int stage_v_297_2 = (((stage_v_168_2 * 3) + pub_r001603_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = ((pub_r001603_0_1 * 2) + 38) & 63;
  int stage_v_298_2 = ((pub_r001603_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001603_9_1 * 2) + 36) & 63;
  int stage_v_299_2 = ((pub_r001603_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = (((sec_r001603_20_1 * 3) + pub_r001603_1_1) + 24) & 127;
  int stage_v_300_2 = (((sec_r001603_20_2 * 3) + pub_r001603_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = (((stage_v_218_1 * 3) + pub_r001603_2_1) + 5) & 127;
  int stage_v_301_2 = (((stage_v_218_2 * 3) + pub_r001603_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = (((stage_v_186_1 * 3) + pub_r001603_4_1) + 33) & 127;
  int stage_v_302_2 = (((stage_v_186_2 * 3) + pub_r001603_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = ((pub_r001603_0_1 * 2) + 22) & 63;
  int stage_v_303_2 = ((pub_r001603_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = (((stage_v_183_1 * 3) + pub_r001603_6_1) + 23) & 127;
  int stage_v_304_2 = (((stage_v_183_2 * 3) + pub_r001603_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = (((sec_r001603_18_1 * 3) + pub_r001603_11_1) + 21) & 127;
  int stage_v_305_2 = (((sec_r001603_18_2 * 3) + pub_r001603_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = ((pub_r001603_10_1 * 2) + 37) & 63;
  int stage_v_306_2 = ((pub_r001603_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = (((stage_v_110_1 * 3) + pub_r001603_8_1) + 32) & 127;
  int stage_v_307_2 = (((stage_v_110_2 * 3) + pub_r001603_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = (((stage_v_253_1 * 3) + pub_r001603_10_1) + 37) & 127;
  int stage_v_308_2 = (((stage_v_253_2 * 3) + pub_r001603_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = (((stage_v_204_1 * 3) + pub_r001603_4_1) + 10) & 127;
  int stage_v_309_2 = (((stage_v_204_2 * 3) + pub_r001603_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = (((stage_v_248_1 * 3) + pub_r001603_15_1) + 8) & 127;
  int stage_v_310_2 = (((stage_v_248_2 * 3) + pub_r001603_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = (((stage_v_168_1 * 3) + pub_r001603_8_1) + 9) & 127;
  int stage_v_311_2 = (((stage_v_168_2 * 3) + pub_r001603_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001603_8_1 * 2) + 38) & 63;
  int stage_v_312_2 = ((pub_r001603_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((stage_v_26_1 * 3) + pub_r001603_4_1) + 32) & 127;
  int stage_v_313_2 = (((stage_v_26_2 * 3) + pub_r001603_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001603_10_1 * 2) + 45) & 63;
  int stage_v_314_2 = ((pub_r001603_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001603_13_1 * 2) + 25) & 63;
  int stage_v_315_2 = ((pub_r001603_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((stage_v_237_1 * 3) + pub_r001603_4_1) + 11) & 127;
  int stage_v_316_2 = (((stage_v_237_2 * 3) + pub_r001603_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((stage_v_35_1 * 3) + pub_r001603_12_1) + 34) & 127;
  int stage_v_317_2 = (((stage_v_35_2 * 3) + pub_r001603_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = ((pub_r001603_5_1 * 2) + 25) & 63;
  int stage_v_318_2 = ((pub_r001603_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001603_5_1 * 2) + 14) & 63;
  int stage_v_319_2 = ((pub_r001603_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((stage_v_165_1 * 3) + pub_r001603_11_1) + 10) & 127;
  int stage_v_320_2 = (((stage_v_165_2 * 3) + pub_r001603_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = ((pub_r001603_7_1 * 2) + 13) & 63;
  int stage_v_321_2 = ((pub_r001603_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = (((stage_v_71_1 * 3) + pub_r001603_11_1) + 18) & 127;
  int stage_v_322_2 = (((stage_v_71_2 * 3) + pub_r001603_11_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = (((stage_v_149_1 * 3) + pub_r001603_7_1) + 21) & 127;
  int stage_v_323_2 = (((stage_v_149_2 * 3) + pub_r001603_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = (((stage_v_133_1 * 3) + pub_r001603_10_1) + 35) & 127;
  int stage_v_324_2 = (((stage_v_133_2 * 3) + pub_r001603_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((stage_v_311_1 * 3) + pub_r001603_12_1) + 15) & 127;
  int stage_v_325_2 = (((stage_v_311_2 * 3) + pub_r001603_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((stage_v_226_1 * 3) + pub_r001603_1_1) + 45) & 127;
  int stage_v_326_2 = (((stage_v_226_2 * 3) + pub_r001603_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = ((pub_r001603_9_1 * 2) + 7) & 63;
  int stage_v_327_2 = ((pub_r001603_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001603_13_1 * 2) + 29) & 63;
  int stage_v_328_2 = ((pub_r001603_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = (((sec_r001603_19_1 * 3) + pub_r001603_14_1) + 21) & 127;
  int stage_v_329_2 = (((sec_r001603_19_2 * 3) + pub_r001603_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = (((stage_v_89_1 * 3) + pub_r001603_6_1) + 8) & 127;
  int stage_v_330_2 = (((stage_v_89_2 * 3) + pub_r001603_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = ((pub_r001603_15_1 * 2) + 50) & 63;
  int stage_v_331_2 = ((pub_r001603_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001603_0_1 * 2) + 28) & 63;
  int stage_v_332_2 = ((pub_r001603_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = (((stage_v_310_1 * 3) + pub_r001603_9_1) + 42) & 127;
  int stage_v_333_2 = (((stage_v_310_2 * 3) + pub_r001603_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = (((stage_v_266_1 * 3) + pub_r001603_11_1) + 37) & 127;
  int stage_v_334_2 = (((stage_v_266_2 * 3) + pub_r001603_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = (((stage_v_127_1 * 3) + pub_r001603_0_1) + 30) & 127;
  int stage_v_335_2 = (((stage_v_127_2 * 3) + pub_r001603_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((stage_v_267_1 * 3) + pub_r001603_14_1) + 42) & 127;
  int stage_v_336_2 = (((stage_v_267_2 * 3) + pub_r001603_14_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_26_1 * 3) + pub_r001603_3_1) + 19) & 127;
  int stage_v_337_2 = (((stage_v_26_2 * 3) + pub_r001603_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((stage_v_223_1 * 3) + pub_r001603_4_1) + 10) & 127;
  int stage_v_338_2 = (((stage_v_223_2 * 3) + pub_r001603_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = (((stage_v_38_1 * 3) + pub_r001603_1_1) + 13) & 127;
  int stage_v_339_2 = (((stage_v_38_2 * 3) + pub_r001603_1_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = (((stage_v_70_1 * 3) + pub_r001603_1_1) + 6) & 127;
  int stage_v_340_2 = (((stage_v_70_2 * 3) + pub_r001603_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = ((pub_r001603_9_1 * 2) + 7) & 63;
  int stage_v_341_2 = ((pub_r001603_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001603_9_1 * 2) + 8) & 63;
  int stage_v_342_2 = ((pub_r001603_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001603_6_1 * 2) + 28) & 63;
  int stage_v_343_2 = ((pub_r001603_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001603_14_1 * 2) + 47) & 63;
  int stage_v_344_2 = ((pub_r001603_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((pub_r001603_2_1 * 2) + 38) & 63;
  int stage_v_345_2 = ((pub_r001603_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = (((stage_v_276_1 * 3) + pub_r001603_8_1) + 10) & 127;
  int stage_v_346_2 = (((stage_v_276_2 * 3) + pub_r001603_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = (((stage_v_224_1 * 3) + pub_r001603_3_1) + 42) & 127;
  int stage_v_347_2 = (((stage_v_224_2 * 3) + pub_r001603_3_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_157_1 * 3) + pub_r001603_9_1) + 14) & 127;
  int stage_v_348_2 = (((stage_v_157_2 * 3) + pub_r001603_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = ((pub_r001603_11_1 * 2) + 7) & 63;
  int stage_v_349_2 = ((pub_r001603_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((pub_r001603_11_1 * 2) + 47) & 63;
  int stage_v_350_2 = ((pub_r001603_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001603_13_1 * 2) + 47) & 63;
  int stage_v_351_2 = ((pub_r001603_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001603_13_1 * 2) + 43) & 63;
  int stage_v_352_2 = ((pub_r001603_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = (((stage_v_187_1 * 3) + pub_r001603_3_1) + 37) & 127;
  int stage_v_353_2 = (((stage_v_187_2 * 3) + pub_r001603_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = (((stage_v_64_1 * 3) + pub_r001603_12_1) + 10) & 127;
  int stage_v_354_2 = (((stage_v_64_2 * 3) + pub_r001603_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = ((pub_r001603_13_1 * 2) + 16) & 63;
  int stage_v_355_2 = ((pub_r001603_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = (((stage_v_208_1 * 3) + pub_r001603_10_1) + 26) & 127;
  int stage_v_356_2 = (((stage_v_208_2 * 3) + pub_r001603_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = (((stage_v_235_1 * 3) + pub_r001603_12_1) + 14) & 127;
  int stage_v_357_2 = (((stage_v_235_2 * 3) + pub_r001603_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = ((pub_r001603_5_1 * 2) + 18) & 63;
  int stage_v_358_2 = ((pub_r001603_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001603_13_1 * 2) + 22) & 63;
  int stage_v_359_2 = ((pub_r001603_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001603_14_1 * 2) + 43) & 63;
  int stage_v_360_2 = ((pub_r001603_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = (((stage_v_89_1 * 3) + pub_r001603_3_1) + 17) & 127;
  int stage_v_361_2 = (((stage_v_89_2 * 3) + pub_r001603_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001603_12_1 * 2) + 11) & 63;
  int stage_v_362_2 = ((pub_r001603_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001603_1_1 * 2) + 9) & 63;
  int stage_v_363_2 = ((pub_r001603_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = (((stage_v_10_1 * 3) + pub_r001603_2_1) + 7) & 127;
  int stage_v_364_2 = (((stage_v_10_2 * 3) + pub_r001603_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = ((pub_r001603_2_1 * 2) + 25) & 63;
  int stage_v_365_2 = ((pub_r001603_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001603_14_1 * 2) + 34) & 63;
  int stage_v_366_2 = ((pub_r001603_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((sec_r001603_20_1 * 3) + pub_r001603_14_1) + 38) & 127;
  int stage_v_367_2 = (((sec_r001603_20_2 * 3) + pub_r001603_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = (((stage_v_35_1 * 3) + pub_r001603_5_1) + 3) & 127;
  int stage_v_368_2 = (((stage_v_35_2 * 3) + pub_r001603_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = ((pub_r001603_12_1 * 2) + 8) & 63;
  int stage_v_369_2 = ((pub_r001603_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001603_10_1 * 2) + 24) & 63;
  int stage_v_370_2 = ((pub_r001603_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001603_11_1 * 2) + 30) & 63;
  int stage_v_371_2 = ((pub_r001603_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = (((stage_v_69_1 * 3) + pub_r001603_4_1) + 3) & 127;
  int stage_v_372_2 = (((stage_v_69_2 * 3) + pub_r001603_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = (((stage_v_297_1 * 3) + pub_r001603_2_1) + 21) & 127;
  int stage_v_373_2 = (((stage_v_297_2 * 3) + pub_r001603_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = ((pub_r001603_11_1 * 2) + 49) & 63;
  int stage_v_374_2 = ((pub_r001603_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = (((stage_v_91_1 * 3) + pub_r001603_11_1) + 20) & 127;
  int stage_v_375_2 = (((stage_v_91_2 * 3) + pub_r001603_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001603_1_1 * 2) + 43) & 63;
  int stage_v_376_2 = ((pub_r001603_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001603_12_1 * 2) + 36) & 63;
  int stage_v_377_2 = ((pub_r001603_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = (((stage_v_308_1 * 3) + pub_r001603_8_1) + 40) & 127;
  int stage_v_378_2 = (((stage_v_308_2 * 3) + pub_r001603_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((sec_r001603_8_1 * 3) + pub_r001603_3_1) + 27) & 127;
  int stage_v_379_2 = (((sec_r001603_8_2 * 3) + pub_r001603_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = ((pub_r001603_4_1 * 2) + 29) & 63;
  int stage_v_380_2 = ((pub_r001603_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001603_12_1 * 2) + 49) & 63;
  int stage_v_381_2 = ((pub_r001603_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((stage_v_102_1 * 3) + pub_r001603_0_1) + 35) & 127;
  int stage_v_382_2 = (((stage_v_102_2 * 3) + pub_r001603_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = ((pub_r001603_1_1 * 2) + 8) & 63;
  int stage_v_383_2 = ((pub_r001603_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001603_10_1 * 2) + 32) & 63;
  int stage_v_384_2 = ((pub_r001603_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001603_11_1 * 2) + 7) & 63;
  int stage_v_385_2 = ((pub_r001603_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001603_12_1 * 2) + 16) & 63;
  int stage_v_386_2 = ((pub_r001603_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((stage_v_69_1 * 3) + pub_r001603_8_1) + 16) & 127;
  int stage_v_387_2 = (((stage_v_69_2 * 3) + pub_r001603_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001603_8_1 * 2) + 18) & 63;
  int stage_v_388_2 = ((pub_r001603_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001603_0_1 * 2) + 43) & 63;
  int stage_v_389_2 = ((pub_r001603_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((pub_r001603_7_1 * 2) + 39) & 63;
  int stage_v_390_2 = ((pub_r001603_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((pub_r001603_12_1 * 2) + 37) & 63;
  int stage_v_391_2 = ((pub_r001603_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = (((helper_flow_3_1 * 3) + pub_r001603_0_1) + 17) & 127;
  int stage_v_392_2 = (((helper_flow_3_2 * 3) + pub_r001603_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = ((pub_r001603_12_1 * 2) + 38) & 63;
  int stage_v_393_2 = ((pub_r001603_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = (((stage_v_326_1 * 3) + pub_r001603_13_1) + 5) & 127;
  int stage_v_394_2 = (((stage_v_326_2 * 3) + pub_r001603_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = (((stage_v_325_1 * 3) + pub_r001603_2_1) + 42) & 127;
  int stage_v_395_2 = (((stage_v_325_2 * 3) + pub_r001603_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = ((pub_r001603_0_1 * 2) + 9) & 63;
  int stage_v_396_2 = ((pub_r001603_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = (((sec_r001603_19_1 * 3) + pub_r001603_6_1) + 4) & 127;
  int stage_v_397_2 = (((sec_r001603_19_2 * 3) + pub_r001603_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = (((stage_v_14_1 * 3) + pub_r001603_3_1) + 38) & 127;
  int stage_v_398_2 = (((stage_v_14_2 * 3) + pub_r001603_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = ((pub_r001603_12_1 * 2) + 9) & 63;
  int stage_v_399_2 = ((pub_r001603_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001603_5_1 * 2) + 14) & 63;
  int stage_v_400_2 = ((pub_r001603_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001603_11_1 != sec_r001603_11_2);
  __CPROVER_assume(sec_r001603_18_1 != sec_r001603_18_2);
  __CPROVER_assume(pub_r001603_1_1 == pub_r001603_1_2);
  __CPROVER_assume(pub_r001603_11_1 == pub_r001603_11_2);
  __CPROVER_assume(pub_r001603_12_1 == pub_r001603_12_2);
  __CPROVER_assume(pub_r001603_3_1 == pub_r001603_3_2);
  __CPROVER_assume(sec_r001603_9_1 != sec_r001603_9_2);
  __CPROVER_assume(sec_r001603_12_1 != sec_r001603_12_2);
  __CPROVER_assume(sec_r001603_10_1 != sec_r001603_10_2);
  __CPROVER_assume(sec_r001603_14_1 != sec_r001603_14_2);
  __CPROVER_assume(pub_r001603_13_1 == pub_r001603_13_2);
  __CPROVER_assume(pub_r001603_0_1 == pub_r001603_0_2);
  __CPROVER_assume(pub_r001603_6_1 == pub_r001603_6_2);
  __CPROVER_assume(sec_r001603_16_1 != sec_r001603_16_2);
  __CPROVER_assume(pub_r001603_10_1 == pub_r001603_10_2);
  __CPROVER_assume(pub_r001603_15_1 == pub_r001603_15_2);
  __CPROVER_assume(pub_r001603_8_1 == pub_r001603_8_2);
  __CPROVER_assume(sec_r001603_17_1 != sec_r001603_17_2);
  __CPROVER_assume(pub_r001603_5_1 == pub_r001603_5_2);
  __CPROVER_assume(sec_r001603_6_1 != sec_r001603_6_2);
  __CPROVER_assume(pub_r001603_14_1 == pub_r001603_14_2);
  __CPROVER_assume(pub_r001603_9_1 == pub_r001603_9_2);
  __CPROVER_assume(sec_r001603_15_1 != sec_r001603_15_2);
  __CPROVER_assume(sec_r001603_7_1 != sec_r001603_7_2);
  __CPROVER_assume(sec_r001603_13_1 != sec_r001603_13_2);
  __CPROVER_assume(sec_r001603_20_1 != sec_r001603_20_2);
  __CPROVER_assume(sec_r001603_1_1 != sec_r001603_1_2);
  __CPROVER_assume(sec_r001603_3_1 != sec_r001603_3_2);
  __CPROVER_assume(sec_r001603_0_1 != sec_r001603_0_2);
  __CPROVER_assume(sec_r001603_5_1 != sec_r001603_5_2);
  __CPROVER_assume(pub_r001603_2_1 == pub_r001603_2_2);
  __CPROVER_assume(sec_r001603_2_1 != sec_r001603_2_2);
  __CPROVER_assume(sec_r001603_4_1 != sec_r001603_4_2);
  __CPROVER_assume(sec_r001603_8_1 != sec_r001603_8_2);
  __CPROVER_assume(pub_r001603_7_1 == pub_r001603_7_2);
  __CPROVER_assume(sec_r001603_19_1 != sec_r001603_19_2);
  __CPROVER_assume(pub_r001603_4_1 == pub_r001603_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.status == st_var_0_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
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
}


