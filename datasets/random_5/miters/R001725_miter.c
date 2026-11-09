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
struct SensorNode_R001725_2513_0
{
  unsigned char threshold;
  int calib;
  short status;
  int buffer[3];
};
struct MatrixBlock_R001725_2513_1
{
  int density;
  unsigned char trace;
  unsigned char scale;
  int dim;
  unsigned char determinant;
  int stride;
  int buffer[3];
};
struct EventLog_R001725_2513_2
{
  short seq;
  short facility;
  int signature;
  int severity;
  int timestamp;
  int code;
  int buffer[3];
};
union TelemetryField_R001725_2513_0
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
void fn_R001725_2513_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st_1 = {0};
  struct MatrixBlock_R001725_2513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_14_1)
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

  switch (anchor_14_2)
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

  int pivot_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_41_1 > 10)
  {
    acc_1 = ((acc_1 + (pivot_41_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_41_2 > 10)
  {
    acc_2 = ((acc_2 + (pivot_41_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_30_1) & 63;
  aux_2 = (aux_2 + pivot_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_14_1 == anchor_14_2);
  assert(pivot_41_1 == pivot_41_2);
  assert(pivot_30_1 == pivot_30_2);
}

int fn_R001725_2513_0(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_14 = (aux + st.buffer[1]) & 3;
  switch (anchor_14)
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

  int pivot_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_41 > 10)
  {
    acc = ((acc + (pivot_41 * 2)) + 5) & 127;
    aux ^= pivot_41 & 15;
  }
  else
  {
    acc = ((acc - pivot_41) + 11) & 127;
    aux += 3;
  }
  int pivot_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001725_2513_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st_1 = {0};
  struct MatrixBlock_R001725_2513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_87_1 = local_arr_1[aux_1 % 3];
  int damping_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_87_2 * 2)) & 127;
  int parity_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_43_1) & 63;
  aux_2 = (aux_2 + parity_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_46_1 > 17)
  {
    acc_1 = ((acc_1 + (quotient_46_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_46_2 > 17)
  {
    acc_2 = ((acc_2 + (quotient_46_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_87_1 == damping_87_2);
  assert(parity_43_1 == parity_43_2);
  assert(quotient_46_1 == quotient_46_2);
}

int fn_R001725_2513_1(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int damping_87 = local_arr[aux % 3];
  acc = (acc + (damping_87 * 2)) & 127;
  int parity_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_43) & 63;
  acc ^= aux;
  int quotient_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_46 > 17)
  {
    acc = ((acc + (quotient_46 * 2)) + 5) & 127;
    aux ^= quotient_46 & 15;
  }
  else
  {
    acc = ((acc - quotient_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001725_2513_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st_1 = {0};
  struct EventLog_R001725_2513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int parity_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_92_1) & 63;
  aux_2 = (aux_2 + parity_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_21_1 > 26)
  {
    acc_1 = ((acc_1 + (anchor_21_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_21_2 > 26)
  {
    acc_2 = ((acc_2 + (anchor_21_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_21_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_92_1 == parity_92_2);
  assert(anchor_21_1 == anchor_21_2);
}

int fn_R001725_2513_2(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int parity_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_92) & 63;
  acc ^= aux;
  int anchor_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_21 > 26)
  {
    acc = ((acc + (anchor_21 * 2)) + 5) & 127;
    aux ^= anchor_21 & 15;
  }
  else
  {
    acc = ((acc - anchor_21) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001725_2513_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001725_2513_0 st_1 = {0};
  struct SensorNode_R001725_2513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int pivot_55_1 = 0;
  int pivot_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_55_1 = ((pivot_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_55_2 = ((pivot_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_55_1) & 127;
    acc_2 = (acc_2 + pivot_55_2) & 127;
  }

  int threshold_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_30_1) & 63;
  aux_2 = (aux_2 + threshold_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_55_1 == pivot_55_2);
  assert(threshold_30_1 == threshold_30_2);
}

int fn_R001725_2513_3(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001725_2513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int pivot_55 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_55 = ((pivot_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_55) & 127;
  }

  int threshold_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001725_2513_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st_1 = {0};
  struct EventLog_R001725_2513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int bound_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_23_1)
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

  switch (bound_23_2)
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
  int bound_59_1 = local_arr_1[aux_1 % 3];
  int bound_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_23_1 == bound_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_59_1 == bound_59_2);
}

int fn_R001725_2513_4(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int bound_23 = (aux + st.buffer[1]) & 3;
  switch (bound_23)
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
  int bound_59 = local_arr[aux % 3];
  acc = (acc + (bound_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001725_2513_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001725_2513_0 st_1 = {0};
  struct SensorNode_R001725_2513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int metric_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_65_1)
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

  switch (metric_65_2)
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

  int phase_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_71_1) & 63;
  aux_2 = (aux_2 + phase_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_92_1 > 43)
  {
    acc_1 = ((acc_1 + (scale_92_1 * 2)) + 5) & 127;
    aux_1 ^= scale_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_92_2 > 43)
  {
    acc_2 = ((acc_2 + (scale_92_2 * 2)) + 5) & 127;
    aux_2 ^= scale_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_65_1 == metric_65_2);
  assert(phase_71_1 == phase_71_2);
  assert(scale_92_1 == scale_92_2);
}

int fn_R001725_2513_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001725_2513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int metric_65 = (aux + st.buffer[1]) & 3;
  switch (metric_65)
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

  int phase_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_71) & 63;
  acc ^= aux;
  int scale_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_92 > 43)
  {
    acc = ((acc + (scale_92 * 2)) + 5) & 127;
    aux ^= scale_92 & 15;
  }
  else
  {
    acc = ((acc - scale_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001725_2513_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001725_2513_0 st_1 = {0};
  struct SensorNode_R001725_2513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int factor_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_15_1)
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

  switch (factor_15_2)
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

  int window_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_74_1 > 30)
  {
    acc_1 = ((acc_1 + (window_74_1 * 2)) + 5) & 127;
    aux_1 ^= window_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_74_2 > 30)
  {
    acc_2 = ((acc_2 + (window_74_2 * 2)) + 5) & 127;
    aux_2 ^= window_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_15_1 == factor_15_2);
  assert(window_74_1 == window_74_2);
}

int fn_R001725_2513_6(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001725_2513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int factor_15 = (aux + st.buffer[1]) & 3;
  switch (factor_15)
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

  int window_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_74 > 30)
  {
    acc = ((acc + (window_74 * 2)) + 5) & 127;
    aux ^= window_74 & 15;
  }
  else
  {
    acc = ((acc - window_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001725_2513_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st_1 = {0};
  struct MatrixBlock_R001725_2513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_53_1 = local_arr_1[aux_1 % 3];
  int sample_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_53_2 * 2)) & 127;
  int delta_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_58_1) & 63;
  aux_2 = (aux_2 + delta_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_26_1)
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

  switch (tracker_26_2)
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

  int stride_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_40_1 > 16)
  {
    acc_1 = ((acc_1 + (stride_40_1 * 2)) + 5) & 127;
    aux_1 ^= stride_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_40_2 > 16)
  {
    acc_2 = ((acc_2 + (stride_40_2 * 2)) + 5) & 127;
    aux_2 ^= stride_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_53_1 == sample_53_2);
  assert(delta_58_1 == delta_58_2);
  assert(tracker_26_1 == tracker_26_2);
  assert(stride_40_1 == stride_40_2);
}

int fn_R001725_2513_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int sample_53 = local_arr[aux % 3];
  acc = (acc + (sample_53 * 2)) & 127;
  int delta_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_58) & 63;
  acc ^= aux;
  int tracker_26 = (aux + st.buffer[1]) & 3;
  switch (tracker_26)
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

  int stride_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_40 > 16)
  {
    acc = ((acc + (stride_40 * 2)) + 5) & 127;
    aux ^= stride_40 & 15;
  }
  else
  {
    acc = ((acc - stride_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001725_2513_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st_1 = {0};
  struct EventLog_R001725_2513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int damping_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_93_1 > 32)
  {
    acc_1 = ((acc_1 + (damping_93_1 * 2)) + 5) & 127;
    aux_1 ^= damping_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_93_2 > 32)
  {
    acc_2 = ((acc_2 + (damping_93_2 * 2)) + 5) & 127;
    aux_2 ^= damping_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_93_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_93_1 == damping_93_2);
}

int fn_R001725_2513_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int damping_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_93 > 32)
  {
    acc = ((acc + (damping_93 * 2)) + 5) & 127;
    aux ^= damping_93 & 15;
  }
  else
  {
    acc = ((acc - damping_93) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001725_2513_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001725_2513_0 st_1 = {0};
  struct SensorNode_R001725_2513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int cursor_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_19_1) & 63;
  aux_2 = (aux_2 + cursor_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_62_1 = local_arr_1[aux_1 % 3];
  int index_reg_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_62_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_19_1 == cursor_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_62_1 == index_reg_62_2);
}

int fn_R001725_2513_9(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001725_2513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int cursor_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_19) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_62 = local_arr[aux % 3];
  acc = (acc + (index_reg_62 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001725_2513_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st_1 = {0};
  struct EventLog_R001725_2513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int segment_60_1 = 0;
  int segment_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_60_1 = ((segment_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_60_2 = ((segment_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_60_1) & 127;
    acc_2 = (acc_2 + segment_60_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_91_1 = local_arr_1[aux_1 % 3];
  int sample_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_91_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_60_1 == segment_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_91_1 == sample_91_2);
}

int fn_R001725_2513_10(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int segment_60 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_60 = ((segment_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_60) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int sample_91 = local_arr[aux % 3];
  acc = (acc + (sample_91 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001725_2513_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st_1 = {0};
  struct EventLog_R001725_2513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int sample_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_57_1 > 25)
  {
    acc_1 = ((acc_1 + (sample_57_1 * 2)) + 5) & 127;
    aux_1 ^= sample_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_57_2 > 25)
  {
    acc_2 = ((acc_2 + (sample_57_2 * 2)) + 5) & 127;
    aux_2 ^= sample_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_75_1) & 63;
  aux_2 = (aux_2 + margin_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_57_1 == sample_57_2);
  assert(margin_75_1 == margin_75_2);
}

int fn_R001725_2513_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int sample_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_57 > 25)
  {
    acc = ((acc + (sample_57 * 2)) + 5) & 127;
    aux ^= sample_57 & 15;
  }
  else
  {
    acc = ((acc - sample_57) + 11) & 127;
    aux += 3;
  }
  int margin_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001725_2513_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st_1 = {0};
  struct MatrixBlock_R001725_2513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int metric_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_72_1) & 63;
  aux_2 = (aux_2 + metric_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_37_1 > 11)
  {
    acc_1 = ((acc_1 + (margin_37_1 * 2)) + 5) & 127;
    aux_1 ^= margin_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_37_2 > 11)
  {
    acc_2 = ((acc_2 + (margin_37_2 * 2)) + 5) & 127;
    aux_2 ^= margin_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_61_1 = local_arr_1[aux_1 % 3];
  int scale_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_61_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_72_1 == metric_72_2);
  assert(margin_37_1 == margin_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_61_1 == scale_61_2);
}

int fn_R001725_2513_12(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int metric_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_72) & 63;
  acc ^= aux;
  int margin_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_37 > 11)
  {
    acc = ((acc + (margin_37 * 2)) + 5) & 127;
    aux ^= margin_37 & 15;
  }
  else
  {
    acc = ((acc - margin_37) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int scale_61 = local_arr[aux % 3];
  acc = (acc + (scale_61 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001725_2513_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st_1 = {0};
  struct MatrixBlock_R001725_2513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int damping_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_20_1 > 30)
  {
    acc_1 = ((acc_1 + (damping_20_1 * 2)) + 5) & 127;
    aux_1 ^= damping_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_20_2 > 30)
  {
    acc_2 = ((acc_2 + (damping_20_2 * 2)) + 5) & 127;
    aux_2 ^= damping_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_90_1 = local_arr_1[aux_1 % 3];
  int sample_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_90_2 * 2)) & 127;
  int margin_71_1 = 0;
  int margin_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_71_1 = ((margin_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_71_2 = ((margin_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_71_1) & 127;
    acc_2 = (acc_2 + margin_71_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_20_1 == damping_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_90_1 == sample_90_2);
  assert(margin_71_1 == margin_71_2);
}

int fn_R001725_2513_13(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int damping_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_20 > 30)
  {
    acc = ((acc + (damping_20 * 2)) + 5) & 127;
    aux ^= damping_20 & 15;
  }
  else
  {
    acc = ((acc - damping_20) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_90 = local_arr[aux % 3];
  acc = (acc + (sample_90 * 2)) & 127;
  int margin_71 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_71 = ((margin_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_71) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001725_2513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st_1 = {0};
  struct MatrixBlock_R001725_2513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int scale_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_15_1)
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

  switch (scale_15_2)
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

  int residue_27_1 = 0;
  int residue_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_27_1 = ((residue_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_27_2 = ((residue_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_27_1) & 127;
    acc_2 = (acc_2 + residue_27_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_19_1 = local_arr_1[aux_1 % 3];
  int accumulator_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_19_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_15_1 == scale_15_2);
  assert(residue_27_1 == residue_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_19_1 == accumulator_19_2);
}

int fn_R001725_2513_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int scale_15 = (aux + st.buffer[1]) & 3;
  switch (scale_15)
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

  int residue_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_27 = ((residue_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_27) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int accumulator_19 = local_arr[aux % 3];
  acc = (acc + (accumulator_19 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001725_2513_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001725_2513_0 st_1 = {0};
  struct SensorNode_R001725_2513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_91_1 = local_arr_1[aux_1 % 3];
  int pivot_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_91_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
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

  assert(pivot_91_1 == pivot_91_2);
}

int fn_R001725_2513_15(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001725_2513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_91 = local_arr[aux % 3];
  acc = (acc + (pivot_91 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001725_2513_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st_1 = {0};
  struct MatrixBlock_R001725_2513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int damping_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_93_1 > 28)
  {
    acc_1 = ((acc_1 + (damping_93_1 * 2)) + 5) & 127;
    aux_1 ^= damping_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_93_2 > 28)
  {
    acc_2 = ((acc_2 + (damping_93_2 * 2)) + 5) & 127;
    aux_2 ^= damping_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_70_1) & 63;
  aux_2 = (aux_2 + pivot_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_64_1)
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

  switch (vector_64_2)
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
  int index_reg_31_1 = local_arr_1[aux_1 % 3];
  int index_reg_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_93_1 == damping_93_2);
  assert(pivot_70_1 == pivot_70_2);
  assert(vector_64_1 == vector_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_31_1 == index_reg_31_2);
}

int fn_R001725_2513_16(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int damping_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_93 > 28)
  {
    acc = ((acc + (damping_93 * 2)) + 5) & 127;
    aux ^= damping_93 & 15;
  }
  else
  {
    acc = ((acc - damping_93) + 11) & 127;
    aux += 3;
  }
  int pivot_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_70) & 63;
  acc ^= aux;
  int vector_64 = (aux + st.buffer[1]) & 3;
  switch (vector_64)
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
  int index_reg_31 = local_arr[aux % 3];
  acc = (acc + (index_reg_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001725_2513_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st_1 = {0};
  struct EventLog_R001725_2513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int offset_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_74_1 > 17)
  {
    acc_1 = ((acc_1 + (offset_74_1 * 2)) + 5) & 127;
    aux_1 ^= offset_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_74_2 > 17)
  {
    acc_2 = ((acc_2 + (offset_74_2 * 2)) + 5) & 127;
    aux_2 ^= offset_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_46_1 = 0;
  int parity_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_46_1 = ((parity_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_46_2 = ((parity_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_46_1) & 127;
    acc_2 = (acc_2 + parity_46_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_74_1 == offset_74_2);
  assert(parity_46_1 == parity_46_2);
}

int fn_R001725_2513_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int offset_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_74 > 17)
  {
    acc = ((acc + (offset_74 * 2)) + 5) & 127;
    aux ^= offset_74 & 15;
  }
  else
  {
    acc = ((acc - offset_74) + 11) & 127;
    aux += 3;
  }
  int parity_46 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_46 = ((parity_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_46) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001725_2513_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st_1 = {0};
  struct MatrixBlock_R001725_2513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int weight_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_95_1) & 63;
  aux_2 = (aux_2 + weight_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_84_1)
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

  switch (delta_84_2)
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

  int delta_91_1 = 0;
  int delta_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_91_1 = ((delta_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_91_2 = ((delta_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_91_1) & 127;
    acc_2 = (acc_2 + delta_91_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_21_1 = local_arr_1[aux_1 % 3];
  int cursor_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_95_1 == weight_95_2);
  assert(delta_84_1 == delta_84_2);
  assert(delta_91_1 == delta_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_21_1 == cursor_21_2);
}

int fn_R001725_2513_18(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int weight_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_95) & 63;
  acc ^= aux;
  int delta_84 = (aux + st.buffer[1]) & 3;
  switch (delta_84)
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

  int delta_91 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_91 = ((delta_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_91) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int cursor_21 = local_arr[aux % 3];
  acc = (acc + (cursor_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001725_2513_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001725_2513_0 st_1 = {0};
  struct SensorNode_R001725_2513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int weight_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_43_1) & 63;
  aux_2 = (aux_2 + weight_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_87_1)
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

  switch (segment_87_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_43_1 == weight_43_2);
  assert(segment_87_1 == segment_87_2);
}

int fn_R001725_2513_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001725_2513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int weight_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_43) & 63;
  acc ^= aux;
  int segment_87 = (aux + st.buffer[1]) & 3;
  switch (segment_87)
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

void fn_R001725_2513_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st_1 = {0};
  struct MatrixBlock_R001725_2513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int phase_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_24_1)
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

  switch (phase_24_2)
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

  int weight_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_46_1) & 63;
  aux_2 = (aux_2 + weight_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_30_1 > 11)
  {
    acc_1 = ((acc_1 + (tracker_30_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_30_2 > 11)
  {
    acc_2 = ((acc_2 + (tracker_30_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_16_1 = local_arr_1[aux_1 % 3];
  int quantum_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_16_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_24_1 == phase_24_2);
  assert(weight_46_1 == weight_46_2);
  assert(tracker_30_1 == tracker_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_16_1 == quantum_16_2);
}

int fn_R001725_2513_20(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001725_2513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int phase_24 = (aux + st.buffer[1]) & 3;
  switch (phase_24)
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

  int weight_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_46) & 63;
  acc ^= aux;
  int tracker_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_30 > 11)
  {
    acc = ((acc + (tracker_30 * 2)) + 5) & 127;
    aux ^= tracker_30 & 15;
  }
  else
  {
    acc = ((acc - tracker_30) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_16 = local_arr[aux % 3];
  acc = (acc + (quantum_16 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001725_2513_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st_1 = {0};
  struct EventLog_R001725_2513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_97_1) & 63;
  aux_2 = (aux_2 + margin_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_41_1 > 15)
  {
    acc_1 = ((acc_1 + (quantum_41_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_41_2 > 15)
  {
    acc_2 = ((acc_2 + (quantum_41_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_41_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_97_1 == margin_97_2);
  assert(quantum_41_1 == quantum_41_2);
}

int fn_R001725_2513_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001725_2513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_97) & 63;
  acc ^= aux;
  int quantum_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_41 > 15)
  {
    acc = ((acc + (quantum_41 * 2)) + 5) & 127;
    aux ^= quantum_41 & 15;
  }
  else
  {
    acc = ((acc - quantum_41) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001725_0_1;
  int sec_r001725_0_2;
  int sec_r001725_1_1;
  int sec_r001725_1_2;
  int sec_r001725_2_1;
  int sec_r001725_2_2;
  int sec_r001725_3_1;
  int sec_r001725_3_2;
  int sec_r001725_4_1;
  int sec_r001725_4_2;
  int sec_r001725_5_1;
  int sec_r001725_5_2;
  int sec_r001725_6_1;
  int sec_r001725_6_2;
  int sec_r001725_7_1;
  int sec_r001725_7_2;
  int sec_r001725_8_1;
  int sec_r001725_8_2;
  int sec_r001725_9_1;
  int sec_r001725_9_2;
  int sec_r001725_10_1;
  int sec_r001725_10_2;
  int sec_r001725_11_1;
  int sec_r001725_11_2;
  int sec_r001725_12_1;
  int sec_r001725_12_2;
  int sec_r001725_13_1;
  int sec_r001725_13_2;
  int sec_r001725_14_1;
  int sec_r001725_14_2;
  int sec_r001725_15_1;
  int sec_r001725_15_2;
  int sec_r001725_16_1;
  int sec_r001725_16_2;
  int sec_r001725_17_1;
  int sec_r001725_17_2;
  int sec_r001725_18_1;
  int sec_r001725_18_2;
  int sec_r001725_19_1;
  int sec_r001725_19_2;
  int pub_r001725_0_1;
  int pub_r001725_0_2;
  int pub_r001725_1_1;
  int pub_r001725_1_2;
  int pub_r001725_2_1;
  int pub_r001725_2_2;
  int pub_r001725_3_1;
  int pub_r001725_3_2;
  int pub_r001725_4_1;
  int pub_r001725_4_2;
  int pub_r001725_5_1;
  int pub_r001725_5_2;
  int pub_r001725_6_1;
  int pub_r001725_6_2;
  int pub_r001725_7_1;
  int pub_r001725_7_2;
  int pub_r001725_8_1;
  int pub_r001725_8_2;
  int pub_r001725_9_1;
  int pub_r001725_9_2;
  int pub_r001725_10_1;
  int pub_r001725_10_2;
  int pub_r001725_11_1;
  int pub_r001725_11_2;
  int pub_r001725_12_1;
  int pub_r001725_12_2;
  int pub_r001725_13_1;
  int pub_r001725_13_2;
  int pub_r001725_14_1;
  int pub_r001725_14_2;
  int pub_r001725_15_1;
  int pub_r001725_15_2;
  int pub_r001725_16_1;
  int pub_r001725_16_2;
  int pub_r001725_17_1;
  int pub_r001725_17_2;
  int pub_r001725_18_1;
  int pub_r001725_18_2;
  int pub_r001725_19_1;
  int pub_r001725_19_2;
  int pub_r001725_20_1;
  int pub_r001725_20_2;
  int pub_r001725_21_1;
  int pub_r001725_21_2;
  int pub_r001725_22_1;
  int pub_r001725_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001725_0_1 >= (-100)) && (pub_r001725_0_1 <= 100));
  __CPROVER_assume((pub_r001725_0_2 >= (-100)) && (pub_r001725_0_2 <= 100));
  __CPROVER_assume((pub_r001725_1_1 >= (-100)) && (pub_r001725_1_1 <= 100));
  __CPROVER_assume((pub_r001725_1_2 >= (-100)) && (pub_r001725_1_2 <= 100));
  __CPROVER_assume((pub_r001725_2_1 >= (-100)) && (pub_r001725_2_1 <= 100));
  __CPROVER_assume((pub_r001725_2_2 >= (-100)) && (pub_r001725_2_2 <= 100));
  __CPROVER_assume((pub_r001725_3_1 >= (-100)) && (pub_r001725_3_1 <= 100));
  __CPROVER_assume((pub_r001725_3_2 >= (-100)) && (pub_r001725_3_2 <= 100));
  __CPROVER_assume((pub_r001725_4_1 >= (-100)) && (pub_r001725_4_1 <= 100));
  __CPROVER_assume((pub_r001725_4_2 >= (-100)) && (pub_r001725_4_2 <= 100));
  __CPROVER_assume((pub_r001725_5_1 >= (-100)) && (pub_r001725_5_1 <= 100));
  __CPROVER_assume((pub_r001725_5_2 >= (-100)) && (pub_r001725_5_2 <= 100));
  __CPROVER_assume((pub_r001725_6_1 >= (-100)) && (pub_r001725_6_1 <= 100));
  __CPROVER_assume((pub_r001725_6_2 >= (-100)) && (pub_r001725_6_2 <= 100));
  __CPROVER_assume((pub_r001725_7_1 >= (-100)) && (pub_r001725_7_1 <= 100));
  __CPROVER_assume((pub_r001725_7_2 >= (-100)) && (pub_r001725_7_2 <= 100));
  __CPROVER_assume((pub_r001725_8_1 >= (-100)) && (pub_r001725_8_1 <= 100));
  __CPROVER_assume((pub_r001725_8_2 >= (-100)) && (pub_r001725_8_2 <= 100));
  __CPROVER_assume((pub_r001725_9_1 >= (-100)) && (pub_r001725_9_1 <= 100));
  __CPROVER_assume((pub_r001725_9_2 >= (-100)) && (pub_r001725_9_2 <= 100));
  __CPROVER_assume((pub_r001725_10_1 >= (-100)) && (pub_r001725_10_1 <= 100));
  __CPROVER_assume((pub_r001725_10_2 >= (-100)) && (pub_r001725_10_2 <= 100));
  __CPROVER_assume((pub_r001725_11_1 >= (-100)) && (pub_r001725_11_1 <= 100));
  __CPROVER_assume((pub_r001725_11_2 >= (-100)) && (pub_r001725_11_2 <= 100));
  __CPROVER_assume((pub_r001725_12_1 >= (-100)) && (pub_r001725_12_1 <= 100));
  __CPROVER_assume((pub_r001725_12_2 >= (-100)) && (pub_r001725_12_2 <= 100));
  __CPROVER_assume((pub_r001725_13_1 >= (-100)) && (pub_r001725_13_1 <= 100));
  __CPROVER_assume((pub_r001725_13_2 >= (-100)) && (pub_r001725_13_2 <= 100));
  __CPROVER_assume((pub_r001725_14_1 >= (-100)) && (pub_r001725_14_1 <= 100));
  __CPROVER_assume((pub_r001725_14_2 >= (-100)) && (pub_r001725_14_2 <= 100));
  __CPROVER_assume((pub_r001725_15_1 >= (-100)) && (pub_r001725_15_1 <= 100));
  __CPROVER_assume((pub_r001725_15_2 >= (-100)) && (pub_r001725_15_2 <= 100));
  __CPROVER_assume((pub_r001725_16_1 >= (-100)) && (pub_r001725_16_1 <= 100));
  __CPROVER_assume((pub_r001725_16_2 >= (-100)) && (pub_r001725_16_2 <= 100));
  __CPROVER_assume((pub_r001725_17_1 >= (-100)) && (pub_r001725_17_1 <= 100));
  __CPROVER_assume((pub_r001725_17_2 >= (-100)) && (pub_r001725_17_2 <= 100));
  __CPROVER_assume((pub_r001725_18_1 >= (-100)) && (pub_r001725_18_1 <= 100));
  __CPROVER_assume((pub_r001725_18_2 >= (-100)) && (pub_r001725_18_2 <= 100));
  __CPROVER_assume((pub_r001725_19_1 >= (-100)) && (pub_r001725_19_1 <= 100));
  __CPROVER_assume((pub_r001725_19_2 >= (-100)) && (pub_r001725_19_2 <= 100));
  __CPROVER_assume((pub_r001725_20_1 >= (-100)) && (pub_r001725_20_1 <= 100));
  __CPROVER_assume((pub_r001725_20_2 >= (-100)) && (pub_r001725_20_2 <= 100));
  __CPROVER_assume((pub_r001725_21_1 >= (-100)) && (pub_r001725_21_1 <= 100));
  __CPROVER_assume((pub_r001725_21_2 >= (-100)) && (pub_r001725_21_2 <= 100));
  __CPROVER_assume((pub_r001725_22_1 >= (-100)) && (pub_r001725_22_1 <= 100));
  __CPROVER_assume((pub_r001725_22_2 >= (-100)) && (pub_r001725_22_2 <= 100));
  __CPROVER_assume((sec_r001725_0_1 >= 0) && (sec_r001725_0_1 <= 255));
  __CPROVER_assume((sec_r001725_0_2 >= 0) && (sec_r001725_0_2 <= 255));
  __CPROVER_assume((sec_r001725_1_1 >= 0) && (sec_r001725_1_1 <= 255));
  __CPROVER_assume((sec_r001725_1_2 >= 0) && (sec_r001725_1_2 <= 255));
  __CPROVER_assume((sec_r001725_2_1 >= 0) && (sec_r001725_2_1 <= 255));
  __CPROVER_assume((sec_r001725_2_2 >= 0) && (sec_r001725_2_2 <= 255));
  __CPROVER_assume((sec_r001725_3_1 >= 0) && (sec_r001725_3_1 <= 255));
  __CPROVER_assume((sec_r001725_3_2 >= 0) && (sec_r001725_3_2 <= 255));
  __CPROVER_assume((sec_r001725_4_1 >= 0) && (sec_r001725_4_1 <= 255));
  __CPROVER_assume((sec_r001725_4_2 >= 0) && (sec_r001725_4_2 <= 255));
  __CPROVER_assume((sec_r001725_5_1 >= 0) && (sec_r001725_5_1 <= 255));
  __CPROVER_assume((sec_r001725_5_2 >= 0) && (sec_r001725_5_2 <= 255));
  __CPROVER_assume((sec_r001725_6_1 >= 0) && (sec_r001725_6_1 <= 255));
  __CPROVER_assume((sec_r001725_6_2 >= 0) && (sec_r001725_6_2 <= 255));
  __CPROVER_assume((sec_r001725_7_1 >= 0) && (sec_r001725_7_1 <= 255));
  __CPROVER_assume((sec_r001725_7_2 >= 0) && (sec_r001725_7_2 <= 255));
  __CPROVER_assume((sec_r001725_8_1 >= 0) && (sec_r001725_8_1 <= 255));
  __CPROVER_assume((sec_r001725_8_2 >= 0) && (sec_r001725_8_2 <= 255));
  __CPROVER_assume((sec_r001725_9_1 >= 0) && (sec_r001725_9_1 <= 255));
  __CPROVER_assume((sec_r001725_9_2 >= 0) && (sec_r001725_9_2 <= 255));
  __CPROVER_assume((sec_r001725_10_1 >= 0) && (sec_r001725_10_1 <= 255));
  __CPROVER_assume((sec_r001725_10_2 >= 0) && (sec_r001725_10_2 <= 255));
  __CPROVER_assume((sec_r001725_11_1 >= 0) && (sec_r001725_11_1 <= 255));
  __CPROVER_assume((sec_r001725_11_2 >= 0) && (sec_r001725_11_2 <= 255));
  __CPROVER_assume((sec_r001725_12_1 >= 0) && (sec_r001725_12_1 <= 255));
  __CPROVER_assume((sec_r001725_12_2 >= 0) && (sec_r001725_12_2 <= 255));
  __CPROVER_assume((sec_r001725_13_1 >= 0) && (sec_r001725_13_1 <= 255));
  __CPROVER_assume((sec_r001725_13_2 >= 0) && (sec_r001725_13_2 <= 255));
  __CPROVER_assume((sec_r001725_14_1 >= 0) && (sec_r001725_14_1 <= 255));
  __CPROVER_assume((sec_r001725_14_2 >= 0) && (sec_r001725_14_2 <= 255));
  __CPROVER_assume((sec_r001725_15_1 >= 0) && (sec_r001725_15_1 <= 255));
  __CPROVER_assume((sec_r001725_15_2 >= 0) && (sec_r001725_15_2 <= 255));
  __CPROVER_assume((sec_r001725_16_1 >= 0) && (sec_r001725_16_1 <= 255));
  __CPROVER_assume((sec_r001725_16_2 >= 0) && (sec_r001725_16_2 <= 255));
  __CPROVER_assume((sec_r001725_17_1 >= 0) && (sec_r001725_17_1 <= 255));
  __CPROVER_assume((sec_r001725_17_2 >= 0) && (sec_r001725_17_2 <= 255));
  __CPROVER_assume((sec_r001725_18_1 >= 0) && (sec_r001725_18_1 <= 255));
  __CPROVER_assume((sec_r001725_18_2 >= 0) && (sec_r001725_18_2 <= 255));
  __CPROVER_assume((sec_r001725_19_1 >= 0) && (sec_r001725_19_1 <= 255));
  __CPROVER_assume((sec_r001725_19_2 >= 0) && (sec_r001725_19_2 <= 255));
  struct SensorNode_R001725_2513_0 st_var_0_1 = {0};
  struct SensorNode_R001725_2513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001725_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001725_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001725_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001725_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001725_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001725_0_2 + 7) & 15;
  struct MatrixBlock_R001725_2513_1 st_var_1_1 = {0};
  struct MatrixBlock_R001725_2513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001725_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001725_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001725_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001725_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001725_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001725_0_2 + 9) & 15;
  struct EventLog_R001725_2513_2 st_var_2_1 = {0};
  struct EventLog_R001725_2513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001725_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001725_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001725_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001725_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001725_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001725_0_2 + 11) & 15;
  union TelemetryField_R001725_2513_0 u_var_1;
  union TelemetryField_R001725_2513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001725_2513_0(sec_r001725_0_1, pub_r001725_1_1, pub_r001725_2_1);
  int helper_flow_0_2 = fn_R001725_2513_0(sec_r001725_0_2, pub_r001725_1_2, pub_r001725_2_2);
  fn_R001725_2513_0_2(sec_r001725_0_1, pub_r001725_1_1, pub_r001725_2_1, sec_r001725_0_2, pub_r001725_1_2, pub_r001725_2_2);
  int helper_flow_1_1 = fn_R001725_2513_1(sec_r001725_1_1, pub_r001725_2_1, pub_r001725_3_1);
  int helper_flow_1_2 = fn_R001725_2513_1(sec_r001725_1_2, pub_r001725_2_2, pub_r001725_3_2);
  fn_R001725_2513_1_2(sec_r001725_1_1, pub_r001725_2_1, pub_r001725_3_1, sec_r001725_1_2, pub_r001725_2_2, pub_r001725_3_2);
  int helper_flow_2_1 = fn_R001725_2513_2(sec_r001725_2_1, sec_r001725_3_1);
  int helper_flow_2_2 = fn_R001725_2513_2(sec_r001725_2_2, sec_r001725_3_2);
  fn_R001725_2513_2_2(sec_r001725_2_1, sec_r001725_3_1, sec_r001725_2_2, sec_r001725_3_2);
  int helper_flow_3_1 = fn_R001725_2513_3(sec_r001725_3_1, sec_r001725_4_1);
  int helper_flow_3_2 = fn_R001725_2513_3(sec_r001725_3_2, sec_r001725_4_2);
  fn_R001725_2513_3_2(sec_r001725_3_1, sec_r001725_4_1, sec_r001725_3_2, sec_r001725_4_2);
  int helper_flow_4_1 = fn_R001725_2513_4(sec_r001725_4_1, sec_r001725_5_1, pub_r001725_6_1);
  int helper_flow_4_2 = fn_R001725_2513_4(sec_r001725_4_2, sec_r001725_5_2, pub_r001725_6_2);
  fn_R001725_2513_4_2(sec_r001725_4_1, sec_r001725_5_1, pub_r001725_6_1, sec_r001725_4_2, sec_r001725_5_2, pub_r001725_6_2);
  int helper_flow_5_1 = fn_R001725_2513_5(sec_r001725_5_1, sec_r001725_6_1, pub_r001725_7_1, pub_r001725_8_1);
  int helper_flow_5_2 = fn_R001725_2513_5(sec_r001725_5_2, sec_r001725_6_2, pub_r001725_7_2, pub_r001725_8_2);
  fn_R001725_2513_5_2(sec_r001725_5_1, sec_r001725_6_1, pub_r001725_7_1, pub_r001725_8_1, sec_r001725_5_2, sec_r001725_6_2, pub_r001725_7_2, pub_r001725_8_2);
  int helper_flow_6_1 = fn_R001725_2513_6(sec_r001725_6_1, sec_r001725_7_1);
  int helper_flow_6_2 = fn_R001725_2513_6(sec_r001725_6_2, sec_r001725_7_2);
  fn_R001725_2513_6_2(sec_r001725_6_1, sec_r001725_7_1, sec_r001725_6_2, sec_r001725_7_2);
  int stage_v_0_1 = ((sec_r001725_14_1 << 1) ^ (pub_r001725_0_1 >> 1)) & 127;
  int stage_v_0_2 = ((sec_r001725_14_2 << 1) ^ (pub_r001725_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_0_2 + 1) & 15;
  out_sink_1 ^= stage_v_0_1 & 63;
  out_sink_2 ^= stage_v_0_2 & 63;
  int stage_v_1_1 = ((sec_r001725_17_1 << 1) ^ (pub_r001725_6_1 >> 1)) & 127;
  int stage_v_1_2 = ((sec_r001725_17_2 << 1) ^ (pub_r001725_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_1_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_1_2 + 1) & 15;
  out_sink_1 ^= stage_v_1_1 & 63;
  out_sink_2 ^= stage_v_1_2 & 63;
  int stage_v_2_1 = ((pub_r001725_12_1 * 2) + 27) & 63;
  int stage_v_2_2 = ((pub_r001725_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001725_12_1 * 2) + 13) & 63;
  int stage_v_3_2 = ((pub_r001725_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001725_19_1 * 2) + 44) & 63;
  int stage_v_4_2 = ((pub_r001725_19_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((helper_flow_1_1 << 1) ^ (pub_r001725_18_1 >> 1)) & 127;
  int stage_v_5_2 = ((helper_flow_1_2 << 1) ^ (pub_r001725_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_5_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_5_2 + 1) & 15;
  out_sink_1 ^= stage_v_5_1 & 63;
  out_sink_2 ^= stage_v_5_2 & 63;
  int stage_v_6_1 = ((sec_r001725_1_1 << 1) ^ (pub_r001725_19_1 >> 1)) & 127;
  int stage_v_6_2 = ((sec_r001725_1_2 << 1) ^ (pub_r001725_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_6_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_6_2 + 1) & 15;
  out_sink_1 ^= stage_v_6_1 & 63;
  out_sink_2 ^= stage_v_6_2 & 63;
  int stage_v_7_1 = ((sec_r001725_2_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_7_2 = ((sec_r001725_2_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_7_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_7_2 + 1) & 15;
  out_sink_1 ^= stage_v_7_1 & 63;
  out_sink_2 ^= stage_v_7_2 & 63;
  int stage_v_8_1 = ((stage_v_7_1 << 1) ^ (pub_r001725_18_1 >> 1)) & 127;
  int stage_v_8_2 = ((stage_v_7_2 << 1) ^ (pub_r001725_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_8_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_8_2 + 1) & 15;
  out_sink_1 ^= stage_v_8_1 & 63;
  out_sink_2 ^= stage_v_8_2 & 63;
  int stage_v_9_1 = ((pub_r001725_16_1 * 2) + 44) & 63;
  int stage_v_9_2 = ((pub_r001725_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((stage_v_6_1 << 1) ^ (pub_r001725_1_1 >> 1)) & 127;
  int stage_v_10_2 = ((stage_v_6_2 << 1) ^ (pub_r001725_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_10_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_10_2 + 1) & 15;
  out_sink_1 ^= stage_v_10_1 & 63;
  out_sink_2 ^= stage_v_10_2 & 63;
  int stage_v_11_1 = ((helper_flow_2_1 << 1) ^ (pub_r001725_12_1 >> 1)) & 127;
  int stage_v_11_2 = ((helper_flow_2_2 << 1) ^ (pub_r001725_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_11_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_11_2 + 1) & 15;
  out_sink_1 ^= stage_v_11_1 & 63;
  out_sink_2 ^= stage_v_11_2 & 63;
  int stage_v_12_1 = ((pub_r001725_16_1 * 2) + 29) & 63;
  int stage_v_12_2 = ((pub_r001725_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001725_10_1 * 2) + 9) & 63;
  int stage_v_13_2 = ((pub_r001725_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((sec_r001725_16_1 << 1) ^ (pub_r001725_18_1 >> 1)) & 127;
  int stage_v_14_2 = ((sec_r001725_16_2 << 1) ^ (pub_r001725_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((helper_flow_6_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_15_2 = ((helper_flow_6_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_15_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_15_2 + 1) & 15;
  out_sink_1 ^= stage_v_15_1 & 63;
  out_sink_2 ^= stage_v_15_2 & 63;
  int stage_v_16_1 = ((helper_flow_2_1 << 1) ^ (pub_r001725_19_1 >> 1)) & 127;
  int stage_v_16_2 = ((helper_flow_2_2 << 1) ^ (pub_r001725_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_16_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_16_2 + 1) & 15;
  out_sink_1 ^= stage_v_16_1 & 63;
  out_sink_2 ^= stage_v_16_2 & 63;
  int stage_v_17_1 = ((helper_flow_6_1 << 1) ^ (pub_r001725_1_1 >> 1)) & 127;
  int stage_v_17_2 = ((helper_flow_6_2 << 1) ^ (pub_r001725_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_17_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_17_2 + 1) & 15;
  out_sink_1 ^= stage_v_17_1 & 63;
  out_sink_2 ^= stage_v_17_2 & 63;
  int stage_v_18_1 = ((sec_r001725_14_1 << 1) ^ (pub_r001725_0_1 >> 1)) & 127;
  int stage_v_18_2 = ((sec_r001725_14_2 << 1) ^ (pub_r001725_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_18_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_18_2 + 1) & 15;
  out_sink_1 ^= stage_v_18_1 & 63;
  out_sink_2 ^= stage_v_18_2 & 63;
  int stage_v_19_1 = ((stage_v_14_1 << 1) ^ (pub_r001725_11_1 >> 1)) & 127;
  int stage_v_19_2 = ((stage_v_14_2 << 1) ^ (pub_r001725_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_19_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_19_2 + 1) & 15;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = ((sec_r001725_19_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_20_2 = ((sec_r001725_19_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((pub_r001725_7_1 * 2) + 45) & 63;
  int stage_v_21_2 = ((pub_r001725_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001725_17_1 * 2) + 12) & 63;
  int stage_v_22_2 = ((pub_r001725_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((sec_r001725_14_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_23_2 = ((sec_r001725_14_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((sec_r001725_19_1 << 1) ^ (pub_r001725_6_1 >> 1)) & 127;
  int stage_v_24_2 = ((sec_r001725_19_2 << 1) ^ (pub_r001725_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_24_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_24_2 + 1) & 15;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = ((pub_r001725_14_1 * 2) + 26) & 63;
  int stage_v_25_2 = ((pub_r001725_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001725_21_1 * 2) + 41) & 63;
  int stage_v_26_2 = ((pub_r001725_21_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001725_6_1 * 2) + 37) & 63;
  int stage_v_27_2 = ((pub_r001725_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((helper_flow_1_1 << 1) ^ (pub_r001725_22_1 >> 1)) & 127;
  int stage_v_28_2 = ((helper_flow_1_2 << 1) ^ (pub_r001725_22_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_28_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_28_2 + 1) & 15;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = ((stage_v_5_1 << 1) ^ (pub_r001725_9_1 >> 1)) & 127;
  int stage_v_29_2 = ((stage_v_5_2 << 1) ^ (pub_r001725_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_29_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_29_2 + 1) & 15;
  out_sink_1 ^= stage_v_29_1 & 63;
  out_sink_2 ^= stage_v_29_2 & 63;
  int stage_v_30_1 = ((helper_flow_0_1 << 1) ^ (pub_r001725_11_1 >> 1)) & 127;
  int stage_v_30_2 = ((helper_flow_0_2 << 1) ^ (pub_r001725_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_30_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_30_2 + 1) & 15;
  out_sink_1 ^= stage_v_30_1 & 63;
  out_sink_2 ^= stage_v_30_2 & 63;
  int stage_v_31_1 = ((sec_r001725_2_1 << 1) ^ (pub_r001725_1_1 >> 1)) & 127;
  int stage_v_31_2 = ((sec_r001725_2_2 << 1) ^ (pub_r001725_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_31_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_31_2 + 1) & 15;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = ((pub_r001725_13_1 * 2) + 9) & 63;
  int stage_v_32_2 = ((pub_r001725_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((sec_r001725_14_1 << 1) ^ (pub_r001725_5_1 >> 1)) & 127;
  int stage_v_33_2 = ((sec_r001725_14_2 << 1) ^ (pub_r001725_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_33_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_33_2 + 1) & 15;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = ((pub_r001725_5_1 * 2) + 33) & 63;
  int stage_v_34_2 = ((pub_r001725_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((sec_r001725_17_1 << 1) ^ (pub_r001725_3_1 >> 1)) & 127;
  int stage_v_35_2 = ((sec_r001725_17_2 << 1) ^ (pub_r001725_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_35_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_35_2 + 1) & 15;
  out_sink_1 ^= stage_v_35_1 & 63;
  out_sink_2 ^= stage_v_35_2 & 63;
  int stage_v_36_1 = ((pub_r001725_16_1 * 2) + 47) & 63;
  int stage_v_36_2 = ((pub_r001725_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((sec_r001725_10_1 << 1) ^ (pub_r001725_10_1 >> 1)) & 127;
  int stage_v_37_2 = ((sec_r001725_10_2 << 1) ^ (pub_r001725_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_37_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_37_2 + 1) & 15;
  out_sink_1 ^= stage_v_37_1 & 63;
  out_sink_2 ^= stage_v_37_2 & 63;
  int stage_v_38_1 = ((sec_r001725_2_1 << 1) ^ (pub_r001725_1_1 >> 1)) & 127;
  int stage_v_38_2 = ((sec_r001725_2_2 << 1) ^ (pub_r001725_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_38_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_38_2 + 1) & 15;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = ((stage_v_6_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_39_2 = ((stage_v_6_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_39_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_39_2 + 1) & 15;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = ((pub_r001725_11_1 * 2) + 29) & 63;
  int stage_v_40_2 = ((pub_r001725_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001725_0_1 * 2) + 37) & 63;
  int stage_v_41_2 = ((pub_r001725_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001725_9_1 * 2) + 19) & 63;
  int stage_v_42_2 = ((pub_r001725_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001725_22_1 * 2) + 45) & 63;
  int stage_v_43_2 = ((pub_r001725_22_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001725_2_1 * 2) + 47) & 63;
  int stage_v_44_2 = ((pub_r001725_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((stage_v_16_1 << 1) ^ (pub_r001725_9_1 >> 1)) & 127;
  int stage_v_45_2 = ((stage_v_16_2 << 1) ^ (pub_r001725_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_45_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_45_2 + 1) & 15;
  out_sink_1 ^= stage_v_45_1 & 63;
  out_sink_2 ^= stage_v_45_2 & 63;
  int stage_v_46_1 = ((pub_r001725_0_1 * 2) + 28) & 63;
  int stage_v_46_2 = ((pub_r001725_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((helper_flow_4_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_47_2 = ((helper_flow_4_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_47_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_47_2 + 1) & 15;
  out_sink_1 ^= stage_v_47_1 & 63;
  out_sink_2 ^= stage_v_47_2 & 63;
  int stage_v_48_1 = ((pub_r001725_16_1 * 2) + 37) & 63;
  int stage_v_48_2 = ((pub_r001725_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((stage_v_39_1 << 1) ^ (pub_r001725_5_1 >> 1)) & 127;
  int stage_v_49_2 = ((stage_v_39_2 << 1) ^ (pub_r001725_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_49_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_49_2 + 1) & 15;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = ((pub_r001725_7_1 * 2) + 8) & 63;
  int stage_v_50_2 = ((pub_r001725_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((stage_v_49_1 << 1) ^ (pub_r001725_17_1 >> 1)) & 127;
  int stage_v_51_2 = ((stage_v_49_2 << 1) ^ (pub_r001725_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_51_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_51_2 + 1) & 15;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = ((sec_r001725_0_1 << 1) ^ (pub_r001725_11_1 >> 1)) & 127;
  int stage_v_52_2 = ((sec_r001725_0_2 << 1) ^ (pub_r001725_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_52_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_52_2 + 1) & 15;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = ((stage_v_38_1 << 1) ^ (pub_r001725_22_1 >> 1)) & 127;
  int stage_v_53_2 = ((stage_v_38_2 << 1) ^ (pub_r001725_22_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_53_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_53_2 + 1) & 15;
  out_sink_1 ^= stage_v_53_1 & 63;
  out_sink_2 ^= stage_v_53_2 & 63;
  int stage_v_54_1 = ((sec_r001725_11_1 << 1) ^ (pub_r001725_19_1 >> 1)) & 127;
  int stage_v_54_2 = ((sec_r001725_11_2 << 1) ^ (pub_r001725_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_54_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_54_2 + 1) & 15;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = ((helper_flow_0_1 << 1) ^ (pub_r001725_4_1 >> 1)) & 127;
  int stage_v_55_2 = ((helper_flow_0_2 << 1) ^ (pub_r001725_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_55_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_55_2 + 1) & 15;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = ((pub_r001725_0_1 * 2) + 34) & 63;
  int stage_v_56_2 = ((pub_r001725_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001725_5_1 * 2) + 15) & 63;
  int stage_v_57_2 = ((pub_r001725_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((stage_v_38_1 << 1) ^ (pub_r001725_11_1 >> 1)) & 127;
  int stage_v_58_2 = ((stage_v_38_2 << 1) ^ (pub_r001725_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_58_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_58_2 + 1) & 15;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = ((stage_v_49_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_59_2 = ((stage_v_49_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_59_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_59_2 + 1) & 15;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = ((stage_v_49_1 << 1) ^ (pub_r001725_18_1 >> 1)) & 127;
  int stage_v_60_2 = ((stage_v_49_2 << 1) ^ (pub_r001725_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_60_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_60_2 + 1) & 15;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = ((helper_flow_1_1 << 1) ^ (pub_r001725_0_1 >> 1)) & 127;
  int stage_v_61_2 = ((helper_flow_1_2 << 1) ^ (pub_r001725_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((stage_v_0_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_62_2 = ((stage_v_0_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_62_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_62_2 + 1) & 15;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = ((sec_r001725_3_1 << 1) ^ (pub_r001725_0_1 >> 1)) & 127;
  int stage_v_63_2 = ((sec_r001725_3_2 << 1) ^ (pub_r001725_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_63_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_63_2 + 1) & 15;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = ((pub_r001725_0_1 * 2) + 36) & 63;
  int stage_v_64_2 = ((pub_r001725_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((stage_v_16_1 << 1) ^ (pub_r001725_1_1 >> 1)) & 127;
  int stage_v_65_2 = ((stage_v_16_2 << 1) ^ (pub_r001725_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_65_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_65_2 + 1) & 15;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = ((stage_v_14_1 << 1) ^ (pub_r001725_21_1 >> 1)) & 127;
  int stage_v_66_2 = ((stage_v_14_2 << 1) ^ (pub_r001725_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_66_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_66_2 + 1) & 15;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = ((pub_r001725_10_1 * 2) + 23) & 63;
  int stage_v_67_2 = ((pub_r001725_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001725_11_1 * 2) + 48) & 63;
  int stage_v_68_2 = ((pub_r001725_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((stage_v_30_1 << 1) ^ (pub_r001725_16_1 >> 1)) & 127;
  int stage_v_69_2 = ((stage_v_30_2 << 1) ^ (pub_r001725_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_69_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_69_2 + 1) & 15;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = ((stage_v_69_1 << 1) ^ (pub_r001725_17_1 >> 1)) & 127;
  int stage_v_70_2 = ((stage_v_69_2 << 1) ^ (pub_r001725_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_70_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_70_2 + 1) & 15;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = ((pub_r001725_19_1 * 2) + 12) & 63;
  int stage_v_71_2 = ((pub_r001725_19_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((stage_v_69_1 << 1) ^ (pub_r001725_6_1 >> 1)) & 127;
  int stage_v_72_2 = ((stage_v_69_2 << 1) ^ (pub_r001725_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_72_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_72_2 + 1) & 15;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = ((pub_r001725_19_1 * 2) + 28) & 63;
  int stage_v_73_2 = ((pub_r001725_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001725_13_1 * 2) + 42) & 63;
  int stage_v_74_2 = ((pub_r001725_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001725_3_1 * 2) + 15) & 63;
  int stage_v_75_2 = ((pub_r001725_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((stage_v_63_1 << 1) ^ (pub_r001725_4_1 >> 1)) & 127;
  int stage_v_76_2 = ((stage_v_63_2 << 1) ^ (pub_r001725_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_76_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_76_2 + 1) & 15;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = ((pub_r001725_21_1 * 2) + 43) & 63;
  int stage_v_77_2 = ((pub_r001725_21_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((stage_v_61_1 << 1) ^ (pub_r001725_19_1 >> 1)) & 127;
  int stage_v_78_2 = ((stage_v_61_2 << 1) ^ (pub_r001725_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_78_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_78_2 + 1) & 15;
  out_sink_1 ^= stage_v_78_1 & 63;
  out_sink_2 ^= stage_v_78_2 & 63;
  int stage_v_79_1 = ((sec_r001725_10_1 << 1) ^ (pub_r001725_2_1 >> 1)) & 127;
  int stage_v_79_2 = ((sec_r001725_10_2 << 1) ^ (pub_r001725_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_79_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_79_2 + 1) & 15;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = ((pub_r001725_22_1 * 2) + 11) & 63;
  int stage_v_80_2 = ((pub_r001725_22_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((stage_v_59_1 << 1) ^ (pub_r001725_11_1 >> 1)) & 127;
  int stage_v_81_2 = ((stage_v_59_2 << 1) ^ (pub_r001725_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_81_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_81_2 + 1) & 15;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = ((pub_r001725_2_1 * 2) + 17) & 63;
  int stage_v_82_2 = ((pub_r001725_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((stage_v_70_1 << 1) ^ (pub_r001725_9_1 >> 1)) & 127;
  int stage_v_83_2 = ((stage_v_70_2 << 1) ^ (pub_r001725_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_83_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_83_2 + 1) & 15;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = ((stage_v_30_1 << 1) ^ (pub_r001725_1_1 >> 1)) & 127;
  int stage_v_84_2 = ((stage_v_30_2 << 1) ^ (pub_r001725_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_84_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_84_2 + 1) & 15;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = ((stage_v_69_1 << 1) ^ (pub_r001725_4_1 >> 1)) & 127;
  int stage_v_85_2 = ((stage_v_69_2 << 1) ^ (pub_r001725_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_85_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_85_2 + 1) & 15;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = ((pub_r001725_8_1 * 2) + 13) & 63;
  int stage_v_86_2 = ((pub_r001725_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001725_17_1 * 2) + 8) & 63;
  int stage_v_87_2 = ((pub_r001725_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001725_18_1 * 2) + 43) & 63;
  int stage_v_88_2 = ((pub_r001725_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001725_15_1 * 2) + 5) & 63;
  int stage_v_89_2 = ((pub_r001725_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001725_22_1 * 2) + 47) & 63;
  int stage_v_90_2 = ((pub_r001725_22_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001725_16_1 * 2) + 47) & 63;
  int stage_v_91_2 = ((pub_r001725_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001725_3_1 * 2) + 7) & 63;
  int stage_v_92_2 = ((pub_r001725_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001725_17_1 * 2) + 7) & 63;
  int stage_v_93_2 = ((pub_r001725_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001725_8_1 * 2) + 26) & 63;
  int stage_v_94_2 = ((pub_r001725_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001725_16_1 * 2) + 16) & 63;
  int stage_v_95_2 = ((pub_r001725_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((stage_v_6_1 << 1) ^ (pub_r001725_13_1 >> 1)) & 127;
  int stage_v_96_2 = ((stage_v_6_2 << 1) ^ (pub_r001725_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_96_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_96_2 + 1) & 15;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = ((stage_v_76_1 << 1) ^ (pub_r001725_10_1 >> 1)) & 127;
  int stage_v_97_2 = ((stage_v_76_2 << 1) ^ (pub_r001725_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_97_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_97_2 + 1) & 15;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = ((pub_r001725_19_1 * 2) + 16) & 63;
  int stage_v_98_2 = ((pub_r001725_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001725_11_1 * 2) + 37) & 63;
  int stage_v_99_2 = ((pub_r001725_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((stage_v_76_1 << 1) ^ (pub_r001725_7_1 >> 1)) & 127;
  int stage_v_100_2 = ((stage_v_76_2 << 1) ^ (pub_r001725_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_100_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_100_2 + 1) & 15;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = ((stage_v_65_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_101_2 = ((stage_v_65_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_101_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_101_2 + 1) & 15;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = ((pub_r001725_15_1 * 2) + 21) & 63;
  int stage_v_102_2 = ((pub_r001725_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001725_12_1 * 2) + 12) & 63;
  int stage_v_103_2 = ((pub_r001725_12_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001725_11_1 * 2) + 34) & 63;
  int stage_v_104_2 = ((pub_r001725_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001725_18_1 * 2) + 27) & 63;
  int stage_v_105_2 = ((pub_r001725_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((stage_v_81_1 << 1) ^ (pub_r001725_2_1 >> 1)) & 127;
  int stage_v_106_2 = ((stage_v_81_2 << 1) ^ (pub_r001725_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_106_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_106_2 + 1) & 15;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = ((pub_r001725_16_1 * 2) + 43) & 63;
  int stage_v_107_2 = ((pub_r001725_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((stage_v_15_1 << 1) ^ (pub_r001725_14_1 >> 1)) & 127;
  int stage_v_108_2 = ((stage_v_15_2 << 1) ^ (pub_r001725_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_108_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_108_2 + 1) & 15;
  out_sink_1 ^= stage_v_108_1 & 63;
  out_sink_2 ^= stage_v_108_2 & 63;
  int stage_v_109_1 = ((helper_flow_5_1 << 1) ^ (pub_r001725_18_1 >> 1)) & 127;
  int stage_v_109_2 = ((helper_flow_5_2 << 1) ^ (pub_r001725_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_109_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_109_2 + 1) & 15;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = ((pub_r001725_13_1 * 2) + 7) & 63;
  int stage_v_110_2 = ((pub_r001725_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_100_1 << 1) ^ (pub_r001725_22_1 >> 1)) & 127;
  int stage_v_111_2 = ((stage_v_100_2 << 1) ^ (pub_r001725_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_111_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_111_2 + 1) & 15;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = ((stage_v_28_1 << 1) ^ (pub_r001725_5_1 >> 1)) & 127;
  int stage_v_112_2 = ((stage_v_28_2 << 1) ^ (pub_r001725_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_112_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_112_2 + 1) & 15;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = ((pub_r001725_10_1 * 2) + 41) & 63;
  int stage_v_113_2 = ((pub_r001725_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001725_5_1 * 2) + 24) & 63;
  int stage_v_114_2 = ((pub_r001725_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001725_16_1 * 2) + 9) & 63;
  int stage_v_115_2 = ((pub_r001725_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((stage_v_14_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_116_2 = ((stage_v_14_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_116_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_116_2 + 1) & 15;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = ((pub_r001725_21_1 * 2) + 18) & 63;
  int stage_v_117_2 = ((pub_r001725_21_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((stage_v_116_1 << 1) ^ (pub_r001725_4_1 >> 1)) & 127;
  int stage_v_118_2 = ((stage_v_116_2 << 1) ^ (pub_r001725_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_118_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_118_2 + 1) & 15;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = ((stage_v_58_1 << 1) ^ (pub_r001725_6_1 >> 1)) & 127;
  int stage_v_119_2 = ((stage_v_58_2 << 1) ^ (pub_r001725_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_119_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_119_2 + 1) & 15;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = ((pub_r001725_11_1 * 2) + 21) & 63;
  int stage_v_120_2 = ((pub_r001725_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((sec_r001725_16_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_121_2 = ((sec_r001725_16_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_121_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_121_2 + 1) & 15;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = ((pub_r001725_3_1 * 2) + 10) & 63;
  int stage_v_122_2 = ((pub_r001725_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((stage_v_52_1 << 1) ^ (pub_r001725_5_1 >> 1)) & 127;
  int stage_v_123_2 = ((stage_v_52_2 << 1) ^ (pub_r001725_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_123_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_123_2 + 1) & 15;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = ((pub_r001725_9_1 * 2) + 18) & 63;
  int stage_v_124_2 = ((pub_r001725_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001725_18_1 * 2) + 8) & 63;
  int stage_v_125_2 = ((pub_r001725_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((stage_v_118_1 << 1) ^ (pub_r001725_10_1 >> 1)) & 127;
  int stage_v_126_2 = ((stage_v_118_2 << 1) ^ (pub_r001725_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_126_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_126_2 + 1) & 15;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = ((stage_v_28_1 << 1) ^ (pub_r001725_21_1 >> 1)) & 127;
  int stage_v_127_2 = ((stage_v_28_2 << 1) ^ (pub_r001725_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_127_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_127_2 + 1) & 15;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = ((sec_r001725_14_1 << 1) ^ (pub_r001725_4_1 >> 1)) & 127;
  int stage_v_128_2 = ((sec_r001725_14_2 << 1) ^ (pub_r001725_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_128_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_128_2 + 1) & 15;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = ((stage_v_81_1 << 1) ^ (pub_r001725_16_1 >> 1)) & 127;
  int stage_v_129_2 = ((stage_v_81_2 << 1) ^ (pub_r001725_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_129_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_129_2 + 1) & 15;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = ((pub_r001725_16_1 * 2) + 16) & 63;
  int stage_v_130_2 = ((pub_r001725_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001725_11_1 * 2) + 37) & 63;
  int stage_v_131_2 = ((pub_r001725_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_97_1 << 1) ^ (pub_r001725_13_1 >> 1)) & 127;
  int stage_v_132_2 = ((stage_v_97_2 << 1) ^ (pub_r001725_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_132_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_132_2 + 1) & 15;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = ((pub_r001725_16_1 * 2) + 18) & 63;
  int stage_v_133_2 = ((pub_r001725_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001725_10_1 * 2) + 22) & 63;
  int stage_v_134_2 = ((pub_r001725_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001725_9_1 * 2) + 43) & 63;
  int stage_v_135_2 = ((pub_r001725_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_85_1 << 1) ^ (pub_r001725_1_1 >> 1)) & 127;
  int stage_v_136_2 = ((stage_v_85_2 << 1) ^ (pub_r001725_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_136_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_136_2 + 1) & 15;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = ((stage_v_118_1 << 1) ^ (pub_r001725_9_1 >> 1)) & 127;
  int stage_v_137_2 = ((stage_v_118_2 << 1) ^ (pub_r001725_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_137_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_137_2 + 1) & 15;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = ((pub_r001725_4_1 * 2) + 14) & 63;
  int stage_v_138_2 = ((pub_r001725_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((stage_v_108_1 << 1) ^ (pub_r001725_0_1 >> 1)) & 127;
  int stage_v_139_2 = ((stage_v_108_2 << 1) ^ (pub_r001725_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_139_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_139_2 + 1) & 15;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = ((stage_v_121_1 << 1) ^ (pub_r001725_5_1 >> 1)) & 127;
  int stage_v_140_2 = ((stage_v_121_2 << 1) ^ (pub_r001725_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_140_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_140_2 + 1) & 15;
  out_sink_1 ^= stage_v_140_1 & 63;
  out_sink_2 ^= stage_v_140_2 & 63;
  int stage_v_141_1 = ((sec_r001725_1_1 << 1) ^ (pub_r001725_22_1 >> 1)) & 127;
  int stage_v_141_2 = ((sec_r001725_1_2 << 1) ^ (pub_r001725_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_141_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_141_2 + 1) & 15;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = ((stage_v_132_1 << 1) ^ (pub_r001725_0_1 >> 1)) & 127;
  int stage_v_142_2 = ((stage_v_132_2 << 1) ^ (pub_r001725_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_142_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_142_2 + 1) & 15;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = ((pub_r001725_6_1 * 2) + 17) & 63;
  int stage_v_143_2 = ((pub_r001725_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((stage_v_142_1 << 1) ^ (pub_r001725_21_1 >> 1)) & 127;
  int stage_v_144_2 = ((stage_v_142_2 << 1) ^ (pub_r001725_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_144_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_144_2 + 1) & 15;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = ((stage_v_24_1 << 1) ^ (pub_r001725_11_1 >> 1)) & 127;
  int stage_v_145_2 = ((stage_v_24_2 << 1) ^ (pub_r001725_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_145_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_145_2 + 1) & 15;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = ((pub_r001725_2_1 * 2) + 25) & 63;
  int stage_v_146_2 = ((pub_r001725_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001725_17_1 * 2) + 12) & 63;
  int stage_v_147_2 = ((pub_r001725_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((stage_v_127_1 << 1) ^ (pub_r001725_18_1 >> 1)) & 127;
  int stage_v_148_2 = ((stage_v_127_2 << 1) ^ (pub_r001725_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_148_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_148_2 + 1) & 15;
  out_sink_1 ^= stage_v_148_1 & 63;
  out_sink_2 ^= stage_v_148_2 & 63;
  int stage_v_149_1 = ((stage_v_19_1 << 1) ^ (pub_r001725_1_1 >> 1)) & 127;
  int stage_v_149_2 = ((stage_v_19_2 << 1) ^ (pub_r001725_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_149_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_149_2 + 1) & 15;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = ((pub_r001725_8_1 * 2) + 21) & 63;
  int stage_v_150_2 = ((pub_r001725_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001725_5_1 * 2) + 25) & 63;
  int stage_v_151_2 = ((pub_r001725_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001725_12_1 * 2) + 48) & 63;
  int stage_v_152_2 = ((pub_r001725_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((helper_flow_4_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_153_2 = ((helper_flow_4_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_153_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_153_2 + 1) & 15;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = ((pub_r001725_22_1 * 2) + 45) & 63;
  int stage_v_154_2 = ((pub_r001725_22_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001725_5_1 * 2) + 26) & 63;
  int stage_v_155_2 = ((pub_r001725_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001725_9_1 * 2) + 49) & 63;
  int stage_v_156_2 = ((pub_r001725_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((stage_v_23_1 << 1) ^ (pub_r001725_18_1 >> 1)) & 127;
  int stage_v_157_2 = ((stage_v_23_2 << 1) ^ (pub_r001725_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_157_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_157_2 + 1) & 15;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = ((stage_v_79_1 << 1) ^ (pub_r001725_4_1 >> 1)) & 127;
  int stage_v_158_2 = ((stage_v_79_2 << 1) ^ (pub_r001725_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_158_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_158_2 + 1) & 15;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = ((pub_r001725_18_1 * 2) + 23) & 63;
  int stage_v_159_2 = ((pub_r001725_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001725_19_1 * 2) + 27) & 63;
  int stage_v_160_2 = ((pub_r001725_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001725_10_1 * 2) + 18) & 63;
  int stage_v_161_2 = ((pub_r001725_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((helper_flow_4_1 << 1) ^ (pub_r001725_6_1 >> 1)) & 127;
  int stage_v_162_2 = ((helper_flow_4_2 << 1) ^ (pub_r001725_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_162_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_162_2 + 1) & 15;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = ((stage_v_69_1 << 1) ^ (pub_r001725_9_1 >> 1)) & 127;
  int stage_v_163_2 = ((stage_v_69_2 << 1) ^ (pub_r001725_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_163_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_163_2 + 1) & 15;
  out_sink_1 ^= stage_v_163_1 & 63;
  out_sink_2 ^= stage_v_163_2 & 63;
  int stage_v_164_1 = ((pub_r001725_19_1 * 2) + 39) & 63;
  int stage_v_164_2 = ((pub_r001725_19_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001725_11_1 * 2) + 33) & 63;
  int stage_v_165_2 = ((pub_r001725_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((stage_v_28_1 << 1) ^ (pub_r001725_21_1 >> 1)) & 127;
  int stage_v_166_2 = ((stage_v_28_2 << 1) ^ (pub_r001725_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_166_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_166_2 + 1) & 15;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = ((pub_r001725_12_1 * 2) + 35) & 63;
  int stage_v_167_2 = ((pub_r001725_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001725_2_1 * 2) + 27) & 63;
  int stage_v_168_2 = ((pub_r001725_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001725_18_1 * 2) + 42) & 63;
  int stage_v_169_2 = ((pub_r001725_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((sec_r001725_16_1 << 1) ^ (pub_r001725_7_1 >> 1)) & 127;
  int stage_v_170_2 = ((sec_r001725_16_2 << 1) ^ (pub_r001725_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_170_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_170_2 + 1) & 15;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = ((stage_v_5_1 << 1) ^ (pub_r001725_4_1 >> 1)) & 127;
  int stage_v_171_2 = ((stage_v_5_2 << 1) ^ (pub_r001725_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_171_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_171_2 + 1) & 15;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = ((pub_r001725_4_1 * 2) + 49) & 63;
  int stage_v_172_2 = ((pub_r001725_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001725_16_1 * 2) + 16) & 63;
  int stage_v_173_2 = ((pub_r001725_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001725_5_1 * 2) + 36) & 63;
  int stage_v_174_2 = ((pub_r001725_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001725_15_1 * 2) + 43) & 63;
  int stage_v_175_2 = ((pub_r001725_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((stage_v_53_1 << 1) ^ (pub_r001725_11_1 >> 1)) & 127;
  int stage_v_176_2 = ((stage_v_53_2 << 1) ^ (pub_r001725_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_176_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_176_2 + 1) & 15;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = ((pub_r001725_21_1 * 2) + 30) & 63;
  int stage_v_177_2 = ((pub_r001725_21_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((stage_v_66_1 << 1) ^ (pub_r001725_15_1 >> 1)) & 127;
  int stage_v_178_2 = ((stage_v_66_2 << 1) ^ (pub_r001725_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_178_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_178_2 + 1) & 15;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = ((stage_v_157_1 << 1) ^ (pub_r001725_9_1 >> 1)) & 127;
  int stage_v_179_2 = ((stage_v_157_2 << 1) ^ (pub_r001725_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_179_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_179_2 + 1) & 15;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = ((pub_r001725_0_1 * 2) + 40) & 63;
  int stage_v_180_2 = ((pub_r001725_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001725_2_1 * 2) + 5) & 63;
  int stage_v_181_2 = ((pub_r001725_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((sec_r001725_5_1 << 1) ^ (pub_r001725_3_1 >> 1)) & 127;
  int stage_v_182_2 = ((sec_r001725_5_2 << 1) ^ (pub_r001725_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_182_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_182_2 + 1) & 15;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = ((stage_v_106_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_183_2 = ((stage_v_106_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_183_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_183_2 + 1) & 15;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = ((pub_r001725_21_1 * 2) + 42) & 63;
  int stage_v_184_2 = ((pub_r001725_21_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((stage_v_170_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_185_2 = ((stage_v_170_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_185_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_185_2 + 1) & 15;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = ((pub_r001725_15_1 * 2) + 12) & 63;
  int stage_v_186_2 = ((pub_r001725_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001725_22_1 * 2) + 10) & 63;
  int stage_v_187_2 = ((pub_r001725_22_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001725_9_1 * 2) + 28) & 63;
  int stage_v_188_2 = ((pub_r001725_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001725_0_1 * 2) + 41) & 63;
  int stage_v_189_2 = ((pub_r001725_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001725_7_1 * 2) + 41) & 63;
  int stage_v_190_2 = ((pub_r001725_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001725_7_1 * 2) + 9) & 63;
  int stage_v_191_2 = ((pub_r001725_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001725_18_1 * 2) + 17) & 63;
  int stage_v_192_2 = ((pub_r001725_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((sec_r001725_18_1 << 1) ^ (pub_r001725_18_1 >> 1)) & 127;
  int stage_v_193_2 = ((sec_r001725_18_2 << 1) ^ (pub_r001725_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_193_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_193_2 + 1) & 15;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = ((stage_v_142_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_194_2 = ((stage_v_142_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_194_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_194_2 + 1) & 15;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = ((stage_v_58_1 << 1) ^ (pub_r001725_11_1 >> 1)) & 127;
  int stage_v_195_2 = ((stage_v_58_2 << 1) ^ (pub_r001725_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_195_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_195_2 + 1) & 15;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = ((stage_v_11_1 << 1) ^ (pub_r001725_19_1 >> 1)) & 127;
  int stage_v_196_2 = ((stage_v_11_2 << 1) ^ (pub_r001725_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_196_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_196_2 + 1) & 15;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = ((pub_r001725_17_1 * 2) + 44) & 63;
  int stage_v_197_2 = ((pub_r001725_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((sec_r001725_14_1 << 1) ^ (pub_r001725_14_1 >> 1)) & 127;
  int stage_v_198_2 = ((sec_r001725_14_2 << 1) ^ (pub_r001725_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_198_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_198_2 + 1) & 15;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = ((stage_v_58_1 << 1) ^ (pub_r001725_13_1 >> 1)) & 127;
  int stage_v_199_2 = ((stage_v_58_2 << 1) ^ (pub_r001725_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_199_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_199_2 + 1) & 15;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = ((stage_v_5_1 << 1) ^ (pub_r001725_6_1 >> 1)) & 127;
  int stage_v_200_2 = ((stage_v_5_2 << 1) ^ (pub_r001725_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_200_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_200_2 + 1) & 15;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = ((pub_r001725_12_1 * 2) + 36) & 63;
  int stage_v_201_2 = ((pub_r001725_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((stage_v_96_1 << 1) ^ (pub_r001725_22_1 >> 1)) & 127;
  int stage_v_202_2 = ((stage_v_96_2 << 1) ^ (pub_r001725_22_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_202_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_202_2 + 1) & 15;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = ((pub_r001725_7_1 * 2) + 46) & 63;
  int stage_v_203_2 = ((pub_r001725_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001725_2_1 * 2) + 17) & 63;
  int stage_v_204_2 = ((pub_r001725_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001725_8_1 * 2) + 50) & 63;
  int stage_v_205_2 = ((pub_r001725_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001725_15_1 * 2) + 45) & 63;
  int stage_v_206_2 = ((pub_r001725_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((helper_flow_4_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_207_2 = ((helper_flow_4_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_207_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_207_2 + 1) & 15;
  out_sink_1 ^= stage_v_207_1 & 63;
  out_sink_2 ^= stage_v_207_2 & 63;
  int stage_v_208_1 = ((stage_v_140_1 << 1) ^ (pub_r001725_21_1 >> 1)) & 127;
  int stage_v_208_2 = ((stage_v_140_2 << 1) ^ (pub_r001725_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_208_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_208_2 + 1) & 15;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = ((pub_r001725_8_1 * 2) + 20) & 63;
  int stage_v_209_2 = ((pub_r001725_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001725_18_1 * 2) + 38) & 63;
  int stage_v_210_2 = ((pub_r001725_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001725_22_1 * 2) + 43) & 63;
  int stage_v_211_2 = ((pub_r001725_22_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((stage_v_37_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_212_2 = ((stage_v_37_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_212_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_212_2 + 1) & 15;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = ((stage_v_45_1 << 1) ^ (pub_r001725_19_1 >> 1)) & 127;
  int stage_v_213_2 = ((stage_v_45_2 << 1) ^ (pub_r001725_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_213_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_213_2 + 1) & 15;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = ((stage_v_141_1 << 1) ^ (pub_r001725_16_1 >> 1)) & 127;
  int stage_v_214_2 = ((stage_v_141_2 << 1) ^ (pub_r001725_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_214_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_214_2 + 1) & 15;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = ((pub_r001725_18_1 * 2) + 27) & 63;
  int stage_v_215_2 = ((pub_r001725_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((stage_v_70_1 << 1) ^ (pub_r001725_17_1 >> 1)) & 127;
  int stage_v_216_2 = ((stage_v_70_2 << 1) ^ (pub_r001725_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_216_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_216_2 + 1) & 15;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = ((pub_r001725_10_1 * 2) + 47) & 63;
  int stage_v_217_2 = ((pub_r001725_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((stage_v_144_1 << 1) ^ (pub_r001725_9_1 >> 1)) & 127;
  int stage_v_218_2 = ((stage_v_144_2 << 1) ^ (pub_r001725_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_218_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_218_2 + 1) & 15;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = ((pub_r001725_7_1 * 2) + 18) & 63;
  int stage_v_219_2 = ((pub_r001725_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((stage_v_121_1 << 1) ^ (pub_r001725_5_1 >> 1)) & 127;
  int stage_v_220_2 = ((stage_v_121_2 << 1) ^ (pub_r001725_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_220_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_220_2 + 1) & 15;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = ((pub_r001725_4_1 * 2) + 26) & 63;
  int stage_v_221_2 = ((pub_r001725_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((stage_v_141_1 << 1) ^ (pub_r001725_12_1 >> 1)) & 127;
  int stage_v_222_2 = ((stage_v_141_2 << 1) ^ (pub_r001725_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_222_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_222_2 + 1) & 15;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = ((pub_r001725_0_1 * 2) + 9) & 63;
  int stage_v_223_2 = ((pub_r001725_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001725_1_1 * 2) + 21) & 63;
  int stage_v_224_2 = ((pub_r001725_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001725_0_1 * 2) + 36) & 63;
  int stage_v_225_2 = ((pub_r001725_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001725_19_1 * 2) + 9) & 63;
  int stage_v_226_2 = ((pub_r001725_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((stage_v_81_1 << 1) ^ (pub_r001725_1_1 >> 1)) & 127;
  int stage_v_227_2 = ((stage_v_81_2 << 1) ^ (pub_r001725_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_227_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_227_2 + 1) & 15;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = ((stage_v_24_1 << 1) ^ (pub_r001725_17_1 >> 1)) & 127;
  int stage_v_228_2 = ((stage_v_24_2 << 1) ^ (pub_r001725_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_228_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_228_2 + 1) & 15;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = ((pub_r001725_18_1 * 2) + 47) & 63;
  int stage_v_229_2 = ((pub_r001725_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001725_13_1 * 2) + 39) & 63;
  int stage_v_230_2 = ((pub_r001725_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((stage_v_35_1 << 1) ^ (pub_r001725_13_1 >> 1)) & 127;
  int stage_v_231_2 = ((stage_v_35_2 << 1) ^ (pub_r001725_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_231_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_231_2 + 1) & 15;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = ((sec_r001725_17_1 << 1) ^ (pub_r001725_16_1 >> 1)) & 127;
  int stage_v_232_2 = ((sec_r001725_17_2 << 1) ^ (pub_r001725_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_232_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_232_2 + 1) & 15;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = ((stage_v_111_1 << 1) ^ (pub_r001725_2_1 >> 1)) & 127;
  int stage_v_233_2 = ((stage_v_111_2 << 1) ^ (pub_r001725_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_233_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_233_2 + 1) & 15;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = ((stage_v_15_1 << 1) ^ (pub_r001725_17_1 >> 1)) & 127;
  int stage_v_234_2 = ((stage_v_15_2 << 1) ^ (pub_r001725_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_234_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_234_2 + 1) & 15;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = ((stage_v_227_1 << 1) ^ (pub_r001725_0_1 >> 1)) & 127;
  int stage_v_235_2 = ((stage_v_227_2 << 1) ^ (pub_r001725_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_235_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_235_2 + 1) & 15;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = ((pub_r001725_10_1 * 2) + 42) & 63;
  int stage_v_236_2 = ((pub_r001725_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001725_7_1 * 2) + 21) & 63;
  int stage_v_237_2 = ((pub_r001725_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((stage_v_116_1 << 1) ^ (pub_r001725_21_1 >> 1)) & 127;
  int stage_v_238_2 = ((stage_v_116_2 << 1) ^ (pub_r001725_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_238_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_238_2 + 1) & 15;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = ((stage_v_29_1 << 1) ^ (pub_r001725_22_1 >> 1)) & 127;
  int stage_v_239_2 = ((stage_v_29_2 << 1) ^ (pub_r001725_22_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_239_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_239_2 + 1) & 15;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = ((stage_v_63_1 << 1) ^ (pub_r001725_5_1 >> 1)) & 127;
  int stage_v_240_2 = ((stage_v_63_2 << 1) ^ (pub_r001725_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_240_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_240_2 + 1) & 15;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = ((pub_r001725_19_1 * 2) + 10) & 63;
  int stage_v_241_2 = ((pub_r001725_19_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((sec_r001725_2_1 << 1) ^ (pub_r001725_14_1 >> 1)) & 127;
  int stage_v_242_2 = ((sec_r001725_2_2 << 1) ^ (pub_r001725_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_242_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_242_2 + 1) & 15;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = ((stage_v_166_1 << 1) ^ (pub_r001725_9_1 >> 1)) & 127;
  int stage_v_243_2 = ((stage_v_166_2 << 1) ^ (pub_r001725_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((stage_v_69_1 << 1) ^ (pub_r001725_1_1 >> 1)) & 127;
  int stage_v_244_2 = ((stage_v_69_2 << 1) ^ (pub_r001725_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_244_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_244_2 + 1) & 15;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = ((pub_r001725_4_1 * 2) + 41) & 63;
  int stage_v_245_2 = ((pub_r001725_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001725_10_1 * 2) + 20) & 63;
  int stage_v_246_2 = ((pub_r001725_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001725_0_1 * 2) + 15) & 63;
  int stage_v_247_2 = ((pub_r001725_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((stage_v_39_1 << 1) ^ (pub_r001725_12_1 >> 1)) & 127;
  int stage_v_248_2 = ((stage_v_39_2 << 1) ^ (pub_r001725_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_248_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_248_2 + 1) & 15;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = ((stage_v_171_1 << 1) ^ (pub_r001725_3_1 >> 1)) & 127;
  int stage_v_249_2 = ((stage_v_171_2 << 1) ^ (pub_r001725_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_249_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_249_2 + 1) & 15;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = ((pub_r001725_9_1 * 2) + 47) & 63;
  int stage_v_250_2 = ((pub_r001725_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001725_7_1 * 2) + 43) & 63;
  int stage_v_251_2 = ((pub_r001725_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001725_9_1 * 2) + 7) & 63;
  int stage_v_252_2 = ((pub_r001725_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((stage_v_53_1 << 1) ^ (pub_r001725_16_1 >> 1)) & 127;
  int stage_v_253_2 = ((stage_v_53_2 << 1) ^ (pub_r001725_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((pub_r001725_0_1 * 2) + 27) & 63;
  int stage_v_254_2 = ((pub_r001725_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001725_14_1 * 2) + 37) & 63;
  int stage_v_255_2 = ((pub_r001725_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((stage_v_214_1 << 1) ^ (pub_r001725_5_1 >> 1)) & 127;
  int stage_v_256_2 = ((stage_v_214_2 << 1) ^ (pub_r001725_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((pub_r001725_9_1 * 2) + 48) & 63;
  int stage_v_257_2 = ((pub_r001725_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((sec_r001725_0_1 << 1) ^ (pub_r001725_21_1 >> 1)) & 127;
  int stage_v_258_2 = ((sec_r001725_0_2 << 1) ^ (pub_r001725_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_258_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_258_2 + 1) & 15;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = ((stage_v_233_1 << 1) ^ (pub_r001725_4_1 >> 1)) & 127;
  int stage_v_259_2 = ((stage_v_233_2 << 1) ^ (pub_r001725_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_259_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_259_2 + 1) & 15;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = ((stage_v_97_1 << 1) ^ (pub_r001725_10_1 >> 1)) & 127;
  int stage_v_260_2 = ((stage_v_97_2 << 1) ^ (pub_r001725_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_260_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_260_2 + 1) & 15;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = ((pub_r001725_14_1 * 2) + 35) & 63;
  int stage_v_261_2 = ((pub_r001725_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((helper_flow_5_1 << 1) ^ (pub_r001725_16_1 >> 1)) & 127;
  int stage_v_262_2 = ((helper_flow_5_2 << 1) ^ (pub_r001725_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_262_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_262_2 + 1) & 15;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = ((sec_r001725_17_1 << 1) ^ (pub_r001725_19_1 >> 1)) & 127;
  int stage_v_263_2 = ((sec_r001725_17_2 << 1) ^ (pub_r001725_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_263_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_263_2 + 1) & 15;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = ((stage_v_258_1 << 1) ^ (pub_r001725_16_1 >> 1)) & 127;
  int stage_v_264_2 = ((stage_v_258_2 << 1) ^ (pub_r001725_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_264_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_264_2 + 1) & 15;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = ((stage_v_196_1 << 1) ^ (pub_r001725_9_1 >> 1)) & 127;
  int stage_v_265_2 = ((stage_v_196_2 << 1) ^ (pub_r001725_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_265_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_265_2 + 1) & 15;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = ((pub_r001725_0_1 * 2) + 42) & 63;
  int stage_v_266_2 = ((pub_r001725_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((stage_v_39_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_267_2 = ((stage_v_39_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_267_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_267_2 + 1) & 15;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = ((pub_r001725_9_1 * 2) + 19) & 63;
  int stage_v_268_2 = ((pub_r001725_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((stage_v_76_1 << 1) ^ (pub_r001725_7_1 >> 1)) & 127;
  int stage_v_269_2 = ((stage_v_76_2 << 1) ^ (pub_r001725_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_269_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_269_2 + 1) & 15;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = ((stage_v_263_1 << 1) ^ (pub_r001725_17_1 >> 1)) & 127;
  int stage_v_270_2 = ((stage_v_263_2 << 1) ^ (pub_r001725_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_270_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_270_2 + 1) & 15;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = ((pub_r001725_4_1 * 2) + 28) & 63;
  int stage_v_271_2 = ((pub_r001725_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((stage_v_79_1 << 1) ^ (pub_r001725_19_1 >> 1)) & 127;
  int stage_v_272_2 = ((stage_v_79_2 << 1) ^ (pub_r001725_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_272_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_272_2 + 1) & 15;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = ((stage_v_244_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_273_2 = ((stage_v_244_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_273_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_273_2 + 1) & 15;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = ((stage_v_119_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_274_2 = ((stage_v_119_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_274_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_274_2 + 1) & 15;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = ((stage_v_109_1 << 1) ^ (pub_r001725_7_1 >> 1)) & 127;
  int stage_v_275_2 = ((stage_v_109_2 << 1) ^ (pub_r001725_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_275_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_275_2 + 1) & 15;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = ((sec_r001725_11_1 << 1) ^ (pub_r001725_14_1 >> 1)) & 127;
  int stage_v_276_2 = ((sec_r001725_11_2 << 1) ^ (pub_r001725_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_276_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_276_2 + 1) & 15;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = ((pub_r001725_10_1 * 2) + 17) & 63;
  int stage_v_277_2 = ((pub_r001725_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((stage_v_240_1 << 1) ^ (pub_r001725_2_1 >> 1)) & 127;
  int stage_v_278_2 = ((stage_v_240_2 << 1) ^ (pub_r001725_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_278_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_278_2 + 1) & 15;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = ((pub_r001725_14_1 * 2) + 10) & 63;
  int stage_v_279_2 = ((pub_r001725_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001725_2_1 * 2) + 46) & 63;
  int stage_v_280_2 = ((pub_r001725_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((stage_v_176_1 << 1) ^ (pub_r001725_3_1 >> 1)) & 127;
  int stage_v_281_2 = ((stage_v_176_2 << 1) ^ (pub_r001725_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_281_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_281_2 + 1) & 15;
  out_sink_1 ^= stage_v_281_1 & 63;
  out_sink_2 ^= stage_v_281_2 & 63;
  int stage_v_282_1 = ((pub_r001725_1_1 * 2) + 13) & 63;
  int stage_v_282_2 = ((pub_r001725_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((stage_v_273_1 << 1) ^ (pub_r001725_9_1 >> 1)) & 127;
  int stage_v_283_2 = ((stage_v_273_2 << 1) ^ (pub_r001725_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_283_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_283_2 + 1) & 15;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = ((stage_v_128_1 << 1) ^ (pub_r001725_1_1 >> 1)) & 127;
  int stage_v_284_2 = ((stage_v_128_2 << 1) ^ (pub_r001725_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_284_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_284_2 + 1) & 15;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = ((stage_v_65_1 << 1) ^ (pub_r001725_22_1 >> 1)) & 127;
  int stage_v_285_2 = ((stage_v_65_2 << 1) ^ (pub_r001725_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_285_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_285_2 + 1) & 15;
  out_sink_1 ^= stage_v_285_1 & 63;
  out_sink_2 ^= stage_v_285_2 & 63;
  int stage_v_286_1 = ((pub_r001725_15_1 * 2) + 48) & 63;
  int stage_v_286_2 = ((pub_r001725_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((stage_v_183_1 << 1) ^ (pub_r001725_3_1 >> 1)) & 127;
  int stage_v_287_2 = ((stage_v_183_2 << 1) ^ (pub_r001725_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_287_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_287_2 + 1) & 15;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = ((pub_r001725_15_1 * 2) + 14) & 63;
  int stage_v_288_2 = ((pub_r001725_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((stage_v_218_1 << 1) ^ (pub_r001725_17_1 >> 1)) & 127;
  int stage_v_289_2 = ((stage_v_218_2 << 1) ^ (pub_r001725_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_289_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_289_2 + 1) & 15;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = ((sec_r001725_16_1 << 1) ^ (pub_r001725_19_1 >> 1)) & 127;
  int stage_v_290_2 = ((sec_r001725_16_2 << 1) ^ (pub_r001725_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_290_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_290_2 + 1) & 15;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = ((pub_r001725_1_1 * 2) + 18) & 63;
  int stage_v_291_2 = ((pub_r001725_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((stage_v_17_1 << 1) ^ (pub_r001725_18_1 >> 1)) & 127;
  int stage_v_292_2 = ((stage_v_17_2 << 1) ^ (pub_r001725_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_292_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_292_2 + 1) & 15;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = ((pub_r001725_0_1 * 2) + 12) & 63;
  int stage_v_293_2 = ((pub_r001725_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((stage_v_118_1 << 1) ^ (pub_r001725_7_1 >> 1)) & 127;
  int stage_v_294_2 = ((stage_v_118_2 << 1) ^ (pub_r001725_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_294_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_294_2 + 1) & 15;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = ((pub_r001725_2_1 * 2) + 34) & 63;
  int stage_v_295_2 = ((pub_r001725_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((stage_v_59_1 << 1) ^ (pub_r001725_13_1 >> 1)) & 127;
  int stage_v_296_2 = ((stage_v_59_2 << 1) ^ (pub_r001725_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_296_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_296_2 + 1) & 15;
  out_sink_1 ^= stage_v_296_1 & 63;
  out_sink_2 ^= stage_v_296_2 & 63;
  int stage_v_297_1 = ((stage_v_126_1 << 1) ^ (pub_r001725_17_1 >> 1)) & 127;
  int stage_v_297_2 = ((stage_v_126_2 << 1) ^ (pub_r001725_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_297_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_297_2 + 1) & 15;
  out_sink_1 ^= stage_v_297_1 & 63;
  out_sink_2 ^= stage_v_297_2 & 63;
  int stage_v_298_1 = ((stage_v_63_1 << 1) ^ (pub_r001725_17_1 >> 1)) & 127;
  int stage_v_298_2 = ((stage_v_63_2 << 1) ^ (pub_r001725_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_298_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_298_2 + 1) & 15;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = ((pub_r001725_0_1 * 2) + 25) & 63;
  int stage_v_299_2 = ((pub_r001725_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((stage_v_216_1 << 1) ^ (pub_r001725_2_1 >> 1)) & 127;
  int stage_v_300_2 = ((stage_v_216_2 << 1) ^ (pub_r001725_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_300_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_300_2 + 1) & 15;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = ((stage_v_81_1 << 1) ^ (pub_r001725_18_1 >> 1)) & 127;
  int stage_v_301_2 = ((stage_v_81_2 << 1) ^ (pub_r001725_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_301_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_301_2 + 1) & 15;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = ((pub_r001725_16_1 * 2) + 5) & 63;
  int stage_v_302_2 = ((pub_r001725_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((stage_v_218_1 << 1) ^ (pub_r001725_3_1 >> 1)) & 127;
  int stage_v_303_2 = ((stage_v_218_2 << 1) ^ (pub_r001725_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_303_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_303_2 + 1) & 15;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = ((stage_v_123_1 << 1) ^ (pub_r001725_5_1 >> 1)) & 127;
  int stage_v_304_2 = ((stage_v_123_2 << 1) ^ (pub_r001725_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_304_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_304_2 + 1) & 15;
  out_sink_1 ^= stage_v_304_1 & 63;
  out_sink_2 ^= stage_v_304_2 & 63;
  int stage_v_305_1 = ((stage_v_259_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_305_2 = ((stage_v_259_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_305_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_305_2 + 1) & 15;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  int stage_v_306_1 = ((helper_flow_5_1 << 1) ^ (pub_r001725_16_1 >> 1)) & 127;
  int stage_v_306_2 = ((helper_flow_5_2 << 1) ^ (pub_r001725_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_306_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_306_2 + 1) & 15;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = ((stage_v_49_1 << 1) ^ (pub_r001725_22_1 >> 1)) & 127;
  int stage_v_307_2 = ((stage_v_49_2 << 1) ^ (pub_r001725_22_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_307_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_307_2 + 1) & 15;
  out_sink_1 ^= stage_v_307_1 & 63;
  out_sink_2 ^= stage_v_307_2 & 63;
  int stage_v_308_1 = ((pub_r001725_7_1 * 2) + 15) & 63;
  int stage_v_308_2 = ((pub_r001725_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((sec_r001725_3_1 << 1) ^ (pub_r001725_16_1 >> 1)) & 127;
  int stage_v_309_2 = ((sec_r001725_3_2 << 1) ^ (pub_r001725_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_309_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_309_2 + 1) & 15;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = ((sec_r001725_19_1 << 1) ^ (pub_r001725_5_1 >> 1)) & 127;
  int stage_v_310_2 = ((sec_r001725_19_2 << 1) ^ (pub_r001725_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_310_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_310_2 + 1) & 15;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = ((stage_v_296_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_311_2 = ((stage_v_296_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_311_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_311_2 + 1) & 15;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = ((sec_r001725_5_1 << 1) ^ (pub_r001725_5_1 >> 1)) & 127;
  int stage_v_312_2 = ((sec_r001725_5_2 << 1) ^ (pub_r001725_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((stage_v_72_1 << 1) ^ (pub_r001725_5_1 >> 1)) & 127;
  int stage_v_313_2 = ((stage_v_72_2 << 1) ^ (pub_r001725_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_313_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_313_2 + 1) & 15;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = ((pub_r001725_10_1 * 2) + 29) & 63;
  int stage_v_314_2 = ((pub_r001725_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001725_1_1 * 2) + 34) & 63;
  int stage_v_315_2 = ((pub_r001725_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001725_21_1 * 2) + 39) & 63;
  int stage_v_316_2 = ((pub_r001725_21_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((sec_r001725_16_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_317_2 = ((sec_r001725_16_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_317_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_317_2 + 1) & 15;
  out_sink_1 ^= stage_v_317_1 & 63;
  out_sink_2 ^= stage_v_317_2 & 63;
  int stage_v_318_1 = ((stage_v_287_1 << 1) ^ (pub_r001725_2_1 >> 1)) & 127;
  int stage_v_318_2 = ((stage_v_287_2 << 1) ^ (pub_r001725_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_318_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_318_2 + 1) & 15;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = ((pub_r001725_5_1 * 2) + 44) & 63;
  int stage_v_319_2 = ((pub_r001725_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001725_17_1 * 2) + 33) & 63;
  int stage_v_320_2 = ((pub_r001725_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((stage_v_185_1 << 1) ^ (pub_r001725_11_1 >> 1)) & 127;
  int stage_v_321_2 = ((stage_v_185_2 << 1) ^ (pub_r001725_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_321_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_321_2 + 1) & 15;
  out_sink_1 ^= stage_v_321_1 & 63;
  out_sink_2 ^= stage_v_321_2 & 63;
  int stage_v_322_1 = ((pub_r001725_13_1 * 2) + 13) & 63;
  int stage_v_322_2 = ((pub_r001725_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001725_4_1 * 2) + 32) & 63;
  int stage_v_323_2 = ((pub_r001725_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((stage_v_1_1 << 1) ^ (pub_r001725_12_1 >> 1)) & 127;
  int stage_v_324_2 = ((stage_v_1_2 << 1) ^ (pub_r001725_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_324_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_324_2 + 1) & 15;
  out_sink_1 ^= stage_v_324_1 & 63;
  out_sink_2 ^= stage_v_324_2 & 63;
  int stage_v_325_1 = ((stage_v_100_1 << 1) ^ (pub_r001725_16_1 >> 1)) & 127;
  int stage_v_325_2 = ((stage_v_100_2 << 1) ^ (pub_r001725_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_325_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_325_2 + 1) & 15;
  out_sink_1 ^= stage_v_325_1 & 63;
  out_sink_2 ^= stage_v_325_2 & 63;
  int stage_v_326_1 = ((stage_v_132_1 << 1) ^ (pub_r001725_6_1 >> 1)) & 127;
  int stage_v_326_2 = ((stage_v_132_2 << 1) ^ (pub_r001725_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_326_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_326_2 + 1) & 15;
  out_sink_1 ^= stage_v_326_1 & 63;
  out_sink_2 ^= stage_v_326_2 & 63;
  int stage_v_327_1 = ((pub_r001725_21_1 * 2) + 6) & 63;
  int stage_v_327_2 = ((pub_r001725_21_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001725_0_1 * 2) + 12) & 63;
  int stage_v_328_2 = ((pub_r001725_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((sec_r001725_12_1 << 1) ^ (pub_r001725_12_1 >> 1)) & 127;
  int stage_v_329_2 = ((sec_r001725_12_2 << 1) ^ (pub_r001725_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_329_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_329_2 + 1) & 15;
  out_sink_1 ^= stage_v_329_1 & 63;
  out_sink_2 ^= stage_v_329_2 & 63;
  int stage_v_330_1 = ((pub_r001725_16_1 * 2) + 23) & 63;
  int stage_v_330_2 = ((pub_r001725_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001725_8_1 * 2) + 42) & 63;
  int stage_v_331_2 = ((pub_r001725_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((stage_v_18_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_332_2 = ((stage_v_18_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_332_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_332_2 + 1) & 15;
  out_sink_1 ^= stage_v_332_1 & 63;
  out_sink_2 ^= stage_v_332_2 & 63;
  int stage_v_333_1 = ((stage_v_218_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_333_2 = ((stage_v_218_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_333_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_333_2 + 1) & 15;
  out_sink_1 ^= stage_v_333_1 & 63;
  out_sink_2 ^= stage_v_333_2 & 63;
  int stage_v_334_1 = ((stage_v_19_1 << 1) ^ (pub_r001725_11_1 >> 1)) & 127;
  int stage_v_334_2 = ((stage_v_19_2 << 1) ^ (pub_r001725_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_334_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_334_2 + 1) & 15;
  out_sink_1 ^= stage_v_334_1 & 63;
  out_sink_2 ^= stage_v_334_2 & 63;
  int stage_v_335_1 = ((stage_v_72_1 << 1) ^ (pub_r001725_22_1 >> 1)) & 127;
  int stage_v_335_2 = ((stage_v_72_2 << 1) ^ (pub_r001725_22_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_335_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_335_2 + 1) & 15;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = ((pub_r001725_22_1 * 2) + 20) & 63;
  int stage_v_336_2 = ((pub_r001725_22_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001725_10_1 * 2) + 34) & 63;
  int stage_v_337_2 = ((pub_r001725_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((stage_v_29_1 << 1) ^ (pub_r001725_6_1 >> 1)) & 127;
  int stage_v_338_2 = ((stage_v_29_2 << 1) ^ (pub_r001725_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_338_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_338_2 + 1) & 15;
  out_sink_1 ^= stage_v_338_1 & 63;
  out_sink_2 ^= stage_v_338_2 & 63;
  int stage_v_339_1 = ((pub_r001725_2_1 * 2) + 30) & 63;
  int stage_v_339_2 = ((pub_r001725_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001725_12_1 * 2) + 11) & 63;
  int stage_v_340_2 = ((pub_r001725_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001725_15_1 * 2) + 33) & 63;
  int stage_v_341_2 = ((pub_r001725_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((stage_v_140_1 << 1) ^ (pub_r001725_22_1 >> 1)) & 127;
  int stage_v_342_2 = ((stage_v_140_2 << 1) ^ (pub_r001725_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_342_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_342_2 + 1) & 15;
  out_sink_1 ^= stage_v_342_1 & 63;
  out_sink_2 ^= stage_v_342_2 & 63;
  int stage_v_343_1 = ((stage_v_51_1 << 1) ^ (pub_r001725_12_1 >> 1)) & 127;
  int stage_v_343_2 = ((stage_v_51_2 << 1) ^ (pub_r001725_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_343_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_343_2 + 1) & 15;
  out_sink_1 ^= stage_v_343_1 & 63;
  out_sink_2 ^= stage_v_343_2 & 63;
  int stage_v_344_1 = ((pub_r001725_7_1 * 2) + 39) & 63;
  int stage_v_344_2 = ((pub_r001725_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((pub_r001725_8_1 * 2) + 10) & 63;
  int stage_v_345_2 = ((pub_r001725_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001725_13_1 * 2) + 43) & 63;
  int stage_v_346_2 = ((pub_r001725_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001725_8_1 * 2) + 6) & 63;
  int stage_v_347_2 = ((pub_r001725_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((stage_v_235_1 << 1) ^ (pub_r001725_6_1 >> 1)) & 127;
  int stage_v_348_2 = ((stage_v_235_2 << 1) ^ (pub_r001725_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_348_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_348_2 + 1) & 15;
  out_sink_1 ^= stage_v_348_1 & 63;
  out_sink_2 ^= stage_v_348_2 & 63;
  int stage_v_349_1 = ((sec_r001725_16_1 << 1) ^ (pub_r001725_19_1 >> 1)) & 127;
  int stage_v_349_2 = ((sec_r001725_16_2 << 1) ^ (pub_r001725_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_349_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_349_2 + 1) & 15;
  out_sink_1 ^= stage_v_349_1 & 63;
  out_sink_2 ^= stage_v_349_2 & 63;
  int stage_v_350_1 = ((stage_v_162_1 << 1) ^ (pub_r001725_16_1 >> 1)) & 127;
  int stage_v_350_2 = ((stage_v_162_2 << 1) ^ (pub_r001725_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((pub_r001725_20_1 * 2) + 9) & 63;
  int stage_v_351_2 = ((pub_r001725_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001725_12_1 * 2) + 35) & 63;
  int stage_v_352_2 = ((pub_r001725_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((stage_v_213_1 << 1) ^ (pub_r001725_1_1 >> 1)) & 127;
  int stage_v_353_2 = ((stage_v_213_2 << 1) ^ (pub_r001725_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_353_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_353_2 + 1) & 15;
  out_sink_1 ^= stage_v_353_1 & 63;
  out_sink_2 ^= stage_v_353_2 & 63;
  int stage_v_354_1 = ((stage_v_101_1 << 1) ^ (pub_r001725_0_1 >> 1)) & 127;
  int stage_v_354_2 = ((stage_v_101_2 << 1) ^ (pub_r001725_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_354_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_354_2 + 1) & 15;
  out_sink_1 ^= stage_v_354_1 & 63;
  out_sink_2 ^= stage_v_354_2 & 63;
  int stage_v_355_1 = ((stage_v_325_1 << 1) ^ (pub_r001725_10_1 >> 1)) & 127;
  int stage_v_355_2 = ((stage_v_325_2 << 1) ^ (pub_r001725_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_355_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_355_2 + 1) & 15;
  out_sink_1 ^= stage_v_355_1 & 63;
  out_sink_2 ^= stage_v_355_2 & 63;
  int stage_v_356_1 = ((stage_v_106_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_356_2 = ((stage_v_106_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_356_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_356_2 + 1) & 15;
  out_sink_1 ^= stage_v_356_1 & 63;
  out_sink_2 ^= stage_v_356_2 & 63;
  int stage_v_357_1 = ((stage_v_62_1 << 1) ^ (pub_r001725_12_1 >> 1)) & 127;
  int stage_v_357_2 = ((stage_v_62_2 << 1) ^ (pub_r001725_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_357_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_357_2 + 1) & 15;
  out_sink_1 ^= stage_v_357_1 & 63;
  out_sink_2 ^= stage_v_357_2 & 63;
  int stage_v_358_1 = ((stage_v_310_1 << 1) ^ (pub_r001725_7_1 >> 1)) & 127;
  int stage_v_358_2 = ((stage_v_310_2 << 1) ^ (pub_r001725_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_358_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_358_2 + 1) & 15;
  out_sink_1 ^= stage_v_358_1 & 63;
  out_sink_2 ^= stage_v_358_2 & 63;
  int stage_v_359_1 = ((pub_r001725_0_1 * 2) + 6) & 63;
  int stage_v_359_2 = ((pub_r001725_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((sec_r001725_2_1 << 1) ^ (pub_r001725_18_1 >> 1)) & 127;
  int stage_v_360_2 = ((sec_r001725_2_2 << 1) ^ (pub_r001725_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_360_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_360_2 + 1) & 15;
  out_sink_1 ^= stage_v_360_1 & 63;
  out_sink_2 ^= stage_v_360_2 & 63;
  int stage_v_361_1 = ((pub_r001725_1_1 * 2) + 41) & 63;
  int stage_v_361_2 = ((pub_r001725_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((stage_v_33_1 << 1) ^ (pub_r001725_10_1 >> 1)) & 127;
  int stage_v_362_2 = ((stage_v_33_2 << 1) ^ (pub_r001725_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_362_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_362_2 + 1) & 15;
  out_sink_1 ^= stage_v_362_1 & 63;
  out_sink_2 ^= stage_v_362_2 & 63;
  int stage_v_363_1 = ((stage_v_287_1 << 1) ^ (pub_r001725_3_1 >> 1)) & 127;
  int stage_v_363_2 = ((stage_v_287_2 << 1) ^ (pub_r001725_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((stage_v_239_1 << 1) ^ (pub_r001725_4_1 >> 1)) & 127;
  int stage_v_364_2 = ((stage_v_239_2 << 1) ^ (pub_r001725_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_364_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_364_2 + 1) & 15;
  out_sink_1 ^= stage_v_364_1 & 63;
  out_sink_2 ^= stage_v_364_2 & 63;
  int stage_v_365_1 = ((stage_v_72_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_72_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((pub_r001725_10_1 * 2) + 7) & 63;
  int stage_v_366_2 = ((pub_r001725_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((stage_v_5_1 << 1) ^ (pub_r001725_14_1 >> 1)) & 127;
  int stage_v_367_2 = ((stage_v_5_2 << 1) ^ (pub_r001725_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_367_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_367_2 + 1) & 15;
  out_sink_1 ^= stage_v_367_1 & 63;
  out_sink_2 ^= stage_v_367_2 & 63;
  int stage_v_368_1 = ((stage_v_101_1 << 1) ^ (pub_r001725_6_1 >> 1)) & 127;
  int stage_v_368_2 = ((stage_v_101_2 << 1) ^ (pub_r001725_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_368_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_368_2 + 1) & 15;
  out_sink_1 ^= stage_v_368_1 & 63;
  out_sink_2 ^= stage_v_368_2 & 63;
  int stage_v_369_1 = ((pub_r001725_7_1 * 2) + 41) & 63;
  int stage_v_369_2 = ((pub_r001725_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001725_4_1 * 2) + 44) & 63;
  int stage_v_370_2 = ((pub_r001725_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((stage_v_358_1 << 1) ^ (pub_r001725_6_1 >> 1)) & 127;
  int stage_v_371_2 = ((stage_v_358_2 << 1) ^ (pub_r001725_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_371_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_371_2 + 1) & 15;
  out_sink_1 ^= stage_v_371_1 & 63;
  out_sink_2 ^= stage_v_371_2 & 63;
  int stage_v_372_1 = ((sec_r001725_3_1 << 1) ^ (pub_r001725_7_1 >> 1)) & 127;
  int stage_v_372_2 = ((sec_r001725_3_2 << 1) ^ (pub_r001725_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_372_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_372_2 + 1) & 15;
  out_sink_1 ^= stage_v_372_1 & 63;
  out_sink_2 ^= stage_v_372_2 & 63;
  int stage_v_373_1 = ((pub_r001725_11_1 * 2) + 50) & 63;
  int stage_v_373_2 = ((pub_r001725_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001725_2_1 * 2) + 20) & 63;
  int stage_v_374_2 = ((pub_r001725_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((stage_v_106_1 << 1) ^ (pub_r001725_15_1 >> 1)) & 127;
  int stage_v_375_2 = ((stage_v_106_2 << 1) ^ (pub_r001725_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_375_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_375_2 + 1) & 15;
  out_sink_1 ^= stage_v_375_1 & 63;
  out_sink_2 ^= stage_v_375_2 & 63;
  int stage_v_376_1 = ((pub_r001725_5_1 * 2) + 49) & 63;
  int stage_v_376_2 = ((pub_r001725_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((helper_flow_5_1 << 1) ^ (pub_r001725_3_1 >> 1)) & 127;
  int stage_v_377_2 = ((helper_flow_5_2 << 1) ^ (pub_r001725_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_377_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_377_2 + 1) & 15;
  out_sink_1 ^= stage_v_377_1 & 63;
  out_sink_2 ^= stage_v_377_2 & 63;
  int stage_v_378_1 = ((stage_v_58_1 << 1) ^ (pub_r001725_7_1 >> 1)) & 127;
  int stage_v_378_2 = ((stage_v_58_2 << 1) ^ (pub_r001725_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((pub_r001725_22_1 * 2) + 15) & 63;
  int stage_v_379_2 = ((pub_r001725_22_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((stage_v_47_1 << 1) ^ (pub_r001725_3_1 >> 1)) & 127;
  int stage_v_380_2 = ((stage_v_47_2 << 1) ^ (pub_r001725_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_380_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_380_2 + 1) & 15;
  out_sink_1 ^= stage_v_380_1 & 63;
  out_sink_2 ^= stage_v_380_2 & 63;
  int stage_v_381_1 = ((pub_r001725_14_1 * 2) + 38) & 63;
  int stage_v_381_2 = ((pub_r001725_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((stage_v_289_1 << 1) ^ (pub_r001725_0_1 >> 1)) & 127;
  int stage_v_382_2 = ((stage_v_289_2 << 1) ^ (pub_r001725_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_382_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_382_2 + 1) & 15;
  out_sink_1 ^= stage_v_382_1 & 63;
  out_sink_2 ^= stage_v_382_2 & 63;
  int stage_v_383_1 = ((stage_v_216_1 << 1) ^ (pub_r001725_2_1 >> 1)) & 127;
  int stage_v_383_2 = ((stage_v_216_2 << 1) ^ (pub_r001725_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_383_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_383_2 + 1) & 15;
  out_sink_1 ^= stage_v_383_1 & 63;
  out_sink_2 ^= stage_v_383_2 & 63;
  int stage_v_384_1 = ((stage_v_158_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_384_2 = ((stage_v_158_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_384_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_384_2 + 1) & 15;
  out_sink_1 ^= stage_v_384_1 & 63;
  out_sink_2 ^= stage_v_384_2 & 63;
  int stage_v_385_1 = ((stage_v_242_1 << 1) ^ (pub_r001725_9_1 >> 1)) & 127;
  int stage_v_385_2 = ((stage_v_242_2 << 1) ^ (pub_r001725_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_385_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_385_2 + 1) & 15;
  out_sink_1 ^= stage_v_385_1 & 63;
  out_sink_2 ^= stage_v_385_2 & 63;
  int stage_v_386_1 = ((pub_r001725_22_1 * 2) + 45) & 63;
  int stage_v_386_2 = ((pub_r001725_22_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((stage_v_371_1 << 1) ^ (pub_r001725_6_1 >> 1)) & 127;
  int stage_v_387_2 = ((stage_v_371_2 << 1) ^ (pub_r001725_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_387_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_387_2 + 1) & 15;
  out_sink_1 ^= stage_v_387_1 & 63;
  out_sink_2 ^= stage_v_387_2 & 63;
  int stage_v_388_1 = ((sec_r001725_5_1 << 1) ^ (pub_r001725_9_1 >> 1)) & 127;
  int stage_v_388_2 = ((sec_r001725_5_2 << 1) ^ (pub_r001725_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_388_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_388_2 + 1) & 15;
  out_sink_1 ^= stage_v_388_1 & 63;
  out_sink_2 ^= stage_v_388_2 & 63;
  int stage_v_389_1 = ((pub_r001725_3_1 * 2) + 17) & 63;
  int stage_v_389_2 = ((pub_r001725_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((pub_r001725_1_1 * 2) + 34) & 63;
  int stage_v_390_2 = ((pub_r001725_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((stage_v_81_1 << 1) ^ (pub_r001725_19_1 >> 1)) & 127;
  int stage_v_391_2 = ((stage_v_81_2 << 1) ^ (pub_r001725_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_391_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_391_2 + 1) & 15;
  out_sink_1 ^= stage_v_391_1 & 63;
  out_sink_2 ^= stage_v_391_2 & 63;
  int stage_v_392_1 = ((pub_r001725_21_1 * 2) + 23) & 63;
  int stage_v_392_2 = ((pub_r001725_21_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001725_2_1 * 2) + 16) & 63;
  int stage_v_393_2 = ((pub_r001725_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((stage_v_318_1 << 1) ^ (pub_r001725_21_1 >> 1)) & 127;
  int stage_v_394_2 = ((stage_v_318_2 << 1) ^ (pub_r001725_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_394_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_394_2 + 1) & 15;
  out_sink_1 ^= stage_v_394_1 & 63;
  out_sink_2 ^= stage_v_394_2 & 63;
  int stage_v_395_1 = ((pub_r001725_3_1 * 2) + 36) & 63;
  int stage_v_395_2 = ((pub_r001725_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((stage_v_60_1 << 1) ^ (pub_r001725_1_1 >> 1)) & 127;
  int stage_v_396_2 = ((stage_v_60_2 << 1) ^ (pub_r001725_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_396_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_396_2 + 1) & 15;
  out_sink_1 ^= stage_v_396_1 & 63;
  out_sink_2 ^= stage_v_396_2 & 63;
  int stage_v_397_1 = ((pub_r001725_18_1 * 2) + 31) & 63;
  int stage_v_397_2 = ((pub_r001725_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001725_16_1 * 2) + 29) & 63;
  int stage_v_398_2 = ((pub_r001725_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((stage_v_234_1 << 1) ^ (pub_r001725_3_1 >> 1)) & 127;
  int stage_v_399_2 = ((stage_v_234_2 << 1) ^ (pub_r001725_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_399_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_399_2 + 1) & 15;
  out_sink_1 ^= stage_v_399_1 & 63;
  out_sink_2 ^= stage_v_399_2 & 63;
  int stage_v_400_1 = ((stage_v_303_1 << 1) ^ (pub_r001725_12_1 >> 1)) & 127;
  int stage_v_400_2 = ((stage_v_303_2 << 1) ^ (pub_r001725_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_400_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_400_2 + 1) & 15;
  out_sink_1 ^= stage_v_400_1 & 63;
  out_sink_2 ^= stage_v_400_2 & 63;
  int stage_v_401_1 = ((pub_r001725_17_1 * 2) + 34) & 63;
  int stage_v_401_2 = ((pub_r001725_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((stage_v_212_1 << 1) ^ (pub_r001725_20_1 >> 1)) & 127;
  int stage_v_402_2 = ((stage_v_212_2 << 1) ^ (pub_r001725_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_402_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_402_2 + 1) & 15;
  out_sink_1 ^= stage_v_402_1 & 63;
  out_sink_2 ^= stage_v_402_2 & 63;
  int stage_v_403_1 = ((stage_v_10_1 << 1) ^ (pub_r001725_13_1 >> 1)) & 127;
  int stage_v_403_2 = ((stage_v_10_2 << 1) ^ (pub_r001725_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_403_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_403_2 + 1) & 15;
  out_sink_1 ^= stage_v_403_1 & 63;
  out_sink_2 ^= stage_v_403_2 & 63;
  int stage_v_404_1 = ((pub_r001725_20_1 * 2) + 27) & 63;
  int stage_v_404_2 = ((pub_r001725_20_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = ((pub_r001725_2_1 * 2) + 17) & 63;
  int stage_v_405_2 = ((pub_r001725_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((stage_v_309_1 << 1) ^ (pub_r001725_21_1 >> 1)) & 127;
  int stage_v_406_2 = ((stage_v_309_2 << 1) ^ (pub_r001725_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_406_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_406_2 + 1) & 15;
  out_sink_1 ^= stage_v_406_1 & 63;
  out_sink_2 ^= stage_v_406_2 & 63;
  int stage_v_407_1 = ((stage_v_166_1 << 1) ^ (pub_r001725_11_1 >> 1)) & 127;
  int stage_v_407_2 = ((stage_v_166_2 << 1) ^ (pub_r001725_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_407_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_407_2 + 1) & 15;
  out_sink_1 ^= stage_v_407_1 & 63;
  out_sink_2 ^= stage_v_407_2 & 63;
  int stage_v_408_1 = ((stage_v_121_1 << 1) ^ (pub_r001725_16_1 >> 1)) & 127;
  int stage_v_408_2 = ((stage_v_121_2 << 1) ^ (pub_r001725_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_408_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_408_2 + 1) & 15;
  out_sink_1 ^= stage_v_408_1 & 63;
  out_sink_2 ^= stage_v_408_2 & 63;
  int stage_v_409_1 = ((sec_r001725_15_1 << 1) ^ (pub_r001725_17_1 >> 1)) & 127;
  int stage_v_409_2 = ((sec_r001725_15_2 << 1) ^ (pub_r001725_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_409_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_409_2 + 1) & 15;
  out_sink_1 ^= stage_v_409_1 & 63;
  out_sink_2 ^= stage_v_409_2 & 63;
  int stage_v_410_1 = ((sec_r001725_3_1 << 1) ^ (pub_r001725_8_1 >> 1)) & 127;
  int stage_v_410_2 = ((sec_r001725_3_2 << 1) ^ (pub_r001725_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_410_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_410_2 + 1) & 15;
  out_sink_1 ^= stage_v_410_1 & 63;
  out_sink_2 ^= stage_v_410_2 & 63;
  int stage_v_411_1 = ((pub_r001725_22_1 * 2) + 34) & 63;
  int stage_v_411_2 = ((pub_r001725_22_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((stage_v_399_1 << 1) ^ (pub_r001725_21_1 >> 1)) & 127;
  int stage_v_412_2 = ((stage_v_399_2 << 1) ^ (pub_r001725_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_412_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_412_2 + 1) & 15;
  out_sink_1 ^= stage_v_412_1 & 63;
  out_sink_2 ^= stage_v_412_2 & 63;
  int stage_v_413_1 = ((pub_r001725_8_1 * 2) + 17) & 63;
  int stage_v_413_2 = ((pub_r001725_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001725_22_1 * 2) + 28) & 63;
  int stage_v_414_2 = ((pub_r001725_22_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((sec_r001725_19_1 << 1) ^ (pub_r001725_6_1 >> 1)) & 127;
  int stage_v_415_2 = ((sec_r001725_19_2 << 1) ^ (pub_r001725_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_415_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_415_2 + 1) & 15;
  out_sink_1 ^= stage_v_415_1 & 63;
  out_sink_2 ^= stage_v_415_2 & 63;
  int stage_v_416_1 = ((pub_r001725_19_1 * 2) + 18) & 63;
  int stage_v_416_2 = ((pub_r001725_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((pub_r001725_17_1 * 2) + 21) & 63;
  int stage_v_417_2 = ((pub_r001725_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001725_15_1 == pub_r001725_15_2);
  __CPROVER_assume(pub_r001725_22_1 == pub_r001725_22_2);
  __CPROVER_assume(sec_r001725_10_1 != sec_r001725_10_2);
  __CPROVER_assume(sec_r001725_6_1 != sec_r001725_6_2);
  __CPROVER_assume(sec_r001725_9_1 != sec_r001725_9_2);
  __CPROVER_assume(sec_r001725_19_1 != sec_r001725_19_2);
  __CPROVER_assume(pub_r001725_4_1 == pub_r001725_4_2);
  __CPROVER_assume(pub_r001725_19_1 == pub_r001725_19_2);
  __CPROVER_assume(pub_r001725_6_1 == pub_r001725_6_2);
  __CPROVER_assume(pub_r001725_20_1 == pub_r001725_20_2);
  __CPROVER_assume(pub_r001725_7_1 == pub_r001725_7_2);
  __CPROVER_assume(sec_r001725_15_1 != sec_r001725_15_2);
  __CPROVER_assume(pub_r001725_8_1 == pub_r001725_8_2);
  __CPROVER_assume(pub_r001725_16_1 == pub_r001725_16_2);
  __CPROVER_assume(sec_r001725_2_1 != sec_r001725_2_2);
  __CPROVER_assume(sec_r001725_18_1 != sec_r001725_18_2);
  __CPROVER_assume(sec_r001725_5_1 != sec_r001725_5_2);
  __CPROVER_assume(sec_r001725_12_1 != sec_r001725_12_2);
  __CPROVER_assume(sec_r001725_1_1 != sec_r001725_1_2);
  __CPROVER_assume(sec_r001725_4_1 != sec_r001725_4_2);
  __CPROVER_assume(sec_r001725_7_1 != sec_r001725_7_2);
  __CPROVER_assume(sec_r001725_16_1 != sec_r001725_16_2);
  __CPROVER_assume(pub_r001725_3_1 == pub_r001725_3_2);
  __CPROVER_assume(pub_r001725_12_1 == pub_r001725_12_2);
  __CPROVER_assume(pub_r001725_1_1 == pub_r001725_1_2);
  __CPROVER_assume(sec_r001725_8_1 != sec_r001725_8_2);
  __CPROVER_assume(pub_r001725_14_1 == pub_r001725_14_2);
  __CPROVER_assume(sec_r001725_3_1 != sec_r001725_3_2);
  __CPROVER_assume(sec_r001725_14_1 != sec_r001725_14_2);
  __CPROVER_assume(pub_r001725_18_1 == pub_r001725_18_2);
  __CPROVER_assume(pub_r001725_11_1 == pub_r001725_11_2);
  __CPROVER_assume(sec_r001725_13_1 != sec_r001725_13_2);
  __CPROVER_assume(pub_r001725_10_1 == pub_r001725_10_2);
  __CPROVER_assume(sec_r001725_17_1 != sec_r001725_17_2);
  __CPROVER_assume(pub_r001725_2_1 == pub_r001725_2_2);
  __CPROVER_assume(pub_r001725_9_1 == pub_r001725_9_2);
  __CPROVER_assume(pub_r001725_13_1 == pub_r001725_13_2);
  __CPROVER_assume(pub_r001725_0_1 == pub_r001725_0_2);
  __CPROVER_assume(pub_r001725_21_1 == pub_r001725_21_2);
  __CPROVER_assume(sec_r001725_11_1 != sec_r001725_11_2);
  __CPROVER_assume(pub_r001725_5_1 == pub_r001725_5_2);
  __CPROVER_assume(sec_r001725_0_1 != sec_r001725_0_2);
  __CPROVER_assume(pub_r001725_17_1 == pub_r001725_17_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.status == st_var_0_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.dim == st_var_1_2.dim);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.stride == st_var_1_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.facility == st_var_2_2.facility);
  assert(st_var_2_1.signature == st_var_2_2.signature);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.code == st_var_2_2.code);
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
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
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
  assert(stage_v_401_1 == stage_v_401_2);
  assert(stage_v_402_1 == stage_v_402_2);
  assert(stage_v_403_1 == stage_v_403_2);
  assert(stage_v_404_1 == stage_v_404_2);
  assert(stage_v_405_1 == stage_v_405_2);
  assert(stage_v_406_1 == stage_v_406_2);
  assert(stage_v_407_1 == stage_v_407_2);
  assert(stage_v_408_1 == stage_v_408_2);
  assert(stage_v_409_1 == stage_v_409_2);
  assert(stage_v_410_1 == stage_v_410_2);
  assert(stage_v_411_1 == stage_v_411_2);
  assert(stage_v_412_1 == stage_v_412_2);
  assert(stage_v_413_1 == stage_v_413_2);
  assert(stage_v_414_1 == stage_v_414_2);
  assert(stage_v_415_1 == stage_v_415_2);
  assert(stage_v_416_1 == stage_v_416_2);
  assert(stage_v_417_1 == stage_v_417_2);
}


